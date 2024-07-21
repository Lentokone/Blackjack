#ifndef DEALER_H
#define DEALER_H

#include "Deck.h"
#include "Player.h"
class Dealer :
    public Player
{
private:
    Deck& deck;

public:
    Dealer(Deck& d) : deck(d) {}

    void dealCard(Player& player, Deck& deck);    //Tälle annetaan tai saa player ja dealer classin hand vectorin, deck classin current cards ja antaa sieltä yhden kortin pelaajalle ja jakajalle
};

//! Dealer hand value alle 17 niin ottaa kortin
#endif // !DEALER_H

