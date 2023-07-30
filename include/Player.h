#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character{
    public:
        Player(std::string name, int attack_damage);
        virtual ~Player();

        void input(const char inpt);

        bool has_treasure();
        void remove_treasure();

        Object::IDs get_id();
    private:
        bool captured_treasure = false;
};

#endif