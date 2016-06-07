#include "stdafx.h"

Status WINAPI
Region_Create(OUT Region ** region)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegion(
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_CreateFromRect(IN const RectF * rect,
                  OUT Region ** region
)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegionRect(
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_CreateFromRectI(IN const Rect * rect,
                   OUT Region ** region
)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegionRectI(
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_CreateFromPath(IN GraphicsPath * path,
                  OUT Region ** region
)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegionPath(
        (Gdiplus::GpPath *)path,
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_CreateFromRgnData(IN const BYTE * regionData,
                         IN INT size,
                         OUT Region ** region
)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegionRgnData(
        regionData, size,
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_CreateFromHrgn(IN HRGN hRgn,
                      OUT Region ** region
)
{
    return (Status)Gdiplus::DllExports::GdipCreateRegionHrgn(
        hRgn,
        (Gdiplus::GpRegion **)region
    );
}

Status WINAPI
Region_Delete(IN Region * region)
{
    return (Status)Gdiplus::DllExports::GdipDeleteRegion(
        (Gdiplus::GpRegion *)region
    );
}

Status WINAPI
Region_Clone(IN Region * region,
             OUT Region ** clone
)
{
    return (Status)Gdiplus::DllExports::GdipCloneRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion **)clone
    );
}

Status WINAPI
Region_MakeInfinite(IN Region * region)
{
    return (Status)Gdiplus::DllExports::GdipSetInfinite(
        (Gdiplus::GpRegion *)region
    );
}

Status WINAPI
Region_MakeEmpty(IN Region * region)
{
    return (Status)Gdiplus::DllExports::GdipSetEmpty(
        (Gdiplus::GpRegion *)region
    );
}

Status WINAPI
Region_IntersectRect(IN Region * region,
                     IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRect(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::CombineMode)CombineModeIntersect
    );
}

Status WINAPI
Region_IntersectRectI(IN Region * region,
                      IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRectI(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::CombineMode)CombineModeIntersect
    );
}

Status WINAPI
Region_IntersectPath(IN Region * region,
                     IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionPath(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)CombineModeIntersect
    );
}

Status WINAPI
Region_IntersectRegion(IN Region * region,
                       IN Region * srcRegion
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)srcRegion,
        (Gdiplus::CombineMode)CombineModeIntersect
    );
}

Status WINAPI
Region_UnionRect(IN Region * region,
                 IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRect(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::CombineMode)CombineModeUnion
    );
}

Status WINAPI
Region_UnionRectI(IN Region * region,
                  IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRectI(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::CombineMode)CombineModeUnion
    );
}

Status WINAPI
Region_UnionPath(IN Region * region,
                 IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionPath(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)CombineModeUnion
    );
}

Status WINAPI
Region_UnionRegion(IN Region * region,
                   IN Region * srcRegion
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)srcRegion,
        (Gdiplus::CombineMode)CombineModeUnion
    );
}

Status WINAPI
Region_XorRect(IN Region * region,
               IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRect(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::CombineMode)CombineModeXor
    );
}

Status WINAPI
Region_XorRectI(IN Region * region,
                IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRectI(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::CombineMode)CombineModeXor
    );
}

Status WINAPI
Region_XorPath(IN Region * region,
               IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionPath(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)CombineModeXor
    );
}

Status WINAPI
Region_XorRegion(IN Region * region,
                 IN Region * srcRegion
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)srcRegion,
        (Gdiplus::CombineMode)CombineModeXor
    );
}

Status WINAPI
Region_ExcludeRect(IN Region * region,
                   IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRect(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::CombineMode)CombineModeExclude
    );
}

Status WINAPI
Region_ExcludeRectI(IN Region * region,
                    IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRectI(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::CombineMode)CombineModeExclude
    );
}

Status WINAPI
Region_ExcludePath(IN Region * region,
                   IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionPath(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)CombineModeExclude
    );
}

Status WINAPI
Region_ExcludeRegion(IN Region * region,
                     IN Region * srcRegion
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)srcRegion,
        (Gdiplus::CombineMode)CombineModeExclude
    );
}

Status WINAPI
Region_ComplementRect(IN Region * region,
                      IN const RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRect(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (Gdiplus::CombineMode)CombineModeComplement
    );
}

Status WINAPI
Region_ComplementRectI(IN Region * region,
                       IN const Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRectI(
        (Gdiplus::GpRegion *)region,
        (GDIPCONST Gdiplus::GpRect *)rect,
        (Gdiplus::CombineMode)CombineModeComplement
    );
}

Status WINAPI
Region_ComplementPath(IN Region * region,
                      IN GraphicsPath * path
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionPath(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpPath *)path,
        (Gdiplus::CombineMode)CombineModeComplement
    );
}

