#include "../../include/DynamicObject.h"

DynamicObject::DynamicObject(std::string name) : Object(name){}
DynamicObject::~DynamicObject(){}

void DynamicObject::move_to(Point position){
    if (GlobalScope::get_object_by_pos(position)){
        return;
    }
    this->position = position;
}