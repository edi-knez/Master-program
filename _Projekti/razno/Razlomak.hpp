#pragma once
#include <iostream>
#include <array>

//
//// prvo podrska za 1 operaciju, a onda za vise njih, zagrade
//// + - * /
class Razlomak
{
public:
	Razlomak() = default;
	Razlomak( int brojnik, int nazivnik ) { m_brojnik = brojnik; m_nazivnik = (nazivnik == 0) + (nazivnik != 0 ) * nazivnik; m_operacija = '\0'; }
	Razlomak( int brojnik, int nazivnik, char oper ) { m_brojnik = brojnik; m_nazivnik = ( nazivnik == 0 ) + ( nazivnik != 0 ) * nazivnik; m_operacija = oper; }

public:
	void setBrojnik( int );
	void setNazivnik( int );
	void setOperacija( char oper );

public:
	friend std::ostream& operator<< ( std::ostream& out, const Razlomak& raz );


public:
	friend Razlomak operator+( const Razlomak& raz1, const Razlomak& raz2 );
	friend Razlomak operator-( const Razlomak& raz1, const Razlomak& raz2 );
	friend Razlomak operator*( const Razlomak& raz1, const Razlomak& raz2 );
	friend Razlomak operator/( const Razlomak& raz1, const Razlomak& raz2 );

private:
	 //skracuje sam sebe
	static void skrati( Razlomak& raz );

private:
	int m_brojnik;
	int m_nazivnik;
	char m_operacija;
};

