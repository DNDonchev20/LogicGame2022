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

string pOnePyramid[21], pTwoPyramid[21];


bool pOneWins = false, pTwoWins = false;

//Player have to choose where to place the chosen card
void inputChosenIndex(int& playerChosenIndex)
{
    cout << "Select an index: ";
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

bool check(int playerChosenCard, int checkCard1, int checkCard2)
{

    playerChosenCard--;
    if (pOne[playerChosenCard] == "1or")
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


}

void addCard(int playerChosenCard, int playerChosenIndex)
{

    if (playerChosenIndex < 6)
    {
        if (pOnePyramid[playerChosenIndex - 1] == "-" || pOnePyramid[playerChosenIndex] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (check(playerChosenCard, playerChosenIndex - 1, playerChosenIndex))
            {
                pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 10)
    {
        if (pOnePyramid[playerChosenIndex] == "-" || pOnePyramid[playerChosenIndex + 1] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (check(playerChosenCard, playerChosenIndex, playerChosenIndex + 1))
            {
                pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 13)
    {
        if (pOnePyramid[playerChosenIndex + 1] == "-" || pOnePyramid[playerChosenIndex + 2] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (check(playerChosenCard, playerChosenIndex + 1, playerChosenIndex + 2))
            {
                pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 15)
    {
        if (pOnePyramid[playerChosenIndex + 2] == "-" || pOnePyramid[playerChosenIndex + 3] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (check(playerChosenCard, playerChosenIndex + 2, playerChosenIndex + 3))
            {
                pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 16)
    {
        if (pOnePyramid[playerChosenIndex + 3] == "-" || pOnePyramid[playerChosenIndex + 4] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (check(playerChosenCard, playerChosenIndex + 3, playerChosenIndex + 4))
            {
                pOnePyramid[playerChosenIndex + 5] = pOne[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
}

void addCardpTwo(int playerChosenCard, int playerChosenIndex)
{

    if (playerChosenIndex < 6)
    {
        if (pTwoPyramid[playerChosenIndex - 1] == "-" || pTwoPyramid[playerChosenIndex] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (checkpTwo(playerChosenCard, playerChosenIndex - 1, playerChosenIndex))
            {
                pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 10)
    {
        if (pTwoPyramid[playerChosenIndex] == "-" || pTwoPyramid[playerChosenIndex + 1] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (checkpTwo(playerChosenCard, playerChosenIndex, playerChosenIndex + 1))
            {
                pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 13)
    {
        if (pTwoPyramid[playerChosenIndex + 1] == "-" || pTwoPyramid[playerChosenIndex + 2] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (checkpTwo(playerChosenCard, playerChosenIndex + 1, playerChosenIndex + 2))
            {
                pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 15)
    {
        if (pTwoPyramid[playerChosenIndex + 2] == "-" || pTwoPyramid[playerChosenIndex + 3] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (checkpTwo(playerChosenCard, playerChosenIndex + 2, playerChosenIndex + 3))
            {
                pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
    else if (playerChosenIndex < 16)
    {
        if (pTwoPyramid[playerChosenIndex + 3] == "-" || pTwoPyramid[playerChosenIndex + 4] == "-")
        {
            cout << "Wrong input";
        }
        else
        {
            if (checkpTwo(playerChosenCard, playerChosenIndex + 3, playerChosenIndex + 4))
            {
                pTwoPyramid[playerChosenIndex + 5] = pTwo[playerChosenCard - 1].substr(0, 1);
            }
            else
            {
                cout << "Wrong input";
            }
        }
    }
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

// Shuffle array
void shuffleArray()
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
        pOnePyramid[i] = baseCardspOne[i];
    }

    cout << endl;

    buildPyramindspOne();

    cout << endl;

    cout << "Player two pyramid: " << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << baseCardspTwo[i] << " ";
        pTwoPyramid[i] = baseCardspTwo[i];
    }

    cout << endl;

    buildPyramindspTwo();
}

void printOptionMenu()
{
    cout << endl;
    cout << "---------------" << endl;
    cout << "1. Place " << endl << "2. Delete" << endl;
    cout << "---------------" << endl;
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
        cout << "Player one turn: ";
        printOptionMenu();
        cout << "Do you want to place or delete a card?(write delete or place): ";
    
        cin >> choise;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choise == "1")
        {
                inputChosenCard(pOneChosenCard);
                inputChosenIndex(pOneChosenIndex);
                addCard(pOneChosenCard, pOneChosenIndex);
                system("pause");
                system("cls");
                allRendering();
                playerOnTurn = false;
                choiseF();
        }
        else if (choise == "2")
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
        cout << "Player two turn:";
        printOptionMenu();
        cout << "Do you want to place or delete a card?(write delete or place): ";

        cin >> choise;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (choise == "1")
        {
            inputChosenCard(pTwoChosenCard);
            inputChosenIndex(pTwoChosenIndex);
            addCardpTwo(pTwoChosenCard, pTwoChosenIndex);
            system("pause");
            system("cls");
            allRendering();
            playerOnTurn = true;
            choiseF();

        }
        else if (choise == "2")
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
    shuffleArray();
    RandomizingPlayerCardsOutput();
    allRendering();
    choiseF();
}

int main()
{
    setup();
}