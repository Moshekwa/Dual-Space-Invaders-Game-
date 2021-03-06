#include "CollisionDetector.h"
#include "GameUpdater.h"
#include <cmath>
#include <iostream>
using namespace std;

CollisionDetector::CollisionDetector()
{
}

tuple<bool, bool> CollisionDetector::LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien)
{
    auto [laser1_Xmin, laser1_Ymin, laser1_Xmax, laser1_Ymax] = _entityShape.laserShape(_laser1);
    auto [laser2_Xmin, laser2_Ymin, laser2_Xmax, laser2_Ymax] = _entityShape.laserShape(_laser2);
    auto [alien_Xmin, alien_Ymin, alien_Xmax, alien_Ymax] = _entityShape.alienShape(_alien);
    bool alienKilledByLaser1 = false;
    bool alienKilledByLaser2 = false;

    if((alien_Xmax > laser1_Xmin && alien_Xmin < laser1_Xmax) &&
        (alien_Ymax > laser1_Ymin && alien_Ymin < laser1_Ymax) && _alien.isAlive() && _laser1.isAlive()) {
        alienKilledByLaser1 = true;
    }
    if((alien_Xmax > laser2_Xmin && alien_Xmin < laser2_Xmax) &&
        (alien_Ymax > laser2_Ymin && alien_Ymin < laser2_Ymax) && _alien.isAlive() && _laser2.isAlive()) {
        alienKilledByLaser2 = true;
    }
    return { alienKilledByLaser1, alienKilledByLaser2 };
}

tuple<bool, int> CollisionDetector::LaserCanonLaserCollision(LaserCanon& _laserCanon1,
    LaserCanon& _laserCanon2,
    Laser& _laser1,
    Laser& _laser2)
{
    auto [laser1_Xmin, laser1_Ymin, laser1_Xmax, laser1_Ymax] = _entityShape.laserShape(_laser1);
    auto [laser2_Xmin, laser2_Ymin, laser2_Xmax, laser2_Ymax] = _entityShape.laserShape(_laser2);
    auto [laserCanon1_Xmin, laserCanon1_Ymin, laserCanon1_Xmax, laserCanon1_Ymax] =
        _entityShape.laserCanonShape(_laserCanon1);
    auto [laserCanon2_Xmin, laserCanon2_Ymin, laserCanon2_Xmax, laserCanon2_Ymax] =
        _entityShape.laserCanonShape(_laserCanon2);

    if((laserCanon2_Xmax > laser1_Xmin && laserCanon2_Xmin < laser1_Xmax) &&
        (laserCanon2_Ymax > laser1_Ymin && laserCanon2_Ymin < laser1_Ymax) && _laserCanon2.isAlive() &&
        _laser1.isAlive()) {
        return { true, 2 };
    }
    if((laserCanon1_Xmax >= laser2_Xmin && laserCanon1_Xmin <= laser2_Xmax) &&
        (laserCanon1_Ymax >= laser2_Ymin && laserCanon1_Ymin <= laser2_Ymax) && _laserCanon1.isAlive() &&
        _laser2.isAlive()) {
        return { true, 1 };
    }
    return { false, 0 };
}

tuple<bool, int>
CollisionDetector::LaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser)
{
    auto [laserCanon1_Xmin, laserCanon1_Ymin, laserCanon1_Xmax, laserCanon1_Ymax] =
        _entityShape.laserCanonShape(_laserCanon1);
    auto [laserCanon2_Xmin, laserCanon2_Ymin, laserCanon2_Xmax, laserCanon2_Ymax] =
        _entityShape.laserCanonShape(_laserCanon2);
    auto [alienlaser_Xmin, alienlaser_Ymin, alienlaser_Xmax, alienlaser_Ymax] =
        _entityShape.alienLaserShape(_alienLaser);

    if((laserCanon1_Xmax > alienlaser_Xmin && laserCanon1_Xmin < alienlaser_Xmax) &&
        (laserCanon1_Ymax > alienlaser_Ymin && laserCanon1_Ymin < alienlaser_Ymax) && _laserCanon1.isAlive() &&
        _alienLaser.isAlive()) {
        return { true, 1 };
    }

    if((laserCanon2_Xmax > alienlaser_Xmin && laserCanon2_Xmin < alienlaser_Xmax) &&
        (laserCanon2_Ymax > alienlaser_Ymin && laserCanon2_Ymin < alienlaser_Ymax) && (_laserCanon2.isAlive()) &&
        _alienLaser.isAlive()) {
        return { true, 2 };
    }

    return { false, 0 };
}

