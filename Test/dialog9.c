#include "stdafx.h"

//--------------------------------------------------------------------------
//  Filling a Shape with a Solid Color
//
//  This demonstrates on how to use the SolidBrush object.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Filling a Shape with a Solid Color");
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

        // To fill a shape with with a solid color, create a SolidBrush object 
        // and then pass the pointer as an argument to one of the fill methods
        // of the Graphics object. 
        // 
        // The following shows how to fill an ellipse with the color red.
        SolidBrush * solidBrush = SolidBrush_Create(ARGB(255, 255, 0, 0));

        Graphics_FillEllipse(graphics, solidBrush, 0, 0, 100, 60);

        // The ellipse is bounded by the rectangle whose upper-left corner is at
        // (0, 0), with of 100, and height of 60.

        // Delete object.
        SolidBrush_Delete(solidBrush);
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