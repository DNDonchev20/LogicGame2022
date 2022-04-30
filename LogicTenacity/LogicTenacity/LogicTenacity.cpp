#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//all cards
string cards[48];
string baseCards[6];
int pOneChosenIndex = 0;
int pTwoChosenIndex = 0;

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

    //baseCards array
    fill(begin(baseCards), begin(baseCards) + 3, "01");
    fill(begin(baseCards) + 3, begin(baseCards) + 6, "10");

    //notCards array
    fill(begin(notCards), begin(notCards) + 2, '!');
}

void RandomizingPlayerCardsInput()
{
    srand(time(0));
       
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
            pOne[i] = cards[randomIndex];

            //set whitespace element for future checks
            cards[randomIndex].erase();
            cout << pOne[i] << " ";
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
            cout << pTwo[i] << " ";
        }
        
    }
    cout << endl;
}

// Shuffle array
void shuffle_array()
{
    random_shuffle(begin(baseCards), end(baseCards));
    for (int i = 0; i < 6; i++)
    {
        cout << baseCards[i] << " ";
    }
}

//make checks what cards can be placed in the first row
void checksFirstRow()
{
    cout << "What card are you going to play " << endl <<
        "Remember if you get it wrong it will send you \"Wrong card!\"";

    for (int i = 0; i < 6; i++)
    {

        if (baseCards[i] == "10" && baseCards[i + 1] == "01")
        {
        playerOneWrong1:
            cin >> pOneChosenIndex;
            inputCheckpOne();
            cout << endl;
            if (pOne[pOneChosenIndex] == "1or")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "1and")
            {
                cout << "Wrong card";

                goto playerOneWrong1;
            }
            else if (pOne[pOneChosenIndex] == "1xor")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "0or")
            {
                cout << "Wrong card";

                goto playerOneWrong1;
            }
            else if (pOne[pOneChosenIndex] == "0and")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "0xor")
            {
                cout << "Wrong card";

                goto playerOneWrong1;
            }
            else
            {
                cout << "Error";
            }

            //here statrs player two turn
        playerTwoWrong1:
            cin >> pTwoChosenIndex;
            inputCheckpTwo();
            if (pTwo[pTwoChosenIndex] == "1or")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "1and")
            {
                cout << "Wrong card";

                goto playerTwoWrong1;
            }
            else if (pTwo[pTwoChosenIndex] == "1xor")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "0or")
            {
                cout << "Wrong card";

                goto playerTwoWrong1;
            }
            else if (pTwo[pTwoChosenIndex] == "0and")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "0xor")
            {
                cout << "Wrong card";

                goto playerTwoWrong1;
            }
            else
            {
                cout << "Error";
            }
        }
        else if (baseCards[i] == "10" && baseCards[i + 1] == "10")
        {
        playerOneWrong2:
            cin >> pOneChosenIndex;
            inputCheckpOne();
            cout << endl;
            if (pOne[pOneChosenIndex] == "1or")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "1and")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "1xor")
            {
                cout << "Wrong card";

                goto playerOneWrong2;
            }
            else if (pOne[pOneChosenIndex] == "0or")
            {
                cout << "Wrong card";

                goto playerOneWrong2;
            }
            else if (pOne[pOneChosenIndex] == "0and")
            {
                cout << "Wrong card";

                goto playerOneWrong2;
            }
            else if (pOne[pOneChosenIndex] == "0xor")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else
            {
                cout << "Error";
            }

            //here statrs player two turn
        playerTwoWrong2:
            cin >> pTwoChosenIndex;
            inputCheckpTwo();

            if (pTwo[pTwoChosenIndex] == "1or")
            {
                cout << "Wrong card";

                goto playerTwoWrong2;
            }
            else if (pTwo[pTwoChosenIndex] == "1and")
            {
                cout << "Wrong card";

                goto playerTwoWrong2;
            }
            else if (pTwo[pTwoChosenIndex] == "1xor")
            {
                cout << "Wrong card";

                goto playerTwoWrong2;
            }
            else if (pTwo[pTwoChosenIndex] == "0or")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "0and")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "0xor")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else
            {
                cout << "Error";
            }


        }
        else if (baseCards[i] == "01" && baseCards[i + 1] == "01")
        {
        playerOneWrong3:
            cin >> pOneChosenIndex;
            inputCheckpOne();
            cout << endl;
            if (pOne[pOneChosenIndex] == "1or")
            {
                cout << "Wrong card";

                goto playerOneWrong3;
            }
            else if (pOne[pOneChosenIndex] == "1and")
            {
                cout << "Wrong card";

                goto playerOneWrong3;
            }
            else if (pOne[pOneChosenIndex] == "1xor")
            {
                cout << "Wrong card";

                goto playerOneWrong3;
            }
            else if (pOne[pOneChosenIndex] == "0or")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "0and")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else if (pOne[pOneChosenIndex] == "0xor")
            {
                pOnePyramid[0][i] = pOne[pOneChosenIndex];
                pOne[pOneChosenIndex].erase(0);
            }
            else
            {
                cout << "Error";
            }

            //here statrs player two turn
        playerTwoWrong3:
            cin >> pTwoChosenIndex;
            inputCheckpTwo();

            if (pTwo[pTwoChosenIndex] == "1or")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "1and")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else if (pTwo[pTwoChosenIndex] == "1xor")
            {
                cout << "Wrong card";

                goto playerTwoWrong3;
            }
            else if (pTwo[pTwoChosenIndex] == "0or")
            {
                cout << "Wrong card";

                goto playerTwoWrong3;
            }
            else if (pTwo[pTwoChosenIndex] == "0and")
            {
                cout << "Wrong card";

                goto playerTwoWrong3;
            }
            else if (pTwo[pTwoChosenIndex] == "0xor")
            {
                pTwoPyramid[0][i] = pTwo[pTwoChosenIndex];
                pTwo[pTwoChosenIndex].erase(0);
            }
            else
            {
                cout << "Error";
            }
        }
    }
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
    checksFirstRow();

}