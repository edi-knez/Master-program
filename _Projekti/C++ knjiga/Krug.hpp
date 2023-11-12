#pragma once
#include <iostream>

class Krug {
public:
    Krug();
    Krug(double r);
    ~Krug();
    bool SetRadijus(double r);

    double izracunajPovrsinu();
    double izracunajOpseg();
private:
    double radijus;
};
