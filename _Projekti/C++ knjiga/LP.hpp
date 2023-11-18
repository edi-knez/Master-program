#pragma once
#include "Ploca.hpp"

/// <summary>
///		Izvedena klasa za klase DVD
///		Sadrzi dodatne informacije koje su povezane uz DVD
///		Override metode base klase _ispisi da doda nove informacije u ispis na konzolu
/// </summary>
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