/// Zbog jednostavnosti, citat ce specijalne datoteke koje ne sadrze nista vise nego samo funkcije koje te zanimaju
///  - u svakom projektu nalazi se "FilesToParse" -> potrebna <- mapa koja sadrzi sve bitne datoteke
/// 
/// TRENUTACNO NE PODRZAVA TEKST ZADATAKA SA VISE LINIJSKIM KOMENTAROM!! /* */

#pragma once
#include <iostream>
#include <fstream>
#include <memory>

#include <sstream>
#include <string_view>
#include <optional>
#include <vector>
#include <string>
#include <stack>
#include <list>

#include "../_Includes/json.hpp"

/// Zapisi u datoteku "Functions.cpp": ° DODAJ_FUNKCIJU( imeNamespace, imeZadatka); °
/// koja ce se izvrsit u funkciji prilikom pokretanja programa
/// ako se velicina funkcija i popisa funkcija ne slazu, IZADI

/// Zapisi sve informacije o zadacima u JSON datoteku


struct Zadatak
{
	std::string tekst;
	std::string deklaracija;
	std::string kod; // tijelo funkcije
};


/*
std::ofstream& operator << ( std::ofstream& dat, const Zadatak& zad )
{
	dat << "TEKST ZADATKA: " << zad.tekst << '\n'
		<< "DEKLARACIJA: " << zad.deklaracija << '\n'
		<< "KOD:\n" << zad.kod << '\n';
	return dat;
}
*/

/// <summary>
///		Ova klasa je zaduzena za prelazak preko zeljenih datoteka i uzimanja informacija za pojedini zadatak.
/// </summary>
class ParseFile
{
public:
	//ParseFile( std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka );
	//ParseFile( std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka = "cpp" );
	//ParseFile( std::vector<std::string_view>& paths, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka );
	ParseFile( const std::string_view& path, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka = "cpp" );
	ParseFile() = delete;
	ParseFile( const ParseFile& ) = delete;
	ParseFile( ParseFile&& ) = default;
	ParseFile& operator=( const ParseFile& ) = delete;
	ParseFile&& operator= ( ParseFile&& ) = delete;
//////////////////////////////////////////////////////////
public:
	/// dohvati popunjene zadatke za JSON handler
	std::vector<Zadatak>&& getZadatke() { return std::move( m_zadaci ); }
	std::fstream& getDatoteku( size_t indexDatoteke ) { return m_datoteke[indexDatoteke]; }
/////////////////////////////////////////////////////////
public:
	/// citaj
	///  - nije potrebno reci za koji je projekt jer m_datoteka vec govori o kojem se projektu radi (po indexu)
	std::vector<Zadatak*> readFile( std::fstream& dat, const bool DEBUG_FLAG = false );
	//
	std::optional<size_t> getPositionOfFunction( std::fstream& dat, const char* imeFunkcije );
	void skipFuncBody( std::fstream& dat/*, std::streampos& brojPreskocenihLinija*/);
/////////////////////////////////////////////////////////
private:
	std::vector<std::fstream> m_datoteke;
	std::vector<std::string_view> m_paths;
	std::vector<Zadatak> m_zadaci;
};

