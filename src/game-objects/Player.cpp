#include "../../include/Player.h"
#include "../../include/Enemy.h"

Player::Player(std::string name,int attack_damage) : Character(name,5){
    this->attack_damage = attack_damage;
}
Player::~Player(){}

void Player::input(const char inp){
    Point mv = Point(0,0);
    switch(inp){
        case 'w':
            mv.y = 1;
            break;
        case 's':
            mv.y = -1;
            break;
        case 'a':
            mv.x = -1;
            break;
        case 'd':
            mv.x = 1;
            break;
    }

    std::shared_ptr<Object> obj = GlobalScope::get_object_by_pos(get_position()+mv);
    if (obj != nullptr){
        if (std::dynamic_pointer_cast<Enemy>(obj)){
            std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(obj);
            enemy->attack(this);
        }
        if (obj->get_id() == Object::IDs::Treasure){
            captured_treasure = true;
        }
    }
    move_to(get_position()+mv);
}

bool Player::has_treasure(){
    return captured_treasure;
}
void Player::remove_treasure(){
    captured_treasure = false;
}

Object::IDs Player::get_id(){
    return Object::IDs::Player;
}