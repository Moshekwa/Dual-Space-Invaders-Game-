#include "Laser.h"

Laser::Laser(const EntityCoordinates& _coordinates)
    : GameEntity{ _coordinates.getXposition(), _coordinates.getYposition(), 5, false }
{
}

void Laser::move(Direction _direction)
{
    switch(_direction) {
    case UP:
	if(getEntityCoordinates().getYposition() != 0) {
	    setYposition(getEntityCoordinates().getYposition() - getEntitySpeed());
	}
	break;
    case DOWN:
	if(getEntityCoordinates().getYposition() < 395) {

	    setYposition(getEntityCoordinates().getYposition() + getEntitySpeed());
	}
    default:
	break;
    }
}

void Laser::update_position(const EntityCoordinates& _entityCoordinates)
{
    setXposition(_entityCoordinates.getXposition() + 6);
    setYposition(_entityCoordinates.getYposition());
}