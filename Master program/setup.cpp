/// Poboljsanja za buducnost:
/// ---------------------------
/// koristi prikladniji spremnik: ime projekta - unordered_map koja sadrzi se poglavlja/cjeline - set koji sadrzi vektor sa svim funkcijama
/// koristi nekakve offsete da bi pojednostavio kod za unos
/// lazy popunjavanje funkcija / imena funkcija / opisa po potrebi
/// koristi namespace funkcije za projekte
/// koristenje MACRO za dodavanje novih funkcija na popis
/// dodavanje klasa

#include <iostream>
#include <array>
#include <set>
#include <unordered_map>
#include <vector>
#include <fstream>

/// VAZNO:
// kada dodajes novi projekt, stavi vrijednost od projekt::END na projekt::imeNovogProjekta
enum class projekt
{
	BEGIN = 0,
	CppKnjiga = 0,
	FESB,
	razno,
	ThinkLAP,
	END = projekt::ThinkLAP
};

struct Zadatak
{
	const char* tekst;
	const char* naziv;
	const char* povratniTip;
	const char* argumenti;
	const char* podTipArgumenata;
	const char* kod; // tijelo funkcije
};

//////////////////////////////////////
/// ////////////////////////////////// potrebne datoteke iz projekta C++ knjiga
//////////////////////////////////////
#include "../_Projekti/C++ knjiga/Cjelina1.hpp"
#include "../_Projekti/C++ knjiga/Cjelina2.hpp"
#include "../_Projekti/C++ knjiga/Cjelina3.hpp"
#include "../_Projekti/C++ knjiga/Cjelina4.hpp"
#include "../_Projekti/C++ knjiga/Cjelina5.hpp"
#include "../_Projekti/C++ knjiga/Cjelina6.hpp"
#include "../_Projekti/C++ knjiga/Cjelina7.hpp"
#include "../_Projekti/C++ knjiga/Cjelina8.hpp"
#include "../_Projekti/C++ knjiga/Cjelina9.hpp"
#include "../_Projekti/C++ knjiga/Cjelina10.hpp"
//////////////////////////////////////

//////////////////////////////////////
/// ////////////////////////////////// potrebne funkcije iz projekta FESB
//////////////////////////////////////
extern void fesb_vj1_1();	extern void fesb_vj1_2();	extern void fesb_vj1_3();	extern void fesb_vj1_4();
extern void fesb_vj2_1();	extern void fesb_vj2_2();	extern void fesb_vj2_3();	extern void fesb_vj2_4();	extern void fesb_vj2_5();
extern void fesb_vj3_1();	extern void fesb_vj3_2();	extern void fesb_vj3_3();	extern void fesb_vj3_4();
extern void fesb_vj4_1();	extern void fesb_vj4_2();	extern void fesb_vj4_3();
extern void fesb_vj5_1();	extern void fesb_vj5_2();	extern void fesb_vj5_3();	extern void fesb_vj5_4();
extern void fesb_vj6_1();	extern void fesb_vj6_2();	extern void fesb_vj6_3();	extern void fesb_vj6_4();
extern void fesb_vj7_1();	extern void fesb_vj7_2();	extern void fesb_vj7_3();	extern void fesb_vj7_4();
extern void fesb_vj8_1();	extern void fesb_vj8_2();	extern void fesb_vj8_3();	extern void fesb_vj8_4();	extern void fesb_vj8_5();	extern void fesb_vj8_6();
extern void fesb_vj9_1();	extern void fesb_vj9_2();	extern void fesb_vj9_3();
extern void fesb_vj10_1();	extern void fesb_vj10_2();	extern void fesb_vj10_3();	extern void fesb_vj10_4();
extern void fesb_vj11_1();	extern void fesb_vj11_2();	extern void fesb_vj11_3();	extern void fesb_vj11_4();
extern void fesb_vj12_1();	extern void fesb_vj12_2();	extern void fesb_vj12_3();	extern void fesb_vj12_4();
//////////////////////////////////////


