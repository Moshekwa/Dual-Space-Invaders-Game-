#ifndef SHOOTINGENTITY_H_INCLUDED
#define SHOOTINGENTITY_H_INCLUDED
#include "GameEntity.h"


class ShootingEntity : public GameEntity
{
public:
    ShootingEntity(int xPosition, int yPosition, int entitySpeed, bool life);
    void shoot();
};

#endif // SHOOTINGENTITY_H_INCLUDED