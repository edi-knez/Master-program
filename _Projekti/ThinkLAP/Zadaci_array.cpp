#include "Zadaci_array.h"

void ispisPocetnogNiza( const char* ime, const auto& niz )
{
	std::puts( ime );
	for( const auto& el : niz )
		std::cout << el << " ";
	std::puts( "\n" );
}

int zad1_recursive( const auto& numbers, size_t index );
int zad1_iterative( const auto& numbers ) noexcept;
void Zadaci_array::zad1( const std::array<int, 9>& numbers )
{
	ispisPocetnogNiza( "brojevi", numbers );

	std::puts( "iteration:" );
	int result = zad1_iterative( numbers );
	std::cout << "Result: " << result << '\n';

	std::puts( "recursion:" );
	result = zad1_recursive( numbers, 0 );
	std::cout << "Result: " << result << "\n\n";
}

static int zad1_iterative( const auto& numbers ) noexcept
{
	int result = 0;
	for( const auto& number : numbers )
	{
		if( number > 0 )	result += number;
	}
	return result;
}
static int zad1_recursive( const auto& numbers, size_t index )
{
	if( index >= numbers.size() )
	{
		return 0;
	}
	else
	{
		return ( numbers.at( index ) > 0 ) * numbers.at( index ) + zad1_recursive( numbers, index + 1 );
	}
}

void zad2_ispis( const int result, const char* ime );
int zad2_iterative( const auto& binStr ) noexcept;
int zad2_recursive( const auto& binStr, size_t index );
void Zadaci_array::zad2( const std::array<char, 7>& binaryString )
{
	ispisPocetnogNiza( "binaryString", binaryString );

	const int result1 = zad2_iterative( binaryString );
	std::puts( "Iterative:" );
	zad2_ispis( result1, "result1" );

	const int result1r = zad2_recursive( binaryString, 0 );
	std::puts( "\nRecursive:" );
	zad2_ispis( result1r, "result1r" );
}

static void zad2_ispis( const int result, const char* ime )
{
	std::cout << ime << " has "
		<< ( ( result <= 0 ) ? "no ON bits!\n\n" : ( ( result & 1 ) ? "odd parity\n\n" : "even parity\n\n" ) );
}
static int zad2_iterative( const auto& binStr ) noexcept
{
	int numberOf_ON_bits = 0;
	for( const auto& bit : binStr )
		numberOf_ON_bits += bit == '1';
	return numberOf_ON_bits;
}
static int zad2_recursive( const auto& binStr, size_t index )
{
	if( index >= binStr.size() )	return 0;
	else	return zad2_recursive( binStr, index + 1 ) + ( binStr.at( index ) == '1' );
}

void zad3_ispis( const int target, const size_t numOfOccurances );
size_t zad3_iterative( const auto& brojevi, const int target );
size_t zad3_recursive( const auto& brojevi, const int target, size_t index );
//!
/// <summary>
/// Runs iterative and recursive versions of functions how many times a number appearded in array
/// </summary>
/// <param name="brojevi"> -the array</param>
/// <param name="target"> -the target</param>
void Zadaci_array::zad3( const std::array<int, 8>& brojevi, const int target )
{
	ispisPocetnogNiza( "brojevi", brojevi );

	std::puts( "Iterative:" );
	const size_t timesAppeard = zad3_iterative( brojevi, target );
	zad3_ispis( target, timesAppeard );

	std::puts( "Recursive:" );
	const size_t timesAppeardR = zad3_recursive( brojevi, target, brojevi.size() - 1 );
	zad3_ispis( target, timesAppeardR );
}

static void zad3_ispis( const int target, const size_t numOfOccurances )
{
	std::cout << "Number target: " << target << " has occured: " << numOfOccurances << " times.\n\n";
}
static size_t zad3_iterative( const auto& brojevi, const int target )
{
	size_t timesAppeard = 0;
	for( const auto& num : brojevi )
		timesAppeard += num == target;

	return timesAppeard;
}
static size_t zad3_recursive( const auto& brojevi, const int target, size_t index )
{
	if( index == 0 )	return brojevi[0] == target;
	else				return zad3_recursive( brojevi, target, index - 1 ) + ( brojevi.at( index ) == target );
}
