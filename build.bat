@echo off
REM Compile the project
g++ -std=c++14 -o Blackjack Blackjack.cpp Deck.cpp Card.cpp Game.cpp Player.cpp Dealer.cpp

REM Check if the compilation was successful
if %errorlevel% equ 0 (
    echo Build successful. Executable 'Blackjack' created.
) else (
    echo Build failed.
)
pause
