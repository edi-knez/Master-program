#include "../Cjelina10.hpp"

/// <summary>
///		U ovom testu se koriste izvedene klase pomocu heap memorije koje se pristupaju pomocu base klase pointera
/// </summary>
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

	delete a, b, c;
}

/// <summary>
///		U ovom testu se takoder pristupa objektima pomoce base klase pointera za koristenje metode ispisa, a i brisanja heap memorije
/// </summary>
void Cjelina10::zad2()
{
    Roditelj* a = new Roditelj("Janko", 1);
    Dijete* b = new Dijete("Ana", true);
    Clan_obitelji* c[2];

    c[0] = a;
    c[1] = b;

    for (int i = 0; i < 2; i++)  c[i]->_ispis();

    delete a, b;

}