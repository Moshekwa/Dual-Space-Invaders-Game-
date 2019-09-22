#ifndef SHOOTINGENTITY_H_INCLUDED
#define SHOOTINGENTITY_H_INCLUDED
#include "MovingEntity.h"

class Ammunition : public MovingEntity
{
public:
    Ammunition(int xPosition, int yPosition, int entitySpeed, bool life, int numberOfLives);
    void shoot();
  
};

#endif // SHOOTINGENTITY_H_INCLUDED