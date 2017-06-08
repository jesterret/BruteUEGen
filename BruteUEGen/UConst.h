#pragma once
#include "TArray.h"
#include "UField.h"

class UConst : public UField
{
public:
    FString& Value()
    {
        return GetPtr(FString, this, pVars->UConst_Value);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        static bool TypeIsPresent = true;
        if (!pClass && TypeIsPresent)
        {
            pClass = UObject::FindClass(L"Const", pCorePackage);
            TypeIsPresent = !!pClass;
        }

        return pClass;
    }
};