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

    WCHAR szBuffer[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, szBuffer);

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
        
        if (Graphics_CreateFromHDC(hdc, &g) == Ok)
        {
            Matrix * transform;
            Matrix_Create(&transform);
            Matrix_Rotate(transform, 20.0f, MatrixOrderPrepend);

            Graphics_SetSmoothingMode(g, SmoothingModeHighQuality);
            //Graphics_SetTransform(g, transform);

            Image * img;
            UINT width, height;

            Image_LoadFromFile(L"Test.bmp", FALSE, &img);
            width = Image_GetWidth(img);
            height = Image_GetHeight(img);

            Rect rc;
            rc.X = 0;
            rc.Y = 0;
            rc.Width = width;
            rc.Height = height;

            ColorMatrix colorMatrix = {
                1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.5f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f, 1.0f
            };

            ImageAttributes * imgAttr;
            ImageAttributes_Create(&imgAttr);
            ImageAttributes_SetColorMatrix(imgAttr, &colorMatrix, 
                                           ColorMatrixFlagsDefault, 
                                           ColorAdjustTypeDefault);

            Graphics_DrawImageRectRectI(g, img, &rc, 0, 0, width, height, 
                                        UnitPixel, imgAttr, NULL, NULL);

            ImageAttributes_Dispose(imgAttr);
            Image_Dispose(img);
            Matrix_Delete(transform);
        }

        Graphics_Delete(g);

        // End Draw

        EndPaint(hWnd, &ps);

        return 0;
    }
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}