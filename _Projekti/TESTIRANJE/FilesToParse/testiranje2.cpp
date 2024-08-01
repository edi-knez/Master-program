#include "..\..\Master program\PotrebneDatotekeIDeklaracijeFunkcija.hpp"
// TESTIRANJE VISE NIVOA NESTED KLASA -> FAILED
// stvara se error koji sprijecava kompilaciju "Function list.cpp" datoteke
// Ukoliko se funkcija ne oznaci kao static, izbacit ce error

///void Cjelina2::Krug::testViseNivoaNestedKlasa() { std::cout << "USPJEH"; }


// TESTIRANJE DEFINIRANJE NAMESPACEA U KLASI -> FAILED
// u funkciji se nemoze definirat namespacea (pokusaj zaobilazenja potrebe za oznacit sve funkcije u nest-anoj klasi kvalifikacijom static

///void Cjelina2::TESTIRANJE::testFunctionInNmsInsideAClass() { std::cout << "USPJEH"; }


// TESTIRANJE NEST-ANJE NAMESPACEA
void TESTIRANJE2::NESTED_NAMESPACE::testViseNivoaNamespacea() { std::cout << "\nUSPJEH\n"; }