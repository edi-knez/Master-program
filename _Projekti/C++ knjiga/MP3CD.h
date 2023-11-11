#pragma once
#include "Ploca.h"

class MP3CD : public Ploca {
public:
    MP3CD() :Ploca() { izvor = "vinil"; }
    void _ispisi() override 
    {
        std::cout << "MP3CD: izvor\t- " << izvor << '\n';
    }

private:
    std::string izvor;
};