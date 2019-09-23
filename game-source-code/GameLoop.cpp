#include "GameLoop.h"
#include <algorithm>
#include <cstdlib>

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _imageDrawer{ new ImageDrawer{ _windowDisplay->getWindow() } }
    , gameWon{ false }
    , gameLost{ false }
    , redAlienRowAlive{ true }
    , purpleAlienRowAlive{ true }
    , upRedAlienRowAlive{ true }
    , upPurpleAlienRowAlive{ true }
{
    createLaserCanonsAndLasers();
    createLaserCanonShields();
    createLaserCanonLives();
    createAliens();
}

void GameLoop::PlayGame()
{
    while(_windowDisplay->getWindow()->isOpen()) {
	if(!_windowDisplay->isPlay()) {

	    if(gameWon) {

		_imageDrawer->drawGameWon();
	    } else if(gameLost) {
		_imageDrawer->drawGameLost();
	    } else {
		_imageDrawer->drawHomeScreen();
	    }

	    _windowDisplay->CheckEvent();
	    _windowDisplay->getWindow()->display();
	    _windowDisplay->getWindow()->clear();
	} else if(_windowDisplay->isPlay()) {
	    _imageDrawer->drawScore(*_laserCanon1);
	    _imageDrawer->drawScore2(*_laserCanon2);
		_imageDrawer->drawHighScore(*_laserCanon1);
	    gameActivities();
	    displayGameEntities();
	    _windowDisplay->getWindow()->display();
	    _windowDisplay->getWindow()->clear();
	}
    }
}

void GameLoop::createLaserCanonsAndLasers()
{
    _laserCanon1 = make_shared<LaserCanon>(
        (get<0>(WindowDisplay::screenDimensions()) / 2) - 10, get<1>(WindowDisplay::screenDimensions()) - 20, 1, 3);
    _laserCanon2 = make_shared<LaserCanon>((get<0>(WindowDisplay::screenDimensions()) / 2) - 10, 40, 2, 3);
    _laser1 = make_shared<Laser>(*_laserCanon1, 1);
    _laser2 = make_shared<Laser>(*_laserCanon2, 1);
}

void GameLoop::laserCanonsInitialPositions()
{
    auto xPosition_1 = (get<0>(WindowDisplay::screenDimensions()) / 2) - 10;
    auto yPosition_1 = get<1>(WindowDisplay::screenDimensions()) - 20;
    auto xPosition_2 = get<0>(WindowDisplay::screenDimensions()) / 2;
    auto yPosition_2 = 40;

    _laserCanon1->setXposition(xPosition_1);
    _laserCanon1->setYposition(yPosition_1);
    _laserCanon2->setXposition(xPosition_2);
    _laserCanon2->setYposition(yPosition_2);
}

void GameLoop::createLaserCanonShields()
{
    auto numberOfShields = LaserCanonShield::getNumberOfShields();

    for(auto i = 0; i < (numberOfShields / 2); i++) {
	auto _laserCanonShield = make_shared<LaserCanonShield>(80 + 100 * i, 450, true, 3);
	auto _UplaserCanonShield = make_shared<LaserCanonShield>(80 + 100 * i, 70, true, 3);
	_laserCanonShields.push_back(_laserCanonShield);
	_laserCanonShields.push_back(_UplaserCanonShield);
    }
}

void GameLoop::createLaserCanonLives()
{
    auto numberOfLives = 3;

    for(auto i = 0; i < numberOfLives; i++) {
	auto _laserCanonLife1 = make_shared<LaserCanonLife>(380 - 20 * i, 0, true, 1);
	auto _laserCanonLife2 = make_shared<LaserCanonLife>(380 - 20 * i, 20, true, 1);
	_laserCanonLife.push_back(_laserCanonLife1);
	_laserCanonLife.push_back(_laserCanonLife2);
    }
}

