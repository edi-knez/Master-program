#pragma once


class b_Oblik
{
public:
	virtual ~b_Oblik() = default;

public:
	b_Oblik( double d ) : polaStranice( d / 2 ) {}
protected:
	double polaStranice;
	virtual double v_povrsina() = 0;
};

