#pragma once
#include "ShareFileInterface.hpp"
//#include "ShareFile1.hpp"

#include <fstream>
#include <iostream>


class ShareFile2_
{
	friend class ShareFileInterface;
	friend bool is_using_file1( const int );
public:
	ShareFile2_()
	{
		m_datoteka.open( "Datoteka.dat", std::ios::out );
	}
	~ShareFile2_() { m_datoteka.close(); }

public:
	void otvori_datoteku();
	void zatvori_datoteku() { if( ShareFile2_::used() )	m_datoteka.close(); }

private:
	static bool used() { return m_datoteka.is_open(); }

private:
	static std::fstream m_datoteka;
};
