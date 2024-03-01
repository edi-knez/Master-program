#include <iostream>
#include "Poglavlje2.h"
#include "Poglavlje3.h"
#include "Poglavlje4.h"
#include "StringLLAdv.h"
#include "Poglavlje5.h"
#include "Poglavlje6.h"
#include "Poglavlje7.h"

#include "../ThinkLAP/_helperFunc_ThinkLAP.hpp"
#include "../../Master program/PotrebneDatotekeIDeklaracijeFunkcija.hpp"

//* int main()
//{
void ThinkLAP::printSidewaysTriangle()
{
	Poglavlje2 pog2;
	pog2.printSidewaysTriangle();
	pog2.printSidewaysTriangleRec();
}

void ThinkLAP::luhnFormulaPrecomputed_and_Expression()
{
	Poglavlje2 pog2;
	pog2.luhnFormulaPrecomputed();
	pog2.luhnFormulaExpression();
}

void ThinkLAP::decodeMessage()
{
	Poglavlje2 pog2;
	pog2.decodeMessage();
	std::cout << "\nRjesenje:\n";
	pog2.decodeMessageRjesenje();

	// slova
	// -      -> promijeni mod
	// ' '    -> razmak
	//
	//		  R, -	, i , g ,  h  , t  , -, ? ,' ', -, Y ,-, e,  s  , -, !
	// input: 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
}


	// vjezbe
void ThinkLAP::pog2vj1()
{
	Poglavlje2 pog2;
	pog2.vj1();
}

void ThinkLAP::pog2vj2()
{
	Poglavlje2 pog2;
	pog2.vj2();
}

void ThinkLAP::pog2vj2version2()
{
	Poglavlje2 pog2;
	pog2.vj2_version2();
}

void ThinkLAP::pog2vj3()
{
	Poglavlje2 pog2;
	//// input: 9780306406157 (978-0-306-40615-7)
	pog2.vj3();
}

void ThinkLAP::pog2vj5_check()
{
	Poglavlje2 pog2;
	pog2.vj5_check();
	//// input: 978030640615 (978-0-306-40615-?)
}

void ThinkLAP::pog2vj5_generate()
{
	Poglavlje2 pog2;
	pog2.vj5_generate();
}

void ThinkLAP::pog2vj6()
{
	try
	{
		Poglavlje2 pog2;
		std::cout << pog2.vj6_bin_to_dec() << '\n';
	}
	catch( const char* poruka )
	{
		std::cout << poruka;
	}
	catch( ... )
	{
		std::cout << "--GRESKA!--\n";
	}
}

void ThinkLAP::pog2vj6_2()
{
	Poglavlje2 pog2;
	int bin = pog2.vj6_dec_to_bin();
	pog2.vj6_ispisi_bin( bin );
	////std::cout << bin;
}

void ThinkLAP::pog2vj7()
{
	struct testCase
	{							// b									d				h
		int test1 = 0;			// 0									0				0x0
		int test2 = 5;			// 101								5				0x5
		int test3 = -5;			// 11111111111111111111111111111011		-5				0xFFFC
		int test4 = INT32_MIN;	// 10000000000000000000000000000000		-2147483648		0x8000
	};

	Poglavlje2 pog2;
	pog2.vj7_pretvorba_sa_hex();
}


void ThinkLAP::pog2vj8()
{
	Poglavlje2 pog2;
////--------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>(neg brojevi)
	pog2.vj8_pretvorba_sve_baze();
}

void ThinkLAP::pog2vj9()
{
	//test cases :
	//rE,
	//Ree,
	//aaaaaa Uhhhhh,
	//bbboKKK,

	Poglavlje2 pog2;
	std::string str;
	std::cout << "Unesi liniju teksta:\n";
	getline( std::cin, str );
	pog2.vj9_unos_string_info( str );
}

///////////////////////////////////////////////////////////////////////////
/// Poglavlje 3:

void ThinkLAP::pog3_finding_the_mode()
{
	Poglavlje3 pog3;
	pog3.finding_the_mode();
}

