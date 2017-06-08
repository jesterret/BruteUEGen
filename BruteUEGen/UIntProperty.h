#pragma once
#include "UProperty.h"

class UIntProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"IntProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};