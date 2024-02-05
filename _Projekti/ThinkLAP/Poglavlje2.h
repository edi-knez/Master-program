#pragma once
#include <iostream>
#include <assert.h>
#include <array>
#include <tuple>
#include <deque>

namespace Extra
{
	enum class Baza : uint8_t
	{
		BIN = 0,
		DEK = 8,
		HEX = 14
	};
	enum class BazaExtended : uint8_t
	{
		BIN = 0,
		TRI = 1,
		CET = 2,
		PET,
		SES,
		SED,
		OCT,
		DEV,
		DEK,
		JED,
		DST,
		TST,
		CST,
		PST,
		HEX,
		OFFSET = 2
	};
};

class Poglavlje2
{
public:
	void printSidewaysTriangle() const;
	void printSidewaysTriangleRec( int iter = 0 ) const;
	void luhnFormulaPrecomputed() const;
	void luhnFormulaExpression() const;
	int doubleDigitValue( int digit ) const;
	void luhnFormulaRjesenje() const;
	std::tuple<int32_t, bool> extract_number() const;
	void decodeMessage() const;
	void decodeMessageRjesenje() const;


//? VJEZBE
	void vj1() const;
	void vj2() const;
	void vj2_version2() const;
	void vj3() const;
	void vj5_check() const;
	void vj5_generate() const;
	int vj6_bin_to_dec() const;
	void vj6_ispisi_bin( int/*64_t*/ broj ) const;
	int vj6_dec_to_bin() const;
	int vj7_bin_to_dec( int broj ) const;
	int vj7_dec_to_bin( int broj ) const;
	int vj7_hex_to_bin( int broj ) const noexcept;
	int vj7_bin_to_hex( int broj ) const noexcept;
	void vj7_ispisi_hex( int broj ) const;
	void vj7_pretvorba_sa_hex() const;
	void vj8_pretvorba_sve_baze() const;
	void vj8_unos( Extra::BazaExtended& bI, int& broj, Extra::BazaExtended& bO ) const;
	void vj8_ispisi_sa_bazom( Extra::BazaExtended bO, uint8_t broj ) const;
	int vj8_otherBase_to_dec( int broj ) const;
	void vj9_unos_string_info( const std::string_view str ) const;

};