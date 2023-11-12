#pragma once
#include <cassert>
#include <algorithm>
#include <iostream>
#include <math.h>


class myCharptr
{
public:
	myCharptr();
	myCharptr( uint8_t numOfEl, const uint8_t* cstr );
	myCharptr( uint8_t len, const myCharptr& rhs );
	myCharptr( const myCharptr& str1, const myCharptr& str2 );
	myCharptr( const myCharptr& rhs );
	myCharptr( myCharptr&& rhs ) noexcept;
	myCharptr& operator= ( const myCharptr& rhs );
	myCharptr& operator= ( myCharptr&& rhs ) noexcept;
	~myCharptr() { if( content )	delete[] content; }
	//
	void init( const myCharptr& string );
	void init( uint8_t len, const myCharptr& string );
	void init( uint8_t numOfEl, const uint8_t* cstr );

//?----------------------------------------	nadogradnja, unutarnje stvari	-----------------------------------
public:
	const uint8_t* getContent() const noexcept { return content; }
	uint8_t* getContent() noexcept { return content; }
	uint8_t getLength() const;
	// sets content to nullptr
	void reset();
	// deletes content then sets it to nullptr
	void reset( int /*unused*/ );
	uint8_t operator[] ( int idx ) const
	{
		if( content == nullptr || idx < 0 || idx > getLength() )	return '\0';
		return content[idx];
	}

//?---------------------------------------	funkcije za zadatke	-------------------------------------------
public:
	void append( uint8_t ch );
	// concatenates 2 strings into this
	void concatenate( const myCharptr& dodajString );
	void concatenate( const char* cstrDodaj );
	// contatenates 2 strings into temporary
	static myCharptr&& concatenate( const myCharptr& string, const myCharptr& dodajString );
	static myCharptr&& concatenate( myCharptr& string, const char* dodajString );
	uint8_t characterAt( uint8_t pos ) const;
	//
	void remove( char pos, char amount );

////////////////////////
private:
	uint8_t* content;

//?---------------------------------------	input / output	-------------------------------------------
private:
	uint8_t& operator[] ( int idx ) { assert( idx >= 0 );  return content[idx]; }
	friend std::ostream& operator<<( std::ostream& os, const myCharptr& string )
	{
		if( string.getLength() > 0 )
			for( int i = 1; i <= string.getLength(); ++i )
				os << string[i];

		return os;
	}
	friend std::istream& operator>>( std::istream& is, myCharptr& string )
	{
		string[0] = static_cast<uint8_t>( is.get() );
		for( int i = 1; i <= string.getLength(); ++i )
			is >> string[i];

		return is;
	}

//!	---------------------------------------------		Tests	-----------------------------------------------
private:
	friend void testSuite();
	static void testContructor( const myCharptr& string1, const myCharptr& string2 );
	static void testCopyConstructor( const myCharptr& string1, const myCharptr& string3 );
	static void testMoveConstructor( const myCharptr& string2, const myCharptr& string4 );
	static void testCopyAssign( myCharptr& string1, const myCharptr& string3 );
	static void testMoveAssign( myCharptr& string1, myCharptr& string3 );
	static void testFunctionality( myCharptr& string1, myCharptr& string2, myCharptr& string3, myCharptr& string4 );
	static void testAppend( myCharptr& string1 );
	static void testConcatenate( myCharptr& string2 );
	static void testCharacterAt( const myCharptr& string1, const myCharptr& string2, const myCharptr& string3, const myCharptr& string4 );
};