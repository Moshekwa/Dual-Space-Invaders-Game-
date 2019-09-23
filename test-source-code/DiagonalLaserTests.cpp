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
    auto entitySpeed = 5;

    auto _laserCanon = LaserCanon(xPosition, yPosition, 1, 3);
    auto _diagonalLaser = DiagonalLaser(_laserCanon, 1);
    auto [x_position, y_position] = _diagonalLaser.entityPosition();
    CHECK(x_position == xPosition);
    _laserCanon.move(RIGHT);

    xPosition += entitySpeed;
    auto [x_position2, y_position2] = _laserCanon.entityPosition();
    CHECK(xPosition == x_position2);
}
