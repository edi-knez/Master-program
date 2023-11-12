#pragma once
#include <iostream>
#include <array>
#include <memory>
#include <fstream>
///
#include "Poglavlje4.h"
#include "Student.h"
#include "Automobile.h"
#include "myCharPtr.h"

class Poglavlje5
{
public:
	void vj_studentRecords() const;


	//
public:
	StudentRecord* addRecord(const Student&, StudentRecords*& list) const;
	void addGradeToRecord(Ocjena& ocjena, StudentRecord* record) const;
	StudentRecords* recordWithNumber(int ID, StudentRecords* head) const;
	void removeRecord(int ID, StudentRecords*& list) const;
	//

public:
	void zad1_printCarInfo() const;
	void zad2_printCarsAge() const;
	void zad3i4_myCharPtr_class() const;
	void zad5_remove() const;
};

