#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/EntityCoordinates.h"
#include "doctest.h"

//---------------------Testing Entity Coordinates-----------------------------------------------------------------------------------








/*
//------------------------------Test for the Alien class-----------------------------------------------------

TEST_CASE("Testing if the Alien class is able to create a valid object with initial positions")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move fuction")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
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

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
    _alien.move(Direction::RIGHT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at left boundary")
{
    auto xPosition = 0;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
    _alien.move(Direction::LEFT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at upper boundary")
{
    auto xPosition = 0;
    auto yPosition = 20;

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
    _alien.move(Direction::UP);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function at bottom boundary")
{
    auto xPosition = 380;
    auto yPosition = 380;

    auto _alien = Alien{ xPosition, yPosition, 380, 0 };
    _alien.move(Direction::DOWN);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

//-------------------------TEST FOR THE LASER CLASS---------------------------------
TEST_CASE("Testing Laser is able to initialize Laser coordinates")
{
    auto x_position = 190;
    auto y_position = 380;

    auto _laser = Laser{};
    _laser = EntityCoordinates{ x_position, y_position };

    CHECK(_laser.getEntityCoordinates().getXposition() == x_position);
    CHECK(_laser.getEntityCoordinates().getYposition() == y_position);
}

TEST_CASE("Testing laser upward movement functionality")
{
    auto _laser = Laser{};

    auto x_position = 380;
    auto y_position = 380;
    auto y_position2 = 375;

    _laser = EntityCoordinates{ x_position, y_position };
    _laser.move(Direction::UP);
    CHECK(_laser.getEntityCoordinates().getYposition() == y_position2);
}

TEST_CASE("Testing laser downward movement functionality")
{
    auto _laser = Laser{};
    auto x_position = 0;
    auto y_position = 0;
    auto y_position2 = 5;

    _laser = EntityCoordinates{ x_position, y_position };
    _laser.move(Direction::DOWN);
    CHECK(_laser.getEntityCoordinates().getYposition() == y_position2);
}

//-------------------TESTS FOR THROWING EXCEPTION FOR INVALID INITIAL COORDIANTES--------------------


TEST_CASE("Testing for Invalid Alien Coordinates")
{
    auto x_position = -4;
    auto y_position = 370;

    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0), InvalidAlienCoordinates);
}
*/