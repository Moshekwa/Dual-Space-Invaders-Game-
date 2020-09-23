#include "KeyHandler.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using sf::Keyboard;

KeyHandler::KeyHandler()
{
}

void KeyHandler::KeyCheck(LaserCanon& _laserCanon1, Laser& _laser1)
{
    auto _gameUpdater = make_shared<GameUpdater>();
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, UP);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Down)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, DOWN);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Space)) {
        _laser1.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::KeyCheck2(LaserCanon& _laserCanon2, Laser& _laser2)
{
    auto _gameUpdater = make_shared<GameUpdater>();

    if(Keyboard::isKeyPressed(Keyboard::Key::D)) {
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) {
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, LEFT);
    }

    if(Keyboard::isKeyPressed(Keyboard::Key::W)) {
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, UP);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::S)) {
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, DOWN);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::X)) {
        _laser2.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2)
{
    auto _gameUpdater = make_shared<GameUpdater>();
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, RIGHT);
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        _gameUpdater->updateLaserCanon1Position(_laserCanon1, LEFT);
        _gameUpdater->updateLaserCanon2Position(_laserCanon2, RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        _laser1.shoot();
        _laser2.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

tuple<bool,bool,bool> KeyHandler::keyCheckGameMode()
{
    auto _escape = false;
    auto _singleMode = false;
    auto _dualMode = false;
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
        _escape = true;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::L)){
        _singleMode = true;
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::K)){
        _dualMode = true;
    }
    return {_escape, _singleMode, _dualMode};
}