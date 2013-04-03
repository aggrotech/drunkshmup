#pragma once

#include "Ship.h"
#include "Bullet.h"
#include "SDL.h"

namespace Aggrotech
{
    class Graphics
    {
    public:

        static const int Width;

        static const int Height;

        Graphics();

        ~Graphics();

        void Prepare();

        void Render(float dt);

        void RenderShip(Ship *ship);

        void RenderBullet(Bullet *bullet);

    private:

        void LoadShipTypes();

        void UnloadShipTypes();

        void LoadBulletTypes();

        void UnloadBulletTypes();

        SDL_Surface *window;

        SDL_Surface *shipSprites[ShipType::kShipTypeCount];

        SDL_Surface *bulletSprites[BulletType::kBulletTypeCount];
    };
}
