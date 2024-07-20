#include "Player.h"
#include <iostream>

using namespace std;

void Player::addCard(const Card& card)
{
	hand.push_back(card);
}

void Player::showHand() const
{
	for (const auto& card : hand) {
		std::cout << card.getCard() << std::endl;
	}
}
// Todo T�nne funktio checkPoints tai vastaava
// Todo siell� on input check jos l�ytyy ace hand vectorista