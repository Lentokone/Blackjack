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
	Card bob;
	hand = { bob };
public:
	void UURR();
	void kortit();
};


#endif // !PLAYER_H