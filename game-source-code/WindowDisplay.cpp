#include "WindowDisplay.h"

WindowDisplay::WindowDisplay()
    : _window{ new RenderWindow{ VideoMode(screenWidth, screenHeight), "Duel Invaders" } }
{
    /// set frame rate
    const int FPS = 60;
    _window->setFramerateLimit(FPS);
    _play = false;
    _singleMode = false;
}

const int WindowDisplay::screenWidth{ 400 };
const int WindowDisplay::screenHeight{ 400 };

void WindowDisplay::CheckEvent()
{
    auto event = Event{};
    while(_window->pollEvent(event)) {
        if(event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            _window->close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::K)) {
            _play = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::L)){
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

tuple <int, int> WindowDisplay::screenDimensions() const
{
    return {screenWidth,screenHeight};
}

