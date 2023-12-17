#include "StringDouble.hpp"

StringDouble operator+( const StringDouble& sd1, const StringDouble& sd2 )
{
	double d1 = std::stod( sd1.m_broj );
	double d2 = std::stod( sd2.m_broj );
	return StringDouble( std::to_string( d1 + d2 ) );
}

StringDouble operator- ( const StringDouble& sd1, const StringDouble& sd2 )
{
	double d1 = std::stod( sd1.m_broj );
	double d2 = std::stod( sd2.m_broj );
	return StringDouble( std::to_string( d1 - d2 ) );
}

StringDouble operator* ( const StringDouble& sd1, const StringDouble& sd2 )
{
	double d1 = std::stod( sd1.m_broj );
	double d2 = std::stod( sd2.m_broj );
	return StringDouble( std::to_string( d1 * d2 ) );
}

StringDouble operator/ ( const StringDouble& sd1, const StringDouble& sd2 )
{
	double d1 = std::stod( sd1.m_broj );
	double d2 = std::stod( sd2.m_broj );
	if( d2 != 0 )	return StringDouble( std::to_string( d1 / d2 ) );
	else			return StringDouble{ "Math Error: djeljenje sa 0!" };
}

std::ostream& operator<<( std::ostream& out, const StringDouble& sd )
{
	out << sd.m_broj << " ";
	return out;
}