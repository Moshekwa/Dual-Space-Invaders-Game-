#include "GameLoop.h"


GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _player{ new Player }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
{
}

void GameLoop::PlayGame()
{
    while(_windowDisplay->getWindow()->isOpen()){
        timerCheck();
        drawGameEntities();
        _windowDisplay->getWindow()->display();
        _windowDisplay->getWindow()->clear();
    }
}

void GameLoop::timerCheck()
{
    _keyHandler.KeyCheck(*_player);
    _windowDisplay->CheckEvent();
    GameUpdater _updater;
    _updater.updatePlayerLaser(*_player);
}

void GameLoop::drawGameEntities()
{
   // EntityDrawerProxy _entityDrawerProxy{_entityDrawer};
    auto _entityDrawerProxy = EntityDrawerProxy{_entityDrawer};
    _entityDrawerProxy._drawPlayer(*_player);
}