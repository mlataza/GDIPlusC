#ifndef GDIPLUS_C_H_
#define GDIPLUS_C_H_

typedef signed   short   INT16;
typedef unsigned short  UINT16;

// Define the Current GDIPlus Version
#ifndef GDIPVER
#define GDIPVER 0x0100
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#pragma region GdiplusEnums.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusEnums.h
*
* Abstract:
*
*   GDI+ Enumeration Types
*
\**************************************************************************/

//--------------------------------------------------------------------------
// Default bezier flattening tolerance in device pixels.
//--------------------------------------------------------------------------

const float FlatnessDefault = 1.0f / 4.0f;

//--------------------------------------------------------------------------
// Graphics and Container State cookies
//--------------------------------------------------------------------------

typedef UINT     GraphicsState;
typedef UINT     GraphicsContainer;

//--------------------------------------------------------------------------
// Fill mode constants
//--------------------------------------------------------------------------

typedef enum FillMode
{
    FillModeAlternate,        // 0
    FillModeWinding           // 1
} FillMode;

//--------------------------------------------------------------------------
// Quality mode constants
//--------------------------------------------------------------------------

typedef enum QualityMode
{
    QualityModeInvalid = -1,
    QualityModeDefault = 0,
    QualityModeLow = 1, // Best performance
    QualityModeHigh = 2  // Best rendering quality
} QualityMode;

//--------------------------------------------------------------------------
// Alpha Compositing mode constants
//--------------------------------------------------------------------------

typedef enum CompositingMode
{
    CompositingModeSourceOver,    // 0
    CompositingModeSourceCopy     // 1
} CompositingMode;

//--------------------------------------------------------------------------
// Alpha Compositing quality constants
//--------------------------------------------------------------------------

typedef enum CompositingQuality
{
    CompositingQualityInvalid = QualityModeInvalid,
    CompositingQualityDefault = QualityModeDefault,
    CompositingQualityHighSpeed = QualityModeLow,
    CompositingQualityHighQuality = QualityModeHigh,
    CompositingQualityGammaCorrected,
    CompositingQualityAssumeLinear
} CompositingQuality;

//--------------------------------------------------------------------------
// Unit constants
//--------------------------------------------------------------------------

typedef enum Unit
{
    UnitWorld,      // 0 -- World coordinate (non-physical unit)
    UnitDisplay,    // 1 -- Variable -- for PageTransform only
    UnitPixel,      // 2 -- Each unit is one device pixel.
    UnitPoint,      // 3 -- Each unit is a printer's point, or 1/72 inch.
    UnitInch,       // 4 -- Each unit is 1 inch.
    UnitDocument,   // 5 -- Each unit is 1/300 inch.
    UnitMillimeter  // 6 -- Each unit is 1 millimeter.
} Unit;

//--------------------------------------------------------------------------
// MetafileFrameUnit
//
// The frameRect for creating a metafile can be specified in any of these
// units.  There is an extra frame unit value (MetafileFrameUnitGdi) so
// that units can be supplied in the same units that GDI expects for
// frame rects -- these units are in .01 (1/100ths) millimeter units
// as defined by GDI.
//--------------------------------------------------------------------------

typedef enum MetafileFrameUnit
{
    MetafileFrameUnitPixel = UnitPixel,
    MetafileFrameUnitPoint = UnitPoint,
    MetafileFrameUnitInch = UnitInch,
    MetafileFrameUnitDocument = UnitDocument,
    MetafileFrameUnitMillimeter = UnitMillimeter,
    MetafileFrameUnitGdi                        // GDI compatible .01 MM units
} MetafileFrameUnit;

//--------------------------------------------------------------------------
// Coordinate space identifiers
//--------------------------------------------------------------------------

typedef enum CoordinateSpace
{
    CoordinateSpaceWorld,     // 0
    CoordinateSpacePage,      // 1
    CoordinateSpaceDevice     // 2
} CoordinateSpace;

//--------------------------------------------------------------------------
// Various wrap modes for brushes
//--------------------------------------------------------------------------

typedef enum WrapMode
{
    WrapModeTile,        // 0
    WrapModeTileFlipX,   // 1
    WrapModeTileFlipY,   // 2
    WrapModeTileFlipXY,  // 3
    WrapModeClamp        // 4
} WrapMode;

//--------------------------------------------------------------------------
// Various hatch styles
//--------------------------------------------------------------------------

typedef enum HatchStyle
{
    HatchStyleHorizontal,                   // 0
    HatchStyleVertical,                     // 1
    HatchStyleForwardDiagonal,              // 2
    HatchStyleBackwardDiagonal,             // 3
    HatchStyleCross,                        // 4
    HatchStyleDiagonalCross,                // 5
    HatchStyle05Percent,                    // 6
    HatchStyle10Percent,                    // 7
    HatchStyle20Percent,                    // 8
    HatchStyle25Percent,                    // 9
    HatchStyle30Percent,                    // 10
    HatchStyle40Percent,                    // 11
    HatchStyle50Percent,                    // 12
    HatchStyle60Percent,                    // 13
    HatchStyle70Percent,                    // 14
    HatchStyle75Percent,                    // 15
    HatchStyle80Percent,                    // 16
    HatchStyle90Percent,                    // 17
    HatchStyleLightDownwardDiagonal,        // 18
    HatchStyleLightUpwardDiagonal,          // 19
    HatchStyleDarkDownwardDiagonal,         // 20
    HatchStyleDarkUpwardDiagonal,           // 21
    HatchStyleWideDownwardDiagonal,         // 22
    HatchStyleWideUpwardDiagonal,           // 23
    HatchStyleLightVertical,                // 24
    HatchStyleLightHorizontal,              // 25
    HatchStyleNarrowVertical,               // 26
    HatchStyleNarrowHorizontal,             // 27
    HatchStyleDarkVertical,                 // 28
    HatchStyleDarkHorizontal,               // 29
    HatchStyleDashedDownwardDiagonal,       // 30
    HatchStyleDashedUpwardDiagonal,         // 31
    HatchStyleDashedHorizontal,             // 32
    HatchStyleDashedVertical,               // 33
    HatchStyleSmallConfetti,                // 34
    HatchStyleLargeConfetti,                // 35
    HatchStyleZigZag,                       // 36
    HatchStyleWave,                         // 37
    HatchStyleDiagonalBrick,                // 38
    HatchStyleHorizontalBrick,              // 39
    HatchStyleWeave,                        // 40
    HatchStylePlaid,                        // 41
    HatchStyleDivot,                        // 42
    HatchStyleDottedGrid,                   // 43
    HatchStyleDottedDiamond,                // 44
    HatchStyleShingle,                      // 45
    HatchStyleTrellis,                      // 46
    HatchStyleSphere,                       // 47
    HatchStyleSmallGrid,                    // 48
    HatchStyleSmallCheckerBoard,            // 49
    HatchStyleLargeCheckerBoard,            // 50
    HatchStyleOutlinedDiamond,              // 51
    HatchStyleSolidDiamond,                 // 52

    HatchStyleTotal,
    HatchStyleLargeGrid = HatchStyleCross,  // 4

    HatchStyleMin = HatchStyleHorizontal,
    HatchStyleMax = HatchStyleTotal - 1,
} HatchStyle;

//--------------------------------------------------------------------------
// Dash style constants
//--------------------------------------------------------------------------

typedef enum DashStyle
{
    DashStyleSolid,          // 0
    DashStyleDash,           // 1
    DashStyleDot,            // 2
    DashStyleDashDot,        // 3
    DashStyleDashDotDot,     // 4
    DashStyleCustom          // 5
} DashStyle;

//--------------------------------------------------------------------------
// Dash cap constants
//--------------------------------------------------------------------------

typedef enum DashCap
{
    DashCapFlat = 0,
    DashCapRound = 2,
    DashCapTriangle = 3
} DashCap;

//--------------------------------------------------------------------------
// Line cap constants (only the lowest 8 bits are used).
//--------------------------------------------------------------------------

typedef enum LineCap
{
    LineCapFlat = 0,
    LineCapSquare = 1,
    LineCapRound = 2,
    LineCapTriangle = 3,

    LineCapNoAnchor = 0x10, // corresponds to flat cap
    LineCapSquareAnchor = 0x11, // corresponds to square cap
    LineCapRoundAnchor = 0x12, // corresponds to round cap
    LineCapDiamondAnchor = 0x13, // corresponds to triangle cap
    LineCapArrowAnchor = 0x14, // no correspondence

    LineCapCustom = 0xff, // custom cap

    LineCapAnchorMask = 0xf0  // mask to check for anchor or not.
} LineCap;

//--------------------------------------------------------------------------
// Custom Line cap type constants
//--------------------------------------------------------------------------

typedef enum CustomLineCapType
{
    CustomLineCapTypeDefault = 0,
    CustomLineCapTypeAdjustableArrow = 1
} CustomLineCapType;

//--------------------------------------------------------------------------
// Line join constants
//--------------------------------------------------------------------------

typedef enum LineJoin
{
    LineJoinMiter = 0,
    LineJoinBevel = 1,
    LineJoinRound = 2,
    LineJoinMiterClipped = 3
} LineJoin;

//--------------------------------------------------------------------------
// Path point types (only the lowest 8 bits are used.)
//  The lowest 3 bits are interpreted as point type
//  The higher 5 bits are reserved for flags.
//--------------------------------------------------------------------------

typedef enum PathPointType
{
    PathPointTypeStart = 0,    // move
    PathPointTypeLine = 1,    // line
    PathPointTypeBezier = 3,    // default Bezier (= cubic Bezier)
    PathPointTypePathTypeMask = 0x07, // type mask (lowest 3 bits).
    PathPointTypeDashMode = 0x10, // currently in dash mode.
    PathPointTypePathMarker = 0x20, // a marker for the path.
    PathPointTypeCloseSubpath = 0x80, // closed flag

                                      // Path types used for advanced path.

                                      PathPointTypeBezier3 = 3,         // cubic Bezier
} PathPointType;


//--------------------------------------------------------------------------
// WarpMode constants
//--------------------------------------------------------------------------

typedef enum WarpMode
{
    WarpModePerspective,    // 0
    WarpModeBilinear        // 1
} WarpMode;

//--------------------------------------------------------------------------
// LineGradient Mode
//--------------------------------------------------------------------------

typedef enum LinearGradientMode
{
    LinearGradientModeHorizontal,         // 0
    LinearGradientModeVertical,           // 1
    LinearGradientModeForwardDiagonal,    // 2
    LinearGradientModeBackwardDiagonal    // 3
} LinearGradientMode;

//--------------------------------------------------------------------------
// Region Comine Modes
//--------------------------------------------------------------------------

typedef enum CombineMode
{
    CombineModeReplace,     // 0
    CombineModeIntersect,   // 1
    CombineModeUnion,       // 2
    CombineModeXor,         // 3
    CombineModeExclude,     // 4
    CombineModeComplement   // 5 (Exclude From)
} CombineMode;

//--------------------------------------------------------------------------
// Image types
//--------------------------------------------------------------------------

typedef enum ImageType
{
    ImageTypeUnknown,   // 0
    ImageTypeBitmap,    // 1
    ImageTypeMetafile   // 2
} ImageType;

//--------------------------------------------------------------------------
// Interpolation modes
//--------------------------------------------------------------------------

typedef enum InterpolationMode
{
    InterpolationModeInvalid = QualityModeInvalid,
    InterpolationModeDefault = QualityModeDefault,
    InterpolationModeLowQuality = QualityModeLow,
    InterpolationModeHighQuality = QualityModeHigh,
    InterpolationModeBilinear,
    InterpolationModeBicubic,
    InterpolationModeNearestNeighbor,
    InterpolationModeHighQualityBilinear,
    InterpolationModeHighQualityBicubic
} InterpolationMode;

//--------------------------------------------------------------------------
// Pen types
//--------------------------------------------------------------------------

typedef enum PenAlignment
{
    PenAlignmentCenter = 0,
    PenAlignmentInset = 1
} PenAlignment;

//--------------------------------------------------------------------------
// Brush types
//--------------------------------------------------------------------------

typedef enum BrushType
{
    BrushTypeSolidColor = 0,
    BrushTypeHatchFill = 1,
    BrushTypeTextureFill = 2,
    BrushTypePathGradient = 3,
    BrushTypeLinearGradient = 4
} BrushType;

//--------------------------------------------------------------------------
// Pen's Fill types
//--------------------------------------------------------------------------

typedef enum PenType
{
    PenTypeSolidColor = BrushTypeSolidColor,
    PenTypeHatchFill = BrushTypeHatchFill,
    PenTypeTextureFill = BrushTypeTextureFill,
    PenTypePathGradient = BrushTypePathGradient,
    PenTypeLinearGradient = BrushTypeLinearGradient,
    PenTypeUnknown = -1
} PenType;

//--------------------------------------------------------------------------
// Matrix Order
//--------------------------------------------------------------------------

typedef enum MatrixOrder
{
    MatrixOrderPrepend = 0,
    MatrixOrderAppend = 1
} MatrixOrder;

//--------------------------------------------------------------------------
// Generic font families
//--------------------------------------------------------------------------

typedef enum GenericFontFamily
{
    GenericFontFamilySerif,
    GenericFontFamilySansSerif,
    GenericFontFamilyMonospace

} GenericFontFamily;

//--------------------------------------------------------------------------
// FontStyle: face types and common styles
//--------------------------------------------------------------------------

typedef enum FontStyle
{
    FontStyleRegular = 0,
    FontStyleBold = 1,
    FontStyleItalic = 2,
    FontStyleBoldItalic = 3,
    FontStyleUnderline = 4,
    FontStyleStrikeout = 8
} FontStyle;

//---------------------------------------------------------------------------
// Smoothing Mode
//---------------------------------------------------------------------------

typedef enum SmoothingMode
{
    SmoothingModeInvalid = QualityModeInvalid,
    SmoothingModeDefault = QualityModeDefault,
    SmoothingModeHighSpeed = QualityModeLow,
    SmoothingModeHighQuality = QualityModeHigh,
    SmoothingModeNone,
    SmoothingModeAntiAlias,
} SmoothingMode;

//---------------------------------------------------------------------------
// Pixel Format Mode
//---------------------------------------------------------------------------

typedef enum PixelOffsetMode
{
    PixelOffsetModeInvalid = QualityModeInvalid,
    PixelOffsetModeDefault = QualityModeDefault,
    PixelOffsetModeHighSpeed = QualityModeLow,
    PixelOffsetModeHighQuality = QualityModeHigh,
    PixelOffsetModeNone,    // No pixel offset
    PixelOffsetModeHalf     // Offset by -0.5, -0.5 for fast anti-alias perf
} PixelOffsetMode;

//---------------------------------------------------------------------------
// Text Rendering Hint
//---------------------------------------------------------------------------

typedef enum TextRenderingHint
{
    TextRenderingHintSystemDefault = 0,            // Glyph with system default rendering hint
    TextRenderingHintSingleBitPerPixelGridFit,     // Glyph bitmap with hinting
    TextRenderingHintSingleBitPerPixel,            // Glyph bitmap without hinting
    TextRenderingHintAntiAliasGridFit,             // Glyph anti-alias bitmap with hinting
    TextRenderingHintAntiAlias,                    // Glyph anti-alias bitmap without hinting
    TextRenderingHintClearTypeGridFit              // Glyph CT bitmap with hinting
} TextRenderingHint;

//---------------------------------------------------------------------------
// Metafile Types
//---------------------------------------------------------------------------

typedef enum MetafileType
{
    MetafileTypeInvalid,            // Invalid metafile
    MetafileTypeWmf,                // Standard WMF
    MetafileTypeWmfPlaceable,       // Placeable WMF
    MetafileTypeEmf,                // EMF (not EMF+)
    MetafileTypeEmfPlusOnly,        // EMF+ without dual, down-level records
    MetafileTypeEmfPlusDual         // EMF+ with dual, down-level records
} MetafileType;

//---------------------------------------------------------------------------
// Specifies the type of EMF to record
//---------------------------------------------------------------------------

typedef enum EmfType
{
    EmfTypeEmfOnly = MetafileTypeEmf,          // no EMF+, only EMF
    EmfTypeEmfPlusOnly = MetafileTypeEmfPlusOnly,  // no EMF, only EMF+
    EmfTypeEmfPlusDual = MetafileTypeEmfPlusDual   // both EMF+ and EMF
} EmfType;

//---------------------------------------------------------------------------
// EMF+ Persistent object types
//---------------------------------------------------------------------------

typedef enum ObjectType
{
    ObjectTypeInvalid,
    ObjectTypeBrush,
    ObjectTypePen,
    ObjectTypePath,
    ObjectTypeRegion,
    ObjectTypeImage,
    ObjectTypeFont,
    ObjectTypeStringFormat,
    ObjectTypeImageAttributes,
    ObjectTypeCustomLineCap,
    ObjectTypeMax = ObjectTypeCustomLineCap,
    ObjectTypeMin = ObjectTypeBrush
} ObjectType;


BOOL WINAPI
ObjectTypeIsValid(ObjectType type);


//---------------------------------------------------------------------------
// EMF+ Records
//---------------------------------------------------------------------------

// We have to change the WMF record numbers so that they don't conflict with
// the EMF and EMF+ record numbers.
typedef enum EmfPlusRecordType EmfPlusRecordType;

#define GDIP_EMFPLUS_RECORD_BASE        0x00004000
#define GDIP_WMF_RECORD_BASE            0x00010000
#define GDIP_WMF_RECORD_TO_EMFPLUS(n)   ((EmfPlusRecordType)((n) | GDIP_WMF_RECORD_BASE))
#define GDIP_EMFPLUS_RECORD_TO_WMF(n)   ((n) & (~GDIP_WMF_RECORD_BASE))
#define GDIP_IS_WMF_RECORDTYPE(n)       (((n) & GDIP_WMF_RECORD_BASE) != 0)

enum EmfPlusRecordType
{
    // Since we have to enumerate GDI records right along with GDI+ records,
    // We list all the GDI records here so that they can be part of the
    // same enumeration type which is used in the enumeration callback.

