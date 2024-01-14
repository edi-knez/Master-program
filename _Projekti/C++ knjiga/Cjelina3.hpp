#pragma once
#include <iostream>

/// <summary>
///		Ova klasa sadrzi zadatke i vjezbe iz cjeline 3.
/// </summary>
class Cjelina3
{
public:
	static void zad1();
	static void zad3();
	static void zad4();
	static void zad5();

private:
	static double povrsinaVrijednost( double lr ) { return lr * lr * 3.14; }
	static void povrsinaPokazivac( double lr, double* pok ) { *pok = lr * lr * 3.14; }
	static void povrsinaReferenca( double lr, double& refPov ) { refPov = lr * lr * 3.14; }
	static void povrsinaOpseg( double& povrsina, double& opseg, const double& rad )
	{
		povrsina = rad * rad * 3.14;
		opseg = 2 * rad * 3.14;
	}
	//
	class Registracija {
	public:
		Registracija() : m_reg1( 100 ), m_reg2( 100 ) {}
		Registracija( int reg1, int reg2 ) : m_reg1( reg1 ), m_reg2( reg2 ) {}
		void Set( int temp1, int temp2 ) {
			if( temp1 > 99 && temp2 > 99 && temp1 < 1000 && temp2 < 1000 )
			{
				m_reg1 = temp1;
				m_reg2 = temp2;
			}
			else
			{
				std::cout << "Greska!!";
				exit( 1 );
			}
		}
		void ispisi() { std::cout << m_reg1 << "-" << m_reg2 << '\n'; };
	private:
		int m_reg1, m_reg2;
	};
};
