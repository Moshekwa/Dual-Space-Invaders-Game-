#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>

class InvalidLaserCanonCoordinates
{
};

class LaserCanon : public MovingEntity
{
public:
    LaserCanon(int x, int y, int canonNumber, int numberOfLives);
    virtual void move(Direction _direction);
    void setScore(int score);
    tuple<int, int> getScoreAndHighScore() const;

private:
    bool lifeLost;
    int _score;
    int _highScore;
    void setHighScore(int highScore);
};

#endif // LASERCANON_H_INCLUDED