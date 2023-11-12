#pragma once
#include "Mail_label.hpp"

class List
{
public:
	List() = default;
	List( Mail_label content, List* next = nullptr ) : m_content( content ), m_next( next ) {}

public:
	const Mail_label& getContent() const { return m_content; }

public:
	List* getNext() const		{ return m_next; }
	void setNext( List& l )		{ m_next = &l; }
	List* gotoNext()			{ return this->m_next; }

public:
	void insert( List*& elem ); // insert (after)

	static void sortByID( List* head )			{ sort( head, uint8_t{ 0 } ); }
	static void sortByFrom( List* head )		{ sort( head, uint8_t{ 1 } ); }
	static void sortByTo( List* head )			{ sort( head, uint8_t{ 2 } ); }
	static void sortByStreet( List* head )		{ sort( head, uint8_t{ 3 } ); }
	static void sortByState( List* head )		{ sort( head, uint8_t{ 4 } ); }

private:
	static void sort( List* head, uint8_t choice );

private:
	Mail_label m_content;
	List* m_next;
};


inline void List::insert( List*& elem )
{
	elem->setNext( *this->getNext() );	// this = objekt koji zove funkciju
	this->setNext( *elem );
}

inline void List::sort( List* head, uint8_t choice )
{
	List* current = head;

	for( ; current->getNext() != nullptr; current = current->gotoNext() ) // idi do prezadnjeg elementa, jer ce zadnji bit automatski sortiran
	{
		List* smallest = current;
		for ( List* elem = current->getNext(); elem != nullptr; elem = elem->gotoNext() )	// prodi kroz cijelu listu
		{
			if( smallest->getContent().getData( choice ) > elem->getContent().getData( choice ) )	// pronadi najmanjeg po podatku koji se sortira
				smallest = elem;
		}
		if( current->getContent().getData( choice ) > smallest->getContent().getData( choice ) )
		{
			// swap pointers
			const List temp = *current;
			List* const smallNext = smallest->getNext();
			*current = *smallest;
			*smallest = temp;
			current->setNext( *temp.getNext() );
			smallest->setNext( *smallNext );
		}
	}
}