#pragma once
#include "b_Number.hpp"
class d_Hex : public b_Number
{
public:
	d_Hex( int num ) : b_Number( num ) {}

public:
	void print_it() override
	{
		int number = m_num;
		std::string buf;
		buf.reserve( 11 );
		constexpr int temp = 'A' - '0';
		do
		{
			int digit = ( number % 16 );
			buf += static_cast<char>( '0' + ( digit % 10 ) + ( digit > 9 ) * temp );
			number /= 16;
		} while( number != 0 );

		for( const auto ch : buf )
			std::cout << ch;

		std::cout << '\n';
	}
};

