#pragma once
#include "UField.h"

class UStruct : public UField
{
public:
    UField* Children()
    {
        return GetPtr(UField*, this, pVars->UStruct_Children);
    }
    UField* SuperField()
    {
        return GetPtr(UField*, this, pVars->UStruct_SuperField);
    }
    DWORD PropertySize()
    {
        return GetPtr(DWORD, this, pVars->UStruct_PropertySize);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        if (!pClass)
            pClass = UObject::FindClass(L"Struct", pCorePackage);

        return pClass;
    }
};