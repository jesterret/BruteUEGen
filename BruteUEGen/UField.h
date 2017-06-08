#pragma once
#include "UObject.h"

class UField : public UObject
{
public:
    UField* Next()
    {
        return GetPtr(UField*, this, pVars->UField_Next);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        if (!pClass)
            pClass = UObject::FindClass(L"Field", pCorePackage);

        return pClass;
    }
};