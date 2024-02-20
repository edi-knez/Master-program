//////////////////////////////////////////////////////////////////////
/// VAZNO: funkcije se moraju dodavat u onom redoslijedu u kojem se ubacuje naziv funkcija na popis !!!
//////////////////////////////////////////////////////////////////////
/// Poboljsanja za buducnost:
/// ---------------------------

/// FEATURE: lazy popunjavanje funkcija / imena funkcija / opisa po potrebi
/// FEATURE: dodavanje klasa
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>


#include <array>
#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"
#include "PotrebneDatotekeIDeklaracijeFunkcija.hpp"

#include "ParseFile.hpp"

using json = nlohmann::json;

// nemoze se koristit za dinamicko dodavanje
enum class projekt
{
	BEGIN = 0,
	CppKnjiga = 0,
	FESB,
	razno,
	ThinkLAP,
	END
};


#define DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( IME_NAMESPACE::ime_funkcije )
#define DODAJ_FUNKCIJU2( ime_funkcije ) Master::popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ime_funkcije )

///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////

extern std::vector<const char*> popisProjekata;


void popuniCijeliPopisFunkcija();
void popuniPopisFunkcijaZa( const enum class projekt proj );
extern void addFunctionsFromFiles();
////////////////////////////////////////////////////////////////////////////////////
namespace Master
{
	// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
	std::vector<std::vector<void ( * )( )>> popisFunkcija;


	namespace _INTERNAL
	{
		nlohmann::json buildJSON_structure();
		void processZadatke( nlohmann::json& jsonData );
		void insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const projekt proj, const std::string& funcName, const std::string& brojCjeline );
	}
}

void Master::_INTERNAL::processZadatke( nlohmann::json& json )
{

}

void popuniCijeliPopisFunkcija()
{
	for( projekt cur = projekt::BEGIN; cur < projekt::END; cur = projekt( static_cast<uint8_t>( cur ) + 1 ) )
	{
		popuniPopisFunkcijaZa( cur );
	}
}


void Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const projekt proj, const std::string& funcName, const std::string& brojCjeline )
{
	size_t funID = 0;
	for( auto cjeline : popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )] )
	{
		funID += cjeline.second.size();
	}
	container.insert( { funcName, funID } );
}

// citanje iz JSON datoteke nakon 2. kompilacije
void popuniPopisFunkcijaZa( const enum class projekt proj )
{
//	std::pair<std::string, std::string> name;
/*
	//while( name = getName() )
	{

		//insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, "cj1.zad4_kvadrat" );
		insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, name.first );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad4_kvadrat );
	}
*/

	std::string brojCjeline;
//	ParseFile pf;
	// otvori datoteku naziva "Functions.cpp" i odi na liniju
	brojCjeline = "Cjelina1";
	std::unordered_map<std::string, size_t> Cjelina1;
	Master::popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { brojCjeline, std::move( Cjelina1 ) } );
	{
		auto& iter = Master::popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( brojCjeline )->second;
		std::string imeZadatka = "cj1.zad4_kvadrat";
		Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( iter, proj, imeZadatka, brojCjeline );
		DODAJ_FUNKCIJU( Cjelina1, zad4_kvadrat );

	}
	addFunctionsFromFiles();


	switch( proj )
	{
		using enum projekt;
	case CppKnjiga:
	{
/*
		brojCjeline = "Cjelina1";
		std::unordered_map<std::string, size_t> Cjelina1;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { brojCjeline, std::move( Cjelina1 ) } );
		{
			auto& iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( brojCjeline )->second;
			std::string imeZadatka = "cj1.zad4_kvadrat";
			insertFunctionNameAndIDIntoUMap( iter, proj, imeZadatka, brojCjeline );
			DODAJ_FUNKCIJU( Cjelina1, zad4_kvadrat );

		}

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { brojCjeline, std::move( Cjelina2 ) } );
		{
			auto& iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( brojCjeline )->second;
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad1", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad2", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad3", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad4", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad5", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj2.zad6", brojCjeline );
			DODAJ_FUNKCIJU( Cjelina2, zad1 );
			DODAJ_FUNKCIJU( Cjelina2, zad2 );
			DODAJ_FUNKCIJU( Cjelina2, zad3 );
			DODAJ_FUNKCIJU( Cjelina2, zad4 );
			DODAJ_FUNKCIJU( Cjelina2, zad5 );
			DODAJ_FUNKCIJU( Cjelina2, zad6 );
		}
		*/
	}
	/*
		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj3.zad1", brojCjeline );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj3.zad3", brojCjeline );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj3.zad4", brojCjeline );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj3.zad5", brojCjeline );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad5 );

	}*/
	}
}
/// ///////////////////////////////////////////////////////////////////////////////////////////////////

/*
json:

{
	"projekti": [
		{
			"Cpp knjiga": {
				"pathProj1": "D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti\\Cpp knjiga",
				[
					"Cjelina1": {
						"Zadaci": [
							{
								"tekst": "pokreni zad1",
								"deklaracija": "void Cjelina1::zad1()",
								"func body": "{ int i = 5; }"
							},
							... ostali zadaci
						],
					}
				]
			}
		},
		... ostale cjeline
	],
	... ostali projekti
}
*/
nlohmann::json Master::_INTERNAL::buildJSON_structure()
{
	using namespace nlohmann;
	json data;

	// postavi temelje
	json::array_t nizProjekata = json::array();
	json::object_t imeProjekta = json::object();
	json::object_t brojCjeline = json::object();
	json::array_t zadaci = json::array();
	json::object_t zadatak = json::object();

/*

	zadatak = { { "tekst", "pokrece zad1" }, { "deklaracija", "void zad2()" }, {"func body", "{ int i = 5; }" } };
	zadaci.push_back( zadatak );
	brojCjeline["cjelina X"] = zadaci;
	imeProjekta["project X"]["pathProj1"] = json::value_type::string_t{};
	imeProjekta["project X"]["brCjeline"] = brojCjeline;
	nizProjekata.push_back( imeProjekta );

*/
	data["projekti"] = nizProjekata;
	return data;
}



/*
	// // write to nonexisting key
		//object["five"]["really"]["nested"] = true;

	}
	nlohmann::json::object_t o;
	o["test"] = listaProjekata;

*/