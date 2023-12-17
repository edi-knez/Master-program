#pragma once
#include "String_matcher.hpp"

static bool isSpace( const char ch ) { return ch == ' '; }

class d_BlankStr_matcher : public String_matcher
{
public:
	int match( const char* const string ) override
	{
		if( *string == '\0' )	return 0;

		const char* ch = string;
		if( isSpace( *ch ) && isSpace( *( ch + 1 ) ) )	return true;
		else											return ( *( ++ch ) == '\0' ); // ako je sljedeci znak kraj stringa, takoder je prazan string jer se nalazi iza razmaka
	}
};

