#include "Parsity.hpp"
#include "Checkbook.hpp"
#include "Queue.hpp"
#include "Small_set.hpp"
#include "FlashCards.hpp"

//#include "ShareFile1.hpp"
//#include "ShareFile2_.hpp"
#include "ShareFileInterface.hpp"
#include "Horses.hpp"
#include "Pigs.hpp"
#include "Dogs.hpp"
#include "Stack_Instance.hpp"
#include "Line_number.hpp"

#include "File_16C.hpp"

#include "Razlomak.hpp"
#include "Decimal.hpp"
#include "Time.hpp"

#include "StringDouble.hpp"
#include "String_matcher.hpp"
#include "Word_match.hpp"
#include "d_Number_mather.hpp"
#include "d_BlankStr_matcher.hpp"
#include "b_Oblik.hpp"
#include "d_Krug.hpp"
#include "d_Kvadrat.hpp"
#include "d_Trokut.hpp"
#include "b_Number.hpp"
#include "d_Dek.hpp"
#include "d_Okt.hpp"
#include "d_Hex.hpp"

#include "PageFormatting.hpp"
#include "SymbolTable.hpp"

#include "List.hpp"
#include "Mail_label.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <climits>


#include "../../Master program/PotrebneDatotekeIDeklaracijeFunkcija.hpp"

/*
	Zad 1:
*/
#define TRUE 1
#define FALSE 0
#define BOLEAN int

/*
	Zad 2:
*/
#define divisibleBy10(number) (number % 10 == 0)

/*
	Zad 3:
*/
#define is_digit(c) (c >= 0 && c <= 9)
#define is_hex(c) (is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))

/*
	Zad 4:
*/

#define swap(num, num2, temp) ((temp = num, num = num2, num2 = temp))

#define swap2(num, num2) num += num2; num2 = num - num2; num -= num2
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

const int X_SIZE = 10;
const int Y_SIZE = 10;
static bool grid[Y_SIZE][X_SIZE]{ { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true },
								  { true, false, false, false, false, false, false, false, false, true } };

/*
	Zad 1:
*/

inline void set_bit( size_t x, size_t y, bool bit );
inline void clear_bit( size_t x, size_t y );
inline bool test_bit( size_t x, size_t y, bool bit );
void crtaj_grid();

/*
	Zad 2:
*/

template <class T> size_t numOfBits( T number );

/*
	Zad 3:
*/

std::array<short, 8> podijeliIntegerU8Dijela( int broj );

/*
	Zad 4:
*/

char shiftBitsLeft( char broj );

/*
	str 227, zad1
*/

bool is_using_file1();
bool is_using_file1( const int );

int ukupanBrojZivotinja();

/*
	poglavlje 15:
	zad 1:
*/

void postavi_niz_na_nulu( std::array<int, 15>& niz );
const char* prvi_alfa_num( const char* word );

/*
	Poglavlje 17
	zad 2:
*/

struct matrica_t {
	matrica_t() = delete;
	matrica_t( size_t x, size_t y, const int* niz )
		: m_x( x )
		, m_y( y )
		, m_niz( niz )
	{
	}

	size_t m_x;
	size_t m_y;
	const int* m_niz;
};

void matrixMultiply( std::array<std::array<int, 2>, 2>& niz );
void matrixMultiply( std::array<std::array<int, 3>, 3>& niz );
void matrixMultiply( std::array<std::array<int, 3>, 3>& niz, int m );
std::vector<int> matrixMultiply( struct matrica_t, struct matrica_t );

/*
	zad 5
*/

void moj_memcpy( const char from[], char to[], size_t n );

/*
	Poglavlje 22
	Zad 5:
*/

void count_letter( const char* cstring ) noexcept( false );

/*
	Poglavlje 23
	Zad 2:
*/

std::fstream search_open( const std::array<const char*, 5>& imenaDatoteka );

/*
	Poglavlje 24
	Zad 1:
*/

template <typename T> T min( T el1, T el2 ) { return ( el1 < el2 ) * el1 + ( el2 < el1 ) * el2; }

const char* min( const char* el1, const char* el2 )
{
	int res1 = strcmp( el1, el2 );
	if( res1 < 0 )
		return el1;
	else
		return el2;
}

/*
	Poglavlje 26
	Zad 1:
*/

