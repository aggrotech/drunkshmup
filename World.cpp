#include "World.h"
#include "Input.h"
#include "Vector2.h"
#include "Bullet.h"
#include "Ship.h"
#include "Graphics.h"
#include <algorithm>

void Aggrotech::World::CreateTestWorld()
{
    gameRect.Origin.x = 320/2;
    gameRect.Origin.y = 480/2;

    gameRect.Size.x = 320/2;
    gameRect.Size.y = 480/2;

    Ship *player = new Ship();
    Vector2 pos;
    
    pos.x = 158.0;
    pos.y = 420.0;

    player->SetPosition(pos);
    player->SetShipType(ShipType::kPlayer);

    ships.push_back(player);
}

void Aggrotech::World::Update(float dt, const Input &input)
{
    FrameCleanup();

    if (input.IsButtonDown())
    {
        Ship *player = ships[0];
        Vector2 position = player->GetPosition();

        position.x += 1.0;

        player->SetPosition(position);
    }

    for (unsigned int i = 0; i < ships.size(); i++)
    {
        Vector2 position = ships[i]->GetPosition();
        Vector2 velocity = ships[i]->GetVelocity();

        position.x += velocity.x;
        position.y += velocity.y;

        ships[i]->SetPosition(position);
    }

    for (unsigned int i = 0; i < bullets.size(); i++)
    {
        Vector2 position = bullets[i]->GetPosition();
        Vector2 velocity = bullets[i]->GetVelocity();

        position.x += velocity.x;
        position.y += velocity.y;

        bullets[i]->SetPosition(position);
    }

    SpawnBulletsMaybe();
}

void Aggrotech::World::Render(Graphics *graphics)
{
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        graphics->RenderShip(ships[i]);
    }

    for (unsigned int i = 0; i < bullets.size(); i++)
    {
        graphics->RenderBullet(bullets[i]);
    }
}

void Aggrotech::World::SpawnBulletsMaybe()
{
    if (bullets.empty())
    {
        Vector2 pos = ships[0]->GetPosition();
        Vector2 vel;

        vel.x = 0.0f;
        vel.y = -1.0f;

        Bullet *b = new Bullet();

        b->SetBulletType(BulletType::kBlue);
        b->SetPosition(pos);
        b->SetVelocity(vel);

        bullets.push_back(b);
    }
}

void Aggrotech::World::FrameCleanup()
{
    std::vector< Bullet *>::iterator it = bullets.begin();
    std::vector< Bullet *>::iterator itEnd = bullets.end();

    while (it != itEnd)
    {
        Bullet *bullet = *it;

        if (!gameRect.IsPointInside(bullet->GetPosition()))
        {
            delete bullet;
            *it = NULL;
        }

        it++;
    }

    Bullet *erasedBullet = NULL;

    bullets.erase(std::remove(bullets.begin(), bullets.end(), erasedBullet), bullets.end());
}
