#include "../../include/Warrior.h"

Warrior::Warrior() : Enemy("Warrior", 2, 1){
    movement_sequence = {Point(1,1),Point(1,-1),Point(-1,-1),Point(-1,1)};
}
Warrior::~Warrior(){}

Object::IDs Warrior::get_id(){
    return Object::IDs::Warrior;
}