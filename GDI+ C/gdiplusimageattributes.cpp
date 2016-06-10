#include "stdafx.h"

ImageAttributes * WINAPI
ImageAttributes_Create()
{
    ImageAttributes * imgAttr;

    if (Gdiplus::DllExports::GdipCreateImageAttributes(
        (Gdiplus::GpImageAttributes **)&imgAttr) == Gdiplus::Ok)
    {
        return imgAttr;
    }
    else
    {
        return NULL;
    }
}

ImageAttributes * WINAPI
ImageAttributes_Clone(IN const ImageAttributes * imageAttr)
{
    ImageAttributes * clone;

    if (Gdiplus::DllExports::GdipCloneImageAttributes(
        (GDIPCONST Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::GpImageAttributes **)&clone) == Gdiplus::Ok)
    {
        return clone;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
ImageAttributes_Dispose(IN ImageAttributes * imageAttr)
{
    return (Status)Gdiplus::DllExports::GdipDisposeImageAttributes(
        (Gdiplus::GpImageAttributes *)imageAttr
    );
}

Status WINAPI
ImageAttributes_SetToIdentity(IN ImageAttributes * imageAttr,
                              IN ColorAdjustType type)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesToIdentity(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type
    );
}

Status WINAPI
ImageAttributes_Reset(IN ImageAttributes * imageAttr,
                      IN ColorAdjustType type)
{
    return (Status)Gdiplus::DllExports::GdipResetImageAttributes(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type
    );
}

Status WINAPI
ImageAttributes_SetColorMatrix(IN ImageAttributes * imageAttr,
                               IN const ColorMatrix * colorMatrix,
                               IN ColorMatrixFlags mode,
                               IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorMatrix(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        (Gdiplus::ColorMatrix *)colorMatrix,
        NULL,
        (Gdiplus::ColorMatrixFlags)mode
    );
}

Status WINAPI
ImageAttributes_ClearColorMatrix(IN ImageAttributes * imageAttr,
                                 IN ColorAdjustType type 
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorMatrix(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        NULL,
        NULL,
        (Gdiplus::ColorMatrixFlags)ColorMatrixFlagsDefault
    );
}

Status WINAPI
ImageAttributes_SetColorMatrices(IN ImageAttributes * imageAttr,
                                 IN const ColorMatrix * colorMatrix,
                                 IN const ColorMatrix * grayMatrix,
                                 IN ColorMatrixFlags mode,
                                 IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorMatrix(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        (GDIPCONST Gdiplus::ColorMatrix *)colorMatrix,
        (GDIPCONST Gdiplus::ColorMatrix *)grayMatrix,
        (Gdiplus::ColorMatrixFlags)mode
    );
}

Status WINAPI
ImageAttributes_ClearColorMatrices(IN ImageAttributes * imageAttr,
                                   IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorMatrix(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        NULL,
        NULL,
        (Gdiplus::ColorMatrixFlags)ColorMatrixFlagsDefault
    );
}

Status WINAPI
ImageAttributes_SetThreshold(IN ImageAttributes * imageAttr,
                             IN REAL threshold,
                             IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesThreshold(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        threshold
    );
}

Status WINAPI
ImageAttributes_ClearThreshold(IN ImageAttributes * imageAttr,
                               IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesThreshold(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        0.0
    );
}

Status WINAPI
ImageAttributes_SetGamma(IN ImageAttributes * imageAttr,
                         IN REAL gamma,
                         IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesGamma(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        gamma
    );
}

Status WINAPI
ImageAttributes_ClearGamma(IN ImageAttributes * imageAttr,
                           IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesGamma(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        0.0
    );
}

Status WINAPI
ImageAttributes_SetNoOp(IN ImageAttributes * imageAttr,
                        IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesNoOp(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE
    );
}

Status WINAPI
ImageAttributes_ClearNoOp(IN ImageAttributes * imageAttr,
                          IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesNoOp(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE
    );
}

Status WINAPI
ImageAttributes_SetColorKey(IN ImageAttributes * imageAttr,
                            IN Color colorLow,
                            IN Color colorHigh,
                            IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorKeys(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        Color_GetValue(colorLow),
        Color_GetValue(colorHigh)
    );
}

Status WINAPI
ImageAttributes_ClearColorKey(IN ImageAttributes * imageAttr,
                              IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesColorKeys(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        NULL,
        NULL
    );
}

Status WINAPI
ImageAttributes_SetOutputChannel(IN ImageAttributes * imageAttr,
                                 IN ColorChannelFlags channelFlags,
                                 IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesOutputChannel(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        (Gdiplus::ColorChannelFlags)channelFlags
    );
}

Status WINAPI
ImageAttributes_ClearOutputChannel(IN ImageAttributes * imageAttr,
                                   IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesOutputChannel(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        (Gdiplus::ColorChannelFlags)ColorChannelFlagsLast
    );
}

Status WINAPI
ImageAttributes_SetOutputChannelColorProfile(IN ImageAttributes * imageAttr,
    IN const WCHAR * colorProfileFilename,
    IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesOutputChannelColorProfile(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        colorProfileFilename
    );
}

Status WINAPI
ImageAttributes_ClearOutputChannelColorProfile(IN ImageAttributes * imageAttr,
                                               IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesOutputChannelColorProfile(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        NULL
    );
}

Status WINAPI
ImageAttributes_SetRemapTable(IN ImageAttributes * imageAttr,
                              IN UINT mapSize,
                              IN const ColorMap * map,
                              IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesRemapTable(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        TRUE,
        mapSize,
        (const Gdiplus::ColorMap *)map
    );
}

Status WINAPI
ImageAttributes_ClearRemapTable(IN ImageAttributes * imageAttr,
                                IN ColorAdjustType type
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesRemapTable(
        (Gdiplus::GpImageAttributes *)imageAttr,
        (Gdiplus::ColorAdjustType)type,
        FALSE,
        0,
        NULL
    );
}

Status WINAPI
ImageAttributes_SetBrushRemapTable(
    IN ImageAttributes * imageAttr,
    IN UINT mapSize,
    IN const ColorMap * map)
{
    return ImageAttributes_SetRemapTable(
        imageAttr, mapSize, map, ColorAdjustTypeBrush);
}

Status WINAPI
ImageAttributes_ClearBrushRemapTable(
    IN ImageAttributes * imageAttr
)
{
    return ImageAttributes_ClearRemapTable(imageAttr, ColorAdjustTypeBrush);
}

Status WINAPI
ImageAttributes_SetWrapMode(IN ImageAttributes * imageAttr,
                            IN WrapMode wrap,
                            IN Color color,
                            IN BOOL clamp
)
{
    return (Status)Gdiplus::DllExports::GdipSetImageAttributesWrapMode(
        (Gdiplus::GpImageAttributes *)imageAttr, 
        (Gdiplus::WrapMode)wrap, 
        Color_GetValue(color), clamp
    );
}

Status WINAPI
ImageAttributes_GetAdjustedPalette(IN ImageAttributes * imageAttr,
                                   IN OUT ColorPalette * colorPalette,
                                   IN ColorAdjustType colorAdjustType
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageAttributesAdjustedPalette(
        (Gdiplus::GpImageAttributes *)imageAttr, 
        (Gdiplus::ColorPalette *)colorPalette, 
        (Gdiplus::ColorAdjustType)colorAdjustType
    );
}