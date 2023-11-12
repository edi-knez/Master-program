#include "Parsity.hpp"
#include "Checkbook.hpp"
#include "Queue.hpp"
#include "Small_set.hpp"
#include "FlashCards.hpp"

#include "ShareFile1.hpp"
#include "ShareFile2_.hpp"
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

#define swap2(num, num2) (num += num2; num2 = num - num2; num -= num2)
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

const int X_SIZE = 10;
const int Y_SIZE = 10;
static bool grid[Y_SIZE][X_SIZE] { { true, false, false, false, false, false, false, false, false, true },
  { true, false, false, false, false, false, false, false, false, true }, { true, false, false, false, false, false, false, false, false, true },
  { true, false, false, false, false, false, false, false, false, true }, { true, false, false, false, false, false, false, false, false, true },
  { true, false, false, false, false, false, false, false, false, true }, { true, false, false, false, false, false, false, false, false, true },
  { true, false, false, false, false, false, false, false, false, true }, { true, false, false, false, false, false, false, false, false, true },
  { true, false, false, false, false, false, false, false, false, true } };

/*
	Zad 1:
*/

inline void set_bit(size_t x, size_t y, bool bit);
inline void clear_bit(size_t x, size_t y);
inline bool test_bit(size_t x, size_t y, bool bit);
void crtaj_grid();

/*
	Zad 2:
*/

template <class T> int numOfBits(T number);

/*
	Zad 3:
*/

std::array<short, 8> podijeliIntegerU8Dijela(int broj);

/*
	Zad 4:
*/

char shiftBitsLeft(char broj);

/*
	str 227, zad1
*/

bool is_using_file(const ShareFile1& cFile1);
bool is_using_file(const ShareFile2_& cFile2);

int ukupanBrojZivotinja();

/*
	poglavlje 15:
	zad 1:
*/

void postavi_niz_na_nulu(std::array<int, 15>& niz);
const char* prvi_alfa_num(const char* word);

/*
	Poglavlje 17
	zad 2:
*/

struct matrica_t {
  matrica_t() = delete;
  matrica_t(size_t x, size_t y, const int* niz)
	  : m_x(x)
	  , m_y(y)
	  , m_niz(niz)
  {
  }

  size_t m_x;
  size_t m_y;
  const int* m_niz;
};

void matrixMultiply(std::array<std::array<int, 2>, 2>& niz);
void matrixMultiply(std::array<std::array<int, 3>, 3>& niz);
void matrixMultiply(std::array<std::array<int, 3>, 3>& niz, int m);
std::vector<int> matrixMultiply(struct matrica_t, struct matrica_t);

/*
	zad 5
*/

void moj_memcpy(const char from[], char to[], size_t n);

/*
	Poglavlje 22
	Zad 5:
*/

void count_letter(const char* cstring) noexcept(false);

/*
	Poglavlje 23
	Zad 2:
*/

std::fstream search_open(std::array<const char*, 5> imenaDatoteka);

/*
	Poglavlje 24
	Zad 1:
*/

template <typename T> T min(T el1, T el2) { return (el1 < el2) * el1 + (el2 < el1) * el2; }

const char* min(const char* el1, const char* el2)
{
  int res1 = strcmp(el1, el2);
  if (res1 < 0)
	return el1;
  else
	return el2;
}

/*
	Poglavlje 26
	Zad 1:
*/

int32_t haveDoubleWords(const std::string_view imeDatoteke);

/*
	Poglavlje 26
	Zad 5:
*/

void ispisi_datoteku_u_konzolu( std::fstream& datoteka, const std::string& imeDatoteke );

