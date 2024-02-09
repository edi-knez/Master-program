/// za napravit:
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - JSON datoteka koja sadrzi sve informacije
/// - citaj JSON datoteku u setup.cpp prilikom ucitavanja popisa

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#include <set>
#include <unordered_map>
#include <deque>

extern enum class projekt;

extern void popuniCijeliPopisFunkcija();

static std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
extern std::array<std::unordered_map<std::string, size_t>, popisProjekata.size()> popisImenaFunkcija;
//extern std::array<std::vector<std::string>, popisProjekata.size()> opisZadatka;
extern std::array<std::vector<void ( * )( )>, popisProjekata.size()> popisFunkcija;

extern void test();

namespace Master
{
	void init() 
	{
		popuniCijeliPopisFunkcija();
		for( auto& vec : popisFunkcija )	vec.shrink_to_fit();
	}
}

void automatizirano();
void rucno();


int main( const size_t args, const char* argv[] )
{
	Master::init();

	auto iterID_funkcijeZaIzvrsit = popisImenaFunkcija[0].find( "cj2.zad4" );
	if( iterID_funkcijeZaIzvrsit != popisImenaFunkcija[0].end() )
	{
		std::cout << "ID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second << '\n';
		popisFunkcija[0][iterID_funkcijeZaIzvrsit->second]();
	}
	//popisFunkcija[2][ID_funkcijeZaIzvrsit->]();
	//test();

	return EXIT_SUCCESS;

	char odabir = 0;
	while( odabir != 'a' && odabir != 'r' )
	{
		std::cout << "Ako želis automatizirat proces unesi znak \"a\", a ako želiš ruèno unosit informacije unesi \"r\" ";
		std::cin >> odabir;
		odabir = tolower( odabir );
	}

	bool wantToContinue = true;
	while( wantToContinue )
	{
		switch( odabir )
		{
		case 'a':
			automatizirano();
			break;
		case 'r':
			// otvori GUI
			rucno();
			break;
		default:
			std::cout << "Krivi unos! Izlazim...";
			exit( EXIT_FAILURE );
		}
	}

	return EXIT_SUCCESS;
}

void automatizirano()
{
	// 3 opcije:
	// koristi argumente ako su dostupni
	// procitaj iz datoteke inpute
	// pitaj korisnika da unese sve potrebne infromacije za zeljenu funkciju
	/// extra:
	// korisnik moze memorirat unos u datoteku
	// korisnik moze memorirat unos u unordered_map
	/// extra2:
	// korisnik unosi imena datoteka koje zeli testirat u argumente programa

	//proslijedi input kako bi se izvrsila zeljena funkcija
}

void rucno()
{
	auto ispisiPopisProjekata = []() {
		uint8_t i = 1;
		for( const std::string_view strView : popisProjekata )
		{
			std::cout << i++ << ". " << strView << '\n';
		}
		};
	auto ispisiPopisFunkcijaZa = []( const enum class projekt proj ) {
		uint8_t projIdx = static_cast<uint8_t>( proj );
		for( uint8_t idx = 0; idx < popisImenaFunkcija[projIdx].size(); ++idx )
		{
		//	std::cout << opisZadatka[projIdx][idx]
			//	<< '\n'
			//<< popisImenaFunkcija[projIdx][idx];
		}
		};
	int tempOdabir;
	auto resetVarijabluZaOdabir = [ & ]() {
		tempOdabir = -1;
		};


	ispisiPopisProjekata();
	//unesi odabir projekta
	projekt mojegaIzbora;
	resetVarijabluZaOdabir();
	while( tempOdabir < 0 || tempOdabir > popisProjekata.size() )	std::cin >> tempOdabir;
	mojegaIzbora = static_cast<projekt>( tempOdabir );

	//ispisi popis funkcija i njihov opis
	ispisiPopisFunkcijaZa( mojegaIzbora );
	//ispisi cjeline/poglavlja funkcija, ispisi opis poglavlja?
	resetVarijabluZaOdabir();
	while( tempOdabir < 0 || tempOdabir > popisProjekata.size() )	std::cin >> tempOdabir;
	//unesi odabir cjeline/poglavlja
	resetVarijabluZaOdabir();
	//unesi odabir funkcije za pokrenut
}