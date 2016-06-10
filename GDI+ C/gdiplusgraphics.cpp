#include "stdafx.h"

Graphics * WINAPI
Graphics_CreateFromHDC(IN HDC hdc)
{
    Graphics * graphics;

    if (Gdiplus::DllExports::GdipCreateFromHDC(
        hdc, (Gdiplus::GpGraphics **)&graphics) == Gdiplus::Ok)
    {
        return graphics;
    }
    else
    {
        return NULL;
    }
}

Graphics * WINAPI
Graphics_CreateFromHDC2(IN HDC hdc,
                        IN HANDLE hdevice
)
{
    Graphics * graphics;

    if (Gdiplus::DllExports::GdipCreateFromHDC2(
        hdc, hdevice, (Gdiplus::GpGraphics **)&graphics) == Gdiplus::Ok)
    {
        return graphics;
    }
    else
    {
        return NULL;
    }
}

Graphics * WINAPI
Graphics_CreateFromHWND(IN HWND hwnd, IN BOOL icm)
{
    Graphics * graphics;

    if (icm)
    {
        if (Gdiplus::DllExports::GdipCreateFromHWNDICM(
            hwnd, (Gdiplus::GpGraphics **)&graphics) == Gdiplus::Ok)
        {
            return graphics;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipCreateFromHWND(
            hwnd, (Gdiplus::GpGraphics **)&graphics) == Gdiplus::Ok)
        {
            return graphics;
        }
        else
        {
            return NULL;
        }
    }
}

Graphics * WINAPI
Graphics_CreateFromImage(IN Image * image)
{
    Graphics * graphics;

    if (Gdiplus::DllExports::GdipGetImageGraphicsContext(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpGraphics **)&graphics) == Gdiplus::Ok)
    {
        return graphics;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
Graphics_Delete(IN Graphics * graphics)
{
    return (Status)Gdiplus::DllExports::GdipDeleteGraphics(
        (Gdiplus::GpGraphics *)graphics
    );
}

Status WINAPI
Graphics_Flush(IN Graphics * graphics,
               IN FlushIntention intention
)
{
    return (Status)Gdiplus::DllExports::GdipFlush(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpFlushIntention)intention
    );
}

HDC WINAPI
Graphics_GetHDC(IN Graphics * graphics)
{
    HDC hdc = NULL;

    Gdiplus::DllExports::GdipGetDC(
        (Gdiplus::GpGraphics *)graphics, &hdc
    );

    return hdc;
}

Status WINAPI
Graphics_ReleaseHDC(IN Graphics * graphics,
                    IN HDC hdc
)
{
    return (Status)Gdiplus::DllExports::GdipReleaseDC(
        (Gdiplus::GpGraphics *)graphics, hdc
    );
}

Status WINAPI
Graphics_SetRenderingOrigin(IN Graphics * graphics,
                            IN INT x, IN INT y
)
{
    return (Status)Gdiplus::DllExports::GdipSetRenderingOrigin(
        (Gdiplus::GpGraphics *)graphics, x, y
    );
}

Status WINAPI
Graphics_GetRenderingOrigin(IN Graphics * graphics,
                            OUT INT * x,
                            OUT INT * y
)
{
    return (Status)Gdiplus::DllExports::GdipGetRenderingOrigin(
        (Gdiplus::GpGraphics *)graphics, x, y
    );
}

Status WINAPI
Graphics_SetCompositingMode(IN Graphics * graphics,
                            IN CompositingMode compositingMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetCompositingMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::CompositingMode)compositingMode
    );
}

CompositingMode WINAPI
Graphics_GetCompositingMode(IN Graphics * graphics)
{
    CompositingMode mode;

    Gdiplus::DllExports::GdipGetCompositingMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::CompositingMode *)&mode
    );

    return mode;
}

Status WINAPI
Graphics_SetCompositingQuality(IN Graphics * graphics,
                               IN CompositingQuality compositingQuality
)
{
    return (Status)Gdiplus::DllExports::GdipSetCompositingQuality(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::CompositingQuality)compositingQuality
    );
}

CompositingQuality WINAPI
Graphics_GetCompositingQuality(IN Graphics * graphics)
{
    CompositingQuality quality;

    Gdiplus::DllExports::GdipGetCompositingQuality(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::CompositingQuality *)&quality
    );

    return quality;
}

Status WINAPI
Graphics_SetTextRenderingHint(IN Graphics * graphics,
                              IN TextRenderingHint newMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetTextRenderingHint(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::TextRenderingHint)newMode
    );
}

TextRenderingHint WINAPI
Graphics_GetTextRenderingHint(IN Graphics * graphics)
{
    TextRenderingHint hint;

    Gdiplus::DllExports::GdipGetTextRenderingHint(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::TextRenderingHint *)&hint
    );

    return hint;
}

Status WINAPI
Graphics_SetTextContrast(IN Graphics * graphics,
                         IN UINT contrast
)
{
    return (Status)Gdiplus::DllExports::GdipSetTextContrast(
        (Gdiplus::GpGraphics *)graphics,
        contrast
    );
}

UINT WINAPI
Graphics_GetTextContrast(IN Graphics * graphics)
{
    UINT contrast;

    Gdiplus::DllExports::GdipGetTextContrast(
        (Gdiplus::GpGraphics *)graphics,
        &contrast
    );

    return contrast;
}

InterpolationMode WINAPI
Graphics_GetInterpolationMode(IN Graphics * graphics)
{
    InterpolationMode mode = InterpolationModeInvalid;

    Gdiplus::DllExports::GdipGetInterpolationMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::InterpolationMode *)&mode
    );

    return mode;
}

