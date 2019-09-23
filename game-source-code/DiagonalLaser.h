#ifndef DIAGONALLASER_H_INCLUDED
#define DIAGONALLASER_H_INCLUDED
#include "Ammunition.h"
#include "LaserCanon.h"

class InvalidCanonDiagonalLaserCoordinates {};

class DiagonalLaser : public Ammunition
{
public:
    DiagonalLaser(LaserCanon& _laserCanon, int numberOfLives);
    ~DiagonalLaser();
    void moveLaserWithCanon(LaserCanon& _laserCanon);
    virtual void move(Direction _direction);

private:
};

#endif // DIAGONALLASER_H_INCLUDED