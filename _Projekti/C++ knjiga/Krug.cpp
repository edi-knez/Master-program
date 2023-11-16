#include "Krug.hpp"

/// <summary>
///		implementacija klase Krug
/// </summary>

Krug::Krug() {
    radijus = 0.0;
}

Krug::Krug(double r) {
    radijus = r;
}

Krug::~Krug() {
    std::cout << "Odoh ja" << '\n';
}

bool Krug::SetRadijus(double r) {
    if (r >= 0.0) {
        radijus = r;
        return true;
    }
    else { return false; }
}

double Krug::izracunajOpseg() {
    return radijus * 6.28;
}

double Krug::izracunajPovrsinu() {
    return radijus * radijus * 3.14;
}