#include "Graphics.h"
#include "SDL_image.h"
#include <vector>

const int Aggrotech::Graphics::Width = 320;

const int Aggrotech::Graphics::Height = 480;

Aggrotech::Graphics::Graphics()
    : window(NULL)
{
    window = SDL_SetVideoMode(Width, Height, 32, SDL_SWSURFACE);

    IMG_Init(IMG_INIT_PNG);
    LoadShipTypes();
    LoadBulletTypes();
}

Aggrotech::Graphics::~Graphics()
{
    UnloadShipTypes();
    UnloadBulletTypes();
    SDL_FreeSurface(window);
}

void Aggrotech::Graphics::Render(float dt)
{
    SDL_Flip(window);
}

void Aggrotech::Graphics::RenderShip(Ship *ship)
{
    SDL_Surface *sprite = shipSprites[ship->GetShipType()];

    SDL_Rect position;
    position.x = static_cast<Sint16>(ship->GetPosition().x);
    position.y = static_cast<Sint16>(ship->GetPosition().y);

    SDL_BlitSurface(sprite, NULL, window, &position);
}

void Aggrotech::Graphics::RenderBullet(Bullet *bullet)
{
    SDL_Surface *sprite = bulletSprites[bullet->GetBulletType()];

    SDL_Rect position;
    position.x = static_cast<Sint16>(bullet->GetPosition().x);
    position.y = static_cast<Sint16>(bullet->GetPosition().y);

    SDL_BlitSurface(sprite, NULL, window, &position);
}

void Aggrotech::Graphics::LoadShipTypes()
{
    std::string files[] = 
    {
        "ships/player.png",
        "ships/enemy1.png",
        "ships/enemy2.png"
    };

    for (int i = 0; i < ShipType::kShipTypeCount; i++)
    {
        shipSprites[i] = IMG_Load(files[i].c_str());
    }
}

void Aggrotech::Graphics::UnloadShipTypes()
{
    for (int i = 0; i < ShipType::kShipTypeCount; i++)
    {
        SDL_FreeSurface(shipSprites[i]);
    }
}

void Aggrotech::Graphics::Prepare()
{
    SDL_FillRect(window, &window->clip_rect, SDL_MapRGB(window->format, 0x00, 0x00, 0x00));
}


void Aggrotech::Graphics::LoadBulletTypes()
{
    std::string files[] = 
    {
        "bullets/blue.png",
        "bullets/red.png"
    };

    for (int i = 0; i < BulletType::kBulletTypeCount; i++)
    {
        bulletSprites[i] = IMG_Load(files[i].c_str());
    }
}

void Aggrotech::Graphics::UnloadBulletTypes()
{
    for (int i = 0; i < BulletType::kBulletTypeCount; i++)
    {
        SDL_FreeSurface(bulletSprites[i]);
    }
}