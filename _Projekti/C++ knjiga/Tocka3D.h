#pragma once
#include <iostream>
#include <cmath>
#include "Tocka2D.h"

class Tocka3D : public Tocka2D {
public:
    Tocka3D(double x, double y, double z) : Tocka2D(m_x, m_y) {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    // metoda kojom se mijenja i ocitava polozaj tocke
    void setZ(double z);
    double getZ() const;
    // operator == ako su tocke identicne
    bool operator== (const Tocka3D& t) const;
    bool areEqual(const Tocka3D& t1, const Tocka3D& t2) { return t1.operator==(t2); }
    // kopirni konstruktor
    Tocka3D& operator= (const Tocka3D& t);

private:
    double m_z;

private:
    friend std::ostream& operator<<(std::ostream& os, const Tocka3D& t);
};
