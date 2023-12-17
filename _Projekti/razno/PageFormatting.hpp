#pragma once
#include<fstream>


class PageFormatting
{
public:
	PageFormatting() = default;
	PageFormatting( const PageFormatting& ) = delete;
	PageFormatting& operator=( const PageFormatting& ) = delete;

public:
	void open_file( const char* );
	void define_header( const char* );
	void print_line( const char* );
	void page();
	void close();

private:
	std::ofstream m_file;
	uint32_t m_linija;	// trenutacna
	uint32_t m_stranica; // ukupno
	uint32_t m_trenutacnaStranica;
};

