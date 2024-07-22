#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"

struct GameResult
{
	std::string outcome;
	int playerPoints = 0;
	int dealerPoints = 0;
};

class Game
{
private:
	Deck deck;
	Player player;
	Dealer dealer;
	bool gameState;
	bool playerTurn;

	std::vector<GameResult> gameHistory;
public:
	Game();

	//Initializes the game, makes a deck, dealer and player object.
	void initializeGame();
	
	//Is the menu for the game
	void gameMenu();

	//Is the flow of the game
	void gameFlow();

	//Shows the score of the game
	void showScore();

	//Checks the dealer's and player's score.
	//! Parempi sanoitus tohon kommenttiin
	void checkGameScore();

	//Tells total games played, game outcomes and how much points did the dealer and player have.
	void showGameHistory();
};


#endif // !GAME_H