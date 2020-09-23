/**
 * @file MovingEntity.h
 * @class MovingEntity
 * @brief This class inherits from Game Entity and add the ability of an object to be move.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef MOVINGENTITY_H_INCLUDED
#define MOVINGENTITY_H_INCLUDED
#include "GameEntity.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class EntitySpeedCannotBeZero
{
};

class MovingEntity : public GameEntity
{
public:
    MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life, int numberOfLives);
    /**
     * @brief return the number of units a moving entity moves by on the screen
     * @return
     */
    int getEntitySpeed() const;
    void setEntitySpeed(int speed);
    /**
     * @brief sets boundaries for objects that are able to move
     * @param left
     * @param right
     * @param upper
     * @param bottom
     */
    void setMovementBoundaries(int left, int right, int upper, int bottom);
    tuple<int, int, int, int> getMovementBoundaries();
    virtual void move(Direction _direction) = 0;
    ~MovingEntity(){};

private:
    int _entitySpeed;
    int rightBoundary;
    int leftBoundary;
    int upperBoundary;
    int bottomBoundary;
};

#endif // MOVINGENTITY_H_INCLUDED