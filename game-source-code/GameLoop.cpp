#include "GameLoop.h"

GameLoop::GameLoop()
    : _windowDisplay{ new WindowDisplay }
    , _laserCanon1{ new LaserCanon{ 190, 380 } }
    , _laserCanon2{ new LaserCanon{ 190, 0 } }
    , _entityDrawer{ new EntityDrawer{ _windowDisplay->getWindow() } }
{
    auto numberOfAliens = 5;
    
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
    //=----------------------------------------------------------------------------------------------------------------------
    
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
    auto _collisionDetector = CollisionDetector{};
    
    for(auto greenAlien : _greenAliens) {
        _updater.updateAlienPosition(*greenAlien);
        _collisionDetector.LaserAlienCollision(*_laserCanon1, *greenAlien);
    }
    for(auto purpleAlien : _purpleAliens) {
        _updater.updateAlienPosition(*purpleAlien);
    }
    for(auto redAlien : _redAliens) {
        _updater.updateAlienPosition(*redAlien);
    }
    
    //-------------------------------------------------------------------
    for(auto UpGreenAlien : _upGreenAliens) {
        _updater.updateUpAlienPosition(*UpGreenAlien);
    }
    for(auto UpPurpleAlien : _upPurpleAliens) {
        _updater.updateUpAlienPosition(*UpPurpleAlien);
    }
    for(auto UpRedAlien : _upRedAliens) {
        _updater.updateUpAlienPosition(*UpRedAlien);
    }
    
}

void GameLoop::drawGameEntities()
{
    auto _entityDrawerProxy = EntityDrawerProxy{ _entityDrawer };
    _entityDrawerProxy._drawPlayer(*_laserCanon1, *_laserCanon2);
    
    for(auto greenAlien : _greenAliens) {
        _entityDrawerProxy._drawGreenAliens(*greenAlien);
    }
    for(auto purpleAlien : _purpleAliens) {
        _entityDrawerProxy._drawPurpleAliens(*purpleAlien);
    }
    for(auto redAlien : _redAliens) {
        _entityDrawerProxy._drawRedAliens(*redAlien);
    }
    
    //--------------------------------------------------------------
    
    for(auto UpGreenAlien : _upGreenAliens) {
        _entityDrawerProxy._drawUpGreenAliens(*UpGreenAlien);
    }
    for(auto UpPurpleAlien : _upPurpleAliens) {
        _entityDrawerProxy._drawUpPurpleAliens(*UpPurpleAlien);
    }
    for(auto UpRedAlien : _upRedAliens) {
        _entityDrawerProxy._drawUpRedAliens(*UpRedAlien);
    }
}

void GameLoop::HomeScreen()
{
    _windowDisplay->drawHomeScreen();
}