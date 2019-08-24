#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

enum Direction { UP, DOWN, LEFT, RIGHT };

class Player
{
public:
    Player(int _xPosition, int _yPosition, bool life);
    void setXposition(int x);
    void setYposition(int y);
    void move(Direction _direction);
    int getXposition();
    int getYposition();
    void setLife(bool _life);
    bool getLife();

private:
    int xPosition, yPosition;
    bool Life;
};

#endif // PLAYER_H_INCLUDED