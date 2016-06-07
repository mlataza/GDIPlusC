#include "stdafx.h"

Status WINAPI
CustomLineCap_Create(IN GraphicsPath * fillPath,
                     IN GraphicsPath * strokePath,
                     IN LineCap baseCap,
                     IN REAL baseInset,
                     OUT CustomLineCap ** customCap
)
{
    return (Status)Gdiplus::DllExports::GdipCreateCustomLineCap(
        (Gdiplus::GpPath *)fillPath,
        (Gdiplus::GpPath *)strokePath,
        (Gdiplus::GpLineCap)baseCap,
        baseInset,
        (Gdiplus::GpCustomLineCap **)customCap
    );
}

Status WINAPI
CustomLineCap_Delete(IN CustomLineCap * customCap)
{
    return (Status)Gdiplus::DllExports::GdipDeleteCustomLineCap(
        (Gdiplus::GpCustomLineCap *)customCap
    );
}

Status WINAPI
CustomLineCap_SetStrokeCaps(IN CustomLineCap * customCap,
                            IN LineCap startCap,
                            IN LineCap endCap
)
{
    return (Status)Gdiplus::DllExports::GdipSetCustomLineCapStrokeCaps(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineCap)startCap,
        (Gdiplus::GpLineCap)endCap
    );
}

Status WINAPI
CustomLineCap_GetStrokeCaps(IN CustomLineCap * customCap,
                            OUT LineCap * startCap,
                            OUT LineCap * endCap
)
{
    return (Status)Gdiplus::DllExports::GdipGetCustomLineCapStrokeCaps(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineCap *)startCap,
        (Gdiplus::GpLineCap *)endCap
    );
}

Status WINAPI
CustomLineCap_SetStrokeJoin(IN CustomLineCap * customCap,
                            IN LineJoin lineJoin
)
{
    return (Status)Gdiplus::DllExports::GdipSetCustomLineCapStrokeJoin(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineJoin)lineJoin
    );
}

LineJoin WINAPI
CustomLineCap_GetStrokeJoin(IN CustomLineCap * customCap)
{
    LineJoin lineJoin;

    Gdiplus::DllExports::GdipGetCustomLineCapStrokeJoin(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineJoin *)&lineJoin
    );

    return lineJoin;
}

Status WINAPI
CustomLineCap_SetBaseCap(IN CustomLineCap * customCap,
                         IN LineCap baseCap
)
{
    return (Status)Gdiplus::DllExports::GdipSetCustomLineCapBaseCap(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineCap)baseCap
    );
}

LineCap WINAPI
CustomLineCap_GetBaseCap(IN CustomLineCap * customCap)
{
    LineCap baseCap;

    Gdiplus::DllExports::GdipGetCustomLineCapBaseCap(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpLineCap *)&baseCap
    );

    return baseCap;
}

Status WINAPI
CustomLineCap_SetBaseInset(IN CustomLineCap * customCap,
                           IN REAL inset
)
{
    return (Status)Gdiplus::DllExports::GdipSetCustomLineCapBaseInset(
        (Gdiplus::GpCustomLineCap *)customCap,
        inset
    );
}

REAL WINAPI
CustomLineCap_GetBaseInset(IN CustomLineCap * customCap)
{
    REAL inset;

    Gdiplus::DllExports::GdipGetCustomLineCapBaseInset(
        (Gdiplus::GpCustomLineCap *)customCap, &inset
    );

    return inset;
}

Status WINAPI
CustomLineCap_SetWidthScale(IN CustomLineCap * customCap,
                            IN REAL widthScale
)
{
    return (Status)Gdiplus::DllExports::GdipSetCustomLineCapWidthScale(
        (Gdiplus::GpCustomLineCap *)customCap,
        widthScale
    );
}

REAL WINAPI
CustomLineCap_GetWidthScale(IN CustomLineCap * customCap)
{
    REAL widthScale;

    Gdiplus::DllExports::GdipGetCustomLineCapWidthScale(
        (Gdiplus::GpCustomLineCap *)customCap,
        &widthScale
    );

    return widthScale;
}

Status WINAPI
CustomLineCap_Clone(IN CustomLineCap * customCap,
                    OUT CustomLineCap ** cloneCap
)
{
    return (Status)Gdiplus::DllExports::GdipCloneCustomLineCap(
        (Gdiplus::GpCustomLineCap *)customCap,
        (Gdiplus::GpCustomLineCap **)cloneCap
    );
}

Status WINAPI
AdjustableArrowCap_Create(IN REAL height,
                          IN REAL width,
                          IN BOOL isFilled,
                          OUT AdjustableArrowCap ** arrowCap
)
{
    return (Status)Gdiplus::DllExports::GdipCreateAdjustableArrowCap(
        height, width,
        isFilled,
        (Gdiplus::GpAdjustableArrowCap **)arrowCap
    );
}

Status WINAPI
AdjustableArrowCap_SetHeight(IN AdjustableArrowCap * arrowCap,
                             IN REAL height
)
{
    return (Status)Gdiplus::DllExports::GdipSetAdjustableArrowCapHeight(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, height
    );
}

REAL WINAPI
AdjustableArrowCap_GetHeight(IN AdjustableArrowCap * arrowCap)
{
    REAL height;

    Gdiplus::DllExports::GdipGetAdjustableArrowCapHeight(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, &height
    );

    return height;
}

Status WINAPI
AdjustableArrowCap_SetWidth(IN AdjustableArrowCap * arrowCap,
                            IN REAL width
)
{
    return (Status)Gdiplus::DllExports::GdipSetAdjustableArrowCapWidth(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, width
    );
}

REAL WINAPI
AdjustableArrowCap_GetWidth(IN AdjustableArrowCap * arrowCap)
{
    REAL width;

    Gdiplus::DllExports::GdipGetAdjustableArrowCapWidth(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, &width
    );

    return width;
}

Status WINAPI
AdjustableArrowCap_SetMiddleInset(IN AdjustableArrowCap * arrowCap,
                                  IN REAL middleInset
)
{
    return (Status)Gdiplus::DllExports::GdipSetAdjustableArrowCapMiddleInset(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, middleInset
    );
}

REAL WINAPI
AdjustableArrowCap_GetMiddleInset(IN AdjustableArrowCap * arrowCap)
{
    REAL middleInset;

    Gdiplus::DllExports::GdipGetAdjustableArrowCapMiddleInset(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, &middleInset
    );

    return middleInset;
}

Status WINAPI
AdjustableArrowCap_SetFillState(IN AdjustableArrowCap * arrowCap,
                                IN BOOL isFilled
)
{
    return (Status)Gdiplus::DllExports::GdipSetAdjustableArrowCapFillState(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, isFilled
    );
}

BOOL WINAPI
AdjustableArrowCap_IsFilled(IN AdjustableArrowCap * arrowCap)
{
    BOOL isFilled;

    Gdiplus::DllExports::GdipGetAdjustableArrowCapFillState(
        (Gdiplus::GpAdjustableArrowCap *)arrowCap, &isFilled
    );

    return isFilled;
}