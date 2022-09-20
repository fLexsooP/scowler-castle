// who: Chence Shi(cshi16)
// what: skowlers_castle
// why: project 3
// when: 12/03/2021


// includes go here
#include <iostream>
#include <stdexcept>

#include "castle.h"

#define WINDOWS true  

void clearScreen();
void clearInstream();
void isValidMove(char);
/*
g++ *.cpp -o skowlers_castle.exe
.\skowlers_castle.exe
*/
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Castle castle;
	char move;
	clearScreen();
	while (!castle.isDead() && !castle.isEscape())
	{
		std::cout << castle;
		std::cout << "Enter move [N,S,W,E,(P)ause,(C)arry wife]:";
		std::cin >> move;
		clearScreen();
		try
		{
			isValidMove(move);
			castle.move(move);
			castle.guardMove();
		}
		catch(const std::invalid_argument  e)
		{
			std::cout << "Invalid input. Please try again.\n";
			continue;
		}
		
	} 
	std::cout << castle;
	if(castle.isDead())
		std::cout << "\nYou died at the hands of a guard. Your wife is doomed!!\n";
	else if(castle.isEscape())
		std::cout << "\nYour wife is rescued. Congratulations!!\n";
	system("pause");
	return 0;
}

void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}

void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(INT_MAX, '\n');
}

void isValidMove(char move)
{
	move = toupper(move);
	switch (move)
	{
	case 'E':
	case 'W':
	case 'N':
	case 'S':
	case 'P':
	case 'C':
		break;
	default:
		throw std::invalid_argument("Invalid Input, please try again.");
	}
}