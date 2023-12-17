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
		buf.reserve( 5 );
		constexpr int temp = 'A' - '0';
		do
		{
			int digit = ( number % 16 );
			// uzmi znak 0 i dodaj mu ostatak da dode na pravi ASCI broj
			// za brojeve ( 0 - 9 ), a za slova ( 0 - 5 )
			// ako je slovo, dodaj mu razliku 'A' - '0' da ima tocan ASCI broj tog slova
			buf += static_cast<char>( '0' + ( digit % 10 ) + ( digit > 9 ) * temp );
			number /= 16;
		} while( number != 0 );

		for( const auto ch : buf )
			std::cout << ch;

		std::cout << '\n';
	}
};

