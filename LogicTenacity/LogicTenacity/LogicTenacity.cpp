#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//all cards
string cards[48];
string baseCardspOne[6];
string baseCardspTwo[6];

int pOneChosenIndex = 0;
int pTwoChosenIndex = 0;

int pOneChosenCard = 0;
int pTwoChosenCard = 0;

//stage 3 and 4
char notCards[2];

//this bools decide who has the turn
bool playerOnTurn = true;

//choise to place or to delete a card
string choise;

//players  
//gamemode 1
string pOne[6], pTwo[6];

string pOnePyramid[15], pTwoPyramid[15];


bool pOneWins = false, pTwoWins = false;

//Player have to choose where to place the chosen card
void inputChosenIndex(int& playerChosenIndex)
{
    cout << "Select an index";
    cin >> playerChosenIndex;
}

//Play have to choose what card to play
void inputChosenCard(int& playerChosenCard)
{
    cout << "Select a card: ";
    cin >> playerChosenCard;
}

void deleteCard(int& playerChosenCard)
{
    pOne[playerChosenCard - 1].erase(0);
    swap(pOne[playerChosenCard - 1], pOne[4]);
}

void deleteCardpTwo(int& playerChosenCard)
{
    pTwo[playerChosenCard - 1].erase(0);
    swap(pTwo[playerChosenCard - 1], pTwo[4]);
}

void fillFifthIndex()
{
    for (int i = 0; i < 48; i++)
    {
        if (cards[i] != "")
        {
            pOne[4] = cards[i] ;
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

/*void addCard(int& playerChoesnCard)
{
    cout << "What card do you want to place?";
    pOneChosenCard = inputChosenCard();
    cout << "Where do you want to place the card?";
    pOneChosenIndex = inputChosenIndex();
    pOnePyramid[pOneChosenIndex] = pOne[pOneChosenCard];
    
    
}*/


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

    for (int i = 0; i < 15; i++)
    {
        pOnePyramid[i] = "-";
    }

    for (int i = 0; i < 15; i++)
    {
        pTwoPyramid[i] = "-";
    }
}

// Shuffle array
void shuffle_array()
{
    srand(time(0));
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

void RandomizingPlayerCardsOutput()
{
    srand(time(0));
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
    int counter = 0;
    cout << setw(2);
    for (int i = 1; i < 6; i++)
    {
        for (int space = 1; space < i; space++)
        {
            cout << " ";
        }

        for (int j = i; j < 6; j++)
        {
            counter++;
            cout << pOnePyramid[i] << " ";
        }
        cout << setw(2);
        cout << endl;
    }
}

//Builing player two starting pyramid
void buildPyramindspTwo()
{
    int counter = 0;
    cout << setw(2);
    for (int i = 1; i < 6; i++)
    {
        for (int space = 1; space < i; space++)
        {
            cout << " ";
        }

        for (int j = i; j < 6; j++)
        {
            counter++;
            cout << pTwoPyramid[i] << " ";
        }
        cout << setw(2);
        cout << endl;
    }
}

void outputPlyerCards()
{
    cout << "Player one cards are: ";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << pOne[i] << " ";
    }
 
    cout << endl;

    cout << "Player two cards are: ";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << pTwo[i] << " ";
    }
    cout << endl;
}

void drawPyramids()
{
    cout << endl;
    cout << "Player one pyramid: " << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << baseCardspOne[i] << " ";
    }

    cout << endl;

    buildPyramindspOne();

    cout << endl;

    cout << "Player two pyramid: " << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << baseCardspTwo[i] << " ";
    }

    cout << endl;

    buildPyramindspTwo();
}

void allRendering()
{
    outputPlyerCards();
    drawPyramids();
}

void choiseF()
{
    static bool firstTimepTwo = true;
    //while
    if (playerOnTurn == true)
    {
        cout << endl;
        cout << "Player one turn: " << endl;
        cout << "Do you want to place or delete a card?(write delete or place): ";
    
        cin >> choise;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choise == "Place" || choise == "place")
        {
            //placeCard()
            /*addCards();*/
        }
        else if (choise == "Delete" || choise == "delete")
        {
            inputChosenCard(pOneChosenCard);
            if (pOneChosenCard < 1 || pOneChosenCard > 5)
            {
                cout << "Wrong card index. Please try again with index from 1 to 5" << endl;
                system("pause");
                system("cls");
                allRendering();
                choiseF();
            }
            else {
                deleteCard(pOneChosenCard);
                system("pause");
                system("cls");

                if (firstTimepTwo == false)
                {
                    fillFithIndexpTwo();
                    
                }
                firstTimepTwo = false;
                allRendering();
                playerOnTurn = false;

                choiseF();
            }       
        }
        else
        {
            cout << "Wrong input. Please try again!" << endl;
            system("pause");
            system("cls");
            allRendering();
            choiseF();
        }
        cout << endl; 
    }
    else {
        cout << "Player two turn:" << endl;
        cout << "Do you want to place or delete a card?(write delete or place): ";

        cin >> choise;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (choise == "Place" || choise == "place")
        {
            //placeCard()
            /*addCards();*/
        }
        else if (choise == "Delete" || choise == "delete")
        {
            inputChosenCard(pTwoChosenCard);
            if (pTwoChosenCard < 1 || pTwoChosenCard > 5)
            {
                cout << "Wrong card index. Please try again with index from 1 to 5!" << endl;
                system("pause");
                system("cls");
                allRendering();
                choiseF();
            }
            else {
                deleteCardpTwo(pTwoChosenCard);
                system("pause");
                system("cls");
                
                playerOnTurn = true;

                fillFifthIndex();
                allRendering();
                choiseF();
            }
        }
        else
        {
            cout << "Wrong input. Please try again!" << endl;
            system("pause");
            system("cls");
            allRendering();
            choiseF();
        }
    }
}

void setup()
{
    fillingCardArrays();
    shuffle_array();
    RandomizingPlayerCardsOutput();
    allRendering();
    choiseF();
}

int main()
{
    setup();
}