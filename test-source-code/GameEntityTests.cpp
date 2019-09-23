#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/GameEntity.h"
#include "../game-source-code/LaserCanon.h"
#include "doctest.h"

TEST_CASE("Testing for Invalid Coordinates of the Game Entity class")
{
    auto xPosition = -4;
    auto yPosition = 400;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 360;
    yPosition = 620;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 620;
    yPosition = 500;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 20;
    yPosition = -500;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);
}

TEST_CASE("Testing if Game Entity does not create a dead object")
{
	auto xPosition = 190;
	auto yPosition = 480;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 0), InvalidEntityPositions);
}

TEST_CASE("Checking if set functions of Game Entity throw exceptions for Invalid coordinates")
{
	auto xPosition = 190;
	auto yPosition = 480;
	auto _gameEntity = GameEntity(xPosition, yPosition, false, 3);
	
	auto x_position = 450;
	auto y_position = -5;
	CHECK_THROWS( _gameEntity.setXposition(x_position));
	CHECK_THROWS(_gameEntity.setYposition(y_position));
	
	x_position = -6;
	y_position = 550;
	CHECK_THROWS( _gameEntity.setXposition(x_position));
	CHECK_THROWS(_gameEntity.setYposition(y_position));
}