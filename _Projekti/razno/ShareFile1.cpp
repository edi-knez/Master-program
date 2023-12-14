#include "ShareFile1.hpp"


//std::fstream ShareFile1::m_datoteka;


void ShareFile1::otvori_datoteku()
{
	if( ShareFileInterface::getStanjeDatoteke() )
	{
		std::cout << "Datoteka je vec otvorena!\n";
		return;
	}
	m_datoteka.open( "Datoteka.dat", std::ios::out );
}
