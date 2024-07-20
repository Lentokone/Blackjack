#include "Card.h"
#include <iostream>

using namespace std;


std::string Card::getSuit() const
{
    switch (suit) {
    case Hearts: return "Hearts";
    case Diamonds: return "Diamonds";
    case Clubs: return "Clubs";
    case Spades: return "Spades";
    default: return "Unknown";
    }
}

std::string Card::getRank() const
{
    switch (rank) {
    case Two: return "Two";
    case Three: return "Three";
    case Four: return "Four";
    case Five: return "Five";
    case Six: return "Six";
    case Seven: return "Seven";
    case Eight: return "Eight";
    case Nine: return "Nine";
    case Ten: return "Ten";
    case Jack: return "Jack";
    case Queen: return "Queen";
    case King: return "King";
    case Ace: return "Ace";
    default: return "Unknown";
    }
}

std::string Card::getCard() const
{
    return Card::getRank() + " of " + Card::getSuit();
}