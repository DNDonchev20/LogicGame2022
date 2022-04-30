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

bool spaceCheck(string stringForCheck)
{

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

    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;
        pOne[i] = cards[randomIndex];

        //set whitespace element for future checks
        cards[randomIndex].erase(0);
    }

    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;
        pTwo[i] = cards[randomIndex];

        //set whitespace element for future checks
        cards[randomIndex].erase(0);
    }
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



void buildPyramid()
{

}

int main()
{
    fillingCardArrays();
    RandomizingPlayerCardsInput();
    shuffle_array();
    buildPyramid();
}