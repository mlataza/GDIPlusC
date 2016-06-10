#include "stdafx.h"

StringFormat * WINAPI
StringFormat_Create(IN INT formatFlags, IN LANGID language)
{
    StringFormat * strFormat;

    if (Gdiplus::DllExports::GdipCreateStringFormat(
        formatFlags,
        language,
        (Gdiplus::GpStringFormat **)&strFormat) == Gdiplus::Ok)
    {
        return strFormat;
    }
    else
    {
        return NULL;
    }
}

StringFormat * WINAPI
StringFormat_GenericDefault()
{
    StringFormat * strFormat;

    if (Gdiplus::DllExports::GdipStringFormatGetGenericDefault(
        (Gdiplus::GpStringFormat **)&strFormat) == Gdiplus::Ok)
    {
        return strFormat;
    }
    else
    {
        return NULL;
    }
}

StringFormat * WINAPI
StringFormat_GenericTypographic()
{
    StringFormat * strFormat;

    if (Gdiplus::DllExports::GdipStringFormatGetGenericTypographic(
        (Gdiplus::GpStringFormat **)&strFormat) == Gdiplus::Ok)
    {
        return strFormat;
    }
    else
    {
        return NULL;
    }
}

StringFormat * WINAPI
StringFormat_Clone(IN StringFormat * strFormat)
{
    StringFormat * clonedFormat;

    if (Gdiplus::DllExports::GdipCloneStringFormat(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::GpStringFormat **)&clonedFormat) == Gdiplus::Ok)
    {
        return clonedFormat;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
StringFormat_Delete(IN StringFormat * strFormat)
{
    return (Status)Gdiplus::DllExports::GdipDeleteStringFormat(
        (Gdiplus::GpStringFormat *)strFormat
    );
}

Status WINAPI
StringFormat_SetFormatFlags(IN StringFormat * strFormat,
                            IN INT flags
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatFlags(
        (Gdiplus::GpStringFormat *)strFormat,
        flags
    );
}

INT WINAPI
StringFormat_GetFormatFlags(IN StringFormat * strFormat)
{
    INT flags;

    Gdiplus::DllExports::GdipGetStringFormatFlags(
        (Gdiplus::GpStringFormat *)strFormat, &flags
    );

    return flags;
}

Status WINAPI
StringFormat_SetAlignment(IN StringFormat * strFormat,
                          IN StringAlignment align
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatAlign(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringAlignment)align
    );
}

StringAlignment WINAPI
StringFormat_GetAlignment(IN StringFormat * strFormat)
{
    StringAlignment alignment;

    Gdiplus::DllExports::GdipGetStringFormatAlign(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringAlignment *)&alignment
    );

    return alignment;
}

Status WINAPI
StringFormat_SetLineAlignment(IN StringFormat * strFormat,
                              IN StringAlignment align
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatLineAlign(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringAlignment)align
    );
}

StringAlignment WINAPI
StringFormat_GetLineAlignment(IN StringFormat * strFormat)
{
    StringAlignment alignment;

    Gdiplus::DllExports::GdipGetStringFormatLineAlign(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringAlignment *)&alignment
    );

    return alignment;
}

Status WINAPI
StringFormat_SetHotkeyPrefix(IN StringFormat * strFormat,
                             IN HotkeyPrefix hotkeyPrefix
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatHotkeyPrefix(
        (Gdiplus::GpStringFormat *)strFormat,
        (INT)hotkeyPrefix
    );
}

HotkeyPrefix WINAPI
StringFormat_GetHotkeyPrefix(IN StringFormat * strFormat)
{
    HotkeyPrefix hotkeyPrefix;
    
    Gdiplus::DllExports::GdipGetStringFormatHotkeyPrefix(
        (Gdiplus::GpStringFormat *)strFormat,
        (INT*)&hotkeyPrefix
    );

    return hotkeyPrefix;
}

Status WINAPI
StringFormat_SetTabStops(IN StringFormat * strFormat,
                         IN REAL firstTabOffset,
                         IN INT count,
                         IN const REAL * tabStops
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatTabStops(
        (Gdiplus::GpStringFormat *)strFormat,
        firstTabOffset,
        count,
        tabStops
    );
}

INT WINAPI
StringFormat_GetTabStopCount(IN StringFormat * strFormat)
{
    INT count;

    Gdiplus::DllExports::GdipGetStringFormatTabStopCount(
        (Gdiplus::GpStringFormat *)strFormat, &count
    );
    
    return count;
}

Status WINAPI
StringFormat_GetTabStops(IN StringFormat * strFormat,
                         IN INT count,
                         OUT REAL * firstTabOffset,
                         OUT REAL * tabStops
)
{
    return (Status)Gdiplus::DllExports::GdipGetStringFormatTabStops(
        (Gdiplus::GpStringFormat *)strFormat,
        count,
        firstTabOffset,
        tabStops
    );
}

Status WINAPI
StringFormat_SetDigitSubstitution(IN StringFormat * strFormat,
                                  IN LANGID language,
                                  IN StringDigitSubstitute substitute
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatDigitSubstitution(
        (Gdiplus::GpStringFormat *)strFormat,
        language,
        (Gdiplus::StringDigitSubstitute)substitute
    );
}

LANGID WINAPI
StringFormat_GetDigitSubstitutionLanguage(IN StringFormat * strFormat)
{
    LANGID language;
    
    Gdiplus::DllExports::GdipGetStringFormatDigitSubstitution(
        (Gdiplus::GpStringFormat *)strFormat,
        &language,
        NULL
    );

    return language;
}

StringDigitSubstitute WINAPI
StringFormat_GetDigitSubstitutionMethod(IN StringFormat * strFormat)
{
    StringDigitSubstitute substitute;

    Gdiplus::DllExports::GdipGetStringFormatDigitSubstitution(
        (Gdiplus::GpStringFormat *)strFormat,
        NULL,
        (Gdiplus::StringDigitSubstitute *)&substitute
    );

    return substitute;
}

Status WINAPI
StringFormat_SetTrimming(IN StringFormat * strFormat,
                         IN StringTrimming trimming
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatTrimming(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringTrimming)trimming
    );
}

StringTrimming WINAPI
StringFormat_GetTrimming(IN StringFormat * strFormat)
{
    StringTrimming trimming;

    Gdiplus::DllExports::GdipGetStringFormatTrimming(
        (Gdiplus::GpStringFormat *)strFormat,
        (Gdiplus::StringTrimming *)&trimming
    );

    return trimming;
}

Status WINAPI
StringFormat_SetMeasurableCharacterRanges(IN StringFormat * strFormat,
                                          IN INT rangeCount,
                                          IN const CharacterRange * ranges
)
{
    return (Status)Gdiplus::DllExports::GdipSetStringFormatMeasurableCharacterRanges(
        (Gdiplus::GpStringFormat *)strFormat,
        rangeCount,
        (GDIPCONST Gdiplus::CharacterRange *)ranges
    );
}

INT WINAPI
StringFormat_GetMeasurableCharacterRangeCount(IN StringFormat * strFormat)
{
    INT count;

    Gdiplus::DllExports::GdipGetStringFormatMeasurableCharacterRangeCount(
        (Gdiplus::GpStringFormat *)strFormat,
        &count
    );

    return count;
}