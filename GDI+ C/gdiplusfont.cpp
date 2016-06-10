#include "stdafx.h"

Font * WINAPI
Font_CreateFromHDC(IN HDC hdc)
{
    Font * font;

    if (Gdiplus::DllExports::GdipCreateFontFromDC(
        hdc, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
    {
        return font;
    }
    else
    {
        return NULL;
    }
}

Font * WINAPI
Font_CreateFromHFONT(IN HDC hdc, IN const HFONT hfont)
{
    Font * font;

    if (hfont)
    {
        LOGFONTA lf;

        if (GetObjectA(hfont, sizeof(LOGFONTA), &lf))
        {
            if (Gdiplus::DllExports::GdipCreateFontFromLogfontA(
                hdc, &lf, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
            {
                return font;
            }
            else
            {
                return NULL;
            }
        }
    }

    if (Gdiplus::DllExports::GdipCreateFontFromDC(
        hdc, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
    {
        return font;
    }
    else
    {
        return NULL;
    }
}

Font * WINAPI
Font_CreateFromLOGFONTW(IN HDC hdc, IN const LOGFONTW * logfont)
{
    Font * font;

    if (logfont)
    {
        if (Gdiplus::DllExports::GdipCreateFontFromLogfontW(
            hdc, logfont, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
        {
            return font;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipCreateFontFromDC(
            hdc, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
        {
            return font;
        }
        else
        {
            return NULL;
        }
    }
}

Font * WINAPI
Font_CreateFromLOGFONTA(IN HDC hdc, IN const LOGFONTA * logfont)
{
    Font * font;

    if (logfont)
    {
        if (Gdiplus::DllExports::GdipCreateFontFromLogfontA(
            hdc, logfont, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
        {
            return font;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (Gdiplus::DllExports::GdipCreateFontFromDC(
            hdc, (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
        {
            return font;
        }
        else
        {
            return NULL;
        }
    }
}

Font * WINAPI
Font_Create(IN FontFamily * family,
            IN REAL emSize,
            IN INT style,
            IN Unit unit
)
{
    Font * font;

    if (Gdiplus::DllExports::GdipCreateFont(
        (Gdiplus::GpFontFamily *)family,
        emSize,
        style,
        (Gdiplus::GpUnit)unit,
        (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
    {
        return font;
    }
    else
    {
        return NULL;
    }
}

Font * WINAPI
Font_Create2(IN const WCHAR * familyName,
             IN REAL emSize,
             IN INT style,
             IN Unit unit,
             IN FontCollection * fontCollection
)
{
    FontFamily * family = NULL;
    Font * font;

    family = FontFamily_CreateFromName(familyName, fontCollection);

    if (!family)
    {
        family = FontFamily_GenericSansSerif();
        if (!family) return NULL;
    }

    if (Gdiplus::DllExports::GdipCreateFont(
        (Gdiplus::GpFontFamily *)family,
        emSize, style,
        (Gdiplus::GpUnit)unit,
        (Gdiplus::GpFont **)&font) == Gdiplus::Ok)
    {
        return font;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
Font_GetLOGFONTA(IN Font * font,
                 IN Graphics * g,
                 OUT LOGFONTA * logfontA
)
{
    return (Status)Gdiplus::DllExports::GdipGetLogFontA(
        (Gdiplus::GpFont *)font, (Gdiplus::GpGraphics *)g, logfontA
    );
}

Status WINAPI
Font_GetLOGFONTW(IN Font * font,
                 IN Graphics * g,
                 OUT LOGFONTW * logfontW
)
{
    return (Status)Gdiplus::DllExports::GdipGetLogFontW(
        (Gdiplus::GpFont *)font, (Gdiplus::GpGraphics *)g, logfontW
    );
}

Font * WINAPI
Font_Clone(IN Font * font)
{
    Font * clonedFont;
    
    if (Gdiplus::DllExports::GdipCloneFont(
        (Gdiplus::GpFont *)font,
        (Gdiplus::GpFont **)&clonedFont) == Gdiplus::Ok)
    {
        return clonedFont;
    }
    else
    {
        return NULL;
    }
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
