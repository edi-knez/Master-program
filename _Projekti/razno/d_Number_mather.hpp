#pragma once
#include "String_matcher.hpp"
#include <string.h>
class d_Number_mather : public String_matcher
{
public:
	int match( const char* const string )
	{
		const char* ch = string;
		size_t sz = strlen( string );
		bool isNumber = sz > 1;
		for( size_t i = 0; i < sz; ++i, ++ch )
		{
			if( *ch < '0' || *ch > '9' )
				return false;
		}
		return isNumber;
	}
};

