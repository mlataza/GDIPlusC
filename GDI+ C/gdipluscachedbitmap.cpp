#include "stdafx.h"

Status WINAPI
CachedBitmap_Create(IN Bitmap * bitmap,
                    IN Graphics * graphics,
                    OUT CachedBitmap ** cachedBitmap
)
{
    return (Status)Gdiplus::DllExports::GdipCreateCachedBitmap(
        (Gdiplus::GpBitmap *)bitmap,
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpCachedBitmap **)cachedBitmap
    );
}

Status WINAPI
CachedBitmap_Delete(IN CachedBitmap * cachedBitmap)
{
    return (Status)Gdiplus::DllExports::GdipDeleteCachedBitmap(
        (Gdiplus::GpCachedBitmap *)cachedBitmap
    );
}