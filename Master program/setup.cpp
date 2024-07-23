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

extern struct Zadatak;

extern void finish_Function_list__cpp_file( std::fstream& datoteka );
extern void autoAddeedFunctionsFromFiles();

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
	std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisImenaFunkcijaPoCjelinama;
	std::vector<std::vector<void ( * )( )>> popisFunkcija;


	namespace _INTERNAL
	{
		std::pair<std::string, std::optional<std::unordered_map<std::string, bool/*unused*/>>> /*std::string_view*/ getFuncReturnType( const std::string& deklaracija, size_t& offset );
		std::pair<std::string, std::string> getNamespaceAndFunctionName( const std::string& deklaracija, size_t& offset );
		std::pair<std::string, std::optional<std::unordered_map<std::string, bool/*unused*/>>> getFuncArguments( const std::string& deklaracija, size_t& offset );
		json::object_t processZadatke( std::vector<Zadatak*>& zad );
		void insertZadatakInfoAndIDIntoUMap( std::unordered_map<std::string, std::pair<Zadatak, size_t>>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline, const json& jZadatak );
		nlohmann::json getJSONFromFile();
	}
}

static std::string utvrdiOKojemPovratnomTipuSeRadi()
{

}

std::pair<std::string, std::optional<std::unordered_map<std::string, bool/*unused*/>>> /*std::string_view*/ Master::_INTERNAL::getFuncReturnType( const std::string& deklaracija, size_t& offset )
{
	auto startIt = deklaracija.begin();
	auto curIt = startIt;
	auto tempIt = curIt;

	curIt = std::find_if_not( curIt, deklaracija.end(), []( char c ){ return isspace( c ); } );
///	do
///	{
	/// kod za podrzavanje raznih kljucnih rijeci u deklaraciji funkcija
	std::unordered_map<std::string, bool/*safe to skip*/> kljucneRijeci = { // izmedu pocetka deklaracije i imena funkcije
		{"const", true}, {"static", true}, {"constexpr", false}, {"consteval", false},
		{"[[nodiscard]]", false}, {"inline", true}, {"decltype", false},
		{"struct", true}, {"enum", true}, {"extern", false}, {"auto", false}
	};
	curIt = std::find( curIt, deklaracija.end(), ' ' );
	/// ...
	/// 
	/// std::string_view trenutacnaRijec( tempIt, curIt );
///	} while( true );
	std::optional<std::unordered_map<std::string, bool/*unused*/>> retVal2;
//	if( )
	std::string retVal1( tempIt, curIt );

	offset += curIt - startIt;
	++offset; // preskoci razmak ' '
	return { retVal1, retVal2 };/*std::string_view(tempIt, curIt);*/
}

std::pair<std::string, std::string> Master::_INTERNAL::getNamespaceAndFunctionName( const std::string& deklaracija, size_t& offset )
{
	size_t offset_ = 0;
	auto startOfFuncArguments = deklaracija.begin() + offset;
	startOfFuncArguments = std::find( startOfFuncArguments, deklaracija.end(), '(' );
	// koristim hack: -1 * ( startOfFuncArguments - deklaracija.begin() ) jer izgleda prirodnije kad moram offset-at reverse pokazivac u desno
	auto tempIt = std::find_if_not( deklaracija.rend() + -1 * ( startOfFuncArguments - deklaracija.begin() ), deklaracija.rend(), []( char c ){ return isspace( c ); } );
	auto endOfFuncName = deklaracija.begin() + ( deklaracija.rend() - tempIt );
	tempIt = std::find_if( tempIt, deklaracija.rend(), []( char c ) { return c == ':' || isspace( c ); } );
	auto startOfFuncName = deklaracija.begin() + ( deklaracija.rend() - tempIt );
	std::string funcName( startOfFuncName, endOfFuncName );
	std::string nmsName( deklaracija.begin() + offset, startOfFuncName - 2 * ( ( deklaracija.begin() + offset ) != startOfFuncName ) );
	offset = startOfFuncArguments - deklaracija.begin();
	return { nmsName, funcName };
}