    WmfRecordTypeSetBkColor = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKCOLOR),
    WmfRecordTypeSetBkMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKMODE),
    WmfRecordTypeSetMapMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPMODE),
    WmfRecordTypeSetROP2 = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETROP2),
    WmfRecordTypeSetRelAbs = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETRELABS),
    WmfRecordTypeSetPolyFillMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPOLYFILLMODE),
    WmfRecordTypeSetStretchBltMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETSTRETCHBLTMODE),
    WmfRecordTypeSetTextCharExtra = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCHAREXTRA),
    WmfRecordTypeSetTextColor = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCOLOR),
    WmfRecordTypeSetTextJustification = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTJUSTIFICATION),
    WmfRecordTypeSetWindowOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWORG),
    WmfRecordTypeSetWindowExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWEXT),
    WmfRecordTypeSetViewportOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTORG),
    WmfRecordTypeSetViewportExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTEXT),
    WmfRecordTypeOffsetWindowOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETWINDOWORG),
    WmfRecordTypeScaleWindowExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEWINDOWEXT),
    WmfRecordTypeOffsetViewportOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETVIEWPORTORG),
    WmfRecordTypeScaleViewportExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEVIEWPORTEXT),
    WmfRecordTypeLineTo = GDIP_WMF_RECORD_TO_EMFPLUS(META_LINETO),
    WmfRecordTypeMoveTo = GDIP_WMF_RECORD_TO_EMFPLUS(META_MOVETO),
    WmfRecordTypeExcludeClipRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXCLUDECLIPRECT),
    WmfRecordTypeIntersectClipRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_INTERSECTCLIPRECT),
    WmfRecordTypeArc = GDIP_WMF_RECORD_TO_EMFPLUS(META_ARC),
    WmfRecordTypeEllipse = GDIP_WMF_RECORD_TO_EMFPLUS(META_ELLIPSE),
    WmfRecordTypeFloodFill = GDIP_WMF_RECORD_TO_EMFPLUS(META_FLOODFILL),
    WmfRecordTypePie = GDIP_WMF_RECORD_TO_EMFPLUS(META_PIE),
    WmfRecordTypeRectangle = GDIP_WMF_RECORD_TO_EMFPLUS(META_RECTANGLE),
    WmfRecordTypeRoundRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_ROUNDRECT),
    WmfRecordTypePatBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_PATBLT),
    WmfRecordTypeSaveDC = GDIP_WMF_RECORD_TO_EMFPLUS(META_SAVEDC),
    WmfRecordTypeSetPixel = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPIXEL),
    WmfRecordTypeOffsetClipRgn = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETCLIPRGN),
    WmfRecordTypeTextOut = GDIP_WMF_RECORD_TO_EMFPLUS(META_TEXTOUT),
    WmfRecordTypeBitBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_BITBLT),
    WmfRecordTypeStretchBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHBLT),
    WmfRecordTypePolygon = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYGON),
    WmfRecordTypePolyline = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYLINE),
    WmfRecordTypeEscape = GDIP_WMF_RECORD_TO_EMFPLUS(META_ESCAPE),
    WmfRecordTypeRestoreDC = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESTOREDC),
    WmfRecordTypeFillRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_FILLREGION),
    WmfRecordTypeFrameRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_FRAMEREGION),
    WmfRecordTypeInvertRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_INVERTREGION),
    WmfRecordTypePaintRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_PAINTREGION),
    WmfRecordTypeSelectClipRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTCLIPREGION),
    WmfRecordTypeSelectObject = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTOBJECT),
    WmfRecordTypeSetTextAlign = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTALIGN),
    WmfRecordTypeDrawText = GDIP_WMF_RECORD_TO_EMFPLUS(0x062F),  // META_DRAWTEXT
    WmfRecordTypeChord = GDIP_WMF_RECORD_TO_EMFPLUS(META_CHORD),
    WmfRecordTypeSetMapperFlags = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPPERFLAGS),
    WmfRecordTypeExtTextOut = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTTEXTOUT),
    WmfRecordTypeSetDIBToDev = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETDIBTODEV),
    WmfRecordTypeSelectPalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTPALETTE),
    WmfRecordTypeRealizePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_REALIZEPALETTE),
    WmfRecordTypeAnimatePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_ANIMATEPALETTE),
    WmfRecordTypeSetPalEntries = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPALENTRIES),
    WmfRecordTypePolyPolygon = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYPOLYGON),
    WmfRecordTypeResizePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESIZEPALETTE),
    WmfRecordTypeDIBBitBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBBITBLT),
    WmfRecordTypeDIBStretchBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBSTRETCHBLT),
    WmfRecordTypeDIBCreatePatternBrush = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBCREATEPATTERNBRUSH),
    WmfRecordTypeStretchDIB = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHDIB),
    WmfRecordTypeExtFloodFill = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTFLOODFILL),
    WmfRecordTypeSetLayout = GDIP_WMF_RECORD_TO_EMFPLUS(0x0149),  // META_SETLAYOUT
    WmfRecordTypeResetDC = GDIP_WMF_RECORD_TO_EMFPLUS(0x014C),  // META_RESETDC
    WmfRecordTypeStartDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x014D),  // META_STARTDOC
    WmfRecordTypeStartPage = GDIP_WMF_RECORD_TO_EMFPLUS(0x004F),  // META_STARTPAGE
    WmfRecordTypeEndPage = GDIP_WMF_RECORD_TO_EMFPLUS(0x0050),  // META_ENDPAGE
    WmfRecordTypeAbortDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x0052),  // META_ABORTDOC
    WmfRecordTypeEndDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x005E),  // META_ENDDOC
    WmfRecordTypeDeleteObject = GDIP_WMF_RECORD_TO_EMFPLUS(META_DELETEOBJECT),
    WmfRecordTypeCreatePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPALETTE),
    WmfRecordTypeCreateBrush = GDIP_WMF_RECORD_TO_EMFPLUS(0x00F8),  // META_CREATEBRUSH
    WmfRecordTypeCreatePatternBrush = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPATTERNBRUSH),
    WmfRecordTypeCreatePenIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPENINDIRECT),
    WmfRecordTypeCreateFontIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEFONTINDIRECT),
    WmfRecordTypeCreateBrushIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEBRUSHINDIRECT),
    WmfRecordTypeCreateBitmapIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(0x02FD),  // META_CREATEBITMAPINDIRECT
    WmfRecordTypeCreateBitmap = GDIP_WMF_RECORD_TO_EMFPLUS(0x06FE),  // META_CREATEBITMAP
    WmfRecordTypeCreateRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEREGION),

    EmfRecordTypeHeader = EMR_HEADER,
    EmfRecordTypePolyBezier = EMR_POLYBEZIER,
    EmfRecordTypePolygon = EMR_POLYGON,
    EmfRecordTypePolyline = EMR_POLYLINE,
    EmfRecordTypePolyBezierTo = EMR_POLYBEZIERTO,
    EmfRecordTypePolyLineTo = EMR_POLYLINETO,
    EmfRecordTypePolyPolyline = EMR_POLYPOLYLINE,
    EmfRecordTypePolyPolygon = EMR_POLYPOLYGON,
    EmfRecordTypeSetWindowExtEx = EMR_SETWINDOWEXTEX,
    EmfRecordTypeSetWindowOrgEx = EMR_SETWINDOWORGEX,
    EmfRecordTypeSetViewportExtEx = EMR_SETVIEWPORTEXTEX,
    EmfRecordTypeSetViewportOrgEx = EMR_SETVIEWPORTORGEX,
    EmfRecordTypeSetBrushOrgEx = EMR_SETBRUSHORGEX,
    EmfRecordTypeEOF = EMR_EOF,
    EmfRecordTypeSetPixelV = EMR_SETPIXELV,
    EmfRecordTypeSetMapperFlags = EMR_SETMAPPERFLAGS,
    EmfRecordTypeSetMapMode = EMR_SETMAPMODE,
    EmfRecordTypeSetBkMode = EMR_SETBKMODE,
    EmfRecordTypeSetPolyFillMode = EMR_SETPOLYFILLMODE,
    EmfRecordTypeSetROP2 = EMR_SETROP2,
    EmfRecordTypeSetStretchBltMode = EMR_SETSTRETCHBLTMODE,
    EmfRecordTypeSetTextAlign = EMR_SETTEXTALIGN,
    EmfRecordTypeSetColorAdjustment = EMR_SETCOLORADJUSTMENT,
    EmfRecordTypeSetTextColor = EMR_SETTEXTCOLOR,
    EmfRecordTypeSetBkColor = EMR_SETBKCOLOR,
    EmfRecordTypeOffsetClipRgn = EMR_OFFSETCLIPRGN,
    EmfRecordTypeMoveToEx = EMR_MOVETOEX,
    EmfRecordTypeSetMetaRgn = EMR_SETMETARGN,
    EmfRecordTypeExcludeClipRect = EMR_EXCLUDECLIPRECT,
    EmfRecordTypeIntersectClipRect = EMR_INTERSECTCLIPRECT,
    EmfRecordTypeScaleViewportExtEx = EMR_SCALEVIEWPORTEXTEX,
    EmfRecordTypeScaleWindowExtEx = EMR_SCALEWINDOWEXTEX,
    EmfRecordTypeSaveDC = EMR_SAVEDC,
    EmfRecordTypeRestoreDC = EMR_RESTOREDC,
    EmfRecordTypeSetWorldTransform = EMR_SETWORLDTRANSFORM,
    EmfRecordTypeModifyWorldTransform = EMR_MODIFYWORLDTRANSFORM,
    EmfRecordTypeSelectObject = EMR_SELECTOBJECT,
    EmfRecordTypeCreatePen = EMR_CREATEPEN,
    EmfRecordTypeCreateBrushIndirect = EMR_CREATEBRUSHINDIRECT,
    EmfRecordTypeDeleteObject = EMR_DELETEOBJECT,
    EmfRecordTypeAngleArc = EMR_ANGLEARC,
    EmfRecordTypeEllipse = EMR_ELLIPSE,
    EmfRecordTypeRectangle = EMR_RECTANGLE,
    EmfRecordTypeRoundRect = EMR_ROUNDRECT,
    EmfRecordTypeArc = EMR_ARC,
    EmfRecordTypeChord = EMR_CHORD,
    EmfRecordTypePie = EMR_PIE,
    EmfRecordTypeSelectPalette = EMR_SELECTPALETTE,
    EmfRecordTypeCreatePalette = EMR_CREATEPALETTE,
    EmfRecordTypeSetPaletteEntries = EMR_SETPALETTEENTRIES,
    EmfRecordTypeResizePalette = EMR_RESIZEPALETTE,
    EmfRecordTypeRealizePalette = EMR_REALIZEPALETTE,
    EmfRecordTypeExtFloodFill = EMR_EXTFLOODFILL,
    EmfRecordTypeLineTo = EMR_LINETO,
    EmfRecordTypeArcTo = EMR_ARCTO,
    EmfRecordTypePolyDraw = EMR_POLYDRAW,
    EmfRecordTypeSetArcDirection = EMR_SETARCDIRECTION,
    EmfRecordTypeSetMiterLimit = EMR_SETMITERLIMIT,
    EmfRecordTypeBeginPath = EMR_BEGINPATH,
    EmfRecordTypeEndPath = EMR_ENDPATH,
    EmfRecordTypeCloseFigure = EMR_CLOSEFIGURE,
    EmfRecordTypeFillPath = EMR_FILLPATH,
    EmfRecordTypeStrokeAndFillPath = EMR_STROKEANDFILLPATH,
    EmfRecordTypeStrokePath = EMR_STROKEPATH,
    EmfRecordTypeFlattenPath = EMR_FLATTENPATH,
    EmfRecordTypeWidenPath = EMR_WIDENPATH,
    EmfRecordTypeSelectClipPath = EMR_SELECTCLIPPATH,
    EmfRecordTypeAbortPath = EMR_ABORTPATH,
    EmfRecordTypeReserved_069 = 69,  // Not Used
    EmfRecordTypeGdiComment = EMR_GDICOMMENT,
    EmfRecordTypeFillRgn = EMR_FILLRGN,
    EmfRecordTypeFrameRgn = EMR_FRAMERGN,
    EmfRecordTypeInvertRgn = EMR_INVERTRGN,
    EmfRecordTypePaintRgn = EMR_PAINTRGN,
    EmfRecordTypeExtSelectClipRgn = EMR_EXTSELECTCLIPRGN,
    EmfRecordTypeBitBlt = EMR_BITBLT,
    EmfRecordTypeStretchBlt = EMR_STRETCHBLT,
    EmfRecordTypeMaskBlt = EMR_MASKBLT,
    EmfRecordTypePlgBlt = EMR_PLGBLT,
    EmfRecordTypeSetDIBitsToDevice = EMR_SETDIBITSTODEVICE,
    EmfRecordTypeStretchDIBits = EMR_STRETCHDIBITS,
    EmfRecordTypeExtCreateFontIndirect = EMR_EXTCREATEFONTINDIRECTW,
    EmfRecordTypeExtTextOutA = EMR_EXTTEXTOUTA,
    EmfRecordTypeExtTextOutW = EMR_EXTTEXTOUTW,
    EmfRecordTypePolyBezier16 = EMR_POLYBEZIER16,
    EmfRecordTypePolygon16 = EMR_POLYGON16,
    EmfRecordTypePolyline16 = EMR_POLYLINE16,
    EmfRecordTypePolyBezierTo16 = EMR_POLYBEZIERTO16,
    EmfRecordTypePolylineTo16 = EMR_POLYLINETO16,
    EmfRecordTypePolyPolyline16 = EMR_POLYPOLYLINE16,
    EmfRecordTypePolyPolygon16 = EMR_POLYPOLYGON16,
    EmfRecordTypePolyDraw16 = EMR_POLYDRAW16,
    EmfRecordTypeCreateMonoBrush = EMR_CREATEMONOBRUSH,
    EmfRecordTypeCreateDIBPatternBrushPt = EMR_CREATEDIBPATTERNBRUSHPT,
    EmfRecordTypeExtCreatePen = EMR_EXTCREATEPEN,
    EmfRecordTypePolyTextOutA = EMR_POLYTEXTOUTA,
    EmfRecordTypePolyTextOutW = EMR_POLYTEXTOUTW,
    EmfRecordTypeSetICMMode = 98,  // EMR_SETICMMODE,
    EmfRecordTypeCreateColorSpace = 99,  // EMR_CREATECOLORSPACE,
    EmfRecordTypeSetColorSpace = 100, // EMR_SETCOLORSPACE,
    EmfRecordTypeDeleteColorSpace = 101, // EMR_DELETECOLORSPACE,
    EmfRecordTypeGLSRecord = 102, // EMR_GLSRECORD,
    EmfRecordTypeGLSBoundedRecord = 103, // EMR_GLSBOUNDEDRECORD,
    EmfRecordTypePixelFormat = 104, // EMR_PIXELFORMAT,
    EmfRecordTypeDrawEscape = 105, // EMR_RESERVED_105,
    EmfRecordTypeExtEscape = 106, // EMR_RESERVED_106,
    EmfRecordTypeStartDoc = 107, // EMR_RESERVED_107,
    EmfRecordTypeSmallTextOut = 108, // EMR_RESERVED_108,
    EmfRecordTypeForceUFIMapping = 109, // EMR_RESERVED_109,
    EmfRecordTypeNamedEscape = 110, // EMR_RESERVED_110,
    EmfRecordTypeColorCorrectPalette = 111, // EMR_COLORCORRECTPALETTE,
    EmfRecordTypeSetICMProfileA = 112, // EMR_SETICMPROFILEA,
    EmfRecordTypeSetICMProfileW = 113, // EMR_SETICMPROFILEW,
    EmfRecordTypeAlphaBlend = 114, // EMR_ALPHABLEND,
    EmfRecordTypeSetLayout = 115, // EMR_SETLAYOUT,
    EmfRecordTypeTransparentBlt = 116, // EMR_TRANSPARENTBLT,
    EmfRecordTypeReserved_117 = 117, // Not Used
    EmfRecordTypeGradientFill = 118, // EMR_GRADIENTFILL,
    EmfRecordTypeSetLinkedUFIs = 119, // EMR_RESERVED_119,
    EmfRecordTypeSetTextJustification = 120, // EMR_RESERVED_120,
    EmfRecordTypeColorMatchToTargetW = 121, // EMR_COLORMATCHTOTARGETW,
    EmfRecordTypeCreateColorSpaceW = 122, // EMR_CREATECOLORSPACEW,
    EmfRecordTypeMax = 122,
    EmfRecordTypeMin = 1,

    // That is the END of the GDI EMF records.

    // Now we start the list of EMF+ records.  We leave quite
    // a bit of room here for the addition of any new GDI
    // records that may be added later.

    EmfPlusRecordTypeInvalid = GDIP_EMFPLUS_RECORD_BASE,
    EmfPlusRecordTypeHeader,
    EmfPlusRecordTypeEndOfFile,

    EmfPlusRecordTypeComment,

    EmfPlusRecordTypeGetDC,

    EmfPlusRecordTypeMultiFormatStart,
    EmfPlusRecordTypeMultiFormatSection,
    EmfPlusRecordTypeMultiFormatEnd,

    // For all persistent objects

    EmfPlusRecordTypeObject,

    // Drawing Records

    EmfPlusRecordTypeClear,
    EmfPlusRecordTypeFillRects,
    EmfPlusRecordTypeDrawRects,
    EmfPlusRecordTypeFillPolygon,
    EmfPlusRecordTypeDrawLines,
    EmfPlusRecordTypeFillEllipse,
    EmfPlusRecordTypeDrawEllipse,
    EmfPlusRecordTypeFillPie,
    EmfPlusRecordTypeDrawPie,
    EmfPlusRecordTypeDrawArc,
    EmfPlusRecordTypeFillRegion,
    EmfPlusRecordTypeFillPath,
    EmfPlusRecordTypeDrawPath,
    EmfPlusRecordTypeFillClosedCurve,
    EmfPlusRecordTypeDrawClosedCurve,
    EmfPlusRecordTypeDrawCurve,
    EmfPlusRecordTypeDrawBeziers,
    EmfPlusRecordTypeDrawImage,
    EmfPlusRecordTypeDrawImagePoints,
    EmfPlusRecordTypeDrawString,

    // Graphics State Records

    EmfPlusRecordTypeSetRenderingOrigin,
    EmfPlusRecordTypeSetAntiAliasMode,
    EmfPlusRecordTypeSetTextRenderingHint,
    EmfPlusRecordTypeSetTextContrast,
    EmfPlusRecordTypeSetInterpolationMode,
    EmfPlusRecordTypeSetPixelOffsetMode,
    EmfPlusRecordTypeSetCompositingMode,
    EmfPlusRecordTypeSetCompositingQuality,
    EmfPlusRecordTypeSave,
    EmfPlusRecordTypeRestore,
    EmfPlusRecordTypeBeginContainer,
    EmfPlusRecordTypeBeginContainerNoParams,
    EmfPlusRecordTypeEndContainer,
    EmfPlusRecordTypeSetWorldTransform,
    EmfPlusRecordTypeResetWorldTransform,
    EmfPlusRecordTypeMultiplyWorldTransform,
    EmfPlusRecordTypeTranslateWorldTransform,
    EmfPlusRecordTypeScaleWorldTransform,
    EmfPlusRecordTypeRotateWorldTransform,
    EmfPlusRecordTypeSetPageTransform,
    EmfPlusRecordTypeResetClip,
    EmfPlusRecordTypeSetClipRect,
    EmfPlusRecordTypeSetClipPath,
    EmfPlusRecordTypeSetClipRegion,
    EmfPlusRecordTypeOffsetClip,

    EmfPlusRecordTypeDrawDriverString,
#if (GDIPVER >= 0x0110)
    EmfPlusRecordTypeStrokeFillPath,
    EmfPlusRecordTypeSerializableObject,

    EmfPlusRecordTypeSetTSGraphics,
    EmfPlusRecordTypeSetTSClip,
#endif
    // NOTE: New records *must* be added immediately before this line.

    EmfPlusRecordTotal,

    EmfPlusRecordTypeMax = EmfPlusRecordTotal - 1,
    EmfPlusRecordTypeMin = EmfPlusRecordTypeHeader,
};

//---------------------------------------------------------------------------
// StringFormatFlags
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// String format flags
//
//  DirectionRightToLeft          - For horizontal text, the reading order is
//                                  right to left. This value is called
//                                  the base embedding level by the Unicode
//                                  bidirectional engine.
//                                  For vertical text, columns are read from
//                                  right to left.
//                                  By default, horizontal or vertical text is
//                                  read from left to right.
//
//  DirectionVertical             - Individual lines of text are vertical. In
//                                  each line, characters progress from top to
//                                  bottom.
//                                  By default, lines of text are horizontal,
//                                  each new line below the previous line.
//
//  NoFitBlackBox                 - Allows parts of glyphs to overhang the
//                                  bounding rectangle.
//                                  By default glyphs are first aligned
//                                  inside the margines, then any glyphs which
//                                  still overhang the bounding box are
//                                  repositioned to avoid any overhang.
//                                  For example when an italic
//                                  lower case letter f in a font such as
//                                  Garamond is aligned at the far left of a
//                                  rectangle, the lower part of the f will
//                                  reach slightly further left than the left
//                                  edge of the rectangle. Setting this flag
//                                  will ensure the character aligns visually
//                                  with the lines above and below, but may
//                                  cause some pixels outside the formatting
//                                  rectangle to be clipped or painted.
//
//  DisplayFormatControl          - Causes control characters such as the
//                                  left-to-right mark to be shown in the
//                                  output with a representative glyph.
//
//  NoFontFallback                - Disables fallback to alternate fonts for
//                                  characters not supported in the requested
//                                  font. Any missing characters will be
//                                  be displayed with the fonts missing glyph,
//                                  usually an open square.
//
//  NoWrap                        - Disables wrapping of text between lines
//                                  when formatting within a rectangle.
//                                  NoWrap is implied when a point is passed
//                                  instead of a rectangle, or when the
//                                  specified rectangle has a zero line length.
//
//  NoClip                        - By default text is clipped to the
//                                  formatting rectangle. Setting NoClip
//                                  allows overhanging pixels to affect the
//                                  device outside the formatting rectangle.
//                                  Pixels at the end of the line may be
//                                  affected if the glyphs overhang their
//                                  cells, and either the NoFitBlackBox flag
//                                  has been set, or the glyph extends to far
//                                  to be fitted.
//                                  Pixels above/before the first line or
//                                  below/after the last line may be affected
//                                  if the glyphs extend beyond their cell
//                                  ascent / descent. This can occur rarely
//                                  with unusual diacritic mark combinations.

//---------------------------------------------------------------------------

typedef enum StringFormatFlags
{
    StringFormatFlagsDirectionRightToLeft = 0x00000001,
    StringFormatFlagsDirectionVertical = 0x00000002,
    StringFormatFlagsNoFitBlackBox = 0x00000004,
    StringFormatFlagsDisplayFormatControl = 0x00000020,
    StringFormatFlagsNoFontFallback = 0x00000400,
    StringFormatFlagsMeasureTrailingSpaces = 0x00000800,
    StringFormatFlagsNoWrap = 0x00001000,
    StringFormatFlagsLineLimit = 0x00002000,

    StringFormatFlagsNoClip = 0x00004000,
    StringFormatFlagsBypassGDI = 0x80000000
} StringFormatFlags;

//---------------------------------------------------------------------------
// StringTrimming
//---------------------------------------------------------------------------

typedef enum StringTrimming {
    StringTrimmingNone = 0,
    StringTrimmingCharacter = 1,
    StringTrimmingWord = 2,
    StringTrimmingEllipsisCharacter = 3,
    StringTrimmingEllipsisWord = 4,
    StringTrimmingEllipsisPath = 5
} StringTrimming;

//---------------------------------------------------------------------------
// National language digit substitution
//---------------------------------------------------------------------------

typedef enum StringDigitSubstitute
{
    StringDigitSubstituteUser = 0,  // As NLS setting
    StringDigitSubstituteNone = 1,
    StringDigitSubstituteNational = 2,
    StringDigitSubstituteTraditional = 3
} StringDigitSubstitute;

//---------------------------------------------------------------------------
// Hotkey prefix interpretation
//---------------------------------------------------------------------------

typedef enum HotkeyPrefix
{
    HotkeyPrefixNone = 0,
    HotkeyPrefixShow = 1,
    HotkeyPrefixHide = 2
} HotkeyPrefix;

//---------------------------------------------------------------------------
// String alignment flags
//---------------------------------------------------------------------------

typedef enum StringAlignment
{
    // Left edge for left-to-right text,
    // right for right-to-left text,
    // and top for vertical
    StringAlignmentNear = 0,
    StringAlignmentCenter = 1,
    StringAlignmentFar = 2
} StringAlignment;

//---------------------------------------------------------------------------
// DriverStringOptions
//---------------------------------------------------------------------------

typedef enum DriverStringOptions
{
    DriverStringOptionsCmapLookup = 1,
    DriverStringOptionsVertical = 2,
    DriverStringOptionsRealizedAdvance = 4,
    DriverStringOptionsLimitSubpixel = 8
} DriverStringOptions;

//---------------------------------------------------------------------------
// Flush Intention flags
//---------------------------------------------------------------------------

typedef enum FlushIntention
{
    FlushIntentionFlush = 0,        // Flush all batched rendering operations
    FlushIntentionSync = 1          // Flush all batched rendering operations
                                    // and wait for them to complete
} FlushIntention;

//---------------------------------------------------------------------------
// Image encoder parameter related types
//---------------------------------------------------------------------------

typedef enum EncoderParameterValueType
{
    EncoderParameterValueTypeByte = 1,    // 8-bit unsigned int
    EncoderParameterValueTypeASCII = 2,    // 8-bit byte containing one 7-bit ASCII
                                           // code. NULL terminated.
                                           EncoderParameterValueTypeShort = 3,    // 16-bit unsigned int
                                           EncoderParameterValueTypeLong = 4,    // 32-bit unsigned int
                                           EncoderParameterValueTypeRational = 5,    // Two Longs. The first Long is the
                                                                                     // numerator, the second Long expresses the
                                                                                     // denomintor.
                                                                                     EncoderParameterValueTypeLongRange = 6,    // Two longs which specify a range of
                                                                                                                                // integer values. The first Long specifies
                                                                                                                                // the lower end and the second one
                                                                                                                                // specifies the higher end. All values
                                                                                                                                // are inclusive at both ends
                                                                                                                                EncoderParameterValueTypeUndefined = 7,    // 8-bit byte that can take any value
                                                                                                                                                                           // depending on field definition
                                                                                                                                                                           EncoderParameterValueTypeRationalRange = 8,    // Two Rationals. The first Rational
                                                                                                                                                                                                                          // specifies the lower end and the second
                                                                                                                                                                                                                          // specifies the higher end. All values
                                                                                                                                                                                                                          // are inclusive at both ends
#if (GDIPVER >= 0x0110)
                                                                                                                                                                                                                          EncoderParameterValueTypePointer = 9     // a pointer to a parameter defined data.
#endif //(GDIPVER >= 0x0110)
} EncoderParameterValueType;

//---------------------------------------------------------------------------
// Image encoder value types
//---------------------------------------------------------------------------

typedef enum EncoderValue
{
    EncoderValueColorTypeCMYK,
    EncoderValueColorTypeYCCK,
    EncoderValueCompressionLZW,
    EncoderValueCompressionCCITT3,
    EncoderValueCompressionCCITT4,
    EncoderValueCompressionRle,
    EncoderValueCompressionNone,
    EncoderValueScanMethodInterlaced,
    EncoderValueScanMethodNonInterlaced,
    EncoderValueVersionGif87,
    EncoderValueVersionGif89,
    EncoderValueRenderProgressive,
    EncoderValueRenderNonProgressive,
    EncoderValueTransformRotate90,
    EncoderValueTransformRotate180,
    EncoderValueTransformRotate270,
    EncoderValueTransformFlipHorizontal,
    EncoderValueTransformFlipVertical,
    EncoderValueMultiFrame,
    EncoderValueLastFrame,
    EncoderValueFlush,
    EncoderValueFrameDimensionTime,
    EncoderValueFrameDimensionResolution,
    EncoderValueFrameDimensionPage,
#if (GDIPVER >= 0x0110)
    EncoderValueColorTypeGray,
    EncoderValueColorTypeRGB,
#endif
} EncoderValue;

//---------------------------------------------------------------------------
// Conversion of Emf To WMF Bits flags
//---------------------------------------------------------------------------

typedef enum EmfToWmfBitsFlags
{
    EmfToWmfBitsFlagsDefault = 0x00000000,
    EmfToWmfBitsFlagsEmbedEmf = 0x00000001,
    EmfToWmfBitsFlagsIncludePlaceable = 0x00000002,
    EmfToWmfBitsFlagsNoXORClip = 0x00000004
} EmfToWmfBitsFlags;

#if (GDIPVER >= 0x0110)
//---------------------------------------------------------------------------
// Conversion of Emf To Emf+ Bits flags
//---------------------------------------------------------------------------

enum ConvertToEmfPlusFlags
{
    ConvertToEmfPlusFlagsDefault = 0x00000000,
    ConvertToEmfPlusFlagsRopUsed = 0x00000001,
    ConvertToEmfPlusFlagsText = 0x00000002,
    ConvertToEmfPlusFlagsInvalidRecord = 0x00000004
};
#endif


//---------------------------------------------------------------------------
// Test Control flags
//---------------------------------------------------------------------------

typedef enum GpTestControlEnum
{
    TestControlForceBilinear = 0,
    TestControlNoICM = 1,
    TestControlGetBuildNumber = 2
} GpTestControlEnum;

#pragma endregion

#pragma region GdiplusTypes.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusTypes.h
*
* Abstract:
*
*   GDI+ Types
*
\**************************************************************************/

//--------------------------------------------------------------------------
// Callback functions
//--------------------------------------------------------------------------

    typedef BOOL(CALLBACK * ImageAbort)(VOID *);
    typedef ImageAbort DrawImageAbort;
    typedef ImageAbort GetThumbnailImageAbort;

// Callback for EnumerateMetafile methods.  The parameters are:

//      recordType      WMF, EMF, or EMF+ record type
//      flags           (always 0 for WMF/EMF records)
//      dataSize        size of the record data (in bytes), or 0 if no data
//      data            pointer to the record data, or NULL if no data
//      callbackData    pointer to callbackData, if any

// This method can then call Metafile::PlayRecord to play the
// record that was just enumerated.  If this method  returns
// FALSE, the enumeration process is aborted.  Otherwise, it continues.

    typedef BOOL(CALLBACK * EnumerateMetafileProc)(EmfPlusRecordType, UINT, UINT, const BYTE*, VOID*);

//--------------------------------------------------------------------------
// Primitive data types
//
// NOTE:
//  Types already defined in standard header files:
//      INT8
//      UINT8
//      INT16
//      UINT16
//      INT32
//      UINT32
//      INT64
//      UINT64
//
//  Avoid using the following types:
//      LONG - use INT
//      ULONG - use UINT
//      DWORD - use UINT32
//--------------------------------------------------------------------------

typedef float REAL;

#define REAL_MAX            FLT_MAX
#define REAL_MIN            FLT_MIN
#define REAL_TOLERANCE     (FLT_MIN * 100)
#define REAL_EPSILON        1.192092896e-07F        /* FLT_EPSILON */

//--------------------------------------------------------------------------
// Forward declarations of common structures
//--------------------------------------------------------------------------

typedef struct Size Size;
typedef struct SizeF SizeF;
typedef struct Point Point;
typedef struct PointF PointF;
typedef struct Rect Rect;
typedef struct RectF RectF;
typedef struct CharacterRange CharacterRange;

//--------------------------------------------------------------------------
// Status return values from GDI+ methods
//--------------------------------------------------------------------------

