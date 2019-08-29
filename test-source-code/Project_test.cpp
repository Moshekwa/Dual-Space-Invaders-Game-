#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/EntityCoordinates.h"
#include "doctest.h"

// Testing Entity Coordinates!
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