int main() ///////////////////////////////////////////////////////////////////     MAIN
{
  //BOLEAN b = TRUE;
  //if( b )
  //	std::cout << "TEST\n";

  //std::cout << divisibleBy10( 10 );

  //std::cout << is_digit( 5 );
  //std::cout << is_hex( 5 );
  //std::cout << is_hex( 'b' );
  //std::cout << is_hex( 'g' );
  //std::cout << is_hex( 'F' );

  //int a = 5, b = 14, temp = 0;
  //swap( a, b, temp );
  //std::cout << a << " " << b << "\n";
  //swap2( a, b );
  //std::cout << a << " " << b << "\n";
  ////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  //	crtaj();
  //for( int i = 0; i < X_SIZE; ++i )
  //{
  //	set_bit( i, 0, true );
  //	set_bit( i, Y_SIZE - 1, 1 );
  //}
  //std::cout << "\n";

  //crtaj();
  //for( int i = 0; i < X_SIZE; ++i )
  //{
  //	clear_bit( i, 0 );
  //}
  //std::cout << "\n";
  //crtaj();

  //std::cout << numOfBits( 5 ) << "\n"
  //	<< numOfBits( 10 ) << "\n"
  //	<< numOfBits( 15 ) << "\n";
  //std::cout << numOfBits( -5 ) << "\n"
  //	<< numOfBits( -15 ) << "\n";

  //int broj;
  //int temp;
  //std::cin >> broj;
  //temp = broj;
  //for( int i = 0; i < 32 || temp > 0; ++i )
  //{
  //	std::cout << ( temp & 0x01 );
  //	temp >>= 1;
  //}

  //std::cout << "\n";
  //std::array<short, 8> odvojeno;
  //odvojeno = podijeliIntegerU8Dijela( broj );
  //for( int i = 0; i < 8; ++i )
  //{
  //	for( int j = 0; j < 4; ++j )
  //	{
  //		std::cout << ( odvojeno[i] & 0x01 );
  //		odvojeno[i] >>= 1;
  //	}
  //	std::cout << "\n";
  //}

  //char broj = 54;
  //char result =  shiftBitsLeft( broj );
  //std::cout << "\nBroj: ";
  //for( int i = 0; i < 8; ++i )
  //{
  //	std::cout << static_cast<bool>( broj & 0x80 );
  //	broj <<= 1;
  //}
  //std::cout << "(2)\nRezultat: ";
  //for( int i = 0; i < 8; ++i )
  //{
  //	std::cout << static_cast<bool>( result & 0x80 );
  //	result <<= 1;
  //}
  //std::cout << "(2)";


  //Parsity primjer;
  //primjer.put();
  //std::cout << primjer.test() << "\n";
  //primjer.put();
  //std::cout << primjer.test() << "\n";

  //Checkbook book1;
  //book1.addItem( 5 );
  //book1.addItem( 100 );
  //book1.addItem( 100 );
  //std::cout << book1.total();

  //queue->vjezbe
  //Queue q;
  //q.put( 1 );
  //q.put( 2 );
  //q.put( 3 );
  //std::cout << q.get() << "\n";
  //std::cout << q.get() << "\n";
  //q.put( 10 );
  //std::cout << q.get() << "\n";

  //Small_set small_set;
  //small_set.set( 3 );
  //small_set.set( 5 );
  //small_set.set( 5 );
  //std::cout << small_set.test( 3 ) << '\n';      // Prints "1"
  //std::cout << small_set.test( 0 ) << '\n';        // Prints "0"
  //small_set.clear( 5 );                             // Set contains [3]
  //Small_set another_set( small_set );
  //small_set.set( 0 );
  //std::cout << small_set.test( 3 ) << '\n';      // Prints "1"
  //std::cout << small_set.test( 0 ) << '\n';        // Prints "0"

  //todo: FlachCards klasa
  //const int n = 5;
  //FlashCards::single_card cards[n] = {
  //    { "test1", "test11" },
  //    { "test2", "test2" },
  //    { "test3", "test3" },
  //    { "test4", "test4" },
  //    { "test5", "test5" }
  //};

  //FlashCards fc( cards, n );
  //fc.izbornik();

  //////////////////////////////////////
  //ShareFile1 test;
  //std::cout << "ShareFile1: " << is_using_file( test ) << "\n";
  //ShareFile2_ test2;
  //std::cout << "ShareFile2: " << is_using_file( test2 ) << "\n";
  //std::cout << "----------------\n";

  //test.otvori_datoteku();
  //std::cout << "ShareFile1: " << is_using_file( test ) << "\n";
  //test2.otvori_datoteku();
  //std::cout << "ShareFile2: " << is_using_file( test2 ) << "\n";
  //std::cout << "----------------\n";

  //test.zatvori_datoteku();
  //test2.zatvori_datoteku();
  //test2.otvori_datoteku();
  //std::cout << "ShareFile2: " << is_using_file( test2 ) << "\n";
  //test.otvori_datoteku();
  //std::cout << "ShareFile1: " << is_using_file( test ) << "\n";
  ////////////////////////////////////////

  //std::array<Pigs, 5> pigs;
  //std::array<Dogs, 2> dogs;
  //std::array<Horses, 3> horses;
  //std::cout << ukupanBrojZivotinja() << "\n";

  //std::array<Stack_Instance, 5> stacks;
  //std::cout << Stack_Instance::who_is_owner( &stacks[0], 5 ) << "\n";
  //stacks[0].take_control();
  //std::cout << Stack_Instance::who_is_owner( &stacks[0], 5 ) << "\n";
  //stacks[4].pop();
  //stacks[0].push_back( 10 );
  //std::cout << "stack[0] size: " << stacks[0].size()
  //    << "\nstack[1] size: " << stacks[1].size()
  //    << '\n';

  //227. stranica
  //char ime[] = "Dogs.hpp";
  //Line_number test( ime );
  //Line_number test2( ime );
  //std::cout << "test2.getCurrentLine(): " << test2.getCurrentLine() << '\n';
  //std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg()<<"\n";
  //test.goto_line( 5 );
  //std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg()<<"\n";
  //test.goto_line( 2 );
  //std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg()<<"\n";
  //test2.goto_line( 2 );
  //std::cout << "\ntest - test2: " << test.getFileRef().tellg() << " - " << test2.getFileRef().tellg()<<"\n";
  //std::cout << "test.getCurrentLine(): " << test.getCurrentLine() << '\n';
  //std::cout << "test.getFileRef().tellg(): " << test.getFileRef().tellg() << '\n';
  //test2.goto_line( 6 );
  //test.goto_line( 6 );
  //std::cout << "test.getCurrentLine(): " << test.getCurrentLine() << '\n';
  //std::cout << "test2.getCurrentLine(): " << test2.getCurrentLine() << '\n';
  //test2.getFileRef().seekg( 5, std::ios::cur );
  //std::cout << "test2.getCharPos(): " << test2.getCharPos() << '\n';
  //test2.goto_line( 0 );
  //test2.getFileRef().seekg( 5, std::ios::beg );
  //std::cout << "test2.getCharPos(): " << test2.getCharPos() << '\n';

  //254. stranica
  //std::array<int, 15> niz;
  //niz.fill( 15 );
  //for( const auto& n : niz )
  //	std::cout << n << " ";
  //std::cout << "\n";
  //postavi_niz_na_nulu( niz );
  //for( const auto& n : niz )
  //	std::cout << n << " ";
  //std::cout << "\n";

  //const char str1[] = " \ttest ";
  //const char str2[] = "  \t ";
  //const char* c = prvi_alfa_num( str1 );
  //const char* d = prvi_alfa_num( str2 );
  //if( c )
  //	std::cout << c << "\n";
  //else
  //	std::cout << "nullptr\n";
  //if( d )
  //	std::cout << d << "\n";
  //else
  //	std::cout << "nullptr\n";

  //////////////////////////////////////////////////////////////
  //File_16C f1( "linije.dat" );
  //std::cout << "broj linija: " << f1.numOfLinesInFile() << " u datoteci: \"" << f1.getName() << "\"\n";

  //File_16C f2( "linija.dat" );
  //f2.copy_file( "copy-linija.dat" );

  //File_16C f3;
  //std::fstream lista( "lista.dat", std::ios::out );
  //lista << 3 << " " << 6 << " " << 9 << " " << 10 << " " << 11 << " " << 12;
  //lista.close();
  //lista.open( "lista.dat", std::ios::out | std::ios::in | std::ios::ate );
  //lista.seekg( std::ios::beg );
  //std::cout << "\"lista.dat\": ";
  //f3.ispis( lista );
  //std::cout << "\n";
  //f3.listOfNumbers( lista );

  //std::fstream sa3( "djeljivi sa 3.dat", std::ios::in | std::ios::app );
  //std::cout << "\"djeljivi sa 3.dat\": ";
  //f3.ispis( sa3 );
  //std::cout << "\n";

  //std::fstream ostali( "svi ostali.dat", std::ios::in | std::ios::app );
  //std::cout << "\"svi ostali.dat\": ";
  //f3.ispis( ostali );
  //std::cout << "\n";

  //lista.close();
  //sa3.close();
  //ostali.close();

  //File_16C f4( "File_16C remove high bit.txt" );
  //typedef const unsigned char cuc;
  //cuc podaci[] = { static_cast< cuc >( 192 ), static_cast< cuc >( 168 ), static_cast< cuc >( 128 ), static_cast< cuc >( 125 ), '\0' };
  //std::fstream in( f4.getName(), std::ios::out | std::ios::app | std::ios::trunc );
  //in << podaci;
  //in.close();

  //f4.removeHighBit();

  //File_16C f5( "pretvorba ASCI u bin.dat" );
  //std::cout << "PRIJE: ";

  //f5.ispis();
  //if( f5.ASCI_to_bin() )
  //{
  //	std::cout << "\nPretvorba uspjesna!\n";
  //	f5.bin_to_ASCI();
  //	std::cout << "\nPOSLIJE: ";
  //	f5.ispis();
  //}
  //else
  //	std::cout << "Nista nece da radi\n";

  //File_16C f6( "osobe.inf" );
  //f6.read_info_o_osobi();
  //f6.ispis_osoba();
  ////////////////////////////////////////////////////////////////

  // 317. stranica
  ////////////////////////////////////////////////////////////////////////
  //std::array<std::array<int, 3>, 3> matrix = { {{{ 2, 1, 1 }},
  //											 {{ 2, 2, 2 }},
  //											 {{ 2, 1, 1 }}} };
  //std::cout << "2x2:\n";
  //std::array<std::array<int, 2>, 2> matrix = {{ {{ 2, 1 }},
  //											  {{ 1, 1 }} }};
  //matrixMultiply( matrix );
  //for( int i = 0; i < 2; ++i )
  //{
  //	for( int j = 0; j < 2; ++j )
  //		std::cout << matrix[i][j] << " ";

  //	std::cout << "\n";
  //}

  //std::array<std::array<int, 3>, 3> matrix = { {{{ 2, 1, 1 }},
  //											 {{ 2, 2, 2 }},
  //											 {{ 2, 1, 1 }}} };
  //matrixMultiply( matrix, 5 );
  //for( int i = 0; i < 3; ++i )
  //{
  //	for( int j = 0; j < 3; ++j )
  //		std::cout << matrix[i][j] << " ";

  //	std::cout << "\n";
  //}

  //std::cout << "vec2x2:\n";
  //size_t x = 3;
  //size_t y = 2;

  //int niz[6] = { 2, 1, 1,
  //				1, 1, 1 };

  //std::vector<int> matricaRez =  matrixMultiply( matrica_t{ x, y, niz }, matrica_t{ y, x, niz } );
  //for( int i = 0; i < y; ++i )
  //{
  //	for( int j = 0; j < y; ++j )
  //		std::cout << matricaRez[i * y + j] << " ";

  //	std::cout << "\n";
  //}
  ///////////////////////////////////////////////////////////////////////////

  //char str[] = "tesaaaaaaaat\0";
  //char noviStr[10];
  //moj_memcpy( str, noviStr, 10 );
  //std::cout << "novi string: " << noviStr << '\n';

  //	341. stranica

  //Razlomak raz1( 1, 3, '+' );
  //Razlomak raz2( 3, 8, '=' );
  //Razlomak rezultat = raz1 + raz2;
  //std::cout << raz1 << raz2 << rezultat;

  //Decimal dec;
  //dec.setBase( 500000 );
  //dec.setDecimal( -15 );
  //std::cout << dec << '\n';
  //dec.setBase( 16 );
  //dec.setDecimal( 32 );
  //std::cout << dec;

  //Time t1( 0, 0, 59, 0 );
  //Time t2( 0, 25, 3, 1 );
  //Time t3 = t1 - t2;
  //std::cout << "  " << t1
  //	<< "- " << t2
  //	<< "----------------------\n"
  //	<< t3;

  //	355. stranica

  //StringDouble sd1("5.55");
  //StringDouble sd2("2");
  //std::cout << sd1 << "+ " << sd2 << "= " << sd1 + sd2 << '\n'
  //	<< sd1 << "- " << sd2 << "= " << sd1 - sd2 << '\n'
  //	<< sd1 << "* " << sd2 << "= " << sd1 * sd2 << '\n'
  //	<< sd1 << "/ " << sd2 << "= " << sd1 / sd2 << '\n';

  //	21. poglavlje procitat kad zavrsis queue & stack vjezbe

  //Checkbook* cb = new Checkbook;
  //cb->total();
  //cb->addItem( 1 );
  //cb->addItem( 2 );
  //cb->addItem( 3 );
  //cb->addItem( 4 );
  //cb->addItem( 5 );
  //cb->addItem( 6 );
  //cb->addItem( 7 );
  ////cb->addItem( 8 );
  ////cb->addItem( 9 );
  ////cb->addItem( 10 );
  ////cb->addItem( 11 );
  ////cb->addItem( 12 );
  ////cb->addItem( 13 );
  ////cb->addItem( 14 );
  //std::array<int, 10> items = static_cast<Queue*>(cb)->get10();
  //for( const auto& item : items )
  //	std::cout << item << "\n";
  //delete cb;

  //Word_match wm;
  //d_Number_mather nm;
  //d_BlankStr_matcher bsm;
  //std::cout << "Word_match: 43, was: " << wm.match( "43" ) << wm.match( "was" )
  //	<< "\nNumber_match 43, was: " << nm.match("43") << nm.match("was")
  //	<< "\nBlankStr_match 43,  , was: " << bsm.match("43") << bsm.match(" ") << bsm.match("was");

  //d_Krug krug( 4 );
  //d_Kvadrat kvad( 4 );
  //d_Trokut trok( 4, 4 );
  //std::cout << "Krug: " << krug.v_povrsina()
  //	<< "\nKvad: " << kvad.v_povrsina()
  //	<< "\nTrok: " << trok.v_povrsina() << "\n";

  //d_Dek dek( 42 );
  //d_Okt okt( 8 );
  //d_Hex hex( 16 );
  //dek.print_it();
  //okt.print_it();
  //hex.print_it();

  //count_letter( "HelloWorld" );
  //count_letter( "Hello World" );

  //	435. stranica

  ////////////////////////////////////////
  //PageFormatting pf;
  //std::string input;
  //input.reserve( 32 );
  //std::cout << "Unesi ime datoteke: ";
  //std::getline( std::cin, input );
  //pf.open_file( input.c_str() );
  //std::cout << "Unesi naslov datoteke: ";
  //std::getline( std::cin, input );
  //pf.page();

  //pf.define_header( input.c_str() );
  //pf.define_header( input.c_str() );
  //std::cout << "Unesi tekst:\n";
  //std::getline( std::cin, input );
  //pf.print_line( input.c_str() );
  //pf.print_line( input.c_str() );
  //pf.page();
  //pf.print_line( input.c_str() );
  //pf.print_line( input.c_str() );
  /////////////////////////////////////////

  //std::array<const char*, 5> imena = { {{"Time.cpp"}, {"test"}, {"aaaaaaa"}, {"razno.cpp"}, {"razno.hpp"} } };
  //std::fstream datoteka = search_open(imena);
  //std::string stream;
  //stream.reserve( 256 );
  //if(datoteka.is_open())
  //{
  //    while ( std::getline( datoteka, stream ) )
  //    {
  //        std::cout << stream << '\n';
  //    }
  //}

  /////////-> Kada koristis usrane std vektore i sranja sa dinamickom memorijom, koristi indexe jer ce se iz cistog mira preselit u memoriji i pointeri nece vazit
  //// Zato kad sam 1. put pisa kod i testira nema gresaka i sad kad opet pokrenem errori neki
  //SymbolTable st;
  //st.enter( "test" );
  //st.enter( "test" );
  //st.enter( "test2" );
  //st.enter( "test" );
  //std::cout << ( st.lookup( "test" ) ? "Nasao sam test\n" : "Nema ga :(\n" );
  //st.remove( "test" );

  //std::cout << ( st.lookup( "test" ) ? "Nasao sam test\n" : "Nema ga :(\n" );

  //	446. stranica

  //std::cout << "min(2, 5): " << min( 2, 5 )
  //<< "\nmin(2.5, 1.05): " << min( 2.5, 1.05 )
  //<< "\nmin('a', 'A'): " << min( 'a', 'A' )
  //<< "\nmin(\"aA\", \"Aa\"): " << min( "aA\0", "Aa\0" ) << '\n';

  //	484. stranica
  //std::string imeDatoteke {};
  //std::cout << "Unesi ime datoteke: ";
  //std::cin >> imeDatoteke; // npr. razno.cpp
  //std::cout << haveDoubleWords( imeDatoteke );

  //Mail_label test( "7", "t", "e", "S", "t" );
  //Mail_label test2( "6", "t", "e", "S", "t" );
  //Mail_label test3( "2", "t", "e", "S", "t" );
  //Mail_label test4;
  //std::cin >> test4;
  //List* head = new List( test );
  //List* el2 = new List( test2 );
  //List* el3 = new List( test3 );
  //List* el4 = new List( test4 );
  //head->insert( el2 );
  //el2->insert( el3 );
  //el3->insert( el4 );
  //std::cout << "HEAD:\n" << head->getContent()
  //    << "EL2:\n" << el2->getContent()
  //    << "EL3:\n" << el3->getContent()
  //    << "EL4:\n" << el4->getContent();
  //List::sortByID( head );
  //std::cout << "\nSORTED!\nHEAD:\n" << head->getContent()
  //    << "EL2:\n" << head->gotoNext()->getContent()
  //    << "EL3:\n" << head->gotoNext()->gotoNext()->getContent()
  //    << "EL4:\n" << head->gotoNext()->gotoNext()->gotoNext()->getContent();


	////const std::string ime = "test.dat";
	////std::fstream datoteka;
	////ispisi_datoteku_u_konzolu( datoteka, ime );

  return 0;
} ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   END MAIN


