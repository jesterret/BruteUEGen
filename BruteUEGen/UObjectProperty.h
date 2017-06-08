#pragma once
#include "UProperty.h"

class UObjectProperty : public UProperty
{
public:
    UClass* PropertyClass()
    {
        return GetPtr(UClass*, this, pVars->UObjectProperty_PropertyClass);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"ObjectProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};