#include "Dealer.h"
#include "Player.h"

void Dealer::dealCard(Player& player, Deck& deck)
{
	if (deck.deckSize() > 0)
	{
		player.addCard(deck.dealCard());
	}
}