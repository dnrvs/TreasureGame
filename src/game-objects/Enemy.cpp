#include "../../include/Enemy.h"

Enemy::Enemy(std::string name, int hp, int attack_damage) : Character(name, hp){
    set_name(name);
    this->attack_damage = attack_damage;
}
Enemy::~Enemy(){}

void Enemy::movement(){
    Point next_mov = movement_sequence[movement_indx];
    std::shared_ptr<Object> obj = GlobalScope::get_object_by_pos(get_position()+next_mov);
    if (obj != nullptr && obj->get_id() == Object::IDs::Player){
        attack(dynamic_cast<Character *>(obj.get()));
    }
    Point next_pos = get_position()+movement_sequence[movement_indx];
    move_to(next_pos);
    if (get_position() == next_pos){
        movement_indx++;
    }
    if (movement_indx > 3){
        movement_indx = 0;
    }
}