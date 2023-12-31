#pragma once
#include "b_Number.hpp"


class d_Okt : public b_Number
{
public:
	d_Okt( int num ) : b_Number( num ) {}

public:
	void print_it() override
	{
		int number = m_num;
		std::string buf;
		buf.reserve( 11 );
		do
		{
			buf += std::to_string( number % 8 );
			number /= 8;
		} while( number != 0 );

		for( const auto ch : buf )
			std::cout << ch;

		std::cout << '\n';
	}
};

