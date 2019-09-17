#include "GameLoop.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{
          (get<0>(WindowDisplay::screenDimensions()) / 2) - 10, get<1>(WindowDisplay::screenDimensions()) - 20, 1 } }
    , _laserCanon2{ new LaserCanon{ (get<0>(WindowDisplay::screenDimensions()) / 2) - 10, 40, 2 } }
    , _laser1{ new Laser{ *_laserCanon1 } }
    , _laser2{ new Laser{ *_laserCanon2 } }
    , _imageDrawer{ new ImageDrawer{ _windowDisplay->getWindow() } }
    , _imageDrawerProxy{ _imageDrawer }
    , gameWon{ false }
    , gameLost{ false }
    , redAlienRowAlive{ true }
    , purpleAlienRowAlive{ true }
    , upRedAlienRowAlive{ true }
    , upPurpleAlienRowAlive{ true }
{

    auto numberOfAliens = Alien::getNumberOfAliens();

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) + 30);
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _greenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _greenAliens.push_back(_greenAlien);
        auto _alienLaser = make_shared<Laser>(*_greenAlien);
        _alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) + 30) + 30;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _purpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _purpleAliens.push_back(_purpleAlien);
        auto _alienLaser = make_shared<Laser>(*_purpleAlien);
        _alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) + 30) + 60;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _redAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _redAliens.push_back(_redAlien);
        auto _alienLaser = make_shared<Laser>(*_redAlien);
        _alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) - 10);
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _upGreenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upGreenAliens.push_back(_upGreenAlien);
        auto _alienLaser = make_shared<Laser>(*_upGreenAlien);
        _alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) - 10) - 30;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _upPurpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upPurpleAliens.push_back(_upPurpleAlien);
        auto _alienLaser = make_shared<Laser>(*_upPurpleAlien);
        _alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
        auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 30 * i;
        auto yPosition = ((get<1>(_windowDisplay->screenDimensions()) / 2) - 10) - 60;
        auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 30 * i;
        auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
        auto _upRedAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
        _upRedAliens.push_back(_upRedAlien);
        auto _alienLaser = make_shared<Laser>(*_upRedAlien);
        _alienLasers.push_back(_alienLaser);
    }
}

void GameLoop::PlayGame()
{
    while(_windowDisplay->getWindow()->isOpen()) {
        if(!_windowDisplay->isPlay()) {

            if(gameWon) {
                _imageDrawerProxy._drawGameWon();
            } else if(gameLost) {
                _imageDrawerProxy._drawGameLost();
            } else {
                _imageDrawerProxy._drawHomeScreen();
            }

            _windowDisplay->CheckEvent();
            _windowDisplay->getWindow()->display();
            _windowDisplay->getWindow()->clear();
        } else if(_windowDisplay->isPlay()) {
            gameActivities();
            drawGameEntities();
            _windowDisplay->getWindow()->display();
            _windowDisplay->getWindow()->clear();
        }
    }
}

