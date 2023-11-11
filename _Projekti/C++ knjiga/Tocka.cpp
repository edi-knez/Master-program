#include "Tocka.h"

double Tocka::Udaljenost(Tocka& t) {
    return sqrt(pow(t.x - this->x, 2) + pow(t.y - this->y, 2));
}