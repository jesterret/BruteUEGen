// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

class CVars* pVars = nullptr;
class UEGenBase* pGen = nullptr;
class UObject* pCorePackage = nullptr;

enum EngineMajorVersion
{
    UE2,
    UE3,
    UE4
};
enum GenerationMethod
{
    Field,
    Method
};

DWORD CALLBACK OnAttach(LPVOID p)
{
    HMODULE hMod = HMODULE(p);

    //pGen = new SDKGenMaker(UE4, Method);
    //if (pGen)
    //    pGen->Generate();

    FreeLibraryAndExitThread(hMod, 0);
    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, OnAttach, hModule, 0, nullptr);
    }
    return TRUE;
}
