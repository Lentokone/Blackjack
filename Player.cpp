#include "Player.h"
#include <iostream>


void Player::addCard(const Card& card)
{
	hand.push_back(card);
}

void Player::showHand() const
{
	std::cout << "Cards in hand: " << hand.size() << std::endl;
	int handaamount = 0;
	for (const auto& card : hand) {
		std::cout << card.getCard() << std::endl;
		handaamount++;
	}
	//std::cout << "Cards in hand: " << handaamount << endl;
}

int Player::getHandValue() const
{
	int handValue = 0;
	int aceCount = 0;
	for (const auto& card : hand) {
		handValue += card.getRankValue();
		if (card.getRank() == "Ace")
		{
			aceCount++;
		}
	}
	std::cout << handValue << std::endl;
	while (handValue > 21 && aceCount > 0) {
		handValue -= 10;
		aceCount--;
	}

	return handValue;
}
// Todo Tänne funktio checkPoints tai vastaava
// Todo siellä on input check jos löytyy ace hand vectorista