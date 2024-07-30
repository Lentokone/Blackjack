#include "../src/Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "../lib/json.hpp"

using json = nlohmann::json;

// Constructor for Game class
Game::Game() : deck(), dealer(deck), gameState(false), playerTurn(true)
{
	//initializeGame();
}

// Initializes the game state, shuffles the deck, and deals initial cards.
void Game::initializeGame()
{
	clearConsole();

	gameState = true;
	deck.resetDeck();
	deck.shuffleDeck();
	std::cout << "*-----------*" << std::endl;
	std::cout << "| Blackjack |" << std::endl;
	std::cout << "*-----------*" << std::endl;
	std::cout << std::endl;

	player.clearHand();
	dealer.clearHand();
	std::cout << "The dealer starts dealing cards" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	dealer.dealCard(player, deck);
	std::cout << "\nYou get " << player.showCardAtIndex(player.getHandLastIndex()) << std::endl;

	dealer.dealCard(player, deck);
	std::cout << "\nYou get " << player.showCardAtIndex(player.getHandLastIndex()) << std::endl;
	
	dealer.dealCard(dealer, deck);
	std::cout << "\nThe dealer gets " << dealer.showCardAtIndex(dealer.getHandLastIndex()) << std::endl;

	dealer.dealCard(dealer, deck);
	std::cout << "The dealer places their second card face down\n" << std::endl;
	playerTurn = true;
}

// Displays the game menu and handles user input.
void Game::gameMenu()
{
	bool menuState = true;
	char userInput;
	int uInputConverted;

	loadGameHistory("game_history.json");
	while (menuState)
	{
		std::cout << "Main menu" << std::endl;
		std::cout << "---------" << std::endl;
		std::cout << "[1] Play game\n[2] Look at previous games\n[q] Quit" << std::endl;
		std::cin >> userInput;
		if (userInput == 'q')
		{
			saveGameHistory("game_history.json");
			menuState = false;
		}
		else
		{
			// If the userInput is a digit, then it converts it to an int.
			if (isdigit(userInput))
			{
				uInputConverted = userInput - '0';
			}
			// Else it will default to a 0.
			else { uInputConverted = 0; }

			switch (uInputConverted)
			{
			case 1:
				initializeGame();
				gameFlow();
				break;
			case 2:	// This is a menu for showing the match history and to clear it.
				clearConsole();
				std::cout << "Game history" << std::endl;
				std::cout << "[1] Show history\n[2] Clear history\n[3] Go back" << std::endl;
				std::cin >> userInput;

				// If the userInput is a digit, then it converts it to an int.
				if (isdigit(userInput))
				{
					uInputConverted = userInput - '0';
				}
				// Else it will default to a 0.
				else { uInputConverted = 0; }

				switch (uInputConverted)
				{
				case 1:
					clearConsole();
					showGameHistory();
					std::cout << std::endl;
					break;
				case 2:
					gameHistory.clear();
					std::cout << "History has been cleared" << std::endl;
					break;
				case 3:
					break;
				default:
					break;
				}
				
				break;
			default:
				std::cout << "This only accepts 1, 2 and q as input" << std::endl;
				break;
			}
			
		}
	}
}

// Manages the main game flow, handling player's and dealer's turns.
void Game::gameFlow()
{
	std::string input = "";
	bool currentGameState = true;

	while (gameState)
	{
		if (currentGameState == true)
		{
			if (player.getHandValue() >= 21)
			{
				playerTurn = false;
				checkGameScore();
				currentGameState = false;
			}
			else
			{
				std::cout << "[1] hit.\n" << "[2] stand.\n" << "[3] show hand.\n" << "[q] Quit. " << std::endl;
				std::cin >> input;
				if (input == "q")
				{
					saveGameHistory("game_history.json");
					gameState = false;
				}
				else if (input == "1")
				{
					dealer.dealCard(player, deck);
					std::cout << "You get " << player.showCardAtIndex(player.getHandLastIndex()) << "\n" << std::endl;
					if (player.getHandValue() >= 21)
					{
						playerTurn = false;
						checkGameScore();
						currentGameState = false;
					}
				}
				else if (input == "2")
				{
					playerTurn = false;
					while (dealer.getHandValue() < 17)
					{
						dealer.dealCard(dealer, deck);
					}
					checkGameScore();
					currentGameState = false;
				}

				else if (input == "3")
				{
					player.showHand();
					showScore();
					
					std::cout << std::endl;
				}
			}
		}
		else 
		{
			std::cout << "---------" << std::endl;
			std::cout << "Game over\n---------\nDo you want to:\n[1] Play again\n[2] Quit" << std::endl;
			std::cin >> input;

			if (input == "1")
			{
				initializeGame();
				currentGameState = true;
			}
			else if (input == "2")
			{
				std::cout << "Quitting game" << std::endl;
				gameState = false;
			}
		}
	}
}