void ThinkLAP::pog3_vj1_sorting()
{
	Poglavlje3 pog3;
	pog3.vj1_sorting();
}

void ThinkLAP::pog3_highestSales_zadano()
{
	Poglavlje3 pog3;
	pog3.highestSales_zadano();
}

void ThinkLAP::pog3_vj2_median()
{
	Poglavlje3 pog3;
	pog3.vj2_median();
}

void ThinkLAP::pog3_vj3_issorted()
{
	Poglavlje3 pog3;
	std::array<int, 20> niz1{ 5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534, 23, 55, 67, 99, 265, 376, 232, 223 };
	std::array<int, 20> niz2{ 23, 55, 67, 99, 223, 232, 265, 376, 1122, 2534, 3838, 3875, 3983, 4785, 4959, 5456, 5865, 6464,  7766, 9957 };
	std::cout << "niz1:\n";
	for( const int el : niz1 )	std::cout << el << " "; std::cout << '\n';
	std::cout << ( ( pog3.vj3_issorted( niz1 ) == true ) ? "sortiran\n" : "nije sortiran\n" );
	std::cout << "\nniz2:\n";
	for( const int el : niz2 )	std::cout << el << " "; std::cout << '\n';
	std::cout << ( ( pog3.vj3_issorted( niz2 ) == true ) ? "sortiran\n" : "nije sortiran\n" );
}

void ThinkLAP::pog3_vj4_encode_and_vj5_decode()
{
	try
	{
	/// ( za trenutacni nacin kriptiranja znakova )
	/// cipher:		┼ ( ? I ž 0 _ ) = E 5 ! ╣ < ' ╦ $ » ╩ 8 U ▀ ď Ó ─ ╝
	/// slova:		a b c d e f g h i j k l m n o p q r s t u v w x y z
		Poglavlje3 pog3;
		const char* plainText = "roses are red, sky is blue. code is gud and so no need to be pulled.";
		auto encoded = pog3.vj4_cipher_encode( plainText );
		std::cout.setf( std::ios::left ); std::cout.width( 12 ); std::cout << "plainText:" << plainText << '\n';
		std::cout.setf( std::ios::left ); std::cout.width( 12 ); std::cout << "encoded:" << encoded << '\n';

		std::cout << "\nNakon dekriptiranja:\n";

		char cipherText[57];
		strcpy_s( cipherText, encoded.get() );
		auto decode = pog3.vj5_cipher_decode( std::move( encoded ) );
		std::cout.setf( std::ios::left ); std::cout.width( 12 ); std::cout << "cipherText:" << cipherText << '\n';
		std::cout.setf( std::ios::left ); std::cout.width( 12 ); std::cout << "decode:" << decode << '\n';
	}
	catch( const char* str )
	{
		std::cout << str;
	}
	catch( ... )
	{
		std::cout << "--GRESKA--\n";
	}
}

/////////////////////////////////////////////////////////////////////////////////////// TODO: PROVJERI da li daje tocne rezultate
void ThinkLAP::pog3_vj8_grade_better_than()
{
	Poglavlje3 pog3;
	const auto rezultati = pog3.vj8_grade_better_than();
	std::cout << "Od trazenog ucenika bolji je postotak studenata sa sljedecim ocjenama:\n"
		<< "25%: " << static_cast<uint8_t>( rezultati[0] != UINT8_MAX ? ( rezultati[0] + 'A' ) : '\\' ) << '\n'
		<< "50%: " << static_cast<uint8_t>( rezultati[1] != UINT8_MAX ? ( rezultati[1] + 'A' ) : '\\' ) << '\n'
		<< "75%: " << static_cast<uint8_t>( rezultati[2] != UINT8_MAX ? ( rezultati[2] + 'A' ) : '\\' ) << '\n';
}

void ThinkLAP::pog3_vj9_modified_median()
{
	Poglavlje3 pog3;
	pog3.vj9_modified_median();
}

