#pragma once

#include "infOsobi.hpp"

#include <fstream>
#include <iostream>


struct infOsobi;

class File_16C
{
public:
	File_16C() = default;
	File_16C( const File_16C& ) = delete;
	File_16C& operator= ( const File_16C& ) = delete;
	~File_16C() { if( osobe != nullptr )	delete[] osobe; }

	File_16C( const char* );
	const char* getName() { return m_name; }


	// Write a program that reads a file and counts the number of lines in it.
	int numOfLinesInFile();
	// Write a program  to copy a file, expanding all tabs to multiple spaces.
	void copy_file( const char*, const char* );
	void copy_file( const char* );
	// Write a program that reads a file containing a list of numbers and writes two
	//files, one with all the numbers divisible by 3 and another containing all the other numbers.
	void listOfNumbers( std::fstream& );
	// Write a program  that reads an ASCII file containing a list of numbers and writes a binary file containing the same list.
	bool ASCI_to_bin();
	// Write a program that goes the other way so you can check your work.
	void bin_to_ASCI();
	// ispisuje brojeve iz m_file
	void ispis();
	void ispis( std::fstream& datoteka );
	// Write a program that copies a file and removes all characters with the high bit -> set(((ch & 0x80) != 0)
	void removeHighBit();
	void unos( const unsigned char a[] ) { otvoriDatoteku(); m_file << a; }
	void izbrisiSadrzaj() { m_file.open( m_name, std::ios::out | std::ios::trunc ); }
	void vrati_datoteku_na_pocetak() { m_file.seekg( std::ios::beg ); }

	// Design a file format to store a person's name, address, and other information. Write a program to read this file and produce a set of mailing labels.
	// deklaracija
	void read_info_o_osobi();
	void ispis_osoba();
	struct infOsobi& getOsobe() { return *osobe; }

private:
	int calculate_num_osoba();
	
private:	// used internaly
	void otvoriDatoteku() { m_file.open( getName(), std::ios::out | std::ios::in | std::ios::app ); }

private:
	const char* m_name;
	std::fstream m_file;
	struct infOsobi* osobe = nullptr;
	int cnt = 0;

};

