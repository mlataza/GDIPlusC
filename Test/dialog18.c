#include "stdafx.h"

//--------------------------------------------------------------------------
//  Using Interpolation Mode to Control Image Quality During Scaling
//
//  This sample demonstrates the effect of different Interpolation Modes on the
//  image quality during scaling.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc18(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Using Interpolation Mode to Control Image Quality During Scaling");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // The interpolation mode of the Graphics object influences the way
        // GDI+ (stretches and shrinks) images. The InterpolationMode enumeration
        // defines several modes, some of which are:
        // -- InterpolationModeNearestNeighbor
        // -- InterpolationModeBilinear
        // -- InterpolationModeHighQualityBilinear
        // -- InterpolationModeBicubic
        // -- InterpolationModeHighQualityBicubic
        // The InterpolationModeNearestNeighbor is the lowest quality mode, and
        // InterpolationModeHighQualityBicubic is the highest quality mode.

        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics);

        Image * image;
        Image_LoadFromFile(L"GrapeBunch.bmp", FALSE, &image);
        UINT width = Image_GetWidth(image);
        UINT height = Image_GetHeight(image);
        Rect destRect;
        // Draw the image with no shrinking or stretching.
        destRect.X = 10;
        destRect.Y = 10;
        destRect.Width = width;
        destRect.Height = height;
        Graphics_DrawImageRectRectI(
            graphics,
            image,
            &destRect,   // destination rectangle  
            0, 0,        // upper-left corner of source rectangle
            width,       // width of source rectangle
            height,      // height of source rectangle
            UnitPixel, NULL, NULL, NULL);
        // Shrink the image using low-quality interpolation. 
        Graphics_SetInterpolationMode(graphics, InterpolationModeNearestNeighbor);
        destRect.X = 10;
        destRect.Y = 250;
        destRect.Width = (INT)(width * 0.6);
        destRect.Height = (INT)(height * 0.6);
        Graphics_DrawImageRectRectI(
            graphics,
            image,
            &destRect,   // destination rectangle 
            0, 0,        // upper-left corner of source rectangle
            width,       // width of source rectangle
            height,      // height of source rectangle
            UnitPixel, NULL, NULL, NULL);
        // Shrink the image using medium-quality interpolation.
        Graphics_SetInterpolationMode(graphics, InterpolationModeHighQualityBilinear);
        destRect.X = 150;
        destRect.Y = 250;
        destRect.Width = (INT)(width * 0.6);
        destRect.Height = (INT)(height * 0.6);
        Graphics_DrawImageRectRectI(
            graphics,
            image,
            &destRect,   // destination rectangle 
            0, 0,        // upper-left corner of source rectangle
            width,       // width of source rectangle
            height,      // height of source rectangle
            UnitPixel, NULL, NULL, NULL);
        // Shrink the image using high-quality interpolation.
        Graphics_SetInterpolationMode(graphics, InterpolationModeHighQualityBicubic);
        destRect.X = 290;
        destRect.Y = 250;
        destRect.Width = (INT)(width * 0.6);
        destRect.Height = (INT)(height * 0.6);
        Graphics_DrawImageRectRectI(
            graphics,
            image,
            &destRect,   // destination rectangle 
            0, 0,        // upper-left corner of source rectangle
            width,       // width of source rectangle
            height,      // height of source rectangle
            UnitPixel, NULL, NULL, NULL);

        // Observe the differences of the smaller images.

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