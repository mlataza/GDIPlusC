#include "stdafx.h"

Status WINAPI
GraphicsPath_Create(IN FillMode fillMode, OUT GraphicsPath ** path)
{
    return (Status)Gdiplus::DllExports::GdipCreatePath(
        (Gdiplus::GpFillMode)fillMode, 
        (Gdiplus::GpPath **)path
    );
}

Status WINAPI
GraphicsPath_Create2(IN const PointF * points,
                     IN const BYTE * types,
                     IN INT count,
                     IN FillMode fillMode,
                     OUT GraphicsPath ** path
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePath2(
        (GDIPCONST Gdiplus::PointF *)points,
        types,
        count,
        (Gdiplus::GpFillMode)fillMode,
        (Gdiplus::GpPath **)path
    );
}

Status WINAPI
GraphicsPath_Create2I(IN const Point * points,
                      IN const BYTE * types,
                      IN INT count,
                      IN FillMode fillMode,
                      OUT GraphicsPath ** path
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePath2I(
        (GDIPCONST Gdiplus::Point *)points,
        types,
        count,
        (Gdiplus::GpFillMode)fillMode,
        (Gdiplus::GpPath **)path
    );
}

Status WINAPI
GraphicsPath_Delete(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipDeletePath(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_Clone(IN GraphicsPath * path, OUT GraphicsPath ** clonePath)
{
    return (Status)Gdiplus::DllExports::GdipClonePath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpPath **)clonePath
    );
}

Status WINAPI
GraphicsPath_Reset(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipResetPath(
        (Gdiplus::GpPath *)path
    );
}

FillMode WINAPI
GraphicsPath_GetFillMode(IN GraphicsPath * path)
{
    FillMode fillmode = FillModeAlternate;

    Gdiplus::DllExports::GdipGetPathFillMode(
        (Gdiplus::GpPath *)path, 
        (Gdiplus::GpFillMode *)&fillmode
    );

    return fillmode;
}

Status WINAPI
GraphicsPath_SetFillMode(IN GraphicsPath * path, IN FillMode fillmode)
{
    return (Status)Gdiplus::DllExports::GdipSetPathFillMode(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpFillMode)fillmode
    );
}

Status WINAPI
GraphicsPath_GetPathData(IN GraphicsPath * path, OUT PathData * pathData)
{
    if (!pathData)
    {
        return InvalidParameter;
    }

    INT count = GraphicsPath_GetPointCount(path);

    if (count <= 0)
    {
        return Ok; // Do nothing.
    }

    if (!pathData->Count)
    {
        pathData->Points = NULL;
        pathData->Types = NULL;
    }

    pathData->Points = (PointF *)realloc(pathData->Points, 
                                         sizeof(PointF) * count);
    pathData->Types = (BYTE *)realloc(pathData->Types, sizeof(BYTE) * count);
    pathData->Count = count;

    if (!pathData->Points || !pathData->Types) // Can't allocate memory.
    {
        if (pathData->Points) free(pathData->Points);
        if (pathData->Types) free(pathData->Types);

        return OutOfMemory;
    }

    return (Status)Gdiplus::DllExports::GdipGetPathData(
        (Gdiplus::GpPath *)path, 
        (Gdiplus::GpPathData *)pathData
    );
}

