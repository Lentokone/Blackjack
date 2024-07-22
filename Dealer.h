#ifndef DEALER_H
#define DEALER_H

#include "Deck.h"
#include "Player.h"
class Dealer :
    public Player
{
private:
    Deck* deck;

public:
    Dealer();

    Dealer(Deck& d) : deck(&d) {}

    //Deals a card to a given player from a given deck
    void dealCard(Player& player, Deck& deck);
};

#endif // !DEALER_H