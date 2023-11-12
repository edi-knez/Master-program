#pragma once

#include <iostream>


class Student
{
public:
	Student() noexcept = default;

public:
	bool				setID( int id ) noexcept
	{	if( id > 0 ) { m_studentID = id; return true; } else { return false; }	}
	int					getID()	const noexcept{ return m_studentID; }
	bool				setName( std::string_view name ) noexcept
	{ if( name != "" ) { m_name = name; return true; } else return false; }
	std::string_view	getName() const noexcept { return m_name; }

private:
	int m_studentID = -1;
	std::string m_name;

	friend std::ostream& operator <<( std::ostream& out, const Student& stud )
	{
		//
		out.setf( std::ios::left ); out.width( 17 );		out << "Student with ID:";
		out.width( 6 );									out << stud.m_studentID;
		//
		out.setf( std::ios::left ); out.width( 10 );		out << "is named:";
		out.width( 20 );									out << stud.m_name << '\n';

		//
		return out;
	}
};
struct Ocjena
{
	Ocjena() = default;
	Ocjena( int broj, int datum ) noexcept
		: broj( broj ), datum( datum ), next( nullptr )
	{}
	Ocjena( const Ocjena& ocjena, Ocjena* next ) noexcept : broj( ocjena.broj ), datum( ocjena.datum ), next( next )
	{}
	~Ocjena()
	{
		std::cout << "BRISEM: " << broj << "\n";
		if( next != nullptr )	delete next;
		next = nullptr;
	}
	Ocjena( const Ocjena& o ) = default;
	Ocjena( Ocjena&& o ) = default;
	Ocjena& operator=( const Ocjena& o ) = default;
	Ocjena& operator=( Ocjena&& o ) = default;
	//// prva 3 bita vrsta ocjene
	//// 14 bita za jedinicu
	//// 14 bita za deseticu
	//// int jed = (broj >> 3)
	int broj;
	// mjesec + dan * 100 + godina * 10000
	// pr 10.5.2000.
	// 20000 5 10
	// pr 10.10.2010.
	// 2010 10 10
	int datum;
	Ocjena* next;

	bool setGrade( int grade ) noexcept { if( grade >= 0 && grade <= 100 ) { broj = grade; return true; } else { broj = -1; return false; } }
	bool setDatum( int _datum ) noexcept
	{
		int godina = _datum;
		int& tmp = datum;
		const uint16_t dan = tmp % 100;
		tmp /= 100;
		const uint16_t mjesec = tmp % 100;
		godina /= 100;
		const bool ispravan = dan > 0 && dan < 32 && mjesec > 0 && mjesec < 13 && godina >= 2020;
		if( ispravan ) datum = _datum;
		return ispravan;
	}
	void ispisiDatum() const
	{
		int godina = datum;
		int& tmp = godina;
		const uint16_t dan = tmp % 100;
		tmp /= 100;
		const uint16_t mjesec = tmp % 100;
		godina /= 100;
		std::cout << dan << "." << mjesec << "." << godina << ".";
	}
};
struct StudentRecord
{
	StudentRecord( const Student& stud, Ocjena& ocjena ) :
		stud( stud ), next( &ocjena )
	{}
	StudentRecord( const Student& stud ) :
		stud( stud ), next( nullptr )
	{}
	~StudentRecord()
	{
		std::cout << "BRISEM StudentRecord...\n";
		if( next != nullptr )	delete next;
		next = nullptr;
	}

	Student stud;
	struct Ocjena* next;

	inline int getID() const { return stud.getID(); }
};

struct StudentRecords
{
	StudentRecords() = default;
	StudentRecords( struct StudentRecord& sRec, StudentRecords* node ) noexcept :
		data( &sRec ), next( node )
	{}
	~StudentRecords()
	{
		std::cout << "BRISEM: " << data->getID() << "\n";
		if( data != nullptr ) delete data;
		if( next != nullptr ) delete next;
		data = nullptr;
		next = nullptr;
	}

	struct StudentRecord* data = nullptr;
	struct StudentRecords* next = nullptr;

