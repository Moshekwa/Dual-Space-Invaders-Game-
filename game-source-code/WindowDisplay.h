/**
 * @file WindowDisplay.h
 * @class WindowDisplay
 * @brief This class creates the SFML screen for displaying the game. 
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef WINDOWDISPLAY_H_INCLUDED
#define WINDOWDISPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <memory>
#include <tuple>

using namespace sf;
using std::shared_ptr;
using namespace std;

class WindowDisplay
{
public:
    WindowDisplay();
    void CheckEvent();
    static tuple<int, int> screenDimensions();

    void setPlay(bool& play);
    bool isPlay() const;
    bool is_singleMode() const;

    shared_ptr<RenderWindow> getWindow();

private:
    const static int screenWidth;
    const static int screenHeight;
    shared_ptr<RenderWindow> _window;
    bool _play;
    Sprite _sprite;
    bool _singleMode;
};

#endif // WINDOWDISPLAY_H_INCLUDED