#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/EntityCoordinates.h"
#include "../game-source-code/LaserCanon.h"
#include "doctest.h"

//---------------------Testing Entity Coordinates-----------------------------------------

TEST_CASE("If EntityCoordinates class is able to create valid object initial positions.")
{
    auto x_position = 0;
    auto y_position = 0;

    auto entity_coordinates = EntityCoordinates{ x_position, y_position };
    CHECK(entity_coordinates.getXposition() == x_position);
    CHECK(entity_coordinates.getYposition() == y_position);
}

TEST_CASE("Test set positions functions of the EntityCoordinates class.")
{
    auto x_position = 380;
    auto y_position = 400;

    auto entity_coordinates = EntityCoordinates{ 0, 0 };
    entity_coordinates.setYposition(y_position);
    entity_coordinates.setXposition(x_position);

    CHECK(entity_coordinates.getYposition() == y_position);
    CHECK(entity_coordinates.getYposition() == y_position);
}

//---------------------------Tests for Lason Cannon class ------------------------------
TEST_CASE("Testing if player is able to create 2 Laser Canon objects at different initial positions")
{
    auto xPosition1 = 190;
    auto yPosition1 = 380;
    auto xPosition2 = 190;
    auto yPosition2 = 0;

    auto _laserCanon1 = LaserCanon{ xPosition1, yPosition1 };
    auto _laserCanon2 = LaserCanon{ xPosition2, yPosition2 };

    CHECK(_laserCanon1.getEntityCoordinates().getXposition() == xPosition1);
    CHECK(_laserCanon2.getEntityCoordinates().getXposition() == xPosition2);
    CHECK(_laserCanon1.getEntityCoordinates().getYposition() == yPosition1);
    CHECK(_laserCanon2.getEntityCoordinates().getYposition() == yPosition2);
}

TEST_CASE("Testing the setPosition functions for Laser Canon")
{
    auto xPosition = 190;
    auto yPosition = 380;

    auto _laserCanon = LaserCanon{ 0, 0 };

    _laserCanon.setXposition(xPosition);
    _laserCanon.setYposition(yPosition);

    CHECK(_laserCanon.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_laserCanon.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function for Lasor Canon")
{
    auto xPosition = 190;
    auto yPosition = 380;

    auto _laserCanon = LaserCanon{ xPosition, yPosition };

    _laserCanon.move(Direction::LEFT);
    CHECK(_laserCanon.getEntityCoordinates().getXposition() == xPosition - _laserCanon.getEntitySpeed());
    _laserCanon.move(Direction::RIGHT);
    CHECK(_laserCanon.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing if the Laser Canon obeys the left boundary restrictions")
{
    auto xPosition = 4;
    auto yPosition = 380;

    auto _laserCanon = LaserCanon{ xPosition, yPosition };
    _laserCanon.move(Direction::LEFT);
    CHECK_FALSE(_laserCanon.getEntityCoordinates().getXposition() == xPosition - _laserCanon.getEntitySpeed());
}

TEST_CASE("Testing if the Laser Canon obeys the right boundary restrictions")
{
    auto xPosition = 375;
    auto yPosition = 380;

    auto _laserCanon = LaserCanon{ xPosition, yPosition };
    _laserCanon.move(Direction::RIGHT);
    CHECK_FALSE(_laserCanon.getEntityCoordinates().getXposition() == xPosition + _laserCanon.getEntitySpeed());
}

//------------------------------Test for the Alien class-----------------------------------------------------

TEST_CASE("Testing if the Alien class is able to create a valid object with initial positions")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition };
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move fuction")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition };
    _alien.move(Direction::LEFT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition - _alien.getEntitySpeed());
    _alien.move(Direction::RIGHT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
    _alien.move(Direction::UP);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition - _alien.getEntitySpeed());
    _alien.move(Direction::DOWN);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function at right boundary")
{
    auto xPosition = 380;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition };
    _alien.move(Direction::RIGHT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at left boundary")
{
    auto xPosition = 0;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition };
    _alien.move(Direction::LEFT);
    CHECK(_alien.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing the move function at upper boundary")
{
    auto xPosition = 0;
    auto yPosition = 20;

    auto _alien = Alien{ xPosition, yPosition };
    _alien.move(Direction::UP);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function at bottom boundary")
{
    auto xPosition = 380;
    auto yPosition = 380;

    auto _alien = Alien{ xPosition, yPosition };
    _alien.move(Direction::DOWN);
    CHECK(_alien.getEntityCoordinates().getYposition() == yPosition);
}

//-------------------------TEST FOR THE LASER CLASS---------------------------------
TEST_CASE("Testing Laser is able to initialize Laser coordinates")
{
	auto x_position = 190;
    auto y_position = 380;
    //auto xPosition2 = 190;
    //auto yPosition2 = 0;
	
	auto _laser = Laser{};
	_laser = EntityCoordinates{x_position ,y_position};
	
	CHECK(_laser.getEntityCoordinates().getXposition() == x_position);
	CHECK(_laser.getEntityCoordinates().getYposition() == y_position);
}


TEST_CASE("Testing laser upward movement functionality")
{
	auto _laser = Laser{};
	
	auto x_position = 380;
	auto y_position = 380;
	//auto xPosition2 = 190;
    auto y_position2 = 375;
	
	
	_laser = EntityCoordinates{x_position ,y_position};
	_laser.move(Direction::UP);
	CHECK(_laser.getEntityCoordinates().getYposition() == y_position2);
} 

TEST_CASE("Testing laser downward movement functionality")
{
	auto _laser = Laser{};
	
	auto x_position = 0;
	auto y_position = 0;
	auto y_position2 = 5;
    
	_laser = EntityCoordinates{x_position ,y_position};
	_laser.move(Direction::DOWN);
	CHECK(_laser.getEntityCoordinates().getYposition() == y_position2);
}


