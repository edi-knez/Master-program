#pragma once
#include "StringLL.h"

struct StringLLAdv
{
	StringLLAdv() : tail(nullptr), head{ 0, tail } {}
	StringLL* tail;
	StringLL head;
};
