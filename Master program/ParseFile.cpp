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
	auto ignoreRestOfALine = []( std::fstream& dat )
		{
			while( dat.get() != '\n' ) {};
		};
	std::string firstWord;
	firstWord.reserve( 30 );
	// TODO: mjesto za razmislit u buducnosti
	std::string funRetType = "void";
	while( !dat.eof() )
	{
		dat >> firstWord;

		if( firstWord == funRetType )
		{
			dat.seekg( -1 * ( firstWord.size() + 1 ), std::ios::cur );	 // + 1, da se vrati ispred 1. znaka u toj liniji
			break;
		}
		ignoreRestOfALine( dat );
		firstWord.clear();
	}
	return dat.eof();
}


void vratiSeZa1ZnakUnazad( std::fstream& dat )
{
	dat.seekg( -1, std::ios::cur );
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
std::string getKomentar( std::fstream& dat )
{
	size_t currentPosInFile = dat.tellg();
	size_t currentPosInComment = dat.tellg();
	size_t previousPosInComment = dat.tellg();
	std::list<std::string> tekstZadatka;
	std::string line;


	auto pronadiPocetakKomentara = [&]()
		{
			while( bool notBeginingOfFile = dat.tellg() > 0 )
			{
				char trenutniZnak = dat.peek();
				vratiSeZa1ZnakUnazad( dat );
				if( trenutniZnak == '/' && dat.peek() == '/' )
					break;	// doslo je do pocetka linije
			}
			dat.get();
			dat.get();	/// preskoci '//' , znakove komentara
		};

/////////////////////
// ovo je test
// previousPosInComment -> 16 - 1 = 15  (- 1 zbog toga sto je zadnja linija komentara)
// currentPosInComment -> 5
// brojZnakova -> 15 - 4 = 11
/////////////////////
	auto preskociWhiteSpace = [ & ]()
		{
			char c;
			while( dat >> c )
			{
				if( isspace( c ) ) continue; // ide jedan znak previse,
				break;
			}
			vratiSeZa1ZnakUnazad( dat );
		};

	auto spremiLinijuUString = [ & ]()
		{
			size_t brojZnakovaULiniji = previousPosInComment - dat.tellg();
			std::getline( dat, line );
			if( !tekstZadatka.empty() )	line += '\n';	// dodaj newline svima osim zadnjoj liniji
			line += '\0';
			tekstZadatka.push_front( line );
			dat.seekg( brojZnakovaULiniji * -1, std::ios::cur );	// vrati ga na mjesto prije nego je pocelo citat znakove u string

		};

	while( bool notBeginingOfFile = dat.tellg() != 0 )
	{
		char trenutniZnak = dat.peek();
		vratiSeZa1ZnakUnazad( dat );	// vracaj se unazad za jedan znak da se nalazis na pocetku linije komentara

		if( bool notBeginingOfFile = dat.tellg(); trenutniZnak == '\n' && notBeginingOfFile > 0 && dat.get() == '\n' )// doslo je do pocetka teksta zadatka
		{
			dat.get(); // preskoci znak '\n'
			while( dat.peek() == '/' )
			{
				dat.get();
			}
			preskociWhiteSpace();
			spremiLinijuUString();
			break;
		}
		vratiSeZa1ZnakUnazad( dat ); // vrati se unazad za znak za koji si sada provjeravao pocetak komentara
		currentPosInComment = dat.tellg();	// zapamti poziciju newline znaka za kasnije

		pronadiPocetakKomentara();
		preskociWhiteSpace();
		spremiLinijuUString();
		while( bool notBeginingOfFile = dat.tellg() > 0 )	// preskoci sve ostale '/' nepotrebne znakove
		{
			if( bool notEndingofNextine = dat.peek() == '\n' )	break;
			vratiSeZa1ZnakUnazad( dat );
		}
		previousPosInComment = currentPosInFile;
		currentPosInFile = dat.tellg();
	}

	std::string retVal;	// dodaj sve linije teksta u jednu cjelinu
	while( !tekstZadatka.empty() )
	{
		std::cout << tekstZadatka.front();
		retVal += tekstZadatka.front();
		tekstZadatka.pop_front();
	}

	dat.seekg( currentPosInFile, std::ios::beg ); // vrati datoteku nazad gdje je bila prije citanja komentara
	return retVal;
}

// BUG: neradi ispravno!!
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
	while( dat >> c )
	{
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
	char c;
	while( dat >> c )
	{
		stack += c == '{';
		stack -= c == '}';
		if( stack == 0 )	break;
	}
}









///



