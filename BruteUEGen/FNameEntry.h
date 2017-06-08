#pragma once
#include "stdafx.h"

class FNameEntry
{
    bool IsWide()
    {
        return pVars->FNameEntry_ForceWide || Flags() & pVars->FNameEntry_WideString;
    }
    DWORD Flags()
    {
        return GetPtr(DWORD, this, pVars->FNameEntry_Flags);
    }
    CHAR* AnsiName()
    {
        return GetPtr(CHAR*, this, pVars->FNameEntry_NameAddress);
    }
    WCHAR* WideName()
    {
        return GetPtr(WCHAR*, this, pVars->FNameEntry_NameAddress);
    }
public:
    wstr Name()
    {
        if (IsWide())
            return fmt::format(L"{}", WideName());
        else
            return fmt::format(L"{}", AnsiName());
    }
};