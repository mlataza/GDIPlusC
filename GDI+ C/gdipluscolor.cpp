#include "stdafx.h"

VOID WINAPI Color_SetValue(OUT Color * color, IN ARGB argb)
{
    *color = argb;
}

VOID WINAPI Color_SetFromCOLORREF(OUT Color * color, IN COLORREF rgb)
{
    *color = Color_MakeARGB(255, GetRValue(rgb), GetGValue(rgb), GetBValue(rgb));
}

COLORREF WINAPI Color_ToCOLORREF(IN Color color)
{
    return RGB(Color_GetRed(color), Color_GetGreen(color), Color_GetBlue(color));
}

// Assemble A, R, G, B values into a 32-bit integer

ARGB WINAPI Color_MakeARGB(IN BYTE a,
                           IN BYTE r,
                           IN BYTE g,
                           IN BYTE b)
{
    return (((ARGB)(b) << BlueShift) |
        ((ARGB)(g) << GreenShift) |
            ((ARGB)(r) << RedShift) |
            ((ARGB)(a) << AlphaShift));
}