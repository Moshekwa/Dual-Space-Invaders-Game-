#include "LaserCanon.h"

LaserCanon::LaserCanon(int x, int y, int canonNumber, int numberOfLives)
    : MovingEntity{ x, y, 5, true, numberOfLives }
    , _movement{ true }
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
    setMovementBoundaries(0, 380, 40, 480);
}

void LaserCanon::move(Direction _direction)
{
    auto [x_position, y_position] = entityPosition();

    switch(_direction) {
    case LEFT:
        setXposition(x_position - getEntitySpeed());
        break;
    case RIGHT:
        setXposition(x_position + getEntitySpeed());
        break;
    case UP:
        setYposition((y_position - getEntitySpeed()));
        break;
    case DOWN:
        setYposition((y_position + getEntitySpeed()));
        break;
    default:
        break;
    }
}

bool LaserCanon::isAbleToMove() const
{
    return _movement;
}

void LaserCanon::setAbilityToMove(bool movement)
{
    _movement = movement;
}