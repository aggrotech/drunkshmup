#include "Rect.h"

Aggrotech::Rect::Rect()
{
}

Aggrotech::Rect::Rect(Vector2 &origin, Vector2 &size)
    : Origin(origin), Size(size)
{

}

bool Aggrotech::Rect::IsPointInside(Vector2 &v) const
{
    float left = Origin.x - Size.x;
    float top = Origin.y - Size.y;
    float right = Origin.x + Size.x;
    float bottom = Origin.y + Size.y;

    return !(v.x < left || v.x > right || v.y < top || v.y > bottom);
}
