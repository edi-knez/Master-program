#include <cstdlib>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#include <set>
#include <unordered_map>
#include <deque>

extern enum class projekt;

static std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
extern std::array<std::vector<std::string>, popisProjekata.size()> popisImenaFunkcija;
extern std::array<std::vector<std::string>, popisProjekata.size()> opisZadatka;

extern void test();


void automatizirano();
void rucno();

int main( char args, char* argv[] )
{

	//test();
	return EXIT_SUCCESS;

	char odabir = 0;
	while( odabir != 'a' && odabir != 'r' )
	{
		std::cout << "Ako želis automatizirat proces unesi znak \"a\", a ako želiš ruèno unosit informacije unesi \"r\" ";
		std::cin >> odabir;
		odabir = tolower( odabir );
	}

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
			std::cout << opisZadatka[projIdx][idx]
				<< '\n'
				<< popisImenaFunkcija[projIdx][idx];
		}
		};

	ispisiPopisProjekata();
	//ispisiPopisFunkcija();
	//ispisiPopisParametara();
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
			std::cout << "You are not supposed to be here";
			exit( 1 );

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
	//ispisi listu projekata
	//unesi odabir projekta
	//ispisi cjeline/poglavlja funkcija, ispisi opis poglavlja?
	//unesi odabir cjeline/poglavlja
	//ispisi popis funkcija i njihov opis
	//unesi odabir funkcije za pokrenut
}