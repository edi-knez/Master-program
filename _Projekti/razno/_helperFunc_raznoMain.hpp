
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




inline void set_bit( size_t x, size_t y, bool bit ) { grid[y][x] = bit; }
inline void clear_bit( size_t x, size_t y ) { set_bit( x, y, false ); }
inline bool test_bit( size_t x, size_t y, bool bit ) { return grid[y][x] == bit; }
void crtaj_grid()
{
	for( int i = 0; i < Y_SIZE; ++i )
	{
		for( int j = 0; j < X_SIZE; ++j )
		{
			if( test_bit( j, i, true ) )
				std::cout << "X";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
}

/// <summary>
///		broji sve postavljene bitove u broju
/// </summary>
/// <param name=" broj koji te zanima</param>
/// <returns> Broj postavljenih bitova</returns>
template <typename T> size_t numOfBits( T number )
{
	size_t bits = 0;
	while( number >>= 1 )
	{
		bits += number & 1;	// OPTIMIZACIJA: branchless brojanje bitova, uklonjen nepotreban shift jer je redoslijed usporedivanja bitova promijenjen
	}
	return bits;
}

int numOfBits( std::string ) { return -1; }

int numOfBits( bool ) { return -1; }

std::array<short, 8> podijeliIntegerU8Dijela( int broj )
{
	std::array<short, 8> dijelovi{};

	for( int i = 0; i < 8; ++i )
	{
		dijelovi[i] = ( broj & 0x0F ); // broj & 1111 (2)
		broj >>= 4; // pomakni sve bitove za 4 mjesta ulijevo, tako ce npr broj 127 -> 0111 1111 (2) postat: 0000 0111 (2)
	}

	return dijelovi;
}


/// <summary>
///		Pomakni sve bitove ulijevo koji imaju vrijednost 1
/// </summary>
/// <param name=" broj-">Shift bits of this number</param>
/// <returns>Shifted all 1s to left</returns>
char shiftBitsLeft( char broj )
{
  // zamjeni sa bool*
	std::cout << "DEBUG TEST:\n";
	char result = 0;
	for( int i = 0; i < 8; ++i ) // char ima 8 bitova
	{
		if( !( broj & ( 0x01 << i ) ) ) // prekocit ce sve slucajeve kada se na i-tom mjestu nalazi 0
			continue;

		for( int j = 7; j > 0; --j )
		{
			if( !( result & ( 0x01 << j ) ) ) // kada nade prvo mjesto sa lijeve strane koje je 0, stavit ce 1 u njega
			{
				result |= 1 << j;
				break;
			}
		}
		//////////////////////////
		std::cout << "temp: "; // debugging purpose
		int temp = result;
		for( int j = 0; j < 8; ++j )
		{
			std::cout << static_cast<bool>( temp & 0x80 );
			temp <<= 1;
		}
		std::cout << "(2)\n";
		//////////////////////////
	}
	return result;
}

bool is_using_file1() { return ShareFile1::used(); }

bool is_using_file1( const int ) { return ShareFile2_::used(); }

inline int horseCnt() { return Horses::animalCount; }
inline int pigsCnt() { return Pigs::animalCount; }
inline int dogsCnt() { return Dogs::animalCount; }

int ukupanBrojZivotinja() { return horseCnt() + pigsCnt() + dogsCnt(); }

void postavi_niz_na_nulu( std::array<int, 15>& n )
{
	int* curr = n.data();
	for( auto cur = std::begin( n ); cur != std::end( n ); ++curr )
		*curr = 0;

	  //ili
	  //memset( &n, 0, sizeof n );

	// ili
	//for( auto& el : n )
	//{
	//	el = 0;
	//}
}

const char* prvi_alfa_num( const char* word )
{
	for( size_t i = 0; word[i] != '\0'; ++i )
	{
		if( ( word[i] >= 'a' && word[i] <= 'z' ) ||
			( word[i] >= 'A' && word[i] <= 'Z' ) ||
			( word[i] >= '0' && word[i] <= '9' ) )
			return &word[i];
	}
	return nullptr;
}

void matrixMultiply( std::array<std::array<int, 3>, 3>& matrix, int m )
{
	for( int i = 0; i < 3; ++i )
		for( int j = 0; j < 3; ++j )
			matrix[i][j] *= m;
}

void matrixMultiply( std::array<std::array<int, 2>, 2>& matrix )
{
	std::array<std::array<int, 2>, 2> noviMatrix{ { 0 } };
	for( size_t i = 0; i < 2; ++i )
		for( size_t j = 0; j < 2; ++j )
			for( size_t k = 0; k < 2; ++k )
				noviMatrix[i][j] += matrix[i][k] + matrix[k][j];

	matrix = noviMatrix;
}

void matrixMultiply( std::array<std::array<int, 3>, 3>& matrix )
{
	std::array<std::array<int, 3>, 3> noviMatrix{ { 0 } };
	for( size_t i = 0; i < 3; ++i )
		for( size_t j = 0; j < 3; ++j )
			for( size_t k = 0; k < 3; ++k )
				noviMatrix[i][j] += matrix[i][k] + matrix[k][j];

	matrix = noviMatrix;
}

std::vector<int> matrixMultiply( struct matrica_t matrica1, struct matrica_t matrica2 )
{

	std::vector<int> noviMatrix;

	if( matrica1.m_y != matrica2.m_x )
	{
		std::cout << "Ove matrice se nemogu mnozit!\n";
		return noviMatrix;
	}

	noviMatrix.reserve( matrica1.m_y * matrica2.m_x );
//	memset( static_cast<void*>( &noviMatrix.begin() ), 0, matrica1.m_y * matrica2.m_x );
	while( noviMatrix.size() < noviMatrix.capacity() )
		noviMatrix.push_back( 0 ); // napuni vektor sa nulama

	for( int i = 0; i < matrica2.m_x; ++i )
		for( int j = 0; j < matrica1.m_y; ++j )
			for( int k = 0; k < matrica2.m_x; ++k )
				noviMatrix[i * matrica1.m_y + j] += matrica1.m_niz[i * matrica1.m_y + k] + matrica2.m_niz[k * matrica2.m_x + j];

	return noviMatrix;
}

static void moj_memcpy( const char from[], char to[], size_t n )
{
	size_t idx = 0;
	for( ; from[idx] != '\0' && idx < n - 1; ++idx )
	{
		to[idx] = from[idx];
	}
	to[idx] = '\0';
}

void count_letter( const char* c ) noexcept( false )
{
	uint8_t samoglasnici = 0, suglasnici = 0;
	for( ; *c != '\0'; ++c )
	{
		if( *c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u' ||
			*c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U' )
			++samoglasnici;
		else if( isalpha( *c ) )
			++suglasnici;
		else
			throw "Znak \"" + *c + std::string( "\" nije slovo!\n" );
	}
	std::cout << "Suglasnici: " << static_cast<size_t>( suglasnici ) << "\nSamoglasnici: " << static_cast<size_t>( samoglasnici ) << '\n';
}

std::fstream search_open( const std::array<const char*, 5>& imenaDatoteka )
{
	std::fstream datoteka;
	for( size_t i = 0; i < 5; ++i )
	{
		datoteka.open( imenaDatoteka[i], std::ios::in );
		if( datoteka.is_open() )	return datoteka;
	}
	std::cout << "Nisam nasao datoteku koja postoji!\n";
	return std::fstream();
}

/// <summary>
/// </summary>
/// <param name="imeDatoteke">Datoteka u koja ce se pretrazivat</param>
/// <returns>
/// -1  -> nemoze se otvorit datoteka ili nepostoji,
/// 0   -> nema duplikata,
/// 1   -> ima duplikata ( najmanje 1 )
/// </returns>
int32_t haveDoubleWords( const std::string_view imeDatoteke )
{
	std::array<std::string, 10000> rijeci;
	size_t count = 0;
	std::ifstream ulaz( imeDatoteke.data(), std::ios::in );
	if( ulaz )
	{
		std::string temp{};
		temp.reserve( 32 );
		for( char ch; !ulaz.eof(); temp.clear() )
		{
			while( true )
			{
				ulaz.get( ch ); // dohvacam znak i postavlja pokazivac na sljedecu lokaciju u datoteci
				if( !isalpha( ch ) ) // ako nije slovo stavi null termination znak i izadi
					break;

				temp += ch;
			}
			if( temp[0] == '\0' ) // ako sam naisao na znak koji nije slovo vise puta zaredom, nemoram pregledavat kolekciju
				continue;

			  // provjeravam trenutnu rijec sa kolekcijom rijeci koje sam vec pronasao
			for( std::string_view rijec : rijeci )
			{
				if( count >= rijeci.size() ) // ovaj slucaj se moze maknut ako se koristi podatkovna struktura (vektor): std::vector<std::string>
				{
					std::cout << "Nema dovoljno mjesta za rijeci!\n";
					return -2;
				}
				else if( temp == rijec ) // pronasli smo duplikat, izadi iz funkcije sa vrijednosti true
					return true;
				else if( rijec.empty() ) // naisli smo na prazno mjesto u kolekciji
				{
					rijeci[count++] = temp; // dodaj rijec na prazno mjesto i povecaj trenutan broj rijeci
					break; // posao obavljen, odi trazit novu rijec
				}
			}
		}
		return false; // nismo nasli niti jednu duplu rijec
	}
	else
	{
		std::cout << "Datoteka ne postoji / nemoze se otvorit.\n";
		return -1;
	}
}

//todo: zavrsi ovo
// trebalo bi sada radit
void ispisi_datoteku_u_konzolu( std::fstream& datoteka, const std::string& imeDatoteke )
{
	datoteka.open( imeDatoteke, std::ios::in );
	if( !datoteka.is_open() )
	{
		std::cout << "Datoteka se nije otvorila!n";
		return;
	}
	bool zavrsenoCitanje = false;

	std::string buf;
	buf.reserve( 8096 );
	while( !zavrsenoCitanje )
	{
		for( size_t counterChars = 0, counterForceBreak = 1, pos = 0; counterChars < 60 * 127; ++counterChars, ++counterForceBreak )
		{
			if( datoteka.eof() )
			{
				zavrsenoCitanje = true;
				break;
			}

			int c = datoteka.get();
			buf += static_cast<unsigned char>( c );

			if( c == '\n' )
			{
				counterForceBreak = 0;
			}
			if( c == ',' )	pos = counterForceBreak + 1;
			if( c == ' ' )	pos = counterForceBreak;
			if( c == '.' && counterForceBreak > 90 )// The split point should be at the end of a sentence if possible,
			{
				buf += '\n';
				if( datoteka.peek() == '\n' ) 	datoteka.seekg( 1, std::ios::cur ); // preskoci taj new line jer sam je vec dodao
				++counterChars;
				counterForceBreak = 0;
			}

			////  or at the end of a word if a sentence is too long//.
			if( counterForceBreak == 127 )
			{
				if( pos > 0 )
				{
					for( size_t i = counterChars - 1; i > 1 + counterChars - ( 127 - pos ); --i ) // kopiraj sve znakove iza razmaka za jedno mjesto gdje ce se stavit znak za novu liniju
					{
						buf[i + 1] = buf[i];
					}
					buf[1 + counterChars - ( 127 - pos )] = '\n';
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
	system( "pause" );
}
