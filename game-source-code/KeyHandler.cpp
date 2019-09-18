#include "KeyHandler.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using sf::Keyboard;

KeyHandler::KeyHandler()
{
}

void KeyHandler::KeyCheck(LaserCanon& _laserCanon1, Laser& _laser1)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
	_laserCanon1.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
	_laserCanon1.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
	_laser1.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
	exit(0);
    }
}

void KeyHandler::KeyCheck2(LaserCanon& _laserCanon2, Laser& _laser2)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) {
	_laserCanon2.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) {
	_laserCanon2.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::W)) {
	_laser2.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
	exit(0);
    }
}

void KeyHandler::singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
	_laserCanon1.move(RIGHT);
	_laserCanon2.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
	_laserCanon1.move(LEFT);
	_laserCanon2.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
	_laser1.shoot();
	_laser2.shoot();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
	exit(0);
    }
}