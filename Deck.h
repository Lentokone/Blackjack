#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"

class Deck
{
private:
	std::vector<Card> deck_cards;
public:
	Deck();

	//Deals a card from the deck
	Card dealCard();
	
	//Shuffles the deck
	void shuffleDeck();

	//Resets the deck
	void resetDeck();

	//These are for testing
	//Shows what cards are in the deck
	void showDeck();
	//Writes deck size into console
	int deckSize();
};
//Reset deck
//shuffle deck

#endif // !DECK_H