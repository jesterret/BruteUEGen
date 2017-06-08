#pragma once
#include "UField.h"

class UProperty : public UField
{
public:
    DWORD ArrayDim()
    {
        return GetPtr(DWORD, this, pVars->UProperty_ArrayDim);
    }
    DWORD ElementSize()
    {
        return GetPtr(DWORD, this, pVars->UProperty_ElementSize);
    }
    DWORD Offset()
    {
        return GetPtr(DWORD, this, pVars->UProperty_Offset);
    }
    DWORD PropertyFlags()
    {
        return GetPtr(DWORD, this, pVars->UProperty_PropertyFlags);
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        if (!pClass)
            pClass = UObject::FindClass(L"Property", pCorePackage);

        return pClass;
    }
};