	static StudentRecords* getStudentWithID( StudentRecords* sRecords, int reqestedID )
	{
		StudentRecords* insertPlace = sRecords;
		if( sRecords->data != nullptr )
		{
			while( sRecords != nullptr && sRecords->data->getID() < reqestedID )
			{
				insertPlace = sRecords;
				sRecords = sRecords->next;
			}
		}

		return insertPlace;
	}
	static void ispisiStudentRecords( struct StudentRecords* head )
	{
		while( head != nullptr )
		{
			const StudentRecord* const trenutacniRecord = head->data;
			if( head->data != nullptr )
			{
				std::cout << "Student: " << trenutacniRecord->stud
					<< "ima ocjene:\n";
				Ocjena* trenutacnaOcjena = head->data->next;
				while( trenutacnaOcjena != nullptr )
				{
					std::cout << trenutacnaOcjena->broj << ", datuma: ";
					trenutacnaOcjena->ispisiDatum();
					std::cout << "\n";
					trenutacnaOcjena = trenutacnaOcjena->next;
				}
				std::cout << "\n\n";
			} else	std::cout << "ERROR\n";
			head = head->next;
		}
	}
};
////inline void freeStudentRecordsMemory(StudentRecords* head)
////{
////	StudentRecords* tmp = head;
////	while (head != nullptr)
////	{
////		delete head->data;
////		head = head->next;
////	}
////	delete tmp;
////}

inline StudentRecord* append( const Student& item, StudentRecords*& list )
{
	if( list->data == nullptr ) // lista prazna
	{
		list->data = new StudentRecord( item );
		return list->data;
	} else
	{
		StudentRecords* insertPlace = StudentRecords::getStudentWithID( list, item.getID() );
		if( list->data->getID() > item.getID() )
		{
			StudentRecord* noviRecord = new StudentRecord( item );
			StudentRecords* tmp = list;
			list = new StudentRecords( *noviRecord, tmp );
			return list->data;
		} else if( list->data->getID() == item.getID() )			return insertPlace->data;
		else
		{
			if( insertPlace->next == nullptr || insertPlace->next->data->getID() != item.getID() )
			{
				StudentRecord* noviRecord = new StudentRecord( item );
				StudentRecords* tmp = insertPlace->next;
				insertPlace->next = new StudentRecords( *noviRecord, tmp/*insertPlace->next*/ );
			}
			return insertPlace->next->data;
		}
	}
}
// return val:
// 1 - OK
// -1 - Ocjena not valid
// -2 - Student invalid
////int8_t append_anyOrder(Student& item, struct Ocjena& ocjena, StudentRecords* list)
////{
////	if (item.getID() <= 0)	return -2;
////	StudentRecords* insertPlace = list->getStudentWithID(list, item.getID());
////	if (list->data == nullptr) // lista prazna
////		list->data = new StudentRecord(item, ocjena);
////	else if(insertPlace->data->getID() == item.getID()) // student u bazi, samo dodaj ocjenu
////	{
////		append(ocjena, insertPlace->data);
////		return -(ocjena.broj < 0);
////	}
////	else // dodaj u bazu pa onda dodaj ocjenu
////	{
////		StudentRecord* noviRecord = new StudentRecord(item, ocjena);
////		if ( insertPlace->data->getID() < item.getID() && insertPlace->next == nullptr)	//ID je veci od svih u listi
////		{
////			insertPlace = new StudentRecords(*noviRecord, nullptr);
////		}
////		else
////		{
////			StudentRecords* tmp = new StudentRecords(*noviRecord, insertPlace->next);
////			insertPlace->next = tmp;
////			tmp = nullptr;
////		}
////		noviRecord = nullptr;
////	}
////}
// return val:
// 1 - OK
// -1 - Ocjena not valid
// -2 - Student invalid
////int8_t append_sorted(Student& item, struct Ocjena& ocjena, StudentRecords* list)
////{
////	if (item.getID() <= 0)	return -2;
////	StudentRecords* insertPlace = list->getStudentWithID(list, item.getID());
////	if (list->data == nullptr) // lista prazna
////		list->data = new StudentRecord(item, ocjena);
////	else if (insertPlace->data->getID() == item.getID())
////	{
////		append(ocjena, insertPlace->data);
////		return -(ocjena.broj < 0);
////	}
////	else
////	{
////		StudentRecord* noviRecord = new StudentRecord(item, ocjena);
////		if (insertPlace == nullptr)	//ID je veci od svih u listi
////		{
////			insertPlace = new StudentRecords(*noviRecord, nullptr);
////		}
////		else
////		{
////			StudentRecords* tmp = new StudentRecords(*noviRecord, insertPlace->next);
////			insertPlace->next = tmp;
////			tmp = nullptr;
////		}
////		noviRecord = nullptr;
////	}
////}

inline void append( Ocjena& ocjena, StudentRecord* sRec )
{
	if( ocjena.broj >= 0 && ocjena.broj <= 100 )
	{
		if( sRec->next == nullptr )	sRec->next = new Ocjena( ocjena, nullptr );
		else
		{
			Ocjena* tmp = sRec->next;
			sRec->next = new Ocjena( ocjena, tmp );
			return;
		}
	}
	ocjena.broj = -1;
}

