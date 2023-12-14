#include "ShareFileInterface.hpp"


bool ShareFileInterface::getStanjeDatoteke()
{
	return ( f_is_using_file() || ShareFile2_::used() );
}
