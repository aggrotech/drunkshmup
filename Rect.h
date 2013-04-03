#pragma once

#include "Vector2.h"

namespace Aggrotech
{
    class Rect
    {
    public:

        Rect();
        Rect(Vector2 &origin, Vector2 &size);

        Vector2 Origin;

        Vector2 Size;

        bool IsPointInside(Vector2 &v) const;
    };
}