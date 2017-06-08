#pragma once
#include "UProperty.h"

class UPointerProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"PointerProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};