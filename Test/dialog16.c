#include "stdafx.h"

//--------------------------------------------------------------------------
//  Cropping and Scaling Images
//
//  This sample demonstrates on how to crop and scale images usin GDI+ C.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc16(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Cropping and Scaling Images");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics);

        Image * image;
        Image_LoadFromFile(L"Apple.gif", FALSE, &image);
        UINT width = Image_GetWidth(image);
        UINT height = Image_GetHeight(image);
        // Make the destination rectangle 30 percent wider and
        // 30 percent taller than the original image.
        // Put the upper-left corner of the destination
        // rectangle at (150, 20).
        Rect destRect = { 150, 20, 1.3 * width, 1.3 * height };
        // Draw the image unaltered with its upper-left corner at (0, 0).
        Graphics_DrawImage(graphics, image, 0, 0);
        // Draw a portion of the image. Scale that portion of the image
        // so that it fills the destination rectangle.
        Graphics_DrawImageRectRectI(
            graphics,
            image,
            &destRect,
            0, 0,               // upper-left corner of source rectangle
            0.75 * width,       // width of source rectangle
            0.75 * height,      // height of source rectangle
            UnitPixel,
            NULL, NULL, NULL
        );

        // Delete objects.
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