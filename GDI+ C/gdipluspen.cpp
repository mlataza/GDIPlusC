#include "stdafx.h"

Status WINAPI
Pen_Create(IN Color color, IN REAL width, OUT Pen ** pen)
{
    Unit unit = UnitWorld;
    
    return (Status)Gdiplus::DllExports::GdipCreatePen1(
        Color_GetValue(color),
        width, 
        (Gdiplus::GpUnit)unit, 
        (Gdiplus::GpPen **)pen
    );
}

Status WINAPI
Pen_Create2(IN Brush * brush, IN REAL width, OUT Pen ** pen)
{
    Unit unit = UnitWorld;
    
    return (Status)Gdiplus::DllExports::GdipCreatePen2(
        (Gdiplus::GpBrush *)brush,
        width,
        (Gdiplus::GpUnit)unit,
        (Gdiplus::GpPen **)pen
    );
}

Status WINAPI
Pen_Delete(IN Pen * pen)
{
    return (Status)Gdiplus::DllExports::GdipDeletePen(
        (Gdiplus::GpPen *)pen
    );
}

Status WINAPI
Pen_Clone(IN Pen * pen, OUT Pen ** clone)
{
    return (Status)Gdiplus::DllExports::GdipClonePen(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpPen **)clone
    );
}

Status WINAPI
Pen_SetWidth(IN Pen * pen, IN REAL width)
{
    return (Status)Gdiplus::DllExports::GdipSetPenWidth(
        (Gdiplus::GpPen *)pen, width
    );
}

REAL WINAPI
Pen_GetWidth(IN Pen * pen)
{
    REAL width;

    Gdiplus::DllExports::GdipGetPenWidth(
        (Gdiplus::GpPen *)pen, &width
    );

    return width;
}

Status WINAPI
Pen_SetLineCap(IN Pen * pen,
               IN LineCap startCap,
               IN LineCap endCap,
               IN DashCap dashCap
)
{
    return (Status)Gdiplus::DllExports::GdipSetPenLineCap197819(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpLineCap)startCap,
        (Gdiplus::GpLineCap)endCap,
        (Gdiplus::DashCap)dashCap
    );
}

Status WINAPI
Pen_SetStartCap(IN Pen * pen, IN LineCap startCap)
{
    return (Status)Gdiplus::DllExports::GdipSetPenStartCap(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineCap)startCap
    );
}

Status WINAPI
Pen_SetEndCap(IN Pen * pen, IN LineCap endCap)
{
    return (Status)Gdiplus::DllExports::GdipSetPenEndCap(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineCap)endCap
    );
}

Status WINAPI
Pen_SetDashCap(IN Pen * pen, IN DashCap dashCap)
{
    return (Status)Gdiplus::DllExports::GdipSetPenDashCap197819(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpDashCap)dashCap
    );
}

LineCap WINAPI
Pen_GetStartCap(IN Pen * pen)
{
    LineCap startCap;

    Gdiplus::DllExports::GdipGetPenStartCap(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineCap *)&startCap
    );

    return startCap;
}

LineCap WINAPI
Pen_GetEndCap(IN Pen * pen)
{
    LineCap endCap;

    Gdiplus::DllExports::GdipGetPenEndCap(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineCap *)&endCap
    );

    return endCap;
}

DashCap WINAPI
Pen_GetDashCap(IN Pen * pen)
{
    DashCap dashCap;

    Gdiplus::DllExports::GdipGetPenDashCap197819(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpDashCap *)&dashCap
    );

    return dashCap;
}

Status WINAPI
Pen_SetLineJoin(IN Pen * pen, IN LineJoin lineJoin)
{
    return (Status)Gdiplus::DllExports::GdipSetPenLineJoin(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineJoin)lineJoin
    );
}

LineJoin WINAPI
Pen_GetLineJoin(IN Pen * pen)
{
    LineJoin lineJoin;

    Gdiplus::DllExports::GdipGetPenLineJoin(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpLineJoin *)&lineJoin
    );

    return lineJoin;
}

Status WINAPI
Pen_SetCustomStartCap(IN Pen * pen, IN CustomLineCap * customCap)
{
    return (Status)Gdiplus::DllExports::GdipSetPenCustomStartCap(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpCustomLineCap *)customCap
    );
}

Status WINAPI
Pen_GetCustomStartCap(IN Pen * pen, OUT CustomLineCap ** customCap)
{
    if (!customCap)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetPenCustomStartCap(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpCustomLineCap **)customCap
    );
}

Status WINAPI
Pen_SetCustomEndCap(IN Pen * pen, IN CustomLineCap * customCap)
{
    return (Status)Gdiplus::DllExports::GdipSetPenCustomEndCap(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpCustomLineCap *)customCap
    );
}

Status WINAPI
Pen_GetCustomEndCap(IN Pen * pen, OUT CustomLineCap ** customCap)
{
    if (!customCap)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetPenCustomEndCap(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpCustomLineCap **)customCap
    );
}

Status WINAPI
Pen_SetMiterLimit(IN Pen * pen, IN REAL miterLimit)
{
    return (Status)Gdiplus::DllExports::GdipSetPenMiterLimit(
        (Gdiplus::GpPen *)pen,
        miterLimit
    );
}

REAL WINAPI
Pen_GetMiterLimit(IN Pen * pen)
{
    REAL miterLimit;

    Gdiplus::DllExports::GdipGetPenMiterLimit(
        (Gdiplus::GpPen *)pen, &miterLimit
    );

    return miterLimit;
}