inline void set_bit(size_t x, size_t y, bool bit) { grid[y][x] = bit; }
inline void clear_bit(size_t x, size_t y) { set_bit(x, y, false); }
inline bool test_bit(size_t x, size_t y, bool bit) { return grid[y][x] == bit; }
void crtaj_grid()
{
  for (int i = 0; i < Y_SIZE; ++i) {
	for (int j = 0; j < X_SIZE; ++j) {
	  if (test_bit(j, i, true))
		std::cout << "X";
	  else
		std::cout << " ";
	}
	std::cout << "\n";
  }
}

template <typename T> size_t numOfBits(T number)
{
  size_t bits = 0;
  int sizeofType = 1 << sizeof(number);
  while (number <<= 1) {
	if (number & (1 << sizeofType))
	  bits++;
  }
  return bits;
}

int numOfBits(std::string) { return -1; }

int numOfBits(bool) { return -1; }

std::array<short, 8> podijeliIntegerU8Dijela(int broj)
{
  std::array<short, 8> dijelovi {};

  for (int i = 0; i < 8; ++i) {
	dijelovi[i] = (broj & 0x0F); // broj & 1111 (2)
	broj >>= 4; // pomakni sve bitove za 4 mjesta ulijevo, tako ce npr broj 127 -> 0111 1111 (2) postat: 0000 0111 (2)
  }

  return dijelovi;
}


