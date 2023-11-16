#include "Tocka.hpp"

/// <summary>
///		Racuna Udaljenost izmedu dvije zeljene tocke
/// </summary>
/// <param name="t">Referenca na drugu tocku</param>
/// <returns>udaljenost izmedu te 2 tocke</returns>
double Tocka::Udaljenost(Tocka& t) {
    return sqrt(pow(t.x - this->x, 2) + pow(t.y - this->y, 2));
}