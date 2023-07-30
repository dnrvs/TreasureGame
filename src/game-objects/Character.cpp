#include "../../include/Character.h"

Character::Character(std::string name, int max_hp) : DynamicObject(name){
    this->max_hp = max_hp;
    this->hp = max_hp;
}
Character::~Character(){}

int Character::get_hp(){
    return this->hp;
}
void Character::decrease_hp(int amount){
    this->hp -= amount;
}

int Character::get_max_hp(){
    return this->max_hp;
}

void Character::attack(Character *c){
    c->decrease_hp(attack_damage);
}