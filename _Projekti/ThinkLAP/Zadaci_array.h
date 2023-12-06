#pragma once

#include <iostream>
#include <array>

class Zadaci_array
{
public:
	static void zad1( const std::array<int, 9>& brojevi );
	static void zad2( const std::array<char, 7>& brojevi );
	static void zad3( const std::array<int, 8>& brojevi, const int target );

	static void test_zad1();
	static void test_zad2();
	static void test_zad3( const std::array<int, 8>& brojevi, const int target );
};
