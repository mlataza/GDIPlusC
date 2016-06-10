#include "stdafx.h"

INT WINAPI
FontCollection_GetFamilyCount(IN FontCollection * fontCollection)
{
    INT numFound = 0;

    Gdiplus::DllExports::GdipGetFontCollectionFamilyCount(
        (Gdiplus::GpFontCollection *)fontCollection, &numFound
    );

    return numFound;
}

Status WINAPI
FontCollection_GetFamilies(IN FontCollection * fontCollection,
                           IN INT numSought,
                           OUT FontFamily ** gpfamilies,
                           OUT INT * numFound
)
{
    return (Status)Gdiplus::DllExports::GdipGetFontCollectionFamilyList(
        (Gdiplus::GpFontCollection *)fontCollection,
        numSought,
        (Gdiplus::GpFontFamily **)gpfamilies,
        numFound
    );
}

InstalledFontCollection * WINAPI
InstalledFontCollection_Create()
{
    InstalledFontCollection * iFontCollection;

    if (Gdiplus::DllExports::GdipNewInstalledFontCollection(
        (Gdiplus::GpFontCollection **)&iFontCollection) == Gdiplus::Ok)
    {
        return iFontCollection;
    }
    else
    {
        return NULL;
    }
}

PrivateFontCollection * WINAPI
PrivateFontCollection_Create()
{
    PrivateFontCollection * pvFontCollection;

    if (Gdiplus::DllExports::GdipNewPrivateFontCollection(
        (Gdiplus::GpFontCollection **)&pvFontCollection) == Gdiplus::Ok)
    {
        return pvFontCollection;
    }
    else
    {
        return NULL;
    }
}

Status WINAPI
PrivateFontCollection_Delete(IN PrivateFontCollection * pvFontCollection)
{
    return (Status)Gdiplus::DllExports::GdipDeletePrivateFontCollection(
        (Gdiplus::GpFontCollection **)&pvFontCollection
    );
}

Status WINAPI
PrivateFontCollection_AddFontFile(IN PrivateFontCollection * pvFontCollection,
                                  IN const WCHAR * filename
)
{
    return (Status)Gdiplus::DllExports::GdipPrivateAddFontFile(
        (Gdiplus::GpFontCollection *)pvFontCollection, filename
    );
}

Status WINAPI
PrivateFontCollection_AddMemoryFont(IN PrivateFontCollection * pvFontCollection,
                                    IN const void * memory,
                                    IN INT length
)
{
    return (Status)Gdiplus::DllExports::GdipPrivateAddMemoryFont(
        (Gdiplus::GpFontCollection *)pvFontCollection,
        memory,
        length
    );
}