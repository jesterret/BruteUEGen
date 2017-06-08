#pragma once
#include "UField.h"
#include "TArray.h"

class UEnum : public UField
{
public:
    TArray<FName>& Names()
    {
        return GetPtr(TArray<FName>, this, pVars->UEnum_Names);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"Enum", pCorePackage);
            TypeIsPresent = !!pClass;
        }

        return pClass;
    }
};