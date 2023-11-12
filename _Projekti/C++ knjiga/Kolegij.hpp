#pragma once
#include <string>

class Kolegij
{
public:
	Kolegij(std::string imeK, std::string pred) : imeKolegija(imeK), predavac(pred), ukupnaOcjena(0) {};
	std::string_view getImeKolegija();
	std::string_view getImePredavaca();
	double getUkupnuOcjenu();

protected:
	std::string imeKolegija,
		predavac;

	double ukupnaOcjena;

};