/// <summary>
/// Pomakni sve bitove ulijevo koji imaju vrijednost 1
/// </summary>
/// <param name=" broj-">Shift bits of this number</param>
/// <returns>Shifted all 1s to left</returns>
char shiftBitsLeft(char broj)
{
  // zamjeni sa bool*
  std::cout << "DEBUG TEST:\n";
  char result = 0;
  for (int i = 0; i < 8; ++i) // char ima 8 bitova
  {
	if (!(broj & (0x01 << i))) // prekocit ce sve slucajeve kada se na i-tom mjestu nalazi 0
	  continue;

	for (int j = 7; j > 0; --j) {
	  if (!(result & (0x01 << j))) // kada nade prvo mjesto sa lijeve strane koje je 0, stavit ce 1 u njega
	  {
		result |= 1 << j;
		break;
	  }
	}
	//////////////////////////
	std::cout << "temp: "; // debugging purpose
	int temp = result;
	for (int j = 0; j < 8; ++j) {
	  std::cout << static_cast<bool>(temp & 0x80);
	  temp <<= 1;
	}
	std::cout << "(2)\n";
	//////////////////////////
  }
  return result;
}

bool is_using_file(const ShareFile1&) { return ShareFile1::used(); }

bool is_using_file(const ShareFile2_&) { return ShareFile2_::used(); }

