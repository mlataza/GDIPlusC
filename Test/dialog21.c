#include "stdafx.h"

//--------------------------------------------------------------------------
//  Improving Performance by Avoiding Automatic Scaling
//
//  This sample demonstrates on how to further improve performance when 
//  displaying images.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc21(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Improving Performance by Avoiding Automatic Scaling");
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
         
        // If you use Graphics_DrawImage where you provide the upper-left corner
        // of the image, GDI+ might scale the image, which would decrease performance.
        
        // If you want to prevent scaling, use Graphics_DrawImageRect and pass
        // the width and height of the destination rectangle. T

        // The following draws the same image twice.
        // In the first case, the image is automatically scaled.
        // In the second case, the width and height of the original image are
        // specified as the destination rectangle.

        Image * image = Image_LoadFromFile(L"Texture1.jpg", FALSE);
        Graphics_DrawImage(graphics, image, 10, 10);
        Graphics_DrawImageRect(graphics, image, 120, 10, (REAL)Image_GetWidth(image),
            (REAL)Image_GetHeight(image));

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