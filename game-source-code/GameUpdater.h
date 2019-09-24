#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Alien.h"
#include "Laser.h"
#include "DiagonalLaser.h"
#include "ScoreBoard.h"

class GameUpdater
{
public:
    GameUpdater();
    void updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1);
    void updateLaser2Position(LaserCanon& _laserCanon2, Laser& _laser2);
    void updateAlienPosition(Alien& _alien);
    void updateUpAlienPosition(Alien& _alien);
    void updateAlienLaserPosition(Alien& _alien, Laser& _alienLaser);
    void updateUpAlienLaserPosition(Alien& _alien, Laser& _alienLaser);
    void updateCanon1_ScoreAndHighScore(ScoreBoard& _scoreBoard1, Alien& _alien);
    void updateCanon2_ScoreAndHighScore(ScoreBoard& _scoreBoard2, Alien& _alien);

	//void updateDiagonalLaserPosition(LaserCanon& _LaserCanon& _laserCanon1, DiagonalLaser& _diagonalLaser); 
private:
};

#endif // GAMEUPDATER_H_INCLUDED