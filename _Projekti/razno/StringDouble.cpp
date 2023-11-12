#include "StringDouble.hpp"

StringDouble operator+( const StringDouble& sd1, const StringDouble& sd2 )
{
    double d1 = std::stod( sd1.broj );
    double d2 = std::stod( sd2.broj );
    return StringDouble( std::to_string( d1 + d2 ) );
}

StringDouble operator- ( const StringDouble& sd1, const StringDouble& sd2 )
{
    double d1 = std::stod( sd1.broj );
    double d2 = std::stod( sd2.broj );
    return StringDouble( std::to_string( d1 - d2 ) );
}

StringDouble operator* ( const StringDouble& sd1, const StringDouble& sd2 )
{
    double d1 = std::stod( sd1.broj );
    double d2 = std::stod( sd2.broj );
    return StringDouble( std::to_string( d1 * d2 ) );
}

StringDouble operator/ ( const StringDouble& sd1, const StringDouble& sd2 )
{
    double d1 = std::stod( sd1.broj );
    double d2 = std::stod( sd2.broj );
    return StringDouble( std::to_string( d1 / d2 ) );
}

std::ostream& operator<<( std::ostream& out, const StringDouble& sd )
{
    out << sd.broj << " ";
    return out;
}