void GameLoop::createAliens()
{
    auto numberOfAliens = Alien::getNumberOfAliens();

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30);
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _greenAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::GREEN);
	_greenAliens.push_back(_greenAlien);
	auto _alienLaser = make_shared<Laser>(*_greenAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30) + 30;
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _purpleAlien =
	    make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::PURPLE);
	_purpleAliens.push_back(_purpleAlien);
	auto _alienLaser = make_shared<Laser>(*_purpleAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30) + 60;
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _redAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::RED);
	_redAliens.push_back(_redAlien);
	auto _alienLaser = make_shared<Laser>(*_redAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10);
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _upGreenAlien =
	    make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::GREEN);
	_upGreenAliens.push_back(_upGreenAlien);
	auto _alienLaser = make_shared<Laser>(*_upGreenAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10) - 30;
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _upPurpleAlien =
	    make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::PURPLE);
	_upPurpleAliens.push_back(_upPurpleAlien);
	auto _alienLaser = make_shared<Laser>(*_upPurpleAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10) - 60;
	auto rightBoundary = get<0>(WindowDisplay::screenDimensions()) - 20 - 30 * i;
	auto leftBoundary = ((30 * numberOfAliens) - 30) - 30 * i;
	auto _upRedAlien = make_shared<Alien>(xPosition, yPosition, rightBoundary, leftBoundary, 1, AlienColour::RED);
	_upRedAliens.push_back(_upRedAlien);
	auto _alienLaser = make_shared<Laser>(*_upRedAlien, 1);
	_alienLasers.push_back(_alienLaser);
    }
}

void GameLoop::aliensInitialPositions()
{
    auto numberOfAliens = Alien::getNumberOfAliens();

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30);
	_greenAliens.at(i)->setXposition(xPosition);
	_greenAliens.at(i)->setYposition(yPosition);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30) + 30;
	_purpleAliens.at(i)->setXposition(xPosition);
	_purpleAliens.at(i)->setYposition(yPosition);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) + 30) + 60;
	_redAliens.at(i)->setXposition(xPosition);
	_redAliens.at(i)->setYposition(yPosition);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10);
	_upGreenAliens.at(i)->setXposition(xPosition);
	_upGreenAliens.at(i)->setYposition(yPosition);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10) - 30;
	_upPurpleAliens.at(i)->setXposition(xPosition);
	_upPurpleAliens.at(i)->setYposition(yPosition);
    }

    for(auto i = 0; i < numberOfAliens; i++) {
	auto xPosition = get<0>(WindowDisplay::screenDimensions()) / 2 - 30 * i;
	auto yPosition = ((get<1>(WindowDisplay::screenDimensions()) / 2) - 10) - 60;
	_upRedAliens.at(i)->setXposition(xPosition);
	_upRedAliens.at(i)->setYposition(yPosition);
    }
}

void GameLoop::gameActivities()
{
    laserCanonAndLaserActivities();
    laserCanonShieldActivities();
    alienActivities();
    _windowDisplay->CheckEvent();
}

void GameLoop::laserCanonAndLaserActivities()
{
    auto _updater = GameUpdater{};
    auto _collisionDetector = CollisionDetector{};

    _updater.updateLaser1Position(*_laserCanon1, *_laser1);
    _updater.updateLaser2Position(*_laserCanon2, *_laser2);

    _collisionDetector.Laser1Laser2Collision(*_laser1, *_laser2);

    if(_windowDisplay->is_singleMode()) {
	_keyHandler.singleModeKeyCheck(*_laserCanon1, *_laserCanon2, *_laser1, *_laser2);
    } else {
	_keyHandler.KeyCheck(*_laserCanon1, *_laser1);
	_keyHandler.KeyCheck2(*_laserCanon2, *_laser2);
    }

    auto [collisionOccured, laserCanonNumber] =
        _collisionDetector.LaserCanonLaserCollision(*_laserCanon1, *_laserCanon2, *_laser1, *_laser2);

    if(collisionOccured) {
	switch(laserCanonNumber) {
	case 1:
	    _laserCanon1->destroyEntity();
	    aliensInitialPositions();
	    laserCanonsInitialPositions();
	    break;
	case 2:
	    _laserCanon2->destroyEntity();
	    aliensInitialPositions();
	    laserCanonsInitialPositions();
	    break;
	default:
	    break;
	}
    }

    for(auto alienLaser : _alienLasers) {
	auto [canonAlienLaserCollision, canonNumber] =
	    _collisionDetector.LaserCanonAlienLaserCollision(*_laserCanon1, *_laserCanon2, *alienLaser);
	_collisionDetector.LaserAliensLaserCollision(*_laser1, *_laser2, *alienLaser);
	if(canonAlienLaserCollision) {
	    switch(canonNumber) {
	    case 1:
		_laserCanon1->destroyEntity();
		aliensInitialPositions();
		laserCanonsInitialPositions();
		break;
	    case 2:
		_laserCanon2->destroyEntity();
		aliensInitialPositions();
		laserCanonsInitialPositions();
		break;
	    default:
		break;
	    }
	}
    }

    if(!_laserCanon1->isAlive() || !_laserCanon2->isAlive()) {
	gameLost = true;
	auto play = false;
	_windowDisplay->setPlay(play);
    }
}

