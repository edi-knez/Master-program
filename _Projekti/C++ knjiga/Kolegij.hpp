#pragma once
#include <string>

/// <summary>
///		Ova klasa sluzi za prikazivanje tko je predavac za pojedini kolegij, koji kolegij predaje i koju konacnu ocjenu imas
/// </summary>
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