//////////////////////////////////////////////
/// poglavlje 4:

void ThinkLAP::pog4_osnovne_operacije_stringa()
{
	Poglavlje4 pog4;
	const char* string = "";
	std::cout << "string: " << string;
	std::cout << "\nAppendig \"a\"\n";
	pog4.append( string, 'a' );
	std::cout << "string: " << string << '\n';
	std::cout << "Concatenating \" test\"\n";
	pog4.concatenate( string, " test" );
	std::cout << "string: " << string << '\n';
	std::cout << "\nAppendig \".\"\n";
	pog4.append( string, '.' );
	std::cout << "string: " << string << '\n';
	std::cout << "Concatenating \" This is\"\n";
	pog4.concatenate( string, " This is." );
	std::cout << "string: " << string << '\n';
	std::cout << "\n";
	std::cout << "string sa characterAt funkcijom:\n";
	for( std::pair<uint8_t, const char*> data = { 1, string }; *data.second != '\0'; ++data.first, ++data.second )
		std::cout << pog4.characterAt( string, data.first ) << '\n';
	delete[] string;
}

void ThinkLAP::pog4_prosjek_ocjena_studenata()
{
	Poglavlje4 pog4;
	Poglavlje4::StudentRecord* record = nullptr;
	pog4.addRecord( record, { 1, 'A' } ); // 1
	pog4.addRecord( record, { 1, 'B' } ); // 2
	pog4.addRecord( record, { 1, 'C' } ); // 6
	pog4.addRecord( record, { 1, 'F' } ); // 6
	pog4.addRecord( record, { 3, 'C' } ); // 3
	pog4.addRecord( record, { 3, 'E' } ); // 5
	pog4.addRecord( record, { 3, 'E' } ); // 5
	pog4.addRecord( record, { 3, 'E' } ); // 5
	pog4.addRecord( record, { 3, 'E' } ); // 5
	std::cout << "Prosjek ocjena u rekordu je: " << static_cast<char>( pog4.averageRecord( record ) ) << '\n';
	delete record;
}

void ThinkLAP::pog4_vj1()
{
	Poglavlje4 pog4;
	pog4.vj1_(); ///////////////////////////////////////////////////////////////////////////////////////// TODO	pogledaj za zadatak koji se moze rjesit sa dinamicnom memorijom
}

void ThinkLAP::pog4_vj2_jos_operacija_nad_stringom()
{
	Poglavlje4 pog4;
	const char* test1 = "\0";
	const char* sub1 = pog4.vj2_sub_string( test1, 0, 5 );
	const char* sub2 = pog4.vj2_sub_string( test1, 5, 2 );
	const char* sub3 = pog4.vj2_sub_string( test1, 0, 1 );
	std::cout << "test1: \"" << sub1 << "\"" << ", " << "\"" << sub2 << "\"" << ", " << "\"" << sub3 << "\"\n";
	const char* test2 = "test2";
	const char* sub4 = pog4.vj2_sub_string( test2, 0, 5 );
	const char* sub5 = pog4.vj2_sub_string( test2, 3, 2 );
	const char* sub6 = pog4.vj2_sub_string( test2, 0, 1 );
	const char* sub7 = pog4.vj2_sub_string( test2, 4, 3 );
	const char* sub8 = pog4.vj2_sub_string( test2, -1, 3 );
	std::cout << "test2: \"" << sub4 << "\"" << ", " << "\"" << sub5 << "\"" << ", " << "\"" << sub6 << "\"" << ", " << "\"" << sub7 << "\"" << ", " << "\"" << sub8 << "\"\n";
	delete[] sub1, delete[] sub2, delete[] sub3, delete[] sub4, delete[] sub5, delete[] sub6, delete[] sub7, delete[] sub8;
}

