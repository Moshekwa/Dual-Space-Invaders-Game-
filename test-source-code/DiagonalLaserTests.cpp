#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/DiagonalLaser.h"
#include "doctest.h"

TEST_CASE("Checking for valid Diagonal Laser Coordinates")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser = DiagonalLaser{ _laserCanon, 1 };
	auto [ x_position, y_position ] = _laserCanon.entityPosition();
	
    CHECK( x_position == xPosition);
    CHECK( y_position == yPosition);
}