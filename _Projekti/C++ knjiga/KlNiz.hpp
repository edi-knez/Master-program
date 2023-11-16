#pragma once

/// <summary>
///		Ova klasa sluzi za racunanje suma niza
/// 
///		Niz moze biti default vrijednosti i kopiran sa drugog pointera	
/// 
///		Sadrzi pointer iA koji ce sadrzavat niz i overloaudan operator[] koji sluzi za pristup elementima niza
/// </summary>
class KlNiz {
public:
    KlNiz();
    ~KlNiz();
    int sumaNiza();
    int sumaNiza(int iA[]);

public:
    int operator[](int idx);


private:
    int* iA;
};