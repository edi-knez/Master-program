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

ParseFile::ParseFile( const std::string_view& path, std::string& imeDatoteke, const char* ekstenzijaDatoteka )
{
	if( path.empty() || path[0] == '\0' )
	{
		std::cout << "UNESI VAZECI PATH!\n";
		exit( EXIT_FAILURE );
	}
	if( imeDatoteke.empty() )
	{
		std::cout << "UNESI IME DATOTEKE GDJE SE NALAZE ZELJENE FUNKCIJE!\n";
		exit( EXIT_FAILURE );
	}

	m_paths.push_back( path );
	for( size_t datIdx = 0; datIdx < imeDatoteke.size(); ++datIdx )
	{
		//std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka;
		m_datoteke.emplace_back( m_paths.front().data() + imeDatoteke, std::ios::in | std::ios::out | std::ios::ate );
		m_datoteke[datIdx].seekg( std::ios::beg );
		m_datoteke[datIdx].seekp( std::ios::beg );
		if( !m_datoteke[datIdx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << m_paths.front() << imeDatoteke << '\n';
			exit( EXIT_FAILURE );
		}
	}
}

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
		m_datoteke.emplace_back( m_paths.front().data() + datotekeProjekta, std::ios::in | std::ios::out | std::ios::ate );
		m_datoteke[datIdx].seekg( std::ios::beg );
		m_datoteke[datIdx].seekp( std::ios::beg );
		if( !m_datoteke[datIdx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << m_paths.front() << datotekeProjekta << '\n';
			exit( EXIT_FAILURE );
		}
	}
}

//////////////////////////////////////////// DEBUG //////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
static size_t DEBUG_FILE_IDX = 1;
static const bool _DEBUG_FLAG = true;
static const bool DEBUG_ACTIVE = false;

#define DUMP_FILE() \
if( DEBUG_FLAG ) \
{ \
	std::string line2; \
	while( std::getline( dat, line2 ) ) \
	{ \
		std::cout << "LINE: " << line2 << "\n"; \
		line2.clear(); \
	} \
}									

#define DEBUG_LOG(IDX_OF_FILE) \
if( _DEBUG_FLAG && DEBUG_IDX == DEBUG_IDX ) \
{ \
	std::cout << "\n----------------------\n"; \
	std::cout << "Nalazim se na znaku: " << static_cast<char>( dat.peek() ) << '\n'; \
	std::cout << "Trenutacna lokacija: " << dat.tellg(); \
	std::cout << "\n----------------------\n"; \
}

#define DEBUG_PRTLINE(DEBUG_ACTIVE) \
{ \
	std::string _line; \
	std::getline( dat, _line ); \
	if( _DEBUG_FLAG && DEBUG_ACTIVE )	std::cout << "LINE: " << _line <<"\n"; \
}

/// ///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


bool findStartOfAFunction( std::fstream& dat/*, std::streampos& brojRedaka*/, const bool DEBUG_FLAG = false );
std::string getKomentar( std::fstream& dat, const bool DEBUG_FLAG = false );
std::string getDeclaration( std::fstream& dat, const bool DEBUG_FLAG = false );
std::string getFuncBody( std::fstream& dat, const bool DEBUG_FLAG = false );
void ParseFile::readFile( std::fstream& dat, std::vector<std::unique_ptr<Zadatak>>& zadaci, size_t& upotrijevbljenoZadataka, const bool DEBUG_FLAG ) const
{
	size_t pronadenoZadataka = 0;
	while( !dat.eof() )
	{
#if true	
//		if( (DEBUG_IDX & 1) == 1 )	// dumpaj samo neparne
		{
			DUMP_FILE();
		}
#endif
		/*std::streampos unused = 0;*/
		bool is_eof = findStartOfAFunction( dat/*, unused*/ );
		if( !is_eof )
		{
			if( pronadenoZadataka < zadaci.size() )
			{
				zadaci[pronadenoZadataka].get()->tekst = getKomentar( dat, DEBUG_FLAG );
				zadaci[pronadenoZadataka].get()->deklaracija = getDeclaration( dat, DEBUG_FLAG );
				zadaci[pronadenoZadataka].get()->kod = getFuncBody( dat, DEBUG_FLAG );
			}
			else
			{
				auto zad = std::make_unique<Zadatak>();
				zad->tekst = getKomentar( dat, DEBUG_FLAG );
				zad->deklaracija = getDeclaration( dat, DEBUG_FLAG );
				zad->kod = getFuncBody( dat, DEBUG_FLAG );
				zadaci.push_back( std::move( zad ) );
			}
			++pronadenoZadataka;
		}
		++DEBUG_FILE_IDX;
	}
	upotrijevbljenoZadataka = pronadenoZadataka;
}

