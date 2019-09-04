#include "GameLoop.h"

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{ 190, 380 } }
    , _laserCanon2{ new LaserCanon{ 190, 0 } }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
{
    auto numberOfAliens = 20;
    for(auto i = 0; i < numberOfAliens; i++) {
        auto _alien = make_shared<Alien>(200 + 20 * i, 200 );
        _aliens.push_back(_alien);
    }
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
    for(auto aliens : _aliens) {
        _updater.updateAlienPosition(*aliens);
    }
}

void GameLoop::drawGameEntities()
{
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };
    _entityDrawerProxy._drawPlayer(*_laserCanon1, *_laserCanon2);
    for(auto aliens : _aliens) {
        _entityDrawerProxy._drawAliens(*aliens);
    }
}

void GameLoop::HomeScreen()
{
    _windowDisplay->drawHomeScreen();
}