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
/// - funkcije koje te zanimaju moraju biti u namespaceu <- | [kad napravis dinamicke spremnike ukloni ovu stavku]   /
///		odvoji sve funkcije koje te zanimaju u zasebnu .cpp datoteku i stavi je u mapu "FilesToParse" <- [mapa naziva "FilesToParse" ce sluzit kao globalni whitelisting]
/// - funkcije moraju imat povratni tip "void" (trenutacno)	<- | [kada napravis da funkcijski pointer bude raznolik, ukloni ovu stavku]
/// - nepodrzava parsiranje heaeder (.hpp) datoteka <- | [kada napravis da moze citat funkcije iz klasa, ukloni ovu stavku]
/// - nepodrzava template funkcije
/// - nepodrzava function overloading -> https://www.youtube.com/watch?v=NMWv2vQQjXE
/// - nemoze deduce-at povratni tip funkcije koja vraca auto <-
/// - podrzava razne kljucne rijeci u deklaraciji funkcija ( const, static, noexcept, constexpr, [[nodiscard]], ... ), ALI nije implementirano njihovo znacenje
/// - nepodrzava razne nove feature iz C++ 20 i nadalje
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// IDEJE za napravit:
/// - [FEATURE] popuni datoteku "PotrebneDatotekeIDeklaracijeFunkcija.hpp" sa forward deklaracijama funkcija i #include-aj sve potrebne datoteke
/// - [TODO: OGRANICENJA] pogledaj iznad ovog odjeljka na popis ogranicenja (oznacenih sa strelicom [ <- ])
/// - [MISCELLANEOUS] podijelit kod u klase
/// - [MISCELLANEOUS] klasu za trazenje / handle-anje stringova za jos pregledniji kod
/// - [FEATURE] dinamicki containeri za bilo kakvu konfiguraciju
/// - napravit novi path za izvršavanje ovog programa (1. pokretanje programa vs 2. pokretanje programa) da bi se uklonio dodatan posao što nepotrebno radi
/// - napravi da se datoteka "Function list.cpp" zadnja kompajla
/// - [FEATURE] ukoliko se u deklaraciji ne nalazi kljucna rijec "noexcept" zahtjevaj da ta funkcija prima argument tipa std::exception&
/// - [FEATURE] omogucit testiranje koda u drugim programskim jezicima pomocu nasljedivanja
/// - [MISCELLANEOUS] smanjit broj cache miss-ova tako sto ces koristit 1 veliki string i offset-e umjesto 3 mala string-a (za tekst, deklaraciju i kod)
/// - [MISCELLANEOUS] napravi izmjene u ParseFile klasi tako da je laksa za koristenje (pristup pojedinoj datoteci, koristi operator [] i varijablu koja prati iskoristene datoteke )
/// - [MISCELLANEOUS] ubrzat ispis u konzolu
/// - [MISCELLANEOUS] promijeni podatkovne strukture za filtere tako da ustedis na prostoru
/// - [FEATURE] pitaj korisnika da odabere zeljene filterske datoteke ukoliko ih ima vise 
/// - [FEATURE] mogucnost korisnika da update-a filtere sa filterima u drugim datotekama 
/// - [FEATURE] ukoliko ima vise filterskih datoteka pitaj korisnika da odabere koje zeli ucitat pri pokretanju programa
/// - [MISCELLANEOUS] neke stavke za filtriranje ce biti od vece koristi ako su pristupne u programu umjesto samo read-only
/// - [MISCELLANEOUS] promijeni strukturu popisaImenaFunkcijaPoCjelinama da sadrzi map za imena projekata zbog filtera
/// - [MISCELLANEOUS] zavrsi implementaciju overloadanih funkcija Master::_INTERNAL::utvrdiOKojemPovratnomTipuSeRadi
/// - [MISCELLANEOUS] zavrsi implementaciju funkcije json::object_t Master::_INTERNAL::processZadatke
/// - [MISCELLANEOUS] ///	Master::_INTERNAL::enforceCorrectBehaviour();	trenutacno nemoze tocno detektirat mjesto
/// - [MISCELLANEOUS] smisli rjesenje za razlicite nacine (postavka: MODE) izvrsavanja ovog programa
/// - [MISCELLANEOUS] refactoraj glavnu podatkovnu strukturu funkcija po cjelinama da bi se mogli koristiti razliciti filteri bez nus pojava 
/// 
///
/// ----------------------------------------------------------------------------------------------
/// TRENUTACNO RADIM NA:
/// - [FEATURE] filtriranje tijekom procesiranja zadataka
/// - [BUG] ispisuje nakdnadno znak '\n' prilikom ispisa koda pokrenute funkcije
/// - [MISCELLANEOUS] popravi ispis imena datotekka pri parsiranju u 3. koraku
/// - [FEATURE] koristi wxWidgets za GUI kod rucnog nacina
/// - [MISCELLANEOUS] otklonit sto vise nepravilnosti prijavljene od stane Clang Tidy i SonarLint alata
///
/// ----------------------------------------------------------------------------------------------
/// SLJEDECE NA REDU:
/// - [OGRANICENJE] funkcije moraju imat povratni tip "void" (trenutacno)	<-
/// - [BUG] u datoteci setup.cpp u funkciji "processZadatke": ukoliko funkcija ima "noexcept" kvalifikaciju, reci ce krivi broj argumenata funkcije
/// - [MISCELLANEOUS] optimiziraj funkcije u datoteci "ParseFile.cpp"
///
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BUGS:
/// - funkcija naziva getPositionOfFunction ne radi nikakve provjere
/// - destruktor klase se trenutacno ne filtrira 
/// - funkcija applyFilters neradi ispravno za whitelistane zadatke u istoj cjelini
/// - working on...

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OSTALO:
/// - Zbog toga sto zelim imat mogucnost prekidanja izvrsenja zadatka (spawnanje i unistavanje thread-a) izgubila se mogucnost uporabe exception handling-a u glavnom thread-u (rjesenje je poslat std::exception referencu kao funkcijski argumenat funkciji koju zelis izvrsit
/// - U slucaju kad imas funkciju nest-anu u klasi unutar druge klase. Tada se funkcija mora oznacit kvalifikacijom static ili se nece moci kompajlat program pri zadnjem koraku

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>

#include <vector>
#include <unordered_map>

#include "..\_Includes\json.hpp"

#include "ParseFile.hpp"
#include "..\Master program\PotrebneDatotekeIDeklaracijeFunkcija.hpp"
/// //////////////////////////////////////////////////////////////
#include "..\USER\Code\YourCode.hpp"

namespace fs = std::filesystem;
using namespace nlohmann;

constexpr const char* USER_DEFAULT_PATH = "USER\\_FILES";

