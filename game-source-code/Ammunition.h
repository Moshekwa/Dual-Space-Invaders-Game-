/**
 * @file Ammunition.h
 * @class Ammunition
 * @brief Ammunition inherits from Game Entity and add the ability of an object to be shot.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

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