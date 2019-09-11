#include "WindowDisplay.h"

WindowDisplay::WindowDisplay()
    : _window{ new RenderWindow{ VideoMode(screenWidth, screenHeight), "Duel Invaders" } }
{
    /// set frame rate
    const int FPS = 60;
    _window->setFramerateLimit(FPS);
    _play = false;
    _playMode = 0;
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
        if(Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            _play = true;
            _playMode = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::L)){
            _play = true;
            _playMode = 2;
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

int WindowDisplay::getPlayMode() const
{
    return _playMode;
}

shared_ptr<RenderWindow> WindowDisplay::getWindow()
{
    return _window;
}

tuple <int, int> WindowDisplay::screenDimensions() const
{
    return {screenWidth,screenHeight};
}