void GameLoop::alienActivities()
{
    auto _updater = GameUpdater{};
    auto _collisionDetector = CollisionDetector{};
    auto counter = 0;
    auto AlienCounter = 0;
    auto totalNumberOfAliens = Alien::getNumberOfAliens() * 6;
    auto randomXpositions = vector<int>{};

    for(auto i = 0; i < 6; i++) {
	auto randomXposition = (rand() % ((get<0>(WindowDisplay::screenDimensions())) - 20)) + 1;
	auto randomXposition2 = (rand() % ((get<0>(WindowDisplay::screenDimensions())) - 20)) + 1;

	randomXpositions.push_back(randomXposition);
	randomXpositions.push_back(randomXposition2);
    }

    for(auto greenAlien : _greenAliens) {
	_updater.updateAlienPosition(*greenAlien);

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(0) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(11)) &&
	    purpleAlienRowAlive == false && greenAlien->isAlive()) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateAlienLaserPosition(*greenAlien, *_alienLasers.at(AlienCounter));

	if(greenAlien->isAlive() && get<1>(greenAlien->entityPosition()) >= get<3>(greenAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}

	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *greenAlien, *_laserCanon1, *_laserCanon2);
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
	purpleAlienRowAlive = any_of(_purpleAliens.begin(), _purpleAliens.end(), isAlive);

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(1) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(10)) &&
	    redAlienRowAlive == false && purpleAlien->isAlive()) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateAlienLaserPosition(*purpleAlien, *_alienLasers.at(AlienCounter));

	if(purpleAlien->isAlive() && get<1>(purpleAlien->entityPosition()) >= get<3>(purpleAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}

	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *purpleAlien, *_laserCanon1, *_laserCanon2);
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
	redAlienRowAlive = any_of(_redAliens.begin(), _redAliens.end(), isAlive);

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(2) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(9)) &&
	    redAlien->isAlive()) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateAlienLaserPosition(*redAlien, *_alienLasers.at(AlienCounter));

	if(redAlien->isAlive() && get<1>(redAlien->entityPosition()) >= get<3>(redAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}
	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *redAlien, *_laserCanon1, *_laserCanon2);
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

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(3) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(8)) &&
	    UpGreenAlien->isAlive() && upPurpleAlienRowAlive == false) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateUpAlienLaserPosition(*UpGreenAlien, *_alienLasers.at(AlienCounter));

	if(UpGreenAlien->isAlive() && get<1>(UpGreenAlien->entityPosition()) <= get<2>(UpGreenAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}
	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpGreenAlien, *_laserCanon1, *_laserCanon2);
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
	upPurpleAlienRowAlive = any_of(_upPurpleAliens.begin(), _upPurpleAliens.end(), isAlive);

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(4) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(7)) &&
	    UpPurpleAlien->isAlive() && upRedAlienRowAlive == false) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateUpAlienLaserPosition(*UpPurpleAlien, *_alienLasers.at(AlienCounter));

	if(UpPurpleAlien->isAlive() &&
	    get<1>(UpPurpleAlien->entityPosition()) <= get<2>(UpPurpleAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}
	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpPurpleAlien, *_laserCanon1, *_laserCanon2);
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
	upRedAlienRowAlive = any_of(_upRedAliens.begin(), _upRedAliens.end(), isAlive);

	if((get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(5) ||
	       get<0>(_alienLasers.at(AlienCounter)->entityPosition()) == randomXpositions.at(6)) &&
	    UpRedAlien->isAlive()) {
	    _alienLasers.at(AlienCounter)->shoot();
	}
	_updater.updateUpAlienLaserPosition(*UpRedAlien, *_alienLasers.at(AlienCounter));

	if(UpRedAlien->isAlive() && get<1>(UpRedAlien->entityPosition()) <= get<2>(UpRedAlien->getBoundaries())) {
	    gameLost = true;
	    auto play = false;
	    _windowDisplay->setPlay(play);
	}
	_collisionDetector.LaserAlienCollision(*_laser1, *_laser2, *UpRedAlien, *_laserCanon1, *_laserCanon2);
	if(!UpRedAlien->isAlive()) {
	    counter++;
	    if(totalNumberOfAliens == counter) {
		auto play = false;
		_windowDisplay->setPlay(play);
		gameWon = true;
	    }
	}
	AlienCounter++;
    }
}

