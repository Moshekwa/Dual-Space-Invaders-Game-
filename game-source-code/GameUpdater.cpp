#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
{
    auto laser1 = 1;
    auto laser2 = 2;

    if(_laserCanon1.getLaser(laser1).isAlive()) {
        _laserCanon1.moveLaser();
    }
    _laserCanon1.update_Laser_position(laser1);

    if(_laserCanon2.getLaser(laser2).isAlive()) {
        _laserCanon2.moveLaser();
    }
    _laserCanon2.update_Laser_position(laser2);
}
