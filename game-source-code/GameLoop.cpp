#include "GameLoop.h"

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
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2;
	auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
	auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
	auto _greenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
	_greenAliens.push_back(_greenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 + 20;
	auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
	auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
	auto _purpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
	_purpleAliens.push_back(_purpleAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 + 40;
	auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
	auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
	auto _redAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
	_redAliens.push_back(_redAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 20;
	auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
	auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
	auto _upGreenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
	_upGreenAliens.push_back(_upGreenAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 40;
	auto rightBoundary = get<0>(_windowDisplay->screenDimensions()) - 20 - 25 * i;
	auto leftBoundary = ((25 * numberOfAliens) - 25) - 25 * i;
	auto _upPurpleAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary);
	_upPurpleAliens.push_back(_upPurpleAlien);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(_windowDisplay->screenDimensions()) / 2 - 25 * i;
	auto yPosition = get<1>(_windowDisplay->screenDimensions()) / 2 - 60;
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
