#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
public:
	//Enumeration for the suits of a card
	enum Suit { Hearts = 1, Diamonds, Clubs, Spades };
	
	//Enumeration for the ranks of a card
	enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

private:
	Suit suit;	// The suit of a card
	Rank rank;	// The rank of a card

public:
	//Constructor for initializing Card object with a Suit and Rank
	Card(Suit s, Rank r) : suit(s), rank(r) {}

	//Returns what suit the card is.For example Diamonds
	std::string getSuit() const;

	//Returns what rank the card is. For example Five. Returns it in string for printing it
	std::string getRank() const;

	//Returns what value the rank is. For example Two of Spades returns int 2 and Jack of Spades returns 10. Jack, Queen and King returns 10 and Ace returns 11
	int getRankValue() const;

	//Returns what suit and rank the card is. For example Ace of Diamonds
	std::string getCard() const;
};


#endif // !CARD_H