Status WINAPI
Pen_SetAlignment(IN Pen * pen, IN PenAlignment penAlignment)
{
    return (Status)Gdiplus::DllExports::GdipSetPenMode(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpPenAlignment)penAlignment
    );
}

PenAlignment WINAPI
Pen_GetAlignment(IN Pen * pen)
{
    PenAlignment penAlignment;

    Gdiplus::DllExports::GdipGetPenMode(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpPenAlignment *)&penAlignment
    );

    return penAlignment;
}

Status WINAPI
Pen_SetTransform(IN Pen * pen, IN Matrix * matrix)
{
    return (Status)Gdiplus::DllExports::GdipSetPenTransform(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Pen_GetTransform(IN Pen * pen, OUT Matrix * matrix)
{
    return (Status)Gdiplus::DllExports::GdipGetPenTransform(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Pen_ResetTransform(IN Pen * pen)
{
    return (Status)Gdiplus::DllExports::GdipResetPenTransform(
        (Gdiplus::GpPen *)pen
    );
}

Status WINAPI
Pen_MultiplyTransform(IN Pen * pen,
                      IN Matrix * matrix,
                      IN MatrixOrder order)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyPenTransform(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Pen_TranslateTransform(IN Pen * pen,
                       IN REAL dx,
                       IN REAL dy,
                       IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslatePenTransform(
        (Gdiplus::GpPen *)pen,
        dx, dy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Pen_ScaleTransform(IN Pen * pen,
                   IN REAL sx,
                   IN REAL sy,
                   IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScalePenTransform(
        (Gdiplus::GpPen *)pen,
        sx, sy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Pen_RotateTransform(IN Pen * pen,
                    IN REAL angle,
                    IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotatePenTransform(
        (Gdiplus::GpPen *)pen,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

PenType WINAPI
Pen_GetPenType(IN Pen * pen)
{
    PenType type;

    Gdiplus::DllExports::GdipGetPenFillType(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpPenType *)&type
    );

    return type;
}

Status WINAPI
Pen_SetColor(IN Pen * pen, IN Color color)
{
    return (Status)Gdiplus::DllExports::GdipSetPenColor(
        (Gdiplus::GpPen *)pen,
        Color_GetValue(color)
    );
}

Status WINAPI
Pen_SetBrush(IN Pen * pen, IN Brush * brush)
{
    return (Status)Gdiplus::DllExports::GdipSetPenBrushFill(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpBrush *)brush
    );
}

Status WINAPI
Pen_GetColor(IN Pen * pen, OUT Color * color)
{
    if (!color)
    {
        return InvalidParameter;
    }

    PenType type = Pen_GetPenType(pen);

    if (type != PenTypeSolidColor)
    {
        return WrongState;
    }

    return (Status)Gdiplus::DllExports::GdipGetPenColor(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::ARGB *)color
    );
}

Status WINAPI
Pen_GetBrush(IN Pen * pen, OUT Brush ** brush)
{
    return (Status)Gdiplus::DllExports::GdipGetPenBrushFill(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpBrush **)brush
    );
}

DashStyle WINAPI
Pen_GetDashStyle(IN Pen * pen)
{
    DashStyle dashStyle;

    Gdiplus::DllExports::GdipGetPenDashStyle(
        (Gdiplus::GpPen *)pen, 
        (Gdiplus::GpDashStyle *)&dashStyle
    );

    return dashStyle;
}

Status WINAPI
Pen_SetDashStyle(IN Pen * pen, IN DashStyle dashStyle)
{
    return (Status)Gdiplus::DllExports::GdipSetPenDashStyle(
        (Gdiplus::GpPen *)pen,
        (Gdiplus::GpDashStyle)dashStyle
    );
}

REAL WINAPI
Pen_GetDashOffset(IN Pen * pen)
{
    REAL dashOffset;

    Gdiplus::DllExports::GdipGetPenDashOffset(
        (Gdiplus::GpPen *)pen,
        &dashOffset
    );

    return dashOffset;
}

Status WINAPI
Pen_SetDashOffset(IN Pen * pen, IN REAL dashOffset)
{
    return (Status)Gdiplus::DllExports::GdipSetPenDashOffset(
        (Gdiplus::GpPen *)pen,
        dashOffset
    );
}

Status WINAPI
Pen_SetDashPattern(IN Pen * pen,
                   IN const REAL * dashArray,
                   IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipSetPenDashArray(
        (Gdiplus::GpPen *)pen,
        dashArray,
        count
    );
}

INT WINAPI
Pen_GetDashPatternCount(IN Pen * pen)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetPenDashCount(
        (Gdiplus::GpPen *)pen, &count
    );

    return count;
}

Status WINAPI
Pen_GetDashPattern(IN Pen * pen,
                   OUT REAL * dashArray,
                   IN INT count)
{
    if (dashArray == NULL || count <= 0)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetPenDashArray(
        (Gdiplus::GpPen *)pen,
        dashArray,
        count
    );
}

Status WINAPI
Pen_SetCompoundArray(IN Pen * pen,
                     IN const REAL * compoundArray,
                     IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipSetPenCompoundArray(
        (Gdiplus::GpPen *)pen,
        compoundArray,
        count
    );
}

INT WINAPI
Pen_GetCompoundArrayCount(IN Pen * pen)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetPenCompoundCount(
        (Gdiplus::GpPen *)pen, &count
    );

    return count;
}

Status WINAPI
Pen_GetCompoundArray(IN Pen * pen,
                     OUT REAL * compoundArray,
                     IN INT count
)
{
    if (compoundArray == NULL || count <= 0)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetPenCompoundArray(
        (Gdiplus::GpPen *)pen,
        compoundArray,
        count
    );
}