#pragma once
#include <array>
#include <iostream>
#include <assert.h>

class FlashCards
{
public:
	struct single_card
	{
		friend class FlashCards;

	public:
		single_card() = default;
		~single_card() = default;
		single_card( const single_card& ) = default;
		single_card& operator= ( const single_card& ) = default;
		single_card( const char* q, const char* a ) : question( q ), answer( a ) {}

	private:
		const char* question;
		const char* answer;

	private:
		const char* getQuestion() const { return question; }
		const char* getAnswer() const { return answer; }
	};

#define MAX_KARTICA 50  // std::array sere ako koristim obican const

public:
	FlashCards( const FlashCards& ) = default;
	FlashCards& operator= ( const FlashCards& ) = default;
	~FlashCards() = default;

	FlashCards() = default;
	FlashCards( const single_card cards[], int n );


public:
	void izbornik();

private:
	size_t m_brojKartica;
	size_t m_ukupanBrojKartica;
	//const size_t MAX_KARTICA = 50;
	std::string m_mojOdgovor{};
	std::array<struct single_card, MAX_KARTICA> m_Fcards;

	enum class m_state_t
	{
		IZADI = -1,
		IZBORNIK,
		POGADAJ
	} m_status;

private:
	const size_t get_broj_kartica() const { return m_brojKartica; }
	const size_t get_ukupan_broj_kartica() const { return m_ukupanBrojKartica; }

private:
	void pokreni_izbornik();
	void prikazi_izbornik();
	void pregled_kartica();
	void pogadaj();

private:
	bool status() const;
	void pitaj_unos( std::array<struct single_card, MAX_KARTICA>& cardsCopy );
	bool check( const std::string_view myAnswer, const char* answer ) const;
	void remove_from_beginning( std::array<struct single_card, MAX_KARTICA>& cardsCopy );
	void put_back( std::array<struct single_card, MAX_KARTICA>& cardsCopy, const struct single_card& card );
};