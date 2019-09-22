#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/Alien.h"
#include "../game-source-code/EntityCoordinates.h"
#include "doctest.h"

//---------------------Testing Entity Coordinates-----------------------------------------------------------------------------------








/*
//------------------------------Test for the Alien class-----------------------------------------------------






//-------------------------TEST FOR THE LASER CLASS---------------------------------




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



*/