Status WINAPI
Graphics_SetInterpolationMode(IN Graphics * graphics,
                              IN InterpolationMode interpolationMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetInterpolationMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::InterpolationMode)interpolationMode
    );
}

SmoothingMode WINAPI
Graphics_GetSmoothingMode(IN Graphics * graphics)
{
    SmoothingMode smoothingMode = SmoothingModeInvalid;

    Gdiplus::DllExports::GdipGetSmoothingMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::SmoothingMode *)&smoothingMode
    );

    return smoothingMode;
}

Status WINAPI
Graphics_SetSmoothingMode(IN Graphics * graphics,
                          IN SmoothingMode smoothingMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetSmoothingMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::SmoothingMode)smoothingMode
    );
}

PixelOffsetMode WINAPI
Graphics_GetPixelOffsetMode(IN Graphics * graphics)
{
    PixelOffsetMode pixelOffsetMode = PixelOffsetModeInvalid;

    Gdiplus::DllExports::GdipGetPixelOffsetMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::PixelOffsetMode *)&pixelOffsetMode
    );

    return pixelOffsetMode;
}

Status WINAPI
Graphics_SetPixelOffsetMode(IN Graphics * graphics,
                            IN PixelOffsetMode pixelOffsetMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetPixelOffsetMode(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::PixelOffsetMode)pixelOffsetMode
    );
}

Status WINAPI
Graphics_SetTransform(IN Graphics * graphics,
                      IN Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipSetWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Graphics_ResetTransform(IN Graphics * graphics)
{
    return (Status)Gdiplus::DllExports::GdipResetWorldTransform(
        (Gdiplus::GpGraphics *)graphics
    );
}

Status WINAPI
Graphics_MultiplyTransform(IN Graphics * graphics,
                           IN const Matrix * matrix,
                           IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Graphics_TranslateTransform(IN Graphics * graphics,
                            IN REAL dx,
                            IN REAL dy,
                            IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        dx, dy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Graphics_ScaleTransform(IN Graphics * graphics,
                        IN REAL sx,
                        IN REAL sy,
                        IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScaleWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        sx, sy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Graphics_RotateTransform(IN Graphics * graphics,
                         IN REAL angle,
                         IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotateWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Graphics_GetTransform(IN Graphics * graphics,
                      OUT Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipGetWorldTransform(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Graphics_SetPageUnit(IN Graphics * graphics,
                     IN Unit unit
)
{
    return (Status)Gdiplus::DllExports::GdipSetPageUnit(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpUnit)unit
    );
}

Status WINAPI
Graphics_SetPageScale(IN Graphics * graphics,
                      IN REAL scale
)
{
    return (Status)Gdiplus::DllExports::GdipSetPageScale(
        (Gdiplus::GpGraphics *)graphics,
        scale
    );
}

Unit WINAPI
Graphics_GetPageUnit(IN Graphics * graphics)
{
    Unit unit;

    Gdiplus::DllExports::GdipGetPageUnit(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpUnit *)&unit
    );

    return unit;
}

REAL WINAPI
Graphics_GetPageScale(IN Graphics * graphics)
{
    REAL scale;

    Gdiplus::DllExports::GdipGetPageScale(
        (Gdiplus::GpGraphics *)graphics, &scale
    );

    return scale;
}

REAL WINAPI
Graphics_GetDpiX(IN Graphics * graphics)
{
    REAL dpi;

    Gdiplus::DllExports::GdipGetDpiX(
        (Gdiplus::GpGraphics *)graphics, &dpi
    );

    return dpi;
}

REAL WINAPI
Graphics_GetDpiY(IN Graphics * graphics)
{
    REAL dpi;

    Gdiplus::DllExports::GdipGetDpiY(
        (Gdiplus::GpGraphics *)graphics, &dpi
    );

    return dpi;
}

Status WINAPI
Graphics_TransformPoints(IN Graphics * graphics,
                         IN CoordinateSpace destSpace,
                         IN CoordinateSpace srcSpace,
                         IN OUT PointF * pts,
                         IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipTransformPoints(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpCoordinateSpace)destSpace,
        (Gdiplus::GpCoordinateSpace)srcSpace,
        (Gdiplus::GpPointF *)pts,
        count
    );
}

Status WINAPI
Graphics_TransformPointsI(
    IN Graphics * graphics,
    IN CoordinateSpace destSpace,
    IN CoordinateSpace srcSpace,
    IN OUT Point * pts,
    IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipTransformPointsI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpCoordinateSpace)destSpace,
        (Gdiplus::GpCoordinateSpace)srcSpace,
        (Gdiplus::GpPoint *)pts,
        count
    );
}

Status WINAPI
Graphics_GetNearestColor(IN Graphics * graphics,
                         IN OUT Color * color
)
{
    return (Status)Gdiplus::DllExports::GdipGetNearestColor(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::ARGB *)color
    );
}

Status WINAPI
Graphics_DrawLine(IN Graphics * graphics,
                  IN Pen * pen,
                  IN REAL x1,
                  IN REAL y1,
                  IN REAL x2,
                  IN REAL y2
)
{
    return (Status)Gdiplus::DllExports::GdipDrawLine(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x1, y1, x2, y2
    );
}

Status WINAPI
Graphics_DrawLineI(IN Graphics * graphics,
                   IN Pen * pen,
                   IN INT x1,
                   IN INT y1,
                   IN INT x2,
                   IN INT y2
)
{
    return (Status)Gdiplus::DllExports::GdipDrawLineI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x1, y1, x2, y2
    );
}

