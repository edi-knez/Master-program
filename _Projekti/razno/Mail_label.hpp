#pragma once
#include <iostream>
#include <cstdint>
#include <array>

class Mail_label
{
public:
	Mail_label() = default;
	Mail_label( std::string id, std::string from, std::string to, std::string street, std::string state )
	{
		m_data = { {{id}, {from}, {to}, {street}, {state}} };
	}

public:
	friend std::ostream& operator<<( std::ostream& out, const Mail_label& mlab );
	friend std::istream& operator>>( std::istream& out, Mail_label& mlab );

public:
	std::string_view getData( uint8_t index ) const { return m_data[index]; }

private:
	std::array<std::string, 5> m_data;

};

