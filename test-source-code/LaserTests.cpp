#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/CollisionDetector.h"
#include "../game-source-code/GameUpdater.h"
#include "../game-source-code/Laser.h"
#include "doctest.h"

TEST_CASE("Laser is able to initialize Laser coordinates")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser = Laser{ _laserCanon, 1 };
	//auto [ x_position, y_position ] = _laserCanon.entityPosition();
    CHECK(_laser.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_laser.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Laser is able to move up the screen")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser = Laser{ _laserCanon, 1 };
    _laser.move(Direction::UP);
    CHECK(_laser.getEntityCoordinates().getYposition() == yPosition - _laser.getEntitySpeed());
}

TEST_CASE("Laser is able to move down the screen")
{
    auto xPosition = 190;
    auto yPosition = 40;
    auto _laserCanon2 = LaserCanon{ xPosition, yPosition, 2, 3 };

    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.move(Direction::DOWN);
    CHECK(_laser2.getEntityCoordinates().getYposition() == yPosition + _laser2.getEntitySpeed());
}

TEST_CASE("Able to set the laser alive and also destroy it")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon1 = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser1 = Laser{ _laserCanon1, 1 };
    CHECK(_laser1.isAlive() == false);
    _laser1.giveEntityLife();
    CHECK(_laser1.isAlive() == true);
    _laser1.destroyEntity();
    CHECK(_laser1.isAlive() == false);
}

TEST_CASE("Laser does not go above the upper screen boundary, it gets distroyed and goes back to the canon")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon1 = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser1 = Laser{ _laserCanon1, 1 };

    _laser1.setYposition(40);
    _laser1.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaser1Position(_laserCanon1, _laser1);

    CHECK(_laser1.isAlive() == false);
    _gameUpdater.updateLaser1Position(_laserCanon1, _laser1);
    CHECK(_laser1.getEntityCoordinates().getYposition() == _laserCanon1.getEntityCoordinates().getYposition());
}

TEST_CASE("Laser does not go below the bottom screen boundary, it gets distroyed and goes back to the canon")
{
    auto xPosition = 190;
    auto yPosition = 40;
    auto _laserCanon2 = LaserCanon{ xPosition, yPosition, 2, 3 };

    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser2.setYposition(490);
    _laser2.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);

    CHECK(_laser2.isAlive() == false);
    _gameUpdater.updateLaser1Position(_laserCanon2, _laser2);
    CHECK(_laser2.getEntityCoordinates().getYposition() == _laserCanon2.getEntityCoordinates().getYposition());
}

TEST_CASE("Both lasers get destroyed when they collide")
{
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    _laser1.giveEntityLife();

    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.giveEntityLife();

    _laser1.setYposition(200);
    _laser2.setYposition(200);
    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.Laser1Laser2Collision(_laser1, _laser2);
    CHECK_FALSE(_laser1.isAlive());
    CHECK_FALSE(_laser2.isAlive());
}

TEST_CASE("Both lasers do not destroyed when did not collide")
{
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    _laser1.giveEntityLife();

    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.giveEntityLife();

    _laser1.setYposition(200);
    _laser2.setYposition(206); 
    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.Laser1Laser2Collision(_laser1, _laser2);
    CHECK(_laser1.isAlive());
    CHECK(_laser2.isAlive());
}

