#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "../include/GlobalScope.h"
#include "../include/Wall.h"
#include "../include/Treasure.h"
#include "../include/Player.h"
#include "../include/Snake.h"
#include "../include/Ghost.h"
#include "../include/Warrior.h"
namespace fs = std::filesystem;

const Point cell_size = Point(20,9);
Point min_offset = Point(0,0), max_offset = cell_size;

std::shared_ptr<Player> player = std::make_shared<Player>(Player("Pedro",100));
bool game_finished = false;
bool game_paused = false;
char action;

class BufferToggle
{
    private:
        struct termios t;

    public:
        void off(void)
        {
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag &= ~ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        }
        void on(void)
        {
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag |= ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        }
} bt;


void end_game(){
    game_finished = true;
    game_paused = false;

    GlobalScope::remove_all_objects();
}

std::string id_to_string(Object::IDs object_id){
    switch(object_id){
        case Object::IDs::Wall:
            return "█";
            break;
        case Object::IDs::Treasure:
            return "$";
            break;
        case Object::IDs::Player:
            return "♦";
            break;
        case Object::IDs::Snake:
            return "S";
            break;
        case Object::IDs::Ghost:
            return "@";
            break;
        case Object::IDs::Warrior:
            return "W";
            break;
    }
    return " ";
}

void print_game(){
    static bool printing;
    if (game_finished || game_paused || printing){
        return;
    }

    printing = true;
    std::cout << "\x1B[2J\x1B[H";
    for (int y = max_offset.y; y >= min_offset.y; y--){
        for (int x = min_offset.x; x < max_offset.x; x++){
            Point p(x,y);
            std::string text = " ";
            std::shared_ptr<Object> obj = GlobalScope::get_object_by_pos(p);
            if (obj != nullptr){
                text = id_to_string(obj->get_id());
            }
            std::cout << text;
        }
        std::cout << std::endl;
    }
    std::cout << "HP: " << player->get_hp() << std::endl;
    printing = false;
}

void print_file(std::string folder, std::string name){
    std::cout << "\x1B[2J\x1B[H";
    fs::path directory = folder;

    if (!fs::is_directory(directory)) {
        std::cerr << "Could not open directory: " << folder << std::endl;
        return;
    }

    for (const auto file : fs::directory_iterator(directory)){
        std::string file_name = file.path().filename().generic_string();
        if (file_name == name){
            std::ifstream file_stream(file.path());
            std::string line;
            while (getline(file_stream,line)){
                std::cout << line << std::endl;
            }
            break;
        }
    }
}

void generate_map(std::ifstream file_stream){
    if (!file_stream.is_open()) {
        std::cerr << "The file could not be opened." << std::endl;
        return;
    }
    std::string line;
    int line_count = 0;
    while (file_stream >> line) {
        line_count++;
        for (int column_count = 0; column_count < line.size(); column_count++){
            std::shared_ptr<Object> n_obj;
            switch (line[column_count]){
                case '#':
                    n_obj = std::make_shared<Wall>(Wall(Point(column_count,line_count-1)));
                    break;
                case '$':
                    n_obj = std::make_shared<Treasure>(Treasure(Point(column_count,line_count-1)));
                    break;
                case 'H':
                    if(GlobalScope::get_object_index(player.get()) == -1){
                        GlobalScope::add_object(player);
                    }
                    player->move_to(Point(column_count,line_count-1));
                    break;
                case 'S':
                    n_obj = std::make_shared<Snake>(Snake());
                    break;
                case '@':
                    n_obj = std::make_shared<Ghost>(Ghost());
                    break;
                case 'W':
                    n_obj = std::make_shared<Warrior>(Warrior());
                    break;
            }
            if (std::dynamic_pointer_cast<Character>(n_obj)){
                std::dynamic_pointer_cast<Character>(n_obj)->move_to(Point(column_count,line_count-1));
            }
            if (n_obj != nullptr){
                GlobalScope::add_object(n_obj);
            }
        }
    }
}

void next_level(){
    static int level_count;

    std::string folder = "./levels/";
    fs::path directory = folder;
    if (!fs::is_directory(directory)) {
        std::cerr << "Could not open directory: " << folder << std::endl;
        return;
    }

    for (const auto file : fs::directory_iterator(directory)){
        std::string file_name = file.path().filename().generic_string();
        if (file_name == "level_"+std::to_string(level_count)+".dat"){
            GlobalScope::remove_all_objects();
            generate_map(std::ifstream(file.path()));
            min_offset = Point(0,0);
            max_offset = Point(20,9);
            level_count++;
            return;
        }
    }
    end_game();
}

void update_game(){
    double time = 0;
    while (!game_finished){
        while (game_paused){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        if (player->get_hp() <= 0){
            print_file("./prints/","gameover.txt");
            end_game();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        time += 0.01;
        if (time > 1){
            for (int i = 0; i < GlobalScope::get_objects_count(); i++){
                std::shared_ptr<Object> object = GlobalScope::get_object(i);
                if (std::dynamic_pointer_cast<Enemy>(object)){
                    std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(object);
                    enemy->movement();
                }
            }
            print_game();
            time = 0;
        }
    }
}

void update_player(){
    while (!game_finished){
        while(game_paused || GlobalScope::get_object_index(player.get()) == -1){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        action = getchar();
        if (action == '.'){
            end_game();
        }
        player->input(action);
        if (!player->has_treasure()){
            Point new_offset = Point(cell_size.x*(player->get_position().x/cell_size.x), (cell_size.y+1)*(player->get_position().y/(cell_size.y+1)));
            max_offset = Point(new_offset.x+cell_size.x,new_offset.y+cell_size.y);
            min_offset = Point(new_offset.x,new_offset.y);
            print_game();
        }
        else{
            player->remove_treasure();
            print_file("./prints/","treasure.txt");
            std::cout << "YOU FIND A TREASURE!!. PRESS 'c' TO CONTINUE\n";
            game_paused = true;
            action = getchar();
            if (action != 'c'){
                end_game();
            }
            game_paused = false;
            next_level();
            print_game();
        }
    }
}

int main(){
    print_file("./prints/","intro.txt");
    bt.off();
    std::cout << "PRESS 'y' TO START\n";
    action = getchar();
    if (action != 'y'){
        return 0;
    }
    next_level();
    print_game();

    std::thread updt(update_game);
    std::thread p_updt(update_player);
    updt.join();
    p_updt.join();
}