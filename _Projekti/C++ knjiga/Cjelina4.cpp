#include "Cjelina4.hpp"

/// <summary>
///		Ispisuje povrsinu i opseg kruga
/// </summary>
void Cjelina4::zad1()
{
    Krug k(10);

    std::cout << "Povrsina: " << k.izracunajPovrsinu() << '\n';
    std::cout << "Opseg: " << k.izracunajOpseg() << '\n';
}

/// <summary>
///		Ispisuje udaljenost dvije tocke iz obadvije perspektive
/// </summary>
void Cjelina4::zad3()
{
        Tocka t1(1.0, 1.0);
        Tocka t2(4.0, 1.0);

        std::cout << "Udaljenost izmedu t1 i t2 = " << t1.Udaljenost(t2) << '\n';
        std::cout << "Udaljenost izmedu t2 i t1 = " << t2.Udaljenost(t1) << '\n';
}

/// <summary>
///		Ispisuje udaljenost dvije tocke postavljene sa metodom setTocka iz obadvije perspektive
/// </summary>
void Cjelina4::zad4()
{
        Tocka2 t1;
        Tocka2 t2;
        t1.setTocka(1, 1);
        t2.setTocka(1, 4);

        std::cout << "Udaljenost izmedu t1 i t2 = " << Udaljenost(t1, t2) << '\n';
        std::cout << "Udaljenost izmedu t2 i t1 = " << Udaljenost(t2, t1) << '\n';
}

/// <summary>
///		Ispisuje rjesenje kriptiranog izraza
/// </summary>
void Cjelina4::zad5()
{
    int i = 0, a = 2, b;

    while (i < 3) {
        std::cout << (i++ - a == (b = 0));
    }
}