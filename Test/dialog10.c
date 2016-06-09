#include "stdafx.h"

//--------------------------------------------------------------------------
//  Filling a Shape with a Hatch Pattern
//
//  This sample demonstrates on how to create a brush with hatch pattern and use
//  it to fill certain shapes.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc10(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, L"Filling a Shape with a Hatch Pattern");
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

        // A hatch pattern is made from two colors: one of the background and one
        // for the lines that form the pattern over the background. To fill a 
        // closed shape with a hatch pattern, use a HatchBrush object.

        HatchBrush * hBrush;
        HatchBrush_Create(HatchStyleHorizontal, ARGB(255, 255, 0, 0),
                          ARGB(255, 128, 255, 255), &hBrush);

        // ARGB(255, 255, 0, 0) is the fore color.
        // ARGB(255, 128, 255, 255) is the background color.

        Graphics_FillEllipse(graphics, hBrush, 0, 0, 100, 60);

        // Delete objects.
        HatchBrush_Delete(hBrush);
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