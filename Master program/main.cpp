////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UPOTREBA:
/// 1)  Stavi datoteke koje zelis testirat na lokaciju ".../Projekti/imeProjekta/FilesToParse/"
/// 2)  Kompajlaj program
/// 3)  Pokreni program
/// 4)  Opet kompajlaj program
/// 5)	Ako naides na bug potrebno je rucno otici u "Function list.cpp" datoteku i zamijenit problematicne linije sa bilo kojim drugim
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
/// - funkcije koje te zanimaju moraju biti u namespaceu /
///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse"
/// - funkcije moraju imat povratni tip "void" (trenutacno)	<-
/// - nepodrzava template funkcije
/// - nepodrzava vise nivoa namespace-a (pr: void namespace1::namespace2::imeFunk() ) za ucitanje deklaracije funkcije	<- (testiraj je li problem rijesen)
/// - nepodrzava razne kljucne rijeci u deklaraciji funkcija ( const, static, noexcept, constexpr, [[likely]], ... )	<- U PROCESU
/// - nepodrzava function overloading -> https://www.youtube.com/watch?v=NMWv2vQQjXE
/// - nemoze deduce-at povratni tip funkcije koja vraca auto <- U PROCESU
/// - nepodrzava trailing return type <- U PROCESU
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FEATURES za napravit:
/// - popuni datoteku "PotrebneDatotekeIDeklaracijeFunkcija.hpp" sa forward deklaracijama funkcija i #include-aj sve potrebne datoteke 
/// - ucitavanje funkcija sa nazivima iz datoteke whitelist (json format)
/// - blokiranje funkcija sa nazivima iz datoteke blacklist (json format)
/// - klasu za trazenje / handle-anje stringova za jos pregledniji kod
/// - podijelit kod u klase
/// - koristi wxWidgets za GUI kod rucnog nacina
/// - dinamicki containeri za bilo kakvu konfiguraciju
/// - dodaj polje u json datoteku za ime datoteke iz koje se procita zadatak (u datoteci moze bit zadataka sa razlicitim namespace-ima)
/// - pogledaj iznad ovog odjeljka na popis ogranicenja (oznacenih sa strelicom [ <- ])
/// - napravit novi path za izvršavanje ovog programa (1. pokretanje programa vs 2. pokretanje programa) da bi se uklonio dodatan posao što nepotrebno radi
/// - napravi da se datoteka "Function list.cpp" zadnja kompajla
/// - ukoliko se u deklaraciji ne nalazi kljucna rijec "noexcept" zahtjevaj da ta funkcija prima argument tipa std::exception& 
/// - omogucit testiranje koda u drugim programskim jezicima pomocu nasljedivanja
/// - --------------------------------------------------------------------------------------------
/// TRENUTACNO RADIM NA:
/// - testiraj radi li ispravno detekcija trailing return types
/// - testiraj podrzava li program vise nivoa namespace-a
/// - otklonit sto vise nepravilnosti prijavljene od stane clang tidy alata
/// - optimiziraj funkcije u datoteci "ParseFile.cpp"
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BUGS:
/// - u datoteci setup.cpp u funkciji "processZadatke": ukoliko funkcija ima "noexcept" kvalifikaciju, proizest ce krivi broj argumenata funkcije
/// - u datoteci ParseFile.cpp u funkciji "findStartOfAFunctioin" se nalazi EDGE CASE -> ukoliko se zagrada sa parametrima funkcije nalazi iza znaka nove linije
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OSTALO:
/// - Zbog toga sto zelim imat mogucnost prekidanja izvrsenja zadatka (spawnanje i unistavanje thread-a) izgubila se mogucnost uporabe exception handling-a u glavnom thread-u (rjesenje je poslat std::exception referencu kao funkcijski argumenat funkciji koju zelis izvrsit

#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
#include <thread>

#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"
using namespace nlohmann;

#include "ParseFile.hpp"

extern struct Zadatak;


extern void popuniCijeliPopisFunkcija( nlohmann::json& jsonData, bool isExecutionProcess );



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
		json::object_t processZadatke( std::vector<Zadatak*>& zadaci );
		void enforceCorrectBehaviour();
		nlohmann::json create_json_Object();
		nlohmann::json getJSONFromFile();
	};

}


void automatizirano();
void rucno();

