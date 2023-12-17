#include "SymbolTable.hpp"

void SymbolTable::enter( const char* name )
{
	m_table.push_back( name );
}

bool SymbolTable::lookup( const char* name )
{
	for( const auto& item : m_table )
	{
		if( item == name )
			return true;
	}
	return false;
}

void SymbolTable::remove( const char* name )
{
	std::vector<std::string>::iterator it = m_table.begin();
	for( size_t i = 0; i < m_table.size(); )
	{
		if( m_table[i] == name )
		{
			m_table.erase( ( it + i ) );
			it = m_table.begin();	// postavi iterator na pravo mjesto ako se vektor premjesti
		}
		else	++i;
	}
}