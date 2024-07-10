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

extern void finish_Function_list__cpp_file();
extern void autoAddeedFunctionsFromFiles();

// dovrsi vracanje u proslo stanje gdje je bilo moguce napravit (vratit datoteku za Macro funkcije, update upotrebu u mainu)
#define DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( IME_NAMESPACE::ime_funkcije )
#define DODAJ_FUNKCIJU2( ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( ime_funkcije )

///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////


void popuniCijeliPopisFunkcija( nlohmann::json& jsonData );
void popuniPopisFunkcijaZa( nlohmann::json& jsonData, const size_t projIdx, std::ostream& funcDat );
////////////////////////////////////////////////////////////////////////////////////
namespace Master
{
	extern std::vector<std::string> popisProjekata;
		// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>> popisImenaFunkcijaPoCjelinama;
	std::vector<std::vector<void ( * )( )>> popisFunkcija;


	namespace _INTERNAL
	{
		std::string_view getFuncReturnType( const Zadatak& zad, size_t& offset );
		std::string_view getNamespace( const Zadatak& zad, size_t& offset );
		std::string_view getFuncName( const Zadatak& zad, size_t& offset );
		std::string_view getFuncArguments( const Zadatak& zad, size_t& offset );
		json::object_t processZadatke( nlohmann::json::object_t& imeProjekta, std::vector<Zadatak*>& zad );
		void insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline );
		nlohmann::json getJSONFromFile();
		std::string getFuncNmsAndName( const std::string& imeNamespacea, const std::string& imeFunkcije );
		void createAFileForStoringFunctionList();
	}
}

static std::string_view universallyExtractFromDeclaration( const Zadatak& zad, size_t& offset )
{
	//zad.deklaracija
	auto startIt = zad.deklaracija.begin() + offset;
	auto curIt = startIt;
	//std::string::const_iterator temp = startIt;

	bool endOfExtractedInfo;
	do
	{
		curIt = std::find_if( curIt, zad.deklaracija.end(), [&]( const char c )
							  {
								  endOfExtractedInfo = isspace( c ) || c == ':' || c == '(' || c == ')';
								  return endOfExtractedInfo;
							  } );
	} while( !endOfExtractedInfo );

	offset += curIt - startIt;
	return std::string_view( startIt, curIt );
}

std::string_view Master::_INTERNAL::getFuncReturnType( const Zadatak& zad, size_t& offset )
{
	std::string_view retVal = universallyExtractFromDeclaration( zad, offset );
	++offset; // preskoci razmak ' '
	return retVal;
}

std::string_view Master::_INTERNAL::getNamespace( const Zadatak& zad, size_t& offset )
{
	std::string_view retVal = universallyExtractFromDeclaration( zad, offset );
	++offset; // za svaki ':' znak
	++offset;
	return retVal;
}

std::string_view Master::_INTERNAL::getFuncName( const Zadatak& zad, size_t& offset )
{
	std::string_view retVal = universallyExtractFromDeclaration( zad, offset );
	offset;
	return retVal;
}

std::string_view Master::_INTERNAL::getFuncArguments( const Zadatak& zad, size_t& offset )
{
	std::string_view retVal( zad.deklaracija.begin() + offset, zad.deklaracija.end() );
	offset = 0;
	return retVal;
}


json::object_t Master::_INTERNAL::processZadatke( json::object_t& imeProjekta, std::vector<Zadatak*>& vecZadaci )
{
	size_t idx = 0;
	size_t brojPreskocenihZnakova = 0;

	json::object_t brojCjeline = json::object();
	json::array_t zadaci = json::array();
	json::object_t zadatak = json::object();

	std::string namespaceName;

	for( const Zadatak* zad : vecZadaci )
	{
		std::string funcReturntype = std::string( getFuncReturnType( *zad, brojPreskocenihZnakova ) );
		namespaceName = std::string( getNamespace( *zad, brojPreskocenihZnakova ) );
		std::string funcName = std::string( getFuncName( *zad, brojPreskocenihZnakova ) );
		std::string_view funcArguments = getFuncArguments( *zad, brojPreskocenihZnakova );	// garantirano da je terminiran

		/// process whitelisting
		///...
		/// process blacklisting
		/// ...

		// zadatak = { { "tekst", "pokrece zad1" }, { "deklaracija", "void zad2()" }, {"func body", "{ int i = 5; }" } };
		zadatak["tekst"] = zad->tekst;
		zadatak["deklaracija"] = zad->deklaracija;
		zadatak["kod"] = zad->kod;

		zadaci.emplace_back( zadatak );
	}
	brojCjeline[namespaceName]["Zadaci"] = zadaci;
	return brojCjeline;
}

void popuniCijeliPopisFunkcija( nlohmann::json& jsonData )
{
	size_t idx = 0;
	std::ofstream datotekaZaSpremanjeFunkcija( "Function list.cpp", std::ios::out | std::ios::app );
	for( const auto& thisProj : Master::popisProjekata )
	{
		popuniPopisFunkcijaZa( jsonData[idx], idx, datotekaZaSpremanjeFunkcija );
		++idx;
	}
	autoAddeedFunctionsFromFiles();
}


void Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline )
{
	size_t funID = 0;
	for( const auto& cjelina : popisImenaFunkcijaPoCjelinama[projIdx] )
	{
		funID += cjelina.second.size();
	}
	container.insert( { funcName, funID } );
}

