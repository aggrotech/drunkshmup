#pragma once

#include <vector>
#include "Rect.h"

namespace Aggrotech
{
    class Ship;
    class Bullet;
    class Input;
    class Graphics;

    class World
    {
    public:

        void CreateTestWorld();
        void SpawnBulletsMaybe();
        void Update(float dt, const Input &input);
        void Render(Graphics *graphics);
        void FrameCleanup();

    private:

        Rect gameRect;
        std::vector< Ship *> ships;
        std::vector< Bullet *> bullets;
    };
}
