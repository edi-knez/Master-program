#include "Cjelina2.hpp"

/// <summary>
///		ispisi integer
/// </summary>
/// <param name="lr">integer koji zelis ispisat</param>
void Cjelina2::ispis(int lr) { std::cout << "(int funkcija): " << lr << '\n'; }

/// <summary>
///		Ispisi double
/// </summary>
/// <param name="lrDouble">double koji zelis ispisat</param>
void Cjelina2::ispis(double lrDouble) { std::cout << "(double funkcija): " << lrDouble << '\n'; }

void Cjelina2::Krug::operator=(double x) { this->m_radijus = x; }

/// <summary>
///		Provjeri hoce li se pozvat pravi overload
/// </summary>
void Cjelina2::zad1()
{
    int r;
    double rDouble;

    r = 2;
    rDouble = 2.7;

    ispis(r);
    ispis(rDouble);
}

/// <summary>
///		testiraj setRadijus metodu
/// </summary>
void Cjelina2::zad2()
{
    Krug k;
    Krug* k2 = new Krug;
    double d;

    d = 1.3;
    k.SetRadijus(d);
    k = d;

    std::cout << "Radijus kruga: " << k.getRadijus() << '\n';
    delete k2;
}

/// <summary>
///		Testiraj setRadijus metodu sa vise vrijednosti i ispisi povrsinu pripadajucih krugova
/// </summary>
void Cjelina2::zad3()
{
    using std::cout;
    Krug k1;
    Krug k2;
    double d;
    Krug k3;
    //k3.radijus = 2;
    k3.SetRadijus(2);
    Krug k4;
    //k4.radijus = -2;
    k4.SetRadijus(-2);
    cout << "Upisite radijus prvog kruga: ";
    std::cin >> d;
    //k1.radijus = d;
    k1.SetRadijus(d);
    cout << "Upisi radijus drugog kruga: ";
    std::cin >> d;
    //k2.radijus = d;
    k2.SetRadijus(d);

    cout << "Povrsina prvog kruga: " << k1.Povrsina() << std::endl;
    cout << "Povrsina drugog kruga " << k2.Povrsina() << std::endl;
    cout << "Povrsina 3. kruga: " << k3.Povrsina() << std::endl;
    cout << "Povrsina 4. kruga " << k4.Povrsina() << std::endl;

}

/// <summary>
///		Opet ispisi radijus i povrsinu kruga
/// </summary>
void Cjelina2::zad4()
{
    using std::cout;
    Krug k1;
    double d;
    cout << "Upisi radijus kruga: ";
    std::cin >> d;
    k1.SetRadijus(d);
    cout << "Radijus kruga je:\t" << k1.getRadijus() << std::endl;
    cout << "Povrsina kruga je:\t" << k1.Povrsina() << std::endl;
}

/// <summary>
///		Ispisi decimalnu vrijednost razlomka ako je vazeci
/// </summary>
void Cjelina2::zad5()
{
    Razlomak raz;
    int br, nz;
    std::cout << "Upisi Brojnik pa nazivnik: ";
    std::cin >> br >> nz;

    if (raz.Set(br, nz))
        std::cout << "Vrijednost razlomka je: " << raz.GetDecimal() << '\n';
    
}

/// <summary>
///		Ispisi string, promijeni mu vrijednost pa opet ispisi te mu ispisi broj znakova koje sadrzi
/// </summary>
void Cjelina2::zad6()
{
    std::string naziv = "Objektno orijentirano programiranje";
    std::string noviStr;
    std::cin >> noviStr;
    std::cout << '\n' << naziv << '\n';
    naziv = noviStr;
    std::cout << naziv << '\n';

    std::cout << "duljina stringa je: " << naziv.length() << '\n';
}