/// TODO: pogledaj ima li greske, zasto je 5 puta komentirano
//////const char* test1 = new char[1]{ "" };
//////const char* tar1 = "";
//////const char* repl1 = "";
//////std::cout << "PRIJE:\ntest1: \"" << test1 << "\"\nTarget: " << "\"" << tar1 << "\"\nReplaceText: " << "\"" << repl1 << "\"\n";
//////pog4.vj3_replaceString(test1, tar1, repl1);
//////std::cout << "-----------------------------------------\nPOSLIJE:\ntest1: \"" << test1 << "\"\n\n";
//////const char* tar2 = "";
//////const char* repl2 = "da";
//////std::cout << "PRIJE:\ntest1: \"" << test1 << "\"\nTarget: " << "\"" << tar2 << "\"\nReplaceText: " << "\"" << repl2 << "\"\n";
//////pog4.vj3_replaceString(test1, tar2, repl2);
//////std::cout << "-----------------------------------------\nPOSLIJE:\ntest1: \"" << test1 << "\"\n\n";
//////pog4.concatenate(test1, "dodaj");
//////const char* tar3 = "do";
//////const char* repl3 = "XYZ";
//////std::cout << "PRIJE:\ntest1: \"" << test1 << "\"\nTarget: " << "\"" << tar3 << "\"\nReplaceText: " << "\"" << repl3 << "\"\n";
//////pog4.vj3_replaceString(test1, tar3, repl3);
//////std::cout << "-----------------------------------------\nPOSLIJE:\ntest1: \"" << test1 <<  "\"\n\n";
//////pog4.concatenate(test1, " mi dorucak");
//////std::cout << "PRIJE:\ntest1: \"" << test1 << "\"\nTarget: " << "\"" << tar3 << "\"\nReplaceText: " << "\"" << repl3 << "\"\n";
//////pog4.vj3_replaceString(test1, tar3, repl3);
//////std::cout << "-----------------------------------------\nPOSLIJE:\ntest1: \"" << test1 << "\"\n\n";

//////std::cout << "PRIJE:\ntest1: \"" << test1 << "\"\nTarget: " << "\"" << tar3 << "\"\nReplaceText: " << "\"" << repl3 << "\"\n";
//////pog4.vj3_replaceString( test1, "test", repl1 );
//////std::cout << "-----------------------------------------\nPOSLIJE:\ntest1: \"" << test1 << "\"\n\n";

//////delete[] test1;
////////////////////////

void ThinkLAP::pog4_myCharPtr_klasa_testiranje()
{
	Poglavlje4 pog4;
	Poglavlje4::myCharptr string1( 12, "Konstruktor!" ), string2( 14, "Konstruktor2!a" );
	std::cout << "string1: " << string1 << '\n';
	std::cout << "string2: " << string2 << '\n';
	Poglavlje4::myCharptr string3( string1 );
	std::cout << "string3(copy konstruktor string1): " << string3 << ", string1: " << string1 << '\n';
	Poglavlje4::myCharptr string4( std::move( string2 ) );
	std::cout << "string4(move konstruktor string2): " << string4 << '\n';
	std::cout << "string2(nakon move): " << string2 << '\n';
	string1 = string3;
	std::cout << "string1(nakon =string3): " << string1 << ", string3: " << string3 << '\n';
	string3 = std::move( string1 );
	std::cout << "string3 mov =string1: " << string3 << ", string1: " << string1 << '\n';
	//////
	pog4.vj4_append( string1, 'a' ); pog4.vj4_append( string1, 'p' ); pog4.vj4_append( string1, 'p' ); pog4.vj4_append( string1, 'e' ); pog4.vj4_append( string1, 'n' ); pog4.vj4_append( string1, 'd' );
	pog4.vj4_concatenate( string2, "concatenate" );
	uint8_t len = std::max( { string1.getLength(), string2.getLength(), string3.getLength(), string4.getLength() } );
	for( uint8_t i = 1; i <= len; ++i )
		std::cout << pog4.vj4_characterAt( string1, i ) << '\t' << pog4.vj4_characterAt( string2, i ) << '\t' << pog4.vj4_characterAt( string3, i ) << '\t' << pog4.vj4_characterAt( string4, i ) << '\n' << '\n';
}

