#include "stdafx.h"

//--------------------------------------------------------------------------
//  Drawing a Line Filled with a Texture
//
//  This topic demonstrates on how to add texture to your GDI+ C pen. 
//  It uses an image file Texture1.jpg is placed in the Test directory.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Drawing a Line Filled with a Texture");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Instead of drawing a line or curve with a solid color, you can draw 
        // with a texture.To draw lines and curves with a texture, create a 
        // TextureBrush object, and pass the address of that TextureBrush object 
        // to a Pen constructor. The image associated with the texture brush is 
        // used to tile the plane(invisibly), and when the pen draws a line or 
        // curve, the stroke of the pen uncovers certain pixels of the tiled texture.
        Graphics * graphics = Graphics_CreateFromHDC(hdc);

        Image * image = Image_LoadFromFile(L"Texture1.jpg", FALSE);

        TextureBrush * tBrush = TextureBrush_Create(image, WrapModeTile);

        Pen * texturedPen = Pen_Create2(tBrush, 30);

        // Draw the image first.
        Graphics_DrawImageRectI(graphics, image, 0, 0, Image_GetWidth(image),
                               Image_GetHeight(image));

        // Now use the texturedPen.
        Graphics_DrawEllipse(graphics, texturedPen, 100, 20, 200, 100);

        // Delete objects
        Pen_Delete(texturedPen);
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