typedef _Return_type_success_(return == 0) enum Status
{
    Ok = 0,
    GenericError = 1,
    InvalidParameter = 2,
    OutOfMemory = 3,
    ObjectBusy = 4,
    InsufficientBuffer = 5,
    NotImplemented = 6,
    Win32Error = 7,
    WrongState = 8,
    Aborted = 9,
    FileNotFound = 10,
    ValueOverflow = 11,
    AccessDenied = 12,
    UnknownImageFormat = 13,
    FontFamilyNotFound = 14,
    FontStyleNotFound = 15,
    NotTrueTypeFont = 16,
    UnsupportedGdiplusVersion = 17,
    GdiplusNotInitialized = 18,
    PropertyNotFound = 19,
    PropertyNotSupported = 20,
#if (GDIPVER >= 0x0110)
    ProfileNotFound = 21,
#endif //(GDIPVER >= 0x0110)
} Status;


    //--------------------------------------------------------------------------
    // Represents a dimension in a 2D coordinate system (floating-point coordinates)
    //--------------------------------------------------------------------------

    struct SizeF
    {
        REAL Width;
        REAL Height;
    };

    BOOL WINAPI SizeF_Equals(IN const SizeF* sz1, IN const SizeF* sz2);

    BOOL WINAPI SizeF_Empty(IN const SizeF* sz);

    //--------------------------------------------------------------------------
    // Represents a dimension in a 2D coordinate system (integer coordinates)
    //--------------------------------------------------------------------------

    struct Size
    {
        INT Width;
        INT Height;
    };

    BOOL WINAPI Size_Equals(IN const Size* sz1, IN const Size* sz2);

    BOOL WINAPI Size_Empty(IN const Size* sz);

    //--------------------------------------------------------------------------
    // Represents a location in a 2D coordinate system (floating-point coordinates)
    //--------------------------------------------------------------------------

    struct PointF
    {
        REAL X;
        REAL Y;
    };

    BOOL WINAPI PointF_Equals(IN const PointF* point1, IN const PointF* point2);

    //--------------------------------------------------------------------------
    // Represents a location in a 2D coordinate system (integer coordinates)
    //--------------------------------------------------------------------------

    struct Point
    {
        INT X;
        INT Y;
    };

    BOOL WINAPI Point_Equals(IN const Point* point1, IN const Point* point2);

    //--------------------------------------------------------------------------
    // Represents a rectangle in a 2D coordinate system (floating-point coordinates)
    //--------------------------------------------------------------------------

    struct RectF
    {
        REAL X;
        REAL Y;
        REAL Width;
        REAL Height;
    };

    VOID WINAPI RectF_GetLocation(IN const RectF* rect, OUT PointF* point);

    VOID WINAPI RectF_GetSize(IN const RectF* rect, OUT SizeF* size);

    VOID WINAPI RectF_GetBounds(IN const RectF* rect, OUT RectF* destRect);

    REAL WINAPI RectF_GetLeft(IN const RectF* rect);

    REAL WINAPI RectF_GetTop(IN const RectF* rect);

    REAL WINAPI RectF_GetRight(IN const RectF* rect);

    REAL WINAPI RectF_GetBottom(IN const RectF* rect);

    BOOL WINAPI RectF_IsEmptyArea(IN const RectF* rect);

    BOOL WINAPI RectF_Equals(IN const RectF* rect1, IN const RectF* rect2);

    BOOL WINAPI RectF_Contains(IN const RectF* rect,
                               IN REAL x,
                               IN REAL y);

    VOID WINAPI RectF_Inflate(OUT RectF* rect,
                              IN REAL dx,
                              IN REAL dy);

    BOOL WINAPI RectF_Intersect(OUT RectF* c,
                                IN const RectF* a,
                                IN const RectF* b);

    BOOL WINAPI RectF_IntersectsWith(IN const RectF* rect1, IN const RectF* rect2);

    BOOL WINAPI RectF_Union(OUT RectF* c,
                            IN const RectF* a,
                            IN const RectF* b);

    VOID WINAPI RectF_Offset(OUT RectF* rect,
                             IN REAL dx,
                             IN REAL dy);
    //--------------------------------------------------------------------------
    // Represents a rectangle in a 2D coordinate system (integer coordinates)
    //--------------------------------------------------------------------------

    struct Rect
    {
        INT X;
        INT Y;
        INT Width;
        INT Height;
    };

    VOID WINAPI Rect_GetLocation(IN const Rect* rect, OUT Point* point);

    VOID WINAPI Rect_GetSize(IN const Rect* rect, OUT Size* size);

    VOID WINAPI Rect_GetBounds(IN const Rect* rect, OUT Rect* destRect);

    INT WINAPI Rect_GetLeft(IN const Rect* rect);

    INT WINAPI Rect_GetTop(IN const Rect* rect);

    INT WINAPI Rect_GetRight(IN const Rect* rect);

    INT WINAPI Rect_GetBottom(IN const Rect* rect);

    BOOL WINAPI Rect_IsEmptyArea(IN const Rect* rect);

    BOOL WINAPI Rect_Equals(IN const Rect* rect1, IN const Rect* rect2);

    BOOL WINAPI Rect_Contains(IN const Rect* rect,
                              IN INT x,
                              IN INT y);

    VOID WINAPI Rect_Inflate(OUT Rect* rect,
                             IN INT dx,
                             IN INT dy);

    BOOL WINAPI Rect_Intersect(OUT Rect* c,
                               IN const Rect* a,
                               IN const Rect* b);

    BOOL WINAPI Rect_IntersectsWith(IN const Rect* rect1, IN const Rect* rect2);

    BOOL WINAPI Rect_Union(OUT Rect* c,
                           IN const Rect* a,
                           IN const Rect* b);

    VOID WINAPI Rect_Offset(OUT Rect* rect,
                            IN INT dx,
                            IN INT dy);

    typedef
        struct PathData
    {
        INT Count;
        PointF* Points;
        _Field_size_opt_(Count) BYTE* Types;
    } PathData;

    VOID WINAPI PathData_Destroy(IN PathData* pathData);

    struct CharacterRange
    {
        INT First;
        INT Length;
    };

#pragma endregion 

#pragma region GdiplusInit.h
/**************************************************************************
*
* Copyright (c) 2000-2003 Microsoft Corporation
*
* Module Name:
*
*   Gdiplus initialization
*
* Abstract:
*
*   GDI+ Startup and Shutdown APIs
*
**************************************************************************/

typedef enum DebugEventLevel
{
    DebugEventLevelFatal,
    DebugEventLevelWarning
} DebugEventLevel;

// Callback function that GDI+ can call, on debug builds, for assertions
// and warnings.

typedef VOID(WINAPI *DebugEventProc)(DebugEventLevel level, CHAR *message);

// Notification functions which the user must call appropriately if
// "SuppressBackgroundThread" (below) is set.

typedef Status(WINAPI *NotificationHookProc)(OUT ULONG_PTR *token);
typedef VOID(WINAPI *NotificationUnhookProc)(ULONG_PTR token);

// Input structure for GdiplusStartup()

typedef struct GdiplusStartupInput
{
    UINT32 GdiplusVersion;             // Must be 1  (or 2 for the Ex version)
    DebugEventProc DebugEventCallback; // Ignored on free builds
    BOOL SuppressBackgroundThread;     // FALSE unless you're prepared to call 
                                       // the hook/unhook functions properly
    BOOL SuppressExternalCodecs;       // FALSE unless you want GDI+ only to use
                                       // its internal image codecs.
#ifdef __cplusplus
    GdiplusStartupInput(
        DebugEventProc debugEventCallback = NULL,
        BOOL suppressBackgroundThread = FALSE,
        BOOL suppressExternalCodecs = FALSE)
    {
        GdiplusVersion = 1;
        DebugEventCallback = debugEventCallback;
        SuppressBackgroundThread = suppressBackgroundThread;
        SuppressExternalCodecs = suppressExternalCodecs;
    }
#endif
} GdiplusStartupInput;

// Output structure for GdiplusStartup()

typedef struct GdiplusStartupOutput
{
    // The following 2 fields are NULL if SuppressBackgroundThread is FALSE.
    // Otherwise, they are functions which must be called appropriately to
    // replace the background thread.
    //
    // These should be called on the application's main message loop - i.e.
    // a message loop which is active for the lifetime of GDI+.
    // "NotificationHook" should be called before starting the loop,
    // and "NotificationUnhook" should be called after the loop ends.

    NotificationHookProc NotificationHook;
    NotificationUnhookProc NotificationUnhook;
} GdiplusStartupOutput;


    // GDI+ initialization. Must not be called from DllMain - can cause deadlock.
    //
    // Must be called before GDI+ API's or constructors are used.
    //
    // token  - may not be NULL - accepts a token to be passed in the corresponding
    //          GdiplusShutdown call.
    // input  - may not be NULL
    // output - may be NULL only if input->SuppressBackgroundThread is FALSE.

    Status WINAPI GdipluscStartup(
        OUT ULONG_PTR *token,
        const GdiplusStartupInput *input,
        OUT GdiplusStartupOutput *output);

    // GDI+ termination. Must be called before GDI+ is unloaded. 
    // Must not be called from DllMain - can cause deadlock.
    //
    // GDI+ API's may not be called after GdiplusShutdown. Pay careful attention
    // to GDI+ object destructors.

    VOID WINAPI GdipluscShutdown(ULONG_PTR token);

#pragma endregion

#pragma region GdiplusPixelFormats.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   Gdiplus Pixel Formats
*
* Abstract:
*
*   GDI+ Pixel Formats
*
\**************************************************************************/

typedef DWORD ARGB;
typedef DWORDLONG ARGB64;

#define ALPHA_SHIFT 24
#define RED_SHIFT   16
#define GREEN_SHIFT 8
#define BLUE_SHIFT  0
#define ALPHA_MASK  ((ARGB) 0xff << ALPHA_SHIFT)

// In-memory pixel data formats:
// bits 0-7 = format index
// bits 8-15 = pixel size (in bits)
// bits 16-23 = flags
// bits 24-31 = reserved

typedef INT PixelFormat;

#define    PixelFormatIndexed      0x00010000 // Indexes into a palette
#define    PixelFormatGDI          0x00020000 // Is a GDI-supported format
#define    PixelFormatAlpha        0x00040000 // Has an alpha component
#define    PixelFormatPAlpha       0x00080000 // Pre-multiplied alpha
#define    PixelFormatExtended     0x00100000 // Extended color 16 bits/channel
#define    PixelFormatCanonical    0x00200000 

#define    PixelFormatUndefined       0
#define    PixelFormatDontCare        0

#define    PixelFormat1bppIndexed     (1 | ( 1 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat4bppIndexed     (2 | ( 4 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat8bppIndexed     (3 | ( 8 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat16bppGrayScale  (4 | (16 << 8) | PixelFormatExtended)
#define    PixelFormat16bppRGB555     (5 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppRGB565     (6 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppARGB1555   (7 | (16 << 8) | PixelFormatAlpha | PixelFormatGDI)
#define    PixelFormat24bppRGB        (8 | (24 << 8) | PixelFormatGDI)
#define    PixelFormat32bppRGB        (9 | (32 << 8) | PixelFormatGDI)
#define    PixelFormat32bppARGB       (10 | (32 << 8) | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical)
#define    PixelFormat32bppPARGB      (11 | (32 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI)
#define    PixelFormat48bppRGB        (12 | (48 << 8) | PixelFormatExtended)
#define    PixelFormat64bppARGB       (13 | (64 << 8) | PixelFormatAlpha  | PixelFormatCanonical | PixelFormatExtended)
#define    PixelFormat64bppPARGB      (14 | (64 << 8) | PixelFormatAlpha  | PixelFormatPAlpha | PixelFormatExtended)
#define    PixelFormat32bppCMYK       (15 | (32 << 8))
#define    PixelFormatMax             16


    UINT WINAPI
        GetPixelFormatSize(PixelFormat pixfmt);

    BOOL WINAPI
        IsIndexedPixelFormat(PixelFormat pixfmt);

    BOOL WINAPI
        IsAlphaPixelFormat(PixelFormat pixfmt);

    BOOL WINAPI
        IsExtendedPixelFormat(PixelFormat pixfmt);

    //--------------------------------------------------------------------------
    // Determine if the Pixel Format is Canonical format:
    //   PixelFormat32bppARGB
    //   PixelFormat32bppPARGB
    //   PixelFormat64bppARGB
    //   PixelFormat64bppPARGB
    //--------------------------------------------------------------------------

    BOOL WINAPI
        IsCanonicalPixelFormat(PixelFormat pixfmt);

typedef enum PaletteFlags
{
    PaletteFlagsHasAlpha = 0x0001,
    PaletteFlagsGrayScale = 0x0002,
    PaletteFlagsHalftone = 0x0004
} PaletteFlags;

typedef struct ColorPalette
{
    UINT Flags;             // Palette flags
    UINT Count;             // Number of color entries
    ARGB Entries[1];        // Palette color entries
} ColorPalette;

#pragma endregion

#pragma region GdiplusColor.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusColor.h
*
* Abstract:
*
*   GDI+ Color Object
*
\**************************************************************************/

//----------------------------------------------------------------------------
// Color mode
//----------------------------------------------------------------------------

typedef enum ColorMode
{
    ColorModeARGB32 = 0,
    ColorModeARGB64 = 1
} ColorMode;

//----------------------------------------------------------------------------
// Color Channel flags
//----------------------------------------------------------------------------

typedef enum ColorChannelFlags
{
    ColorChannelFlagsC = 0,
    ColorChannelFlagsM,
    ColorChannelFlagsY,
    ColorChannelFlagsK,
    ColorChannelFlagsLast
} ColorChannelFlags;

//----------------------------------------------------------------------------
// Color
//----------------------------------------------------------------------------

// Common color constants

enum
{
    AliceBlue = 0xFFF0F8FF,
    AntiqueWhite = 0xFFFAEBD7,
    Aqua = 0xFF00FFFF,
    Aquamarine = 0xFF7FFFD4,
    Azure = 0xFFF0FFFF,
    Beige = 0xFFF5F5DC,
    Bisque = 0xFFFFE4C4,
    Black = 0xFF000000,
    BlanchedAlmond = 0xFFFFEBCD,
    Blue = 0xFF0000FF,
    BlueViolet = 0xFF8A2BE2,
    Brown = 0xFFA52A2A,
    BurlyWood = 0xFFDEB887,
    CadetBlue = 0xFF5F9EA0,
    Chartreuse = 0xFF7FFF00,
    Chocolate = 0xFFD2691E,
    Coral = 0xFFFF7F50,
    CornflowerBlue = 0xFF6495ED,
    Cornsilk = 0xFFFFF8DC,
    Crimson = 0xFFDC143C,
    Cyan = 0xFF00FFFF,
    DarkBlue = 0xFF00008B,
    DarkCyan = 0xFF008B8B,
    DarkGoldenrod = 0xFFB8860B,
    DarkGray = 0xFFA9A9A9,
    DarkGreen = 0xFF006400,
    DarkKhaki = 0xFFBDB76B,
    DarkMagenta = 0xFF8B008B,
    DarkOliveGreen = 0xFF556B2F,
    DarkOrange = 0xFFFF8C00,
    DarkOrchid = 0xFF9932CC,
    DarkRed = 0xFF8B0000,
    DarkSalmon = 0xFFE9967A,
    DarkSeaGreen = 0xFF8FBC8B,
    DarkSlateBlue = 0xFF483D8B,
    DarkSlateGray = 0xFF2F4F4F,
    DarkTurquoise = 0xFF00CED1,
    DarkViolet = 0xFF9400D3,
    DeepPink = 0xFFFF1493,
    DeepSkyBlue = 0xFF00BFFF,
    DimGray = 0xFF696969,
    DodgerBlue = 0xFF1E90FF,
    Firebrick = 0xFFB22222,
    FloralWhite = 0xFFFFFAF0,
    ForestGreen = 0xFF228B22,
    Fuchsia = 0xFFFF00FF,
    Gainsboro = 0xFFDCDCDC,
    GhostWhite = 0xFFF8F8FF,
    Gold = 0xFFFFD700,
    Goldenrod = 0xFFDAA520,
    Gray = 0xFF808080,
    Green = 0xFF008000,
    GreenYellow = 0xFFADFF2F,
    Honeydew = 0xFFF0FFF0,
    HotPink = 0xFFFF69B4,
    IndianRed = 0xFFCD5C5C,
    Indigo = 0xFF4B0082,
    Ivory = 0xFFFFFFF0,
    Khaki = 0xFFF0E68C,
    Lavender = 0xFFE6E6FA,
    LavenderBlush = 0xFFFFF0F5,
    LawnGreen = 0xFF7CFC00,
    LemonChiffon = 0xFFFFFACD,
    LightBlue = 0xFFADD8E6,
    LightCoral = 0xFFF08080,
    LightCyan = 0xFFE0FFFF,
    LightGoldenrodYellow = 0xFFFAFAD2,
    LightGray = 0xFFD3D3D3,
    LightGreen = 0xFF90EE90,
    LightPink = 0xFFFFB6C1,
    LightSalmon = 0xFFFFA07A,
    LightSeaGreen = 0xFF20B2AA,
    LightSkyBlue = 0xFF87CEFA,
    LightSlateGray = 0xFF778899,
    LightSteelBlue = 0xFFB0C4DE,
    LightYellow = 0xFFFFFFE0,
    Lime = 0xFF00FF00,
    LimeGreen = 0xFF32CD32,
    Linen = 0xFFFAF0E6,
    Magenta = 0xFFFF00FF,
    Maroon = 0xFF800000,
    MediumAquamarine = 0xFF66CDAA,
    MediumBlue = 0xFF0000CD,
    MediumOrchid = 0xFFBA55D3,
    MediumPurple = 0xFF9370DB,
    MediumSeaGreen = 0xFF3CB371,
    MediumSlateBlue = 0xFF7B68EE,
    MediumSpringGreen = 0xFF00FA9A,
    MediumTurquoise = 0xFF48D1CC,
    MediumVioletRed = 0xFFC71585,
    MidnightBlue = 0xFF191970,
    MintCream = 0xFFF5FFFA,
    MistyRose = 0xFFFFE4E1,
    Moccasin = 0xFFFFE4B5,
    NavajoWhite = 0xFFFFDEAD,
    Navy = 0xFF000080,
    OldLace = 0xFFFDF5E6,
    Olive = 0xFF808000,
    OliveDrab = 0xFF6B8E23,
    Orange = 0xFFFFA500,
    OrangeRed = 0xFFFF4500,
    Orchid = 0xFFDA70D6,
    PaleGoldenrod = 0xFFEEE8AA,
    PaleGreen = 0xFF98FB98,
    PaleTurquoise = 0xFFAFEEEE,
    PaleVioletRed = 0xFFDB7093,
    PapayaWhip = 0xFFFFEFD5,
    PeachPuff = 0xFFFFDAB9,
    Peru = 0xFFCD853F,
    Pink = 0xFFFFC0CB,
    Plum = 0xFFDDA0DD,
    PowderBlue = 0xFFB0E0E6,
    Purple = 0xFF800080,
    Red = 0xFFFF0000,
    RosyBrown = 0xFFBC8F8F,
    RoyalBlue = 0xFF4169E1,
    SaddleBrown = 0xFF8B4513,
    Salmon = 0xFFFA8072,
    SandyBrown = 0xFFF4A460,
    SeaGreen = 0xFF2E8B57,
    SeaShell = 0xFFFFF5EE,
    Sienna = 0xFFA0522D,
    Silver = 0xFFC0C0C0,
    SkyBlue = 0xFF87CEEB,
    SlateBlue = 0xFF6A5ACD,
    SlateGray = 0xFF708090,
    Snow = 0xFFFFFAFA,
    SpringGreen = 0xFF00FF7F,
    SteelBlue = 0xFF4682B4,
    Tan = 0xFFD2B48C,
    Teal = 0xFF008080,
    Thistle = 0xFFD8BFD8,
    Tomato = 0xFFFF6347,
    Transparent = 0x00FFFFFF,
    Turquoise = 0xFF40E0D0,
    Violet = 0xFFEE82EE,
    Wheat = 0xFFF5DEB3,
    White = 0xFFFFFFFF,
    WhiteSmoke = 0xFFF5F5F5,
    Yellow = 0xFFFFFF00,
    YellowGreen = 0xFF9ACD32
};

// Shift count and bit mask for A, R, G, B components

enum
{
    AlphaShift = 24,
    RedShift = 16,
    GreenShift = 8,
    BlueShift = 0
};

enum
{
    AlphaMask = 0xff000000,
    RedMask = 0x00ff0000,
    GreenMask = 0x0000ff00,
    BlueMask = 0x000000ff
};

typedef ARGB Color;

#define Color_GetAlpha(color) ((BYTE)(color >> AlphaShift))

#define Color_GetA(color) Color_GetAlpha(color)

#define Color_GetRed(color) ((BYTE)(color >> RedShift))

#define Color_GetR(color) Color_GetRed(color)

#define Color_GetGreen(color) ((BYTE)(color >> GreenShift))

#define Color_GetG(color) Color_GetGreen(color)

#define Color_GetBlue(color) ((BYTE)(color >> BlueShift))

#define Color_GetB(color) Color_GetBlue(color)

#define Color_GetValue(color) ((ARGB)color)

VOID WINAPI Color_SetValue(OUT Color * color, IN ARGB argb);

VOID WINAPI Color_SetFromCOLORREF(OUT Color * color, IN COLORREF rgb);

COLORREF WINAPI Color_ToCOLORREF(IN Color color);

// Assemble A, R, G, B values into a 32-bit integer

#define ARGB(a, r, g, b) ((Color)Color_MakeARGB(a, r, g, b))

ARGB WINAPI Color_MakeARGB(IN BYTE a,
                           IN BYTE r,
                           IN BYTE g,
                           IN BYTE b);

#pragma endregion

#pragma region GdiplusMetaHeader.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   Metafile headers
*
* Abstract:
*
*   GDI+ Metafile Related Structures
*
\**************************************************************************/

typedef struct
{
    DWORD   iType;              // Record type EMR_HEADER
    DWORD   nSize;              // Record size in bytes.  This may be greater
                                // than the sizeof(ENHMETAHEADER).
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    RECTL   rclFrame;           // Inclusive-inclusive Picture Frame .01mm unit
    DWORD   dSignature;         // Signature.  Must be ENHMETA_SIGNATURE.
    DWORD   nVersion;           // Version number
    DWORD   nBytes;             // Size of the metafile in bytes
    DWORD   nRecords;           // Number of records in the metafile
    WORD    nHandles;           // Number of handles in the handle table
                                // Handle index zero is reserved.
    WORD    sReserved;          // Reserved.  Must be zero.
    DWORD   nDescription;       // Number of chars in the unicode desc string
                                // This is 0 if there is no description string
    DWORD   offDescription;     // Offset to the metafile description record.
                                // This is 0 if there is no description string
    DWORD   nPalEntries;        // Number of entries in the metafile palette.
    SIZEL   szlDevice;          // Size of the reference device in pels
    SIZEL   szlMillimeters;     // Size of the reference device in millimeters
} ENHMETAHEADER3;

// Placeable WMFs

// Placeable Metafiles were created as a non-standard way of specifying how 
// a metafile is mapped and scaled on an output device.
// Placeable metafiles are quite wide-spread, but not directly supported by
// the Windows API. To playback a placeable metafile using the Windows API,
// you will first need to strip the placeable metafile header from the file.
// This is typically performed by copying the metafile to a temporary file
// starting at file offset 22 (0x16). The contents of the temporary file may
// then be used as input to the Windows GetMetaFile(), PlayMetaFile(),
// CopyMetaFile(), etc. GDI functions.

// Each placeable metafile begins with a 22-byte header,
//  followed by a standard metafile:

typedef struct
{
    INT16           Left;
    INT16           Top;
    INT16           Right;
    INT16           Bottom;
} PWMFRect16;

typedef struct
{
    UINT32          Key;            // GDIP_WMF_PLACEABLEKEY
    INT16           Hmf;            // Metafile HANDLE number (always 0)
    PWMFRect16      BoundingBox;    // Coordinates in metafile units
    INT16           Inch;           // Number of metafile units per inch
    UINT32          Reserved;       // Reserved (always 0)
    INT16           Checksum;       // Checksum value for previous 10 WORDs
} WmfPlaceableFileHeader;

// Key contains a special identification value that indicates the presence
// of a placeable metafile header and is always 0x9AC6CDD7.

// Handle is used to stored the handle of the metafile in memory. When written
// to disk, this field is not used and will always contains the value 0.

// Left, Top, Right, and Bottom contain the coordinates of the upper-left
// and lower-right corners of the image on the output device. These are
// measured in twips.

// A twip (meaning "twentieth of a point") is the logical unit of measurement
// used in Windows Metafiles. A twip is equal to 1/1440 of an inch. Thus 720
// twips equal 1/2 inch, while 32,768 twips is 22.75 inches.

// Inch contains the number of twips per inch used to represent the image.
// Normally, there are 1440 twips per inch; however, this number may be
// changed to scale the image. A value of 720 indicates that the image is
// double its normal size, or scaled to a factor of 2:1. A value of 360
// indicates a scale of 4:1, while a value of 2880 indicates that the image
// is scaled down in size by a factor of two. A value of 1440 indicates
// a 1:1 scale ratio.

// Reserved is not used and is always set to 0.

// Checksum contains a checksum value for the previous 10 WORDs in the header.
// This value can be used in an attempt to detect if the metafile has become
// corrupted. The checksum is calculated by XORing each WORD value to an
// initial value of 0.

// If the metafile was recorded with a reference Hdc that was a display.

#define GDIP_EMFPLUSFLAGS_DISPLAY       0x00000001

typedef struct MetafileHeader
{
    MetafileType        Type;
    UINT                Size;               // Size of the metafile (in bytes)
    UINT                Version;            // EMF+, EMF, or WMF version
    UINT                EmfPlusFlags;
    REAL                DpiX;
    REAL                DpiY;
    INT                 X;                  // Bounds in device units
    INT                 Y;
    INT                 Width;
    INT                 Height;
    union
    {
        METAHEADER      WmfHeader;
        ENHMETAHEADER3  EmfHeader;
    };
    INT                 EmfPlusHeaderSize;  // size of the EMF+ header in file
    INT                 LogicalDpiX;        // Logical Dpi of reference Hdc
    INT                 LogicalDpiY;        // usually valid only for EMF+
} MetafileHeader;

MetafileType WINAPI MetafileHeader_GetType(IN const MetafileHeader * mfh);

UINT WINAPI MetafileHeader_GetMetafileSize(IN const MetafileHeader * mfh);

// If IsEmfPlus, this is the EMF+ version; else it is the WMF or EMF ver

UINT WINAPI MetafileHeader_GetVersion(IN const MetafileHeader * mfh);

// Get the EMF+ flags associated with the metafile

UINT WINAPI MetafileHeader_GetEmfPlusFlags(IN const MetafileHeader * mfh);

REAL WINAPI MetafileHeader_GetDpiX(IN const MetafileHeader * mfh);

REAL WINAPI MetafileHeader_GetDpiY(IN const MetafileHeader * mfh);

VOID 
WINAPI MetafileHeader_GetBounds(IN const MetafileHeader * mfh, OUT Rect *rect);

// Is it any type of WMF (standard or Placeable Metafile)?

BOOL WINAPI MetafileHeader_IsWmf(IN const MetafileHeader * mfh);

// Is this an Placeable Metafile?

BOOL WINAPI MetafileHeader_IsWmfPlaceable(IN const MetafileHeader * mfh);

// Is this an EMF (not an EMF+)?

BOOL WINAPI MetafileHeader_IsEmf(IN const MetafileHeader * mfh);

