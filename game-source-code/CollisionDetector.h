/**
 * @file CollisionDetector.h
 * @class CollisionDetector
 * @brief This class is responsible for detecting collision of game objects.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef COLLISIONDETECTOR_H_INCLUDED
#define COLLISIONDETECTOR_H_INCLUDED
#include "EntityShape.h"
#include <tuple>
using namespace std;

class CollisionDetector
{
public:
    CollisionDetector();
    /**
     * @brief Detects collision between a canon laser and an alien
     * @param _laser1
     * @param _laser2
     * @param _alien
     * @return
     */
    tuple<bool, bool> LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien);

    /**
     * @brief Detects the collision between the laser canon and the laser of a different canon
     * @param _laserCanon1
     * @param _laserCanon2
     * @param _laser1
     * @param _laser2
     */
    tuple<bool, int>
    LaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);
    /**
     * @brief detects collision between laser canon and the alien laser
     * @param _laserCanon1
     * @param _laserCanon2
     * @param _alienLaser
     */
    tuple<bool, int>
    LaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser);
    /**
     * @brief detects the collision between the shield and an alien laser
     * @param _laserCanonShield
     * @param _alienLaser
     * @return
     */
    bool LaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser);
    /**
     * @brief detects the collision between the shield and a canon laser
     * @param _laserCanonShield
     * @param _laser1
     * @param _laser2
     */
    tuple<bool, bool>
    LaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2);
    /**
     * @brief detects collision between the canon lasers
     * @param _laser1
     * @param _laser2
     * @return
     */
    bool Laser1Laser2Collision(Laser& _laser1, Laser& _laser2);
    /**
     * @brief detects collision between the canon laser and an alien laser
     * @param _laser1
     * @param _laser2
     * @param _alienLaser
     * @return
     */
    tuple<bool, bool> LaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser);
    /**
     * @brief detects collision between laser canons
     * @param _laserCanon1
     * @param _laserCanon2
     * @return
     */
    bool LaserCanonLaserCanonCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);
    /**
     * @brief detects the laser canon and alien collision
     * @param _laserCanon1
     * @param _laserCanon2
     * @param _alien
     * @return
     */
    tuple<bool, bool> LaserCanonAlienCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Alien& _alien);
    /**
     * @brief detects collision between a shield and the laser canon
     * @param _laserCanon1
     * @param _laserCanon2
     * @param _laserCanonShield
     * @return
     */
    tuple<bool, bool> CanonShieldLaserCanonCollision(LaserCanon& _laserCanon1,
        LaserCanon& _laserCanon2,
        LaserCanonShield& _laserCanonShield);
    ~CollisionDetector(){};

private:
    EntityShape _entityShape;
};

#endif // COLLISIONDETECTOR_H_INCLUDED