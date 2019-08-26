#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"

class Laser : public GameEntity
{
public:
    Laser(const EntityCoordinates& _coordinates = EntityCoordinates{ 0, 0 });
    virtual void move(Direction _direction);

private:
    bool life;
};

#endif // LASER_H_INCLUDED