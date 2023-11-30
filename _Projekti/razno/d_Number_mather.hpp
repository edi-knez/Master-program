#pragma once
#include "String_matcher.hpp"

#include <string.h>


class d_Number_mather : public String_matcher
{
public:
	int match( const char* const string )
	{
		if( string == nullptr )	return false;
		while( *string != '\0' )
		{
			if( *string < '0' || *string > '9' )
				return false;
		}
		return true;
	}
};

