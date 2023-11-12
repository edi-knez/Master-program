#include "FlashCards.hpp"

FlashCards::FlashCards( const single_card cards[], int n ) :
	m_brojKartica( n ), m_ukupanBrojKartica( n ), m_status( FlashCards::m_state_t::IZBORNIK )
{
	assert( n < MAX_KARTICA );
	for ( size_t i = 0; i < m_brojKartica; ++i )
		m_Fcards[i] = cards[i];

}

void FlashCards::pokreni_izbornik()
{
	while( m_status > m_state_t::IZADI )
	{
		prikazi_izbornik();
		std::string odabir;
		std::cin >> odabir;
		switch( odabir[0] )
		{
		case '1':
			pogadaj();
			break;
		case '2':

			break;
		case '3':
			break;
		}
		odabir.clear();
	}
}

void FlashCards::prikazi_izbornik()
{
	std::cout << "IZBORNIK:"
		<< "\n1) --- Pogadanje kartica"
		<< "\n2) --- Pregled kartica"
		<< "\n\n"
		;

	std::cout << "Moj odabir: ";
}

void FlashCards::izbornik()
{
	pokreni_izbornik();
}

void FlashCards::pogadaj()
{
	std::array<struct FlashCards::single_card, 50> cardsCopy = m_Fcards;
	size_t cards = cardsCopy.size();

	while( m_mojOdgovor != "\n" || !status() )
	{
		pitaj_unos( cardsCopy );

		if( check( m_mojOdgovor, cardsCopy[0].getAnswer() ) )
		{
			std::cout << "Tocno!!\n";
			remove_from_beginning( cardsCopy );
			--m_brojKartica;
		}
		else
		{
			std::cout << "Netocno!\n";
			single_card currentCard = cardsCopy[0];
			remove_from_beginning( cardsCopy );
			put_back( cardsCopy, currentCard );
		}
	}
}

inline bool FlashCards::status() const
{
	std::cout << "Tocno odgovorenih kartica: " << get_ukupan_broj_kartica() - get_broj_kartica() << " / " << get_ukupan_broj_kartica() << "\n\n";
	return get_broj_kartica() > 0;
}

void FlashCards::pitaj_unos( std::array<struct single_card, MAX_KARTICA>& cardsCopy )
{
	std::cout << "Upisi odgovor ili -1 za izlaz!\n";
	std::cout << "Opis rijeci:\n" << cardsCopy[0].getQuestion() << "\n";
	std::cout << "Odgovor: ";
	std::cin >> m_mojOdgovor;
}

inline bool FlashCards::check( const std::string_view myAnswer, const char* answer ) const
{
	return myAnswer == answer;
}

inline void FlashCards::remove_from_beginning( std::array<struct single_card, MAX_KARTICA>& cardsCopy )
{
	for( size_t i = 1; i < get_broj_kartica(); ++i )
		cardsCopy[i - 1] = cardsCopy[i];
}

inline void FlashCards::put_back( std::array<struct single_card, MAX_KARTICA>& cardsCopy, const struct single_card& card )
{
	cardsCopy[get_broj_kartica() - 1] = card;
}