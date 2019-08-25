#include "KeyHandler.h"
#include "Player.h"
#include "WindowDisplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    auto texture = Texture{};
    auto texture2 = Texture{};
    auto windowDisplay = WindowDisplay{};
    auto _keyHandler = KeyHandler{};
    auto _player = Player{190,380};
    auto _player2 = Player{190,0};

    if(!texture.loadFromFile("player1.png")) {
        exit(1);
    }
    
     if(!texture2.loadFromFile("player2.png")) {
        exit(1);
    }

    Sprite sprite;
    sprite.setTexture(texture);
    Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite.setScale(Vector2f(0.5f, 0.5f));
    sprite2.setScale(Vector2f(0.5f, 0.5f));

    while(windowDisplay.getWindow()->isOpen()) {
        sprite.setPosition(Vector2f(_player.getXposition(), _player.getYposition()));
        sprite2.setPosition(Vector2f(_player2.getXposition(), _player2.getYposition()));
        _keyHandler.KeyCheck(_player);
        _keyHandler.KeyCheck2(_player2);
        windowDisplay.CheckEvent();
        windowDisplay.getWindow()->clear();
        windowDisplay.getWindow()->draw(sprite);
        windowDisplay.getWindow()->draw(sprite2);
        windowDisplay.getWindow()->display();
    }

    return 0;
}