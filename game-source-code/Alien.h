/**
 * @file Alien.h
 * @class Alien
 * @brief This class models the behaviour an alien object. It inherits from Moving Entity class which inherits from Game
 * Entity
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>
using namespace std;

enum AlienColour { RED, PURPLE, GREEN };

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
    static int getNumberOfAliens();
    AlienColour getAlienColour() const;
    int alienPoints(AlienColour _colour);

private:
    bool alienRightDirection;
    const static int numberOfAliens;
    AlienColour _alienColour;
};

#endif // ALIEN_H_INCLUDED