// Is this an EMF or EMF+ file?

BOOL WINAPI MetafileHeader_IsEmfOrEmfPlus(IN const MetafileHeader * mfh);

// Is this an EMF+ file?

BOOL WINAPI MetafileHeader_IsEmfPlus(IN const MetafileHeader * mfh);

// Is this an EMF+ dual (has dual, down-level records) file?

BOOL WINAPI MetafileHeader_IsEmfPlusDual(IN const MetafileHeader * mfh);

// Is this an EMF+ only (no dual records) file?

BOOL WINAPI MetafileHeader_IsEmfPlusOnly(IN const MetafileHeader * mfh);

// If it's an EMF+ file, was it recorded against a display Hdc?

BOOL WINAPI MetafileHeader_IsDisplay(IN const MetafileHeader * mfh);

// Get the WMF header of the metafile (if it is a WMF)

const METAHEADER *
WINAPI MetafileHeader_GetWmfHeader(IN const MetafileHeader * mfh);

// Get the EMF header of the metafile (if it is an EMF)

const ENHMETAHEADER3 *
WINAPI MetafileHeader_GetEmfHeader(IN const MetafileHeader * mfh);

#pragma endregion

#pragma region GdiplusImaging.h
/**************************************************************************\
*
* Copyright (c) 1999-2000  Microsoft Corporation
*
* Module Name:
*
*   GdiplusImaging.h
*
* Abstract:
*
*   GDI+ Imaging GUIDs
*
\**************************************************************************/

//---------------------------------------------------------------------------
// Image file format identifiers
//---------------------------------------------------------------------------

