#include "stdafx.h"

//--------------------------------------------------------------------------
//  Drawing a Line with Line Caps
//
//  This sample demonstrates on how to use line caps with GDI+ C.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc5(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Drawing a Line with Line Caps");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH); // Set background color to white.
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * graphics = Graphics_CreateFromHDC(hdc);

        // You can specify line caps for the start of a line (start cap), the 
        // end of a line (end cap), or the dashes of a dashed line (dash cap).
        // The following example draws a line with an arrowhead at one end and 
        // a round cap at the other end:

        Pen * pen = Pen_Create(ARGB(255, 0, 0, 255), 8);
        Pen_SetStartCap(pen, LineCapArrowAnchor);
        Pen_SetEndCap(pen, LineCapRoundAnchor);

        Graphics_DrawLine(graphics, pen, 20, 175, 300, 175);

        // Delete objects.
        Pen_Delete(pen);
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