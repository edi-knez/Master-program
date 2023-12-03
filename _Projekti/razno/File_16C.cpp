#include "File_16C.hpp"

File_16C::File_16C( const char* imeDatoteke ) : m_name( imeDatoteke ) { }

int File_16C::numOfLinesInFile()
{
	otvoriDatoteku();
	int num = 0;
	char c;
	while( ( c = static_cast<char>( m_file.get() ) ) != EOF )
		num += c == '\n';

	return num;
}

void File_16C::copy_file( const char* from, const char* to )
{
	std::ifstream f( from, std::ios::in | std::ios::beg );
	std::ofstream t( to, std::ios::out | std::ios::trunc );
	if( !f.is_open() || !t.is_open() )	return;

	char c;
	while( ( c = static_cast<char>( f.get() ) ) != EOF )
		t.put( c );
}

void File_16C::copy_file( const char* to )
{
	otvoriDatoteku();
	std::ofstream t( to, std::ios::out | std::ios::trunc );
	if( !t.is_open() || !this->m_file.is_open() )	return;

	char c;
	while( !m_file.eof() )
	{
		c = m_file.get();
		t.put( c );
	}
}

void File_16C::listOfNumbers( std::fstream& listaBrojeva )
{
	listaBrojeva.clear();
	listaBrojeva.seekg( std::ios::beg );
	std::ofstream list1( "djeljivi sa 3.dat", std::ios::out | std::ios::trunc );
	std::ofstream list2( "svi ostali.dat", std::ios::out | std::ios::trunc );
	if( !list1.is_open() || !list2.is_open() )	return;

	int broj;
	while( listaBrojeva >> broj )
	{
		if( broj % 3 == 0 )	list1 << broj << " ";
		else				list2 << broj << " ";
	}
}

bool File_16C::ASCI_to_bin()
{
	otvoriDatoteku();
	std::ofstream bin( "bin.dat", std::ios::out | std::ios::trunc | std::ios::binary );
	if( !bin.is_open() || !this->m_file.is_open() )	return false;

	for( int broj; m_file >> broj; )
		bin.write( reinterpret_cast<char*>( &broj ), sizeof( broj ) );

	// izbrisi sadrzaj datoteke
	std::ofstream( m_name, std::ios::out | std::ios::trunc );
	return true;
}

void File_16C::bin_to_ASCI()
{
	otvoriDatoteku();
	std::ifstream bin( "bin.dat", std::ios::in | std::ios::binary | std::ios::app );
	if( !bin.is_open() || !this->m_file.is_open() )	return;
	int broj;
	while( bin.read( reinterpret_cast<char*>( &broj ), sizeof( int ) ) )
	{
		m_file << broj;
	}
}

void File_16C::ispis()
{
	otvoriDatoteku();
	if( !m_file.is_open() )	return;

	for( int broj; m_file >> broj; )
		std::cout << broj << " ";
}

void File_16C::ispis( std::fstream& datoteka )
{
	for( int broj; datoteka >> broj; )
		std::cout << broj << " ";

	datoteka.seekg( std::ios::beg );
}

void File_16C::removeHighBit()
{
	otvoriDatoteku();
	std::ofstream copy( "m_file removed high bit copy.txt", std::ios::out, std::ios::trunc );
	if( !copy.is_open() || !m_file.is_open() )	return;

	for( short int c; ( c = m_file.get() ) != EOF; )
		copy << static_cast<unsigned char>( c & 0x7F ) << " ";

}

int File_16C::calculate_num_osoba()
{
	otvoriDatoteku();
	if( !m_file.is_open() )	return -1;

	int count = 0;
	long int ID = 0;
	std::string ime;
	std::string adresa;

	while( m_file >> ID >> ime >> adresa )
		++count;
	m_file.close();

	return count;
}

void File_16C::read_info_o_osobi()
{
	cnt = calculate_num_osoba();
	if( cnt > 0 )
	{
		otvoriDatoteku();
		if( !m_file.is_open() )		return;
		osobe = new infOsobi[cnt];

		for( int i = 0; i < cnt; ++i )
		{
			m_file >> osobe[i].m_ID;
			m_file >> osobe[i].m_name;
			m_file >> osobe[i].m_address;
		}
		delete[] osobe;
		osobe = nullptr;
	}
}

void File_16C::ispis_osoba()
{
	std::cout << "ID\tIme\t\tAdresa\n";
	for( int i = 0; i < cnt; ++i )
	{
		std::cout << osobe[i].getID() << "\t" << osobe[i].getName() << "\t\t" << osobe[i].getAddress() << "\n";
	}

}