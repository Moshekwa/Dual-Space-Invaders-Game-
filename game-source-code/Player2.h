#ifndef PLAYER2_H_INCLUDED
#define PLAYER2_H_INCLUDED

enum Direction2 { UP2, DOWN2, LEFT2, RIGHT2 };

class Player2
{
public:
    Player2(int _xPosition, int _yPosition, bool life);
    void setXposition(int x);
    void setYposition(int y);
    void move(Direction2 _direction);
    int getXposition();
    int getYposition();
    void setLife(bool _life);
    bool getLife();

private:
    int xPosition, yPosition;
    bool Life;
};

#endif // PLAYER_H_INCLUDED