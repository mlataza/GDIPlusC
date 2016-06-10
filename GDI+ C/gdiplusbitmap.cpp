#include "stdafx.h"

Image * WINAPI
Image_LoadFromFile(IN const WCHAR * filename, IN BOOL useEmbeddedColorManagement)
{
    Image * image;

    if (useEmbeddedColorManagement)
    {
        if (Gdiplus::DllExports::GdipLoadImageFromFileICM(
            filename,
            (Gdiplus::GpImage **)&image) == Gdiplus::Ok)
        {
            return image;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipLoadImageFromFile(
            filename,
            (Gdiplus::GpImage **)&image) == Gdiplus::Ok)
        {
            return image;
        }
        else
        {
            return NULL;
        }
    }
}

Image * WINAPI
Image_LoadFromStream(IN IStream * stream,
                     IN BOOL useEmbeddedColorManagement
)
{
    Image * image;

    if (useEmbeddedColorManagement)
    {
        if (Gdiplus::DllExports::GdipLoadImageFromStreamICM(
            stream,
            (Gdiplus::GpImage **)&image) == Gdiplus::Ok)
        {
            return image;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipLoadImageFromStream(
            stream,
            (Gdiplus::GpImage **)&image) == Gdiplus::Ok)
        {
            return image;
        }
        else
        {
            return NULL;
        }
    }
}

Status WINAPI
Image_Dispose(IN Image * image)
{
    return (Status)Gdiplus::DllExports::GdipDisposeImage(
        (Gdiplus::GpImage *)image
    );
}

Image * WINAPI
Image_Clone(IN Image * image)
{
    Image * clone;

    if (Gdiplus::DllExports::GdipCloneImage(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpImage **)&clone) == Gdiplus::Ok)
    {
        return clone;
    }
    else
    {
        return NULL;
    }
}

UINT WINAPI
Image_GetEncoderParameterListSize(IN Image * image,
                                  IN const CLSID * clsidEncoder
)
{
    UINT size = 0;

    Gdiplus::DllExports::GdipGetEncoderParameterListSize(
        (Gdiplus::GpImage *)image,
        clsidEncoder,
        &size
    );

    return size;
}

Status WINAPI
Image_GetEncoderParameterList(IN Image * image,
                              IN const CLSID * clsidEncoder,
                              IN UINT size,
                              OUT EncoderParameters * buffer
)
{
    return (Status)Gdiplus::DllExports::GdipGetEncoderParameterList(
        (Gdiplus::GpImage *)image,
        clsidEncoder,
        size,
        (Gdiplus::EncoderParameters *)buffer
    );
}

Status WINAPI
Image_SaveToFile(IN Image * image,
                 IN const WCHAR * filename,
                 IN const CLSID * clsidEncoder,
                 IN const EncoderParameters * encoderParams
)
{
    return (Status)Gdiplus::DllExports::GdipSaveImageToFile(
        (Gdiplus::GpImage *)image,
        filename,
        clsidEncoder,
        (GDIPCONST Gdiplus::EncoderParameters *)encoderParams
    );
}

Status WINAPI
Image_SaveToStream(IN Image * image,
                   IN IStream * stream,
                   IN const CLSID * clsidEncoder,
                   IN const EncoderParameters * encoderParams
)
{
    return (Status)Gdiplus::DllExports::GdipSaveImageToStream(
        (Gdiplus::GpImage *)image,
        stream,
        clsidEncoder,
        (GDIPCONST Gdiplus::EncoderParameters *)encoderParams
    );
}

Status WINAPI
Image_SaveAdd(IN Image * image,
              IN const EncoderParameters * encoderParams
)
{
    return (Status)Gdiplus::DllExports::GdipSaveAdd(
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::EncoderParameters *)encoderParams
    );
}

Status WINAPI
Image_SaveAddImage(IN Image * image,
                   IN Image * newImage,
                   IN const EncoderParameters * encoderParams
)
{
    return (Status)Gdiplus::DllExports::GdipSaveAddImage(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpImage *)newImage,
        (GDIPCONST Gdiplus::EncoderParameters *)encoderParams
    );
}

ImageType WINAPI
Image_GetType(IN Image * image)
{
    ImageType type = ImageTypeUnknown;

    Gdiplus::DllExports::GdipGetImageType(
        (Gdiplus::GpImage *)image,
        (Gdiplus::ImageType *)&type
    );

    return type;
}

Status WINAPI
Image_GetPhysicalDimension(IN Image * image,
                           OUT SizeF * size
)
{
    REAL width, height;
    Status status;

    status = (Status)Gdiplus::DllExports::GdipGetImageDimension(
        (Gdiplus::GpImage *)image,
        &width, &height
    );

    size->Width = width;
    size->Height = height;

    return status;
}