bool findStartOfAFunction( std::fstream& dat/*, std::streampos& brojRedaka*/, const bool DEBUG_FLAG )
{
	auto ignoreRestOfALine = [&]()
		{
			while( char c = dat.get() )
			{
				if( c == '\n' || c == ';' )	break;
			}
		};

	std::string firstWord;
	firstWord.reserve( 30 );
	// TODO: mjesto za razmislit u buducnosti
	std::string funRetType = "void";
	while( dat >> firstWord )
	{
		if( firstWord == funRetType )
		{
			size_t brojProvjereZnakovaDeklaracije = 0;
			char c;
			while( c = dat.get() )
			{
				++brojProvjereZnakovaDeklaracije;
				bool didItFoundEndOfALine = c == '\n';
				bool didItFoundFunctionBody = c == '{';
				bool didItFoundEndOfDeclaration = c == ';';

				/// ispravak EDGE CASE-a -> detektiraj zavrsetak parametarske liste funkcije, tek nakon toga nastavi trazit pocetak funkcije
				if( didItFoundEndOfALine )
				{
					while( c = dat.get() )
					{
						if( !isspace( c ) )	break;
						++brojProvjereZnakovaDeklaracije;
					}
					if( c == '{' )	goto success;
					else			goto failed;	// ako nije pocetak tijela funkcije, znaci da je kraj deklaracije. Provjeri ima li vise uspjeha u sljedecoj liniji
				}
				else if( didItFoundFunctionBody )		goto success;	// pocetna zagrada funkcije se nalazi u istoj liniji
				else if( didItFoundEndOfDeclaration ) { ignoreRestOfALine(); goto failed; }	// neradi se o definicije funkcije, nego samo o deklaraciji
			}

		success:
			dat.seekg( -1 * ( firstWord.size() + 1 + brojProvjereZnakovaDeklaracije + 1 ), std::ios::cur );	 // + 1, da se vrati ispred 1. znaka u toj liniji
			break;
		}

		ignoreRestOfALine();
	failed:
		firstWord.clear();
	}

	return dat.eof();
}


void vratiSeZa1ZnakUnazad( std::fstream& dat )
{
	dat.seekg( -1 * ( dat.tellg() > 0 ), std::ios::cur );
}

/// <summary>
///		test komentar

