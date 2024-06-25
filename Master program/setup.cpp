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


#define DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( IME_NAMESPACE::ime_funkcije )
#define DODAJ_FUNKCIJU2( ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( ime_funkcije )

///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////



void popuniCijeliPopisFunkcija();
void popuniPopisFunkcijaZa( const size_t projIdx );
////////////////////////////////////////////////////////////////////////////////////
namespace Master
{
	extern std::vector<std::string> popisProjekata;
		// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
	std::vector<std::vector<void ( * )( )>> popisFunkcija;


	namespace _INTERNAL
	{
		nlohmann::json buildJSON_structure();
		std::string_view getFuncReturnType( const Zadatak& zad, size_t& offset );
		std::string_view getNamespace( const Zadatak& zad, size_t& offset );
		std::string_view getFuncName( const Zadatak& zad, size_t& offset );
		std::string_view getFuncArguments( const Zadatak& zad, size_t& offset ); 
		void processZadatke( nlohmann::json& jsonObj, std::vector<Zadatak*>& zad );
		void insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline );
	}
}

std::string_view Master::_INTERNAL::getFuncReturnType( const Zadatak& zad, size_t& offset )
{
	//zad.deklaracija
	auto startIt = zad.deklaracija.begin() + offset;
	auto curIt = startIt;
	std::string::const_iterator temp = startIt;

	bool endOfReturnType;
	do
	{
		temp = std::find_if( startIt, zad.deklaracija.end(), [ & ]( const char c )
							 {
								 endOfReturnType = c == ':' || c == '(';
								 return isspace( c ) || endOfReturnType;
							 } );


		if( !endOfReturnType )	curIt = temp;
		else break;
	} while( true );

	offset += curIt - startIt;
	return std::string_view( startIt, curIt );
}

std::string_view Master::_INTERNAL::getNamespace( const Zadatak& zad, size_t& offset )
{
	return getFuncReturnType( zad, offset );	// zbog univerzalnosti, vrijedi isti kod
}

std::string_view Master::_INTERNAL::getFuncName( const Zadatak& zad, size_t& offset )
{
	return getFuncReturnType( zad, offset );	// zbog univerzalnosti, vrijedi isti kod
}

std::string_view Master::_INTERNAL::getFuncArguments( const Zadatak& zad, size_t& offset )
{
	return std::string_view( zad.deklaracija.begin() + offset, zad.deklaracija.end() );
}


void Master::_INTERNAL::processZadatke( nlohmann::json& jsonObj, std::vector<Zadatak*>& zadaci )
{
	//json::array_t zadaci = json::array();
	std::vector<std::pair<std::string, std::string>> a;
	for( const Zadatak* zad : zadaci )
	{
		size_t idx = 0;
		size_t brojPreskocenihZnakova = 0;
		std::string funcReturntype = std::string( getFuncReturnType( *zad, brojPreskocenihZnakova ) );
		std::string namespaceName = std::string( getNamespace( *zad, brojPreskocenihZnakova ) );
		std::string funcName = std::string( getFuncName( *zad, brojPreskocenihZnakova ) );
		std::string_view funcArguments = getFuncReturnType( *zad, brojPreskocenihZnakova );	// garantirano da je terminiran

		/// process whitelisting
		///...
		/// process blacklisting
		/// ...

		json::object_t zadatak = json::object();
		zadatak["tekst zadatka"] = zad->tekst;
		zadatak["deklaracija"] = zad->deklaracija;
		zadatak["kod"] = zad->kod;
		jsonObj[namespaceName] = zadatak;
	}
//	zapisiDeklaracijeFunkcijaU_Functions__cpp( zadaci );
}

void zapisiDeklaracijeFunkcijaU_Functions__cpp( std::vector<Zadatak*>& vecZadataka )
{
	const char* path{ "D:\__EDUKACIJA\PROGRAMIRANJE\C++\TEST\Master program\Master program" };
	std::vector<std::string> imenaDatoteka;
	imenaDatoteka.push_back( std::string( "Functions.cpp" ) );
	// otvori datoteku naziva "Functions.cpp" i odi na liniju
	ParseFile pf( std::string_view( path ), imenaDatoteka );
	std::fstream& dat = pf.getDatoteku( 0 );
	pf.getPositionOfFunction( dat, imenaDatoteka[0].c_str() );
	pf.skipFuncBody( dat );
	dat.seekg( -1, std::ios::cur );

	for( const auto zad : vecZadataka )
	{
		dat << zad->deklaracija << '\n';	//TODO: ->>>>>>>>>>>>>>>>>>>>>>>>>>> procitaj filtrirano iz json datoteke
	}
	dat << '}' << '\n';
}

void popuniCijeliPopisFunkcija()
{
	size_t projIdx = 0;
	// citanje iz json objekta
	for( const auto thisProj : Master::popisProjekata )
	{
		popuniPopisFunkcijaZa( projIdx++ );
	}
}


void Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline )
{
	size_t funID = 0;
	for( auto cjeline : popisImenaFunkcijaPoCjelinama[projIdx] )
	{
		funID += cjeline.second.size();
	}
	container.insert( { funcName, funID } );
}

/// citanje iz JSON objekta nakon 2. kompilacije
void popuniPopisFunkcijaZa( const size_t projIdx )
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

	// radi sljedeci postupak pomocu json datoteke ¢¢

	brojCjeline = "Cjelina1";
	std::unordered_map<std::string, size_t> Cjelina1;
	Master::popisImenaFunkcijaPoCjelinama[projIdx].insert( { brojCjeline, std::move( Cjelina1 ) } );
	{
		auto& iter = Master::popisImenaFunkcijaPoCjelinama[projIdx].find( brojCjeline )->second;
		std::string imeZadatka = "cj1.zad4_kvadrat";
		Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( iter, projIdx, imeZadatka, brojCjeline );
		DODAJ_FUNKCIJU( Cjelina1, zad4_kvadrat );

	}
	//autoAddedFunctionsFromFiles(); ????????????????????????????????????


	switch( projIdx )
	{
//		using enum projekt;
	case /*CppKnjiga*/0:
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
	"projekt": [
		{
			"Cpp knjiga": {
				"pathProj": "D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti\\Cpp knjiga",
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
	data["projekt"] = nizProjekata;
	return data;
}





/*
	// // write to nonexisting key
		//object["five"]["really"]["nested"] = true;

	}
	nlohmann::json::object_t o;
	o["test"] = listaProjekata;

*/