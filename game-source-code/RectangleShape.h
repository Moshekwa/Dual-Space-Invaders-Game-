#ifndef RECTANGLESHAPE_H_INCLUDED
#define RECTANGLESHAPE_H_INCLUDED
#include "Alien.h"
#include "EntityShape.h"
#include "Laser.h"
#include "LaserCanon.h"
#include "LaserCanonShield.h"

#include <memory>
using std::shared_ptr;

class RectangleShape : public EntityShape
{
public:
    RectangleShape(shared_ptr<Laser>& _laser1,
        shared_ptr<Laser>& _laser2,
        shared_ptr<Laser>& _alienLaser,
        shared_ptr<LaserCanon>& _laserCanon1,
        shared_ptr<LaserCanon>& _laserCanon2,
        shared_ptr<LaserCanonShield>& _shield,
        shared_ptr<Alien>& _alien);
    virtual void createShape() const override;

private:
    shared_ptr<Laser> laser1;
    shared_ptr<Laser> laser2;
    shared_ptr<Laser> alienLaser;
    shared_ptr<LaserCanon> laserCanon1;
    shared_ptr<LaserCanon> laserCanon2;
    shared_ptr<LaserCanonShield> shield;
    shared_ptr<Alien> alien;
};

#endif // RECTANGLESHAPE_H_INCLUDED