void GameLoop::laserCanonShieldActivities()
{
    auto _collisionDetector = CollisionDetector{};
    for(auto alienLaser : _alienLasers) {
	for(auto laserCanonShield : _laserCanonShields) {
	    _collisionDetector.LaserCanonShieldAlienLaserCollision(*laserCanonShield, *alienLaser);
	}
    }

    for(auto laserCanonShield : _laserCanonShields) {
	_collisionDetector.LaserCanonShieldLaserCollission(*laserCanonShield, *_laser1, *_laser2);
    }
}

void GameLoop::displayGameEntities()
{
    auto spriteNumber = vector<int>{ 1, 2, 3 };
    auto spriteBoundaries = vector<int>{ 0, 40, 80, 120, 160, 200, 240, 280, 320, 380 };
    displayGreenAlians(spriteNumber, spriteBoundaries);
    displayPurpleAliens(spriteNumber, spriteBoundaries);
    displayRedAliens(spriteNumber, spriteBoundaries);
    displayLaserCanonShields();
    displayLaserCanonLives();
    displayLaserCanonsAndLasers();
}

void GameLoop::displayLaserCanonsAndLasers()
{
    _imageDrawer->drawLaserCanon(*_laserCanon1);
    _imageDrawer->drawLaserCanon2(*_laserCanon2);
    _imageDrawer->drawLaser(*_laser1);
    _imageDrawer->drawLaser2(*_laser2);
    for(auto _alienLaser : _alienLasers) {
	_imageDrawer->drawAlienLaser(*_alienLaser);
    }
}

void GameLoop::displayLaserCanonShields()
{
    for(auto _laserCanonShield : _laserCanonShields) {
	if(get<1>(_laserCanonShield->entityPosition()) == 450) {
	    _imageDrawer->drawLaserCanonShields(*_laserCanonShield, 1, _laserCanonShield->getNumberOfLives());
	} else {
	    _imageDrawer->drawLaserCanonShields(*_laserCanonShield, 2, _laserCanonShield->getNumberOfLives());
	}
    }
}

void GameLoop::displayLaserCanonLives()
{
    switch(_laserCanon1->getNumberOfLives()) {
    case 1:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(0));
	break;
    case 2:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(0));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(2));
	break;
    case 3:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(0));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(2));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(4));
	break;
    default:
	break;
    }

    switch(_laserCanon2->getNumberOfLives()) {
    case 1:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(1));
	break;
    case 2:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(1));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(3));
	break;
    case 3:
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(1));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(3));
	_imageDrawer->drawLaserCanonLives(*_laserCanonLife.at(5));
	break;
    default:
	break;
    }
}

