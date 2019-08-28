#include "KeyHandler.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using sf::Keyboard;

KeyHandler::KeyHandler(){}

void KeyHandler::KeyCheck(Player& player)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        player.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        player.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
         player.shootLaser();
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}

void KeyHandler::KeyCheck2(Player& player2)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::D)) {
        player2.move(RIGHT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::A)) {
        player2.move(LEFT);
    }
    if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        exit(0);
    }
}