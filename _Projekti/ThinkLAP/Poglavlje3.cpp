#include "Poglavlje3.h"


// Vjezba 7
void Poglavlje3::finding_the_mode()
{
	const int ARRAY_SIZE = 12;
	int surveyData[ARRAY_SIZE] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };
	const uint8_t RANGE = 10;
	uint8_t counters[RANGE] = { 0 };

	for( uint16_t i = 0; i < ARRAY_SIZE; ++i )
	{
		++counters[surveyData[i] - 1];
	}

	uint16_t mode = counters[0];
	int16_t broj = 0;
	for( uint8_t i = 1; i < RANGE; ++i )
	{
		if( counters[i] > mode ) { mode = counters[i]; broj = i + 1; };
	}
	std::cout << "Broj: " << broj << ", se pojavio: " << mode << " puta\n";
} // vjezba 7

int compareFuncID( const void* voidA, const void* voidB ) {
	int* intA = (int*) ( voidA );
	int* intB = (int*) ( voidB );
	return *intA - *intB;
}
int compareFuncOcjena( const void* voidA, const void* voidB ) {
	int* intA = (int*) ( voidA );
	int* intB = (int*) ( voidB );
	return *( intA + 1 ) - *( intB + 1 );
}
void Poglavlje3::vj1_sorting()
{
	struct student stud1 { 1, 'A', "Tihomir" };
	struct student stud2 { 42, 'F', "Marica" };
	struct student stud3 { 55, 'B', "Grga" };
	struct student stud4 { 7, 'A', "Perica" };
	std::array<struct student, 4> studenti{ stud1, stud2, stud3, stud4 };

	for( const auto& stud : studenti )
		std::cout << stud;

	std::qsort( &studenti, studenti.size(), sizeof student, compareFuncID );
	std::cout << "\nNakon qsort po ID-u\n";
	for( const auto& stud : studenti )
		std::cout << stud;

	std::qsort( &studenti, studenti.size(), sizeof student, compareFuncOcjena );
	std::cout << "\nNakon qsort po ocjeni\n";
	for( const auto& stud : studenti )
		std::cout << stud;

}

