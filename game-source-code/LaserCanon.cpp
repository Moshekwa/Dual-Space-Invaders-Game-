#include "LaserCanon.h"

LaserCanon::LaserCanon(int x, int y, int canonNumber, int numberOfLives)
    : MovingEntity{ x, y, 5, true, numberOfLives }
    , lifeLost{ false }
    , _score{0}
    , _highScore{0} //this will change
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
    auto x_position = get<0>(entityPosition());
    switch(_direction) {
    case LEFT:
	if(x_position > leftBoundary) {
	    setXposition(x_position - getEntitySpeed());
	}
	break;
    case RIGHT:
	if(x_position < rightBoundary) {
	    setXposition(x_position + getEntitySpeed());
	}
	break;
    default:
	break;
    }
}

void LaserCanon::setScore(int score)
{
    _score = score;
    if(_score > _highScore){
        setHighScore(_score);
    }
}

void LaserCanon::setHighScore(int highScore)
{
    _highScore = highScore;
}

tuple<int, int> LaserCanon::getScoreAndHighScore() const
{
    return {_score, _highScore};
}