Status WINAPI
Image_GetBounds(IN Image * image,
                OUT RectF * srcRect,
                OUT Unit * srcUnit
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageBounds(
        (Gdiplus::GpImage *)image,
        (Gdiplus::GpRectF *)srcRect,
        (Gdiplus::GpUnit *)srcUnit
    );
}

UINT WINAPI
Image_GetWidth(IN Image * image)
{
    UINT width = 0;

    Gdiplus::DllExports::GdipGetImageWidth(
        (Gdiplus::GpImage *)image, &width
    );

    return width;
}

UINT WINAPI
Image_GetHeight(IN Image * image)
{
    UINT height = 0;

    Gdiplus::DllExports::GdipGetImageHeight(
        (Gdiplus::GpImage *)image, &height
    );

    return height;
}

REAL WINAPI
Image_GetHorizontalResolution(IN Image * image)
{
    REAL resolution = 0.0f;

    Gdiplus::DllExports::GdipGetImageHorizontalResolution(
        (Gdiplus::GpImage *)image, &resolution
    );

    return resolution;
}

REAL WINAPI
Image_GetVerticalResolution(IN Image * image)
{
    REAL resolution = 0.0f;

    Gdiplus::DllExports::GdipGetImageVerticalResolution(
        (Gdiplus::GpImage *)image, &resolution
    );

    return resolution;
}

UINT WINAPI
Image_GetFlags(IN Image * image)
{
    UINT flags = 0;

    Gdiplus::DllExports::GdipGetImageFlags(
        (Gdiplus::GpImage *)image, &flags
    );

    return flags;
}

Status WINAPI
Image_GetRawFormat(IN Image * image,
                   OUT GUID * format
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageRawFormat(
        (Gdiplus::GpImage *)image, format
    );
}

PixelFormat WINAPI
Image_GetPixelFormat(IN Image * image)
{
    PixelFormat format;

    Gdiplus::DllExports::GdipGetImagePixelFormat(
        (Gdiplus::GpImage *)image, &format
    );

    return format;
}

INT WINAPI
Image_GetPaletteSize(IN Image * image)
{
    INT size = 0;

    Gdiplus::DllExports::GdipGetImagePaletteSize(
        (Gdiplus::GpImage *)image, &size
    );

    return size;
}

Status WINAPI
Image_GetPalette(IN Image * image,
                 OUT ColorPalette * palette,
                 IN INT size
)
{
    return (Status)Gdiplus::DllExports::GdipGetImagePalette(
        (Gdiplus::GpImage *)image,
        (Gdiplus::ColorPalette *)palette,
        size
    );
}

Status WINAPI
Image_SetPalette(IN Image * image,
                 IN const ColorPalette * palette
)
{
    return (Status)Gdiplus::DllExports::GdipSetImagePalette(
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::ColorPalette *)palette
    );
}

Image * WINAPI
Image_GetThumbnailImage(IN Image * image,
                        IN UINT thumbWidth,
                        IN UINT thumbHeight,
                        IN GetThumbnailImageAbort callback,
                        IN VOID * callbackData
)
{
    Image * thumbnailImage;

    if (Gdiplus::DllExports::GdipGetImageThumbnail(
        (Gdiplus::GpImage *)image,
        thumbWidth, thumbHeight,
        (Gdiplus::GpImage **)&thumbnailImage,
        callback, callbackData) == Gdiplus::Ok)
    {
        return thumbnailImage;
    }
    else
    {
        return NULL;
    }
}

UINT WINAPI
Image_GetFrameDimensionsCount(IN Image * image)
{
    UINT count = 0;

    Gdiplus::DllExports::GdipImageGetFrameDimensionsCount(
        (Gdiplus::GpImage *)image,
        &count
    );

    return count;
}

Status WINAPI
Image_GetFrameDimensionsList(IN Image * image,
                             OUT GUID * dimensionIDs,
                             IN UINT count
)
{
    return (Status)Gdiplus::DllExports::GdipImageGetFrameDimensionsList(
        (Gdiplus::GpImage *)image,
        dimensionIDs,
        count
    );
}

UINT WINAPI
Image_GetFrameCount(IN Image * image,
                    IN const GUID * dimensionID
)
{
    UINT count = 0;

    Gdiplus::DllExports::GdipImageGetFrameCount(
        (Gdiplus::GpImage *)image,
        dimensionID,
        &count
    );
    return count;
}

