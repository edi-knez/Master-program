#pragma once
#include "ShareFileInterface.hpp"
#include "ShareFile1.hpp"

#include <fstream>
#include <iostream>


class ShareFile2_
{
	friend class ShareFileInterface;
public:
	ShareFile2_()
	{
		std::fstream otvori("datoteka.dat", std::ios::out);
	}
	~ShareFile2_() { datoteka.close(); }

public:
	void otvori_datoteku();
	void zatvori_datoteku() { if( ShareFile2_::used() )	datoteka.close(); }


private:
	static std::fstream datoteka;

private:
	static bool used() { return datoteka.is_open(); }

private:
	friend bool is_using_file( const ShareFile2_& datoteka );
};
