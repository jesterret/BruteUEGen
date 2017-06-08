#pragma once
#include "UObject.h"

class UClass : public UStruct
{
public:
    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        if (!pClass)
            pClass = UObject::FindClass(L"Class", pCorePackage);

        return pClass;
    }
};