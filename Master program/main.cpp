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
extern std::array<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>, popisProjekata.size()> popisImenaFunkcijaPoCjelinama;
//extern std::array<std::unordered_map<std::string, size_t>, popisProjekata.size()> popisImenaFunkcija;
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

	std::cout << "DOBRODOSAO!!\n"
		<< "Unesi broj za projekt iz cijeg zelis pokrenut funkciju:\n\n1) Cpp knjiga\n2) FESB\n3) Practical c++ programming\n4) ThinkLAP\n\n";
	char odabirProjekta;
	do
	{
		std::cin >> odabirProjekta;
		switch( odabirProjekta )
		{
		case '1': case '2': case '3': case '4':
			odabirProjekta -= '0' + 1;
			break;
		default:
			puts( "Krivi unos!!" );
			odabirProjekta = -1;
		}
	} while( odabirProjekta < 0 );
	std::cout << "\nOdabrao si projekt " << popisProjekata[odabirProjekta]
		<< "\n\Iz koje cjeline zelis pokrenut funkciju?\n\n";
	for( const auto& str : popisImenaFunkcijaPoCjelinama[odabirProjekta] )
		std::cout << str.first << '\n';
	std::cout << "\nTvoj odabir: ";
	std::string odabirCjeline;
	do
	{
		std::cin >> odabirCjeline;
		if( popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline ) == popisImenaFunkcijaPoCjelinama[odabirProjekta].end() )
		{
			puts( "Krivi unos!!!" );
		}
		else	break;
	} while( true );
	std::cout << "\nOdabrao si projekt " << popisProjekata[odabirProjekta] << " - " << odabirCjeline
		<< "\n\Izaberi jednu od ponudenih funkcija koju zelis pokrenut:\n";
	for( const auto& str : popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second )
	{
		puts( str.first.c_str() );
	}
	std::cout << "\nTvoj odabir: ";
	std::string odabirFunkcije;
	do
	{
		std::cin >> odabirFunkcije;
		if( popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije ) == popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
		{
			puts( "Krivi unos!!!" );
		}
		else	break;
	} while( true );
	auto iterID_funkcijeZaIzvrsit = popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije );
	if( iterID_funkcijeZaIzvrsit != popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
	{
		std::cout << "Pokrecem...\n";
		std::cout << "ID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second << '\n';
		popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second]();
	}
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
		//for( uint8_t idx = 0; idx < popisImenaFunkcija[projIdx].size(); ++idx )
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