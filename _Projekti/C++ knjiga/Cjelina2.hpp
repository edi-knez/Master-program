#pragma once
#include <iostream>


/// <summary>
///		Sadrzi zadatke koje se traze u cjelini2.
///		zad1 - zad6
/// 
///		overloadi metode ispis se koriste u zad1
/// 
///		Klasa krug sadrzi default konstruktora za inicijalizaciju, postavljanje radijusa i racunanje povrsine
/// 
///		Klasa Razlomak sadrzi sadrzi default konstruktora za inicijalizaciju, metodu za postavljanje vrijednosti brojnika i nazivnika te metodu za racunanje decimalne vrijedosti
/// </summary>
class Cjelina2
{
public:
    void zad1();
    void zad2();
    void zad3();
    void zad4();
    void zad5();
    void zad6();

private:
    void ispis(int lr);
    void ispis(double lrDouble);
    //

public:
    class Krug {
    public:
        Krug() { m_radijus = 0.0; }

    public:
        double Povrsina() { return 3.14 * m_radijus * m_radijus;    }
    
    public:
        double getRadijus() { return m_radijus; }
        //void setRadijus(double radijus) {
        //    m_radijus = radijus;
        //}
        void SetRadijus(double tempR) 
        {
            if (tempR >= 0.0) { m_radijus = tempR; }
            else { std::cout << "GRESKA! Radijus ne moze biti negativan!!" << '\n'; }
        }

        void operator=(double x);

    //public:
    private:
        double m_radijus;
    };

    //
    class Razlomak {
    public:
        Razlomak() : brojnik(0), nazivnik(0) {}

    public:
        bool Set(int tempBr, int tempNz) {
            if (tempNz != 0) {
                brojnik = tempBr;
                nazivnik = tempNz;
                return 1;
            }
            else {
                std::cout << "Greska! Nazivnik nesmije biti 0!";
                return 0;
            }
        };
        double GetDecimal() { return static_cast<double>(brojnik) / static_cast<double>(nazivnik); }

    private:
        int brojnik;
        int nazivnik;
    };
};




