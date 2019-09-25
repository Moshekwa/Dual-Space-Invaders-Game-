#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>

class InvalidLaserCanonCoordinates
{
};


class LaserCanon : public MovingEntity
{
public:
    LaserCanon(int x, int y, int canonNumber, int numberOfLives);
    bool isAbleToMove() const;
    void setAbilityToMove(bool movement);
    virtual void move(Direction _direction);

private:
    int _movement;
};

#endif // LASERCANON_H_INCLUDED