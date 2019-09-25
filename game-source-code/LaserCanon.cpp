#include "LaserCanon.h"

LaserCanon::LaserCanon(int x, int y, int canonNumber, int numberOfLives)
    : MovingEntity{ x, y, 5, true, numberOfLives }
{
    switch(canonNumber) {
    case 1:
        if(x < 0 || x > 380 || y != 480) {
            throw InvalidLaserCanonCoordinates{};
        }
        break;
    case 2:
        if(x < 0 || x > 380 || y != 40) {

            throw InvalidLaserCanonCoordinates{};
        }
        break;
    default:
        break;
    }
}

void LaserCanon::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;
    auto upperBoundary = 40;
    auto bottomBoundary = 480;
    auto [x_position, y_position] = entityPosition();

    switch(_direction) {
    case LEFT:
        if(x_position > leftBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            setXposition(x_position - getEntitySpeed());
        }
        break;
    case RIGHT:
        if(x_position < rightBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            setXposition(x_position + getEntitySpeed());
        }
        break;
    case UP:
        if(y_position > upperBoundary) {
            setYposition((y_position - getEntitySpeed()));
        }
        break;
    case DOWN:
        if(y_position < bottomBoundary) {
            setYposition((y_position + getEntitySpeed()));
        }
        break;
    default:
        break;
    }
}
