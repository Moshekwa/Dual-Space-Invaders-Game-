#include "WindowDisplay.h"

WindowDisplay::WindowDisplay() :_window {new RenderWindow{VideoMode(width, height), "Duel Invaders"}}
{
    /// set frame rate
    const int FPS = 60;
    _window->setFramerateLimit(FPS);
}

void WindowDisplay::CheckEvent()
{
    Event event;
    while(_window->pollEvent(event)){
        if(event.type == Event::Closed){
            _window->close();
        }
    }
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