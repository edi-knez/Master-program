#pragma once
#include <string>
#include <vector>


class SymbolTable
{
public:
	SymbolTable() { m_table.reserve( 10 ); };

public:
	void enter( const char* name );
	bool lookup( const char* name );
	void remove( const char* name );

private:
	std::vector<std::string> m_table;
};

