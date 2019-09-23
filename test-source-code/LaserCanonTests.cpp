#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/CollisionDetector.h"
#include "../game-source-code/Laser.h"
#include "../game-source-code/LaserCanon.h"
#include "doctest.h"

TEST_CASE("Testing for Invalid Laser Canon Coordinates of the second player")
{
    auto xPosition = 500;
    auto yPosition = 0;
    CHECK_THROWS_AS(LaserCanon(xPosition, yPosition, 2, 3), InvalidLaserCanonCoordinates);
}

TEST_CASE("Testing if player is able to create 2 Laser Canon objects at different initial positions")
{
    auto xPosition1 = 190;
    auto yPosition1 = 480;
    auto xPosition2 = 190;
    auto yPosition2 = 40;
    auto _laserCanon1 = LaserCanon{ xPosition1, yPosition1, 1, 3 };
    auto _laserCanon2 = LaserCanon{ xPosition2, yPosition2, 2, 3 };

    CHECK(get<0>(_laserCanon1.entityPosition()) == xPosition1);
    CHECK(get<0>(_laserCanon2.entityPosition()) == xPosition2);
    CHECK(get<1>(_laserCanon1.entityPosition()) == yPosition1);
    CHECK(get<1>(_laserCanon2.entityPosition()) == yPosition2);
}

TEST_CASE("Testing the setPosition functions for Laser Canon")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ 20, 480, 1, 3 };

    _laserCanon.setXposition(xPosition);
    _laserCanon.setYposition(yPosition);

    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition);
}

TEST_CASE("Testing the move function for Lasor Canon")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    _laserCanon.move(Direction::LEFT);
    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    _laserCanon.move(Direction::RIGHT);
    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition);
}

TEST_CASE("Laser Canon obeys the left boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };
    _laserCanon.setXposition(0);
    _laserCanon.move(Direction::LEFT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == 0);
}

TEST_CASE("Laser Canon obeys the right boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };
    _laserCanon.setXposition(380);
    _laserCanon.move(Direction::RIGHT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition + _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == 380);
}

TEST_CASE("Testing the destroyEntity function for laserCanon")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 3;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.destroyEntity();
    CHECK(_laserCanon.getNumberOfLives() == laserCanonLives - 1);
}

TEST_CASE("LaserCanon life is set false when it's number of lives is zero")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 1;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.destroyEntity();
    CHECK(_laserCanon.getNumberOfLives() == 0);
    CHECK(_laserCanon.isAlive() == false);
}

TEST_CASE("Collision detection of laserCanon1 and the laser from canon2")
{
    auto laserCanon1_Xposition = 190;
    auto laserCanon1_Yposition = 480;
    auto laserCanon2_Xposition = 190;
    auto laserCanon2_Yposition = 40;

    auto laserCanonLives = 1;

    auto _laserCanon1 = LaserCanon{ laserCanon1_Xposition, laserCanon1_Yposition, 1, laserCanonLives };
    auto _laserCanon2 = LaserCanon{ laserCanon2_Xposition, laserCanon2_Yposition, 2, laserCanonLives };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser2.setXposition(laserCanon1_Xposition);
    _laser2.setYposition(laserCanon1_Yposition);
    _laser2.giveEntityLife();

    auto _collisionDetector = CollisionDetector{};
    auto [collisionOccured, laserCanonNumber] =
        _collisionDetector.LaserCanonLaserCollision(_laserCanon1, _laserCanon2, _laser1, _laser2);

    CHECK(collisionOccured == true);
    CHECK(laserCanonNumber == 1);
}

TEST_CASE("Collision detection of laserCanon2 and the laser from canon1")
{
    auto laserCanon1_Xposition = 190;
    auto laserCanon1_Yposition = 480;
    auto laserCanon2_Xposition = 190;
    auto laserCanon2_Yposition = 40;

    auto laserCanonLives = 1;

    auto _laserCanon1 = LaserCanon{ laserCanon1_Xposition, laserCanon1_Yposition, 1, laserCanonLives };
    auto _laserCanon2 = LaserCanon{ laserCanon2_Xposition, laserCanon2_Yposition, 2, laserCanonLives };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser1.setXposition(laserCanon2_Xposition);
    _laser1.setYposition(laserCanon2_Yposition);
    _laser1.giveEntityLife();

    auto _collisionDetector = CollisionDetector{};
    auto [collisionOccured, laserCanonNumber] =
        _collisionDetector.LaserCanonLaserCollision(_laserCanon1, _laserCanon2, _laser1, _laser2);

    CHECK(collisionOccured == true);
    CHECK(laserCanonNumber == 2);
}

TEST_CASE("Setting and returning the score of the laserCanon correctly")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 3;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.setScore(10);
    CHECK(get<0>(_laserCanon.getScoreAndHighScore()) == 10);
}

TEST_CASE("The correct high score is set and returned")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 3;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.setScore(20);
    _laserCanon.setScore(10);
    auto [score, highScore] = _laserCanon.getScoreAndHighScore();
    CHECK(score == 10);
    CHECK(highScore == 20);
}