#include "Poglavlje2.h"

void Poglavlje2::printSidewaysTriangle() const
{
	constexpr int SIZE = 7;

	// 1. korak napravi kvadrat
	for( int i = 1; i <= SIZE; ++i )
	{
		for( int j = 1; j <= SIZE; ++j )
		{
			std::cout << '#';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	// 2. korak napravi silazni pravokutni trokut
	for( int i = 1; i <= SIZE; ++i )
	{
		for( int j = SIZE - i; j < SIZE; ++j )
		{
			std::cout << '#';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	// 3. korak: kada dode na polovicu pocni smanjivat j
	for( int i = 1; i <= SIZE; ++i )
	{
		for( int j = SIZE - i; j < SIZE && j >= 0; j = j + 1 - 2 * ( i > SIZE / 2 ) )
		{
			std::cout << '#';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	// rjesenje:
		//for (int j = 1; j <= SIZE; ++j)
		//{
		//	// j - 4 -> dobije se uzlazni oblik
		//	// abs -> makni minus, postaje uzlazno - silazni oblik, brojevi oznacavaju prazna mjesta
		//	// 4 - prazna mjesta -> dobije se ukupan broj znakova u redu
		//	std::cout << 4 - abs(j - 4) << '\n';
		//}
	for( int i = 1; i <= SIZE; ++i )
	{
		for( int j = 1; j <= 4 - abs( i - 4 ); ++j )
		{
			std::cout << '#';
		}
		std::cout << '\n';
	}

}
void Poglavlje2::printSidewaysTriangleRec( int iter ) const
{
	if( iter == 4 ) return;
	for( int i = 1; i <= iter; ++i )
		std::cout << '#';
	std::cout << '\n';
	printSidewaysTriangleRec( ++iter );
	for( int i = 1; i <= iter; ++i )
		std::cout << '#';
	std::cout << '\n';
}

void Poglavlje2::luhnFormulaPrecomputed() const
{
	// za uduplane brojeve
	std::array precomputedData{ 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	int sum = 0;
	std::string number;
	std::cout << "Upisi ID broj: ";
	std::cin >> number;
	const char* ptrNum = number.data();
	assert( number.size() < 15 );

	for( auto [tmpLen, multiply] = std::tuple{ size_t{number.size()}, uint8_t{0} };
		 tmpLen != 0;
		 --tmpLen, ++ptrNum, multiply = !multiply )
	{
		if( !isdigit( *ptrNum ) )
		{
			std::cout << "ID NUMBER ERROR!\n";
			return;
		}

		if( multiply ) // svaka 2 znamenka
		{
			sum += precomputedData.at( *ptrNum - '0' );
		}
		else sum += *ptrNum - '0';
	}
	if( sum == 0 && number.size() == 1 ) std::cout << "Broj je prekratak!\n";
	else if( sum % 10 == 0 ) std::cout << "Broj je vazeci!\n";
	else					std::cout << "Broj nije vazeci!\n";
}
void Poglavlje2::luhnFormulaExpression() const
{
	// abs(-9 * (broj > 4) + (9 * (broj > 4) - broj) * 2)
	//	pr.broj = 5
	//	abs(-9 + (9 - 5) * 2 -> abs(-9 + 4 * 2) -> abs(-1) = 1
	//	pr2.broj = 4
	//	abs(0 + (0 - 4) * 2) -> abs(-4 * 2) -> abs(-8) = 8
	int sum = 0;
	std::string number{};

	std::cout << "Upisi ID broj: ";
	std::cin >> number;
	char const* ptrNum = number.data();

	//size_t len = strlen(number);

	for( auto [tmpLen, multiply] = std::tuple{ size_t{number.length()}, uint8_t{0} };
		 tmpLen != 0;
		 --tmpLen, ++ptrNum, multiply = !multiply )
	{
		if( !isdigit( *ptrNum ) )
		{
			std::cout << "ID NUMBER ERROR!\n";
			return;
		}

		if( multiply ) // svaka 2 znamenka
		{
			const bool uvjet = *ptrNum > '4';
			const int num = *ptrNum - '0';
			//!std::cout << "(-9 * uvjet): " << -9 * uvjet
				//!<< "\n((9* uvjet) - num) * 2: " << ((9 * uvjet) - num) * 2 << '\n';
			sum += abs( -9 * uvjet + ( 9 * uvjet - num ) * 2 );
		}
		else sum += *ptrNum - '0';
	}
	if( sum == 0 && number.length() == 1 ) std::cout << "Broj je prekratak!\n";
	else if( sum % 10 == 0 ) std::cout << "Broj je vazeci!\n";
	else					std::cout << "Broj nije vazeci!\n";
}

int Poglavlje2::doubleDigitValue( int digit ) const
{
	const int doubledDigit = digit * 2;
	int sum;
	if( doubledDigit > 10 ) sum = 1 + doubledDigit % 10;
	else sum = doubledDigit;
	return sum;
}
void Poglavlje2::luhnFormulaRjesenje() const
{
	char digit;
	int oddLengthChecksum = 0;
	int evenLengthChecksum = 0;
	int position = 1;
	std::cout << "Enter a number: ";
	digit = static_cast<char>( std::cin.get() );
	while( digit != '\n' )
	{
		if( position % 2 == 0 )
		{
			oddLengthChecksum += doubleDigitValue( digit - '0' );
			evenLengthChecksum += digit - '0';
		}
		else
		{
			oddLengthChecksum += digit - '0';
			evenLengthChecksum += doubleDigitValue( digit - '0' );
		}
		digit = static_cast<char>( std::cin.get() );
		position++;
	}
	int checksum;
	if( ( position - 1 ) % 2 == 0 ) checksum = evenLengthChecksum;
	else checksum = oddLengthChecksum;
	std::cout << "Checksum is " << checksum << ". \n";
	if( checksum % 10 == 0 )
	{
		std::cout << "Checksum is divisible by 10. Valid. \n";
	}
	else
	{
		std::cout << "Checksum is not divisible by 10. Invalid. \n";
	}

}

std::tuple<int32_t, bool> Poglavlje2::extract_number() const
{
	int32_t decodedBroj;
	unsigned char input;

	decodedBroj = 0;
	bool isNegative = false;
	for( uint8_t idx = 0; ( input = static_cast<uint8_t>( std::cin.get() ) ) != '\0'; ++idx )
	{
		if( input == '-' )
		{
			isNegative = true;
		}
		// spajanje pojedinih znakova u viseznamenkasti broj
		else if( isdigit( input ) )
		{
			decodedBroj *= 10;
			decodedBroj += ( input - '0' );
		}
		// broj je spreman za dekodiranje
		else if( input == ',' )	return std::tuple( decodedBroj, false );
		// dosli smo do kraja inputa
		else if( input == '\n' )
		{
			if( isNegative )
				decodedBroj *= -1;
			return std::tuple( decodedBroj, true );
		}
		// greska u upisu
		else
		{
			std::cout << "ERROR\n";
			return std::tuple( UINT32_MAX, true );
		}

	}
	return std::tuple( -1, false );
}
void Poglavlje2::decodeMessage() const
{
	std::array znakovi = { '!', '?', ',', '.', ' ', ';', '"', '\'' };
	enum class DecodeMode
	{
		VELIKA = 'A',
		MALA = 'a',
		ZNAKOVI = 0
	} dMode = DecodeMode::VELIKA;

	std::string message;	message.reserve( 64 );
	uint8_t i = 0;
	// 0 - decodedBroj,
	// 1 - isDone
	std::tuple<uint32_t, bool> data( 0, false );

	for( ; std::get<1>( data ) == false; ++i )
	{
		data = extract_number();

		// offset od prvog znaka u modu
		if( dMode == DecodeMode::ZNAKOVI )	std::get<0>( data ) %= 9;
		else								std::get<0>( data ) %= 27;

		// zapisivanje rezultata
		if( std::get<0>( data ) != 0 )
		{
			if( dMode == DecodeMode::ZNAKOVI )
			{
				message[i] = znakovi.at( std::get<0>( data ) - 1 );
			}
			else
			{
				message[i] = std::get<0>( data ) + static_cast<uint32_t>( dMode ) - 1;
			}
		}

		// mod se mijenja ukoliko je offest 0
		else
		{
			switch( dMode )
			{
			case DecodeMode::VELIKA:
				dMode = DecodeMode::MALA;
				break;
			case DecodeMode::MALA:
				dMode = DecodeMode::ZNAKOVI;
				break;
			default:
				dMode = DecodeMode::VELIKA;
			}
			--i;
		}
	}

	message[i] = '\0';
	std::cout << message;
}
void Poglavlje2::decodeMessageRjesenje() const
{
	char outputCharacter;
	enum class modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
	modeType mode = modeType::UPPERCASE;
	char digitChar;
	do
	{
		digitChar = std::cin.get();
		int number = ( digitChar - '0' );
		digitChar = std::cin.get();
		while( ( digitChar != 10 ) && ( digitChar != ',' ) )
		{
			number = number * 10 + ( digitChar - '0' );
			digitChar = std::cin.get();
		}
		switch( mode )
		{
			using enum modeType;
		case UPPERCASE:
			number = number % 27;
			outputCharacter = number + 'A' - 1;
			if( number == 0 )
			{
				mode = LOWERCASE;
				continue;
			}
			break;
		case LOWERCASE:
			number = number % 27;
			outputCharacter = number + 'a' - 1;
			if( number == 0 )
			{
				mode = PUNCTUATION;
				continue;
			}
			break;
		case PUNCTUATION:
			number = number % 9;
			switch( number )
			{
			case 1: outputCharacter = '!'; break;
			case 2: outputCharacter = '?'; break;
			case 3: outputCharacter = ','; break;
			case 4: outputCharacter = '.'; break;
			case 5: outputCharacter = ' '; break;
			case 6: outputCharacter = ';'; break;
			case 7: outputCharacter = '"'; break;
			case 8: outputCharacter = '\''; break;
			default: mode = UPPERCASE; continue;

			}

			break;
		}
		std::cout << outputCharacter;
	} while( digitChar != '\n' );
	std::cout << "\n";
}

// vjezbe
void Poglavlje2::vj1() const
{
	for( int i = 0; i < 4; ++i )
	{
		for( int j = 0; j < 8 - i; ++j )
		{
			if( j < i )	std::cout << ' ';
			else		std::cout << '#';
		}
		std::cout << '\n';
	}
}

void test_vj2()
{
	constexpr int ROWS = 8;
	//// Broj razmaka je ispravan
	//for (int i = -3; i <= 4; ++i)
	//{
	//	std::cout << abs(i - ( 1 * i > 0 )) << '\n';
	//}
	//std::cout << '\n';
	// NOVA FORMULA ZA RAZMAKE! ( i - 4 je -3, sto je pocetno stanje prosle petlje )
	for( int i = 1; i <= ROWS; ++i )
	{
		std::cout << abs( i - 4 ) - ( 1 * i > 4 ) << '\n';
	}
	std::cout << '\n';

	//// crta razmake
	//for (int i = -3; i <= 4; ++i)
	//{
	//	for (int j = 0; j < abs(i - (1 * i > 0)); ++j)
	//	{
	//		std::cout << '#';
	//	}
	//	std::cout << '\n';
	//}

	// RJESENJE:
	for( int i = 1; i <= 8; ++i )
	{
		const int brojRazmaka = abs( i - 4 ) - ( 1 * i > 4 );
		const int brojLjestava = 8 - brojRazmaka * 2;	// 8 (broj ukupnih mjesta) -  brojRazmaka * 2 (razmaci sa obe strane za svaki red
		for( int j = 0; j < brojLjestava + brojRazmaka; ++j )
		{
			if( j < brojRazmaka )	std::cout << ' ';
			else					std::cout << '#';
		}
		std::cout << '\n';
	}

}
void Poglavlje2::vj2() const
{
	for( int i = 1; i <= 8; ++i )
	{
		const int brojRazmaka = abs( i - 4 ) - ( 1 * i > 4 );
		const int brojLjestava = 8 - brojRazmaka * 2;
		for( int j = 0; j < brojLjestava + brojRazmaka; ++j )
		{
			if( j < brojRazmaka )	std::cout << ' ';
			else					std::cout << '#';
		}
		std::cout << '\n';
	}

	//test_vj2();
}
void Poglavlje2::vj2_version2() const
{
	for( int i = 1; i <= 8; ++i )
	{
		const int brojRazmaka = abs( i - 4 ) - ( 1 * i > 4 );
		const int brojLjestva = 8 - brojRazmaka * 2;
		for( int j = 0; j < brojRazmaka; ++j )
		{
			std::cout << ' ';
		}
		for( int j = 0; j < brojLjestva; ++j )
		{
			std::cout << '#';
		}
		std::cout << '\n';
	}

	//test_vj2();
}

void test_vj3()
{
	//// broj razmaka u svakom redu (razmaci napocetku)
	//for (int i = 1; i <= 8; ++i)
	//{
	//	std::cout << 3 - abs(i - 4 - (i > 4)) << '\n';
	//}
	//std::cout << '\n';

	//// broj razmaka u svakom redu (razmaci nakraju)
	//for (int i = 1; i <= 8; ++i)
	//{
	//	const int brojRazmakaLD = 3 - abs(i - 4 - (i > 4));
	//	const int brojLjestva = brojRazmakaLD + 1;
	//	const int brojRazmakaSredina = 14 - brojRazmakaLD * 2 - brojLjestva * 2;
	//	std::cout << brojRazmakaLD + brojRazmakaSredina + brojLjestva * 2<< '\n';
	//}
	//std::cout << '\n';


	for( int i = 1; i <= 8; ++i )
	{
		const int brojRazmakaLD = 3 - abs( i - 4 - ( i > 4 ) );
		const int brojLjestva = brojRazmakaLD + 1;
		const int brojRazmakaSredina = 14 - brojRazmakaLD * 2 - brojLjestva * 2;
		for( int j = 1; j <= brojRazmakaLD + brojRazmakaSredina + brojLjestva * 2; ++j )
		{
			if( j <= brojRazmakaLD )							std::cout << ' '; // samo lijeva strana se crta
			else if( j > brojRazmakaLD + brojLjestva &&
					 j <= 14 - brojRazmakaLD - brojLjestva )	std::cout << ' '; // prazan prostor izmedu
			else											std::cout << '#';
		}
		std::cout << '\n';
	}
}
void Poglavlje2::vj3() const
{
	//test_vj3();
	for( int i = 1; i <= 8; ++i )
	{
		const int brojRazmakaLD = 3 - abs( i - 4 - ( i > 4 ) );
		const int brojLjestva = brojRazmakaLD + 1;
		const int brojRazmakaSredina = 14 - brojRazmakaLD * 2 - brojLjestva * 2;
		for( int j = 1; j <= brojRazmakaLD + brojRazmakaSredina + brojLjestva * 2; ++j )
		{
			if( j <= brojRazmakaLD )							std::cout << ' '; // samo lijeva strana se crta
			else if( j > brojRazmakaLD + brojLjestva &&
					 j <= 14 - brojRazmakaLD - brojLjestva )		std::cout << ' '; // prazan prostor izmedu
			else											std::cout << '#';
		}
		std::cout << '\n';
	}

}

void vj5_build_and_print_ISBN_format( std::string_view digits )
{
	// drugi pristup:
	// spremit u niz pozicije na kojima se nalazi znak '-':
	// for(int i = 0, idx = 0; i < 18; ++i){
	//	if(format[idx] == i)	ISBN[i] = '-';
	// }
	digits = digits.substr( 0, 14 );
	std::array<char, 18> ISBN{};
	// (978-0-306-40615-?)
	// koliko znamenaka se nalazi ispred znaka '-'
	std::array<uint8_t, 4> format{ 3, 1, 3, 5 };

	uint8_t ISBNcounter = 0;
	uint8_t digitsCounter = 0;
	for( uint8_t i = 0; i < format.size(); ++i )
	{
		for( uint8_t j = 0; j < format.at( i ); ++j )
		{
			ISBN.at( ISBNcounter ) = digits[digitsCounter];
			++ISBNcounter;
			++digitsCounter;
		}
		ISBN.at( ISBNcounter ) = '-';
		++ISBNcounter;
	}
	ISBN.at( ISBNcounter ) = digits[digitsCounter];
	++ISBNcounter;
	ISBN.at( ISBNcounter ) = '\0';
	std::cout << ISBN.data();
}
// arguments:
// first- sum
// second- digits
std::pair<uint32_t, std::array<char, 14>> vj5_calculate_sum( const uint32_t DIGITS )
{
	//char test[14];
	//std::pair<uint32_t, char*> retVal = std::make_pair(0, test);
	//std::pair<uint32_t, char*> retVal{ 0, (char*)"aa" };

	std::pair<uint32_t, std::array<char, 14>> retVal{};
	char input;
	bool multiply = false;
	for( std::streamsize sz = 0; sz < DIGITS; multiply = !multiply ) // std::cin.eof() -> ctrl + z
	{
		std::cin.get( input );
		if( input == '\n' ) continue;
		if( !isdigit( input ) )
		{
			std::cout << "ERROR!\n";
			retVal.first = UINT32_MAX;
			return retVal;
		}

		retVal.first += multiply ? 3 * ( input - '0' ) : input - '0';
		retVal.second.at( size_t( sz ) ) = input;
		++sz;
	}
	retVal.second[retVal.second.size() - 1] = '\0';
	return retVal;
}
void Poglavlje2::vj5_check() const
{
	std::cout << "Checking ISBN for following number: ";
	const auto [sum, ISBN] = vj5_calculate_sum( 13 );
	if( sum == UINT32_MAX )	return;

	std::cout << "ISBN: ";
	vj5_build_and_print_ISBN_format( ISBN.data() );
	( sum % 10 == 0 ) ? std::cout << " je ispravan!\n" : std::cout << " nije ispravan!\n";
}
void Poglavlje2::vj5_generate() const
{
	std::cout << "Generating last digit for ISBN: ";
	const auto [sum, ISBN] = vj5_calculate_sum( 12 );
	if( sum == UINT32_MAX )	return;

	std::cout << "Zadnja znamenka ISBN broja je: " << 10 - ( sum % 10 ) << '\n';
}


int Poglavlje2::vj6_bin_to_dec() const
{
	std::cout << "Unesi jednu liniju binarnog broja: ";
	int dec = 0;
	char bit;
	std::cin.get( bit );
	// undefined behaviour ako se unese broj 0 vise od 32 puta?
	while( bit != '\n' && dec >= 0 )
	{
		if( bit < '0' || bit > '1' )
		{
			throw "ERROR 20!\n";
		}
		dec = ( dec << 1 ) + ( bit - '0' );
		std::cin.get( bit );
	}
	return dec;
}
void Poglavlje2::vj6_ispisi_bin( int/*64_t*/ broj ) const
{
	std::cout << "Bin: ";
	int64_t pos = 1;// mora bit 64 bita jer ako broj koristi sva 32 bita(negativan je), tada pos nikada nece biti veci od tog broja
	while( pos << 1 <= uint32_t/*int64_t*/( broj ) )	pos <<= 1;

	for( bool bit; pos > 0; pos >>= 1 )
	{
		bit = pos & broj;
		std::cout << bit;
	}
	std::cout << '\n';
}
int Poglavlje2::vj6_dec_to_bin() const
{
	std::cout << "Unesi jedan broj: ";
	auto [dec, unused] = extract_number();
	int32_t bin = 0;
	int64_t bitPos = 1;

	while( bin != dec )
	{
		bin += ( dec & bitPos );
		bitPos <<= 1;
	}


	return bin;
}

int Poglavlje2::vj7_bin_to_dec( int broj ) const
{
	int dec = 0;
	int pos = 1;

	while( dec != broj )
	{
		dec += ( broj & pos );
		pos <<= 1;
	}
	return dec;
}
int Poglavlje2::vj7_dec_to_bin( int broj ) const
{
	int bin = 0;
	int64_t bitPos = 1;
	while( bin != broj )
	{
		bin += ( broj & bitPos );
		bitPos <<= 1;
	}
	return bin;
}

int vj7_unos_hex_broja()
{
	//std::optional<int> t;
	//t.
	constexpr static uint8_t HexSlova[]
	{
		10, // A
		11,
		12,
		13,
		14,
		15  // F
	};
	bool isNegative = false;
	int hex = 0;
	char temp = '0';
	while( temp != '\n' )
	{
		std::cin.get( temp );

		if( !isalnum( temp ) )
		{
			if( temp == '-' )		isNegative = true;
			else if( temp == '\n' )	break;
			else					throw "ERROR 16";
		}
		else
		{
			if( isdigit( temp ) )	hex = ( hex << 4 ) + temp - '0';
			else
			{
				if( temp <= 'F' )	hex = ( hex << 4 ) + HexSlova[temp - 'A'];
				////-49 + 97; = 48 -> '0'
				else if( temp >= 'a' && temp <= 'f' )	hex = ( hex << 4 ) + HexSlova[temp - 'a'];
				else
				{
					throw "ERROR 16.1!";
				}
			}
		}
	}

	if( isNegative )
		hex *= -1;
	return hex;
}
int Poglavlje2::vj7_hex_to_bin( int broj ) const noexcept
{
	int bin = 0;
	uint32_t checkBits = 0xF;
	while( bin != broj )
	{
		bin += ( broj & checkBits );
		checkBits <<= 4;
	}
	return bin;
}
int Poglavlje2::vj7_bin_to_hex( int broj ) const noexcept
{
	int hex = 0;
	uint64_t pos = 0xF;

	while( hex != broj )
	{
		hex += ( broj & pos );
		pos <<= 4;
	}
	return hex;
}
void Poglavlje2::vj7_ispisi_hex( int broj ) const
{
	// 10000000000000000000000000000000
	// 01111111111111111111111111111111
	// 1111111111111111111111111111
	//std::cout << "broj: " << broj << '\n';
	uint32_t bitsCheck = 0xF;
	int64_t pos = 0x10;// mora bit 64 bita jer ako broj koristi sva 32 bita(negativan je), tada pos nikada nece biti veci od tog broja
	int bits = 0;
	while( pos <= uint32_t( broj ) )
	{
		//std::cout << "pos: " << pos << " < " << static_cast<int64_t>(broj) << '\n';
		bits += 4;
		pos <<= 4;
	}
	//std::cout << "broj: " << broj << '\n';
	//vj6_ispisi_bin(pos);
	bitsCheck <<= bits;
	//std::cout << "bitsCheck: ";
	//vj6_ispisi_bin(bitsCheck);

	std::cout << "Hex: 0x";
	for( uint8_t ch; bits >= 0; bits -= 4, bitsCheck >>= 4 )
	{
		uint32_t temp = ( broj & bitsCheck ) >> bits;
		//std::cout << "temp: " << temp;
		ch = uint8_t( temp + ( ( ( temp <= 9 ) * '0' ) + ( ( temp >= 10 ) * ( 'A' - 10 ) ) ) );
		std::cout << ch;// << '\n';
	}
	std::cout << '\n';
}
void Poglavlje2::vj7_pretvorba_sa_hex() const
{
	using Baza = Extra::Baza;
	using BazaE = Extra::BazaExtended;
	Baza bInp{};
	Baza bOut;
	int brojZaPretvorit = INT32_MAX;
	uint8_t odabir = -1;
	while( odabir > uint8_t( Baza::HEX ) + uint8_t( BazaE::OFFSET ) )
	{
		std::cout << "Izbor iz:\n"
			<< "2) Baze bin\n"
			<< "10) Baze dek\n"
			<< "16) Baze hex\n";
		std::cout << "U kojoj se bazi broj nalazi: ";
		odabir = static_cast<uint8_t>( extract_number()._Myfirst._Val );

		switch( odabir )
		{
		case uint8_t( Baza::BIN ) + uint8_t( BazaE::OFFSET ):
			bInp = Baza::BIN;
			brojZaPretvorit = vj6_bin_to_dec();
			break;
		case uint8_t( Baza::DEK ) + uint8_t( BazaE::OFFSET ):
		{
			bInp = Baza::DEK;
			std::cout << "Unesi dekatski broj: ";
			////auto [dec, unused] = extract_number();// za grupu podataka(treba mi samo int)
			brojZaPretvorit = extract_number()._Myfirst._Val;
			break;
		}
		case uint8_t( Baza::HEX ) + uint8_t( BazaE::OFFSET ):
			bInp = Baza::HEX;
			std::cout << "Unesi hexadekatski broj: ";
			brojZaPretvorit = vj7_unos_hex_broja();
			break;
		default:
			std::cout << "Krivi unos!\n";
		}
	}
	odabir = -1;
	while( odabir > uint8_t( Baza::HEX ) + uint8_t( BazaE::OFFSET ) )
	{
		std::cout << "Izbor u:\n"
			<< "2) Bazu bin\n"
			<< "10) Bazu dek\n"
			<< "16) Bazu hex\n";
		std::cout << "U koju bazu pretvorit broj: ";
		odabir = uint8_t( extract_number()._Myfirst._Val );
		switch( odabir )
		{
		case uint8_t( Baza::BIN ) + uint8_t( BazaE::OFFSET ):
			bOut = Baza::BIN;
			if( bInp == bOut )
			{
				std::cout << "Broj se nalazi u toj bazi!\n";
				break;
			}
			vj6_ispisi_bin( brojZaPretvorit );
			break;
		case uint8_t( Baza::DEK ) + uint8_t( BazaE::OFFSET ):
			bOut = Baza::DEK;
			if( bInp == bOut )
			{
				std::cout << "Broj se nalazi u toj bazi!\n";
				break;
			}
			else if( bInp == Baza::BIN )
			{
				std::cout << vj7_bin_to_dec( brojZaPretvorit ) << '\n';
			}
			else // HEX
				std::cout << vj7_bin_to_dec( vj7_hex_to_bin( brojZaPretvorit ) ) << '\n';
			break;
		case uint8_t( Baza::HEX ) + uint8_t( BazaE::OFFSET ):
			bOut = Baza::HEX;
			if( bInp == bOut )
			{
				std::cout << "Broj se nalazi u toj bazi!\n";
				break;
			}
			if( bInp == Baza::BIN )
			{
				brojZaPretvorit = vj7_bin_to_hex( brojZaPretvorit );
				vj7_ispisi_hex( brojZaPretvorit );
			}
			else // DEK
			{
				brojZaPretvorit = vj7_bin_to_hex( vj7_dec_to_bin( brojZaPretvorit ) );
				vj7_ispisi_hex( brojZaPretvorit );
			}
			break;
		default:
			std::cout << "Krivi unos!\n";
			std::cin.ignore();
		}
	}

}

void Poglavlje2::vj8_pretvorba_sve_baze() const
{
	Extra::BazaExtended bInp, bOut = Extra::BazaExtended::HEX;
	int pocetniBroj;
	int pretvoreniBroj;
	//vj8_unos(bInp, pocetniBroj, bOut);
	// pretvoreniBroj = pretvorba
	pretvoreniBroj = 2147483647;
	vj8_ispisi_sa_bazom( bOut, pretvoreniBroj );
}
void Poglavlje2::vj8_unos( Extra::BazaExtended& bI, int& broj, Extra::BazaExtended& bO ) const
{
	std::cout << "Unesi bazu broja(2[bin] - 16[hex]): ";
	bI = static_cast<Extra::BazaExtended>( extract_number()._Myfirst._Val - 2 );
	if( bI > Extra::BazaExtended::HEX )
		throw "Nepodrzana baza!\n";
	std::cout << "Unesi broj za pretvorit: ";
	broj = extract_number()._Myfirst._Val;
	std::cout << "Unesi u koju zelis pretvorit broj(2[bin] - 16[hex]): ";
	bO = static_cast<Extra::BazaExtended>( extract_number()._Myfirst._Val - 2 );
	if( bO > Extra::BazaExtended::HEX )
		throw "Nepodrzana baza!\n";
}

void Poglavlje2::vj8_ispisi_sa_bazom( Extra::BazaExtended bO, uint8_t broj ) const
{
	static constexpr std::array znakovi = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	std::deque<uint8_t> izlaz{};
	const uint8_t baza = static_cast<uint8_t>( bO ) + static_cast<uint8_t>( Extra::BazaExtended::OFFSET );

	while( broj != 0 )
	{
		const uint8_t temp = broj % baza;
		broj /= baza;
		izlaz.push_front( temp );
	}

	for( const auto& tbroj : izlaz )
	{
		//uint8_t temp = broj + (((broj <= 9) * '0') + ((broj >= 10) * ('A' - 10))); // umjesto ove kalkulacije koristim gotovu tablicu vrijednosti
		std::cout << znakovi.at( tbroj );
	}
	if( izlaz.empty() )	std::cout << '0';
	std::cout << '\n';
}
int vj8_metodad_pretvorba( Extra::Baza bI, Extra::Baza bO )
{
	return 0;
}
int Poglavlje2::vj8_otherBase_to_dec( int broj ) const
{
	int dec = 0;
	while( broj != 0 )
	{
		dec = broj;
	}
	return 0;
}

//int Poglavlje2::vj6_dec_to_bin(int broj)
//{
//	int bin = 0;
//	while (broj > 0)
//	{
//		bin <<= 1;
//		bin += broj & 1;
//		broj >>= 1;
//	}
//	return bin;
//}


void Poglavlje2::vj9_unos_string_info( const std::string_view str ) const
{
	uint8_t longestWord = 0;
	uint8_t numOfWords = 0;
	uint8_t samoglasniciURijeci = 0;

	char prethodniZnak = ' ';
	uint8_t tmpSlovaURijeci = 0;
	uint8_t tmpSamoglasniciURijeci = 0;

	std::string_view::const_iterator iter = str.begin();
	for( ; iter != str.end(); ++iter )
	{
		const char ch = *iter;

		const bool isSlovo = isalpha( ch );
		tmpSlovaURijeci += isSlovo;
		const bool isSamoglasnik = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
		tmpSamoglasniciURijeci += isSamoglasnik;

		auto update_varijable = [ & ]( const bool isNovaRijec = true ) mutable {
			numOfWords += isNovaRijec;
			if( longestWord < tmpSlovaURijeci )	longestWord = tmpSlovaURijeci;
			if( samoglasniciURijeci < tmpSamoglasniciURijeci )	samoglasniciURijeci = tmpSamoglasniciURijeci;
			};

		if( ( isspace( ch ) || ispunct( ch ) ) && !isspace( prethodniZnak ) )
		{
			update_varijable();
			tmpSlovaURijeci = 0;
			tmpSamoglasniciURijeci = 0;
		}
		else if( iter + 1 == str.end() )	update_varijable( isSlovo );

		prethodniZnak = ch;
	}
	std::cout << "Ta linija sadrzi:\n"
		<< "Broj rijeci: " << static_cast<int>( numOfWords ) << "\n"
		<< "Najdulja rijec ima: " << static_cast<int>( longestWord ) << " slova\n"
		<< "Najvise samoglasnika u rijeci: " << static_cast<int>( samoglasniciURijeci ) << '\n';
}