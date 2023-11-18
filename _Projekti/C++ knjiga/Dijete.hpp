#pragma once
#include <iostream>

#include "Clan_obitelji.hpp"

/// <summary>
///		Ova klasa oznacuje da taj clan obitelji ima ulogu dijete
///		Override metodu _ispis koja ispisuje njegovo ime i prezime i kojeg je spola
/// </summary>
class Dijete : public Clan_obitelji {
public:
    Dijete(std::string str, bool da_ne) : Clan_obitelji(str), kcer(da_ne) { }
    void _ispis() override {
        std::cout << "Ime i prezime: " << ime_prezime;
        if (kcer)    std::cout << "\nSpol: kcer\n";
        else        std::cout << "\nSpol: sin\n";
    }

private:
    bool kcer;
};

