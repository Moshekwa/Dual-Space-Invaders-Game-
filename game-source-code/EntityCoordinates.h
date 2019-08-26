#ifndef ENTITYCOORDINATES_H_INCLUDED
#define ENTITYCOORDINATES_H_INCLUDED

class EntityCoordinates
{
public:
    EntityCoordinates(int x=0, int y=0);
    void setXposition(int x);
    void setYposition(int y);
    int getXposition() const;
    int getYposition() const;

private:
    int xPosition;
    int yPosition;
};

#endif // ENTITYCOORDINATES_H_INCLUDED