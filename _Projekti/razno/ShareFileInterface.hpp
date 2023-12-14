#pragma once
#include "ShareFile1.hpp"
#include "ShareFile2_.hpp"


class ShareFileInterface
{
public:
	static bool getStanjeDatoteke();

};

	////////////
bool f_is_using_file()
{
	return ShareFile1::used();
}