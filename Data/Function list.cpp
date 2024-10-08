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

    datoteka << '\n' << '}';
    datoteka << "\n\n\n" << macro1 << '\n' << macro2 << '\n';
}

void autoAddeedFunctionsFromFiles()
{
	DODAJ_FUNKCIJU( 0, Cjelina1, zad4_kvadrat );
	DODAJ_FUNKCIJU( 0, Cjelina1, zad5_ispis );
	DODAJ_FUNKCIJU( 0, Cjelina1, vj1_2datoteke );
	DODAJ_FUNKCIJU( 0, Cjelina1, vj3_krug );
	DODAJ_FUNKCIJU( 0, Cjelina10, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina10, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad5 );
	DODAJ_FUNKCIJU( 0, Cjelina2, zad6 );
	DODAJ_FUNKCIJU( 0, Cjelina3, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina3, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina3, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina3, zad5 );
	DODAJ_FUNKCIJU( 0, Cjelina4, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina4, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina4, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina4, zad5 );
	DODAJ_FUNKCIJU( 0, Cjelina5, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina5, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina6, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina6, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina6, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina6, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina7, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina7, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina7, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina8, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina8, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina8, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina9, zad1 );
	DODAJ_FUNKCIJU( 0, Cjelina9, zad2 );
	DODAJ_FUNKCIJU( 0, Cjelina9, zad3 );
	DODAJ_FUNKCIJU( 0, Cjelina9, zad4 );
	DODAJ_FUNKCIJU( 0, Cjelina9, zad6 );
	DODAJ_FUNKCIJU( 1, FESB, vj7_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj7_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj7_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj7_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_5 );
	DODAJ_FUNKCIJU( 1, FESB, vj8_6 );
	DODAJ_FUNKCIJU( 1, FESB, vj9_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj9_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj9_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj10_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj10_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj10_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj10_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj11_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj11_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj11_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj11_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj12_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj12_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj12_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj12_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj1_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj1_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj1_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj1_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj1_5 );
	DODAJ_FUNKCIJU( 1, FESB, vj2_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj2_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj2_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj2_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj2_5 );
	DODAJ_FUNKCIJU( 1, FESB, vj3_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj3_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj3_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj3_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj4_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj4_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj4_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj5_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj5_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj5_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj5_4 );
	DODAJ_FUNKCIJU( 1, FESB, vj6_1 );
	DODAJ_FUNKCIJU( 1, FESB, vj6_2 );
	DODAJ_FUNKCIJU( 1, FESB, vj6_3 );
	DODAJ_FUNKCIJU( 1, FESB, vj6_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog10_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog10_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog10_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog10_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_5 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog11_6 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog13_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog13_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog13_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog13_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog13_5 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog14_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog14_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog14_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog14_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog15_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog15_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_5 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog16_6 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog17_2__1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog17_2__2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog17_2__3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog17_5 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog18_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog18_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog18_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog19_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog21_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog21_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog21_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog21_5 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog22_4 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog23_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog23_2 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog23_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog24_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog26_1 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog26_3 );
	DODAJ_FUNKCIJU( 2, PracticalCppProg, pog26_5 );
	DODAJ_FUNKCIJU( 3, TESTIRANJE1, trailingReturnFun2 );
	DODAJ_FUNKCIJU( 3, TESTIRANJE2::NESTED_NAMESPACE, testViseNivoaNamespacea );
	DODAJ_FUNKCIJU( 3, TESTIRANJE3::EDGE_CASES, newLineBeforeOpenParanthasis );
	DODAJ_FUNKCIJU( 4, ThinkLAP, printSidewaysTriangle );
	DODAJ_FUNKCIJU( 4, ThinkLAP, luhnFormulaPrecomputed_and_Expression );
	DODAJ_FUNKCIJU( 4, ThinkLAP, decodeMessage );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj2version2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj3 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj5_check );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj5_generate );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj6 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj6_2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj7 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj8 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog2vj9 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_finding_the_mode );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj1_sorting );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_highestSales_zadano );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj2_median );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj3_issorted );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj4_encode_and_vj5_decode );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj8_grade_better_than );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog3_vj9_modified_median );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_osnovne_operacije_stringa );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_prosjek_ocjena_studenata );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj2_jos_operacija_nad_stringom );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_myCharPtr_klasa_testiranje );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj4_dodavanje_and_vj5_uklananje_studentkih_rekorda );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj6 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj7 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj8 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj9 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog4_vj10 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog5_vj1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog5_zad1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog5_zad2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog5_zad3_i_4 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog5_zad5 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_vj1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_vj2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_vj3 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_vj4 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_vj5 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad1 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad2 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad3 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad4 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad5 );
	DODAJ_FUNKCIJU( 4, ThinkLAP, pog6_zad6 );

}


#undef DODAJ_FUNKCIJU
#undef DODAJ_FUNKCIJU2
