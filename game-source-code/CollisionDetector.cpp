#include "CollisionDetector.h"
#include <cmath>

CollisionDetector::CollisionDetector()
{
}

void CollisionDetector::LaserAlienCollision(LaserCanon& _laser1, Alien& _alien)
{
    auto radii_sum = laserRadius + alienRadius;
    auto laserXCentre = _laser1.getLaser(1).getEntityCoordinates().getXposition() + laserRadius;
    auto laserYCentre = _laser1.getLaser(1).getEntityCoordinates().getYposition() + laserRadius;
    auto alienXCentre = _alien.getEntityCoordinates().getXposition() + alienRadius;
    auto alienYCentre = _alien.getEntityCoordinates().getYposition() + alienRadius;

    auto centreDistance = sqrt(pow(laserXCentre - alienXCentre, 2) + pow(laserYCentre - alienYCentre, 2));
    if(centreDistance < radii_sum){
        _laser1.destroyLaser(1);
    }
}