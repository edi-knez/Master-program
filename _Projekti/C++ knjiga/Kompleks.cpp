#include "Kompleks.hpp"



Kompleks::Kompleks() {
    imag = 0.0;
    real = 0.0;
}

Kompleks::Kompleks(double r, double i) {
    real = r;
    imag = i;
}

Kompleks Kompleks::operator+(const Kompleks& d) {
    Kompleks zbroj(this->real + d.real, this->imag + d.imag);
    return zbroj;
}

Kompleks Kompleks::operator-(const Kompleks& d)
{
    Kompleks razlika(real - d.real, imag - d.imag);
    return razlika;
}



bool operator< (const Kompleks& c1, const Kompleks& c2) {
    return (pow(c1.real, 2) + pow(c1.imag, 2) < pow(c2.real, 2) + pow(c2.imag, 2));
}

bool operator> (const Kompleks& c1, const Kompleks& c2) {
    return (pow(c1.real, 2) + pow(c1.imag, 2) > pow(c2.real, 2) + pow(c2.imag, 2));
}

std::istream& operator>> (std::istream& s, Kompleks& c1) {
    double rtemp, itemp;

    if (s >> rtemp >> itemp) {
        c1.real = rtemp;
        c1.imag = itemp;
    }
    return s;
}


Kompleks& Kompleks::operator= (const Kompleks& c) {
    real = c.real;
    imag = c.imag;

    return *this;
}

Kompleks& Kompleks::operator+= (const Kompleks& c) {
    real += c.real;
    imag += c.imag;

    return *this;
}

//
std::ostream& operator <<(std::ostream& os, const Kompleks& c)
{
    os << std::setprecision(13) << c.getReal() << " + i * " << c.getImag() << "\n";
    return os;
}