inline int horseCnt() { return Horses::animalCount; }
inline int pigsCnt() { return Pigs::animalCount; }
inline int dogsCnt() { return Dogs::animalCount; }

int ukupanBrojZivotinja() { return horseCnt() + pigsCnt() + dogsCnt(); }

void postavi_niz_na_nulu(std::array<int, 15>& n)
{
  int* curr = n.data();
  for (; curr <= &n[14]; ++curr)
	*curr = 0;

  //ili
  //memset( &n, 0, sizeof n );
}

const char* prvi_alfa_num(const char* word)
{
  size_t sz = strlen(word);
  for (size_t i = 0; i < sz; ++i) {
	if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= '0' && word[i] <= '9'))
	  return &word[i];
  }
  return nullptr;
}

void matrixMultiply(std::array<std::array<int, 3>, 3>& matrix, int m)
{
  for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
	  matrix[i][j] = m * matrix[i][j];
}

void matrixMultiply(std::array<std::array<int, 2>, 2>& matrix)
{
  std::array<std::array<int, 2>, 2> noviMatrix { { 0 } };
  for (size_t i = 0; i < 2; ++i)
	for (size_t j = 0; j < 2; ++j)
	  for (size_t k = 0; k < 2; ++k)
		noviMatrix[i][j] += matrix[i][k] + matrix[k][j];

  matrix = noviMatrix;
}

