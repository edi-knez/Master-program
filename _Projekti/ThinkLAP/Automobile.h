#pragma once
#include <string>
#include <ctime>

class Automobile
{
public:
	Automobile() noexcept : m_modelYear( INT64_MIN ) {}
	Automobile( const std::string_view manufactureName, const std::string_view modelName, int modelYear ) :
		m_manufactureName( manufactureName ), m_modelName( modelName ), m_modelYear( modelYear )
	{}

public:
	void setManufactureName( const std::string& manufactureName )        { m_manufactureName = manufactureName; }
	void setModelName      ( const std::string_view modelName ) noexcept { m_modelName = modelName; }
	void setModelYear      ( const int modelYear ) noexcept              { m_modelYear = modelYear; }
	std::string_view getManufactureName() const noexcept                 { return m_manufactureName; }
	std::string_view getModelName() const noexcept                       { return m_modelName; }
	long long getModelYear() const noexcept                              { return m_modelYear; }
	////////////////////
	std::string getDescription() const
	{
		return std::string{ std::to_string( m_modelYear ) + " " + m_manufactureName + " " + m_modelName };
	}
	time_t getCarsAgeInYears() const noexcept
	{
		time_t now;
		struct tm nowLocal;
		now = time( nullptr );
		nowLocal = *localtime( &now );
		return  nowLocal.tm_year + 1900LL - m_modelYear;
	}

private:
	std::string m_manufactureName;
	std::string m_modelName;
	long long	m_modelYear;

};