/// ////////////////////////////////////////////////////////////////////////////////////////////////////
int main( const int args, const char* const argv[] )
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

void pokreni(){}


void Master::pokretanjeFunkcija()
{

	if( Master::popisProjekata.size() == 0 )
	{
		std::cout << "Nema niti jednog ucitanog projekta :(\nIzlazim...\n";
		puts( "==========================================================================================" );
		exit( EXIT_SUCCESS );
	}
	bool vratiSeKorakUnazad = false;
	char stage = 1;
	while( stage > 0 )
	{
		vratiSeKorakUnazad = false;
		std::cout << "\nUnesi broj -1 za izlazak iz programa ili jedan od ponudenih brojeva za projekt iz cijeg zelis pokrenut funkciju:\n";
		puts( "--------------------------------------------------------" );
		{
			size_t idx = 1;
			for( const auto& proj : Master::popisProjekata )
				std::cout << idx++ << ") " << proj << '\n';
			puts( "" );
		}
		char odabirProjekta = 0;
		do
		{
			std::cout << "Tvoj odabir: ";
			std::cin >> odabirProjekta;

			if( odabirProjekta == '-' )	{ --stage; vratiSeKorakUnazad = true; break; }	// koristi trik sto cin za unosenje znakova koristi buffer koji ce procitat znak '-' iz broja "-1"
			if( ( odabirProjekta -= '0' ) <= Master::popisProjekata.size() )
			{
				odabirProjekta -= 1; // pocinje od rednog broja 1, a ne od broja 0
				break;
			}
			else
			{
				puts( "Krivi unos!!\n" );
				while( std::cin.peek() != '\n' )
				{
					std::cin.ignore();
				}
				odabirProjekta = -1;
			}
		} while( odabirProjekta < 0 );
		if( vratiSeKorakUnazad )	break;

		++stage;
		while( stage > 1 )
		{
			vratiSeKorakUnazad = false;
			std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << '\n';
			puts( "--------------------------------------------------------" );

			if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].size() == 0 )
			{
				std::cout << "\nNema niti jedne ucitane cjeline :(\nVraæam se na odabir projekta\n";
				puts( "==========================================================================================" );
				--stage;
				break;
			}

			std::cout << "\nIz koje cjeline zelis pokrenut funkciju? Ako se zelis vratit na odabir projekta, unesi -1. A ako zelis izac iz programa unesi -2\n";
			puts( "--------------------------------------------------------" );

			for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta] )
				std::cout << str.first << '\n';
			std::cout << "\nTvoj odabir: ";
			std::string odabirCjeline;
			do
			{
				bool vratiSeNazad = false;
				std::cin >> odabirCjeline;
				if( odabirCjeline == "-1" )			{ --stage; vratiSeKorakUnazad = true; break; }
				else if( odabirCjeline == "-2" )	exit( EXIT_SUCCESS );
				if( Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline ) == Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].end() )
				{
					puts( "Krivi unos!!!" );
				}
				else	break;
			} while( true );
			if( vratiSeKorakUnazad )	break;

			++stage;
			while( stage > 2 )
			{
				vratiSeKorakUnazad = false;
				std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << " - " << odabirCjeline;
				puts( "\n--------------------------------------------------------" );

				if( Master::popisFunkcija[odabirProjekta].size() == 0 )
				{
					std::cout << "\n\nNema niti jedne ucitane funkcije :(\nOvo se moglo dogoditi jer nisi ponovno kompajlao program kao sto si trebao ili ako si rucno izbrisao sve funkcije iz \"Function list.cpp\" datoteke ili datoteka nije podrzana u trenutacnoj verziji programa (pogledaj odjeljak \"OGRANICENJE\" na vrhu main.cpp ili se jednostavno u datoteci koju si stavio pod path \"_Projekti\\imeProjekta\\FilesToParse\\imeDatoteka\" ne nalazi niti jedna funkcija.\nVracam se na odabir cjeline\n";

					puts( "==========================================================================================" );
					--stage;
					break;
				}

				std::cout << "\nIzaberi jednu od ponudenih funkcija koju zelis pokrenut:\n";
				puts( "--------------------------------------------------------" );
				for( const auto& str : Master::popisImenaFunkcijaPoCjelinama[odabirProjekta].find( odabirCjeline )->second )
				{
					puts( str.first.c_str() );
				}
				std::cout << "\nAko se zelis vratit na odabir cjeline, unesi -1. A ako zelis izac iz programa unesi -2\n";
				puts( "--------------------------------------------------------" );
				std::cout << "Tvoj odabir: ";
				std::string odabirFunkcije;
				do
				{
					std::cin >> odabirFunkcije;
					if( odabirFunkcije == "-1" )		{ --stage; vratiSeKorakUnazad = true; break; }
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
					try
					{
					//	throw 1;
						bool timeoutEnabled = false; /*NE UKLJUCUJ AKO ZELIS DEBUGIRAT*/
						std::cout << "\nAko zelis stavit timeout od 15 sekundi na izvrsenje zadatka, unesi SAMO enter ";
						{
							std::string ch = "t";
							std::cin.ignore();
							std::getline( std::cin, ch );
							if( ch.length() == 0 )	timeoutEnabled = true;
						}
						puts( "\n====================================================" );
						std::cout << iterID_funkcijeZaIzvrsit->second.first;
						puts( "====================================================" );
						std::cout << "\nID_funkZaIzvrsit: " << iterID_funkcijeZaIzvrsit->second.second << '\n';
						std::cout << "Pokrecem...\n\n\n";
						std::cout << "Funkcija je vratila sljedeæi rezultat:\n";
						puts( "--------------------------------------------------------" );
						std::thread zadatakThread( Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second.second] );
						///Master::popisFunkcija[odabirProjekta][iterID_funkcijeZaIzvrsit->second.second]
						static bool isFuncDone = false;
						std::jthread thd2(
							[&]()
							{
								using namespace std::chrono_literals;
								bool ponoviUpit = true;
								auto pocetnoVrijeme = std::chrono::high_resolution_clock::now();
								auto vrijmeSada = std::chrono::high_resolution_clock::now();

								while( !isFuncDone )
								{
									if( ponoviUpit && std::chrono::high_resolution_clock::now() - vrijmeSada > std::chrono::high_resolution_clock::duration( 250ms ) )
									{
										std::cout << "Cekam unos korisnika: ";
										vrijmeSada = std::chrono::high_resolution_clock::now();
										ponoviUpit = false;
									}

									if( timeoutEnabled && std::chrono::high_resolution_clock::now() - pocetnoVrijeme > std::chrono::seconds( 15 ) )
									{
										puts( "\n\n=============================================================================================" );
										std::cout << "Proslo je 15 sekundi od pokretanja funkcije, vjerojatnost je da je funkcija zapela u beskonacnoj petlji\nIzlazim...\n";
										puts( "===============================================================================================" );
										TerminateThread( zadatakThread.native_handle(), 1 );	/// <------- WINDOWS dependent
										std::cout.flush();
										std::cout.seekp( std::ios::end );
										break;
									}

									std::this_thread::sleep_for( 100ms );
								}
							} );


						zadatakThread.join(); // prisili ispis funkcije "puts" poslije izvrsenja funkcije
						isFuncDone = true;
						puts( "\n====================================================\n" );
					}
					catch( std::exception& e )
					{
						puts( "\n\n====================================================\n" );
						std::cout << "Funkcija je bacila iznimku: " << e.what() << "\nAko zelis istrazit o cemu se radi pritisni tipku entera.Ukoliko pak zelis nastavit testirat neke druge aspekte, stisni bilo koju drugu tipku: ";
						char c;
						std::cin >> c;
						if( tolower( c ) == 'y' )	throw;
						puts( "\n====================================================\n" );
					}
					catch( ... )
					{
						puts( "\n/n====================================================\n" );
						std::cout << "Funkcija je bacila iznimku!\nAko zelis istrazit o cemu se radi pritisni tipku 'y'.Ukoliko pak zelis nastavit testirat neke druge aspekte, stisni bilo koju drugu tipku: ";
						char c;
						std::cin >> c;
						if( tolower( c ) == 'y' )	throw;
						puts( "\n====================================================\n" );
					}
				}
			}
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




