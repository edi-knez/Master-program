#include "ParseFile.hpp"


/// UNIMPLEMENTED for now...
/*ParseFile::ParseFile(std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka)
{
//	m_paths.emplace_back( paths );

	if( pathIdx.size() != imenaDatoteka.size() || pathIdx.size() != ekstenzijaDatoteka.size() || imenaDatoteka.size() != ekstenzijaDatoteka.size() )
	{
		std::cout << "Broj argumenata se ne podudaraju!\n";
		exit( EXIT_FAILURE );
	}

	for( size_t idx = 0; idx < pathIdx.size(); ++idx )
	{
		if( pathIdx[idx] < 0 || pathIdx[idx] > paths.size() )
		{
			std::cout << "Nevazeci pathIdx!!\n";
			exit( EXIT_FAILURE );
		}
		std::string_view curPath = m_paths[pathIdx[idx]];
		std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka[idx];
	//	m_datoteke.emplace_back( std::fstream( curPath.data() + dat, std::ios::in ) );
		if( !m_datoteke[idx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << curPath << '/' << dat << '\n';
			exit( EXIT_FAILURE );
		}
	}
}
*/

ParseFile::ParseFile( const std::string_view& path, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka )
{
	if( path.empty() || path[0] == '\0' )
	{
		std::cout << "UNESI VAZECI PATH!\n";
		exit( EXIT_FAILURE );
	}
	if( imenaDatoteka.empty() )
	{
		std::cout << "UNESI LISTU DATOTEKA GDJE SE NALAZE ZELJENE FUNKCIJE!\n";
		exit( EXIT_FAILURE );
	}

	m_paths.push_back( path );
	for( size_t datIdx = 0; datIdx < imenaDatoteka.size(); ++datIdx )
	{
		//std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka;
		std::string datotekeProjekta = imenaDatoteka[datIdx];
		m_datoteke.emplace_back( std::fstream( m_paths.front().data() + datotekeProjekta, std::ios::in ) );

		if( !m_datoteke[datIdx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << m_paths.front() << datotekeProjekta << '\n';
			exit( EXIT_FAILURE );
		}
	}

}

bool findStartOfAFunction( std::fstream& dat );
std::string getKomentar( std::fstream& dat );
std::string getDeclaration( std::fstream& dat );
std::string getFuncBody( std::fstream& dat );
std::vector<Zadatak*> ParseFile::readFile( std::fstream& dat )
{

	std::vector<Zadatak*> retVal;
	while( !dat.eof() )
	{
		bool is_eof = findStartOfAFunction( dat );
		if( !is_eof )
		{
			auto zad = new Zadatak;
			zad->tekst = getKomentar( dat );
			zad->deklaracija = getDeclaration( dat );
			zad->kod = getFuncBody( dat );
			retVal.push_back( std::move( zad ) );
		}
	}
	return retVal;
}

bool findStartOfAFunction( std::fstream& dat )
{
	std::string firstWord;
	firstWord.reserve( 30 );
	// TODO: mjesto za razmislit u buducnosti
	std::string funRetType = "void";
	while( !dat.eof() )
	{
		dat >> firstWord;

		if( firstWord == funRetType )
		{
			dat.seekg( -1 * ( firstWord.size() + 1 ), std::ios::cur );	 // + 1 da se vrati ispred 1. znaka u toj liniji
			break;
		}
		while( dat.get() != '\n' ) {};
		firstWord.clear();
	}
	return dat.eof();
}

/// <summary>
///		test komentar

// BUG: neradi ispravno!!
/// <summary>
///		Da bi bio siguran da citas komentar od funkcije, a ne neki random, moras pocet citat od deklaracije te funkcije.
///		Citas od kraja linije prema pocetku dok nenaides na pocetak komentara "//" ili dok do dodes do kraja cijelog komentara "\n\n".
///		Linije sprema u listu sprijeda. Jer se cita odzada, to je najjednostavniji nacini da se dobije ispravan tekst zadatka.	
/// 
///		Garantirano je da je komentar u ovom formatu jer inace se nebi moglo kompajlat.
/// </summary>
/// <param name="dat"> datoteka koja se cita </param>
/// <returns> Cijeli tekst zadatka (ukoliko ga ima) </returns>
std::string getKomentar( std::fstream& dat )
{
	size_t currentPosInFile = dat.tellg();
	size_t currentPosInComment = dat.tellg();
	size_t previousPosInComment = dat.tellg();
	std::list<std::string> tekstZadatka;
	std::string line;
	bool firstTime = true;
	while( bool notBeginingOfFile = dat.tellg() > 0 )
	{
		dat.seekg( -2, std::ios::cur );	// vracaj se unazad za jedan znak da se nalazis na pocetku linije komentara
	//	dat.seekg( -1, std::ios::cur );
	//	dat.seekg( -1, std::ios::cur );
		std::cout << "nalazi se na znaku: " << dat.peek() << "\t, a sljedeci znak je: " << dat.get() << "\n\n";
		if( bool notBeginingOfFile = dat.tellg()/* - static_cast<std::streampos>( 1 ) */; dat.peek() == '\n' && notBeginingOfFile > 0 && dat.get() == '\n' )	break;	// doslo je do pocetka teksta zadatka
		dat.seekg( -1, std::ios::cur ); // vrati se unazad za znak za koji si sada provjeravao pocetak komentara
		currentPosInComment = dat.tellg();	// zapamti poziciju newline znaka za kasnije

		while( bool notBeginingOfFile = dat.tellg() > 0 )
		{
			if( dat.peek() == '/' && dat.get() == '/' )	break;	// doslo je do pocetka linije
			dat.seekg( -1, std::ios::cur ); // vrati se unazad za znak za koji si sada provjeravao pocetak linije i vrati se 1 znak da nastavi dalji pregledavat
		}

/////////////////////
// ovo je test
// previousPosInComment -> 16 - 1 = 15  (- 1 zbog toga sto je zadnja linija komentara)
// currentPosInComment -> 5
// brojZnakova -> 15 - 4 = 11
/////////////////////

		// preskoci sve whitspace od pocetka komentara
		char c;
		while( dat >> c ) if( isalpha( c ) ) break; // ide jedan znak previse,
		dat.seekg( -1, std::ios::cur );		// vrati ga

		// doslo je do pocetka komentara, spremi liniju u string
		size_t brojZnakova = previousPosInComment - dat.tellg();
		line.reserve( brojZnakova + 1 );
		for( int cnt = 0; cnt < brojZnakova; ++cnt )
		{
			dat >> c;
			if( c == '\n' )	break;
			line += c;
		}
		if( !tekstZadatka.empty() )	line += '\n';	// dodaj newline svima osim zadnjoj liniji
		line += '\0';
		tekstZadatka.push_front( line );
		dat.seekg( brojZnakova * -1, std::ios::cur );	// vrati ga na mjesto prije nego je pocelo citat znakove u string

		while( bool notBeginingOfFile = dat.tellg() > 0 )	// preskoci sve ostale '/' nepotrebne znakove
		{
			if( bool notEndingofNextine = dat.peek() == '\n' )
				break;
			dat.seekg( -1, std::ios::cur );
		}
		previousPosInComment = currentPosInFile;
		currentPosInFile = dat.tellg();

	}
	std::string retVal;	// dodaj sve liniju u jednu cjelinu
	for( const auto& linijaTekstaZadatka : tekstZadatka )	retVal += linijaTekstaZadatka;
	dat.seekg( currentPosInFile, std::ios::beg ); // vrati datoteku nazad gdje je bila prije citanja komentara
	return retVal;
}

std::string getDeclaration( std::fstream& dat )
{
	char c;
	while( dat >> c ) if( isalpha( c ) )	break;	// preskoci whitespace
	dat.seekg( -1, std::ios::cur );
	std::string line;
	dat >> line;
	while( dat.peek() != ')' )	dat.seekg( -1, std::ios::cur );
	dat.seekg( 1, std::ios::cur );
	bool pocetakTijelaFun = line.at( line.size() - 3 ) == '{';
	return std::string( line.begin(), line.end() - pocetakTijelaFun - 1 ); // -1 zbog '\n' znaka
}

std::string getFuncBody( std::fstream& dat )
{
	std::string retVal;
	size_t stack = 0;
	char c;
	while( !dat.eof() )
	{
		dat >> c;
		retVal += c;
		stack += c == '{';
		stack -= c == '}';
		if( stack == 0 )	break;
	}

	return retVal;
}

void skipFuncBody( std::fstream& dat );
std::optional<size_t> ParseFile::getPositionOfFunction( std::fstream& dat, const char* imeFunkcije )
{
	while( bool is_eof = findStartOfAFunction( dat ) )
	{
		std::string deklaracija = getDeclaration( dat );
		std::string::iterator it;
		// pronadi pocetak povratnog tipa
		it = std::find_if( deklaracija.begin(), deklaracija.end(), [ &it ]( char c )
						   {
							   return isalpha( c );
						   } );
		// pronadi kraj povratnog tipa
		it = std::find_if( it, deklaracija.end(), [ & ]( char c )
						   {
							   return  isspace( c );
						   } );
		// pronadi pocetak imena funkcije
		it = std::find_if( it, deklaracija.end(), [ & ]( char c )
						   {
							   return isalpha( c );
						   } );
		// pronadi kraj imena funkcije
		std::string::iterator itEnd = it;
		itEnd = std::find( it, deklaracija.end(), '(' );

		// ukloni namespace ukoliko postoji
		std::string::iterator itTemp = it;
		while( itTemp != itEnd && *itTemp != ':' ) { ++itTemp; }
		if( itTemp != itEnd )
		{
			it = itTemp + 2;
		}

		std::string pronadenoIme( it, itEnd );
		if( strcmp( pronadenoIme.data(), imeFunkcije ) == 0 )	return dat.tellg();
		else skipFuncBody( dat );
	}
	return {};
}

void skipFuncBody( std::fstream& dat )
{
	size_t stack = 0;
	while( !dat.eof() )
	{
		dat.seekg( 1, std::ios::cur );
		stack += dat.peek() == '{';
		stack -= dat.peek() == '}';
		if( stack == 0 )	break;
	}
}









///



