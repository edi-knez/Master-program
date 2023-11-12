#include "PageFormatting.hpp"

void PageFormatting::open_file( const char* ime )
{
    file.open( ime , std::ios::app );
}

void PageFormatting::define_header( const char* header )
{
    if( stranica == 0 || trenutacnaStranica >= stranica ){}
    else
    {
        file << header << "\n\n";
        ++trenutacnaStranica;
        linija += 3;
    }
}

void PageFormatting::print_line( const char* line)
{
    if ( file.is_open() )
    {
        file << line << '\n';
        ++linija;
        if( linija == 24 )  page();
        trenutacnaStranica += trenutacnaStranica < stranica;
    }
}

void PageFormatting::page()
{
    if( file.is_open() )
    {
        for ( ; linija % 24 != 0; ++linija )
            file << '\n';

        ++stranica;
    }
}

void PageFormatting::close()
{
    if ( file.is_open() )
        file.close();
}
