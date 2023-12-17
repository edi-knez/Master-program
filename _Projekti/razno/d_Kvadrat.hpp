#pragma once
#include "b_Oblik.hpp"

#include <math.h>


class d_Kvadrat : public b_Oblik
{
public:
	d_Kvadrat( double str ) : b_Oblik( str * 2 ) {}

public:
	double v_povrsina() override
	{
		return pow( polaStranice, 2 );
	}

};

