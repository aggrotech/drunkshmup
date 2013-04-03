#include "Bullet.h"

Aggrotech::Vector2 Aggrotech::Bullet::GetPosition() const
{
    return position;
}

void Aggrotech::Bullet::SetPosition(Vector2 &pos)
{
    position = pos;
}
        
Aggrotech::Vector2 Aggrotech::Bullet::GetVelocity() const
{
    return velocity;
}

void Aggrotech::Bullet::SetVelocity(Vector2 &vel)
{
    velocity = vel;
}

Aggrotech::BulletType Aggrotech::Bullet::GetBulletType() const
{ 
    return bulletType;
}

void Aggrotech::Bullet::SetBulletType(BulletType type)
{
    bulletType = type;
}
