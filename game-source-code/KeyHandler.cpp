#include "KeyHandler.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using sf::Keyboard;

KeyHandler::KeyHandler()
{
}

void KeyHandler::KeyCheck(Player& _player)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        _player.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        _player.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::KeyCheck2(Player& _player)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) {
        _player.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) {
        _player.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}