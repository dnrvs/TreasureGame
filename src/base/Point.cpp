#include "../../include/Point.h"

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}
Point::~Point(){}

Point Point::operator+(Point p){
    return Point(this->x + p.x, this->y + p.y);
}
Point Point::operator-(Point p){
    return Point(this->x - p.x, this->y - p.y);
}
Point Point::operator*(Point p){
    return Point(this->x * p.x, this->y * p.y);
}
Point Point::operator/(Point p){
    return Point(this->x / p.x, this->y / p.y);
}
void Point::operator+=(Point p){
    this->x += p.x;
    this->y += p.y;
}
void Point::operator-=(Point p){
    this->x -= p.x;
    this->y -= p.y;
}
void Point::operator*=(Point p){
    this->x *= p.x;
    this->y *= p.y;
}
void Point::operator/=(Point p){
    this->x /= p.x;
    this->y /= p.y;
}
bool Point::operator!=(Point p){
    return this->x != p.x || this->y != p.y;
}
/*bool Point::operator<(Point p){
    return this->x < p.x || this->y < p.y;
}
bool Point::operator>(Point p){
    return this->x > p.x || this->y > p.y;
}
bool Point::operator<=(Point p);
bool Point::operator>=(Point p);*/
bool Point::operator==(Point p){
    return this->x == p.x && this->y == p.y;
}
int Point::operator[](int indx){
    switch(indx){
        case 0: 
            return this->x;
            break;
        case 1: 
            return this->y;
            break;
    }
    return 0;
}