int32_t haveDoubleWords( const std::string_view imeDatoteke );

/*
	Poglavlje 26
	Zad 5:
*/

void ispisi_datoteku_u_konzolu( std::fstream& datoteka, const std::string& imeDatoteke );


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void PracticalCppProg::pog10_1()
{
	BOLEAN b = TRUE;
	if( b )  	std::cout << "TEST MACRO\n";
}

void PracticalCppProg::pog10_2()
{
	BOLEAN isIstina = divisibleBy10( 10 );
	std::cout << "Broj: " << 10 << ( ( isIstina == 1 ) ? " je" : " nije" ) << " djeljiv sa 10!\n";
}

void PracticalCppProg::pog10_3()
{
	std::cout << is_digit( 5 );
	std::cout << is_hex( 5 );
	std::cout << is_hex( 'b' );
	std::cout << is_hex( 'g' );
	std::cout << is_hex( 'F' );
}

void PracticalCppProg::pog10_4()
{
	int a = 5, b = 14, temp = 0;
	std::cout << "swap varijabli putem MACRO:\n";
	swap( a, b, temp );
	std::cout << "sa temp varijablom: " << a << " " << b << "\n";
	swap2( a, b );
	std::cout << "bez temp varijable: " << a << " " << b << "\n";
}


void PracticalCppProg::pog11_1()
{
	puts( "PRIJE:" );
	crtaj_grid();
	for( int i = 0; i < X_SIZE; ++i )
	{
		set_bit( i, 0, true );
		set_bit( i, Y_SIZE - 1, 1 );
	}
	std::cout << "\nPoslije:\n";
	crtaj_grid();
}

void PracticalCppProg::pog11_2()
{
	puts( "PRIJE:" );
	crtaj_grid();
	for( int i = 0; i < X_SIZE; ++i )
	{
		clear_bit( i, 0 );
	}
	std::cout << "\nPoslije:\n";
	crtaj_grid();
}

void PracticalCppProg::pog11_3()
{
	std::cout << numOfBits( 5 ) << "\n"
		<< numOfBits( 10 ) << "\n"
		<< numOfBits( 15 ) << "\n";
	std::cout << numOfBits( -5 ) << "\n"
		<< numOfBits( -15 ) << "\n";
}

void PracticalCppProg::pog11_4()
{
	int broj;
	int temp;
	char postavljeniBitoviBroja[sizeof( broj ) + 1] = { 0 };
	std::cin >> broj;
	temp = broj;
	size_t idx = 0;
	for( ; temp > 0; ++idx )
	{
		postavljeniBitoviBroja[sizeof( broj ) - idx] = ( temp & 0x1 ) + '0';	// OPTIMIZACIJA: spremi rezultat u bufer umjesto zvat funkciju za ispis za svaki broj
		temp >>= 1;
	}
	std::cout << postavljeniBitoviBroja << "\n";
}

void PracticalCppProg::pog11_5()
{
	int broj;
	std::cin >> broj;
	std::array<short, 8> odvojeno;
	char bitoviDijelaBroja[5] = { 0 };
	odvojeno = podijeliIntegerU8Dijela( broj );
	for( int i = 0; i < 8; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			bitoviDijelaBroja[4 - j] = ( odvojeno[i] & 0x01 ) + '0';
			odvojeno[i] >>= 1;
		}
		std::cout << bitoviDijelaBroja << "\n";
	}
}

void PracticalCppProg::pog11_6()
{
	char broj = 54;
	char result = shiftBitsLeft( broj );
	char bitoviBroja[sizeof( broj ) + 1] = { 0 };
	const char MSG = 1 << sizeof( broj );	// Most Significant Bit
	std::cout << "\nBroj: ";
	size_t idx = 0;
	do
	{
		bitoviBroja[idx] = ( broj & MSG ) + '0';
		broj <<= 1;
		++idx;
	} while( broj > 0 );
	std::cout << bitoviBroja
		<< "(2)\nRezultat: ";

	idx = 0;
	do
	{
		bitoviBroja[idx] = ( result & MSG ) + '0';
		result <<= 1;
		++idx;
	} while( result > 0 );
	std::cout << bitoviBroja << "(2)";	// po bazi 2
}


void PracticalCppProg::pog13_1()
{
	Parsity primjer;
	primjer.put();
	std::cout << primjer.test() << "\n";
	primjer.put();
	std::cout << primjer.test() << "\n";
}

