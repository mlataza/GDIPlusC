#include "stdafx.h"

//--------------------------------------------------------------------------
//  Filling a Shape with an Image Texture
// 
//  This sample demonstrates on how to fill a shape using a texture brush.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc11(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Filling a Shape with an Image Texture");
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

        // You can fill a closed shape with a texture by using the Image object
        // and the TextureBrush object.
        Image * image;
        Image_LoadFromFile(L"Texture1.jpg", FALSE, &image);

        TextureBrush * tBrush;
        TextureBrush_Create(image, WrapModeTile, &tBrush);

        Graphics_FillEllipse(graphics, tBrush, 0, 0, 100, 60);

        // Delete objects.
        TextureBrush_Delete(tBrush);
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