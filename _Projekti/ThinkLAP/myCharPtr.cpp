#include "myCharPtr.h"

myCharptr::myCharptr()
	: content{ nullptr }
{}
myCharptr::myCharptr( uint8_t numOfEl, const uint8_t* cstr )
	: content{ new uint8_t[numOfEl + 1] }
{
	init( numOfEl, cstr );
}

myCharptr::myCharptr( uint8_t len, const myCharptr& rhs )
{
	if( this == &rhs )	return;
	len = std::max( len, rhs.getLength() );
	this->content = new uint8_t[len + 1];
	init( len, rhs );
}

myCharptr::myCharptr( const myCharptr& str1, const myCharptr& str2 )
{
	int len = str1.getLength() + str2.getLength();
	this->content = new uint8_t[1 + len];
	init( len, str1 );
	for( int i = 1; i <= str2.getLength(); ++i )
		this->getContent()[i + str1.getLength()] = str2.getContent()[i];
}

myCharptr::myCharptr( const myCharptr& rhs )
{
	if( this == &rhs )	return;
	this->content = new uint8_t[rhs.getLength() + 1];
	init( rhs );
}

myCharptr::myCharptr( myCharptr&& rhs ) noexcept
{
	this->content = rhs.content;
	rhs.content = nullptr;
}

myCharptr& myCharptr::operator= ( const myCharptr& rhs )
{
	if( this == &rhs )	return *this;
	if( this->content != nullptr )	delete this->content;
	this->content = new uint8_t[rhs.getLength() + 1];
	init( rhs );
	return *this;
}

myCharptr& myCharptr::operator= ( myCharptr&& rhs ) noexcept
{
	if( this == &rhs )	return *this;
	if( this->content != nullptr )	delete this->content;
	this->content = rhs.content;
	rhs.content = nullptr;
	return *this;
}

void myCharptr::init( const myCharptr& string )
{
	if( string.getContent() == nullptr )	content[0] = 0;
	else								init( string.getLength(), string.content + 1 );
}
void myCharptr::init( uint8_t len, const myCharptr& string )
{
	if( string.getContent() == nullptr )	content[0] = len;
	else								init( len, string.content + 1 );
}
void myCharptr::init( uint8_t numOfEl, const uint8_t* cstr )
{
	content[0] = numOfEl;
	if( cstr == nullptr ) return;
	for( int i = 1; i <= numOfEl; ++i )
	{
		content[i] = cstr[i - 1];
	}
}

uint8_t myCharptr::getLength() const { if( content != nullptr ) { return content[0]; } else { return 0; } }
// sets content to nullptr
void myCharptr::reset() { content = nullptr; }
// deletes content then sets it to nullptr
void myCharptr::reset( int ) { if( content != nullptr ) { delete[] content; } content = nullptr; }

////////////////////////
void myCharptr::append( uint8_t ch )
{
	uint8_t len;
	if( content == nullptr )	len = 1;
	else					len = getLength() + 1;
	myCharptr tmp( len, *this );
	tmp[len] = ch;
	reset( 1 );
	*this = std::move( tmp );
}

void myCharptr::concatenate( const myCharptr& dodajString )
{
	if( content == nullptr )
	{
		*this = dodajString;
	}
	else if( dodajString.getContent() == nullptr )	return;
	else
	{
		uint8_t lenStr1 = getLength();
		uint8_t lenStr2 = dodajString.getLength();

		myCharptr tmp;
		for( int i = 1; i <= lenStr1; ++i )
			tmp[i] = content[i];

		for( int i = 1; i < tmp.getLength(); ++i )
			tmp[i + lenStr1] = dodajString[i];
		reset( 1 );
		*this = std::move( tmp );
		tmp.reset();
	}
}

void myCharptr::concatenate( const char* cstrDodaj )
{
	if( cstrDodaj == nullptr )	return;
	uint8_t lenStr1 = getLength();
	uint8_t lenStr2 = strlen( cstrDodaj ) + ( content == nullptr );
	myCharptr tmp( lenStr1 + lenStr2 - 1ui8, content );
	for( int i = lenStr1 + 1; i <= tmp.getLength(); ++i )
		tmp[i] = cstrDodaj[i - 1];
	reset( 1 );
	*this = std::move( tmp );
}

