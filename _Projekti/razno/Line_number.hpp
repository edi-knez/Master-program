#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


struct lineNumAndPosInfo_t
{
	lineNumAndPosInfo_t() : m_currentLine( 0 ), m_currentPos( 0 ) {}
	lineNumAndPosInfo_t( size_t greska ) : m_currentPos( std::numeric_limits<size_t>::max() ) {}
	size_t m_currentLine;
	std::streampos m_currentPos;
};

class Line_number
{
public:
	Line_number( const Line_number& ) = delete;
	Line_number& operator= ( const Line_number& ) = delete;
	~Line_number() = default;
	Line_number( const char name[] );

public:
	bool init( const char name[] );
	void goto_line( int );
	size_t getCurrentLine();
	long int getCharPos();

public:
	std::fstream& getFileRef() { return m_datoteka; }

private:
	std::fstream m_datoteka;
	size_t m_idx;
	const char* m_nameOfTheFile;
	static std::vector<struct lineNumAndPosInfo_t> m_table;
};