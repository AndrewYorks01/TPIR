/// Small prize games are stored here.

#ifndef SMALLPRIZE_H_INCLUDED
#define SMALLPRIZE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <list>
#include <algorithm>

#include "prize.h"

using namespace std;

/// Shows the remaining boxes in numerical order. Uses a bubble sort to sort the remaining boxes.
void showRemainingBoxes(int arr[], int left)
{
    int temp;
    int iter;
    int index;

    if (left == 16){
        cout << endl << "1  2  3  4  5  6  7  8";
        cout << endl << "9 10 11 12 13 14 15 16";
        }
    else if (left == 8){
        int eights[8];
        for (int x = 0; x < 8; x++)
            eights[x] = arr[x];
        for (iter = 1; iter < 8; iter++)
        {
            for (index = 0; index < 8-iter; index++)
            {
            if (eights[index] > eights[index + 1])
            {
                temp = eights[index];
                eights[index] = eights[index+1];
                eights[index+1] = temp;
            }
            }
        } // end bubble sort
        cout << endl;
        for (int w = 0; w < 8; w++)
            cout << eights[w] << " ";
    } /// end if there are 8
    else if (left == 4){
        int fours[4];
        for (int v = 0; v < 4; v++)
            fours[v] = arr[v];
        for (iter = 1; iter < 4; iter++)
        {
            for (index = 0; index < 4-iter; index++)
            {
            if (fours[index] > fours[index + 1])
            {
                temp = fours[index];
                fours[index] = fours[index+1];
                fours[index+1] = temp;
            }
            }
        } // end bubble sort
        cout << endl;
        for (int u = 0; u < 4; u++)
            cout << fours[u] << " ";
    } /// end if there are 4
    else{
        int one = arr[0];
        int two = arr[1];
        if (one < two)
            cout << endl << one << " " << two;
        else
            cout << endl << two << " " << one;
    }
}

/// Reverses the digits of a 2-digit number. This is used in Joker.
int invert(int n){
    if (n > 99)
        return 0;
    else if (n < 10)
        return 0;
    else if ( (n % 10) == 0)
        return 0;
    else if ( (n % 11) == 0)
        return 0;
    else{
        int digits[2];
        digits[0] = n / 10 % 10;
        digits[1] = n % 10;
        int result = digits[1]*10 + digits[0];
        return result;
    }
}

/// Shows a domino in Domino Game.
void showDomino(bool arr[]){
    cout << endl;
    if (arr[1])
        cout << "O";
    else
        cout << "*";
    cout << " ";
    if (arr[2])
        cout << "O";
    else
        cout << "*";
    cout << endl << " ";
    if (arr[3])
        cout << "O";
    else
        cout << "*";
    cout << endl;
    if (arr[4])
        cout << "O";
    else
        cout << "*";
    cout << " ";
    if (arr[5])
        cout << "O";
    else
        cout << "*";
    cout << endl << "---";
    cout << endl;
    if (arr[6])
        cout << "O";
    else
        cout << "*";
    cout << " ";
    if (arr[7])
        cout << "O";
    else
        cout << "*";
    cout << endl << " ";
    if (arr[8])
        cout << "O";
    else
        cout << "*";
    cout << endl;
    if (arr[9])
        cout << "O";
    else
        cout << "*";
    cout << " ";
    if (arr[0])
        cout << "O";
    else
        cout << "*";
}

/// Shows a domino in Domino Game, with the unfilled spaces being labeled.
void showPlayerDomino(bool arr[]){
    cout << endl;
    if (arr[1])
        cout << "O";
    else
        cout << "1";
    cout << " ";
    if (arr[2])
        cout << "O";
    else
        cout << "2";
    cout << endl << " ";
    if (arr[3])
        cout << "O";
    else
        cout << "3";
    cout << endl;
    if (arr[4])
        cout << "O";
    else
        cout << "4";
    cout << " ";
    if (arr[5])
        cout << "O";
    else
        cout << "5";
    cout << endl << "---";
    cout << endl;
    if (arr[6])
        cout << "O";
    else
        cout << "6";
    cout << " ";
    if (arr[7])
        cout << "O";
    else
        cout << "7";
    cout << endl << " ";
    if (arr[8])
        cout << "O";
    else
        cout << "8";
    cout << endl;
    if (arr[9])
        cout << "O";
    else
        cout << "9";
    cout << " ";
    if (arr[0])
        cout << "O";
    else
        cout << "0";
}

/// Back to '72
void playBackTo72()
{
    /// Fun fact: This was the 50th game completed!

    /// Items under $100
    list<small> firstItems;
    list<small>::iterator firstItemIt;

    /// Items over $100
    list<small> secondItems;
    list<small>::iterator secondItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;
    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;
    inFile.open("./prizes/small72.txt");
    while (inFile)
    {
       pptr = new small;
       if (inFile >> t_Description >> t_ShortName >> t_Price)
       {
           pptr->setDescription(t_Description);
           pptr->setShortName(t_ShortName);
           pptr->setPrice(t_Price);
           if (t_Price < 100)
           {
               firstItems.push_back(*pptr);
               i++;
           }
           else
           {
               secondItems.push_back(*pptr);
               j++;
           }
       }
    } // end while loop
    inFile.close();

    cout << "BACK TO '72" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.

    /// Generate a randomization field for products under $100 and a single random number for products over $100.
    int randomizationField[i];
    int randomHigher = rand() % j;

    for (int r = 0; r < i; r++)
    {
        randomizationField[r] = r;
    }

    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    int z2 = 0;
    small items[3];

    /// Set the two small prizes under $100
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        firstItemIt = firstItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            firstItemIt++;
        }

        items[itemCount].setDescription(firstItemIt->getDescription());
        items[itemCount].setShortName(firstItemIt->getShortName());
        items[itemCount].setPrice(firstItemIt->getPrice());
    }

    /// Set the price of the third item
    secondItemIt = secondItems.begin();
    for (z2 = 0; z2 < randomHigher; z2++)
        secondItemIt++;
    items[2].setDescription(secondItemIt->getDescription());
    items[2].setShortName(secondItemIt->getShortName());
    items[2].setPrice(secondItemIt->getPrice());

    int bank = 50;
    bool won = false;
    //int on = 0;
    int bid1;
    int bid2;
    int bid3;

    cout << endl << "Range left: $" << bank;
    cout << endl << "1. ";
    items[0].showPrize();
    if (items[0].getPrice() <= 25)
        cout << endl << "The price is between $0 and $50";
    else if (items[0].getPrice() <= 50)
        cout << endl << "The price is between $25 and $75";
    else if (items[0].getPrice() <= 75)
        cout << endl << "The price is between $50 and $100";
    else
        cout << endl << "The price is between $75 and $125";
    cout << endl << "How much do you think the item cost in 1972?: $";
    cin >> bid1;
    cout << endl << "The actual retail price is ";
    items[0].showARP();
    cout << endl << "For a difference of $" << abs(bid1 - items[0].getPrice());
    bank -= abs(bid1 - items[0].getPrice());
    cout << endl;
    if (bank >= 0)
    {
        cout << endl << "Range left: $" << bank;
        cout << endl << "2. ";
        items[1].showPrize();
        if (items[1].getPrice() <= 25)
        cout << endl << "The price is between $0 and $50";
        else if (items[1].getPrice() <= 50)
        cout << endl << "The price is between $25 and $75";
        else if (items[1].getPrice() <= 75)
        cout << endl << "The price is between $50 and $100";
        else
        cout << endl << "The price is between $75 and $125";
        cout << endl << "How much do you think the item cost in 1972?: $";
        cin >> bid2;
        cout << endl << "The actual retail price is ";
        items[1].showARP();
        cout << endl << "For a difference of $" << abs(bid2 - items[1].getPrice());
        bank -= abs(bid2 - items[1].getPrice());
        cout << endl;
        if (bank >= 0)
        {
        cout << endl << "Range left: $" << bank;
        cout << endl << "3. ";
        items[2].showPrize();
        if (items[2].getPrice() <= 125)
            cout << endl << "The price is between $50 and $150";
        else if (items[2].getPrice() <= 150)
            cout << endl << "The price is between $75 and $175";
        else if (items[2].getPrice() <= 175)
            cout << endl << "The price is between $100 and $200";
        else
            cout << endl << "The price is between $125 and $225";
        cout << endl << "How much do you think the item cost in 1972?: $";
        cin >> bid3;
        cout << endl << "The actual retail price is ";
        items[2].showARP();
        cout << endl << "For a difference of $" << abs(bid3 - items[2].getPrice());
        bank -= abs(bid3 - items[2].getPrice());
        cout << endl;
        if (bank >= 0){
            cout << endl << "Range left: $" << bank;
            cout << endl << "Congratulations, you win!";
            }
        else
            cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    }
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Balance Game ('84)
void playBalanceGame84()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 100) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "BALANCE GAME ('84)" << endl;

    small tempItems[5];

    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    /// Set first item
    first = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    tempItems[0].setDescription(gameItemIt->getDescription());
    tempItems[0].setShortName(gameItemIt->getShortName());
    tempItems[0].setPrice(gameItemIt->getPrice());

    /// Set second item
    bool setSecond = false;
    while (!setSecond){
        int difference = 10;
        second = first;
        while (second == first)
            second = rand() % i;
        gameItemIt = gameItems.begin();
        for (int z = 0; z < second; z++)
            gameItemIt++;
        difference = abs(tempItems[0].getPrice() - (gameItemIt->getPrice()) );
        if (difference <= 5){
            tempItems[1].setDescription(gameItemIt->getDescription());
            tempItems[1].setShortName(gameItemIt->getShortName());
            tempItems[1].setPrice(gameItemIt->getPrice());
            setSecond = true;
        }
    }

    /// Set third item
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    tempItems[2].setDescription(gameItemIt->getDescription());
    tempItems[2].setShortName(gameItemIt->getShortName());
    tempItems[2].setPrice(gameItemIt->getPrice());

    /// Set fourth item
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    tempItems[3].setDescription(gameItemIt->getDescription());
    tempItems[3].setShortName(gameItemIt->getShortName());
    tempItems[3].setPrice(gameItemIt->getPrice());

    /// Set fifth item
    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fifth; z++)
        gameItemIt++;
    tempItems[4].setDescription(gameItemIt->getDescription());
    tempItems[4].setShortName(gameItemIt->getShortName());
    tempItems[4].setPrice(gameItemIt->getPrice());

    int dollars = 5;
    bool placedOnLeft = false;
    bool placedOnRight = false;
    bool usedAllItems = false;
    bool won = false;
    bool lost = false;

    int leftSide = 0;
    int rightSide = 0;

    int ids[5] = {0, 1, 2, 3, 4};
    random_shuffle(&ids[0], &ids[5]);

    small items[5];

    for (int i = 0; i < 5; i++){
        items[i].setDescription(tempItems[ids[i]].getDescription());
        items[i].setShortName(tempItems[ids[i]].getShortName());
        items[i].setPrice(tempItems[ids[i]].getPrice());
    }

    bool used[5];
    for (int u = 0; u < 5; u++)
        used[u] = false;

    while ( (!won) && (!lost) ){
        cout << endl << "Barker Silver Dollars: " << dollars;
        cout << endl << "$" << leftSide << " ___ " << "$" << rightSide;

        cout << endl;

        for (int k = 0; k < 5; k++){
            cout << endl << k+1 << ". ";
            items[k].showPrize();
            if (used[k])
                cout << " - $" << items[k].getPrice();
        }
        cout << endl << "6. Place a Barker Silver Dollar";
        int choice = 0;
        char side = '!';
        while ( (choice < 1) || (choice > 6) ){
            cout << endl << "What do you want to place on the scale?: ";
            cin >> choice;
        }
        if ( (choice < 6) && (used[choice-1]) )
            cout << endl << "You've already picked this item. Please pick another.";

        else if ( (choice < 6) && (!used[choice-1]) ) {
        while ( (side != 'L') && (side != 'l') && (side != 'R') && (side != 'r') ){
            cout << endl << "Do you want to place it on the left (L) or the right (R)?: ";
            cin >> side;
        }
        used[choice-1] = true;
        cout << endl << "The actual retail price of the ";
        items[choice-1].showShortName();
        cout << " is $" << items[choice-1].getPrice();
        if ( (side == 'L') || (side == 'l') )
            leftSide += items[choice-1].getPrice();
        else
            rightSide += items[choice-1].getPrice();
        cout << endl;
        } // place an item

        else{
        if (dollars == 0)
            cout << endl << "You're out of Barker Silver Dollars.";
        else if ( (!used[0]) && (!used[1]) && (!used[2]) && (!used[3]) && (!used[4]) )
            cout << endl << "You need to place an item on the scale first.";
        else{
        while ( (side != 'L') && (side != 'l') && (side != 'R') && (side != 'r') ){
            cout << endl << "Do you want to place it on the left (L) or the right (R)?: ";
            cin >> side;
        }
        if ( (side == 'L') || (side == 'l') )
            leftSide += 1;
        else
            rightSide += 1;
        dollars -= 1;
        }
        } // place a Barker Silver Dollar

    if ( ((leftSide == rightSide)) && ( (used[0]) || (used[1]) || (used[2]) || (used[3]) || (used[4]) ) )
        won = true;
    else if ( (used[0]) && (used[1]) && (used[2]) && (used[3]) && (used[4]) && (abs(leftSide-rightSide) > 5) )
        lost = true;

    } // end while

    cout << endl << "$" << leftSide << " ___ " << "$" << rightSide;

    if (won)
        cout << endl << "Congratulations, you win!";
    if (lost)
        cout << endl << "The scale can't be balanced... Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Bonus Game
void playBonusGame()
{
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice))
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "BONUS GAME" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[4];
    bool spotControlled[4];
    bool spaceStatus[4]; // one of these has the bonus, the other three do not
    int wrongPrices[4]; // these will become the wrong prices

    /// Pick one of the four windows to have the bonus spot.
    int bonusSpot;
    bonusSpot = rand() % 4;
    spaceStatus[bonusSpot] = true;

    /// Make sure the player hasn't controlled any spots.
    for (int init = 0; init < 4; init++)
        spotControlled[init] = false;

    /// Generate four integers that are either 0 or 1. If the integer is 0, the corresponding price will be too
    /// low, and the correct answer will be HIGHER. If the integer is 1, the corresponding price will be too high,
    /// and the correct answer will be LOWER.
    int wrongValues[4];
    for (int q = 0; q < 4; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

    /// This line will only be used for debugging and is commented out once the game is finished.
    //cout << "The bonus is behind prize #" << bonusSpot + 1 << endl;

    /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    char answer = 'x';

    /// Generate the wrong prices.
    for (int w = 0; w < 4; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// the correct answer will be HIGHER. The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// the correct answer will be LOWER. The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (51 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    }
    cout << endl;


    /// The main gameplay.
    for (int start = 0; start < 4; start++)
    {
        cout << start+1 << ". ";
        items[start].showPrize();
        cout << endl << "$" << wrongPrices[start];
        while ( (answer != 'H') && (answer != 'L') &&  (answer != 'h') && (answer != 'l') ){
        cout << endl << "This price is wrong. \nIs the correct price higher (H) or lower (L)?: ";
        cin >> answer;
        } /// end while loop
        if ((answer == 'H') || (answer == 'h'))
        {
            cout << "The actual retail price is ";
            items[start].showARP();
            if ((items[start].getPrice() >= wrongPrices[start])){
                cout << endl << "That's correct! You've earned control of this space.";
                spotControlled[start] = true;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item.";
            }

            cout << endl;
        }
        else
        {
            cout << "The actual retail price is ";
            items[start].showARP();
            if (items[start].getPrice() <= wrongPrices[start]){
                cout << endl << "That's correct! You've earned control of this space.";
                spotControlled[start] = true;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item.";
            }
            cout << endl;
        }
        answer = 'X';
        cout << endl;
    } // end for loop

    cout << "The bonus is behind window #" << bonusSpot + 1 << endl;
    if (spotControlled[bonusSpot] == true)
        cout << "Congratulations, you win!" << endl;
    else
    {
        if ((spotControlled[0] == false) && (spotControlled[1] == false) && (spotControlled[2] == false) && (spotControlled[3] == false))
            cout << "Well... you're not the biggest loser, but you're in the top five." << endl;
        else
            cout << "Sorry, you didn't win." << endl;
    }

    inFile.close();
    system("pause");
    system("CLS");

}

/// Cliff Hangers
void playCliffHangers()
{

    /// items between $15 and $24
    list<small> firstItems;
    list<small>::iterator firstItemIt;
    //cout << "\n***generated first list\n";

    /// items between $25 and $34
    list<small> secondItems;
    list<small>::iterator secondItemIt;
    //cout << "\n***generated second list\n";

    /// items between $35 and $44
    list<small> thirdItems;
    list<small>::iterator thirdItemIt;
    //cout << "\n***generated third list\n";

    string t_cliffDescription;
    string t_cliffShortName;
    int     t_cliffPrice;

    small * cliffptr;

    srand(time(0));

    int i = 0;

    int ofType1 = 0;
    int ofType2 = 0;
    int ofType3 = 0;
    //cout << "\n***initialized other values\n";

    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        cliffptr = new small;
        if ((inFile >> t_cliffDescription >> t_cliffShortName >> t_cliffPrice) && t_cliffPrice >= 15 && t_cliffPrice <= 50)
        {
            cliffptr->setDescription(t_cliffDescription);
            cliffptr->setShortName(t_cliffShortName);
            cliffptr->setPrice(t_cliffPrice);
            if (t_cliffPrice >= 15 && t_cliffPrice <= 28){
                firstItems.push_back(*cliffptr);
                ofType1++;
                }
            else if (t_cliffPrice >= 28 && t_cliffPrice <= 41){
                secondItems.push_back(*cliffptr);
                ofType2++;
                }
            else{
                thirdItems.push_back(*cliffptr);
                ofType3++;
                }

            i++;
        }
    } // end while loop
    inFile.close();
    //cout << "\n***successfully read and sorted data\n";


    cout << "CLIFF HANGERS" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.

    /// There are three randomization fields, one for each bank of small prizes.
    int randomizationField[ofType1];
    int randomizationField2[ofType2];
    int randomizationField3[ofType3];
    //cout << "\n***generated randomization fields\n";

    //cout << ofType1 << ", " << ofType2 << ", " << ofType3 << endl;


    /// Initialize the sequences of numbers
    for (int j = 0; j < ofType1; j++)
    {
        randomizationField[j] = j;
    }
    for (int j2 = 0; j2 < ofType2; j2++)
    {
        randomizationField2[j2] = j2;
    }
    for (int j3 = 0; j3 < ofType3; j3++)
    {
        randomizationField3[j3] = j3;
    }

    //cout << "\n***loaded data into randomization fields\n";


    // rearrange the numbers
    for (int k = ofType1-1; k > 0; k--)
    {
        int l = rand()%k;
        int t = randomizationField[k];
        randomizationField[k] = randomizationField[l];
        randomizationField[l] = t;
    }
    for (int k2 = ofType2-1; k2 > 0; k2--)
    {
        int l2 = rand()%k2;
        int t2 = randomizationField2[k2];
        randomizationField2[k2] = randomizationField2[l2];
        randomizationField2[l2] = t2;
    }
    for (int k3 = ofType3-1; k3 > 0; k3--)
    {
        int l3 = rand()%k3;
        int t3 = randomizationField3[k3];
        randomizationField3[k3] = randomizationField3[l3];
        randomizationField3[l3] = l3;
    }


    int z = 0;
    small items[3];
    bool prizeChosen[3]; /// determines if the randomizer has picked an item in each price range
    int climberSteps = 0;
    int temp = 0; /// temporarily holds the item's price
    bool lost = false;
    bool won = false;
    //cout << "\n***initialized more data\n";


    /// Set each item

    firstItemIt = firstItems.begin();
    int getTo1 = (rand() % ofType1);
    //cout << "\n***random = " << getTo1 << endl;
    /*
    for (int g = 0; g < getTo1; g++){
        while (firstItemIt != firstItems.end()){
            firstItemIt++;}
        // cout << g;
    }*/
    advance(firstItemIt, getTo1);
    items[0].setDescription(firstItemIt->getDescription());
    items[0].setShortName(firstItemIt->getShortName());
    items[0].setPrice(firstItemIt->getPrice());

    secondItemIt = secondItems.begin();
    int getTo2 = (rand() % ofType2);
    //cout << "\n***random = " << getTo2 << endl;
    advance(secondItemIt, getTo2);
    items[1].setDescription(secondItemIt->getDescription());
    items[1].setShortName(secondItemIt->getShortName());
    items[1].setPrice(secondItemIt->getPrice());

    thirdItemIt = thirdItems.begin();
    int getTo3 = (rand() % ofType3);
    //cout << "\n***random = " << getTo3 << endl;
    advance(thirdItemIt, getTo3);
    items[2].setDescription(thirdItemIt->getDescription());
    items[2].setShortName(thirdItemIt->getShortName());
    items[2].setPrice(thirdItemIt->getPrice());

    /*
        for (int b = 0; b < 3; b++)
        {
            items[b].showPrize();
            cout << endl;
            items[b].showARP();
            cout << endl;
        }
    */

    int guess1 = 0;
    int guess2 = 0;
    int guess3 = 0;

    int difference1 = 0;
    int difference2 = 0;
    int difference3 = 0;


    while ((!lost) && (!won)){

    /// Prize #1
    cout << endl;
    cout << "Position: " << climberSteps << endl;
    cout << "1. ";
    items[0].showPrize();
    cout << endl << "What is the price?: $";
    cin >> guess1;
    cout << "The actual retail price is ";
    items[0].showARP();
    int difference1 = abs(guess1 - items[0].getPrice());
    climberSteps += difference1;
    if (difference1 == 0)
        cout << endl << "You were exactly right!";
    if (difference1 != 0)
        cout << endl << "You were off by $" << difference1;
    if (climberSteps > 25)
        lost = true;

    if (climberSteps <= 25){
    /// Prize #2
    cout << endl << endl;
    cout << "Position: " << climberSteps << endl;
    cout << "2. ";
    items[1].showPrize();
    cout << endl << "What is the price?: $";
    cin >> guess2;
    cout << "The actual retail price is ";
    items[1].showARP();
    int difference2 = abs(guess2 - items[1].getPrice());
    climberSteps += difference2;
    if (difference2 == 0)
        cout << endl << "You were exactly right!";
    if (difference2 != 0)
        cout << endl << "You were off by $" << difference2;
    if (climberSteps > 25)
        lost = true;
    }

    if (climberSteps <= 25){
    /// Prize #3
    cout << endl << endl;
    cout << "Position: " << climberSteps << endl;
    cout << "3. ";
    items[2].showPrize();
    cout << endl << "What is the price?: $";
    cin >> guess3;
    cout << "The actual retail price is ";
    items[2].showARP();
    int difference3 = abs(guess3 - items[2].getPrice());
    climberSteps += difference3;
    if (difference3 == 0)
        cout << endl << "You were exactly right!";
    if (difference3 != 0)
        cout << endl << "You were off by $" << difference3;
    if (climberSteps > 25)
        lost = true;
    }

    if (!lost)
        won = true;
    }

    cout << endl << endl;
    if (won){
        cout << "Position: " << climberSteps << endl;
        cout << "Congratulations, you win!" << endl;
    }
    else
        cout << "Sorry, you lose." << endl;

    system("pause");
    system("CLS");

    //cout << "end";
}

