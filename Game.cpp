#include <iostream>
#include "Game.h"
#include <string>

Game::Game() : deck(), dealer(deck), gameState(false), playerTurn(true)
{
	//initializeGame();
}

void Game::initializeGame()
{
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
	std::cout << "\nYou get " << player.showCardAtIndex(player.getHandSize()) << std::endl;

	dealer.dealCard(player, deck);
	std::cout << "\nYou get " << player.showCardAtIndex(player.getHandSize()) << std::endl;
	
	dealer.dealCard(dealer, deck);
	std::cout << "\nThe dealer gets " << dealer.showCardAtIndex(dealer.getHandSize()) << std::endl;

	dealer.dealCard(dealer, deck);
	std::cout << "The dealer places their second card face down\n" << std::endl;
	
}

void Game::gameMenu()
{
	bool menuState = true;
	std::string userInput = "";

	while (menuState)
	{
		std::cout << "Main menu" << std::endl;
		std::cout << "---------" << std::endl;
		std::cout << "[1] Play game\n[2] Look at previous games\n[q] Quit" << std::endl;
		std::cin >> userInput;
		if (userInput == "q")
		{
			menuState = false;
		}
		else
		{
			int intInput = stoi(userInput);
			switch (intInput)
			{
			case 1:
				//if (gameState == false) { gameState = true; }
				initializeGame();
				gameFlow();
				break;
			case 2:	//Tästä ehkä mieluummin seuraava menu jossa voi valita show history, clear history, back
				std::cout << std::endl;
				std::cout << "[1] Show history\n[2] Clear history\n[3] Go back" << std::endl;
				std::cin >> userInput;
				switch (stoi(userInput))
				{
				case 1:
					showGameHistory();
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

void Game::gameFlow()
{
	std::string input = "";
	bool currentGameState = true;

	while (gameState)
	{
		if (currentGameState == 1)
		{
			if (player.getHandValue() >= 21)
			{
				checkGameScore();
				currentGameState = false;
			}
			else
			{
				std::cout << "[1] hit.\n" << "[2] stand.\n" << "[3] show score.\n" << "[q] = quit. " << std::endl;
				std::cin >> input;
				if (input == "q")
				{
					gameState = false;
				}
				else if (input == "1")
				{
					dealer.dealCard(player, deck);
					std::cout << "You get " << player.showCardAtIndex(player.getHandSize()) << "\n" << std::endl;
					if (player.getHandValue() >= 21)
					{
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
					showScore();
					
					std::cout << std::endl;
				}
			}
		}
		else 
		{
			std::cout << "Do you want to play again(1) or quit?(2)" << std::endl;
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

void Game::showScore()
{
	Card dealerFirstCard = dealer.getCardAtIndex(0);
	std::cout << "Your hand value is " << player.getHandValue() << " Points" << std::endl;
	std::cout << std::endl;
	if (playerTurn)
	{
		std::cout << "The dealer's hand value is " << dealerFirstCard.getRankValue() << "\nAnd they have a hidden card" << std::endl;
	}
	else
	{
		std::cout << "The dealer's hand value is " << dealer.getHandValue() << std::endl;
	}
}

void Game::checkGameScore()
{
    GameResult matchResult;
    int dealerScore = dealer.getHandValue();
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

    // Save the game result
    gameHistory.push_back(matchResult);
    
    showScore();
}

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