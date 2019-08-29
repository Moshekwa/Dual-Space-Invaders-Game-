#include "GameLoop.h"

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _player{ new Player{ 190, 380 } }
    , _player2{ new Player{ 190, 0 } }
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
    _keyHandler.KeyCheck(*_player);
    _keyHandler.KeyCheck2(*_player2);
    _windowDisplay->CheckEvent();
    GameUpdater _updater;
    _updater.updatePlayerLaser(*_player);
    _updater.updatePlayerLaser2(*_player2);
}

void GameLoop::drawGameEntities()
{
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };
    _entityDrawerProxy._drawPlayer(*_player);
    _entityDrawerProxy._drawPlayer2(*_player2);
}

void GameLoop::HomeScreen()
{
    _windowDisplay->drawHomeScreen();
}