// Displays the current scores for the player and dealer.
void Game::showScore()
{
	//Gets thee first card of the dealer
	Card dealerFirstCard = dealer.getCardAtIndex(0);
	std::cout << "Your hand value is " << player.getHandValue() << " Points" << std::endl;
	std::cout << std::endl;

	//If it is the player's turn, the dealer's second card is hidden
	if (playerTurn)
	{
		std::cout << "The dealer's hand value is " << dealerFirstCard.getRankValue() << "\nAnd they have a hidden card" << std::endl;
	}
	//After the player's turn is over, the dealer then reveals his second card
	else
	{
		std::cout << "The dealer's hand value is " << dealer.getHandValue() << std::endl;
	}
}

// Evaluates and displays the result of the game, then saves the result to the game history.
void Game::checkGameScore()
{
    GameResult matchResult;
	// Gets the value of dealer's hand.
    int dealerScore = dealer.getHandValue();
	// Gets the value of player's hand.
    int playerScore = player.getHandValue();

    if (playerScore <= 21)
    {
        if (dealerScore <= 21)
        {
            if (playerScore == 21 && dealerScore == 21)
            {
                matchResult.outcome = "Stalemate, both have blackjack";
            }
            else if (playerScore == 21)
            {
                matchResult.outcome = "Player wins with a blackjack";
            }
            else if (dealerScore == 21)
            {
                matchResult.outcome = "Dealer wins with a blackjack";
            }
            else if (playerScore > dealerScore)
            {
                matchResult.outcome = "Player wins, by having more points";
            }
            else if (playerScore == dealerScore)
            {
                matchResult.outcome = "Stalemate, player and dealer have the same amount of points";
            }
            else
            {
                matchResult.outcome = "Dealer wins, by having more points";
            }
        }
        else
        {
            matchResult.outcome = "Player wins, dealer has bust.";
        }
    }
    else
    {
        matchResult.outcome = "Dealer wins, player has bust.";
    }
	std::cout << matchResult.outcome << std::endl;
    matchResult.playerPoints = playerScore;
    matchResult.dealerPoints = dealerScore;

    // Save the game result to gameHistory vector.
    gameHistory.push_back(matchResult);
    showScore();
}

// Displays the game history from previous sessions.
void Game::showGameHistory()
{
	if (gameHistory.empty()) {
		std::cout << "No previous games to show." << std::endl;
		return;
	}
	int gameCount = 0;
	std::cout << "Game History:" << std::endl;
	for (const auto& result : gameHistory) {
		gameCount++;
		std::cout << gameCount << ". " << "Outcome: " << result.outcome
			<< " | Player points: " << result.playerPoints
			<< " | Dealer points: " << result.dealerPoints << std::endl;
	}
}

// Saves the game history to a file in JSON format.
void Game::saveGameHistory(const std::string& filename) {
	// Takes the parent path of the current path and moves to /data/ folder and uses the file using the given filename as its name.
	std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "data" / filename;

	json j = gameHistory; // Converts gameHistory vector to JSON
	std::ofstream file(filePath);
	if (file.is_open()) {
		file << j.dump(4); // Saves JSON to a file with 4-space indentation
		file.close();
		std::cout << "Game history saved to " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file for writing" << std::endl;
	}
}

// Loads the game history from a file in JSON format.
void Game::loadGameHistory(const std::string& filename) {
	// Takes the parent path of the current path and moves to /data/ folder and uses the file using the given filename as its name.
	std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "data" / filename;

	json j;
	std::ifstream file(filePath);
	if (file.is_open()) {
		file >> j; // Reads JSON from a file
		file.close();
		gameHistory = j.get<std::vector<GameResult>>(); // Converts JSON to a gameHistory vector
		std::cout << "Game history loaded from " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file for reading" << std::endl;
	}
}

// Clears the console, platform-specific.
void Game::clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}