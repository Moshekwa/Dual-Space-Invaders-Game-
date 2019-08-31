#include "GameUpdater.h"
#include <iostream>

using namespace std;

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(Player& _player, Player& _player2)
{
    auto laser1 = 1;
    auto laser2 = 2;
    
    if(_player.getLaser(laser1).isAlive()) {
        _player.moveLaser();
    }
    _player.update_Laser_position(laser1);
    
    if(_player2.getLaser(laser2).isAlive()) {
        _player2.moveLaser();
    }
    _player2.update_Laser_position(laser2);
}
