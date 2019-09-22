#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/Laser.h"
#include "../game-source-code/CollisionDetector.h"
#include "doctest.h"

TEST_CASE("Testing if the Alien class is able to create a valid object with initial positions")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move fuction")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    _alien.move(Direction::LEFT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition - _alien.getEntitySpeed());
    _alien.move(Direction::RIGHT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
    _alien.move(Direction::UP);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition - 2 * _alien.getEntitySpeed());
    _alien.move(Direction::DOWN);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function at right boundary")
{
    auto xPosition = 380;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    _alien.move(Direction::RIGHT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at left boundary")
{
    auto xPosition = 0;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    _alien.move(Direction::LEFT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at upper boundary")
{
    auto xPosition = 0;
    auto yPosition = 70;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    _alien.move(Direction::UP);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function at bottom boundary")
{
    auto xPosition = 380;
    auto yPosition = 450;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1 };
    _alien.move(Direction::DOWN);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
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
    
    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives };
    
    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();
    
    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserAlienCollision(_laser1, _laser2, _alien);
    
    CHECK(_alien.isAlive() == false);    
}
