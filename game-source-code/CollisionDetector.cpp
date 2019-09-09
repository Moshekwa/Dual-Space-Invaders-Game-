#include "CollisionDetector.h"
#include <cmath>

CollisionDetector::CollisionDetector()
{
}

void CollisionDetector::LaserAlienCollision(LaserCanon& _laser1, LaserCanon& _laser2, Alien& _alien)
{
    auto laserOne = 1;
    auto laserTwo = 2;
    auto radii_sum = laserRadius + alienRadius;
    auto laserXCentre = _laser1.getLaser(laserOne).getEntityCoordinates().getXposition() + laserRadius;
    auto laserYCentre = _laser1.getLaser(laserOne).getEntityCoordinates().getYposition() + laserRadius;
    
    auto laser2XCentre = _laser2.getLaser(laserTwo).getEntityCoordinates().getXposition() + laserRadius;
    auto laser2YCentre = _laser2.getLaser(laserTwo).getEntityCoordinates().getYposition() + laserRadius;
    
    auto alienXCentre = _alien.getEntityCoordinates().getXposition() + alienRadius;
    auto alienYCentre = _alien.getEntityCoordinates().getYposition() + alienRadius;

    auto centreDistance = sqrt(pow(laserXCentre - alienXCentre, 2) + pow(laserYCentre - alienYCentre, 2));
    
    auto centreDistance2 = sqrt(pow(laser2XCentre - alienXCentre, 2) + pow(laser2YCentre - alienYCentre, 2));
    
    if(centreDistance < radii_sum){
        _laser1.destroyLaser(laserOne);
        _alien.destroyEntity();
    }
    if(centreDistance2 < radii_sum){
         _laser2.destroyLaser(laserTwo);
         _alien.destroyEntity();
    }
}