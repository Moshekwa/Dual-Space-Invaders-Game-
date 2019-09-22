#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>
using namespace std;

enum AlienColour {RED, PURPLE, GREEN};

class InvalidAlienCoordinates
{
};

class Alien : public MovingEntity
{
public:
    Alien(int x, int y, int _rightBoundary, int _leftBoundary, int numberOfLives, AlienColour alienColour);
    virtual void move(Direction _direction);
    bool getAlienRightDirection() const;
    void setAlienRightDirection(bool rightDirection);
    tuple<int, int, int, int> getBoundaries() const;
    static int getNumberOfAliens();
    AlienColour getAlienColour() const;
    int alienPoints(AlienColour _colour);

private:
    int rightBoundary;
    int leftBoundary;
    int upperBoundary;
    int bottomBoundary;
    bool alienRightDirection;
    const static int numberOfAliens;
    AlienColour _alienColour;
};

#endif // ALIEN_H_INCLUDED