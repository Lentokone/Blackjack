@echo off
setlocal

rem Set the compiler and flags
set COMPILER=g++
set FLAGS=-std=c++17

rem Set the source files
set SOURCES=src\Blackjack.cpp src\Deck.cpp src\Card.cpp src\Game.cpp src\Player.cpp src\Dealer.cpp

rem Set the include directories
set INCLUDES=-Isrc -Ilib

rem Set the output directory and executable name
set OUTPUT_DIR=build
set OUTPUT_NAME=Blackjack.exe

rem Create the output directory if it doesn't exist
if not exist %OUTPUT_DIR% mkdir %OUTPUT_DIR%

rem Compile the project
%COMPILER% %FLAGS% %INCLUDES% %SOURCES% -o %OUTPUT_DIR%\%OUTPUT_NAME%

rem Check if the compilation was successful
if %errorlevel% equ 0 (
    echo Build successful. Executable '%OUTPUT_NAME%' created in build folder.
) else (
    echo Build failed.
)

endlocal
pause
