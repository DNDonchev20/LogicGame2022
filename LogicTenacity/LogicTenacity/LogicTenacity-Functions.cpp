#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "LogicTenacity-Functions.h"
using namespace std;

//all cards
string cards[48];
string baseCardspOne[6];
string baseCardspTwo[6];

string firstRowpOne[5];
string firstRowpTwo[5];
string playerOne;
string playerTwo = "Bot's";
string playerOneWin;
string playerTwoWin;

//not cards
int notCardspOne = 4, notCardspTwo = 4;

int pOneChosenIndex = 0;
int pTwoChosenIndex = 0;

int pOneChosenCard = 0;
int pTwoChosenCard = 0;

//this bools decide who has the turn
bool playerOnTurn = true;

//this bool decide if you are playing with a bot or not
bool isBot = true;

//choise to place or to delete a card
string choise;

//players  
//gamemode 1
string pOne[6], pTwo[6];

string pOnePyramid[21], pTwoPyramid[21];


bool pOneWins = false, pTwoWins = false;

void allRendering();
void printOptionMenu();
void choiseF();
void botTurn();

//Player have to choose where to place the chosen card
void inputChosenIndex(int& playerChosenIndex)
{
	cout << "Select an index: ";
	cin >> playerChosenIndex;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Play have to choose what card to play
void inputChosenCard(int& playerChosenCard)
{
	cout << "Select a card: ";
	cin >> playerChosenCard;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (playerChosenCard < 1 || playerChosenCard > 5) {
		cout << "The card number is not correct! Please try again... " << endl;
		system("pause");

		system("cls");
		allRendering();

		cout << endl << "Select a card: ";
		cin >> playerChosenCard;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void deleteCardpOne(int& playerChosenCard)
{
	pOne[playerChosenCard - 1].erase(0);
	swap(pOne[playerChosenCard - 1], pOne[4]);
}

void deleteCardpTwo(int& playerChosenCard)
{
	pTwo[playerChosenCard - 1].erase(0);
	swap(pTwo[playerChosenCard - 1], pTwo[4]);
}


void deleteCard(int player, int& playerChosenCard)
{
	if (player == 1) {
		deleteCardpOne(playerChosenCard);
	}
	else {
		deleteCardpTwo(playerChosenCard);
	}
}

bool checkNotCardpOne(int forCheck, int checkCard1, int checkCard2)
{
	if (firstRowpOne[forCheck] == "1or")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (firstRowpOne[forCheck] == "1and")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (firstRowpOne[forCheck] == "1xor")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpOne[forCheck] == "0or")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpOne[forCheck] == "0and")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpOne[forCheck] == "0xor")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	return false;
}

bool checkNotCardpTwo(int forCheck, int checkCard1, int checkCard2)
{
	if (firstRowpTwo[forCheck] == "1or")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (firstRowpTwo[forCheck] == "1and")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (firstRowpTwo[forCheck] == "1xor")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpTwo[forCheck] == "0or")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpTwo[forCheck] == "0and")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (firstRowpTwo[forCheck] == "0xor")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	return false;
}

bool check(int playerChosenCard, int checkCard1, int checkCard2)
{

	playerChosenCard--;
	if (pOne[playerChosenCard] == "1or")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[
			checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (pOne[playerChosenCard] == "1and")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (pOne[playerChosenCard] == "1xor")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pOne[playerChosenCard] == "0or")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pOne[playerChosenCard] == "0and")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pOne[playerChosenCard] == "0xor")
	{
		if (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "0") || (pOnePyramid[checkCard1] == "0" && pOnePyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pOnePyramid[checkCard1] == "1" && pOnePyramid[checkCard2] == "1")
		{
			return true;
		}
	}

	return false;
}

bool checkpTwo(int playerChosenCard, int checkCard1, int checkCard2)
{

	playerChosenCard--;
	if (pTwo[playerChosenCard] == "1or")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (pTwo[playerChosenCard] == "1and")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}
	else if (pTwo[playerChosenCard] == "1xor")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return false;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pTwo[playerChosenCard] == "0or")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pTwo[playerChosenCard] == "0and")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return true;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return false;
		}
	}
	else if (pTwo[playerChosenCard] == "0xor")
	{
		if (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "0")
		{
			return true;
		}
		else if ((pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "0") || (pTwoPyramid[checkCard1] == "0" && pTwoPyramid[checkCard2] == "1"))
		{
			return false;
		}
		else if (pTwoPyramid[checkCard1] == "1" && pTwoPyramid[checkCard2] == "1")
		{
			return true;
		}
	}

	return false;
}

