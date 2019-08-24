#include "Player.h"
#include "WindowDisplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    Texture texture;
    WindowDisplay windowDisplay;
    Player _player{200,380, true};

    if(!texture.loadFromFile("spaceship.png")) {
        exit(1);
    }

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(_player.getXposition(), _player.getYposition()));
    sprite.setScale(Vector2f(0.5f, 0.5f));

    while(windowDisplay.getWindow()->isOpen()) {
        windowDisplay.CheckEvent();
        windowDisplay.getWindow()->clear();
        windowDisplay.getWindow()->draw(sprite);
        windowDisplay.getWindow()->display();
    }

    return 0;
}