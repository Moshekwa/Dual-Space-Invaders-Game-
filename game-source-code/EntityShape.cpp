#include "EntityShape.h"

EntityShape::EntityShape()
{
}

EntityShape::~EntityShape()
{
}

tuple<int, int, int, int> EntityShape::laser1Shape(Laser& _laser1)
{
    auto [x_min, y_min] = _laser1.entityPosition();
    auto x_max = x_min + laserWidth;
    auto y_max = y_min + laserHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::laser2Shape(Laser& _laser2)
{
    auto [x_min, y_min] = _laser2.entityPosition();
    auto x_max = x_min + laserWidth;
    auto y_max = y_min + laserHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::alienLaserShape(Laser& _alienLaser)
{
    auto [x_min, y_min] = _alienLaser.entityPosition();
    auto x_max = x_min + laserWidth;
    auto y_max = y_min + laserHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::alienShape(Alien& _alien)
{
    auto [x_min, y_min] = _alien.entityPosition();
    auto x_max = x_min + alienWidth;
    auto y_max = y_min + alienHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::laserCanon1Shape(LaserCanon& _laserCanon1)
{
    auto [x_min, y_min] = _laserCanon1.entityPosition();
    auto x_max = x_min + laserCanonWidth;
    auto y_max = y_min + laserCanonHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::laserCanon2Shape(LaserCanon& _laserCanon2)
{
    auto [x_min, y_min] = _laserCanon2.entityPosition();
    auto x_max = x_min + laserCanonWidth;
    auto y_max = y_min + laserCanonHeight;

    return { x_min, y_min, x_max, y_max };
}

tuple<int, int, int, int> EntityShape::laserCanonShieldShape(LaserCanonShield& _shield)
{
    auto [x_min, y_min] = _shield.entityPosition();
    auto x_max = x_min + LaserCanonShieldWidth;
    auto y_max = y_min + LaserCanonShieldHeight;

    return { x_min, y_min, x_max, y_max };
}