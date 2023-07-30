#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "Object.h"

class DynamicObject : public Object{
    public:
        DynamicObject(std::string name);
        virtual ~DynamicObject() = 0;

        void move_to(Point position);
    private:
        using Object::position;
};

#endif