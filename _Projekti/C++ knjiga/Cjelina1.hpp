#pragma once
#include <iostream>

extern int z121_datoteka();	// daje vidljivost (ovoj datoteci) o funkciji ovoga imena koja se nalazi u drugoj cpp datoteci

/// <summary>
///		Ova klasa sadrzi zadatke i vjezbe iz cjeline 1.
/// </summary>
class Cjelina1
{
public:
    static void zad4_kvadrat();
    static void zad5_ispis();

private:
    static double _kvadPovrsina(double x);

public:
    static void vj1_2datoteke();
    static void vj3_krug();
};

