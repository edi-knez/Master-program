#include "Tocka2.hpp"

/// <summary>
///		friend funkcija za racunanje udaljenosti izmedu dvije tocke
/// </summary>
/// <param name="t1">tocka 1>
/// <param name="t2">tocka 2>
/// <returns></returns>
double Udaljenost(const Tocka2& t1, const Tocka2& t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}