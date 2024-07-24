#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

class Player
{
private:
	//The player's cards in hand.
	std::vector<Card> hand;
public:
	//Function that adds a card to players hand.
	void addCard(const Card& card);

	//Shows what suite and rank a card is at that index.
	std::string showCardAtIndex(int index);

	//Returns a card object at that index.
	Card getCardAtIndex(int index);

	//Function to show how many cards player has and what they are.
	void showHand() const;
	
	//Returns the last index of the hand.
	int getHandLastIndex();

	//Function to get the point value of players hand.
	int getHandValue() const;

	//Clears the hand.
	void clearHand();
};


#endif // !PLAYER_H