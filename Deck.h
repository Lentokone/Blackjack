#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"

class Deck
{
private:
	// Vector for all the cards in a deck.
	std::vector<Card> deck_cards;
public:
	// Constructor for a deck object.
	Deck();

	// Deals a card from the deck.
	Card dealCard();
	
	// Shuffles the deck.
	void shuffleDeck();

	// Resets the deck.
	void resetDeck();
	
	/*
	////This is for testing

	//Shows what cards are in the deck
	void showDeck();
	*/
	
	// Returns size of deck.
	int deckSize();
};
#endif // !DECK_H