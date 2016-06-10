#include "stdafx.h"

//--------------------------------------------------------------------------
//  Reading and Writing Metadata
//
//  This sample demonstrates on how to read metadata on image files.
//--------------------------------------------------------------------------

// Some image files contain metadata that you can read to determine 
// features of the image. For example, a digital photograph might 
// contain metadata that you can read to determine the make and model 
// of the camera used to capture the image. With Windows GDI+, you can 
// read existing metadata, and you can also write new metadata to image 
// files.

// GDI+ provides a uniform way of storing and retrieving metadata from 
// image files in various formats. In GDI+, a piece of metadata is called 
// a property item. You can store and retrieve metadata by calling the 
// Image_SetPropertyItem and Image_GetPropertyItem functions, and you 
// don't have to be concerned about the details of how a particular file 
// format stores that metadata.

// GDI+ currently supports metadata for the TIFF, JPEG, Exif, and PNG 
// file formats. The Exif format, which specifies how to store images 
// captured by digital still cameras, is built on top of the TIFF and 
// JPEG formats. Exif uses the TIFF format for uncompressed pixel data 
// and the JPEG format for compressed pixel data.

LPWSTR propertyTypes[] = {
    L"Nothing",                   // 0
    L"PropertyTagTypeByte",       // 1
    L"PropertyTagTypeASCII",      // 2
    L"PropertyTagTypeShort",      // 3
    L"PropertyTagTypeLong",       // 4
    L"PropertyTagTypeRational",   // 5
    L"Nothing",                   // 6
    L"PropertyTagTypeUndefined",  // 7
    L"Nothing",                   // 8
    L"PropertyTagTypeSLONG",      // 9
    L"PropertyTagTypeSRational"
};

// Converts PropertyType to string.
VOID WINAPI PropertyTypeFROMWORD(WORD index, LPWSTR string, UINT maxChars)
{
    wcscpy_s(string, maxChars, propertyTypes[index]);
}

// Taken from https://msdn.microsoft.com/en-us/library/windows/desktop/ms533843(v=vs.85).aspx
int GetEncoderClsid(const WCHAR * format, CLSID * pClsid)
{
    UINT  num = 0;          // number of image encoders
    UINT  size = 0;         // size of the image encoder array in bytes

    ImageCodecInfo* pImageCodecInfo = NULL;

    GetImageEncodersSize(&num, &size);
    if (size == 0)
        return -1;  // Failure

    pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL)
        return -1;  // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j)
    {
        if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
        {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;  // Success
        }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
}

#define BUFFSIZE 20000

INT_PTR CALLBACK DialogProc22(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static WCHAR szTextOut[BUFFSIZE]; // String buffer for the display.
    static WCHAR szTemp[80]; // Contains output from the wsprintf function.

    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Reading and Writing Metadata");
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
        SolidBrush * brush = SolidBrush_Create(ARGB(255, 0, 0, 0));
        szTextOut[0] = L'\0'; // Clear the buffer.

        // The following uses Bitmap_GetPropertySize / Image_GetPropertySize
        // to determine how many pieces of metadata are in the file Texture1.jpg
        UINT size, count;
        Bitmap * bitmap = Bitmap_CreateFromFile(L"Metadata.jpg", FALSE);
        Bitmap_GetPropertySize(bitmap, &size, &count);

        wsprintf(szTemp, L"There are %d pieces of metadata in the file.\n", count);
        wcscat_s(szTextOut, BUFFSIZE, szTemp);
        wsprintf(szTemp, L"The total size of the metadata is %d bytes.\n\n", size);
        wcscat_s(szTextOut, BUFFSIZE, szTemp);

        // GDI+ stores an individual piece of metadata in a PropertyItem object.
        // You can call the Image_GetAllPropertyItems method to retrieve all the
        // metadata from a file. The Image_GetAllPropertyItems method returns
        // an array of PropertyItem objects. Before you can call Image_GetAllPropertyItems,
        // you must allocate a buffer large enough to receive that array.
        // You can call the Image_GetPropertySize method to get the size (in bytes)
        // of the required buffer.

        // String buffer for the property type string.
        WCHAR szPropertyType[30];

        // Allocate a buffer.
        PropertyItem * pPropBuffer = (PropertyItem *)malloc(size);

        // Get all the property items.
        Bitmap_GetAllPropertyItems(bitmap, size, count, pPropBuffer);

        
        // For each PropertyItem in the array, display the id, type, and length.
        UINT j;
        for (j = 0; j < count; j++)
        {
            // Convert the property type to string.
            PropertyTypeFROMWORD(pPropBuffer[j].type, szPropertyType, 30);

            wsprintf(szTemp, L"Property Item %d\n", j); 
            wcscat_s(szTextOut, BUFFSIZE, szTemp); // Copy temp to string buffer.
            wsprintf(szTemp, L"  id: 0x%x\n", pPropBuffer[j].id);
            wcscat_s(szTextOut, BUFFSIZE, szTemp); // Copy temp to string buffer.
            wsprintf(szTemp, L"  type: %s\n", szPropertyType);
            wcscat_s(szTextOut, BUFFSIZE, szTemp); // Copy temp to string buffer.
            wsprintf(szTemp, L"  length: %d bytes\n\n", pPropBuffer[j].length);
            wcscat_s(szTextOut, BUFFSIZE, szTemp); // Copy temp to string buffer.
        }

        // Let's try viewing some metadata.
        MessageBoxA(hWnd, pPropBuffer[0].value, "PropertyItem: 0", 0);
        MessageBoxA(hWnd, pPropBuffer[1].value, "PropertyItem: 1", 0);
        MessageBoxA(hWnd, pPropBuffer[6].value, "PropertyItem: 6", 0);
        MessageBoxA(hWnd, pPropBuffer[12].value, "PropertyItem: 12", 0);
        MessageBoxA(hWnd, pPropBuffer[13].value, "PropertyItem: 13", 0);
        MessageBoxA(hWnd, pPropBuffer[23].value, "PropertyItem: 23", 0);
        MessageBoxA(hWnd, pPropBuffer[24].value, "PropertyItem: 24", 0);
        
        // Display the output string.
        PointF pt = { 6, 6 };
        Graphics_DrawStringToPoint(g, szTextOut, -1, font, &pt, NULL, brush);

        // To write an item of metadata to an Image object, initialize a PropertyItem 
        // object and then pass the address of that PropertyItem object to the 
        // Image_SetPropertyItem function.

        PropertyItem * propertyItem = (PropertyItem *)malloc(sizeof(PropertyItem));
        char propertyValue[] = "I wrote my own metada.!!!";
        propertyItem->id = PropertyTagImageDescription;
        propertyItem->length = sizeof(propertyValue); // Number of bytes of the propertyValue.
        propertyItem->type = PropertyTagTypeASCII;
        propertyItem->value = propertyValue;

        Bitmap_SetPropertyItem(bitmap, propertyItem); 

        // Save the image now.
        CLSID clsid; 
        GetEncoderClsid(L"image/jpeg", &clsid);
        Status stat = Bitmap_SaveToFile(bitmap, L"Metadata2.jpg", &clsid, NULL);

        // You can check the metadata of the image file by opening the context
        // menu, click Properties, and select the Details tab.

        // Cleanup.
        free(propertyItem);
        free(pPropBuffer);

        // Delete object.
        Bitmap_Dispose(bitmap);
        SolidBrush_Delete(brush);
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