#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "json.hpp"

using json = nlohmann::json;

struct GameResult
{
	std::string outcome;
	int playerPoints = 0;
	int dealerPoints = 0;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(GameResult, outcome, playerPoints, dealerPoints)
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
	
	//Is the menu for the game.
	void gameMenu();

	//Is the flow of the game.
	void gameFlow();

	//Shows the score of the game.
	void showScore();

	//Checks the dealer's and player's score.
	void checkGameScore();

	//Tells total games played, game outcomes and how much points did the dealer and player have.
	void showGameHistory();

	//Saves the game history to "game_history.json".
	void saveGameHistory(const std::string& filename);

	//Loads the game history from "game_history.json".
	void loadGameHistory(const std::string& filename);

	//Clears the console.
	void clearConsole();
};


#endif // !GAME_H