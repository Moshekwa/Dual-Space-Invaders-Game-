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

    if(!texture.loadFromFile("spaceship.png")) {
        exit(1);
    }

    Sprite sprite;
    sprite.setTexture(texture);

    while(windowDisplay.getWindow()->isOpen()) {
        windowDisplay.CheckEvent();
        windowDisplay.getWindow()->clear();
        windowDisplay.getWindow()->draw(sprite);
        windowDisplay.getWindow()->display();
    }

    return 0;
}