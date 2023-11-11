#pragma once
#include <string>
#include <iostream>


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

protected:
public:
    std::string naslov,
        izvodac;
    int trajanje = 45;
};