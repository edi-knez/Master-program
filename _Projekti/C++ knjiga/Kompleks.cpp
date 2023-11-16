#include "Kompleks.hpp"

/// <summary>
///		Implementacija klase Kompleks
/// </summary>

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


/// <summary>
///		Usporedba dvaju kompleksnih brojeva
/// </summary>
/// <param name="c1"></param>
/// <param name="c2"></param>
/// <returns></returns>
bool operator< (const Kompleks& c1, const Kompleks& c2) {
    return (pow(c1.real, 2) + pow(c1.imag, 2) < pow(c2.real, 2) + pow(c2.imag, 2));
}

bool operator> (const Kompleks& c1, const Kompleks& c2) {
    return (pow(c1.real, 2) + pow(c1.imag, 2) > pow(c2.real, 2) + pow(c2.imag, 2));
}

/// <summary>
///		Implementacija istream operatora >> da bi se mogo direktno upisat u cin objekt sa tipkovnice
/// </summary>
/// <param name="s"></param>
/// <param name="c1"></param>
/// <returns></returns>
std::istream& operator>> (std::istream& s, Kompleks& c1) {
    double rtemp, itemp;

    if (s >> rtemp >> itemp) {
        c1.real = rtemp;
        c1.imag = itemp;
    }
    return s;
}

/// <summary>
///		Implementacija operatora = , nije potrebno provjeravat je li samopridruzivanje jer se nece brisat memorija
/// </summary>
/// <param name="c">Novi kompleksni broj</param>
/// <returns>Referencu na objekt koji je pozvan</returns>
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
