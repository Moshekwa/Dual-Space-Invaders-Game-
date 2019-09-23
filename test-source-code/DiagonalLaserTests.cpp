#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/DiagonalLaser.h"
#include "doctest.h"

TEST_CASE("Checking if Diagonal Laser is initialized properly")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon(xPosition, yPosition, 1, 3);
    auto _diagonalLaser = DiagonalLaser(_laserCanon, 1);
    auto [x_position, y_position] = _diagonalLaser.entityPosition();
    CHECK(x_position == xPosition);
    CHECK(y_position == yPosition);
}

TEST_CASE("Checking if Diagonal Laser moves with the canon")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto entitySpeed = 6;
	auto xPosition2 = xPosition + entitySpeed ;
	
    auto _laserCanon = LaserCanon(xPosition, yPosition, 1, 3);
    auto _diagonalLaser = DiagonalLaser(_laserCanon, 1);
	
    auto [x_position, y_position] = _diagonalLaser.entityPosition();
    CHECK(x_position == xPosition);
    _diagonalLaser.moveDiagonalLaserWithCanon(_laserCanon);
	
	auto [x_position2, y_position2] = _diagonalLaser.entityPosition();
    CHECK(xPosition2 == x_position2);
}

TEST_CASE("Testing Diagonal Laser move functionality")
{
	auto xPosition = 190;
    auto yPosition = 480;
	auto entitySpeed = 5;
	auto xPosition2 = xPosition + entitySpeed;
    auto yPosition2 = yPosition - entitySpeed;
    
	
	auto _laserCanon = LaserCanon(xPosition, yPosition, 1, 3);
    auto _diagonalLaser = DiagonalLaser(_laserCanon, 1);
	
    
	
	_diagonalLaser.move(Direction::UP);
	auto [x_position, y_position] = _diagonalLaser.entityPosition();
	CHECK(x_position == xPosition2);
	CHECK(y_position == yPosition2);
}
