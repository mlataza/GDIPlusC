#include "stdafx.h"

Status WINAPI
Brush_Delete(IN Brush * brush)
{
    return (Status)Gdiplus::DllExports::GdipDeleteBrush(
        (Gdiplus::GpBrush *)brush
    );
}

Brush * WINAPI
Brush_Clone(IN Brush * brush)
{
    Brush * clone;

    if (Gdiplus::DllExports::GdipCloneBrush(
        (Gdiplus::GpBrush *)brush,
        (Gdiplus::GpBrush **)&clone) == Gdiplus::Ok)
    {
        return clone;
    }
    else
    {
        return NULL;
    }
}

BrushType WINAPI
Brush_GetType(IN Brush * brush)
{
    BrushType type = (BrushType)(-1);

    Gdiplus::DllExports::GdipGetBrushType(
        (Gdiplus::GpBrush *)brush, 
        (Gdiplus::GpBrushType *)&type
    );

    return type;
}

SolidBrush * WINAPI
SolidBrush_Create(IN Color color)
{
    SolidBrush * solidBrush;

    if (Gdiplus::DllExports::GdipCreateSolidFill(
        Color_GetValue(color),
        (Gdiplus::GpSolidFill **)&solidBrush) == Gdiplus::Ok)
    {
        return solidBrush;
    }
    else
    {
        return NULL;
    }
}

Color WINAPI
SolidBrush_GetColor(IN SolidBrush * solidBrush)
{
    Color color = 0;

    Gdiplus::DllExports::GdipGetSolidFillColor(
        (Gdiplus::GpSolidFill *)solidBrush,
        (Gdiplus::ARGB *)&color
    );

    return color;
}

Status WINAPI
SolidBrush_SetColor(IN SolidBrush * solidBrush, IN Color color)
{
    return (Status)Gdiplus::DllExports::GdipSetSolidFillColor(
        (Gdiplus::GpSolidFill *)solidBrush,
        Color_GetValue(color)
    );
}

TextureBrush * WINAPI
TextureBrush_Create(IN Image * image, IN WrapMode wrapMode)
{
    TextureBrush * textureBrush;

    if (Gdiplus::DllExports::GdipCreateTexture(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpWrapMode)wrapMode,
        (Gdiplus::GpTexture **)&textureBrush) == Gdiplus::Ok)
    {
        return textureBrush;
    }
    else
    {
        return NULL;
    }
}

TextureBrush * WINAPI
TextureBrush_CreateIA(IN Image * image,
                      IN const RectF * dstRect,
                      IN const ImageAttributes * imageAttributes
)
{
    TextureBrush * textureBrush;

    if (Gdiplus::DllExports::GdipCreateTextureIA(
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes,
        dstRect->X,
        dstRect->Y,
        dstRect->Width,
        dstRect->Height,
        (Gdiplus::GpTexture **)&textureBrush) == Gdiplus::Ok)
    {
        return textureBrush;
    }
    else
    {
        return NULL;
    }
}

TextureBrush * WINAPI
TextureBrush_CreateIAI(IN Image * image,
                       IN const Rect * dstRect,
                       IN const ImageAttributes * imageAttributes
)
{
    TextureBrush * textureBrush;

    if (Gdiplus::DllExports::GdipCreateTextureIAI(
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttributes,
        dstRect->X,
        dstRect->Y,
        dstRect->Width,
        dstRect->Height,
        (Gdiplus::GpTexture **)&textureBrush) == Gdiplus::Ok)
    {
        return textureBrush;
    }
    else
    {
        return NULL;
    }
}

TextureBrush * WINAPI
TextureBrush_Create2(IN Image * image,
                     IN WrapMode wrapMode,
                     IN REAL dstX,
                     IN REAL dstY,
                     IN REAL dstWidth,
                     IN REAL dstHeight
)
{
    TextureBrush * textureBrush;

    if (Gdiplus::DllExports::GdipCreateTexture2(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpWrapMode)wrapMode,
        dstX,
        dstY,
        dstWidth,
        dstHeight,
        (Gdiplus::GpTexture **)&textureBrush) == Gdiplus::Ok)
    {
        return textureBrush;
    }
    else
    {
        return NULL;
    }
}