/// Domino Game
void playDominoGame()
{
    /// Credit to CBach88 for making this game!
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice))
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "DOMINO GAME" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[4];

    int space1 = rand() % 10;

    int space2 = space1;
    while (space2 == space1)
        space2 = rand() % 10;

    int space3 = space1;
    while ( (space3 == space1) || (space3 == space2) )
        space3 = rand() % 10;

    int space4 = space1;
    while ( (space4 == space1) || (space4 == space2) || (space4 == space3) )
        space4 = rand() % 10;

    int space5 = space1;
    while ( (space5 == space1) || (space5 == space2) || (space5 == space3) || (space5 == space4) )
        space5 = rand() % 10;

    //cout << endl << space1 << ", " << space2 << ", " << space3 << ", " << space4 << ", " << space5;

    bool chosenGameDomino[10];
    for (int d = 0; d < 10; d++){
        if ( (d == space1) || (d == space2) || (d == space3) || (d == space4) || (d == space5) )
            chosenGameDomino[d] = true;
        else
            chosenGameDomino[d] = false;
    }

//    showDomino(chosenGameDomino);

//    cout << endl;
//    cout << endl << "1 2";
//    cout << endl << " 3";
//    cout << endl << "4 5";
//    cout << endl << "---";
//    cout << endl << "6 7";
//    cout << endl << " 8";
//    cout << endl << "9 0";

    bool chosenPlayerDomino[10];
    for (int p = 0; p < 10; p++)
        chosenPlayerDomino[p] = false;

    showPlayerDomino(chosenPlayerDomino);

    int firstNo = 10;
    while ((firstNo < 0) || (firstNo > 9)){
        cout << endl << "Which space do you want a dot to go on the domino?: ";
        cin >> firstNo;
    }
    chosenPlayerDomino[firstNo] = true;
    showDomino(chosenPlayerDomino);

    int earnedDots = 0;
    int wrongPrices[4]; // these will become the wrong prices

    /// Generate four integers that are either 0 or 1. If the integer is 0, the corresponding price will be too
    /// low, and the correct answer will be HIGHER. If the integer is 1, the corresponding price will be too high,
    /// and the correct answer will be LOWER.
    int wrongValues[4];
    for (int q = 0; q < 4; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

   /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    char answer = 'x';

    /// Generate the wrong prices.
    for (int w = 0; w < 4; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// the correct answer will be HIGHER. The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// the correct answer will be LOWER. The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (51 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    }
    cout << endl;

    for (int s = 0; s < 4; s++){
    int place = 10;
    cout << endl << s+1 << ". ";
    items[s].showPrize();
    cout << endl << "$" << wrongPrices[s];
    while ( (answer != 'H') && (answer != 'L') &&  (answer != 'h') && (answer != 'l') ){
    cout << endl << "This price is wrong. \nIs the correct price higher (H) or lower (L)?: ";
        cin >> answer;
    } /// end while loop
    if ((answer == 'H') || (answer == 'h'))
    {
        cout << "The actual retail price is ";
        items[s].showARP();
        if ((items[s].getPrice() >= wrongPrices[s])){
            cout << endl << "That's correct! You can place another dot on the board.";
            showPlayerDomino(chosenPlayerDomino);
            while ( ((place < 0) || (place > 9)) || (chosenPlayerDomino[place]) ){
            cout << endl << "Which space do you want a dot to go on the domino?: ";
                cin >> place;
            } // end while
            chosenPlayerDomino[place] = true;
            earnedDots += 1;
            }
        else
            cout << endl << "Sorry, that's not correct. You don't win this item.";
    }
    else
    {
        cout << "The actual retail price is ";
        items[s].showARP();
        if ((items[s].getPrice() <= wrongPrices[s])){
        cout << endl << "That's correct! You can place another dot on the board.";
        showPlayerDomino(chosenPlayerDomino);
            while ( ((place < 0) || (place > 9)) || (chosenPlayerDomino[place]) ){
            cout << endl << "Which space do you want a dot to go on the domino?: ";
                cin >> place;
            } // end while
            chosenPlayerDomino[place] = true;
            earnedDots += 1;
            }
        else
            cout << endl << "Sorry, that's not correct. You don't win this item.";
    }
    answer = 'X';
    showDomino(chosenPlayerDomino);
    } // end for loop

    int matches = 0;
    cout << endl << "Let's see how much money you've earned...";
    cout << endl;
    system("pause");

    showDomino(chosenGameDomino);
    for (int m = 0; m < 10; m++){
    if (chosenGameDomino[m] && chosenPlayerDomino[m])
        matches += 1;
    }

    if (matches == 1)
        cout << endl << "You have 1 matching spot.";
    else
        cout << endl << "You have " << matches << " matching spots.";
    if (matches == 5)
        cout << endl << "Congratulations, you win $25,000!";
    else if (matches == 4)
        cout << endl << "You've won $7500. Thanks for playing!";
    else if (matches == 3)
        cout << endl << "You've won $5000. Thanks for playing!";
    else if (matches == 2)
        cout << endl << "You've won $2500. Thanks for playing!";
    else if (matches == 1)
        cout << endl << "You've won $1000. Thanks for playing!";
    else
        cout << endl << "Sorry, you didn't win any money.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Finish Line
void playFinishLine()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 100) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "FINISH LINE" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[6];
    int kept = 0;
    int gave = 0;

    /// Set the items
    for (int itemCount = 0; itemCount < 6; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        items[itemCount].setDescription(gameItemIt->getDescription());
        items[itemCount].setShortName(gameItemIt->getShortName());
        items[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Begin the game
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    /// First pair of prizes
    cout << endl << "Horse: $" << kept;
    cout << endl << "Finish line: $" << gave;
    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl << "2. ";
    items[1].showPrize();
    while ( (choice1 < 1) || (choice1 > 2) ){
    cout << endl << "Which prize do you want to select?: ";
    cin >> choice1;
    }
    if (choice1 == 1)
    {
        cout << endl << "You chose the ";
        items[0].showShortName();
        cout << ". \nThe ";
        items[1].showShortName();
        cout << " is $" << items[1].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[1].getPrice();
    }
    else
    {
        cout << endl << "You chose the ";
        items[1].showShortName();
        cout << ". \nThe ";
        items[0].showShortName();
        cout << " is $" << items[0].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[0].getPrice();
    }

    cout << endl;
    /// Second pair of prizes
    cout << endl << "Horse: $" << kept;
    cout << endl << "Finish line: $" << gave;
    cout << endl << "1. ";
    items[2].showPrize();
    cout << endl << "2. ";
    items[3].showPrize();
    while ( (choice2 < 1) || (choice2 > 2) ){
    cout << endl << "Which prize do you want to select?: ";
    cin >> choice2;
    }
    if (choice2 == 1)
    {
        cout << endl << "You chose the ";
        items[2].showShortName();
        cout << ". \nThe ";
        items[3].showShortName();
        cout << " is $" << items[3].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[3].getPrice();
    }
    else
    {
        cout << endl << "You kept the ";
        items[3].showShortName();
        cout << ". \nThe ";
        items[2].showShortName();
        cout << " is $" << items[2].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[2].getPrice();
    }

    cout << endl;
    /// Third pair of prizes
    cout << endl << "Horse: $" << kept;
    cout << endl << "Finish line: $" << gave;
    cout << endl << "1. ";
    items[4].showPrize();
    cout << endl << "2. ";
    items[5].showPrize();
    while ( (choice3 < 1) || (choice3 > 2) ){
    cout << endl << "Which prize do you want to select?: ";
    cin >> choice3;
    }
    if (choice3 == 1)
    {
        cout << endl << "You chose the ";
        items[4].showShortName();
        cout << ". \nThe ";
        items[5].showShortName();
        cout << " is $" << items[5].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[5].getPrice();
    }
    else
    {
        cout << endl << "You chose the ";
        items[5].showShortName();
        cout << ". \nThe ";
        items[4].showShortName();
        cout << " is $" << items[4].getPrice() << "\nand the finish line will be moved that far.";
        gave += items[4].getPrice();
    }

    cout << endl << "Let's start the race and see if your horse crosses the finish line." << endl;
    system("pause");

    /// First pair
    if (choice1 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[0].showShortName();
        cout << endl << "is $" << items[0].getPrice();
        kept += items[0].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[1].showShortName();
        cout << endl << "is $" << items[1].getPrice();
        kept += items[1].getPrice();
    }
    cout << endl << "Horse's distance: " << kept;
    cout << endl << "Finish line: " << gave;
    cout << endl;
    system("pause");

    /// Second pair
    if (choice2 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[2].showShortName();
        cout << endl << "is $" << items[2].getPrice();
        kept += items[2].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[3].showShortName();
        cout << endl << "is $" << items[3].getPrice();
        kept += items[3].getPrice();
    }
    cout << endl << "Horse's distance: " << kept;
    cout << endl << "Finish line: " << gave;
    cout << endl;
    system("pause");

    /// Third pair
    if (choice3 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[4].showShortName();
        cout << endl << "is $" << items[4].getPrice();
        kept += items[4].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[5].showShortName();
        cout << endl << "is $" << items[5].getPrice();
        kept += items[5].getPrice();
    }
    cout << endl << "Horse's distance: " << kept;
    cout << endl << "Finish line: " << gave;
    cout << endl;

    if (kept >= gave)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Give or Keep
void playGiveOrKeep()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 100) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "GIVE OR KEEP" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[6];
    int kept = 0;
    int gave = 0;

    /// Set the items
    for (int itemCount = 0; itemCount < 6; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        items[itemCount].setDescription(gameItemIt->getDescription());
        items[itemCount].setShortName(gameItemIt->getShortName());
        items[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Begin the game
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    /// First pair of prizes
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl << "2. ";
    items[1].showPrize();
    while ( (choice1 < 1) || (choice1 > 2) ){
    cout << endl << "Which prize do you want to keep?: ";
    cin >> choice1;
    }
    if (choice1 == 1)
    {
        cout << endl << "You kept the ";
        items[0].showShortName();
        cout << ". \nThe ";
        items[1].showShortName();
        cout << " is $" << items[1].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[1].getPrice();
    }
    else
    {
        cout << endl << "You kept the ";
        items[1].showShortName();
        cout << ". \nThe ";
        items[0].showShortName();
        cout << " is $" << items[0].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[0].getPrice();
    }

    cout << endl;
    /// Second pair of prizes
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl << "1. ";
    items[2].showPrize();
    cout << endl << "2. ";
    items[3].showPrize();
    while ( (choice2 < 1) || (choice2 > 2) ){
    cout << endl << "Which prize do you want to keep?: ";
    cin >> choice2;
    }
    if (choice2 == 1)
    {
        cout << endl << "You kept the ";
        items[2].showShortName();
        cout << ". \nThe ";
        items[3].showShortName();
        cout << " is $" << items[3].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[3].getPrice();
    }
    else
    {
        cout << endl << "You kept the ";
        items[3].showShortName();
        cout << ". \nThe ";
        items[2].showShortName();
        cout << " is $" << items[2].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[2].getPrice();
    }

    cout << endl;
    /// Third pair of prizes
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl << "1. ";
    items[4].showPrize();
    cout << endl << "2. ";
    items[5].showPrize();
    while ( (choice3 < 1) || (choice3 > 2) ){
    cout << endl << "Which prize do you want to keep?: ";
    cin >> choice3;
    }
    if (choice3 == 1)
    {
        cout << endl << "You kept the ";
        items[4].showShortName();
        cout << ". \nThe ";
        items[5].showShortName();
        cout << " is $" << items[5].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[5].getPrice();
    }
    else
    {
        cout << endl << "You kept the ";
        items[5].showShortName();
        cout << ". \nThe ";
        items[4].showShortName();
        cout << " is $" << items[4].getPrice() << "\nand its price will go in the GIVE column.";
        gave += items[4].getPrice();
    }

    cout << endl << "Now let's see how much you kept." << endl;
    system("pause");

    /// First pair
    if (choice1 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[0].showShortName();
        cout << endl << "is $" << items[0].getPrice();
        kept += items[0].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[1].showShortName();
        cout << endl << "is $" << items[1].getPrice();
        kept += items[1].getPrice();
    }
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl;
    system("pause");

    /// Second pair
    if (choice2 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[2].showShortName();
        cout << endl << "is $" << items[2].getPrice();
        kept += items[2].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[3].showShortName();
        cout << endl << "is $" << items[3].getPrice();
        kept += items[3].getPrice();
    }
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl;
    system("pause");

    /// Third pair
    if (choice3 == 1)
    {
        cout << endl << "The actual retail price of the ";
        items[4].showShortName();
        cout << endl << "is $" << items[4].getPrice();
        kept += items[4].getPrice();
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        items[5].showShortName();
        cout << endl << "is $" << items[5].getPrice();
        kept += items[5].getPrice();
    }
    cout << endl << "KEEP: $" << kept;
    cout << endl << "GIVE: $" << gave;
    cout << endl;

    if (kept >= gave)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Half Off
void playHalfOff(bool mds, bool mdg)
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "1/2 OFF" << endl;

    if (mdg){
    cout << endl;
    cout << endl << "This is the Million Dollar Game!";
    cout << endl << "One of these boxes contains $25,000, but";
    cout << endl << "another contains a check for $1,000,000!";
    cout << endl << "If you win the $25,000, you can risk it to";
    cout << endl << "find the box containing the $1,000,000!";
    cout << endl << endl;
    }

    small prizes[6];

    /// These will ensure that the prices of the half-off items are always even numbers, so we don't generate weird decimal prices.
    bool foundFirst = false;
    bool foundSecond = false;
    bool foundThird = false;

    /// Determines the side on which each "half-off" prize will appear.
    int side1 = rand() % 2;
    int side2 = rand() % 2;
    int side3 = rand() % 2;

    small tempItem;

    int first;
    int second;
    int third;

    while (!foundFirst)
    {
        first = rand() % i;
        gameItemIt = gameItems.begin();
        for (int z = 0; z < first; z++)
            gameItemIt++;
        tempItem.setDescription(gameItemIt->getDescription());
        tempItem.setShortName(gameItemIt->getShortName());
        tempItem.setPrice(gameItemIt->getPrice());

        if ( (tempItem.getPrice() % 2) == 0)
        {
            if (side1 == 0)
            {
                prizes[0].setDescription(tempItem.getDescription());
                prizes[0].setShortName(tempItem.getShortName());
                prizes[0].setPrice(tempItem.getPrice());
            }
            else
            {
                prizes[1].setDescription(tempItem.getDescription());
                prizes[1].setShortName(tempItem.getShortName());
                prizes[1].setPrice(tempItem.getPrice());
            }
            foundFirst = true;
        } // end if statement
    } // end while loop

    while (!foundSecond)
    {
        second = first;
        while (second == first)
            second = rand() % i;
        gameItemIt = gameItems.begin();
        for (int z2 = 0; z2 < second; z2++)
            gameItemIt++;
        tempItem.setDescription(gameItemIt->getDescription());
        tempItem.setShortName(gameItemIt->getShortName());
        tempItem.setPrice(gameItemIt->getPrice());

        if ( (tempItem.getPrice() % 2) == 0)
        {
            if (side2 == 0)
            {
                prizes[2].setDescription(tempItem.getDescription());
                prizes[2].setShortName(tempItem.getShortName());
                prizes[2].setPrice(tempItem.getPrice());
            }
            else
            {
                prizes[3].setDescription(tempItem.getDescription());
                prizes[3].setShortName(tempItem.getShortName());
                prizes[3].setPrice(tempItem.getPrice());
            }
            foundSecond = true;
        } // end if statement

    } // end while loop

    while (!foundThird)
    {
        third = first;
        while ( (third == first) || (third == second) )
            third = rand() % i;
        gameItemIt = gameItems.begin();
        for (int z3 = 0; z3 < third; z3++)
            gameItemIt++;
        tempItem.setDescription(gameItemIt->getDescription());
        tempItem.setShortName(gameItemIt->getShortName());
        tempItem.setPrice(gameItemIt->getPrice());

        if ( (tempItem.getPrice() % 2) == 0)
        {
            if (side3 == 0)
            {
                prizes[4].setDescription(tempItem.getDescription());
                prizes[4].setShortName(tempItem.getShortName());
                prizes[4].setPrice(tempItem.getPrice());
            }
            else
            {
                prizes[5].setDescription(tempItem.getDescription());
                prizes[5].setShortName(tempItem.getShortName());
                prizes[5].setPrice(tempItem.getPrice());
            }
            foundThird = true;
        } // end if statement

    } // end while loop

    /// Set the remaining prizes
    int rem1;
    int rem2;
    int rem3;

    /// Set the other prize in pair #1
    rem1 = first;
    while ( (rem1 == first) || (rem1 == second) || (rem1 == third) )
        rem1 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z4 = 0; z4 < rem1; z4++)
        gameItemIt++;
    if (side1 == 0)
    {
        prizes[1].setDescription(gameItemIt->getDescription());
        prizes[1].setShortName(gameItemIt->getShortName());
        prizes[1].setPrice(gameItemIt->getPrice());
    }
    else
    {
        prizes[0].setDescription(gameItemIt->getDescription());
        prizes[0].setShortName(gameItemIt->getShortName());
        prizes[0].setPrice(gameItemIt->getPrice());
    }

    /// Set the other prize in pair #2
    rem2 = first;
    while ( (rem2 == first) || (rem2 == second) || (rem2 == third) || (rem2 == rem1) )
        rem2 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z5 = 0; z5 < rem2; z5++)
        gameItemIt++;
    if (side2 == 0)
    {
        prizes[3].setDescription(gameItemIt->getDescription());
        prizes[3].setShortName(gameItemIt->getShortName());
        prizes[3].setPrice(gameItemIt->getPrice());
    }
    else
    {
        prizes[2].setDescription(gameItemIt->getDescription());
        prizes[2].setShortName(gameItemIt->getShortName());
        prizes[2].setPrice(gameItemIt->getPrice());
    }

    /// Set the other prize in pair #3
    rem3 = first;
    while ( (rem3 == first) || (rem3 == second) || (rem3 == third) || (rem3 == rem1) || (rem3 == rem2) )
        rem3 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z6 = 0; z6 < rem3; z6++)
        gameItemIt++;
    if (side3 == 0)
    {
        prizes[5].setDescription(gameItemIt->getDescription());
        prizes[5].setShortName(gameItemIt->getShortName());
        prizes[5].setPrice(gameItemIt->getPrice());
    }
    else
    {
        prizes[4].setDescription(gameItemIt->getDescription());
        prizes[4].setShortName(gameItemIt->getShortName());
        prizes[4].setPrice(gameItemIt->getPrice());
    }

    int boxes[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    random_shuffle(&boxes[0], &boxes[16]);
    int boxesLeft = 16;

    showRemainingBoxes(boxes, boxesLeft);

    int choice1 = 0;
    cout << endl << "1. ";
    prizes[0].showPrize();
    if (side1 == 0)
        cout << " - $" << (prizes[0].getPrice()/2);
    else
        cout << " - $" << (prizes[0].getPrice());
    cout << endl << "2. ";
    prizes[1].showPrize();
    if (side1 == 1)
        cout << " - $" << (prizes[1].getPrice()/2);
    else
        cout << " - $" << (prizes[1].getPrice());
    while ( (choice1 < 1) || (choice1 > 2)){
        cout << endl << "Which item (enter its number) is half off its ARP?: ";
        cin >> choice1;
    }
    cout << endl << "The actual retail price of the ";
    prizes[choice1-1].showShortName();
    cout << " is ";
    prizes[choice1-1].showARP();

    if ( (choice1-1) == side1)
    {
        cout << endl << "That's correct! Let's eliminate half of the boxes.";
        boxesLeft /= 2;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl;
    showRemainingBoxes(boxes, boxesLeft);
    cout << endl;

    int choice2 = 0;
    cout << endl << "1. ";
    prizes[2].showPrize();
    if (side2 == 0)
        cout << " - $" << (prizes[2].getPrice()/2);
    else
        cout << " - $" << (prizes[2].getPrice());
    cout << endl << "2. ";
    prizes[3].showPrize();
    if (side2 == 1)
        cout << " - $" << (prizes[3].getPrice()/2);
    else
        cout << " - $" << (prizes[3].getPrice());
    while ( (choice2 < 1) || (choice2 > 2)){
        cout << endl << "Which item (enter its number) is half off its ARP?: ";
        cin >> choice2;
    }
    cout << endl << "The actual retail price of the ";
    prizes[choice2+1].showShortName();
    cout << " is ";
    prizes[choice2+1].showARP();

    if ( (choice2-1) == side2)
    {
        cout << endl << "That's correct! Let's eliminate half of the boxes.";
        boxesLeft /= 2;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl;
    showRemainingBoxes(boxes, boxesLeft);
    cout << endl;


    int choice3 = 0;
    cout << endl << "1. ";
    prizes[4].showPrize();
    if (side3 == 0)
        cout << " - $" << (prizes[4].getPrice()/2);
    else
        cout << " - $" << (prizes[4].getPrice());
    cout << endl << "2. ";
    prizes[5].showPrize();
    if (side3 == 1)
        cout << " - $" << (prizes[5].getPrice()/2);
    else
        cout << " - $" << (prizes[5].getPrice());
    while ( (choice3 < 1) || (choice3 > 2)){
        cout << endl << "Which item (enter its number) is half off its ARP?: ";
        cin >> choice3;
    }

    cout << endl << "The actual retail price of the ";
    prizes[choice3+3].showShortName();
    cout << " is ";
    prizes[choice3+3].showARP();

    if ( (choice3-1) == side3)
    {
        cout << endl << "That's correct! Let's eliminate half of the boxes.";
        boxesLeft /= 2;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl;
    showRemainingBoxes(boxes, boxesLeft);
    cout << endl;

    int boxChoice = 0;

    while ( (boxChoice < 1) || (boxChoice > 16) ){
            if (mds)
                cout << endl << "Which box contains the $25,000?: ";
            else
                cout << endl << "Which box contains the $10,000?: ";
            cin >> boxChoice;
        }

    if (boxChoice == boxes[0]){
        if (mds)
            cout << endl << "Congratulations, you won $25,000!";
        else
            cout << endl << "Congratulations, you win $10,000!";

        /// Million dollar game mode
        if (mdg){
        int mdBox = boxes[0];
        int guessBox = 0;
        while (mdBox == boxes[0])
            mdBox = (rand() % 16) + 1;
        //cout << endl << "Million dollars is in box #" << mdBox;
        char giveUp = '!';
        while ( (giveUp != 'Y') && (giveUp != 'y') && (giveUp != 'N') && (giveUp != 'n') ){
            cout << endl << "Do you want to keep the $25,000 (Y) \nor risk it for $1,000,000 (N)?: ";
            cin >> giveUp;
        }
        if ( (giveUp == 'Y') || (giveUp == 'y') )
            cout << endl << "You're keeping the $25,000. Thanks for playing!";
        else{
        cout << endl;
        for (int q = 1; q <= 8; q++){
            if (q == boxes[0])
                ;
            else
                cout << " " << q << " ";
        }
        cout << endl;
        for (int q = 9; q <= 16; q++){
            if (q == boxes[0])
                ;
            else
                cout << q << " ";
        }

        while ( (guessBox < 1) || (guessBox > 16) ){
            cout << endl << "Which box contains the check for $1,000,000?: ";
            cin >> guessBox;
        }
        if (guessBox == mdBox)
            cout << endl << "CONGRATULATIONS, YOU WIN $1,000,000!";
        else
            cout << endl << "Sorry, you lose. The $1,000,000 was in box #" << mdBox << ".";
        } // player risks the $25,000
        } /// end if Million Dollar game

        } // picked box containing cash
    else
        cout << endl << "Sorry, you lose. The money was in box #" << boxes[0] << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Hot Seat
void playHotSeat()
{
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice))
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "HOT SEAT" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }

    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[5];
    int wrongPrices[5]; // these will become the wrong prices

    /// Generate four integers that are either 0 or 1. If the integer is 0, the corresponding price will be too
    /// low, and the correct answer will be HIGHER. If the integer is 1, the corresponding price will be too high,
    /// and the correct answer will be LOWER.
    int wrongValues[4];
    for (int q = 0; q < 4; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 5; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

    /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    char answer = 'x';

    /// Generate the wrong prices.
    for (int w = 0; w < 5; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// the correct answer will be HIGHER. The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// the correct answer will be LOWER. The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (51 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    } // end for loop generating "wrong" prices

    list<small> rights;
    list<small>::iterator rightsIt;
    small * rptr;
    int gotRight = 0;

    list<small> wrongs;
    list<small>::iterator wrongsIt;
    small * wptr;
    int gotWrong = 0;

    for (int start = 0; start < 5; start++){
        answer = '!';
        cout << endl;
        cout << start+1 << ". ";
        items[start].showPrize();
        cout << endl << "$" << wrongPrices[start];
        while ( (answer != 'H') && (answer != 'L') &&  (answer != 'h') && (answer != 'l') ){
        cout << endl << "Is the correct price for this item higher (H) or lower (L)?: ";
        cin >> answer;
        } // end while loop
        if ((answer == 'H') || (answer == 'h')){
            if ((items[start].getPrice() >= wrongPrices[start])){
                rptr = new small;
                rptr->setDescription(items[start].getDescription());
                rptr->setShortName(items[start].getShortName());
                rptr->setPrice(items[start].getPrice());
                rights.push_back(*rptr);
                gotRight += 1;
            }
            else{
                wptr = new small;
                wptr->setDescription(items[start].getDescription());
                wptr->setShortName(items[start].getShortName());
                wptr->setPrice(items[start].getPrice());
                wrongs.push_back(*wptr);
                gotWrong += 1;
            }
        } // end if player guessed HIGHER
        else{
            if ((items[start].getPrice() <= wrongPrices[start])){
                rptr = new small;
                rptr->setDescription(items[start].getDescription());
                rptr->setShortName(items[start].getShortName());
                rptr->setPrice(items[start].getPrice());
                rights.push_back(*rptr);
                gotRight += 1;
            }
            else{
                wptr = new small;
                wptr->setDescription(items[start].getDescription());
                wptr->setShortName(items[start].getShortName());
                wptr->setPrice(items[start].getPrice());
                wrongs.push_back(*wptr);
                gotWrong += 1;
            }
        } // end if player guessed LOWER
    } // end for loop

    bool bail = false;

    cout << endl << "Now, let's reveal the ones you have right, one at a time randomly.";
    cout << endl;
    system("pause");

    if (gotRight == 0){
        cout << endl << "Sorry, you didn't get any right.";
    }

    /// Player has at least one item right.
    else{

    char bailChoice = '!';

    /// If the player only got one item right, don't create an array.
    rightsIt = rights.begin();
    //wrongsIt = wrongs.begin();

    /// Player has one item right
    if (gotRight == 1){

    //int fourWrongs[4] = {0, 1, 2, 3};
    //random_shuffle(&fourWrongs[0], &fourWrongs[3]);
    int randWrong = rand() % 4;

    small fail4[4];
    for (int w = 0; w < 4; w++){
        wrongsIt = wrongs.begin();
        for (int v = 0; v < w; v++)
            wrongsIt++;
        fail4[w].setDescription(wrongsIt->getDescription());
        fail4[w].setShortName(wrongsIt->getShortName());
        fail4[w].setPrice(wrongsIt->getPrice());
    }

    cout << endl << "The actual retail price of the ";
    rightsIt->showShortName();
    cout << " is $" << rightsIt->getPrice();
    cout << endl << "Right now you have $500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $2500 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $500. Thanks for playing!";
    else{
    cout << endl << "The actual retail price of the ";
    fail4[randWrong].showShortName();
    cout << " is $" << fail4[randWrong].getPrice();
    cout << endl << "Sorry, you lose.";
    }
    } // end if player has only one item right.

    /// Player has two items right
    else if (gotRight == 2){

    small right2[2];
    rightsIt = rights.begin();
    right2[0].setDescription(rightsIt->getDescription());
    right2[0].setShortName(rightsIt->getShortName());
    right2[0].setPrice(rightsIt->getPrice());
    rightsIt++;
    right2[1].setDescription(rightsIt->getDescription());
    right2[1].setShortName(rightsIt->getShortName());
    right2[1].setPrice(rightsIt->getPrice());

    small fail3[3];
    for (int w = 0; w < 3; w++){
        wrongsIt = wrongs.begin();
        for (int v = 0; v < w; v++)
            wrongsIt++;
        fail3[w].setDescription(wrongsIt->getDescription());
        fail3[w].setShortName(wrongsIt->getShortName());
        fail3[w].setPrice(wrongsIt->getPrice());
    }

    /// If this is 0, item 0 will be displayed first, and if it's 1, item 1 will be displayed first.
    int showFirst = rand() % 2;
    int showSecond;
    if (showFirst == 0)
        showSecond = 1;
    else
        showSecond = 0;

    cout << endl << "The actual retail price of the ";
    right2[showFirst].showShortName();
    cout << " is $" << right2[showFirst].getPrice();
    cout << endl << "Right now you have $500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $2500 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $500. Thanks for playing!";

    else{
        bailChoice = '!';
        cout << endl << "The actual retail price of the ";
        right2[showSecond].showShortName();
        cout << " is $" << right2[showSecond].getPrice();
        cout << endl << "Right now you have $2500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $5000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $2500. Thanks for playing!";

    else{
        int randWrong3 = rand() % 3;
        cout << endl << "The actual retail price of the ";
        fail3[randWrong3].showShortName();
        cout << " is $" << fail3[randWrong3].getPrice();
        cout << endl << "Sorry, you lose.";
    }

    } // end else if the player continues after the first item and has two items right

    } // end if player has two items right.

    /// Player has three items right.
    else if (gotRight == 3){

    small right3[3];
    for (int w = 0; w < 3; w++){
        rightsIt = rights.begin();
        for (int v = 0; v < w; v++)
            rightsIt++;
        right3[w].setDescription(rightsIt->getDescription());
        right3[w].setShortName(rightsIt->getShortName());
        right3[w].setPrice(rightsIt->getPrice());
    }

    small fail2[2];
    wrongsIt = wrongs.begin();
    fail2[0].setDescription(wrongsIt->getDescription());
    fail2[0].setShortName(wrongsIt->getShortName());
    fail2[0].setPrice(wrongsIt->getPrice());
    wrongsIt++;
    fail2[1].setDescription(wrongsIt->getDescription());
    fail2[1].setShortName(wrongsIt->getShortName());
    fail2[1].setPrice(wrongsIt->getPrice());

    int threeRights[3] = {0, 1, 2};
    random_shuffle(&threeRights[0], &threeRights[3]);

    cout << endl << "The actual retail price of the ";
    right3[threeRights[0]].showShortName();
    cout << " is $" << right3[threeRights[0]].getPrice();
    cout << endl << "Right now you have $500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $2500 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $500. Thanks for playing!";

    else{
        bailChoice = '!';
        cout << endl << "The actual retail price of the ";
        right3[threeRights[1]].showShortName();
        cout << " is $" << right3[threeRights[1]].getPrice();
        cout << endl << "Right now you have $2500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $5000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $2500. Thanks for playing!";

    else{
        bailChoice = '!';
        cout << endl << "The actual retail price of the ";
        right3[threeRights[2]].showShortName();
        cout << " is $" << right3[threeRights[2]].getPrice();
        cout << endl << "Right now you have $5000.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $10000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $5000. Thanks for playing!";

    else{
        int randWrong2 = rand() % 2;
        cout << endl << "The actual retail price of the ";
        fail2[randWrong2].showShortName();
        cout << " is $" << fail2[randWrong2].getPrice();
        cout << endl << "Sorry, you lose.";
    }
    } // end else if the player continues after the second item and has three items right
    } // end else if the player continues after the first item and has three items right

    } // end if player has three items right.

    /// Player has four items right.
    else if (gotRight == 4){

    small right4[4];
    for (int w = 0; w < 4; w++){
        rightsIt = rights.begin();
        for (int v = 0; v < w; v++)
            rightsIt++;
        right4[w].setDescription(rightsIt->getDescription());
        right4[w].setShortName(rightsIt->getShortName());
        right4[w].setPrice(rightsIt->getPrice());
    }

    wrongsIt = wrongs.begin();

    int fourRights[4] = {0, 1, 2, 3};
    random_shuffle(&fourRights[0], &fourRights[4]);

    cout << endl << "The actual retail price of the ";
    right4[fourRights[0]].showShortName();
    cout << " is $" << right4[fourRights[0]].getPrice();
    cout << endl << "Right now you have $500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $2500 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $500. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right4[fourRights[1]].showShortName();
    cout << " is $" << right4[fourRights[1]].getPrice();
    cout << endl << "Right now you have $2500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $5000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $2500. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right4[fourRights[2]].showShortName();
    cout << " is $" << right4[fourRights[2]].getPrice();
    cout << endl << "Right now you have $5000.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $10000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $5000. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right4[fourRights[3]].showShortName();
    cout << " is $" << right4[fourRights[3]].getPrice();
    cout << endl << "Right now you have $10000.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $20000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $10000. Thanks for playing!";

    else{
        cout << endl << "The actual retail price of the ";
        wrongsIt->showShortName();
        cout << " is $" << wrongsIt->getPrice();
        cout << endl << "Sorry, you lose.";
    }

    } // end else if player continues after the third item and has four items right
    } // end else if player continues after the second item and has four items right
    } // end else if player continues after the first item and has four items right

    } // end if player has four items right.

    /// Player has all five items right
    else{

    small right5[5];
    for (int w = 0; w < 5; w++){
        rightsIt = rights.begin();
        for (int v = 0; v < w; v++)
            rightsIt++;
        right5[w].setDescription(rightsIt->getDescription());
        right5[w].setShortName(rightsIt->getShortName());
        right5[w].setPrice(rightsIt->getPrice());
    }

    int fiveRights[5] = {0, 1, 2, 3, 4};
    random_shuffle(&fiveRights[0], &fiveRights[5]);

    cout << endl << "The actual retail price of the ";
    right5[fiveRights[0]].showShortName();
    cout << " is $" << right5[fiveRights[0]].getPrice();
    cout << endl << "Right now you have $500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $2500 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $500. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right5[fiveRights[1]].showShortName();
    cout << " is $" << right5[fiveRights[1]].getPrice();
    cout << endl << "Right now you have $2500.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $5000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $2500. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right5[fiveRights[2]].showShortName();
    cout << " is $" << right5[fiveRights[2]].getPrice();
    cout << endl << "Right now you have $5000.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $10000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $5000. Thanks for playing!";

    else{
    bailChoice = '!';
    cout << endl << "The actual retail price of the ";
    right5[fiveRights[3]].showShortName();
    cout << " is $" << right5[fiveRights[3]].getPrice();
    cout << endl << "Right now you have $10000.";
    while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep what you have (Y) or risk it for $20000 (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y') )
        cout << endl << "You're walking away with $10000. Thanks for playing!";

    else{
    cout << endl << "The actual retail price of the ";
    right5[fiveRights[4]].showShortName();
    cout << " is $" << right5[fiveRights[4]].getPrice();
    cout << endl << "Congratulations, you win $20,000!";
    }

    } // end if player continues after the third item and has five items right

    } // end if player continues after the second item and has five items right
    } // end if player continues after the first item and has five items right

    } // end if player has five items right.

    } // end else if the player has at least one item right.

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Joker
void playJoker()
{
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice) && (t_bonusPrice < 100) && ( (t_bonusPrice % 10) != 0) && ( (t_bonusPrice % 11) != 0) )
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "JOKER" << endl;

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }
    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[4];
    bool discarded[5];
    bool hasJoker[5]; // one of these has the joker, the other four do not

    /// Pick one of the five cards to be the joker.
    int jokerSpot;
    jokerSpot = rand() % 5;

    for (int h = 0; h < 5; h++){
    if (h == jokerSpot)
        hasJoker[h] = true;
    else
        hasJoker[h] = false;
    }

    /// Make sure the player hasn't discarded any cards.
    for (int init = 0; init < 5; init++)
        discarded[init] = false;

    /// Generate four integers that are either 0 or 1.
    /// If the integer is 0, the correct price will be choice #1.
    /// If the integer is 1, the correct price will be choice #2.
    int orientation[4];
    for (int q = 0; q < 4; q++)
    {
        orientation[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

    int earned = 0;

    for (int start = 0; start < 4; start++){
        cout << endl;
        for (int b = 0; b < 5; b++){
            if (discarded[b])
                cout << "* ";
            else
                cout << b+1 << " ";
        }
        cout << endl << endl;

        int cardChoice = 0;
        char answer = 'x';

        cout << start+1 << ". ";
        items[start].showPrize();
        if (orientation[start] == 0){
            cout << endl << " " << (items[start].getPrice() / 10 % 10);
            cout << endl << "*" << (items[start].getPrice() % 10) << "*";
            }
        else{
            cout << endl << " " << (items[start].getPrice() % 10);
            cout << endl << "*" << (items[start].getPrice() / 10 % 10) << "*";
        }
        while ( (answer != 'L') && (answer != 'l') && (answer != 'R') && (answer != 'r') ){
            if (orientation[start] == 0){
                cout << endl << "Is the price $" << items[start].getPrice() << " (L) or $" << invert(items[start].getPrice()) << " (R)?: ";
            }
            else{
                cout << endl << "Is the price $" << invert(items[start].getPrice()) << " (L) or $" << items[start].getPrice() << " (R)?: ";
            }
            cin >> answer;
        }
        cout << endl << "The actual retail price is $" << items[start].getPrice();
        if  ( ( ((answer == 'L') || (answer == 'l')) && (orientation[start] == 0) ) ||
              ( ((answer == 'R') || (answer == 'r')) && (orientation[start] == 1) ) )
        {
            cout << endl << "Yes, that's correct!";
            while ( (cardChoice < 1) || (cardChoice > 5) ){
                cout << endl << "Which card (1-5) do you want to discard?: ";
                cin >> cardChoice;
                if (discarded[cardChoice-1]){
                    cout << endl << "You've already discarded this card. Please choose another one.";
                    cardChoice = 0;
                }
            }
            discarded[cardChoice-1] = true;
        } // end if statement for a correct answer
        else
            cout << endl << "Sorry, that's not correct.";
    } // end while loop

    if ( (!discarded[0]) && (!discarded[1]) && (!discarded[2]) && (!discarded[3]) && (!discarded[4]) )
        cout << endl << "Sorry, you lose.";
    else{
        cout << endl << "Let's see if you've discarded the joker.";
        cout << endl;
        system("pause");
        bool won = false;
        int d = 0;
        while ( (d < 5) && (!won) ){
        if (discarded[d]){
            cout << endl << "Let's see if card #" << d+1 << " is the joker...";
            cout << endl;
            system("pause");
            if (hasJoker[d])
                won = true;
            else
                cout << endl << "This card isn't the joker." << endl;
        }
        d++;
        } // end while loop

        if (won)
            cout << endl << "Congratulations, you win!";
        else{
            cout << endl << "Sorry, you lose.";
            cout << endl << "The joker was card #" << jokerSpot+1 << ".";
            }
    } // end else if player discarded at least one card

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Master Key
void playMasterKey()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string t_Description;
    string t_ShortName;
    int t_Price;
    small * pptr;

    list<medium> gameItemsMedium;
    list<medium>::iterator gameItemMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string c_Model;
    string c_Options;
    int c_Price;
    car * cptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 100) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop checking for small prizes
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
        mptr = new medium;
        if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price > 1000) )
        {
            mptr->setDescription(m_Description);
            mptr->setShortName(m_ShortName);
            mptr->setPrice(m_Price);
            gameItemsMedium.push_back(*mptr);
            j++;
        }
    } // end while loop checking for medium prizes
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + largInput);
    while (inFile)
    {
        lptr = new large;
        if ( (inFile >> l_Description >> l_ShortName >> l_Price) )
        {
            lptr->setDescription(l_Description);
            lptr->setShortName(l_ShortName);
            lptr->setPrice(l_Price);
            gameItemsLarge.push_back(*lptr);
            k++;
        }
    } // end while loop checking for large prizes
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( inFile >> c_Model >> c_Options >> c_Price )
        {
            cptr->setModel(c_Model);
            cptr->setOptions(c_Options);
            cptr->setPrice(c_Price);
            gameCars.push_back(*cptr);
            l++;
        }
    } // end while loop checking for cars
    inFile.close();
    inFile.clear();

    cout << "MASTER KEY" << endl;

    int medID = rand() % j;
    int larID = rand() % k;
    int carID = rand() % l;

    medium prize1;
    large prize2;
    car prize3;


    /// Set the three prizes that can be won with the keys.
    gameItemMedIt = gameItemsMedium.begin();
    for (int z = 0; z < medID; z++)
        gameItemMedIt++;
    prize1.setDescription(gameItemMedIt->getDescription());
    prize1.setShortName(gameItemMedIt->getShortName());
    prize1.setPrice(gameItemMedIt->getPrice());

    gameItemsLargeIt = gameItemsLarge.begin();
    for (int z2 = 0; z2 < larID; z2++)
        gameItemsLargeIt++;
    prize2.setDescription(gameItemsLargeIt->getDescription());
    prize2.setShortName(gameItemsLargeIt->getShortName());
    prize2.setPrice(gameItemsLargeIt->getPrice());

    gameCarIt = gameCars.begin();
    for (int z3 = 0; z3 < carID; z3++)
        gameCarIt++;
    prize3.setModel(gameCarIt->getModel());
    prize3.setOptions(gameCarIt->getOptions());
    prize3.setPrice(gameCarIt->getPrice());

    cout << endl << "1. ";
    prize1.showPrize();
    cout << endl << "2. ";
    prize2.showPrize();
    cout << endl << "3. ";
    prize3.showModel();
    cout << endl << "Comes with: ";
    prize3.showOptions();

    /// 0 represents the dud key, 1 represents the smaller prize, 2 represents the larger prize,
    /// 3 represents the car, and 4 represents the master key.
    int keys[5] = {0, 1, 2, 3, 4};
    random_shuffle(&keys[0], &keys[5]);

    int earnedKeys = 0;

    int smallID1 = rand() % i;
    int smallID2 = smallID1;
    while (smallID2 == smallID1)
        smallID2 = rand() % i;

    small sm1;
    small sm2;

    /// set the two small prizes
    gameItemIt = gameItems.begin();
    for (int z4 = 0; z4 < smallID1; z4++)
        gameItemIt++;
    sm1.setDescription(gameItemIt->getDescription());
    sm1.setShortName(gameItemIt->getShortName());
    sm1.setPrice(gameItemIt->getPrice());

    gameItemIt = gameItems.begin();
    for (int z5 = 0; z5 < smallID2; z5++)
        gameItemIt++;
    sm2.setDescription(gameItemIt->getDescription());
    sm2.setShortName(gameItemIt->getShortName());
    sm2.setPrice(gameItemIt->getPrice());

    int side1 = rand() % 2;
    int side2 = rand() % 2;

    cout << endl << endl;

    cout << endl << "1. ";
    sm1.showPrize();
    int wrongDigit;
    if (sm1.getPrice() % 10 == 0) /// checks if the correct price is divisible by 10, ensuring that a 1-digit price is never an option.
        side1 = 0;
    if (side1 == 0){
        if (sm1.getPrice() % 11 == 0) /// checks if the correct price is divisible by 11, ensuring that it doesn't generate two identical options.
        {
            wrongDigit = sm1.getPrice() / 11;
            while (wrongDigit == (sm1.getPrice() / 11) )
                wrongDigit = (rand() % 9) + 1;
        }
        else
            wrongDigit = (rand() % 9) + 1;
        cout << endl << wrongDigit << sm1.getPrice();
        cout << endl << "L R";
        }
    else
        {
            if (sm1.getPrice() % 11 == 0)
            {
                wrongDigit = sm1.getPrice() / 11;
                while (wrongDigit == (sm1.getPrice() / 11) )
                    wrongDigit = (rand() % 10);
            }
            else
                    wrongDigit = rand() % 10;
        cout << endl << sm1.getPrice() << wrongDigit;
        cout << endl << "L R";
        }

    char choice1 = 'A';

    while ( (choice1 != 'L') && (choice1 != 'R') && (choice1 != 'l') && (choice1 != 'r') ){
        cout << endl << "Does the left number (L) or right number (R) belong in the price?: ";
        cin >> choice1;
    }
        cout << endl << "The actual retail price of the item is ";
        sm1.showARP();
        if ( ((choice1 == 'L') || (choice1 == 'l')) && (side1 == 1) ){
            cout << endl << "That's correct! You earn a key.";
            earnedKeys += 1;
        }
        else if ( ((choice1 == 'R') || (choice1 == 'r')) && (side1 == 0) ){
            cout << endl << "That's correct! You earn a key.";
            earnedKeys += 1;
        }
        else
            cout << endl << "Sorry, that's not correct.";

    cout << endl;

    cout << endl << "2. ";
    sm2.showPrize();
    int wrongDigit2;
    if (sm2.getPrice() % 10 == 0) /// checks if the correct price is divisible by 10, ensuring that a 1-digit price is never an option.
        side2 = 0;
    if (side2 == 0){
        if (sm2.getPrice() % 11 == 0) /// checks if the correct price is divisible by 11, ensuring that it doesn't generate two identical options.
        {
            wrongDigit2 = sm2.getPrice() / 11;
            while (wrongDigit2 == (sm2.getPrice() / 11) )
                wrongDigit2 = (rand() % 9) + 1;
        }
        else
            wrongDigit2 = (rand() % 9) + 1;
        cout << endl << wrongDigit2 << sm2.getPrice();
        cout << endl << "L R";
        }
    else
        {
            if (sm2.getPrice() % 11 == 0)
            {
                wrongDigit2 = sm2.getPrice() / 11;
                while (wrongDigit2 == (sm2.getPrice() / 11) )
                    wrongDigit2 = (rand() % 10);
            }
            else
                    wrongDigit2 = rand() % 10;
        cout << endl << sm2.getPrice() << wrongDigit2;
        cout << endl << "L R";
        }

    char choice2 = 'A';

    while ( (choice2 != 'L') && (choice2 != 'R') && (choice2 != 'l') && (choice2 != 'r') ){
        cout << endl << "Does the left number (L) or right number (R) belong in the price?: ";
        cin >> choice2;
    }
        cout << endl << "The actual retail price of the item is ";
        sm2.showARP();
        if ( ((choice2 == 'L') || (choice2 == 'l')) && (side2 == 1) ){
            cout << endl << "That's correct! You earn a key.";
            earnedKeys += 1;
        }
        else if ( ((choice2 == 'R') || (choice2 == 'r')) && (side2 == 0) ){
            cout << endl << "That's correct! You earn a key.";
            earnedKeys += 1;
        }
        else
            cout << endl << "Sorry, that's not correct.";

    cout << endl;
    bool wonPrize1 = false;
    bool wonPrize2 = false;
    bool wonPrize3 = false;
    bool wonMasterKey = false;

    if (earnedKeys == 0)
        cout << endl << "Sorry, you didn't earn any keys.";
    else
    {
        if (earnedKeys == 1)
            cout << endl << "You've earned 1 key.";
        else
            cout << endl << "You've earned 2 keys.";

        cout << endl << "Let's try your first key...";
        cout << endl;
        system("pause");
        if (keys[0] == 0)
            cout << endl << "Sorry, this was the dud key.";
        else if (keys[0] == 1)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "No, it isn't.";
        }
        else if (keys[0] == 2)
        {
            cout << endl << "Congratulations, you won the ";
            prize2.showShortName();
            wonPrize2 = true;
        }
        else if (keys[0] == 3)
        {
            cout << endl << "Congratulations, you won the car!";
            wonPrize3 = true;
        }
        else if (keys[0] == 4)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "Yes, it is! Congratulations!";
            wonMasterKey = true;
        }

        if (!wonMasterKey && earnedKeys == 2)
        {
            cout << endl << "Let's try the second key now." << endl;
            system("pause");

            if (wonPrize1)
            {
                if (keys[1] == 0)
                    cout << endl << "Sorry, this was the dud key.";
                else if (keys[1] == 2)
                {
                cout << endl << "Congratulations, you won the ";
                prize2.showShortName();
                wonPrize2 = true;
                cout << endl << "But is this the master key?" << endl;
                system("pause");
                cout << endl << "No, it isn't.";
                }
                else if (keys[1] == 3)
                {
                cout << endl << "Congratulations, you won the car!";
                wonPrize3 = true;
                }
                else if (keys[1] == 4)
                {
                cout << endl << "Congratulations, you won the ";
                prize2.showShortName();
                wonPrize2 = true;
                cout << endl << "But is this the master key?" << endl;
                system("pause");
                cout << endl << "Yes, it is! Congratulations!";
                wonMasterKey = true;
                }
            } // end else for if player won first prize

        else if (wonPrize2)
        {
            if (keys[1] == 0)
                cout << endl << "Sorry, this was the dud key.";
            else if (keys[1] == 1)
            {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "No, it isn't.";
            }
            else if (keys[1] == 3)
            {
            cout << endl << "Congratulations, you won the car!";
            wonPrize3 = true;
            }
            else if (keys[1] == 4)
            {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "Yes, it is! Congratulations!";
            wonMasterKey = true;
            }
        } // end else for if player won second prize

    else if (wonPrize3)
    {
        if (keys[1] == 0)
            cout << endl << "Sorry, this was the dud key.";
        else if (keys[1] == 1)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "No, it isn't.";
        }
        else if (keys[1] == 2)
        {
            cout << endl << "Congratulations, you won the ";
            prize2.showShortName();
            wonPrize2 = true;
        }
        else if (keys[1] == 4)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "Yes, it is! Congratulations!";
            wonMasterKey = true;
        }
    } // end else for if player won car

    else
    {
        if (keys[1] == 1)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "No, it isn't.";
        }
        else if (keys[1] == 2)
        {
            cout << endl << "Congratulations, you won the ";
            prize2.showShortName();
            wonPrize2 = true;
        }
        else if (keys[1] == 3)
        {
            cout << endl << "Congratulations, you won the car!";
            wonPrize3 = true;
        }
        else if (keys[1] == 4)
        {
            cout << endl << "Congratulations, you won the ";
            prize1.showShortName();
            wonPrize1 = true;
            cout << endl << "But is this the master key?" << endl;
            system("pause");
            cout << endl << "Yes, it is! Congratulations!";
            wonMasterKey = true;
        }

    } // end else for if player chose dud key

        } // end else statement for picking second key


    } // end else statement for key portion

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Mystery Price
void playMysteryPrice()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string t_Description;
    string t_ShortName;
    int t_Price;
    small * pptr;

    list<small> mysteryPriceItems;
    list<small>::iterator mysteryIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    small * mptr;

    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 125))
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    // Open prizes that can be mystery prices
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        mptr = new small;
        if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price >= 125) )
        {
            mptr->setDescription(m_Description);
            mptr->setShortName(m_ShortName);
            mptr->setPrice(m_Price);
            mysteryPriceItems.push_back(*mptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "MYSTERY PRICE" << endl;
    //cout << endl << "j = " << j;

    small items[4];
    small mysteryPrize;

    int randomMyst;
    int first;
    int second;
    int third;
    int fourth;

    bool setup = false;
    while (!setup){

    int mprice;

    /// First, set the mystery prize.
    randomMyst = rand() % j;
    mysteryIt = mysteryPriceItems.begin();
    for (int z = 0; z < randomMyst; z++)
        mysteryIt++;
    mysteryPrize.setDescription(mysteryIt->getDescription());
    mysteryPrize.setShortName(mysteryIt->getShortName());
    mysteryPrize.setPrice(mysteryIt->getPrice());
    mprice = mysteryPrize.getPrice();
    //cout << endl << "set mystery price";

    first = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    items[0].setDescription(gameItemIt->getDescription());
    items[0].setShortName(gameItemIt->getShortName());
    items[0].setPrice(gameItemIt->getPrice());
    //cout << endl << "set first price";

    second = first;
    while (second == first)
        second = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    items[1].setDescription(gameItemIt->getDescription());
    items[1].setShortName(gameItemIt->getShortName());
    items[1].setPrice(gameItemIt->getPrice());
    //cout << endl << "set second price";

    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    items[2].setDescription(gameItemIt->getDescription());
    items[2].setShortName(gameItemIt->getShortName());
    items[2].setPrice(gameItemIt->getPrice());
    //cout << endl << "set third price";

    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    items[3].setDescription(gameItemIt->getDescription());
    items[3].setShortName(gameItemIt->getShortName());
    items[3].setPrice(gameItemIt->getPrice());
    //cout << endl << "set fourth price";

    if ( ( (items[0].getPrice() + items[1].getPrice()) >= mprice ) || ( (items[0].getPrice() + items[2].getPrice()) >= mprice ) ||
        (  (items[0].getPrice() + items[3].getPrice()) >= mprice ) || ( (items[1].getPrice() + items[2].getPrice()) >= mprice ) ||
        (  (items[1].getPrice() + items[3].getPrice()) >= mprice ) || ( (items[2].getPrice() + items[3].getPrice()) >= mprice ) )
        setup = true;

    } // end while loop

    int bid1;
    int bid2;
    int bid3;
    int bid4;

    int bank = 0;
    cout << endl << "Mystery prize: ";
    mysteryPrize.showPrize();

    cout << endl;
    cout << endl << "Bank: $" << bank;
    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl << "What is your bid on this item?: $";
    cin >> bid1;
    cout << endl << "The actual retail price of the ";
    items[0].showShortName();
    cout << " is $" << items[0].getPrice();
    if (bid1 > items[0].getPrice())
        cout << endl << "You overbid on this item, so your bid doesn't go in the bank.";
    else{
        cout << endl << "Your bid will be added to the bank.";
        bank += bid1;
    }

    cout << endl;
    cout << endl << "Bank: $" << bank;
    cout << endl << "2. ";
    items[1].showPrize();
    cout << endl << "What is your bid on this item?: $";
    cin >> bid2;
    cout << endl << "The actual retail price of the ";
    items[1].showShortName();
    cout << " is $" << items[1].getPrice();
    if (bid2 > items[1].getPrice())
        cout << endl << "You overbid on this item, so your bid doesn't go in the bank.";
    else{
        cout << endl << "Your bid will be added to the bank.";
        bank += bid2;
    }

    cout << endl;
    cout << endl << "Bank: $" << bank;
    cout << endl << "3. ";
    items[2].showPrize();
    cout << endl << "What is your bid on this item?: $";
    cin >> bid3;
    cout << endl << "The actual retail price of the ";
    items[2].showShortName();
    cout << " is $" << items[2].getPrice();
    if (bid3 > items[2].getPrice())
        cout << endl << "You overbid on this item, so your bid doesn't go in the bank.";
    else{
        cout << endl << "Your bid will be added to the bank.";
        bank += bid3;
    }

    cout << endl;
    cout << endl << "Bank: $" << bank;
    cout << endl << "4. ";
    items[3].showPrize();
    cout << endl << "What is your bid on this item?: $";
    cin >> bid4;
    cout << endl << "The actual retail price of the ";
    items[3].showShortName();
    cout << " is $" << items[3].getPrice();
    if (bid4 > items[3].getPrice())
        cout << endl << "You overbid on this item, so your bid doesn't go in the bank.";
    else{
        cout << endl << "Your bid will be added to the bank.";
        bank += bid4;
    }

    cout << endl << endl << "You have $" << bank << " in the bank.";
    cout << endl << "The actual retail price of the mystery prize is $" << mysteryPrize.getPrice();
    if (bank >= mysteryPrize.getPrice())
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// On the Spot
void playOnTheSpot()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "ON THE SPOT" << endl;

    small items[6];

    int first = rand() % i;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    items[0].setDescription(gameItemIt->getDescription());
    items[0].setShortName(gameItemIt->getShortName());
    items[0].setPrice(gameItemIt->getPrice());



    /// Set the remaining items, ensuring that none of them have the same price.
    bool setSecond = false;
    int second;
    while (!setSecond)
    {
    second = first;
    while (second == first)
        second = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z2 = 0; z2 < second; z2++)
        gameItemIt++;
    if (gameItemIt->getPrice() != items[0].getPrice()){
        items[1].setDescription(gameItemIt->getDescription());
        items[1].setShortName(gameItemIt->getShortName());
        items[1].setPrice(gameItemIt->getPrice());
        setSecond = true;
    } // end if
    } // end while

    /// Third item
    bool setThird = false;
    int third;
    while (!setThird)
    {
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z3 = 0; z3 < third; z3++)
        gameItemIt++;
    if ( (gameItemIt->getPrice() != items[0].getPrice()) && (gameItemIt->getPrice() != items[1].getPrice()) ){
        items[2].setDescription(gameItemIt->getDescription());
        items[2].setShortName(gameItemIt->getShortName());
        items[2].setPrice(gameItemIt->getPrice());
        setThird = true;
    } // end if
    } // end while

    /// Fourth item
    bool setFourth = false;
    int fourth;
    while (!setFourth)
    {
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z4 = 0; z4 < fourth; z4++)
        gameItemIt++;
    if ( (gameItemIt->getPrice() != items[0].getPrice()) && (gameItemIt->getPrice() != items[1].getPrice()) && (gameItemIt->getPrice() != items[2].getPrice()) ){
        items[3].setDescription(gameItemIt->getDescription());
        items[3].setShortName(gameItemIt->getShortName());
        items[3].setPrice(gameItemIt->getPrice());
        setFourth = true;
    } // end if
    } // end while

    /// Fifth item
    bool setFifth = false;
    int fifth;
    while (!setFifth)
    {
    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z5 = 0; z5 < fifth; z5++)
        gameItemIt++;
    if ( (gameItemIt->getPrice() != items[0].getPrice()) && (gameItemIt->getPrice() != items[1].getPrice()) && (gameItemIt->getPrice() != items[2].getPrice()) && (gameItemIt->getPrice() != items[3].getPrice()) ){
        items[4].setDescription(gameItemIt->getDescription());
        items[4].setShortName(gameItemIt->getShortName());
        items[4].setPrice(gameItemIt->getPrice());
        setFifth = true;
    } // end if
    } // end while

    /// Sixth item
    bool setSixth = false;
    int sixth;
    while (!setSixth)
    {
    sixth = first;
    while ( (sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z6 = 0; z6 < sixth; z6++)
            gameItemIt++;
    if ( (gameItemIt->getPrice() != items[0].getPrice()) && (gameItemIt->getPrice() != items[1].getPrice()) && (gameItemIt->getPrice() != items[2].getPrice()) && (gameItemIt->getPrice() != items[3].getPrice()) && (gameItemIt->getPrice() != items[4].getPrice()) ){
        items[5].setDescription(gameItemIt->getDescription());
        items[5].setShortName(gameItemIt->getShortName());
        items[5].setPrice(gameItemIt->getPrice());
        setSixth = true;
    } // end if
    } // end while

    int ids[6] = {0, 1, 2, 3, 4, 5};
    random_shuffle(&ids[0], &ids[6]);

    bool won = false;
    bool lost = false;
    bool wrongPathA = false;
    bool wrongPathB = false;
    bool wrongPathC = false;

    bool priceRevealed[6];
    for (int q = 0; q < 6; q++)
        priceRevealed[q] = false;

    while ( (!won) && (!lost) ){
    for (int p = 0; p < 6; p++){
        cout << endl << p+1 << ". ";
        items[p].showPrize();
        if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
    }

    cout << endl;

    if (wrongPathA)
        cout << endl << "X. $" << items[ids[0]].getPrice() << ", $" << items[ids[1]].getPrice() << ", $" << items[ids[2]].getPrice();
    else
        cout << endl << "A. $" << items[ids[0]].getPrice() << ", $" << items[ids[1]].getPrice() << ", $" << items[ids[2]].getPrice();
    if (wrongPathB)
        cout << endl << "X. $" << items[ids[1]].getPrice() << ", $" << items[ids[2]].getPrice() << ", $" << items[ids[0]].getPrice();
    else
        cout << endl << "B. $" << items[ids[1]].getPrice() << ", $" << items[ids[2]].getPrice() << ", $" << items[ids[0]].getPrice();
    if (wrongPathC)
        cout << endl << "X. $" << items[ids[3]].getPrice() << ", $" << items[ids[4]].getPrice() << ", $" << items[ids[5]].getPrice();
    else
        cout << endl << "C. $" << items[ids[3]].getPrice() << ", $" << items[ids[4]].getPrice() << ", $" << items[ids[5]].getPrice();

    char path = '?';
    while ( (path != 'A') && (path != 'a') && (path != 'B') && (path != 'b') && (path != 'C') && (path != 'c') ){
        cout << endl << "Which path do you want to pick?: ";
        cin >> path;
    }

    if ( (path == 'A') || (path == 'a') ){
        if (!wrongPathA){
        int choiceA1 = 0;
        int choiceA2 = 0;
        int choiceA3 = 0;

        while ((choiceA1 < 1) || (choiceA1 > 6)){
            cout << endl << "Which item is $" << items[ids[0]].getPrice() << "?: ";
            cin >> choiceA1;
        }
        if (items[choiceA1-1].getPrice() == items[ids[0]].getPrice()){
        priceRevealed[choiceA1-1] = true;
        cout << endl << "Yes, that's correct.";
        cout << endl;

        for (int p = 0; p < 6; p++){
        cout << endl << p+1 << ". ";
        items[p].showPrize();
        if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
        }

        while ((choiceA2 < 1) || (choiceA2 > 6)){
            cout << endl << "Which item is $" << items[ids[1]].getPrice() << "?: ";
            cin >> choiceA2;
        }

        if (items[choiceA2-1].getPrice() == items[ids[1]].getPrice()){
        priceRevealed[choiceA2-1] = true;
        cout << endl << "Yes, that's correct. You're almost there!";
        cout << endl;

        for (int p = 0; p < 6; p++){
        cout << endl << p+1 << ". ";
        items[p].showPrize();
        if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
        }

        while ((choiceA3 < 1) || (choiceA3 > 6)){
            cout << endl << "Which item is $" << items[ids[2]].getPrice() << "?: ";
            cin >> choiceA3;
        }

        if (items[choiceA3-1].getPrice() == items[ids[2]].getPrice()){
            priceRevealed[choiceA3-1] = true;
            cout << endl << "Yes, that's correct.";
            won = true;
        }
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathA = true;
        }

        } /// end if statement for if player guessed the second item on path A correctly
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathA = true;
        }

        } /// end if statement if player guessed the first item on path A correctly
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathA = true;
        }
    } /// end if path A
    else
        cout << endl << "You can't pick this path anymore. Please pick another one.";
    } // chose path A

    else if ( (path == 'B') || (path == 'b') ){
    if (!wrongPathB){
        int choiceB1 = 0;
        int choiceB2 = 0;
        int choiceB3 = 0;

        while ((choiceB1 < 1) || (choiceB1 > 6)){
            cout << endl << "Which item is $" << items[ids[1]].getPrice() << "?: ";
            cin >> choiceB1;
        }

        if (items[choiceB1-1].getPrice() == items[ids[1]].getPrice()){
        priceRevealed[choiceB1-1] = true;
        cout << endl << "Yes, that's correct.";
        cout << endl;

        for (int p = 0; p < 6; p++){
        cout << endl << p+1 << ". ";
        items[p].showPrize();
        if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
        }

        while ((choiceB2 < 1) || (choiceB2 > 6)){
            cout << endl << "Which item is $" << items[ids[2]].getPrice() << "?: ";
            cin >> choiceB2;
        }

        if (items[choiceB2-1].getPrice() == items[ids[2]].getPrice()){
        priceRevealed[choiceB2-1] = true;
        cout << endl << "Yes, that's correct. You're almost there!";
        cout << endl;

        for (int p = 0; p < 6; p++){
        cout << endl << p+1 << ". ";
        items[p].showPrize();
        if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
        }

        while ((choiceB3 < 1) || (choiceB3 > 6)){
            cout << endl << "Which item is $" << items[ids[0]].getPrice() << "?: ";
            cin >> choiceB3;
        }

        if (items[choiceB3-1].getPrice() == items[ids[0]].getPrice()){
            priceRevealed[choiceB3-1] = true;
            cout << endl << "Yes, that's correct.";
            won = true;
        }
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathB = true;
        }

        } /// end if statement for if player guessed the second item on path B correctly
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathB = true;
        }

        } /// end if statement for if player guessed the first item on path B correctly
        else
        {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathB = true;
        }


    } /// end if path B
    else
        cout << endl << "You can't pick this path anymore. Please pick another one.";
    } // chose path B

    else if ( (path == 'C') || (path == 'c') ){
        if (!wrongPathC){
        int choiceC1 = 0;
        int choiceC2 = 0;
        int choiceC3 = 0;

        while ((choiceC1 < 1) || (choiceC1 > 6)){
            cout << endl << "Which item is $" << items[ids[3]].getPrice() << "?: ";
            cin >> choiceC1;
        }
            if (items[choiceC1-1].getPrice() == items[ids[3]].getPrice()){
            priceRevealed[choiceC1-1] = true;
            cout << endl << "Yes, that's correct.";
            cout << endl;

            for (int p = 0; p < 6; p++){
            cout << endl << p+1 << ". ";
            items[p].showPrize();
            if (priceRevealed[p])
            cout << " - $" << items[p].getPrice();
            }

            while ((choiceC2 < 1) || (choiceC2 > 6)){
            cout << endl << "Which item is $" << items[ids[4]].getPrice() << "?: ";
            cin >> choiceC2;
            }

            if (items[choiceC2-1].getPrice() == items[ids[4]].getPrice()){
            priceRevealed[choiceC2-1] = true;
            cout << endl << "Yes, that's correct. You're almost there!";
            cout << endl;

            for (int p = 0; p < 6; p++){
            cout << endl << p+1 << ". ";
            items[p].showPrize();
            if (priceRevealed[p])
                cout << " - $" << items[p].getPrice();
            }

            while ((choiceC3 < 1) || (choiceC3 > 6)){
                cout << endl << "Which item is $" << items[ids[5]].getPrice() << "?: ";
                cin >> choiceC3;
            }

            if (items[choiceC3-1].getPrice() == items[ids[5]].getPrice()){
                priceRevealed[choiceC3-1] = true;
                cout << endl << "Yes, that's correct.";
                won = true;
            }
            else
            {
            cout << endl << "Sorry, that's not correct. You're back on the spot again.";
            wrongPathC = true;
            }


            }
            else
            {
                cout << endl << "Sorry, that's not correct. You're back on the spot again.";
                wrongPathC = true;
            }


            } /// end if statement for if player guessed the first item on path C correctly
            else
            {
                cout << endl << "Sorry, that's not correct. You're back on the spot again.";
                wrongPathC = true;
            }

        } /// end if path C
        else
            cout << endl << "You can't pick this path anymore. Please pick another one.";

    } // chose path C


    if (wrongPathA && wrongPathB && wrongPathC)
        lost = true;

    } // end while loop

    if (won)
        cout << endl << "Congratulations, you win!";
    else if (lost)
        cout << endl << "Sorry, you lose.";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Plinko
