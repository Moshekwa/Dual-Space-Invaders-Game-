/**
 * @file LaserCanon.h
 * @class LaserCanon
 * @brief This class is responsible for defining the behaviour of a laser canon object.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>

class InvalidLaserCanonPosition
{
};


class LaserCanon : public MovingEntity
{
public:
    LaserCanon(int x, int y, int canonNumber, int numberOfLives);
    void setFacedDirection(Direction directionFaced);
    Direction getFacedDirection() const;
    void setAbilityToMove(bool movementAbility);
    bool isAbleToMove() const;
    virtual void move(Direction _direction);

private:
    Direction _directionFaced;
    bool ableToMove;
};

#endif // LASERCANON_H_INCLUDED