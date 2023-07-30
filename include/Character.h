#ifndef CHARACTER_H
#define CHARACTER_H

#include "DynamicObject.h"

class Character : public DynamicObject{
    public:
        Character(std::string name, int max_hp);
        virtual ~Character() = 0;

        int get_hp();
        void decrease_hp(int amount);

        int get_max_hp();

        void attack(Character *c);
    protected:
        int attack_damage = 0;
    private:
        int hp;
        int max_hp;
};

#endif