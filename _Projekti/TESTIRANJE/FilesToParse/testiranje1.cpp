#include <iostream>


auto testFun1() -> int
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa int\n";
	return 1;
}


auto testFun2() -> void
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa void\n";
}

namespace TESTIRANJE1
{
	int testFun1();
	void testFun2();
}

auto TESTIRANJE1::testFun1() -> int
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa int\n";
	return 1;
}


auto TESTIRANJE1::testFun2() -> void
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa void\n";
}