// TODO: OPTIMIZACIJA, umjesto dodavanja znakova stringu, vrati pocetnu i krajnju poziciju u datoteci iz koje ce spremit tekst u string sa samo jednom alokacijom
/// <summary>
///		Da bi bio siguran da citas komentar od funkcije, a ne neki random, moras pocet citat od deklaracije te funkcije.
///		Citas od kraja linije prema pocetku dok nenaides na pocetak komentara "//" ili dok do dodes do kraja cijelog komentara (linija izned nema znakove jednolijskog kokmentara ili si naisao na pocetak viselinijskog komentara).
///		Linije sprema u listu sprijeda. Jer se cita odzada, to je najjednostavniji nacini da se dobije ispravan tekst zadatka.	
/// 
///		Garantirano je da je komentar u ovom formatu jer inace se nebi moglo kompajlat.
/// </summary>
/// <param name="dat"> datoteka koja se cita </param>
/// <returns> Cijeli tekst zadatka (ukoliko ga ima) </returns>
std::string getKomentar( std::fstream& dat, const bool DEBUG_FLAG )
{
//	DEBUG_PRTLINE( true );

//	//	if( ::_DEBUG_FLAG && ::DEBUG_FILE_IDX == 2 )
//	//		std::cout << "\n----------------------\nLokacija u datoteci: " << dat.tellg() << "\n------------------------------\n";

	size_t currentPosInFile = dat.tellg();
	size_t currentPosInComment = dat.tellg();
	size_t previousPosInComment = dat.tellg();
	std::list<std::string> tekstZadatka;
	std::string line;
	bool pronasaoPocetakLinijeKomentara = false;
	bool pronasaoPocetakCijelogKomentara = false;
	bool pronasaoKrajViseLinijskogKomentara = false;

/////////////////////
// ovo je test
// previousPosInComment -> 16 - 1 = 15  (- 1 zbog toga sto je zadnja linija komentara)
// currentPosInComment -> 5
// brojZnakova -> 15 - 4 = 11
/////////////////////


	auto pronadiPocetakKomentara = [&]()
		{
			while( bool notBeginingOfFile = dat.tellg() > 0 && !pronasaoPocetakCijelogKomentara )
			{
				char trenutniZnak = dat.peek();
				if( trenutniZnak == '\n' && !pronasaoPocetakLinijeKomentara )
				{
					pronasaoPocetakCijelogKomentara = true;
					break;
				}

				vratiSeZa1ZnakUnazad( dat );
				if( dat.peek() == '/' && trenutniZnak == '/' )
				{
					pronasaoPocetakLinijeKomentara = true;
					break;
				}

				if( !pronasaoPocetakLinijeKomentara && dat.peek() == '*' && trenutniZnak == '/' ) // da bih se izbjegli bugovi, viselinijski komentari se zasebno handle-aju
				{
					currentPosInComment = dat.tellg();
					pronasaoKrajViseLinijskogKomentara = true;
					while( bool notBeginingOfFile = dat.tellg() > 0 )
					{
						trenutniZnak = dat.peek();
						vratiSeZa1ZnakUnazad( dat );
						if( dat.peek() == '\n' )	break;
						if( dat.peek() == '/' && trenutniZnak == '/' )
						{
							pronasaoKrajViseLinijskogKomentara = false;
							pronasaoPocetakLinijeKomentara = true;
							break;
						}
					}
					if( pronasaoPocetakLinijeKomentara )	break;

					while( bool notBeginingOfFile = dat.tellg() > 0 )
					{
						trenutniZnak = dat.peek();
						vratiSeZa1ZnakUnazad( dat );
						if( dat.peek() == '/' && trenutniZnak == '*' )
						{
							pronasaoPocetakCijelogKomentara = true;
							break;
						}
					}
					if( pronasaoPocetakCijelogKomentara )	break;
				}
			}
#if false
			if( ::_DEBUG_FLAG && ::DEBUG_IDX == 6 && currentPosInComment == 740 )
				std::cout << "\n----------------------\nTrenutni znak: " << dat.peek() << "\n------------------------------\n";
#endif
			dat.get(); /// preskoci '//' , znakove komentara
			dat.get();
		};


	auto spremiLinijuUString = [&]()
		{
			previousPosInComment = currentPosInComment;
			currentPosInComment = dat.tellg();

			std::getline( dat, line );
			if( !tekstZadatka.empty() )	line += '\n';	// dodaj newline svima osim zadnjoj liniji
			tekstZadatka.push_front( line );

			long long brojZnakovaULiniji = abs( static_cast<long long>( previousPosInComment - dat.tellg() ) );
			dat.seekg( brojZnakovaULiniji * -1 - 1, std::ios::cur );	// vrati ga na mjesto prije nego je pocelo citat znakove u string
		};


	while( bool notBeginingOfFile = dat.tellg() > 1 )	// mora imat barem 2 znaka '/' da bi se linija smatrala kao komentar
	{
		pronasaoPocetakLinijeKomentara = false;
		vratiSeZa1ZnakUnazad( dat );
		vratiSeZa1ZnakUnazad( dat );
		vratiSeZa1ZnakUnazad( dat ); // vrati se unazad da bi dosao ispred znaka za novu liniju ( '\n' )
		if( dat.tellg() == 0 )	break;
		currentPosInComment = dat.tellg();	// zapamti poziciju newline znaka za kasnijef

		pronadiPocetakKomentara(); // vracaj se unazad za jedan znak da se nalazis na pocetku linije komentara
		if( pronasaoPocetakCijelogKomentara )	break;
		char c;
#if false
		DEBUG_LOG( 1 );
#endif
		if( pronasaoPocetakLinijeKomentara )
		{
			while( isspace( dat.peek() ) ) { dat.get(); } // nalazi se na znaku '/'
			spremiLinijuUString();
			while( bool notBeginingOfFile = dat.tellg() > 0 )	// preskoci sve ostale '/' nepotrebne znakove
			{
				if( bool notEndingOfNextine = dat.peek() == '\n' )	{ dat.get(); break; }
				vratiSeZa1ZnakUnazad( dat );
			}
		}
	}

	std::string retVal;	// dodaj sve linije teksta u jednu cjelinu
	if( pronasaoKrajViseLinijskogKomentara )
	{
		retVal.reserve( currentPosInComment - dat.tellg() );
		while( dat.tellg() != currentPosInComment )
			retVal += dat.get();
	}
	else
	{
		while( !tekstZadatka.empty() )
		{
			retVal += tekstZadatka.front();
			tekstZadatka.pop_front();
		}
	}

#if false
//	if( ::_DEBUG_FLAG && ::DEBUG_IDX == 2 )	DUMP_FILE();
#endif

	dat.seekg( currentPosInFile, std::ios::beg ); // vrati datoteku nazad gdje je bila prije citanja komentara

	return retVal;
}

