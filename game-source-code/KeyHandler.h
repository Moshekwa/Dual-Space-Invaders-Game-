#ifndef KEYHANDLER_H_INCLUDED
#define KEYHANDLER_H_INCLUDED

#include "Player.h"
#include <memory>
using std::shared_ptr;

class KeyHandler
{
public:
    KeyHandler();
    void KeyCheck(Player& player);
    void KeyCheck2(Player& player2);

private:
};

#endif // KEYHANDLER_H_INCLUDED