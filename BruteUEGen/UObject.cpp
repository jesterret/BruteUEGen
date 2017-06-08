#include "stdafx.h"
#include "UObject.h"
#include "UStruct.h"
#include "UClass.h"

wstr UObject::GetName()
{
    return pGen->GetName(Name().Index)->Name();
}
wstr UObject::GetNameCPP()
{
    if (IsA(UClass::StaticClass()))
    {
        UClass* pClass = (UClass*)this;
        while (pClass)
        {
            if (pClass->GetName() == TEXT("Actor"))
                return fmt::format(L"A{}", GetName());
            else if (pClass->GetName() == TEXT("Object"))
                return fmt::format(L"U{}", GetName());

            pClass = (UClass*)pClass->SuperField();
        }
    }
    else
        return fmt::format(L"F{}", GetName());

    return wstr();
}
wstr UObject::GetFullName()
{
    if (this->Class() && this->Outer())
    {
        return fmt::format(L"{0} {1}.{2}", Class()->GetName(), GetOuter(this->Outer()), GetName());
    }
    return TEXT("(null)");
}
wstr UObject::GetOuter(UObject* pOuter)
{
    if (pOuter)
    {
        return fmt::format(L"{0}.{1}", GetOuter(pOuter->Outer()), pOuter->GetName());
    }
    return wstr();
}
bool UObject::IsA(UField* pClass)
{
    if (pClass)
    {
        for (UStruct* SuperClass = Class(); SuperClass; SuperClass = (UStruct*)SuperClass->SuperField())
        {
            if (SuperClass == pClass)
                return true;
        }
    }
    return false;
}

UClass* UObject::StaticClass()
{
    static UClass* pClass = nullptr;
    if (!pClass)
        pClass = UObject::FindClass(L"Object", pCorePackage);

    return pClass;
}