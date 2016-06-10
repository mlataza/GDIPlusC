//---------------------------------------------------------------------------
//
//  This is a simple demonstration on how to use the GDI+ C library.
//
//  GDIPlusC.dll should be in the .exe's directory.
//
//  Samples codes are found in dialog(n).c, e.g. dialog1.c.
//
//  All samples are copied from Microsoft's Using GDI+ (Windows) article. 
//  https://msdn.microsoft.com/en-us/library/windows/desktop/ms533802(v=vs.85).aspx
//---------------------------------------------------------------------------

#include "stdafx.h"

// Enable visual styles.
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

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
                             L"GDI+ C Samples",
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             500, 500,
                             NULL, NULL, NULL, NULL);

    ShowWindow(hWnd, nShowCmd);
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

typedef struct
{
    WCHAR szSampleTitle[80]; // The title of the sample.
    DLGPROC fnDlgProc; // The associated dialog procedure for that sample.
} Sample;

Sample Samples[] = {
    {L"1. Drawing a Line", DialogProc1},
    {L"2. Drawing a String", DialogProc2},
    {L"3. Using a Pen to Draw Lines and Rectangles", DialogProc3},
    {L"4. Setting Pen Width and Alignment", DialogProc4},
    {L"5. Drawing a Line with Line Caps", DialogProc5},
    {L"6. Joining Lines", DialogProc6},
    {L"7. Drawing a Custom Dashed Line", DialogProc7},
    {L"8. Drawing a Line Filled with a Texture", DialogProc8},
    {L"9. Filling a Shape with a Solid Color", DialogProc9},
    {L"10. Filling a Shape with a Hatch Pattern", DialogProc10},
    {L"11. Filling a Shape with an Image Texture", DialogProc11},
    {L"12. Tiling a Shape with an Image", DialogProc12},
    {L"13. Loading and Displaying Bitmaps", DialogProc13},
    {L"14. Loading and Displaying Metafiles", DialogProc14},
    {L"15. Recording Metafiles", DialogProc15},
    {L"16. Cropping and Scaling Images", DialogProc16},
    {L"17. Rotating, Reflecting, and Skewing Images", DialogProc17},
    {L"18. Using Interpolation Mode to Control Image Quality During Scaling", DialogProc18},
    {L"19. Creating Thumbnail Images", DialogProc19},
    {L"20. Using a Cached Bitmap to Improve Performance", DialogProc20}
};

#define MARGIN      8
#define BTN_WIDTH   100
#define BTN_HEIGHT  30

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hListbox;
    static HWND hButton;
    static HWND hDlg;
    static int cx, cy;

    switch (msg)
    {
    case WM_CREATE:
    {
        // Create my list box.
        hListbox = CreateWindow(L"Listbox", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER,
                                MARGIN, MARGIN, 0, 0, hWnd, NULL, NULL, NULL);

        int i, pos;
        // Add the items into the list box.
        for (i = 0; i < ARRAYSIZE(Samples); i++)
        {
            pos = (int)SendMessage(hListbox, LB_ADDSTRING, 0,
                (LPARAM)Samples[i].szSampleTitle);

            SendMessage(hListbox, LB_SETITEMDATA, pos, (LPARAM)i);
        }

        // Create the button.
        hButton = CreateWindow(L"Button", L"Open Sample", WS_CHILD | WS_VISIBLE | WS_BORDER,
                               0, 0, BTN_WIDTH, BTN_HEIGHT, hWnd, (HMENU)1, 
                               NULL, NULL);

        return 0;
    }
    case WM_SIZE:
    {
        cx = LOWORD(lParam);
        cy = HIWORD(lParam);


        HDWP hdwp = BeginDeferWindowPos(2);

        hdwp = DeferWindowPos(hdwp, hListbox, NULL, 0, 0,
                              cx - 2 * MARGIN, cy - (3 * MARGIN) - BTN_HEIGHT,
                              SWP_NOMOVE);

        hdwp = DeferWindowPos(hdwp, hButton, NULL, cx - BTN_WIDTH - MARGIN,
                              cy - BTN_HEIGHT - MARGIN, 0, 0, SWP_NOSIZE);

        EndDeferWindowPos(hdwp);

        return 0;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == 1)
        {
            int lbItem = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0);
            int i = (int)SendMessage(hListbox, LB_GETITEMDATA, lbItem, 0);

            if (i != -1)
            {
                DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hWnd,
                          Samples[i].fnDlgProc); 
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