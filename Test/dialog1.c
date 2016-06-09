#include "stdafx.h"

//---------------------------------------------------------------------------
//  Drawing a Line
//  
//  This sample demonstrates how to draw a simple line using GDI+ C.
//---------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc1(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, L"Drawing a Line");
        return TRUE;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics); 

        Pen * pen;
        Pen_Create(ARGB(255, 0, 0, 255), 1.0f, &pen);

        // Draw the line using integer coordinates.
        // Functions that end with 'I' uses integer coordinates.
        Graphics_DrawLineI(graphics, pen, 0, 0, 200, 100); 

        // Make sure to cleanup the memory when they are not needed.
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