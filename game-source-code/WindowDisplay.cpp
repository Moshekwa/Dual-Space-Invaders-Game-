#include "WindowDisplay.h"

WindowDisplay::WindowDisplay()
    : _window{ new RenderWindow{ VideoMode(width, height), "Duel Invaders" } }
{
    /// set frame rate
    const int FPS = 60;
    _window->setFramerateLimit(FPS);
    _play = false;
}

void WindowDisplay::CheckEvent()
{
    auto event = Event{};
    while(_window->pollEvent(event)) {
        if(event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            _window->close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            _play = true;
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

shared_ptr<RenderWindow> WindowDisplay::getWindow()
{
    return _window;
}

int WindowDisplay::getWidth() const
{
    return width;
}

int WindowDisplay::getHeight() const
{
    return height;
}