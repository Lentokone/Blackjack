#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
public:
	enum Suit { Hearts, Diamonds, Clubs, Spades };
	enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

private:
	Suit suit;
	Rank rank;

public:
	Card(Suit s, Rank r) : suit(s), rank(r) {}


	std::string getSuit() const;
	std::string getRank() const;


	std::string getCard() const;
};


#endif // !CARd_H