#include "stdafx.h"

//--------------------------------------------------------------------------
//  Loading and Displaying Metafiles
//
//  This sample demonstrates on how to load .emf files (Enhanced Metafiles).
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc14(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Loading and Displaying Metafiles");
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

        // The Metafile object, which is based from the Image object provides
        // more specialized methods for recording, displaying, and examining 
        // vector images.
        Image * image = Image_LoadFromFile(L"SampleMetafile.emf", FALSE);

        Graphics_DrawImage(graphics, image, 60, 10);

        // Delete objects.
        Image_Dispose(image);
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