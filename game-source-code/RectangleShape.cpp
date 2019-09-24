#include "RectangleShape.h"

RectangleShape::RectangleShape(shared_ptr<Laser>& _laser1,
    shared_ptr<Laser>& _laser2,
    shared_ptr<Laser>& _alienLaser,
    shared_ptr<LaserCanon>& _laserCanon1,
    shared_ptr<LaserCanon>& _laserCanon2,
    shared_ptr<LaserCanonShield>& _shield,
    shared_ptr<Alien>& _alien)
    : laser1{ _laser1 }
    , laser2{ _laser2 }
    , alienLaser{ _alienLaser }
    , laserCanon1{ _laserCanon1 }
    , laserCanon2{ _laserCanon2 }
    , shield{ _shield }
    , alien{ _alien }
{
}

template <class T>
void RectangleShape::createShape(T a) const
{
    
}