const auto dodajItemeUVektor = []( std::vector<std::string>& container, const char* fullPath, bool addFileNameIntoJson = false ) {
	for( const auto& entry : fs::directory_iterator( fullPath ) )
	{
		std::string pathToItems = entry.path().string();
		std::string::reverse_iterator itEnd;
		itEnd = std::find( pathToItems.rbegin(), pathToItems.rend(), '\\' );
		size_t offsetToItemName = pathToItems.rend() - itEnd;
		std::string fileName( pathToItems.begin() + offsetToItemName, pathToItems.end() );
		container.emplace_back( fileName );
	}
	};



void Master::init()
{
	std::cout << "DOBRODOSAO!!\n";
	puts( "----------------------" );
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ofstream( "Data\\" + nazivJSONdat, std::ios::app );
	std::ifstream JSON_datoteka( "Data\\" + nazivJSONdat, std::ios::in );
	nlohmann::json jsonData;
	char odabir;

	const auto pripremiProgramZaKoristenje = [&]()
		{
			bool isPopisProjekataEmpty = popisProjekata.empty();
			for( const auto& projektEntry : jsonData["projekt"] )
			{
				json::object_t projEntryObj = projektEntry;
				const auto& extractedProjektEntryValue = projEntryObj;
				std::string projectName = extractedProjektEntryValue.begin()._Ptr->_Myval.first;

				if( isPopisProjekataEmpty )		Master::popisProjekata.emplace_back( projectName );
				popisImenaFunkcijaPoCjelinama.push_back( {} );
				popisFunkcija.push_back( {} );
			}
			popuniCijeliPopisFunkcija(/*from*/ jsonData["projekt"], odabir == '1' );
			for( auto& vec : popisFunkcija )
				vec.shrink_to_fit();
		};

	bool firstTimeRunning = JSON_datoteka.is_open();
	bool isFileEmpty = std::filesystem::file_size( "Data\\" + nazivJSONdat ) == 0;
	if( !firstTimeRunning || isFileEmpty )
	{
		odabir = '0';
		jsonData = Master::_INTERNAL::create_json_Object();
		std::cout << "Da bi nastavio na sljedeci korak, ponovno kompajliraj program!\nIzlazim...\n";
		pripremiProgramZaKoristenje();
		/// naredbe ispod ovog komentara se nebi smjele izvrsit jer se program mora ugasit na ovom koraku
		exit( EXIT_SUCCESS );
	}
	else
	{
		std::cout << "Ako zelis nastavit sa trenatacnom verzijom upisi broj 1, inace 0: ";
		std::cin >> odabir;
		if( odabir == '1' )
		{
			jsonData = Master::_INTERNAL::getJSONFromFile();
			pripremiProgramZaKoristenje();
				///	Master::_INTERNAL::enforceCorrectBehaviour();	trenutacno nemoze tocno detektirat mjesto
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
			pripremiProgramZaKoristenje();
			/// naredbe ispod ovog komentara se nebi smjele izvrsit jer se program mora ugasit na ovom koraku
			std::cout << "Da bi nastavio na sljedeci korak, ponovno kompajliraj program\nIzlazim...\n";
			exit( EXIT_SUCCESS );
		}
	}
}

