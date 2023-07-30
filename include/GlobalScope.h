#ifndef GLOBALSCOPE_H
#define GLOBALSCOPE_H

#include <vector>
#include <memory>
#include "Object.h"
#include "Point.h"

class Object;

class GlobalScope{
    public:
        static void add_object(std::shared_ptr<Object> obj);
        static void remove_object(std::shared_ptr<Object> obj);
        static void remove_all_objects();
        static std::shared_ptr<Object> get_object(int indx);
        static std::shared_ptr<Object> get_object_by_pos(Point pos);
        static int get_objects_count();
        static int get_object_index(Object *obj);
    private:
        static std::vector<std::shared_ptr<Object>> objects;

        GlobalScope();
        ~GlobalScope();
};

#endif