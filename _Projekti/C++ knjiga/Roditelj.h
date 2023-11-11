#pragma once
#include <iostream>
#include "Clan_obitelji.h"
class Roditelj : public Clan_obitelji {
public:
    Roditelj() : Clan_obitelji() { brDjece = 0; }
    Roditelj(std::string str, int nDjece) : Clan_obitelji(str), brDjece(nDjece) {}
    void _ispis() override {
        std::cout << "Ime i prezime: " << ime_prezime << "\nBroj djece: " << brDjece << '\n';
    }

private:
    int brDjece;
};
