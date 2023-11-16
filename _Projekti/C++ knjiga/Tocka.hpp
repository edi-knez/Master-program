#pragma once
#include <iostream>
#include <cmath>

/// <summary>
///		Ova klasa služi za prikazivanje tocke u kartizijevom sustavu
///		Sadrzi default i parametizirani konstruktor, metodu koja racuna udaljenost izmedu te tocke i tocke za koju se zeli izracunat udaljenost
///		te privatne varijable x i y koje oznacavaju koordinate te tocke
/// </summary>
class Tocka {
public:
    Tocka() : x(0), y(0) {};
    Tocka(double _x, double _y) : x(_x), y(_y) {};
    double Udaljenost(Tocka& t);

private:
    double x, y;
};

