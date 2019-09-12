#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Alien.h"
#include "LaserCanon.h"

class GameUpdater
{
public:
    GameUpdater();
    void updatePlayerLaser(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);
    void updateAlienPosition(Alien& _alien);
    void updateUpAlienPosition(Alien& _alien);

private:
};

#endif // GAMEUPDATER_H_INCLUDED