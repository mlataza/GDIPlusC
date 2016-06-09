#include "stdafx.h"

//-------------------------------------------------------------------------
//  Rotating, Reflecting, and Skewing Images
//
//  This sample discusses and demonstrates on how to apply those transformations
//  to images and metafiles.
//-------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc17(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Rotating, Reflecting, and Skewing Images");
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

        // You can rotate, reflect, and skew an image by specifying the destination
        // points for the upper-left, upper-right, and lower-left corners of the
        // original image. The three destination points determine an affine
        // transformation that maps the original rectangular image to a parallelogram.
        // The lower-right corner of the original image is mapped to the fourth 
        // corner of the parallelogram, which is calculated from the three
        // specified destination points.

        // The following shows the original image and the image mapped to the
        // parallelogram.

        Point destinationPoints[] = {
            {200, 20},
            {110, 100},
            {250, 30}
        };
        Image * image;
        Image_LoadFromFile(L"Stripes.bmp", FALSE, &image);

        // Draw the image unaltered with its upper-left corner at (0, 0).
        Graphics_DrawImageRect(graphics, image, 0, 0, 100, 50);
        // Draw the image mapped to the parallelogram.
        Graphics_DrawImagePointsI(graphics, image, destinationPoints, 3); // I'm using integer coordinates.

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