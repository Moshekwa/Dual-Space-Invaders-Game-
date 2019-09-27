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
    /**
     * @brief responsible for moving the alien object towards the desired direction
     * @param _direction
     */
    virtual void move(Direction _direction) override;
    /**
     * @brief returns a boolean to confirm that the alien is moving towards the right hand side.
     * @return
     */
    bool getAlienRightDirection() const;
    /**
     * @brief sets the boolean that confirms the right movement of the alien.
     * @param rightDirection
     */
    void setAlienRightDirection(bool rightDirection);
    /**
     * @brief returns the number of alien objects to be present in the game once it starts running. This number shows
     * the number of alien per row. There are three rows of aliens on each alien armada with different colours.
     * @return
     */
    static int getNumberOfAliens();

    AlienColour getAlienColour() const;
    /**
     * @brief Takes in a colour and returns an appropriate score for that colour alien
     * @param _colour
     * @return
     */
    int alienPoints(AlienColour _colour);
    ~Alien(){};

private:
    bool alienRightDirection;
    const static int numberOfAliens;
    AlienColour _alienColour;
};

#endif // ALIEN_H_INCLUDED