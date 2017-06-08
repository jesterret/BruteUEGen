#pragma once
#include "UProperty.h"

class UMapProperty : public UProperty
{
public:
    UProperty* Key()
    {
        return GetPtr(UProperty*, this, pVars->UMapProperty_Key);
    }
    UProperty* Value()
    {
        return GetPtr(UProperty*, this, pVars->UMapProperty_Value);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"MapProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};