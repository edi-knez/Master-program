#include "Tocka2.h"

double Udaljenost(const Tocka2& t1, const Tocka2& t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}