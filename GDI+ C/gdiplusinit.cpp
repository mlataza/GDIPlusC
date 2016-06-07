#include "stdafx.h"

Status WINAPI GdipluscStartup(
    OUT ULONG_PTR *token,
    const GdiplusStartupInput *input,
    OUT GdiplusStartupOutput *output)
{
    return (Status)GdiplusStartup(
        token,
        (const Gdiplus::GdiplusStartupInput *)input,
        (Gdiplus::GdiplusStartupOutput *)output
    );
}


VOID WINAPI GdipluscShutdown(ULONG_PTR token)
{
    Gdiplus::GdiplusShutdown(token);
}