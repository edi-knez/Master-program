#include "Checkbook.hpp"


void Checkbook::addItem( int item )
{
	try
	{
		if( total() >= MAX_SIZE )	throw "Nema vise mjesta!";

		m_items[totalCount] = item;
		++totalCount;
	}
	catch( const char* txtCode )
	{
		std::cout << txtCode << '\n';
	}

}

int Checkbook::total()
{
	return totalCount;
}