void playNotCardpOne(int playerChosenIndex)
{
	if (playerChosenIndex == 1)
	{
		if (checkNotCardpOne(playerChosenIndex - 1, playerChosenIndex - 1, playerChosenIndex))
		{
			cout << "";
		}
		else
		{
			pOnePyramid[playerChosenIndex + 5] = '-';
		}
	}
	else if (playerChosenIndex == 6)
	{
		if (checkNotCardpOne(playerChosenIndex - 1, playerChosenIndex - 2, playerChosenIndex - 1))
		{
			cout << "";
		}
		else
		{
			pOnePyramid[playerChosenIndex] = '-';
		}

	}
	else
	{

		if (checkNotCardpOne(playerChosenIndex - 1, playerChosenIndex - 1, playerChosenIndex))
		{
			cout << "";
		}
		else
		{
			pOnePyramid[playerChosenIndex + 6] = '-';
		}
		if (checkNotCardpOne(playerChosenIndex - 1, playerChosenIndex - 2, playerChosenIndex - 1))
		{
			cout << "";
		}
		else
		{
			pOnePyramid[playerChosenIndex + 5] = '-';
		}


	}
}

void playNotCardpTwo(int playerChosenIndex)
{
	if (playerChosenIndex == 1)
	{
		if (checkNotCardpTwo(playerChosenIndex + 5, playerChosenIndex - 1, playerChosenIndex))
		{
			cout << "";
		}
		else
		{
			pTwoPyramid[playerChosenIndex + 5] = '-';
		}
	}
	else if (playerChosenIndex == 6)
	{
		if (checkNotCardpTwo(playerChosenIndex + 5, playerChosenIndex - 2, playerChosenIndex - 1))
		{
			cout << "";
		}
		else
		{
			pTwoPyramid[playerChosenIndex + 5] = '-';
		}

	}
	else
	{

		if (checkNotCardpTwo(playerChosenIndex + 6, playerChosenIndex - 1, playerChosenIndex))
		{
			cout << "";
		}
		else
		{
			pTwoPyramid[playerChosenIndex + 6] = '-';
		}

		if (checkNotCardpTwo(playerChosenIndex + 5, playerChosenIndex - 2, playerChosenIndex - 1))
		{
			cout << "";
		}
		else
		{
			pTwoPyramid[playerChosenIndex + 5] = '-';
		}



	}
}

