#pragma once
#include "Ploca.hpp"


class DVD : public Ploca {
public:
    DVD() :Ploca() { dvostrani = true; }

    void _ispisi() override 
    {
        ispis_basic_info();
        std::cout << "DVD: dvostrani\t- " << dvostrani << '\n' << '\n';
    }

private:
    bool dvostrani;
};
