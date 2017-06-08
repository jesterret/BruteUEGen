#pragma once
#include "UProperty.h"

class UStructProperty : public UProperty
{
public:
    UStruct* Struct()
    {
        return GetPtr(UStruct*, this, pVars->UStructProperty_Struct);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"StructProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};