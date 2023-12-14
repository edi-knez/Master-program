#include "Time.hpp"

Time::Time( int s, int m, int sec, bool mode = false )
{
	m_mode = mode;
	m_sati = abs( s % ( ( 2 - isMode12() ) * 12 ) );
	m_minute = abs( m % 60 );
	m_sekunde = abs( sec % 60 );
}

[[nodiscard]] inline Time operator+( const Time& t1, const Time& t2 )
{
	int sec = t1.m_sekunde + t2.m_sekunde;
	int min = ( sec >= 60 ) + t1.m_minute + t2.m_minute;
	int sat = ( min >= 60 ) + ( t1.m_sati + t2.m_sati ) % ( ( 2 - t1.isMode12() ) * 12 );	// % 12 ili % 24 zbog overlapa sati
	return Time( sat, min % 60, sec % 60, t1.m_mode );
}

[[nodiscard]] Time operator-( const Time& t1, const Time& t2 )
{
	int tempSec = t1.m_sekunde - t2.m_sekunde;
	int tempMin = t1.m_minute - t2.m_minute;
	int tempSat = t1.m_sati - t2.m_sati;

	// ispravak BUG-a, neispravno vrijeme kada bi underlapao
	int sec = abs( ( ( tempSec < 0 ) * -60 ) + tempSec );
	int min = abs( ( ( ( tempMin - ( tempSec < 0 ) ) < 0 ) * -60 ) + tempMin );
	int sat = abs( ( ( ( tempSat - ( tempMin < 0 ) ) < 0 ) * ( 2 - t1.isMode12() ) * -12 ) + tempSat);
	return Time( sat, min, sec, t1.m_mode );
}

std::ostream& operator<<( std::ostream& out, const Time& t )
{
	out << t.m_sati << " : " << t.m_minute << " : " << t.m_sekunde << '\n';
	return out;
}