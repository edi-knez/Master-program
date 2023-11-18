#pragma once
#include "Ploca.hpp"

/// <summary>
///		Izvedena klasa za klase CD
///		Sadrzi dodatne informacije koje su povezane uz DVD
///		Override metode base klase _ispisi da doda nove informacije u ispis na konzolu
/// </summary>
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