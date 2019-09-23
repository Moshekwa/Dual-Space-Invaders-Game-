#include "DiagonalLaser.h"

DiagonalLaser::DiagonalLaser(LaserCanon& _laserCanon, int numberOfLives)
    : Ammunition{ get<0>(_laserCanon.entityPosition()), get<1>(_laserCanon.entityPosition()), 5, false, numberOfLives }
{
	auto [x_position, y_position] = entityPosition();
    if(x_position < 0 || x_position > 400 || y_position < 40 || y_position > 480) {
        throw InvalidCanonDiagonalLaserCoordinates{};
    }
}

DiagonalLaser::~DiagonalLaser()
{
}

void DiagonalLaser::moveLaserWithCanon(LaserCanon& _laserCanon)
{
    auto [x_position, y_position] = _laserCanon.entityPosition();
    setXposition(x_position + 6);
    setYposition(y_position);
}

void DiagonalLaser::move(Direction _direction)
{
    auto y_position = get<1>(entityPosition());
	auto x_position = get<0>(entityPosition());
    switch(_direction) {
    case UP:
	setYposition(y_position - getEntitySpeed());
	setXposition(x_position + getEntitySpeed());
	break;
    case DOWN:
	setYposition(y_position + getEntitySpeed());
	setXposition(x_position - getEntitySpeed());
    default:
	break;
    }
}