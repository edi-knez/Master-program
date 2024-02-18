#include "ParseFile.h"


/// UNIMPLEMENTED for now...
/*ParseFile::ParseFile(std::vector<std::string_view>& paths, std::vector<size_t>& pathIdx, std::vector<std::string>& imenaDatoteka, std::vector<std::string>& ekstenzijaDatoteka)
{
//	m_paths.emplace_back( paths );

	if( pathIdx.size() != imenaDatoteka.size() || pathIdx.size() != ekstenzijaDatoteka.size() || imenaDatoteka.size() != ekstenzijaDatoteka.size() )
	{
		std::cout << "Broj argumenata se ne podudaraju!\n";
		exit( EXIT_FAILURE );
	}

	for( size_t idx = 0; idx < pathIdx.size(); ++idx )
	{
		if( pathIdx[idx] < 0 || pathIdx[idx] > paths.size() )
		{
			std::cout << "Nevazeci pathIdx!!\n";
			exit( EXIT_FAILURE );
		}
		std::string_view curPath = m_paths[pathIdx[idx]];
		std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka[idx];
	//	m_datoteke.emplace_back( std::fstream( curPath.data() + dat, std::ios::in ) );
		if( !m_datoteke[idx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << curPath << '/' << dat << '\n';
			exit( EXIT_FAILURE );
		}
	}
}
*/

ParseFile::ParseFile( std::vector<std::string_view>& paths, std::vector<std::string>& imenaDatoteka, const char* ekstenzijaDatoteka )
{
	if( paths.empty() )
	{
		std::cout << "UNESI LISTU PATHOVA!\n";
		exit( EXIT_FAILURE );
	}
	if( imenaDatoteka.empty() )
	{
		std::cout << "UNESI LISTU DATOTEKA GDJE SE NALAZE ZELJENE FUNKCIJE!\n";
		exit( EXIT_FAILURE );
	}

	for( size_t idx = 0; idx < paths.size(); ++idx )
	{
		std::string_view curPath = m_paths[idx];
		std::string dat = imenaDatoteka[idx] + '.' + ekstenzijaDatoteka;
	//	m_datoteke.emplace_back( std::ifstream( curPath.data() + dat, std::ios::in ) );
		if( !m_datoteke[idx].is_open() )
		{
			std::cout << "Nisam otvorio datoteku: " << curPath << '\\' << dat << '\n';
			exit( EXIT_FAILURE );
		}
	}
}

void ParseFile::readFiles()
{
	for( const auto& pathToProject : m_paths )
	{
		for( auto& dat : m_datoteke )
		{
			readFile( dat );
		}
	}
}

void findStartOfAFunction( std::ifstream& dat );
void getKomentar( std::ifstream& dat );
void getDeclaration( std::ifstream& dat );
void getFuncBody( std::ifstream& dat);
void ParseFile::readFile( std::ifstream& dat )
{
	findStartOfAFunction( dat );
	getKomentar( dat );
	getDeclaration( dat );
	getFuncBody( dat );
//	bool endOfFile = false;
//	std::stack<int> st;
//	int pocetakDeklaracije;
//	while( !dat.eof() ){}

}

void findStartOfAFunction( std::ifstream& dat )
{
	char c;
	while( dat >> c )
	{

	}
}

void getKomentar( std::ifstream& dat )
{}
void getDeclaration( std::ifstream& dat )
{}
void getFuncBody( std::ifstream& dat )
{}