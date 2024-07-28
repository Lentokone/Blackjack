#include <iostream>
#include "../src/Dealer.h"
#include "../src/Player.h"

Dealer::Dealer()
{
	deck = new Deck(); // Dynamically allocate a new Deck.
    deck->shuffleDeck();
}

// Deals a card to a given player from a given deck.
void Dealer::dealCard(Player& player, Deck& deck)
{
	//If the deck is not empty.
	if (deck.deckSize() > 0)
	{
		//Deals a card to the given player.
		player.addCard(deck.dealCard());
	}
}