#include "../../include/Snake.h"

Snake::Snake() : Enemy("Snake", 2, 1){
    movement_sequence = {Point(1,0),Point(0,-1),Point(-1,0),Point(0,1)};
}
Snake::~Snake(){}

Object::IDs Snake::get_id(){
    return Object::IDs::Snake;
}