#include "LaserCanon.h"

LaserCanon::LaserCanon(int x, int y, int canonNumber, int numberOfLives)
    : MovingEntity{ x, y, 5, true, numberOfLives }
    , ableToMove{ true }

{
    switch(canonNumber) {
    case 1:
        if(x != 190 || y != 480) {
            throw InvalidLaserCanonPosition{};
        }
        break;
    case 2:
        if(x != 190 || y != 40) {

            throw InvalidLaserCanonPosition{};
        }
        break;
    default:
        break;
    }
    setMovementBoundaries(0, 380, 40, 480);
    if(get<1>(entityPosition()) == get<2>(getMovementBoundaries())) {
        _directionFaced = Direction::DOWN;
    }
    if(get<1>(entityPosition()) == get<3>(getMovementBoundaries())) {
        _directionFaced = Direction::UP;
    }
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

void LaserCanon::setFacedDirection(Direction directionFaced)
{
    _directionFaced = directionFaced;
}

Direction LaserCanon::getFacedDirection() const
{
    return _directionFaced;
}

void LaserCanon::setAbilityToMove(bool movementAbility)
{
    ableToMove = movementAbility;
}

bool LaserCanon::isAbleToMove() const
{
    return ableToMove;
}