bool CollisionDetector::LaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser)
{
    auto [shield_Xmin, shield_Ymin, shield_Xmax, shield_Ymax] = _entityShape.laserCanonShieldShape(_laserCanonShield);
    auto [alienlaser_Xmin, alienlaser_Ymin, alienlaser_Xmax, alienlaser_Ymax] =
        _entityShape.alienLaserShape(_alienLaser);

    if((shield_Xmax > alienlaser_Xmin && shield_Xmin < alienlaser_Xmax) &&
        (shield_Ymax > alienlaser_Ymin && shield_Ymin < alienlaser_Ymax) &&
        (_laserCanonShield.isAlive() && _alienLaser.isAlive()) && _alienLaser.isAlive()) {
        return true;
    }
    return false;
}

tuple<bool, bool>
CollisionDetector::LaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2)
{
    auto [shield_Xmin, shield_Ymin, shield_Xmax, shield_Ymax] = _entityShape.laserCanonShieldShape(_laserCanonShield);
    auto [laser1_Xmin, laser1_Ymin, laser1_Xmax, laser1_Ymax] = _entityShape.laserShape(_laser1);
    auto [laser2_Xmin, laser2_Ymin, laser2_Xmax, laser2_Ymax] = _entityShape.laserShape(_laser2);
    auto shieldHitByLaser1 = false;
    auto shieldHitByLaser2 = false;

    if((shield_Xmax > laser1_Xmin && shield_Xmin < laser1_Xmax) &&
        (shield_Ymax > laser1_Ymin && shield_Ymin < laser1_Ymax) && (_laserCanonShield.isAlive()) &&
        _laser1.isAlive()) {
        shieldHitByLaser1 = true;
    }
    if((shield_Xmax >= laser2_Xmin && shield_Xmin <= laser2_Xmax) &&
        (shield_Ymax >= laser2_Ymin && shield_Ymin <= laser2_Ymax) && (_laserCanonShield.isAlive()) &&
        _laser2.isAlive()) {
        shieldHitByLaser2 = true;
    }
    return { shieldHitByLaser1, shieldHitByLaser2 };
}

bool CollisionDetector::Laser1Laser2Collision(Laser& _laser1, Laser& _laser2)
{
    auto [laser1_Xmin, laser1_Ymin, laser1_Xmax, laser1_Ymax] = _entityShape.laserShape(_laser1);
    auto [laser2_Xmin, laser2_Ymin, laser2_Xmax, laser2_Ymax] = _entityShape.laserShape(_laser2);

    if((laser2_Xmax > laser1_Xmin && laser2_Xmin < laser1_Xmax) &&
        (laser2_Ymax > laser1_Ymin && laser2_Ymin < laser1_Ymax) && _laser1.isAlive() && _laser2.isAlive()) {
        return true;
    }
    return false;
}

tuple<bool, bool> CollisionDetector::LaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser)
{
    auto [laser1_Xmin, laser1_Ymin, laser1_Xmax, laser1_Ymax] = _entityShape.laserShape(_laser1);
    auto [laser2_Xmin, laser2_Ymin, laser2_Xmax, laser2_Ymax] = _entityShape.laserShape(_laser2);
    auto [alienlaser_Xmin, alienlaser_Ymin, alienlaser_Xmax, alienlaser_Ymax] =
        _entityShape.alienLaserShape(_alienLaser);
    auto collisionByLaser1 = false;
    auto collisionByLaser2 = false;

    if((alienlaser_Xmax > laser1_Xmin && alienlaser_Xmin < laser1_Xmax) &&
        (alienlaser_Ymax > laser1_Ymin && alienlaser_Ymin < laser1_Ymax) && _laser1.isAlive() &&
        _alienLaser.isAlive()) {
        collisionByLaser1 = true;
    }

    if((alienlaser_Xmax > laser2_Xmin && alienlaser_Xmin < laser2_Xmax) &&
        (alienlaser_Ymax > laser2_Ymin && alienlaser_Ymin < laser2_Ymax) && _laser2.isAlive() &&
        _alienLaser.isAlive()) {
        collisionByLaser2 = true;
    }

    return { collisionByLaser1, collisionByLaser2 };
}

