#include "../../include/Treasure.h"

Treasure::Treasure(Point pos) : Object("Treasure"){
    this->position = pos;
}
Treasure::~Treasure(){}

Object::IDs Treasure::get_id(){
    return Object::IDs::Treasure;
}