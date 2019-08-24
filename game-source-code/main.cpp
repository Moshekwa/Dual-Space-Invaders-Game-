#include "Player.h"
#include "WindowDisplay.h"
#include "KeyHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    Texture texture;
    WindowDisplay windowDisplay;
    KeyHandler _keyHandler;
    Player _player{200,380, true};

    if(!texture.loadFromFile("player1.png")) {
        exit(1);
    }

    Sprite sprite;
    sprite.setTexture(texture);
    
    sprite.setScale(Vector2f(0.5f, 0.5f));

    while(windowDisplay.getWindow()->isOpen()) {
        sprite.setPosition(Vector2f(_player.getXposition(), _player.getYposition()));
        _keyHandler.KeyCheck(_player);
        windowDisplay.CheckEvent();
        windowDisplay.getWindow()->clear();
        windowDisplay.getWindow()->draw(sprite);
        windowDisplay.getWindow()->display();
    }

    return 0;
}