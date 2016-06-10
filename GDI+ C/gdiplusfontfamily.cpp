#include "stdafx.h"

FontFamily * WINAPI
FontFamily_CreateFromName(IN const WCHAR * name,
                          IN FontCollection * fontCollection
)
{
    FontFamily * fontFamily;

    if (Gdiplus::DllExports::GdipCreateFontFamilyFromName(
        name,
        (Gdiplus::GpFontCollection *)fontCollection,
        (Gdiplus::GpFontFamily **)&fontFamily) == Gdiplus::Ok)
    {
        return fontFamily;
    }
    else
    {
        return NULL;
    }
}

FontFamily * WINAPI
FontFamily_GenericSansSerif()
{
    FontFamily * fontFamily;

    if (Gdiplus::DllExports::GdipGetGenericFontFamilySansSerif(
        (Gdiplus::GpFontFamily **)&fontFamily) == Gdiplus::Ok)
    {
        return fontFamily;
    }
    else
    {
        return NULL;
    }
}

FontFamily * WINAPI
FontFamily_GenericSerif()
{
    FontFamily * fontFamily;

    if (Gdiplus::DllExports::GdipGetGenericFontFamilySerif(
        (Gdiplus::GpFontFamily **)&fontFamily) == Gdiplus::Ok)
    {
        return fontFamily;
    }
    else
    {
        return NULL;
    }
}

FontFamily * WINAPI
FontFamily_GenericMonospace()
{
    FontFamily * fontFamily;

    if (Gdiplus::DllExports::GdipGetGenericFontFamilyMonospace(
        (Gdiplus::GpFontFamily **)&fontFamily) == Gdiplus::Ok)
    {
        return fontFamily;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
FontFamily_Delete(IN FontFamily * fontFamily)
{
    return (Status)Gdiplus::DllExports::GdipDeleteFontFamily(
        (Gdiplus::GpFontFamily *)fontFamily
    );
}

FontFamily * WINAPI
FontFamily_Clone(IN FontFamily * fontFamily)
{
    FontFamily * clonedFamily;

    if (Gdiplus::DllExports::GdipCloneFontFamily(
        (Gdiplus::GpFontFamily *)fontFamily,
        (Gdiplus::GpFontFamily **)&clonedFamily) == Gdiplus::Ok)
    {
        return clonedFamily;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
FontFamily_GetFamilyName(IN FontFamily * fontFamily,
                         IN LPWSTR name,
                         IN LANGID language
)
{
    return (Status)Gdiplus::DllExports::GdipGetFamilyName(
        (Gdiplus::GpFontFamily *)fontFamily,
        name,
        language
    );
}

BOOL WINAPI
FontFamily_IsStyleAvailable(IN FontFamily * fontFamily,
                            IN INT style
)
{
    BOOL    StyleAvailable;
    Status  status;

    status = (Status)Gdiplus::DllExports::GdipIsStyleAvailable(
        (Gdiplus::GpFontFamily *)fontFamily, style, &StyleAvailable
    );

    if (status != Ok)
        StyleAvailable = FALSE;

    return StyleAvailable;
}

UINT16 WINAPI
FontFamily_GetEmHeight(IN FontFamily * fontFamily,
                       IN INT style
)
{
    UINT16  EmHeight;

    Gdiplus::DllExports::GdipGetEmHeight(
        (Gdiplus::GpFontFamily *)fontFamily, style, &EmHeight
    );

    return EmHeight;
}

UINT16 WINAPI
FontFamily_GetCellAscent(IN FontFamily * fontFamily,
                         IN INT style
)
{
    UINT16  CellAscent;

    Gdiplus::DllExports::GdipGetCellAscent(
        (Gdiplus::GpFontFamily *)fontFamily, style, &CellAscent
    );

    return CellAscent;
}

UINT16 WINAPI
FontFamily_GetCellDescent(IN FontFamily * fontFamily,
                          IN INT style
)
{
    UINT16  CellDescent;

    Gdiplus::DllExports::GdipGetCellDescent(
        (Gdiplus::GpFontFamily *)fontFamily, style, &CellDescent
    );

    return CellDescent;
}

UINT16 WINAPI
FontFamily_GetLineSpacing(IN FontFamily * fontFamily,
                          IN INT style
)
{
    UINT16  LineSpacing;

    Gdiplus::DllExports::GdipGetLineSpacing(
        (Gdiplus::GpFontFamily *)fontFamily, style, &LineSpacing
    );

    return LineSpacing;

}