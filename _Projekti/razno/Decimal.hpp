#pragma once
#include <iostream>

class Decimal
{
public:
	Decimal() : m_base(0), m_decimal(0) {}

public:
	void setBase( int num )
	{
		if( num >= 100000 || num <= -100000 )
		{
			std::cout << "Nedozvoljena baza!\n";
			return;
		}
		m_base = num;
	}
	void setDecimal( int num )
	{
		if( num < 0 )
		{
			std::cout << "Nedozvoljena decimala\n";
			return;
		}
		while( num >= 10 )
		{
			size_t mjesta = 10;
			if      ( num > 100 )	{ mjesta = 100; }
			else if ( num > 1000 )	{ mjesta = 1000; }
			else if ( num > 10000 )	{ mjesta = 10000; }
			else if ( num > 100000 ){ mjesta = 100000; }
			num /= mjesta;
		}
		m_decimal = num;
	}
	int getBase() const { return m_base; }
	int getDecimal() const { return m_decimal; }

private:
	friend std::ostream& operator<<( std::ostream& out, const Decimal& broj )
	{
		for( int znamenka = 5; znamenka >= 0; --znamenka )
			out << ( static_cast<int>( broj.getBase() / pow(10, znamenka) ) % 10 );
		out << "." << broj.getDecimal();
		return out;
	}

private:
	int m_base;
	int m_decimal;
};

