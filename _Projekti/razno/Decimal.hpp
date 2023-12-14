#pragma once
#include <iostream>

// All numbers are of the form DDDDD.D
class Decimal
{
public:
	Decimal() : m_base( 0 ), m_decimal( 0 ) {}

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
		while( num >= 100 )	// skracuj decimalni dio ukoliko je korisnik poslao broj veci od jednoznamenkastog!
		{
			size_t mjesta = 10;
			if( num > 100 ) { mjesta = 100; }
			else if( num > 1'000 ) { mjesta = 1'000; }
			else if( num > 10'000 ) { mjesta = 10'000; }
			else if( num > 100'000 ) { mjesta = 100'000; }
			num /= mjesta;
		}
		m_decimal = num;
	}
	int getBase() const { return m_base; }
	int getDecimal() const { return m_decimal; }

private:
	friend std::ostream& operator<<( std::ostream& out, const Decimal& broj )
	{
		out << broj.getBase() << "." << broj.getDecimal();
		return out;
	}

private:
	int m_base;
	int m_decimal;
};

