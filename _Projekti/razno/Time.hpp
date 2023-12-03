#pragma once
#include <iostream>
class Time
{
public:
	// postavlja mode i vrijeme na 0 : 0 : 0
	Time( bool mode = false ) : m_mode( mode ), m_sati( 0 ), m_minute( 0 ), m_sekunde( 0 ) {}
	// postavlja mode i vrijeme na apsolutnu vrijednost ostatka djeljenja sa 60
	Time( int s, int m, int sec, bool mode );

public:
	friend Time operator+ ( const Time&, const Time& );
	friend Time operator- ( const Time&, const Time& );
	friend std::ostream& operator<<( std::ostream& out, const Time& );

private:
	bool isMode12() const { return m_mode == true; }

private:
	bool m_mode;

private:
	int m_sati;
	int m_minute;
	int m_sekunde;
};

