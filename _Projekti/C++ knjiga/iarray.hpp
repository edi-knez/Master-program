#pragma once

/// <summary>
///		Ova klasa sluzi za koristenje integer niza sa dinamickom alokacijom memorije
/// 
///		Implementirani su default, parametizirani, copy konstruktor i destruktor
///		Implemetirani su overloaud operatori = , += , [] 
/// </summary>

const int def_iarray_size = 5;

class iarray
{
public:
	iarray( int def_size = 5 ) {
		init( (const int*)0, def_size );	// [[BUG]] nemoze default konstruirat niz sa velicinom 5 elemenata jer nije alocirao memoriju gdje ce ih spremit
		//init(nullptr, def_size);
	}

	iarray( const iarray& rhs ) {
		init( rhs.m_arr, rhs.m_size );
	}

	iarray( const int* array, int size ) {
		init( array, size );
	}

	~iarray( void ) {
		delete[] m_arr;
	}

	iarray& operator= ( const iarray& rhs );
	iarray& operator+= ( const int& size );
	int size() { return m_size; }
	int& operator[] ( int index )				{ return m_arr[index]; }	// za pisanje na ne-konst objektima
	const int& operator[] ( int index ) const { return m_arr[index]; }	// za konst objekte i citanje

private:
	void init( const int* array, int size );
	int* m_arr;
	int m_size;

};


