#include "Line_number.hpp"

std::vector<lineNumAndPosInfo_t> Line_number::m_table{};

Line_number::Line_number( const char name[] ) 
{ 
	if( init( name ) )
	{
		m_idx = m_table.size();
		m_table.push_back( lineNumAndPosInfo_t() );
	}
	else
	{
		Line_number::~Line_number();
	}
}

bool Line_number::init( const char name[] )
{
	// stvori datoteku ako ne postoji
	m_datoteka.open( name, std::ios::in );
	if( m_datoteka.is_open() )
	{
		m_nameOfTheFile = name;
		return true;
	}
	else
	{
		std::cout << "Datoteka nije otvorena!\n";
		return false;
	}
}

void Line_number::goto_line( int zeljenaLinija = 0 )
{
	if( zeljenaLinija < 0 )	return;

	if( m_table[m_idx].m_currentLine == zeljenaLinija )	return;

	// nadi najmanju arihmeticku sredinu (najblizu liniju)
	std::for_each( std::begin( m_table ), std::end( m_table ), [&]( lineNumAndPosInfo_t& info ) 
	{
		//linija = std::min( std::abs( vLin[0] - zeljenaLinija ), linija );
		size_t abs = std::abs( static_cast<long>(info.m_currentLine) - zeljenaLinija );
		if( abs < m_table[m_idx].m_currentLine - zeljenaLinija )
		{
			//std::cout << "skacem na liniju: " << info.m_currentLine << " sa linije ovog objekta: " << m_table[m_idx].m_currentLine << "\nNova lokacija u datoteci: " << info.m_currentPos << ", stara lokacija: " << m_table[m_idx].m_currentPos << "\n";
			m_table[m_idx].m_currentLine = info.m_currentLine;
			m_table[m_idx].m_currentPos = info.m_currentPos;
			m_datoteka.seekg( info.m_currentPos, std::ios::beg );
		}
	});

	// ako je manji bit ce 1, ako veci bit ce -1
	int pomak = ( m_table[m_idx].m_currentLine < zeljenaLinija ) - ( m_table[m_idx].m_currentLine > zeljenaLinija );

	if( pomak == 1 )
		while ( getCurrentLine() != zeljenaLinija )
		{
			if( m_datoteka.eof() ) { std::cout << "Ova datoteka nema toliko linija!\n"; return; }
			
			//std::cout << (unsigned char)m_datoteka.peek();
			m_table[m_idx].m_currentLine +=  m_datoteka.get() == '\n';
		}
	else
	{
		while( getCurrentLine() != zeljenaLinija )
		{
			if( m_datoteka.tellg() == -1 ) { std::cout << "Ova datoteka je vec na pocetku!\n"; return; }

			//std::cout << (unsigned char)m_datoteka.peek();
			m_table[m_idx].m_currentLine -=  m_datoteka.seekg( -1, std::ios::cur ).peek() == '\n';
		}
	}
	m_table[m_idx].m_currentPos = m_datoteka.tellg();
}

size_t Line_number::getCurrentLine() { return m_table[m_idx].m_currentLine; }

long int Line_number::getCharPos()
{
	long int pos = 0;
		// od trenutacne pozicije karaktera odi nazad jedno mjesto dok ne dode
	if( getCurrentLine() == 0 ) // do pocetka datoteke
		while( m_datoteka.seekg( -1, std::ios::cur ).tellg() != -1  )
			++pos;
	else // ili do new line
		while( m_datoteka.seekg( -1, std::ios::cur ).peek() != '\n' )
		{
			//std::cout << (unsigned char)m_datoteka.seekg( -1, std::ios::cur ).get();
			++pos;
		}

	// vrati lokaciju get pokazivaca tamo dije pokazivao prije poziva ova funkcije
	m_datoteka.seekg( pos, std::ios::cur );
	return pos;
}