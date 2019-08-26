#include "Laser.h"
#include <iostream>
using namespace std;

Laser::Laser(const EntityCoordinates& _coordinates)
    : GameEntity{ _coordinates.getXposition(), _coordinates.getYposition(), 5, false }
{
}

void Laser::move(Direction _direction)
{
    switch(_direction) {
    case UP:
        if(getEntityCoordinates().getXposition() != 0) {
            setYposition(getEntityCoordinates().getYposition() - getEntitySpeed());
        }
        break;
    default:
        break;
    }
}
