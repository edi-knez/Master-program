#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include <cassert>
#include <memory>


class Poglavlje4
{
private:
	struct Student
	{
		Student( int id, int grade ) noexcept : m_id( id ), m_grade( grade ) {}
		int m_id;
		int m_grade;

	private:
		friend std::ostream& operator <<( std::ostream& os, const struct Student stud )
		{
			return ( os << "Student sa ID: " << stud.m_id << ", ima ocjenu: " << stud.m_grade << '\n' );
		}
	};
public:
	struct StudentRecord
	{
		StudentRecord( int id, int grade ) noexcept: studentInfo( id, grade ) {}
		~StudentRecord() noexcept { /* std::cout << "Dealociram: " << studentInfo << '\n'; */ if( next != nullptr ) delete next; }
		Student studentInfo;
		StudentRecord* next = nullptr;
	};
	//
public:
	struct myCharptr
	{
		myCharptr() : content{ nullptr } {}
		myCharptr( char numOfEl, const char* cstr )
		{
			content = new char[numOfEl + 1];
			init( numOfEl, strlen(cstr), cstr);
		}
		myCharptr( uint8_t len, const myCharptr& rhs )
		{
			if( this == &rhs )	return;
			len = std::max( len, rhs.getLength() );
			this->content = new char[len + 1];
			init( len, rhs );
		}
		myCharptr( const myCharptr& str1, const myCharptr& str2 )
		{
			int len = str1.getLength() + str2.getLength();
			this->content = new char[1 + len];
			init( len, str1 );
			for( int i = 1; i <= str2.getLength(); ++i )
				this->getContent()[i + str1.getLength()] = str2.getContent()[i];
		}
		myCharptr( const myCharptr& rhs )
		{
			if( this == &rhs )	return;
			this->content = new char[rhs[0] + 1];
			init( rhs );
		}
		myCharptr( myCharptr&& rhs ) noexcept
		{
			this->content = rhs.content;
			rhs.content = nullptr;
		}
		myCharptr& operator= ( const myCharptr& rhs )
		{
			if( this == &rhs )	return *this;
			if( this->content != nullptr )	delete this->content;
			this->content = new char[rhs[0] + 1];
			init( rhs );
			return *this;
		}
		myCharptr& operator= ( myCharptr&& rhs ) noexcept
		{
			if( this == &rhs )	return *this;
			if( this->content != nullptr )	delete this->content;
			this->content = rhs.content;
			rhs.content = nullptr;
			return *this;
		}
		~myCharptr() { if( content )	delete[] content; }

		void init( const myCharptr& string )
		{
			if( string.getContent() == nullptr )	content[0] = 0;
			else								init( string[0], string.getLength(), string.content + 1 );
		}
		void init( uint8_t len, const myCharptr& string )
		{
			if( string.getContent() == nullptr )	content[0] = len;
			else								init( len, string.getLength(), string.content + 1);
		}
		void init( char numOfEl, char oldSize, const char* cstr )
		{
			content[0] = numOfEl;

			for( int i = 1; i <= oldSize; ++i )
			{
				content[i] = cstr[i - 1];
			}
		}
		//void reserve(char places)
		//{
		//	myCharptr tmp = std::move(*this);
		//	this->reset();
		//	this->content = new char[places + 1];
		//	for (int i = 0; i <= this->getLength(); ++i)
		//		this->content[i] = tmp.content[i];
		//}
		const char* getContent() const { return content; }
		char* getContent() { return content; }
		uint8_t getLength() const { if( content != nullptr ) { return content[0]; } else { return 0; } }
		// sets content to nullptr
		void reset() { content = nullptr; }
		// deletes content then sets it to nullptr
		void reset( int ) { if( content != nullptr ) { delete[] content; } content = nullptr; }
	private:
		char* content = nullptr;

		char operator[] ( int idx ) const { assert( idx >= 0 );  return content[idx]; }
		friend std::ostream& operator<<( std::ostream& os, const myCharptr& string )
		{
			if( string.getLength() > 0 )
				for( int i = 1; i <= string[0]; ++i )
					os << string[i];
			return os;
		}
		////friend std::istream& operator<<(std::istream& is, myCharptr& string)
		////{
		////	for (int i = 1; i < string[0]; ++i)
		////		is >> i;

		////	return is;
		////}
	};

public:
	void append( const char*& cstr, char ch );
	void concatenate( const char*& cstr, const char* cstrDodaj );
	char* characterAt( const char* cstr, uint8_t poz );
	//
	void addRecord( StudentRecord*& sRec, Student stud );
	float averageRecord( StudentRecord* sRec );


public:
	void vj1_();
	const char* vj2_sub_string( const char* cstr, int startPos, int length );
	void vj3_replaceString( const char*& source, const char* target, const char* replaceText );
	void vj4_append( myCharptr& string, char ch );
	void vj4_concatenate( myCharptr& string, const myCharptr& cstrDodaj );
	// deletes content of store and replaces content with concatenated string
	void vj4_concatenate( myCharptr& store, const myCharptr& string, const myCharptr& dodajString );
	// deletes content of store and replaces content with concatenated string
	void vj4_concatenate( myCharptr& store, myCharptr& string, const char* dodajString );
	void vj4_concatenate( myCharptr& string, const char* cstrDodaj );
	char vj4_characterAt( const myCharptr& string, uint8_t poz );
	void vj5_remove_record( struct StudentRecord*& sRec, int kriterij, char mode );
	//namespace StringLinkedList // datoteka StrinkLinkedList.cpp
	//{
	//	void vj6_append(struct StringLLAdv& advNode, char slovo);
	//	char vj6_characterAt(const struct StringLLAdv& advNode, uint8_t pos);
	//	void vj7_concatenate(struct StringLLAdv& advNode, const struct StringLLAdv& advNode2);
	//	void vj8_rmvchar(struct StringLLAdv& advNode, uint8_t pos, uint8_t kolicina);
	// 	StringLLAdv vj9_intToList()
	//	void del(struct StringLLAdv& advNode);
	//	void del(struct StringLL* head);
	//};

private:
	std::unique_ptr<char> ch = std::make_unique<char>(2);
};

