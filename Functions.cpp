//#include <synchapi.h>
#include <fstream>
#include <iostream>

#define DODAJ_FUNKCIJU( IME_NAMESPACE, ime_funkcije ) popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( IME_NAMESPACE::ime_funkcije )
#define DODAJ_FUNKCIJU2( ime_funkcije ) popisFunkcija[static_cast<uint8_t>( proj )].emplace_back( ime_funkcije )

// nakraju kad se sve funkcije tu dodaju, pozovi funkciju undefineMacros !!
void undefineMacros()
{
	const char* macro1 = "#undef DODAJ_FUNKCIJU";
	const char* macro2 = "#undef DODAJ_FUNKCIJU2";
	std::ofstream datoteka("Functions.cpp", std::ios::out | std::ios::app);
	if( datoteka.is_open() )
	{
		datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n';
	}
	else
	{
		std::cout << "\n\nGRESKA!! Pokusat cu opet za 5 sekundi\n";
		//Sleep( 5000 );
		datoteka.open( "Functions.cpp", std::ios::out | std::ios::app );
		if( datoteka.is_open() )
		{
			datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n';
		}
		else
		{
			std::cout << "\n\nGRESKA prilikom zavrsavanja postupka dodavanja funkcija!!\n";
			datoteka.close();
			exit( EXIT_FAILURE );
		}
	}
}


void addFunctionsFromFiles()
{

}
