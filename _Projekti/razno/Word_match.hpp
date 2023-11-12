#pragma once
#include "String_matcher.hpp"
#include <string.h>
class Word_match : public String_matcher
{
public:
	int match( const char* const string )
	{
		const char* ch = string;
		size_t sz = strlen( string );
		bool isWord = sz > 1;
		for( size_t i = 0; i < sz; ++i, ++ch )
		{
			if( !( *ch >= 'a' && *ch <= 'z' || *ch >= 'A' && *ch <= 'Z' ) )
				return false;
		}
		return isWord;
	}
};

