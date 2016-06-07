#include "stdafx.h"

BOOL WINAPI
ObjectTypeIsValid(ObjectType type)
{
    return ((type >= ObjectTypeMin) && (type <= ObjectTypeMax));
}