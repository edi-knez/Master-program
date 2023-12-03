#pragma once
class Dogs
{
	friend int dogsCnt();

public:
	Dogs() { ++animalCount; }
	~Dogs() { --animalCount; }

private:
	static int animalCount;
};

