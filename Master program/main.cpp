////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UPOTREBA:
/// 1)  Stavi datoteke koje zelis testirat na lokaciju ".../Projekti/imeProjekta/FilesToParse/"
/// 2)  Kompajlaj program
/// 3)  Pokreni program
/// 4)  Opet kompajlaj program
/// 5)	Zbog bugova potrebno je rucno otici u "Function list.cpp" datoteku i komentirat problematicne linije
/// 6)  Pokreni program 
/// ---------------------------------
/// Objašnjenje:
/// -- Prilikom prvog pokretanja programa stvorit ce se json datoteka iz koje ce se citat sve informacije.
/// -- prilikom èitanja json datoteke, zapisat æe popis funkcija u .cpp datoteku naziva "Function list"
/// -- prilikom druge kompilacije programa, linkat æe se svi funkcijski pointeri koji su se prethodno zapisali u tu .cpp datoteku
/// ////////////////////////////////////////////////////////////////
/// nakon toga ako zelis promijenit (dodat/uklonit) datoteke iz kojih citas informacije o funkcijama, moras ponovit cijeli postupak
/// ////////////////////////////////////////////////////////////////
/// ta .cpp datoteka mora biti prisutna u baš tom obliku (nesmije se dirat sadrzaj i lokacija na kojoj se nalazi)
/// ako je obrišeš morat æeš ruèno je napravit i kopirat sadržaj iz Function list.bak datoteke i ubacit datoteku u visual studio da bi mogao krenut na korak 2)
/// ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OGRANICENJA:
/// - podrzava samo jedno linijske komentare za tekst zadataka	<-
/// - funkcije koje te zanimaju moraju biti u namespaceu /
///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse"
/// - funkcije moraju imat povratni tip "void" (trenutacno)	<-
/// - nepodrzava template funkcije
/// - nepodrzava vise nivoa namespace-a (pr: void namespace1::namespace2::imeFunk() ) za ucitanje deklaracije funkcije	<-
/// - nepodrzava razne kljucne rijeci u deklaraciji funkcija ( const, static, noexcept, constexpr, [[likely]], ... )	<-
/// - nepodrzava function overloading
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FEATURES za napravit:
/// - citaj JSON datoteku u setup.cpp prilikom ucitavanja popisa
/// - ucitavanje funkcija sa nazivima iz datoteke whitelist
/// - blokiranje funkcija sa nazivima iz datoteke blacklist
/// - podrzavanje viselinijskih komentara
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - spawnanje zadataka na novom threadu
/// - vremenski ogranicit izvrsavanje zadatka
/// - dinamicki containeri za bilo kakvu konfiguraciju
/// - dodaj polje u json datoteku za ime datoteke iz koje se procita zadatak (u datoteci moze bit zadataka sa razlicitim namespace-ima)
/// - pogledaj iznad ovog odjeljka na popis ogranicenja (oznacenih sa strelicom [ <- ])
/// - podijelit kod u klase
/// - omogucit testiranje koda u drugim programskim jezicima pomocu nasljedivanja
/// - napravit novi path za izvršavanje ovog programa (1. pokretanje programa vs 2. pokretanje programa) da bi se uklonio dodatan posao što nepotrebno radi
/// - Otkriven novi BUG -> ne handle-a ispravno za slucaj da funkcija nema namespace;

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


extern void popuniCijeliPopisFunkcija( nlohmann::json& jsonData );



namespace Master
{
	std::vector<std::string> popisProjekata;
	// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisImenaFunkcijaPoCjelinama;
	extern std::vector<std::vector<void ( * )( )>> popisFunkcija;

	void init();
	void pokretanjeFunkcija();
	namespace _INTERNAL
	{
		json::object_t processZadatke( nlohmann::json::object_t& jsonData, std::vector<Zadatak*>& zadaci );
		nlohmann::json create_json_Object();
		nlohmann::json getJSONFromFile();
	};

}


void automatizirano();
void rucno();

