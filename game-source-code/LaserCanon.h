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
    /**
     * @brief sets the direction the lase canon object is facing on the screen
     * @param directionFaced
     */
    void setFacedDirection(Direction directionFaced);
    /**
     * @brief return the direction the laser canon is facing
     * @return
     */
    Direction getFacedDirection() const;
    /**
     * @brief sets the canon's ability to move true of false
     * @param movementAbility
     */
    void setAbilityToMove(bool movementAbility);
    /**
     * @brief returns true if the canon is able to move
     * @return
     */
    bool isAbleToMove() const;
    virtual void move(Direction _direction) override;
    ~LaserCanon(){};

private:
    Direction _directionFaced;
    bool ableToMove;
};

#endif // LASERCANON_H_INCLUDED