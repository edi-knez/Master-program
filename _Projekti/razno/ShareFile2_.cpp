#include "ShareFile2_.hpp"



void ShareFile2_::otvori_datoteku()
{
	if( ShareFileInterface::getStanjeDatoteke() )
	{
		std::cout << "Datoteka je vec otvorena!\n";
		return;
	}
	m_datoteka.open( "Datoteka.dat", std::ios::out );
}