TextureBrush * WINAPI
TextureBrush_Create2I(IN Image * image,
                      IN WrapMode wrapMode,
                      IN INT dstX,
                      IN INT dstY,
                      IN INT dstWidth,
                      IN INT dstHeight
)
{
    TextureBrush * textureBrush;

    if (Gdiplus::DllExports::GdipCreateTexture2I(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpWrapMode)wrapMode,
        dstX,
        dstY,
        dstWidth,
        dstHeight,
        (Gdiplus::GpTexture **)&textureBrush) == Gdiplus::Ok)
    {
        return textureBrush;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
TextureBrush_SetTransform(IN TextureBrush * textureBrush,
                          IN const Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipSetTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        (GDIPCONST Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
TextureBrush_GetTransform(IN TextureBrush * textureBrush,
    OUT Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipGetTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
TextureBrush_ResetTransform(IN TextureBrush * textureBrush)
{
    return (Status)Gdiplus::DllExports::GdipResetTextureTransform(
        (Gdiplus::GpTexture *)textureBrush
    );
}

Status WINAPI
TextureBrush_MultiplyTransform(IN TextureBrush * textureBrush,
                               IN const Matrix * matrix,
                               IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        (GDIPCONST Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
TextureBrush_TranslateTransform(IN TextureBrush * textureBrush,
                                IN REAL dx,
                                IN REAL dy,
                                IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        dx, dy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
TextureBrush_ScaleTransform(IN TextureBrush * textureBrush,
                            IN REAL sx,
                            IN REAL sy,
                            IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScaleTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        sx, sy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
TextureBrush_RotateTransform(IN TextureBrush * textureBrush,
                             IN REAL angle,
                             IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotateTextureTransform(
        (Gdiplus::GpTexture *)textureBrush,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
TextureBrush_SetWrapMode(IN TextureBrush * textureBrush, IN WrapMode wrapMode)
{
    return (Status)Gdiplus::DllExports::GdipSetTextureWrapMode(
        (Gdiplus::GpTexture *)textureBrush,
        (Gdiplus::GpWrapMode)wrapMode
    );
}

WrapMode WINAPI
TextureBrush_GetWrapMode(IN TextureBrush * textureBrush)
{
    WrapMode wrapMode;

    Gdiplus::DllExports::GdipGetTextureWrapMode(
        (Gdiplus::GpTexture *)textureBrush,
        (Gdiplus::GpWrapMode *)&wrapMode
    );
    
    return wrapMode;
}

Image * WINAPI
TextureBrush_GetImage(IN TextureBrush * textureBrush)
{
    Image * image = NULL;

    Gdiplus::DllExports::GdipGetTextureImage(
        (Gdiplus::GpTexture *)textureBrush,
        (Gdiplus::GpImage **)&image
    );

    return image;
}

LinearGradientBrush * WINAPI
LinearGradientBrush_Create(IN const PointF * point1,
                           IN const PointF * point2,
                           IN Color color1,
                           IN Color color2
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrush(
        (GDIPCONST Gdiplus::GpPointF *)point1,
        (GDIPCONST Gdiplus::GpPointF *)point2,
        Color_GetValue(color1),
        Color_GetValue(color2),
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

LinearGradientBrush * WINAPI
LinearGradientBrush_CreateI(IN const Point * point1,
                            IN const Point * point2,
                            IN Color color1,
                            IN Color color2
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrushI(
        (GDIPCONST Gdiplus::GpPoint *)point1,
        (GDIPCONST Gdiplus::GpPoint *)point2,
        Color_GetValue(color1),
        Color_GetValue(color2),
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

LinearGradientBrush * WINAPI
LinearGradientBrush_CreateFromRect(IN const RectF * rect,
                                   IN Color color1,
                                   IN Color color2,
                                   IN LinearGradientMode mode
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrushFromRect(
        (GDIPCONST Gdiplus::GpRectF *)rect,
        Color_GetValue(color1),
        Color_GetValue(color2),
        (Gdiplus::LinearGradientMode)mode,
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

LinearGradientBrush * WINAPI
LinearGradientBrush_CreateFromRectI(IN const Rect * rect,
                                    IN Color color1,
                                    IN Color color2,
                                    IN LinearGradientMode mode
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrushFromRectI(
        (GDIPCONST Gdiplus::GpRect *)rect,
        Color_GetValue(color1),
        Color_GetValue(color2),
        (Gdiplus::LinearGradientMode)mode,
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

LinearGradientBrush * WINAPI
LinearGradientBrush_CreateFromRectWithAngle(IN const RectF * rect,
                                            IN Color color1,
                                            IN Color color2,
                                            IN REAL angle,
                                            IN BOOL isAngleScalable
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrushFromRectWithAngle(
        (GDIPCONST Gdiplus::GpRectF *)rect,
        Color_GetValue(color1),
        Color_GetValue(color2),
        angle,
        isAngleScalable,
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

LinearGradientBrush * WINAPI
LinearGradientBrush_CreateFromRectWithAngleI(IN const Rect * rect,
                                             IN Color color1,
                                             IN Color color2,
                                             IN REAL angle,
                                             IN BOOL isAngleScalable
)
{
    LinearGradientBrush * lgBrush;

    if (Gdiplus::DllExports::GdipCreateLineBrushFromRectWithAngleI(
        (GDIPCONST Gdiplus::GpRect *)rect,
        Color_GetValue(color1),
        Color_GetValue(color2),
        angle,
        isAngleScalable,
        (Gdiplus::GpWrapMode)WrapModeTile,
        (Gdiplus::GpLineGradient **)&lgBrush) == Gdiplus::Ok)
    {
        return lgBrush;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
LinearGradientBrush_SetLinearColors(IN LinearGradientBrush * lgBrush,
                                    IN Color color1,
                                    IN Color color2
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineColors(
        (Gdiplus::GpLineGradient *)lgBrush,
        Color_GetValue(color1),
        Color_GetValue(color2)
    );
}

Status WINAPI
LinearGradientBrush_GetLinearColors(IN LinearGradientBrush * lgBrush,
                                    OUT Color * colors
)
{
    if (colors == NULL)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipGetLineColors(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::ARGB *)colors
    );
}

Status WINAPI
LinearGradientBrush_GetRectangle(IN LinearGradientBrush * lgBrush,
                                 OUT RectF * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetLineRect(
        (Gdiplus::GpLineGradient *)lgBrush, 
        (Gdiplus::GpRectF *)rect
    );
}

Status WINAPI
LinearGradientBrush_GetRectangleI(IN LinearGradientBrush * lgBrush,
                                  OUT Rect * rect
)
{
    return (Status)Gdiplus::DllExports::GdipGetLineRectI(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::GpRect *)rect
    );
}

Status WINAPI
LinearGradientBrush_SetGammaCorrection(IN LinearGradientBrush * lgBrush,
                                       IN BOOL useGammaCorrection
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineGammaCorrection(
        (Gdiplus::GpLineGradient *)lgBrush,
        useGammaCorrection
    );
}

BOOL WINAPI
LinearGradientBrush_GetGammaCorrection(IN LinearGradientBrush * lgBrush)
{
    BOOL useGammaCorrection;

    Gdiplus::DllExports::GdipGetLineGammaCorrection(
        (Gdiplus::GpLineGradient *)lgBrush,
         &useGammaCorrection
    );

    return useGammaCorrection;
}

INT WINAPI
LinearGradientBrush_GetBlendCount(IN LinearGradientBrush * lgBrush)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetLineBlendCount(
        (Gdiplus::GpLineGradient *)lgBrush,
        &count
    );

    return count;
}

Status WINAPI
LinearGradientBrush_SetBlend(IN LinearGradientBrush * lgBrush,
                             IN const REAL * blendFactors,
                             IN const REAL * blendPositions,
                             IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineBlend(
        (Gdiplus::GpLineGradient *)lgBrush,
        blendFactors,
        blendPositions,
        count
    );
}

Status WINAPI
LinearGradientBrush_GetBlend(IN LinearGradientBrush * lgBrush,
                             OUT REAL * blendFactors,
                             OUT REAL * blendPositions,
                             IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipGetLineBlend(
        (Gdiplus::GpLineGradient *)lgBrush,
        blendFactors,
        blendPositions,
        count
    );
}

INT WINAPI
LinearGradientBrush_GetInterpolationColorCount(IN LinearGradientBrush * lgBrush)
{
    INT count = 0;

    Gdiplus::DllExports::GdipGetLinePresetBlendCount(
        (Gdiplus::GpLineGradient *)lgBrush,
        &count
    );

    return count;
}

Status WINAPI
LinearGradientBrush_SetInterpolationColors(IN LinearGradientBrush * lgBrush,
                                           IN const Color * presetColors,
                                           IN const REAL * blendPositions,
                                           IN INT count
)
{
    if ((count <= 0) || !presetColors)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipSetLinePresetBlend(
        (Gdiplus::GpLineGradient *)lgBrush,
        (GDIPCONST Gdiplus::ARGB *)presetColors,
        blendPositions,
        count
    );
}

Status WINAPI
LinearGradientBrush_GetInterpolationColors(IN LinearGradientBrush * lgBrush,
                                           OUT Color * presetColors,
                                           OUT REAL * blendPositions,
                                           IN INT count
)
{
    if ((count <= 0) || !presetColors)
        return InvalidParameter;

    return (Status)Gdiplus::DllExports::GdipGetLinePresetBlend(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::ARGB *)presetColors,
        blendPositions,
        count
    );
}

Status WINAPI
LinearGradientBrush_SetBlendBellShape(IN LinearGradientBrush * lgBrush,
                                      IN REAL focus,
                                      IN REAL scale
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineSigmaBlend(
        (Gdiplus::GpLineGradient *)lgBrush, focus, scale
    );
}

Status WINAPI
LinearGradientBrush_SetBlendTriangularShape(IN LinearGradientBrush * lgBrush,
                                            IN REAL focus,
                                            IN REAL scale
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineLinearBlend(
        (Gdiplus::GpLineGradient *)lgBrush, focus, scale
    );
}

Status WINAPI
LinearGradientBrush_SetTransform(IN LinearGradientBrush * lgBrush,
                                 IN const Matrix * matrix
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        (GDIPCONST Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
LinearGradientBrush_GetTransform(IN LinearGradientBrush * lgBrush,
                                 OUT Matrix *matrix
)
{
    return (Status)Gdiplus::DllExports::GdipGetLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
LinearGradientBrush_ResetTransform(IN LinearGradientBrush * lgBrush)
{
    return (Status)Gdiplus::DllExports::GdipResetLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush
    );
}

Status WINAPI
LinearGradientBrush_MultiplyTransform(IN LinearGradientBrush * lgBrush,
                                      IN const Matrix * matrix,
                                      IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
LinearGradientBrush_TranslateTransform(IN LinearGradientBrush * lgBrush,
                                       IN REAL dx,
                                       IN REAL dy,
                                       IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        dx, dy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
LinearGradientBrush_ScaleTransform(IN LinearGradientBrush * lgBrush,
                                   IN REAL sx,
                                   IN REAL sy,
                                   IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScaleLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        sx, sy,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
LinearGradientBrush_RotateTransform(IN LinearGradientBrush * lgBrush,
                                    IN REAL angle,
                                    IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotateLineTransform(
        (Gdiplus::GpLineGradient *)lgBrush,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
LinearGradientBrush_SetWrapMode(IN LinearGradientBrush * lgBrush,
                                IN WrapMode wrapMode
)
{
    return (Status)Gdiplus::DllExports::GdipSetLineWrapMode(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::GpWrapMode) wrapMode
    );
}

WrapMode WINAPI
LinearGradientBrush_GetWrapMode(IN LinearGradientBrush * lgBrush)
{
    WrapMode wrapMode;

    Gdiplus::DllExports::GdipGetLineWrapMode(
        (Gdiplus::GpLineGradient *)lgBrush,
        (Gdiplus::GpWrapMode *)&wrapMode
    );

    return wrapMode;
}

HatchBrush * WINAPI
HatchBrush_Create(IN HatchStyle hatchStyle,
                  IN Color foreColor,
                  IN Color backColor
)
{
    HatchBrush * hatchBrush;

    if (Gdiplus::DllExports::GdipCreateHatchBrush(
        (Gdiplus::GpHatchStyle)hatchStyle,
        Color_GetValue(foreColor),
        Color_GetValue(backColor),
        (Gdiplus::GpHatch **)&hatchBrush) == Gdiplus::Ok)
    {
        return hatchBrush;
    }
    else
    {
        return NULL;
    }
}

HatchStyle WINAPI
HatchBrush_GetHatchStyle(IN HatchBrush * hatchBrush)
{
    HatchStyle hatchStyle;

    Gdiplus::DllExports::GdipGetHatchStyle(
        (Gdiplus::GpHatch *)hatchBrush,
        (Gdiplus::GpHatchStyle *)&hatchStyle
    );

    return hatchStyle;
}

Color WINAPI
HatchBrush_GetForegroundColor(IN HatchBrush * hatchBrush)
{
    Color color = 0;

    Gdiplus::DllExports::GdipGetHatchForegroundColor(
        (Gdiplus::GpHatch *)hatchBrush,
        (Gdiplus::ARGB *)&color
    );

    return color;
}

Color WINAPI
HatchBrush_GetBackgroundColor(IN HatchBrush * hatchBrush)
{
    Color color = 0;

    Gdiplus::DllExports::GdipGetHatchBackgroundColor(
        (Gdiplus::GpHatch *)hatchBrush,
        (Gdiplus::ARGB *)&color
    );

    return color;
}