#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Alien.h"
#include "LaserCanon.h"
#include "Laser.h"

class GameUpdater
{
public:
    GameUpdater();
    void updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1);
    void updateLaser2Position(LaserCanon& _laserCanon2, Laser& _laser2);
    void updateAlienPosition(Alien& _alien);
    void updateUpAlienPosition(Alien& _alien);

private:
};

#endif // GAMEUPDATER_H_INCLUDED