Status WINAPI
Image_SelectActiveFrame(IN Image * image,
                        IN const GUID * dimensionID,
                        IN UINT frameIndex
)
{
    return (Status)Gdiplus::DllExports::GdipImageSelectActiveFrame(
        (Gdiplus::GpImage *)image,
        dimensionID,
        frameIndex
    );
}

Status WINAPI
Image_RotateFlip(IN Image * image,
                 IN RotateFlipType rotateFlipType
)
{
    return (Status)Gdiplus::DllExports::GdipImageRotateFlip(
        (Gdiplus::GpImage *)image,
        (Gdiplus::RotateFlipType)rotateFlipType
    );
}

UINT WINAPI
Image_GetPropertyCount(IN Image * image)
{
    UINT numProperty = 0;

    Gdiplus::DllExports::GdipGetPropertyCount(
        (Gdiplus::GpImage *)image,
        &numProperty
    );

    return numProperty;
}

Status WINAPI
Image_GetPropertyIdList(IN Image * image,
                        IN UINT numOfProperty,
                        OUT PROPID * list
)
{
    return (Status)Gdiplus::DllExports::GdipGetPropertyIdList(
        (Gdiplus::GpImage *)image,
        numOfProperty, list
    );
}

UINT WINAPI
Image_GetPropertyItemSize(IN Image * image,
                          IN PROPID propId
)
{
    UINT size = 0;

    Gdiplus::DllExports::GdipGetPropertyItemSize(
        (Gdiplus::GpImage *)image,
        propId,
        &size
    );

    return size;
}

Status WINAPI
Image_GetPropertyItem(IN Image * image,
                      IN PROPID propId,
                      IN UINT propSize,
                      OUT PropertyItem * buffer
)
{
    return (Status)Gdiplus::DllExports::GdipGetPropertyItem(
        (Gdiplus::GpImage *)image,
        propId, propSize,
        (Gdiplus::PropertyItem *)buffer
    );
}

Status WINAPI
Image_GetPropertySize(IN Image * image,
                      OUT UINT * totalBufferSize,
                      OUT UINT * numProperties
)
{
    return (Status)Gdiplus::DllExports::GdipGetPropertySize(
        (Gdiplus::GpImage *)image,
        totalBufferSize,
        numProperties
    );
}

Status WINAPI
Image_GetAllPropertyItems(IN Image * image,
                          IN UINT totalBufferSize,
                          IN UINT numProperties,
                          OUT PropertyItem * allItems
)
{
    if (!allItems)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipGetAllPropertyItems(
        (Gdiplus::GpImage *)image,
        totalBufferSize,
        numProperties,
        (Gdiplus::PropertyItem *)allItems
    );
}

Status WINAPI
Image_RemovePropertyItem(IN Image * image,
                         IN PROPID propId
)
{
    return (Status)Gdiplus::DllExports::GdipRemovePropertyItem(
        (Gdiplus::GpImage *)image, propId
    );
}

Status WINAPI
Image_SetPropertyItem(IN Image * image,
                      IN const PropertyItem * item
)
{
    return (Status)Gdiplus::DllExports::GdipSetPropertyItem(
        (Gdiplus::GpImage *)image,
        (GDIPCONST Gdiplus::PropertyItem *)item
    );
}