Status WINAPI
GraphicsPath_StartFigure(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipStartPathFigure(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_CloseFigure(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipClosePathFigure(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_CloseAllFigures(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipClosePathFigures(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_SetMarker(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipSetPathMarker(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_ClearMarkers(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipClearPathMarkers(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_Reverse(IN GraphicsPath * path)
{
    return (Status)Gdiplus::DllExports::GdipReversePath(
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPath_GetLastPoint(IN GraphicsPath * path, OUT PointF * lastPoint)
{
    return (Status)Gdiplus::DllExports::GdipGetPathLastPoint(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpPointF *)lastPoint
    );
}

Status WINAPI
GraphicsPath_AddLine(IN GraphicsPath * path,
                     IN REAL x1,
                     IN REAL y1,
                     IN REAL x2,
                     IN REAL y2
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathLine(
        (Gdiplus::GpPath *)path,
        x1, y1, x2, y2
    );
}

Status WINAPI
GraphicsPath_AddLineI(IN GraphicsPath * path,
    IN INT x1,
    IN INT y1,
    IN INT x2,
    IN INT y2
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathLineI(
        (Gdiplus::GpPath *)path,
        x1, y1, x2, y2
    );
}

Status WINAPI
GraphicsPath_AddLines(IN GraphicsPath * path,
                      IN const PointF * points,
                      IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathLine2(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddLinesI(IN GraphicsPath * path,
                       IN const Point * points,
                       IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathLine2I(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddArc(IN GraphicsPath * path,
                    IN REAL x,
                    IN REAL y,
                    IN REAL width,
                    IN REAL height,
                    IN REAL startAngle,
                    IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathArc(
        (Gdiplus::GpPath *)path, x, y, width, height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
GraphicsPath_AddArcI(IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathArcI(
        (Gdiplus::GpPath *)path, x, y, width, height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
GraphicsPath_AddBezier(IN GraphicsPath * path,
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
    return (Status)Gdiplus::DllExports::GdipAddPathBezier(
        (Gdiplus::GpPath *)path,
        x1, y1, x2, y2, x3, y3, x4, y4
    );
}

Status WINAPI
GraphicsPath_AddBezierI(IN GraphicsPath * path,
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
    return (Status)Gdiplus::DllExports::GdipAddPathBezierI(
        (Gdiplus::GpPath *)path,
        x1, y1, x2, y2, x3, y3, x4, y4
    );
}

Status WINAPI
GraphicsPath_AddBeziers(IN GraphicsPath * path,
                        IN const PointF * points,
                        IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathBeziers(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddBeziersI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathBeziersI(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddCurve(IN GraphicsPath * path,
                      IN const PointF * points,
                      IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurve(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddCurveI(IN GraphicsPath * path,
                       IN const Point * points,
                       IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurveI(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddCurve2(IN GraphicsPath * path,
                       IN const PointF * points,
                       IN INT count,
                       IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurve2(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        tension
    );
}

Status WINAPI
GraphicsPath_AddCurve2I(IN GraphicsPath * path,
                        IN const Point * points,
                        IN INT count,
                        IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurve2I(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        tension
    );
}

Status WINAPI
GraphicsPath_AddCurve3(IN GraphicsPath * path,
                       IN const PointF * points,
                       IN INT count,
                       IN INT offset,
                       IN INT numberOfSegments,
                       IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurve3(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        offset,
        numberOfSegments,
        tension
    );
}

Status WINAPI
GraphicsPath_AddCurve3I(IN GraphicsPath * path,
                        IN const Point * points,
                        IN INT count,
                        IN INT offset,
                        IN INT numberOfSegments,
                        IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathCurve3I(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        offset,
        numberOfSegments,
        tension
    );
}

Status WINAPI
GraphicsPath_AddClosedCurve(IN GraphicsPath * path,
                            IN const PointF * points,
                            IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathClosedCurve(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddClosedCurveI(IN GraphicsPath * path,
                             IN const Point * points,
                             IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathClosedCurveI(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddClosedCurve2(IN GraphicsPath * path,
                             IN const PointF * points,
                             IN INT count,
                             IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathClosedCurve2(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        tension
    );
}

Status WINAPI
GraphicsPath_AddClosedCurve2I(IN GraphicsPath * path,
                              IN const Point * points,
                              IN INT count,
                              IN REAL tension
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathClosedCurve2I(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        tension
    );
}

Status WINAPI
GraphicsPath_AddRectangle(IN GraphicsPath * path,
                          IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathRectangle(
        (Gdiplus::GpPath *)path,
        rect->X,
        rect->Y,
        rect->Width,
        rect->Height
    );
}

Status WINAPI
GraphicsPath_AddRectangleI(IN GraphicsPath * path,
                          IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathRectangleI(
        (Gdiplus::GpPath *)path,
        rect->X,
        rect->Y,
        rect->Width,
        rect->Height
    );
}

Status WINAPI
GraphicsPath_AddRectangles(IN GraphicsPath * path,
                           IN const RectF * rects,
                           IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathRectangles(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpRectF *)rects,
        count
    );
}

Status WINAPI
GraphicsPath_AddRectanglesI(IN GraphicsPath * path,
                            IN const Rect * rects,
                            IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathRectanglesI(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpRect *)rects,
        count
    );
}

Status WINAPI
GraphicsPath_AddEllipse(IN GraphicsPath * path,
                        IN REAL x,
                        IN REAL y,
                        IN REAL width,
                        IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathEllipse(
        (Gdiplus::GpPath *)path,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
GraphicsPath_AddEllipseI(IN GraphicsPath * path,
                         IN INT x,
                         IN INT y,
                         IN INT width,
                         IN INT height
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathEllipseI(
        (Gdiplus::GpPath *)path,
        x,
        y,
        width,
        height
    );
}

Status WINAPI
GraphicsPath_AddPie(IN GraphicsPath * path,
                    IN REAL x,
                    IN REAL y,
                    IN REAL width,
                    IN REAL height,
                    IN REAL startAngle,
                    IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathPie(
        (Gdiplus::GpPath *)path, x, y, width, height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
GraphicsPath_AddPieI(IN GraphicsPath * path,
                     IN INT x,
                     IN INT y,
                     IN INT width,
                     IN INT height,
                     IN REAL startAngle,
                     IN REAL sweepAngle
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathPieI(
        (Gdiplus::GpPath *)path, x, y, width, height,
        startAngle,
        sweepAngle
    );
}

Status WINAPI
GraphicsPath_AddPolygon(IN GraphicsPath * path,
                        IN const PointF * points,
                        IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathPolygon(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddPolygonI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathPolygonI(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPoint *)points,
        count
    );
}

Status WINAPI
GraphicsPath_AddPath(IN GraphicsPath * path,
                     IN const GraphicsPath * addingPath,
                     IN BOOL connect
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathPath(
        (Gdiplus::GpPath *)path,
        (GDIPCONST Gdiplus::GpPath *)addingPath,
        connect
    );
}

Status WINAPI
GraphicsPath_AddString(IN GraphicsPath * path,
                       IN const WCHAR * string,
                       IN INT length,
                       IN const FontFamily * family,
                       IN INT style,
                       IN REAL emSize,
                       IN const RectF * layoutRect,
                       IN const StringFormat  * format
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathString(
        (Gdiplus::GpPath *)path,
        string,
        length,
        (GDIPCONST Gdiplus::GpFontFamily *)family,
        style,
        emSize,
        (GDIPCONST Gdiplus::GpRectF *)layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)format
    );
}

Status WINAPI
GraphicsPath_AddStringI(IN GraphicsPath * path,
                        IN const WCHAR * string,
                        IN INT length,
                        IN const FontFamily * family,
                        IN INT style,
                        IN REAL emSize,
                        IN const Rect * layoutRect,
                        IN const StringFormat  * format
)
{
    return (Status)Gdiplus::DllExports::GdipAddPathStringI(
        (Gdiplus::GpPath *)path,
        string,
        length,
        (GDIPCONST Gdiplus::GpFontFamily *)family,
        style,
        emSize,
        (GDIPCONST Gdiplus::GpRect *)layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)format
    );
}

Status WINAPI
GraphicsPath_AddString2(IN GraphicsPath * path,
                        IN const WCHAR * string,
                        IN INT length,
                        IN const FontFamily * family,
                        IN INT style,
                        IN REAL emSize,
                        IN const PointF * origin,
                        IN const StringFormat  * format
)
{
    RectF layoutRect;

    layoutRect.X = origin->X;
    layoutRect.Y = origin->Y;
    layoutRect.Width = 0.0f;
    layoutRect.Height = 0.0f;

    return (Status)Gdiplus::DllExports::GdipAddPathString(
        (Gdiplus::GpPath *)path,
        string,
        length,
        (GDIPCONST Gdiplus::GpFontFamily *)family,
        style,
        emSize,
        (GDIPCONST Gdiplus::GpRectF *)&layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)format
    );
}

Status WINAPI
GraphicsPath_AddString2I(IN GraphicsPath * path,
                         IN const WCHAR * string,
                         IN INT length,
                         IN const FontFamily * family,
                         IN INT style,
                         IN REAL emSize,
                         IN const Point * origin,
                         IN const StringFormat  * format
)
{
    Rect layoutRect;

    layoutRect.X = origin->X;
    layoutRect.Y = origin->Y;
    layoutRect.Width = 0;
    layoutRect.Height = 0;

    return (Status)Gdiplus::DllExports::GdipAddPathStringI(
        (Gdiplus::GpPath *)path,
        string,
        length,
        (GDIPCONST Gdiplus::GpFontFamily *)family,
        style,
        emSize,
        (GDIPCONST Gdiplus::GpRect *)&layoutRect,
        (GDIPCONST Gdiplus::GpStringFormat *)format
    );
}

Status WINAPI
GraphicsPath_Transform(IN GraphicsPath * path,
                       IN Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipTransformPath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
GraphicsPath_GetBounds(IN GraphicsPath * path,
                       OUT RectF * bounds,
                       IN const Matrix * matrix,
                       IN const Pen * pen
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathWorldBounds(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpRectF *)bounds,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (GDIPCONST Gdiplus::GpPen *)pen
    );
}

Status WINAPI
GraphicsPath_GetBoundsI(IN GraphicsPath * path,
                        OUT Rect * bounds,
                        IN const Matrix * matrix,
                        IN const Pen * pen
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathWorldBoundsI(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpRect *)bounds,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (GDIPCONST Gdiplus::GpPen *)pen
    );
}

Status WINAPI
GraphicsPath_Flatten(IN GraphicsPath * path,
                     IN Matrix * matrix,
                     IN REAL flatness
)
{
    return (Status)Gdiplus::DllExports::GdipFlattenPath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpMatrix *)matrix,
        flatness
    );
}

Status WINAPI
GraphicsPath_Widen(IN GraphicsPath * path,
                   IN Pen * pen,
                   IN Matrix * matrix,
                   IN REAL flatness
)
{
    return (Status)Gdiplus::DllExports::GdipWidenPath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpMatrix *)matrix,
        flatness
    );
}

Status WINAPI
GraphicsPath_Outline(IN GraphicsPath * path,
                     IN Matrix * matrix,
                     IN REAL flatness
)
{
    return (Status)Gdiplus::DllExports::GdipWindingModeOutline(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpMatrix *)matrix,
        flatness
    );
}

Status WINAPI
GraphicsPath_Warp(IN GraphicsPath * path,
                  IN const PointF * destPoints,
                  IN INT count,
                  IN const RectF * srcRect,
                  IN Matrix * matrix,
                  IN WarpMode warpMode,
                  IN REAL flatness
)
{
    return (Status)Gdiplus::DllExports::GdipWarpPath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpMatrix *)matrix,
        (GDIPCONST Gdiplus::GpPointF *)destPoints,
        count,
        srcRect->X,
        srcRect->Y,
        srcRect->Width,
        srcRect->Height,
        (Gdiplus::WarpMode)warpMode,
        flatness
    );
}

INT WINAPI
GraphicsPath_GetPointCount(IN GraphicsPath * path)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetPointCount(
        (Gdiplus::GpPath *)path, &count
    );

    return count;
}

Status WINAPI
GraphicsPath_GetPathTypes(IN GraphicsPath * path,
                          OUT BYTE * types,
                          IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathTypes(
        (Gdiplus::GpPath *)path,
        types,
        count
    );
}

Status WINAPI
GraphicsPath_GetPathPoints(IN GraphicsPath * path,
                           OUT PointF * points,
                           IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathPoints(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpPointF *)points,
        count
    );
}

Status WINAPI
GraphicsPath_GetPathPointsI(IN GraphicsPath * path,
                            OUT Point * points,
                            IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathPointsI(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpPoint *)points,
        count
    );
}

BOOL WINAPI
GraphicsPath_IsVisible(IN GraphicsPath * path,
                       IN REAL x,
                       IN REAL y,
                       IN Graphics * g
)
{
    BOOL bResult;

    Gdiplus::DllExports::GdipIsVisiblePathPoint(
        (Gdiplus::GpPath *)path,
        x, y,
        (Gdiplus::GpGraphics *)g,
        &bResult
    );

    return bResult;
}

BOOL WINAPI
GraphicsPath_IsVisibleI(IN GraphicsPath * path,
                        IN INT x,
                        IN INT y,
                        IN Graphics * g // = NULL
)
{
    BOOL bResult;

    Gdiplus::DllExports::GdipIsVisiblePathPointI(
        (Gdiplus::GpPath *)path,
        x, y,
        (Gdiplus::GpGraphics *)g,
        &bResult
    );

    return bResult;
}

BOOL WINAPI
GraphicsPath_IsOutlineVisible(IN GraphicsPath * path,
                              IN REAL x,
                              IN REAL y,
                              IN Pen * pen,
                              IN Graphics * g
)
{
    BOOL bResult;

    Gdiplus::DllExports::GdipIsOutlineVisiblePathPoint(
        (Gdiplus::GpPath *)path,
        x, y,
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpGraphics *)g,
        &bResult
    );

    return bResult;
}

BOOL WINAPI
GraphicsPath_IsOutlineVisibleI(IN GraphicsPath * path,
                               IN INT x,
                               IN INT y,
                               IN Pen * pen,
                               IN Graphics * g
)
{
    BOOL bResult;

    Gdiplus::DllExports::GdipIsOutlineVisiblePathPointI(
        (Gdiplus::GpPath *)path,
        x, y,
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpGraphics *)g,
        &bResult
    );

    return bResult;
}

Status WINAPI
GraphicsPathIterator_Create(IN GraphicsPath * path,
                            OUT GraphicsPathIterator ** pathIter
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePathIter(
        (Gdiplus::GpPathIterator **)pathIter,
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
GraphicsPathIterator_Delete(IN GraphicsPathIterator * pathIter)
{
    return (Status)Gdiplus::DllExports::GdipDeletePathIter(
        (Gdiplus::GpPathIterator *)pathIter
    );
}

INT WINAPI
GraphicsPathIterator_NextSubpath(IN GraphicsPathIterator * pathIter,
                                 OUT INT * startIndex,
                                 OUT INT * endIndex,
                                 OUT BOOL * isClosed
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterNextSubpath(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount, startIndex, endIndex, isClosed
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_NextSubpathPath(IN GraphicsPathIterator * pathIter,
                                     OUT GraphicsPath * path,
                                     OUT BOOL * isClosed
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterNextSubpathPath(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount,
        (Gdiplus::GpPath *)path,
        isClosed
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_NextPathType(IN GraphicsPathIterator * pathIter,
                                  OUT BYTE * pathType,
                                  OUT INT * startIndex,
                                  OUT INT * endIndex
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterNextPathType(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount, pathType, startIndex, endIndex
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_NextMarker(IN GraphicsPathIterator * pathIter,
                                OUT INT * startIndex,
                                OUT INT * endIndex
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterNextMarker(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount, startIndex, endIndex
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_NextMarkerPath(IN GraphicsPathIterator * pathIter,
                                    OUT GraphicsPath * path)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterNextMarkerPath(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount,
        (Gdiplus::GpPath *)path
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_GetCount(IN GraphicsPathIterator * pathIter)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterGetCount(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_GetSubpathCount(IN GraphicsPathIterator * pathIter)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterGetSubpathCount(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount
    );

    return resultCount;
}

BOOL WINAPI
GraphicsPathIterator_HasCurve(IN GraphicsPathIterator * pathIter)
{
    BOOL hasCurve;

    Gdiplus::DllExports::GdipPathIterHasCurve(
        (Gdiplus::GpPathIterator *)pathIter, &hasCurve
    );

    return hasCurve;
}

Status WINAPI
GraphicsPathIterator_Rewind(IN GraphicsPathIterator * pathIter)
{
    return (Status)Gdiplus::DllExports::GdipPathIterRewind(
        (Gdiplus::GpPathIterator *)pathIter
    );
}

INT WINAPI
GraphicsPathIterator_Enumerate(IN GraphicsPathIterator * pathIter,
                               OUT PointF * points,
                               OUT BYTE * types,
                               IN INT count
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterEnumerate(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount,
        (Gdiplus::GpPointF *)points,
        types, count
    );

    return resultCount;
}

INT WINAPI
GraphicsPathIterator_CopyData(IN GraphicsPathIterator * pathIter,
                              OUT PointF * points,
                              OUT BYTE * types,
                              IN INT startIndex,
                              IN INT endIndex
)
{
    INT resultCount;

    Gdiplus::DllExports::GdipPathIterCopyData(
        (Gdiplus::GpPathIterator *)pathIter,
        &resultCount,
        (Gdiplus::GpPointF *)points,
        types, startIndex, endIndex
    );

    return resultCount;
}

Status WINAPI
PathGradientBrush_Create(IN const PointF * points,
                         IN INT count,
                         IN WrapMode wrapMode,
                         OUT PathGradientBrush ** pgBrush
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePathGradient(
        (GDIPCONST Gdiplus::GpPointF *)points,
        count,
        (Gdiplus::GpWrapMode)wrapMode,
        (Gdiplus::GpPathGradient **)pgBrush
    );
}

Status WINAPI
PathGradientBrush_CreateI(IN const Point * points,
                          IN INT count,
                          IN WrapMode wrapMode,
                          OUT PathGradientBrush ** pgBrush
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePathGradientI(
        (GDIPCONST Gdiplus::GpPoint *)points,
        count,
        (Gdiplus::GpWrapMode)wrapMode,
        (Gdiplus::GpPathGradient **)pgBrush
    );
}

Status WINAPI
PathGradientBrush_CreateFromPath(IN const GraphicsPath * path,
                                 OUT PathGradientBrush ** pgBrush
)
{
    return (Status)Gdiplus::DllExports::GdipCreatePathGradientFromPath(
        (GDIPCONST Gdiplus::GpPath *)path,
        (Gdiplus::GpPathGradient **)pgBrush
    );
}

Color WINAPI
PathGradientBrush_GetCenterColor(IN PathGradientBrush * pgBrush)
{
    Color color = 0;

    Gdiplus::DllExports::GdipGetPathGradientCenterColor(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::ARGB *)&color
    );

    return color;
}

Status WINAPI
PathGradientBrush_SetCenterColor(IN PathGradientBrush * pgBrush,
                                 IN Color color
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientCenterColor(
        (Gdiplus::GpPathGradient *)pgBrush,
        Color_GetValue(color)
    );
}

INT WINAPI
PathGradientBrush_GetPointCount(IN PathGradientBrush * pgBrush)
{
    INT count;

    Gdiplus::DllExports::GdipGetPathGradientPointCount(
        (Gdiplus::GpPathGradient *)pgBrush, &count
    );

    return count;
}

INT WINAPI
PathGradientBrush_GetSurroundColorCount(IN PathGradientBrush * pgBrush)
{
    INT count;

    Gdiplus::DllExports::GdipGetPathGradientSurroundColorCount(
        (Gdiplus::GpPathGradient *)pgBrush, &count
    );

    return count;
}

Status WINAPI
PathGradientBrush_GetSurroundColors(IN PathGradientBrush * pgBrush,
                                    OUT Color * colors,
                                    IN OUT INT * count
)
{
    if (!colors || !count)
    {
        return InvalidParameter;
    }

    INT count1 = PathGradientBrush_GetSurroundColorCount(pgBrush);

    if ((*count < count1) || (count1 <= 0))
        return InsufficientBuffer;

    return (Status)Gdiplus::DllExports::GdipGetPathGradientSurroundColorsWithCount(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::ARGB *)colors,
        count
    );
}

Status WINAPI
PathGradientBrush_SetSurroundColors(IN PathGradientBrush * pgBrush,
                                    IN const Color * colors,
                                    IN OUT INT * count
)
{
    if (!colors || !count)
    {
        return InvalidParameter;
    }

    INT count1 = PathGradientBrush_GetPointCount(pgBrush);

    if ((*count > count1) || (count1 <= 0))
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipSetPathGradientSurroundColorsWithCount(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::ARGB *)colors,
        count
    );
}

Status WINAPI
PathGradientBrush_GetGraphicsPath(IN PathGradientBrush * pgBrush,
                                  OUT GraphicsPath * path
)
{
    if (!path)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetPathGradientPath(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpPath *)path
    );
}

Status WINAPI
PathGradientBrush_SetGraphicsPath(IN PathGradientBrush * pgBrush,
                                  IN const GraphicsPath * path
)
{
    if (!path)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipSetPathGradientPath(
        (Gdiplus::GpPathGradient *)pgBrush,
        (GDIPCONST Gdiplus::GpPath *)path
    );
}

Status WINAPI
PathGradientBrush_GetCenterPoint(IN PathGradientBrush * pgBrush,
                                 OUT PointF * point
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientCenterPoint(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpPointF *)point
    );
}

Status WINAPI
PathGradientBrush_GetCenterPointI(IN PathGradientBrush * pgBrush,
                                  OUT Point * point
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientCenterPointI(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpPoint *)point
    );
}

Status WINAPI
PathGradientBrush_SetCenterPoint(IN PathGradientBrush * pgBrush,
                                 IN const PointF * point
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientCenterPoint(
        (Gdiplus::GpPathGradient *)pgBrush,
        (GDIPCONST Gdiplus::GpPointF *)point
    );
}

Status WINAPI
PathGradientBrush_SetCenterPointI(IN PathGradientBrush * pgBrush,
                                  IN const Point * point
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientCenterPointI(
        (Gdiplus::GpPathGradient *)pgBrush,
        (GDIPCONST Gdiplus::GpPoint *)point
    );
}

Status WINAPI
PathGradientBrush_GetRectangle(IN PathGradientBrush * pgBrush,
                               OUT RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientRect(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpRectF *)rect
    );
}

Status WINAPI
PathGradientBrush_GetRectangleI(IN PathGradientBrush * pgBrush,
                                OUT Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientRectI(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpRect *)rect
    );
}

Status WINAPI
PathGradientBrush_SetGammaCorrection(IN PathGradientBrush * pgBrush,
                                     IN BOOL useGammaCorrection
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientGammaCorrection(
        (Gdiplus::GpPathGradient *)pgBrush, useGammaCorrection
    );
}

BOOL WINAPI
PathGradientBrush_GetGammaCorrection(IN PathGradientBrush * pgBrush)
{
    BOOL useGammaCorrection;

    Gdiplus::DllExports::GdipGetPathGradientGammaCorrection(
        (Gdiplus::GpPathGradient *)pgBrush, &useGammaCorrection
    );

    return useGammaCorrection;
}

INT WINAPI
PathGradientBrush_GetBlendCount(IN PathGradientBrush * pgBrush)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetPathGradientBlendCount(
        (Gdiplus::GpPathGradient *)pgBrush, &count
    );

    return count;
}

Status WINAPI
PathGradientBrush_GetBlend(IN PathGradientBrush * pgBrush,
                           OUT REAL * blendFactors,
                           OUT REAL * blendPositions,
                           IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientBlend(
        (Gdiplus::GpPathGradient *)pgBrush,
        blendFactors, blendPositions, count
    );
}

Status WINAPI
PathGradientBrush_SetBlend(IN PathGradientBrush * pgBrush,
                           IN const REAL * blendFactors,
                           IN const REAL * blendPositions,
                           IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientBlend(
        (Gdiplus::GpPathGradient *)pgBrush,
        blendFactors, blendPositions, count
    );
}

INT WINAPI
PathGradientBrush_GetInterpolationColorCount(IN PathGradientBrush * pgBrush)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetPathGradientPresetBlendCount(
        (Gdiplus::GpPathGradient *)pgBrush, &count
    );

    return count;
}

Status WINAPI
PathGradientBrush_SetInterpolationColors(IN PathGradientBrush * pgBrush,
                                         IN const Color * presetColors,
                                         IN const REAL * blendPositions,
                                         IN INT count
)
{
    if ((count <= 0) || !presetColors || !blendPositions)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipSetPathGradientPresetBlend(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::ARGB *)presetColors,
        blendPositions,
        count
    );
}

Status WINAPI
PathGradientBrush_GetInterpolationColors(IN PathGradientBrush * pgBrush,
                                         OUT Color * presetColors,
                                         OUT REAL * blendPositions,
                                         IN INT count
)
{
    if ((count <= 0) || !presetColors || !blendPositions)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipGetPathGradientPresetBlend(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::ARGB *)presetColors,
        blendPositions,
        count
    );
}

Status WINAPI
PathGradientBrush_SetBlendBellShape(IN PathGradientBrush * pgBrush,
                                    IN REAL focus,
                                    IN REAL scale
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientSigmaBlend(
        (Gdiplus::GpPathGradient *)pgBrush, focus, scale
    );
}

Status WINAPI
PathGradientBrush_SetBlendTriangularShape(IN PathGradientBrush * pgBrush,
                                          IN REAL focus,
                                          IN REAL scale
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientLinearBlend(
        (Gdiplus::GpPathGradient *)pgBrush, focus, scale
    );
}

Status WINAPI
PathGradientBrush_GetTransform(IN PathGradientBrush * pgBrush,
                               OUT Matrix *matrix
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
PathGradientBrush_SetTransform(IN PathGradientBrush * pgBrush,
                               IN Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
PathGradientBrush_ResetTransform(IN PathGradientBrush * pgBrush)
{
    return (Status)Gdiplus::DllExports::GdipResetPathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush
    );
}

Status WINAPI
PathGradientBrush_MultiplyTransform(IN PathGradientBrush * pgBrush,
                                    IN const Matrix * matrix,
                                    IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyPathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
PathGradientBrush_TranslateTransform(IN PathGradientBrush * pgBrush,
                                     IN REAL dx,
                                     IN REAL dy,
                                     IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslatePathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        dx, dy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
PathGradientBrush_ScaleTransform(IN PathGradientBrush * pgBrush,
                                 IN REAL sx,
                                 IN REAL sy,
                                 IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScalePathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        sx, sy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
PathGradientBrush_RotateTransform(IN PathGradientBrush * pgBrush,
                                  IN REAL angle,
                                  IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotatePathGradientTransform(
        (Gdiplus::GpPathGradient *)pgBrush,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
PathGradientBrush_GetFocusScales(IN PathGradientBrush * pgBrush,
                                 OUT REAL * xScale,
                                 OUT REAL * yScale
)
{
    return (Status)Gdiplus::DllExports::GdipGetPathGradientFocusScales(
        (Gdiplus::GpPathGradient *)pgBrush, xScale, yScale
    );
}

Status WINAPI
PathGradientBrush_SetFocusScales(IN PathGradientBrush * pgBrush,
                                 IN REAL xScale,
                                 IN REAL yScale
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientFocusScales(
        (Gdiplus::GpPathGradient *)pgBrush, xScale, yScale
    );
}

WrapMode WINAPI
PathGradientBrush_GetWrapMode(IN PathGradientBrush * pgBrush)
{
    WrapMode wrapMode;

    Gdiplus::DllExports::GdipGetPathGradientWrapMode(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpWrapMode *)&wrapMode
    );

    return wrapMode;
}

Status WINAPI
PathGradientBrush_SetWrapMode(IN PathGradientBrush * pgBrush,
                              IN WrapMode wrapMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetPathGradientWrapMode(
        (Gdiplus::GpPathGradient *)pgBrush,
        (Gdiplus::GpWrapMode)wrapMode
    );
}