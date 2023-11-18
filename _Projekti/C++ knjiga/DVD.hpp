#pragma once
#include "Ploca.hpp"

/// <summary>
///		Izvedena klasa za klase DVD
///		Sadrzi dodatne informacije koje su povezane uz DVD
///		Override metode base klase _ispisi da doda nove informacije u ispis na konzolu
/// </summary>
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
