#include "EntityShape.h"

EntityShape::EntityShape()
{
}

tuple<int, int, int, int> EntityShape::laserShape(Laser& _laser)
{
    auto [x_min, y_min] = _laser.entityPosition();
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

tuple<int, int, int, int> EntityShape::laserCanonShape(LaserCanon& _laserCanon)
{
    auto [x_min, y_min] = _laserCanon.entityPosition();
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