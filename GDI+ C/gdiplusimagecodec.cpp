#include "stdafx.h"

Status WINAPI
GetImageDecodersSize(
    OUT UINT * numDecoders,
    OUT UINT * size
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageDecodersSize(
        numDecoders, size
    );
}

Status WINAPI
GetImageDecoders(IN UINT numDecoders,
                 IN UINT size,
                 OUT ImageCodecInfo * decoders
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageDecoders(
        numDecoders, size, (Gdiplus::ImageCodecInfo *)decoders
    );
}

Status WINAPI
GetImageEncodersSize(OUT UINT * numEncoders,
                     OUT UINT * size
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageEncodersSize(
        numEncoders, size
    );
}

Status WINAPI
GetImageEncoders(IN UINT numEncoders,
                 IN UINT size,
                 OUT ImageCodecInfo * encoders
)
{
    return (Status)Gdiplus::DllExports::GdipGetImageEncoders(
        numEncoders, size, (Gdiplus::ImageCodecInfo *)encoders
    );
}