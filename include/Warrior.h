#ifndef WARRIOR_H
#define WARRIOR_H

#include "Enemy.h"

class Warrior : public Enemy{
    public:
        Warrior();
        ~Warrior();

        Object::IDs get_id();
};

#endif