std::pair<std::string, std::optional<std::unordered_map<std::string, bool/*unused*/>>> Master::_INTERNAL::getFuncArguments(const std::string& deklaracija, size_t& offset)
{
	std::unordered_map<std::string, bool/*safe to skip*/> kljucneRijeci = { // izmedu desne zatvarajuce zagrade liste argumenata ')' i otvarajuce zagrade za definiciju koda '{'
		{"noexcept", true}, {"throw", false},  {"->", false},
	};
	auto krajListeArgumenata = std::find( deklaracija.begin() + offset, deklaracija.end(), ')' );
	std::string retVal1( deklaracija.begin() + offset, krajListeArgumenata );
	offset = 0;

	/// ////////////////////////////////////////////////////////////////////////////////////////////////////
	std::optional<std::unordered_map<std::string, bool/*unused*/>> retval2;	// utvrdi sto treba vratit ovdje <----------------------------------
	if(  )

	return { retVal1, retval2 };
}


json::object_t Master::_INTERNAL::processZadatke( std::vector<Zadatak*>& vecZadaci )
{
	size_t brojPreskocenihZnakova = 0;

	json::object_t brojCjeline = json::object();
	std::unordered_map<std::string, json::array_t> grupiraniZadaciPoNamespaceu;
	json::object_t zadatak = json::object();

	std::string namespaceName;
	std::unordered_map<std::string, bool /*unused*/> poznataImenaFunkcija;

	size_t numOfFuncArguments = 0;

	for( const Zadatak* zad : vecZadaci )
	{
		auto [funcReturnType, extra] = getFuncReturnType( zad->deklaracija, brojPreskocenihZnakova );
		auto [namespaceName, funcName] = getNamespaceAndFunctionName( zad->deklaracija, brojPreskocenihZnakova );
		auto [funcArguments, extra2] = getFuncArguments( zad->deklaracija, brojPreskocenihZnakova );
		size_t numOfFuncArguments = 0;
		const auto izbrojiArgumente = [&]()
			{
				auto curIt =
					std::find_if_not( funcArguments.begin() + 1, funcArguments.end(), []( char c ) { return isspace( c ); } );
				numOfFuncArguments += *curIt != ')'; /// BUG: ukoliko funkcija ima "noexcept" kvalifikaciju, proizest ce krivi rezultat
				std::for_each( curIt, funcArguments.end() - 1, [&]( char c ) // nije vazno sto ide do kraja deklaracije, nema znaka zareza (') nakon zatvarajuce zagrade
							   {
								   numOfFuncArguments += c == ',';
							   } );
			};
		izbrojiArgumente();

		/// handling auto deduction type
		if( funcReturnType == "auto" )	funcReturnType = utvrdiOKojemPovratnomTipuSeRadi();
		else if( funcReturnType == "decltype" )
		/// process default blacklisting
		{
			std::string_view keywordOperator = "operator";
			if( funcName.starts_with( keywordOperator ) )
			{
				std::unordered_map<std::string, bool/*unused*/> overloadableOperators = {
					// Unary Arithmetic Operators such as: +, -, ++, —
					{"+", true}, {"-", true}, {"++", true}, {"--", true},
					// Binary Arithmetic Operators such as: *, /, %
					{"*", true}, {"/", true}, {"%", true},
					// Assignment Operators such as: =, +=, *=, /=, -=, %=
					{"=", true}, {"+=", true}, {"*=", true}, {"/=", true}, {"-=", true}, {"%=", true},
					// Bitwise Operators such as: &, |, <<, >>, ~, ^
					{"&", true}, {"|", true}, {"<<", true}, {">>", true},
					// Logical Operators such as: &, ||, ! 
					{"||", true}, {"!", true},
					// Relational Operators such as : > , < , == , <= , >=
					{">", true}, {"<", true}, {"==", true}, {"<=", true}, {">=", true},
					// De - referencing Operator : ( -> )
					{"->", true},
					// Dynamic memory allocation and De - allocation Operators : New, delete  
					{"new", true}, {"delete", true},
					// Subscript Operator : []
					{"[]", true},
					// Function call : ( )
					{"()", true}
				};

				auto offsetBegin = std::find_if_not( funcName.begin() + keywordOperator.size() + 1, funcName.end(), []( char c ) { return isspace( c ); } );
				auto trimmedSpaces = std::find_if_not( funcName.rbegin(), funcName.rend() - ( offsetBegin - funcName.begin() ), []( char c ){ return isspace( c ); } );
				auto endWithTrimmedSpaces = funcName.end() - ( trimmedSpaces - funcName.rbegin() );

				if( overloadableOperators.find( std::string_view( offsetBegin, endWithTrimmedSpaces ).data() ) != overloadableOperators.end() )	continue;
			}
		}
		if( namespaceName == "" )			continue;	/// za sada nemoze handle-at funkcije bez namespacea
		if( poznataImenaFunkcija.find( funcName ) != poznataImenaFunkcija.end() ) /// blacklista function overload-e
		{
			continue;
		}
		else
		{
			poznataImenaFunkcija.insert( { funcName, true } );
		}
		if( numOfFuncArguments > 0 )		continue;
		if( grupiraniZadaciPoNamespaceu.find( namespaceName ) == grupiraniZadaciPoNamespaceu.end() )
		{
			grupiraniZadaciPoNamespaceu[namespaceName] = json::array();
		}
		/// nemozes izvrsit funkciju tijekom run-time koja je oznacena da se moze izvrsit samo tijekom compile-time!
		if( extra.has_value() && extra.value().find("consteval") != extra.value().end() )	continue;

		/// process whitelisting from user file
		///...
		/// process blacklisting from user file
		///...

		// zadatak = { { "tekst", "pokrece zad1" }, { "deklaracija", "void zad2()" }, {"func body", "{ int i = 5; }" } };
		zadatak["tekst"] = zad->tekst;
		zadatak["deklaracija"] = zad->deklaracija;
		zadatak["kod"] = zad->kod;

		grupiraniZadaciPoNamespaceu[namespaceName].emplace_back( zadatak );
	}
	for( const auto& entry : grupiraniZadaciPoNamespaceu )
		brojCjeline[entry.first]["Zadaci"] = entry.second;
	return brojCjeline;
}

