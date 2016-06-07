#include "stdafx.h"

Status WINAPI
Matrix_Create(OUT Matrix ** matrix)
{
    return (Status)Gdiplus::DllExports::GdipCreateMatrix(
        (Gdiplus::GpMatrix **)matrix
    );
}

Status WINAPI
Matrix_Create2(OUT Matrix ** matrix,
               IN REAL m11,
               IN REAL m12,
               IN REAL m21,
               IN REAL m22,
               IN REAL dx,
               IN REAL dy)
{
    return (Status)Gdiplus::DllExports::GdipCreateMatrix2(
        m11, m12, m21, m22, dx, dy,
        (Gdiplus::GpMatrix **)matrix
    );
}

Status WINAPI
Matrix_Create3(OUT Matrix ** matrix,
    IN const RectF * rect,
    IN const PointF * dstplg
)
{
    return (Status)Gdiplus::DllExports::GdipCreateMatrix3(
        (GDIPCONST Gdiplus::GpRectF *)rect,
        (GDIPCONST Gdiplus::GpPointF *)dstplg,
        (Gdiplus::GpMatrix **)matrix
    );
}

Status WINAPI
Matrix_Create3I(OUT Matrix ** matrix,
                IN const Rect * rect,
                IN const Point * dstplg
)
{
    return (Status)Gdiplus::DllExports::GdipCreateMatrix3I(
        (GDIPCONST Gdiplus::GpRect *)rect,
        (GDIPCONST Gdiplus::GpPoint *)dstplg,
        (Gdiplus::GpMatrix **)matrix
    );
}

Status WINAPI
Matrix_Clone(IN Matrix * matrix, OUT Matrix ** clone)
{
    return (Status)Gdiplus::DllExports::GdipCloneMatrix(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrix **)clone
    );
}

