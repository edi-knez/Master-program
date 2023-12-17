#pragma once
#include <iostream>
#include <sstream>


class b_Number
{
public:
	b_Number() = delete;
	b_Number( int n ) : m_num( n ) {}

protected:
	virtual void print_it() = 0;

protected:
	int m_num;
};

