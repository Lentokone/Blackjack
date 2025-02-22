#include "../src/Player.h"
#include <iostream>

void Player::addCard(const Card& card)
{
	// Adds the given card to hand vector.
	hand.push_back(card);
}

std::string Player::showCardAtIndex(int index)
{
	// Copies the card from hand vector at given index.
	Card& IndexCard = hand.at(index);
	// Returns the output from .getCard.
	// The output will be a string that contains the the suit and rank of the card.
	return IndexCard.getCard();
}

Card Player::getCardAtIndex(int index)
{
	// Copies the card from hand vector at given index.
	Card& IndexCard = hand.at(index);
	// Returns the card object.
	return IndexCard;
}

void Player::showHand() const
{
	std::cout << "Cards in hand: " << hand.size() << std::endl;
	std::cout << "---------------" << std::endl;
	
	// Prints out each card from hand.
	for (const auto& card : hand) {
		std::cout << "-" << card.getCard() << std::endl;
	}
}

// This is used outside of Player.cpp.
// It is used to return the last index of hand vector.
int Player::getHandLastIndex()
{
	int handLastIndex = static_cast<int>(hand.size() - 1);
	return handLastIndex;
}

int Player::getHandValue() const
{
	// int variable for total hand value.
	int handValue = 0;

	// int variable for ace's in hand
	int aceCount = 0;

	for (const auto& card : hand) {
		// Takes card object. Uses its getRankValue() function, which returns its value.
		// Adds the card value into the handValue variable.
		handValue += card.getRankValue();
		
		// If there is an ace in hand.
		if (card.getRank() == "Ace")
		{
			// ace count is incremented by 1.
			aceCount++;
		}
	}

	// If the hand value goes over 21 and the player has an ace.
	while (handValue > 21 && aceCount > 0) {
		// Changes the hand's ace value from 11 to 1.
		handValue -= 10;
		aceCount--;
	}

	// Return the total value of hand.
	return handValue;
}

void Player::clearHand()
{
	// Clears the hand vector.
	hand.clear();
}