#pragma once
#include "UProperty.h"
#include "UEnum.h"

class UByteProperty : public UProperty
{
public:
    UEnum* Enum()
    {
        return GetPtr(UEnum*, this, pVars->UByteProperty_Enum);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"ByteProperty", pCorePackage);
            TypeIsPresent = !!pClass;
        }
        return pClass;
    }
};