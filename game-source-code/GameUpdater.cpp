#include "GameUpdater.h"
#include <iostream>

using namespace std;

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(Player& _player)
{
    if(_player.getLaser().isAlive()) {
	_player.moveLaser();
    }
    _player.update_Laser_position();
}

void GameUpdater::updatePlayerLaser2(Player& _player2)
{
    if(_player2.getLaser2().isAlive()) {
	_player2.moveLaser();
    }
    _player2.update_Laser2_position();
}