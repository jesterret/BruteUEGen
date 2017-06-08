#pragma once
#include "stdafx.h"

class UClass;
class UObject;
struct Pattern;
class FNameEntry;

struct GameObjects
{
    Pattern GObjectsPattern;
    Pattern GNamesPattern;
    Pattern ProcessEventPattern;
    int Index;
    GameObjects() : bValid(false) {}
    GameObjects(Pattern& Objects, Pattern& Names, Pattern& PE, int PEIndex = -1) : bValid(true), Index(PEIndex), GObjectsPattern(Objects), GNamesPattern(Names), ProcessEventPattern(PE) {}

    operator bool()
    {
        return bValid;
    }
    Pattern& operator[](uint32_t i)
    {
        switch (i)
        {
        case 0:
            return GObjectsPattern;
        case 1:
            return GNamesPattern;
        case 2:
            return ProcessEventPattern;
        default:
            return Pattern();
        }
    }
private:
    bool bValid;
};

class UEGenBase
{
    FILE* f;
    TCHAR DefaultDir[MAX_PATH];

    virtual DWORD_PTR GetGObjectArray(Pattern& GObjectPattern) = NULL;
    virtual DWORD_PTR GetGNamesArray(Pattern& GNamesPattern) = NULL;


    virtual bool Init(wchar_t* Game);
    virtual bool InitOffsets() = NULL;
    virtual void InitSignatures() = NULL;
    virtual void CustomInitialization() = NULL;
    virtual void FinalizeGeneration() = NULL;

    virtual void ProcessPackages() = NULL;
    virtual void PreProcessPackage(UObject* pObj) = NULL;
    virtual void PreProcessPackageObject(UObject* pObj) = NULL;
protected:
    UEGenBase() : DefaultDir(TEXT("C:\\BruteSDK\\"))
    {
        Buffer.buffer().reserve(1 << 26);
    }

    fmt::WMemoryWriter Buffer;
    std::map<UClass*, std::function<wstr(UObject* pProp, bool bFunc, bool bAddTypes)>> DefinedTypes;
    std::map<wstr, GameObjects> GameInfo;

    virtual wstr GetType(UObject* pProp, bool bFunc = false, bool bAddTypes = true);
    virtual void RegisterTypes();

    bool GenDirRecursive(wchar_t* Dir);
    bool GenDirRecursive(const wchar_t* Dir);
public:
    virtual UObject* GetObject(int Index) = NULL;
    virtual LONG_PTR GetObjectCount() = NULL;
    virtual FNameEntry* GetName(int Index) = NULL;
    virtual LONG_PTR GetNameCount() = NULL;

    void Generate(wchar_t* Directory = nullptr, wchar_t* GameName = nullptr);
};

extern UEGenBase* pGen;