#pragma once
#include "Checkbook.hpp"

#include <iostream>
#include <exception>
#include <array>
class Checkbook;
class Queue : public Checkbook
{

public:
	int get();
	std::array<int, 10> get10();
};

