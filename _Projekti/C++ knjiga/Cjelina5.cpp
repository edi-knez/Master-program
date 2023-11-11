#include "Cjelina5.h"

void Cjelina5::zad2()
{
	Krug* k = new Krug();
	if (k->SetRadijus(1.0))
	{
		std::cout << "Povrsina: " << k->izracunajPovrsinu() << '\n';
		std::cout << "Opseg: " << k->izracunajOpseg() << '\n';
	}
	else { std::cout << "Greska\n"; }
	if (k->SetRadijus(-1.0))
	{
		std::cout << "Povrsina: " << k->izracunajPovrsinu() << '\n';
		std::cout << "Opseg: " << k->izracunajOpseg() << '\n';
	}
	else { std::cout << "Greska pri unosu radijusa\n"; }

	delete k;
}

void Cjelina5::zad3()
{
	KlNiz kn1;

	for (int i = 0; i < 10; i++) {
		std::cout << "A[ " << i << "] = " << kn1[i] << '\n';
	}
	std::cout << "suma niza: " << kn1.sumaNiza() << '\n';
}