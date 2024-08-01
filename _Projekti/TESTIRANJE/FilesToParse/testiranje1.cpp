#include <iostream>
#include "../../Master program/PotrebneDatotekeIDeklaracijeFunkcija.hpp"


auto trailingReturnFun1() -> int
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa int\n";
	return 1;
}


auto trailingReturnFun2() -> void
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa void\n";
}


auto TESTIRANJE1::trailingReturnFun1() -> int
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa int\n";
	return 1;
}


auto TESTIRANJE1::trailingReturnFun2() -> void
{
	std::cout << "\nFunkcija povratno tipa auto bez argumentskih parametara ima trailing return type tipa void\n";
}