void playPlinko()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 100))
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "PLINKO" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int board[9] = {0, 0, 100, 100, 500, 500, 1000, 1000, 10000};

    int z = 0;
    small items[4];
    int chips = 1;

    /// Set the items
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        items[itemCount].setDescription(gameItemIt->getDescription());
        items[itemCount].setShortName(gameItemIt->getShortName());
        items[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Set the wrong numbers for each price.
    int wrongNumber1 = 0;
    int wrongNumber2 = 0;
    int wrongNumber3 = 0;
    int wrongNumber4 = 0;

    /// Positions in which the wrong number appears.
    int position1 = rand() % 2;
    int position2 = rand() % 2;
    int position3 = rand() % 2;
    int position4 = rand() % 2;

    /// Temporarily hold the prices for each prize.
    int price1 = items[0].getPrice();
    int price2 = items[1].getPrice();
    int price3 = items[2].getPrice();
    int price4 = items[3].getPrice();

    /// First item
    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl;
    char choice = 'A';
    int correctFirstDigit1 = price1 / 10 % 10;
    int correctSecondDigit1 = price1 % 10;
    if (position1 == 0) /// the left number is wrong, so the right number is correct.
    {
        /// Since this changes the first digit, the wrong digit can't be zero.
        while ( (wrongNumber1 == correctFirstDigit1) || (wrongNumber1 == 0) )
            wrongNumber1 = (rand() % 9 + 1);
        cout << "$" << wrongNumber1 << correctSecondDigit1 << endl;
    }
    else /// the right number is wrong, so the left number is correct.
    {
        wrongNumber1 = correctSecondDigit1;
        while (wrongNumber1 == correctSecondDigit1)
            wrongNumber1 = rand() % 10;
        cout << "$" << correctFirstDigit1 << wrongNumber1 << endl;
    }
   while ( (choice != 'L') && (choice != 'R') && (choice != 'l') && (choice != 'r') ){
       cout << endl << "Is the left number (L) or the right number (R) correct?: ";
       cin >> choice;
   }
    cout << endl << "The actual retail price is $" << price1 << endl;
    if ( ((choice == 'L') || (choice == 'l')) && (position1 == 1) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
        }
    else if ( ((choice == 'R') || (choice == 'r')) && (position1 == 0) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
    }
    else
        cout << "Sorry, that's not correct." << endl;
///---------------------------------------------------------------------------///
    /// Second item
    cout << endl << "2. ";
    items[1].showPrize();
    cout << endl;
    choice = 'A';
    int correctFirstDigit2 = price2 / 10 % 10;
    int correctSecondDigit2 = price2 % 10;
    if (position2 == 0) /// the left number is wrong, so the right number is correct.
    {
        /// Since this changes the first digit, the wrong digit can't be zero.
        while ( (wrongNumber2 == correctFirstDigit2) || (wrongNumber2 == 0) )
            wrongNumber2 = (rand() % 9 + 1);
        cout << "$" << wrongNumber2 << correctSecondDigit2 << endl;
    }
    else /// the right number is wrong, so the left number is correct.
    {
        wrongNumber2 = correctSecondDigit2;
        while (wrongNumber2 == correctSecondDigit2)
            wrongNumber2 = rand() % 10;
        cout << "$" << correctFirstDigit2 << wrongNumber2 << endl;
    }
   while ( (choice != 'L') && (choice != 'R') && (choice != 'l') && (choice != 'r') ){
       cout << endl << "Is the left number (L) or the right number (R) correct?: ";
       cin >> choice;
   }
    cout << endl << "The actual retail price is $" << price2 << endl;
    if ( ((choice == 'L') || (choice == 'l')) && (position2 == 1) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
        }
    else if ( ((choice == 'R') || (choice == 'r')) && (position2 == 0) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
    }
    else
        cout << "Sorry, that's not correct." << endl;
///---------------------------------------------------------------------------///
    /// Third item
    cout << endl << "3. ";
    items[2].showPrize();
    cout << endl;
    choice = 'A';
    int correctFirstDigit3 = price3 / 10 % 10;
    int correctSecondDigit3 = price3 % 10;
    if (position3 == 0) /// the left number is wrong, so the right number is correct.
    {
        /// Since this changes the first digit, the wrong digit can't be zero.
        while ( (wrongNumber3 == correctFirstDigit3) || (wrongNumber3 == 0) )
            wrongNumber3 = (rand() % 9 + 1);
        cout << "$" << wrongNumber3 << correctSecondDigit3 << endl;
    }
    else /// the right number is wrong, so the left number is correct.
    {
        wrongNumber3 = correctSecondDigit3;
        while (wrongNumber3 == correctSecondDigit3)
            wrongNumber3 = rand() % 10;
        cout << "$" << correctFirstDigit3 << wrongNumber3 << endl;
    }
   while ( (choice != 'L') && (choice != 'R') && (choice != 'l') && (choice != 'r') ){
       cout << endl << "Is the left number (L) or the right number (R) correct?: ";
       cin >> choice;
   }
    cout << endl << "The actual retail price is $" << price3 << endl;
    if ( ((choice == 'L') || (choice == 'l')) && (position3 == 1) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
        }
    else if ( ((choice == 'R') || (choice == 'r')) && (position3 == 0) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
    }
    else
        cout << "Sorry, that's not correct." << endl;
///---------------------------------------------------------------------------///
    /// Fourth item
    cout << endl << "4. ";
    items[3].showPrize();
    cout << endl;
    choice = 'A';
    int correctFirstDigit4 = price4 / 10 % 10;
    int correctSecondDigit4 = price4 % 10;
    if (position4 == 0) /// the left number is wrong, so the right number is correct.
    {
        /// Since this changes the first digit, the wrong digit can't be zero.
        while ( (wrongNumber4 == correctFirstDigit4) || (wrongNumber4 == 0) )
            wrongNumber4 = (rand() % 9 + 1);
        cout << "$" << wrongNumber4 << correctSecondDigit4 << endl;
    }
    else /// the right number is wrong, so the left number is correct.
    {
        wrongNumber4 = correctSecondDigit4;
        while (wrongNumber4 == correctSecondDigit4)
            wrongNumber4 = rand() % 10;
        cout << "$" << correctFirstDigit4 << wrongNumber4 << endl;
    }
   while ( (choice != 'L') && (choice != 'R') && (choice != 'l') && (choice != 'r') ){
       cout << endl << "Is the left number (L) or the right number (R) correct?: ";
       cin >> choice;
   }
    cout << endl << "The actual retail price is $" << price4 << endl;
    if ( ((choice == 'L') || (choice == 'l')) && (position4 == 1) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
        }
    else if ( ((choice == 'R') || (choice == 'r')) && (position4 == 0) ){
        cout << "That's correct! You earn a Plinko chip." << endl;
        chips += 1;
    }
    else
        cout << "Sorry, that's not correct." << endl;
///---------------------------------------------------------------------------///

    if (chips == 1)
        cout << endl << "You've won 1 Plinko chip.";
    else
        cout << endl << "You've won " << chips << " Plinko chips.";

    int onChip = 0;
    int winnings = 0;

    int wonChips[5];
    for (int w = 0; w < 5; w++)
        wonChips[w] = rand() % 9;

    while (chips > 0)
    {
        cout << endl << "Winnings: $" << winnings;
        cout << endl << "Press any key to drop the Plinko chip." << endl;
        system("pause");
        cout << endl << "You won $" << board[wonChips[onChip]] << " with that chip.";
        winnings += board[wonChips[onChip]];
        onChip++;
        chips--;
    }

    cout << endl;

    if (winnings == 0)
        cout << endl << "Sorry, you didn't win any money this time.";
    else if ( (winnings < 50000) && (winnings > 0) )
        cout << endl << "You've won $" << winnings << " playing Plinko.";
    else if (winnings == 50000)
        cout << endl << "Congratulations, you won $50,000!";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Punch-a-Bunch
void playPunchABunch()
{
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice))
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "PUNCH-A-BUNCH" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[4];

    int punchboard[50] = {25000, 10000, 10000, 5000, 5000, 5000, 5000, 2500, 2500, 2500,
                          2500, 2500, 2500, 2500, 2500, 1000, 1000, 1000, 1000, 1000,
                          1000, 1000, 1000, 1000, 1000, 500, 500, 500, 500, 500,
                          500, 500, 500, 500, 500, 250, 250, 250, 250, 250, 250,
                          250, 250, 250, 250, 100, 100, 100, 100, 100};
    random_shuffle(&punchboard[0], &punchboard[50]);

    int punches = 0;
    int wrongPrices[4]; // these will become the wrong prices

    /// Generate four integers that are either 0 or 1. If the integer is 0, the corresponding price will be too
    /// low, and the correct answer will be HIGHER. If the integer is 1, the corresponding price will be too high,
    /// and the correct answer will be LOWER.
    int wrongValues[4];
    for (int q = 0; q < 4; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

   /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    char answer = 'x';

    /// Generate the wrong prices.
    for (int w = 0; w < 4; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// the correct answer will be HIGHER. The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// the correct answer will be LOWER. The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (51 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    }
    cout << endl;

    /// The main gameplay.
    for (int start = 0; start < 4; start++)
    {
        cout << "Punches: " << punches << endl;
        cout << start+1 << ". ";
        items[start].showPrize();
        cout << endl << "$" << wrongPrices[start];
        while ( (answer != 'H') && (answer != 'L') &&  (answer != 'h') && (answer != 'l') ){
        cout << endl << "This price is wrong. \nIs the correct price higher (H) or lower (L)?: ";
        cin >> answer;
        } /// end while loop
        if ((answer == 'H') || (answer == 'h'))
        {
            cout << "The actual retail price is ";
            items[start].showARP();
            if ((items[start].getPrice() >= wrongPrices[start])){
                cout << endl << "That's correct! You've earned a punch on the board.";
                punches += 1;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item.";
            }

            cout << endl;
        }
        else
        {
            cout << "The actual retail price is ";
            items[start].showARP();
            if ((items[start].getPrice() <= wrongPrices[start])){
                cout << endl << "That's correct! You've earned a punch on the board.";
                punches += 1;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item.";
            }
            cout << endl;
        }
        answer = 'X';
        cout << endl;
    } // end for loop

    bool wonBigPrize = false;
    bool bail = false;
    int countdown = punches;
    int onPunch = 0;
    int winnings = 0;

    if (punches > 0)
    {
        while ((countdown > 0) && (!wonBigPrize) && (!bail))
        {
            char keepGoing = 'A';
            cout << "Let's see what you punched out..." << endl;
            system("pause");
            cout << endl << "You punched out $" << punchboard[onPunch];
            if (punchboard[onPunch] == 25000)
                wonBigPrize = true;
            else
            {
                if (countdown > 1){
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') ){
                //cout << endl << "countdown = " << countdown << endl;
                cout << endl << "Do you want to move on (Y) or stop now (N)?: ";
                cin >> keepGoing;
                }
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                {
                    cout << endl << "All right, then.";
                    cout << endl;
                    countdown -= 1;
                    onPunch += 1;
                }
                else{
                    bail = true;
                    winnings = punchboard[onPunch];
                }
                }
                else{
                    countdown -= 1;
                    winnings = punchboard[onPunch];
                }
            }
        }

        if (wonBigPrize)
            cout << endl << "Congratulations, you won $25,000!";
        else
            cout << endl << "You've won $" << winnings << ". Thanks for playing!";

    } /// end if the player has punches
    else
        cout << endl << "You didn't earn any punches on the board. Sorry...";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Rat Race
void playRatRace()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;
    string g_Description;
    string g_ShortName;
    double g_Price;
    grocery * gptr;

    list<small> gameSmalls;
    list<small>::iterator gameSmallIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    list<medium> gameItemsMedium;
    list<medium>::iterator gameItemMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string c_Model;
    string c_Options;
    int c_Price;
    car * cptr;

    srand(time(0));

    int g = 0; // Grocery items
    int h = 0; // Small prizes
    int i = 0; // Medium prizes
    int j = 0; // Large prizes
    int k = 0; // Cars

    ifstream inFile;

    // Open grocery.txt
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    gptr = new grocery;
    if ( (inFile >> g_Description >> g_ShortName >> g_Price) && (g_Price < 10) )
    {
        gptr->setDescription(g_Description);
        gptr->setShortName(g_ShortName);
        gptr->setPrice(g_Price);
        ggItems.push_back(*gptr);
        g++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    // Open small.txt
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        sptr = new small;
        if ((inFile >> s_Description >> s_ShortName >> s_Price) )
        {
            sptr->setDescription(s_Description);
            sptr->setShortName(s_ShortName);
            sptr->setPrice(s_Price);
            gameSmalls.push_back(*sptr);
            h++;
        }
    } // end while loop checking for small prizes
    inFile.close();
    inFile.clear();

    // Open medium.txt
    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
        mptr = new medium;
        if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price > 1000) )
        {
            mptr->setDescription(m_Description);
            mptr->setShortName(m_ShortName);
            mptr->setPrice(m_Price);
            gameItemsMedium.push_back(*mptr);
            i++;
        }
    } // end while loop checking for medium prizes
    inFile.close();
    inFile.clear();

    // Open large.txt
    inFile.open("./prizes/" + largInput);
    while (inFile)
    {
        lptr = new large;
        if ( (inFile >> l_Description >> l_ShortName >> l_Price) )
        {
            lptr->setDescription(l_Description);
            lptr->setShortName(l_ShortName);
            lptr->setPrice(l_Price);
            gameItemsLarge.push_back(*lptr);
            j++;
        }
    } // end while loop checking for large prizes
    inFile.close();
    inFile.clear();

    // Opene car.txt
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( inFile >> c_Model >> c_Options >> c_Price )
        {
            cptr->setModel(c_Model);
            cptr->setOptions(c_Options);
            cptr->setPrice(c_Price);
            gameCars.push_back(*cptr);
            k++;
        }
    } // end while loop checking for cars
    inFile.close();
    inFile.clear();

    cout << "RAT RACE" << endl;
