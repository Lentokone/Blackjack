#include "Card.h"
#include <iostream>

using namespace std;

// Returns the suit  in a string.
// This function uses the card suit enum values and returns them in string.
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

// Returns the rank in a string.
// This function uses the card rank enum values and returns them in string.
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

// Returns the value of the card's rank in blackjack.
int Card::getRankValue() const
{
    switch (rank)
    {
    case Card::Jack:
    case Card::Queen:
    case Card::King:
        return 10;
        break;
    case Card::Ace:
        return 11;
        break;
    default:
        return static_cast<int>(rank);
    }
}

// Returns the rank and suit of the card in a string.
std::string Card::getCard() const
{
    return Card::getRank() + " of " + Card::getSuit();
}