namespace Master
{
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisWhitelistanihImenaFunkcijaPoCjelinama;
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisBlacklistanihImenaFunkcijaPoCjelinama;
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisFiltriranihImenaFunkcijaPoCjelinama;

	std::unordered_map<std::string, std::string> konfiguracijskePostavke;
	std::vector<std::string> popisProjekata;
	// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisImenaFunkcijaPoCjelinama;
	extern std::vector<std::vector<void ( * )( )>> popisFunkcija;

	void init();
	void loadFilters();
	void switchFilters();
	[[nodiscard]] std::pair<std::optional<json>, std::optional<json>> helpFunc_odaberiFiltere();
	[[nodiscard]] nlohmann::json convertToJson( /*from*/ std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> spremnikFunkcijaPoCjelinama );

	void goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string& ), char& odabirProjekta, std::string& odabirCjeline, std::string& odabirFunkcije, char& stage );

	void goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string&, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& ), char& odabirProjekta, std::string& odabirCjeline, std::string& odabirFunkcije, char& stage );

	void goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string&, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& ), char stage );

	[[nodiscard]] std::optional<nlohmann::json> getJSONFromFile( const char* path );
	void ucitajPocetniPopisFunkcija();
	void removeIncompatibleFunctions();
	void removeIncompatibleFilters();
	void applyFilters();
	void startFilteringProcess();
	void filter( const char, const std::string&, const std::string&, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama );
	void saveFilterFiles();
	void helpFunc_removeIncompatibleFilter( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFilterskihFunkcija );
	bool helpFunc_saveOrOverwriteFilterFile( const bool isWhitelistFile );
	void helpFunc_repeatStepIfDesiredOfSavingFilter( const bool isWhitelistFile );

	extern void popuniCijeliPopisFunkcija( const nlohmann::json& jsonData, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, bool isExecutionProcess );
	extern void popuniCijeliPopisFunkcija( const nlohmann::json& jsonData, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama );

	namespace _INTERNAL
	{

		void unesiKonfiguracijskePostavke();
		[[nodiscard]] json::object_t processZadatke( const std::vector<std::unique_ptr<Zadatak>>& zadaci, const size_t upotrijebljenoZadataka, std::string_view nazivDatoteke );
		void enforceCorrectBehaviour();
		nlohmann::json create_json_Object();
	};

};


void automatizirano();
void rucno();

/// /////////////////// /////////////////// ///////////////////// ////////////////////// ///////////////////
int main( const int args, const char* const argv[] )
{
	Master::init();

	// forsiraj konfiguracijske postavke da sadrzavaju samo velika slova
	for( auto& [key, val] : Master::konfiguracijskePostavke )
		std::for_each( val.begin(), val.end(), []( char& c ) { return toupper( c ); } );


	/// razmisli o ovome rjesenju (posebni path koji zavisi od MODE postavke) ili na potrebnim mjestima stavi prikladni if slucaj
	if( Master::konfiguracijskePostavke["MODE"] == "USER" )
	{
		/// TODO
		/// zapocni GUI
		rucno();
	}
	else if( Master::konfiguracijskePostavke["MODE"] == "AUTOMATED" )
	{
		automatizirano();

	}
	else if( Master::konfiguracijskePostavke["MODE"] == "REPL" )
	{
		/// TODO
	}

	if( Master::konfiguracijskePostavke.at( "SKIP_LOADING_FILTERS_AT_STARTUP" ) != "YES" )
		Master::loadFilters();

	bool isCompatibleOption =
		Master::konfiguracijskePostavke["FILTER"] == "ALLOW" &&
		Master::konfiguracijskePostavke["FILTER_WHILE"] == "RUNNING";

	char odabir = 0x7F;
	while( bool wantToContinue = true )
	{
		std::cout << "\nImas sljedece opcije:\n"
			<< "1) Nastavi na sljedeci korak\n"
			<< "2) Odi na postupak filtriranja funkcija\n"
			<< "3) Odi na postupak zamjene filtera\n"
			<< "4) Odi na postupak spremanja filtera\n"
			<< "Ili bilo koji drugi znak za izlazak iz programa\n";
		puts( "---------------------------------------------" );
		std::cout << "Tvoj odabir: ";
		std::cin >> odabir;
		std::cin.seekg( std::cin.end );
		puts( "" );

		if( odabir == '1' )
		{
			Master::removeIncompatibleFunctions();
			Master::ucitajPocetniPopisFunkcija(); /// napravi nesto pametnije ovdje, ucitaj samo potrebne funkcije
			if( isCompatibleOption &&
				Master::konfiguracijskePostavke["USE_FILTERS"] != "NONE" )
			{
				bool foundFilters = false;
				for( size_t idx = 0; !foundFilters && idx < Master::popisWhitelistanihImenaFunkcijaPoCjelinama.size(); ++idx )
				{
					auto curCjelinaIt = Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].begin();
					while( !foundFilters && curCjelinaIt != Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].end() )
					{
						if( !curCjelinaIt->second.empty() )
						{
							foundFilters = true;
							break;
						}
						++curCjelinaIt;
					}
				}
				for( size_t idx = 0; !foundFilters && idx < Master::popisBlacklistanihImenaFunkcijaPoCjelinama.size(); ++idx )
				{
					auto curCjelinaIt = Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].begin();
					while( !foundFilters && curCjelinaIt != Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].end() )
					{
						if( !curCjelinaIt->second.empty() )
						{
							foundFilters = true;
							break;
						}
						++curCjelinaIt;
					}
				}

				if( foundFilters ) Master::applyFilters();
			}
			else	std::cout << "Filteri su iskljuceni!\n";

			USER::executableCode();
		}
		else if( odabir == '2' )
		{
			std::cout << "Zapocinjem filterski proces...\n\n";
			Master::startFilteringProcess();
		}
		else if( odabir == '3' )
		{
			std::cout << "Zapocinjem postupak zamjene filtera...\n\n";
			Master::switchFilters();
		}
		else if( odabir == '4' )
		{
			std::cout << "Zapocinjem postupak spremanja filtera...\n\n";
			Master::saveFilterFiles();
		}
		else { wantToContinue = false; break; }
	}

	if( Master::konfiguracijskePostavke["SAVE_FILTERS"] != "NEVER" )	Master::saveFilterFiles();

	std::cout << "IZLAZIM...\n";
	return EXIT_SUCCESS;
}


/// ////////////////////////////// //////////////////////////////// ////////////////////////////////// /////////////////////////////////////

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

void rucno() {}

/// /////////////////// ///////////////////////////////// //////////////////////////// /////////////////////////////////

