#include "SymbolTable.hpp"

void SymbolTable::enter( const char* name )
{
	table.push_back( name );
}

bool SymbolTable::lookup( const char* name )
{
	for( const auto& item : table )
	{
		if( item == name )
			return true;
	}
	return false;
}

void SymbolTable::remove( const char* name )
{
	std::vector<std::string>::iterator it = table.begin();
	for( size_t i = 0; i < table.size(); )
	{
		if( table[i] == name )
		{
			table.erase( ( it + i ) );
			it = table.begin();	// postavi iterator na pravo mjesto ako se vektor premjesti
		}
		else	++i;
	}
}