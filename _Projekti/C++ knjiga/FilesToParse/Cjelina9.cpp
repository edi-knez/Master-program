#include "../Cjelina9.hpp"

void Cjelina9::zad1()
{
    using std::cin; using std::cout; using std::string; using std::list;
    string str;
    list<string> lst;
    list<string>::const_iterator it;

    std::ofstream izlaz("lista.txt");

    cin >> str;
    while (str != "kraj") {
        lst.push_back(str);
        cin >> str;
    }

    cout << '\n';
    izlaz << "Lista:\n";

    for (it = lst.begin(); it != lst.end(); it++) {
        cout << *it << '\n';
        izlaz << *it << '\n';
    }
    cout << '\n';
    izlaz << '\n';

    lst.reverse();
    izlaz << "Obrnuto:\n";
    for (it = lst.begin(); it != lst.end(); it++) {
        izlaz << *it << '\n';
        cout << *it << '\n';
    }

    izlaz.close();
}

void Cjelina9::zad2()
{
    using std::vector; using std::cout;
    int a;
    vector<int> v;
    vector<int>::iterator iter;

    std::cin >> a;
    while (a != 0) {
        v.push_back(a);
        std::cin >> a;
    }
    cout << '\n';

    sort(v.begin(), v.end());

    iter = find(v.begin(), v.end(), 55);
    if (iter != v.end()) {
        cout << "iter: " << *iter << '\n';
    }
    else {
        cout << "Not found!\n";
    }

    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << '\n';
    }
}

void Cjelina9::zad3()
{
    LP* a = new LP;
    CD* b = new CD;
    DVD* c = new DVD;

    a->_ispisi();
    b->_ispisi();
    c->_ispisi();

    delete a, b, c;

    MP3CD d;
    d._ispisi();
}

void Cjelina9::zad4()
{
    using std::cout;
    Tocka2D t1(1, 1);
    cout << t1.getX() << ", " << t1.getY() << '\n';

    Tocka3D t11(2, 2, 2);
    cout << "t11" << t11 << '\n';

    Tocka3D t12(-2, -2, -2);
    cout << "t12" << t12 << '\n';

    cout << "t11" << t11 << " == t12" << t12 << ": " << t11.operator==(t12) << '\n';

    /* t12.setX(2);
     t12.setY(2);
     t12.setZ(2);*/

    std::cout << "t12 = t11\n";
    t12 = t11;
    cout << "t12" << t12 << '\n';
    cout << "t11" << t11 << " == t12" << t12 << ": " << (t11 == t12) << '\n';

    t12.setZ(3);
    cout << "t12" << t12 << '\n';
    cout << "t11" << t11 << " == t12" << t12 << ": " << (t11 == t12) << '\n';

}

void Cjelina9::zad6()
{
    O_O_P o1;

    o1.setOcjenuPredavanja(4);
    o1.setIspraljenaOcjenaPredavanja(5, 0);
    o1.ispisiOcjenePredavanja();
}
