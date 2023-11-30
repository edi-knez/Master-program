#pragma once
#include <string>
#include <vector>


class SymbolTable
{
public:
	SymbolTable() { table.reserve( 10 ); };

public:
	void enter( const char* name );
	bool lookup( const char* name );
	void remove( const char* name );

private:
	std::vector<std::string> table;
};