inline char korakOdabiraProjekta( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, char& stage )
{
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
		std::cin.seekg( std::cin.end );
		puts( "========================" );

		if( odabirProjekta == '-' )
		{
			--stage;
			break;
		} // koristi trik sto cin za unosenje znakova koristi buffer koji ce procitat znak '-' iz broja "-1"
		if( ( odabirProjekta -= '0' ) <= Master::popisProjekata.size() )
		{
			++stage;
			return odabirProjekta;
		}
		else
		{
			puts( "Krivi unos!!\n" );
			while( std::cin.peek() != '\n' ) // ignoriraj ostatak inputa
			{
				std::cin.seekg( std::cin.end );
			}
			odabirProjekta = -1;
		}
	} while( odabirProjekta < 0 );
}

inline std::string korakOdabiraCjeline( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, const char odabirProjekta, char& stage )
{
	std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << '\n';
	puts( "--------------------------------------------------------" );

	if( spremnikFunkcijaPoCjelinama[odabirProjekta].size() == 0 )
	{
		std::cout << "\nNema niti jedne ucitane cjeline :(\nVraæam se na odabir projekta\n";
		puts( "==========================================================================================" );
		--stage;
		return "";
	}

	std::cout << "\nIz koje cjeline zelis pokrenut funkciju? Ako se zelis vratit na odabir projekta, unesi -1. A ako zelis izac iz programa unesi -2\n";
	puts( "--------------------------------------------------------" );

	for( const auto& [nazivCjeline, unused] : spremnikFunkcijaPoCjelinama[odabirProjekta] )
		std::cout << nazivCjeline << '\n';
	std::cout << "\nTvoj odabir: ";
	std::string odabirCjeline;
	do
	{
		bool vratiSeNazad = false;
		std::cin >> odabirCjeline;
		puts( "========================" );
		if( odabirCjeline == "-1" )
		{
			--stage;
			break;
		}
		else if( odabirCjeline == "-2" )
			exit( EXIT_SUCCESS );
		if( !spremnikFunkcijaPoCjelinama[odabirProjekta].contains( odabirCjeline ) )
		{
			puts( "Krivi unos!!!" );
		}
		else
		{
			++stage;
			break;
		}
	} while( true );
	return odabirCjeline;
}

inline std::string korakOdabirFunkcije( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, const char odabirProjekta, const std::string& odabirCjeline, char& stage )
{
	std::cout << "\nOdabrao si projekt " << Master::popisProjekata[odabirProjekta] << " - " << odabirCjeline;
	puts( "\n--------------------------------------------------------" );

	if( Master::popisFunkcija[odabirProjekta].size() == 0 )
	{
		std::cout << "\n\nNema niti jedne ucitane funkcije :(\nOvo se moglo dogoditi jer nisi ponovno kompajlao program	kao sto si trebao ili ako si rucno "
			"izbrisao sve funkcije iz \"Function list.cpp\" datoteke ili datoteka nije podrzana u trenutacnoj verziji programa (pogledaj odjeljak "
			"\"OGRANICENJE\" na vrhu main.cpp ili se jednostavno u datoteci koju si stavio pod path \"_Projekti\\imeProjekta\\FilesToParse\\imeDatoteka\" "
			"ne nalazi niti jedna funkcija.\nVracam se na odabir cjeline\n";

		puts( "==========================================================================================" );


		--stage;
		return "";
	}

	std::cout << "\nIzaberi jednu od ponudenih funkcija koju zelis pokrenut:\n";
	puts( "--------------------------------------------------------" );
	for( const auto& str : spremnikFunkcijaPoCjelinama[odabirProjekta].at( odabirCjeline ) )
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
		puts( "========================" );
		if( odabirFunkcije == "-1" )
		{
			--stage;
			break;
		}
		else if( odabirFunkcije == "-2" )
			exit( EXIT_SUCCESS );
		if( !spremnikFunkcijaPoCjelinama[odabirProjekta].at( odabirCjeline ).contains( odabirFunkcije ) )
		{
			puts( "Krivi unos!!!" );
		}
		else
		{
			++stage;
			break;
		}
	} while( true );

	return odabirFunkcije;
}

void Master::goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string& ), char& odabirProjekta, std::string& odabirCjeline, std::string& odabirFunkcije, char& stage )
{
	if( spremnikFunkcijaPoCjelinama.empty() )
	{
		std::clog << "Spremnik funkcija po cjelinama koji si pruzio je prazan\n";
		puts( "===============================================" );
		return;
	}

	do
	{
		switch( stage )
		{
			case 1:
				odabirProjekta = korakOdabiraProjekta( spremnikFunkcijaPoCjelinama, stage );
				odabirProjekta -= 1;
				break;
			case 2:
				odabirCjeline = korakOdabiraCjeline( spremnikFunkcijaPoCjelinama, odabirProjekta, stage );
				break;
			case 3:
				odabirFunkcije = korakOdabirFunkcije( spremnikFunkcijaPoCjelinama, odabirProjekta, odabirCjeline, stage );
				break;
			case 4:
				executeThis( odabirProjekta, odabirCjeline, odabirFunkcije );
				--stage;
				break;
			default:
				assert( false, "WTH, how did you get here??\n" );
		}
	} while( stage > 0 );
}


void Master::goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string&, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& ), char& odabirProjekta, std::string& odabirCjeline, std::string& odabirFunkcije, char& stage )
{
	if( spremnikFunkcijaPoCjelinama.empty() )
	{
		std::clog << "Spremnik funkcija po cjelinama koji si pruzio je prazan\n";
		puts( "===============================================" );
		return;
	}

	do
	{
		switch( stage )
		{
			case 1:
				odabirProjekta = korakOdabiraProjekta( spremnikFunkcijaPoCjelinama, stage );
				odabirProjekta -= 1;
				break;
			case 2:
				odabirCjeline = korakOdabiraCjeline( spremnikFunkcijaPoCjelinama, odabirProjekta, stage );
				break;
			case 3:
				odabirFunkcije = korakOdabirFunkcije( spremnikFunkcijaPoCjelinama, odabirProjekta, odabirCjeline, stage );
				break;
			case 4:
				executeThis( odabirProjekta, odabirCjeline, odabirFunkcije, spremnikFunkcijaPoCjelinama );
				--stage;
				break;
			default:
				assert( false, "WTH, how did you get here??\n" );
		}
	} while( stage > 0 );
}

void Master::goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string&, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& ), char stage = 1 )
{
	char odabirProjekta;
	std::string odabirCjeline;
	std::string odabirFunkcije;

	Master::goToTheWantedFunctionAndThen( spremnikFunkcijaPoCjelinama, Master::filter, odabirProjekta, odabirCjeline, odabirFunkcije, stage );
}

/// //////// /////////// /////////////// /////////////////// ///////////////

