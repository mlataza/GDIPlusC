#include "stdafx.h"

//--------------------------------------------------------------------------
//  Joining Lines
//
//  This sample demonstrates on how to connect lines with GDI+ C.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc6(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Joining Lines");
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

        // A line join is the common area that is formed by two lines whose 
        // ends meet or overlap. Windows GDI+ provides four line join styles: 
        // miter, bevel, round, and miter clipped. Line join style is a property 
        // of the Pen object. When you specify a line join style for a pen and 
        // then use that pen to draw a path, the specified join style is applied 
        // to all the connected lines in the path.

        // The following draws a beveled line join.
        GraphicsPath * path;
        GraphicsPath_Create(FillModeAlternate, &path);

        Pen * penJoin;
        Pen_Create(ARGB(255, 0, 0, 255), 8, &penJoin);

        GraphicsPath_StartFigure(path);
        GraphicsPath_AddLine(path, 50, 200, 100, 200);
        GraphicsPath_AddLine(path, 100, 200, 100, 250);

        Pen_SetLineJoin(penJoin, LineJoinBevel);
        Graphics_DrawPath(graphics, penJoin, path); // Draw the path.

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