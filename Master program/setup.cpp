/// Poboljsanja za buducnost:
/// ---------------------------
/// koristi prikladniji spremnik: ime projekta - unordered_map koja sadrzi se poglavlja/cjeline - set koji sadrzi vektor sa svim funkcijama
/// koristi nekakve offsete da bi pojednostavio kod za unos
/// lazy popunjavanje funkcija / imena funkcija / opisa po potrebi
/// koristi namespace funkcije za projekata

#include <iostream>
#include <array>
#include <set>
#include <unordered_map>
#include <vector>

enum class projekt
{
	CppKnjiga = 0,
	FESB,
	razno,
	ThinkLAP
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
/// ////////////////////////////////// template za automatizirat zvanje funkcija umjesto sve rucno napravit u switchu
//////////////////////////////////////
extern void fesb_vj10_1();
void test()
{
	void ( *Pfun )( ) = fesb_vj10_1;

	std::vector<void (*)()> vecPointersOnFunctions;
	vecPointersOnFunctions.push_back( fesb_vj10_1 );
	//void* vPtr_naFunkciju = reinterpret_cast<void*>( fesb_vj10_1 );

	//auto funcPtr = fesb_vj10_1;
	vecPointersOnFunctions[0]();
}

///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////

std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
std::array<std::vector<std::string>, popisProjekata.size()> popisImenaFunkcija;
std::array<std::vector<void (*)()>, popisProjekata.size()> popisFunkcija;

void popuniCijeliPopisFunkcija();
void popuniPopisFunkcijaZa( const enum class projekt proj );

////////////////////////////////////////////////////////////////////////////////////


void popuniCijeliPopisFunkcija()
{
	popuniPopisFunkcijaZa( projekt::CppKnjiga );
	popuniPopisFunkcijaZa( projekt::FESB );
	popuniPopisFunkcijaZa( projekt::razno );
	popuniPopisFunkcijaZa( projekt::ThinkLAP );
}

void popuniPopisFunkcijaZa( const enum class projekt proj )
{
	switch( proj )
	{
		using enum projekt;
	case CppKnjiga:
	{
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.zad4_kvadrat" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.zad5_ispis" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.vj1_2datoteke" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.vj3_krug" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad4_kvadrat );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::zad5_ispis );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::vj1_2datoteke );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina1::vj3_krug );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina2::zad6 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina3::zad5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina4::zad5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj5.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj5.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina5::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina5::zad3 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina6" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina6::zad4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina7" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina7::zad4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina8" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina8::zad3 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina9" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina9::zad6 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina10" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj10.zad1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj10.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina10::zad1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Cjelina10::zad2 );
		
	}
	break;

	case FESB:
	{
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj1_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj2_5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj3_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj4_3 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj5_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina6" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj6_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina7" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj7_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina8" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj8_6 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina9" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj9_3 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina10" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_3);
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj10_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina11" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj11_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Cjelina12" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( fesb_vj12_4 );
	}
	break;

	case razno:
	{
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje10" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_1);
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje11" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog11_6 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje13" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog13_5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje14" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog14_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje15" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog15_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog15_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog15_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog15_2 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje16" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_5" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_6" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_4 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_5 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog16_6 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje17" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_2__3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog17_5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje18" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog18_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje19" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog19_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog19_1 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje21" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_4" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog21_5 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje22" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog22_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog22_4 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje23" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog23_3 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje24" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog24_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog24_1 );

		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje26" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog26_5 );
	}
	break;

	case ThinkLAP:
	{
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "--Poglavlje10" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_1" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_2" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_3" );
		popisImenaFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_1 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_2 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_3 );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( Practical_Cpp_Programming_pog10_4 );
	}
	break;

	default:
		std::cout << "ERROR"; exit( 1 );
	}



}

