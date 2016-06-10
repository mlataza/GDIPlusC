#include "stdafx.h"

//-------------------------------------------------------------------------
//  Drawing a Custom Dashed Line
//
//  This sample demonstrates on how to draw a custom dashed line.
//-------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc7(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Drawing a Custom Dashed Line");
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

        // To draw a custom dashed line, put the lengths of the dashes and spaces
        // in an array and pass the address of the array as an argument to the 
        // Pen_SetDashPattern method of a Pen object. The following example draws 
        // a custom dashed line based on the array {5, 2, 15, 4}. If you multiply 
        // the elements of the array by the pen width of 5, you get {25, 10, 75, 20}. 
        // The displayed dashes alternate in length between 25 and 75, and the 
        // spaces alternate in length between 10 and 20.
        REAL dashValues[4] = { 5, 2, 15, 4 };
        Pen * blackPen = Pen_Create(ARGB(255, 0, 0, 0), 5);
        Pen_SetDashPattern(blackPen, dashValues, 4); // Set the dash pattern.

        Graphics_DrawLine(graphics, blackPen, 5, 5, 405, 5);

        // Delete object.
        Pen_Delete(blackPen);
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