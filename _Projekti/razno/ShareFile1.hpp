#pragma once
#include "ShareFileInterface.hpp"
#include "ShareFile2_.hpp"

#include <fstream>
#include <iostream>


class ShareFile1
{
	friend class ShareFileInterface;
public:
	ShareFile1()
	{
		m_datoteka.open( "Datoteka.dat", std::ios::out );
	}
	~ShareFile1() = default;

public:
	void otvori_datoteku();
	void zatvori_datoteku() { if( ShareFile1::used() )	 m_datoteka.close(); }


private:
	static bool used() { return m_datoteka.is_open(); }

private:
	static std::fstream m_datoteka;

private:
	friend bool is_using_file1();
	friend bool f_is_using_file();
};
