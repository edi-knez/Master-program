#pragma once
#include "String_matcher.hpp"
#include <string.h>
class Word_match : public String_matcher
{
public:
	int match( const char* const string )
	{
		if( string == nullptr )	return -1;
		while( *string != '\0' )
		{
			if( !( *string >= 'a' && *string <= 'z' ||
				   *string >= 'A' && *string <= 'Z' ) )
				return false;
			++string;
		}
		return true;
	}
};

