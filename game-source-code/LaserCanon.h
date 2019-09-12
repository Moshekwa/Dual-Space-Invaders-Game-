#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "GameEntity.h"
#include "Laser.h"

class InvalidLaserCanonCoordinates
{
};

class LaserCanon : public GameEntity
{
public:
    LaserCanon(int x, int y, int canonNumber);
    void shootLaser(int laser_number);
    void destroyLaser(int laser_number);
    void moveLaser();
    Laser getLaser(int laser_number) const;
    void update_Laser_position(int laser_number);
    virtual void move(Direction _direction);

private:
    Laser _laser;
    Laser _laser2;
};

#endif // LASERCANON_H_INCLUDED