void popuniCijeliPopisFunkcija( nlohmann::json& jsonData )
{
	const char* relativePathToFile = "Data\\";
	std::string imeDatotekeZaFunkcije = "Function list.cpp";
	ParseFile pf( std::string_view( relativePathToFile ), imeDatotekeZaFunkcije );
	std::fstream& datotekaZaSpremanjeFunkcija = pf.getDatoteku( 0 );

	/// ///////////////////////////////////////////////////////
	char HACK_isItStepNumber3;
	std::cout << "Ako si na koraku 3) (za vise informacija pogledaj na vrh \"main.cpp\" datoteke) , unesi znak y: ";
	std::cin >> HACK_isItStepNumber3;
	puts( "\n==========================================================================================" );
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
			std::cout << "Ovo se jedino moglo dogodit jer promijenio ime funkcije \"autoAddedFunctionsFromFiles\" u \"Function list.cpp\"  datoteci\nIzlazim...\n";
			exit( EXIT_FAILURE );
		}
		datotekaZaSpremanjeFunkcija.seekp( writingPosition.value() + 2 );
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

void Master::_INTERNAL::insertZadatakInfoAndIDIntoUMap( std::unordered_map<std::string, std::pair<Zadatak, size_t>>& container, const size_t projIdx, const std::string& funcName, const std::string& brojCjeline, const json& jZadatak )
{
	size_t funID = 0;
	for( const auto& cjelina : popisImenaFunkcijaPoCjelinama[projIdx] )
	{
		funID += cjelina.second.size();
	}
	Zadatak zadatak( jZadatak );
	container.insert( { funcName, { zadatak, funID } } );
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

		std::unordered_map<std::string, std::pair<Zadatak, size_t>> CjelinaX;
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
			Master::_INTERNAL::insertZadatakInfoAndIDIntoUMap( iter, projIdx, imeZadatka, brojCjeline, zadatak );
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

	// radi sljedeci postupak pomocu json datoteke ˘˘

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