#include "KeyHandler.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using sf::Keyboard;

KeyHandler::KeyHandler()
{
}

void KeyHandler::KeyCheck(LaserCanon& _laserCanon1)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        _laserCanon1.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        _laserCanon1.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        auto laser_number = 1;
        _laserCanon1.shootLaser(laser_number);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::KeyCheck2(LaserCanon& _laserCanon2)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) {
        _laserCanon2.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) {
        _laserCanon2.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::W)) {
        auto laser_number = 2;
        _laserCanon2.shootLaser(laser_number);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
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
        auto laser1 = 1;
        auto laser2 = 2;
        _laserCanon1.shootLaser(laser1);
        _laserCanon2.shootLaser(laser2);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}