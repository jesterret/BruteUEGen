#pragma once
#include "UProperty.h"

class UArrayProperty : public UProperty
{
public:
    UProperty* Inner()
    {
        return GetPtr(UProperty*, this, pVars->UArrayProperty_Inner);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"ArrayProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};