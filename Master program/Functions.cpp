//#include <synchapi.h>
#include <fstream>
#include <iostream>


// nakraju kad se sve funkcije tu dodaju, zatvori funkciju i undefine macroe
void finish_Functions_cpp_file()
{
	const char* macro1 = "#undef DODAJ_FUNKCIJU";
	const char* macro2 = "#undef DODAJ_FUNKCIJU2";
	std::ofstream datoteka( "Functions.cpp", std::ios::out | std::ios::app );
	if( datoteka.is_open() )
	{
		datoteka << "\n\n" << '}';
		datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n' << EOF;
	}
	else
	{
		std::cout << "\n\nGRESKA!! Pokusat cu opet za 5 sekundi\n";
		//Sleep( 5000 );
		datoteka.open( "Functions.cpp", std::ios::out | std::ios::app );
		if( datoteka.is_open() )
		{
			datoteka << "\n\n" << '}';
			datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n' << EOF;
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
