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

ParseFile::ParseFile( std::vector<std::string_view>& paths, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka )
{
	if( paths.empty() )
	{
		std::cout << "UNESI LISTU PATHOVA!\n";
		exit( EXIT_FAILURE );
	}
	if( imenaDatoteka.empty() )
	{
		std::cout << "UNESI LISTU DATOTEKA GDJE SE NALAZE ZELJENE FUNKCIJE!\n";
		exit( EXIT_FAILURE );
	}

	for( size_t idx = 0; idx < paths.size(); ++idx )
	{
		std::string_view curPath = m_paths[idx];
		std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka;
	//	m_datoteke.emplace_back( std::ifstream( curPath.data() + dat, std::ios::in ) );
		if( !m_datoteke[idx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << curPath << '\\' << dat << '\n';
			exit( EXIT_FAILURE );
		}
	}
}

bool findStartOfAFunction( std::ifstream& dat );
std::string getKomentar( std::ifstream& dat );
std::string getDeclaration( std::ifstream& dat );
std::string getFuncBody( std::ifstream& dat );
std::vector<Zadatak> ParseFile::readFile( std::ifstream& dat )
{
	std::vector<Zadatak> retVal;
	while( !dat.eof() )
	{
		bool is_eof = findStartOfAFunction( dat );
		if( !is_eof )
		{
			auto zad = std::make_unique<Zadatak>();
			zad->tekst = getKomentar( dat );
			zad->deklaracija = getDeclaration( dat );
			zad->kod = getFuncBody( dat );
			retVal.emplace_back( zad );
		}
	}
	return retVal;
}

bool findStartOfAFunction( std::ifstream& dat )
{
	std::string line;
	line.reserve( 255 );
	while( dat >> line )
	{
		std::string funRetType = "void";
		// preskoci sav whitespace
		const auto pocetak = std::find_first_of( line.begin(), line.end(), funRetType.begin(), funRetType.end() );

		if( pocetak[0] != '\0' )	break;
	}
	return dat.eof();
}

/// <summary>
///		test komentar

/// <summary>
///		Da bi bio siguran da citas komentar od funkcije, a ne neki random, moras pocet citat od deklaracije te funkcije.
///		Citas od kraja linije prema pocetku dok nenaides na pocetak komentara "//" ili dok do dodes do kraja cijelog komentara "\n\n".
///		Linije sprema u listu sprijeda. Jer se cita odzada, to je najjednostavniji nacini da se dobije ispravan tekst zadatka.	
/// 
///		Garantirano je da je komentar u ovom formatu jer inace se nebi moglo kompajlat.
/// </summary>
/// <param name="dat"> datoteka koja se cita </param>
/// <returns> Cijeli tekst zadatka (ukoliko ga ima) </returns>
std::string getKomentar( std::ifstream& dat )
{
	size_t currentPosInFile = dat.tellg();
	size_t currentPosInComment = dat.tellg();
	size_t previousPosInComment = dat.tellg();
	std::list<std::string> tekstZadatka;
	std::string line;
	while( bool notBeginingOfFile = dat.tellg() > 0 )
	{
		dat.seekg( -1, std::ios::cur );	// vracaj se unazad za jedan znak da se nalazis na pocetku linije komentara
		if( bool notBeginingOfFile = dat.tellg() - static_cast<std::streampos>( 1 ); dat.peek() == '\n' && notBeginingOfFile > 0 && dat.get() == '\n' )	break;	// doslo je do pocetka teksta zadatka
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
}

std::string getDeclaration( std::ifstream& dat )
{
	std::string line;
	char c;
	while( dat >> c ) if( isalpha( c ) )	break;	// preskoci whitespace
	dat.seekg( -1, std::ios::cur );
	dat >> line;
	return line;
}

std::string getFuncBody( std::ifstream& dat )
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