DEFINE_GUID(ImageFormatUndefined, 0xb96b3ca9, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatMemoryBMP, 0xb96b3caa, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatEMF, 0xb96b3cac, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatWMF, 0xb96b3cad, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatEXIF, 0xb96b3cb2, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatIcon, 0xb96b3cb5, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

//---------------------------------------------------------------------------
// Predefined multi-frame dimension IDs
//---------------------------------------------------------------------------

DEFINE_GUID(FrameDimensionTime, 0x6aedbd6d, 0x3fb5, 0x418a, 0x83, 0xa6, 0x7f, 0x45, 0x22, 0x9d, 0xc8, 0x72);
DEFINE_GUID(FrameDimensionResolution, 0x84236f7b, 0x3bd3, 0x428f, 0x8d, 0xab, 0x4e, 0xa1, 0x43, 0x9c, 0xa3, 0x15);
DEFINE_GUID(FrameDimensionPage, 0x7462dc86, 0x6180, 0x4c7e, 0x8e, 0x3f, 0xee, 0x73, 0x33, 0xa7, 0xa4, 0x83);

//---------------------------------------------------------------------------
// Property sets
//---------------------------------------------------------------------------

DEFINE_GUID(FormatIDImageInformation, 0xe5836cbe, 0x5eef, 0x4f1d, 0xac, 0xde, 0xae, 0x4c, 0x43, 0xb6, 0x08, 0xce);
DEFINE_GUID(FormatIDJpegAppHeaders, 0x1c4afdcd, 0x6177, 0x43cf, 0xab, 0xc7, 0x5f, 0x51, 0xaf, 0x39, 0xee, 0x85);

//---------------------------------------------------------------------------
// Encoder parameter sets
//---------------------------------------------------------------------------

DEFINE_GUID(EncoderCompression, 0xe09d739d, 0xccd4, 0x44ee, 0x8e, 0xba, 0x3f, 0xbf, 0x8b, 0xe4, 0xfc, 0x58);
DEFINE_GUID(EncoderColorDepth, 0x66087055, 0xad66, 0x4c7c, 0x9a, 0x18, 0x38, 0xa2, 0x31, 0x0b, 0x83, 0x37);
DEFINE_GUID(EncoderScanMethod, 0x3a4e2661, 0x3109, 0x4e56, 0x85, 0x36, 0x42, 0xc1, 0x56, 0xe7, 0xdc, 0xfa);
DEFINE_GUID(EncoderVersion, 0x24d18c76, 0x814a, 0x41a4, 0xbf, 0x53, 0x1c, 0x21, 0x9c, 0xcc, 0xf7, 0x97);
DEFINE_GUID(EncoderRenderMethod, 0x6d42c53a, 0x229a, 0x4825, 0x8b, 0xb7, 0x5c, 0x99, 0xe2, 0xb9, 0xa8, 0xb8);
DEFINE_GUID(EncoderQuality, 0x1d5be4b5, 0xfa4a, 0x452d, 0x9c, 0xdd, 0x5d, 0xb3, 0x51, 0x05, 0xe7, 0xeb);
DEFINE_GUID(EncoderTransformation, 0x8d0eb2d1, 0xa58e, 0x4ea8, 0xaa, 0x14, 0x10, 0x80, 0x74, 0xb7, 0xb6, 0xf9);
DEFINE_GUID(EncoderLuminanceTable, 0xedb33bce, 0x0266, 0x4a77, 0xb9, 0x04, 0x27, 0x21, 0x60, 0x99, 0xe7, 0x17);
DEFINE_GUID(EncoderChrominanceTable, 0xf2e455dc, 0x09b3, 0x4316, 0x82, 0x60, 0x67, 0x6a, 0xda, 0x32, 0x48, 0x1c);
DEFINE_GUID(EncoderSaveFlag, 0x292266fc, 0xac40, 0x47bf, 0x8c, 0xfc, 0xa8, 0x5b, 0x89, 0xa6, 0x55, 0xde);

DEFINE_GUID(CodecIImageBytes, 0x025d1823, 0x6c7d, 0x447b, 0xbb, 0xdb, 0xa3, 0xcb, 0xc3, 0xdf, 0xa2, 0xfc);

typedef interface IImageBytes IImageBytes;

typedef struct IImageBytesVtbl
{
    BEGIN_INTERFACE

    // Return total number of bytes in the IStream
    HRESULT(STDMETHODCALLTYPE * CountBytes)(
        __RPC__in IImageBytes * This,
        OUT UINT * pcb
        );

    // Locks "cb" bytes, starting from "ulOffset" in the stream, and returns the
    // pointer to the beginning of the locked memory chunk in "ppvBytes"

    HRESULT(STDMETHODCALLTYPE * LockBytes)(
        __RPC__in IImageBytes * This,
        IN UINT cb,
        IN ULONG ulOffset,
        OUT const VOID ** ppvBytes
        );

    // Unlocks "cb" bytes, pointed by "pvBytes", starting from "ulOffset" in the
    // stream

    HRESULT(STDMETHODCALLTYPE * UnlockBytes)(
        __RPC__in IImageBytes * This,
        IN const VOID * pvBytes,
        IN UINT cb,
        IN ULONG ulOffset
        );

    END_INTERFACE
} IImageBytesVtbl;

// DECLSPEC_UUID("025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC")
interface IImageBytes
{
    CONST_VTBL IImageBytesVtbl * lpVtbl;
};

#define IImageBytes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageBytes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageBytes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define IImageBytes_CountBytes(This, pcb)   \
    ( (This)->lpVtbl -> CountBytes(This) )

#define IImageBytes_LockBytes(This, cb, ulOffset, ppvBytes)   \
    ( (This)->lpVtbl -> LockBytes(This, cb, ulOffset, ppvBytes) )

#define IImageBytes_UnlockBytes(This, pvBytes, cb, ulOffset)   \
    ( (This)->lpVtbl -> UnlockBytes(This, pvBytes, cb, ulOffset) )

//--------------------------------------------------------------------------
// ImageCodecInfo structure
//--------------------------------------------------------------------------

typedef struct ImageCodecInfo
{
    CLSID Clsid;
    GUID  FormatID;
    const WCHAR * CodecName;
    const WCHAR * DllName;
    const WCHAR * FormatDescription;
    const WCHAR * FilenameExtension;
    const WCHAR * MimeType;
    DWORD Flags;
    DWORD Version;
    DWORD SigCount;
    DWORD SigSize;
    const BYTE * SigPattern;
    const BYTE * SigMask;
} ImageCodecInfo;

//--------------------------------------------------------------------------
// Information flags about image codecs
//--------------------------------------------------------------------------

typedef enum ImageCodecFlags
{
    ImageCodecFlagsEncoder = 0x00000001,
    ImageCodecFlagsDecoder = 0x00000002,
    ImageCodecFlagsSupportBitmap = 0x00000004,
    ImageCodecFlagsSupportVector = 0x00000008,
    ImageCodecFlagsSeekableEncode = 0x00000010,
    ImageCodecFlagsBlockingDecode = 0x00000020,

    ImageCodecFlagsBuiltin = 0x00010000,
    ImageCodecFlagsSystem = 0x00020000,
    ImageCodecFlagsUser = 0x00040000
} ImageCodecFlags;

//---------------------------------------------------------------------------
// Access modes used when calling Image::LockBits
//---------------------------------------------------------------------------

typedef enum ImageLockMode
{
    ImageLockModeRead = 0x0001,
    ImageLockModeWrite = 0x0002,
    ImageLockModeUserInputBuf = 0x0004
} ImageLockMode;

//---------------------------------------------------------------------------
// Information about image pixel data
//---------------------------------------------------------------------------

typedef struct BitmapData
{
    UINT Width;
    UINT Height;
    INT Stride;
    PixelFormat PixelFormat;
    VOID * Scan0;
    UINT_PTR Reserved;
} BitmapData;

//---------------------------------------------------------------------------
// Image flags
//---------------------------------------------------------------------------

typedef enum ImageFlags
{
    ImageFlagsNone = 0,

    // Low-word: shared with SINKFLAG_x

    ImageFlagsScalable = 0x0001,
    ImageFlagsHasAlpha = 0x0002,
    ImageFlagsHasTranslucent = 0x0004,
    ImageFlagsPartiallyScalable = 0x0008,

    // Low-word: color space definition

    ImageFlagsColorSpaceRGB = 0x0010,
    ImageFlagsColorSpaceCMYK = 0x0020,
    ImageFlagsColorSpaceGRAY = 0x0040,
    ImageFlagsColorSpaceYCBCR = 0x0080,
    ImageFlagsColorSpaceYCCK = 0x0100,

    // Low-word: image size info

    ImageFlagsHasRealDPI = 0x1000,
    ImageFlagsHasRealPixelSize = 0x2000,

    // High-word

    ImageFlagsReadOnly = 0x00010000,
    ImageFlagsCaching = 0x00020000
} ImageFlags;

typedef enum RotateFlipType
{
    RotateNoneFlipNone = 0,
    Rotate90FlipNone = 1,
    Rotate180FlipNone = 2,
    Rotate270FlipNone = 3,

    RotateNoneFlipX = 4,
    Rotate90FlipX = 5,
    Rotate180FlipX = 6,
    Rotate270FlipX = 7,

    RotateNoneFlipY = Rotate180FlipX,
    Rotate90FlipY = Rotate270FlipX,
    Rotate180FlipY = RotateNoneFlipX,
    Rotate270FlipY = Rotate90FlipX,

    RotateNoneFlipXY = Rotate180FlipNone,
    Rotate90FlipXY = Rotate270FlipNone,
    Rotate180FlipXY = RotateNoneFlipNone,
    Rotate270FlipXY = Rotate90FlipNone
} RotateFlipType;

//---------------------------------------------------------------------------
// Encoder Parameter structure
//---------------------------------------------------------------------------
typedef struct EncoderParameter
{
    GUID    Guid;               // GUID of the parameter
    ULONG   NumberOfValues;     // Number of the parameter values
    ULONG   Type;               // Value type, like ValueTypeLONG  etc.
    VOID *  Value;              // A pointer to the parameter values
} EncoderParameter;

//---------------------------------------------------------------------------
// Encoder Parameters structure
//---------------------------------------------------------------------------
typedef struct EncoderParameters
{
    UINT Count;                      // Number of parameters in this structure
    EncoderParameter Parameter[1];   // Parameter values
} EncoderParameters;

//---------------------------------------------------------------------------
// Property Item
//---------------------------------------------------------------------------
typedef struct PropertyItem
{
    PROPID  id;                 // ID of this property
    ULONG   length;             // Length of the property value, in bytes
    WORD    type;               // Type of the value, as one of TAG_TYPE_XXX
                                // defined above
    VOID *  value;              // property value
} PropertyItem;

//---------------------------------------------------------------------------
// Image property types 
//---------------------------------------------------------------------------
#define PropertyTagTypeByte        1
#define PropertyTagTypeASCII       2
#define PropertyTagTypeShort       3
#define PropertyTagTypeLong        4
#define PropertyTagTypeRational    5
#define PropertyTagTypeUndefined   7
#define PropertyTagTypeSLONG       9
#define PropertyTagTypeSRational  10

//---------------------------------------------------------------------------
// Image property ID tags
//---------------------------------------------------------------------------

#define PropertyTagExifIFD             0x8769
#define PropertyTagGpsIFD              0x8825

#define PropertyTagNewSubfileType      0x00FE
#define PropertyTagSubfileType         0x00FF
#define PropertyTagImageWidth          0x0100
#define PropertyTagImageHeight         0x0101
#define PropertyTagBitsPerSample       0x0102
#define PropertyTagCompression         0x0103
#define PropertyTagPhotometricInterp   0x0106
#define PropertyTagThreshHolding       0x0107
#define PropertyTagCellWidth           0x0108
#define PropertyTagCellHeight          0x0109
#define PropertyTagFillOrder           0x010A
#define PropertyTagDocumentName        0x010D
#define PropertyTagImageDescription    0x010E
#define PropertyTagEquipMake           0x010F
#define PropertyTagEquipModel          0x0110
#define PropertyTagStripOffsets        0x0111
#define PropertyTagOrientation         0x0112
#define PropertyTagSamplesPerPixel     0x0115
#define PropertyTagRowsPerStrip        0x0116
#define PropertyTagStripBytesCount     0x0117
#define PropertyTagMinSampleValue      0x0118
#define PropertyTagMaxSampleValue      0x0119
#define PropertyTagXResolution         0x011A   // Image resolution in width direction
#define PropertyTagYResolution         0x011B   // Image resolution in height direction
#define PropertyTagPlanarConfig        0x011C   // Image data arrangement
#define PropertyTagPageName            0x011D
#define PropertyTagXPosition           0x011E
#define PropertyTagYPosition           0x011F
#define PropertyTagFreeOffset          0x0120
#define PropertyTagFreeByteCounts      0x0121
#define PropertyTagGrayResponseUnit    0x0122
#define PropertyTagGrayResponseCurve   0x0123
#define PropertyTagT4Option            0x0124
#define PropertyTagT6Option            0x0125
#define PropertyTagResolutionUnit      0x0128   // Unit of X and Y resolution
#define PropertyTagPageNumber          0x0129
#define PropertyTagTransferFuncition   0x012D
#define PropertyTagSoftwareUsed        0x0131
#define PropertyTagDateTime            0x0132
#define PropertyTagArtist              0x013B
#define PropertyTagHostComputer        0x013C
#define PropertyTagPredictor           0x013D
#define PropertyTagWhitePoint          0x013E
#define PropertyTagPrimaryChromaticities 0x013F
#define PropertyTagColorMap            0x0140
#define PropertyTagHalftoneHints       0x0141
#define PropertyTagTileWidth           0x0142
#define PropertyTagTileLength          0x0143
#define PropertyTagTileOffset          0x0144
#define PropertyTagTileByteCounts      0x0145
#define PropertyTagInkSet              0x014C
#define PropertyTagInkNames            0x014D
#define PropertyTagNumberOfInks        0x014E
#define PropertyTagDotRange            0x0150
#define PropertyTagTargetPrinter       0x0151
#define PropertyTagExtraSamples        0x0152
#define PropertyTagSampleFormat        0x0153
#define PropertyTagSMinSampleValue     0x0154
#define PropertyTagSMaxSampleValue     0x0155
#define PropertyTagTransferRange       0x0156

#define PropertyTagJPEGProc            0x0200
#define PropertyTagJPEGInterFormat     0x0201
#define PropertyTagJPEGInterLength     0x0202
#define PropertyTagJPEGRestartInterval 0x0203
#define PropertyTagJPEGLosslessPredictors  0x0205
#define PropertyTagJPEGPointTransforms     0x0206
#define PropertyTagJPEGQTables         0x0207
#define PropertyTagJPEGDCTables        0x0208
#define PropertyTagJPEGACTables        0x0209

#define PropertyTagYCbCrCoefficients   0x0211
#define PropertyTagYCbCrSubsampling    0x0212
#define PropertyTagYCbCrPositioning    0x0213
#define PropertyTagREFBlackWhite       0x0214

#define PropertyTagICCProfile          0x8773   // This TAG is defined by ICC
// for embedded ICC in TIFF
#define PropertyTagGamma               0x0301
#define PropertyTagICCProfileDescriptor 0x0302
#define PropertyTagSRGBRenderingIntent 0x0303

#define PropertyTagImageTitle          0x0320
#define PropertyTagCopyright           0x8298

// Extra TAGs (Like Adobe Image Information tags etc.)

#define PropertyTagResolutionXUnit           0x5001
#define PropertyTagResolutionYUnit           0x5002
#define PropertyTagResolutionXLengthUnit     0x5003
#define PropertyTagResolutionYLengthUnit     0x5004
#define PropertyTagPrintFlags                0x5005
#define PropertyTagPrintFlagsVersion         0x5006
#define PropertyTagPrintFlagsCrop            0x5007
#define PropertyTagPrintFlagsBleedWidth      0x5008
#define PropertyTagPrintFlagsBleedWidthScale 0x5009
#define PropertyTagHalftoneLPI               0x500A
#define PropertyTagHalftoneLPIUnit           0x500B
#define PropertyTagHalftoneDegree            0x500C
#define PropertyTagHalftoneShape             0x500D
#define PropertyTagHalftoneMisc              0x500E
#define PropertyTagHalftoneScreen            0x500F
#define PropertyTagJPEGQuality               0x5010
#define PropertyTagGridSize                  0x5011
#define PropertyTagThumbnailFormat           0x5012  // 1 = JPEG, 0 = RAW RGB
#define PropertyTagThumbnailWidth            0x5013
#define PropertyTagThumbnailHeight           0x5014
#define PropertyTagThumbnailColorDepth       0x5015
#define PropertyTagThumbnailPlanes           0x5016
#define PropertyTagThumbnailRawBytes         0x5017
#define PropertyTagThumbnailSize             0x5018
#define PropertyTagThumbnailCompressedSize   0x5019
#define PropertyTagColorTransferFunction     0x501A
#define PropertyTagThumbnailData             0x501B// RAW thumbnail bits in
// JPEG format or RGB format
// depends on
// PropertyTagThumbnailFormat

// Thumbnail related TAGs

#define PropertyTagThumbnailImageWidth       0x5020  // Thumbnail width
#define PropertyTagThumbnailImageHeight      0x5021  // Thumbnail height
#define PropertyTagThumbnailBitsPerSample    0x5022  // Number of bits per
// component
#define PropertyTagThumbnailCompression      0x5023  // Compression Scheme
#define PropertyTagThumbnailPhotometricInterp 0x5024 // Pixel composition
#define PropertyTagThumbnailImageDescription 0x5025  // Image Tile
#define PropertyTagThumbnailEquipMake        0x5026  // Manufacturer of Image
// Input equipment
#define PropertyTagThumbnailEquipModel       0x5027  // Model of Image input
// equipment
#define PropertyTagThumbnailStripOffsets     0x5028  // Image data location
#define PropertyTagThumbnailOrientation      0x5029  // Orientation of image
#define PropertyTagThumbnailSamplesPerPixel  0x502A  // Number of components
#define PropertyTagThumbnailRowsPerStrip     0x502B  // Number of rows per strip
#define PropertyTagThumbnailStripBytesCount  0x502C  // Bytes per compressed
// strip
#define PropertyTagThumbnailResolutionX      0x502D  // Resolution in width
// direction
#define PropertyTagThumbnailResolutionY      0x502E  // Resolution in height
// direction
#define PropertyTagThumbnailPlanarConfig     0x502F  // Image data arrangement
#define PropertyTagThumbnailResolutionUnit   0x5030  // Unit of X and Y
// Resolution
#define PropertyTagThumbnailTransferFunction 0x5031  // Transfer function
#define PropertyTagThumbnailSoftwareUsed     0x5032  // Software used
#define PropertyTagThumbnailDateTime         0x5033  // File change date and
// time
#define PropertyTagThumbnailArtist           0x5034  // Person who created the
// image
#define PropertyTagThumbnailWhitePoint       0x5035  // White point chromaticity
#define PropertyTagThumbnailPrimaryChromaticities 0x5036 
// Chromaticities of
// primaries
#define PropertyTagThumbnailYCbCrCoefficients 0x5037 // Color space transforma-
// tion coefficients
#define PropertyTagThumbnailYCbCrSubsampling 0x5038  // Subsampling ratio of Y
// to C
#define PropertyTagThumbnailYCbCrPositioning 0x5039  // Y and C position
#define PropertyTagThumbnailRefBlackWhite    0x503A  // Pair of black and white
// reference values
#define PropertyTagThumbnailCopyRight        0x503B  // CopyRight holder

#define PropertyTagLuminanceTable            0x5090
#define PropertyTagChrominanceTable          0x5091

#define PropertyTagFrameDelay                0x5100
#define PropertyTagLoopCount                 0x5101

#define PropertyTagPixelUnit         0x5110  // Unit specifier for pixel/unit
#define PropertyTagPixelPerUnitX     0x5111  // Pixels per unit in X
#define PropertyTagPixelPerUnitY     0x5112  // Pixels per unit in Y
#define PropertyTagPaletteHistogram  0x5113  // Palette histogram

// EXIF specific tag

#define PropertyTagExifExposureTime  0x829A
#define PropertyTagExifFNumber       0x829D

#define PropertyTagExifExposureProg  0x8822
#define PropertyTagExifSpectralSense 0x8824
#define PropertyTagExifISOSpeed      0x8827
#define PropertyTagExifOECF          0x8828

#define PropertyTagExifVer            0x9000
#define PropertyTagExifDTOrig         0x9003 // Date & time of original
#define PropertyTagExifDTDigitized    0x9004 // Date & time of digital data generation

#define PropertyTagExifCompConfig     0x9101
#define PropertyTagExifCompBPP        0x9102

#define PropertyTagExifShutterSpeed   0x9201
#define PropertyTagExifAperture       0x9202
#define PropertyTagExifBrightness     0x9203
#define PropertyTagExifExposureBias   0x9204
#define PropertyTagExifMaxAperture    0x9205
#define PropertyTagExifSubjectDist    0x9206
#define PropertyTagExifMeteringMode   0x9207
#define PropertyTagExifLightSource    0x9208
#define PropertyTagExifFlash          0x9209
#define PropertyTagExifFocalLength    0x920A
#define PropertyTagExifSubjectArea    0x9214  // exif 2.2 Subject Area
#define PropertyTagExifMakerNote      0x927C
#define PropertyTagExifUserComment    0x9286
#define PropertyTagExifDTSubsec       0x9290  // Date & Time subseconds
#define PropertyTagExifDTOrigSS       0x9291  // Date & Time original subseconds
#define PropertyTagExifDTDigSS        0x9292  // Date & TIme digitized subseconds

#define PropertyTagExifFPXVer         0xA000
#define PropertyTagExifColorSpace     0xA001
#define PropertyTagExifPixXDim        0xA002
#define PropertyTagExifPixYDim        0xA003
#define PropertyTagExifRelatedWav     0xA004  // related sound file
#define PropertyTagExifInterop        0xA005
#define PropertyTagExifFlashEnergy    0xA20B
#define PropertyTagExifSpatialFR      0xA20C  // Spatial Frequency Response
#define PropertyTagExifFocalXRes      0xA20E  // Focal Plane X Resolution
#define PropertyTagExifFocalYRes      0xA20F  // Focal Plane Y Resolution
#define PropertyTagExifFocalResUnit   0xA210  // Focal Plane Resolution Unit
#define PropertyTagExifSubjectLoc     0xA214
#define PropertyTagExifExposureIndex  0xA215
#define PropertyTagExifSensingMethod  0xA217
#define PropertyTagExifFileSource     0xA300
#define PropertyTagExifSceneType      0xA301
#define PropertyTagExifCfaPattern     0xA302

// New EXIF 2.2 properties

#define PropertyTagExifCustomRendered           0xA401
#define PropertyTagExifExposureMode             0xA402
#define PropertyTagExifWhiteBalance             0xA403
#define PropertyTagExifDigitalZoomRatio         0xA404
#define PropertyTagExifFocalLengthIn35mmFilm    0xA405
#define PropertyTagExifSceneCaptureType         0xA406
#define PropertyTagExifGainControl              0xA407
#define PropertyTagExifContrast                 0xA408
#define PropertyTagExifSaturation               0xA409
#define PropertyTagExifSharpness                0xA40A
#define PropertyTagExifDeviceSettingDesc        0xA40B
#define PropertyTagExifSubjectDistanceRange     0xA40C
#define PropertyTagExifUniqueImageID            0xA420


#define PropertyTagGpsVer             0x0000
#define PropertyTagGpsLatitudeRef     0x0001
#define PropertyTagGpsLatitude        0x0002
#define PropertyTagGpsLongitudeRef    0x0003
#define PropertyTagGpsLongitude       0x0004
#define PropertyTagGpsAltitudeRef     0x0005
#define PropertyTagGpsAltitude        0x0006
#define PropertyTagGpsGpsTime         0x0007
#define PropertyTagGpsGpsSatellites   0x0008
#define PropertyTagGpsGpsStatus       0x0009
#define PropertyTagGpsGpsMeasureMode  0x00A
#define PropertyTagGpsGpsDop          0x000B  // Measurement precision
#define PropertyTagGpsSpeedRef        0x000C
#define PropertyTagGpsSpeed           0x000D
#define PropertyTagGpsTrackRef        0x000E
#define PropertyTagGpsTrack           0x000F
#define PropertyTagGpsImgDirRef       0x0010
#define PropertyTagGpsImgDir          0x0011
#define PropertyTagGpsMapDatum        0x0012
#define PropertyTagGpsDestLatRef      0x0013
#define PropertyTagGpsDestLat         0x0014
#define PropertyTagGpsDestLongRef     0x0015
#define PropertyTagGpsDestLong        0x0016
#define PropertyTagGpsDestBearRef     0x0017
#define PropertyTagGpsDestBear        0x0018
#define PropertyTagGpsDestDistRef     0x0019
#define PropertyTagGpsDestDist        0x001A
#define PropertyTagGpsProcessingMethod 0x001B
#define PropertyTagGpsAreaInformation 0x001C
#define PropertyTagGpsDate            0x001D
#define PropertyTagGpsDifferential    0x001E

#pragma endregion

#pragma region GdiplusColorMatrix.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusColorMatrix.h
*
* Abstract:
*
*  GDI+ Color Matrix object, used with Graphics.DrawImage
*
\**************************************************************************/

//----------------------------------------------------------------------------
// Color matrix
//----------------------------------------------------------------------------

typedef struct ColorMatrix
{
    REAL m[5][5];
} ColorMatrix;

//----------------------------------------------------------------------------
// Color Matrix flags
//----------------------------------------------------------------------------

typedef enum ColorMatrixFlags
{
    ColorMatrixFlagsDefault = 0,
    ColorMatrixFlagsSkipGrays = 1,
    ColorMatrixFlagsAltGray = 2
} ColorMatrixFlags;

//----------------------------------------------------------------------------
// Color Adjust Type
//----------------------------------------------------------------------------

typedef enum ColorAdjustType
{
    ColorAdjustTypeDefault,
    ColorAdjustTypeBitmap,
    ColorAdjustTypeBrush,
    ColorAdjustTypePen,
    ColorAdjustTypeText,
    ColorAdjustTypeCount,
    ColorAdjustTypeAny      // Reserved
} ColorAdjustType;

//----------------------------------------------------------------------------
// Color Map
//----------------------------------------------------------------------------

typedef struct ColorMap
{
    Color oldColor;
    Color newColor;
} ColorMap;

#pragma endregion

#pragma region GdiplusGpStubs.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusGpStubs.h
*
* Abstract:
*
*   Private GDI+ header file.
*
\**************************************************************************/

//---------------------------------------------------------------------------
// Private GDI+ structures for internal type checking
//---------------------------------------------------------------------------

typedef struct { int unused; } EmptyClass;

typedef EmptyClass Graphics;

typedef EmptyClass  Brush;
typedef Brush TextureBrush;
typedef Brush SolidBrush;
typedef Brush LinearGradientBrush;
typedef Brush PathGradientBrush;
typedef Brush HatchBrush;

typedef EmptyClass Pen;
typedef EmptyClass CustomLineCap;
typedef CustomLineCap AdjustableArrowCap;

typedef EmptyClass Image;
typedef Image Bitmap;
typedef Image Metafile;
typedef EmptyClass ImageAttributes;

typedef EmptyClass GraphicsPath;
typedef EmptyClass Region;
typedef EmptyClass GraphicsPathIterator;

typedef EmptyClass FontFamily;
typedef EmptyClass Font;
typedef EmptyClass StringFormat;
typedef EmptyClass FontCollection;
typedef FontCollection InstalledFontCollection;
typedef FontCollection PrivateFontCollection;

typedef EmptyClass CachedBitmap;

typedef EmptyClass Matrix;

#pragma endregion

#pragma region GdiplusImageAttributes.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   Image Attributes
*
* Abstract:
*
*   GDI+ Image Attributes used with Graphics.DrawImage
*
* There are 5 possible sets of color adjustments:
*          ColorAdjustDefault,
*          ColorAdjustBitmap,
*          ColorAdjustBrush,
*          ColorAdjustPen,
*          ColorAdjustText,
*
* Bitmaps, Brushes, Pens, and Text will all use any color adjustments
* that have been set into the default ImageAttributes until their own
* color adjustments have been set.  So as soon as any "Set" method is
* called for Bitmaps, Brushes, Pens, or Text, then they start from
* scratch with only the color adjustments that have been set for them.
* Calling Reset removes any individual color adjustments for a type
* and makes it revert back to using all the default color adjustments
* (if any).  The SetToIdentity method is a way to force a type to
* have no color adjustments at all, regardless of what previous adjustments
* have been set for the defaults or for that type.
*
\***************************************************************************/

Status WINAPI
ImageAttributes_Create(OUT ImageAttributes ** imageAttr);

Status WINAPI
ImageAttributes_Clone(IN const ImageAttributes * imageAttr,
                      OUT ImageAttributes ** cloneImageAttr);

Status WINAPI
ImageAttributes_Dispose(IN ImageAttributes * imageAttr);

Status WINAPI
ImageAttributes_SetToIdentity(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_Reset(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetColorMatrix(
    IN ImageAttributes * imageAttr,
    IN const ColorMatrix * colorMatrix,
    IN ColorMatrixFlags mode, // = ColorMatrixFlagsDefault
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearColorMatrix(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetColorMatrices(
    IN ImageAttributes * imageAttr,
    IN const ColorMatrix * colorMatrix,
    IN const ColorMatrix * grayMatrix,
    IN ColorMatrixFlags mode, // = ColorMatrixFlagsDefault
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearColorMatrices(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetThreshold(
    IN ImageAttributes * imageAttr,
    IN REAL threshold,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearThreshold(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetGamma(
    IN ImageAttributes * imageAttr,
    IN REAL gamma,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearGamma(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetNoOp(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearNoOp(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetColorKey(
    IN ImageAttributes * imageAttr,
    IN Color colorLow,
    IN Color colorHigh,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearColorKey(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetOutputChannel(
    IN ImageAttributes * imageAttr,
    IN ColorChannelFlags channelFlags,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearOutputChannel(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetOutputChannelColorProfile(
    IN ImageAttributes * imageAttr,
    IN const WCHAR * colorProfileFilename,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearOutputChannelColorProfile(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetRemapTable(
    IN ImageAttributes * imageAttr,
    IN UINT mapSize,
    IN const ColorMap * map,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_ClearRemapTable(
    IN ImageAttributes * imageAttr,
    IN ColorAdjustType type // = ColorAdjustTypeDefault
);

Status WINAPI
ImageAttributes_SetBrushRemapTable(
    IN ImageAttributes * imageAttr,
    IN UINT mapSize,
    IN const ColorMap * map);

Status WINAPI
ImageAttributes_ClearBrushRemapTable(
    IN ImageAttributes * imageAttr
);

Status WINAPI
ImageAttributes_SetWrapMode(
    IN ImageAttributes * imageAttr,
    IN WrapMode wrap,
    IN Color color, // = NULL
    IN BOOL clamp // = FALSE
);

// The flags of the palette are ignored.

Status WINAPI
ImageAttributes_GetAdjustedPalette(
    IN ImageAttributes * imageAttr,
    IN OUT ColorPalette * colorPalette,
    IN ColorAdjustType colorAdjustType
);

#pragma endregion

#pragma region GdiplusMatrix.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusMatrix.h
*
* Abstract:
*
*   GDI+ Matrix class
*
\**************************************************************************/

// Default constructor is set to identity matrix.

Status WINAPI
Matrix_Create(
    OUT Matrix ** matrix
);

Status WINAPI
Matrix_Create2(
    OUT Matrix ** matrix,
    IN REAL m11,
    IN REAL m12,
    IN REAL m21,
    IN REAL m22,
    IN REAL dx,
    IN REAL dy
);

Status WINAPI
Matrix_Create3(
    OUT Matrix ** matrix,
    IN const RectF * rect,
    IN const PointF * dstplg
);

Status WINAPI
Matrix_Create3I(
    OUT Matrix ** matrix,
    IN const Rect * rect,
    IN const Point * dstplg
);

Status WINAPI
Matrix_Clone(
    IN Matrix * matrix,
    OUT Matrix ** clone
);

Status WINAPI
Matrix_Delete(
    IN Matrix * matrix
);

Status WINAPI
Matrix_GetElements(
    IN Matrix * matrix,
    OUT REAL * m
);

Status WINAPI
Matrix_SetElements(
    IN Matrix * matrix,
    IN REAL m11,
    IN REAL m12,
    IN REAL m21,
    IN REAL m22,
    IN REAL dx,
    IN REAL dy
);

REAL WINAPI Matrix_OffsetX(IN Matrix * matrix);

REAL WINAPI Matrix_OffsetY(IN Matrix * matrix);

Status WINAPI
Matrix_Reset(
    IN Matrix * matrix
);

Status WINAPI
Matrix_Multiply(
    IN Matrix * matrix,
    IN Matrix * nmatrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_Translate(
    IN Matrix * matrix,
    IN REAL offsetX,
    IN REAL offsetY,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_Scale(
    IN Matrix * matrix,
    IN REAL scaleX,
    IN REAL scaleY,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_Rotate(
    IN Matrix * matrix,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_RotateAt(
    IN Matrix * matrix,
    IN REAL angle,
    IN const PointF * center,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_Shear(
    IN Matrix * matrix,
    IN REAL shearX,
    IN REAL shearY,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Matrix_Invert(IN Matrix * matrix);

Status WINAPI
Matrix_TransformPoints(
    IN Matrix * matrix,
    IN OUT PointF * pts,
    IN INT count // = 1
);

// integer version
Status WINAPI
Matrix_TransformPointsI(
    IN Matrix * matrix,
    IN OUT Point * pts,
    IN INT count // = 1
);

Status WINAPI
Matrix_TransformVectors(
    IN Matrix * matrix,
    IN OUT PointF * pts,
    IN INT count // = 1
);

// integer version
Status WINAPI
Matrix_TransformVectorsI(
    IN Matrix * matrix,
    IN OUT Point * pts,
    IN INT count // = 1
);

BOOL WINAPI
Matrix_IsInvertible(IN const Matrix * matrix);

BOOL WINAPI
Matrix_IsIdentity(IN const Matrix * matrix);

BOOL WINAPI
Matrix_Equals(
    IN const Matrix * matrix1,
    IN const Matrix * matrix2
);

#pragma endregion

#pragma region GdiplusBrush.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusBrush.h
*
* Abstract:
*
*   GDI+ Brush class
*
\**************************************************************************/

//--------------------------------------------------------------------------
// Abstract base class for various brush types
//--------------------------------------------------------------------------

Status WINAPI
Brush_Delete(
    IN Brush * brush
);

Status WINAPI
Brush_Clone(
    IN Brush * brush,
    OUT Brush ** clone
);

BrushType WINAPI
Brush_GetType(
    IN Brush * brush
);

//--------------------------------------------------------------------------
// Solid Fill Brush Object
//--------------------------------------------------------------------------

Status WINAPI
SolidBrush_Create(
    IN Color color,
    OUT SolidBrush ** solidBrush
);

#define SolidBrush_Delete(solidBrush) Brush_Delete(solidBrush)

#define SolidBrush_Clone(solidBrush, clone) Brush_Clone(solidBrush, clone)

Color WINAPI
SolidBrush_GetColor(IN SolidBrush * solidBrush);

Status WINAPI
SolidBrush_SetColor(
    IN SolidBrush * solidBrush,
    IN Color color
);

//--------------------------------------------------------------------------
// Texture Brush Fill Object
//--------------------------------------------------------------------------

Status WINAPI
TextureBrush_Create(
    IN Image * image,
    IN WrapMode wrapMode, // = WrapModeTile
    OUT TextureBrush ** textureBrush
);

Status WINAPI
TextureBrush_CreateIA(
    IN Image * image,
    IN const RectF * dstRect,
    IN const ImageAttributes * imageAttributes, // = NULL
    OUT TextureBrush ** textureBrush
);

// integer version
Status WINAPI
TextureBrush_CreateIAI(
    IN Image * image,
    IN const Rect * dstRect,
    IN const ImageAttributes * imageAttributes, // = NULL
    OUT TextureBrush ** textureBrush
);

// When creating a texture brush from a metafile image, the dstRect
// is used to specify the size that the metafile image should be
// rendered at in the device units of the destination graphics.
// It is NOT used to crop the metafile image, so only the width 
// and height values matter for metafiles.

Status WINAPI
TextureBrush_Create2(
    IN Image * image,
    IN WrapMode wrapMode,
    IN REAL dstX,
    IN REAL dstY,
    IN REAL dstWidth,
    IN REAL dstHeight,
    OUT TextureBrush ** textureBrush
);

Status WINAPI
TextureBrush_Create2I(
    IN Image * image,
    IN WrapMode wrapMode,
    IN INT dstX,
    IN INT dstY,
    IN INT dstWidth,
    IN INT dstHeight,
    OUT TextureBrush ** textureBrush
);

#define TextureBrush_Delete(textureBrush) Brush_Delete(textureBrush)

#define TextureBrush_Clone(textureBrush, clone) Brush_Clone(textureBrush, clone)

Status WINAPI
TextureBrush_SetTransform(
    IN TextureBrush * textureBrush,
    IN const Matrix * matrix
);

Status WINAPI
TextureBrush_GetTransform(
    IN TextureBrush * textureBrush,
    OUT Matrix * matrix
);

Status WINAPI
TextureBrush_ResetTransform(IN TextureBrush * textureBrush);

Status WINAPI
TextureBrush_MultiplyTransform(
    IN TextureBrush * textureBrush,
    IN const Matrix * matrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
TextureBrush_TranslateTransform(
    IN TextureBrush * textureBrush,
    IN REAL dx,
    IN REAL dy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
TextureBrush_ScaleTransform(
    IN TextureBrush * textureBrush,
    IN REAL sx,
    IN REAL sy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
TextureBrush_RotateTransform(
    IN TextureBrush * textureBrush,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
TextureBrush_SetWrapMode(
    IN TextureBrush * textureBrush,
    IN WrapMode wrapMode
);

WrapMode WINAPI
TextureBrush_GetWrapMode(IN TextureBrush * textureBrush);

Image * WINAPI
TextureBrush_GetImage(IN TextureBrush * textureBrush);

//--------------------------------------------------------------------------
// Linear Gradient Brush Object
//--------------------------------------------------------------------------

Status WINAPI
LinearGradientBrush_Create(
    IN const PointF * point1,
    IN const PointF * point2,
    IN Color color1,
    IN Color color2,
    OUT LinearGradientBrush ** lgBrush
);

// integer version
Status WINAPI
LinearGradientBrush_CreateI(
    IN const Point * point1,
    IN const Point * point2,
    IN Color color1,
    IN Color color2,
    OUT LinearGradientBrush ** lgBrush
);

Status WINAPI
LinearGradientBrush_CreateFromRect(
    IN const RectF * rect,
    IN Color color1,
    IN Color color2,
    IN LinearGradientMode mode,
    OUT LinearGradientBrush ** lgBrush
);

// integer version
Status WINAPI
LinearGradientBrush_CreateFromRectI(
    IN const Rect * rect,
    IN Color color1,
    IN Color color2,
    IN LinearGradientMode mode,
    OUT LinearGradientBrush ** lgBrush
);

Status WINAPI
LinearGradientBrush_CreateFromRectWithAngle(
    IN const RectF * rect,
    IN Color color1,
    IN Color color2,
    IN REAL angle,
    IN BOOL isAngleScalable, // = FALSE
    OUT LinearGradientBrush ** lgBrush
);

// integer version
Status WINAPI
LinearGradientBrush_CreateFromRectWithAngleI(
    IN const Rect * rect,
    IN Color color1,
    IN Color color2,
    IN REAL angle,
    IN BOOL isAngleScalable, // = FALSE
    OUT LinearGradientBrush ** lgBrush
);

#define LinearGradientBrush_Delete(lgBrush) Brush_Delete(lgBrush)

#define LinearGradientBrush_Clone(lgBrush, clone) Brush_Clone(lgBrush, clone)

Status WINAPI
LinearGradientBrush_SetLinearColors(
    IN LinearGradientBrush * lgBrush,
    IN Color color1,
    IN Color color2
);

Status WINAPI
LinearGradientBrush_GetLinearColors(
    IN LinearGradientBrush * lgBrush,
    OUT Color * colors
);

Status WINAPI
LinearGradientBrush_GetRectangle(
    IN LinearGradientBrush * lgBrush,
    OUT RectF * rect
);

Status WINAPI
LinearGradientBrush_GetRectangleI(
    IN LinearGradientBrush * lgBrush,
    OUT Rect * rect
);

Status WINAPI
LinearGradientBrush_SetGammaCorrection(
    IN LinearGradientBrush * lgBrush,
    IN BOOL useGammaCorrection
);

BOOL WINAPI
LinearGradientBrush_GetGammaCorrection(
    IN LinearGradientBrush * lgBrush
);

INT WINAPI
LinearGradientBrush_GetBlendCount(
    IN LinearGradientBrush * lgBrush
);

Status WINAPI
LinearGradientBrush_SetBlend(
    IN LinearGradientBrush * lgBrush,
    IN const REAL * blendFactors,
    IN const REAL * blendPositions,
    IN INT count
);

Status WINAPI
LinearGradientBrush_GetBlend(
    IN LinearGradientBrush * lgBrush,
    OUT REAL * blendFactors,
    OUT REAL * blendPositions,
    IN INT count
);

INT WINAPI
LinearGradientBrush_GetInterpolationColorCount(
    IN LinearGradientBrush * lgBrush
);

Status WINAPI
LinearGradientBrush_SetInterpolationColors(
    IN LinearGradientBrush * lgBrush,
    IN const Color * presetColors,
    IN const REAL * blendPositions,
    IN INT count
);

Status WINAPI
LinearGradientBrush_GetInterpolationColors(
    IN LinearGradientBrush * lgBrush,
    OUT Color * presetColors,
    OUT REAL * blendPositions,
    IN INT count
);

Status WINAPI
LinearGradientBrush_SetBlendBellShape(
    IN LinearGradientBrush * lgBrush,
    IN REAL focus,
    IN REAL scale // = 1.0f
);

Status WINAPI
LinearGradientBrush_SetBlendTriangularShape(
    IN LinearGradientBrush * lgBrush,
    IN REAL focus,
    IN REAL scale // = 1.0f
);

Status WINAPI
LinearGradientBrush_SetTransform(
    IN LinearGradientBrush * lgBrush,
    IN const Matrix * matrix
);

Status WINAPI
LinearGradientBrush_GetTransform(
    IN LinearGradientBrush * lgBrush,
    OUT Matrix *matrix
);

Status WINAPI
LinearGradientBrush_ResetTransform(IN LinearGradientBrush * lgBrush);

Status WINAPI
LinearGradientBrush_MultiplyTransform(
    IN LinearGradientBrush * lgBrush,
    IN const Matrix * matrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
LinearGradientBrush_TranslateTransform(
    IN LinearGradientBrush * lgBrush,
    IN REAL dx,
    IN REAL dy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
LinearGradientBrush_ScaleTransform(
    IN LinearGradientBrush * lgBrush,
    IN REAL sx,
    IN REAL sy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
LinearGradientBrush_RotateTransform(
    IN LinearGradientBrush * lgBrush,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
LinearGradientBrush_SetWrapMode(
    IN LinearGradientBrush * lgBrush,
    IN WrapMode wrapMode
);

WrapMode WINAPI
LinearGradientBrush_GetWrapMode(IN LinearGradientBrush * lgBrush);

//--------------------------------------------------------------------------
// PathGradientBrush object is defined
// in gdipluspath.h.
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Hatch Brush Object
//--------------------------------------------------------------------------

Status WINAPI
HatchBrush_Create(
    IN HatchStyle hatchStyle,
    IN Color foreColor,
    IN Color backColor, // = 0x00000000
    OUT HatchBrush ** hatchBrush
);

#define HatchBrush_Delete(hatchBrush) Brush_Delete(hatchBrush)

#define HatchBrush_Clone(hatchBrush, clone) Brush_Clone(hatchBrush, clone)

HatchStyle WINAPI
HatchBrush_GetHatchStyle(IN HatchBrush * hatchBrush);

Color WINAPI
HatchBrush_GetForegroundColor(IN HatchBrush * hatchBrush);

Color WINAPI
HatchBrush_GetBackgroundColor(IN HatchBrush * hatchBrush);

#pragma endregion

#pragma region GdiplusPen.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusPen.h
*
* Abstract:
*
*   GDI+ Pen class
*
\**************************************************************************/

//--------------------------------------------------------------------------
// Pen class
//--------------------------------------------------------------------------

Status WINAPI
Pen_Create(
    IN Color color,
    IN REAL width, // = 1.0f
    OUT Pen ** pen
);

Status WINAPI
Pen_Create2(
    IN Brush * brush,
    IN REAL width, // = 1.0f
    OUT Pen ** pen
);

Status WINAPI
Pen_Delete(IN Pen * pen);

Status WINAPI
Pen_Clone(
    IN Pen * pen,
    OUT Pen ** clone
);

Status WINAPI
Pen_SetWidth(
    IN Pen * pen,
    IN REAL width
);

REAL WINAPI
Pen_GetWidth(IN Pen * pen);

// Set/get line caps: start, end, and dash

// Line cap and join APIs by using LineCap and LineJoin enums.

Status WINAPI
Pen_SetLineCap(
    IN Pen * pen,
    IN LineCap startCap,
    IN LineCap endCap,
    IN DashCap dashCap
);

Status WINAPI
Pen_SetStartCap(
    IN Pen * pen,
    IN LineCap startCap
);

Status WINAPI
Pen_SetEndCap(
    IN Pen * pen,
    IN LineCap endCap
);

Status WINAPI
Pen_SetDashCap(
    IN Pen * pen,
    IN DashCap dashCap
);

LineCap WINAPI
Pen_GetStartCap(IN Pen * pen);

LineCap WINAPI
Pen_GetEndCap(IN Pen * pen);

DashCap WINAPI
Pen_GetDashCap(IN Pen * pen);

Status WINAPI
Pen_SetLineJoin(
    IN Pen * pen,
    IN LineJoin lineJoin
);

LineJoin WINAPI
Pen_GetLineJoin(IN Pen * pen);

Status WINAPI
Pen_SetCustomStartCap(
    IN Pen * pen,
    IN CustomLineCap * customCap
);

Status WINAPI
Pen_GetCustomStartCap(
    IN Pen * pen,
    OUT CustomLineCap ** customCap
);

Status WINAPI
Pen_SetCustomEndCap(
    IN Pen * pen,
    IN CustomLineCap * customCap
);

Status WINAPI
Pen_GetCustomEndCap(
    IN Pen * pen,
    OUT CustomLineCap ** customCap
);

Status WINAPI
Pen_SetMiterLimit(
    IN Pen * pen,
    IN REAL miterLimit
);

REAL WINAPI
Pen_GetMiterLimit(IN Pen * pen);

Status WINAPI
Pen_SetAlignment(
    IN Pen * pen,
    IN PenAlignment penAlignment
);

PenAlignment WINAPI
Pen_GetAlignment(IN Pen * pen);

Status WINAPI
Pen_SetTransform(
    IN Pen * pen,
    IN Matrix * matrix
);

Status WINAPI
Pen_GetTransform(
    IN Pen * pen,
    OUT Matrix * matrix
);

Status WINAPI
Pen_ResetTransform(IN Pen * pen);

Status WINAPI
Pen_MultiplyTransform(
    IN Pen * pen,
    IN Matrix * matrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Pen_TranslateTransform(
    IN Pen * pen,
    IN REAL dx,
    IN REAL dy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Pen_ScaleTransform(
    IN Pen * pen,
    IN REAL sx,
    IN REAL sy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Pen_RotateTransform(
    IN Pen * pen,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

PenType WINAPI
Pen_GetPenType(IN Pen * pen);

Status WINAPI
Pen_SetColor(
    IN Pen * pen,
    IN Color color
);

Status WINAPI
Pen_SetBrush(
    IN Pen * pen,
    IN Brush * brush
);

Status WINAPI
Pen_GetColor(
    IN Pen * pen,
    OUT Color * color
);

Status WINAPI
Pen_GetBrush(
    IN Pen * pen,
    OUT Brush ** brush
);

DashStyle WINAPI
Pen_GetDashStyle(IN Pen * pen);

Status WINAPI
Pen_SetDashStyle(
    IN Pen * pen,
    IN DashStyle dashStyle
);

REAL WINAPI
Pen_GetDashOffset(IN Pen * pen);

Status WINAPI
Pen_SetDashOffset(
    IN Pen * pen,
    IN REAL dashOffset
);

Status WINAPI
Pen_SetDashPattern(
    IN Pen * pen,
    IN const REAL * dashArray,
    IN INT count
);

INT WINAPI
Pen_GetDashPatternCount(IN Pen * pen);

Status WINAPI
Pen_GetDashPattern(
    IN Pen * pen,
    OUT REAL * dashArray,
    IN INT count
);

Status WINAPI
Pen_SetCompoundArray(
    IN Pen * pen,
    IN const REAL * compoundArray,
    IN INT count
);

INT WINAPI
Pen_GetCompoundArrayCount(IN Pen * pen);

Status WINAPI
Pen_GetCompoundArray(
    IN Pen * pen,
    OUT REAL * compoundArray,
    IN INT count
);

#pragma endregion

#pragma region GdiplusStringFormat.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusStringFormat.h
*
* Abstract:
*
*   GDI+ StringFormat class
*
\**************************************************************************/

Status WINAPI
StringFormat_Create(
    IN INT formatFlags, // = 0
    IN LANGID language, // = LANG_NEUTRAL
    OUT StringFormat ** strFormat
);

Status WINAPI
StringFormat_GenericDefault(OUT StringFormat ** strFormat);

Status WINAPI
StringFormat_GenericTypographic(OUT StringFormat ** strFormat);

Status WINAPI
StringFormat_Clone(
    IN StringFormat * strFormat,
    OUT StringFormat ** clonedFormat
);

Status WINAPI
StringFormat_Delete(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetFormatFlags(
    IN StringFormat * strFormat,
    IN INT flags
);

INT WINAPI
StringFormat_GetFormatFlags(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetAlignment(
    IN StringFormat * strFormat,
    IN StringAlignment align
);

StringAlignment WINAPI
StringFormat_GetAlignment(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetLineAlignment(
    IN StringFormat * strFormat,
    IN StringAlignment align
);

StringAlignment WINAPI
StringFormat_GetLineAlignment(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetHotkeyPrefix(
    IN StringFormat * strFormat,
    IN HotkeyPrefix hotkeyPrefix
);

HotkeyPrefix WINAPI
StringFormat_GetHotkeyPrefix(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetTabStops(
    IN StringFormat * strFormat,
    IN REAL firstTabOffset,
    IN INT count,
    IN const REAL * tabStops
);

INT WINAPI
StringFormat_GetTabStopCount(IN StringFormat * strFormat);

Status WINAPI
StringFormat_GetTabStops(
    IN StringFormat * strFormat,
    IN INT count,
    OUT REAL * firstTabOffset,
    OUT REAL * tabStops
);

Status WINAPI
StringFormat_SetDigitSubstitution(
    IN StringFormat * strFormat,
    IN LANGID language,
    IN StringDigitSubstitute substitute
);

LANGID WINAPI
StringFormat_GetDigitSubstitutionLanguage(IN StringFormat * strFormat);

StringDigitSubstitute WINAPI
StringFormat_GetDigitSubstitutionMethod(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetTrimming(
    IN StringFormat * strFormat,
    IN StringTrimming trimming
);

StringTrimming WINAPI
StringFormat_GetTrimming(IN StringFormat * strFormat);

Status WINAPI
StringFormat_SetMeasurableCharacterRanges(
    IN StringFormat * strFormat,
    IN INT rangeCount,
    IN const CharacterRange * ranges
);

INT WINAPI
StringFormat_GetMeasurableCharacterRangeCount(IN StringFormat * strFormat);

#pragma endregion

#pragma region GdiplusPath.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusPath.h
*
* Abstract:
*
*   GDI+ Graphics Path class
*
\**************************************************************************/

Status WINAPI
GraphicsPath_Create(
    IN FillMode fillMode, // = FillModeAlternate
    OUT GraphicsPath ** path
);

Status WINAPI
GraphicsPath_Create2(
    IN const PointF * points,
    IN const BYTE * types,
    IN INT count,
    IN FillMode fillMode, // = FillModeAlternate
    OUT GraphicsPath ** path
);

// integer version
Status WINAPI
GraphicsPath_Create2I(
    IN const Point * points,
    IN const BYTE * types,
    IN INT count,
    IN FillMode fillMode, // = FillModeAlternate
    OUT GraphicsPath ** path
);

Status WINAPI
GraphicsPath_Delete(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_Clone(
    IN GraphicsPath * path,
    OUT GraphicsPath ** clonePath
); 

// Reset the path object to empty (and fill mode to FillModeAlternate)

Status WINAPI
GraphicsPath_Reset(IN GraphicsPath * path);

FillMode WINAPI
GraphicsPath_GetFillMode(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_SetFillMode(
    IN GraphicsPath * path,
    IN FillMode fillmode
);

Status WINAPI
GraphicsPath_GetPathData(
    IN GraphicsPath * path,
    OUT PathData * pathData
);
    
Status WINAPI
GraphicsPath_StartFigure(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_CloseFigure(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_CloseAllFigures(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_SetMarker(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_ClearMarkers(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_Reverse(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_GetLastPoint(
    IN GraphicsPath * path,
    OUT PointF * lastPoint
);

Status WINAPI
GraphicsPath_AddLine(
    IN GraphicsPath * path,
    IN REAL x1,
    IN REAL y1,
    IN REAL x2,
    IN REAL y2
);

// integer version
Status WINAPI
GraphicsPath_AddLineI(
    IN GraphicsPath * path,
    IN INT x1,
    IN INT y1,
    IN INT x2,
    IN INT y2
);

Status WINAPI
GraphicsPath_AddLines(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddLinesI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddArc(
    IN GraphicsPath * path,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
GraphicsPath_AddArcI(
    IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
GraphicsPath_AddBezier(
    IN GraphicsPath * path,
    IN REAL x1,
    IN REAL y1,
    IN REAL x2,
    IN REAL y2,
    IN REAL x3,
    IN REAL y3,
    IN REAL x4,
    IN REAL y4
);

// integer version
Status WINAPI
GraphicsPath_AddBezierI(
    IN GraphicsPath * path,
    IN INT x1,
    IN INT y1,
    IN INT x2,
    IN INT y2,
    IN INT x3,
    IN INT y3,
    IN INT x4,
    IN INT y4
);

Status WINAPI
GraphicsPath_AddBeziers(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
GraphicsPath_AddBeziersI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddCurve(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
GraphicsPath_AddCurveI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddCurve2(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count,
    IN REAL tension
);

// integer version
Status WINAPI
GraphicsPath_AddCurve2I(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count,
    IN REAL tension
);

Status WINAPI
GraphicsPath_AddCurve3(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count,
    IN INT offset,
    IN INT numberOfSegments,
    IN REAL tension
);

// integer version
Status WINAPI
GraphicsPath_AddCurve3I(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count,
    IN INT offset,
    IN INT numberOfSegments,
    IN REAL tension
);

Status WINAPI
GraphicsPath_AddClosedCurve(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
GraphicsPath_AddClosedCurveI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddClosedCurve2(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count,
    IN REAL tension
);

// integer version
Status WINAPI
GraphicsPath_AddClosedCurve2I(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count,
    IN REAL tension
);

Status WINAPI
GraphicsPath_AddRectangle(
    IN GraphicsPath * path,
    IN const RectF * rect
);

// integer version
Status WINAPI
GraphicsPath_AddRectangleI(
    IN GraphicsPath * path,
    IN const Rect * rect
);

Status WINAPI
GraphicsPath_AddRectangles(
    IN GraphicsPath * path,
    IN const RectF * rects,
    IN INT count
);

 // integer version
Status WINAPI
GraphicsPath_AddRectanglesI(
    IN GraphicsPath * path,
    IN const Rect * rects,
    IN INT count
);

Status WINAPI
GraphicsPath_AddEllipse(
    IN GraphicsPath * path,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
GraphicsPath_AddEllipseI(
    IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
GraphicsPath_AddPie(
    IN GraphicsPath * path,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

// integer version
Status WINAPI
GraphicsPath_AddPieI(
    IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
GraphicsPath_AddPolygon(
    IN GraphicsPath * path,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
GraphicsPath_AddPolygonI(
    IN GraphicsPath * path,
    IN const Point * points,
    IN INT count
);

Status WINAPI
GraphicsPath_AddPath(
    IN GraphicsPath * path,
    IN const GraphicsPath * addingPath,
    IN BOOL connect
);

Status WINAPI
GraphicsPath_AddString(
    IN GraphicsPath * path,
    IN const WCHAR * string,
    IN INT length,
    IN const FontFamily * family,
    IN INT style,
    IN REAL emSize,  // World units
    IN const RectF * layoutRect,
    IN const StringFormat  * format
);

// integer version
Status WINAPI
GraphicsPath_AddStringI(
    IN GraphicsPath * path,
    IN const WCHAR * string,
    IN INT length,
    IN const FontFamily * family,
    IN INT style,
    IN REAL emSize,  // World units
    IN const Rect * layoutRect,
    IN const StringFormat  * format
);

Status WINAPI
GraphicsPath_AddString2(
    IN GraphicsPath * path,
    IN const WCHAR * string,
    IN INT length,
    IN const FontFamily * family,
    IN INT style,
    IN REAL emSize,  // World units
    IN const PointF * origin,
    IN const StringFormat  * format
);

// integer version
Status WINAPI
GraphicsPath_AddString2I(
    IN GraphicsPath * path,
    IN const WCHAR * string,
    IN INT length,
    IN const FontFamily * family,
    IN INT style,
    IN REAL emSize,  // World units
    IN const Point * origin,
    IN const StringFormat  * format
);
    
Status WINAPI
GraphicsPath_Transform(
    IN GraphicsPath * path,
    IN Matrix * matrix
);

// This is not always the tightest bounds.

Status WINAPI
GraphicsPath_GetBounds(
    IN GraphicsPath * path,
    OUT RectF * bounds,
    IN const Matrix * matrix, // = NULL
    IN const Pen * pen // = NULL
);

// integer version
Status WINAPI
GraphicsPath_GetBoundsI(
    IN GraphicsPath * path,
    OUT Rect * bounds,
    IN const Matrix * matrix, // = NULL
    IN const Pen * pen // = NULL
);

// Once flattened, the resultant path is made of line segments and
// the original path information is lost.  When matrix is NULL the
// identity matrix is assumed.

Status WINAPI
GraphicsPath_Flatten(
    IN GraphicsPath * path,
    IN Matrix * matrix, // = NULL
    IN REAL flatness // = FlatnessDefault
);

Status WINAPI
GraphicsPath_Widen(
    IN GraphicsPath * path,
    IN Pen * pen,
    IN Matrix * matrix, // = NULL
    IN REAL flatness // = FlatnessDefault
);

Status WINAPI
GraphicsPath_Outline(
    IN GraphicsPath * path,
    IN Matrix * matrix, // = NULL
    IN REAL flatness // = FlatnessDefault
);

// Once this is called, the resultant path is made of line segments and
// the original path information is lost.  When matrix is NULL, the 
// identity matrix is assumed.

Status WINAPI
GraphicsPath_Warp(
    IN GraphicsPath * path,
    IN const PointF * destPoints,
    IN INT count,
    IN const RectF * srcRect,
    IN Matrix * matrix, // = NULL
    IN WarpMode warpMode, // = WarpModePerspective
    IN REAL flatness // = FlatnessDefault
);

INT WINAPI
GraphicsPath_GetPointCount(IN GraphicsPath * path);

Status WINAPI
GraphicsPath_GetPathTypes(
    IN GraphicsPath * path,
    OUT BYTE * types,
    IN INT count
);

Status WINAPI
GraphicsPath_GetPathPoints(
    IN GraphicsPath * path,
    OUT PointF * points,
    IN INT count
);

// integer version
Status WINAPI
GraphicsPath_GetPathPointsI(
    IN GraphicsPath * path,
    OUT Point * points,
    IN INT count
);

BOOL WINAPI
GraphicsPath_IsVisible(
    IN GraphicsPath * path,
    IN REAL x,
    IN REAL y,
    IN Graphics * g // = NULL
);

// integer version
BOOL WINAPI
GraphicsPath_IsVisibleI(
    IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN Graphics * g // = NULL
);

BOOL WINAPI
GraphicsPath_IsOutlineVisible(
    IN GraphicsPath * path,
    IN REAL x,
    IN REAL y,
    IN Pen * pen,
    IN Graphics * g // = NULL
);

// integer version
BOOL WINAPI
GraphicsPath_IsOutlineVisibleI(
    IN GraphicsPath * path,
    IN INT x,
    IN INT y,
    IN Pen * pen,
    IN Graphics * g // = NULL
);


//--------------------------------------------------------------------------
// GraphicsPathIterator class
//--------------------------------------------------------------------------

Status WINAPI
GraphicsPathIterator_Create(
    IN GraphicsPath * path,
    OUT GraphicsPathIterator ** pathIter
);

Status WINAPI
GraphicsPathIterator_Delete(IN GraphicsPathIterator * pathIter);

INT WINAPI
GraphicsPathIterator_NextSubpath(
    IN GraphicsPathIterator * pathIter,
    OUT INT * startIndex,
    OUT INT * endIndex,
    OUT BOOL * isClosed
);

INT WINAPI
GraphicsPathIterator_NextSubpathPath(
    IN GraphicsPathIterator * pathIter,
    OUT GraphicsPath * path,
    OUT BOOL * isClosed
);

INT WINAPI
GraphicsPathIterator_NextPathType(
    IN GraphicsPathIterator * pathIter,
    OUT BYTE * pathType,
    OUT INT * startIndex,
    OUT INT * endIndex
);

INT WINAPI
GraphicsPathIterator_NextMarker(
    IN GraphicsPathIterator * pathIter,
    OUT INT * startIndex,
    OUT INT * endIndex
);

INT WINAPI
GraphicsPathIterator_NextMarkerPath(
    IN GraphicsPathIterator * pathIter,
    OUT GraphicsPath * path
);

INT WINAPI
GraphicsPathIterator_GetCount(IN GraphicsPathIterator * pathIter);

INT WINAPI
GraphicsPathIterator_GetSubpathCount(IN GraphicsPathIterator * pathIter);

BOOL WINAPI
GraphicsPathIterator_HasCurve(IN GraphicsPathIterator * pathIter);

Status WINAPI
GraphicsPathIterator_Rewind(IN GraphicsPathIterator * pathIter);

INT WINAPI
GraphicsPathIterator_Enumerate(
    IN GraphicsPathIterator * pathIter,
    OUT PointF * points,
    OUT BYTE * types,
    IN INT count
);

INT WINAPI
GraphicsPathIterator_CopyData(
    IN GraphicsPathIterator * pathIter,
    OUT PointF * points,
    OUT BYTE * types,
    IN INT startIndex,
    IN INT endIndex
);


//--------------------------------------------------------------------------
// Path Gradient Brush
//--------------------------------------------------------------------------


Status WINAPI
PathGradientBrush_Create(
    IN const PointF * points,
    IN INT count,
    IN WrapMode wrapMode, // = WrapModeClamp
    OUT PathGradientBrush ** pgBrush
);

// integer version
Status WINAPI
PathGradientBrush_CreateI(
    IN const Point * points,
    IN INT count,
    IN WrapMode wrapMode, // = WrapModeClamp
    OUT PathGradientBrush ** pgBrush
);

Status WINAPI
PathGradientBrush_CreateFromPath(
    IN const GraphicsPath * path,
    OUT PathGradientBrush ** pgBrush
);

#define PathGradientBrush_Delete(pgBrush) Brush_Delete(pgBrush)

#define PathGradientBrush_Clone(pgBrush, clone) Brush_Clone(pgBrush, clone)

Color WINAPI
PathGradientBrush_GetCenterColor(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_SetCenterColor(
    IN PathGradientBrush * pgBrush,
    IN Color color
);

INT WINAPI
PathGradientBrush_GetPointCount(IN PathGradientBrush * pgBrush);

INT WINAPI
PathGradientBrush_GetSurroundColorCount(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_GetSurroundColors(
    IN PathGradientBrush * pgBrush,
    OUT Color * colors,
    IN OUT INT * count
);

Status WINAPI
PathGradientBrush_SetSurroundColors(
    IN PathGradientBrush * pgBrush,
    IN const Color * colors,
    IN OUT INT * count
);

Status WINAPI
PathGradientBrush_GetGraphicsPath(
    IN PathGradientBrush * pgBrush,
    OUT GraphicsPath * path
);

Status WINAPI
PathGradientBrush_SetGraphicsPath(
    IN PathGradientBrush * pgBrush,
    IN const GraphicsPath * path
);

Status WINAPI
PathGradientBrush_GetCenterPoint(
    IN PathGradientBrush * pgBrush,
    OUT PointF * point
);

// integer version
Status WINAPI
PathGradientBrush_GetCenterPointI(
    IN PathGradientBrush * pgBrush,
    OUT Point * point
);

Status WINAPI
PathGradientBrush_SetCenterPoint(
    IN PathGradientBrush * pgBrush,
    IN const PointF * point
);

Status WINAPI
PathGradientBrush_SetCenterPointI(
    IN PathGradientBrush * pgBrush,
    IN const Point * point
);

Status WINAPI
PathGradientBrush_GetRectangle(
    IN PathGradientBrush * pgBrush,
    OUT RectF * rect
);

Status WINAPI
PathGradientBrush_GetRectangleI(
    IN PathGradientBrush * pgBrush,
    OUT Rect * rect
);

Status WINAPI
PathGradientBrush_SetGammaCorrection(
    IN PathGradientBrush * pgBrush,
    IN BOOL useGammaCorrection
);

BOOL WINAPI
PathGradientBrush_GetGammaCorrection(IN PathGradientBrush * pgBrush);

INT WINAPI
PathGradientBrush_GetBlendCount(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_GetBlend(
    IN PathGradientBrush * pgBrush,
    OUT REAL * blendFactors,
    OUT REAL * blendPositions,
    IN INT count
);

Status WINAPI
PathGradientBrush_SetBlend(
    IN PathGradientBrush * pgBrush,
    IN const REAL * blendFactors,
    IN const REAL * blendPositions,
    IN INT count
);

INT WINAPI
PathGradientBrush_GetInterpolationColorCount(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_SetInterpolationColors(
    IN PathGradientBrush * pgBrush,
    IN const Color * presetColors,
    IN const REAL * blendPositions,
    IN INT count
);

Status WINAPI
PathGradientBrush_GetInterpolationColors(
    IN PathGradientBrush * pgBrush,
    OUT Color * presetColors,
    OUT REAL * blendPositions,
    IN INT count
);

Status WINAPI
PathGradientBrush_SetBlendBellShape(
    IN PathGradientBrush * pgBrush,
    IN REAL focus,
    IN REAL scale // = 1.0
);

Status WINAPI
PathGradientBrush_SetBlendTriangularShape(
    IN PathGradientBrush * pgBrush,
    IN REAL focus,
    IN REAL scale // = 1.0
);

Status WINAPI
PathGradientBrush_GetTransform(
    IN PathGradientBrush * pgBrush,
    OUT Matrix *matrix
);

Status WINAPI
PathGradientBrush_SetTransform(
    IN PathGradientBrush * pgBrush,
    IN Matrix * matrix
);

Status WINAPI
PathGradientBrush_ResetTransform(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_MultiplyTransform(
    IN PathGradientBrush * pgBrush,
    IN const Matrix * matrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
PathGradientBrush_TranslateTransform(
    IN PathGradientBrush * pgBrush,
    IN REAL dx,
    IN REAL dy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
PathGradientBrush_ScaleTransform(
    IN PathGradientBrush * pgBrush,
    IN REAL sx,
    IN REAL sy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
PathGradientBrush_RotateTransform(
    IN PathGradientBrush * pgBrush,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
PathGradientBrush_GetFocusScales(
    IN PathGradientBrush * pgBrush,
    OUT REAL * xScale,
    OUT REAL * yScale
);

Status WINAPI
PathGradientBrush_SetFocusScales(
    IN PathGradientBrush * pgBrush,
    IN REAL xScale,
    IN REAL yScale
);

WrapMode WINAPI
PathGradientBrush_GetWrapMode(IN PathGradientBrush * pgBrush);

Status WINAPI
PathGradientBrush_SetWrapMode(
    IN PathGradientBrush * pgBrush,
    IN WrapMode wrapMode
);

#pragma endregion

#pragma region GdiplusLineCaps.h
/**************************************************************************\
*
* Copyright (c) 2000-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*    GdiplusLineCaps.h
*
* Abstract:
*
*   GDI+ CustomLineCap APIs
*
\**************************************************************************/

Status WINAPI
CustomLineCap_Create(
    IN GraphicsPath * fillPath,
    IN GraphicsPath * strokePath,
    IN LineCap baseCap,
    IN REAL baseInset,
    OUT CustomLineCap ** customCap
);

Status WINAPI
CustomLineCap_Delete(IN CustomLineCap * customCap);

Status WINAPI
CustomLineCap_SetStrokeCaps(
    IN CustomLineCap * customCap,
    IN LineCap startCap,
    IN LineCap endCap
);

Status WINAPI
CustomLineCap_GetStrokeCaps(
    IN CustomLineCap * customCap,
    OUT LineCap * startCap,
    OUT LineCap * endCap
);

Status WINAPI
CustomLineCap_SetStrokeJoin(
    IN CustomLineCap * customCap,
    IN LineJoin lineJoin
);

LineJoin WINAPI
CustomLineCap_GetStrokeJoin(IN CustomLineCap * customCap);

Status WINAPI
CustomLineCap_SetBaseCap(
    IN CustomLineCap * customCap,
    IN LineCap baseCap
);

LineCap WINAPI
CustomLineCap_GetBaseCap(IN CustomLineCap * customCap);

Status WINAPI
CustomLineCap_SetBaseInset(
    IN CustomLineCap * customCap,
    IN REAL inset
);

REAL WINAPI
CustomLineCap_GetBaseInset(IN CustomLineCap * customCap);

Status WINAPI
CustomLineCap_SetWidthScale(
    IN CustomLineCap * customCap,
    IN REAL widthScale
);

REAL WINAPI
CustomLineCap_GetWidthScale(IN CustomLineCap * customCap);

Status WINAPI
CustomLineCap_Clone(
    IN CustomLineCap * customCap,
    OUT CustomLineCap ** cloneCap
);

typedef EmptyClass AdjustableArrowCap;

#define AdjustableArrowCap_Delete(arrowCap) CustomLineCap_Delete(arrowCap)
#define AdjustableArrowCap_SetStrokeCaps(arrowCap, startCap, endCap) \
    CustomLineCap_SetStrokeCaps(arrowCap, startCap, endCap)
#define AdjustableArrowCap_GetStrokeCaps(arrowCap, startCap, endCap) \
    CustomLineCap_GetStrokeCaps(arrowCap, startCap, endCap)
#define AdjustableArrowCap_SetStrokeJoin(arrowCap, lineJoin) \
    CustomLineCap_SetStrokeJoin(arrowCap, lineJoin)
#define AdjustableArrowCap_GetStrokeJoin(arrowCap) \
    CustomLineCap_GetStrokeJoin(arrowCap)
#define AdjustableArrowCap_SetBaseCap(arrowCap, baseCap) \
    CustomLineCap_SetBaseCap(arrowCap, baseCap)
#define AdjustableArrowCap_GetBaseCap(arrowCap) \
    CustomLineCap_GetBaseCap(arrowCap)
#define AdjustableArrowCap_SetBaseInset(arrowCap, inset) \
    CustomLineCap_SetBaseInset(arrowCap, inset)
#define AdjustableArrowCap_GetBaseInset(arrowCap) \
    CustomLineCap_GetBaseInset(arrowCap)
#define AdjustableArrowCap_SetWidthScale(arrowCap, widthScale) \
    CustomLineCap_SetWidthScale(arrowCap, widthScale)
#define AdjustableArrowCap_GetWidthScale(arrowCap) \
    CustomLineCap_GetWidthScale(arrowCap)
#define AdjustableArrowCap_Clone(arrowCap, clonedCap) \
    CustomLineCap_Clone(arrowCap, clonedCap)

Status WINAPI
AdjustableArrowCap_Create(
    IN REAL height,
    IN REAL width,
    IN BOOL isFilled, // = TRUE
    OUT AdjustableArrowCap ** arrowCap
);

Status WINAPI
AdjustableArrowCap_SetHeight(
    IN AdjustableArrowCap * arrowCap,
    IN REAL height
);

REAL WINAPI
AdjustableArrowCap_GetHeight(IN AdjustableArrowCap * arrowCap);

Status WINAPI
AdjustableArrowCap_SetWidth(
    IN AdjustableArrowCap * arrowCap,
    IN REAL width
);

REAL WINAPI
AdjustableArrowCap_GetWidth(IN AdjustableArrowCap * arrowCap);

Status WINAPI
AdjustableArrowCap_SetMiddleInset(
    IN AdjustableArrowCap * arrowCap,
    IN REAL middleInset
);

REAL WINAPI
AdjustableArrowCap_GetMiddleInset(IN AdjustableArrowCap * arrowCap);

Status WINAPI
AdjustableArrowCap_SetFillState(
    IN AdjustableArrowCap * arrowCap,
    IN BOOL isFilled
);

BOOL WINAPI
AdjustableArrowCap_IsFilled(IN AdjustableArrowCap * arrowCap);

#pragma endregion

#pragma region GdiplusGraphics.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusGraphics.h
*
* Abstract:
*
*   GDI+ Graphics Object
*
\**************************************************************************/

Status WINAPI
Graphics_CreateFromHDC(
    IN HDC hdc,
    OUT Graphics ** graphics
);

Status WINAPI
Graphics_CreateFromHDC2(
    IN HDC hdc,
    IN HANDLE hdevice,
    OUT Graphics ** graphics
);

Status WINAPI
Graphics_CreateFromHWND(
    IN HWND hwnd,
    IN BOOL icm, // = FALSE
    OUT Graphics ** graphics
);

Status WINAPI
Graphics_CreateFromImage(
    IN Image * image,
    OUT Graphics ** graphics
);

Status WINAPI
Graphics_Delete(IN Graphics * graphics);

Status WINAPI
Graphics_Flush(
    IN Graphics * graphics,
    IN FlushIntention intention // = FlushIntentionFlush
);

//------------------------------------------------------------------------
// GDI Interop methods
//------------------------------------------------------------------------

// Locks the graphics until ReleaseDC is called

HDC WINAPI
Graphics_GetHDC(IN Graphics * graphics);

Status WINAPI
Graphics_ReleaseHDC(
    IN Graphics * graphics,
    IN HDC hdc
);

//------------------------------------------------------------------------
// Rendering modes
//------------------------------------------------------------------------

Status WINAPI
Graphics_SetRenderingOrigin(
    IN Graphics * graphics,
    IN INT x,
    IN INT y
);

Status WINAPI
Graphics_GetRenderingOrigin(
    IN Graphics * graphics,
    OUT INT * x,
    OUT INT * y
);

Status WINAPI
Graphics_SetCompositingMode(
    IN Graphics * graphics,
    IN CompositingMode compositingMode
);

CompositingMode WINAPI
Graphics_GetCompositingMode(IN Graphics * graphics);

Status WINAPI
Graphics_SetCompositingQuality(
    IN Graphics * graphics,
    IN CompositingQuality compositingQuality
);

CompositingQuality WINAPI
Graphics_GetCompositingQuality(IN Graphics * graphics);

Status WINAPI
Graphics_SetTextRenderingHint(
    IN Graphics * graphics,
    IN TextRenderingHint newMode
);

TextRenderingHint WINAPI
Graphics_GetTextRenderingHint(IN Graphics * graphics);

Status WINAPI
Graphics_SetTextContrast(
    IN Graphics * graphics,
    IN UINT contrast
);

UINT WINAPI
Graphics_GetTextContrast(IN Graphics * graphics);

InterpolationMode WINAPI
Graphics_GetInterpolationMode(IN Graphics * graphics);

Status WINAPI
Graphics_SetInterpolationMode(
    IN Graphics * graphics,
    IN InterpolationMode interpolationMode
);

SmoothingMode WINAPI
Graphics_GetSmoothingMode(IN Graphics * graphics);

Status WINAPI
Graphics_SetSmoothingMode(
    IN Graphics * graphics,
    IN SmoothingMode smoothingMode
);

PixelOffsetMode WINAPI
Graphics_GetPixelOffsetMode(IN Graphics * graphics);

Status WINAPI
Graphics_SetPixelOffsetMode(
    IN Graphics * graphics,
    IN PixelOffsetMode pixelOffsetMode
);

//------------------------------------------------------------------------
// Manipulate current world transform
//------------------------------------------------------------------------

Status WINAPI
Graphics_SetTransform(
    IN Graphics * graphics,
    IN Matrix * matrix
);

Status WINAPI
Graphics_ResetTransform(IN Graphics * graphics);

Status WINAPI
Graphics_MultiplyTransform(
    IN Graphics * graphics,
    IN const Matrix * matrix,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Graphics_TranslateTransform(
    IN Graphics * graphics,
    IN REAL dx,
    IN REAL dy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Graphics_ScaleTransform(
    IN Graphics * graphics,
    IN REAL sx,
    IN REAL sy,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Graphics_RotateTransform(
    IN Graphics * graphics,
    IN REAL angle,
    IN MatrixOrder order // = MatrixOrderPrepend
);

Status WINAPI
Graphics_GetTransform(
    IN Graphics * graphics,
    OUT Matrix * matrix
);

Status WINAPI
Graphics_SetPageUnit(
    IN Graphics * graphics,
    IN Unit unit
);

Status WINAPI
Graphics_SetPageScale(
    IN Graphics * graphics,
    IN REAL scale
);

Unit WINAPI
Graphics_GetPageUnit(IN Graphics * graphics);

REAL WINAPI
Graphics_GetPageScale(IN Graphics * graphics);

REAL WINAPI
Graphics_GetDpiX(IN Graphics * graphics);

REAL WINAPI
Graphics_GetDpiY(IN Graphics * graphics);

Status WINAPI
Graphics_TransformPoints(
    IN Graphics * graphics,
    IN CoordinateSpace destSpace,
    IN CoordinateSpace srcSpace,
    IN OUT PointF * pts,
    IN INT count
);

// integer version
Status WINAPI
Graphics_TransformPointsI(
    IN Graphics * graphics,
    IN CoordinateSpace destSpace,
    IN CoordinateSpace srcSpace,
    IN OUT Point * pts,
    IN INT count
);

//------------------------------------------------------------------------
// GetNearestColor (for <= 8bpp surfaces).  Note: Alpha is ignored.
//------------------------------------------------------------------------

Status WINAPI
Graphics_GetNearestColor(
    IN Graphics * graphics,
    IN OUT Color * color
);

Status WINAPI
Graphics_DrawLine(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x1,
    IN REAL y1,
    IN REAL x2,
    IN REAL y2
);

// integer version
Status WINAPI
Graphics_DrawLineI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x1,
    IN INT y1,
    IN INT x2,
    IN INT y2
);

Status WINAPI
Graphics_DrawLines(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
Graphics_DrawLinesI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_DrawArc(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

// integer version
Status WINAPI
Graphics_DrawArcI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
Graphics_DrawBezier(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x1,
    IN REAL y1,
    IN REAL x2,
    IN REAL y2,
    IN REAL x3,
    IN REAL y3,
    IN REAL x4,
    IN REAL y4
);

// integer version
Status WINAPI
Graphics_DrawBezierI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x1,
    IN INT y1,
    IN INT x2,
    IN INT y2,
    IN INT x3,
    IN INT y3,
    IN INT x4,
    IN INT y4
);

Status WINAPI
Graphics_DrawBeziers(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count
);

Status WINAPI
Graphics_DrawBeziersI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_DrawRectangle(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
Graphics_DrawRectangleI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
Graphics_DrawRectangles(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const RectF * rects,
    IN INT count
);

// integer version
Status WINAPI
Graphics_DrawRectanglesI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Rect * rects,
    IN INT count
);

Status WINAPI
Graphics_DrawEllipse(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
Graphics_DrawEllipseI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
Graphics_DrawPie(
    IN Graphics * graphics,
    IN Pen * pen,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

// integer version
Status WINAPI
Graphics_DrawPieI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
Graphics_DrawPolygon(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count
);

Status WINAPI
Graphics_DrawPolygonI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_DrawPath(
    IN Graphics * graphics,
    IN Pen * pen,
    IN GraphicsPath * path
);

Status WINAPI
Graphics_DrawCurve(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
Graphics_DrawCurveI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_DrawCurve2(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count,
    IN REAL tension
);

// integer version
Status WINAPI
Graphics_DrawCurve2I(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count,
    IN REAL tension
);

Status WINAPI
Graphics_DrawCurve3(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count,
    IN INT offset,
    IN INT numberOfSegments,
    IN REAL tension // = 0.5f
);

// integer version
Status WINAPI
Graphics_DrawCurve3I(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count,
    IN INT offset,
    IN INT numberOfSegments,
    IN REAL tension // = 0.5f
);

Status WINAPI
Graphics_DrawClosedCurve(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
Graphics_DrawClosedCurveI(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_DrawClosedCurve2(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const PointF * points,
    IN INT count,
    IN REAL tension
);

// integer version
Status WINAPI
Graphics_DrawClosedCurve2I(
    IN Graphics * graphics,
    IN Pen * pen,
    IN const Point * points,
    IN INT count,
    IN REAL tension
);

Status WINAPI
Graphics_Clear(
    IN Graphics * graphics,
    IN Color color
);

Status WINAPI
Graphics_FillRectangle(
    IN Graphics * graphics,
    IN Brush * brush,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
Graphics_FillRectangleI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
Graphics_FillRectangles(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const RectF * rects,
    IN INT count
);

// integer version
Status WINAPI
Graphics_FillRectanglesI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const Rect * rects,
    IN INT count
);

Status WINAPI
Graphics_FillPolygon(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const PointF * points,
    IN INT count,
    IN FillMode fillMode // = FillModeAlternate
);

// integer version
Status WINAPI
Graphics_FillPolygonI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const Point * points,
    IN INT count,
    IN FillMode fillMode // = FillModeAlternate
);

Status WINAPI
Graphics_FillEllipse(
    IN Graphics * graphics,
    IN Brush * brush,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
Graphics_FillEllipseI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
Graphics_FillPie(
    IN Graphics * graphics,
    IN Brush * brush,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

// integer version
Status WINAPI
Graphics_FillPieI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN REAL startAngle,
    IN REAL sweepAngle
);

Status WINAPI
Graphics_FillPath(
    IN Graphics * graphics,
    IN Brush * brush,
    IN GraphicsPath * path
);

Status WINAPI
Graphics_FillClosedCurve(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const PointF * points,
    IN INT count
);

// integer version
Status WINAPI
Graphics_FillClosedCurveI(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const Point * points,
    IN INT count
);

Status WINAPI
Graphics_FillClosedCurve2(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const PointF * points,
    IN INT count,
    IN FillMode fillMode,
    IN REAL tension // = 0.5f
);

// integer version
Status WINAPI
Graphics_FillClosedCurve2I(
    IN Graphics * graphics,
    IN Brush * brush,
    IN const Point * points,
    IN INT count,
    IN FillMode fillMode,
    IN REAL tension // = 0.5f
);

Status WINAPI
Graphics_FillRegion(
    IN Graphics * graphics,
    IN Brush * brush,
    IN Region * region
);

Status WINAPI
Graphics_DrawString(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const RectF * layoutRect,
    IN const StringFormat * stringFormat,
    IN const Brush * brush
);

Status WINAPI
Graphics_DrawStringToPoint(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const PointF * origin,
    IN const StringFormat * stringFormat, // = NULL
    IN const Brush * brush
);

Status WINAPI
Graphics_MeasureString(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const RectF * layoutRect,
    IN const StringFormat * stringFormat, // = NULL
    OUT RectF * boundingBox,
    OUT INT * codepointsFitted, // = NULL
    OUT INT * linesFilled // = NULL
);

Status WINAPI
Graphics_MeasureStringSize(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const SizeF * layoutRectSize,
    IN const StringFormat * stringFormat, // = NULL
    OUT SizeF * size,
    OUT INT * codepointsFitted, // = NULL
    OUT INT * linesFilled // = NULL
);

Status WINAPI
Graphics_MeasureCharacterRanges(
    IN Graphics * graphics,
    IN const WCHAR * string,
    IN INT length,
    IN const Font * font,
    IN const RectF * layoutRect,
    IN const StringFormat * stringFormat,
    IN INT regionCount,
    OUT Region * regions
);

Status WINAPI
Graphics_DrawDriverString(
    IN Graphics * graphics,
    IN const UINT16 * text,
    IN INT length,
    IN const Font * font,
    IN const Brush * brush,
    IN const PointF * positions,
    IN INT flags,
    IN const Matrix * matrix
);

Status WINAPI
Graphics_MeasureDriverString(
    IN Graphics * graphics,
    IN const UINT16 * text,
    IN INT length,
    IN const Font * font,
    IN const PointF * positions,
    IN INT flags,
    IN const Matrix * matrix,
    OUT RectF * boundingBox
);

// Draw a cached bitmap on this graphics destination offset by
// x, y. Note this will fail with WrongState if the CachedBitmap
// native format differs from this Graphics.

Status WINAPI
Graphics_DrawCachedBitmap(
    IN Graphics * graphics,
    IN CachedBitmap * cb,
    IN INT x,
    IN INT y
);

Status WINAPI
Graphics_DrawImage(
    IN Graphics * graphics,
    IN Image * image,
    IN REAL x,
    IN REAL y
);

// integer version
Status WINAPI
Graphics_DrawImageI(
    IN Graphics * graphics,
    IN Image * image,
    IN INT x,
    IN INT y
);

Status WINAPI
Graphics_DrawImageRect(
    IN Graphics * graphics,
    IN Image * image,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
Status WINAPI
Graphics_DrawImageRectI(
    IN Graphics * graphics,
    IN Image * image,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

Status WINAPI
Graphics_DrawImagePoints(
    IN Graphics * graphics,
    IN Image * image,
    IN const PointF * destPoints,
    IN INT count
);

// integer version
Status WINAPI
Graphics_DrawImagePointsI(
    IN Graphics * graphics,
    IN Image * image,
    IN const Point * destPoints,
    IN INT count
);

Status WINAPI
Graphics_DrawImagePointRect(
    IN Graphics * graphics,
    IN Image * image,
    IN REAL x,
    IN REAL y,
    IN REAL srcx,
    IN REAL srcy,
    IN REAL srcwidth,
    IN REAL srcheight,
    IN Unit srcUnit
);

// integer version
Status WINAPI
Graphics_DrawImagePointRectI(
    IN Graphics * graphics,
    IN Image * image,
    IN INT x,
    IN INT y,
    IN INT srcx,
    IN INT srcy,
    IN INT srcwidth,
    IN INT srcheight,
    IN Unit srcUnit
);

Status WINAPI
Graphics_DrawImageRectRect(
    IN Graphics * graphics,
    IN Image * image,
    IN const RectF * destRect,
    IN REAL srcx,
    IN REAL srcy,
    IN REAL srcwidth,
    IN REAL srcheight,
    IN Unit srcUnit,
    IN const ImageAttributes * imageAttributes, // = NULL
    IN DrawImageAbort callback, // = NULL
    IN VOID * callbackData // = NULL
);

// integer version
Status WINAPI
Graphics_DrawImageRectRectI(
    IN Graphics * graphics,
    IN Image * image,
    IN const Rect * destRect,
    IN INT srcx,
    IN INT srcy,
    IN INT srcwidth,
    IN INT srcheight,
    IN Unit srcUnit,
    IN const ImageAttributes * imageAttributes, // = NULL
    IN DrawImageAbort callback, // = NULL
    IN VOID * callbackData // = NULL
);

Status WINAPI
Graphics_DrawImagePointsRect(
    IN Graphics * graphics,
    IN Image * image,
    IN const PointF * destPoints,
    IN INT count,
    IN REAL srcx,
    IN REAL srcy,
    IN REAL srcwidth,
    IN REAL srcheight,
    IN Unit srcUnit,
    IN const ImageAttributes * imageAttributes, // = NULL
    IN DrawImageAbort callback, // = NULL
    IN VOID * callbackData // = NULL
);

// integer version
Status WINAPI
Graphics_DrawImagePointsRectI(
    IN Graphics * graphics,
    IN Image * image,
    IN const Point * destPoints,
    IN INT count,
    IN INT srcx,
    IN INT srcy,
    IN INT srcwidth,
    IN INT srcheight,
    IN Unit srcUnit,
    IN const ImageAttributes * imageAttributes, // = NULL
    IN DrawImageAbort callback, // = NULL
    IN VOID * callbackData // = NULL
);

// The following methods are for playing an EMF+ to a graphics
// via the enumeration interface.  Each record of the EMF+ is
// sent to the callback (along with the callbackData).  Then
// the callback can invoke the Metafile::PlayRecord method
// to play the particular record.

Status WINAPI
Graphics_EnumerateMetafile(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const PointF * destPoint,
    IN EnumerateMetafileProc  callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Point * destPoint,
    IN EnumerateMetafileProc  callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_EnumerateMetafileDestRect(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const RectF * destRect,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileDestRectI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Rect * destRect,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_EnumerateMetafileDestPoints(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const PointF * destPoints,
    IN INT count,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileDestPointsI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Point * destPoints,
    IN INT count,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPoint(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const PointF * destPoint,
    IN const RectF * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPointI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Point * destPoint,
    IN const Rect * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestRect(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const RectF * destRect,
    IN const RectF * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileSrcRectDestRectI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Rect * destRect,
    IN const Rect * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPoints(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const PointF * destPoints,
    IN INT count,
    IN const RectF * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

// integer version
Status WINAPI
Graphics_EnumerateMetafileSrcRectDestPointsI(
    IN Graphics * graphics,
    IN const Metafile * metafile,
    IN const Point * destPoints,
    IN INT count,
    IN const Rect * srcRect,
    IN Unit srcUnit,
    IN EnumerateMetafileProc callback,
    IN VOID * callbackData, // = NULL
    IN const ImageAttributes * imageAttributes // = NULL
);

Status WINAPI
Graphics_SetClipGraphics(
    IN Graphics * graphics,
    IN Graphics * srcGraphics,
    IN CombineMode combineMode // = CombineModeReplace
);

Status WINAPI
Graphics_SetClipRect(
    IN Graphics * graphics,
    IN const RectF * rect,
    IN CombineMode combineMode // = CombineModeReplace
);

// integer version
Status WINAPI
Graphics_SetClipRectI(
    IN Graphics * graphics,
    IN const Rect * rect,
    IN CombineMode combineMode // = CombineModeReplace
);

Status WINAPI
Graphics_SetClipPath(
    IN Graphics * graphics,
    IN GraphicsPath * path,
    IN CombineMode combineMode // = CombineModeReplace
);

Status WINAPI
Graphics_SetClipRegion(
    IN Graphics * graphics,
    IN Region * region,
    IN CombineMode combineMode // = CombineModeReplace
);

// This is different than the other SetClip methods because it assumes
// that the HRGN is already in device units, so it doesn't transform
// the coordinates in the HRGN.

Status WINAPI
Graphics_SetClipHRGN(
    IN Graphics * graphics,
    IN HRGN hRgn,
    IN CombineMode combineMode // = CombineModeReplace
);

Status WINAPI
Graphics_IntersectClipRect(
    IN Graphics * graphics,
    IN const RectF * rect
);

// integer version
Status WINAPI
Graphics_IntersectClipRectI(
    IN Graphics * graphics,
    IN const Rect * rect
);

Status WINAPI
Graphics_IntersectClipRegion(
    IN Graphics * graphics,
    IN Region * region
);

Status WINAPI
Graphics_ExcludeClipRect(
    IN Graphics * graphics,
    IN const RectF * rect
);

// integer version
Status WINAPI
Graphics_ExcludeClipRectI(
    IN Graphics * graphics,
    IN const Rect * rect
);

Status WINAPI
Graphics_ExcludeClipRegion(
    IN Graphics * graphics,
    IN Region * region
);

Status WINAPI
Graphics_ResetClip(IN Graphics * graphics);

Status WINAPI
Graphics_TranslateClip(
    IN Graphics * graphics,
    IN REAL dx,
    IN REAL dy
);

// integer version
Status WINAPI
Graphics_TranslateClipI(
    IN Graphics * graphics,
    IN INT dx,
    IN INT dy
);

Status WINAPI
Graphics_GetClip(
    IN Graphics * graphics,
    OUT Region * region
);

Status WINAPI
Graphics_GetClipBounds(
    IN Graphics * graphics,
    OUT RectF * rect
);

Status WINAPI
Graphics_GetClipBoundsI(
    IN Graphics * graphics,
    OUT Rect * rect
);

BOOL WINAPI
Graphics_IsClipEmpty(IN Graphics * graphics);

Status WINAPI
Graphics_GetVisibleClipBounds(
    IN Graphics * graphics,
    OUT RectF * rect
);

// integer version
Status WINAPI
Graphics_GetVisibleClipBoundsI(
    IN Graphics * graphics,
    OUT Rect * rect
);

BOOL WINAPI
Graphics_IsVisibleClipEmpty(IN Graphics * graphics);

BOOL WINAPI
Graphics_IsVisiblePoint(
    IN Graphics * graphics,
    IN REAL x,
    IN REAL y
);

// integer version
BOOL WINAPI
Graphics_IsVisiblePointI(
    IN Graphics * graphics,
    IN INT x,
    IN INT y
);

BOOL WINAPI
Graphics_IsVisibleRect(
    IN Graphics * graphics,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height
);

// integer version
BOOL WINAPI
Graphics_IsVisibleRectI(
    IN Graphics * graphics,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height
);

GraphicsState
Graphics_Save(IN Graphics * graphics);

Status WINAPI
Graphics_Restore(
    IN Graphics * graphics,
    IN GraphicsState gstate
);

GraphicsContainer WINAPI
Graphics_BeginContainer(
    IN Graphics * graphics,
    IN const RectF * dstRect,
    IN const RectF * srcRect,
    IN Unit unit
);

// integer version
GraphicsContainer WINAPI
Graphics_BeginContainerI(
    IN Graphics * graphics,
    IN const Rect * dstRect,
    IN const Rect * srcRect,
    IN Unit unit
);

GraphicsContainer WINAPI
Graphics_BeginContainer2(IN Graphics * graphics);

Status WINAPI
Graphics_EndContainer(
    IN Graphics * graphics,
    IN GraphicsContainer state
);

// Only valid when recording metafiles.

Status WINAPI
Graphics_AddMetafileComment(
    IN Graphics * graphics,
    IN const BYTE * data,
    IN UINT sizeData
);

HPALETTE WINAPI
Graphics_GetHalftonePalette();

#pragma endregion

#pragma region GdiplusBitmap.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusBitmap.h
*
* Abstract:
*
*   GDI+ Bitmap class
*
\**************************************************************************/

Status WINAPI
Image_LoadFromFile(
    IN const WCHAR * filename,
    IN BOOL useEmbeddedColorManagement,
    OUT Image ** image
);

Status WINAPI
Image_LoadFromStream(
    IN IStream * stream,
    IN BOOL useEmbeddedColorManagement,
    OUT Image ** image
);

Status WINAPI
Image_Dispose(IN Image * image);

Status WINAPI
Image_Clone(
    IN Image * image,
    OUT Image ** clone
);

UINT WINAPI
Image_GetEncoderParameterListSize(
    IN Image * image,
    IN const CLSID * clsidEncoder
);

Status WINAPI
Image_GetEncoderParameterList(
    IN Image * image,
    IN const CLSID * clsidEncoder,
    IN UINT size,
    OUT EncoderParameters * buffer
);

Status WINAPI
Image_SaveToFile(
    IN Image * image,
    IN const WCHAR * filename,
    IN const CLSID * clsidEncoder,
    IN const EncoderParameters * encoderParams
);

Status WINAPI
Image_SaveToStream(
    IN Image * image,
    IN IStream * stream,
    IN const CLSID * clsidEncoder,
    IN const EncoderParameters * encoderParams
);

Status WINAPI
Image_SaveAdd(
    IN Image * image,
    IN const EncoderParameters * encoderParams
);

Status WINAPI
Image_SaveAddImage(
    IN Image * image,
    IN Image * newImage,
    IN const EncoderParameters * encoderParams
);

ImageType WINAPI
Image_GetType(IN Image * image);

Status WINAPI
Image_GetPhysicalDimension(
    IN Image * image,
    OUT SizeF * size
);

Status WINAPI
Image_GetBounds(
    IN Image * image,
    OUT RectF * srcRect,
    OUT Unit * srcUnit
);

UINT WINAPI
Image_GetWidth(IN Image * image);

UINT WINAPI
Image_GetHeight(IN Image * image);

REAL WINAPI
Image_GetHorizontalResolution(IN Image * image);

REAL WINAPI
Image_GetVerticalResolution(IN Image * image);

UINT WINAPI
Image_GetFlags(IN Image * image);

Status WINAPI
Image_GetRawFormat(
    IN Image * image,
    OUT GUID * format
);

PixelFormat WINAPI
Image_GetPixelFormat(IN Image * image);

INT WINAPI
Image_GetPaletteSize(IN Image * image);

Status WINAPI
Image_GetPalette(
    IN Image * image,
    OUT ColorPalette * palette,
    IN INT size
);

Status WINAPI
Image_SetPalette(
    IN Image * image,
    IN const ColorPalette * palette
);

Status WINAPI
Image_GetThumbnailImage(
    IN Image * image,
    IN UINT thumbWidth,
    IN UINT thumbHeight,
    IN GetThumbnailImageAbort callback,
    IN VOID * callbackData,
    OUT Image ** thumbnailImage
);

UINT WINAPI
Image_GetFrameDimensionsCount(IN Image * image);

Status WINAPI
Image_GetFrameDimensionsList(
    IN Image * image,
    OUT GUID * dimensionIDs,
    IN UINT count
);

UINT WINAPI
Image_GetFrameCount(
    IN Image * image,
    IN const GUID * dimensionID
);

Status WINAPI
Image_SelectActiveFrame(
    IN Image * image,
    IN const GUID * dimensionID,
    IN UINT frameIndex
);

Status WINAPI
Image_RotateFlip(
    IN Image * image,
    IN RotateFlipType rotateFlipType
);

UINT WINAPI
Image_GetPropertyCount(IN Image * image);

Status WINAPI
Image_GetPropertyIdList(
    IN Image * image,
    IN UINT numOfProperty,
    OUT PROPID * list
);

UINT WINAPI
Image_GetPropertyItemSize(
    IN Image * image,
    IN PROPID propId
);

Status WINAPI
Image_GetPropertyItem(
    IN Image * image,
    IN PROPID propId,
    IN UINT propSize,
    OUT PropertyItem * buffer
);

Status WINAPI
Image_GetPropertySize(
    IN Image * image,
    OUT UINT * totalBufferSize,
    OUT UINT * numProperties
);

Status WINAPI
Image_GetAllPropertyItems(
    IN Image * image,
    IN UINT totalBufferSize,
    IN UINT numProperties,
    OUT PropertyItem * allItems
);

Status WINAPI
Image_RemovePropertyItem(
    IN Image * image,
    IN PROPID propId
);

Status WINAPI
Image_SetPropertyItem(
    IN Image * image,
    IN const PropertyItem * item
);

#define Bitmap_Dispose(bitmap) Image_Dispose(bitmap)
#define Bitmap_Clone(bitmap, clone) Image_Clone(bitmap, clone)
#define Bitmap_GetEncoderParameterListSize(bitmap, clsidEncoder) \
    Image_GetEncoderParameterListSize(bitmap, clsidEncoder)
#define Bitmap_GetEncoderParameterList(bitmap, clsidEncoder, size, buffer) \
    Image_GetEncoderParameterList(bitmap, clsidEncoder, size, buffer)
#define Bitmap_SaveToFile(bitmap, filename, clsidEncoder, encoderParams) \
    Image_SaveToFile(bitmap, filename, clsidEncoder, encoderParams)
#define Bitmap_SaveToStream(bitmap, stream, clsidEncoder, encoderParams) \
    Image_SaveToStream(bitmap, stream, clsidEncoder, encoderParams)
#define Bitmap_SaveAdd(bitmap, encoderParams) \
    Image_SaveAdd(bitmap, encoderParams)
#define Bitmap_SaveAddImage(bitmap, newBitmap, encoderParams) \
    Image_SaveAddImage(bitmap, newBitmap, encoderParams)
#define Bitmap_GetType(bitmap) Image_GetType(bitmap)
#define Bitmap_GetPhysicalDimension(bitmap, size) \
    Image_GetPhysicalDimension(bitmap, size)
#define Bitmap_GetBounds(bitmap, srcRect, srcUnit) \
    Image_GetBounds(bitmap, srcRect, srcUnit)
#define Bitmap_GetWidth(bitmap) Image_GetWidth(bitmap)
#define Bitmap_GetHeight(bitmap) Image_GetHeight(bitmap)
#define Bitmap_GetHorizontalResolution(bitmap) \
    Image_GetHorizontalResolution(bitmap)
#define Bitmap_GetVerticalResolution(bitmap) \
    Image_GetVerticalResolution(bitmap)
#define Bitmap_GetFlags(bitmap) Image_GetFlags(bitmap)
#define Bitmap_GetRawFormat(bitmap, format) Image_GetRawFormat(bitmap, format)
#define Bitmap_GetPixelFormat(bitmap) Image_GetPixelFormat(bitmap)
#define Bitmap_GetPaletteSize(bitmap) Image_GetPaletteSize(bitmap)
#define Bitmap_GetPalette(bitmap, palette, size) \
    Image_GetPalette(bitmap, palette, size)
#define Bitmap_SetPalette(bitmap, palette) Image_SetPalette(bitmap, palette)
#define Bitmap_GetThumbnailImage \
    (bitmap, thumbWidth, thumbHeight, callback, callbackData, thumbnailImage) \
    Image_GetThumbnailImage \
    (bitmap, thumbWidth, thumbHeight, callback, callbackData, thumbnailImage)
#define Bitmap_GetFrameDimensionsCount(bitmap) \
    Image_GetFrameDimensionsCount(bitmap)
#define Bitmap_GetFrameDimensionsList(bitmap, dimensionIDs, count) \
    Image_GetFrameDimensionsList(bitmap, dimensionIDs, count)
#define Bitmap_GetFrameCount(bitmap, dimensionID) \
    Image_GetFrameCount(bitmap, dimensionID)
#define Bitmap_SelectActiveFrame(bitmap, dimensionID, frameIndex) \
    Image_SelectActiveFrame(bitmap, dimensionID, frameIndex)
#define Bitmap_RotateFlip(bitmap, rotateFlipType) \
    Image_RotateFlip(bitmap, rotateFlipType)
#define Bitmap_GetPropertyCount(bitmap) Image_GetPropertyCount(bitmap)
#define Bitmap_GetPropertyIdList(bitmap, numOfProperty, list) \
    Image_GetPropertyIdList(bitmap, numOfProperty, list)
#define Bitmap_GetPropertyItemSize(bitmap, propId) \
    Image_GetPropertyItemSize(bitmap, propId)
#define Bitmap_GetPropertyItem(bitmap, propId, propSize, buffer) \
    Image_GetPropertyItem(bitmap, propId, propSize, buffer)
#define Bitmap_GetPropertySize(bitmap, totalBufferSize, numProperties) \
    Image_GetPropertySize(bitmap, totalBufferSize, numProperties)
#define Bitmap_GetAllPropertyItems \
    (bitmap, totalBufferSize, numProperties, allItems) \
    Image_GetAllPropertyItems(bitmap, totalBufferSize, numProperties, allItems)
#define Bitmap_RemovePropertyItem(image, propId) \
    Image_RemovePropertyItem(image, propId)
#define Bitmap_SetPropertyItem(bitmap, item) \
    Image_SetPropertyItem(bitmap, item)

Status WINAPI
Bitmap_CreateFromFile(
    IN const WCHAR * filename,
    IN BOOL useEmbeddedColorManagement,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromStream(
    IN IStream * stream,
    IN BOOL useEmbeddedColorManagement,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromScan0(
    IN INT width,
    IN INT height,
    IN INT stride, // = 0
    IN PixelFormat format,
    IN BYTE * scan0, // = NULL
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromGraphics(
    IN INT width,
    IN INT height,
    IN Graphics * target,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromGdiDib(
    IN const BITMAPINFO * gdiBitmapInfo,
    IN VOID * gdiBitmapData,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromHBITMAP(
    IN HBITMAP hbm,
    IN HPALETTE hpal,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromHICON(
    IN HICON hicon,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_CreateFromResource(
    IN HINSTANCE hInstance,
    IN const WCHAR * bitmapName,
    OUT Bitmap ** bitmap
);

Status WINAPI
Bitmap_GetHBITMAP(
    IN Bitmap * bitmap,
    IN Color colorBackground,
    OUT HBITMAP * hbmReturn
);

Status WINAPI
Bitmap_GetHICON(
    IN Bitmap * bitmap,
    OUT HICON * hiconReturn
);

Status WINAPI
Bitmap_CloneArea(
    IN Bitmap * bitmap,
    IN REAL x,
    IN REAL y,
    IN REAL width,
    IN REAL height,
    IN PixelFormat format,
    OUT Bitmap ** clone
);

// integer version
Status WINAPI
Bitmap_CloneAreaI(
    IN Bitmap * bitmap,
    IN INT x,
    IN INT y,
    IN INT width,
    IN INT height,
    IN PixelFormat format,
    OUT Bitmap ** clone
);

Status WINAPI
Bitmap_LockBits(
    IN Bitmap * bitmap,
    IN const Rect* rect,
    IN UINT flags,
    IN PixelFormat format,
    OUT BitmapData * lockedBitmapData
);

Status WINAPI
Bitmap_UnlockBits(
    IN Bitmap * bitmap,
    IN BitmapData * lockedBitmapData
);

Color WINAPI
Bitmap_GetPixel(
    IN Bitmap * bitmap,
    IN INT x,
    IN INT y
);

Status WINAPI
Bitmap_SetPixel(
    IN Bitmap * bitmap,
    IN INT x,
    IN INT y,
    IN Color color
);

Status WINAPI
Bitmap_SetResolution(
    IN Bitmap * bitmap,
    IN REAL xdpi,
    IN REAL ydpi
);

#pragma endregion

#pragma region GdiplusMetafile.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusMetafile.h
*
* Abstract:
*
*   GDI+ Metafile class
*
\**************************************************************************/

#define Metafile_Dispose(metafile) Image_Dispose(metafile)
#define Metafile_Clone(metafile, clone) Image_Clone(metafile, clone)
#define Metafile_GetEncoderParameterListSize(metafile, clsidEncoder) \
    Image_GetEncoderParameterListSize(metafile, clsidEncoder)
#define Metafile_GetEncoderParameterList(metafile, clsidEncoder, size, buffer) \
    Image_GetEncoderParameterList(metafile, clsidEncoder, size, buffer)
#define Metafile_SaveToFile(metafile, filename, clsidEncoder, encoderParams) \
    Image_SaveToFile(metafile, filename, clsidEncoder, encoderParams)
#define Metafile_SaveToStream(metafile, stream, clsidEncoder, encoderParams) \
    Image_SaveToStream(metafile, stream, clsidEncoder, encoderParams)
#define Metafile_SaveAdd(metafile, encoderParams) \
    Image_SaveAdd(metafile, encoderParams)
#define Metafile_SaveAddImage(metafile, newMetafile, encoderParams) \
    Image_SaveAddImage(metafile, newMetafile, encoderParams)
#define Metafile_GetType(metafile) Image_GetType(metafile)
#define Metafile_GetPhysicalDimension(metafile, size) \
    Image_GetPhysicalDimension(metafile, size)
#define Metafile_GetBounds(metafile, srcRect, srcUnit) \
    Image_GetBounds(metafile, srcRect, srcUnit)
#define Metafile_GetWidth(metafile) Image_GetWidth(metafile)
#define Metafile_GetHeight(metafile) Image_GetHeight(metafile)
#define Metafile_GetHorizontalResolution(metafile) \
    Image_GetHorizontalResolution(metafile)
#define Metafile_GetVerticalResolution(metafile) \
    Image_GetVerticalResolution(metafile)
#define Metafile_GetFlags(metafile) Image_GetFlags(metafile)
#define Metafile_GetRawFormat(metafile, format) Image_GetRawFormat(metafile, format)
#define Metafile_GetPixelFormat(metafile) Image_GetPixelFormat(metafile)
#define Metafile_GetPaletteSize(metafile) Image_GetPaletteSize(metafile)
#define Metafile_GetPalette(metafile, palette, size) \
    Image_GetPalette(metafile, palette, size)
#define Metafile_SetPalette(metafile, palette) Image_SetPalette(metafile, palette)
#define Metafile_GetThumbnailImage \
    (metafile, thumbWidth, thumbHeight, callback, callbackData, thumbnailImage) \
    Image_GetThumbnailImage \
    (metafile, thumbWidth, thumbHeight, callback, callbackData, thumbnailImage)
#define Metafile_GetFrameDimensionsCount(metafile) \
    Image_GetFrameDimensionsCount(metafile)
#define Metafile_GetFrameDimensionsList(metafile, dimensionIDs, count) \
    Image_GetFrameDimensionsList(metafile, dimensionIDs, count)
#define Metafile_GetFrameCount(metafile, dimensionID) \
    Image_GetFrameCount(metafile, dimensionID)
#define Metafile_SelectActiveFrame(metafile, dimensionID, frameIndex) \
    Image_SelectActiveFrame(metafile, dimensionID, frameIndex)
#define Metafile_RotateFlip(metafile, rotateFlipType) \
    Image_RotateFlip(metafile, rotateFlipType)
#define Metafile_GetPropertyCount(metafile) Image_GetPropertyCount(metafile)
#define Metafile_GetPropertyIdList(metafile, numOfProperty, list) \
    Image_GetPropertyIdList(metafile, numOfProperty, list)
#define Metafile_GetPropertyItemSize(metafile, propId) \
    Image_GetPropertyItemSize(metafile, propId)
#define Metafile_GetPropertyItem(metafile, propId, propSize, buffer) \
    Image_GetPropertyItem(metafile, propId, propSize, buffer)
#define Metafile_GetPropertySize(metafile, totalBufferSize, numProperties) \
    Image_GetPropertySize(metafile, totalBufferSize, numProperties)
#define Metafile_GetAllPropertyItems \
    (metafile, totalBufferSize, numProperties, allItems) \
    Image_GetAllPropertyItems(metafile, totalBufferSize, numProperties, allItems)
#define Metafile_RemovePropertyItem(image, propId) \
    Image_RemovePropertyItem(image, propId)
#define Metafile_SetPropertyItem(metafile, item) \
    Image_SetPropertyItem(metafile, item)

Status WINAPI
Metafile_CreateFromWmf(
    IN HMETAFILE hWmf,
    IN const WmfPlaceableFileHeader * wmfPlaceableFileHeader,
    IN BOOL deleteWmf,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateFromEmf(
    IN HENHMETAFILE hEmf,
    IN BOOL deleteEmf,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateFromFile(
    IN const WCHAR * filename,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateFromWmfFile(
    IN const WCHAR * filename,
    IN const WmfPlaceableFileHeader * wmfPlaceableFileHeader,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateFromStream(
    IN IStream * stream,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateRecord(
    IN HDC referenceHdc,
    IN const RectF * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);

// integer version
Status WINAPI
Metafile_CreateRecordI(
    IN HDC referenceHdc,
    IN const Rect * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateRecordFileName(
    IN const WCHAR * fileName,
    IN HDC referenceHdc,
    IN const RectF * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);

// integer version
Status WINAPI
Metafile_CreateRecordFileNameI(
    IN const WCHAR * fileName,
    IN HDC referenceHdc,
    IN const Rect * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);

Status WINAPI
Metafile_CreateRecordStream(
    IN IStream * stream,
    IN HDC referenceHdc,
    IN const RectF * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);

// integer version
Status WINAPI
Metafile_CreateRecordStreamI(
    IN IStream * stream,
    IN HDC referenceHdc,
    IN const Rect * frameRect,
    IN MetafileFrameUnit frameUnit,
    IN EmfType type,
    IN const WCHAR * description,
    OUT Metafile ** metafile
);
 
Status WINAPI
Metafile_GetMetafileHeaderFromEmf(
    IN HENHMETAFILE hEmf,
    OUT MetafileHeader * header
);

Status WINAPI
Metafile_GetMetafileHeaderFromFile(
    IN const WCHAR * filename,
    OUT MetafileHeader * header
);

Status WINAPI
Metafile_GetMetafileHeaderFromStream(
    IN IStream * stream,
    OUT MetafileHeader * header
);

Status WINAPI
Metafile_GetMetafileHeaderFromMetafile(
    IN Metafile * metafile,
    OUT MetafileHeader * header
);

// Once this method is called, the Metafile object is in an invalid state
// and can no longer be used.  It is the responsiblity of the caller to
// invoke DeleteEnhMetaFile to delete this hEmf.

HENHMETAFILE WINAPI
Metafile_GetHENHMETAFILE(IN Metafile * metafile);

// Used in conjuction with Graphics::EnumerateMetafile to play an EMF+
// The data must be DWORD aligned if it's an EMF or EMF+.  It must be
// WORD aligned if it's a WMF.

Status WINAPI
Metafile_PlayRecord(
    IN Metafile * metafile,
    IN EmfPlusRecordType recordType,
    IN UINT flags,
    IN UINT dataSize,
    IN const BYTE * data
);

// If you're using a printer HDC for the metafile, but you want the
// metafile rasterized at screen resolution, then use this API to set
// the rasterization dpi of the metafile to the screen resolution,
// e.g. 96 dpi or 120 dpi.

Status WINAPI
Metafile_SetDownLevelRasterizationLimit(
    IN Metafile * metafile,
    IN UINT metafileRasterizationLimitDpi
);

UINT WINAPI
Metafile_GetDownLevelRasterizationLimit(IN Metafile * metafile);

UINT WINAPI
Metafile_EmfToWmfBits(
    IN HENHMETAFILE hemf,
    IN UINT cbData16,
    OUT LPBYTE pData16,
    IN INT iMapMode,
    IN INT eFlags
);

#pragma endregion

#pragma region GdiplusCachedBitmap.h
/**************************************************************************
*
* Copyright (c) 2000 Microsoft Corporation
*
* Module Name:
*
*   CachedBitmap class definition
*
* Abstract:
*
*   GDI+ CachedBitmap is a representation of an accelerated drawing
*   that has restrictions on what operations are allowed in order
*   to accelerate the drawing to the destination.
*
*   Look for class definition in GdiplusHeaders.h
*
**************************************************************************/

Status WINAPI
CachedBitmap_Create(
    IN Bitmap * bitmap,
    IN Graphics * graphics,
    OUT CachedBitmap ** cachedBitmap
);

Status WINAPI
CachedBitmap_Delete(IN CachedBitmap * cachedBitmap);

#pragma endregion

#pragma region GdiplusRegion.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusRegion.h
*
* Abstract:
*
*   GDI+ Region class implementation
*
\**************************************************************************/

Status WINAPI
Region_Create(OUT Region ** region);

Status WINAPI
Region_CreateFromRect(
    IN const RectF * rect,
    OUT Region ** region
);

// integer version
Status WINAPI
Region_CreateFromRectI(
    IN const Rect * rect,
    OUT Region ** region
);

Status WINAPI
Region_CreateFromPath(
    IN GraphicsPath * path,
    OUT Region ** region
);

Status WINAPI
Region_CreateFromRgnData(
    IN const BYTE * regionData,
    IN INT size,
    OUT Region ** region
);

Status WINAPI
Region_CreateFromHrgn(
    IN HRGN hRgn,
    OUT Region ** region
);

Status WINAPI
Region_Delete(IN Region * region);

Status WINAPI
Region_Clone(
    IN Region * region,
    OUT Region ** clone
);

Status WINAPI
Region_MakeInfinite(IN Region * region);

Status WINAPI
Region_MakeEmpty(IN Region * region);

Status WINAPI
Region_IntersectRect(
    IN Region * region,
    IN const RectF * rect
);

// integer version
Status WINAPI
Region_IntersectRectI(
    IN Region * region,
    IN const Rect * rect
);

Status WINAPI
Region_IntersectPath(
    IN Region * region,
    IN GraphicsPath * path
);

Status WINAPI
Region_IntersectRegion(
    IN Region * region,
    IN Region * srcRegion
);

Status WINAPI
Region_UnionRect(
    IN Region * region,
    IN const RectF * rect
);

// integer version
Status WINAPI
Region_UnionRectI(
    IN Region * region,
    IN const Rect * rect
);

Status WINAPI
Region_UnionPath(
    IN Region * region,
    IN GraphicsPath * path
);

Status WINAPI
Region_UnionRegion(
    IN Region * region,
    IN Region * srcRegion
);

Status WINAPI
Region_XorRect(
    IN Region * region,
    IN const RectF * rect
);

// integer version
Status WINAPI
Region_XorRectI(
    IN Region * region,
    IN const Rect * rect
);

Status WINAPI
Region_XorPath(
    IN Region * region,
    IN GraphicsPath * path
);

Status WINAPI
Region_XorRegion(
    IN Region * region,
    IN Region * srcRegion
);

Status WINAPI
Region_ExcludeRect(
    IN Region * region,
    IN const RectF * rect
);

// integer version
Status WINAPI
Region_ExcludeRectI(
    IN Region * region,
    IN const Rect * rect
);

Status WINAPI
Region_ExcludePath(
    IN Region * region,
    IN GraphicsPath * path
);

Status WINAPI
Region_ExcludeRegion(
    IN Region * region,
    IN Region * srcRegion
);

Status WINAPI
Region_ComplementRect(
    IN Region * region,
    IN const RectF * rect
);

// integer version
Status WINAPI
Region_ComplementRectI(
    IN Region * region,
    IN const Rect * rect
);

Status WINAPI
Region_ComplementPath(
    IN Region * region,
    IN GraphicsPath * path
);

Status WINAPI
Region_ComplementRegion(
    IN Region * region,
    IN Region * srcRegion
);

Status WINAPI
Region_Translate(
    IN Region * region,
    IN REAL dx,
    IN REAL dy
);

// integer version
Status WINAPI
Region_TranslateI(
    IN Region * region,
    IN INT dx,
    IN INT dy
);

Status WINAPI
Region_Transform(
    IN Region * region,
    IN Matrix * matrix
);

Status WINAPI
Region_GetBounds(
    IN Region * region,
    OUT RectF * rect,
    IN Graphics * g
);

// integer version
Status WINAPI
Region_GetBoundsI(
    IN Region * region,
    OUT Rect * rect,
    IN Graphics * g
);

HRGN WINAPI
Region_GetHRGN(
    IN Region * region,
    IN Graphics * g
);

BOOL WINAPI
Region_IsEmpty(
    IN Region * region,
    IN Graphics * g
);

BOOL WINAPI
Region_IsInfinite(
    IN Region * region,
    IN Graphics * g
);

BOOL WINAPI
Region_Equals(
    IN Region * region,
    IN Region * region2,
    IN Graphics * g
);

// Get the size of the buffer needed for the GetData method
UINT WINAPI
Region_GetDataSize(IN Region * region);

// buffer     - where to put the data
// bufferSize - how big the buffer is (should be at least as big as GetDataSize())
// sizeFilled - if not NULL, this is an OUT param that says how many bytes
//              of data were written to the buffer.
Status WINAPI
Region_GetData(
    IN Region * region,
    OUT BYTE * buffer,
    IN UINT bufferSize,
    OUT UINT * sizeFilled
);

/**
 * Hit testing operations
 **/
BOOL WINAPI
Region_IsVisiblePoint(
    IN Region * region,
    IN const PointF * point,
    IN Graphics * g
);

// integer version
BOOL WINAPI
Region_IsVisiblePointI(
    IN Region * region,
    IN const Point * point,
    IN Graphics * g
);

BOOL WINAPI
Region_IsVisibleRect(
    IN Region * region,
    IN const RectF * rect,
    IN Graphics * g
);

// integer version
BOOL WINAPI
Region_IsVisibleRectI(
    IN Region * region,
    IN const Rect * rect,
    IN Graphics * g
);

UINT WINAPI
Region_GetRegionScansCount(
    IN Region * region,
    IN Matrix * matrix
);

// If rects is NULL, return the count of rects in the region.
// Otherwise, assume rects is big enough to hold all the region rects
// and fill them in and return the number of rects filled in.
// The rects are returned in the units specified by the matrix
// (which is typically a world-to-device transform).
// Note that the number of rects returned can vary, depending on the
// matrix that is used.

Status WINAPI
Region_GetRegionScans(
    IN Region * region,
    IN Matrix * matrix,
    OUT RectF * rects,
    IN OUT INT * count
);

// integer version
Status WINAPI
Region_GetRegionScansI(
    IN Region * region,
    IN Matrix * matrix,
    OUT Rect * rects,
    IN OUT INT * count
);

#pragma endregion

#pragma region GdiplusFontCollection.h
/**************************************************************************\
*
* Copyright (c) 2000, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusFontCollection.h
*
* Abstract:
*
*   Font collections (Installed and Private)
*
\**************************************************************************/

INT WINAPI
FontCollection_GetFamilyCount(IN FontCollection * fontCollection);

Status WINAPI
FontCollection_GetFamilies(
    IN FontCollection * fontCollection,
    IN INT numSought,
    OUT FontFamily ** gpfamilies,
    OUT INT * numFound
);

Status WINAPI
InstalledFontCollection_Create(OUT InstalledFontCollection ** iFontCollection);

Status WINAPI
PrivateFontCollection_Create(OUT PrivateFontCollection ** pvFontCollection);

Status WINAPI
PrivateFontCollection_Delete(IN PrivateFontCollection * pvFontCollection);

Status WINAPI
PrivateFontCollection_AddFontFile(
    IN PrivateFontCollection * pvFontCollection,
    IN const WCHAR * filename
);

Status WINAPI
PrivateFontCollection_AddMemoryFont(
    IN PrivateFontCollection * pvFontCollection,
    IN const void * memory,
    IN INT length
);

#pragma endregion

#pragma region GdiplusFontFamily.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusFontFamily.h
*
* Abstract:
*
*   GDI+ Font Family class
*
\**************************************************************************/

Status WINAPI
FontFamily_CreateFromName(
    IN const WCHAR * name,
    IN FontCollection * fontCollection, // = NULL
    OUT FontFamily ** fontFamily
);

Status WINAPI
FontFamily_GenericSansSerif(OUT FontFamily ** fontFamily);

Status WINAPI
FontFamily_GenericSerif(OUT FontFamily ** fontFamily);

Status WINAPI
FontFamily_GenericMonospace(OUT FontFamily ** fontFamily);

Status WINAPI
FontFamily_Delete(IN FontFamily * fontFamily);

Status WINAPI
FontFamily_Clone(
    IN FontFamily * fontFamily,
    OUT FontFamily ** clonedFamily
);
 
Status WINAPI
FontFamily_GetFamilyName(
    IN FontFamily * fontFamily,
    IN LPWSTR name,
    IN LANGID language
);

BOOL WINAPI
FontFamily_IsStyleAvailable(
    IN FontFamily * fontFamily,
    IN INT style
);

UINT16 WINAPI
FontFamily_GetEmHeight(
    IN FontFamily * fontFamily,
    IN INT style
);

UINT16 WINAPI
FontFamily_GetCellAscent(
    IN FontFamily * fontFamily,
    IN INT style
);

UINT16 WINAPI
FontFamily_GetCellDescent(
    IN FontFamily * fontFamily,
    IN INT style
);

UINT16 WINAPI
FontFamily_GetLineSpacing(
    IN FontFamily * fontFamily,
    IN INT style
);

#pragma endregion

#pragma region GdiplusFont.h
/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusFont.h
*
* Abstract:
*
*   GDI+ Font class
*
\**************************************************************************/

Status WINAPI
Font_CreateFromHDC(
    IN HDC hdc,
    OUT Font ** font
);

Status WINAPI
Font_CreateFromHFONT(
    IN HDC hdc,
    IN const HFONT hfont,
    OUT Font ** font
);

Status WINAPI
Font_CreateFromLogfontW(
    IN HDC hdc,
    IN const LOGFONTW * logfont,
    OUT Font ** font
);

Status WINAPI
Font_CreateFromLogfontA(
    IN HDC hdc,
    IN const LOGFONTA * logfont,
    OUT Font ** font
);

Status WINAPI
Font_Create(
    IN FontFamily * family,
    IN REAL emSize,
    IN INT style,
    IN Unit unit,
    OUT Font ** font
);

Status WINAPI
Font_Create2(
    IN const WCHAR * familyName,
    IN REAL emSize,
    IN INT style,
    IN Unit unit,
    IN FontCollection * fontCollection,
    OUT Font ** font
);

Status WINAPI
Font_GetLogFontA(
    IN Font * font,
    IN Graphics * g,
    OUT LOGFONTA * logfontA
);

Status WINAPI
Font_GetLogFontW(
    IN Font * font,
    IN Graphics * g,
    OUT LOGFONTW * logfontW
);

Status WINAPI
Font_Clone(
    IN Font * font,
    OUT Font ** clonedFont
);

Status WINAPI
Font_Delete(IN Font * font);

// Operations

Status WINAPI
Font_GetFamily(
    IN Font * font,
    OUT FontFamily * family
);

INT WINAPI
Font_GetStyle(IN Font * font);

REAL WINAPI
Font_GetSize(IN Font * font);

Unit WINAPI
Font_GetUnit(IN Font * font);

REAL WINAPI
Font_GetHeight(
    IN Font * font,
    IN Graphics * graphics
);

REAL WINAPI
Font_GetHeightGivenDPI(
    IN Font * font,
    IN REAL dpi
);

#pragma endregion

#pragma region GdiplusImageCodec.h
/**************************************************************************\
*
* Copyright (c) 2000-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusImageCodec.h
*
* Abstract:
*
*   GDI+ Codec Image APIs
*
\**************************************************************************/

Status WINAPI
GetImageDecodersSize(
    OUT UINT * numDecoders,
    OUT UINT * size
);

Status WINAPI
GetImageDecoders(
    IN UINT numDecoders,
    IN UINT size,
    OUT ImageCodecInfo * decoders
);

Status WINAPI
GetImageEncodersSize(
    OUT UINT * numEncoders,
    OUT UINT * size
);

Status WINAPI
GetImageEncoders(
    IN UINT numEncoders,
    IN UINT size,
    OUT ImageCodecInfo * encoders
);

#pragma endregion

#ifdef __cplusplus
}
#endif

#endif // GDIPLUS_C_H_