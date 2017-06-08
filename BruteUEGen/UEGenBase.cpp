#include "stdafx.h"

bool UEGenBase::GenDirRecursive(const wchar_t* Dir)
{
    if (!Dir)
        return false;

    wchar_t canonpath[MAX_PATH] = { L'\0' };

    PathCchCanonicalize(canonpath, MAX_PATH, Dir);
    auto x = canonpath;
    while (*x != L'\0')
    {
        if (*x == L'\\')
            *x = L'/';

        x++;
    }

    wchar_t folder[MAX_PATH] = { L'\0' };
    auto end = wcschr(Dir, L'/');
    while (end != nullptr)
    {
        wcscpy_s(folder, canonpath);

        if (!_wmkdir(folder))
            if (GetLastError() == ENOENT)
                return false;

        end = wcschr(++end, L'/');
    }
    return true;
}
bool UEGenBase::GenDirRecursive(wchar_t* Dir)
{
    if (!Dir)
        return false;

    wchar_t canonpath[MAX_PATH] = { L'\0' };

    auto x = Dir;
    while (*x != L'\0')
    {
        if (*x == L'\\')
            *x = L'/';

        x++;
    }

    PathCchCanonicalize(canonpath, MAX_PATH, Dir);

    wchar_t folder[MAX_PATH] = { L'\0' };
    wchar_t *end = wcschr(Dir, L'/');
    while (end != nullptr)
    {
        wcscpy_s(folder, canonpath);

        if (!_wmkdir(folder))
            if (GetLastError() == ENOENT)
                return false;

        end = wcschr(++end, L'/');
    }
    return true;
}

wstr UEGenBase::GetType(UObject* pProp, bool bFunc, bool bAddTypes)
{
    if (pProp)
    {
        for (auto& Type : DefinedTypes)
        {
            if(Type.first)
                if (pProp->IsA((UField*)Type.first))
                    return Type.second(pProp, bFunc, bAddTypes);
        }
    }
    return wstr();
}

void UEGenBase::RegisterTypes()
{
    DefinedTypes[UBoolProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        if (bFunc)
            return TEXT("bool");
        else
            return TEXT("BitManager");
    };
    DefinedTypes[UIntProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return L"int32_t";
    };
    DefinedTypes[UFloatProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return L"float";
    };
    DefinedTypes[UDoubleProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return L"double";
    };
    DefinedTypes[UPointerProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return L"void*";
    };
    DefinedTypes[UNameProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return (bAddTypes ? L"struct " : wstr()) + L"FName";
    };
    DefinedTypes[UStrProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return (bAddTypes ? L"struct " : wstr()) + L"FString";
    };
    DefinedTypes[UDelegateProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        return (bAddTypes ? L"struct " : wstr()) + L"FDelegate";
    };
    DefinedTypes[UStructProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UStructProperty*)pProp;
        return (bAddTypes ? L"struct " : wstr()) + p->GetNameCPP();
    };
    DefinedTypes[UClassProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UClassProperty*)pProp;
        return (bAddTypes ? L"class " : wstr()) + p->MetaClass()->GetNameCPP() + L"*";
    };
    DefinedTypes[UObjectProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UObjectProperty*)pProp;
        return (bAddTypes ? L"class " : wstr()) + p->PropertyClass()->GetNameCPP() + L"*";
    };
    DefinedTypes[UInterfaceProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UInterfaceProperty*)pProp;
        return (bAddTypes ? L"class " : wstr()) + p->InterfaceClass()->GetNameCPP() + L"*";
    };
    DefinedTypes[UArrayProperty::StaticClass()] =
        [&](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UArrayProperty*)pProp;
        auto Inner = GetType(p->Inner());
        if (!Inner.empty())
            return (bAddTypes ? TEXT("struct ") : wstr()) + TEXT("TArray<") + Inner + TEXT(">");
        else
            return wstr();
    };
    DefinedTypes[UMapProperty::StaticClass()] =
        [](UObject* pProp, bool bFunc, bool bAddTypes) -> wstr
    {
        auto p = (UMapProperty*)pProp;
        return L"*";
    };
}

bool UEGenBase::Init(wchar_t* Game)
{
    return true;
}
void UEGenBase::Generate(wchar_t* Directory /*= nullptr*/, wchar_t* GameName /*= nullptr*/)
{
    wchar_t Game[_MAX_FNAME] = { TEXT('\0') };

    if (Directory)
        wcscpy_s(DefaultDir, Directory);

    if (GameName == nullptr)
    {
        wchar_t GameDir[MAX_PATH] = { L'\0' };
        GetModuleFileName(GetModuleHandle(nullptr), GameDir, MAX_PATH - 1);
        _wsplitpath_s(GameDir, nullptr, 0, nullptr, 0, Game, _MAX_FNAME - 1, nullptr, 0);
        GameName = Game;
    }
    wcscat_s(DefaultDir, GameName);
    wcscat_s(DefaultDir, L"/");

    if (GenDirRecursive(DefaultDir))
    {
        InitSignatures();
        if (Init(GameName) && InitOffsets())
        {
            CustomInitialization();
            ProcessPackages();
            FinalizeGeneration();
        }
    }
}
