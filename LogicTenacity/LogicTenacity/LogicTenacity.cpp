#include <iostream>
#include <string>
#include <vector>
using namespace std;

//all cards
string cards[48];
string baseCards[6];

//stage 3 and 4
char notCards[2];

//players  
//gamemode 1
string pOne[18], pTwo[18];


void fillingArrays()
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

void RandomizingArrayOutput()
{
    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;
        pOne[i] = cards[randomIndex];

        //delete the element that's in the pOne array
        cards[randomIndex].erase(0);
    }

    for (int i = 0; i < 4; i++)
    {
        //gets random index from array
        int randomIndex = rand() % 48;


        pTwo[i] = cards[randomIndex];

        //delete the element that's in the pTwo array
        cards[randomIndex].erase(0);
    }

    for (int i = 0; i < 48; i++) {
        cout << cards[i] << " ";
    }

}

int main()
{
    fillingArrays();
    RandomizingArrayOutput();
}