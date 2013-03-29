#pragma once

#include "Bullet.h"
#include <vector>

namespace Aggrotech
{
    class Ship;
    class Input;
    class Graphics;

    class World
    {
    public:

        void CreateTestWorld();
        void Update(float dt, const Input &input);
        void Render(Graphics *graphics);

    private:

        std::vector< Ship *> ships;
        std::vector< Bullet > bullets;
    };
}
