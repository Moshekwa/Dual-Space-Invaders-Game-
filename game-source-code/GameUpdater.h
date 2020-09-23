/**
 * @file GameUpdater.h
 * @class GameUpdater
 * @brief Responsible for updating the positions of the game objects and the players' score as the game is being played.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Alien.h"
#include "Laser.h"
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
    void updateCanon_ScoreAndHighScore(ScoreBoard& _scoreBoard, Alien& _alien);
    void updateLaserCanon1Position(LaserCanon& _laserCanon1, Direction _direction);
    void updateLaserCanon2Position(LaserCanon& _laserCanon2, Direction _direction);
    ~GameUpdater(){};

private:
};

#endif // GAMEUPDATER_H_INCLUDED