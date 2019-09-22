#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/EntityCoordinates.h"
#include "doctest.h"

//---------------------Testing Entity Coordinates-----------------------------------------------------------------------------------








/*
//------------------------------Test for the Alien class-----------------------------------------------------






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