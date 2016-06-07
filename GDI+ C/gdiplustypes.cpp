#include "stdafx.h"

//
//  SizeF
//
BOOL WINAPI SizeF_Equals(IN const SizeF* sz1, IN const SizeF* sz2)
{
    return (sz1->Width == sz2->Width) && (sz1->Height == sz1->Height);
}

BOOL WINAPI SizeF_Empty(IN const SizeF* sz)
{
    return (sz->Width == 0.0f && sz->Height == 0.0f);
}

//
// Size
//
BOOL WINAPI Size_Equals(IN const Size* sz1, IN const Size* sz2)
{
    return (sz1->Width == sz2->Width) && (sz1->Height == sz2->Height);
}

BOOL WINAPI Size_Empty(IN const Size* sz)
{
    return (sz->Width == 0 && sz->Height == 0);
}

//
// PointF
//
BOOL WINAPI PointF_Equals(IN const PointF* point1, IN const PointF* point2)
{
    return (point1->X == point2->X) && (point1->Y == point2->Y);
}

//
// Point
//
BOOL WINAPI Point_Equals(IN const Point* point1, IN const Point* point2)
{
    return (point1->X == point2->X) && (point1->Y == point2->Y);
}

//
// RectF
//

VOID WINAPI RectF_GetLocation(IN const RectF* rect, OUT PointF* point)
{
    point->X = rect->X;
    point->Y = rect->Y;
}

VOID WINAPI RectF_GetSize(IN const RectF* rect, OUT SizeF* size)
{
    size->Width = rect->Width;
    size->Height = rect->Height;
}

VOID WINAPI RectF_GetBounds(IN const RectF* rect, OUT RectF* destRect)
{
    destRect->X = rect->X;
    destRect->Y = rect->Y;
    destRect->Width = rect->Width;
    destRect->Height = rect->Height;
}

REAL WINAPI RectF_GetLeft(IN const RectF* rect)
{
    return rect->X;
}

REAL WINAPI RectF_GetTop(IN const RectF* rect)
{
    return rect->Y;
}

REAL WINAPI RectF_GetRight(IN const RectF* rect)
{
    return rect->X + rect->Width;
}

REAL WINAPI RectF_GetBottom(IN const RectF* rect)
{
    return rect->Y + rect->Height;
}

BOOL WINAPI RectF_IsEmptyArea(IN const RectF* rect)
{
    return (rect->Width <= REAL_EPSILON) || (rect->Height <= REAL_EPSILON);
}

BOOL WINAPI RectF_Equals(IN const RectF* rect1, IN const RectF* rect2)
{
    return rect1->X == rect2->X &&
        rect1->Y == rect2->Y &&
        rect1->Width == rect2->Width &&
        rect1->Height == rect2->Height;
}

BOOL WINAPI RectF_Contains(IN const RectF* rect,
                           IN REAL x,
                           IN REAL y)
{
    return x >= rect->X && x < RectF_GetRight(rect) &&
        y >= rect->Y && y < RectF_GetBottom(rect);
}

VOID WINAPI RectF_Inflate(OUT RectF* rect,
                          IN REAL dx,
                          IN REAL dy)
{
    rect->X -= dx;
    rect->Y -= dy;
    rect->Width += 2 * dx;
    rect->Height += 2 * dy;
}

BOOL WINAPI RectF_Intersect(OUT RectF* c,
                            IN const RectF* a,
                            IN const RectF* b)
{
    REAL right = min(RectF_GetRight(a), RectF_GetRight(b));
    REAL bottom = min(RectF_GetBottom(a), RectF_GetBottom(b));
    REAL left = max(RectF_GetLeft(a), RectF_GetLeft(b));
    REAL top = max(RectF_GetTop(a), RectF_GetTop(b));

    c->X = left;
    c->Y = top;
    c->Width = right - left;
    c->Height = bottom - top;
    return !RectF_IsEmptyArea(c);
}

BOOL WINAPI RectF_IntersectsWith(IN const RectF* rect1, IN const RectF* rect2)
{
    return (RectF_GetLeft(rect1) < RectF_GetRight(rect2) &&
            RectF_GetTop(rect1) < RectF_GetBottom(rect2) &&
            RectF_GetRight(rect1) > RectF_GetLeft(rect2) &&
            RectF_GetBottom(rect1) > RectF_GetTop(rect2));
}

