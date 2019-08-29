#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/EntityCoordinates.h"
#include "../game-source-code/Player.h"
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

//---------------------------Tests for Player class ------------------------------
TEST_CASE("Testing if player is able to create 2 player objects at different initial positions")
{
    auto xPosition1 = 190;
    auto yPosition1 = 380;
    auto xPosition2 = 190;
    auto yPosition2 = 0;

    auto _player1 = Player{ xPosition1, yPosition1 };
    auto _player2 = Player{ xPosition2, yPosition2 };

    CHECK(_player1.getEntityCoordinates().getXposition() == xPosition1);
    CHECK(_player2.getEntityCoordinates().getXposition() == xPosition2);
    CHECK(_player1.getEntityCoordinates().getYposition() == yPosition1);
    CHECK(_player2.getEntityCoordinates().getYposition() == yPosition2);
}

TEST_CASE("Testing the setPosition functions for player")
{
    auto xPosition = 190;
    auto yPosition = 380;

    auto _player = Player{ 0, 0 };

    _player.setXposition(xPosition);
    _player.setYposition(yPosition);

    CHECK(_player.getEntityCoordinates().getXposition() == xPosition);
    CHECK(_player.getEntityCoordinates().getYposition() == yPosition);
}

TEST_CASE("Testing the move function for player")
{
    auto xPosition = 190;
    auto yPosition = 380;

    auto _player = Player{ xPosition, yPosition };

    _player.move(Direction::LEFT);
    CHECK(_player.getEntityCoordinates().getXposition() == xPosition - _player.getEntitySpeed());
    _player.move(Direction::RIGHT);
    CHECK(_player.getEntityCoordinates().getXposition() == xPosition);
}

TEST_CASE("Testing if the player obeys the left boundary restrictions")
{
    auto xPosition = 4;
    auto yPosition = 380;

    auto _player = Player{ xPosition, yPosition };
    _player.move(Direction::LEFT);
    CHECK_FALSE(_player.getEntityCoordinates().getXposition() == xPosition - _player.getEntitySpeed());
}

TEST_CASE("Testing if the player obeys the right boundary restrictions")
{
    auto xPosition = 375;
    auto yPosition = 380;

    auto _player = Player{ xPosition, yPosition };
    _player.move(Direction::RIGHT);
    CHECK_FALSE(_player.getEntityCoordinates().getXposition() == xPosition + _player.getEntitySpeed());
}