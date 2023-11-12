#pragma once
class Horses
{
	friend int horseCnt();

public:
	Horses() { ++animalCount; }
	~Horses() { --animalCount; }

private:
	static int animalCount;

};

