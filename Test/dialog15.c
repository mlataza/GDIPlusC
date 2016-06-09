#include "stdafx.h"

//--------------------------------------------------------------------------
//  Recording Metafiles
//
//  This sample demonstrates the use of Metafiles in recording the sequence of
//  drawing commands performed on a Graphics object.
//--------------------------------------------------------------------------

INT_PTR CALLBACK DialogProc15(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        return SetWindowText(hWnd, L"Recording Metafiles");
    }
    case WM_CTLCOLORDLG:
    {
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // The Metafile object allows you to record a sequence of drawing commands.
        // The recorded commands can be stored in memory, saved to a file, or 
        // saved to a stream. Metafiles can contain vector graphics, raster images
        // and text.

        // The code first creates a Metafile object which it uses to record a 
        // sequence of graphics commands and then saves the recorded commands in 
        // a file named SampleMetafile.emf.

        // The recording stops (and the recorded commands are saved to the file)
        // when the Graphics object is destroyed. The last two lines of code
        // display the metafile by creating a new Graphics object and passing the
        // address of the Metafile to the Graphics_DrawImage function.

        Metafile * metafile;
        Metafile_CreateRecordFileName(L"SampleMetafile.emf", hdc, NULL,
                                      MetafileFrameUnitGdi, EmfTypeEmfOnly,
                                      L"", &metafile);
        {
            Graphics * graphics;
            Graphics_CreateFromImage(metafile, &graphics); // Load the metafile into the Graphics object.

            // Create the drawing tools.
            Pen * pen;
            Pen_Create(ARGB(255, 0, 255, 0), 1.0f, &pen);
            SolidBrush * solidBrush;
            SolidBrush_Create(ARGB(255, 0, 0, 255), &solidBrush);

            // Add a rectangle and an ellipse to the metafile.
            Graphics_DrawRectangle(graphics, pen, 50, 10, 25, 75);
            Graphics_DrawEllipse(graphics, pen, 100, 10, 25, 75);

            // Add an ellipse (drawn with antialiasing) to the metafile.
            Graphics_SetSmoothingMode(graphics, SmoothingModeAntiAlias);
            Graphics_DrawEllipse(graphics, pen, 150, 10, 25, 75);

            // Add some text (drawn with antialiasing) to the metafile.
            FontFamily * fontFamily;
            FontFamily_CreateFromName(L"Arial", NULL, &fontFamily);
            Font * font;
            Font_Create(fontFamily, 24, FontStyleRegular, UnitPixel, &font);

            Graphics_SetTextRenderingHint(graphics, TextRenderingHintAntiAlias);
            Graphics_RotateTransform(graphics, 30.0f, MatrixOrderPrepend); // Default MatrixOrder is MatrixOrderPrepend.
            PointF point = { 50, 50 };
            Graphics_DrawStringToPoint(graphics, L"Smooth Text", 11, font,
                                       &point, NULL, solidBrush);

            // Destroy tools
            Font_Delete(font);
            FontFamily_Delete(fontFamily);
            SolidBrush_Delete(solidBrush);
            Pen_Delete(pen);

            // End recording of metafile.
            Graphics_Delete(graphics);
        }

        // Play back the metafile.
        Graphics * playbackGraphics;
        Graphics_CreateFromHDC(hdc, &playbackGraphics);
        Graphics_DrawImage(playbackGraphics, metafile, 200, 100);

        // To record a metafile, you must construct a Graphics object based on
        // a Metafile object. The recording of the metafile ends when that 
        // Graphics object is deleted.

        // A metafile contains its own graphics state, which is defined by the
        // Graphics object used to record the metafile. Any properties of the 
        // Graphics object (clip region, world transformation, smoothing mode,
        // and the like) that you set while recording the metafile will be
        // stored in the metafile. When you draw the metafile, the drawing
        // will be done according to those stored properties.

        // End drawing.
        Graphics_Delete(playbackGraphics);
        Metafile_Dispose(metafile);
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