#include <fstream>
#include <iostream>
#include <vector>

#include "..\Master program\PotrebneDatotekeIDeklaracijeFunkcija.hpp"

#define DODAJ_FUNKCIJU( projIdx, IME_NAMESPACE, ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( IME_NAMESPACE::ime_funkcije )
#define DODAJ_FUNKCIJU2( ime_funkcije ) Master::popisFunkcija[projIdx].emplace_back( ime_funkcije )


namespace Master
{
    extern std::vector<std::vector< void ( * )( ) >> popisFunkcija;
}

// nakraju kad se sve funkcije tu dodaju, zatvori funkciju i undefine macroe
void finish_Function_list__cpp_file( std::fstream& datoteka )
{
    const char* macro1 = "#undef DODAJ_FUNKCIJU";
    const char* macro2 = "#undef DODAJ_FUNKCIJU2";

    datoteka << "\n\n" << '}';
    datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n';
}

void autoAddeedFunctionsFromFiles()
{

}