void GameLoop::gameActivities()
{
    if(_windowDisplay->is_singleMode()) {
        _keyHandler.singleModeKeyCheck(*_laserCanon1, *_laserCanon2, *_laser1, *_laser2);
    } else {
        _keyHandler.KeyCheck(*_laserCanon1, *_laser1);
        _keyHandler.KeyCheck2(*_laserCanon2, *_laser2);
    }
    _windowDisplay->CheckEvent();

    auto _updater = GameUpdater{};
    _updater.updateLaser1Position(*_laserCanon1, *_laser1);
    _updater.updateLaser2Position(*_laserCanon2, *_laser2);

    auto _collisionDetector = CollisionDetector{};
    _collisionDetector.LaserCanonLaserCollision(*_laserCanon1, *_laserCanon2, *_laser1, *_laser2);

    if(!_laserCanon1->isAlive() || !_laserCanon2->isAlive()) {
        gameLost = true;
        auto play = false;
        _windowDisplay->setPlay(play);
    }

    auto counter = 0;
    auto totalNumberOfAliens = Alien::getNumberOfAliens() * 6;

    auto randomXposition = (rand() % ((get<0>(WindowDisplay::screenDimensions())) - 20)) + 1;
    auto AlienCounter = 0;

    for(auto greenAlien : _greenAliens) {
        _updater.updateAlienPosition(*greenAlien);

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            purpleAlienRowAlive == false && greenAlien->isAlive()) {
            _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateAlienLaserPosition(*greenAlien, *_alienLasers.at(AlienCounter));

        if(greenAlien->isAlive() &&
            greenAlien->getEntityCoordinates().getYposition() >= get<3>(greenAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }

        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *greenAlien);
        if(!greenAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
        AlienCounter++;
    }

    for(auto purpleAlien : _purpleAliens) {
        _updater.updateAlienPosition(*purpleAlien);

        auto isAlive = [](auto n) { return n->isAlive(); };
        auto AlienRowAlive = any_of(_purpleAliens.begin(), _purpleAliens.end(), isAlive);
        purpleAlienRowAlive = AlienRowAlive;

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            redAlienRowAlive == false && purpleAlien->isAlive()) {
            _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateAlienLaserPosition(*purpleAlien, *_alienLasers.at(AlienCounter));

        if(purpleAlien->isAlive() &&
            purpleAlien->getEntityCoordinates().getYposition() >= get<3>(purpleAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }

        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *purpleAlien);
        if(!purpleAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
        AlienCounter++;
    }

    for(auto redAlien : _redAliens) {
        _updater.updateAlienPosition(*redAlien);

        auto isAlive = [](auto n) { return n->isAlive(); };
        auto AlienRowAlive = any_of(_redAliens.begin(), _redAliens.end(), isAlive);
        redAlienRowAlive = AlienRowAlive;

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            redAlien->isAlive()) {
            _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateAlienLaserPosition(*redAlien, *_alienLasers.at(AlienCounter));

        if(redAlien->isAlive() &&
            redAlien->getEntityCoordinates().getYposition() >= get<3>(redAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *redAlien);
        if(!redAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
        AlienCounter++;
    }

    for(auto UpGreenAlien : _upGreenAliens) {
        _updater.updateUpAlienPosition(*UpGreenAlien);

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            UpGreenAlien->isAlive() && upPurpleAlienRowAlive == false) {
             _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateAlienLaserPosition(*UpGreenAlien, *_alienLasers.at(AlienCounter));

        if(UpGreenAlien->isAlive() &&
            UpGreenAlien->getEntityCoordinates().getYposition() <= get<2>(UpGreenAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpGreenAlien);
        if(!UpGreenAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
        AlienCounter++;
    }

    for(auto UpPurpleAlien : _upPurpleAliens) {
        _updater.updateUpAlienPosition(*UpPurpleAlien);

        auto isAlive = [](auto n) { return n->isAlive(); };
        auto AlienRowAlive = any_of(_upPurpleAliens.begin(), _upPurpleAliens.end(), isAlive);
        upPurpleAlienRowAlive = AlienRowAlive;

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            UpPurpleAlien->isAlive() && upRedAlienRowAlive == false) {
            _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateAlienLaserPosition(*UpPurpleAlien, *_alienLasers.at(AlienCounter));

        if(UpPurpleAlien->isAlive() &&
            UpPurpleAlien->getEntityCoordinates().getYposition() <= get<2>(UpPurpleAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpPurpleAlien);
        if(!UpPurpleAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
        AlienCounter++;
    }

    for(auto UpRedAlien : _upRedAliens) {
        _updater.updateUpAlienPosition(*UpRedAlien);

        auto isAlive = [](auto n) { return n->isAlive(); };
        auto AlienRowAlive = any_of(_upRedAliens.begin(), _upRedAliens.end(), isAlive);
        upRedAlienRowAlive = AlienRowAlive;

        if(_alienLasers.at(AlienCounter)->getEntityCoordinates().getXposition() == randomXposition &&
            UpRedAlien->isAlive()) {
            _alienLasers.at(AlienCounter)->shootLaser();
        }
        _updater.updateUpAlienLaserPosition(*UpRedAlien, *_alienLasers.at(AlienCounter));

        if(UpRedAlien->isAlive() &&
            UpRedAlien->getEntityCoordinates().getYposition() <= get<2>(UpRedAlien->getBoundaries())) {
            gameLost = true;
            auto play = false;
            _windowDisplay->setPlay(play);
        }
        _collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpRedAlien);
        if(!UpRedAlien->isAlive()) {
            counter++;
            if(totalNumberOfAliens == counter) {
                auto play = false;
                _windowDisplay->setPlay(play);
                gameWon = true;
            }
        }
    }
    AlienCounter++;
}

void GameLoop::drawGameEntities()
{
    _imageDrawerProxy._drawLaserCanons(*_laserCanon1, *_laserCanon2);
    _imageDrawerProxy._drawLasers(*_laser1, *_laser2);
    for(auto _alienLaser : _alienLasers) {
        _imageDrawerProxy._drawAlienLasers(*_alienLaser);
    }

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

            _imageDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(0));

        } else if((GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(1));

        } else if((GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (GreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                GreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawGreenAliens(*GreenAlien, spriteNumber.at(2));
        }
    }

    for(auto UpGreenAlien : _upGreenAliens) {

        if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _imageDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(0));

        } else if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(1));

        } else if((UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpGreenAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpGreenAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(2));
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

            _imageDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(0));

        } else if((PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(1));

        } else if((PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (PurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                PurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawPurpleAliens(*PurpleAlien, spriteNumber.at(2));
        }
    }

    for(auto UpPurpleAlien : _upPurpleAliens) {

        if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _imageDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(0));

        } else if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(1));

        } else if((UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpPurpleAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpPurpleAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(2));
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

            _imageDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(0));

        } else if((RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(1));

        } else if((RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (RedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                RedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawRedAliens(*RedAlien, spriteNumber.at(2));
        }
    }

    for(auto UpRedAlien : _upRedAliens) {

        if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(0) &&
               UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(1)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(3) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(4)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(6) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(7))) {

            _imageDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(0));

        } else if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(1) &&
                      UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(2)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(4) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(5)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(7) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(8))) {

            _imageDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(1));

        } else if((UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(2) &&
                      UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(3)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(5) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(6)) ||
            (UpRedAlien->getEntityCoordinates().getXposition() >= spriteBoundaries.at(8) &&
                UpRedAlien->getEntityCoordinates().getXposition() < spriteBoundaries.at(9))) {

            _imageDrawerProxy._drawUpRedAliens(*UpRedAlien, spriteNumber.at(2));
        }
    }
}