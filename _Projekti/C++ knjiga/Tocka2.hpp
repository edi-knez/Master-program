#pragma once
#include <cmath>

class Tocka2 {
public:
    Tocka2() : x(0), y(0) {};
    inline void setTocka(double _x, double _y);

private:
    double x, y;

public:
    friend double Udaljenost(const Tocka2& t1, const Tocka2& t2);/* {
        return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
    };*/
};

inline void Tocka2::setTocka(double _x, double _y) {
    x = _x;
    y = _y;
}

// already defined?
////double Udaljenost(const Tocka2& t1, const Tocka2& t2) {
////    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
////}