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
		std::fstream otvori( "datoteka.dat", std::ios::out );
	}
	~ShareFile1() = default;

public:
	void otvori_datoteku();
	void zatvori_datoteku() { if( ShareFile1::used() )	 datoteka.close(); }


private:
	static bool used() { return datoteka.is_open(); }

private:
	static std::fstream datoteka;

private:
	friend bool is_using_file( const ShareFile1& datoteka );
};
