#include "Cjelina10.hpp"

void Cjelina10::zad1()
{
    /*   LP* a = new LP;
   CD* b = new CD;
   DVD* c = new DVD;

   a->ispis();
   b->ispis();
   c->ispis();

   delete a, b, c;*/

    LP* a = new LP;
    CD* b = new CD;
    DVD* c = new DVD;
    Ploca* A[3];

    A[0] = a;
    A[1] = b;
    A[2] = c;

    for (int i = 0; i < 3; i++) {
        A[i]->_ispisi();
    }

    delete A[0], A[1], A[2];
}

void Cjelina10::zad2()
{
    Roditelj* a = new Roditelj("Janko", 1);
    Dijete* b = new Dijete("Ana", true);
    Clan_obitelji* c[2];

    c[0] = a;
    c[1] = b;

    for (int i = 0; i < 2; i++)  c[i]->_ispis();

    for (int i = 0; i < 2; i++)  delete c[i];

}