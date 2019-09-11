#include "GameLoop.h"
#include <iostream>
using namespace std;

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{
          (get<0>(_windowDisplay->screenDimensions()) / 2) - 10, get<1>(_windowDisplay->screenDimensions()) - 20 } }
    , _laserCanon2{ new LaserCanon{ (get<0>(_windowDisplay->screenDimensions()) / 2) - 10, 0 } }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
    , gameWon{ false }
    , gameLost{ false }
{

    auto _alien = Alien{ 0, 0, 0, 0 };
    auto numberOfAliens = _alien.getNumberOfAliens();

    for(auto i = 0; i < numberOfAliens; i++) {
        auto _greenAlien = make_shared<Alien>(200 - 20 * i, 200, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _greenAliens.push_back(_greenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto _purpleAlien =
            make_shared<Alien>(200 - 20 * i, 200 + 20, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _purpleAliens.push_back(_purpleAlien);
    }
    for(auto i = 0; i < numberOfAliens; i++) {
        auto _redAlien =
            make_shared<Alien>(200 - 20 * i, 200 + 40, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _redAliens.push_back(_redAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto _upGreenAlien = make_shared<Alien>(200 - 20 * i, 180, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _upGreenAliens.push_back(_upGreenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto _upPurpleAlien =
            make_shared<Alien>(200 - 20 * i, 180 - 20, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _upPurpleAliens.push_back(_upPurpleAlien);
    }
    for(auto i = 0; i < numberOfAliens; i++) {
        auto _upRedAlien =
            make_shared<Alien>(200 - 20 * i, 180 - 40, 380 - 20 * i, ((20 * numberOfAliens) - 20) - 20 * i);
        _upRedAliens.push_back(_upRedAlien);
    }
}

void GameLoop::PlayGame()
{
    while(_windowDisplay->getWindow()->isOpen()) {
        if(!_windowDisplay->isPlay()) {
            auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };

            if(gameWon) {
                _entityDrawerProxy._drawGameWon();
            } else if(gameLost) {
                _entityDrawerProxy._drawGameLost();
            } else {
                _entityDrawerProxy._drawHomeScreen();
            }

            _windowDisplay->CheckEvent();
            _windowDisplay->getWindow()->display();
            _windowDisplay->getWindow()->clear();
        } else if(_windowDisplay->isPlay()) {
            timerCheck();
            drawGameEntities();
            _windowDisplay->getWindow()->display();
            _windowDisplay->getWindow()->clear();
        }
    }
}

void GameLoop::timerCheck()
{
    _keyHandler.KeyCheck(*_laserCanon1, *_laserCanon2, _windowDisplay->getPlayMode());
    if(_windowDisplay->getPlayMode() == 1) {
        _keyHandler.KeyCheck2(*_laserCanon2);
    }
    _windowDisplay->CheckEvent();
    GameUpdater _updater;
    _updater.updatePlayerLaser(*_laserCanon1, *_laserCanon2);
    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserCanonLaserCollision(*_laserCanon1, *_laserCanon2);

    if(!_laserCanon1->isAlive() || !_laserCanon2->isAlive()) {
        gameLost = true;
        auto play = false;
        _windowDisplay->setPlay(play);
    }

    auto counter = 0;
    auto _alien = Alien{ 0, 0, 0, 0 };
    auto numberOfAliens = _alien.getNumberOfAliens() * 6;

    for(auto greenAlien : _greenAliens) {
        _updater.updateAlienPosition(*greenAlien);
        if(greenAlien->isAlive() &&
            greenAlien->getEntityCoordinates().getYposition() >= get<3>(greenAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }

        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *greenAlien);
        if(!greenAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }

    for(auto purpleAlien : _purpleAliens) {
        _updater.updateAlienPosition(*purpleAlien);
        if(purpleAlien->isAlive() &&
            purpleAlien->getEntityCoordinates().getYposition() >= get<3>(purpleAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }

        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *purpleAlien);
        if(!purpleAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }

    for(auto redAlien : _redAliens) {
        _updater.updateAlienPosition(*redAlien);
        if(redAlien->isAlive() &&
            redAlien->getEntityCoordinates().getYposition() >= get<3>(redAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *redAlien);
        if(!redAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }

    for(auto UpGreenAlien : _upGreenAliens) {
        _updater.updateUpAlienPosition(*UpGreenAlien);
        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *UpGreenAlien);
        if(!UpGreenAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }

    for(auto UpPurpleAlien : _upPurpleAliens) {
        _updater.updateUpAlienPosition(*UpPurpleAlien);
        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *UpPurpleAlien);
        if(!UpPurpleAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }

    for(auto UpRedAlien : _upRedAliens) {
        _updater.updateUpAlienPosition(*UpRedAlien);
        _collisionDetector.LaserAlienCollision(*_laserCanon1, *_laserCanon2, *UpRedAlien);
        if(!UpRedAlien->isAlive()) {
            counter++;
            if(numberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }
}

void GameLoop::drawGameEntities()
{
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };
    _entityDrawerProxy._drawPlayer(*_laserCanon1, *_laserCanon2);

    for(auto GreenAliens : _greenAliens) {
        _entityDrawerProxy._drawGreenAliens(*GreenAliens);
    }

    for(auto PurpleAliens : _purpleAliens) {
        _entityDrawerProxy._drawPurpleAliens(*PurpleAliens);
    }
    for(auto RedAliens : _redAliens) {
        _entityDrawerProxy._drawRedAliens(*RedAliens);
    }
    for(auto UpGreenAliens : _upGreenAliens) {
        _entityDrawerProxy._drawUpGreenAliens(*UpGreenAliens);
    }
    for(auto UpPurpleAliens : _upPurpleAliens) {
        _entityDrawerProxy._drawUpPurpleAliens(*UpPurpleAliens);
    }
    for(auto UpRedAliens : _upRedAliens) {
        _entityDrawerProxy._drawUpRedAliens(*UpRedAliens);
    }
}
