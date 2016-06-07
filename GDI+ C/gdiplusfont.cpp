#include "stdafx.h"

Status WINAPI
Font_CreateFromHDC(IN HDC hdc,
                  OUT Font ** font
)
{
    return (Status)Gdiplus::DllExports::GdipCreateFontFromDC(
        hdc, (Gdiplus::GpFont **)font
    );
}

Status WINAPI
Font_CreateFromHFONT(IN HDC hdc,
                     IN const HFONT hfont,
                     OUT Font ** font
)
{
    if (hfont)
    {
        LOGFONTA lf;

        if (GetObjectA(hfont, sizeof(LOGFONTA), &lf))
            return (Status)Gdiplus::DllExports::GdipCreateFontFromLogfontA(
                hdc, &lf, (Gdiplus::GpFont **)font
            );
        else
            return (Status)Gdiplus::DllExports::GdipCreateFontFromDC(
                hdc, (Gdiplus::GpFont **)font
            );
    }
    else
    {
        return (Status)Gdiplus::DllExports::GdipCreateFontFromDC(
            hdc, (Gdiplus::GpFont **)font
        );
    }
}

Status WINAPI
Font_CreateFromLogfontW(IN HDC hdc,
                        IN const LOGFONTW * logfont,
                        OUT Font ** font
)
{
    if (logfont)
    {
        return (Status)Gdiplus::DllExports::GdipCreateFontFromLogfontW(
            hdc, logfont, (Gdiplus::GpFont **)font
        );
    }
    else
    {
        return (Status)Gdiplus::DllExports::GdipCreateFontFromDC(
            hdc, (Gdiplus::GpFont **)font
        );
    }
}

Status WINAPI
Font_CreateFromLogfontA(IN HDC hdc,
                        IN const LOGFONTA * logfont,
                        OUT Font ** font
)
{
    if (logfont)
    {
        return (Status)Gdiplus::DllExports::GdipCreateFontFromLogfontA(
            hdc, logfont, (Gdiplus::GpFont **)font
        );
    }
    else
    {
        return (Status)Gdiplus::DllExports::GdipCreateFontFromDC(
            hdc, (Gdiplus::GpFont **)font
        );
    }
}

Status WINAPI
Font_Create(IN FontFamily * family,
            IN REAL emSize,
            IN INT style,
            IN Unit unit,
            OUT Font ** font
)
{
    return (Status)Gdiplus::DllExports::GdipCreateFont(
        (Gdiplus::GpFontFamily *)family,
        emSize,
        style,
        (Gdiplus::GpUnit)unit,
        (Gdiplus::GpFont **)font
    );
}

Status WINAPI
Font_Create2(IN const WCHAR * familyName,
             IN REAL emSize,
             IN INT style,
             IN Unit unit,
             IN FontCollection * fontCollection,
             OUT Font ** font
)
{
    Status status;
    FontFamily * family = NULL;

    if (FontFamily_CreateFromName(familyName, fontCollection, &family) != Ok)
    {
        status = FontFamily_GenericSansSerif(&family);

        if (status != Ok) return status;
    }

    return (Status)Gdiplus::DllExports::GdipCreateFont(
        (Gdiplus::GpFontFamily *)family,
        emSize, style,
        (Gdiplus::GpUnit)unit,
        (Gdiplus::GpFont **)font
    );
}

Status WINAPI
Font_GetLogFontA(IN Font * font,
                 IN Graphics * g,
                 OUT LOGFONTA * logfontA
)
{
    return (Status)Gdiplus::DllExports::GdipGetLogFontA(
        (Gdiplus::GpFont *)font, (Gdiplus::GpGraphics *)g, logfontA
    );
}

Status WINAPI
Font_GetLogFontW(IN Font * font,
                 IN Graphics * g,
                 OUT LOGFONTW * logfontW
)
{
    return (Status)Gdiplus::DllExports::GdipGetLogFontW(
        (Gdiplus::GpFont *)font, (Gdiplus::GpGraphics *)g, logfontW
    );
}

Status WINAPI
Font_Clone(IN Font * font,
           OUT Font ** clonedFont
)
{
    return (Status)Gdiplus::DllExports::GdipCloneFont(
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpFont **)clonedFont
    );
}

Status WINAPI
Font_Delete(IN Font * font)
{
    return (Status)Gdiplus::DllExports::GdipDeleteFont(
        (Gdiplus::GpFont *)font
    );
}

Status WINAPI
Font_GetFamily(IN Font * font,
               OUT FontFamily * family
)
{
    if (!family)
    {
        return InvalidParameter;
    }

    return (Status)Gdiplus::DllExports::GdipGetFamily(
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpFontFamily **)family
    );
}

INT WINAPI
Font_GetStyle(IN Font * font)
{
    INT style;

    Gdiplus::DllExports::GdipGetFontStyle(
        (Gdiplus::GpFont *)font, &style
    );

    return style;
}

REAL WINAPI
Font_GetSize(IN Font * font)
{
    REAL size;

    Gdiplus::DllExports::GdipGetFontSize(
        (Gdiplus::GpFont *)font, &size
    );

    return size;
}

Unit WINAPI
Font_GetUnit(IN Font * font)
{
    Unit unit;

    Gdiplus::DllExports::GdipGetFontUnit(
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpUnit *)&unit
    );

    return unit;
}

REAL WINAPI
Font_GetHeight(IN Font * font,
               IN Graphics * graphics
)
{
    REAL height;

    Gdiplus::DllExports::GdipGetFontHeight(
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpGraphics *)graphics,
        &height
    );

    return height;
}

REAL WINAPI
Font_GetHeightGivenDPI(IN Font * font,
                       IN REAL dpi
)
{
    REAL height;

    Gdiplus::DllExports::GdipGetFontHeightGivenDPI(
        (Gdiplus::GpFont *)font, dpi, &height
    );

    return height;
}
