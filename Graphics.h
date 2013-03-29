#pragma once

#include "Ship.h"
#include "SDL.h"

namespace Aggrotech
{
    class Ship;

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

    private:

        void LoadShipTypes();

        void UnloadShipTypes();

        SDL_Surface *window;

        SDL_Surface *shipSprites[ShipType::kShipTypeCount];
    };
}