//////////////////////////////////////
/// ////////////////////////////////// potrebne funkcije iz projekta razno
//////////////////////////////////////
extern void Practical_Cpp_Programming_pog10_1(); extern void Practical_Cpp_Programming_pog10_2(); extern void Practical_Cpp_Programming_pog10_3();
extern void Practical_Cpp_Programming_pog10_4();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog11_1(); extern void Practical_Cpp_Programming_pog11_2(); extern void Practical_Cpp_Programming_pog11_3();
extern void Practical_Cpp_Programming_pog11_4(); extern void Practical_Cpp_Programming_pog11_5(); extern void Practical_Cpp_Programming_pog11_6();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog13_1(); extern void Practical_Cpp_Programming_pog13_2(); extern void Practical_Cpp_Programming_pog13_3();
extern void Practical_Cpp_Programming_pog13_4(); extern void Practical_Cpp_Programming_pog13_5();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog13_1(); extern void Practical_Cpp_Programming_pog13_2(); extern void Practical_Cpp_Programming_pog13_3();
extern void Practical_Cpp_Programming_pog13_4();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog14_1(); extern void Practical_Cpp_Programming_pog14_2(); extern void Practical_Cpp_Programming_pog14_3();
extern void Practical_Cpp_Programming_pog14_4();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog15_1(); extern void Practical_Cpp_Programming_pog15_2();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog16_1(); extern void Practical_Cpp_Programming_pog16_2(); extern void Practical_Cpp_Programming_pog16_3();
extern void Practical_Cpp_Programming_pog16_4(); extern void Practical_Cpp_Programming_pog16_5(); extern void Practical_Cpp_Programming_pog16_6();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog17_2__1(); extern void Practical_Cpp_Programming_pog17_2__2(); extern void Practical_Cpp_Programming_pog17_2__3();
extern void Practical_Cpp_Programming_pog17_5();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog18_1(); extern void Practical_Cpp_Programming_pog18_2(); extern void Practical_Cpp_Programming_pog18_4();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog19_1();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog21_1(); extern void Practical_Cpp_Programming_pog21_2(); extern void Practical_Cpp_Programming_pog21_3();
extern void Practical_Cpp_Programming_pog21_5();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog22_4();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog23_1(); extern void Practical_Cpp_Programming_pog23_2(); extern void Practical_Cpp_Programming_pog23_3();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog24_1();
/////////////////////////////////////
extern void Practical_Cpp_Programming_pog26_1(); extern void Practical_Cpp_Programming_pog26_3(); extern void Practical_Cpp_Programming_pog26_5();
/////////////////////////////////////

//////////////////////////////////////
/// //////////////////////////////////
//////////////////////////////////////
/// poglavlje 2:
extern void ThinkLAP_printSidewaysTriangle(); extern void ThinkLAP_luhnFormulaPrecomputed_and_Expression(); extern void ThinkLAP_decodeMessage();
extern void ThinkLAP_pog2vj1(); extern void ThinkLAP_pog2vj2(); extern void ThinkLAP_pog2vj2version2(); extern void ThinkLAP_pog2vj3(); extern void ThinkLAP_pog2vj5_check(); extern void ThinkLAP_pog2vj5_generate(); extern void ThinkLAP_pog2vj6(); extern void ThinkLAP_pog2vj6_2(); extern void ThinkLAP_pog2vj7(); extern void ThinkLAP_pog2vj8(); extern void ThinkLAP_pog2vj9();

/// poglavlje 3:
extern void ThinkLAP_pog3_finding_the_mode(); extern void ThinkLAP_pog3_vj1_sorting(); void ThinkLAP_pog3_highestSales_zadano(); extern void ThinkLAP_pog3_vj2_median(); extern void ThinkLAP_pog3_vj3_issorted(); extern void ThinkLAP_pog3_vj4_encode_and_vj5_decode(); extern void ThinkLAP_pog3_vj8_grade_better_than(); extern void ThinkLAP_pog3_vj9_modified_median();

/// poglavlje 4:
extern void ThinkLAP_pog4_osnovne_operacije_stringa(); extern void ThinkLAP_pog4_prosjek_ocjena_studenata(); extern void ThinkLAP_pog4_vj1(); extern void ThinkLAP_pog4_vj2_jos_operacija_nad_stringom(); extern void ThinkLAP_pog4_myCharPtr_klasa_testiranje(); extern void ThinkLAP_pog4_vj4_dodavanje_and_vj5_uklananje_studentkih_rekorda(); extern void ThinkLAP_pog4_vj6(); extern void ThinkLAP_pog4_vj7(); extern void ThinkLAP_pog4_vj8(); extern void ThinkLAP_pog4_vj9(); extern void ThinkLAP_pog4_vj10();