/// ////////////////////////////////////////////////////////////////////////////////////////////////////
int main( const size_t args, const char* argv[] )
{
	Master::init();
	Master::pokretanjeFunkcija();


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


std::ostream& operator<<( std::ostream& dat, const Zadatak& zad )
{
	dat << "TEKST ZADATKA: " << zad.tekst << '\n' << "DEKLARACIJA: " << zad.deklaracija << '\n' << "KOD:\n" << zad.kod << '\n';
	return dat;
}

void Master::pokretanjeFunkcija()
{
	while( bool youAreNotDone = true )
	{
		if( Master::popisProjekata.size() == 0 )
		{
			std::cout << "Nema niti jednog ucitanog projekta :(\nIzlazim...\n";
			exit( EXIT_SUCCESS );
		}

	stage1:
		std::cout << "Unesi broj -1 za izlazak iz programa ili jedan od ponudenih brojeva za projekt iz cijeg zelis pokrenut funkciju:\n";
		{
			size_t idx = 1;
			for( const auto& proj : Master::popisProjekata )
				std::cout << idx++ << ") " << proj << '\n';
			puts( "" );
		}
		char odabirProjekta = 0;
		do
		{
			std::cin >> odabirProjekta;

			if( odabirProjekta == '-' )	return;	// koristi trik sto cin za unosenje znakova koristi buffer koji ce procitat znak '-' iz broja "-1"
			if( ( odabirProjekta -= '0' ) <= Master::popisProjekata.size() )
			{
				odabirProjekta -= 1; // pocinje od rednog broja 1, a ne od broja 0
				break;
			}
			else
			{
				puts( "Krivi unos!!" );
				odabirProjekta = -1;
			}
		} while( odabirProjekta < 0 );

	stage2:
		std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta]
			<< "\n\Iz koje cjeline zelis pokrenut funkciju? Ako se zelis vratit na odabir projekta, unesi -1. A ako zelis izac iz programa unesi -2\n\n";
		for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta] )
			std::cout << str.first << '\n';
		std::cout << "\nTvoj odabir: ";
		std::string odabirCjeline;
		do
		{
			if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].size() == 0 )
			{
				std::cout << "Nema niti jedne ucitane cjeline :(\nVraæam se na odabir projekta\n";
				goto stage1;
			}

			std::cin >> odabirCjeline;
			if( odabirCjeline == "-1" )			goto stage1;
			else if( odabirCjeline == "-2" )	exit( EXIT_SUCCESS );
			if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline ) == Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].end() )
			{
				puts( "Krivi unos!!!" );
			}
			else	break;
		} while( true );

	stage3:
		std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << " - " << odabirCjeline
			<< "\n\Izaberi jednu od ponudenih funkcija koju zelis pokrenut:\n\n";
		for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second )
		{
			puts( str.first.c_str() );
		}
		std::cout << "\nAko se zelis vratit na odabir cjeline, unesi -1. A ako zelis izac iz programa unesi -2\n";
		std::cout << "\nTvoj odabir: ";
		std::string odabirFunkcije;
		do
		{
			if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.size() == 0 )
			{
				std::cout << "Nema niti jedne ucitane funkcije :(\nOvo se moglo dogoditi jer nisi ponovno kompajlao program kao sto si trebao ili ako si rucno izbrisao sve funkcije iz \"Function list.cpp\" datoteke ili datoteka nije podrzana u trenutacnoj verziji programa (pogledaj odjeljak \"OGRANICENJE\" na vrhu main.cpp ili se jednostavno u datoteci koju si stavio pod path \"_Projekti\\imeProjekta\\FilesToParse\\imeDatoteka\" ne nalazi niti jedna funkcija \nVraæam se na odabir cjelina\n";
				goto stage2;
			}

			std::cin >> odabirFunkcije;
			if( odabirFunkcije == "-1" )		goto stage2;
			else if( odabirFunkcije == "-2" )	exit( EXIT_SUCCESS );
			if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije )
				== Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
			{
				puts( "Krivi unos!!!" );
			}
			else	break;
		} while( true );
		auto iterID_funkcijeZaIzvrsit = Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.find( odabirFunkcije );
		if( iterID_funkcijeZaIzvrsit != Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second.end() )
		{
			std::cout << "\nID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second.second << '\n';
			std::cout << "Pokrecem...\n\n\n";
			std::cout << "Funkcija je vratila sljedeæi rezultat:\n";
			Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second.second]();
			puts( "\n====================================================" );
			std::cout << iterID_funkcijeZaIzvrsit->second.first;
			puts("====================================================");
		}
	}
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




