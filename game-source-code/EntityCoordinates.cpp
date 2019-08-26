#include "EntityCoordinates.h"

EntityCoordinates::EntityCoordinates(int x, int y)
{
    xPosition = x;
    yPosition = y;
}

void EntityCoordinates::setXposition(int x)
{
    xPosition = x;
}

void EntityCoordinates::setYposition(int y)
{
    yPosition = y;
}

int EntityCoordinates::getXposition() const
{
    return xPosition;
}

int EntityCoordinates::getYposition() const
{
    return yPosition;
}