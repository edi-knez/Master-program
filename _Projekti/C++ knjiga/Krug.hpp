#pragma once
#include <iostream>

/// <summary>
///		Ova klasa sluzi za izradu kruga radijusa m_radijus i izracunavanje njegovog opsega i povrsine
/// </summary>
class Krug {
public:
    Krug();
    Krug(double r);
    ~Krug();
    bool SetRadijus(double r);

    double izracunajPovrsinu();
    double izracunajOpseg();
private:
    double radijus;
};
