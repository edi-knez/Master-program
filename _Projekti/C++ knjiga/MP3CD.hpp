#pragma once
#include "Ploca.hpp"

/// <summary>
///		Izvedena klasa za klase MP3CD
///		Sadrzi dodatne informacije koje su povezane uz DVD
///		Override metode base klase _ispisi da promijeni informacije u ispis na konzolu
/// </summary>
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