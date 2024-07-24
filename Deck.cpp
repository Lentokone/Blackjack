#include "Deck.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

//Constructor for deck object, that adds all the cards for each suit to the deck_cards vector.
Deck::Deck()
{
	for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
		for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
			deck_cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
		}
	}
}

Card Deck::dealCard()
{
	// Makes a random device.
	std::random_device randomNumber;

	// Uses the random device to seed the default random engine.
	std::default_random_engine gen(randomNumber());

	// This creates the range of the random number generation.
	std::uniform_int_distribution<> dis(0, deck_cards.size() - 1);

	// This generates a random number to the int variable.
	int randomCardNumber = dis(gen);

	// This grabs a card from the deck at the position of the randomCardNumber.
	Card dealingCard = deck_cards.at(randomCardNumber);

	// This removes the card from the deck, so there is no duplicates.
	deck_cards.erase(deck_cards.begin() + randomCardNumber);

	// Returns the dealt card.
	return dealingCard;
}

void Deck::shuffleDeck()
{
	// Creates a random number generator.
	auto rng = std::default_random_engine{};
	// Shuffles the deck with the random number generator.
	std::shuffle(std::begin(deck_cards), std::end(deck_cards), rng);
}

void Deck::resetDeck()
{
	// Clears the deck vector.
	deck_cards.clear();

	// Adds all the cards for each suit to the deck_cards vector.
	for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
		for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
			deck_cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
		}
	}
}

/*
//This is for testing

void Deck::showDeck()
{
	std::cout << "Cards in hand: " << deck_cards.size() << std::endl;
	int handaamount = 0;
	for (const auto& card : deck_cards) {
		std::cout << card.getCard() << std::endl;
		handaamount++;
	}
}
*/

int Deck::deckSize()
{
	// If the deck_cards is not empty.
	if (deck_cards.size() > 0)
	{
		// Return the size of deck_cards.
		return deck_cards.size();

	}
	// If deck_cards is empty, returns 0.
	else { return 0; }
}
