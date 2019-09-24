#ifndef ENTITYSHAPE_H_INCLUDED
#define ENTITYSHAPE_H_INCLUDED
#include "GameEntity.h"

class EntityShape
{
public:
    virtual void createShape() const = 0;
    virtual ~EntityShape() {};
};

#endif // ENTITYSHAPE_H_INCLUDED