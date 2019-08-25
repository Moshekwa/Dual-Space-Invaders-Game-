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
    auto laserTexture = Texture{};
    
    auto windowDisplay = WindowDisplay{};
    auto _keyHandler = KeyHandler{};
    auto _player = Player{ windowDisplay.getWidth() / 2 - 10, windowDisplay.getHeight() - 20 };
    auto _player2 = Player{ windowDisplay.getWidth() / 2 - 10, 0 };
    auto _laser = Laser{};

    if(!texture.loadFromFile("player1.png")) {
        exit(1);
    }

    if(!texture2.loadFromFile("player2.png")) {
        exit(1);
    }
    
    if(!laserTexture.loadFromFile("laser1.png")){
        exit(1);
    }

    auto sprite = Sprite{};
    sprite.setTexture(texture);
    auto sprite2 = Sprite{};
    sprite2.setTexture(texture2);
    auto laserSprite = Sprite{};
    laserSprite.setTexture(laserTexture);
    
    sprite.setScale(Vector2f(0.5f, 0.5f));
    sprite2.setScale(Vector2f(0.5f, 0.5f));
    laserSprite.setScale(Vector2f(0.5f, 0.5f));

    while(windowDisplay.getWindow()->isOpen()) {
        sprite.setPosition(Vector2f(_player.getXposition(), _player.getYposition()));
        sprite2.setPosition(Vector2f(_player2.getXposition(), _player2.getYposition()));
        laserSprite.setPosition(Vector2f(_player.getLaser().getXposition(), _player.getLaser().getYposition()));
        
        _keyHandler.KeyCheck(_player);
        _keyHandler.KeyCheck2(_player2);
        
        windowDisplay.CheckEvent();
        windowDisplay.getWindow()->clear();
        
        windowDisplay.getWindow()->draw(sprite);
        windowDisplay.getWindow()->draw(sprite2);
        windowDisplay.getWindow()->draw(laserSprite);
        windowDisplay.getWindow()->display();
    }

    return 0;
}