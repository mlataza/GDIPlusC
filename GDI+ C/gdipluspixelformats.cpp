#include "stdafx.h"

UINT WINAPI
GetPixelFormatSize(PixelFormat pixfmt)
{
    return (pixfmt >> 8) & 0xff;
}

BOOL WINAPI
IsIndexedPixelFormat(PixelFormat pixfmt)
{
    return (pixfmt & PixelFormatIndexed) != 0;
}

BOOL WINAPI
IsAlphaPixelFormat(PixelFormat pixfmt)
{
    return (pixfmt & PixelFormatAlpha) != 0;
}

BOOL WINAPI
IsExtendedPixelFormat(PixelFormat pixfmt)
{
    return (pixfmt & PixelFormatExtended) != 0;
}

BOOL WINAPI
IsCanonicalPixelFormat(PixelFormat pixfmt)
{
    return (pixfmt & PixelFormatCanonical) != 0;
}