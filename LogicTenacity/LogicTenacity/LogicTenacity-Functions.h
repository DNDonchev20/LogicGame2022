#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

void inputChosenIndex(int& playerChosenIndex);

void inputChosenCard(int& playerChosenCard);

void deleteCardpOne(int& playerChosenCard);

void deleteCardpTwo(int& playerChosenCard);

void deleteCard(int player, int& playerChosenCard);

bool checkNotCardpOne(int forCheck, int checkCard1, int checkCard2);

bool checkNotCardpTwo(int forCheck, int checkCard1, int checkCard2);

bool check(int playerChosenCard, int checkCard1, int checkCard2);

bool checkpTwo(int playerChosenCard, int checkCard1, int checkCard2);

void playNotCardpOne(int playerChosenIndex);

void playNotCardpTwo(int playerChosenIndex);

bool addCard(int playerChosenCard, int playerChosenIndex);

bool addCardpTwo(int playerChosenCard, int playerChosenIndex, bool botcheck = false);

void isValidStatement();

void fillFifthIndex();

void fillFithIndexpTwo();

void fillingCardArrays();

void checkIfMainDeckIsEmpty();

void shuffleArray();

void printCounterEnemyNotCardMenu();

void counterEnemyNotCard();

void notCardSwapBaseCards(int& playerChosenSwapCard);

void RandomizingPlayerCardsOutput();

void buildPyramindspOne();

void buildPyramindspTwo();

void outputPlyerCards();

bool counterpOne();

bool counterpTwo();

void drawPyramids();

void printOptionMenu();

void printOptionMenuPCorP();

void allRendering();

void botTurn();

void validateTurn();

void choiseF();

void setup();