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
/// OGRANICENJA:
/// - podrzava samo jedno linijske komentare za tekst zadataka
/// - funkcije koje te zanimaju moraju biti u namespaceu / 
///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse"
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TODO za napravit:
/// - citaj JSON datoteku u setup.cpp prilikom ucitavanja popisa
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - ucitavanje funkcija sa nazivima iz datoteke whitelist
/// - blokiranje funkcija sa nazivima iz datoteke blacklist
/// - podrzavanje viselinijskih komentara 
/// - dinamicki containeri za bilo kakvu konfiguraciju

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"

#include "ParseFile.hpp"

extern struct Zadatak;

extern void popuniCijeliPopisFunkcija();

static std::vector<std::string> popisProjekata;


///extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
//extern std::array<std::vector<std::string>, popisProjekata.size()> opisZadatka;
///extern std::vector<std::vector<void ( * )( )>> popisFunkcija;


namespace Master
{
	// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
	extern std::vector<std::vector<void ( * )( )>> popisFunkcija;

	void init();
	namespace _INTERNAL
	{
		nlohmann::json buildJSON_structure();
		void processZadatke( nlohmann::json& jsonData );
	}

}

void automatizirano();
void rucno();

/// ////////////////////////////////////////////////////////////////////////////////////////////////////
int main( const size_t args, const char* argv[] )
{
	Master::init();



	exit( EXIT_SUCCESS );
/// ////////////////////////////////////////////////////////////////////////////////////////////////////

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
	for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta] )
		std::cout << str.first << '\n';
	std::cout << "\nTvoj odabir: ";
	std::string odabirCjeline;
	do
	{
		std::cin >> odabirCjeline;
		if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline ) == Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].end() )
		{
			puts( "Krivi unos!!!" );
		}
		else	break;
	} while( true );
	std::cout << "\nOdabrao si projekt " << popisProjekata[odabirProjekta] << " - " << odabirCjeline
		<< "\n\Izaberi jednu od ponudenih funkcija koju zelis pokrenut:\n\n";
	for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second )
	{
		puts( str.first.c_str() );
	}
	std::cout << "\nTvoj odabir: ";
	std::string odabirFunkcije;
	do
	{
		std::cin >> odabirFunkcije;
		if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije ) == Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
		{
			puts( "Krivi unos!!!" );
		}
		else	break;
	} while( true );
	auto iterID_funkcijeZaIzvrsit = Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije );
	if( iterID_funkcijeZaIzvrsit != Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
	{
		std::cout << "\nID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second << '\n';
		std::cout << "Pokrecem...\n\n\n";
		Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second]();
	}

	return EXIT_SUCCESS;
/// ////////////////// //////////////////////// //////////////////////////////////////	////////////////////////////////////////////////
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



}
std::ofstream& operator << ( std::ofstream& dat, const Zadatak& zad )
{
	dat << "TEKST ZADATKA: " << zad.tekst << '\n'
		<< "DEKLARACIJA: " << zad.deklaracija << '\n'
		<< "KOD:\n" << zad.kod << '\n';
	return dat;
}
void Master::init()
{
	const auto dodajItemeUVektor = []( std::vector<std::string>& container, const char* fullPath )
		{
			for( const auto& entry : fs::directory_iterator( fullPath ) )
			{
				std::string pathToItems = entry.path().string();
				std::string::reverse_iterator itStart = pathToItems.rbegin();
				std::string::reverse_iterator itEnd;
				itEnd = std::find( itStart, pathToItems.rend(), '\\' );
				size_t itemNameLen = itEnd - itStart;
				std::string fileName( pathToItems.begin() + pathToItems.size() - itemNameLen, pathToItems.end() );
				container.push_back( fileName );
			}
		};

	std::cout << "DOBRODOSAO!!\n";
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ifstream JSON_datoteka( nazivJSONdat, std::ios::in );
	if( !JSON_datoteka.is_open() )
	{
		std::ofstream JSONdat( "dummy.json", std::ios::out );
		if( !JSONdat.is_open() )
		{
			std::cout << "Nisam mogao otvorit \"InformacijeOZadacima.json\" datoteku!"
				<< "\Izlazim...\n";
			exit( EXIT_FAILURE );
		}
		nlohmann::json jsonData = _INTERNAL::buildJSON_structure();

		// dodaj imena projekata u vektor
		dodajItemeUVektor( popisProjekata, "D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti" );

		std::vector<std::string> paths;
		// popuni pathove dinamicki sa svim projektima
		for( const auto& entry : fs::directory_iterator( "D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti" ) )
		{
			std::string pathToItems = entry.path().string();
			pathToItems += "\\FilesToParse\\";
			paths.push_back( std::move( pathToItems ) );
		}

		std::vector<std::vector<std::string>> imenaDatoteka;
		// popuni imena datoteka dinamicki sa svim datotekama na tom pathu
		{
			size_t idx = 0;
			for( const auto path : paths )
			{
				imenaDatoteka.push_back( {} );
				dodajItemeUVektor( imenaDatoteka[idx], path.data() );
				++idx;
			}
		}

		std::cout << "Parsing files...";
		std::vector<ParseFile> pfs;
		std::vector<Zadatak*> zadaci( paths.size() );
#define SPREMAN_ZA_SLJEDECI_KORAK true
#if SPREMAN_ZA_SLJEDECI_KORAK
		std::ofstream dat( "zadaci.dat", std::ios::out );
		if( !dat.is_open() )
		{
			std::cout << "Nisam mogao otvorit \"InformacijeOZadacima.json\" datoteku!"
				<< "\Izlazim...\n";
			exit( EXIT_FAILURE );
		}
		dat << "===================================================\n";
#endif
		for( size_t idx = 0; idx < paths.size(); ++idx )
		{
			puts( "\n--------------------------------------------" );
			pfs.push_back( ParseFile( paths[idx], imenaDatoteka[idx] ) );
			size_t idxOfFile = 0;
			for( const auto& fName : imenaDatoteka[idx] )
			{
				std::cout << fName;
				bool DEBUG_FLAG = false; /*	DEBUG_FLAG = fName == "Cjelina101.cpp"; */


				zadaci = std::move( pfs[idx].readFile( pfs[idx].getDatoteku( idxOfFile ), DEBUG_FLAG ) );
#if SPREMAN_ZA_SLJEDECI_KORAK
				for( const auto zadatak : zadaci )
				{
					dat << *zadatak << "--------------------------------\n";
				}
#endif
		// popuni JSON objekt kako parsira datoteke
				/// zadaci stizu po cjelinama u kojima se nalaze
				puts( "" );
				++idxOfFile;
			}
#if SPREMAN_ZA_SLJEDECI_KORAK
			dat << "====================================================\n";
#endif
		}
		puts( "\n--------------------------------------------" );
		std::cout << "\nDONE!\nRecompile the program to proceed to the next stage!\nExiting...\n";
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