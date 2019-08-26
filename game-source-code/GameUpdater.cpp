#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(Player& _player)
{
    if(!_player.getLaser().isAlive()) {
        _player.moveLaser();
    }
}