void GameLoop::displayGreenAlians(vector<int> spriteNumber, vector<int> spriteBoundaries)
{

    for(auto GreenAlien : _greenAliens) {
	auto greenAlien_Xposition = get<0>(GreenAlien->entityPosition());

	if((greenAlien_Xposition >= spriteBoundaries.at(0) && greenAlien_Xposition < spriteBoundaries.at(1)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(3) && greenAlien_Xposition < spriteBoundaries.at(4)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(6) && greenAlien_Xposition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawGreenAliens(*GreenAlien, spriteNumber.at(0));

	} else if((greenAlien_Xposition >= spriteBoundaries.at(1) && greenAlien_Xposition < spriteBoundaries.at(2)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(4) && greenAlien_Xposition < spriteBoundaries.at(5)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(7) && greenAlien_Xposition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawGreenAliens(*GreenAlien, spriteNumber.at(1));

	} else if((greenAlien_Xposition >= spriteBoundaries.at(2) && greenAlien_Xposition < spriteBoundaries.at(3)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(5) && greenAlien_Xposition < spriteBoundaries.at(6)) ||
	    (greenAlien_Xposition >= spriteBoundaries.at(8) && greenAlien_Xposition < spriteBoundaries.at(9))) {

	    _imageDrawer->drawGreenAliens(*GreenAlien, spriteNumber.at(2));
	}
    }

    for(auto UpGreenAlien : _upGreenAliens) {
	auto upGreenAlien_Xposition = get<0>(UpGreenAlien->entityPosition());
	if((upGreenAlien_Xposition >= spriteBoundaries.at(0) && upGreenAlien_Xposition < spriteBoundaries.at(1)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(3) && upGreenAlien_Xposition < spriteBoundaries.at(4)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(6) && upGreenAlien_Xposition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(0));

	} else if((upGreenAlien_Xposition >= spriteBoundaries.at(1) &&
	              upGreenAlien_Xposition < spriteBoundaries.at(3)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(4) && upGreenAlien_Xposition < spriteBoundaries.at(5)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(7) && upGreenAlien_Xposition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(1));

	} else if((upGreenAlien_Xposition >= spriteBoundaries.at(2) &&
	              upGreenAlien_Xposition < spriteBoundaries.at(3)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(5) && upGreenAlien_Xposition < spriteBoundaries.at(6)) ||
	    (upGreenAlien_Xposition >= spriteBoundaries.at(8) && upGreenAlien_Xposition < spriteBoundaries.at(9))) {

	    _imageDrawer->drawUpGreenAliens(*UpGreenAlien, spriteNumber.at(2));
	}
    }
}

void GameLoop::displayPurpleAliens(vector<int> spriteNumber, vector<int> spriteBoundaries)
{
    for(auto PurpleAlien : _purpleAliens) {
	auto purpleAlien_Xposition = get<0>(PurpleAlien->entityPosition());
	if((purpleAlien_Xposition >= spriteBoundaries.at(0) && purpleAlien_Xposition < spriteBoundaries.at(1)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(3) && purpleAlien_Xposition < spriteBoundaries.at(4)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(6) && purpleAlien_Xposition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawPurpleAliens(*PurpleAlien, spriteNumber.at(0));

	} else if((purpleAlien_Xposition >= spriteBoundaries.at(1) && purpleAlien_Xposition < spriteBoundaries.at(2)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(4) && purpleAlien_Xposition < spriteBoundaries.at(5)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(7) && purpleAlien_Xposition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawPurpleAliens(*PurpleAlien, spriteNumber.at(1));

	} else if((purpleAlien_Xposition >= spriteBoundaries.at(2) && purpleAlien_Xposition < spriteBoundaries.at(3)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(5) && purpleAlien_Xposition < spriteBoundaries.at(6)) ||
	    (purpleAlien_Xposition >= spriteBoundaries.at(8) && purpleAlien_Xposition < spriteBoundaries.at(9))) {

	    _imageDrawer->drawPurpleAliens(*PurpleAlien, spriteNumber.at(2));
	}
    }

    for(auto UpPurpleAlien : _upPurpleAliens) {

	auto UpPurpleAlien_Xposition = get<0>(UpPurpleAlien->entityPosition());
	if((UpPurpleAlien_Xposition >= spriteBoundaries.at(0) && UpPurpleAlien_Xposition < spriteBoundaries.at(1)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(3) && UpPurpleAlien_Xposition < spriteBoundaries.at(4)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(6) && UpPurpleAlien_Xposition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(0));
	} else if((UpPurpleAlien_Xposition >= spriteBoundaries.at(1) &&
	              UpPurpleAlien_Xposition < spriteBoundaries.at(2)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(4) && UpPurpleAlien_Xposition < spriteBoundaries.at(5)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(7) && UpPurpleAlien_Xposition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(1));
	} else if((UpPurpleAlien_Xposition >= spriteBoundaries.at(2) &&
	              UpPurpleAlien_Xposition < spriteBoundaries.at(3)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(5) && UpPurpleAlien_Xposition < spriteBoundaries.at(6)) ||
	    (UpPurpleAlien_Xposition >= spriteBoundaries.at(8) && UpPurpleAlien_Xposition < spriteBoundaries.at(9))) {
	    _imageDrawer->drawUpPurpleAliens(*UpPurpleAlien, spriteNumber.at(2));
	}
    }
}

void GameLoop::displayRedAliens(vector<int> spriteNumber, vector<int> spriteBoundaries)
{
    for(auto RedAlien : _redAliens) {
	auto redAlien_xPosition = get<0>(RedAlien->entityPosition());
	if((redAlien_xPosition >= spriteBoundaries.at(0) && redAlien_xPosition < spriteBoundaries.at(1)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(3) && redAlien_xPosition < spriteBoundaries.at(4)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(6) && redAlien_xPosition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawRedAliens(*RedAlien, spriteNumber.at(0));

	} else if((redAlien_xPosition >= spriteBoundaries.at(1) && redAlien_xPosition < spriteBoundaries.at(2)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(4) && redAlien_xPosition < spriteBoundaries.at(5)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(7) && redAlien_xPosition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawRedAliens(*RedAlien, spriteNumber.at(1));

	} else if((redAlien_xPosition >= spriteBoundaries.at(2) && redAlien_xPosition < spriteBoundaries.at(3)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(5) && redAlien_xPosition < spriteBoundaries.at(6)) ||
	    (redAlien_xPosition >= spriteBoundaries.at(8) && redAlien_xPosition < spriteBoundaries.at(9))) {

	    _imageDrawer->drawRedAliens(*RedAlien, spriteNumber.at(2));
	}
    }

    for(auto UpRedAlien : _upRedAliens) {

	auto upRedAlien_xPosition = get<0>(UpRedAlien->entityPosition());
	if((upRedAlien_xPosition >= spriteBoundaries.at(0) && upRedAlien_xPosition < spriteBoundaries.at(1)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(3) && upRedAlien_xPosition < spriteBoundaries.at(4)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(6) && upRedAlien_xPosition < spriteBoundaries.at(7))) {

	    _imageDrawer->drawUpRedAliens(*UpRedAlien, spriteNumber.at(0));

	} else if((upRedAlien_xPosition >= spriteBoundaries.at(1) && upRedAlien_xPosition < spriteBoundaries.at(2)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(4) && upRedAlien_xPosition < spriteBoundaries.at(5)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(7) && upRedAlien_xPosition < spriteBoundaries.at(8))) {

	    _imageDrawer->drawUpRedAliens(*UpRedAlien, spriteNumber.at(1));

	} else if((upRedAlien_xPosition >= spriteBoundaries.at(2) && upRedAlien_xPosition < spriteBoundaries.at(3)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(5) && upRedAlien_xPosition < spriteBoundaries.at(6)) ||
	    (upRedAlien_xPosition >= spriteBoundaries.at(8) && upRedAlien_xPosition < spriteBoundaries.at(9))) {

	    _imageDrawer->drawUpRedAliens(*UpRedAlien, spriteNumber.at(2));
	}
    }
}