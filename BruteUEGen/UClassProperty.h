#pragma once
#include "UProperty.h"

class UClassProperty : public UProperty
{
public:
    UClass* MetaClass()
    {
        return GetPtr(UClass*, this, pVars->UClassProperty_MetaClass);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"ClassProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};