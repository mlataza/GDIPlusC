#include "stdafx.h"

//-------------------------------------------------------------------------
//  Using a Cached Bitmap to Improve Performance
//
//  This sample demonstrates on how to use the CachedBitmap object.
//-------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc20(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, 
                             L"Using a Cached Bitmap to Improve Performance - DO NOT RESIZE!!!");

        SetWindowPos(hWnd, NULL, 0, 0, 600, 600, SWP_NOREDRAW | SWP_NOMOVE);
        return TRUE;
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * graphics = Graphics_CreateFromHDC(hdc);

        // Image and Bitmap objects store images in a device-independent format.
        // A CachedBitmap object stores an image in the format of the current
        // display device. Rendering an image stored in a CachedBitmap object
        // is fast because no processing is spent converting the image to the
        // format required by the display device.

        Bitmap * bitmap = Bitmap_CreateFromFile(L"GrapeBunch.bmp", FALSE);
        UINT width = Bitmap_GetWidth(bitmap);
        UINT height = Bitmap_GetHeight(bitmap);
        CachedBitmap * cBitmap = CachedBitmap_Create(bitmap, graphics);

        int j, k;
        for (j = 0; j < 300; j += 10)
            for (k = 0; k < 1000; k++)
                Graphics_DrawImageRectI(graphics, bitmap, j, j / 2, width, height);
        for (j = 0; j < 300; j += 10)
            for (k = 0; k < 1000; k++)
                Graphics_DrawCachedBitmap(graphics, cBitmap, j, 150 + j / 2);

        // A CachedBitmap object matches the format of the display device at 
        // the time the CachedBitmap object was constructed. If the user of your 
        // program changes the display settings, your code should construct a 
        // new CachedBitmap object. The Graphics_DrawCachedBitmap function will 
        // fail if you pass it a CachedBitmap object that was created prior to 
        // a change in the display format.

        // Delete the objects.
        CachedBitmap_Delete(cBitmap);
        Bitmap_Dispose(bitmap);
        Graphics_Delete(graphics);

        EndPaint(hWnd, &ps);
        return TRUE;
    }
    case WM_CLOSE:
    {
        return EndDialog(hWnd, 0);
    }
    default:
        return FALSE;
    }
}