#pragma once
#include "UProperty.h"

class UFloatProperty : public UProperty
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"FloatProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};