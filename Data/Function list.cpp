#include <fstream>
#include <iostream>


// nakraju kad se sve funkcije tu dodaju, zatvori funkciju i undefine macroe
void finish_Function_list__cpp_file( std::fstream& datoteka )
{
	const char* macro1 = "#undef DODAJ_FUNKCIJU";
	const char* macro2 = "#undef DODAJ_FUNKCIJU2";

	datoteka << "\n\n" << '}';
	datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n' << EOF;
}

void autoAddeedFunctionsFromFiles()
{

}