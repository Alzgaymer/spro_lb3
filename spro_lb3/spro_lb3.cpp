#include "headers.h"
#include "resource.h"

// for correct work need c++20 or newer
// UNICODE character set
// and Linker\system\subsystem\windows

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;
	//fill window class
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	//register main window 
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);
		throw;
	}
	HWND hwnd;
	hwnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		szWindowClass,
		_T("WinProject"),
		WS_OVERLAPPEDWINDOW,
		//centerized window
		MaxPixelsFSX / 2 - MaxPixelsFSX / 4, MaxPixelsFSY / 2 - MaxPixelsFSY / 4,
		MaxPixelsFSX / 2, MaxPixelsFSY / 2,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hwnd)
	{
		MessageBox(NULL,
			_T("Call to project::Create_Window failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);
		throw;
	}
	
	ShowWindow(hwnd,
		nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);	
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	HINSTANCE dllC, dllF;
	

	HDC WindowDC;
	WindowDC = GetDC(hWnd);
	switch (message)
	{
	case WM_CREATE:
		
		break;
	case WM_CHAR:

		TemporaryDC = CreateCompatibleDC(WindowDC);

		BitmapDC = CreateCompatibleBitmap(WindowDC, rt.right - rt.left, rt.bottom - rt.top);
		//take bitmap as a dc
		SelectObject(TemporaryDC, BitmapDC);

		
		dllC = LoadLibrary(_T("dllColor.dll"));
		dllF = LoadLibrary(_T("dllFont.dll"));
		if (!dllC||!dllF)
		{
			MessageBox(hWnd, L"Cannot open dll", L"spro_lb3 error", MB_ICONSTOP);
		}
		typedef void (*dllColor) (HDC);
		typedef void (*dllFont) (std::wstring);

		dllColor randomTextColour;
		dllFont changeCase;
		randomTextColour = (dllColor)GetProcAddress(dllC, "RandomTextColour");
		changeCase = (dllFont)GetProcAddress(dllF, "ChangeCase");

		
		KeyboardBuffer.push_back((TCHAR)wParam);
		changeCase(KeyboardBuffer);
		//for (size_t i = 0; i < KeyboardBuffer.size(); i++)
		//{
			randomTextColour(TemporaryDC);
			DrawText(TemporaryDC, &KeyboardBuffer[0], KeyboardBuffer.size(), &rt, 0);
		//}
		SetWindowText(hWnd, &KeyboardBuffer[0]);
		//copy dc(bitmap) to hdc(our screen)
		BitBlt(WindowDC, 0, 0, rt.right - rt.left, rt.bottom - rt.top, TemporaryDC, 0, 0, SRCCOPY);
		FreeLibrary(dllC);
		FreeLibrary(dllF);
		DeleteDC(TemporaryDC);
		DeleteObject(BitmapDC);
		break;
	case WM_SIZE:
		GetClientRect(hWnd, &rt);
		Draw(WindowDC);
		break;
	case WM_DESTROY:
		
		PostQuitMessage(69);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

}

void Draw(HDC WindowDC)
{
	HINSTANCE dllC = LoadLibrary(_T("dllColor.dll"));

	if (!dllC)
	{
		MessageBox(0, L"Cannot open dll", L"spro_lb3 error", MB_ICONSTOP);
	}
	typedef void (*dllColor) (HDC);
	

	dllColor randomTextColour;
	randomTextColour = (dllColor)GetProcAddress(dllC, "RandomTextColour");
	TemporaryDC = CreateCompatibleDC(WindowDC);

	BitmapDC = CreateCompatibleBitmap(WindowDC, rt.right - rt.left, rt.bottom - rt.top);
	//take bitmap as a dc
	SelectObject(TemporaryDC, BitmapDC);

	randomTextColour(TemporaryDC);
	DrawText(TemporaryDC, &KeyboardBuffer[0], KeyboardBuffer.size(), &rt, 0);

	BitBlt(WindowDC, 0, 0, rt.right - rt.left, rt.bottom - rt.top, TemporaryDC, 0, 0, SRCCOPY);

	DeleteDC(TemporaryDC);
	DeleteObject(BitmapDC);
	FreeLibrary(dllC);
}