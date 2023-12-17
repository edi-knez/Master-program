#include "ShareFileInterface.hpp"


bool ShareFileInterface::getStanjeDatoteke()
{
	return ( ShareFile1::used() || ShareFile2_::used() );
}