Status WINAPI
Graphics_DrawLines(IN Graphics * graphics,
                   IN Pen * pen,
                   IN const PointF * points,
                   IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawLines(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_DrawLinesI(IN Graphics * graphics,
                    IN Pen * pen,
                    IN const Point * points,
                    IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawLinesI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_DrawArc(IN Graphics * graphics,
                 IN Pen * pen,
                 IN REAL x,
                 IN REAL y,
                 IN REAL width,
                 IN REAL height,
                 IN REAL startAngle,
                 IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipDrawArc(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
Graphics_DrawArcI(IN Graphics * graphics,
                  IN Pen * pen,
                  IN INT x,
                  IN INT y,
                  IN INT width,
                  IN INT height,
                  IN REAL startAngle,
                  IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipDrawArcI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
Graphics_DrawBezier(IN Graphics * graphics,
                    IN Pen * pen,
                    IN REAL x1,
                    IN REAL y1,
                    IN REAL x2,
                    IN REAL y2,
                    IN REAL x3,
                    IN REAL y3,
                    IN REAL x4,
                    IN REAL y4
)
{
    return (Status)Gdiplus::DllExports::GdipDrawBezier(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x1, y1, x2, y2, x3, y3, x4, y4
    );
}

Status WINAPI
Graphics_DrawBezierI(IN Graphics * graphics,
                     IN Pen * pen,
                     IN INT x1,
                     IN INT y1,
                     IN INT x2,
                     IN INT y2,
                     IN INT x3,
                     IN INT y3,
                     IN INT x4,
                     IN INT y4
)
{
    return (Status)Gdiplus::DllExports::GdipDrawBezierI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x1, y1, x2, y2, x3, y3, x4, y4
    );
}

Status WINAPI
Graphics_DrawBeziers(IN Graphics * graphics,
                     IN Pen * pen,
                     IN const PointF * points,
                     IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawBeziers(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_DrawBeziersI(IN Graphics * graphics,
                      IN Pen * pen,
                      IN const Point * points,
                      IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawBeziersI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_DrawRectangle(IN Graphics * graphics,
                       IN Pen * pen,
                       IN REAL x,
                       IN REAL y,
                       IN REAL width,
                       IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawRectangle(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_DrawRectangleI(IN Graphics * graphics,
                        IN Pen * pen,
                        IN INT x,
                        IN INT y,
                        IN INT width,
                        IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawRectangleI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_DrawRectangles(IN Graphics * graphics,
                        IN Pen * pen,
                        IN const RectF * rects,
                        IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawRectangles(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpRectF *)rects,
        count
    );
}

Status WINAPI
Graphics_DrawRectanglesI(IN Graphics * graphics,
                         IN Pen * pen,
                         IN const Rect * rects,
                         IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawRectanglesI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpRect *)rects,
        count
    );
}

Status WINAPI
Graphics_DrawEllipse(IN Graphics * graphics,
                     IN Pen * pen,
                     IN REAL x,
                     IN REAL y,
                     IN REAL width,
                     IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawEllipse(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
Graphics_DrawEllipseI(IN Graphics * graphics,
                      IN Pen * pen,
                      IN INT x,
                      IN INT y,
                      IN INT width,
                      IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawEllipseI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
Graphics_DrawPie(IN Graphics * graphics,
                 IN Pen * pen,
                 IN REAL x,
                 IN REAL y,
                 IN REAL width,
                 IN REAL height,
                 IN REAL startAngle,
                 IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipDrawPie(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
Graphics_DrawPieI(IN Graphics * graphics,
                  IN Pen * pen,
                  IN INT x,
                  IN INT y,
                  IN INT width,
                  IN INT height,
                  IN REAL startAngle,
                  IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipDrawPieI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        x,
        y,
        width,
        height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
Graphics_DrawPolygon(IN Graphics * graphics,
                     IN Pen * pen,
                     IN const PointF * points,
                     IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawPolygon(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_DrawPolygonI(IN Graphics * graphics,
                      IN Pen * pen,
                      IN const Point * points,
                      IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawPolygonI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_DrawPath(IN Graphics * graphics,
                  IN Pen * pen,
                  IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipDrawPath(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
Graphics_DrawCurve(IN Graphics * graphics,
                   IN Pen * pen,
                   IN const PointF * points,
                   IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurve(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_DrawCurveI(IN Graphics * graphics,
                    IN Pen * pen,
                    IN const Point * points,
                    IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurveI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_DrawCurve2(IN Graphics * graphics,
                    IN Pen * pen,
                    IN const PointF * points,
                    IN INT count,
                    IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurve2(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        tension
    );
}

Status WINAPI
Graphics_DrawCurve2I(IN Graphics * graphics,
                     IN Pen * pen,
                     IN const Point * points,
                     IN INT count,
                     IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurve2I(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        tension
    );
}

Status WINAPI
Graphics_DrawCurve3(IN Graphics * graphics,
                    IN Pen * pen,
                    IN const PointF * points,
                    IN INT count,
                    IN INT offset,
                    IN INT numberOfSegments,
                    IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurve3(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count, offset,
        numberOfSegments, tension
    );
}

Status WINAPI
Graphics_DrawCurve3I(IN Graphics * graphics,
                     IN Pen * pen,
                     IN const Point * points,
                     IN INT count,
                     IN INT offset,
                     IN INT numberOfSegments,
                     IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCurve3I(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count, offset,
        numberOfSegments, tension
    );
}

Status WINAPI
Graphics_DrawClosedCurve(IN Graphics * graphics,
                         IN Pen * pen,
                         IN const PointF * points,
                         IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawClosedCurve(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_DrawClosedCurveI(IN Graphics * graphics,
                          IN Pen * pen,
                          IN const Point * points,
                          IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipDrawClosedCurveI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_DrawClosedCurve2(IN Graphics * graphics,
                          IN Pen * pen,
                          IN const PointF * points,
                          IN INT count,
                          IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawClosedCurve2(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        tension
    );
}

Status WINAPI
Graphics_DrawClosedCurve2I(IN Graphics * graphics,
                           IN Pen * pen,
                           IN const Point * points,
                           IN INT count,
                           IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipDrawClosedCurve2I(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPen *)pen,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        tension
    );
}

Status WINAPI
Graphics_Clear(IN Graphics * graphics, IN Color color)
{
    return (Status)Gdiplus::DllExports::GdipGraphicsClear(
        (Gdiplus::GpGraphics *)graphics,
        Color_GetValue(color)
    );
}

Status WINAPI
Graphics_FillRectangle(IN Graphics * graphics,
                       IN Brush * brush,
                       IN REAL x,
                       IN REAL y,
                       IN REAL width,
                       IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipFillRectangle(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_FillRectangleI(IN Graphics * graphics,
                        IN Brush * brush,
                        IN INT x,
                        IN INT y,
                        IN INT width,
                        IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipFillRectangleI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_FillRectangles(IN Graphics * graphics,
                        IN Brush * brush,
                        IN const RectF * rects,
                        IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipFillRectangles(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpRectF *)rects,
        count
    );
}

Status WINAPI
Graphics_FillRectanglesI(IN Graphics * graphics,
                         IN Brush * brush,
                         IN const Rect * rects,
                         IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipFillRectanglesI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpRect *)rects,
        count
    );
}

Status WINAPI
Graphics_FillPolygon(IN Graphics * graphics,
                     IN Brush * brush,
                     IN const PointF * points,
                     IN INT count,
                     IN FillMode fillMode
)
{
    return (Status)Gdiplus::DllExports::GdipFillPolygon(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        (Gdiplus::GpFillMode)fillMode
    );
}

Status WINAPI
Graphics_FillPolygonI(IN Graphics * graphics,
                      IN Brush * brush,
                      IN const Point * points,
                      IN INT count,
                      IN FillMode fillMode
)
{
    return (Status)Gdiplus::DllExports::GdipFillPolygonI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        (Gdiplus::GpFillMode)fillMode
    );
}

Status WINAPI
Graphics_FillEllipse(IN Graphics * graphics,
                     IN Brush * brush,
                     IN REAL x,
                     IN REAL y,
                     IN REAL width,
                     IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipFillEllipse(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_FillEllipseI(IN Graphics * graphics,
                      IN Brush * brush,
                      IN INT x,
                      IN INT y,
                      IN INT width,
                      IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipFillEllipseI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height
    );
}

Status WINAPI
Graphics_FillPie(IN Graphics * graphics,
                 IN Brush * brush,
                 IN REAL x,
                 IN REAL y,
                 IN REAL width,
                 IN REAL height,
                 IN REAL startAngle,
                 IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipFillPie(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height,
        startAngle, sweepAngle
    );
}

Status WINAPI
Graphics_FillPieI(IN Graphics * graphics,
                  IN Brush * brush,
                  IN INT x,
                  IN INT y,
                  IN INT width,
                  IN INT height,
                  IN REAL startAngle,
                  IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipFillPieI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        x, y,
        width, height,
        startAngle, sweepAngle
    );
}

Status WINAPI
Graphics_FillPath(IN Graphics * graphics,
                  IN Brush * brush,
                  IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipFillPath(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
Graphics_FillClosedCurve(IN Graphics * graphics,
                         IN Brush * brush,
                         IN const PointF * points,
                         IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipFillClosedCurve(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
Graphics_FillClosedCurveI(IN Graphics * graphics,
                          IN Brush * brush,
                          IN const Point * points,
                          IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipFillClosedCurveI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
Graphics_FillClosedCurve2(IN Graphics * graphics,
                          IN Brush * brush,
                          IN const PointF * points,
                          IN INT count,
                          IN FillMode fillMode,
                          IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipFillClosedCurve2(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        tension,
        (Gdiplus::GpFillMode)fillMode
    );
}

Status WINAPI
Graphics_FillClosedCurve2I(IN Graphics * graphics,
                           IN Brush * brush,
                           IN const Point * points,
                           IN INT count,
                           IN FillMode fillMode,
                           IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipFillClosedCurve2I(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        tension,
        (Gdiplus::GpFillMode)fillMode
    );
}

Status WINAPI
Graphics_FillRegion(IN Graphics * graphics,
                    IN Brush * brush,
                    IN Region * region
)
{
    return (Status)Gdiplus::DllExports::GdipFillRegion(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpBrush *)brush,
        (Gdiplus::GpRegion *)region
    );
}

Status WINAPI
Graphics_DrawString(IN Graphics * graphics,
                    IN const WCHAR * string,
                    IN INT length,
                    IN const Font * font,
                    IN const RectF * layoutRect,
                    IN const StringFormat * stringFormat,
                    IN const Brush * brush
)
{
    return (Status)Gdiplus::DllExports::GdipDrawString(
        (Gdiplus::GpGraphics *)graphics,
        string,
        length,
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpRectF *)layoutRect,
        (Gdiplus::GpStringFormat *)stringFormat,
        (Gdiplus::GpBrush *)brush
    );
}

Status WINAPI
Graphics_DrawStringToPoint(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const PointF * origin,
    IN const StringFormat * stringFormat,
    IN const Brush * brush
)
{
    RectF rect;

    rect.X = origin->X;
    rect.Y = origin->Y;
    rect.Width = 0.0f;
    rect.Height = 0.0f;

    return Graphics_DrawString(graphics, string, length, font, &rect,
                               stringFormat, brush);
}

Status WINAPI
Graphics_MeasureString(IN Graphics * graphics,
                       IN const WCHAR * string,
                       IN INT length,
                       IN const Font * font,
                       IN const RectF * layoutRect,
                       IN const StringFormat * stringFormat,
                       OUT RectF * boundingBox,
                       OUT INT * codepointsFitted,
                       OUT INT * linesFilled
)
{
    return (Status)Gdiplus::DllExports::GdipMeasureString(
        (Gdiplus::GpGraphics *)graphics,
        string,
        length,
        (GDIPCONST Gdiplus::GpFont *)font,
        (GDIPCONST Gdiplus::GpRectF *)layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)stringFormat,
        (Gdiplus::GpRectF *)boundingBox,
        codepointsFitted,
        linesFilled
    );
}

Status WINAPI
Graphics_MeasureStringSize(IN Graphics * graphics,
                           IN const WCHAR * string,
                           IN INT length,
                           IN const Font * font,
                           IN const SizeF * layoutRectSize,
                           IN const StringFormat * stringFormat,
                           OUT SizeF * size,
                           OUT INT * codepointsFitted,
                           OUT INT * linesFilled
)
{
    RectF   layoutRect;
    RectF   boundingBox;
    Status  status;

    if (!size)
    {
        return InvalidParameter;
    }

    layoutRect.X = 0.0f;
    layoutRect.Y = 0.0f;
    layoutRect.Width = layoutRectSize->Width;
    layoutRect.Height = layoutRectSize->Height;

    status = Graphics_MeasureString(
        graphics, string, length, font, &layoutRect,
        stringFormat, &boundingBox, codepointsFitted, linesFilled
    );

    size->Width = boundingBox.Width;
    size->Height = boundingBox.Height;

    return status;
}

Status WINAPI
Graphics_MeasureCharacterRanges(IN Graphics * graphics,
                                IN const WCHAR * string,
                                IN INT length,
                                IN const Font * font,
                                IN const RectF * layoutRect,
                                IN const StringFormat * stringFormat,
                                IN INT regionCount,
                                OUT Region ** regions
)
{
    if (!regions || regionCount <= 0)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipMeasureCharacterRanges(
        (Gdiplus::GpGraphics *)graphics,
        string,
        length,
        (GDIPCONST Gdiplus::GpFont *)font,
        (GDIPCONST Gdiplus::GpRectF &)*layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)stringFormat,
        regionCount,
        (Gdiplus::GpRegion **)regions
    );
}

Status WINAPI
Graphics_DrawDriverString(IN Graphics * graphics,
                          IN const UINT16 * text,
                          IN INT length,
                          IN const Font * font,
                          IN const Brush * brush,
                          IN const PointF * positions,
                          IN INT flags,
                          IN const Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipDrawDriverString(
        (Gdiplus::GpGraphics *)graphics,
        text,
        length,
        (GDIPCONST Gdiplus::GpFont *)font,
        (GDIPCONST Gdiplus::GpBrush *)brush,
        (Gdiplus::GpPointF *)positions,
        flags,
        (GDIPCONST Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Graphics_MeasureDriverString(IN Graphics * graphics, 
                             IN const UINT16 * text,
                             IN INT length,
                             IN const Font * font,
                             IN const PointF * positions,
                             IN INT flags,
                             IN const Matrix * matrix,
                             OUT RectF * boundingBox
)
{
    return (Status)Gdiplus::DllExports::GdipMeasureDriverString(
        (Gdiplus::GpGraphics *)graphics,
        text,
        length,
        (GDIPCONST Gdiplus::GpFont *)font,
        (Gdiplus::GpPointF *)positions,
        flags,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpRectF *)boundingBox
    );
}

Status WINAPI
Graphics_DrawCachedBitmap(IN Graphics * graphics,
                          IN CachedBitmap * cb,
                          IN INT x,
                          IN INT y
)
{
    return (Status)Gdiplus::DllExports::GdipDrawCachedBitmap(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpCachedBitmap *)cb,
        x, y
    );
}

Status WINAPI
Graphics_DrawImage(IN Graphics * graphics,
                   IN Image * image,
                   IN REAL x,
                   IN REAL y
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImage(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x,
        y
    );
}

Status WINAPI
Graphics_DrawImageI(IN Graphics * graphics,
                    IN Image * image,
                    IN INT x,
                    IN INT y
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImageI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x,
        y
    );
}

Status WINAPI
Graphics_DrawImageRect(IN Graphics * graphics,
                       IN Image * image,
                       IN REAL x,
                       IN REAL y,
                       IN REAL width,
                       IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImageRect(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
Graphics_DrawImageRectI(IN Graphics * graphics,
                        IN Image * image,
                        IN INT x,
                        IN INT y,
                        IN INT width,
                        IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImageRectI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
Graphics_DrawImagePoints(IN Graphics * graphics,
                         IN Image * image,
                         IN const PointF * destPoints,
                         IN INT count
)
{
    if (count != 3 && count != 4)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipDrawImagePoints(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpPointF *)destPoints,
        count
    );
}

Status WINAPI
Graphics_DrawImagePointsI(IN Graphics * graphics,
                          IN Image * image,
                          IN const Point * destPoints,
                          IN INT count
)
{
    if (count != 3 && count != 4)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipDrawImagePointsI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpPoint *)destPoints,
        count
    );
}

Status WINAPI
Graphics_DrawImagePointRect(IN Graphics * graphics,
                            IN Image * image,
                            IN REAL x,
                            IN REAL y,
                            IN REAL srcx,
                            IN REAL srcy,
                            IN REAL srcwidth,
                            IN REAL srcheight,
                            IN Unit srcUnit
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImagePointRect(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x, y,
        srcx, srcy,
        srcwidth, srcheight, (Gdiplus::GpUnit)srcUnit
    );
}

Status WINAPI
Graphics_DrawImagePointRectI(IN Graphics * graphics,
                             IN Image * image,
                             IN INT x,
                             IN INT y,
                             IN INT srcx,
                             IN INT srcy,
                             IN INT srcwidth,
                             IN INT srcheight,
                             IN Unit srcUnit
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImagePointRectI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        x, y,
        srcx, srcy,
        srcwidth, srcheight, (Gdiplus::GpUnit)srcUnit
    );
}

Status WINAPI
Graphics_DrawImageRectRect(IN Graphics * graphics,
                           IN Image * image,
                           IN const RectF * destRect,
                           IN REAL srcx,
                           IN REAL srcy,
                           IN REAL srcwidth,
                           IN REAL srcheight,
                           IN Unit srcUnit,
                           IN const ImageAttributes * imageAttributes,
                           IN DrawImageAbort callback,
                           IN VOID * callbackData
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImageRectRect(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        destRect->X,
        destRect->Y,
        destRect->Width,
        destRect->Height,
        srcx, srcy,
        srcwidth, srcheight,
        (Gdiplus::GpUnit)srcUnit,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes,
        callback,
        callbackData
    );
}

Status WINAPI
Graphics_DrawImageRectRectI(IN Graphics * graphics,
                            IN Image * image,
                            IN const Rect * destRect,
                            IN INT srcx,
                            IN INT srcy,
                            IN INT srcwidth,
                            IN INT srcheight,
                            IN Unit srcUnit,
                            IN const ImageAttributes * imageAttributes,
                            IN DrawImageAbort callback,
                            IN VOID * callbackData
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImageRectRectI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        destRect->X,
        destRect->Y,
        destRect->Width,
        destRect->Height,
        srcx, srcy,
        srcwidth, srcheight,
        (Gdiplus::GpUnit)srcUnit,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes,
        callback,
        callbackData
    );
}

Status WINAPI
Graphics_DrawImagePointsRect(IN Graphics * graphics,
                             IN Image * image,
                             IN const PointF * destPoints,
                             IN INT count,
                             IN REAL srcx,
                             IN REAL srcy,
                             IN REAL srcwidth,
                             IN REAL srcheight,
                             IN Unit srcUnit,
                             IN const ImageAttributes * imageAttributes,
                             IN DrawImageAbort callback,
                             IN VOID * callbackData
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImagePointsRect(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpPointF *)destPoints, count,
        srcx, srcy,
        srcwidth,
        srcheight,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::GpImageAttributes *)imageAttributes,
        callback,
        callbackData
    );
}

Status WINAPI
Graphics_DrawImagePointsRectI(IN Graphics * graphics,
                              IN Image * image,
                              IN const Point * destPoints,
                              IN INT count,
                              IN INT srcx,
                              IN INT srcy,
                              IN INT srcwidth,
                              IN INT srcheight,
                              IN Unit srcUnit,
                              IN const ImageAttributes * imageAttributes,
                              IN DrawImageAbort callback,
                              IN VOID * callbackData
)
{
    return (Status)Gdiplus::DllExports::GdipDrawImagePointsRectI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpPoint *)destPoints, count,
        srcx, srcy,
        srcwidth,
        srcheight,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::GpImageAttributes *)imageAttributes,
        callback,
        callbackData
    );
}

Status WINAPI
Graphics_EnumerateMetafile(IN Graphics * graphics,
                           IN const Metafile * metafile,
                           IN const PointF * destPoint,
                           IN EnumerateMetafileProc  callback,
                           IN VOID * callbackData,
                           IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestPoint(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)(metafile),
        (GDIPCONST Gdiplus::GpPointF &)*destPoint,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileI(IN Graphics * graphics,
                            IN const Metafile * metafile,
                            IN const Point * destPoint,
                            IN EnumerateMetafileProc  callback,
                            IN VOID * callbackData,
                            IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestPointI(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)(metafile),
        (GDIPCONST Gdiplus::GpPoint &)*destPoint,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileDestRect(IN Graphics * graphics,
                                   IN const Metafile * metafile,
                                   IN const RectF * destRect,
                                   IN EnumerateMetafileProc callback,
                                   IN VOID * callbackData,
                                   IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestRect(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpRectF &)*destRect,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileDestRectI(IN Graphics * graphics,
                                    IN const Metafile * metafile,
                                    IN const Rect * destRect,
                                    IN EnumerateMetafileProc callback,
                                    IN VOID * callbackData,
                                    IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestRectI(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpRect &)*destRect,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileDestPoints(IN Graphics * graphics,
                                     IN const Metafile * metafile,
                                     IN const PointF * destPoints,
                                     IN INT count,
                                     IN EnumerateMetafileProc callback,
                                     IN VOID * callbackData,
                                     IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestPoints(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (Gdiplus::GpPointF *)destPoints,
        count,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileDestPointsI(IN Graphics * graphics,
                                      IN const Metafile * metafile,
                                      IN const Point * destPoints,
                                      IN INT count,
                                      IN EnumerateMetafileProc callback,
                                      IN VOID * callbackData,
                                      IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileDestPointsI(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (Gdiplus::GpPoint *)destPoints,
        count,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPoint(IN Graphics * graphics,
                                           IN const Metafile * metafile,
                                           IN const PointF * destPoint,
                                           IN const RectF * srcRect,
                                           IN Unit srcUnit,
                                           IN EnumerateMetafileProc callback,
                                           IN VOID * callbackData,
                                           IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestPoint(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpPointF &)*destPoint,
        (GDIPCONST Gdiplus::GpRectF &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPointI(IN Graphics * graphics,
                                            IN const Metafile * metafile,
                                            IN const Point * destPoint,
                                            IN const Rect * srcRect,
                                            IN Unit srcUnit,
                                            IN EnumerateMetafileProc callback,
                                            IN VOID * callbackData,
                                            IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestPointI(
        (Gdiplus::GpGraphics *)graphics,
        (GDIPCONST Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpPoint &)*destPoint,
        (GDIPCONST Gdiplus::GpRect &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestRect(IN Graphics * graphics,
                                          IN const Metafile * metafile,
                                          IN const RectF * destRect,
                                          IN const RectF * srcRect,
                                          IN Unit srcUnit,
                                          IN EnumerateMetafileProc callback,
                                          IN VOID * callbackData,
                                          IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestRect(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpRectF &)*destRect,
        (GDIPCONST Gdiplus::GpRectF &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestRectI(IN Graphics * graphics,
                                           IN const Metafile * metafile,
                                           IN const Rect * destRect,
                                           IN const Rect * srcRect,
                                           IN Unit srcUnit,
                                           IN EnumerateMetafileProc callback,
                                           IN VOID * callbackData,
                                           IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestRectI(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpRect &)*destRect,
        (GDIPCONST Gdiplus::GpRect &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPoints(IN Graphics * graphics,
                                            IN const Metafile * metafile,
                                            IN const PointF * destPoints,
                                            IN INT count,
                                            IN const RectF * srcRect,
                                            IN Unit srcUnit,
                                            IN EnumerateMetafileProc callback,
                                            IN VOID * callbackData,
                                            IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestPoints(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpPointF *)destPoints,
        count,
        (GDIPCONST Gdiplus::GpRectF &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPointsI(IN Graphics * graphics,
                                             IN const Metafile * metafile,
                                             IN const Point * destPoints,
                                             IN INT count,
                                             IN const Rect * srcRect,
                                             IN Unit srcUnit,
                                             IN EnumerateMetafileProc callback,
                                             IN VOID * callbackData,
                                             IN const ImageAttributes * imageAttributes
)
{
    return (Status)Gdiplus::DllExports::GdipEnumerateMetafileSrcRectDestPointsI(
        (Gdiplus::GpGraphics *)graphics,
        (const Gdiplus::GpMetafile *)metafile,
        (GDIPCONST Gdiplus::GpPoint *)destPoints,
        count,
        (GDIPCONST Gdiplus::GpRect &)*srcRect,
        (Gdiplus::GpUnit)srcUnit,
        (Gdiplus::EnumerateMetafileProc)callback,
        callbackData,
        (Gdiplus::GpImageAttributes *)imageAttributes
    );
}

Status WINAPI
Graphics_SetClipGraphics(IN Graphics * graphics,
                         IN Graphics * srcGraphics,
                         IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipGraphics(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpGraphics *)srcGraphics,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_SetClipRect(IN Graphics * graphics,
                     IN const RectF * rect,
                     IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipRect(
        (Gdiplus::GpGraphics *)graphics,
        rect->X, rect->Y,
        rect->Width, rect->Height,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_SetClipRectI(IN Graphics * graphics,
                      IN const Rect * rect,
                      IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipRectI(
        (Gdiplus::GpGraphics *)graphics,
        rect->X, rect->Y,
        rect->Width, rect->Height,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_SetClipPath(IN Graphics * graphics,
                     IN GraphicsPath * path,
                     IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipPath(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_SetClipRegion(IN Graphics * graphics,
                       IN Region * region,
                       IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipRegion(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRegion *)region,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_SetClipHRGN(IN Graphics * graphics,
                     IN HRGN hRgn,
                     IN CombineMode combineMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetClipHrgn(
        (Gdiplus::GpGraphics *)graphics, hRgn,
        (Gdiplus::CombineMode)combineMode
    );
}

Status WINAPI
Graphics_IntersectClipRect(IN Graphics * graphics,
                           IN const RectF * rect
)
{
    return Graphics_SetClipRect(graphics, rect, CombineModeIntersect);
}

Status WINAPI
Graphics_IntersectClipRectI(IN Graphics * graphics,
                            IN const Rect * rect
)
{
    return Graphics_SetClipRectI(graphics, rect, CombineModeIntersect);
}

Status WINAPI
Graphics_IntersectClipRegion(IN Graphics * graphics,
                             IN Region * region
)
{
    return Graphics_SetClipRegion(graphics, region, CombineModeIntersect);
}

Status WINAPI
Graphics_ExcludeClipRect(IN Graphics * graphics,
                         IN const RectF * rect
)
{
    return Graphics_SetClipRect(graphics, rect, CombineModeExclude);
}

Status WINAPI
Graphics_ExcludeClipRectI(IN Graphics * graphics,
                          IN const Rect * rect
)
{
    return Graphics_SetClipRectI(graphics, rect, CombineModeExclude);
}

Status WINAPI
Graphics_ExcludeClipRegion(IN Graphics * graphics,
                           IN Region * region
)
{
    return Graphics_SetClipRegion(graphics, region, CombineModeExclude);
}

Status WINAPI
Graphics_ResetClip(IN Graphics * graphics)
{
    return (Status)Gdiplus::DllExports::GdipResetClip(
        (Gdiplus::GpGraphics *)graphics
    );
}

Status WINAPI
Graphics_TranslateClip(IN Graphics * graphics,
                       IN REAL dx,
                       IN REAL dy
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateClip(
        (Gdiplus::GpGraphics *)graphics, dx, dy
    );
}

Status WINAPI
Graphics_TranslateClipI(
    IN Graphics * graphics,
    IN INT dx,
    IN INT dy
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateClipI(
        (Gdiplus::GpGraphics *)graphics, dx, dy
    );
}

Status WINAPI
Graphics_GetClip(IN Graphics * graphics,
                 OUT Region * region
)
{
    return (Status)Gdiplus::DllExports::GdipGetClip(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRegion *)region
    );
}

Status WINAPI
Graphics_GetClipBounds(IN Graphics * graphics,
                       OUT RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetClipBounds(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRectF *)rect
    );
}

Status WINAPI
Graphics_GetClipBoundsI(IN Graphics * graphics,
                        OUT Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetClipBoundsI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRect *)rect
    );
}

BOOL WINAPI
Graphics_IsClipEmpty(IN Graphics * graphics)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsClipEmpty(
        (Gdiplus::GpGraphics *)graphics, &booln
    );

    return booln;
}

Status WINAPI
Graphics_GetVisibleClipBounds(IN Graphics * graphics,
                              OUT RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetVisibleClipBounds(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRectF *)rect
    );
}

Status WINAPI
Graphics_GetVisibleClipBoundsI(IN Graphics * graphics,
                               OUT Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetVisibleClipBoundsI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRect *)rect
    );
}

BOOL WINAPI
Graphics_IsVisibleClipEmpty(IN Graphics * graphics)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisibleClipEmpty(
        (Gdiplus::GpGraphics *)graphics, &booln
    );

    return booln;
}

BOOL WINAPI
Graphics_IsVisiblePoint(IN Graphics * graphics,
                        IN REAL x,
                        IN REAL y
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisiblePoint(
        (Gdiplus::GpGraphics *)graphics,
        x, y,
        &booln
    );

    return booln;
}

BOOL WINAPI
Graphics_IsVisiblePointI(IN Graphics * graphics,
                         IN INT x,
                         IN INT y
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisiblePointI(
        (Gdiplus::GpGraphics *)graphics,
        x, y,
        &booln
    );

    return booln;
}

BOOL WINAPI
Graphics_IsVisibleRect(IN Graphics * graphics,
                       IN REAL x,
                       IN REAL y,
                       IN REAL width,
                       IN REAL height
)
{
    BOOL booln = TRUE;

    Gdiplus::DllExports::GdipIsVisibleRect(
        (Gdiplus::GpGraphics *)graphics,
        x, y,
        width, height,
        &booln
    );

    return booln;
}

BOOL WINAPI
Graphics_IsVisibleRectI(IN Graphics * graphics,
                        IN INT x,
                        IN INT y,
                        IN INT width,
                        IN INT height
)
{
    BOOL booln = TRUE;

    Gdiplus::DllExports::GdipIsVisibleRectI(
        (Gdiplus::GpGraphics *)graphics,
        x, y,
        width, height,
        &booln
    );

    return booln;
}

GraphicsState
Graphics_Save(IN Graphics * graphics)
{
    GraphicsState gstate;

    Gdiplus::DllExports::GdipSaveGraphics(
        (Gdiplus::GpGraphics *)graphics, &gstate
    );

    return gstate;
}

Status WINAPI
Graphics_Restore(IN Graphics * graphics,
                 IN GraphicsState gstate
)
{
    return (Status)Gdiplus::DllExports::GdipRestoreGraphics(
        (Gdiplus::GpGraphics *)graphics,
        gstate
    );
}

GraphicsContainer WINAPI
Graphics_BeginContainer(IN Graphics * graphics,
                        IN const RectF * dstRect,
                        IN const RectF * srcRect,
                        IN Unit unit
)
{
    GraphicsContainer state;

    Gdiplus::DllExports::GdipBeginContainer(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRectF *)dstRect,
        (Gdiplus::GpRectF *)srcRect,
        (Gdiplus::GpUnit)unit,
        &state
    );

    return state;
}

GraphicsContainer WINAPI
Graphics_BeginContainerI(IN Graphics * graphics,
                         IN const Rect * dstRect,
                         IN const Rect * srcRect,
                         IN Unit unit
)
{
    GraphicsContainer state;

    Gdiplus::DllExports::GdipBeginContainerI(
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpRect *)dstRect,
        (Gdiplus::GpRect *)srcRect,
        (Gdiplus::GpUnit)unit,
        &state
    );

    return state;
}

GraphicsContainer WINAPI
Graphics_BeginContainer2(IN Graphics * graphics)
{
    GraphicsContainer state;

    Gdiplus::DllExports::GdipBeginContainer2(
        (Gdiplus::GpGraphics *)graphics, &state
    );

    return state;
}

Status WINAPI
Graphics_EndContainer(IN Graphics * graphics,
                      IN GraphicsContainer state
)
{
    return (Status)Gdiplus::DllExports::GdipEndContainer(
        (Gdiplus::GpGraphics *)graphics, state
    );
}

Status WINAPI
Graphics_AddMetafileComment(IN Graphics * graphics,
                            IN const BYTE * data,
                            IN UINT sizeData
)
{
    return (Status)Gdiplus::DllExports::GdipComment(
        (Gdiplus::GpGraphics *)graphics, sizeData, data
    );
}

HPALETTE WINAPI
Graphics_GetHalftonePalette()
{
    return Gdiplus::DllExports::GdipCreateHalftonePalette();
}
