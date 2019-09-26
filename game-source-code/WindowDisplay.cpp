#include "KeyHandler.h"
#include "WindowDisplay.h"
#include <memory>
using std::make_shared;

WindowDisplay::WindowDisplay()
    : _window{ new RenderWindow{ VideoMode(screenWidth, screenHeight), "Duel Space Invaders" } }
{
    // set frame rate
    const int FPS = 60;
    _window->setFramerateLimit(FPS);
    _play = false;
    _singleMode = false;
}

const int WindowDisplay::screenWidth{ 400 };
const int WindowDisplay::screenHeight{ 500 };

void WindowDisplay::CheckEvent()
{
    auto event = Event{};
    auto _keyHandler = make_shared<KeyHandler>();
    auto [quit, singlePlay, dualPlay] = _keyHandler->keyCheckGameMode();

    while(_window->pollEvent(event)) {
        if(event.type == Event::Closed || quit) {
            _window->close();
        }
        if(dualPlay) {
            _play = true;
        }
        if(singlePlay) {
            _play = true;
            _singleMode = true;
        }
    }
}

void WindowDisplay::setPlay(bool& play)
{
    _play = play;
}

bool WindowDisplay::isPlay() const
{
    return _play;
}

bool WindowDisplay::is_singleMode() const
{
    return _singleMode;
}

shared_ptr<RenderWindow> WindowDisplay::getWindow()
{
    return _window;
}

tuple<int, int> WindowDisplay::screenDimensions()
{
    return { screenWidth, screenHeight };
}
