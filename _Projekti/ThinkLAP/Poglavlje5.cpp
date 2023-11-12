#include "Poglavlje5.h"

//? --------------------------------------------->	VJEZBE	<--------------------------------------------
struct combineData
{
	Student student;
	Ocjena ocjena{ -1, -1 };
};
bool simulacijaUnesaPodataka( std::array<combineData, 10>& studenti, Poglavlje4::myCharptr&& imeDatoteke, const char* extenzija )
{
	Poglavlje4 pog4;
	Poglavlje4::myCharptr _imeDat{};
	pog4.vj4_concatenate( _imeDat, imeDatoteke, extenzija );
	const std::string_view naziv( _imeDat.getContent() + 1, _imeDat.getLength() );
	std::fstream datoteka( naziv.data(), std::ios::in );
	int ID;
	int grade;
	int datum;
	std::string name;
	size_t i;
	if( !datoteka.is_open() )	return false;
	// validacija, svi podaci moraju bit uneseni
	for( i = 0; datoteka >> ID >> grade >> datum >> name && i < studenti.size(); ++i )
	{
		studenti.at( i ).student.setID( ID );
		studenti.at( i ).ocjena.setGrade( grade );
		studenti.at( i ).ocjena.setDatum( datum );
		studenti.at( i ).student.setName( std::move( name ) );
	}
	return i < studenti.size();
}
void unesiPodatkeUMemoriju( std::array<combineData, 10>& studenti, StudentRecords*& sRecords )
{
	// unesi podatke iz prethodne funkcije u listu
	for( size_t i = 0; i < studenti.size(); ++i )
	{
		StudentRecord* dodaniStudent = append( studenti.at( i ).student, sRecords );
		append( studenti.at( i ).ocjena, dodaniStudent );
	}
}
void Poglavlje5::vj_studentRecords() const
{
	//// sRecords stavit unique_ptr, te umjesto promjene sRecords, stavi njegove pointere na sRecords->next
	//auto sRecords = std::make_unique<StudentRecords>();

	auto sRecords = new StudentRecords{};
	std::array<combineData, 10> studenti;
	if( simulacijaUnesaPodataka( studenti, std::move( Poglavlje4::myCharptr{ 12, "Student data" } ), ".dat" ) == true )		return;

	for( const auto& stud : studenti )
		std::cout << stud.student;

	unesiPodatkeUMemoriju( studenti, sRecords );
	StudentRecords::ispisiStudentRecords( sRecords ); // poziva ispisiStudentRecord
	////freeStudentRecordsMemory(sRecords);
	delete sRecords;
}

StudentRecord* Poglavlje5::addRecord( const Student& stud, StudentRecords*& list ) const
{
	return append( stud, list );
}

void Poglavlje5::addGradeToRecord( Ocjena& ocjena, StudentRecord* record ) const
{
	append( ocjena, record );
}

StudentRecords* Poglavlje5::recordWithNumber( int ID, StudentRecords* head ) const
{
	return StudentRecords::getStudentWithID( head, ID );
}

void Poglavlje5::removeRecord( int ID, StudentRecords*& list ) const
{
	StudentRecords* RecordToRemove = recordWithNumber( ID, list );
	if( RecordToRemove->data->getID() != ID )	return;
	if( RecordToRemove == list )
	{
		if( list->next == nullptr )
		{
			delete list->data;
		}
		else
		{
			list = list->next;
			RecordToRemove->next = nullptr;
			delete RecordToRemove;
		}
	}
	else
	{
		StudentRecords* tmp = RecordToRemove->next;
		RecordToRemove->next = tmp->next;
		tmp->next = nullptr;
		delete tmp;
	}
}


//? ----------------------------------------->	ZADACI	<---------------------------------------------------
Automobile setAuto()
{
	Automobile auto1;
	auto1.setModelYear( 2004 );
	auto1.setManufactureName( "Cherlovet" );
	auto1.setModelName( "Impala" );
	return auto1;
}
void Poglavlje5::zad1_printCarInfo() const
{
	Automobile auto1;
	std::cout << auto1.getModelYear() << " " << auto1.getManufactureName() << " " << auto1.getModelName() << "\n";
	auto1 = setAuto();
	std::cout << auto1.getModelYear() << " " << auto1.getManufactureName() << " " << auto1.getModelName() << "\n";
}

void Poglavlje5::zad2_printCarsAge() const
{
	Automobile auto1 = setAuto();
	std::cout << "Car is " << auto1.getCarsAgeInYears() << " years old\n";
}

////////////////////////

void testSuite()
{
	myCharptr string1( 12, (const uint8_t*) "Konstruktor!" ), string2( 14, (const uint8_t*) "Konstruktor2!a" );
	myCharptr::testContructor( string1, string2 );
	myCharptr string3( string1 );
	myCharptr::testCopyConstructor( string1, string3 );
	myCharptr string4( std::move( string2 ) );
	myCharptr::testMoveConstructor( string2, string4 );
	myCharptr::testCopyAssign( string1, string3 );
	myCharptr::testMoveAssign( string1, string3 );
	//
	myCharptr::testFunctionality( string1, string2, string3, string4 );
}
void Poglavlje5::zad3i4_myCharPtr_class() const
{
	testSuite();
}

void Poglavlje5::zad5_remove() const
{
	myCharptr string( 12, (const uint8_t*) "Konstruktor!" );
	std::cout << string << "\n| remove pos: 1, slova: 1\n\n";
	string.remove( 1, 1 );
	std::cout << string << "\n| remove pos: 2, slova: 3\n\n";
	string.remove( 2, 3 );
	std::cout << string << "\n| remove pos: 1, slova: 1\n\n";
	string.remove( 1, 1 );
	std::cout << string << "\n| remove pos: 2, slova: 3\n\n";
	string.remove( 2, 3 );
	std::cout << string << "\n| remove pos: 2, slova: 5\n\n";
	string.remove( 2, 5 );
	std::cout << string << '\n';
}

