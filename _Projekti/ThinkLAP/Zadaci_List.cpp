#include "Zadaci_List.h"


static void ispisPocetneListe( const char* ime, const auto& pLista )
{
	std::puts( ime );
	const auto* pTemp = pLista.get();
	while( pTemp != nullptr )
	{
		std::cout << pTemp->getElement() << " ";
		pTemp = pTemp->getNext();
	}
	std::puts( "\n" );
}

int zad1_iterative( const List<int>* root );
int zad1_recursive( const List<int>* root );
void Zadaci_List::zad1( const std::array< int, 9>& brojevi )
{
	auto pLista{ std::make_unique<List<int>>( brojevi ) };
	ispisPocetneListe( "lista", pLista );

	std::puts( "iteration:" );
	int result = zad1_iterative( pLista.get() );
	std::cout << "Result: " << result << '\n';

	std::puts( "recursion:" );
	result = zad1_recursive( pLista.get() );
	std::cout << "Result: " << result << "\n\n";

}
static int zad1_iterative( const List<int>* root )
{
	size_t sum = 0;
	while( root != nullptr )
	{
		sum += ( root->getElement() > 0 ) * root->getElement();
		root = root->getNext();
	}
	return sum;
}
static int zad1_recursive( const List<int>* root )
{
	if( root == nullptr )	return 0;
	else					return zad1_iterative( root->getNext() ) + root->getElement();
}


void zad2_ispis( const int result, const char* ime );
size_t zad2_iterative( const List<char>* binStr );
size_t zad2_recursive( const List<char>* binStr );

void Zadaci_List::zad2( const std::array< char, 7>& binaryString )
{
	auto pLista{ std::make_unique<List<char>>( binaryString ) };

	ispisPocetneListe( "binaryStringLista", pLista );

	const int result1 = zad2_iterative( pLista.get() );
	std::puts( "Iterative:" );
	zad2_ispis( result1, "result1" );

	const int result1r = zad2_recursive( pLista.get() );
	std::puts( "\nRecursive:" );
	zad2_ispis( result1r, "result1r" );
}


static void zad2_ispis( const int result, const char* ime )
{
	std::cout << ime << " has "
		<< ( ( result <= 0 ) ? "no ON bits!\n\n" : ( ( result & 1 ) ? "odd parity\n\n" : "even parity\n\n" ) );
}
static size_t zad2_iterative( const List<char>* binStr )
{
	size_t times_1_appeard = 0;
	while( binStr != nullptr )
	{
		times_1_appeard += binStr->getElement() == '1';
		List<char>::gotoNext( binStr );
	}
	return times_1_appeard;
}
static size_t zad2_recursive( const List<char>* binStr )
{
	if( binStr == nullptr )	return 0;
	else					return zad2_recursive( binStr->getNext() ) + ( binStr->getElement() == '1' ) * binStr->getElement();
}



size_t zad3_iterative( const auto* lista, const int target );
size_t zad3_recursive( const auto* lista, const int target );
void zad3_ispis( const int target, const size_t numOfOccurances );
void Zadaci_List::zad3( const std::array<int, 8>& brojevi, const int target )
{
	auto pLista{ std::make_unique<List<int>>( brojevi ) };

	ispisPocetneListe( "lista", pLista );

	const int result1 = zad3_iterative( pLista.get(), target );
	std::puts( "Iterative:" );
	zad3_ispis( target, result1 );

	const int result1r = zad3_recursive( pLista.get(), target );
	std::puts( "\nRecursive:" );
	zad3_ispis( target, result1r );
}
static size_t zad3_iterative( const auto* lista, const int target )
{
	size_t timesAppeardInList = 0;
	while( lista != nullptr )
	{
		timesAppeardInList += lista->getElement() == target;
		List<int>::gotoNext( lista );
	}
	return timesAppeardInList;
}
static size_t zad3_recursive( const auto* lista, const int target )
{
	if( lista == nullptr )	return 0;
	else					return zad3_recursive( lista->getNext(), target ) + (lista->getElement() == target);
}
static void zad3_ispis( const int target, const size_t numOfOccurances )
{
	std::cout << "Number target: " << target << " has occured: " << numOfOccurances << " times.\n\n";
}
