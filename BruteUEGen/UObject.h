#pragma once
#include "stdafx.h"
#include "FName.h"

class UClass;
class UField;

class UObject
{
    wstr GetOuter(UObject* pOuter);
    static bool IsValidObject(UObject* pOuter, wchar_t *text)
    {
        return pOuter && (pOuter->Name() == text || text == nullptr);
    }
    static bool IsValidObject(UObject* pOuter, std::nullptr_t)
    {
        return true;
    }
    static bool IsValidObject(UObject* pOuter, UObject* pObject)
    {
        return pOuter && (pOuter == pObject || pOuter->IsA((UField*)pObject));
    }
    template <typename ...args_t> static bool IsValidObject(UObject* pOuter, wchar_t* text, args_t ...args)
    {
        if (pOuter && (text == nullptr || pOuter->Name() == text))
            return IsValidObject(pOuter->Outer(), args...);

        return false;
    }
    template <typename ...args_t> static bool IsValidObject(UObject* pOuter, std::nullptr_t, args_t ...args)
    {
        if (pOuter)
            return IsValidObject(pOuter->Outer(), args...);

        return false;
    }
    template <typename ...args_t> static bool IsValidObject(UObject* pOuter, UObject* pObject, args_t ...args)
    {
        if (pOuter && (pOuter == pObject || pOuter->IsA((UField*)pObject)))
            return IsValidObject(pOuter->Outer(), args...);

        return false;
    }
public:
    template <class T, typename ...args_t> static T* FindObject(wchar_t* ObjName, args_t ...args)
    {
        for (DWORD i = 0; i < pGen->GetObjectCount(); i++)
        {
            UObject* pObject = pGen->GetObject(i);

            if (!Cast<T>(pObject))
                continue;

            if (pObject->Name() == ObjName && IsValidObject(pObject->Outer(), args...))
                return (T*)pObject;
        }
        return nullptr;
    }
    template <typename ...args_t> static UClass* FindClass(wchar_t* ObjName, args_t ...args)
    {
        for (LONG_PTR i = 0; i < pGen->GetObjectCount(); i++)
        {
            UObject* pObject = pGen->GetObject(i);

            if (pObject && pObject->Name() == ObjName)
                if (IsValidObject(pObject->Outer(), args...))
                    return (UClass*)pObject;
        }
        return nullptr;
    }

    wstr GetName();
    wstr GetNameCPP();
    wstr GetFullName();

    wstr GetPackageName()
    {
        return GetOutermost()->GetName();
    }
    UObject* GetOutermost()
    {
        UObject* pRet = this;
        while (pRet->Outer())
        {
            pRet = pRet->Outer();
        }
        return pRet;
    }

    QWORD& ObjectFlags()
    {
        return GetPtr(QWORD, this, pVars->UObject_ObjectFlags);
    }
    int& ObjectInternalInteger()
    {
        return GetPtr(int, this, pVars->UObject_ObjectInternalInteger);
    }
    UClass*& Class()
    {
        return GetPtr(UClass*, this, pVars->UObject_Class);
    }
    UObject*& Outer()
    {
        return GetPtr(UObject*, this, pVars->UObject_Outer);
    }
    FName& Name()
    {
        return GetPtr(FName, this, pVars->UObject_Name);
    }

    bool IsA(UField* pClass);
    
    static UClass* StaticClass();
};
extern class UObject* pCorePackage;