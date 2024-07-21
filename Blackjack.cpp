// Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//! Ei varmaan tarvi selitt‰‰

// ! perkele
// Todo Luokat
// ! Ajattelin card, deck, ehk‰ game, character, player, dealer

//

// ! Hello helbert.
// ? Ace on 11, mutta jos hand value yli 21 niin ace on 1


//Todo Poista nuo kommentit, ne ovat vanhat t. Olli 22/07/ 1:17

#include <iostream>
#include <stdio.h>
#include <string>

#include "Player.h"
#include "Dealer.h"
#include "Card.h"

#include <vector>

using namespace std;


int main()
{
    Player bob;
    Card kortt(Card::Clubs, Card::Five);

    bob.addCard(Card(Card::Hearts, Card::Four));
    bob.addCard(Card(Card::Diamonds, Card::Three));
    bob.addCard(Card(Card::Clubs, Card::Three));
    bob.addCard(Card(Card::Spades, Card::Ace));

    bob.addCard(kortt);
    bob.showHand();

    
    vector<Card> apina;
    Card monkey(Card::Clubs, Card::Three);
    apina.push_back(monkey);

    for (const auto& card : apina) {
        std::cout << card.getCard() << std::endl;
    }
    cout << "Teesmaili" << endl;
    Card& kakka = apina.at(0);
    apina.erase(apina.begin());
    cout << kakka.getCard() << endl;
    int suitInput, rankInput;
    cin >> suitInput;
    cin >> rankInput;
    Card::Suit suit = static_cast<Card::Suit>(suitInput);
    Card::Rank rank = static_cast<Card::Rank>(rankInput);

    // Create Card object
    Card card(suit, rank);
    cout << card.getRank() + " of " + card.getSuit() << endl;
    Deck test;
    Dealer jakaja(test);
    jakaja.showHand();
    Card gege(Card::Clubs, Card::Ace);
    cout << gege.getRank() << endl;

    
    cout << bob.getHandValue() << endl;
    Deck uuRR;
    uuRR.showDeck();
    Dealer kalle(uuRR);
    kalle.addCard(Card(Card::Spades, Card::Ace));
    kalle.showHand();
    Player paavo;
    kalle.dealCard(paavo, uuRR);
    kalle.dealCard(paavo, uuRR);
    kalle.dealCard(paavo, uuRR);
    paavo.showHand();
    uuRR.showDeck();
    kalle.dealCard(kalle, uuRR);
    kalle.showHand();
    
    cout << endl;
    cout << "Apina testaus" << endl;
    uuRR.showDeck();
    cout << "Apina testaus" << endl;
    uuRR.shuffleDeck();
    cout << "Apina testaus" << endl;
    uuRR.showDeck();
    cout << "Apina testaus" << endl;
    uuRR.resetDeck();
    uuRR.showDeck();
    cout << "Apina testaus" << endl;
    while (uuRR.deckSize() > 0)
    {
        kalle.dealCard(kalle, uuRR);
    }
    cout << endl;
    cout << "Kallen k‰si" << endl;
    cout << endl;
    kalle.showHand();
    cout << endl;
    cout << endl;
    uuRR.showDeck();
    kalle.dealCard(kalle, uuRR);
    uuRR.showDeck();
}