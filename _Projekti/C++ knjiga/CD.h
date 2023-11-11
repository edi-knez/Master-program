#pragma once
#include "Ploca.h"

class CD : public Ploca {
public:
    CD() :Ploca() { RW = true; }

    void _ispisi() override 
    {
        ispis_basic_info();
        std::cout << "CD: RW\t- " << RW << '\n' << '\n';
    }

private:
    bool RW;
};