const auto dodajItemeUVektor = []( std::vector<std::string>& container, const char* fullPath ) {
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



void Master::init()
{
	std::cout << "DOBRODOSAO!!\n";
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ifstream JSON_datoteka( "Data\\" + nazivJSONdat, std::ios::in );
	nlohmann::json jsonData;
	bool firstTimeRunning = JSON_datoteka.is_open();
	bool isFileEmpty = std::filesystem::file_size( "Data\\" + nazivJSONdat ) == 0;
	if( !firstTimeRunning || isFileEmpty )
	{
		jsonData = Master::_INTERNAL::create_json_Object();
		std::cout << "Da bi nastavio na sljedeci korak, ponovno kompajliraj program!\nIzlazim...\n";
		exit( EXIT_SUCCESS );
	}
	else
	{
		std::cout << "Ako zelis nastavit sa trenatacnom verzijom upisi broj 1, inace 0: ";
		char odabir;
		std::cin >> odabir;
		if( odabir == '1' )
		{
			jsonData = Master::_INTERNAL::getJSONFromFile();
			// dodaj imena projekata u vektor
			for( const auto& projektEntry : jsonData["projekt"] )
			{
				json::object_t projEntryObj = projektEntry;
				const auto& extractedProjektEntryValue = projEntryObj;
				std::string projectName = extractedProjektEntryValue.begin()._Ptr->_Myval.first;

				Master::popisProjekata.emplace_back( projectName );
				popisImenaFunkcijaPoCjelinama.push_back( {} );
				popisFunkcija.push_back( {} );
			}
			popuniCijeliPopisFunkcija(/*from*/ jsonData["projekt"] );
			for( auto& vec : popisFunkcija )
				vec.shrink_to_fit();
		}
		else if( odabir == '0' )
		{
			std::cout << "Pravim kopiju JSON datoteke i brisem original!\n";
			auto copy_file = []( std::fstream& copyFrom, std::ofstream& copyTo ) {
				std::string strFile;
				while( !copyFrom.eof() )
				{
					strFile += copyFrom.get();
				}
				if( strFile[strFile.size() - 1] == 'ÿ' )	strFile.resize( strFile.size() - 1 );
				copyTo << strFile;
				};
			std::fstream curJSON( "Data\\" + nazivJSONdat, std::ios::in );
			std::ofstream backup( "Data\\" + nazivJSONdat + ".bak", std::ios::out );
			if( !curJSON.is_open() || !backup.is_open() )
			{
				std::cout << "Nemogu zavrsit postupak!!\n"
					<< "Ako problem je i dalje tu, obrisi JSON datoteku rucno\n\n";
			}
			copy_file( curJSON, backup );
			curJSON.close(); backup.close();
			std::ofstream deleteJSON( "Data\\" + nazivJSONdat, std::ios::trunc );
			deleteJSON.close();

			curJSON.open( "Data\\Function list.cpp", std::ios::in );
			backup.open( "Data\\Function list.cpp.bak", std::ios::out );
			if( !curJSON.is_open() || !backup.is_open() )
			{
				std::cout << "Nemogu zavrsit postupak kopiranja \"Function list.cpp\" datoteke!!\n"
					<< "Ako problem je i dalje tu, obrisi datoteku rucno\n\n";
			}
			copy_file( curJSON, backup );
			curJSON.close(); backup.close();
			std::ofstream deleteFunctions( "Data\\" + nazivJSONdat, std::ios::trunc );
			deleteFunctions.close();

			curJSON.open( "Data\\Function list.bak", std::ios::in );
			backup.open( "Data\\Function list.cpp", std::ios::out );
			if( !curJSON.is_open() || !backup.is_open() )
			{
				std::cout << "Nemogu zavrsit postupak kopiranja \"Function list.bak\" datoteke!!\n"
					<< "Ako problem je i dalje tu, obrisi datoteku rucno\n\n";
			}
			copy_file( curJSON, backup );
			curJSON.close(); backup.close();

			jsonData = Master::_INTERNAL::create_json_Object();
			std::cout << "Da bi nastavio na sljedeci korak, ponovno kompajliraj program\nIzlazim...\n";
			exit( EXIT_SUCCESS );
		}
	}
}

nlohmann::json Master::_INTERNAL::create_json_Object()
{
	nlohmann::json jsonData;
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ifstream JSON_existingDatoteka( "Data\\" + nazivJSONdat, std::ios::in );
	if( !JSON_existingDatoteka.is_open() || std::filesystem::file_size( "Data\\" + nazivJSONdat ) == 0 )
	{
		std::ofstream JSON_newDatoteka( "Data\\" + nazivJSONdat, std::ios::out );
		if( !JSON_newDatoteka.is_open() )
		{
			std::cout << "Nisam mogao otvorit \"InformacijeOZadacima.json\" datoteku!"
				<< "\Izlazim...\n";
			exit( EXIT_FAILURE );
		}

		json::array_t nizProjekata = json::array();
		std::vector<json::object_t> imeProjekta{};

		dodajItemeUVektor( Master::popisProjekata, "_Projekti" );

		std::vector<std::string> paths;
		{
		  // popuni pathove dinamicki sa svim projektima
			uint32_t idx = 0;
			for( const auto& entry : fs::directory_iterator( "_Projekti" ) )
			{
				std::string pathToItem = entry.path().string();
				imeProjekta.push_back( {} );
				imeProjekta[idx][Master::popisProjekata[idx]]["pathToProj"] = pathToItem;
				++idx;
				pathToItem += "\\FilesToParse\\";
				paths.push_back( std::move( pathToItem ) );
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
#define SPREMAN_ZA_SLJEDECI_KORAK false // kod ispravno radi, sacuvano radi lakseg debugiranja u buducnosti
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
				json::object_t zadaciCjeline = Master::_INTERNAL::processZadatke( imeProjekta[idx], zadaci );
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
	return jsonData;
}


#undef SPREMAN_ZA_SLJEDECI_KORAK;
