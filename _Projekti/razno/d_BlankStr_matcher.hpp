#pragma once
#include "String_matcher.hpp"
class d_BlankStr_matcher : public String_matcher
{
public:
	int match( const char* const string )
	{
		const char* ch = string;
		if( ch[0] != ' ' )
			return false;
		return (*(++ch) == '\0');
	}
};

