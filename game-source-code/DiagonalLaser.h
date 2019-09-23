#ifndef DIAGONALLASER_H_INCLUDED
#define DIAGONALLASER_H_INCLUDED
#include "Ammunition.h"
#include "LaserCanon.h"

class InvalidCanonDiagonalLaserCoordinates
{
};

class DiagonalLaser : public Ammunition
{
public:
    DiagonalLaser(LaserCanon& _laserCanon, int numberOfLives);
    ~DiagonalLaser();
    virtual void move(Direction _direction);
	void moveDiagonalLaserWithCanon (LaserCanon& _laserCanon);
	
private:
};

#endif // DIAGONALLASER_H_INCLUDED