BOOL WINAPI RectF_Union(OUT RectF* c,
                        IN const RectF* a,
                        IN const RectF* b)
{
    REAL right = max(RectF_GetRight(a), RectF_GetRight(b));
    REAL bottom = max(RectF_GetBottom(a), RectF_GetBottom(b));
    REAL left = min(RectF_GetLeft(a), RectF_GetLeft(b));
    REAL top = min(RectF_GetTop(a), RectF_GetTop(b));

    c->X = left;
    c->Y = top;
    c->Width = right - left;
    c->Height = bottom - top;
    return !RectF_IsEmptyArea(c);
}

VOID WINAPI RectF_Offset(OUT RectF* rect,
                         IN REAL dx,
                         IN REAL dy)
{
    rect->X += dx;
    rect->Y += dy;
}

//
// Rect
//
VOID WINAPI Rect_GetLocation(IN const Rect* rect, OUT Point* point)
{
    point->X = rect->X;
    point->Y = rect->Y;
}

VOID WINAPI Rect_GetSize(IN const Rect* rect, OUT Size* size)
{
    size->Width = rect->Width;
    size->Height = rect->Height;
}

VOID WINAPI Rect_GetBounds(IN const Rect* rect, OUT Rect* destRect)
{
    destRect->X = rect->X;
    destRect->Y = rect->Y;
    destRect->Width = rect->Width;
    destRect->Height = rect->Height;
}

INT WINAPI Rect_GetLeft(IN const Rect* rect)
{
    return rect->X;
}

INT WINAPI Rect_GetTop(IN const Rect* rect)
{
    return rect->Y;
}

INT WINAPI Rect_GetRight(IN const Rect* rect)
{
    return rect->X + rect->Width;
}

INT WINAPI Rect_GetBottom(IN const Rect* rect)
{
    return rect->Y + rect->Height;
}

BOOL WINAPI Rect_IsEmptyArea(IN const Rect* rect)
{
    return (rect->Width == 0) || (rect->Height == 0);
}

BOOL WINAPI Rect_Equals(IN const Rect* rect1, IN const Rect* rect2)
{
    return rect1->X == rect2->X &&
        rect1->Y == rect2->Y &&
        rect1->Width == rect2->Width &&
        rect1->Height == rect2->Height;
}

BOOL WINAPI Rect_Contains(IN const Rect* rect,
                          IN INT x,
                          IN INT y)
{
    return x >= rect->X && x < Rect_GetRight(rect) &&
        y >= rect->Y && y < Rect_GetBottom(rect);
}

VOID WINAPI Rect_Inflate(OUT Rect* rect,
                         IN INT dx,
                         IN INT dy)
{
    rect->X -= dx;
    rect->Y -= dy;
    rect->Width += 2 * dx;
    rect->Height += 2 * dy;
}

BOOL WINAPI Rect_Intersect(OUT Rect* c,
                           IN const Rect* a,
                           IN const Rect* b)
{
    INT right = min(Rect_GetRight(a), Rect_GetRight(b));
    INT bottom = min(Rect_GetBottom(a), Rect_GetBottom(b));
    INT left = max(Rect_GetLeft(a), Rect_GetLeft(b));
    INT top = max(Rect_GetTop(a), Rect_GetTop(b));

    c->X = left;
    c->Y = top;
    c->Width = right - left;
    c->Height = bottom - top;
    return !Rect_IsEmptyArea(c);
}

BOOL WINAPI Rect_IntersectsWith(IN const Rect* rect1, IN const Rect* rect2)
{
    return (Rect_GetLeft(rect1) < Rect_GetRight(rect2) &&
            Rect_GetTop(rect1) < Rect_GetBottom(rect2) &&
            Rect_GetRight(rect1) > Rect_GetLeft(rect2) &&
            Rect_GetBottom(rect1) > Rect_GetTop(rect2));
}

BOOL WINAPI Rect_Union(OUT Rect* c,
                       IN const Rect* a,
                       IN const Rect* b)
{
    INT right = max(Rect_GetRight(a), Rect_GetRight(b));
    INT bottom = max(Rect_GetBottom(a), Rect_GetBottom(b));
    INT left = min(Rect_GetLeft(a), Rect_GetLeft(b));
    INT top = min(Rect_GetTop(a), Rect_GetTop(b));

    c->X = left;
    c->Y = top;
    c->Width = right - left;
    c->Height = bottom - top;
    return !Rect_IsEmptyArea(c);
}

VOID WINAPI Rect_Offset(OUT Rect* rect,
                        IN INT dx,
                        IN INT dy)
{
    rect->X += dx;
    rect->Y += dy;
}

//
// PathData
//
VOID WINAPI PathData_Destroy(IN PathData* pathData)
{
    if (pathData->Points)
    {
        free(pathData->Points);
    }

    if (pathData->Points)
    {
        free(pathData->Types);
    }
}