void Master::startFilteringProcess()
{
	bool wantToContinue = true;
	while( wantToContinue )
	{
		bool useBothFilters = Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH";
		bool useWhitelistFilter = Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_WHITELIST" || useBothFilters;
		bool useBlacklistFilter = Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_BLACKLIST" || useBothFilters;
		if( ( useBothFilters | useWhitelistFilter | useBlacklistFilter ) == 0 )
		{
			std::cerr << "ERROR; Nevazeca konfiguracijska postavka pod stavkom \"USE_FILTERS\"";
			puts( "========================================" );
			return;
		}

		uint8_t availableOptions = 1 +
			useWhitelistFilter +
			useBlacklistFilter;

		char odabir;
		std::cout << "Imas sljedece opcije:\n"
			<< "1) popisImenaFunkcijaPoCjelinama\n"
			<< "2) ";
		if( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_WHITELIST" ||
			Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" )
		{
			std::cout << "popisWhitelistanihImenaFunkcijaPoCjelinama";
			if( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" )
			{
				std::cout << "\n3) popisBlacklistanihImenaFunkcijaPoCjelinama";
			}
		}
		else { std::cout << "popisBlacklistanihImenaFunkcijaPoCjelinama"; }
		std::cout << "\nIli bilo koji drugi znak za izlazak";
		puts( "\n---------------------------------------------" );

		std::cout << "Tvoj odabir: "; std::cin >> odabir;
		puts( "" );
		std::cin.seekg( std::cin.end );
		switch( odabir )
		{
			case '1':
				Master::goToTheWantedFunctionAndThen( Master::popisImenaFunkcijaPoCjelinama, Master::filter );
				break;
			case '2':
				if( useWhitelistFilter )	Master::goToTheWantedFunctionAndThen( Master::popisWhitelistanihImenaFunkcijaPoCjelinama, Master::filter );
				else						Master::goToTheWantedFunctionAndThen( Master::popisBlacklistanihImenaFunkcijaPoCjelinama, Master::filter );
				break;
			case '3':
				if( availableOptions < 3 )	{ wantToContinue = false; break; }
				Master::goToTheWantedFunctionAndThen( Master::popisBlacklistanihImenaFunkcijaPoCjelinama, Master::filter );
				break;
			default:	wantToContinue = false;
		}
	}
}

void Master::filter( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije, std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama )
{
	auto getContainerName = [&]() -> std::string_view
	{
		if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )	return "popisImenaFunkcijaPoCjelinama";
		else if( &spremnikFunkcijaPoCjelinama == &Master::popisWhitelistanihImenaFunkcijaPoCjelinama )	return "popisWhitelistanihImenaFunkcijaPoCjelinama";
		else if( &spremnikFunkcijaPoCjelinama == &Master::popisBlacklistanihImenaFunkcijaPoCjelinama )	return "popisBlacklistanihImenaFunkcijaPoCjelinama";
		else return "ERROR";
	};

	const char OFFSET = 1;

	std::string_view containerName = getContainerName();
	assert( containerName != "ERROR", "not yet supported functionality" );

	std::cout << "Imas sljedece opcije:\n";
	if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
		std::cout << "1) Dodaj funkciju u \"" << containerName << "\" spremnik/nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";
	else
		std::cout << "1) Ukloni funkciju iz \"" << containerName << "\" spremnika/nUnesi bilo koji drugi znak ako zelis obustavit trenutacnu operaciju\n\n";

	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik1 = Master::popisWhitelistanihImenaFunkcijaPoCjelinama;
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnik2 = Master::popisBlacklistanihImenaFunkcijaPoCjelinama;
	char odabir;
	std::cout << "Tvoj odabir: "; std::cin >> odabir;
	std::cin.seekg( std::cin.end );
	switch( odabir )
	{
		case '1':
			if( &spremnikFunkcijaPoCjelinama == &Master::popisImenaFunkcijaPoCjelinama )
			{
				std::cout << "Imas sljedece opcije:\n"
					<< "w) ako zelis spremit funkciju u whitelist filter\n"
					<< "b) ako zelis spremit funkciju u blacklist filter\n"
					<< "Bilo koji drugi znak za obustavljanje operacije\n\n";
				std::cout << "Tvoj odabir: "; std::cin >> odabir;

				if( odabir == 'w' || odabir == 'b' )
				{
					std::vector<bool> vTracker1;
					vTracker1.reserve( 5 );
					std::vector<bool> vTracker2;
					vTracker2.reserve( 5 );

					vTracker1.push_back( spremnik1.size() >= odabirProjekta + OFFSET );
					vTracker2.push_back( spremnik2.size() >= odabirProjekta + OFFSET );

					vTracker1.push_back( vTracker1.back() == true && spremnik1[odabirProjekta].contains( odabirCjeline + OFFSET ) );
					vTracker2.push_back( vTracker2.back() == true && spremnik2[odabirProjekta].contains( odabirCjeline + OFFSET ) );

					vTracker1.push_back( vTracker1.back() == true && spremnik1[odabirProjekta + OFFSET][odabirCjeline].contains( odabirFunkcije ) );
					vTracker2.push_back( vTracker2.back() == true && spremnik2[odabirProjekta + OFFSET][odabirCjeline].contains( odabirFunkcije ) );

					if( vTracker1.back() == false && vTracker2.back() == false )
					{
						auto entry = spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline][odabirFunkcije];
						if( odabir == 'w' )
						{
							while( spremnik1.size() < odabirProjekta + OFFSET )	spremnik1.push_back( {} );
							spremnik1[odabirProjekta][odabirCjeline][odabirFunkcije] = entry;
						}
						else if( odabir == 'b' )
						{
							while( spremnik2.size() < odabirProjekta + OFFSET )	spremnik2.push_back( {} );
							spremnik2[odabirProjekta][odabirCjeline][odabirFunkcije] = entry;
						}
					}

				}
				else return;

			}
			else
			{
				/// ukloni iz filtera
				if( spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline].contains( odabirFunkcije ) )
					spremnikFunkcijaPoCjelinama[odabirProjekta][odabirCjeline].erase( odabirFunkcije );
			}
			break;
		default: return;
	}

}


void Master::ucitajPocetniPopisFunkcija()
{

	for( size_t idx = 0; idx < Master::popisProjekata.size(); ++idx )
	{
		// provjeri sadrzi ime projekta koji je valjan
		if( Master::popisFiltriranihImenaFunkcijaPoCjelinama.size() < idx + 1 )
			Master::popisFiltriranihImenaFunkcijaPoCjelinama.push_back( {} );
		for( auto& cjelina : Master::popisImenaFunkcijaPoCjelinama[idx] )
		{
			if( !Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].contains( cjelina.first ) )
				Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx][cjelina.first] = {};
			auto& it = Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].at( cjelina.first );
			for( auto& zadatakData : cjelina.second )
			{
				if( !it.contains( zadatakData.first ) )
					it.insert( zadatakData );
			}
		}
	}
}

