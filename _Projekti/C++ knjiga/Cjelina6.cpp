#include "Cjelina6.hpp"

static double rekurzija(int potencija, double baza);

void Cjelina6::zad1()
{
    using std::cout;
    Kompleks a(6.6, 4.7);
    Kompleks b(2.6, 3.4);

    Kompleks c;

    cout << "a = " << a.getReal() << " + i * " << a.getImag() << '\n';
    cout << "b = " << b.getReal() << " + i * " << b.getImag() << '\n';

    c = a + b;

    cout << "c = a + b" << '\n';
    cout << "c = " << c.getReal() << " + i * " << c.getImag() << '\n';

    c = a - b;

    cout << "c = a - b" << '\n';
    cout << "c = " << c.getReal() << " + i * " << c.getImag() << '\n';
}

void Cjelina6::zad2()
{
    using std::cout; using std::cin;
    Kompleks a, b;

    cout << "Upisite 2 kompleksna broja (dva para vrijednosti): " << '\n';

    cin >> a;
    cin >> b;

    cout << "Upisali ste brojeve" << '\n';
    cout << "a = " << a.getReal() << " + i * " << a.getImag() << '\n';
    cout << "b = " << b.getReal() << " + i * " << b.getImag() << '\n';

    if (a < b) {
        cout << "a je manji od b!" << '\n';
    }
    else {
        cout << "a je veci ili jednak c!" << '\n';
    }

    Kompleks c;

    c = a;

    cout << "c = " << c.getReal() << " + i * " << c.getImag() << '\n';

    c.setReal(3.0);
    cout << "c = " << c.getReal() << " + i * " << c.getImag() << '\n';

    if (c > a) {
        cout << "c je veci od a!" << '\n';
    }
    else {
        cout << "c je manji ili jednak a!" << '\n';
    }

    c += a;
    cout << "c = " << c.getReal() << " + i * " << c.getImag() << '\n';
}

void Cjelina6::zad3()
{
    using std::cout;

    int arr[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 1, 2, 3, 4, 5, 6 };
    //iarray d;
    iarray i1{};
    iarray i2(arr, 5);
    iarray i3(i2);

    cout << "i1:\t" << i1.size() << '\n';
    cout << "i2:\t" << i2.size() << '\n';
    cout << "i3:\t" << i3.size() << '\n';

    i3 += 2;
    i2 += 5;
    cout << "i2:\t" << i2.size() << '\n';
    cout << "i3:\t" << i3.size() << '\n';

    i3 = iarray(arr2, 6);
    std::cout << "i3:\t" << i3.size() << '\n';
}

void Cjelina6::zad4()
{
    int i = 0;
    int p;
    double b, r;

    std::cout << "Upisi bazu: ";
    std::cin >> b;
    std::cout << "Upisi potenciju: ";
    std::cin >> p;

    r = rekurzija(p, b);

    std::cout << b << " na " << p << " je: " << r << '\n';
}

//
double rekurzija(int potencija, double baza) {

    if (potencija == 0) {
        return 1;
    }
    else {
        if (potencija > 0)
            return baza * rekurzija(potencija - 1, baza);
        else {
            return ((1 / baza) * rekurzija(potencija + 1, baza));
        }
    }
}