Status WINAPI
Region_ComplementRegion(IN Region * region,
                        IN Region * srcRegion
)
{
    return (Status)Gdiplus::DllExports::GdipCombineRegionRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)srcRegion,
        (Gdiplus::CombineMode)CombineModeComplement
    );
}

Status WINAPI
Region_Translate(IN Region * region,
                 IN REAL dx,
                 IN REAL dy
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateRegion(
        (Gdiplus::GpRegion *)region, dx, dy
    );
}

Status WINAPI
Region_TranslateI(IN Region * region,
                  IN INT dx,
                  IN INT dy
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateRegionI(
        (Gdiplus::GpRegion *)region, dx, dy
    );
}

Status WINAPI
Region_Transform(IN Region * region,
                 IN Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipTransformRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Region_GetBounds(IN Region * region,
                 OUT RectF * rect,
                 IN Graphics * g
)
{
    return (Status)Gdiplus::DllExports::GdipGetRegionBounds(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpGraphics *)g,
        (Gdiplus::GpRectF *)rect
    );
}

Status WINAPI
Region_GetBoundsI(IN Region * region,
                  OUT Rect * rect,
                  IN Graphics * g
)
{
    return (Status)Gdiplus::DllExports::GdipGetRegionBoundsI(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpGraphics *)g,
        (Gdiplus::GpRect *)rect
    );
}

HRGN WINAPI
Region_GetHRGN(IN Region * region,
               IN Graphics * g
)
{
    HRGN hrgn;

    (Status)Gdiplus::DllExports::GdipGetRegionHRgn(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpGraphics *)g,
        &hrgn
    );

    return hrgn;
}

BOOL WINAPI
Region_IsEmpty(IN Region * region,
               IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsEmptyRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

BOOL WINAPI
Region_IsInfinite(IN Region * region,
                  IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsInfiniteRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

BOOL WINAPI
Region_Equals(IN Region * region,
              IN Region * region2,
              IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsEqualRegion(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRegion *)region2,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

UINT WINAPI
Region_GetDataSize(IN Region * region)
{
    UINT bufferSize = 0;

    Gdiplus::DllExports::GdipGetRegionDataSize(
        (Gdiplus::GpRegion *)region, &bufferSize
    );

    return bufferSize;
}

Status WINAPI
Region_GetData(IN Region * region,
               OUT BYTE * buffer,
               IN UINT bufferSize,
               OUT UINT * sizeFilled
)
{
    return (Status)Gdiplus::DllExports::GdipGetRegionData(
        (Gdiplus::GpRegion *)region, buffer,
        bufferSize, sizeFilled
    );
}

BOOL WINAPI
Region_IsVisiblePoint(IN Region * region,
                 IN const PointF * point,
                 IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisibleRegionPoint(
        (Gdiplus::GpRegion *)region,
        point->X, point->Y,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

BOOL WINAPI
Region_IsVisiblePointI(IN Region * region,
                       IN const Point * point,
                       IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisibleRegionPointI(
        (Gdiplus::GpRegion *)region,
        point->X, point->Y,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

BOOL WINAPI
Region_IsVisibleRect(IN Region * region,
                     IN const RectF * rect,
                     IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisibleRegionRect(
        (Gdiplus::GpRegion *)region,
        rect->X, rect->Y,
        rect->Width, rect->Height,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

BOOL WINAPI
Region_IsVisibleRectI(IN Region * region,
                      IN const Rect * rect,
                      IN Graphics * g
)
{
    BOOL booln = FALSE;

    Gdiplus::DllExports::GdipIsVisibleRegionRectI(
        (Gdiplus::GpRegion *)region,
        rect->X, rect->Y,
        rect->Width, rect->Height,
        (Gdiplus::GpGraphics *)g,
        &booln
    );

    return booln;
}

UINT WINAPI
Region_GetRegionScansCount(IN Region * region,
                           IN Matrix * matrix
)
{
    UINT count = 0;

    Gdiplus::DllExports::GdipGetRegionScansCount(
        (Gdiplus::GpRegion *)region,
        &count,
        (Gdiplus::GpMatrix *)matrix
    );

    return count;
}

Status WINAPI
Region_GetRegionScans(IN Region * region,
                      IN Matrix * matrix,
                      OUT RectF * rects,
                      IN OUT INT * count
)
{
    return (Status)Gdiplus::DllExports::GdipGetRegionScans(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRectF *)rects,
        count,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Region_GetRegionScansI(IN Region * region,
                       IN Matrix * matrix,
                       OUT Rect * rects,
                       IN OUT INT * count
)
{
    return (Status)Gdiplus::DllExports::GdipGetRegionScansI(
        (Gdiplus::GpRegion *)region,
        (Gdiplus::GpRect *)rects,
        count,
        (Gdiplus::GpMatrix *)matrix
    );
}