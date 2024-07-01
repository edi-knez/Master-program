////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UPOTREBA:
/// 1)  Stavi datoteke koje zelis testirat na lokaciju ".../Projekti/imeProjekta/FilesToParse/"
/// 2)  Kompajlaj program (stvorit ce JSON datoteku)
/// 3)  Pokreni program
/// ////////////////////////////////////////////////////////////////
/// nakon toga ako zelis promijenit (dodat/uklonit) datoteke iz kojih citas informacije o funkcijama, moras ponovit cijeli postupak
/// ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OGRANICENJA:
/// - podrzava samo jedno linijske komentare za tekst zadataka
/// - funkcije koje te zanimaju moraju biti u namespaceu / 
///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse"
/// - funkcije moraju imat povratni tip "void" (trenutacno)
/// - nepodrzava template funkcije
/// - nepodrzava vise nivoa namespace-a (pr: void namespace1::namespace2::imeFunk() ) za ucitanje deklaracije funkcije
/// - nepodrzava razne kljucne rijeci u deklaraciji funkcija ( const, static, noexcept, constexpr, [[likely]], ... )
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TODO za napravit:
/// - citaj JSON datoteku u setup.cpp prilikom ucitavanja popisa
/// - ucitavanje funkcija sa nazivima iz datoteke whitelist
/// - blokiranje funkcija sa nazivima iz datoteke blacklist
/// - podrzavanje viselinijskih komentara 
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - spawnanje zadataka na novom threadu
/// - vremenski ogranicit izvrsavanje zadatka
/// - dinamicki containeri za bilo kakvu konfiguraciju
/// - dodaj polje u json datoteku za ime datoteke iz koje se procita zadatak (u datoteci moze bit zadataka sa razlicitim namespace-ima)
/// - pogledaj iznad ove odjelka popis ogranicenja

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"
using namespace nlohmann;

#include "ParseFile.hpp"

extern struct Zadatak;

extern void popuniCijeliPopisFunkcija();




namespace Master
{
	std::vector<std::string> popisProjekata;
		// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
	extern std::vector<std::vector<void ( * )( )>> popisFunkcija;

