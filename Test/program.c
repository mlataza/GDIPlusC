#define _USE_MATH_DEFINES
#include <math.h>

#include <Windows.h>
#include "..\GDI+ C\gdiplusc.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPWSTR pCmdLine, int nShowCmd)
{
    WNDCLASSEX wcex;
    wcex.cbClsExtra = 0;
    wcex.cbSize = sizeof(wcex);
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = NULL;
    wcex.hIconSm = NULL;
    wcex.hInstance = NULL;
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = L"GDIPlus_Test";
    wcex.lpszMenuName = NULL;
    wcex.style = 0;

    if (!RegisterClassEx(&wcex))
    {
        return -1;
    }

    GdiplusStartupInput input;
    input.GdiplusVersion = 1;
    input.DebugEventCallback = NULL;
    input.SuppressBackgroundThread = FALSE;
    input.SuppressExternalCodecs = FALSE;

    ULONG_PTR token;

    GdipluscStartup(&token, &input, NULL);

    HWND hWnd = CreateWindow(L"GDIPlus_Test",
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

    GdipluscShutdown(token);

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Draw here using GDI+ C.

        Graphics * g;
        Graphics_CreateFromHDC(hdc, &g);
        Graphics_SetSmoothingMode(g, SmoothingModeAntiAlias);

        Pen * blue;
        Pen_Create(0xff0000ff, 1.0f, &blue);

        Pen * red;
        Pen_Create(0xffff0000, 1.0f, &red);

        int y = 256;
        int x;

        for (x = 0; x < 256; x += 5)
        {
            Graphics_DrawLineI(g, blue, 0, y, x, 0);
            Graphics_DrawLineI(g, red, 256, x, y, 256);
        }

        Pen * pen = NULL;
        Pen_Create(0xffffffff, 1.0f, &pen);

        for (y = 0; y < 256; y++)
        {
           Pen_SetColor(pen, ARGB(y, 0, 255, 0));

            Graphics_DrawLineI(g, pen, 0, y, 256, y);
        }

        for (x = 0; x < 256; x++)
        {
            Pen_SetColor(pen, ARGB(x, 255, 0, 255));

            Graphics_DrawLineI(g, pen, x, 100, x, 200);
        }

        Pen_Delete(pen);
        Pen_Delete(red);
        Pen_Delete(blue);
        Graphics_Delete(g);

        // End Draw

        EndPaint(hWnd, &ps);

        return 0;
    }
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}