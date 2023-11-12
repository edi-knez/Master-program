#pragma once
class Pigs
{
	friend int pigsCnt();

public:
	Pigs() { ++animalCount; }
	~Pigs() { --animalCount; }

private:
	static int animalCount;

};

