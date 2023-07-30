#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character{
    public:
        Enemy(std::string name, int hp, int attack_damage);
        virtual ~Enemy() = 0;
        virtual void movement();
    protected:
        std::vector<Point> movement_sequence;
        int movement_indx = 0;
};

#endif