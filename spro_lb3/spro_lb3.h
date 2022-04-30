#pragma once
#include "headers.h"
#pragma region global variables
static TCHAR szWindowClass[] = _T("Title");
static const auto MaxPixelsFSX = GetSystemMetrics(SM_CXFULLSCREEN);
static const auto MaxPixelsFSY = GetSystemMetrics(SM_CYFULLSCREEN);


static /*std::vector<wchar_t> */ std::wstring KeyboardBuffer;
static RECT rt;
static HDC TemporaryDC;
static HBITMAP BitmapDC;
#pragma endregion

LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

void Draw(HDC);