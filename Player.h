#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

class Player
{
private:
	//Parempi olisi olla vain lista jonne laittaa noita kortteja

	//The player's cards in hand
	std::vector<Card> hand;

public:
	//Function that adds a card to players hand
	void addCard(const Card& card);

	//Function to show how many cards player has and what they are
	void showHand() const;
	
	//Function to get the point value of players hand
	int getHandValue() const;
};


#endif // !PLAYER_H