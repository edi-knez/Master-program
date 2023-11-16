#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>


/// <summary>
///		Ova klasa sluzi za primjenu konpleksnih brojeva 
///		Koristi razne operator oveloadove za jednostavnije korisnicko sucelje
/// </summary>
class Kompleks {
public:
    Kompleks();
    Kompleks(double r, double i);

public:
    Kompleks operator+ (const Kompleks& d);
    Kompleks operator- (const Kompleks& d);
    //
public:
    Kompleks& operator= (const Kompleks& d);
    Kompleks& operator+= (const Kompleks& c);

public:
    double getReal() const { return real; }
    double getImag() const { return imag; }
    //
public:
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

private:
    double real, imag;
    //
    friend bool operator< (const Kompleks& c1, const Kompleks& c2);	// ovdje se koristi friend jer je simetricna funkcija, usporedba bad dvima objektima
    friend bool operator> (const Kompleks& c1, const Kompleks& c2);
    friend std::istream& operator>> (std::istream& s, Kompleks& c1);	// a ovdje se koristi friend jer se drugacije nemoze napravit overload operatora >> klase istream

    //
private:
    friend std::ostream& operator<< (std::ostream& os, const Kompleks& c);
};

