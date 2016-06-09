#include "stdafx.h"

//--------------------------------------------------------------------------
//  Using a Pen to Draw Lines and Rectangles
//
//  This demonstrates the use of GDI+ pen in drawing lines and rectangles.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc3(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, L"Using a Pen to Draw Lines and Rectangles");
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

        // Drawing a line from (20, 10) to (300, 100).
        Pen * pen;
        Pen_Create(ARGB(255, 0, 0, 0), 1.0f, &pen); 
        // ARGB(255, 0, 0, 0) - correspond to alpha, red, green, and blue components of the color
        // 1.0f - width of the pen in pixels
        
        Graphics_DrawLineI(graphics, pen, 20, 10, 300, 100);

        // Draw a rectangle with its upper-left corner at (10, 50), width of 100 and a height of 50.
        Pen * blackPen;
        Pen_Create(ARGB(255, 0, 0, 0), 5.0f, &blackPen); // Width of the pen is 5.0 pixels.

        Graphics_DrawRectangleI(graphics, blackPen, 10, 50, 100, 50);

        // Delete the objects.
        Pen_Delete(blackPen);
        Pen_Delete(pen);
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