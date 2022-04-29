// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#define _T(x) L##x

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void Hello(HWND hwnd)
{
    MessageBox(
        hwnd,
        _T("Hello world"),
        _T("Hello from dll"),
        MB_OK
        );
}