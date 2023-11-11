#pragma once
#include <string>
class Clan_obitelji { // base
public:
    Clan_obitelji() : ime_prezime("") {}
    Clan_obitelji(std::string str) : ime_prezime(str) {}
    virtual void _ispis() = 0;

protected:
    std::string ime_prezime;
};


