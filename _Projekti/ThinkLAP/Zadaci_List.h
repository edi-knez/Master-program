#pragma once
#include <iostream>
#include <memory>
#include <array>
#include <type_traits>


template <typename T>
class List
{
public:
	List() = default;
	explicit List<T>( const T el ) noexcept : m_element( el ) {}
	explicit List( const auto& niz ) /*requires std::is_same_v(std::vector | std::array)*/
	{
		List* pTemp = this;
		size_t idx = 0;
		for( ; idx < niz.size() - 1; ++idx )
		{
			pTemp->m_element = niz[idx];
			pTemp->m_next = std::make_unique< List >( List{} );
			pTemp = pTemp->getNext();

		}
		if( niz.size() > 0 )
		{
			pTemp->m_element = niz[idx];
			pTemp->m_next = nullptr;
		}
	}

	T getElement() const noexcept { return m_element; }
	List* getNext() const noexcept { return m_next.get(); }
	static void gotoNext( const List*& node )
	{
		if( node != nullptr )	node = node->getNext();
	}
private:
	T m_element{ -1 };
	std::unique_ptr< List > m_next{};
};


class Zadaci_List
{
public:
	static void zad1( const std::array< int, 9>& brojevi );
	static void zad2( const std::array< char, 7>& binaryString );
	static void zad3( const std::array<int, 8>& brojevi, int target );

};