void matrixMultiply(std::array<std::array<int, 3>, 3>& matrix)
{
  std::array<std::array<int, 3>, 3> noviMatrix { { 0 } };
  for (size_t i = 0; i < 3; ++i)
	for (size_t j = 0; j < 3; ++j)
	  for (size_t k = 0; k < 3; ++k)
		noviMatrix[i][j] += matrix[i][k] + matrix[k][j];

  matrix = noviMatrix;
}

std::vector<int> matrixMultiply(struct matrica_t matrica1, struct matrica_t matrica2)
{

  std::vector<int> noviMatrix;

  if (matrica1.m_y != matrica2.m_x) {
	std::cout << "Ove matrice se nemogu mnozit!\n";
	return noviMatrix;
  }

  noviMatrix.reserve(matrica1.m_y * matrica2.m_x);
  while (noviMatrix.size() < noviMatrix.capacity())
	noviMatrix.push_back(0); // napuni vektor sa nulama

  for (int i = 0; i < matrica2.m_x; ++i)
	for (int j = 0; j < matrica1.m_y; ++j)
	  for (int k = 0; k < matrica2.m_x; ++k)
		noviMatrix[i * matrica1.m_y + j] += matrica1.m_niz[i * matrica1.m_y + k] + matrica2.m_niz[k * matrica2.m_x + j];

  return noviMatrix;
}

