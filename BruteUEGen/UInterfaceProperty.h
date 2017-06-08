#pragma once
#include "UProperty.h"

class UInterfaceProperty : public UProperty
{
public:
    UClass* InterfaceClass()
    {
        return GetPtr(UClass*, this, pVars->UInterfaceProperty_InterfaceClass);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"InterfaceProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};