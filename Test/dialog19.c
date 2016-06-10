#include "stdafx.h"

//--------------------------------------------------------------------------
//  Creating Thumbnail Images
//
//  This sample demonstrates on how to create a thumbnail using the 
//  Image_GetThumbnailImage function.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc19(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Creating Thumbnail Images");
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

        Image * image = Image_LoadFromFile(L"Apple.gif", FALSE);

        // Create a thumbnail image with a width of 60 and height of 60.
        Image * thumbnail = Image_GetThumbnailImage(image, 60, 60, NULL, NULL);

        Graphics_DrawImageRect(graphics, thumbnail, 10.0f, 10.0f,
            (REAL)Image_GetWidth(thumbnail),
            (REAL)Image_GetHeight(thumbnail));

        // Delete objects.
        Image_Dispose(thumbnail);
        Image_Dispose(image);
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