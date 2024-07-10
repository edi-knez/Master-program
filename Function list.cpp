#include <fstream>
#include <iostream>


// nakraju kad se sve funkcije tu dodaju, zatvori funkciju i undefine macroe
void finish_Function_list__cpp_file()
{
	const char* macro1 = "#undef DODAJ_FUNKCIJU";
	const char* macro2 = "#undef DODAJ_FUNKCIJU2";
	std::ofstream datoteka( "Function list.cpp", std::ios::out | std::ios::app );
	if( datoteka.is_open() )
	{
		datoteka << "\n\n" << '}';
		datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n' << EOF;
	}
	else
	{
		datoteka.open( "Function list.cpp", std::ios::out | std::ios::app );
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

void autoAddeedFunctionsFromFiles()
{

}