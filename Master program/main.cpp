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

extern enum class projekt {};

extern void popuniCijeliPopisFunkcija();

static std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
extern std::array<std::vector<std::string>, popisProjekata.size()> popisImenaFunkcija;
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

int main( char args, char* argv[] )
{
	Master::init();
	//popisFunkcija[0][0]();
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
			rucno();
			break;
		default:
			std::cout << "Krivi unos! Izlazim...";
			exit( EXIT_FAILURE );
		}
	}
	// zadnji zad iz 1. datoteke
	//zad4();

	// VJEZBE 7
	//aazad1();
	//aazad2();
	//aazad3();
	//aazad4();

	// VJEZBE 8
	//abzad1();
	//abzad2();
	//abzad3();
	//abzad4();
	//abzad5();
	//abzad6();

	// VJEZBE 9
	//aczad1();
	//aczad2();
	//aczad3();

	// VJEZBE 10
	//adzad1();
	//adzad2();
	//adzad3();
	//adzad4();

	// VJEZBE 11
	//aezad1();
	//aezad2();
	//aezad3();
	//aezad4();

	// VJEZBE 12
	//afzad1();
	//afzad2();
	//afzad3();
	//afzad4();

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

	ispisiPopisProjekata();
	//unesi odabir projekta
	projekt mojegaIzbora;
	int tempOdabir = -1;
	while( tempOdabir < 0 || tempOdabir > popisProjekata.size() )	std::cin >> tempOdabir;
	mojegaIzbora = static_cast<projekt>( tempOdabir );

	//ispisi popis funkcija i njihov opis
	ispisiPopisFunkcijaZa( mojegaIzbora );
	//ispisi cjeline/poglavlja funkcija, ispisi opis poglavlja?
	tempOdabir = -1;
	while( tempOdabir < 0 || tempOdabir > popisProjekata.size() )	std::cin >> tempOdabir;
	//unesi odabir cjeline/poglavlja
	//unesi odabir funkcije za pokrenut
}