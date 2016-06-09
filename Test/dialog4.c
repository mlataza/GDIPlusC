#include "stdafx.h"

//--------------------------------------------------------------------------
//  Setting Pen Width and Alignment
//
//  This sample demonstrates the concept of pen width and alignment, as well as
//  how to set them using GDI+ C.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc4(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hWnd, L"Setting Pen Width and Alignment");
        return TRUE;
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH); // Set background color.
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics);

        // When creating a Pen, you could set the width of the pen. You can also
        // change the width of the Pen using Pen_SetWidth.
        //
        // A theoretical line has a width of zero. When you draw a line, the pixels
        // are centered on the theoretical line. The following draws a specified line
        // twice: once with a black pen of width 1 and once with a green pen of width 10.
        Pen * blackPen;
        Pen_Create(ARGB(255, 0, 0, 0), 1.0f, &blackPen);

        Pen * greenPen;
        Pen_Create(ARGB(255, 0, 255, 0), 1.0f, &greenPen); // You could replace 1.0f with 10.0f.
        Pen_SetWidth(greenPen, 10.0f);
        Pen_SetAlignment(greenPen, PenAlignmentCenter);

        // Draw the green line.
        Graphics_DrawLine(graphics, greenPen, 10, 100, 100, 50);

        // Draw the black line.
        Graphics_DrawLine(graphics, blackPen, 10, 100, 100, 50);

        // The green pixel and the black pixels are centered on the theoretical line.

        // Delete current objects.
        Pen_Delete(greenPen);
        Pen_Delete(blackPen);

        // The following draws a specified rectangle twice: once with a black pen
        // of width 1 and once with a green pen of width 10.
        Pen_Create(ARGB(255, 0, 0, 0), 1.0f, &blackPen);
        Pen_Create(ARGB(255, 0, 255, 0), 10.0f, &greenPen);
        Pen_SetAlignment(greenPen, PenAlignmentCenter);

        // Draw the rectangle with green pen.
        Graphics_DrawRectangle(graphics, greenPen, 10, 120, 50, 50);

        // Draw the rectangle with black pen.
        Graphics_DrawRectangle(graphics, blackPen, 10, 120, 50, 50);

        // The green pixels are centered on the theoretical rectangle, which is 
        // represented by the black pixels.

        // Let's see if the alignment of the green pen is set to PenAlignmentInset.

        Pen_SetAlignment(greenPen, PenAlignmentInset);
      
        // Draw the rectangle with green pen.
        Graphics_DrawRectangle(graphics, greenPen, 80, 120, 50, 50);

        // Draw the rectangle with black pen.
        Graphics_DrawRectangle(graphics, blackPen, 80, 120, 50, 50);

        // Now the pixels in the wide green line appear on the inside of the 
        // rectangle as shown in the following illustration.

        // Delete objects.
        Pen_Delete(blackPen);
        Pen_Delete(greenPen);
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