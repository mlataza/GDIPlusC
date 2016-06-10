#include "stdafx.h"

//--------------------------------------------------------------------------
//  Tiling a Shape with an Image
//
//  This sample demonstrates on how to use TextureBrush object to tile an image.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc12(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Tiling a Shape with an Image");
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

        // Just as tiles can be placed next to each other to cover a floor, 
        // rectangular images can be placed next to each other to fill (tile) a
        // shape. To tile the interior of a shape, use a texture brush. When you 
        // construct a TextureBrush object, one of the arguments you pass to the 
        // constructor is the address of an Image object. When you use the texture 
        // brush to paint the interior of a shape, the shape is filled with 
        // repeated copies of this image.

        // The wrap mode property of the TextBrush object determines how the
        // image is oriented as it is repeated in a rectangular grid. You can
        // make all tiles in the grid have the same orientation, or you can
        // make the image flip from one grid position to next. The flipping can
        // be horizontal, vertical, or both.

        Image * image = Image_LoadFromFile(L"HouseAndTree.png", FALSE);

        TextureBrush * tBrush = TextureBrush_Create(image, WrapModeTile);

        Pen * pen = Pen_Create(Black, 1.0f);

        // Draw a tiled image with WrapModeTile (default) orientation.
        Graphics_FillRectangle(graphics, tBrush, 0, 0, 200, 200);
        Graphics_DrawRectangle(graphics, pen, 0, 0, 200, 200);

        // Flipping an image horizontally while tiling.
        TextureBrush_SetWrapMode(tBrush, WrapModeTileFlipX);
        Graphics_FillRectangle(graphics, tBrush, 200, 0, 200, 200);
        Graphics_DrawRectangle(graphics, pen, 200, 0, 200, 200);

        // Flipping an image vertically while tiling.
        TextureBrush_SetWrapMode(tBrush, WrapModeTileFlipY);
        Graphics_FillRectangle(graphics, tBrush, 0, 200, 200, 200);
        Graphics_DrawRectangle(graphics, pen, 0, 200, 200, 200);

        // Flipping an image horizontally and vertically while tiling.
        TextureBrush_SetWrapMode(tBrush, WrapModeTileFlipXY);
        Graphics_FillRectangle(graphics, tBrush, 200, 200, 200, 200);
        Graphics_DrawRectangle(graphics, pen, 200, 200, 200, 200);

        // Delete objects.
        Pen_Delete(pen);
        TextureBrush_Delete(tBrush);
        Image_Dispose(image);

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