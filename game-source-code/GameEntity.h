#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

enum Direction { UP, DOWN, LEFT, RIGHT };

class GameEntity
{
public:
    GameEntity(int x, int y);
    void setXposition(int x);
    void setYposition(int y);
    int getXposition() const;
    int getYposition() const;
    int getEntitySpeed() const;
    virtual void move(Direction _direction) = 0;

private:
    int xPosition, yPosition;
    const int speed = 5;
};

#endif // GAMEENTITY_H_INCLUDED