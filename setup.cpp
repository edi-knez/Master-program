#include <iostream>
#include <array>
#include <vector>

enum class projekt
{
	CppKnjiga = 0,
	FESB,
	razno,
	ThinkLAP
};

//////////////////////////////////////
/// ////////////////////////////////// template za automatizirat zvanje funkcija umjesto sve rucno napravit u switchu
//////////////////////////////////////
extern void fesb_vj10_1();
void test()
{
	std::vector<void*> vecPointersOnFunctions;
	vecPointersOnFunctions.push_back( reinterpret_cast<void*>( fesb_vj10_1 ) );
	void* vPtr_naFunkciju = reinterpret_cast<void*>( fesb_vj10_1 );
	void ( *Pfun )( ) = fesb_vj10_1;
	//auto funcPtr = fesb_vj10_1;
	reinterpret_cast<void (*)()>(vecPointersOnFunctions[0])();
}
///////////////////////////////////
/// ////////////////////////////////
///////////////////////////////////

std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
std::array<std::vector<std::string>, popisProjekata.size()> popisImenaFunkcija;
std::array<std::vector<std::string>, popisProjekata.size()> popisFunkcija;

void popuniPopisFunkcija();
void popuniPopisFunkcijaZa( const enum class projekt proj );

////////////////////////////////////////////////////////////////////////////////////


void popuniPopisFunkcija()
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
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.zad4_kvadrat" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.zad5_ispis" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.vj1_2datoteke" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj1.vj3_krug" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj2.zad6" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj3.zad5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj4.zad5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj5.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj5.zad3" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj6.zad4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj7.zad4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj8.zad3" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj9.zad6" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj10.zad1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "cj10.zad2" );
	}
	break;

	case FESB:
	{
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj1_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj2_5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj3_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj4_3" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj5_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj6_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj7_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj8_6" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj9_3" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj10_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj11_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "fesb_vj12_4" );
	}
	break;

	case razno:
	{
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog10_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog11_6" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog13_5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog14_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog15_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog15_2" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_5" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog16_6" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_2__3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog17_5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog18_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog19_1" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_4" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog21_5" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog22_4" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_2" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog23_3" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog24_1" );

		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_1" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_3" );
		popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( "Practical C++ Programming_pog26_5" );
	}
	break;

	case ThinkLAP:
	{

	}
	break;

	default:
		std::cout << "ERROR"; exit( 1 );
	}



}

