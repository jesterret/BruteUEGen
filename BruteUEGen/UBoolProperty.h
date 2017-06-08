#pragma once
#include "UProperty.h"

class UBoolProperty : public UProperty
{
public:
    DWORD BitMask()
    {
        return GetPtr(DWORD, this, pVars->UBoolProperty_BitMask);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"BoolProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};