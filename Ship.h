#pragma once

#include "Vector2.h"

namespace Aggrotech
{
    enum ShipType
    {
        kPlayer,
        kEnemy1,
        kEnemy2,
        kShipTypeCount
    };

    class Ship
    {
    public:

        Vector2 GetVelocity() const;

        void SetVelocity(Vector2 v);

        Vector2 GetPosition() const;

        void SetPosition(Vector2 p);

        ShipType GetShipType() const;

        void SetShipType(ShipType type);

    private:

        Vector2 velocity;
        Vector2 position;
        ShipType shipType;
    };
}
