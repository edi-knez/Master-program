#pragma once
#include <array>
class Small_set
{
public:
	Small_set() : m_set( { -1 } ) {};
	~Small_set() = default;

public:
	void set( int x );
	void clear( int ind );
	int test( int x );

private:
	static const int _SIZE = 32;
	std::array<int, _SIZE> m_set;

};

