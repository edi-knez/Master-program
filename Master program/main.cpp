#include <cstdlib>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

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


extern enum class projekt;

static std::array popisProjekata{ "C++ knjiga", "FESB", "razno", "ThinkLAP" };
extern std::array<std::vector<std::string>, popisProjekata.size()> popisFunkcija;
extern std::array<std::vector<std::string>, popisProjekata.size()> opisZadatka;



int main()
{

	void ( *Pfun )( ) = fesb_vj10_1;
	pFun();
	char odabir = 0;
	while( odabir != 'a' || odabir != 'r' )
	{
		std::cout << "Ako želis automatizirat proces unesi znak \"a\", a ako želiš ruèno unosit informacije unesi \"r\" ";
		std::cin >> odabir;
		odabir = tolower( odabir );
	}

	auto ispisiPopisProjekata = []() {
		uint8_t i = 1;
		for( const std::string_view strView : popisProjekata )
		{
			std::cout << i++ << ". " << strView << '\n';
		}
		};
	auto ispisiPopisFunkcijaZa = []( const enum class projekt proj ) {
		uint8_t projIdx = static_cast<uint8_t>( proj );
		for( uint8_t idx = 0; idx < popisFunkcija[projIdx].size(); ++idx )
		{
			std::cout << opisZadatka[projIdx][idx]
				<< '\n'
				<< popisFunkcija[projIdx][idx];
		}
		};

	ispisiPopisProjekata();
	//ispisiPopisFunkcija();
	//ispisiPopisParametara();
	bool wantToContinue = true;
	while( wantToContinue )
	{
		switch( odabir )
		{
		case 'a':
			//automatizirano()
			break;
		case 'r':
			rucno();
			break;
		default:
			std::cout << "You are not supposed to be here";
			exit( 1 );

		}
	}
	// zadnji zad iz 1. datoteke
	//zad4();

	// VJEZBE 7
	//aazad1();
	//aazad2();
	//aazad3();
	//aazad4();

	// VJEZBE 8
	//abzad1();
	//abzad2();
	//abzad3();
	//abzad4();
	//abzad5();
	//abzad6();

	// VJEZBE 9
	//aczad1();
	//aczad2();
	//aczad3();

	// VJEZBE 10
	//adzad1();
	//adzad2();
	//adzad3();
	//adzad4();

	// VJEZBE 11
	//aezad1();
	//aezad2();
	//aezad3();
	//aezad4();

	// VJEZBE 12
	//afzad1();
	//afzad2();
	//afzad3();
	//afzad4();

	return EXIT_SUCCESS;
}