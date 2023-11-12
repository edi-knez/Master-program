#pragma once
#include "b_Oblik.hpp"
#include <math.h>
#include <corecrt_math_defines.h>
class d_Krug : public b_Oblik
{
public:
	d_Krug(double d) : b_Oblik(d) {}
	double v_povrsina()
	{
		return pow( polaStranice, 2 ) * M_PI;
	}
};

