#pragma once
#include <string>

/// <summary>
///		Ova base klasa predstavlja clana obitelji. Njegova uloga se moze implementirati pomocu izvedene klase.
/// </summary>
class Clan_obitelji { // base
public:
    Clan_obitelji() : ime_prezime("") {}
    Clan_obitelji(std::string str) : ime_prezime(str) {}
    virtual void _ispis() = 0;

protected:
    std::string ime_prezime;
};


