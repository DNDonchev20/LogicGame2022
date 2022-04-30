#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
using namespace vars;

namespace vars {
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

    //players  
    //gamemode 1
    string pOne[4], pTwo[4];
    string pOnePyramid[5][5] = { "-", "-", "-", "-", "-", " ",
    "-", "-", "-", "-", " ", "-", "-", "-", " ", " ", " ", "-", "-", " ", " ", " ", "-", " ", " " },

    pTwoPyramid[5][5] = { "-", "-", "-", "-", "-", " ",
    "-", "-", "-", "-", " ", "-", "-", "-", " ", " ", " ", "-", "-", " ", " ", " ", "-", " ", " " };

    bool pOneWins = false, pTwoWins = false;
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
}

void RandomizingPlayerCardsInput()
{
    srand(time(0));
       
    cout << "Player one cards are: ";
    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;
        if (cards[randomIndex] == "")
        {
            i--;
        }
        else if(cards[randomIndex] != ""){
            pOne[i] = cards[randomIndex];

            //set whitespace element for future checks
            cards[randomIndex].erase();
            cout << i + 1 << ". " << pOne[i] << " ";
        }
        
    }

    cout << endl;

    cout << "Player two cards are: ";
    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;
        if (cards[randomIndex] == "")
        {
            i--;
        }
        else if(cards[randomIndex] != ""){
            pTwo[i] = cards[randomIndex];

            //set whitespace element for future checks
            cards[randomIndex].erase();
            cout << i + 1 << ". " << pTwo[i] << " ";
        }
        
    }
    cout << endl;
}

// Shuffle array
void shuffle_array()
{
    random_shuffle(begin(baseCardspOne), end(baseCardspOne));
    cout << "Player one base cards: " << setw(56) << "Player two base cards are : " << endl;
    for(int i = 0; i < 6; i++)
    {
        if(baseCardspOne[i] == "1")
        {
            baseCardspTwo[i] = "0";
        }
        else if(baseCardspOne[i] == "0")
        {
            baseCardspTwo[i] = "1";
        }
        cout << baseCardspOne[i] << " ";
    }

    cout << setw(40);
    for (int i = 0; i < 6; i++)
    {
        cout << baseCardspTwo[i] << " ";
    }
    cout << endl;
}

void inputCheckpOne()
{
    if (pOneChosenIndex < 0 || pOneChosenIndex > 3)
    {
        cout << "That's not real cards index. Please try again!" << endl;
        cin >> pOneChosenIndex;
        inputCheckpOne();
    }
}

void inputCheckpTwo()
{
    if (pTwoChosenIndex < 0 || pTwoChosenIndex > 3)
    {
        cout << "That's not real cards index. Please try again!" << endl;
        cin >> pTwoChosenIndex;
        inputCheckpTwo();
    }
}

//make checks what cards can be placed in the first row
int inputChosenCard()
{
    int playerChosenCard;
    cout << "Select a card";
    cin >> playerChosenCard;
    
    return playerChosenCard;
}
int inputChosenIndex()
{
    int playerChosenIndex;
    cout << "Select an index";
    cin >> playerChosenIndex;

    return playerChosenIndex;
}


/*void buildPyramindPOne()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pOnePyramid[i][j] == "")
            {
                continue;
            }
            else {
                cout << pOnePyramid[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void outputBasecards()
{
    for (int i = 0; i < 6; i++)
    {
        cout << baseCards[i] << " ";
    }
}

void buildPyramindPTwo()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pTwoPyramid[i][j] == "")
            {
                continue;
            }
            else {
                cout << pTwoPyramid[i][j] << " ";
            }
        }
        cout << endl;
    }
}*/

int main()
{
    fillingCardArrays();
    RandomizingPlayerCardsInput();
    shuffle_array();
}

