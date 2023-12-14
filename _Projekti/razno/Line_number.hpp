#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


struct lineNumAndPosInfo_t
{
	lineNumAndPosInfo_t() : m_currentLine( 0 ), m_currentPos( 0 ) {}
	lineNumAndPosInfo_t( size_t greska ) : m_currentLine( std::numeric_limits<size_t>::max() ), m_currentPos( 0 ) {}
	size_t m_currentLine;
	std::streampos m_currentPos;
};

/// <summary>
///		Ovo je klasa koja prati broj linije na kojoj se nalazi u otvorenoj datoteci. Takoðer se može saznat na kojem znaku se nalazi pokazivac.
///		Ima podatkovni clan tipa vektora koji sadrzi valjane infromacije o podatkovnim linijama od drugih objekata koji imaju otvorenu tu istu			datoteku. Koristi ga kao checkpoint da dode do zeljene linije umjesto za svaki objekt da trazi zeljenu liniju od pocetka datoteke.
/// </summary>
class Line_number
{
public:
	Line_number( const Line_number& ) = delete;
	Line_number& operator= ( const Line_number& ) = delete;
	~Line_number() = default;
	Line_number( const char name[] );

public:
	bool init( const char name[] );
	void goto_line( size_t lineNumber );
	size_t getCurrentLine();
	size_t getCharPos();

public:
	std::fstream& getFileRef() { return m_datoteka; }

private:
	std::fstream m_datoteka;
	size_t m_idx;
	const char* m_nameOfTheFile;
	static std::vector<struct lineNumAndPosInfo_t> m_table;
};