#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"
#include <tuple>
using namespace std;

class InvalidAlienCoordinates
{
};

class Alien : public GameEntity
{
public:
    Alien(int x, int y, int _rightBoundary, int _leftBoundary);
    virtual void move(Direction _direction);
    bool getAlienRightDirection() const;
    void setAlienRightDirection(bool rightDirection);
    tuple<int, int, int, int> getBoundaries() const;
    static int getNumberOfAliens();

private:
    int rightBoundary;
    int leftBoundary;
    int upperBoundary;
    int bottomBoundary;
    bool alienRightDirection;
    const static int numberOfAliens;
};

#endif // ALIEN_H_INCLUDED