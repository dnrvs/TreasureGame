#include "../include/GlobalScope.h"
std::vector<std::shared_ptr<Object>> GlobalScope::objects;

void GlobalScope::add_object(std::shared_ptr<Object> obj){
    objects.push_back(obj);
}
void GlobalScope::remove_object(std::shared_ptr<Object> obj){
    int indx = get_object_index(obj.get());
    if (indx != -1){
        objects.erase(objects.begin()+indx);
    }
}
void GlobalScope::remove_all_objects(){
    objects.clear();
}
std::shared_ptr<Object> GlobalScope::get_object(int indx){
    return objects[indx];
}
std::shared_ptr<Object> GlobalScope::get_object_by_pos(Point pos){
    for(auto obj : objects){
        if (obj->get_position() == pos){
            return obj;
        }
    }
    return nullptr;
}
int GlobalScope::get_objects_count(){
    return objects.size();
}
int GlobalScope::get_object_index(Object *obj){
    int indx = -1;
    for (int i = 0; i < objects.size(); i++){
        if (objects[i].get() == obj){
            indx = i;
        }
    }
    return indx;
}

GlobalScope::GlobalScope(){}
GlobalScope::~GlobalScope(){}