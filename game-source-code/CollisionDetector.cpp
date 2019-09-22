#include "CollisionDetector.h"
#include <cmath>

CollisionDetector::CollisionDetector()
{
}

void CollisionDetector::LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien)
{
    auto [laser1_xPosition, laser1_yPosition] = _laser1.entityPosition();
    auto [laser2_xPosition, laser2_yPosition] = _laser2.entityPosition();
    auto [alienXposition, alienYposition] = _alien.entityPosition();

    auto radii_sum = laserRadius + alienRadius;

    auto laserXCentre = laser1_xPosition + laserRadius;
    auto laserYCentre = laser1_yPosition + laserRadius;

    auto laser2XCentre = laser2_xPosition + laserRadius;
    auto laser2YCentre = laser2_yPosition + laserRadius;

    auto alienXCentre = alienXposition + alienRadius;
    auto alienYCentre = alienYposition + alienRadius;

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

tuple<bool, int> CollisionDetector::LaserCanonLaserCollision(LaserCanon& _laserCanon1,
    LaserCanon& _laserCanon2,
    Laser& _laser1,
    Laser& _laser2)
{
    auto [canon1_xPosition, canon1_yPosition] = _laserCanon1.entityPosition();
    auto [canon2_xPosition, canon2_yPosition] = _laserCanon2.entityPosition();
    auto [laser1_xPosition, laser1_yPosition] = _laser1.entityPosition();
    auto [laser2_xPosition, laser2_yPosition] = _laser2.entityPosition();

    auto radii_sum = laserRadius + laserCanonRadius;
    auto laserXCentre = laser1_xPosition + laserRadius;
    auto laserYCentre = laser1_yPosition + laserRadius;
    auto laser2XCentre = laser2_xPosition + laserRadius;
    auto laser2YCentre = laser2_yPosition + laserRadius;

    auto LaserCanonXcentre = canon1_xPosition + laserCanonRadius;
    auto LaserCanonYcentre = canon1_yPosition + laserCanonRadius;
    auto LaserCanon2Xcentre = canon2_xPosition + laserCanonRadius;
    auto LaserCanon2Ycentre = canon2_yPosition + laserCanonRadius;

    auto centreDistance = sqrt(pow(laserXCentre - LaserCanon2Xcentre, 2) + pow(laserYCentre - LaserCanon2Ycentre, 2));
    auto centreDistance2 = sqrt(pow(laser2XCentre - LaserCanonXcentre, 2) + pow(laser2YCentre - LaserCanonYcentre, 2));

    if(centreDistance < radii_sum && _laserCanon2.isAlive() && _laser1.isAlive()) {
        _laser1.destroyEntity();
        return { true, 2 };
    }

    if(centreDistance2 < radii_sum && _laserCanon1.isAlive() && _laser2.isAlive()) {
        _laser2.destroyEntity();
        return { true, 1 };
    }
    return { false, 0 };
}

tuple<bool, int>
CollisionDetector::LaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser)
{

    auto [canon1_xPosition, canon1_yPosition] = _laserCanon1.entityPosition();
    auto [canon2_xPosition, canon2_yPosition] = _laserCanon2.entityPosition();
    auto [alienLaser_xPosition, alienLaser_yPosition] = _alienLaser.entityPosition();

    auto radii_sum = laserRadius + laserCanonRadius;
    auto laserXCentre = alienLaser_xPosition + laserRadius;
    auto laserYCentre = alienLaser_yPosition + laserRadius;

    auto LaserCanonXcentre = canon1_xPosition + laserCanonRadius;
    auto LaserCanonYcentre = canon1_yPosition + laserCanonRadius;
    auto LaserCanon2Xcentre = canon2_xPosition + laserCanonRadius;
    auto LaserCanon2Ycentre = canon2_yPosition + laserCanonRadius;

    auto centreDistance = sqrt(pow(laserXCentre - LaserCanonXcentre, 2) + pow(laserYCentre - LaserCanonYcentre, 2));
    auto centreDistance2 = sqrt(pow(laserXCentre - LaserCanon2Xcentre, 2) + pow(laserYCentre - LaserCanon2Ycentre, 2));

    if(centreDistance < radii_sum && _laserCanon1.isAlive() && _alienLaser.isAlive()) {
        _alienLaser.destroyEntity();
        //_laserCanon1.destroyEntity();
        return { true, 1 };
    }

    if(centreDistance2 < radii_sum && _laserCanon2.isAlive() && _alienLaser.isAlive()) {
        _alienLaser.destroyEntity();
        //_laserCanon2.destroyEntity();
        return { true, 2 };
    }
    return { false, 0 };
}

