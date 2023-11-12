#pragma once
#include <iostream>
#include <cmath>

class Tocka {
public:
    Tocka() : x(0), y(0) {};
    Tocka(double _x, double _y) : x(_x), y(_y) {};
    double Udaljenost(Tocka& t);

private:
    double x, y;
};

