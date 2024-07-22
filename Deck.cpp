#include "Deck.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

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
	//Tämä jakaa kortin jollekkin
	//Tuo on vanha kommennti
	// Todo Poista nämä kommentit
	std::random_device randomNumber;

	std::default_random_engine gen(randomNumber());
	std::uniform_int_distribution<> dis(0, deck_cards.size() - 1);

	int randomCardNumber = dis(gen);

	Card dealingCard = deck_cards.at(randomCardNumber);

	deck_cards.erase(deck_cards.begin() + randomCardNumber);
	return dealingCard;
}

void Deck::shuffleDeck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(deck_cards), std::end(deck_cards), rng);
}

void Deck::resetDeck()
{
	deck_cards.clear();

	for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
		for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
			deck_cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
		}
	}
}

//These are for testing
void Deck::showDeck()
{
	std::cout << "Cards in hand: " << deck_cards.size() << std::endl;
	int handaamount = 0;
	for (const auto& card : deck_cards) {
		std::cout << card.getCard() << std::endl;
		handaamount++;
	}
}

int Deck::deckSize()
{
	if (deck_cards.size() > 0)
	{
		return deck_cards.size();

	}
	else { return 0; }
}