/// ukoliko korisnik obrise neke funkcije iz datoteke "Function list.cpp" izmedu koraka 3) i 5) , nastat ce nered. Funkcije zavise u kojem redoslijedu su dodane, a i kako program ocekuje da ima isti broj funkcija u "Function list.cpp", tako i u json datoteci, izbacit ce exception access out of range ukoliko se proba pokrenut funkcija sa velikim ID-om.
/// ovo se takoder moze rijesiti na bolji nacin poput skeniranja Function list.cpp datoteke nakon samog pokretanja programa da uoci izbacene funkcije, ali nije potrebno tu komplicirat jer u buducnosti ovaj korak ce biti nepotreban
void Master::_INTERNAL::enforceCorrectBehaviour()
{
	std::cout << "stripping out stuff:\n";
	puts( "-----------------------------------------" );
	std::array<size_t, 2> idx{ 0 };
	//std::vector<std::pair
	for( ; idx[0] < popisProjekata.size(); )
	{
		if( Master::popisImenaFunkcijaPoCjelinama[idx[0]].size() == 0 )
		{
			std::cout << "Brisem projekt sa niti jednom cjelinom: " << Master::popisProjekata[idx[0]] << "\n";
			puts( "==========================================================================================" );
			Master::popisImenaFunkcijaPoCjelinama.erase( Master::popisImenaFunkcijaPoCjelinama.begin() + idx[0] );
			Master::popisProjekata.erase( Master::popisProjekata.begin() + idx[0] );
			continue;
		}

		auto curCjelinaIt = Master::popisImenaFunkcijaPoCjelinama[idx[0]].begin();
		std::string nazivCjeline;
		size_t ukupanBrojZadatakaUProjektu = 0;
		bool isFirstTimePrinted = false;
		for( idx[1] = 0; idx[1] < popisImenaFunkcijaPoCjelinama[idx[0]].size(); ++idx[1], ++curCjelinaIt )
		{
		//std::map<int, int> t{{5, 4}};
		//auto ttt = t.begin()._Ptr->_Myval;
		//for( auto& kv : t )
		//{
		//	kv.
		//}


			if( Master::popisFunkcija[idx[0]].size() == 0 )
			{
				std::cout << "\n\nNema niti jedne ucitane funkcije u ovoj cjelini :(\nOvo se moglo dogoditi jer nisi ponovno kompajlao program kao sto si trebao ili ako si rucno izbrisao sve funkcije iz \"Function list.cpp\" datoteke ili datoteka nije podrzana u trenutacnoj verziji programa (pogledaj odjeljak \"OGRANICENJE\" na vrhu main.cpp ili se jednostavno u datoteci koju si stavio pod path \"_Projekti\\imeProjekta\\FilesToParse\\imeDatoteka\" ne nalazi niti jedna funkcija.\n"
					<< "Brisem cjelinu: " << nazivCjeline << '\n';
				puts( "--------------------------------------------\n" );
				Master::popisImenaFunkcijaPoCjelinama[idx[0]].erase( nazivCjeline );
			}

			ukupanBrojZadatakaUProjektu += curCjelinaIt->second.size();
		}

		auto item = Master::popisImenaFunkcijaPoCjelinama[idx[0]].begin();
		while( Master::popisFunkcija[idx[0]].size() < ukupanBrojZadatakaUProjektu )
		{
			if( !isFirstTimePrinted )
			{

				std::cout << "\nBroj funkcija pronadenih u datoteci \"Function list.cpp\" ne odgovara broju zadataka koji su spremljeni u json datoteku za projekt: " << popisProjekata[idx[0]];
				puts( "\n--------------------------------------------\n" );
				isFirstTimePrinted = true;
			}

			ukupanBrojZadatakaUProjektu -= item->second.size();
			std::string nazivNajveceCjeline = item->first;
			for( const auto& cjelina : Master::popisImenaFunkcijaPoCjelinama[idx[0]] )
			{
				if( cjelina.first > nazivNajveceCjeline )	nazivNajveceCjeline = cjelina.first;
			}
			std::cout << "Brisem: " << nazivNajveceCjeline << "\n";
			Master::popisImenaFunkcijaPoCjelinama[idx[0]].erase( nazivNajveceCjeline );
		}

		if( Master::popisImenaFunkcijaPoCjelinama[idx[0]].size() == 0 )
		{
			puts( "==========================================================================================" );
			std::cout << "\nBrisem projekt sa niti jednom cjelinom: " << Master::popisProjekata[idx[0]] << "\n";
			puts( "==========================================================================================" );
			puts( "--------------------------------------------\n" );
			Master::popisImenaFunkcijaPoCjelinama.erase( Master::popisImenaFunkcijaPoCjelinama.begin() + idx[0] );
			Master::popisProjekata.erase( Master::popisProjekata.begin() + idx[0] );
			continue;
		}
		else ++idx[0];
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
				<< "\nIzlazim...\n";
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
				dodajItemeUVektor( imenaDatoteka[idx], path.data(), true );
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
				json::object_t zadaciCjeline = Master::_INTERNAL::processZadatke( zadaci );
				imeProjekta[idx][Master::popisProjekata[idx]]["Broj cjeline"].emplace_back( zadaciCjeline );
				nizProjekata[idx] = imeProjekta[idx];


#if false
				if( idx == 1 )
				{
					jsonData["projekt"] = nizProjekata;
					JSON_newDatoteka << jsonData;
			}
#endif
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


#undef SPREMAN_ZA_SLJEDECI_KORAK
