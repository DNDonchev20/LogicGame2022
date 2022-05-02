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
bool playerTurn = true;


//choise to place or to delete a card
string choise;

//players  
//gamemode 1
string pOne[5], pTwo[5];

string pOnePyramid[15], pTwoPyramid[15];


bool pOneWins = false, pTwoWins = false;

//Play have to choose what card to play
int inputChosenCard(int& playerChosenCard)
{
    cout << "Select a card: ";
    cin >> playerChosenCard;

    return playerChosenCard;
}

//Player have to choose where to place the chosen card
int inputChosenIndex(int& playerChosenIndex)
{
    cout << "Select an index";
    cin >> playerChosenIndex;

    return playerChosenIndex;
}

void deleteCard(int& playerChosenCard)
{
    pOne[playerChosenCard].erase(0);
    if (pOne[playerChosenCard] == "")
    {
        for (int i = playerChosenCard; i < 5; i++)
        {
            pOne[playerChosenCard] = pOne[playerChosenCard + 1];
        }
    }
}

void fillingCardArrays()
{
    //filling the arrays
    //cards array
    fill(begin(cards), begin(cards) + 8, "1or");
    fill(begin(cards) + 8, begin(cards) + 16, "1and");
    fill(begin(cards) + 16, begin(cards) + 24, "1xor");
    fill(begin(cards) + 24, begin(cards) + 32, "0or");
    fill(begin(cards) + 32, begin(cards) + 40, "0and");
    fill(begin(cards) + 40, begin(cards) + 48, "0xor");

    //baseCards arrays
    fill(begin(baseCardspOne), begin(baseCardspOne) + 3, "1");
    fill(begin(baseCardspOne) + 3, begin(baseCardspOne) + 6, "0");

    //notCards array
    fill(begin(notCards), begin(notCards) + 2, '!');

    //Pyramid arrays
    fill(begin(pOnePyramid), end(pOnePyramid), "-");
    fill(begin(pTwoPyramid), end(pTwoPyramid), "-");
}

void RandomizingPlayerCardsOutput()
{
    srand(time(0));
    for (int i = 0; i < 4; i++)
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

    for (int i = 0; i < 4; i++)
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

void pOneFillFifthIndex()
{
    srand(time(0));

    //gets random index from array
    int randomIndex = rand() % 48;
    
    if (cards[randomIndex] != "")
    {
        pOne[4] = cards[randomIndex];
        cards[randomIndex].erase(0);
        cout << "Drawed card: " << pOne[4];
    }
    else {
        pOneFillFifthIndex();
    }
}

void pTwoFillFifthIndex()
{
    srand(time(0));

    //gets random index from array
    int randomIndex = rand() % 48;
    pTwo[4] = cards[randomIndex];
    cout << "Drawed card: " << pTwo[4];
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

// Shuffle array
void shuffle_array()
{
    random_shuffle(begin(baseCardspOne), end(baseCardspOne));
    
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

void outputPlyerCards()
{
    cout << "Player one cards are: ";
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << pOne[i] << " ";
    }
    

    cout << endl;

    cout << "Player two cards are: ";
    for (int i = 0; i < 4; i++)
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
    cout << "Do you want to play or delete a card?" << endl;
    cin >> choise;

    if (choise == "Place" || choise == "place")
    {
        //placeCard()
    }
    else if (choise == "Delete" || choise == "delete")
    {
        inputChosenCard(pOneChosenCard);
        deleteCard(pOneChosenCard);
        system("pause");
        system("cls");
        allRendering();
        choiseF();
    }
    else
    {
        cout << "Wrong input plese try again";
        system("pause");
        system("cls");
        allRendering();
        choiseF();
    }

    cout << endl;
}

void inputCheckpOne()
{
    if (pOneChosenIndex < 0 || pOneChosenIndex > 3)
    {
        cout << "That's not real card index. Please try again!" << endl;
        cin >> pOneChosenIndex;
        inputCheckpOne();
    }
}

void inputCheckpTwo()
{
    if (pTwoChosenIndex < 0 || pTwoChosenIndex > 3)
    {
        cout << "That's not real card index. Please try again!" << endl;
        cin >> pTwoChosenIndex;
        inputCheckpTwo();
    }
}

/*void outputBasecards()
{
    for (int i = 0; i < 6; i++)
    {
        cout << baseCards[i] << " ";
    }
}*/


int main()
{
    fillingCardArrays();
    shuffle_array();
    RandomizingPlayerCardsOutput();
    allRendering();
    choiseF();
}