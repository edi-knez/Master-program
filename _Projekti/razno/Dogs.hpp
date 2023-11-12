#pragma once
class Dogs
{
	friend int dogsCnt();

public:
	Dogs();
	~Dogs();

private:
	static int animalCount;

};

