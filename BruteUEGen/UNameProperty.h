#pragma once
#include "UProperty.h"

class UNameProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"NameProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};