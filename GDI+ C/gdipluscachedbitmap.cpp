#include "stdafx.h"

CachedBitmap * WINAPI
CachedBitmap_Create(IN Bitmap * bitmap, IN Graphics * graphics)
{
    CachedBitmap * cachedBitmap;

    if (Gdiplus::DllExports::GdipCreateCachedBitmap(
        (Gdiplus::GpBitmap *)bitmap,
        (Gdiplus::GpGraphics *)graphics,
        (Gdiplus::GpCachedBitmap **)&cachedBitmap) == Gdiplus::Ok)
    {
        return cachedBitmap;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
CachedBitmap_Delete(IN CachedBitmap * cachedBitmap)
{
    return (Status)Gdiplus::DllExports::GdipDeleteCachedBitmap(
        (Gdiplus::GpCachedBitmap *)cachedBitmap
    );
}