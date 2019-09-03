#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
{
    auto laser1 = 1;
    auto laser2 = 2;

    if(_laserCanon1.getLaser(laser1).isAlive()) {
        if(_laserCanon1.getLaser(laser1).getEntityCoordinates().getYposition() == 0){
            _laserCanon1.destroyLaser(laser1);
        }
        _laserCanon1.moveLaser();
    }
    _laserCanon1.update_Laser_position(laser1);

    if(_laserCanon2.getLaser(laser2).isAlive()) {
        if(_laserCanon2.getLaser(laser2).getEntityCoordinates().getYposition() == 395){
            _laserCanon2.destroyLaser(laser2);
        }
        _laserCanon2.moveLaser();
    }
    _laserCanon2.update_Laser_position(laser2);
}
