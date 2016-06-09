#include "stdafx.h"

//--------------------------------------------------------------------------
//  Loading and Displaying Bitmaps
//
//  This sample demonstrates on loading and drawing images and bitmaps.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc13(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, L"Loading and Displaying Bitmaps");
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

        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics);

        // To display a raster image on the screen, you need an Image object and
        // a Graphics object. 
        Image * image;
        Image_LoadFromFile(L"HouseAndTree.png", FALSE, &image); 
        // The image file is relative to the current directory.
        
        Graphics_DrawImage(graphics, image, 10, 10);

        // The Image object provides basic methods for loading and displaying
        // raster images and vector images. The Bitmap object, which is based 
        // from the Image object, provides more specialized methods on loading,
        // displaying, and manipulating raster images.

        HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
        Bitmap * bitmap;
        Bitmap_CreateFromHICON(hIcon, &bitmap);
        Graphics_DrawImage(graphics, bitmap, 100, 10);

        // Delete objects.
        Bitmap_Dispose(bitmap);
        Image_Dispose(image);
        Graphics_Delete(graphics);

        EndPaint(hWnd, &ps);
        return TRUE;
    }
    case WM_CLOSE:
    {
        EndDialog(hWnd, 0);
        return TRUE;
    }
    default:
        return FALSE;
    }
}