#include <iostream>
#include "Dealer.h"
#include "Player.h"

Dealer::Dealer()
{
	deck = new Deck(); // Dynamically allocate a new Deck
    deck->shuffleDeck();
}


void Dealer::dealCard(Player& player, Deck& deck)
{
	//If the deck is not empty
	if (deck.deckSize() > 0)
	{
		//Deals a card to the given player
		player.addCard(deck.dealCard());
	}
}