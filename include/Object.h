#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <algorithm>
#include "GlobalScope.h"
#include "Point.h"

class Object{
    public:
        enum class IDs {Object,Player,Snake,Ghost,Warrior,Wall,Treasure};

        Object(std::string name);
        virtual ~Object();

        virtual IDs get_id() = 0;

        void set_name(std::string name);
        std::string get_name();

        Point get_position();
    protected:
        Point position = Point(0,0);
    private:
        std::string name;
};

#endif