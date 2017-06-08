#pragma once
#include "UProperty.h"

class UStrProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"StrProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};