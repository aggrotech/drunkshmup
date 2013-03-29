#include "Ship.h"

Aggrotech::Vector2 Aggrotech::Ship::GetVelocity() const
{
    return velocity;
}

void Aggrotech::Ship::SetVelocity(Vector2 v)
{
    velocity = v;
}

Aggrotech::Vector2 Aggrotech::Ship::GetPosition() const
{
    return position;
}

void Aggrotech::Ship::SetPosition(Vector2 p)
{
    position = p;
}

Aggrotech::ShipType Aggrotech::Ship::GetShipType() const
{
    return shipType;
}

void Aggrotech::Ship::SetShipType(ShipType type)
{
    shipType = type;
}
