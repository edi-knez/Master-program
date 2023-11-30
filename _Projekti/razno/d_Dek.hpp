#pragma once
#include "b_Number.hpp"
class d_Dek : public b_Number
{
public:
	d_Dek( int num ) : b_Number( num ) {}

public:
	void print_it() override
	{
		std::cout << m_num << '\n';
	}
};

