#pragma once
#include <iostream>

extern int z121_datoteka();	// daje vidljivost funkciji koja se nalazi u drugoj cpp datoteci

/// <summary>
///		Ova klasa sadrzi zadatke i vjezbe iz cjeline 1.
/// </summary>
class Cjelina1
{
public:
    void zad4_kvadrat();
    void zad5_ispis();

private:
    double _kvadPovrsina(double x);

public:
    void vj1_2datoteke();
    void vj3_krug();
};