/// poglavlje 5:
extern void ThinkLAP_pog5_vj1(); extern void ThinkLAP_pog5_zad1(); extern void ThinkLAP_pog5_zad2(); extern void ThinkLAP_pog5_zad3_i_4(); extern void ThinkLAP_pog5_zad5();

/// poglavlje 6:
extern void ThinkLAP_pog6_vj1(); extern void ThinkLAP_pog6_vj2(); extern void ThinkLAP_pog6_vj3(); extern void ThinkLAP_pog6_vj4(); extern void ThinkLAP_pog6_vj5(); extern void ThinkLAP_pog6_zad1(); extern void ThinkLAP_pog6_zad2(); extern void ThinkLAP_pog6_zad3(); extern void ThinkLAP_pog6_zad4(); extern void ThinkLAP_pog6_zad5(); extern void ThinkLAP_pog6_zad6();
//////////////////////////////////////


//////////////////////////////////////
/// ////////////////////////////////// template za automatizirat zvanje funkcija umjesto sve rucno napravit u switchu
//////////////////////////////////////
extern void fesb_vj10_1();
void test()
{
	void ( *Pfun )( ) = fesb_vj10_1;

	std::vector<void ( * )( )> vecPointersOnFunctions;
	vecPointersOnFunctions.push_back( fesb_vj10_1 );
	//void* vPtr_naFunkciju = reinterpret_cast<void*>( fesb_vj10_1 );

	//auto funcPtr = fesb_vj10_1;
	vecPointersOnFunctions[0]();
}
///////////////////////////////////


///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////

extern std::array<const char*, 4> popisProjekata;
// niz projekata koji sadrzi umap stringova cjelina koji sadrzi umap stringova naziva funkcija
std::array<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>, popisProjekata.size()> popisImenaFunkcijaPoCjelinama;
std::array<std::vector<void ( * )( )>, popisProjekata.size()> popisFunkcija;

void popuniCijeliPopisFunkcija();
void popuniPopisFunkcijaZa( const enum class projekt proj );

////////////////////////////////////////////////////////////////////////////////////



void popuniCijeliPopisFunkcija()
{
	for( projekt cur = projekt::BEGIN; cur < projekt::END; cur = projekt( static_cast<uint8_t>( cur ) + 1 ) )
	{
		popuniPopisFunkcijaZa( cur );
	}
}
// ZA KASNIJE
std::pair<std::string, std::string> getName()
{
	return {};
}


void insertFunctionNameAndIDIntoUMap( std::unordered_map<std::string, size_t>& container, const projekt proj, const std::string& funcName, const std::string& brojCjeline )
{
	size_t funID = 0;
	for( auto cjeline : popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )] )
	{
		funID += cjeline.second.size();
	}

	container.insert( { funcName, funID } );
}

