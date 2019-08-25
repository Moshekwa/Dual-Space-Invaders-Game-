#include "Laser.h"

Laser::Laser()
    : GameEntity(200, 380)
{
}

void Laser::move(Direction _direction)
{
    switch(_direction) {
    case UP:
        if(getYposition() != 0) {
            setYposition(getYposition() - getEntitySpeed());
        }
        break;
    default:
        break;
    }
}