bool CollisionDetector::LaserCanonLaserCanonCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
{
    auto [laserCanon1_Xmin, laserCanon1_Ymin, laserCanon1_Xmax, laserCanon1_Ymax] =
        _entityShape.laserCanonShape(_laserCanon1);
    auto [laserCanon2_Xmin, laserCanon2_Ymin, laserCanon2_Xmax, laserCanon2_Ymax] =
        _entityShape.laserCanonShape(_laserCanon2);

    if((laserCanon1_Xmax >= laserCanon2_Xmin && laserCanon1_Xmin <= laserCanon2_Xmax) &&
        (laserCanon1_Ymax >= laserCanon2_Ymin && laserCanon1_Ymin <= laserCanon2_Ymax) && (_laserCanon1.isAlive()) &&
        _laserCanon2.isAlive()) {
        return true;
    }
    return false;
}

tuple<bool, bool>
CollisionDetector::LaserCanonAlienCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Alien& _alien)
{
    auto [laserCanon1_Xmin, laserCanon1_Ymin, laserCanon1_Xmax, laserCanon1_Ymax] =
        _entityShape.laserCanonShape(_laserCanon1);
    auto [laserCanon2_Xmin, laserCanon2_Ymin, laserCanon2_Xmax, laserCanon2_Ymax] =
        _entityShape.laserCanonShape(_laserCanon2);
    auto [alien_Xmin, alien_Ymin, alien_Xmax, alien_Ymax] = _entityShape.alienShape(_alien);
    auto alienKilledByCanon1 = false;
    auto alienKilledByCanon2 = false;

    if((laserCanon1_Xmax >= alien_Xmin && laserCanon1_Xmin <= alien_Xmax) &&
        (laserCanon1_Ymax >= alien_Ymin && laserCanon1_Ymin <= alien_Ymax) && (_laserCanon1.isAlive()) &&
        _alien.isAlive()) {
        alienKilledByCanon1 = true;
        return { alienKilledByCanon1, alienKilledByCanon2 };
    }
    if((laserCanon2_Xmax >= alien_Xmin && laserCanon2_Xmin <= alien_Xmax) &&
        (laserCanon2_Ymax >= alien_Ymin && laserCanon2_Ymin <= alien_Ymax) && (_laserCanon2.isAlive()) &&
        _alien.isAlive()) {
        alienKilledByCanon2 = true;
        return { alienKilledByCanon1, alienKilledByCanon2 };
    }
    return { alienKilledByCanon1, alienKilledByCanon2 };
}

tuple<bool, bool> CollisionDetector::CanonShieldLaserCanonCollision(LaserCanon& _laserCanon1,
    LaserCanon& _laserCanon2,
    LaserCanonShield& _laserCanonShield)
{
    auto [laserCanon1_Xmin, laserCanon1_Ymin, laserCanon1_Xmax, laserCanon1_Ymax] =
        _entityShape.laserCanonShape(_laserCanon1);
    auto [laserCanon2_Xmin, laserCanon2_Ymin, laserCanon2_Xmax, laserCanon2_Ymax] =
        _entityShape.laserCanonShape(_laserCanon2);
    auto [shield_Xmin, shield_Ymin, shield_Xmax, shield_Ymax] = _entityShape.laserCanonShieldShape(_laserCanonShield);
    auto shieldHitByCanon1 = false;
    auto shieldHitByCanon2 = false;

    if((laserCanon1_Xmax >= shield_Xmin && laserCanon1_Xmin <= shield_Xmax) &&
        (laserCanon1_Ymax >= shield_Ymin && laserCanon1_Ymin <= shield_Ymax) && (_laserCanon1.isAlive()) &&
        _laserCanonShield.isAlive()) {
        shieldHitByCanon1 = true;
    }
    if((laserCanon2_Xmax >= shield_Xmin && laserCanon2_Xmin <= shield_Xmax) &&
        (laserCanon2_Ymax >= shield_Ymin && laserCanon2_Ymin <= shield_Ymax) && (_laserCanon2.isAlive()) &&
        _laserCanonShield.isAlive()) {
        shieldHitByCanon2 = true;
    }
    return { shieldHitByCanon1, shieldHitByCanon2 };
}