void moj_memcpy(const char from[], char to[], size_t n)
{
  size_t idx = 0;
  for (; from[idx] != '\0' && idx < n - 1; ++idx) {
	to[idx] = from[idx];
  }
  to[idx] = '\0';
}

void count_letter(const char* c) noexcept(false)
{
  uint8_t samoglasnici = 0, suglasnici = 0;
  for (; *c != '\0'; ++c) {
	if (*c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u' || *c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U')
	  ++samoglasnici;
	else if (isalpha(*c))
	  ++suglasnici;
	else
	  throw "Znak \"" + *c + std::string("\" nije slovo!\n");
  }
  std::cout << "Suglasnici: " << static_cast<size_t>(suglasnici) << "\nSamoglasnici: " << static_cast<size_t>(samoglasnici) << '\n';
}

std::fstream search_open(std::array<const char*, 5> imenaDatoteka)
{
  std::fstream datoteka;
  for (size_t i = 0; i < 5; ++i) {
	datoteka.open(imenaDatoteka[i], std::ios::in);
	if (datoteka.is_open())
	  return datoteka;
  }
  std::cout << "Nisam nasao datoteku koja postoji!\n";
  return std::fstream();
}

/// <summary>
/// Pretrazuje datoteku dok ne nade duplu rijec
/// </summary>
/// <param name="imeDatoteke">Datoteka u koja ce se pretrazivat</param>
/// <returns>
/// -1  -> nemoze se otvorit datoteka ili nepostoji,
/// 0   -> nema duplikata,
/// 1   -> ima duplikata ( najmanje 1 )
/// </returns>
int32_t haveDoubleWords(const std::string_view imeDatoteke)
{
  std::array<std::string, 10000> rijeci;
  size_t count = 0;
  std::ifstream ulaz(imeDatoteke.data(), std::ios::in);
  if (ulaz) {
	std::string temp {};
	temp.reserve(32);
	for (char ch; !ulaz.eof(); temp.clear()) {
	  while (true) {
		ulaz.get(ch); // dohvacam znak i postavlja pokazivac na sljedecu lokaciju u datoteci
		if (!isalpha(ch)) // ako nije slovo stavi null termination znak i izadi
		  break;

		temp += ch;
	  }
	  if (temp[0] == '\0') // ako sam naisao na znak koji nije slovo vise puta zaredom, nemoram pregledavat
		continue;

	  // provjeravam trenutnu rijec sa kolekcijom rijeci koje sam vec pronasao
	  for (std::string_view rijec : rijeci) {
		if (count >= rijeci.size()) // ovaj slucaj se moze maknut ako se koristi podatkovna struktura (vektor): std::vector<std::string>
		{
		  std::cout << "Nema dovoljno mjesta za rijeci!\n";
		  return -2;
		} else if (temp == rijec) // pronasli smo duplikat, izadi iz funkcije sa vrijednosti true
		  return true;
		else if (rijec.empty()) // naisli smo na prazno mjesto u kolekciji
		{
		  rijeci[count++] = temp; // dodaj rijec na prazno mjesto i povecaj trenutan broj rijeci
		  break; // posao obavljen, odi trazit novu rijec
		}
	  }
	}
	return false; // nismo nasli niti jednu duplu rijec
  } else {
	std::cout << "Datoteka ne postoji / nemoze se otvorit.\n";
	return -1;
  }
}

