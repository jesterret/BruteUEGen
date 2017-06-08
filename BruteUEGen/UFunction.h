#pragma once
#include "UProperty.h"

class UFunction : public UProperty
{
public:
    DWORD FunctionFlags()
    {
        return GetPtr(DWORD, this, pVars->UFunction_FunctionFlags);
    }
    BYTE NumParams()
    {
        return GetPtr(BYTE, this, pVars->UFunction_NumParms);
    }
    WORD ParmsSize()
    {
        return GetPtr(WORD, this, pVars->UFunction_ParamsSize);
    }
    WORD ReturnValueOffset()
    {
        return GetPtr(WORD, this, pVars->UFunction_ReturnValueOffset);
    }
    template <typename T> T Func()
    {
        return GetPtr(T, this, pVars->UFunction_Func);
    }
    void* Func()
    {
        return this->Func<void*>();
    }

    static UClass* StaticClass()
    {
        static UClass* pClass = nullptr;
        if (!pClass)
            pClass = UObject::FindClass(L"Function", pCorePackage);

        return pClass;
    }
};