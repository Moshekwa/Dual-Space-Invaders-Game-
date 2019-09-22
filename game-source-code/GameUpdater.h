#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Alien.h"
#include "Laser.h"

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
    void updateCanon1_Score(LaserCanon& _laserCanon1, Alien& _alien);
    void updateCanon2_Score(LaserCanon& _laserCanon2, Alien& _alien);

private:
};

#endif // GAMEUPDATER_H_INCLUDED