#include "GameLoop.h"

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{
          (get<0>(_windowDisplay->screenDimensions()) / 2) - 10, get<1>(_windowDisplay->screenDimensions()) - 20 } }
    , _laserCanon2{ new LaserCanon{ (get<0>(_windowDisplay->screenDimensions()) / 2) - 10, 0 } }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
    , _entityDrawerProxy{ _entityDrawer }
    , gameWon{ false }
    , gameLost{ false }
{

    auto _alien = Alien{ 0, 0, 0, 0 };
    auto numberOfAliens = _alien.getNumberOfAliens();
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _greenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _greenAliens.push_back(_greenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 + 25;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _purpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _purpleAliens.push_back(_purpleAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 + 50;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _redAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _redAliens.push_back(_redAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 25;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _upGreenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upGreenAliens.push_back(_upGreenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 50;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _upPurpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upPurpleAliens.push_back(_upPurpleAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
        auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 75;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
        auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
        auto _upRedAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upRedAliens.push_back(_upRedAlien);
    }
}

void GameLoop::PlayGame()
{
    while(_windowDisplay->getWindow()->isOpen()) {
        if(!_windowDisplay->isPlay()) {

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
    if(_windowDisplay->is_singleMode()) {
        _keyHandler.singleModeKeyCheck(*_laserCanon1, *_laserCanon2);
    } else {
        _keyHandler.KeyCheck(*_laserCanon1);
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
        if(UpGreenAlien->isAlive() &&
            UpGreenAlien->getEntityCoordinates().getYposition() <= get<2>(UpGreenAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
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
        if(UpPurpleAlien->isAlive() &&
            UpPurpleAlien->getEntityCoordinates().getYposition() <= get<2>(UpPurpleAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
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
        if(UpRedAlien->isAlive() &&
            UpRedAlien->getEntityCoordinates().getYposition() <= get<2>(UpRedAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
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
    _entityDrawerProxy._drawLaserCanonsAndLasers(*_laserCanon1, *_laserCanon2);

    auto spriteNumber = vector<int>{ 1, 2, 3 };
    auto spriteBoundaries = vector<int>{ 0, 40, 80, 120, 160, 200, 240, 280, 320, 380 };
    drawGreenAlians(spriteNumber, spriteBoundaries);
    drawPurpleAliens(spriteNumber, spriteBoundaries);
    drawRedAliens(spriteNumber, spriteBoundaries);
}

void GameLoop::drawGreenAlians(vector<int> spriteNumber, vector<int> spriteBoundaries)
{
    for(auto GreenAlien : _greenAliens) {
        if((GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(0));

        } else if((GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(1));

        } else if((GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(2));
        }
    }

    for(auto UpGreenAlien : _upGreenAliens) {

        if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(0));

        } else if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(1));

        } else if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(2));
        }
    }
}

void GameLoop::drawPurpleAliens(vector<int> spriteNumber, vector<int> spriteBoundaries)
{
    for(auto PurpleAlien : _purpleAliens) {

        if((PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(0));

        } else if((PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(1));

        } else if((PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(2));
        }
    }

    for(auto UpPurpleAlien : _upPurpleAliens) {

        if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(0));

        } else if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(1));

        } else if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(2));
        }
    }
}

void GameLoop::drawRedAliens(vector<int> spriteNumber, vector<int> spriteBoundaries)
{
    for(auto RedAlien : _redAliens) {

        if((RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(0));

        } else if((RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(1));

        } else if((RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(2));
        }
    }

    for(auto UpRedAlien : _upRedAliens) {

        if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _entityDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(0));

        } else if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _entityDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(1));

        } else if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _entityDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(2));
        }
    }
}