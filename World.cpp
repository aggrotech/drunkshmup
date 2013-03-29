#include "World.h"
#include "Input.h"
#include "Vector2.h"
#include "Graphics.h"

void Aggrotech::World::CreateTestWorld()
{
    Ship *player = new Ship();
    Vector2 pos;
    
    pos.x = 0.0;
    pos.y = 420.0;

    player->SetPosition(pos);
    player->SetShipType(ShipType::kPlayer);

    ships.push_back(player);
}

void Aggrotech::World::Update(float dt, const Input &input)
{
    if (input.IsButtonDown())
    {
        Ship *player = ships[0];
        Vector2 position = player->GetPosition();

        position.x += 1.0;

        player->SetPosition(position);
    }
}

void Aggrotech::World::Render(Graphics *graphics)
{
    for(unsigned int i = 0; i < ships.size(); i++)
    {
        graphics->RenderShip(ships[i]);
    }
}