void ThinkLAP::pog4_vj4_dodavanje_and_vj5_uklananje_studentkih_rekorda()
{
	Poglavlje4 pog4;
	Poglavlje4::StudentRecord* record = nullptr;
	pog4.addRecord( record, { 1, 'A' } ); // 1
	pog4.addRecord( record, { 1, 'B' } ); // 2
	pog4.addRecord( record, { 1, 'C' } ); // 6
	char kriterij;
	uint8_t mode;
	std::cout << "Unesi po kojem kriteriju zelis uklonit iz rekorda: ";
	std::cin >> kriterij;	// 1
	std::cout << "Unesi koji mode zelis(0-> ID, 1-> ocjena): ";
	std::cin >> mode;	// 0
	pog4.vj5_remove_record( record, kriterij, mode );
	std::cout << "Unesi po kojem kriteriju zelis uklonit iz rekorda: ";
	std::cin >> kriterij;	// 'C'
	std::cout << "Unesi koji mode zelis(0-> ID, 1-> ocjena): ";
	std::cin >> mode;	// 1
	pog4.vj5_remove_record( record, kriterij, mode );
	std::cout << "Unesi po kojem kriteriju zelis uklonit iz rekorda: ";
	std::cin >> kriterij;	// 'A'
	std::cout << "Unesi koji mode zelis(0-> ID, 1-> ocjena): ";
	std::cin >> mode;	// 1
	pog4.vj5_remove_record( record, kriterij, mode );
	delete record;
}

StringLLAdv testVal1()
{
	struct StringLLAdv advNode {};
	StringLinkedList::vj6_append( advNode, 'a' );
	StringLinkedList::vj6_append( advNode, 'p' );
	StringLinkedList::vj6_append( advNode, 'p' );
	return advNode;
}

StringLLAdv testVal2()
{
	struct StringLLAdv advNode2 {};
	StringLinkedList::vj6_append( advNode2, '&' );
	StringLinkedList::vj6_append( advNode2, 'c' );
	StringLinkedList::vj6_append( advNode2, 'o' );
	StringLinkedList::vj6_append( advNode2, 'n' );
	return advNode2;
}

void ThinkLAP::pog4_vj6()
{
	struct StringLLAdv advNode = testVal1();
	std::cout << "nakon append advNode:\n";
	for( int i = 0; i < advNode.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode, i ) << '\n';
	StringLinkedList::del( advNode );
}

void ThinkLAP::pog4_vj7()
{
	StringLLAdv advNode = testVal1();
	StringLLAdv advNode2 = testVal2();
	StringLinkedList::vj7_concatenate( advNode, advNode2 );
	std::cout << "\nnakon contatenate advNode:\n";
	for( int i = 0; i < advNode.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode, i ) << '\n';
	StringLinkedList::del( advNode );
	StringLinkedList::del( advNode2 );
}

void ThinkLAP::pog4_vj8()
{
	StringLLAdv advNode = testVal1();
	StringLLAdv advNode2 = testVal2();
	StringLinkedList::vj7_concatenate( advNode, advNode2 );
	std::cout << "\nnakon contatenate advNode:\n";
	StringLinkedList::vj8_rmvchar( advNode, 5, 3 );
	std::cout << "\nnakon rmvchar advNode:\n";
	for( int i = 0; i < advNode.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode, i ) << '\n';
	StringLinkedList::vj8_rmvchar( advNode, 0, 2 );
	std::cout << "\nnakon rmvchar advNode:\n";
	for( int i = 0; i < advNode.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode, i ) << '\n';
	StringLinkedList::vj8_rmvchar( advNode2, 1, 3 );
	std::cout << "\nnakon rmvchar advNode2:\n";
	for( int i = 0; i < advNode2.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode2, i ) << '\n';
	StringLinkedList::vj8_rmvchar( advNode2, 0, 1 );
	std::cout << "\nnakon rmvchar advNode2:\n";
	for( int i = 0; i < advNode2.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode2, i ) << '\n';
	StringLinkedList::del( advNode );
	StringLinkedList::del( advNode2 );
}

