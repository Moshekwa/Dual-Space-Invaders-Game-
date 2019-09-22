#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED
#include <tuple>
using namespace std;

class GameEntity
{
public:
    GameEntity(int xPosition, int yPosition, bool life, int numberOfLives);
    void setXposition(int x);
    void setYposition(int y);
    tuple<int, int> entityPosition() const;
    void giveEntityLife();
    void destroyEntity();
    bool isAlive() const;
    int getNumberOfLives() const;

private:
    int _Xposition;
    int _Yposition;
    bool _life;
    int _numberOfLives;
};

#endif // GAMEENTITY_H_INCLUDED