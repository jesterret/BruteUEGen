#pragma once
#include "UProperty.h"

class UDoubleProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"DoubleProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};