#pragma once
#include <iostream>


struct infOsobi
{
public:
	infOsobi() : m_name( "" ), m_address( "" ), m_ID( -1 ) {}
	infOsobi( std::string name, std::string address, long int ID ) : m_name( name ), m_address( address ), m_ID( ID ) {}

private:
	friend class File_16C;

private:
	std::string m_name;
	std::string m_address;
	long int m_ID;


public:
	const std::string& getName() { return m_name; }
	const std::string& getAddress() { return m_address; }
	const long int getID() { return m_ID; }

private:
	std::ostream& operator << ( std::ostream& out )
	{
		out << getName() << "\t" << getAddress() << "\t" << getID() << "\n";
		return out;
	}
	friend std::ostream& operator << ( std::ostream& out, struct infOsobi osoba )
	{
		out << osoba.getName() << "\t" << osoba.getAddress() << "\t" << osoba.getID() << "\n";
		return out;
	}
};
