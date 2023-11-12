#pragma once
#include <iostream>
#include "Kolegij.hpp"


class O_O_P : public Kolegij
{
public:
	O_O_P() : Kolegij("Objektno orijentirano programiranje", "Ivo Ivic") {
		satnicaPredavanja = 0;
		satnicaVjezbi = 0;
		for (int i = 0; i < 15; i++) {
			ocjenePredavanja[i] = 0;
			ocjeneVjezbi[i] = 0;
		}
	}
	int getSatnicuPredavanja();
	int getSatnicuVjezbi();
	int* getOcjenePredavanja();
	int* getOcjeneVjezbi();

	void setOcjenuPredavanja(int ocjena);	// pozivaju funkciju nadiSlobodanIndex,
	void setOcjenuVjezbi(int ocjena);	// koji nalazi prvi slobodan index za upisat ocjenu

	void setIspraljenaOcjenaPredavanja(int ocjena, int index); // ako je index (pozivom nadiSlobodanIndex funkcije)
	void setIspravljenaOcjenaVjezbe(int ocjena, int index);		// veci od broja upisanih ocjena, izadi iz funkcije

	void ispisiOcjenePredavanja() {
		for (int i = 0; i < 15; i++) {
			if (O_O_P::ocjenePredavanja[i] != 0)	std::cout << O_O_P::ocjenePredavanja[i] << '\n';
		}
	}

	void ispisiOcjeneVjezbi() {
		for (int i = 0; i < 15; i++) {
			if (O_O_P::ocjeneVjezbi[i] != 0)	std::cout << O_O_P::ocjeneVjezbi[i] << '\n';
		}
	}

private:
	int satnicaPredavanja,
		satnicaVjezbi,
		ocjenePredavanja[15],
		ocjeneVjezbi[15];

	int nadiSlobodanIndex(int ocjene[]);
};