// TODO: OPTIMIZACIJA, umjesto dodavanja znakova stringu, vrati pocetnu i krajnju poziciju u datoteci iz koje ce spremit tekst u string sa samo jednom alokacijom
std::string getDeclaration( std::fstream& dat, const bool DEBUG_FLAG )
{
	while( isspace( dat.peek() ) )
	{
		dat.get();
	//	if( ::_DEBUG_FLAG && ::DEBUG_IDX == 2 )	std::cout << dat.peek() << '\n';
	}	// preskoci whitespace
	bool startOfArguments = false;
	size_t stack = 0;
	std::string deklaracija;

	while( startOfArguments == false || stack != 0 )
	{
		stack += dat.peek() == '(';
		stack -= dat.peek() == ')';
		startOfArguments |= stack;
		deklaracija += dat.get();
	}
	dat.get();
	return deklaracija;
}

// TODO: OPTIMIZACIJA, umjesto dodavanja znakova stringu, vrati pocetnu i krajnju poziciju u datoteci iz koje ce spremit tekst u string sa samo jednom alokacijom
std::string getFuncBody( std::fstream& dat, const bool DEBUG_FLAG )
{
	std::string retVal = "";
	std::string line = "";
	line.reserve( 255 );
	size_t stack = 0;
	while( true )
	{
		std::getline( dat, line );
		for( const char c : line )
		{
			retVal += c;
			stack += c == '{';
			stack -= c == '}';
		}
		if( stack == 0 )	break;
		retVal += '\n';
	}
	//std::cout << retVal;
	return retVal;
}

/// <summary>
///		Pretrazuje ostatak datoteke od lokacije na kojemu se referenca trenutacno nalazi
/// </summary>
/// <param name="dat"> referenca datoteke koju pretrazujes </param>
/// <param name="imeFunkcije"> ime funkcije koje trazis u toj datoteci </param>
/// <returns> offset ili nullopt ako nije uspjela pretraga </returns>
std::optional<size_t> ParseFile::getPositionOfFunction( std::fstream& dat, const char* imeFunkcije )
{
	/*std::streampos brojRedaka = 0;
	brojRedaka += 1;*/
	while( bool is_not_eof = !findStartOfAFunction( dat/*, brojRedaka*/ ) )
	{
		std::string deklaracija = getDeclaration( dat );
		std::string::iterator it;
		// pronadi pocetak povratnog tipa
		it = std::find_if( deklaracija.begin(), deklaracija.end(), []( char c )
						   {
							   return isalpha( c );
						   } );
		// pronadi kraj povratnog tipa
		it = std::find_if( it, deklaracija.end(), []( char c )
						   {
							   return  isspace( c );
						   } );
		// pronadi pocetak imena funkcije
		it = std::find_if( it, deklaracija.end(), []( char c )
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
		if( strcmp( pronadenoIme.data(), imeFunkcije ) == 0 )	return dat.tellg() /*( dat.tellg() - brojRedaka )*/;
		else													skipFuncBody( dat/*, brojRedaka*/ );
	}
	return {};
}

/// <summary>
///		Preskace tijelo funkcije. Nekoristi nepotrebno dodatnu memoriju i vrijeme za bufere, te ne vraca nikakav string za razliku od funkcije getFuncBody
/// 
///		SMATRA SE da je pokazivac trenutne lokacije u datoteci na znaku za pocetak funkcije koje zelis preskocit ( '{' )
/// </summary>
/// <param name="dat"> referenca datotecnog objekta gdje preskaces tijelo funkcije </param>
void ParseFile::skipFuncBody( std::fstream& dat/*, std::streampos& brojPreskocenihLinija*/ )
{
	size_t stack = 0;
	char c;
	while( dat >> c )
	{
		/*brojPreskocenihLinija += c == '\n';*/
		stack += c == '{';
		stack -= c == '}';
		if( stack == 0 )	break;
	}
}






 ///

std::ostream& operator<<( std::ostream& dat, const Zadatak& zad )
{
	dat << "TEKST ZADATKA: " << zad.tekst << '\n'
		<< "DEKLARACIJA: " << zad.deklaracija << '\n'
		<< "KOD:\n" << zad.kod << '\n';
	return dat;
}