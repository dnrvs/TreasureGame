#include "../../include/Wall.h"

Wall::Wall(Point position) : Object("Wall"){
    this->position = position;
}
Wall::~Wall(){}

Object::IDs Wall::get_id(){
    return Object::IDs::Wall;
}