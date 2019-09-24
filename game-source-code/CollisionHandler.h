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
    ~CollisionHandler();
    void handleLaserAlienCollision(Laser& _laser1,
        Laser& _laser2,
        Alien& _alien,
        ScoreBoard& _scoreBoard1,
        ScoreBoard& _scoreBoard2);
    void
    handleLaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);

    void handleLaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser);
    void handleLaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser);
    void handleLaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2);
    void handleLaser1Laser2Collision(Laser& _laser1, Laser& _laser2);
    void handleLaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser);

    bool isLaserCanonShot();
    void setCanonShotStateFalse();

private:
    shared_ptr<CollisionDetector> _collisionDetector;
    shared_ptr<GameUpdater> _gameUpdater;
    bool canonIsShot;
};

#endif // COLLISIONHANDLER_H_INCLUDED