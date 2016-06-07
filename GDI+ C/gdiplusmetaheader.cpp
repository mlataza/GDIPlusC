#include "stdafx.h"

MetafileType WINAPI MetafileHeader_GetType(IN const MetafileHeader * mfh)
{
    return mfh->Type;
}

UINT WINAPI MetafileHeader_GetMetafileSize(IN const MetafileHeader * mfh)
{
    return mfh->Size;
}

// If IsEmfPlus, this is the EMF+ version; else it is the WMF or EMF ver

UINT WINAPI MetafileHeader_GetVersion(IN const MetafileHeader * mfh)
{
    return mfh->Version;
}

// Get the EMF+ flags associated with the metafile

UINT WINAPI MetafileHeader_GetEmfPlusFlags(IN const MetafileHeader * mfh)
{
    return mfh->EmfPlusFlags;
}

REAL WINAPI MetafileHeader_GetDpiX(IN const MetafileHeader * mfh)
{
    return mfh->DpiX;
}

REAL WINAPI MetafileHeader_GetDpiY(IN const MetafileHeader * mfh)
{
    return mfh->DpiY;
}

VOID WINAPI MetafileHeader_GetBounds(IN const MetafileHeader * mfh, OUT Rect *rect)
{
    rect->X = mfh->X;
    rect->Y = mfh->Y;
    rect->Width = mfh->Width;
    rect->Height = mfh->Height;
}

// Is it any type of WMF (standard or Placeable Metafile)?

BOOL WINAPI MetafileHeader_IsWmf(IN const MetafileHeader * mfh)
{
    return ((mfh->Type == MetafileTypeWmf) ||
        (mfh->Type == MetafileTypeWmfPlaceable));
}

// Is this an Placeable Metafile?

BOOL WINAPI MetafileHeader_IsWmfPlaceable(IN const MetafileHeader * mfh)
{
    return (mfh->Type == MetafileTypeWmfPlaceable);
}

// Is this an EMF (not an EMF+)?

BOOL WINAPI MetafileHeader_IsEmf(IN const MetafileHeader * mfh)
{
    return (mfh->Type == MetafileTypeEmf);
}

// Is this an EMF or EMF+ file?

BOOL WINAPI MetafileHeader_IsEmfOrEmfPlus(IN const MetafileHeader * mfh)
{
    return (mfh->Type >= MetafileTypeEmf);
}

// Is this an EMF+ file?

BOOL WINAPI MetafileHeader_IsEmfPlus(IN const MetafileHeader * mfh)
{
    return (mfh->Type >= MetafileTypeEmfPlusOnly);
}

// Is this an EMF+ dual (has dual, down-level records) file?

BOOL WINAPI MetafileHeader_IsEmfPlusDual(IN const MetafileHeader * mfh)
{
    return (mfh->Type == MetafileTypeEmfPlusDual);
}

// Is this an EMF+ only (no dual records) file?

BOOL WINAPI MetafileHeader_IsEmfPlusOnly(IN const MetafileHeader * mfh)
{
    return (mfh->Type == MetafileTypeEmfPlusOnly);
}

// If it's an EMF+ file, was it recorded against a display Hdc?

BOOL WINAPI MetafileHeader_IsDisplay(IN const MetafileHeader * mfh)
{
    return (MetafileHeader_IsEmfPlus(mfh) &&
        ((mfh->EmfPlusFlags & GDIP_EMFPLUSFLAGS_DISPLAY) != 0));
}

// Get the WMF header of the metafile (if it is a WMF)

const METAHEADER *
WINAPI MetafileHeader_GetWmfHeader(IN const MetafileHeader * mfh)
{
    if (MetafileHeader_IsWmf(mfh))
    {
        return &mfh->WmfHeader;
    }
    return NULL;
}

// Get the EMF header of the metafile (if it is an EMF)

const ENHMETAHEADER3 *
WINAPI MetafileHeader_GetEmfHeader(IN const MetafileHeader * mfh)
{
    if (MetafileHeader_IsEmfOrEmfPlus(mfh))
    {
        return &mfh->EmfHeader;
    }
    return NULL;
}