//    cout << endl << "g = " << g;
//    cout << endl << "h = " << h;
//    cout << endl << "i = " << i;
//    cout << endl << "j = " << j;
//    cout << endl << "k = " << k;
    int medID = rand() % i;
    int larID = rand() % j;
    int carID = rand() % k;

    medium prize1;
    large prize2;
    car prize3;

    /// Set the three prizes that can be won.
    gameItemMedIt = gameItemsMedium.begin();
    for (int z = 0; z < medID; z++)
        gameItemMedIt++;
    prize1.setDescription(gameItemMedIt->getDescription());
    prize1.setShortName(gameItemMedIt->getShortName());
    prize1.setPrice(gameItemMedIt->getPrice());

    gameItemsLargeIt = gameItemsLarge.begin();
    for (int z2 = 0; z2 < larID; z2++)
        gameItemsLargeIt++;
    prize2.setDescription(gameItemsLargeIt->getDescription());
    prize2.setShortName(gameItemsLargeIt->getShortName());
    prize2.setPrice(gameItemsLargeIt->getPrice());

    gameCarIt = gameCars.begin();
    for (int z3 = 0; z3 < carID; z3++)
        gameCarIt++;
    prize3.setModel(gameCarIt->getModel());
    prize3.setOptions(gameCarIt->getOptions());
    prize3.setPrice(gameCarIt->getPrice());

    cout << endl << "1. ";
    prize1.showPrize();
    cout << endl << "2. ";
    prize2.showPrize();
    cout << endl << "3. ";
    prize3.showModel();
    cout << endl << "Comes with: ";
    prize3.showOptions();

    /// 1 = YELLOW, 2 = GREEN, 3 = PINK,
    /// 4 = ORANGE, 5 = BLUE
    int race[5] = {1, 2, 3, 4, 5};

    bool pickedYellow = false;
    bool pickedGreen = false;
    bool pickedPink = false;
    bool pickedOrange = false;
    bool pickedBlue = false;

    int rat1 = 0;
    int rat2 = 0;
    int rat3 = 0;

    cout << endl;

    grocery item1;
    int grocID = rand() % g;
    ggItemIt = ggItems.begin();
    for (int q = 0; q < grocID; q++)
        ggItemIt++;
    item1.setDescription(ggItemIt->getDescription());
    item1.setShortName(ggItemIt->getShortName());
    item1.setPrice(ggItemIt->getPrice());

    cout << endl << "1. ";
    item1.showPrize();
    double bid1;
    cout << endl << "Within $1, how much is the price?: $";
    cin >> bid1;
    double diff1 = abs(item1.getPrice() - bid1);
    cout << endl << "The actual retail price of the ";
    item1.showShortName();
    cout << " is ";
    item1.showARP();
    cout << endl << fixed << setprecision(2) << "For a difference of $" << diff1;
    if (diff1 <= 1){
        cout << endl << "You've earned a rat.";
        while ( (rat1 < 1) || (rat1 > 5) ){
            cout << endl << "1. YELLOW";
            cout << endl << "2. GREEN";
            cout << endl << "3. PINK";
            cout << endl << "4. ORANGE";
            cout << endl << "5. BLUE";
            cout << endl << "Which rat (1-5) do you want to pick?: ";
            cin >> rat1;
        }
        if (rat1 == 1)
            pickedYellow = true;
        else if (rat1 == 2)
            pickedGreen = true;
        else if (rat1 == 3)
            pickedPink = true;
        else if (rat1 == 4)
            pickedOrange = true;
        else
            pickedBlue = true;
    } // end if player came in the range for this item
    else
        cout << endl << "Sorry, you don't get a rat for this item." << endl;

    small item2;
    bool setSecond = false;
    while (!setSecond){
        int sid1 = rand() % h;
        gameSmallIt = gameSmalls.begin();
        for (int q = 0; q < sid1; q++)
            gameSmallIt++;
        if (gameSmallIt->getPrice() < 100){
            item2.setDescription(gameSmallIt->getDescription());
            item2.setShortName(gameSmallIt->getShortName());
            item2.setPrice(gameSmallIt->getPrice());
            setSecond = true;
        } // end if
    } // end while loop

    cout << endl << "2. ";
    item2.showPrize();
    int bid2;
    cout << endl << "Within $10, how much is the price?: $";
    cin >> bid2;
    int diff2 = abs(item2.getPrice() - bid2);
    cout << endl << "The actual retail price of the ";
    item2.showShortName();
    cout << " is ";
    item2.showARP();
    cout << endl << "For a difference of $" << diff2;
    if (diff2 <= 10){
        cout << endl << "You've earned a rat.";
        while ( (rat2 < 1) || (rat2 > 5) ){
            cout << endl << "1. YELLOW";
            if (pickedYellow)
                cout << " - O";
            cout << endl << "2. GREEN";
            if (pickedGreen)
                cout << " - O";
            cout << endl << "3. PINK";
            if (pickedPink)
                cout << " - O";
            cout << endl << "4. ORANGE";
            if (pickedOrange)
                cout << " - O";
            cout << endl << "5. BLUE";
            if (pickedBlue)
                cout << " - O";
            cout << endl << "Which rat (1-5) do you want to pick?: ";
            cin >> rat2;
            if ( (rat2 == 1) && pickedYellow){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat2 = 0;
                }
            else if ( (rat2 == 2) && pickedGreen){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat2 = 0;
                }
            else if ( (rat2 == 3) && pickedPink){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat2 = 0;
                }
            else if ( (rat2 == 4) && pickedOrange){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat2 = 0;
                }
            else if ( (rat2 == 5) && pickedBlue){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat2 = 0;
                }
        } // end while loop
        if (rat2 == 1)
            pickedYellow = true;
        else if (rat2 == 2)
            pickedGreen = true;
        else if (rat2 == 3)
            pickedPink = true;
        else if (rat2 == 4)
            pickedOrange = true;
        else
            pickedBlue = true;
    } // end if player came in the range for this item
    else
        cout << endl << "Sorry, you don't get a rat for this item." << endl;

    small item3;
    bool setThird = false;
    while (!setThird){
        int sid2 = rand() % h;
        gameSmallIt = gameSmalls.begin();
        for (int q = 0; q < sid2; q++)
            gameSmallIt++;
        if (gameSmallIt->getPrice() >= 100){
            item3.setDescription(gameSmallIt->getDescription());
            item3.setShortName(gameSmallIt->getShortName());
            item3.setPrice(gameSmallIt->getPrice());
            setThird = true;
        } // end if
    } // end while loop

    cout << endl << "3. ";
    item3.showPrize();
    int bid3;
    cout << endl << "Within $100, how much is the price?: $";
    cin >> bid3;
    int diff3 = abs(item3.getPrice() - bid3);
    cout << endl << "The actual retail price of the ";
    item3.showShortName();
    cout << " is ";
    item3.showARP();
    cout << endl << "For a difference of $" << diff3;
    if (diff3 <= 100){
        cout << endl << "You've earned a rat.";
        while ( (rat3 < 1) || (rat3 > 5) ){
            cout << endl << "1. YELLOW";
            if (pickedYellow)
                cout << " - O";
            cout << endl << "2. GREEN";
            if (pickedGreen)
                cout << " - O";
            cout << endl << "3. PINK";
            if (pickedPink)
                cout << " - O";
            cout << endl << "4. ORANGE";
            if (pickedOrange)
                cout << " - O";
            cout << endl << "5. BLUE";
            if (pickedBlue)
                cout << " - O";
            cout << endl << "Which rat (1-5) do you want to pick?: ";
            cin >> rat3;
            if ( (rat3 == 1) && pickedYellow){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat3 = 0;
                }
            else if ( (rat3 == 2) && pickedGreen){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat3 = 0;
                }
            else if ( (rat3 == 3) && pickedPink){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat3 = 0;
                }
            else if ( (rat3 == 4) && pickedOrange){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat3 = 0;
                }
            else if ( (rat3 == 5) && pickedBlue){
                cout << endl << "You've already chosen this rat. Please pick another one.";
                rat3 = 0;
                }
        } // end while loop
        if (rat3 == 1)
            pickedYellow = true;
        else if (rat3 == 2)
            pickedGreen = true;
        else if (rat3 == 3)
            pickedPink = true;
        else if (rat3 == 4)
            pickedOrange = true;
        else
            pickedBlue = true;
    } // end if player came in the range for this item
    else
        cout << endl << "Sorry, you don't get a rat for this item." << endl;

    random_shuffle(&race[0], &race[5]);

    if ( (!pickedYellow) && (!pickedGreen) && (!pickedPink) && (!pickedOrange) && (!pickedBlue) ){
        cout << endl << "You didn't earn any rats, but let's see how the race goes anyway.";
        cout << endl;
        system("pause");
        for (int r = 0; r < 5; r++){
            cout << r+1 << ". ";
            if (race[r] == 1)
                cout << "YELLOW";
            else if (race[r] == 2)
                cout << "GREEN";
            else if (race[r] == 3)
                cout << "PINK";
            else if (race[r] == 4)
                cout << "ORANGE";
            else
                cout << "BLUE";
            cout << endl;
        }
        cout << "Sorry, you lose.";
    } // end if player won no rats
    else
    {
    bool wonCar = false;
    bool wonLarge = false;
    bool wonMed = false;
    cout << endl << "You've chosen these rats:";
    if (pickedYellow)
        cout << endl << "YELLOW";
    if (pickedGreen)
        cout << endl << "GREEN";
    if (pickedPink)
        cout << endl << "PINK";
    if (pickedOrange)
        cout << endl << "ORANGE";
    if (pickedBlue)
        cout << endl << "BLUE";

    cout << endl << endl << "Let's see how the race goes.";
    cout << endl;
    system("pause");
    for (int r = 0; r < 5; r++){
        cout << r+1 << ". ";
        if (race[r] == 1)
            cout << "YELLOW";
        else if (race[r] == 2)
            cout << "GREEN";
        else if (race[r] == 3)
            cout << "PINK";
        else if (race[r] == 4)
            cout << "ORANGE";
        else
            cout << "BLUE";
        cout << endl;
    }

    /// Check if player won the car
    if ( (pickedYellow) && (race[0] == 1) )
        wonCar = true;
    else if ( (pickedGreen) && (race[0] == 2) )
        wonCar = true;
    else if ( (pickedPink) && (race[0] == 3) )
        wonCar = true;
    else if ( (pickedOrange) && (race[0] == 4) )
        wonCar = true;
    else if ( (pickedBlue) && (race[0] == 5) )
        wonCar = true;

    /// Check if player won the second place prize
    if ( (pickedYellow) && (race[1] == 1) )
        wonLarge = true;
    else if ( (pickedGreen) && (race[1] == 2) )
        wonLarge = true;
    else if ( (pickedPink) && (race[1] == 3) )
        wonLarge = true;
    else if ( (pickedOrange) && (race[1] == 4) )
        wonLarge = true;
    else if ( (pickedBlue) && (race[1] == 5) )
        wonLarge = true;

    /// Check if player won the third place prize
    if ( (pickedYellow) && (race[2] == 1) )
        wonMed = true;
    else if ( (pickedGreen) && (race[2] == 2) )
        wonMed = true;
    else if ( (pickedPink) && (race[2] == 3) )
        wonMed = true;
    else if ( (pickedOrange) && (race[2] == 4) )
        wonMed = true;
    else if ( (pickedBlue) && (race[2] == 5) )
        wonMed = true;

    if ( (!wonCar) && (!wonLarge) && (!wonMed) )
        cout << endl << "Sorry, you lose.";
    else{
        if (wonCar)
            cout << endl << "You won the car!";
        if (wonLarge){
            cout << endl << "You won the ";
            prize2.showShortName();
        }
        if (wonMed){
            cout << endl << "You won the ";
            prize1.showShortName();
        }
    }

    if (wonCar)
        cout << endl << "Congratulations, you win!";

    } // end if player got at least one item right

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Secret "X"
void playSecretX()
{
    list<small> secretItems;
    list<small>::iterator secretItemIt;

    string t_secretDescription;
    string t_secretShortName;
    int     t_secretPrice;

    small * secretptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        secretptr = new small;
        if ((inFile >> t_secretDescription >> t_secretShortName >> t_secretPrice))
        {
            secretptr->setDescription(t_secretDescription);
            secretptr->setShortName(t_secretShortName);
            secretptr->setPrice(t_secretPrice);
            secretItems.push_back(*secretptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "SECRET \"X\"" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[2];

    /// Determines the position of the secret X itself. If 0, the secret X is in the top-center space, if 1, the
    /// secret X is in the center space, and if 2, the secret X is in the bottom-center space.
    int secretX = rand() % 3;

    /// Determines where the correct price will be for each price. If 0, the correct price is choice 1, and if
    /// 1, the correct price is choice 2.
    int prize1Position = rand() % 2;
    int prize2Position = rand() % 2;

    /// The spaces in which the player can place an X.
    bool otherSpaces[6];
    for (int x = 0; x < 6; x++)
        otherSpaces[x] = false;

    cout << "1 ? 2" << endl;
    cout << "3 ? 4" << endl;
    cout << "5 ? 6" << endl;

    int firstX = -1;
    while (firstX < 1 || firstX > 6){
    cout << endl << "Which space you like to place your first X?: ";
    cin >> firstX;
    }
    otherSpaces[firstX-1] = true;

/// Display the board with the contestant's placed X's. We may turn this into a function later.
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
/// The block of code displaying the board ends here.

    /// Set the two items
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        secretItemIt = secretItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            secretItemIt++;
        }

        items[itemCount].setDescription(secretItemIt->getDescription());
        items[itemCount].setShortName(secretItemIt->getShortName());
        items[itemCount].setPrice(secretItemIt->getPrice());
    }

    /// Generate four integers that are either 0 or 1. If the integer is 0, the wrong price will be too low, and if 1, the
    /// wrong price will be too high.
    int wrongValues[2];
    for (int q = 0; q < 2; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    int wrongPrices[2];

    /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    /// Generate the wrong prices.
    for (int w = 0; w < 2; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (37 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    } /// end for loop

    /// Player's answers.
    int answer1 = -1;
    int answer2 = -2;

    /// Extra X spaces.
    int secondX = 0;
    int thirdX = 0;

    /// If either of these return true, the player can place another X.
    bool wonFirstPrize = false;
    bool wonSecondPrize = false;

    /// These default to false and return true once the player has made
    /// a valid input. These insure that the player doesn't place an X in
    /// a square that already has one.
    bool validSecondX = false;
    bool validThirdX = false;

    //cout << "Secret X value: " << secretX << endl;


    cout << endl;
    items[0].showPrize();
    //cout << endl << "Random value: " << prize1Position+1 << endl;
    cout << endl;
    if (prize1Position == 0)
    {
        /// Choice #1 is the correct answer.
        cout << "1. ";
        items[0].showARP();
        cout << endl;
        cout << "2. $" << wrongPrices[0];
        cout << endl;
    }
    else
    {
        /// Choice #2 is the correct answer.
        cout << "1. $" << wrongPrices[0];
        cout << endl;
        cout << "2. ";
        items[0].showARP();
        cout << endl;
    }
    while (answer1 < 1 || answer1 > 2)
    {
        cout << "For another X, what is the correct answer?: ";
        cin >> answer1;
    }
    cout << "The actual retail price is ";
    items[0].showARP();
    if (prize1Position == 0 && answer1 == 1)
    {
        wonFirstPrize = true;
        cout << endl << "That's correct! You earn another X.";
        cout << endl;
    }
    else if (prize1Position == 1 && answer1 == 2)
    {
        wonFirstPrize = true;
        cout << endl << "That's correct! You earn another X.";
        cout << endl;
    }
    else if (prize1Position == 0 && answer1 == 2)
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    else if (prize1Position == 1 && answer1 == 1)
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    else
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    if (wonFirstPrize)
    {
/// Display the board with the contestant's placed X's. We may turn this into a function later.
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
/// The block of code displaying the board ends here.
    while (validSecondX == false)
    {
    while (secondX < 1 || secondX > 6){
    cout << endl << "Where would you like to place your X?: ";
    cin >> secondX;
    }
    if (otherSpaces[secondX-1] == false){
        otherSpaces[secondX-1] = true;
        validSecondX = true;
        }
    else /// If the player attempts to put an X in a space that already has one, set the
         /// value of secondX to a number outside the range, thereby resetting the while loop.
        secondX = 7;
    }
    } /// end if wonFirstPrize statement

/// Display the board with the contestant's placed X's. We may turn this into a function later.
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
/// The block of code displaying the board ends here.

    cout << "On to the next prize..." << endl;

    /// Prize #2
    cout << endl;
    items[1].showPrize();
    //cout << endl << "Random value: " << prize2Position+1 << endl;
    cout << endl;
    if (prize2Position == 0)
    {
        /// Choice #1 is the correct answer.
        cout << "1. ";
        items[1].showARP();
        cout << endl;
        cout << "2. $" << wrongPrices[1];
        cout << endl;
    }
    else
    {
        /// Choice #2 is the correct answer.
        cout << "1. $" << wrongPrices[1];
        cout << endl;
        cout << "2. ";
        items[1].showARP();
        cout << endl;
    }
    while (answer2 < 1 || answer2 > 2)
    {
        cout << "For another X, what is the correct answer?: ";
        cin >> answer2;
    }
    cout << "The actual retail price is ";
    items[1].showARP();
    if (prize2Position == 0 && answer2 == 1)
    {
        wonSecondPrize = true;
        cout << endl << "That's correct! You earn another X.";
        cout << endl;
    }
    else if (prize2Position == 1 && answer2 == 2)
    {
        wonSecondPrize = true;
        cout << endl << "That's correct! You earn another X.";
        cout << endl;
    }
    else if (prize2Position == 0 && answer2 == 2)
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    else if (prize2Position == 1 && answer2 == 1)
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    else
    {
        cout << endl << "Sorry, that's not correct.";
        cout << endl;
    }
    /// End portion about guessing prices

/// BEGIN HERE

   if (wonSecondPrize)
    {
/// Display the board with the contestant's placed X's. We may turn this into a function later.
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
/// The block of code displaying the board ends here.
    while (validThirdX == false)
    {
    while (thirdX < 1 || thirdX > 6){
    cout << endl << "Where would you like to place your X?: ";
    cin >> thirdX;
    }
    if (otherSpaces[thirdX-1] == false){
        otherSpaces[thirdX-1] = true;
        validThirdX = true;
        }
    else /// If the player attempts to put an X in a space that already has one, set the
         /// value of thirdX to a number outside the range, thereby resetting the while loop.
        thirdX = 7;
    }
    } /// end if wonFirstPrize statement

/// Display the board with the contestant's placed X's. We may turn this into a function later.
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
/// The block of code displaying the board ends here.

    cout << endl << "Let's see where the secret X is.";
    cout << endl;
    system("pause");
    cout << endl;

    if (secretX == 0) /// the secret X is in the top row
    {
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " X ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
    }
    else if (secretX == 1) /// the secret X is in the center
    {
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " X ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " ? ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
    }
    else /// the secret X is in the bottom row
    {
    if (otherSpaces[0] == true)
        cout << "X";
    else
        cout << "1";
    cout << " ? ";
    if (otherSpaces[1] == true)
        cout << "X";
    else
        cout << "2";
    cout << endl;

    if (otherSpaces[2] == true)
        cout << "X";
    else
        cout << "3";
    cout << " ? ";
    if (otherSpaces[3] == true)
        cout << "X";
    else
        cout << "4";
    cout << endl;

    if (otherSpaces[4] == true)
        cout << "X";
    else
        cout << "5";
    cout << " X ";
    if (otherSpaces[5] == true)
        cout << "X";
    else
        cout << "6";
    cout << endl;
    }

    bool wonGame = false;

    if ((otherSpaces[0] == true) && (otherSpaces[1] == true) && (secretX == 0) ) /// three in a row in the top row
    {
        cout << endl << "Congratulations, you win!";
        wonGame = true;
    }
    else if ((otherSpaces[2] == true) && (otherSpaces[3] == true) && (secretX == 1) && !wonGame ) /// three in a row in the center row
    {
        cout << endl << "Congratulations, you win!";
        wonGame = true;
    }
    else if ((otherSpaces[4] == true) && (otherSpaces[5] == true) && (secretX == 2) && !wonGame ) /// three in a row in the bottom row
    {
        cout << endl << "Congratulations, you win!";
        wonGame = true;
    }
    else if ((otherSpaces[0] == true) && (otherSpaces[5] == true) && (secretX == 1) && !wonGame ) /// top-left to bottom-right diagonal
    {
        cout << endl << "Congratulations, you win!";
        wonGame = true;
    }
    else if ((otherSpaces[1] == true) && (otherSpaces[4] == true) && (secretX == 1) && !wonGame ) /// top-right to bottom-left diagonal
    {
        cout << endl << "Congratulations, you win!";
        wonGame = true;
    }
    else
    {
        if (!wonGame)
            cout << endl << "Sorry, you lose.";
    }
    cout << endl;
    system("pause");
    system("CLS");

} // end

/// Shell Game
void playShellGame()
{
    list<small> bonusItems;
    list<small>::iterator bonusItemIt;

    string t_bonusDescription;
    string t_bonusShortName;
    int     t_bonusPrice;

    small * bonusptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        bonusptr = new small;
        if ((inFile >> t_bonusDescription >> t_bonusShortName >> t_bonusPrice))
        {
            bonusptr->setDescription(t_bonusDescription);
            bonusptr->setShortName(t_bonusShortName);
            bonusptr->setPrice(t_bonusPrice);
            bonusItems.push_back(*bonusptr);
            i++;
        }
    } // end while loop

    cout << "SHELL GAME" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[4];
    bool spotControlled[4];
    bool spaceStatus[4]; // one of these has the bonus, the other three do not
    int wrongPrices[4]; // these will become the wrong prices

    /// Pick one of the four shells to have the ball.
    int bonusSpot;
    bonusSpot = rand() % 4;
    spaceStatus[bonusSpot] = true;

    /// Make sure the player hasn't picked any shells.
    for (int init = 0; init < 4; init++)
        spotControlled[init] = false;

    /// Generate four integers that are either 0 or 1. If the integer is 0, the corresponding price will be too
    /// low, and the correct answer will be HIGHER. If the integer is 1, the corresponding price will be too high,
    /// and the correct answer will be LOWER.
    int wrongValues[4];
    for (int q = 0; q < 4; q++)
    {
        wrongValues[q] = rand() % 2;
    }

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        bonusItemIt = bonusItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            bonusItemIt++;
        }

        items[itemCount].setDescription(bonusItemIt->getDescription());
        items[itemCount].setShortName(bonusItemIt->getShortName());
        items[itemCount].setPrice(bonusItemIt->getPrice());
    }

    /// This line will only be used for debugging and is commented out once the game is finished.
    //cout << "The bonus is behind prize #" << bonusSpot + 1 << endl;

    /// tempPrice holds the original price, and finalPrice holds the changed wrong price.
    int tempPrice = 0;
    int finalPrice = 0;

    char answer = 'x';

    /// Generate the wrong prices.
    for (int w = 0; w < 4; w++)
    {
        //cout << wrongValues[w] << ", ";

        if (wrongValues[w] == 0) /// the correct answer will be HIGHER. The wrong price will be less than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            if (tempPrice >= 20)
                finalPrice = rand() % ((tempPrice+1) - 10) + 10;
            else
                finalPrice = rand() % ((tempPrice+1) - 5) + 5;
            //cout << "Wrong price: " << finalPrice << endl;
            wrongPrices[w] = finalPrice;
        }
        else /// the correct answer will be LOWER. The wrong price will be more than the ARP.
        {
            tempPrice = items[w].getPrice();
            //cout << tempPrice << endl;
            int addition = (rand() % (51 - 10) + 10);
            finalPrice = tempPrice + addition;
            wrongPrices[w] = finalPrice;
        }
    }
    cout << endl;
    int chipsEarned = 0;

    /// The main gameplay.
    for (int start = 0; start < 4; start++)
    {
        cout << "O O O O";
        cout << endl;
        for (int c = 0; c < 4; c++){
        if (spotControlled[c])
            cout << "* ";
        else
            cout << "  ";
        }
        cout << endl;
        int shellChoice = 5;
        cout << start+1 << ". ";
        items[start].showPrize();
        cout << endl << "$" << wrongPrices[start];
        while ( (answer != 'H') && (answer != 'L') &&  (answer != 'h') && (answer != 'l') ){
        cout << endl << "This price is wrong. \nIs the correct price higher (H) or lower (L)?: ";
        cin >> answer;
        } /// end while loop
        if ((answer == 'H') || (answer == 'h'))
        {
            cout << endl << "The actual retail price is ";
            items[start].showARP();
            if ((items[start].getPrice() >= wrongPrices[start])){
                chipsEarned += 1;
                cout << endl << "That's correct!";
                while ( (shellChoice > 4) || (shellChoice < 0) || (spotControlled[shellChoice-1] == true) )
                {
                    cout << endl << "Which shell (1-4) do you want to place a chip next to?: ";
                    cin >> shellChoice;
                    cout << endl;
                }
                spotControlled[shellChoice-1] = true;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item." << endl << endl;
            }

            //cout << endl;
        }
        else
        {
            cout << endl << "The actual retail price is ";
            items[start].showARP();
            if (items[start].getPrice() <= wrongPrices[start]){
                chipsEarned += 1;
                cout << endl << "That's correct!";
                while ( (shellChoice > 4) || (shellChoice < 0) || (spotControlled[shellChoice-1] == true) )
                {
                    cout << endl << "Which shell (1-4) do you want to place a chip next to?: ";
                    cin >> shellChoice;
                    cout << endl;
                }
                spotControlled[shellChoice-1] = true;
                }
            else
            {
                cout << endl << "Sorry, that's not correct. You don't win this item." << endl << endl;
            }
            //cout << endl;
        }
        answer = 'X';
        //cout << endl;
    } // end for loop

    if (chipsEarned == 4)
    {
        int bonusChip = 0;
        while ( (bonusChip < 1) || (bonusChip > 4)){
        cout << "You won all 4 chips, but for a cash bonus, \nwhich shell has the ball behind it?: ";
        cin >> bonusChip;
        }
        cout << endl << "The ball is under shell #" << bonusSpot+1;
        if ( (bonusChip-1) == bonusSpot)
            cout << endl << "Congratulations, you won the prize and a cash bonus!";
        else
            cout << endl << "You didn't win the cash bonus, but you did win the prize.";
    }
    else if (chipsEarned == 0)
        cout << endl << "Sorry, you lose.";
    else
    {
        cout << endl << "Let's see which shell the ball is behind..." << endl;
        system("pause");
        cout << endl << "The ball is under shell #" << bonusSpot+1;
        cout << endl;
        if (spotControlled[bonusSpot])
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Spelling Bee
void playSpellingBee()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 50) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "SPELLING BEE" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    small items[3];

    char cards[30] = {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
                      'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
                      'R', 'R', 'R', 'R', 'R', 'R', '!', '!'};

    random_shuffle(&cards[0], &cards[30]);

    /// Set the items
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        items[itemCount].setDescription(gameItemIt->getDescription());
        items[itemCount].setShortName(gameItemIt->getShortName());
        items[itemCount].setPrice(gameItemIt->getPrice());
    }

    int cardsEarned = 2;
    bool madePerfectBid = false;
    bool madePerfectBid2 = false;
    bool madePerfectBid3 = false;

    cout << endl << "You get two cards for free, but let's see if you can earn more.";

    int bid1 = 0;
    int bid2 = 0;
    int bid3 = 0;

    int diff1;
    int diff2;
    int diff3;

    cout << endl;
    cout << endl << "1. ";
    items[0].showPrize();
    while (bid1 <= 0){
    cout << endl << "What is this item's ARP?: $";
    cin >> bid1;
    }
    cout << endl << "The actual retail price of the ";
    items[0].showShortName();
    cout << " is ";
    items[0].showARP();
    diff1 = abs(bid1 - items[0].getPrice());
    cout << endl << "For a difference of $" << diff1;
    if (diff1 == 0)
    {
        cout << endl << "You win all 3 picks for bidding exactly right!";
        madePerfectBid = true;
        cardsEarned = 5;
    }
    else if (diff1 <= 10){
        cout << endl << "You win another pick on the board.";
        cardsEarned += 1;
        }
    else
        cout << endl << "Sorry, you don't win a pick for this item.";

    if (!madePerfectBid){
    {
    cout << endl;
    cout << endl << "2. ";
    items[1].showPrize();
    while (bid2 <= 0){
    cout << endl << "What is this item's ARP?: $";
    cin >> bid2;
    }
    cout << endl << "The actual retail price of the ";
    items[1].showShortName();
    cout << " is ";
    items[1].showARP();
    diff2 = abs(bid2 - items[1].getPrice());
    cout << endl << "For a difference of $" << diff2;
    if (diff2 == 0)
    {
        cout << endl << "You win all 3 picks for bidding exactly right!";
        madePerfectBid2 = true;
        cardsEarned = 5;
    }
    else if (diff2 <= 10)
    {
        cout << endl << "You win another pick on the board.";
        cardsEarned += 1;
    }
    else
        cout << endl << "Sorry, you don't win a pick for this item.";

    if (!madePerfectBid2)
    {
    cout << endl;
    cout << endl << "3. ";
    items[2].showPrize();
    while (bid3 <= 0){
    cout << endl << "What is this item's ARP?: $";
    cin >> bid3;
    }
    cout << endl << "The actual retail price of the ";
    items[2].showShortName();
    cout << " is ";
    items[2].showARP();
    diff3 = abs(bid3 - items[2].getPrice());
    cout << endl << "For a difference of $" << diff3;
    if (diff3 == 0)
    {
        cout << endl << "You win all 3 picks for bidding exactly right!";
        madePerfectBid3 = true;
        cardsEarned = 5;
    }
    else if (diff3 <= 10)
    {
        cout << endl << "You win another pick on the board.";
        cardsEarned += 1;
    }
    else
        cout << endl << "Sorry, you don't win a pick for this item.";
    }

    } // end if statement

    } // end if statement

    bool bail = false;
    bool hasC = false;
    bool hasA = false;
    bool hasR = false;
    bool spelledCar = false;
    int onCard = 0;

    cout << endl;

    while ( (cardsEarned != 0) && (!bail) && (!spelledCar) )
    {
        cout << endl;
        if (hasC)
            cout << "C";
        else
            cout << "*";
        if (hasA)
            cout << "A";
        else
            cout << "*";
        if (hasR)
            cout << "R";
        else
            cout << "*";
        cout << endl;
        char bailChoice = 'A';
        cout << endl << "Right now you have $" << cardsEarned*1000 << ".";
        while ( (bailChoice != 'Y') && (bailChoice != 'N') && (bailChoice != 'y') && (bailChoice != 'n') ){
            cout << endl << "Do you want to keep the money (Y) or reveal the next card? (N): ";
            cin >> bailChoice;
        }
        if ( (bailChoice == 'Y') || (bailChoice == 'y') )
            bail = true;
        else
        {
            if (cards[onCard] == 'C')
            {
                cout << endl << "Behind this card is a C";
                hasC = true;
            }
            else if (cards[onCard] == 'A')
            {
                cout << endl << "Behind this card is an A";
                hasA = true;
            }
            else if (cards[onCard] == 'R')
            {
                cout << endl << "Behind this card is an R";
                hasR = true;
            }
            else
            {
               cout << endl << "Behind this card is the word CAR";
               spelledCar = true;
            }
            if ( (hasC) && (hasA) && (hasR) )
                spelledCar = true;
            else{
                onCard++;
                cardsEarned -= 1;
                }
        } /// player did not bail

    } /// end while loop

    if (bail)
        cout << endl << "You're walking away with $" << cardsEarned*1000 << ". Thanks for playing!";
    else if (spelledCar){
        cout << endl << "CAR";
        cout << endl << "Congratulations, you win!";
        }
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Super Ball!!
void playSuperBall()
{
    list<small> gameSmalls;
    list<small>::iterator gameSmallIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    list<medium> gameItemsMedium;
    list<medium>::iterator gameItemMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    srand(time(0));

    int h = 0; // Small prizes
    int i = 0; // Medium prizes
    int j = 0; // Large prizes

    ifstream inFile;

    // Open small.txt
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        sptr = new small;
        if ((inFile >> s_Description >> s_ShortName >> s_Price) )
        {
            sptr->setDescription(s_Description);
            sptr->setShortName(s_ShortName);
            sptr->setPrice(s_Price);
            gameSmalls.push_back(*sptr);
            h++;
        }
    } // end while loop checking for small prizes
    inFile.close();
    inFile.clear();

    // Open medium.txt
    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
        mptr = new medium;
        if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price > 1000) )
        {
            mptr->setDescription(m_Description);
            mptr->setShortName(m_ShortName);
            mptr->setPrice(m_Price);
            gameItemsMedium.push_back(*mptr);
            i++;
        }
    } // end while loop checking for medium prizes
    inFile.close();
    inFile.clear();

    // Open large.txt
    inFile.open("./prizes/" + largInput);
    while (inFile)
    {
        lptr = new large;
        if ( (inFile >> l_Description >> l_ShortName >> l_Price) )
        {
            lptr->setDescription(l_Description);
            lptr->setShortName(l_ShortName);
            lptr->setPrice(l_Price);
            gameItemsLarge.push_back(*lptr);
            j++;
        }
    } // end while loop checking for large prizes
    inFile.close();
    inFile.clear();

    cout << "SUPER BALL!!" << endl;

    medium door1Item;
    large door2Item;
    large door3Item;

    // Set the item behind door #1
    int medID = rand() % i;
    gameItemMedIt = gameItemsMedium.begin();
    for (int z = 0; z < medID; z++)
        gameItemMedIt++;
    door1Item.setDescription(gameItemMedIt->getDescription());
    door1Item.setShortName(gameItemMedIt->getShortName());
    door1Item.setPrice(gameItemMedIt->getPrice());

    // Set the item behind door #2
    bool setSecond = false;
    while (!setSecond){
    int larID1 = rand() % j;
    gameItemsLargeIt = gameItemsLarge.begin();
    for (int z = 0; z < larID1; z++)
            gameItemsLargeIt++;
    if (gameItemsLargeIt->getPrice() < 7500){
        door2Item.setDescription(gameItemsLargeIt->getDescription());
        door2Item.setShortName(gameItemsLargeIt->getShortName());
        door2Item.setPrice(gameItemsLargeIt->getPrice());
        setSecond = true;
    }
    } // end while loop

    // Set the item behind door #3
    bool setThird = false;
    while (!setThird){
    int larID2 = rand() % j;
    gameItemsLargeIt = gameItemsLarge.begin();
    for (int z = 0; z < larID2; z++)
            gameItemsLargeIt++;
    if (gameItemsLargeIt->getPrice() >= 7500){
        door3Item.setDescription(gameItemsLargeIt->getDescription());
        door3Item.setShortName(gameItemsLargeIt->getShortName());
        door3Item.setPrice(gameItemsLargeIt->getPrice());
        setThird = true;
    }
    } // end while loop

    cout << endl << "1. ";
    door1Item.showPrize();
    cout << endl << "2. ";
    door2Item.showPrize();
    cout << endl << "3. ";
    door3Item.showPrize();

    bool wonFirst = false;
    bool wonSecond = false;
    bool wonThird = false;

    small items[4];
    int side1 = rand() % 2;
    int side2 = rand() % 2;
    int side3 = rand() % 2;
    int side4 = rand() % 2;

    cout << endl;

    /// Small prize #1
    int sm_id1 = rand() % h;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < sm_id1; z++)
        gameSmallIt++;
    items[0].setDescription(gameSmallIt->getDescription());
    items[0].setShortName(gameSmallIt->getShortName());
    items[0].setPrice(gameSmallIt->getPrice());

    int wrong1 = items[0].getPrice();
    while (wrong1 == items[0].getPrice()){
        if (items[0].getPrice() < 100)
            wrong1 = (rand() % 90)+10;
        else
            wrong1 = (rand() % 95)+100;
    }

    int choice1 = 0;
    cout << endl;
    items[0].showPrize();
    if (side1 == 0){
        cout << endl << "1. $" << items[0].getPrice();
        cout << endl << "2. $" << wrong1;
    }
    else{
        cout << endl << "1. $" << wrong1;
        cout << endl << "2. $" << items[0].getPrice();
    }
    while ( (choice1 < 1) || (choice1 > 2) ){
        cout << endl << "Which price (1-2) is correct?: ";
        cin >> choice1;
    }

    cout << endl << "The actual retail price of the ";
    items[0].showShortName();
    cout << " is $" << items[0].getPrice();
    if (choice1 == (side1+1) ){
        cout << endl << "That's correct! You've earned a ball for the ";
        door1Item.showShortName();
        cout << ".";
        wonFirst = true;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl;

    /// Small prize #2
    int sm_id2 = sm_id1;
    while (sm_id2 == sm_id1)
        sm_id2 = rand() % h;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < sm_id2; z++)
        gameSmallIt++;
    items[1].setDescription(gameSmallIt->getDescription());
    items[1].setShortName(gameSmallIt->getShortName());
    items[1].setPrice(gameSmallIt->getPrice());

    int wrong2 = items[1].getPrice();
    while (wrong2 == items[1].getPrice()){
        if (items[1].getPrice() < 100)
            wrong2 = (rand() % 90)+10;
        else
            wrong2 = (rand() % 95)+100;
    }

    int choice2 = 0;
    cout << endl;
    items[1].showPrize();
    if (side2 == 0){
        cout << endl << "1. $" << items[1].getPrice();
        cout << endl << "2. $" << wrong2;
    }
    else{
        cout << endl << "1. $" << wrong2;
        cout << endl << "2. $" << items[1].getPrice();
    }
    while ( (choice2 < 1) || (choice2 > 2) ){
        cout << endl << "Which price (1-2) is correct?: ";
        cin >> choice2;
    }

    cout << endl << "The actual retail price of the ";
    items[1].showShortName();
    cout << " is $" << items[1].getPrice();
    if (choice2 == (side2+1) ){
        cout << endl << "That's correct! You've earned a ball for the ";
        door2Item.showShortName();
        cout << ".";
        wonSecond = true;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl;

    /// Small prize #3
    int sm_id3 = sm_id1;
    while ( (sm_id3 == sm_id1) || (sm_id3 == sm_id2) )
        sm_id3 = rand() % h;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < sm_id3; z++)
        gameSmallIt++;
    items[2].setDescription(gameSmallIt->getDescription());
    items[2].setShortName(gameSmallIt->getShortName());
    items[2].setPrice(gameSmallIt->getPrice());

    int wrong3 = items[2].getPrice();
    while (wrong3 == items[2].getPrice()){
        if (items[2].getPrice() < 100)
            wrong3 = (rand() % 90)+10;
        else
            wrong3 = (rand() % 95)+100;
    }

    int choice3 = 0;
    cout << endl;
    items[2].showPrize();
    if (side3 == 0){
        cout << endl << "1. $" << items[2].getPrice();
        cout << endl << "2. $" << wrong3;
    }
    else{
        cout << endl << "1. $" << wrong3;
        cout << endl << "2. $" << items[2].getPrice();
    }
    while ( (choice3 < 1) || (choice3 > 2) ){
        cout << endl << "Which price (1-2) is correct?: ";
        cin >> choice3;
    }

    cout << endl << "The actual retail price of the ";
    items[2].showShortName();
    cout << " is $" << items[2].getPrice();
    if (choice3 == (side3+1) ){
        cout << endl << "That's correct! You've earned a ball for the ";
        door3Item.showShortName();
        cout << ".";
        wonThird = true;
    }
    else
        cout << endl << "Sorry, that's not correct.";

    if ( (!wonFirst) && (!wonSecond) && (!wonThird) )
        cout << endl << "Sorry, you lose.";
    else
    {
    int money = 0;
    int ball1 = rand() % 3;
    int ball2 = rand() % 3;
    int ball3 = rand() % 3;

    bool got1 = false;
    bool got2 = false;
    bool got3 = false;

    cout << endl;
    if (wonFirst){
        cout << endl << "Let's see what you'll get with ball #1...";
        cout << endl;
        system("pause");
        if (ball1 == 0){
            cout << endl << "You've won $50 with this ball.";
            money += 50;
            }
        else if (ball1 == 1){
            cout << endl << "You've won $100 with this ball.";
            money += 100;
        }
        else{
            cout << endl << "Congratulations, you won the ";
            door1Item.showShortName();
            cout << "!";
            got1 = true;
        }
        cout << endl;
    } // end for ball #1

    if (wonSecond){
        cout << endl << "Let's see what you'll get with ball #2...";
        cout << endl;
        system("pause");
        if (ball2 == 0){
            cout << endl << "You've won $50 with this ball.";
            money += 50;
            }
        else if (ball2 == 1){
            cout << endl << "You've won $100 with this ball.";
            money += 100;
        }
        else{
            cout << endl << "Congratulations, you won the ";
            door2Item.showShortName();
            cout << "!";
            got2 = true;
        }
        cout << endl;
    } // end for ball #2

    if (wonThird){
        cout << endl << "Let's see what you'll get with ball #3...";
        cout << endl;
        system("pause");
        if (ball3 == 0){
            cout << endl << "You've won $50 with this ball.";
            money += 50;
            }
        else if (ball3 == 1){
            cout << endl << "You've won $100 with this ball.";
            money += 100;
        }
        else{
            cout << endl << "Congratulations, you won the ";
            door3Item.showShortName();
            cout << "!";
            got3 = true;
        }
        cout << endl;
    } // end for ball #3

    if (got1 && got2 && got3)
        cout << endl << "Let's see if you can earn a bonus with the super ball." << endl;
    else
        cout << endl << "Let's see if you can win everything with the super ball." << endl;

    /// Small prize #4
    int sm_id4 = sm_id1;
    while ( (sm_id4 == sm_id1) || (sm_id4 == sm_id2) || (sm_id4 == sm_id3) )
        sm_id4 = rand() % h;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < sm_id4; z++)
        gameSmallIt++;
    items[3].setDescription(gameSmallIt->getDescription());
    items[3].setShortName(gameSmallIt->getShortName());
    items[3].setPrice(gameSmallIt->getPrice());

    int wrong4 = items[3].getPrice();
    while (wrong4 == items[3].getPrice()){
        if (items[3].getPrice() < 100)
            wrong4 = (rand() % 90)+10;
        else
            wrong4 = (rand() % 95)+100;
    }

    int choice4 = 0;
    cout << endl;
    items[3].showPrize();
    if (side4 == 0){
        cout << endl << "1. $" << items[3].getPrice();
        cout << endl << "2. $" << wrong4;
    }
    else{
        cout << endl << "1. $" << wrong4;
        cout << endl << "2. $" << items[3].getPrice();
    }
    while ( (choice4 < 1) || (choice4 > 2) ){
        cout << endl << "Which price (1-2) is correct?: ";
        cin >> choice4;
    }

    cout << endl << "The actual retail price of the ";
    items[3].showShortName();
    cout << " is $" << items[3].getPrice();
    if (choice4 == (side4+1) ){
        int ball4 = rand() % 3;
        cout << endl << "That's correct! You've earned the super ball.";
        cout << endl << endl << "Let's see what you'll get with the super ball...";
        cout << endl;
        system("pause");
        if (ball4 == 0){
            cout << endl << "You've won $150 with this ball.";
            money += 150;
            if (!got1 && !got2 && !got3)
                cout << endl << endl << "You've won $" << money << ".";
            else
                cout << endl << endl << "You've won $" << money << " and these prizes:";
            if (got1){
                cout << endl;
                door1Item.showShortName();
            }
            if (got2){
                cout << endl;
                door2Item.showShortName();
            }
            if (got3){
                cout << endl;
                door3Item.showShortName();
            }

            }
        else if (ball4 == 1){
            cout << endl << "You've won $300 with this ball.";
            money += 300;
            if (!got1 && !got2 && !got3)
                cout << endl << endl << "You've won $" << money << ".";
            else
                cout << endl << endl << "You've won $" << money << " and these prizes:";

            if (got1){
                cout << endl;
                door1Item.showShortName();
            }
            if (got2){
                cout << endl;
                door2Item.showShortName();
            }
            if (got3){
                cout << endl;
                door3Item.showShortName();
            }
        }
        else{
        if (got1 && got2 && got3)
            cout << endl << "Congratulations, you won all the prizes and $3000!" << endl;
        else
            cout << endl << "Congratulations, you've won everything!" << endl;
        }

    } // won super ball
    else{
    cout << endl << "Sorry, that's not correct.";
    if (!got1 && !got2 && !got3)
        cout << endl << endl << "You've won $" << money << ".";
    else
        cout << endl << endl << "You've won $" << money << " and these prizes:";
    if (got1){
        cout << endl;
        door1Item.showShortName();
    }
    if (got2){
        cout << endl;
        door2Item.showShortName();
    }
    if (got3){
        cout << endl;
        door3Item.showShortName();
    }
    } // didn't win super ball

    } // end if player has at least one ball

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Trader Bob
void playTraderBob()
{
    list<small> gameItems;
    list<small>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> t_Description >> t_ShortName >> t_Price) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "TRADER BOB" << endl;

    small temps[7];
    small items[7];

    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;
    int seventh;

    bool setup = false;

    while (!setup){

    first = rand() % i;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    temps[0].setDescription(gameItemIt->getDescription());
    temps[0].setShortName(gameItemIt->getShortName());
    temps[0].setPrice(gameItemIt->getPrice());

    /// Pair 1
    second = first;
    while (second == first)
        second = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    temps[1].setDescription(gameItemIt->getDescription());
    temps[1].setShortName(gameItemIt->getShortName());
    temps[1].setPrice(gameItemIt->getPrice());

    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    temps[2].setDescription(gameItemIt->getDescription());
    temps[2].setShortName(gameItemIt->getShortName());
    temps[2].setPrice(gameItemIt->getPrice());


    /// Pair 2
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    temps[3].setDescription(gameItemIt->getDescription());
    temps[3].setShortName(gameItemIt->getShortName());
    temps[3].setPrice(gameItemIt->getPrice());

    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fifth; z++)
        gameItemIt++;
    temps[4].setDescription(gameItemIt->getDescription());
    temps[4].setShortName(gameItemIt->getShortName());
    temps[4].setPrice(gameItemIt->getPrice());


    /// Pair 3
    sixth = first;
    while ( (sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < sixth; z++)
        gameItemIt++;
    temps[5].setDescription(gameItemIt->getDescription());
    temps[5].setShortName(gameItemIt->getShortName());
    temps[5].setPrice(gameItemIt->getPrice());

    seventh = first;
    while ( (seventh == first) || (seventh == second) || (seventh == third) || (seventh == fourth) || (seventh == fifth) || (seventh == sixth) )
        seventh = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < seventh; z++)
        gameItemIt++;
    temps[6].setDescription(gameItemIt->getDescription());
    temps[6].setShortName(gameItemIt->getShortName());
    temps[6].setPrice(gameItemIt->getPrice());


    if ( (temps[1].getPrice() > temps[0].getPrice()) && (temps[2].getPrice() < temps[0].getPrice()) &&
         (temps[3].getPrice() > temps[1].getPrice()) && (temps[4].getPrice() < temps[1].getPrice()) &&
         (temps[5].getPrice() > temps[3].getPrice()) && (temps[6].getPrice() < temps[3].getPrice()) )
            setup = true;

    } // end while loop

    int pos1 = rand() % 2;
    int pos2 = rand() % 2;
    int pos3 = rand() % 2;

    items[0].setDescription(temps[0].getDescription());
    items[0].setShortName(temps[0].getShortName());
    items[0].setPrice(temps[0].getPrice());

    /// Set first pair
    if (pos1 == 0){
    items[1].setDescription(temps[1].getDescription());
    items[1].setShortName(temps[1].getShortName());
    items[1].setPrice(temps[1].getPrice());

    items[2].setDescription(temps[2].getDescription());
    items[2].setShortName(temps[2].getShortName());
    items[2].setPrice(temps[2].getPrice());
    }
    else{
    items[1].setDescription(temps[2].getDescription());
    items[1].setShortName(temps[2].getShortName());
    items[1].setPrice(temps[2].getPrice());

    items[2].setDescription(temps[1].getDescription());
    items[2].setShortName(temps[1].getShortName());
    items[2].setPrice(temps[1].getPrice());
    }

    /// Set second pair
    if (pos2 == 0){
    items[3].setDescription(temps[3].getDescription());
    items[3].setShortName(temps[3].getShortName());
    items[3].setPrice(temps[3].getPrice());

    items[4].setDescription(temps[4].getDescription());
    items[4].setShortName(temps[4].getShortName());
    items[4].setPrice(temps[4].getPrice());
    }
    else{
    items[3].setDescription(temps[4].getDescription());
    items[3].setShortName(temps[4].getShortName());
    items[3].setPrice(temps[4].getPrice());

    items[4].setDescription(temps[3].getDescription());
    items[4].setShortName(temps[3].getShortName());
    items[4].setPrice(temps[3].getPrice());
    }

    /// Set third pair
    if (pos3 == 0){
    items[5].setDescription(temps[5].getDescription());
    items[5].setShortName(temps[5].getShortName());
    items[5].setPrice(temps[5].getPrice());

    items[6].setDescription(temps[6].getDescription());
    items[6].setShortName(temps[6].getShortName());
    items[6].setPrice(temps[6].getPrice());
    }
    else{
    items[5].setDescription(temps[6].getDescription());
    items[5].setShortName(temps[6].getShortName());
    items[5].setPrice(temps[6].getPrice());

    items[6].setDescription(temps[5].getDescription());
    items[6].setShortName(temps[5].getShortName());
    items[6].setPrice(temps[5].getPrice());
    }

