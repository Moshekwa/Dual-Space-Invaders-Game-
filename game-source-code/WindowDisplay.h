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
    tuple<int, int> screenDimensions() const;

    void setPlay(bool& play);
    bool isPlay() const;
    
    int getPlayMode() const;

    shared_ptr<RenderWindow> getWindow();

private:
    const static int screenWidth;
    const static int screenHeight;
    shared_ptr<RenderWindow> _window;
    bool _play;
    Sprite _sprite;
    int _playMode;
};

#endif // WINDOWDISPLAY_H_INCLUDED