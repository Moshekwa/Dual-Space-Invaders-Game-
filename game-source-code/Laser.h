/**
 * @file Laser.h
 * @class Laser
 * @brief This class is responsible for defining the behaviour of a laser object.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "Ammunition.h"
#include "LaserCanon.h"
#include "Alien.h"

class InvalidCanonLaserCoordinates
{
};

class InvalidAlienLaserCoordinates
{
};

class Laser : public Ammunition
{
public:
    Laser(LaserCanon& _laserCanon, int numberOfLives);
    Laser(Alien& _alien, int numberOfLives);
    void moveLaserWithCanon(LaserCanon& _laserCanon);
    void moveLaserWithAlien(Alien& _alien);
    bool isLaserInMotion() const;
    void setLaserInMotion(bool motion);
    virtual void move(Direction _direction);

private:
    bool laserMotion;
};

#endif // LASER_H_INCLUDED