#ifndef DEALER_H
#define DEALER_H

#include "../src/Deck.h"
#include "../src/Player.h"
class Dealer :
    public Player
{
private:
    Deck* deck;

public:
    // Default constructor for dealer object.
    Dealer();

    // Constructor for a specific deck.
    Dealer(Deck& d) : deck(&d) {}

    // Deals a card to a given player from a given deck.
    void dealCard(Player& player, Deck& deck);
};

#endif // !DEALER_H