void ThinkLAP::pog4_vj9()
{
//inp: 12233344445555566666677777778888888899999999910101010101010101010
	std::cout << "Unesi bilo koji pozitivan broj: ";
	StringLLAdv advNode = StringLinkedList::vj9_intToList();
	std::cout.width( 33 );  std::cout.setf( std::ios::left ); std::cout << "\nBroj unutar advNode: ";
	for( int i = 0; i < advNode.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNode, i );
	StringLinkedList::del( advNode );
}

void ThinkLAP::pog4_vj10()
{
	std::cout << "Unesi bilo koji pozitivan broj: ";
	StringLLAdv advNode = StringLinkedList::vj9_intToList();
	std::cout << "\nUnesi bilo koji pozitivan broj: ";
	StringLLAdv advNode2 = StringLinkedList::vj9_intToList();
	std::cout << "\nadvNode + advNode2 = ";
	StringLLAdv advNodeRez = StringLinkedList::vj10_add_2_int_lists( advNode, advNode2 );
	for( int i = 0; i < advNodeRez.head.slovo; ++i )
		std::cout << StringLinkedList::vj6_characterAt( advNodeRez, i );
	StringLinkedList::del( advNode );
	StringLinkedList::del( advNode2 );
	StringLinkedList::del( advNodeRez );
}

//////////////////////////////////////
/// poglavlje5:

void ThinkLAP::pog5_vj1()
{
	Poglavlje5 pog5;
	pog5.vj_studentRecords();
}

void ThinkLAP::pog5_zad1()
{
	Poglavlje5 pog5;
	pog5.zad1_printCarInfo();
}

void ThinkLAP::pog5_zad2()
{
	Poglavlje5 pog5;
	pog5.zad2_printCarsAge();
}

void ThinkLAP::pog5_zad3_i_4()
{
	Poglavlje5 pog5;
	pog5.zad3i4_myCharPtr_class();
}

void ThinkLAP::pog5_zad5()
{
	Poglavlje5 pog5;
	pog5.zad5_remove();
}
//TODO zavrsi 2 zad

///////////////////////////////////////////////////////////////////
//////pog5.zad6(); // student records
//////pog5.zad7(); // stud rec with range



///////////////////////////////////////////
/// poglavlje 6:

void ThinkLAP::pog6_vj1()
{
	Poglavlje6 pog6;
	pog6.vj1_parrots();
}

void ThinkLAP::pog6_vj2()
{
	Poglavlje6 pog6;
	pog6.vj2_salary();
}

void ThinkLAP::pog6_vj3()
{
	Poglavlje6 pog6;
	pog6.vj3_sum();
}

void ThinkLAP::pog6_vj4()
{
	Poglavlje6 pog6;
	pog6.vj4_count_negative_numbers();
}

void ThinkLAP::pog6_vj5()
{
	Poglavlje6 pog6;
	pog6.vj5_biggest_num_tree();
}

void ThinkLAP::pog6_zad1()
{
	Poglavlje6 pog6;
	pog6.zad1_sum_of_positive_numbers();
}

void ThinkLAP::pog6_zad2()
{
	Poglavlje6 pog6;
	pog6.zad2_binary_str_even_odd();
}

void ThinkLAP::pog6_zad3()
{
	Poglavlje6 pog6;
	pog6.zad3_target_appeard();
}

void ThinkLAP::pog6_zad4()
{
	Poglavlje6 pog6;
	pog6.zad4_tree_is_heap();
}

void ThinkLAP::pog6_zad5()
{
	Poglavlje6 pog6;
	pog6.zad5_is_binary_search_tree();
}

void ThinkLAP::pog6_zad6()
{
	Poglavlje6 pog6;
	pog6.zad6_insert_value_in_binary_search_tree();
}

/* //TODO zavrsi zadatke Think like a programmer knjige?
Poglavlje7 pog7;


return 0;
}

*/
