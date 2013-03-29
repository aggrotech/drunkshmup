#pragma once

#include "Vector2.h"

namespace Aggrotech
{
    class Bullet
    {
    public:

        Vector2 GetPosition() const;
        void SetPosition(Vector2 &pos);

        Vector2 GetVelocity() const;
        void SetVelocity(Vector2 &vel);

    private:

        Vector2 position;
        Vector2 velocity;
    };
}
