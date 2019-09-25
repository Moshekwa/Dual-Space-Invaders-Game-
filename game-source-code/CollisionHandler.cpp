#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
    : _collisionDetector{ new CollisionDetector{} }
    , _gameUpdater{ new GameUpdater{} }
    , canonIsShot{ false }
{
}

CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::isLaserCanonShot()
{
    return canonIsShot;
}

void CollisionHandler::setCanonShotStateFalse()
{
    canonIsShot = false;
}

void CollisionHandler::handleLaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien, ScoreBoard& _scoreBoard)
{
    auto [alienKilledByLaser1, alienKilledByLaser2] = _collisionDetector->LaserAlienCollision(_laser1, _laser2, _alien);
    if(alienKilledByLaser1) {
        _alien.destroyEntity();
        _laser1.destroyEntity();
        _gameUpdater->updateCanon_ScoreAndHighScore(_scoreBoard, _alien);
    }
    if(alienKilledByLaser2) {
        _alien.destroyEntity();
        _laser2.destroyEntity();
        _gameUpdater->updateCanon_ScoreAndHighScore(_scoreBoard, _alien);
    }
}

void CollisionHandler::handleLaserCanonLaserCollision(LaserCanon& _laserCanon1,
    LaserCanon& _laserCanon2,
    Laser& _laser1,
    Laser& _laser2)
{
    auto [collisionOccured, laserCanonNumber] =
        _collisionDetector->LaserCanonLaserCollision(_laserCanon1, _laserCanon2, _laser1, _laser2);
    if(collisionOccured) {
        switch(laserCanonNumber) {
        case 1:
            _laserCanon1.destroyEntity();
            _laser2.destroyEntity();
            canonIsShot = true;
            break;
        case 2:
            _laserCanon2.destroyEntity();
            _laser1.destroyEntity();
            canonIsShot = true;
            break;
        default:
            break;
        }
    }
}

void CollisionHandler::handleLaserCanonAlienLaserCollision(LaserCanon& _laserCanon1,
    LaserCanon& _laserCanon2,
    Laser& _alienLaser)
{
    auto [collisionOccured, canonNumber] =
        _collisionDetector->LaserCanonAlienLaserCollision(_laserCanon1, _laserCanon2, _alienLaser);
    if(collisionOccured) {
        switch(canonNumber) {
        case 1:
            _laserCanon1.destroyEntity();
            _alienLaser.destroyEntity();
            canonIsShot = true;
            break;
        case 2:
            _laserCanon2.destroyEntity();
            _alienLaser.destroyEntity();
            canonIsShot = true;
            break;
        default:
            break;
        }
    }
}

void CollisionHandler::handleLaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield,
    Laser& _alienLaser)
{
    auto collisionOccured = _collisionDetector->LaserCanonShieldAlienLaserCollision(_laserCanonShield, _alienLaser);
    if(collisionOccured) {
        _laserCanonShield.destroyEntity();
        _alienLaser.destroyEntity();
    }
}

void CollisionHandler::handleLaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield,
    Laser& _laser1,
    Laser& _laser2)
{
    auto [shieldHitByLaser1, shieldHitByLaser2] =
        _collisionDetector->LaserCanonShieldLaserCollission(_laserCanonShield, _laser1, _laser2);

    if(shieldHitByLaser1) {
        _laser1.destroyEntity();
    }
    if(shieldHitByLaser2) {
        _laser2.destroyEntity();
    }
}

void CollisionHandler::handleLaser1Laser2Collision(Laser& _laser1, Laser& _laser2)
{
    auto collisionOccured = _collisionDetector->Laser1Laser2Collision(_laser1, _laser2);
    if(collisionOccured) {
        _laser1.destroyEntity();
        _laser2.destroyEntity();
    }
}

void CollisionHandler::handleLaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser)
{
    auto [collisionByLaser1, collisionByLaser2] =
        _collisionDetector->LaserAliensLaserCollision(_laser1, _laser2, _alienLaser);
    if(collisionByLaser1) {
        _laser1.destroyEntity();
        _alienLaser.destroyEntity();
    }
    if(collisionByLaser2) {
        _laser2.destroyEntity();
        _alienLaser.destroyEntity();
    }
}

void CollisionHandler::hanldleLaserCanonLaserCanonCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
{
    auto collisionOccured = _collisionDetector->LaserCanonLaserCanonCollision(_laserCanon1, _laserCanon2);
    if(collisionOccured) {
    }
}

void CollisionHandler::handleLaserCanonAlienCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Alien& _alien)
{
    auto [alienKilledByCanon1, alienKilledByCanon2] =
        _collisionDetector->LaserCanonAlienCollision(_laserCanon1, _laserCanon2, _alien);
    if(alienKilledByCanon1) {
        _laserCanon1.destroyEntity();
        _alien.destroyEntity();
    }
    if(alienKilledByCanon2) {
        _laserCanon2.destroyEntity();
        _alien.destroyEntity();
    }
}