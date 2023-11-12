#pragma once
#include "Ploca.hpp"
#include <iostream>

class LP : public Ploca {
public:
    LP() :Ploca() { RPM = 45; }

    void _ispisi() override 
    {
        ispis_basic_info();
        std::cout << "LP: RPM\t- " << RPM << '\n' << '\n';
    }

private:
    int RPM;
};