myCharptr&& myCharptr::concatenate( const myCharptr& string, const myCharptr& dodajString )
{
	myCharptr store;
	if( string.getContent() == nullptr )
	{
		store = dodajString;
	}
	else if( dodajString.getContent() == nullptr ) { store = string; }
	else
	{
		const uint8_t lenStr1 = string.getLength();
		const uint8_t lenStr2 = dodajString.getLength();

		myCharptr tmp;
		for( size_t i = 1; i <= lenStr1; ++i )
			tmp[i] = string[i];

		for( size_t i = 1; i < tmp.getLength(); ++i )
			tmp[i + lenStr1] = dodajString[i];

		store = std::move( tmp );
	}
	return std::move( store );
}

myCharptr&& myCharptr::concatenate( myCharptr& string, const char* dodajString )
{
	uint8_t lenDodStr = static_cast<uint8_t>( strlen( dodajString ) ) + 1;
	if( string.getContent() == nullptr )
	{
		return std::move( myCharptr{ lenDodStr, reinterpret_cast<const uint8_t*>( dodajString ) } );
	}
	else if( dodajString == nullptr )
	{
		return std::move( string );
	}
	else
	{
		const uint8_t lenStr1 = string.getLength();

		myCharptr tmp( lenStr1 + lenDodStr, string );

		for( int i = lenDodStr; i > 0; --i )
			tmp[i + lenStr1] = dodajString[i - 1];

		return std::move( tmp );
	}
}

uint8_t myCharptr::characterAt( uint8_t pos ) const
{
	if( content == nullptr || pos == 0 || pos > getLength() )	return '\0';
	return content[pos];
}

void myCharptr::remove( char pos, char amount )
{
	if( content == nullptr || pos < 1 || pos > getLength() )	return;
	// every time character gets removed, actualAmount increases (for edge cases)
	char actualAmount = 0;
	// nothing to do while i < pos
	// from pos to end shift all characters amount x to left
	for( int i = pos, end = getLength() - amount;
		 i <= end;	// no need to copy garbage
		 ++i, actualAmount += actualAmount < amount )
		content[i] = content[i + amount];

	content[0] -= actualAmount;
}

//void myCharptr::testSuite()
//{
//	myCharptr string1(12, "Konstruktor!"), string2(14, "Konstruktor2!a");
//	testContructor(string1, string2);
//	myCharptr string3(string1);
//	testCopyConstructor(string1, string3);
//	myCharptr string4(std::move(string2));
//	testMoveConstructor(string2, string4);
//	testCopyAssign(string1, string3);
//	testMoveAssign(string1, string3);
//	//
//	testFunctionality(string1, string2, string3, string4);
//
//}
void myCharptr::testContructor( const myCharptr& string1, const myCharptr& string2 )
{
	std::cout << "string1: " << string1 << '\n';
	std::cout << "string2: " << string2 << '\n';
}
void myCharptr::testCopyConstructor( const myCharptr& string1, const myCharptr& string3 )
{
	std::cout << "string3(copy konstruktor string1): " << string3 << ", string1: " << string1 << '\n';
}
void myCharptr::testMoveConstructor( const myCharptr& string2, const myCharptr& string4 )
{
	std::cout << "string4(move konstruktor string2): " << string4 << ", string2(nakon move): " << string2 << '\n';
}

void myCharptr::testCopyAssign( myCharptr& string1, const myCharptr& string3 )
{
	string1 = string3;
	std::cout << "string1(nakon =string3): " << string1 << ", string3: " << string3 << '\n';
}
void myCharptr::testMoveAssign( myCharptr& string1, myCharptr& string3 )
{
	string3 = std::move( string1 );
	std::cout << "string3 mov =string1: " << string3 << ", string1: " << string1 << '\n';
}

//////
void myCharptr::testFunctionality( myCharptr& string1, myCharptr& string2, myCharptr& string3, myCharptr& string4 )
{
	testAppend( string1 );
	testConcatenate( string2 );
	testCharacterAt( string1, string2, string3, string4 );
}
void myCharptr::testAppend( myCharptr& string1 )
{
	string1.append( 'a' ); string1.append( 'p' ); string1.append( 'p' ); string1.append( 'e' ); string1.append( 'n' ); string1.append( 'd' );
}
void myCharptr::testConcatenate( myCharptr& string2 )
{
	string2.concatenate( "concatenate" );
}

void myCharptr::testCharacterAt( const myCharptr& string1, const myCharptr& string2, const myCharptr& string3, const myCharptr& string4 )
{
	uint8_t len = std::max( { string1.getLength(), string2.getLength(), string3.getLength(), string4.getLength() } );
	for( uint8_t i = 1; i <= len; ++i )
	{
		std::cout << string1[i] << '\t';
		std::cout << string2[i] << '\t';
		std::cout << string3[i] << '\t';
		std::cout << string4[i] << '\n';
	}
}