/*
    for (int b = 0; b < 7; b++){
        cout << endl << b+1 << ". ";
        items[b].showPrize();
        cout << " - $" << items[b].getPrice();
    }
*/

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    int start = items[0].getPrice();
    small chosen1;
    small chosen2;
    small chosen3;

    cout << endl << "Base item:" << endl;
    items[0].showPrize();

    /// First pair of items
    cout << endl;
    cout << endl << "1. ";
    items[1].showPrize();
    cout << endl << "2. ";
    items[2].showPrize();

    while ( (choice1 < 1) || (choice1 > 2) ){
        cout << endl << "Which item is more expensive than the ";
        items[0].showShortName();
        cout << "?: ";
        cin >> choice1;
    }
    cout << endl << "Let's reveal the price of the item you didn't pick.";
    if (choice1 == 1){
        cout << endl << "The actual retail price of the ";
        items[2].showShortName();
        cout << " is $" << items[2].getPrice();
        chosen1.setDescription(items[1].getDescription());
        chosen1.setShortName(items[1].getShortName());
        chosen1.setPrice(items[1].getPrice());
    }
    else{
        cout << endl << "The actual retail price of the ";
        items[1].showShortName();
        cout << " is $" << items[1].getPrice();
        chosen1.setDescription(items[2].getDescription());
        chosen1.setShortName(items[2].getShortName());
        chosen1.setPrice(items[2].getPrice());
    }

    cout << endl;
    cout << endl << "Base item:" << endl;
    chosen1.showPrize();

    /// Second pair of items
    cout << endl;
    cout << endl << "1. ";
    items[3].showPrize();
    cout << endl << "2. ";
    items[4].showPrize();

    while ( (choice2 < 1) || (choice2 > 2) ){
        cout << endl << "Which item is more expensive than the ";
        chosen1.showShortName();
        cout << "?: ";
        cin >> choice2;
    }
    cout << endl << "Let's reveal the price of the item you didn't pick.";
    if (choice2 == 1){
        cout << endl << "The actual retail price of the ";
        items[4].showShortName();
        cout << " is $" << items[4].getPrice();
        chosen2.setDescription(items[3].getDescription());
        chosen2.setShortName(items[3].getShortName());
        chosen2.setPrice(items[3].getPrice());
    }
    else{
        cout << endl << "The actual retail price of the ";
        items[3].showShortName();
        cout << " is $" << items[3].getPrice();
        chosen2.setDescription(items[4].getDescription());
        chosen2.setShortName(items[4].getShortName());
        chosen2.setPrice(items[4].getPrice());
    }
    cout << endl;
    cout << endl << "Base item:" << endl;
    chosen2.showPrize();

    /// Third pair of items
    cout << endl;
    cout << endl << "1. ";
    items[5].showPrize();
    cout << endl << "2. ";
    items[6].showPrize();

    while ( (choice3 < 1) || (choice3 > 2) ){
        cout << endl << "Which item is more expensive than the ";
        chosen2.showShortName();
        cout << "?: ";
        cin >> choice3;
    }
    cout << endl << "Let's reveal the price of the item you didn't pick.";
    if (choice3 == 1){
        cout << endl << "The actual retail price of the ";
        items[6].showShortName();
        cout << " is $" << items[6].getPrice();
        chosen3.setDescription(items[5].getDescription());
        chosen3.setShortName(items[5].getShortName());
        chosen3.setPrice(items[5].getPrice());
    }
    else{
        cout << endl << "The actual retail price of the ";
        items[5].showShortName();
        cout << " is $" << items[5].getPrice();
        chosen3.setDescription(items[6].getDescription());
        chosen3.setShortName(items[6].getShortName());
        chosen3.setPrice(items[6].getPrice());
    }
    cout << endl;

    cout << endl << "Let's see if you've won.";
    cout << endl << "The actual retail price of the ";
    items[0].showShortName();
    cout << " is $" << items[0].getPrice();
    cout << endl;
    system("pause");
    cout << endl << "The actual retail price of the ";
    chosen1.showShortName();
    cout << " is $" << chosen1.getPrice();
    if (chosen1.getPrice() < items[0].getPrice())
        cout << endl << "Sorry, you lose.";
    else{
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        chosen2.showShortName();
        cout << " is $" << chosen2.getPrice();
        if (chosen2.getPrice() < chosen1.getPrice())
            cout << endl << "Sorry, you lose.";
        else
        {
            cout << endl;
            system("pause");
            cout << endl << "The actual retail price of the ";
            chosen3.showShortName();
            cout << " is $" << chosen3.getPrice();
            if (chosen3.getPrice() < chosen2.getPrice())
                cout << endl << "Sorry, you lose.";
            else
                cout << endl << "Congratulations, you win!";
        } // else if player didn't lose on pair #2
    } // else if player didn't lose on pair #1

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

#endif // SMALLPRIZE_H_INCLUDED
