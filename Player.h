#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

class Player
{
private:
	//Parempi olisi olla vain lista jonne laittaa noita kortteja

	//Tai käsi luokka jossa ne hommat
	std::vector<Card> hand;

public:
	void addCard(const Card& card);
	void showHand() const;
	

};


#endif // !PLAYER_H