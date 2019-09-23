#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/CollisionDetector.h"
#include "../game-source-code/GameUpdater.h"
#include "../game-source-code/Laser.h"
#include "doctest.h"

TEST_CASE("Exception throw for Invalid Alien Coordinates")
{
    auto x_position = 390;
    auto y_position = 400;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);

    x_position = 200;
    y_position = 490;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);

    x_position = 200;
    y_position = 39;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);
}

TEST_CASE("Testing if the Alien class is able to create a valid object with initial positions")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    auto [alien_Xposition, alien_Yposition] = _alien.entityPosition();
    CHECK(alien_Xposition == xPosition);
    CHECK(alien_Yposition == yPosition);
}

TEST_CASE("Testing the move fuction")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };

    _alien.move(Direction::LEFT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition - _alien.getEntitySpeed());

    _alien.move(Direction::RIGHT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);

    _alien.move(Direction::UP);
    CHECK(get<1>(_alien.entityPosition()) == yPosition - 2 * _alien.getEntitySpeed());

    _alien.move(Direction::DOWN);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Testing the move function at right boundary")
{
    auto xPosition = 380;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::RIGHT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);
}

TEST_CASE("Testing the move function at left boundary")
{
    auto xPosition = 0;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::LEFT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);
}

TEST_CASE("Testing the move function at upper boundary")
{
    auto xPosition = 0;
    auto yPosition = 70;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::UP);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Testing the move function at bottom boundary")
{
    auto xPosition = 380;
    auto yPosition = 450;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::DOWN);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Alien gets destroyed when hit by a laserCanon laser")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto alienLives = 1;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives, AlienColour::GREEN };

    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();

    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserAlienCollision(_laser1, _laser2, _alien, _laserCanon1, _laserCanon2);

    CHECK(_alien.isAlive() == false);
}

TEST_CASE("Score gets updated correctly for different aliens")
{
    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto alienLives = 1;

    auto _greenAlien = Alien{ 200, 200, 380, 0, alienLives, AlienColour::GREEN };
    auto _purpleAlien = Alien{ 200, 200, 380, 0, alienLives, AlienColour::PURPLE };
    auto _redAlien = Alien{ 200, 200, 380, 0, alienLives, AlienColour::RED };

    auto _gameUpdater = GameUpdater{};

    _gameUpdater.updateCanon1_Score(_laserCanon1, _greenAlien);
    _gameUpdater.updateCanon2_Score(_laserCanon2, _greenAlien);
    CHECK(get<0>(_laserCanon1.getScoreAndHighScore()) == 30);
    CHECK(get<0>(_laserCanon2.getScoreAndHighScore()) == 30);

    _laserCanon1.setScore(0);
    _laserCanon2.setScore(0);
    _gameUpdater.updateCanon1_Score(_laserCanon1, _purpleAlien);
    _gameUpdater.updateCanon2_Score(_laserCanon2, _purpleAlien);
    CHECK(get<0>(_laserCanon1.getScoreAndHighScore()) == 20);
    CHECK(get<0>(_laserCanon2.getScoreAndHighScore()) == 20);

    _laserCanon1.setScore(0);
    _laserCanon2.setScore(0);
    _gameUpdater.updateCanon1_Score(_laserCanon1, _redAlien);
    _gameUpdater.updateCanon2_Score(_laserCanon2, _redAlien);
    CHECK(get<0>(_laserCanon1.getScoreAndHighScore()) == 10);
    CHECK(get<0>(_laserCanon2.getScoreAndHighScore()) == 10);
}

TEST_CASE("Score gets updated when an alien is shot")
{
    auto xposition = 200;
    auto yposition = 200;
    auto xposition2 = 100;
    auto yposition2 = 100;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };
    auto _alien = Alien{ xposition, yposition, 380, 0, 1, AlienColour::GREEN };
    auto _alien2 = Alien{ xposition2, yposition2, 380, 0, 1, AlienColour::RED };

    _laser1.setXposition(xposition);
    _laser1.setYposition(yposition);
    _laser2.setXposition(xposition2);
    _laser2.setYposition(yposition2);
    _laser1.giveEntityLife();
    _laser2.giveEntityLife();

    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserAlienCollision(_laser1, _laser2, _alien, _laserCanon1, _laserCanon2);
    _collisionDetector.LaserAlienCollision(_laser1, _laser2, _alien2, _laserCanon1, _laserCanon2);

    CHECK(get<0>(_laserCanon1.getScoreAndHighScore()) == 30);
    CHECK(get<0>(_laserCanon2.getScoreAndHighScore()) == 10);
}
