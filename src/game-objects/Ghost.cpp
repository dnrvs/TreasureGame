#include "../../include/Ghost.h"

Ghost::Ghost() : Enemy("Ghost", 2, 1){
    movement_sequence = {Point(1,0),Point(1,0),Point(-1,0),Point(-1,0),Point(-1,0),Point(-1,0),Point(1,0),Point(1,0)};
}
Ghost::~Ghost(){}

Object::IDs Ghost::get_id(){
    return Object::IDs::Ghost;
}