void CollisionDetector::LaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser)
{
    auto [shield_xPosition, shield_yposition] = _laserCanonShield.entityPosition();
    auto [alienLaser_xPosition, alienLaser_yPosition] = _alienLaser.entityPosition();

    auto radii_sum = laserRadius + LaserCanonShieldRadius;
    auto laserXCentre = alienLaser_xPosition + laserRadius;
    auto laserYCentre = alienLaser_yPosition + laserRadius;

    auto LaserCanonShieldXcentre = shield_xPosition + LaserCanonShieldRadius;
    auto LaserCanonShieldYcentre = shield_yposition + LaserCanonShieldRadius;

    auto centreDistance =
        sqrt(pow(laserXCentre - LaserCanonShieldXcentre, 2) + pow(laserYCentre - LaserCanonShieldYcentre, 2));

    if(centreDistance < radii_sum && _alienLaser.isAlive() && _laserCanonShield.isAlive()) {
        _laserCanonShield.destroyEntity();
        _alienLaser.destroyEntity();
    }
}

void CollisionDetector::LaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield,
    Laser& _laser1,
    Laser& _laser2)
{
    auto [shield_xPosition, shield_yposition] = _laserCanonShield.entityPosition();
    auto [laser1_xPosition, laser1_yPosition] = _laser1.entityPosition();
    auto [laser2_xPosition, laser2_yPosition] = _laser2.entityPosition();

    auto radii_sum = laserRadius + LaserCanonShieldRadius;

    auto laserXCentre = laser1_xPosition + laserRadius;
    auto laserYCentre = laser1_yPosition + laserRadius;

    auto laser2XCentre = laser2_xPosition + laserRadius;
    auto laser2YCentre = laser2_yPosition + laserRadius;

    auto LaserCanonShieldXcentre = shield_xPosition + LaserCanonShieldRadius;
    auto LaserCanonShieldYcentre = shield_yposition + LaserCanonShieldRadius;

    auto centreDistance =
        sqrt(pow(laserXCentre - LaserCanonShieldXcentre, 2) + pow(laserYCentre - LaserCanonShieldYcentre, 2));
    auto centreDistance2 =
        sqrt(pow(laser2XCentre - LaserCanonShieldXcentre, 2) + pow(laser2YCentre - LaserCanonShieldYcentre, 2));

    if(centreDistance < radii_sum && _laser1.isAlive() && _laserCanonShield.isAlive()) {
        _laser1.destroyEntity();
    }
    if(centreDistance2 < radii_sum && _laser2.isAlive() && _laserCanonShield.isAlive()) {
        _laser2.destroyEntity();
    }
}

void CollisionDetector::Laser1Laser2Collision(Laser& _laser1, Laser& _laser2)
{
    auto [laser1_xPosition, laser1_yPosition] = _laser1.entityPosition();
    auto [laser2_xPosition, laser2_yPosition] = _laser2.entityPosition();

    auto radii_sum = laserRadius + laserRadius;
    auto laserXCentre = laser1_xPosition + laserRadius;
    auto laserYCentre = laser1_yPosition + laserRadius;

    auto laser2XCentre = laser2_xPosition + laserRadius;
    auto laser2YCentre = laser2_yPosition + laserRadius;

    auto centreDistance = sqrt(pow(laserXCentre - laser2XCentre, 2) + pow(laserYCentre - laser2YCentre, 2));

    if(centreDistance < radii_sum && _laser1.isAlive() && _laser2.isAlive()) {
        _laser1.destroyEntity();
        _laser2.destroyEntity();
    }
}

void CollisionDetector::LaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser)
{
    auto [laser1_xPosition, laser1_yPosition] = _laser1.entityPosition();
    auto [laser2_xPosition, laser2_yPosition] = _laser2.entityPosition();
    auto [alienLaser_xPosition, alienLaser_yPosition] = _alienLaser.entityPosition();
    
    auto radii_sum = laserRadius + alienRadius;
    auto laserXCentre = laser1_xPosition + laserRadius;
    auto laserYCentre = laser1_yPosition + laserRadius;

    auto laser2XCentre = laser2_xPosition + laserRadius;
    auto laser2YCentre = laser2_yPosition + laserRadius;

    auto alienLaserXCentre = alienLaser_xPosition + laserRadius;
    auto alienLaserYCentre = alienLaser_yPosition + laserRadius;

    auto centreDistance = sqrt(pow(laserXCentre - alienLaserXCentre, 2) + pow(laserYCentre - alienLaserYCentre, 2));
    auto centreDistance2 = sqrt(pow(laser2XCentre - alienLaserXCentre, 2) + pow(laser2YCentre - alienLaserYCentre, 2));

    if(centreDistance < radii_sum && _laser1.isAlive() && _alienLaser.isAlive()) {
        _laser1.destroyEntity();
        _alienLaser.destroyEntity();
    }

    if(centreDistance2 < radii_sum && _laser2.isAlive() && _alienLaser.isAlive()) {
        _laser2.destroyEntity();
        _alienLaser.destroyEntity();
    }
}