void popuniPopisFunkcijaZa( const enum class projekt proj )
{
//	std::pair<std::string, std::string> name;
	/// ZA KasNIJE
/*
	// dohvacaj imena funkcija iz datoteke
	// ucitaj funkcije iz .exe ili .obj  datoteke
	//while( name = getName() )
	{

		//insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, "cj1.zad4_kvadrat" );
		insertFunctionNameAndIDIntoUMap( popisImenaFunkcijaPoCjelinama, proj, name.first );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad4_kvadrat );
	}
*/


	std::string brojCjeline;
	switch( proj )
	{
		using enum projekt;
	case CppKnjiga:
	{
		brojCjeline = "Cjelina1";
		std::unordered_map<std::string, size_t> Cjelina1;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { brojCjeline, std::move( Cjelina1 ) } );
		{
		////std::unordered_map<std::string, size_t> test;
		////test = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find("Cjelina1")->second;
			auto& iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( brojCjeline )->second;
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj1.zad4_kvadrat", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj1.zad5_ispis", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj1.vj1_2datoteke", brojCjeline );
			insertFunctionNameAndIDIntoUMap( iter, proj, "cj1.vj3_krug", brojCjeline );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad4_kvadrat );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad5_ispis );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::vj1_2datoteke );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::vj3_krug );
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
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad1 );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad2 );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad3 );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad4 );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad5 );
			popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad6 );
		}
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

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj4.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj4.zad3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj4.zad4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj4.zad5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj5.zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj5.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina5::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina5::zad3 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj6.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj6.zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj6.zad3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj6.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj7.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj7.zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj7.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj8.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj8.zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj8.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad3 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj9.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj9.zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj9.zad3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj9.zad4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj9.zad6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad6 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj10.zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "cj10.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina10::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina10::zad2 );

	}
	break;

	case FESB:
	{
		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj1_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj1_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj1_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj1_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj2_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj2_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj2_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj2_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj2_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj3_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj3_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj3_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj3_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj4_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj4_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj4_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_3 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj5_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj5_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj5_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj5_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj6_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj6_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj6_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj6_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj7_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj7_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj7_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj7_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_5" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj8_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_6 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj9_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj9_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj9_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_3 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj10_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj10_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj10_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj10_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj11_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj11_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj11_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj11_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj12_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj12_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj12_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "fesb_vj12_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_4 );
	}
	break;

	case razno:
	{
		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog10_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog10_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog10_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog10_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_5" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog11_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_6 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog13_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog13_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog13_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog13_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog13_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog14_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog14_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog14_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog14_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog15_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog15_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog15_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog15_2 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_5" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog16_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_6 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog17_2__1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog17_2__2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog17_2__3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog17_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog18_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog18_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog18_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog19_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog19_1 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog21_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog21_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog21_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog21_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog21_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog22_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog22_4 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog23_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog23_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog23_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_3 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog24_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog24_1 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog26_1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog26_3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "Practical C++ Programming_pog26_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_5 );
	}
	break;

	case ThinkLAP:
	{
		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_printSidewaysTriangle" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_luhnFormulaPrecomputed_and_Expression" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_decodeMessage" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj2version2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj5_check" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj5_generate" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj6" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj6_2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj7" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj8" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog2vj9" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_printSidewaysTriangle );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_luhnFormulaPrecomputed_and_Expression );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_decodeMessage );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj2version2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj5_check );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj5_generate );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj6 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj6_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj7 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj8 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog2vj9 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_finding_the_mode" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj1_sorting" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_highestSales_zadano" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj2_median" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj3_issorted" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj4_encode_and_vj5_decode" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj8_grade_better_than" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog3_vj9_modified_median" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_finding_the_mode );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj1_sorting );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_highestSales_zadano );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj2_median );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj3_issorted );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj4_encode_and_vj5_decode );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj8_grade_better_than );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog3_vj9_modified_median );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_osnovne_operacije_stringa" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_prosjek_ocjena_studenata" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj2_jos_operacija_nad_stringom" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_myCharPtr_klasa_testiranje" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj4_dodavanje_and_vj5_uklananje_studentkih_rekorda" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj6" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj7" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj8" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj9" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog4_vj10" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_osnovne_operacije_stringa );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_prosjek_ocjena_studenata );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj2_jos_operacija_nad_stringom );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_myCharPtr_klasa_testiranje );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj4_dodavanje_and_vj5_uklananje_studentkih_rekorda );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj6 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj7 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj8 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj9 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog4_vj10 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog5_vj1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog5_zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog5_zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog5_zad3_i_4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog5_zad5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog5_vj1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog5_zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog5_zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog5_zad3_i_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog5_zad5 );

		brojCjeline = "Cjelina2";
		std::unordered_map<std::string, size_t> Cjelina2;
		popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].insert( { "Cjelina2", Cjelina2 } );
		iter = popisImenaFunkcijaPoCjelinama[static_cast<uint8_t>( proj )].find( "Cjelina1" )->second;
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_vj1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_vj2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_vj3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_vj4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_vj5" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad1" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad2" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad3" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad4" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad5" );
		insertFunctionNameAndIDIntoUMap( iter, proj, "ThinkLAP_pog6_zad6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_vj1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_vj2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_vj3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_vj4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_vj5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ThinkLAP_pog6_zad6 );
	}
	break;

	default:
		std::cout << "ERROR: invalid project"; exit( 1 );
	}*/
	}
}


