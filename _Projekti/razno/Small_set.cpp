#include "Small_set.hpp"

void Small_set::set(int x) { m_set[x] = x; }

void Small_set::clear(int ind) { m_set[ind] = 0; }

int Small_set::test(int x) { return m_set[x] == x; }
