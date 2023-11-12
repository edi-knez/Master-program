#pragma once
#include <iostream>
#include <memory>
#include <iomanip>
#include <array>
#include <algorithm>
#include <numeric>
#include <cstring>

struct student
{
	int studentID;
	int grade;
	std::string name;

	friend std::ostream& operator <<( std::ostream& out, const struct student& stud )
	{
		//
		out.setf( std::ios::left ); out.width( 17 );	out << "Student with ID:";
		out.width( 6 );									out << stud.studentID;
		//
		out.setf( std::ios::left ); out.width( 10 );	out << "is named:";
		out.width( 20 );								out << stud.name;
		//
		out.width( 15 );								out << "and has grade:";
														out << char( stud.grade ) << '\n';
//
		return out;
	}
};

class Poglavlje3
{
public:
	Poglavlje3() = default;
	Poglavlje3( const Poglavlje3& ) = default;
	Poglavlje3& operator=( const Poglavlje3& ) = default;

public:
	void highestSales_zadano();

public:
	void finding_the_mode();

public:
	void vj1_sorting();
	void vj2_median();
	bool vj3_issorted( std::array<int, 20> );
	std::unique_ptr<char[]> vj4_cipher_encode( std::string_view plainText );
	std::unique_ptr<char[]> vj5_cipher_decode( std::unique_ptr<char[]> cipherText );
	// 25%, 50%, 75%
	std::array<uint8_t, 3> vj8_grade_better_than();
	void vj9_modified_median();

};