nlohmann::json Master::_INTERNAL::getJSONFromFile()
{
	std::ifstream jsonDat( "InformacijeOZadacima.json", std::ios::in );
	json retVal;
	if( jsonDat.is_open() )	jsonDat >> retVal;
	return retVal;
}

void Master::_INTERNAL::createAFileForStoringFunctionList()
{
	std::ifstream file( "Function list.cpp", std::ios::in );
	std::ofstream newFile;
	if( !file.is_open() )
	{
		newFile.open( "Function list.cpp", std::ios::out );
	}
	file.open( "Function list.cpp", std::ios::in );
	if( file.is_open() )
	{
		// pripremi datoteku za koristenje
		newFile << "#include <fstream> \
#include <iostream>\
\
\
// nakraju kad se sve funkcije tu dodaju, zatvori funkciju i undefine macroe\
void finish_Functions_cpp_file()\
		{\
			const char* macro1 = \"#undef DODAJ_FUNKCIJU\";\
			const char* macro2 = \"#undef DODAJ_FUNKCIJU2\";\
			std::ofstream datoteka( \"Functions.cpp\", std::ios::out | std::ios::app );\
			if( datoteka.is_open() )\
			{\
				datoteka << \"\n\n\" << '}';\
				datoteka << \"\n\n\n\" << macro1 << '\n' << macro2 << '\n' << EOF;\
			}\
			else\
			{\
				datoteka.open( \"Function list.cpp\", std::ios::out | std::ios::app );\
				if( datoteka.is_open() )\
				{\
					datoteka << \"\n\n\" << '}';\
					datoteka << \"\n\n\n\" << macro1 << '\n' << macro2 << '\n' << EOF;\
				}\
				else\
				{\
					std::cout << \"\n\nGRESKA prilikom zavrsavanja postupka dodavanja funkcija!!\n\";\
					datoteka.close();\
					exit( EXIT_FAILURE );\
				}\
			}\
		}\
		\
		void autoAddeedFunctionsFromFiles()\
		{\
		\
		}\
";

	}
	else
	{
		std::cout << "Nisam mogao otvorit \"Function list\" datoteku\n"
			<< "Izlazim...\n";
		exit( EXIT_FAILURE );
	}
}

std::string Master::_INTERNAL::getFuncNmsAndName( const std::string& imeNamespacea, const std::string& imeFunkcije )
{
	std::string combinedNamespaceAndFunctionName = imeNamespacea + "::" + imeFunkcije;
	return combinedNamespaceAndFunctionName;
}

void popuniPopisFunkcijaZa( nlohmann::json& jsonData, const size_t projIdx, std::ostream& funcDat )
{
	// otvori datoteku u koju ces zapisivat funkcije
	json::object_t cjelEntryObj = jsonData;
	const auto& extractedProjektEntryValue = cjelEntryObj.extract( "Broj cjeline" ); // nazivi projekata su spremljeni u std::map pod. strukturu u json objektu, znaci sortirani su
	std::pair<std::string, json::array_t> cjelineData;
	cjelineData = extractedProjektEntryValue._Getptr()->_Myval;
	std::string brojCjeline = std::move( cjelineData.first );
	std::unordered_map<std::string, size_t> CjelinaX;
	Master::popisImenaFunkcijaPoCjelinama[projIdx].insert( { brojCjeline, std::move( CjelinaX ) } );
	auto& iter = Master::popisImenaFunkcijaPoCjelinama[projIdx].find( brojCjeline )->second;
//	std::clog << "cjelinaData -> " << cjelineData.second << "\n\n";
	for( const auto& zadatak : cjelineData.second )
	{
		std::string imeZadatka = "cj1.zad4_kvadrat"; // <---- procitaj ime zadatka
		Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( iter, projIdx, imeZadatka, brojCjeline );
		// zapisi u datoteku na pravo mjesto sljedece:
	//	"DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( IME_NAMESPACE::ime_funkcije );"
	}
}


//	std::pair<std::string, std::string> name;
/*
	//while( name = getName() )
	{

		//insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, "cj1.zad4_kvadrat" );
		insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, name.first );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad4_kvadrat );
	}
*/

/*
	std::string brojCjeline;

	// radi sljedeci postupak pomocu json datoteke ��

	brojCjeline = "Cjelina1";
	std::unordered_map<std::string, size_t> Cjelina1;
	Master::popisImenaFunkcijaPoCjelinama[projIdx].insert( { brojCjeline, std::move( Cjelina1 ) } );
	{
		auto& iter = Master::popisImenaFunkcijaPoCjelinama[projIdx].find( brojCjeline )->second;
		std::string imeZadatka = "cj1.zad4_kvadrat";
		Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( iter, projIdx, imeZadatka, brojCjeline );
		DODAJ_FUNKCIJU( Cjelina1, zad4_kvadrat );

	}

	*/


	///---------------------------------------------------------------------------------------------------------------------------------------------------------

//	switch( projIdx )
//	{
//		using enum projekt;
//	case /*CppKnjiga*/0:
	//{
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
//	}
//}
/// ///////////////////////////////////////////////////////////////////////////////////////////////////

/* PROTOTIP STRUKTURE JSON DATOTEKE
json:

{
	"projekt": [
		{
			"pathToProj": "D:\\__EDUKACIJA\\PROGRAMIRANJE\\C++\\TEST\\Master program\\_Projekti\\Cpp knjiga",
			"Cpp knjiga": {
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






/*
	// // write to nonexisting key
		//object["five"]["really"]["nested"] = true;

	}
	nlohmann::json::object_t o;
	o["test"] = listaProjekata;

*/