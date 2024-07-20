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
// Todo Tänne funktio checkPoints tai vastaava
// Todo siellä on input check jos löytyy ace hand vectorista