void PracticalCppProg::pog13_2()
{
	Checkbook book1;
	book1.addItem( 5 );
	book1.addItem( 100 );
	book1.addItem( 100 );
	std::cout << book1.total();
}

void PracticalCppProg::pog13_3()
{
	Queue q;
	q.addItem( 1 );
	q.addItem( 2 );
	q.addItem( 3 );
	std::cout << q.get() << "\n";
	std::cout << q.get() << "\n";
	q.addItem( 10 );
	std::cout << q.get() << "\n";
}

void PracticalCppProg::pog13_4()
{
	Small_set small_set;
	small_set.set( 3 );
	small_set.set( 5 );
	small_set.set( 5 );
	std::cout << small_set.test( 3 ) << '\n';      // Prints "1"
	std::cout << small_set.test( 0 ) << '\n';        // Prints "0"
	small_set.clear( 5 );                             // Set contains [3]
	Small_set another_set( small_set );
	small_set.set( 0 );
	std::cout << small_set.test( 3 ) << '\n';      // Prints "1"
	std::cout << small_set.test( 0 ) << '\n';        // Prints "0"
}

void PracticalCppProg::pog13_5()
{
  ////todo: FlachCards klasa
	std::vector<FlashCards::single_card> cards = {	// dodavanje kartica dinamicki
		{ "test1", "test11" },
		{ "test2", "test2" },
		{ "test3", "test3" },
		{ "test4", "test4" },
		{ "test5", "test5" }
	};

	FlashCards fc( cards.data(), cards.size() );
	fc.izbornik();
}


void PracticalCppProg::pog14_1()
{
	ShareFile1 test;
	std::cout << "ShareFile1: " << is_using_file1() << "\n";
	ShareFile2_ test2;
	std::cout << "ShareFile2: " << is_using_file1( 0 ) << "\n";
	std::cout << "----------------\n";

	test.otvori_datoteku();
	std::cout << "ShareFile1: " << is_using_file1() << "\n";
	test2.otvori_datoteku();
	std::cout << "ShareFile2: " << is_using_file1( 0 ) << "\n";
	std::cout << "----------------\n";

	test.zatvori_datoteku();
	test2.zatvori_datoteku();
	test2.otvori_datoteku();
	std::cout << "ShareFile2: " << is_using_file1( 0 ) << "\n";
	test.otvori_datoteku();
	std::cout << "ShareFile1: " << is_using_file1() << "\n";
}

void PracticalCppProg::pog14_2()
{
	std::array<Pigs, 5> pigs;
	std::array<Dogs, 2> dogs;
	std::array<Horses, 3> horses;
	std::cout << ukupanBrojZivotinja() << "\n";
}

void PracticalCppProg::pog14_3()
{
	std::array<Stack_Instance, 5> stacks;
	std::cout << Stack_Instance::who_is_owner( &stacks[0], 5 ) << "\n";
	stacks[0].take_control();
	std::cout << Stack_Instance::who_is_owner( &stacks[0], 5 ) << "\n";
	stacks[4].pop();
	stacks[0].push_back( 10 );
	std::cout << "stack[0] size: " << stacks[0].size()
		<< "\nstack[1] size: " << stacks[1].size()
		<< '\n';
}

void PracticalCppProg::pog14_4()
{
  //227. stranica
	char ime[] = "Dogs.hpp";
	Line_number test( ime );
	if( test.getCurrentLine() == std::numeric_limits<size_t>::max() )	return; // failed to open
	Line_number test2( ime );
	if( test2.getCurrentLine() == std::numeric_limits<size_t>::max() )	return;	// failed to open

	std::cout << "test2.getCurrentLine(): " << test2.getCurrentLine() << '\n';
	std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg() << "\n";
	test.goto_line( 5 );
	std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg() << "\n";
	test.goto_line( 2 );
	std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg() << "\n";
	test2.goto_line( 2 );
	std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg() << "\n";
	std::cout << "test.getCurrentLine(): " << test.getCurrentLine() << '\n';
	std::cout << "test.getFileRef().tellg(): " << test.getFileRef().tellg() << '\n';
	test2.goto_line( 6 );
	test.goto_line( 6 );
	std::cout << "test.getCurrentLine(): " << test.getCurrentLine() << '\n';
	std::cout << "test2.getCurrentLine(): " << test2.getCurrentLine() << '\n';
	test2.getFileRef().seekg( 5, std::ios::cur );
	std::cout << "test2.getCharPos(): " << test2.getCharPos() << '\n';
	test2.goto_line( 0 );
	test2.getFileRef().seekg( 5, std::ios::cur );
	std::cout << "test2.getCharPos(): " << test2.getCharPos() << '\n';
}

  //254. stranica
