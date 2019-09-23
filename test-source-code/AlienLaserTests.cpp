#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/CollisionDetector.h"
#include "../game-source-code/GameUpdater.h"
#include "../game-source-code/Laser.h"
#include "doctest.h"

TEST_CASE("Able to initialise alien laser positions")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };

    auto [x_position, y_position] = _alienLaser.entityPosition();
    CHECK(x_position == xPosition);
    CHECK(y_position == yPosition);
}

TEST_CASE("Laser is able to move up the screen")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.move(Direction::UP);
    auto y_position = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == yPosition - _alienLaser.getEntitySpeed());
}

TEST_CASE("Laser is able to move down the screen")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.move(Direction::DOWN);
    auto y_position = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == yPosition + _alienLaser.getEntitySpeed());
}

TEST_CASE("Able to set the laser alive and also destroy it")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    CHECK_FALSE(_alienLaser.isAlive());
    _alienLaser.giveEntityLife();
    CHECK(_alienLaser.isAlive());
    _alienLaser.destroyEntity();
    CHECK_FALSE(_alienLaser.isAlive());
}

TEST_CASE("Laser does not go above the upper screen boundary, it gets distroyed and goes back to the alien")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.setYposition(40);
    _alienLaser.giveEntityLife();

    auto _gameUpdater = GameUpdater{};

    _gameUpdater.updateUpAlienLaserPosition(_alien, _alienLaser);
    CHECK_FALSE(_alienLaser.isAlive());
    _gameUpdater.updateUpAlienLaserPosition(_alien, _alienLaser);

    auto y_position = get<1>(_alien.entityPosition());
    auto y_position2 = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == y_position2);
}

TEST_CASE("Laser does not go below the bottom screen boundary, it gets distroyed and goes back to the alien")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.setYposition(490);
    _alienLaser.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateAlienLaserPosition(_alien, _alienLaser);
    CHECK_FALSE(_alienLaser.isAlive());
    _gameUpdater.updateAlienLaserPosition(_alien, _alienLaser);
    auto y_position = get<1>(_alien.entityPosition());
    auto y_position2 = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == y_position2);
}

TEST_CASE("Alien laser and canon laser gets destroyed when they collide")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser1.giveEntityLife();
    _alienLaser.giveEntityLife();
    _laser1.setYposition(300);
    _alienLaser.setYposition(300);
    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserAliensLaserCollision(_laser1, _laser2, _alienLaser);

    CHECK_FALSE(_laser1.isAlive());
    CHECK_FALSE(_alienLaser.isAlive());
} 