bool addCard(int playerChosenCard, int playerChosenIndex)
{
	if (pOnePyramid[playerChosenIndex + 5] != "-")
	{
		return false;
	}

	if (playerChosenIndex < 6)
	{
		if (pOnePyramid[playerChosenIndex - 1] == "-" || pOnePyramid[playerChosenIndex] == "-")
		{
			return false;
		}
		else
		{
			if (check(playerChosenCard, playerChosenIndex - 1, playerChosenIndex))
			{
				pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
				firstRowpOne[playerChosenIndex - 1] = pOne[playerChosenCard - 1];
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 10)
	{
		if (pOnePyramid[playerChosenIndex] == "-" || pOnePyramid[playerChosenIndex + 1] == "-")
		{
			return false;
		}
		else
		{
			if (check(playerChosenCard, playerChosenIndex, playerChosenIndex + 1))
			{
				pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 13)
	{
		if (pOnePyramid[playerChosenIndex + 1] == "-" || pOnePyramid[playerChosenIndex + 2] == "-")
		{
			return false;
		}
		else
		{
			if (check(playerChosenCard, playerChosenIndex + 1, playerChosenIndex + 2))
			{
				pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 15)
	{
		if (pOnePyramid[playerChosenIndex + 2] == "-" || pOnePyramid[playerChosenIndex + 3] == "-")
		{
			return false;
		}
		else
		{
			if (check(playerChosenCard, playerChosenIndex + 2, playerChosenIndex + 3))
			{
				pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 16)
	{
		if (pOnePyramid[playerChosenIndex + 3] == "-" || pOnePyramid[playerChosenIndex + 4] == "-")
		{
			return false;
		}
		else
		{
			if (check(playerChosenCard, playerChosenIndex + 3, playerChosenIndex + 4))
			{
				pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

//checks all inputs if they are correct
bool addCardpTwo(int playerChosenCard, int playerChosenIndex, bool botcheck)
{
	if (pTwoPyramid[playerChosenIndex + 5] != "-")
	{
		return false;
	}

	if (playerChosenIndex < 6)
	{
		if (pTwoPyramid[playerChosenIndex - 1] == "-" || pTwoPyramid[playerChosenIndex] == "-")
		{
			return false;
		}
		else
		{
			if (checkpTwo(playerChosenCard, playerChosenIndex - 1, playerChosenIndex))
			{
				if (!botcheck) {
					pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
					firstRowpTwo[playerChosenIndex - 1] = pTwo[playerChosenCard - 1];
				}
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 10)
	{
		if (pTwoPyramid[playerChosenIndex] == "-" || pTwoPyramid[playerChosenIndex + 1] == "-")
		{
			return false;
		}
		else
		{
			if (checkpTwo(playerChosenCard, playerChosenIndex, playerChosenIndex + 1))
			{
				if (!botcheck) {
					pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
				}

				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 13)
	{
		if (pTwoPyramid[playerChosenIndex + 1] == "-" || pTwoPyramid[playerChosenIndex + 2] == "-")
		{
			return false;
		}
		else
		{
			if (checkpTwo(playerChosenCard, playerChosenIndex + 1, playerChosenIndex + 2))
			{
				if (!botcheck) {

					pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
				}
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 15)
	{
		if (pTwoPyramid[playerChosenIndex + 2] == "-" || pTwoPyramid[playerChosenIndex + 3] == "-")
		{
			return false;
		}
		else
		{
			if (checkpTwo(playerChosenCard, playerChosenIndex + 2, playerChosenIndex + 3))
			{
				if (!botcheck) {
					pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
				}

				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (playerChosenIndex < 16)
	{
		if (pTwoPyramid[playerChosenIndex + 3] == "-" || pTwoPyramid[playerChosenIndex + 4] == "-")
		{
			return false;
		}
		else
		{
			if (checkpTwo(playerChosenCard, playerChosenIndex + 3, playerChosenIndex + 4))
			{
				if (!botcheck) {
					pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
				}

				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

//this is what happens when check first row is completed
void isValidStatement()
{
	if (pOnePyramid[6] == "-")
	{
		pOnePyramid[11] = "-";
		pOnePyramid[15] = "-";

		pOnePyramid[18] = "-";
	}

	if (pOnePyramid[7] == "-")
	{
		pOnePyramid[11] = "-";
		pOnePyramid[12] = "-";

		pOnePyramid[15] = "-";
		pOnePyramid[16] = "-";

		pOnePyramid[18] = "-";
		pOnePyramid[19] = "-";
	}

	if (pOnePyramid[8] == "-")
	{
		pOnePyramid[12] = "-";
		pOnePyramid[13] = "-";

		pOnePyramid[15] = "-";
		pOnePyramid[16] = "-";
		pOnePyramid[17] = "-";

		pOnePyramid[18] = "-";
		pOnePyramid[19] = "-";
	}

	if (pOnePyramid[9] == "-")
	{
		pOnePyramid[13] = "-";
		pOnePyramid[14] = "-";

		pOnePyramid[16] = "-";
		pOnePyramid[17] = "-";

		pOnePyramid[18] = "-";
		pOnePyramid[19] = "-";
	}

	if (pOnePyramid[10] == "-")
	{
		pOnePyramid[14] = "-";
		pOnePyramid[17] = "-";

		pOnePyramid[19] = "-";
	}

	if (pTwoPyramid[6] == "-")
	{
		pTwoPyramid[11] = "-";
		pTwoPyramid[15] = "-";

		pTwoPyramid[18] = "-";
	}

	if (pTwoPyramid[7] == "-")
	{
		pTwoPyramid[11] = "-";
		pOnePyramid[12] = "-";

		pTwoPyramid[15] = "-";
		pOnePyramid[16] = "-";

		pTwoPyramid[18] = "-";
		pTwoPyramid[19] = "-";
	}

	if (pTwoPyramid[8] == "-")
	{
		pTwoPyramid[12] = "-";
		pTwoPyramid[13] = "-";

		pTwoPyramid[15] = "-";
		pTwoPyramid[16] = "-";
		pTwoPyramid[17] = "-";

		pTwoPyramid[18] = "-";
		pTwoPyramid[19] = "-";
	}

	if (pTwoPyramid[9] == "-")
	{
		pTwoPyramid[13] = "-";
		pTwoPyramid[14] = "-";

		pTwoPyramid[16] = "-";
		pTwoPyramid[17] = "-";

		pTwoPyramid[18] = "-";
		pTwoPyramid[19] = "-";
	}

	if (pTwoPyramid[10] == "-")
	{
		pTwoPyramid[14] = "-";
		pTwoPyramid[17] = "-";

		pTwoPyramid[19] = "-";
	}
}

//fill the second index after is swapped
void fillFifthIndex()
{
	for (int i = 0; i < 48; i++)
	{
		if (cards[i] != "")
		{
			pOne[4] = cards[i];
			cards[i].erase(0);
			break;
		}
	}
}

void fillFithIndexpTwo()
{
	for (int i = 0; i < 48; i++)
	{
		if (cards[i] != "")
		{
			pTwo[4] = cards[i];
			cards[i].erase(0);
			break;
		}
	}
}

//filling all arrays
void fillingCardArrays()
{
	for (int i = 0; i < 48; i++)
	{
		if (i < 8)
		{
			cards[i] = "1or";
		}
		else if (i < 16)
		{
			cards[i] = "1and";
		}
		else if (i < 24)
		{
			cards[i] = "1xor";
		}
		else if (i < 32)
		{
			cards[i] = "0or";
		}
		else if (i < 40)
		{
			cards[i] = "0and";
		}
		else if (i < 48)
		{
			cards[i] = "0xor";
		}
	}

	//shuffle the deck
	for (int i = 0; i < 48; i++)
	{
		int random = rand() % 48;
		string temporary = cards[i];
		cards[i] = cards[random];
		cards[random] = temporary;
	}

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			baseCardspOne[i] = "1";
		}
		else
		{
			baseCardspOne[i] = "0";
		}
	}

	for (int i = 6; i < 21; i++)
	{
		pOnePyramid[i] = "-";
	}

	for (int i = 6; i < 21; i++)
	{
		pTwoPyramid[i] = "-";
	}
}

void checkIfMainDeckIsEmpty()
{
	int counter = 0;
	for (int i = 0; i < 48; i++)
	{
		if (cards[i] == "")
		{
			counter++;
		}
	}

	if (counter == 48)
	{
		for (int i = 0; i < 48; i++)
		{
			if (i < 8)
			{
				cards[i] = "1or";
			}
			else if (i < 16)
			{
				cards[i] = "1and";
			}
			else if (i < 24)
			{
				cards[i] = "1xor";
			}
			else if (i < 32)
			{
				cards[i] = "0or";
			}
			else if (i < 40)
			{
				cards[i] = "0and";
			}
			else if (i < 48)
			{
				cards[i] = "0xor";
			}
		}
	}
}

// Shuffling the base cards
void shuffleArray()
{
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		int random = rand() % 6;
		string temporary = baseCardspOne[i];
		baseCardspOne[i] = baseCardspOne[random];
		baseCardspOne[random] = temporary;
	}


	for (int i = 0; i < 6; i++)
	{
		if (baseCardspOne[i] == "1")
		{
			baseCardspTwo[i] = "0";
		}
		else if (baseCardspOne[i] == "0")
		{
			baseCardspTwo[i] = "1";
		}
	}
}

void printCounterEnemyNotCardMenu()
{
	cout << "Do you want to counter enemy not card?" << endl;
	cout << "---------------" << endl;
	cout << "1. Yes " << endl << "2. No";
	cout << endl;
	cout << "---------------" << endl;
}

void counterEnemyNotCard()
{
	printCounterEnemyNotCardMenu();
	int choiceToCounterOrNot;
	cin >> choiceToCounterOrNot;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choiceToCounterOrNot == 1)
	{
		cout << "You countered him. Now it's other player turn!" << endl;
		system("pause");
		system("cls");

		if (playerOnTurn == true)
		{
			playerOnTurn = false;
		}
		else {
			playerOnTurn = true;
		}
	}
	else if (choiceToCounterOrNot == 0) {


	}
	else {
		cout << "This turn is not possible. That's invalid turn." << endl;

		system("pause");
		system("cls");
		allRendering();
	}
}

void notCardSwapBaseCards(int& playerChosenSwapCard)
{
	if (baseCardspOne[playerChosenSwapCard - 1] == "1")
	{
		baseCardspOne[playerChosenSwapCard - 1] = "0";
		baseCardspTwo[playerChosenSwapCard - 1] = "1";
	}
	else {
		baseCardspOne[playerChosenSwapCard - 1] = "1";
		baseCardspTwo[playerChosenSwapCard - 1] = "0";
	}

	if (pOnePyramid[playerChosenSwapCard - 1] == "1")
	{
		pOnePyramid[playerChosenSwapCard - 1] = "0";
		pTwoPyramid[playerChosenSwapCard - 1] = "1";
	}
	else {
		pOnePyramid[playerChosenSwapCard - 1] = "1";
		pTwoPyramid[playerChosenSwapCard - 1] = "0";
	}
}

//randomizing players cards
void RandomizingPlayerCardsOutput()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		//gets random index from array
		int randomIndex = rand() % 48;
		if (cards[randomIndex] == "")
		{
			i--;
		}
		else if (cards[randomIndex] != "") {
			pOne[i] = cards[randomIndex];

			//set whitespace element for future checks
			cards[randomIndex].erase();
		}
	}

	for (int i = 0; i < 5; i++)
	{
		//gets random index from array
		int randomIndex = rand() % 48;
		if (cards[randomIndex] == "")
		{
			i--;
		}
		else if (cards[randomIndex] != "") {
			pTwo[i] = cards[randomIndex];

			//set whitespace element for future checks
			cards[randomIndex].erase();
		}
	}
}

//Builing player one starting pyramid
void buildPyramindspOne()
{
	int counter = 6;
	cout << setw(2);
	for (int i = 1; i < 6; i++)
	{
		for (int space = 1; space < i; space++)
		{
			cout << " ";
		}

		for (int j = i; j < 6; j++)
		{

			cout << pOnePyramid[counter] << " ";
			counter++;
		}
		cout << setw(2);
		cout << endl;
	}
}

//Builing player two starting pyramid
void buildPyramindspTwo()
{
	int counter = 6;
	cout << setw(2);
	for (int i = 1; i < 6; i++)
	{

		for (int space = 1; space < i; space++)
		{
			cout << " ";
		}

		for (int j = i; j < 6; j++)
		{

			cout << pTwoPyramid[counter] << " ";
			counter++;
		}
		cout << setw(2);
		cout << endl;
	}
}

//outputs player cards randomized
void outputPlyerCards()
{
	cout << playerOne << " cards are : ";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << pOne[i] << " ";
	}
	cout << "Not cards: " << notCardspOne;

	cout << endl;

	cout << playerTwo << " cards are: ";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << pTwo[i] << " ";
	}
	cout << "Not cards: " << notCardspTwo;
	cout << endl;

}

bool counterpOne()
{
	string input;
	cout << playerOne << " do you want to counter " << playerTwo << " not card?";
	cout << "1. Yes";
	cout << "2.No";

	cin >> input;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (input == "1")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool counterpTwo()
{
	string input;
	cout << playerTwo << " do you want to counter " << playerOne <<  " not card ? ";
	cout << "1. Yes";
	cout << "2.No";

	cin >> input;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (input == "1")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//draws both pyramids
void drawPyramids()
{
	cout << endl;
	cout << playerOne << " pyramid: " << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << baseCardspOne[i] << " ";
		pOnePyramid[i] = baseCardspOne[i];
	}

	cout << endl;

	buildPyramindspOne();

	cout << endl;

	cout  << playerTwo << " pyramid: " << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << baseCardspTwo[i] << " ";
		pTwoPyramid[i] = baseCardspTwo[i];
	}

	cout << endl;

	buildPyramindspTwo();
}

//menu for place or delete
void printOptionMenu()
{
	cout << endl;
	cout << "---------------" << endl;
	cout << "1. Place " << endl << "2. Delete" << endl << "3. Place not card" << endl;
	cout << "---------------" << endl;
}

//menu for computer or player
void printOptionMenuPCorP()
{
	cout << endl;
	cout << "---------------" << endl;
	cout << "1. PC " << endl << "2. Player" << endl;
	cout << "---------------" << endl;
}

bool PCorPMenu = true;
string choisePCorP = "";
void allRendering()
{
	checkIfMainDeckIsEmpty();

	if (PCorPMenu == true)
	{
		cout << endl;
		cout << "What do you want to play against. Computer or other player?";

		printOptionMenuPCorP();

		cout << "Your choice: ";
		cin >> choisePCorP;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (choisePCorP == "1")
		{
			isBot = true;
			system("pause");
			system("cls");
			cout << "Enter your name : ";
			getline(cin, playerOne);
			playerOneWin = playerOne;
			playerOne += "'s";
			system("pause");
			system("cls");
		}
		else if (choisePCorP == "2") {
			isBot = false;
			system("pause");
			system("cls");
			cout << "Player one enter your name : ";
			getline(cin, playerOne);
			playerOneWin = playerOne;
			playerOne += "'s";
			system("pause");
			system("cls");
			cout << "Player two enter your name : ";
			getline(cin, playerTwo);
			playerTwoWin = playerTwo;
			playerTwo += "'s";
			system("pause");
			system("cls");
		}
		else {
			cout << "Wrong input. Please try again!" << endl;
			system("pause");
			system("cls");
			allRendering();
			cin >> choisePCorP;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			system("cls");
		}	
	}

	PCorPMenu = false;

	outputPlyerCards();
	drawPyramids();

	cout << endl;

	while (pOnePyramid[20] == "-" && pTwoPyramid[20] == "-") {
		if (playerOnTurn == true) {
			cout << playerOne << " turn: ";
			printOptionMenu();
			cout << "What do you want to play: ";
			choiseF();
		}
		else {
			if (!isBot)
			{
				cout << playerTwo << " turn:";
				printOptionMenu();
				cout << "What do you want to play: ";
				choiseF();
			}
			else {
				cout << "Now it's bot's turn" << endl;
				botTurn();
				system("pause");
				system("cls");
				playerOnTurn = true;
				fillFifthIndex();
				allRendering();
			}
		}
	}
	cout << (pOnePyramid[20] != "-" ?  playerOneWin + " is winner" : playerTwoWin + " is winner");
	cout << endl;
	system("pause");
}

//bot funcitons
bool botTurnNotCard()
{
	srand(time(0));
	int index = rand() & 3;
	if (index == 1)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void botTurn() {

	srand(time(NULL));
	vector< pair<int, int>  > possible; //.first is card, .second is index
	for (int i = 1; i <= 15; i++) // check all indexes
	{
		for (int j = 1; j <= 5; j++) { //if the card is possible
			if (addCardpTwo(j, i, true)) {
				possible.push_back(make_pair(j, i));
			}
		}
	}

	if (possible.size() > 0) {
		//pick random entry from vector and play it
		int index = rand() % possible.size();
		addCardpTwo(possible[index].first,
			possible[index].second);
		deleteCard(2, possible[index].first);
	}
}

//checks if player has chosen the right card
void validateTurn() {
	if (playerOnTurn) {
		inputChosenIndex(pOneChosenIndex);
		while (!addCard(pOneChosenCard, pOneChosenIndex)) {
			cout << "This turn is not possible. Please try again." << endl;
			system("pause");

			system("cls");
			allRendering();

			inputChosenIndex(pOneChosenIndex);
		}
		deleteCard(1, pOneChosenCard);
	}
	else {
		inputChosenIndex(pTwoChosenIndex);
		while (!addCardpTwo(pTwoChosenCard, pTwoChosenIndex, false)) {
			cout << "This turn is not possible. Please try again." << endl;
			system("pause");

			system("cls");
			allRendering();

			inputChosenIndex(pTwoChosenIndex);
		}
		deleteCard(2, pOneChosenCard);
	}
}

void choiseF()
{
	if (playerOnTurn == true)
	{
		int flag = 0;
		cin >> choise;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (choise == "1")
		{
			inputChosenCard(pOneChosenCard);
			validateTurn();
			playerOnTurn = false;
			system("pause");
			system("cls");

			if (pTwo[4] == "")
			{
				fillFithIndexpTwo();
			}

			allRendering();
		}
		else if (choise == "2")
		{
			inputChosenCard(pOneChosenCard);
			deleteCard(1, pOneChosenCard);
			system("pause");
			system("cls");

			if (pTwo[4] == "")
			{
				fillFithIndexpTwo();
			}

			playerOnTurn = false;
			allRendering();

		}
		else if (choise == "3")
		{
			inputChosenIndex(pOneChosenIndex);
			if (pOneChosenIndex > 6 || pOneChosenIndex < 1)
			{
				cout << "This turn is not possible. Please try again." << endl;
				system("pause");
				system("cls");
				flag = 1;
				allRendering();
			}
			if (notCardspOne <= 0)
			{
				cout << "You do not have not cards. PLease try again." << endl;
				system("pause");
				system("cls");
				flag = 1;
				allRendering();
			}
			notCardspOne--;
			if (!isBot)
			{
				if (counterpTwo())
				{
					flag = 1;
					notCardspTwo--;
					system("pause");
					system("cls");

					allRendering();
				}
				else
				{
					notCardSwapBaseCards(pOneChosenIndex);
					playNotCardpOne(pOneChosenIndex);
					playNotCardpTwo(pOneChosenIndex);
					isValidStatement();

					system("pause");
					system("cls");
					if (flag == 0)
					{
						playerOnTurn = false;
					}
					else
					{
						playerOnTurn = true;
					}


					allRendering();
				}

			}
			else
			{
				cout << "Now it's bot's turn" << endl;
				if (botTurnNotCard())
				{
					flag = 1;
					notCardspTwo--;
					system("pause");
					system("cls");

					allRendering();
				}
				else
				{
					notCardSwapBaseCards(pOneChosenIndex);
					playNotCardpOne(pOneChosenIndex);
					playNotCardpTwo(pOneChosenIndex);
					isValidStatement();

					system("pause");
					system("cls");
					if (flag == 0)
					{
						playerOnTurn = false;
					}
					else
					{
						playerOnTurn = true;
					}


					allRendering();
				}
				
				
			}	
		}
		else
		{
			cout << "Wrong input. Please try again!" << endl;
			system("pause");
			system("cls");
			allRendering();
		}
		cout << endl;
	}
	else {
		int flag = 0;
		cin >> choise;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		if (choise == "1")
		{
			inputChosenCard(pTwoChosenCard);
			validateTurn();
			system("pause");
			system("cls");
			playerOnTurn = true;

			if (pOne[4] == "")
			{
				fillFifthIndex();
			}

			allRendering();

		}
		else if (choise == "2")
		{
			inputChosenCard(pTwoChosenCard);
			deleteCard(2, pTwoChosenCard);
			system("pause");
			system("cls");

			playerOnTurn = true;

			if (pOne[4] == "")
			{
				fillFifthIndex();
			}
			allRendering();
		}
		else if (choise == "3")
		{
			inputChosenIndex(pTwoChosenIndex);
			if (pTwoChosenIndex > 6 || pTwoChosenIndex < 1)
			{
				cout << "This turn is not possible. Please try again." << endl;
				system("pause");
				system("cls");
				flag = 1;
				allRendering();
			}
			if (notCardspTwo <= 0)
			{
				cout << "You do not have not cards. PLease try again." << endl;
				system("pause");
				system("cls");
				flag = 1;
				allRendering();
			}

			notCardspTwo--;

			if (counterpOne())
			{
				flag = 1;
				notCardspOne--;
				system("pause");
				system("cls");

				allRendering();
			}
			else
			{
				notCardSwapBaseCards(pTwoChosenIndex);
				playNotCardpOne(pTwoChosenIndex);
				playNotCardpTwo(pTwoChosenIndex);
				isValidStatement();

				system("pause");
				system("cls");
				if (flag == 0)
				{
					playerOnTurn = true;
				}
				else
				{
					playerOnTurn = false;
				}
				allRendering();
			}
		}
	}
}

void setup()
{
	system("color 1f");

	fillingCardArrays();
	shuffleArray();
	RandomizingPlayerCardsOutput();
	allRendering();
}