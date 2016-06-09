//---------------------------------------------------------------------------
//
// This is a simple demonstration on how to use the GDI+ C library.
//
// GDIPlusC.dll should be in the exe's directory.
//
// Samples codes are found in dialog(n).c, e.g. dialog1.c.
//---------------------------------------------------------------------------

#include "stdafx.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPWSTR pCmdLine, int nShowCmd)
{
    WNDCLASSEX wcex;
    wcex.cbClsExtra = 0;
    wcex.cbSize = sizeof(wcex);
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = NULL;
    wcex.hIconSm = NULL;
    wcex.hInstance = NULL;
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = L"GDIPlusC Test Window";
    wcex.lpszMenuName = NULL;
    wcex.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&wcex))
    {
        return -1;
    }

    //
    //  Initialize GDI+.
    //
    GdiplusStartupInput input;
    input.GdiplusVersion = 1; 
    input.DebugEventCallback = NULL; 
    input.SuppressBackgroundThread = FALSE;  
    input.SuppressExternalCodecs = FALSE;

    ULONG_PTR token;

    GdipluscStartup(&token, &input, NULL); // Call this function to start GDI+ C.

    HWND hWnd = CreateWindow(L"GDIPlusC Test Window",
                             L"Testing",
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             NULL, NULL, NULL, NULL);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //
    //  Closing GDI+ C.
    //
    GdipluscShutdown(token); // Call this function before the application exits.

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        // Create my buttons.
        INT x = 8, y = 8;

        CreateWindow(L"Button", L"Drawing a Line", WS_CHILD | WS_VISIBLE,
                     x, y, 150, 50, 
                     hWnd, (HMENU)1, NULL, NULL);
        x += 150 + 8;

        CreateWindow(L"Button", L"Drawing a String", WS_CHILD | WS_VISIBLE,
                     x, y, 150, 50,
                     hWnd, (HMENU)2, NULL, NULL);
        x = 8;
        y += 50 + 8;

        CreateWindow(L"Button", L"Using a Pen to Draw Lines and Rectangles",
                     WS_CHILD | WS_VISIBLE, x, y, 308, 50,
                     hWnd, (HMENU)3, NULL, NULL);
        x += 308 + 8;



        return 0;
    }
    case WM_COMMAND:
    {
        if (HIWORD(wParam) == BN_CLICKED)
        {
            switch (LOWORD(wParam))
            {
            case 1:
                DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProc1);
                break;
            case 2:
                DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProc2);
                break;
            case 3:
                DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProc3);
                break;
            }
        }
        return 0;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}