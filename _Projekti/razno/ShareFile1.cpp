#include "ShareFile1.hpp"


std::fstream ShareFile1::datoteka;


void ShareFile1::otvori_datoteku()
{
	if( ShareFileInterface::getStanjeDatoteke() )
	{
		std::cout << "Datoteka je vec otvorena!\n";
		return;
	}
	datoteka.open( "Datoteka.dat", std::ios::out );
}
