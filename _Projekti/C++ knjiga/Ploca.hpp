#pragma once
#include <string>
#include <iostream>

/// <summary>
///		Base klasa za infromacije o pjesmi
///		Sadrzi pure virtual funkciju _ispisi koju ce izvedene klase morat implementirat
///		Metoda ispis_basic_info ispisuje informacije koje su zajednicke svim izvedenim medijima
/// </summary>
class Ploca {
public:
    Ploca() {
        naslov = "";
        izvodac = "";
        trajanje = 45;
    }

    void ispis_basic_info()
    {
        using std::cout;
        cout << "LP: naslov\t- " << naslov << '\n';
        cout << "LP: izvodac\t- " << izvodac << '\n';
        cout << "LP: trajanje\t- " << trajanje << '\n';
    }
    virtual void _ispisi(void) = 0;


public:
    std::string naslov,
        izvodac;
    int trajanje = 45;
};