Status WINAPI
Matrix_Delete(IN Matrix * matrix)
{
    return (Status)Gdiplus::DllExports::GdipDeleteMatrix(
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Matrix_GetElements(
    IN Matrix * matrix,
    OUT REAL * m
)
{
    return (Status)Gdiplus::DllExports::GdipGetMatrixElements(
        (Gdiplus::GpMatrix *)matrix, m
    );
}

Status WINAPI
Matrix_SetElements(
    IN Matrix * matrix,
    IN REAL m11,
    IN REAL m12,
    IN REAL m21,
    IN REAL m22,
    IN REAL dx,
    IN REAL dy
)
{
    return (Status)Gdiplus::DllExports::GdipSetMatrixElements(
        (Gdiplus::GpMatrix *)matrix,
        m11, m12, m21, m22, dx, dy
    );
}

REAL WINAPI Matrix_OffsetX(IN Matrix * matrix)
{
    REAL elements[6];

    if (Matrix_GetElements(matrix, &elements[0]) == Ok)
        return elements[4];
    else
        return 0.0f;
}

REAL WINAPI Matrix_OffsetY(IN Matrix * matrix)
{
    REAL elements[6];

    if (Matrix_GetElements(matrix, &elements[0]) == Ok)
        return elements[5];
    else
        return 0.0f;
}

Status WINAPI
Matrix_Reset(IN Matrix * matrix)
{
    // set identity matrix elements 
    return (Status)Gdiplus::DllExports::GdipSetMatrixElements(
        (Gdiplus::GpMatrix *)matrix,
        1.0, 0.0, 0.0, 1.0, 0.0, 0.0
    );
}

Status WINAPI
Matrix_Multiply(IN Matrix * matrix,
    IN Matrix * nmatrix,
    IN MatrixOrder order 
)
{
    return (Status)Gdiplus::DllExports::GdipMultiplyMatrix(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpMatrix *)nmatrix,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Matrix_Translate(IN Matrix * matrix,
                 IN REAL offsetX,
                 IN REAL offsetY,
                 IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipTranslateMatrix(
        (Gdiplus::GpMatrix *)matrix,
        offsetX, offsetY,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Matrix_Scale(IN Matrix * matrix,
             IN REAL scaleX,
             IN REAL scaleY,
             IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipScaleMatrix(
        (Gdiplus::GpMatrix *)matrix,
        scaleX, scaleY,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Matrix_Rotate(IN Matrix * matrix,
              IN REAL angle,
              IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipRotateMatrix(
        (Gdiplus::GpMatrix *)matrix, angle,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Matrix_RotateAt(IN Matrix * matrix,
                IN REAL angle,
                IN const PointF * center,
                IN MatrixOrder order
)
{
    REAL x = (order == MatrixOrderPrepend) ? center->X : -center->X;
    REAL y = (order == MatrixOrderPrepend) ? center->Y : -center->Y;

    Gdiplus::DllExports::GdipTranslateMatrix(
        (Gdiplus::GpMatrix *)matrix,
        x, y,
        (Gdiplus::GpMatrixOrder)order
    );

    Gdiplus::DllExports::GdipRotateMatrix(
        (Gdiplus::GpMatrix *)matrix,
        angle,
        (Gdiplus::GpMatrixOrder)order
    );

    return (Status)Gdiplus::DllExports::GdipTranslateMatrix(
        (Gdiplus::GpMatrix *)matrix,
        -x, -y,
        (Gdiplus::GpMatrixOrder)order
    );

}

Status WINAPI
Matrix_Shear(IN Matrix * matrix,
             IN REAL shearX,
             IN REAL shearY,
             IN MatrixOrder order
)
{
    return (Status)Gdiplus::DllExports::GdipShearMatrix(
        (Gdiplus::GpMatrix *)matrix,
        shearX,
        shearY,
        (Gdiplus::GpMatrixOrder)order
    );
}

Status WINAPI
Matrix_Invert(IN Matrix * matrix)
{
    return (Status)Gdiplus::DllExports::GdipInvertMatrix(
        (Gdiplus::GpMatrix *)matrix
    );
}

Status WINAPI
Matrix_TransformPoints(IN Matrix * matrix,
                       IN OUT PointF * pts,
                       IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipTransformMatrixPoints(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpPointF *)pts,
        count
    );
}

Status WINAPI
Matrix_TransformPointsI(IN Matrix * matrix,
                        IN OUT Point * pts,
                        IN INT count
)
{
    return (Status)Gdiplus::DllExports::GdipTransformMatrixPointsI(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpPoint *)pts,
        count
    );
}

Status WINAPI
Matrix_TransformVectors(IN Matrix * matrix,
                        IN OUT PointF * pts,
                        IN INT count // = 1
)
{
    return (Status)Gdiplus::DllExports::GdipVectorTransformMatrixPoints(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpPointF *)pts,
        count
    );
}

Status WINAPI
Matrix_TransformVectorsI(IN Matrix * matrix,
                         IN OUT Point * pts,
                         IN INT count // = 1
)
{
    return (Status)Gdiplus::DllExports::GdipVectorTransformMatrixPointsI(
        (Gdiplus::GpMatrix *)matrix,
        (Gdiplus::GpPoint *)pts,
        count
    );
}

BOOL WINAPI
Matrix_IsInvertible(IN const Matrix * matrix)
{
    BOOL result = FALSE;

    Gdiplus::DllExports::GdipIsMatrixInvertible(
        (GDIPCONST Gdiplus::GpMatrix *)matrix, &result
    );

    return result;
}

BOOL WINAPI
Matrix_IsIdentity(IN const Matrix * matrix)
{
    BOOL result = FALSE;

    Gdiplus::DllExports::GdipIsMatrixIdentity(
        (GDIPCONST Gdiplus::GpMatrix *)matrix, &result
    );

    return result;
}

BOOL WINAPI
Matrix_Equals(IN const Matrix * matrix1, IN const Matrix * matrix2)
{
    BOOL result = FALSE;

    Gdiplus::DllExports::GdipIsMatrixEqual(
        (GDIPCONST Gdiplus::GpMatrix *)matrix1,
        (GDIPCONST Gdiplus::GpMatrix *)matrix2,
        &result
    );

    return result;
}