void PracticalCppProg::pog15_1()
{
	std::array<int, 15> niz;
	niz.fill( 15 );
	for( const auto& n : niz )
		std::cout << n << " ";
	std::cout << "\n";
	postavi_niz_na_nulu( niz );
	for( const auto& n : niz )
		std::cout << n << " ";
	std::cout << "\n";
}

void PracticalCppProg::pog15_2()
{
	const char str1[] = " \ttest ";
	const char str2[] = "  \t ";
	const char* c = prvi_alfa_num( str1 );
	const char* d = prvi_alfa_num( str2 );
	if( c )
		std::cout << c << "\n";
	else
		std::cout << "nullptr\n";
	if( d )
		std::cout << d << "\n";
	else
		std::cout << "nullptr\n";
}


void PracticalCppProg::pog16_1()
{
	File_16C f1( "linije.dat" );
	std::cout << "broj linija: " << f1.numOfLinesInFile() << " u datoteci: \"" << f1.getName() << "\"\n";
}

void PracticalCppProg::pog16_2()
{
	File_16C f2( "linija.dat" );
	f2.copy_file( "copy-linija.dat" );
}

void PracticalCppProg::pog16_3()
{
	File_16C f3;
	std::fstream lista( "lista.dat", std::ios::out );
	lista << 3 << " " << 6 << " " << 9 << " " << 10 << " " << 11 << " " << 12;
	lista.close();
	lista.open( "lista.dat", std::ios::out | std::ios::in | std::ios::ate );
	lista.seekg( std::ios::beg );
	std::cout << "\"lista.dat\": ";
	f3.ispis( lista );
	std::cout << "\n";
	f3.listOfNumbers( lista );

	std::fstream sa3( "djeljivi sa 3.dat", std::ios::in | std::ios::app );
	std::cout << "\"djeljivi sa 3.dat\": ";
	f3.ispis( sa3 );
	std::cout << "\n";

	std::fstream ostali( "svi ostali.dat", std::ios::in | std::ios::app );
	std::cout << "\"svi ostali.dat\": ";
	f3.ispis( ostali );
	std::cout << "\n";

	lista.close();
	sa3.close();
	ostali.close();
}

void PracticalCppProg::pog16_4()
{
	File_16C f4( "File_16C remove high bit.txt" );
	typedef const unsigned char cuc;
	cuc podaci[] = { static_cast<cuc>( 192 ), static_cast<cuc>( 168 ), static_cast<cuc>( 128 ), static_cast<cuc>( 125 ), '\0' };
	std::fstream in( f4.getName(), std::ios::out | std::ios::app | std::ios::trunc );
	in << podaci;
	in.close();
	f4.removeHighBit();
}

void PracticalCppProg::pog16_5()
{
	File_16C f5( "pretvorba ASCI u bin.dat" );
	std::cout << "PRIJE: ";
	f5.ispis();

	if( f5.ASCI_to_bin() )
	{
		std::cout << "\nPretvorba uspjesna!\n";
		f5.bin_to_ASCI();
		std::cout << "\nPOSLIJE: ";
		f5.ispis();
	}
	else
		std::cout << "Nista nece da radi\n";
}

void PracticalCppProg::pog16_6()
{
	File_16C f6( "osobe.inf" );
	f6.read_info_o_osobi();
	f6.ispis_osoba();
}


// 317. stranica
////////////////////////////////////////////////////////////////////////
void PracticalCppProg::pog17_2__1()
{
	std::cout << "2x2:\n";
	std::array<std::array<int, 2>, 2> matrix = { { {{ 2, 1 }},
												{{ 1, 1 }} } };
	matrixMultiply( matrix );
	for( int i = 0; i < 2; ++i )
	{
		for( int j = 0; j < 2; ++j )
			std::cout << matrix[i][j] << " ";

		std::cout << "\n";
	}
}

