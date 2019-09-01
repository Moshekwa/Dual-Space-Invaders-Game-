#include "GameLoop.h"

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{ 190, 380 } }
    , _laserCanon2{ new LaserCanon{ 190, 0 } }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
{
}

void GameLoop::PlayGame()
{
    HomeScreen();
    while(_windowDisplay->getWindow()->isOpen()) {
        timerCheck();
        drawGameEntities();
        _windowDisplay->getWindow()->display();
        _windowDisplay->getWindow()->clear();
    }
}

void GameLoop::timerCheck()
{
    _keyHandler.KeyCheck(*_laserCanon1);
    _keyHandler.KeyCheck2(*_laserCanon2);
    _windowDisplay->CheckEvent();
    GameUpdater _updater;
    _updater.updatePlayerLaser(*_laserCanon1, *_laserCanon2);
}

void GameLoop::drawGameEntities()
{
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };
    _entityDrawerProxy._drawPlayer(*_laserCanon1, *_laserCanon2);
}

void GameLoop::HomeScreen()
{
    _windowDisplay->drawHomeScreen();
}