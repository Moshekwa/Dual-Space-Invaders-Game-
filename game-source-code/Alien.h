#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"

class Alien : public GameEntity
{
public:
    Alien(int x, int y, int _rightBoundary, int _leftBoundary);
    virtual void move(Direction _direction);
    bool getAlienRightDirection() const;
    void setAlienRightDirection(bool rightDirection);
    int getRightBoundary() const;
    int getLeftBoundary() const;
    int getNumberOfAliens() const;

private:
    int numberOfAliens;
    int rightBoundary;
    int leftBoundary;
    bool alienRightDirection;
};

#endif // ALIEN_H_INCLUDED