void Master::removeIncompatibleFunctions()
{
	if( Master::popisFiltriranihImenaFunkcijaPoCjelinama.empty() )	return;

	for( size_t idx = 0; idx < Master::popisProjekata.size(); ++idx )
	{
		if( Master::popisFiltriranihImenaFunkcijaPoCjelinama.size() < idx )	break;
		// provjeri sadrzi ime projekta koji je valjan
		auto cjelinaCurIt = Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].begin();
		while( cjelinaCurIt != Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].end() )
		{
			if( !Master::popisImenaFunkcijaPoCjelinama[idx].contains( cjelinaCurIt->first ) ||
				( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" ||
				  Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_WHITELIST" ) &&
				  Master::popisWhitelistanihImenaFunkcijaPoCjelinama.size() > idx &&
				  !Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].contains( cjelinaCurIt->first )
				  ||
				( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" ||
				  Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_BLACKLIST" ) &&
				  Master::popisBlacklistanihImenaFunkcijaPoCjelinama.size() > idx &&
				  Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].contains( cjelinaCurIt->first )
				)
			{
				Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].erase( cjelinaCurIt->first );
				cjelinaCurIt = Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].begin();
				continue;
			}
			else ++cjelinaCurIt;

		}
	}
}

void Master::helpFunc_removeIncompatibleFilter( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFilterskihFunkcija )
{
	if( spremnikFilterskihFunkcija.size() == 0 )
	{
		std::clog << "spremnikFilterskihFunkcija je prazan\n";
		return;
	}

	for( size_t idx = 0; idx < Master::popisProjekata.size(); ++idx )
	{
		// provjeri sadrzi ime projekta koji je valjan
		if( idx >= spremnikFilterskihFunkcija.size() )	return;/// promijeni u break ako budes dodavo funkcionalnst
		for( auto& cjelina : spremnikFilterskihFunkcija[idx] )
		{
			if( !Master::popisImenaFunkcijaPoCjelinama[idx].contains( cjelina.first ) )
			{
				spremnikFilterskihFunkcija[idx].erase( cjelina.first );
				continue;
			}
			for( auto& zadatakData : cjelina.second )
			{
				if( !Master::popisImenaFunkcijaPoCjelinama[idx].at( cjelina.first ).contains( zadatakData.first ) )
					spremnikFilterskihFunkcija[idx].at( cjelina.first ).erase( zadatakData.first );
			}
		}
	}
}

void Master::removeIncompatibleFilters()
{
	Master::helpFunc_removeIncompatibleFilter( Master::popisWhitelistanihImenaFunkcijaPoCjelinama );
	Master::helpFunc_removeIncompatibleFilter( Master::popisBlacklistanihImenaFunkcijaPoCjelinama );
}

void Master::applyFilters()
{
	if( Master::popisFiltriranihImenaFunkcijaPoCjelinama.empty() )	return;

	for( size_t idx = 0; idx < Master::popisProjekata.size(); ++idx )
	{
		if( Master::popisFiltriranihImenaFunkcijaPoCjelinama.size() < idx )	break;
		// provjeri sadrzi ime projekta koji je valjan
		for( auto& cjelina : Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx] )
		{
			std::multimap<const std::string, std::string> foundWhitelistedFilters;
			auto ZadatakCurIt = cjelina.second.begin();
			while( ZadatakCurIt != cjelina.second.end() )
			{
				// zbog jednostavnosti, logika je unazad. Ukoliko ne zadovoljava uvjete, izbrisi ga.							
				if( Master::popisImenaFunkcijaPoCjelinama[idx].at( cjelina.first ).contains( ZadatakCurIt->first ) )
				{
					if( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" ||
						Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_WHITELIST" )
					{
						if( Master::popisWhitelistanihImenaFunkcijaPoCjelinama.size() > idx &&
							Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].contains( cjelina.first ) )
						{
							if( !Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].empty() &&
								Master::popisWhitelistanihImenaFunkcijaPoCjelinama[idx].at( cjelina.first ).contains( ZadatakCurIt->first ) )
							{
								++ZadatakCurIt;
								continue;
							}
							else
							{
								foundWhitelistedFilters.insert( { cjelina.first, ZadatakCurIt->first } );
								++ZadatakCurIt;
								continue;
							}
						}
					}

					if( Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "BOTH" ||
						Master::konfiguracijskePostavke.at( "USE_FILTERS" ) == "ONLY_BLACKLIST" )
					{
						if( Master::popisBlacklistanihImenaFunkcijaPoCjelinama.size() > idx &&
							!Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].empty() &&
							Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].contains( cjelina.first ) )
						{
							if( !Master::popisBlacklistanihImenaFunkcijaPoCjelinama[idx].at( cjelina.first ).contains( ZadatakCurIt->first ) )
							{
								++ZadatakCurIt;
								continue;
							}
						}
						else
						{
							++ZadatakCurIt;
							continue;
						}
					}
				}

				Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].at( cjelina.first ).erase( ZadatakCurIt->first );
				ZadatakCurIt = cjelina.second.begin();

			}
			for( const auto& itemToDelete : foundWhitelistedFilters )
				Master::popisFiltriranihImenaFunkcijaPoCjelinama[idx].at( itemToDelete.first ).erase( itemToDelete.second );
			foundWhitelistedFilters.clear();
		}
	}

}

void Master::helpFunc_repeatStepIfDesiredOfSavingFilter( const bool isWhitelistFile )
{
	char odabir;
	while( !Master::helpFunc_saveOrOverwriteFilterFile( isWhitelistFile ) )	// ako si nesto zeznuo imas priliku ponovit postupak
	{
		std::cout << "\nImas sljedece opcije:\n"
			<< "1) ponovi postupak\n"
			<< "Bilo koji drugi znak da nastavis na sljedeci korak\n\n";
		std::cout << "Tvoj odabir: "; std::cin >> odabir;
		std::cin.seekg( std::cin.end );
		if( odabir != '1' )	return;
	}
}

