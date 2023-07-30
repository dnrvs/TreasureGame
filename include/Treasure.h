#ifndef TREASURE_H
#define TREASURE_H

#include "Object.h"

class Treasure : public Object{
    public:
        Treasure(Point position);
        ~Treasure();

        Object::IDs get_id();
};

#endif