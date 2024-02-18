/// Zbog jednostavnosti, citat ce specijalne datoteke koje ne sadrze nista vise nego samo funkcije koje te zanimaju
///  - u svakom projektu nalazi se "FilesToParse" -> potrebna <- mapa koja sadrzi sve bitne datoteke
#pragma once
#include <iostream>
#include <fstream>

#include <vector>
#include <string_view>
#include <string>
#include <stack>

#include "../_Includes/json.hpp"

/// Zapisi u datoteku "Functions.cpp": � DODAJ_FUNKCIJU( imeNamespace, imeZadatka); �
/// koja ce se izvrsit u funkciji prilikom pokretanja programa
/// ako se velicina funkcija i popisa funkcija ne slazu, IZADI

/// Zapisi sve informacije o zadacima u JSON datoteku


static struct Zadatak
{
	std::string tekst;
	std::string povratniTip;
	std::string naziv;
	std::string podTipArgumenata;
	std::string argumenti;
	std::string kod; // tijelo funkcije
};

/// <summary>
///		Ova klasa je zaduzena za prelazak preko zeljenih datoteka i uzimanja informacija za pojedini zadatak.
/// </summary>
class ParseFile
{
public:
	//ParseFile( std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka );
	//ParseFile( std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka = "cpp" );
	//ParseFile( std::vector<std::string_view>& paths, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka );
	ParseFile( std::vector<std::string_view>& paths, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka = "cpp");
	ParseFile() = delete;
	ParseFile( const ParseFile& ) = delete;
	ParseFile( ParseFile&& ) = delete;
	ParseFile& operator=( const ParseFile& ) = delete;
	ParseFile&& operator= ( ParseFile&& ) = delete;
//////////////////////////////////////////////////////////
public:
	/// dohvati popunjene zadatke za JSON handler
	std::vector<Zadatak>&& getZadatke() { return std::move( m_zadaci ); }
/////////////////////////////////////////////////////////
private:
	/// citaj
	///  - nije potrebno reci za koji je projekt jer m_datoteka vec govori o kojem se projektu radi
	// pronadi pocetak funkcije
	// koristi listu da bi dobio tekst zadatka
	// procitaj deklaraciju
	// procitaj tijelo
	void readFiles();
	void readFile( std::ifstream& dat );

/////////////////////////////////////////////////////////
private:
	std::vector<std::ifstream> m_datoteke;
	std::vector<std::string_view> m_paths;
	std::vector<Zadatak> m_zadaci;
};

