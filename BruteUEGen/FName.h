#pragma once
#include "stdafx.h"
#include "TArray.h"
#include "FNameEntry.h"

extern UEGenBase* pGen;

struct FName
{
    int Index;

    FName() : Index(-1) {};
    FName(int i) : Index(i) {};
    FName(wchar_t* FindName)
    {
        static std::vector<int> NameCache;

        for (ULONG_PTR i = 0; i < NameCache.size(); i++)
        {
            if (pGen->GetName(NameCache[i])->Name() == FindName)
            {
                Index = NameCache[i];
                return;
            }
        }

        for (LONG_PTR i = 0; i < pGen->GetNameCount(); i++)
        {
            if (pGen->GetName(i))
            {
                if (pGen->GetName(Index)->Name() == FindName)
                {
                    NameCache.push_back(i);
                    Index = i;
                }
            }
        }
    };
    ~FName() {};

    wstr GetName()
    {
        if ((Index < 0 || Index > pGen->GetNameCount()) && !pGen->GetName(Index))
            return L"UnknownName";
        else
            return pGen->GetName(Index)->Name();
    };

    bool operator == (FName& A) 
    {
        return (Index == A.Index);
    };
    bool operator != (FName& A) 
    {
        return (Index != A.Index);
    };
    bool operator == (const FName& A) const
    {
        return (Index == A.Index);
    };
    bool operator != (const FName& A) const
    {
        return (Index != A.Index);
    };
};