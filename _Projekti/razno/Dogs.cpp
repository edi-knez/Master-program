#include "Dogs.hpp"

int Dogs::animalCount = 0;

Dogs::Dogs() { Dogs::animalCount += 1; }

Dogs::~Dogs() { Dogs::animalCount -= 1; }