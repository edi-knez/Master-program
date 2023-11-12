#include "KlNiz.hpp"

KlNiz::KlNiz() {
    iA = new int[10];
    for (int i = 0; i < 10; i++) {
        iA[i] = 2 * i;
    }
}

KlNiz::~KlNiz() {
    delete[] iA;
}

int KlNiz::sumaNiza() {
    int s = 0;

    for (int i = 0; i < 10; i++) {
        s = s + this->iA[i];
    }
    return s;
}
int KlNiz::sumaNiza(int iA[]) {
    int s = 0;

    for (int i = 0; i < 10; i++) {
        s = s + iA[i];
    }
    return s;
}

int KlNiz::operator[] (int idx) {
    return iA[idx];
}