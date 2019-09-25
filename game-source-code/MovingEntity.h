#ifndef MOVINGENTITY_H_INCLUDED
#define MOVINGENTITY_H_INCLUDED
#include "GameEntity.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class MovingEntity : public GameEntity
{
public:
    MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life, int numberOfLives);
    int getEntitySpeed() const;
    void setEntitySpeed(int speed);
    void setMovementBoundaries(int left, int right, int upper, int bottom);
    tuple<int, int, int, int> getMovementBoundaries();
    virtual void move(Direction _direction) = 0;
    
private:
    int _entitySpeed;
    int rightBoundary;
    int leftBoundary;
    int upperBoundary;
    int bottomBoundary;
};

#endif // MOVINGENTITY_H_INCLUDED