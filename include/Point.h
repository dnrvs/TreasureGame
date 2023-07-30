#ifndef POINT_H
#define POINT_H

class Point{
    public:
        int x, y;
        Point(int x, int y);
        ~Point();

        Point operator+(Point p);
        Point operator-(Point p);
        Point operator*(Point p);
        Point operator/(Point p);
        void operator+=(Point p);
        void operator-=(Point p);
        void operator*=(Point p);
        void operator/=(Point p);
        bool operator!=(Point p);
        /*bool operator<(Point p);
        bool operator>(Point p);
        bool operator<=(Point p);
        bool operator>=(Point p);*/
        bool operator==(Point p);
        int operator[](int indx);
};

#endif