void PracticalCppProg::pog17_2__2()
{
	std::array<std::array<int, 3>, 3> matrix = { {{{ 2, 1, 1 }},
											   {{ 2, 2, 2 }},
											   {{ 2, 1, 1 }}} };
	matrixMultiply( matrix, 5 );
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
			std::cout << matrix[i][j] << " ";

		std::cout << "\n";
	}
}

void PracticalCppProg::pog17_2__3()
{
	std::cout << "vec2x2:\n";
	size_t x = 3;
	size_t y = 2;

	int niz[6] = { 2, 1, 1,
				  1, 1, 1 };

	std::vector<int> matricaRez = matrixMultiply( matrica_t{ x, y, niz }, matrica_t{ y, x, niz } );
	for( int i = 0; i < y; ++i )
	{
		for( int j = 0; j < y; ++j )
			std::cout << matricaRez[i * y + j] << " ";

		std::cout << "\n";
	}
}

void PracticalCppProg::pog17_5()
{
	char str[] = "tesaaaaaaaat\0";
	char noviStr[10];
	moj_memcpy( str, noviStr, 10 );
	std::cout << "novi string: " << noviStr << '\n';
}

///////////////////////////////////////////////////////////////////////////
//	341. stranica
void PracticalCppProg::pog18_1()
{
	Razlomak raz1( 1, 3, '+' );
	Razlomak raz2( 3, 8, '=' );
	Razlomak rezultat = raz1 + raz2;
	std::cout << raz1 << raz2 << rezultat;
}

void PracticalCppProg::pog18_2()
{
	Decimal dec;
	dec.setBase( 500000 );
	dec.setDecimal( -15 );
	std::cout << dec << '\n';
	dec.setBase( 16 );
	dec.setDecimal( 32 );
	std::cout << dec;
}

void PracticalCppProg::pog18_4()
{
	Time t1( 0, 0, 59, 0 );
	Time t2( 0, 25, 3, 1 );
	Time t3 = t1 - t2;
	std::cout << "  " << t1
		<< "- " << t2
		<< "----------------------\n"
		<< t3;
}

//	355. stranica
void PracticalCppProg::pog19_1()
{
	StringDouble sd1( "5.55" );
	StringDouble sd2( "2" );
	std::cout << sd1 << "+ " << sd2 << "= " << sd1 + sd2 << '\n'
		<< sd1 << "- " << sd2 << "= " << sd1 - sd2 << '\n'
		<< sd1 << "* " << sd2 << "= " << sd1 * sd2 << '\n'
		<< sd1 << "/ " << sd2 << "= " << sd1 / sd2 << '\n';
}

void PracticalCppProg::pog21_1()
{
	Checkbook* cb = new Checkbook;
	cb->total();
	cb->addItem( 1 );
	cb->addItem( 2 );
	cb->addItem( 3 );
	cb->addItem( 4 );
	cb->addItem( 5 );
	cb->addItem( 6 );
	cb->addItem( 7 );
	//cb->addItem( 8 );
	//cb->addItem( 9 );
	//cb->addItem( 10 );
	//cb->addItem( 11 );
	//cb->addItem( 12 );
	//cb->addItem( 13 );
	//cb->addItem( 14 );
	std::array<int, 10> items = static_cast<Queue*>( cb )->get10();
	for( const auto& item : items )
		std::cout << item << "\n";
	delete cb;
}

void PracticalCppProg::pog21_2()
{
	Word_match wm;
	d_Number_mather nm;
	d_BlankStr_matcher bsm;
	std::cout << "Word_match: 43, was: " << wm.match( "43" ) << wm.match( "was" )
		<< "\nNumber_match 43, was: " << nm.match( "43" ) << nm.match( "was" )
		<< "\nBlankStr_match 43,  , was: " << bsm.match( "43" ) << bsm.match( "  " ) << bsm.match( "was" );
}

void PracticalCppProg::pog21_3()
{
	d_Krug krug( 4 );
	d_Kvadrat kvad( 4 );
	d_Trokut trok( 4, 4 );
	std::cout << "Krug: " << krug.v_povrsina()
		<< "\nKvad: " << kvad.v_povrsina()
		<< "\nTrok: " << trok.v_povrsina() << "\n";
}