Bitmap * WINAPI
Bitmap_CreateFromFile(IN const WCHAR * filename,
                      IN BOOL useEmbeddedColorManagement
)
{
    Bitmap * bitmap;

    if (useEmbeddedColorManagement)
    {
        if (Gdiplus::DllExports::GdipCreateBitmapFromFileICM(
            filename,
            (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
        {
            return bitmap;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipCreateBitmapFromFile(
            filename,
            (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
        {
            return bitmap;
        }
        else
        {
            return NULL;
        }
    }
}

Bitmap * WINAPI
Bitmap_CreateFromStream(IN IStream * stream,
                        IN BOOL useEmbeddedColorManagement
)
{
    Bitmap * bitmap;

    if (useEmbeddedColorManagement)
    {
        if (Gdiplus::DllExports::GdipCreateBitmapFromStreamICM(
            stream,
            (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
        {
            return bitmap;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipCreateBitmapFromStream(
            stream,
            (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
        {
            return bitmap;
        }
        else
        {
            return NULL;
        }
    }
}

Bitmap * WINAPI
Bitmap_CreateFromScan0(IN INT width,
                       IN INT height,
                       IN INT stride,
                       IN PixelFormat format,
                       IN BYTE * scan0
)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromScan0(
        width,
        height,
        stride,
        format,
        scan0,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CreateFromGraphics(IN INT width,
                          IN INT height,
                          IN Graphics * target
)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromGraphics(
        width,
        height,
        (Gdiplus::GpGraphics *)target,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CreateFromGdiDib(IN const BITMAPINFO * gdiBitmapInfo,
                        IN VOID * gdiBitmapData
)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromGdiDib(
        gdiBitmapInfo,
        gdiBitmapData,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CreateFromHBITMAP(IN HBITMAP hbm,
                         IN HPALETTE hpal
)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromHBITMAP(
        hbm, hpal,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CreateFromHICON(IN HICON hicon)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromHICON(
        hicon,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CreateFromResource(IN HINSTANCE hInstance,
                          IN const WCHAR * bitmapName
)
{
    Bitmap * bitmap;

    if (Gdiplus::DllExports::GdipCreateBitmapFromResource(
        hInstance,
        bitmapName,
        (Gdiplus::GpBitmap **)&bitmap) == Gdiplus::Ok)
    {
        return bitmap;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
Bitmap_GetHBITMAP(IN Bitmap * bitmap,
                  IN Color colorBackground,
                  OUT HBITMAP * hbmReturn
)
{
    return (Status)Gdiplus::DllExports::GdipCreateHBITMAPFromBitmap(
        (Gdiplus::GpBitmap *)bitmap,
        hbmReturn,
        Color_GetValue(colorBackground)
    );
}

Status WINAPI
Bitmap_GetHICON(IN Bitmap * bitmap,
                OUT HICON * hiconReturn
)
{
    return (Status)Gdiplus::DllExports::GdipCreateHICONFromBitmap(
        (Gdiplus::GpBitmap *)bitmap,
        hiconReturn
    );
}

Bitmap * WINAPI
Bitmap_CloneArea(IN Bitmap * bitmap,
                 IN REAL x,
                 IN REAL y,
                 IN REAL width,
                 IN REAL height,
                 IN PixelFormat format
)
{
    Bitmap * clone;

    if (Gdiplus::DllExports::GdipCloneBitmapArea(
        x,
        y,
        width,
        height,
        format,
        (Gdiplus::GpBitmap *)bitmap,
        (Gdiplus::GpBitmap **)&clone) == Gdiplus::Ok)
    {
        return clone;
    }
    else
    {
        return NULL;
    }
}

Bitmap * WINAPI
Bitmap_CloneAreaI(IN Bitmap * bitmap,
                  IN INT x,
                  IN INT y,
                  IN INT width,
                  IN INT height,
                  IN PixelFormat format
)
{
    Bitmap * clone;

    if (Gdiplus::DllExports::GdipCloneBitmapAreaI(
        x,
        y,
        width,
        height,
        format,
        (Gdiplus::GpBitmap *)bitmap,
        (Gdiplus::GpBitmap **)&clone) == Gdiplus::Ok)
    {
        return clone;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
Bitmap_LockBits(IN Bitmap * bitmap,
                IN const Rect * rect,
                IN UINT flags,
                IN PixelFormat format,
                OUT BitmapData * lockedBitmapData
)
{
    return (Status)Gdiplus::DllExports::GdipBitmapLockBits(
        (Gdiplus::GpBitmap *)bitmap,
        (GDIPCONST Gdiplus::GpRect *)rect,
        flags,
        format,
        (Gdiplus::BitmapData *)lockedBitmapData
    );
}

Status WINAPI
Bitmap_UnlockBits(IN Bitmap * bitmap,
                  IN BitmapData * lockedBitmapData
)
{
    return (Status)Gdiplus::DllExports::GdipBitmapUnlockBits(
        (Gdiplus::GpBitmap *)bitmap,
        (Gdiplus::BitmapData *)lockedBitmapData
    );
}

Color WINAPI
Bitmap_GetPixel(IN Bitmap * bitmap,
                IN INT x,
                IN INT y
)
{
    Color color = 0;

    Gdiplus::DllExports::GdipBitmapGetPixel(
        (Gdiplus::GpBitmap *)bitmap,
        x, y,
        (Gdiplus::ARGB *)&color
    );

    return color;
}

Status WINAPI
Bitmap_SetPixel(IN Bitmap * bitmap,
                IN INT x,
                IN INT y,
                IN Color color
)
{
    return (Status)Gdiplus::DllExports::GdipBitmapSetPixel(
        (Gdiplus::GpBitmap *)bitmap,
        x, y,
        Color_GetValue(color)
    );
}

Status WINAPI
Bitmap_SetResolution(IN Bitmap * bitmap,
                     IN REAL xdpi,
                     IN REAL ydpi
)
{
    return (Status)Gdiplus::DllExports::GdipBitmapSetResolution(
        (Gdiplus::GpBitmap *)bitmap,
        xdpi, ydpi
    );
}