/// funkcija sluzi za spremanje filterskeDatoteke
/// funkcija vraca vrijednost true: u slucaju ako je usjesno spremljena datoteka ili
/// vraca vrijednost false: ako si slucajno krivo unijeo ili nezelis spremit filter
bool Master::helpFunc_saveOrOverwriteFilterFile( const bool isWhitelistFile )
{
	char odabir;
	std::cout << "Imas sljedece opcije:\n"
		<< "1) Ako zelis overwrite-tat default filtersku datoteku " << ( isWhitelistFile ? "whitelist" : "blacklist" ) << '\n'
		<< "2) Ako zelis spremit filtersku datoteku pod custom imenom\n"
		<< "Bilo koji drugi znak za obustavljanje operacije\n\n";
	std::cout << "Tvoj odabir: "; std::cin >> odabir;
	std::cin.seekg( std::cin.end );

	nlohmann::json json;
	std::string pathToFile = "filter\\";
	std::ofstream filter;
	switch( odabir )
	{
		case '1':
			pathToFile += ( isWhitelistFile ? "whitelist" : "blacklist" );
			pathToFile += ".json";
			filter.open( pathToFile, std::ios::out, std::ios::trunc );
			if( filter.is_open() )
			{
				json = Master::convertToJson( /*from*/ ( isWhitelistFile ? Master::popisWhitelistanihImenaFunkcijaPoCjelinama : Master::popisBlacklistanihImenaFunkcijaPoCjelinama ) );
				filter << json;
				return true;
			}
			else return false;

			break;
		case '2':
		{
			std::string imeDatoteke;
			std::cout << "Unesi ime filterske datoteke (bez ekstenzije): ";
			std::getline( std::cin, imeDatoteke );
			imeDatoteke += ".json";
			pathToFile += imeDatoteke;
			if( std::ifstream( pathToFile, std::ios::in ).is_open() )
			{
				std::cout << "Filterska datoteka sa tim imenom vec postoji!\n"
					<< "Ako je zelis overwrite-at, upisi znak '\y'\: ";
				char input;
				std::cin >> input;
				if( tolower( input ) == 'y' )
				{
					filter.open( pathToFile, std::ios::out, std::ios::trunc );
					if( filter.is_open() )
					{
						json = Master::convertToJson( /*from*/ ( isWhitelistFile ? Master::popisWhitelistanihImenaFunkcijaPoCjelinama : Master::popisBlacklistanihImenaFunkcijaPoCjelinama ) );
						filter << json;
						return true;
					}
				}
				else return true;
			}
			else
			{
				filter.open( pathToFile, std::ios::out, std::ios::trunc );
				if( filter.is_open() )
				{
					json = Master::convertToJson( /*from*/ ( isWhitelistFile ? Master::popisWhitelistanihImenaFunkcijaPoCjelinama : Master::popisBlacklistanihImenaFunkcijaPoCjelinama ) );
					filter << json;
					return true;
				}
			}

			break;
		}
		default: return false;
	}
}


[[nodiscard]] nlohmann::json Master::convertToJson( /*from*/ std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> spremnikFunkcijaPoCjelinama )
{
	nlohmann::json jRetVal;
	std::vector<nlohmann::json::object_t> jNizProjekata( spremnikFunkcijaPoCjelinama.size() );
	nlohmann::json::object_t jBrojCjeline;
	nlohmann::json::array_t jZadaci;
	nlohmann::json::object_t jZadatak;


	for( size_t idx = 0; idx < spremnikFunkcijaPoCjelinama.size(); ++idx )
	{
		for( auto& cjelina : spremnikFunkcijaPoCjelinama[idx] )
		{
			if( cjelina.second.empty() )	break;
			for( auto& zadatakData : cjelina.second )
			{
				jZadatak["tekst"] = zadatakData.second.first.tekst;
				jZadatak["deklaracija"] = zadatakData.second.first.deklaracija;
				jZadatak["kod"] = zadatakData.second.first.kod;
				jZadaci.emplace_back( jZadatak );
			}
			jBrojCjeline[cjelina.first]["Zadaci"] = jZadaci;
			jZadaci.clear();
		}
		jNizProjekata[idx][Master::popisProjekata[idx]]["Broj cjeline"].emplace_back( jBrojCjeline );
		jBrojCjeline.clear();
	}
	jRetVal["projekt"] = jNizProjekata;
	return jRetVal;
}

void Master::saveFilterFiles()
{
	char odabir;
	if( Master::konfiguracijskePostavke["SAVE_FILTERS"] == "ASK" )
	{
		if( !Master::popisWhitelistanihImenaFunkcijaPoCjelinama.empty() )
		{
			std::cout << "Ako zelis spremit trenutacni whitelist filter, unesi znak 'y': ";
			std::cin >> odabir;
			std::cin.seekg( std::cin.end );
			if( tolower( odabir ) == 'y' ) helpFunc_repeatStepIfDesiredOfSavingFilter( true );
		}

		if( !Master::popisBlacklistanihImenaFunkcijaPoCjelinama.empty() )
		{
			std::cout << "Ako zelis spremit trenutacni blacklist filter, unesi znak 'y': ";
			std::cin >> odabir;
			std::cin.seekg( std::cin.end );
			if( tolower( odabir ) == 'y' )	helpFunc_repeatStepIfDesiredOfSavingFilter( false );
		}
	}
	else if( Master::konfiguracijskePostavke["OVERWRITE_FILTERS"] == "ONLY_WHITELIST" )
	{
		if( !Master::popisWhitelistanihImenaFunkcijaPoCjelinama.empty() )
			helpFunc_repeatStepIfDesiredOfSavingFilter( true );
	}
	else if( Master::konfiguracijskePostavke["OVERWRITE_FILTERS"] == "ONLY_BLACKLIST" )
	{
		if( !Master::popisBlacklistanihImenaFunkcijaPoCjelinama.empty() )
			helpFunc_repeatStepIfDesiredOfSavingFilter( false );
	}
	else if( Master::konfiguracijskePostavke["OVERWRITE_FILTERS"] == "ALWAYS" )
	{
		if( !Master::popisWhitelistanihImenaFunkcijaPoCjelinama.empty() )
			helpFunc_repeatStepIfDesiredOfSavingFilter( true );

		if( !Master::popisBlacklistanihImenaFunkcijaPoCjelinama.empty() )
			helpFunc_repeatStepIfDesiredOfSavingFilter( false );
	}
	else std::cerr << "ERROR; Nevazeca konfiguracijska postavka!\n";
}

std::pair<std::optional<json>, std::optional<json>> Master::helpFunc_odaberiFiltere()
{
	std::pair<std::optional<json>, std::optional<json>> retVal;
	std::vector<std::string> pathsDoFiltera;
	pathsDoFiltera.reserve( 8 );

	std::cout << "\nImas sljedece filtere za izabrat:\n";
	size_t idx = 1;
	for( const auto& entry : fs::directory_iterator( "filter" ) )
	{
		const auto& entryStr = entry.path().string();
		std::string_view nazivFiltra( std::find( entryStr.cbegin(), entryStr.cend(), '\\' ) + 1, entryStr.end() );
		std::cout << idx << ") " << nazivFiltra << '\n';
		pathsDoFiltera.emplace_back( entryStr );
		++idx;
	}
	char odabir;
	std::cout << "0) za praznjenje spremnika\n"
		<< "-1) za preskakanje\n";
	puts( "--------------------------------------\n" );
	std::cout << "Tvoj odabir whitelist filtera: "; std::cin >> odabir;
	std::cin.seekg( std::cin.end );
	if( odabir == '-' )
	{
		std::cout << "Preskacem ovaj filter!\n";
	}
	else if( odabir < '0' || odabir > '0' + idx )
	{
		std::cout << "Nevazeci unos!\n";
	}
	else if( odabir == '0' )
	{
		retVal.first = json();
	}
	else
	{
		retVal.first = Master::getJSONFromFile( pathsDoFiltera[odabir - '0' - 1].c_str() );
	}
	puts( "=============================\n" );

	std::cout << "Tvoj odabir blacklist filtera: "; std::cin >> odabir;
	std::cin.seekg( std::cin.end );
	if( odabir == '-' )
	{
		std::cout << "Preskacem ovaj filter!\n";
	}
	else if( odabir < '0' || odabir > '0' + idx )
	{
		std::cout << "Nevazeci unos!\n";
	}
	else if( odabir == '0' )
	{
		retVal.second = json();
	}
	else
	{
		retVal.second = Master::getJSONFromFile( pathsDoFiltera[odabir - '0' - 1].c_str() );
	}
	puts( "=============================\n" );

	return retVal;
}



