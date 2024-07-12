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
#include <optional>

#include <array>
#include <vector>
#include <unordered_map>

#include "../_Includes/json.hpp"
#include "PotrebneDatotekeIDeklaracijeFunkcija.hpp"

#include "ParseFile.hpp"

using json = nlohmann::json;

extern void finish_Function_list__cpp_file( std::fstream& datoteka );
extern void autoAddeedFunctionsFromFiles();

// dovrsi vracanje u proslo stanje gdje je bilo moguce napravit (vratit datoteku za Macro funkcije, update upotrebu u mainu)
//#define DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( IME_NAMESPACE::ime_funkcije )
//#define DODAJ_FUNKCIJU2( ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( ime_funkcije )

///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////


void popuniCijeliPopisFunkcija( nlohmann::json& jsonData );
void popuniPopisFunkcijaZa( nlohmann::json& jsonData, const size_t projIdx, std::ostream& funcDat, char HACK_isItStepNumber3 );
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
	/// TOOO: handle-aj slucaj da nema nemaspace-a da ga mozes blacklistat
		if( namespaceName == "" )	continue;
		if( funcName == "operator=" ) continue;

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
	const char* relativePathToFile = "Data\\";
	std::vector<std::string> imeDatotekeZaFunkcije = { "Function list.cpp" };
	ParseFile pf( std::string_view( relativePathToFile ), imeDatotekeZaFunkcije );
	std::fstream& datotekaZaSpremanjeFunkcija = pf.getDatoteku( 0 );
	/// ///////////////////////////////////////////////////////
	char HACK_isItStepNumber3;
	std::cout << "Ako si na koraku 3) (za vise informacija pogledaj na vrh \"main.cpp\" datoteke unesi znak y: ";
	std::cin >> HACK_isItStepNumber3;
	puts( "" );
	if( HACK_isItStepNumber3 == 'y' )
	{
		// zapisi u datoteku na pravo mjesto:

		// ukoliko funkcija sa tim imenom postoji, pronaci ce je. U suprotnom neces moci kompajlat program.
		std::optional<size_t> writingPosition;
		do
		{
			writingPosition = pf.getPositionOfFunction( datotekaZaSpremanjeFunkcija, "autoAddeedFunctionsFromFiles" );
		} while( !writingPosition.has_value() && !datotekaZaSpremanjeFunkcija.eof() );

		if( datotekaZaSpremanjeFunkcija.eof() )
		{
			std::cout << "Ovo se jedino moglo dogodit jer si izbrisao forward deklaraciju funkcije \"autoAddedFunctionsFromFiles\" sa vrha ove .cpp datoteke\nIzlazim...\n";
			exit( EXIT_FAILURE );
		}
		datotekaZaSpremanjeFunkcija.seekp(writingPosition.value() + 2 );
	}
	/// //////////////////////////////////////////////////////////


	size_t idx = 0;
	for( const auto& thisProj : Master::popisProjekata )
	{
		popuniPopisFunkcijaZa( jsonData[idx], idx, datotekaZaSpremanjeFunkcija, HACK_isItStepNumber3 );
		++idx;
	}


	/// /////////////////////////////////////////////////////////
	if( HACK_isItStepNumber3 == 'y' )
	{
		finish_Function_list__cpp_file( datotekaZaSpremanjeFunkcija );
		std::cout << "Ponovno kompaliraj program da bi nastavio na sljedeci korak\nIzlazim...\n";
		exit( EXIT_SUCCESS );
	}
	/// //////////////////////////////////////////////////////////

	autoAddeedFunctionsFromFiles();	// ubaci sve function pointere popisFunkcija
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
	std::ifstream jsonDat( "Data\\InformacijeOZadacima.json", std::ios::in );
	json retVal;
	if( jsonDat.is_open() )	jsonDat >> retVal;
	return retVal;
}

void popuniPopisFunkcijaZa( nlohmann::json& jsonData, const size_t projIdx, std::ostream& funcDat, const char HACK_isItStepNumber3 )
{
	// otvori datoteku u koju ces zapisivat funkcije
	json::object_t cjelEntryObj = jsonData.begin().value();
///	std::clog << "\n\n" << cjelEntryObj << "\n\n";
	const auto& extractedCjelinaEntryValue = cjelEntryObj.extract( "Broj cjeline" );
	// nazivi projekata su spremljeni u std::map pod. strukturu u json objektu, znaci sortirani su
	std::pair<std::string, json::array_t> cjelineData;
	cjelineData = extractedCjelinaEntryValue._Getptr()->_Myval;
	for( const auto& cjelina : cjelineData.second )
	{
		const std::string& brojCjeline = cjelina.begin().key();
		cjelEntryObj = cjelina.begin().value();

		std::unordered_map<std::string, size_t> CjelinaX;
		Master::popisImenaFunkcijaPoCjelinama[projIdx].insert( { brojCjeline, std::move( CjelinaX ) } );
		auto& iter = Master::popisImenaFunkcijaPoCjelinama[projIdx].find( brojCjeline )->second;
		for( const auto& zadatak : cjelEntryObj["Zadaci"] )
		{
			const std::string& deklaracija = zadatak["deklaracija"];
			auto endIt = std::find( deklaracija.rbegin(), deklaracija.rend(), '(' );
			auto startIt = std::find_if( endIt, deklaracija.rend(), []( char c )
										 {
											 return c == ':' || isspace( c );
										 } );
			++endIt;
			size_t startOffset = deklaracija.rend() - startIt;
			size_t endOffset = deklaracija.rend() - endIt;
			std::string imeZadatka( deklaracija.data() + startOffset, deklaracija.data() + endOffset );
			Master::_INTERNAL::insertFunctionNameAndIDIntoUMap( iter, projIdx, imeZadatka, brojCjeline );
			if( HACK_isItStepNumber3 == 'y' )
			{
				if( true )	funcDat << '\t' << "DODAJ_FUNKCIJU( " << projIdx << ", " << brojCjeline << ", " << imeZadatka << " );\r";
			///	else		funcDat << "DODAJ_FUNKCIJU2( " << imeZadatka << " );\n";
			}
		}
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