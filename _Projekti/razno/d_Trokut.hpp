#pragma once
#include "b_Oblik.hpp"
class d_Trokut : public b_Oblik
{
public:
	d_Trokut( double stranica, double visina ) : b_Oblik( stranica ), m_visina( visina ) {}

public:
	double v_povrsina()
	{
		return polaStranice * m_visina;
	}

private:
	double m_visina;
};

