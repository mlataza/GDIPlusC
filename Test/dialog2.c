#include "stdafx.h"

//---------------------------------------------------------------------------
//  Drawing a String
//
//  This sample demonstrates how to draw a string using GDI+ C.
//---------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Drawing a String");
    }
    case WM_CTLCOLORDLG:
    {
        // Set the background color to white.
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Create all the GDI+ objects first.
        Graphics * graphics;
        Graphics_CreateFromHDC(hdc, &graphics);

        SolidBrush * brush;
        SolidBrush_Create(ARGB(255, 0, 0, 255), &brush);

        FontFamily * fontFamily;
        FontFamily_CreateFromName(L"Times New Roman", NULL, &fontFamily);

        Font * font;
        Font_Create(fontFamily, 24, FontStyleRegular, UnitPixel, &font);

        PointF pointF = { 10.0f, 20.0f };

        // Draw the string now.
        Graphics_DrawStringToPoint(graphics, L"Hello World!", -1, font, &pointF, NULL, brush);

        // Destroy all the objects.
        Font_Delete(font);
        FontFamily_Delete(fontFamily);
        SolidBrush_Delete(brush);
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