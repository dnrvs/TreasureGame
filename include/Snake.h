#ifndef SNAKE_H
#define SNAKE_H

#include "Enemy.h"

class Snake : public Enemy{
    public:
        Snake();
        ~Snake();

        Object::IDs get_id();
};

#endif