void Master::loadFilters()
{
	if( Master::konfiguracijskePostavke.at( "SKIP_LOADING_FILTERS_AT_STARTUP" ) != "NO" )
	{
		std::cerr << "Nevazeca konfiguracijska postavka!\n";
		return;
	}

	std::optional<json> jWhitelist;
	std::optional<json> jBlacklist;
	char odabir = 0;

	if( Master::konfiguracijskePostavke.at( "LOAD_DEFAULT_FILTERS" ) == "ASK" )
	{
		std::cout << "\nImas sljedece opcije:\n"
			<< "1) Za ucitat default filtere ukoliko postoje\n"
			<< "2) Za rucno biranje filtera\n"
			<< "Ili bilo koji drugi znak za preskakanje ucitavanja filtera\n"
			<< "--------------------------------------------------\n";
		std::cout << "Tvoj odabir: "; std::cin >> odabir;
		std::cin.seekg( std::cin.end );
	}

	if( odabir == '1' || Master::konfiguracijskePostavke.at( "LOAD_DEFAULT_FILTERS" ) == "YES" )
	{
		jWhitelist = Master::getJSONFromFile( "filter\\whitelist.json" );
		jBlacklist = Master::getJSONFromFile( "filter\\blacklist.json" );
	}
	if( odabir == '2' || Master::konfiguracijskePostavke.at( "LOAD_DEFAULT_FILTERS" ) == "NO" )
	{
		auto filters = Master::helpFunc_odaberiFiltere();
		jWhitelist = filters.first;
		jBlacklist = filters.second;
	}

	if( jWhitelist.has_value() )
	{
		Master::popuniCijeliPopisFunkcija( /*from*/ jWhitelist.value()["projekt"], /*to*/ Master::popisWhitelistanihImenaFunkcijaPoCjelinama );
		Master::helpFunc_removeIncompatibleFilter( Master::popisWhitelistanihImenaFunkcijaPoCjelinama );
	}
	if( jBlacklist.has_value() )
	{
		Master::popuniCijeliPopisFunkcija( /*from*/ jBlacklist.value()["projekt"], /*to*/ Master::popisBlacklistanihImenaFunkcijaPoCjelinama );
		Master::helpFunc_removeIncompatibleFilter( Master::popisBlacklistanihImenaFunkcijaPoCjelinama );
	}
}

void Master::switchFilters()
{
	auto [jWhitelist, jBlacklist] = Master::helpFunc_odaberiFiltere();

	if( jWhitelist.has_value() )
	{
		Master::popisWhitelistanihImenaFunkcijaPoCjelinama.clear();
		Master::popuniCijeliPopisFunkcija( /*from*/ jWhitelist.value()["projekt"], /*to*/ Master::popisWhitelistanihImenaFunkcijaPoCjelinama );
		Master::helpFunc_removeIncompatibleFilter( Master::popisWhitelistanihImenaFunkcijaPoCjelinama );
	}
	if( jBlacklist.has_value() )
	{
		Master::popisBlacklistanihImenaFunkcijaPoCjelinama.clear();
		Master::popuniCijeliPopisFunkcija( /*from*/ jBlacklist.value()["projekt"], /*to*/ Master::popisBlacklistanihImenaFunkcijaPoCjelinama );
		Master::helpFunc_removeIncompatibleFilter( Master::popisBlacklistanihImenaFunkcijaPoCjelinama );
	}
}

/// //////// ////////// ////////////// /////////////////////// ///////////////


