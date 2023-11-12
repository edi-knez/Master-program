#pragma once

#include <array>
#include <iostream>
#include <assert.h>
class Checkbook
{
public:
	Checkbook();

public:
	int total();

public:
	void addItem( int item );

protected:
	static const int MAX_SIZE = 1;
	size_t totalCount;
	std::array<int, MAX_SIZE> m_items;

};

