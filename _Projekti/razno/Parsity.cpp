#include "Parsity.hpp"

Parsity::Parsity() : count( 0 )
{
}

void Parsity::put()
{
	++count;
}

bool Parsity::test()
{
	return ( count % 2 == 0 );
}