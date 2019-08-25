#ifndef KEYHANDLER_H_INCLUDED
#define KEYHANDLER_H_INCLUDED

#include "Player.h"
#include <memory>
using std::shared_ptr;

class KeyHandler
{
public:
    KeyHandler();
    void KeyCheck(Player& _player);
    void KeyCheck2(Player& _player);

        private:
};

#endif // KEYHANDLER_H_INCLUDED