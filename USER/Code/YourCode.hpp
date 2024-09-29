#pragma once
#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <unordered_map>

#include <chrono>

#include <thread>
#include <Windows.h>

#include "../../Master program/ParseFile.hpp"

namespace Master
{
	void goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string& ), char& odabirProjekta, std::string& odabirCjeline, std::string& odabirFunkcije, char& stage );
	void goToTheWantedFunctionAndThen( std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>>& spremnikFunkcijaPoCjelinama, void( *executeThis )( const char, const std::string&, const std::string& ) );

	extern std::vector<std::string> popisProjekata;
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisImenaFunkcijaPoCjelinama;
	extern std::vector<std::unordered_map<std::string, std::unordered_map<std::string, std::pair<Zadatak, size_t>>>> popisFiltriranihImenaFunkcijaPoCjelinama;
	extern std::vector<std::vector<void ( * )( )>> popisFunkcija;
}


///  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static inline void korakIzvrsavanjaFunkcije( const char odabirProjekta, const std::string& odabirCjeline, const std::string& odabirFunkcije );

namespace USER
{
	void executableCode();
}
