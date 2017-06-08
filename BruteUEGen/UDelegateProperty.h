#pragma once
#include "UProperty.h"

class UDelegateProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"DelegateProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};