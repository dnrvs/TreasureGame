#ifndef WALL_H
#define WALL_H

#include "Object.h"

class Wall : public Object{
    public:
        Wall(Point position);
        ~Wall();

        Object::IDs get_id();
};

#endif