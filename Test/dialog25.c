#include "stdafx.h"

//--------------------------------------------------------------------------
//  Retrieving the Class Identifier for an Encoder
//
//  This sample demonstrates on how to get the CLSID of an encoder using its
//  MimeType.
//--------------------------------------------------------------------------

// The function GetEncoderClsid in the following example receives the MIME types
// of the encoders built into the Windows GDI+ are as follows:
// -- image/bmp
// -- image/jpeg
// -- image/gif
// -- image/tiff
// -- image/png
// This function basically loops through all the installed encoders and checks
// if an encoder matches the specified MimeType. When it does find one, it copies
// its CLSID to pClsid and returns TRUE. Otherwise, it just returns FALSE.

BOOL WINAPI GetEncoderClsid(const WCHAR * mimeType, CLSID * pClsid)
{
    UINT num = 0;
    UINT size = 0;

    GetImageEncodersSize(&num, &size);

    ImageCodecInfo * encoders = (ImageCodecInfo *)malloc(size);

    if (!encoders) return FALSE; // Failed to allocate buffer.

    // Get the array of encoders.
    GetImageEncoders(num, size, encoders);

    // Find the specified encoder.
    BOOL bFound = FALSE;
    UINT i;
    for (i = 0; i < num; i++)
    {
        if (wcscmp(mimeType, encoders[i].MimeType) == 0)
        {
            *pClsid = encoders[i].Clsid;
            bFound = TRUE;
            break; // Break the loop.
        }
    }

    free(encoders); // Destroy the buffer.
    return bFound;
}

INT_PTR CALLBACK DialogProc25(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        // Lets try getting the Class Identifier of the PNG encoder.
        CLSID clsid;
        WCHAR szGuid[40];

        if (GetEncoderClsid(L"image/png", &clsid))
        {
            StringFromGUID2(&clsid, szGuid, 40);
            WCHAR szTemp[80];
            wsprintf(szTemp, L"The CLSID of the PNG encoder is %s.", szGuid);
            MessageBox(hWnd, szTemp, NULL, MB_ICONINFORMATION);
        }
        else
        {
            MessageBox(hWnd, L"Encoder not installed.", NULL, 0);
        }

        return SetWindowText(hWnd, L"Retrieveing the Class Identifier for an Encoder");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_CLOSE:
    {
        return EndDialog(hWnd, 0);
    }
    default:
        return FALSE;
    }
}