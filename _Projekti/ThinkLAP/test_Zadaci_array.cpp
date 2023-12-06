#include "Zadaci_array.h"

int zad1_recursive( const auto& numbers, size_t index );
int zad1_iterative( const auto& numbers ) noexcept;
void Zadaci_array::test_zad1()
{
	static constexpr std::array numbers = { 1, 5, -4, 100, -54, 0 , 5, -54, 100 };
	std::puts( "iteration:" );
	int result = zad1_iterative( numbers );
	std::cout << "Result: " << result << '\n';

	std::puts( "recursion:" );
	result = zad1_recursive( numbers, 0 );
	std::cout << "Result: " << result << '\n';
}

int zad1_iterative( const auto& numbers ) noexcept
{
	int result = 0;
	for( const auto& number : numbers )
	{
		if( number > 0 )	result += number;
	}
	return result;
}
int zad1_recursive( const auto& numbers, size_t index )
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
void Zadaci_array::test_zad2()
{
	static constexpr std::array binaryString1{ '1', '1', '0', '0', '1', '0', '1' };
	static constexpr std::array binaryString2{ '1', '1', '1', '0', '1', '0', '1' };
	static constexpr std::array binaryString3{ '0', '0', '0', '0', '0', '0', '0' };
	const int result1 = zad2_iterative( binaryString1 );
	const int result2 = zad2_iterative( binaryString2 );
	const int result3 = zad2_iterative( binaryString3 );
	std::puts( "Iteratie:" );
	zad2_ispis( result1, "result1" );
	zad2_ispis( result2, "result2" );
	zad2_ispis( result3, "result3" );

	const int result1r = zad2_recursive( binaryString1, 0 );
	const int result2r = zad2_recursive( binaryString2, 0 );
	const int result3r = zad2_recursive( binaryString3, 0 );
	std::puts( "\nRecursive:" );
	zad2_ispis( result1r, "result1r" );
	zad2_ispis( result2r, "result2r" );
	zad2_ispis( result3r, "result3r" );
}

void zad2_ispis( const int result, const char* ime )
{
	std::cout << ime << " has "
		<< ( ( result <= 0 ) ? "no ON bits!\n" : ( ( result & 1 ) ? "odd parity\n" : "even parity\n" ) );
}
int zad2_iterative( const auto& binStr ) noexcept
{
	int numberOf_ON_bits = 0;
	for( const auto& bit : binStr )
		numberOf_ON_bits += bit == '1';
	return numberOf_ON_bits;
}
int zad2_recursive( const auto& binStr, size_t index )
{
	if( index >= binStr.size() )
		return 0;
	else
		return zad2_recursive( binStr, index + 1 ) + ( binStr.at( index ) == '1' );
}

void zad3_ispis( const int target, const size_t numOfOccurances );
size_t zad3_iterative( const auto& brojevi, const int target );
size_t zad3_recursive( const auto& brojevi, const int target, size_t index );

void Zadaci_array::test_zad3(const std::array<int, 8>& brojevi, const int target)
{
	std::puts( "Iterative:" );
	const size_t timesAppeard = zad3_iterative( brojevi, target );
	zad3_ispis( target, timesAppeard );

	std::puts( "Recursive:" );
	const size_t timesAppeardR = zad3_recursive( brojevi, target, brojevi.size() - 1 );
	zad3_ispis( target, timesAppeardR );
}

void zad3_ispis( const int target, const size_t numOfOccurances )
{
	std::cout << "Number target: " << target << " has occured: " << numOfOccurances << " times.\n";
}
size_t zad3_iterative( const auto& brojevi, const int target )
{
	size_t timesAppeard = 0;
	for( const auto& num : brojevi )
		timesAppeard += num == target;

	return timesAppeard;
}

size_t zad3_recursive( const auto& brojevi, const int target, size_t index )
{
	if( index == 0 )
		return brojevi[0] == target;
	else
		return zad3_recursive( brojevi, target, index - 1 ) + brojevi.at(index) == target;
}
