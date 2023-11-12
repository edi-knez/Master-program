#include "Queue.hpp"


inline int Queue::get()
{
	//assert( Checkbook::total() > 0 );
	try
	{
		return m_items[--totalCount];
	}
	catch( int broj )
	{
		std::cout << "Exception: " << broj << '\n';
	}
	catch( const std::exception& e )
	{
		std::cout << "Expection: " << e.what() << "\n";
	}
}

std::array<int, 10> Queue::get10()
{
	std::array<int, 10> items;
	for( size_t i = 0; i < 10; ++i )
	{
		items[i] = get();
	}
	return items;
}