void PracticalCppProg::pog21_5()
{
	d_Dek dek( 42 );
	d_Okt okt( 8 );
	d_Hex hex( 16 );
	dek.print_it();
	okt.print_it();
	hex.print_it();

}


void PracticalCppProg::pog22_4()
{
	count_letter( "HelloWorld" );
	count_letter( "Hello World" );
}


//	435. stranica
////////////////////////////////////////
void PracticalCppProg::pog23_1()
{
	PageFormatting pf;
	std::string input;
	input.reserve( 32 );
	std::cout << "Unesi ime datoteke: ";
	std::getline( std::cin, input );
	pf.open_file( input.c_str() );
	std::cout << "Unesi naslov datoteke: ";
	std::getline( std::cin, input );
	pf.page();

	pf.define_header( input.c_str() );
	pf.define_header( input.c_str() );
	std::cout << "Unesi tekst:\n";
	std::getline( std::cin, input );
	pf.print_line( input.c_str() );
	pf.print_line( input.c_str() );
	pf.page();
	pf.print_line( input.c_str() );
	pf.print_line( input.c_str() );
}

void PracticalCppProg::pog23_2()
{
	std::array<const char*, 5> imenaDatoteka = { {{"Time.cpp"}, {"test"}, {"aaaaaaa"}, {"raznoMain.cpp"}, {"razno.hpp"} } };
	std::fstream datoteka = search_open( imenaDatoteka );
	std::string stream;
	stream.reserve( 256 );
	if( datoteka.is_open() )
	{
		while( std::getline( datoteka, stream ) )
		{
			std::cout << stream << '\n';
		}
	}
}

/////////-> Koristi indexe kada brises vise stvari za redom iz vektora jer se moze preselit u memoriji
//// Zato kad sam 1. put pisa kod i testira nema gresaka i sad kad opet pokrenem errori neki
void PracticalCppProg::pog23_3()
{
	SymbolTable st;
	st.enter( "test" );
	st.enter( "test" );
	st.enter( "test2" );
	st.enter( "test" );
	std::cout << ( st.lookup( "test" ) ? "Nasao sam test\n" : "Nema ga :(\n" );
	st.remove( "test" );

	std::cout << ( st.lookup( "test" ) ? "Nasao sam test\n" : "Nema ga :(\n" );
}


//	446. stranica
void PracticalCppProg::pog24_1()
{
	std::cout << "min(2, 5): " << min( 2, 5 )
		<< "\nmin(2.5, 1.05): " << min( 2.5, 1.05 )
		<< "\nmin('a', 'A'): " << min( 'a', 'A' )
		<< "\nmin(\"aA\", \"Aa\"): " << min( "aA\0", "Aa\0" ) << '\n';
}


//	484. stranica
void PracticalCppProg::pog26_1()
{
	std::string imeDatoteke{};
	std::cout << "Unesi ime datoteke: ";
	std::cin >> imeDatoteke; // npr. raznoMain.cpp
	std::cout << haveDoubleWords( imeDatoteke );
}

void PracticalCppProg::pog26_3()
{
	Mail_label test( "7", "t", "e", "S", "t" );
	Mail_label test2( "6", "t", "e", "S", "t" );
	Mail_label test3( "2", "t", "e", "S", "t" );
	Mail_label test4;
	std::cin >> test4;
	List* head = new List( test );
	List* el2 = new List( test2 );
	List* el3 = new List( test3 );
	List* el4 = new List( test4 );
	head->insert( el2 );
	el2->insert( el3 );
	el3->insert( el4 );
	std::cout << "HEAD:\n" << head->getContent()
		<< "EL2:\n" << el2->getContent()
		<< "EL3:\n" << el3->getContent()
		<< "EL4:\n" << el4->getContent();
	List::sortByID( head );
	std::cout << "\nSORTED!\nHEAD:\n" << head->getContent()
		<< "EL2:\n" << head->gotoNext()->getContent()
		<< "EL3:\n" << head->gotoNext()->gotoNext()->getContent()
		<< "EL4:\n" << head->gotoNext()->gotoNext()->gotoNext()->getContent();
}

void PracticalCppProg::pog26_5()
{
	const std::string ime = "raznoMain.cpp";
	std::fstream datoteka;
	ispisi_datoteku_u_konzolu( datoteka, ime );
}
