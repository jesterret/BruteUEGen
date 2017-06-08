// stdafx.cpp : source file that includes just the standard includes
// BruteUEGen.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#pragma comment(lib, "Pathcch.lib")

template <typename T> T*& Cast(UObject* pObj)
{
    return pObj && pObj->IsA(T::StaticClass()) ? (T*)pObj : nullptr;
}