void Poglavlje3::highestSales_zadano()
{
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int sales[NUM_AGENTS][NUM_MONTHS] = {
										{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
										{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
										{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
	};


	int highestSales = sales[0][0];
	for( int agent = 0; agent < NUM_AGENTS; agent++ )
	{
		for( int month = 0; month < NUM_MONTHS; month++ )
		{
			if( sales[agent][month] > highestSales )	highestSales = sales[agent][month];
		}
	}
	std::cout << "Najveca placa: " << highestSales << '\n';
}
void Poglavlje3::vj2_median()
{
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int sales[NUM_AGENTS][NUM_MONTHS] = {
										{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
										{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
										{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
	};


	int highestMedian = -1;
	for( int agent = 0, sredina = ( NUM_MONTHS / 2 ) - 1; agent < NUM_AGENTS; agent++ )
	{
		if( sales[agent][sredina] > highestMedian )		highestMedian = sales[agent][sredina];
	}
	std::cout << "Najveci median: " << highestMedian << '\n';
}

bool Poglavlje3::vj3_issorted( std::array<int, 20> niz )
{
	for( uint8_t i = 0; i < niz.size() - 1; ++i )
		if( niz[i] > niz[i + 1] )	return false;

	return true;
}

static constexpr auto buildCipherSymbols = []()
	{
		char znak = 234;
		int32_t rdm = 0xC59006A4;
		const uint8_t domet = 33;
		std::array<char, 26> cipherSymbols{};
		for( uint8_t i = 0; i < cipherSymbols.size();)
		{
			znak = domet + ( rdm & 0xBF );
			rdm >>= 7;
			rdm = ( rdm * 0x63 );

			for( uint8_t j = 0; j <= i; ++j )
			{
				if( cipherSymbols[j] == znak )
				{
					j = 0;
					znak = znak + ( static_cast<uint32_t>( 3.6537644l ) & 0xE7 ) - domet;
				}
				if( i == j )
				{
					cipherSymbols[i++] = znak;
					break;
				}
			}

		}

		return cipherSymbols;
	};
std::array<char, 26> buildCipherSymbolsRuntime()
{
	char znak = -22;
	int32_t rdm = 0xC59006A4;
	const uint8_t domet = 33;
	std::array<char, 26> cipherSymbols{};
	for( uint8_t i = 0; i < cipherSymbols.size();)
	{
		znak = domet + ( rdm & 0xBF );
		rdm >>= 7;
		rdm = ( rdm * 0x63 );

		for( uint8_t j = 0; j <= i; ++j )
		{
			if( cipherSymbols[j] == static_cast<char>( znak ) )
			{
				j = 0;
				znak = znak + ( static_cast<uint32_t>( 3.6537644l ) & 0xE7 ) - domet;
			}
			if( i == j )
			{
				cipherSymbols[i++] = znak;
				break;
			}
		}

	}
	//for (const auto& item : cipherSymbols)
	//	std::cout << item << ' ';

	return cipherSymbols;
}
std::unique_ptr<char[]> Poglavlje3::vj4_cipher_encode( std::string_view plainText )
{
	auto encoded = std::make_unique<char[]>( 257 );
	std::array<char, 26> cipherSymbols = buildCipherSymbols();
	////std::array<uint8_t, 26> cipherSymbols = buildCipherSymbolsRuntime();
	uint8_t idx = 0;
	for( ; idx < plainText.size(); ++idx )
	{
		char ch = ( plainText[idx] >= 'a' && plainText[idx] <= 'z' ) ? cipherSymbols[plainText[idx] - 'a'] : plainText[idx];
		encoded.get()[idx] = ch;
	}
	encoded.get()[idx] = '\0';
	for( const auto& znak : cipherSymbols )
		std::cout << znak << ' ';
	std::cout << '\n';
	return encoded;

}

std::unique_ptr<char[]> Poglavlje3::vj5_cipher_decode( std::unique_ptr<char[]> cipherText )
{
	auto cipherSymbols = buildCipherSymbols();
	////auto cipherSymbols = buildCipherSymbolsRuntime();
	std::unique_ptr<char[]> decoded;
	cipherText.swap( decoded );
	std::string_view view = decoded.get();
	////std::cout << "cipherText: ";
	////std::cout << view << '\n';

	uint8_t cnt = 0;
	for( const auto& znak : view )
	{
		bool OK = true;
		for( uint8_t j = 0; j <= cipherSymbols.size(); ++j )
		{
			if( j == cipherSymbols.size() )
			{
				bool dopusteno = znak == ' ' || znak == '.' || znak == ',';
				OK = dopusteno;
				break;
			}
			else if( znak == cipherSymbols[j] )
			{
				decoded[cnt] = 'a' + j;
				break;
			}
		}
		if( OK == false )
			throw "Unrecognized cipher symbol!\n";
		++cnt;
	}

	return decoded;
}

std::array<uint8_t, 3> Poglavlje3::vj8_grade_better_than()
{
	const uint8_t brojStudenata = 10;
	std::array<uint8_t, 3> retVal{};
	struct student stud1 { 1, 'A', "Tihomir" };
	struct student stud2 { 2, 'F', "Marica" };
	struct student stud3 { 3, 'B', "Grga" };
	struct student stud4 { 4, 'C', "Perica" };
	struct student stud5 { 5, 'D', "Tihomir" };
	struct student stud6 { 6, 'E', "Marica" };
	struct student stud7 { 7, 'B', "Grga" };
	struct student stud8 { 8, 'C', "Perica" };
	struct student stud9 { 9, 'E', "Grga" };
	struct student stud10 { 10, 'E', "Perica" };
	std::array<struct student, brojStudenata> studenti{ stud1, stud2, stud3, stud4, stud5, stud6, stud7, stud8, stud9, stud10 };
	std::array<uint8_t, 6> ocjene{ 0 };
	std::for_each( studenti.begin(), studenti.end(), [ &studenti, &ocjene ]( const struct student& stud ) mutable { ++ocjene[stud.grade - 'A']; } );
	std::for_each( ocjene.begin(), ocjene.end(), [ &ocjene, i = 0 ]( uint8_t ocjena ) mutable
				   {
					   std::cout << static_cast<uint8_t>( 'A' + i++ ) << ": " << static_cast<uint8_t>( ocjena + '0' ) << '\n';
				   } );
	int idx;
	std::cout << "Unesi index studenta: ";
	std::cin >> idx;
	const auto trazeniStud = std::find_if( studenti.begin(), studenti.end(), [ & ]( const struct student& stud )
										   { return stud.studentID == idx; } );
	if( trazeniStud != studenti.end() )
	{
		retVal = { UINT8_MAX, UINT8_MAX, UINT8_MAX };
		if( trazeniStud->grade == 'A' )	return retVal;
		uint8_t ocjena = trazeniStud->grade - 'A';
		// izracunaj koliko je boljih studenata od trazenog
		uint8_t brBoljihStudenta = 0;
		std::array<uint8_t, 6>::iterator pocetak = ocjene.begin() + ocjena - 1;
		std::array<uint8_t, 6>::iterator kraj = ocjene.begin();
		bool postavljen[3]{ false };
		do
		{
			brBoljihStudenta += *pocetak;
			float postotak = brBoljihStudenta / static_cast<float>( brojStudenata - 1 );
			if( !postavljen[0] && postotak >= 0.245 )
			{
				retVal[0] = *pocetak;
				postavljen[0] = true;
			}
			if( !postavljen[1] && postotak >= 0.495 )
			{
				retVal[1] = *pocetak;
				postavljen[1] = true;
			}
			if( !postavljen[2] && postotak >= 0.745 )
			{
				retVal[2] = *pocetak;
				postavljen[2] = true;
			}
			--pocetak;
		} while( pocetak != kraj );

	}
	else
	{
		std::cout << "Nepostoji student sa tim indexom!\n";
		return { UINT8_MAX, UINT8_MAX, UINT8_MAX };
	}


	return retVal;
}

void Poglavlje3::vj9_modified_median()
{
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int sales[NUM_AGENTS][NUM_MONTHS] = {
		{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
		{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
		{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
	};
	int mjesecZaposljenje[NUM_AGENTS];
	std::cout << "U kojem mjesecu se zaposlio 1. agent: ";
	std::cin >> mjesecZaposljenje[0];
	memset( sales[0], -1, mjesecZaposljenje[0] * sizeof( int ) );
	std::cout << "U kojem mjesecu se zaposlio 2. agent: ";
	std::cin >> mjesecZaposljenje[1];
	memset( sales[1], -1, mjesecZaposljenje[1] * sizeof( int ) );
	std::cout << "U kojem mjesecu se zaposlio 3. agent: ";
	std::cin >> mjesecZaposljenje[2];
	memset( sales[2], -1, mjesecZaposljenje[2] * sizeof( int ) );

	int highestMedian = -1;
	for( int agent = 0, sredina = ( mjesecZaposljenje[agent] + ( NUM_MONTHS - mjesecZaposljenje[agent] ) / 2 ) - 1;
		 agent < NUM_AGENTS;
		 agent++ )
	{
		if( sales[agent][sredina] > highestMedian )
			highestMedian = sales[agent][sredina];
	}
	std::cout << "Najveci median: " << highestMedian << '\n';
}