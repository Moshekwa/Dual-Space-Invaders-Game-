/**
 * @file CollisionHandler.h
 * @class CollisionHandler
 * @brief This class makes decision based on whether or not collision between game objects occured.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef COLLISIONHANDLER_H_INCLUDED
#define COLLISIONHANDLER_H_INCLUDED
#include "CollisionDetector.h"
#include "GameUpdater.h"
#include "ScoreBoard.h"
#include <memory>
using std::shared_ptr;

class CollisionHandler
{
public:
    CollisionHandler();
    void handleLaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien, ScoreBoard& _scoreBoard);
    void
    handleLaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);

    void handleLaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser);
    void handleLaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser);
    void handleLaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2);
    void handleLaser1Laser2Collision(Laser& _laser1, Laser& _laser2);
    void handleLaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser);
    void hanldleLaserCanonLaserCanonCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);
    void handleLaserCanonAlienCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Alien& _alien);
    void handleCanonShieldLaserCanonCollision(LaserCanon& _laserCanon1,
        LaserCanon& _laserCanon2,
        LaserCanonShield& _laserCanonShield);

    /**
     * @brief returns true if a laser canon is destroyed from collision
     * @return
     */
    bool isLaserCanonKilled();
    /**
     * @brief sets a flag to be checked if collision occured
     */
    void setCanonKilledFlagFalse();
    ~CollisionHandler(){};

private:
    shared_ptr<CollisionDetector> _collisionDetector;
    shared_ptr<GameUpdater> _gameUpdater;
    bool canonIsKilled;
};

#endif // COLLISIONHANDLER_H_INCLUDED