const auto dodajItemeUVektor = []( std::vector<std::string>& container, const char* fullPath )
{
	for( const auto& entry : fs::directory_iterator( fullPath ) ) {
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
	Master::_INTERNAL::unesiKonfiguracijskePostavke();
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	std::ofstream( "Data\\" + nazivJSONdat, std::ios::app );	// stvori datoteku ukoliko vec nepostoji
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

			if( isPopisProjekataEmpty )	Master::popisProjekata.emplace_back( projectName );
			popisImenaFunkcijaPoCjelinama.push_back( {} );
			popisFunkcija.push_back( {} );
		}
		popuniCijeliPopisFunkcija(/*from*/ jsonData["projekt"], /*to*/ Master::popisImenaFunkcijaPoCjelinama, odabir == '1' );
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
		std::cin.seekg( std::cin.end );
		puts( "===================================" );
		if( odabir == '1' )
		{
			std::optional<nlohmann::json> optJsonData;
			optJsonData = Master::getJSONFromFile( "Data\\InformacijeOZadacima.json" );
			if( optJsonData.has_value() )
			{
				jsonData = std::move( optJsonData.value() );
				pripremiProgramZaKoristenje();
				///	Master::_INTERNAL::enforceCorrectBehaviour();	trenutacno nemoze tocno detektirat mjesto
			}
			else
			{
				std::cerr << "NEMOGU NASTAVIT; NEMA DATOTEKE \"InformacijeOZadacima.json\"/n";
				exit( EXIT_FAILURE );
			}
		}
		else if( odabir == '0' ) // napravi backup trenutacnih datoteka i izradi nove datoteke sa zadacima
		{
			std::cout << "Pravim kopiju JSON datoteke i brisem original!\n\n";
			auto copy_file = []( std::fstream& copyFrom, std::ofstream& copyTo ) {
				std::string strFile;
				while( !copyFrom.eof() )
				{
					strFile += copyFrom.get();
				}
				if( strFile[strFile.size() - 1] == 'ÿ' )
					strFile.resize( strFile.size() - 1 );
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
			curJSON.close();
			backup.close();
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
			curJSON.close();
			backup.close();
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
			curJSON.close();
			backup.close();

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
	for( ; idx[0] < popisProjekata.size();)
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
				std::cout << "\n\nNema niti jedne ucitane funkcije u ovoj cjelini :(\nOvo se moglo dogoditi jer nisi ponovno kompajlao program kao sto si trebao ili "
					"ako si rucno izbrisao sve funkcije iz \"Function list.cpp\" datoteke ili datoteka nije podrzana u trenutacnoj verziji programa (pogledaj "
					"odjeljak \"OGRANICENJE\" na vrhu main.cpp ili se jednostavno u datoteci koju si stavio pod path "
					"\"_Projekti\\imeProjekta\\FilesToParse\\imeDatoteka\" ne nalazi niti jedna funkcija.\n"
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

				std::cout << "\nBroj funkcija pronadenih u datoteci \"Function list.cpp\" ne odgovara broju zadataka koji su spremljeni u json datoteku za projekt: "
					<< popisProjekata[idx[0]];
				puts( "\n--------------------------------------------\n" );
				isFirstTimePrinted = true;
			}

			ukupanBrojZadatakaUProjektu -= item->second.size();
			std::string nazivNajveceCjeline = item->first;
			for( const auto& cjelina : Master::popisImenaFunkcijaPoCjelinama[idx[0]] )
			{
				if( cjelina.first > nazivNajveceCjeline )
					nazivNajveceCjeline = cjelina.first;
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
		else
			++idx[0];
	}
}

nlohmann::json Master::_INTERNAL::create_json_Object()
{
	nlohmann::json jsonData;
	std::string nazivJSONdat = "InformacijeOZadacima.json";
	if( std::ifstream JSON_existingDatoteka( "Data\\" + nazivJSONdat, std::ios::in );
		!JSON_existingDatoteka.is_open() || std::filesystem::file_size( "Data\\" + nazivJSONdat ) == 0 )
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

		/// TODO //////////////////////////////////////////////////////////////////////
		// otvori datoteke za filtriranje
		std::ifstream whitelistDat( "filtriranje\\whitelist.json" );
		std::ifstream blacklistDat( "filtriranje\\blacklist.json" );
		/// ///////////////////////////////////////////////////////////////////////////

		dodajItemeUVektor( Master::popisProjekata, "_Projekti" );
		if( Master::konfiguracijskePostavke.at( "FILTER" ) == "ALLOW" && Master::konfiguracijskePostavke.at( "FILTER_WHILE" ) == "PROCESSING" )
		{
			/// TODO
			/// blacklist or whitelist projekt koji ima odredeno ime
			/// (trenutacno nema funkcionalnost za unijet samo tu stavku)
			if( true )
			{

			}

		}

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
			for( const auto& path : paths )
			{
				imenaDatoteka.push_back( {} );
				dodajItemeUVektor( imenaDatoteka[idx], path.data() );
				++idx;
			}
		}

		std::cout << "Parsing files...";
		std::vector<ParseFile> pfs;
		std::vector<std::unique_ptr<Zadatak>> zadaci;
		zadaci.reserve( 8 );
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
		for( size_t idx = 0, upotrijebljenoZadataka = 0; idx < paths.size(); ++idx )
		{
			puts( "\n--------------------------------------------" );
			pfs.emplace_back( paths[idx], imenaDatoteka[idx] );
			size_t idxOfFile = 0;
			nizProjekata.emplace_back( nlohmann::json::object_t() );
			for( const auto& fName : imenaDatoteka[idx] )
			{
				if( Master::konfiguracijskePostavke.at( "FILTER" ) == "ALLOW" && Master::konfiguracijskePostavke.at( "FILTER_WHILE" ) == "PROCESSING" )
				{
					/// TODO
					/// blacklist or whitelist datoteku koja ima odredeno ime
					/// (trenutacno nema funkcionalnost za unijet samo tu stavku)

					if( false )
					{
						continue;
					}
				}

				bool DEBUG_FLAG = false; /*	DEBUG_FLAG = fName == "Cjelina101.cpp"; */


				pfs[idx].readFile( pfs[idx].getDatoteku( idxOfFile ), zadaci, upotrijebljenoZadataka, DEBUG_FLAG );

				/// zadaci stizu po cjelinama u kojima se nalaze
				puts( "" );
				++idxOfFile;

				if( Master::konfiguracijskePostavke.at( "FILTER" ) == "ALLOW" && Master::konfiguracijskePostavke.at( "FILTER_WHILE" ) == "PROCESSING" )
				{
					/// process whitelisting from user file
					void* cur;
					if( true )
					{

					}

				}

				// popuni JSON objekt kako parsira datoteke
				json::object_t zadaciCjeline = Master::_INTERNAL::processZadatke( zadaci, upotrijebljenoZadataka, fName );
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
			std::for_each( imenaDatoteka[idx].begin(), imenaDatoteka[idx].end(), []( const std::string_view imeDatoteke, int l_idx = 0 ){
				if( true )	std::cout << imeDatoteke << '/n';	/// TODO: ispis zavisi nalazi li se ime u vektoru tipa bool
			} );
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
//


std::optional<nlohmann::json> Master::getJSONFromFile( const char* path )
{
	std::ifstream jsonDat( path, std::ios::in );
	json retVal;
	if( jsonDat.is_open() && std::filesystem::file_size( path ) > 0 )	{ jsonDat >> retVal; return retVal; }
	return std::nullopt;
}

void Master::_INTERNAL::unesiKonfiguracijskePostavke()
{
	std::ifstream cfg( "conf.ig", std::ios::in );
	if( cfg.is_open() )
	{
		char preth, cur;
		std::string key;
		key.reserve( 20 );
		std::string value;
		value.reserve( 20 );
		while( !cfg.eof() )
		{
		start:
			if( konfiguracijskePostavke.size() > 15 )	break;
			key.clear();
			value.clear();

			preth = cur = 0;
			key.clear();
			while( !cfg.eof() && cfg.peek() != '[' )
			{
				preth = cur;
				cur = cfg.get();
				if( preth == '/' && cur == '/' ) goto start;
			}
			cfg.get();
			while( !cfg.eof() && key.length() < 50 && cfg.peek() != ']' ) key += cfg.get();
			if( key.empty() )	continue;
			cfg.get();
			if( cfg.eof() )	break;
			while( isspace( cfg.peek() ) ) cfg.get();
			if( cfg.eof() )	break;
			while( !cfg.eof() && value.length() < 1024 && !isspace( cfg.peek() ) ) value += cfg.get();
			if( !value.empty() && !key.empty() ) Master::konfiguracijskePostavke[key] = value;
			value.clear();
		}
	}

	// default konfiguracijske postavke
	if( Master::konfiguracijskePostavke.size() < 3 ||
		!Master::konfiguracijskePostavke.contains( "MODE" ) ||
		!Master::konfiguracijskePostavke.contains( "FILTER" ) )
	{
		Master::konfiguracijskePostavke["MODE"] = "USER";
		Master::konfiguracijskePostavke["FILTER"] = "DISALLOW";
		Master::konfiguracijskePostavke["SAVE_FILTERS"] = "ASK";
	}

}
