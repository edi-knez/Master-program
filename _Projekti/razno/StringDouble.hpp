#pragma once
#include <string>
#include <iostream>


class StringDouble
{
public:
	StringDouble( std::string& br ) : m_broj( br ) { m_broj.reserve( 32 ); }
	StringDouble( std::string&& br ) : m_broj( std::move( br ) ) { m_broj.reserve( 32 ); }

public:
	friend StringDouble operator+ ( const StringDouble&, const StringDouble& );
	friend StringDouble operator- ( const StringDouble&, const StringDouble& );
	friend StringDouble operator* ( const StringDouble&, const StringDouble& );
	friend StringDouble operator/ ( const StringDouble&, const StringDouble& );

	friend std::ostream& operator<< ( std::ostream&, const StringDouble& );

private:
	std::string m_broj;
};

