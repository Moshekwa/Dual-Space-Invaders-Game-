#ifndef WINDOWDISPLAY_H_INCLUDED
#define WINDOWDISPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;
using std::shared_ptr;

class WindowDisplay
{
public:
    WindowDisplay();
    void CheckEvent();
    int getWidth() const;
    int getHeight() const;
    shared_ptr<RenderWindow> getWindow();
    

private:
    const int width = 400;
    const int height = 400;
    shared_ptr<RenderWindow> _window;
};

#endif // WINDOWDISPLAY_H_INCLUDED