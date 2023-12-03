#pragma once
#include <stdio.h>
#include <vcruntime_string.h>
#include <assert.h>

// nije dovrseno
template<typename T, size_t s>
class Niz_template
{

public:
	Niz_template() = delete;
	Niz_template( const T& niz2 ) : m_sz( niz2.size() ) { memcpy( m_niz, niz2, m_sz ); }
	Niz_template( size_t sz ) : m_sz( sz ) {}

public:
	T& operator=( T& toNiz ) = delete;

	T operator[]( size_t pos ) const { assert( pos >= 0 && pos < m_sz ); return m_niz[pos]; }
	T& operator[]( size_t pos ) { assert( pos >= 0 && pos < m_sz ); return m_niz[pos]; }
	bool operator == ( const T& niz2 ) const;

public:
	constexpr void fill( T el )
	{
		memset( m_niz, el, m_sz );
	}
	constexpr void fill( T el, size_t cnt )
	{
		if( cnt > m_niz.size() ) { return; }

		memset( m_niz, el, cnt );
	}
	size_t size() const { return m_niz.m_sz; }
	constexpr size_t memorySize() const { return m_niz[m_sz - 1] - m_niz; }

private:
	size_t m_sz = s;

public:
	T* m_niz;
};

template<typename T, size_t s>
bool Niz_template<T, s>::operator == ( const T& niz2 ) const {
	if( m_sz == niz2.m_sz )
		return !memcmp( m_niz, niz2, m_sz);
	return false;
}