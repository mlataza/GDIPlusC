//---------------------------------------------------------------------------
// This is a simple demonstration on how to use the GDIPlusC library.
//---------------------------------------------------------------------------

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
        Graphics_CreateFromHDC(hdc, &g); // Create the graphics object.
        Graphics_SetSmoothingMode(g, SmoothingModeAntiAlias); // Set smoothing mode to anti alias. 
                                                              // This gives you smooth lines.

        Pen * pen;
        Pen_Create(ARGB(128, 255, 0, 0), 2.5f, &pen); // Creates a red pen. This function returns Ok when successful.
                                                      // ARGB creates a color with A - alpha, 
                                                      //                           R - red,
                                                      //                           G - green,
                                                      //                           B - blue
                                                      // You could also represent that color in hex:
                                                      // 0xffff0000
                                                      //   A R G B

        // Let's draw a line now.
        Graphics_DrawLineI(g, pen, 12, 15, 400, 245); // When the function ends with 'I', it uses integer-based coordinates.
                                                      // Otherwise, it uses float-based coordinates. 

        // Let's draw a string.
        FontFamily * family;
        FontFamily_CreateFromName(L"Times New Roman", NULL, &family);

        Font * font;
        Font_Create(family, 24, FontStyleRegular, UnitPixel, &font);

        SolidBrush * brush;
        SolidBrush_Create(Blue, &brush);

        PointF pt;
        pt.X = 160.0f;
        pt.Y = 100.0f;

        Graphics_DrawStringToPoint(g, L"This is a sample text.", -1, font, &pt, NULL, brush);

        // Make sure to delete all the objects when they are not needed.
        Pen_Delete(pen);
        Graphics_Delete(g);
        
        // End Draw

        EndPaint(hWnd, &ps);

        return 0;
    }
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}