	void init();
	void a();
	namespace _INTERNAL
	{
		json::object_t processZadatke( nlohmann::json::object_t& jsonData, std::vector<Zadatak*>& zadaci );
	};

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
		for( const auto proj : Master::popisProjekata )
			std::cout << idx++ << ") " << proj << '\n';
		puts( "" );
	}
	char odabirProjekta = 0;
	do
	{
		std::cin >> odabirProjekta;

		if ( ( odabirProjekta -= '0' ) < Master::popisProjekata.size() )
		{
			odabirProjekta += 1;	// pocinje od rednog broja 1, a ne od broja 0
			break;
		}
		else
		{
			puts( "Krivi unos!!" );
			odabirProjekta = -1;
		}
	} while( odabirProjekta < 0 );
	std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta]
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
	std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << " - " << odabirCjeline
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
	std::cout << "DOBRODOSAO!!\n";
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ifstream JSON_datoteka( nazivJSONdat, std::ios::in );
	if( !JSON_datoteka.is_open() )
	{
		a();
	}
	else
	{
		std::cout << "Ako zelis nastavit sa trenatacnom verzijom upisi broj 1, inace 0: ";
		char odabir;
		std::cin >> odabir;
		if( odabir == '1' )
		{
			for( size_t i = 0; i < Master::popisProjekata.size(); ++i )
			{
				popisImenaFunkcijaPoCjelinama.push_back( {} );
				popisFunkcija.push_back( {} );
			}
			popuniCijeliPopisFunkcija();
			for( auto& vec : popisFunkcija )	vec.shrink_to_fit();
		}
		else if( odabir == '0' )
		{
			/// // popuni datoteku Functions.cpp iz JSON objekta
			a();
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

void Master::a()
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
				container.emplace_back( fileName );
			}
		};

	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ifstream JSON_existingDatoteka( nazivJSONdat, std::ios::in  );	// ************** pogledaj ova 2 ifa ( kako handle-at ako nemoze otvorit json datoteku?? )
	if( !JSON_existingDatoteka.is_open() )
	{
		std::ofstream JSON_newDatoteka( nazivJSONdat, std::ios::out );
		if( !JSON_newDatoteka.is_open() )
		{
			std::cout << "Nisam mogao otvorit \"InformacijeOZadacima.json\" datoteku!"
				<< "\Izlazim...\n";
			exit( EXIT_FAILURE );
		}
		
		nlohmann::json jsonData;
		json::array_t nizProjekata = json::array();
		std::vector<json::object_t> imeProjekta{};

		// dodaj imena projekata u vektor
		dodajItemeUVektor( Master::popisProjekata, "_Projekti" );

		std::vector<std::string> paths;
		{
			// popuni pathove dinamicki sa svim projektima
			uint32_t idx = 0;
			for( const auto& entry : fs::directory_iterator( "_Projekti" ))
			{
				std::string pathToItem = entry.path().string();
				imeProjekta.push_back({});
				imeProjekta[idx][Master::popisProjekata[idx]]["pathToProj"] = pathToItem;
				++idx;
				pathToItem += "\\FilesToParse\\";
				paths.push_back( std::move( pathToItem ));
			}
		}
		
		std::vector<std::vector<std::string>> imenaDatoteka;
		// popuni imena datoteka dinamicki sa svim datotekama na tom pathu
		{
			size_t idx = 0;
			for( const auto path : paths )
			{
				imenaDatoteka.push_back( {} );
				///TODO: dodaj kod za unosenje imena datoteka u json 
				dodajItemeUVektor( imenaDatoteka[idx], path.data() );
				++idx;
			}
		}
		std::cout << "Parsing files...";
		std::vector<ParseFile> pfs;
		std::vector<Zadatak*> zadaci( paths.size() );
#define SPREMAN_ZA_SLJEDECI_KORAK false		// kod ispravno radi, sacuvano radi lakseg debugiranja u buducnosti
#if SPREMAN_ZA_SLJEDECI_KORAK
		std::ofstream dat( "zadaci.dat", std::ios::out );
		if( !dat.is_open() )
		{
			std::cout << "Nisam mogao otvorit \"zadaci.dat\" datoteku!"
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
			nizProjekata.emplace_back( nlohmann::json::object_t() );
			for( const auto& fName : imenaDatoteka[idx] )
			{
				std::cout << fName;
				bool DEBUG_FLAG = false; /*	DEBUG_FLAG = fName == "Cjelina101.cpp"; */


				zadaci = std::move( pfs[idx].readFile( pfs[idx].getDatoteku( idxOfFile ), DEBUG_FLAG ) );

				/// zadaci stizu po cjelinama u kojima se nalaze
				puts( "" );
				++idxOfFile;

					// popuni JSON objekt kako parsira datoteke
				json::object_t zadaciCjeline = Master::_INTERNAL::processZadatke( imeProjekta[idx], zadaci);
				imeProjekta[idx][Master::popisProjekata[idx]]["Broj cjeline"].emplace_back( zadaciCjeline );
				nizProjekata[idx] = imeProjekta[idx];
			//		jsonData["projekt"] = nizProjekata;
			//		std::clog << "jsonData:\n" << jsonData.dump(1) << "\n\n\n\n";
			}

#if SPREMAN_ZA_SLJEDECI_KORAK
			dat << "====================================================\n";
#endif
		}
		puts( "\n--------------------------------------------" );
		jsonData["projekt"] = nizProjekata;
		JSON_newDatoteka << jsonData;

		std::cout << "\n=====================================================================\n"
			<< "\t\t Zadaci su serializirani u json datoteku"
			<< "\n=====================================================================\n";
	//	std::clog << "jsonData:\n" << jsonData.dump(1) << '\n';
	}


}


#undef SPREMAN_ZA_SLJEDECI_KORAK;
