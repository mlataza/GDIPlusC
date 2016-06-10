#include "stdafx.h"

//--------------------------------------------------------------------------
//  Listing Installed Encoders
//
//  This sample demonstrates on how to display all the encoders installed in the
//  GDI+.
//--------------------------------------------------------------------------

// GDI+ provides the GetImageEncoders function so that you can determine which 
// image encoders are available on your computer. GetImageEncoders returns an 
// array of ImageCodecInfo objects. Before you call GetImageEncoders, you must 
// allocate a buffer large enough to receive that array. You can call 
// GetImageEncodersSize to determine the size of the required buffer.

INT_PTR CALLBACK DialogProc23(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static WCHAR szTextOut[500]; // The text to be displayed on the form.

    switch (msg)
    {
    case WM_INITDIALOG:
    {
        szTextOut[0] = L'\0';
        wcscpy_s(szTextOut, 500, L"Image encoders installed: \n\n");

        UINT num; // number of image encoders
        UINT size; // size, in bytes, of the image encoder array

        GetImageEncodersSize(&num, &size);

        // Create a buffer large enough to hold the array of ImageCodecInfo.
        ImageCodecInfo * encoders = (ImageCodecInfo *)malloc(size);

        // GetImageEncoders creates an array of ImageCodecInfo objects
        // and copies that array into a previously allocated buffer. 
        GetImageEncoders(num, size, encoders);

        // Display the graphics file format (MimeType)
        // for each ImageCodecInfo object.
        WCHAR szTemp[80];

        UINT j;
        for (j = 0; j < num; j++)
        {
            wsprintf(szTemp, L"%s\n", encoders[j].MimeType);
            wcscat_s(szTextOut, 500, szTemp); // Append to szTextOut.
        }

        return SetWindowText(hWnd, L"Listing Installed Encoders");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        Graphics * g = Graphics_CreateFromHDC(hdc);
        FontFamily * family = FontFamily_CreateFromName(L"Times New Roman", NULL);
        Font * font = Font_Create(family, 14, FontStyleRegular, UnitPixel);
        SolidBrush * solidBrush = SolidBrush_Create(Red);
        PointF pt = { 6, 6 };

        // Draw the szTextOut.
        Graphics_DrawStringToPoint(g, szTextOut, -1, font, &pt, NULL, solidBrush);

        SolidBrush_Delete(solidBrush);
        Font_Delete(font);
        FontFamily_Delete(family);
        Graphics_Delete(g);

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