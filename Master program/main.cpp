////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UPOTREBA:
/// 1)  Konstruiraj pf objekt sa potrebnim informacijama u funkciji init unutar namespace Master.
/// 2)  Kompajlaj program (stvorit ce JSON datoteku)
/// 3)  Da bi mogao pokrenut funkcije iz tih datoteka, kompajlaj opet
/// 4)  Pokreni program
/// ////////////////////////////////////////////////////////////////
/// nakon toga ako zelis promijenit (dodat/uklonit) datoteke iz kojih citas informacije o funkcijama, moras ponovit cijeli postupak
/// ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// RAZLOG:
/// da bi se automatizirao postupak, ParserFile klasa se ucitat sve informacije o funkcijama, te ce dodat sva imena funkcija u "Functions.cpp" datoteku 
/// za koju je potrebna jos jedna kompilacija da bi mogao koristit funkcionalnosti koju si dodao
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// za napravit:
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - JSON datoteka koja sadrzi sve informacije
/// - citaj JSON datoteku u setup.cpp prilikom ucitavanja popisa

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"

#include "ParseFile.h"

extern enum class projekt {};

extern void popuniCijeliPopisFunkcija();

static std::vector popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
//extern std::array<std::vector<std::string>, popisProjekata.size()> opisZadatka;
extern std::vector<std::vector<void ( * )( )>> popisFunkcija;


namespace Master
{
	void init()
	{
		std::cout << "DOBRODOSAO!!\n";
		std::string nazivJSONdat = "InformacijeOZadacima.json";
		std::ifstream JSON_dat( nazivJSONdat, std::ios::in );
		if( !JSON_dat.is_open() )
		{
			//std::ofstream dat( "InformacijeOZadacima.json", std::ios::out );
			//nlohmann::json a;
			//a["test"] = 5;

			std::vector<std::string_view> paths =
			{
				"D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti",
				"D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti",
				"D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti",
				"D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti"
			};

			std::vector<std::vector<std::string>> imenaDatoteka;
			{
				size_t idx = 0;
				for( const auto path : paths )
				{
					imenaDatoteka.push_back( {} );
					for( const auto& entry : fs::directory_iterator( path ) )
					{
						std::string pathToFile = entry.path().string();
						size_t fileNameLen = 0;
						while( pathToFile[pathToFile.size() - 1 - fileNameLen++] != '\\' ) {}
						std::string fileName( pathToFile.begin() + pathToFile.size() - fileNameLen, pathToFile.end() );
						imenaDatoteka[idx].push_back( fileName );
					}
					++idx;
				}
			}

			std::cout << "Parsing files...\n";
			for( size_t idx = 0; idx < paths.size(); ++idx )
			{
				ParseFile pf( paths, imenaDatoteka[idx] );
				for( const auto& fName : imenaDatoteka )
				{
			//		pf.readFile();
			// popuni JSON objekt i Functions.cpp kako parsira datoteke

				}

			}
			std::cout << "\n\nRecompile the program to proced to the next stage!\nExiting...\n";
			exit( EXIT_SUCCESS );
		}
		else
		{
			std::cout << "Ako zelis nastavit sa trenatacnom verzijom upisi broj 1, inace 0: ";
			char odabir;
			std::cin >> odabir;
			if( odabir == '1' )
			{
				for( size_t i = 0; i < popisProjekata.size(); ++i )
				{
					popisImenaFunkcijaPoCjelinama.push_back( {} );
					popisFunkcija.push_back( {} );
				}
				popuniCijeliPopisFunkcija();
				for( auto& vec : popisFunkcija )	vec.shrink_to_fit();
			}
			else if( odabir == '0' )
			{
				std::cout << "Pravim kopiju JSON datoteke i brisem je!\n";
				std::cout << "Da bi primjenio promjene, rekompaliraj program\n";
				auto copy_file = []( std::ifstream& copyFrom, std::ofstream& copyTo )
					{
						std::stringbuf buf;
						char c;
						while( copyFrom >> c )
						{
							buf.sputbackc( c );
						}
						for( const char c : buf.str() )
						{
							copyTo.put( c );
						}
					};
				std::ifstream curJSON( nazivJSONdat, std::ios::in );
				std::ofstream backup( nazivJSONdat + ".bak", std::ios::out );
				if( !curJSON.is_open() || !backup.is_open() )
				{
					std::cout << "Nemogu zavrsit postupak!!\n"
						<< "Ako problem je i dalje tu, obrisi JSON datoteku rucno\n\n";
				}
				copy_file( curJSON, backup );
				std::remove( nazivJSONdat.c_str() );
				exit( EXIT_SUCCESS );
			}
		}
	}
}

void automatizirano();
void rucno();


int main( const size_t args, const char* argv[] )
{
	Master::init();

	std::cout << "Unesi broj za projekt iz cijeg zelis pokrenut funkciju:\n";
	{
		size_t idx = 1;
		for( const auto proj : popisProjekata )
			std::cout << idx++ << ") " << proj << '\n';
		puts( "" );
	}
	char odabirProjekta = 0;
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
		<< "\n\Izaberi jednu od ponudenih funkcija koju zelis pokrenut:\n\n";
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
		std::cout << "\nID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second << '\n';
		std::cout << "Pokrecem...\n\n\n";
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