#include "PageFormatting.hpp"

void PageFormatting::open_file( const char* ime )
{
	m_file.open( ime, std::ios::app );
}

void PageFormatting::define_header( const char* header )
{
	if( m_stranica == 0 || m_trenutacnaStranica >= m_stranica ) {}
	else
	{
		m_file << header << "\n\n";
		++m_trenutacnaStranica;
		m_linija += 3;
	}
}

void PageFormatting::print_line( const char* line )
{
	if( m_file.is_open() )
	{
		m_file << line << '\n';
		++m_linija;
		if( m_linija == 24 )  page();
		m_trenutacnaStranica += m_trenutacnaStranica < m_stranica;
	}
}

inline void PageFormatting::page()
{
	if( m_file.is_open() )
	{
		for( ; m_linija % 24 != 0; ++m_linija )
			m_file << '\n';

		++m_stranica;
	}
}

void PageFormatting::close()
{
	if( m_file.is_open() )	m_file.close();
}
