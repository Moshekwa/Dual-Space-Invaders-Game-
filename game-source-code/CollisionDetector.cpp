#include "CollisionDetector.h"
#include <cmath>

CollisionDetector::CollisionDetector()
{
}

void CollisionDetector::LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien)
{
    auto radii_sum = laserRadius + alienRadius;
    auto laserXCentre = _laser1.getEntityCoordinates().getXposition() + laserRadius;
    auto laserYCentre = _laser1.getEntityCoordinates().getYposition() + laserRadius;

    auto laser2XCentre = _laser2.getEntityCoordinates().getXposition() + laserRadius;
    auto laser2YCentre = _laser2.getEntityCoordinates().getYposition() + laserRadius;

    auto alienXCentre = _alien.getEntityCoordinates().getXposition() + alienRadius;
    auto alienYCentre = _alien.getEntityCoordinates().getYposition() + alienRadius;

    auto centreDistance = sqrt(pow(laserXCentre - alienXCentre, 2) + pow(laserYCentre - alienYCentre, 2));

    auto centreDistance2 = sqrt(pow(laser2XCentre - alienXCentre, 2) + pow(laser2YCentre - alienYCentre, 2));

    if(centreDistance < radii_sum && _alien.isAlive()) {
	_laser1.destroyEntity();
	_alien.destroyEntity();
    }
    if(centreDistance2 < radii_sum && _alien.isAlive()) {
	_laser2.destroyEntity();
	_alien.destroyEntity();
    }
}

void CollisionDetector::LaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2)
{
    auto radii_sum = laserRadius + laserCanonRadius;
    auto laserXCentre = _laser1.getEntityCoordinates().getXposition() + laserRadius;
    auto laserYCentre = _laser1.getEntityCoordinates().getYposition() + laserRadius;
    auto laser2XCentre = _laser2.getEntityCoordinates().getXposition() + laserRadius;
    auto laser2YCentre = _laser2.getEntityCoordinates().getYposition() + laserRadius;

    auto LaserCanonXcentre = _laserCanon1.getEntityCoordinates().getXposition() + laserCanonRadius;
    auto LaserCanonYcentre = _laserCanon1.getEntityCoordinates().getYposition() + laserCanonRadius;
    auto LaserCanon2Xcentre = _laserCanon2.getEntityCoordinates().getXposition() + laserCanonRadius;
    auto LaserCanon2Ycentre = _laserCanon2.getEntityCoordinates().getYposition() + laserCanonRadius;

    auto centreDistance = sqrt(pow(laserXCentre - LaserCanon2Xcentre, 2) + pow(laserYCentre - LaserCanon2Ycentre, 2));
    auto centreDistance2 = sqrt(pow(laser2XCentre - LaserCanonXcentre, 2) + pow(laser2YCentre - LaserCanonYcentre, 2));

    if(centreDistance < radii_sum && _laserCanon2.isAlive() && _laser1.isAlive()) {
	_laser1.destroyEntity();
	_laserCanon2.destroyEntity();
    }

    if(centreDistance2 < radii_sum && _laserCanon1.isAlive() && _laser2.isAlive()) {
	_laser2.destroyEntity();
	_laserCanon1.destroyEntity();
    }
}