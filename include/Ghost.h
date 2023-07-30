#ifndef GHOST_H
#define GHOST_H

#include "Enemy.h"

class Ghost : public Enemy{
    public:
        Ghost();
        ~Ghost();

        Object::IDs get_id();
};

#endif