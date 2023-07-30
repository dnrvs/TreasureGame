#include "../../include/Object.h"

Object::Object(std::string name){
    this->name = name;
}
Object::~Object(){}

Object::IDs Object::get_id(){
    return Object::IDs::Object;
}

void Object::set_name(std::string name){
    this->name = name;
}
std::string Object::get_name(){
    return this->name;
}

Point Object::get_position(){
    return this->position;
}