void ispisi_datoteku_u_konzolu(std::fstream& datoteka, const std::string& imeDatoteke)
{
  datoteka.open(imeDatoteke, std::ios::in);
  bool zavrsenoCitanje = false;

  std::string buf;
  buf.reserve( 8096 );
  while (!zavrsenoCitanje) 
  {
	for( size_t counterChars = 0, counterForceBreak = 1, pos = 0; counterChars < 60 * 127; ++counterChars, ++counterForceBreak ) 
	{
	  if( datoteka.eof() ) {
		zavrsenoCitanje = true;
		break;
	  }

	  int c = datoteka.get();
	  buf += static_cast<unsigned char>(c);

	  if( c == '\n' ) {
		counterForceBreak = 0;
		pos = 0;
	  }
	  // The split point should be at the end of a sentence if possible,
	  if( c == '.' ) 
	  {
		// provjeri dali je sljedeci znak u datoteci new line znak
		if( datoteka.get() != '\n' )
		  buf += '\n';
		datoteka.seekg( -1, std::ios::cur ); // vrati get pointer za jedno mjesto
		++counterChars;
		counterForceBreak = 0;
		pos = 0;
	  }
	  
	  if( c == ' ' )
		  pos = counterForceBreak;

	  ////  or at the end of a word if a sentence is too long//.
	  if( counterForceBreak == 127 ) 
	  {
		  if( pos > 0 )
		  {
			buf[counterChars - (127 - pos)] = '\n';
		  }
		  else 
		  {
			++counterChars;
			buf += '\n';
		  }
		  counterForceBreak = 0;
		  pos = 0;
	  }

	}
	std::cout << buf;
	buf.clear();
  }
}