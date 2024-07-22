#include "Player.h"
#include <iostream>

void Player::addCard(const Card& card)
{
	hand.push_back(card);
}

std::string Player::showCardAtIndex(int index)
{
	Card& IndexCard = hand.at(index);
	return IndexCard.getCard();
}

Card Player::getCardAtIndex(int index)
{
	Card& IndexCard = hand.at(index);
	return IndexCard;
}

void Player::showHand() const
{
	std::cout << "Cards in hand: " << hand.size() << std::endl;
	std::cout << "---------------" << std::endl;
	int handaamount = 0;
	for (const auto& card : hand) {
		std::cout << "-" << card.getCard() << std::endl;
		handaamount++;
	}
	//std::cout << "Cards in hand: " << handaamount << endl;
}

int Player::getHandSize()
{
	return hand.size() - 1;
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

	while (handValue > 21 && aceCount > 0) {
		handValue -= 10;
		aceCount--;
	}

	return handValue;
}

void Player::clearHand()
{
	hand.clear();
}
// Todo Tänne funktio checkPoints tai vastaava
// Todo siellä on input check jos löytyy ace hand vectorista