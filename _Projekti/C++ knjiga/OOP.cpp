#include "OOP.hpp"


int O_O_P::getSatnicuPredavanja() {
	return satnicaPredavanja;
}

int O_O_P::getSatnicuVjezbi() {
	return satnicaVjezbi;
}

int* O_O_P::getOcjenePredavanja() {
	return ocjenePredavanja;
}

int* O_O_P::getOcjeneVjezbi() {
	return ocjeneVjezbi;
}

void O_O_P::setOcjenuPredavanja(int ocjena) {
	int index = O_O_P::nadiSlobodanIndex(O_O_P::ocjenePredavanja);

	O_O_P::ocjenePredavanja[index] = ocjena;
}


void O_O_P::setOcjenuVjezbi(int ocjena) {
	int index = O_O_P::nadiSlobodanIndex(O_O_P::ocjeneVjezbi);

	O_O_P::ocjeneVjezbi[index] = ocjena;
}

void O_O_P::setIspraljenaOcjenaPredavanja(int ocjena, int index) {
	int checkIndex = O_O_P::nadiSlobodanIndex(ocjenePredavanja);
	if (index > checkIndex) {
		std::cout << "GRESKA\nPogresna vrijednost indexa!\n";
	}
	else {
		O_O_P::ocjenePredavanja[index] = ocjena;
	}
}

void O_O_P::setIspravljenaOcjenaVjezbe(int ocjena, int index) {
	int checkIndex = O_O_P::nadiSlobodanIndex(ocjeneVjezbi);
	if (index > checkIndex) {
		std::cout << "GRESKA!\nPogresna vrijednost indexa!\n";
	}
	else {
		O_O_P::ocjeneVjezbi[index] = ocjena;
	}
}

int O_O_P::nadiSlobodanIndex(int ocjene[]) {
	int i = 0;
	for (; i < 15; i++) {
		if (ocjene[i] == 0) { return i; }
		else if (ocjene[15] != 0) {
			std::cout << "GRESKA!\nNema prostora za ocjenu\nKraj programa!\n";
			exit(1);
		}
	}
        return i;
}