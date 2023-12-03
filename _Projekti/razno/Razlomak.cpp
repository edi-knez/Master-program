#include "Razlomak.hpp"

std::ostream& operator<<( std::ostream& out, const Razlomak& raz )
{
	out << raz.m_brojnik << "/" << raz.m_nazivnik << " ";
	if( raz.m_operacija == '+' ||
		raz.m_operacija == '-' ||
		raz.m_operacija == '*' ||
		raz.m_operacija == '/' ||
		raz.m_operacija == '=' )
	{
		out << raz.m_operacija << " ";
	}
	return out;
}

void Razlomak::skrati( Razlomak& raz )
{
	for( int i = 2; i <= raz.m_nazivnik / 2; ++i )
		if( raz.m_brojnik % i == 0 )
		{
			raz.m_brojnik /= i;
			raz.m_nazivnik /= i;
		}
}

void Razlomak::setBrojnik( int broj1 )
{
	m_brojnik = broj1;
}

void Razlomak::setNazivnik( int broj1 )
{
	if( broj1 == 0 )
	{
		std::cout << "nazivnik nemoze biti 0!\n";
		return;
	}
	m_nazivnik = broj1;

	if( m_brojnik == 0 )	m_nazivnik = 1;
}

void Razlomak::setOperacija( char oper )
{
	switch( oper )
	{
	case '+': case '-': case '*': case '/':
		m_operacija = oper;
		break;
	default:
		std::cout << "Nece ici. Dozvoljenje operacije: +, -, *, /\n";
	}
}

Razlomak operator +( const Razlomak& raz1, const Razlomak& raz2 )
{
	Razlomak rezultat;
	rezultat.m_brojnik = ( raz1.m_brojnik * raz2.m_nazivnik ) + ( raz2.m_brojnik * raz1.m_nazivnik );
	rezultat.m_nazivnik = raz1.m_nazivnik * raz2.m_nazivnik;
	Razlomak::skrati( rezultat );
	return rezultat;
}

Razlomak operator -( const Razlomak& raz1, const Razlomak& raz2 )
{
	Razlomak rezultat;
	rezultat.m_brojnik = ( raz1.m_brojnik * raz2.m_nazivnik ) - ( raz2.m_brojnik * raz1.m_nazivnik );
	rezultat.m_nazivnik = raz1.m_nazivnik * raz2.m_nazivnik;
	Razlomak::skrati( rezultat );
	return rezultat;
}

Razlomak operator *( const Razlomak& raz1, const Razlomak& raz2 )
{
	Razlomak rezultat;
	rezultat.m_brojnik = raz1.m_brojnik * raz2.m_brojnik;
	rezultat.m_nazivnik = raz1.m_nazivnik * raz2.m_nazivnik;
	Razlomak::skrati( rezultat );
	return rezultat;
}

Razlomak operator /( const Razlomak& raz1, const Razlomak& raz2 )
{
	Razlomak rezultat;
	rezultat.m_brojnik = raz1.m_brojnik / raz2.m_brojnik;
	rezultat.m_nazivnik = raz1.m_nazivnik / raz2.m_nazivnik;
	Razlomak::skrati( rezultat );
	return rezultat;
}