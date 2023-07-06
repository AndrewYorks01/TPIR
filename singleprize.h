/// Single-prize (mostly quickies) games.

#ifndef SINGLEPRIZE_H_INCLUDED
#define SINGLEPRIZE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <list>

#include "prize.h"

using namespace std;

   /// Prizes used in Coming or Going can't end in 0, and preferably not with 1 or 2. Also, the price can't
    /// be a palindrome.
    bool compatibleForCOG(int price)
    {
    if (price % 10 == 0) /// check if the price ends in 0 (bad!)
        return false;
    else
    {

    if (price < 10000) /// 4-digit price.
    {
        int fourdigit[4];
        fourdigit[0] = price / 1000 % 10;
        fourdigit[1] = price / 100 % 10;
        fourdigit[2] = price / 10 % 10;
        fourdigit[3] = price % 10;
        if (fourdigit[3] == 1) /// check if the price ends in 1 (less bad)
            return false;
        else if (fourdigit[3] == 2) /// check if the price ends in 2 (not ideal)
            return false;
        else
        {
            /// check if the price is a palindrome
            if ( (fourdigit[0] == fourdigit[3]) && (fourdigit[1] == fourdigit[2]) )
                return false;
            else
                return true;
        }

    }
    else /// 5-digit price. (Yes, the real Coming or Going has never used 5-digit prices, but who says we can't?)
    {
       int fivedigit[5];
        fivedigit[0] = price / 10000 % 10;
        fivedigit[1] = price / 1000 % 10;
        fivedigit[2] = price / 100 % 10;
        fivedigit[3] = price / 10 % 10;
        fivedigit[4] = price % 10;
        if (fivedigit[4] == 1) /// check if the price ends in 1 (less bad)
            return false;
        else if (fivedigit[4] == 2) /// check if the price ends in 2 (not ideal)
            return false;
        else
        {
            /// check if the price is a palindrome
            if ( (fivedigit[0] == fivedigit[4]) && (fivedigit[1] == fivedigit[3]) )
                return false;
            else
                return true;
        }

    }

    } // end else

    } // end bool
   /// The prizes in Flip Flop are all four digits. The first and second digit can't be the same, nor can the third
   /// and fourth digit. Also, the second digit can't be zero.
    bool compatibleForFlipFlop(int price)
    {
    if (price > 9999)
        return false;
    else
    {
        int fourdigit[4];
        fourdigit[0] = price / 1000 % 10;
        fourdigit[1] = price / 100 % 10;
        fourdigit[2] = price / 10 % 10;
        fourdigit[3] = price % 10;

        if (fourdigit[0] == fourdigit[1]) /// check if first and second digits are the same
            return false;
        else if (fourdigit[2] == fourdigit[3]) /// check if third and fourth digits are the same
            return false;
        else if (fourdigit[1] == 0) /// check if second digit is zero
            return false;
        else
            return true;

    } // end else
    }
   /// The prizes in Side by Side are all four digits. Both set of digits can't be the same (e.g., a price like 4242
    /// doesn't work). Also, the third digit can't be zero.
    bool compatibleForSBS(int price)
    {
        if (price > 9999)
            return false;
        else
        {
        int fourdigit[4];
        fourdigit[0] = price / 1000 % 10;
        fourdigit[1] = price / 100 % 10;
        fourdigit[2] = price / 10 % 10;
        fourdigit[3] = price % 10;

        if (fourdigit[2] == 0)
            return false;
        else
        {
            if ( (fourdigit[0] == fourdigit[2]) && (fourdigit[1] == fourdigit[3]) )
                return false;
            else
                return true;
        }

        } // end else

    } // end bool

    /// Uses a bubble sort algorithm to sort the number choices in Pick-a-Number.
    void sortPickNumbers(int nos[])
    {
        int temp;
        int iter;
        int index;
        for (iter = 1; iter < 3; iter++)
        {
            for (index = 0; index < 3-iter; index++)
                if (nos[index] > nos[index + 1])
                {
                    temp = nos[index];
                    nos[index] = nos[index + 1];
                    nos[index + 1] = temp;
                }
        }
    }
    /// Takes an int and makes it show up with a zero before it. This is the same function used in Money Game and Gridlock!.
    string ffSpace(int value)
    {
        string r;
        if (value < 10)
            r = "0" + to_string(value);
        else
            r = to_string(value);
        return r;
    }

    /// The prizes in One Way or Another are all four digits. The second and last digits in the price
    /// can't be 0, 1, or 2, and all four digits in the price can't be the same.
    bool compatibleForOneWayOrAnother(int price)
    {
        if (price > 9999)
            return false;
        else{
        int fourdigit[4];
        fourdigit[0] = price / 1000 % 10;
        fourdigit[1] = price / 100 % 10;
        fourdigit[2] = price / 10 % 10;
        fourdigit[3] = price % 10;

        if (price % 1111 == 0)
            return false;
        else if (fourdigit[3] == 0)
            return false;
        else if (fourdigit[3] == 1)
            return false;
        else if (fourdigit[3] == 2)
            return false;
        else if (fourdigit[1] == 0)
            return false;
        else if (fourdigit[1] == 1)
            return false;
        else if (fourdigit[1] == 2)
            return false;
        else
            return true;
        } // end else
    }

    /// The prizes in Jam are all four digits. There can't be any repeating digits, and at least two of the
    /// digits have to be at least 3.
    bool compatibleForJam(int price)
    {
    if (price > 9999)
            return false;
        else{
        int fourdigit[4];
        fourdigit[0] = price / 1000 % 10;
        fourdigit[1] = price / 100 % 10;
        fourdigit[2] = price / 10 % 10;
        fourdigit[3] = price % 10;

        if (fourdigit[1] == fourdigit[0])
            return false;
        else if ((fourdigit[2] == fourdigit[0]) || (fourdigit[2] == fourdigit[1]))
            return false;
        else if ((fourdigit[3] == fourdigit[0]) || (fourdigit[3] == fourdigit[1]) || (fourdigit[3] == fourdigit[2]) )
            return false;
        else{
        int flag = 0;
        for (int check = 0; check < 4; check++){
            if (fourdigit[0] >= 3)
                flag += 1;
        }
        if (flag >= 2)
            return true;
        else
            return false;
        } // price has no repeating digits
        } // price has 4 digits
    }

/// Balance Game
void playBalanceGame()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && (t_Price < 13000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "BALANCE GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();

    /// Round down to the nearest multiple of 1000. The two bags' total must equal this.
    int thousandths = gamePrize.getPrice() - (gamePrize.getPrice() % 1000);

    int smallBag = gamePrize.getPrice() - thousandths;
    int bigBags[3];

    /// This generates the bags.
    /// For example, if "thousandths" equals 6000, we could generate 4000 and 2000.
    /// If thousandths is divisible by 2000, we don't want two identical values.
    if ( (thousandths % 2000) == 0)
    {
        if (thousandths == 4000)
        {
            bigBags[0] = 3;
            bigBags[1] = 1;
        } /// end if thousandths is 4000

        if (thousandths == 6000)
        {
            int set6000 = rand() % 2;
            if (set6000 == 0)
            {
                bigBags[0] = 5;
                bigBags[1] = 1;
            } // end for 0
            if (set6000 == 1)
            {
                bigBags[0] = 4;
                bigBags[1] = 2;
            } // end for 1
        } /// end if thousandths is 6000

        if (thousandths == 8000)
        {
            int set8000 = rand() % 3;
            if (set8000 == 0)
            {
                bigBags[0] = 7;
                bigBags[1] = 1;
            } // end for 0
            if (set8000 == 1)
            {
                bigBags[0] = 6;
                bigBags[1] = 2;
            } // end for 1
            if (set8000 == 2)
            {
                bigBags[0] = 5;
                bigBags[1] = 3;
            } // end for 2

        } /// end if thousandths is 8000

        if (thousandths == 10000)
        {
            int set10000 = rand() % 4;
            if (set10000 == 0)
            {
                bigBags[0] = 9;
                bigBags[1] = 1;
            } // end for 0
            if (set10000 == 1)
            {
                bigBags[0] = 8;
                bigBags[1] = 2;
            } // end for 1
            if (set10000 == 2)
            {
                bigBags[0] = 7;
                bigBags[1] = 3;
            } // end for 2
            if (set10000 == 3)
            {
                bigBags[0] = 6;
                bigBags[1] = 4;
            } // end for 3
        } /// end if thousandths is 10000

        if (thousandths == 120000)
        {
            int set12000 = rand() % 5;
            if (set12000 == 0)
            {
                bigBags[0] = 11;
                bigBags[1] = 1;
            } // end for 0
            if (set12000 == 1)
            {
                bigBags[0] = 10;
                bigBags[1] = 2;
            } // end for 1
            if (set12000 == 2)
            {
                bigBags[0] = 9;
                bigBags[1] = 3;
            } // end for 2
            if (set12000 == 3)
            {
                bigBags[0] = 8;
                bigBags[1] = 4;
            } // end for 3
            if (set12000 == 4)
            {
                bigBags[0] = 7;
                bigBags[1] = 5;
            } // end for 4
        } /// endif thousandths is 12000

    } /// end for if thousandths is divisible by 2000
    else
    {
        if (thousandths == 3000)
        {
            bigBags[0] = 2;
            bigBags[1] = 1;
        } /// end if thousandths is 3000

        if (thousandths == 5000)
        {
            int set5000 = rand() % 2;
            if (set5000 == 0)
            {
                bigBags[0] = 4;
                bigBags[1] = 1;
            } // end for 0
            if (set5000 == 1)
            {
                bigBags[0] = 3;
                bigBags[1] = 2;
            } // end for 1
        } /// end if thousandths is 5000

        if (thousandths == 7000)
        {
            int set7000 = rand() % 3;
            if (set7000 == 0)
            {
                bigBags[0] = 6;
                bigBags[1] = 1;
            } // end for 0
            if (set7000 == 1)
            {
                bigBags[0] = 5;
                bigBags[1] = 2;
            } // end for 1
            if (set7000 == 2)
            {
                bigBags[0] = 4;
                bigBags[1] = 3;
            } // end for 2

        } /// end if thousandths is 7000

        if (thousandths == 9000)
        {
            int set9000 = rand() % 4;
            if (set9000 == 0)
            {
                bigBags[0] = 8;
                bigBags[1] = 1;
            } // end for 0
            if (set9000 == 1)
            {
                bigBags[0] = 7;
                bigBags[1] = 2;
            } // end for 1
            if (set9000 == 2)
            {
                bigBags[0] = 6;
                bigBags[1] = 3;
            } // end for 2
            if (set9000 == 3)
            {
                bigBags[0] = 5;
                bigBags[1] = 4;
            } // end for 3
        } /// end if thousandths is 9000

        if (thousandths == 110000)
        {
            int set11000 = rand() % 5;
            if (set11000 == 0)
            {
                bigBags[0] = 10;
                bigBags[1] = 1;
            } // end for 0
            if (set11000 == 1)
            {
                bigBags[0] = 9;
                bigBags[1] = 2;
            } // end for 1
            if (set11000 == 2)
            {
                bigBags[0] = 8;
                bigBags[1] = 3;
            } // end for 2
            if (set11000 == 3)
            {
                bigBags[0] = 7;
                bigBags[1] = 4;
            } // end for 3
            if (set11000 == 4)
            {
                bigBags[0] = 6;
                bigBags[1] = 5;
            } // end for 4
        } /// endif thousandths is 11000

    } /// end for if thousandths is not divisible by 2000

    int unused = 0;
    unused = bigBags[0];
    while ( (unused == bigBags[0]) || (unused == bigBags[1]) ){
        unused = rand() % (thousandths / 1000) + 1;
        }
    unused *= 1000;

    bigBags[0] *= 1000;
    bigBags[1] *= 1000;
    bigBags[2] = unused;

    //cout << "unused = " << unused;
    cout << endl;
    //cout << endl << "price = " << gamePrize.getPrice() << endl;
    //cout << endl << "bags = " << thousandths << endl;

    random_shuffle(&bigBags[0], &bigBags[3]);

    int playerSide = smallBag;
    int placed = 0;

    bool pickedBag[3];
    for (int x = 0; x < 3; x++)
        pickedBag[x] = false;

    while (placed < 2){
    int choice = 0;
    for (int x = 0; x < 3; x++){
        cout << x+1 << ". " << bigBags[x];
        if (pickedBag[x])
            cout << " - O";
        cout << endl;
        }
    cout << "The scale is currently set to $" << playerSide << "." << endl;
    cout << "Which bag do you want to add to the scale?: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        if (pickedBag[0])
            cout << endl << "You've already picked this bag. Please pick another.";
        else
        {
            pickedBag[0] = true;
            playerSide += bigBags[0];
            placed += 1;
        }
        break;

    case 2:
        if (pickedBag[1])
            cout << endl << "You've already picked this bag. Please pick another.";
        else
        {
            pickedBag[1] = true;
            playerSide += bigBags[1];
            placed += 1;
        }
        break;

    case 3:
        if (pickedBag[2])
            cout << endl << "You've already picked this bag. Please pick another.";
        else
        {
            pickedBag[2] = true;
            playerSide += bigBags[2];
            placed += 1;
        }
        break;

    default:
        cout << endl << "That won't work. Try again." << endl;

    } /// end switch
    cout << endl;
    } /// end while loop

    cout << "You've set the scale to $" << playerSide;
    cout << endl << "The actual retail price of the item is $" << gamePrize.getPrice();

    if (playerSide == gamePrize.getPrice())
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Bonkers
void playBonkers()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "BONKERS" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int thePrice = gamePrize.getPrice();

    int priceDigits[4];
    priceDigits[0] = thePrice / 1000 % 10;
    priceDigits[1] = thePrice / 100 % 10;
    priceDigits[2] = thePrice / 10 % 10;
    priceDigits[3] = thePrice % 10;

    /// These will be set to 0 if they need to be made HIGHER (the wrong digit will be too low)
    /// and 1 if they need to be made LOWER (the wrong digit will be too high).
    int pos1;
    int pos2;
    int pos3;
    int pos4;

    if (priceDigits[0] == 9)
        pos1 = 0;
    else if (priceDigits[0] == 8)
        pos1 = 0;
    else
        pos1 = rand() % 2;

    if (priceDigits[1] == 9)
        pos2 = 0;
    else if (priceDigits[1] == 8)
        pos2 = 0;
    else if (priceDigits[1] == 0)
        pos2 = 1;
    else if (priceDigits[1] == 1)
        pos2 = 1;
    else
        pos2 = rand() % 2;

    if (priceDigits[2] == 9)
        pos3 = 0;
    else if (priceDigits[2] == 8)
        pos3 = 0;
    else if (priceDigits[2] == 0)
        pos3 = 1;
    else if (priceDigits[2] == 1)
        pos3 = 1;
    else
        pos3 = rand() % 2;

    if (priceDigits[3] == 9)
        pos4 = 0;
    else if (priceDigits[3] == 8)
        pos4 = 0;
    else if (priceDigits[3] == 0)
        pos4 = 1;
    else if (priceDigits[3] == 1)
        pos4 = 1;
    else
        pos4 = rand() % 2;

    //cout << endl << "pattern: " << pos1 << pos2 << pos3 << pos4;
    //cout << endl << "price: $" << thePrice;

    int wrongDigits[4];

    /// Set the first wrong digit
    if (pos1 == 0)
        wrongDigits[0] = rand()%( (priceDigits[0] - 1) -4 + 1) + 4;
    else{ // generate a random number higher than the correct digit
        //int randNum = rand()%(max-min + 1) + min;
        if (priceDigits[0] == 8)
          wrongDigits[0] = 9;
        else if (priceDigits[0] == 7)
          wrongDigits[0] = 8;
        else if (priceDigits[0] == 6)
          wrongDigits[0] = rand()%(8-7 + 1) + 7;
        else if (priceDigits[0] == 5)
          wrongDigits[0] = rand()%(8-6 + 1) + 6;
        else if (priceDigits[0] == 4)
          wrongDigits[0] = rand()%(8-5 + 1) + 5;
        else
          wrongDigits[0] = rand()%(8-4 + 1) + 4;
//        while ( (wrongDigits[0] < 0) || (wrongDigits[0] > 9) )
//            wrongDigits[0] = rand()%(8 - (priceDigits[0]) + 1) + (priceDigits[0]+1);
        }
    //cout << endl << "wrong[0] = " << wrongDigits[0];

    /// Set the second wrong digit
    if (pos2 == 0)
        wrongDigits[1] = rand()%( (priceDigits[1] - 1) - 1 + 1) + 1;
    else{
        //while ( (wrongDigits[1] < 1) || (wrongDigits[1] > 9) )
        //    wrongDigits[1] = rand()%(8 - ( priceDigits[1]+1) + 1) + (priceDigits[1]+1);
        if (priceDigits[1] == 8)
          wrongDigits[1] = 9;
        else if (priceDigits[1] == 7)
          wrongDigits[1] = 8;
        else if (priceDigits[1] == 6)
          wrongDigits[1] = rand()%(8-7 + 1) + 7;
        else if (priceDigits[1] == 5)
          wrongDigits[1] = rand()%(8-6 + 1) + 6;
        else if (priceDigits[1] == 4)
          wrongDigits[1] = rand()%(8-5 + 1) + 5;
        else if (priceDigits[1] == 3)
          wrongDigits[1] = rand()%(8-4 + 1) + 4;
        else if (priceDigits[1] == 2)
          wrongDigits[1] = rand()%(8-3 + 1) + 3;
        else if (priceDigits[1] == 1)
          wrongDigits[1] = rand()%(8-2 + 1) + 2;
        else
         wrongDigits[1] = rand()%(8-1 + 1) + 1;
        }
    //cout << endl << "wrong[1] = " << wrongDigits[1];

    /// Set the third wrong digit
    if (pos3 == 0)
        wrongDigits[2] = rand()%( (priceDigits[2] - 1) - 1 + 1) + 1;
    else{
        //while ( (wrongDigits[2] < 1) || (wrongDigits[2] > 9) )
        //    wrongDigits[2] = rand()%(8 - (priceDigits[2]+1) + 1) + (priceDigits[2]+1);
        if (priceDigits[2] == 8)
          wrongDigits[2] = 9;
        else if (priceDigits[2] == 7)
          wrongDigits[2] = 8;
        else if (priceDigits[2] == 6)
          wrongDigits[2] = rand()%(8-7 + 1) + 7;
        else if (priceDigits[2] == 5)
          wrongDigits[2] = rand()%(8-6 + 1) + 6;
        else if (priceDigits[2] == 4)
          wrongDigits[2] = rand()%(8-5 + 1) + 5;
        else if (priceDigits[2] == 3)
          wrongDigits[2] = rand()%(8-4 + 1) + 4;
        else if (priceDigits[2] == 2)
          wrongDigits[2] = rand()%(8-3 + 1) + 3;
        else if (priceDigits[2] == 1)
          wrongDigits[2] = rand()%(8-2 + 1) + 2;
        else
         wrongDigits[2] = rand()%(8-1 + 1) + 1;
        }
    //cout << endl << "wrong[2] = " << wrongDigits[2];

    /// Set the fourth wrong digit
    if (pos4 == 0)
        wrongDigits[3] = rand()%( (priceDigits[3] - 1) - 1 + 1) + 1;
    else{
        //while ( (wrongDigits[3] < 1) || (wrongDigits[3] > 9) )
        //    wrongDigits[3] = rand()%(8 - (priceDigits[3]+1) + 1) + (priceDigits[3]+1);
        if (priceDigits[3] == 8)
          wrongDigits[3] = 9;
        else if (priceDigits[3] == 7)
          wrongDigits[3] = 8;
        else if (priceDigits[3] == 6)
          wrongDigits[3] = rand()%(8-7 + 1) + 7;
        else if (priceDigits[3] == 5)
          wrongDigits[3] = rand()%(8-6 + 1) + 6;
        else if (priceDigits[3] == 4)
          wrongDigits[3] = rand()%(8-5 + 1) + 5;
        else if (priceDigits[3] == 3)
          wrongDigits[3] = rand()%(8-4 + 1) + 4;
        else if (priceDigits[3] == 2)
          wrongDigits[3] = rand()%(8-3 + 1) + 3;
        else if (priceDigits[3] == 1)
          wrongDigits[3] = rand()%(8-2 + 1) + 2;
        else
         wrongDigits[3] = rand()%(8-1 + 1) + 1;
        }
    //cout << endl << "wrong[3] = " << wrongDigits[3];

    //cout << endl << "set digits";

//    if ( (wrongDigits[0] == 0) && (priceDigits[0] != 1) && (pos1 == 1) )
//        wrongDigits[0] = 1;
//    if ( (wrongDigits[1] == 0) && (priceDigits[1] != 1) && (pos2 == 1) )
//        wrongDigits[1] = 1;
//    if ( (wrongDigits[2] == 0) && (priceDigits[2] != 1) && (pos3 == 1) )
//        wrongDigits[2] = 1;
//    if ( (wrongDigits[3] == 0) && (priceDigits[3] != 1) && (pos4 == 1) )
//        wrongDigits[3] = 1;

    //cout << endl << "wrong price: $" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];

    int chances = 6;
    bool won = false;

    while ( (chances > 0) && (!won)){
    int p1 = 10;
    int p2 = 10;
    int p3 = 10;
    int p4 = 10;

    /// Digit #1
    cout << endl << " H";
    cout << endl << "$" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];
    cout << endl << " L";
    char entry1 = '!';
    while ( (entry1 != 'H') && (entry1 != 'h') && (entry1 != 'L') && (entry1 != 'l') ){
        cout << endl << "Is the first digit higher (H) or lower (L)?: ";
        cin >> entry1;
    }
    if ( (entry1 == 'H') || (entry1 == 'h') )
        p1 = 0;
    else
        p1 = 1;

    /// Digit #2
    cout << endl << " ";
    if (p1 == 0)
        cout << "*H";
    else
        cout << " H";
    cout << endl << "$" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];
    cout << endl << " ";
    if (p1 == 1)
        cout << "*L";
    else
        cout << " L";
    char entry2 = '!';
    while ( (entry2 != 'H') && (entry2 != 'h') && (entry2 != 'L') && (entry2 != 'l') ){
        cout << endl << "Is the second digit higher (H) or lower (L)?: ";
        cin >> entry2;
    }
    if ( (entry2 == 'H') || (entry2 == 'h') )
        p2 = 0;
    else
        p2 = 1;

    /// Digit #3
    cout << endl << " ";
    if (p1 == 0)
        cout << "*";
    else
        cout << " ";
    if (p2 == 0)
        cout << "*H";
    else
        cout << " H";
    cout << endl << "$" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];
    cout << endl << " ";
    if (p1 == 1)
        cout << "*";
    else
        cout << " ";
    if (p2 == 1)
        cout << "*L";
    else
        cout << " L";
    char entry3 = '!';
    while ( (entry3 != 'H') && (entry3 != 'h') && (entry3 != 'L') && (entry3 != 'l') ){
        cout << endl << "Is the third digit higher (H) or lower (L)?: ";
        cin >> entry3;
    }
    if ( (entry3 == 'H') || (entry3 == 'h') )
        p3 = 0;
    else
        p3 = 1;

    /// Digit #4
    cout << endl << " ";
    if (p1 == 0)
        cout << "*";
    else
        cout << " ";
    if (p2 == 0)
        cout << "*";
    else
        cout << " ";
    if (p3 == 0)
        cout << "*H";
    else
        cout << " H";
    cout << endl << "$" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];
    cout << endl << " ";
    if (p1 == 1)
        cout << "*";
    else
        cout << " ";
    if (p2 == 1)
        cout << "*";
    else
        cout << " ";
    if (p3 == 1)
        cout << "*L";
    else
        cout << " L";
    char entry4 = '!';
    while ( (entry4 != 'H') && (entry4 != 'h') && (entry4 != 'L') && (entry4 != 'l') ){
        cout << endl << "Is the fourth digit higher (H) or lower (L)?: ";
        cin >> entry4;
    }
    if ( (entry4 == 'H') || (entry4 == 'h') )
        p4 = 0;
    else
        p4 = 1;

    /// Check
    cout << endl << " ";
    if (p1 == 0)
        cout << "*";
    else
        cout << " ";
    if (p2 == 0)
        cout << "*";
    else
        cout << " ";
    if (p3 == 0)
        cout << "*";
    else
        cout << " ";
    if (p4 == 0)
        cout << "*";
    else
        cout << " ";
    cout << endl << "$" << wrongDigits[0] << wrongDigits[1] << wrongDigits[2] << wrongDigits[3];
    cout << endl << " ";
    if (p1 == 1)
        cout << "*";
    else
        cout << " ";
    if (p2 == 1)
        cout << "*";
    else
        cout << " ";
    if (p3 == 1)
        cout << "*";
    else
        cout << " ";
    if (p4 == 1)
        cout << "*";
    else
        cout << " ";

    cout << endl << "Let's see if you're right...";
    cout << endl;
    system("pause");

    if ( (p1 == pos1) && (p2 == pos2) && (p3 == pos3) && (p4 == pos4) )
        won = true;
    else{
        cout << endl << "Sorry, that's not correct.";
        chances -= 1;
    }

    } // end while loop

    if (won){
        cout << endl << "$" << thePrice;
        cout << endl << "Congratulations, you win!";
    }
    else{
        cout << endl;
        cout << endl << "$" << thePrice;
        cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Check Game
void playCheckGame()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && t_Price < 8000)
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "CHECK GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();

    int checkAmount = 0;
    int total = 0;

    cout << endl << "AT LEAST $8,000 BUT NOT OVER $9,000" << endl;
    cout << "How much will you write the check for?: $";
    cin >> checkAmount;
    cout << endl;
    cout << "You wrote the check for $" << checkAmount << endl;
    system("pause");
    cout << endl << "The actual retail price of the prize is ";
    gamePrize.showARP();
    cout << endl;
    total = checkAmount + gamePrize.getPrice();
    cout << endl << "For a total of $" << total;
    cout << endl;
    if ((total >= 8000) && (total <= 9000))
        cout << endl << "Congratulations, you win!";
    else if (total < 8000)
        cout << endl << "Sorry, you lose.";
    else if (total > 9000)
        cout << endl << "Sorry, you went over.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Coming or Going
void playComingOrGoing()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (compatibleForCOG(t_Price)) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "COMING OR GOING" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int orientation = rand() % 2; /// if 0, then COMING. if 1, then GOING.

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();
    int alternateOrientation = 0;
    if (itemPrice < 10000){
    alternateOrientation =
            (itemPrice / 1000 % 10) + // first digit
            (itemPrice / 100 % 10)*10 + // second digit
            (itemPrice / 10 % 10)*100 + // third digit
            (itemPrice % 10)*1000; // fourth digit
    }
    cout << endl;

    if (orientation == 0) /// the correct answer is COMING
    {
    cout << "COMING: $" << itemPrice << endl;
    cout << "GOING: $" << alternateOrientation << endl;
    }
    else /// the correct answer is GOING
    {
    cout << "COMING: $" << alternateOrientation << endl;
    cout << "GOING: $" << itemPrice << endl;
    }

    //cout << "Answer: " << orientation+1 << endl;

    int answer = 0;
    while ((answer < 1) || (answer > 2))
    {
        cout << "Are you coming (1) or going (2)?: ";
        cin >> answer;
    }
    cout << endl << "The actual retail price is $" << itemPrice << endl;
    if (answer == orientation+1)
        cout << "Congratulations, you win!";
    else
        cout << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Double Prices
void playDoublePrices()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( inFile >> t_Description >> t_ShortName >> t_Price )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "DOUBLE PRICES" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int position = rand() % 2; /// if 0, the correct price is #1. If 1, the correct price is #2.

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();
    int wrongPrice = itemPrice;

    if (itemPrice < 10000){
    while (wrongPrice == itemPrice){
    wrongPrice = rand() % (9999 - 3500) + 3500;
    }
    }
    else{
    while (wrongPrice == itemPrice){
    wrongPrice = rand() % (15000 - 10000) + 10000;
    }
    }

    cout << endl;

    if (position == 0)
    {
        cout << "1. $" << itemPrice << endl;
        cout << "2. $" << wrongPrice << endl;
    }
    else
    {
        cout << "1. $" << wrongPrice << endl;
        cout << "2. $" << itemPrice << endl;
    }

    int choice = 0;
    while ((choice < 1) || (choice > 2))
    {
        cout << endl << "Which is the correct price?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price is $" << itemPrice;
    cout << endl;
    if (choice == position+1)
        cout << "Congratulations, you win!";
    else
        cout << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Flip Flop
void playFlipFlop()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (compatibleForFlipFlop(t_Price)) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "FLIP FLOP" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int todo = rand() % 3; /// if 0, then FLIP. if 1, then FLOP. if 2, then FLIP-FLOP.

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();
    int wrongPrice = 0;
    int flipPrice = 0;
    int flopPrice = 0;
    int flipFlopPrice = 0;
    if (todo == 0) /// the correct answer is FLIP
    {
        wrongPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                ((itemPrice / 10 % 10) * 10) +   // third digit
                (itemPrice % 10);                // fourth digit
        flipPrice = itemPrice;
        flopPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                (itemPrice / 10 % 10) +           // third digit
                ((itemPrice % 10) * 10);          // fourth digit
        flipFlopPrice =
                ((itemPrice / 1000 % 10) * 1000) + // first digit
                ((itemPrice / 100 % 10) * 100) + // second digit
                (itemPrice / 10 % 10) +           // third digit
                ((itemPrice % 10) * 10);          // fourth digit

    }
    else if (todo == 1)
    {
        wrongPrice =
                ((itemPrice / 1000 % 10) * 1000) + // first digit
                ((itemPrice / 100 % 10) * 100) + // second digit
                (itemPrice / 10 % 10) +           // third digit
                ((itemPrice % 10) * 10);          // fourth digit
        flipPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                ((itemPrice / 1 % 10) * 10) +   // third digit
                (itemPrice / 10 % 10);                // fourth digit
        flopPrice = itemPrice;
        flipFlopPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                ((itemPrice / 10 % 10) * 10) +   // third digit
                (itemPrice % 10);

    }
    else
    {
        wrongPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                ((itemPrice / 1 % 10) * 10) +   // third digit
                (itemPrice / 10 % 10);                // fourth digit
        flipPrice =
                ((itemPrice / 1000 % 10) * 1000) + // first digit
                ((itemPrice / 100 % 10) * 100) + // second digit
                ((itemPrice / 1 % 10) * 10) +   // third digit
                (itemPrice / 10 % 10);                // fourth digit
        flopPrice =
                ((itemPrice / 100 % 10) * 1000) + // first digit
                ((itemPrice / 1000 % 10) * 100) + // second digit
                ((itemPrice / 10 % 10) * 10) +   // third digit
                (itemPrice / 1 % 10);                // fourth digit
        flipFlopPrice = itemPrice;
    }
    cout << endl;
    cout << endl;
    cout << "The price is not $" << wrongPrice << "." << endl;
    cout << "But you can FLIP (1) and make it $" << flipPrice << endl;
    cout << "Or you can FLOP (2) and make it $" << flopPrice << endl;
    cout << "Or you can FLIP-FLOP (3) and make it $" << flipFlopPrice << endl;
    int choice = 0;
    while ((choice < 1) || (choice > 3))
    {
        cout << endl << "Which would you like to do?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price is $" << itemPrice;
    cout << endl;
    if (choice == todo+1)
        cout << "Congratulations, you win!";
    else
        cout << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Freeze Frame
void playFreezeFrame()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "FREEZE FRAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();

    int aa = 0;
    int bb = 0;
    int cc = 0;
    int dd = 0;
    int ee = 0;
    int ff = 0;
    int gg = 0;
    int hh = 0;

    int position = rand() % 8; // determines which price will be correct
    //cout << endl << "position = " << position << endl;

    if (position == 0) // the correct price will be AAHH
        {
        aa = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        hh = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        bb = aa;
        while ( (bb == aa) || (bb == hh) )
            bb = rand() % 100;
        cc = aa;
        while ( (cc == aa) || (cc == hh) || (cc == bb) )
            cc = rand() % 100;
        dd = aa;
        while ( (dd == aa) || (dd == hh) || (dd == bb) || (dd == cc) )
            dd = rand() % 100;
        ee = aa;
        while ( (ee == aa) || (ee == hh) || (ee == bb) || (ee == cc) || (ee == dd) )
            ee = rand() % 100;
        ff = aa;
        while ( (ff == aa) || (ff == hh) || (ff == bb) || (ff == cc) || (ff == dd) || (ff == ee) )
            ff = rand() % 100;
        gg = aa;
        while ( (gg == aa) || (gg == hh) || (gg == bb) || (gg == cc) || (gg == dd) || (gg == ee) || (gg == ff) )
            gg = rand() % 100;
    }
    else if (position == 1) // the correct price will be BBAA
    {
        bb = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        aa = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        cc = bb;
        while ( (cc == bb) || (cc == aa) )
            cc = rand() % 100;
        dd = bb;
        while ( (dd == bb) || (dd == aa) || (dd == cc) )
            dd = rand() % 100;
        ee = bb;
        while ( (ee == bb) || (ee == aa) || (ee == cc) || (ee == dd) )
            ee = rand() % 100;
        ff = bb;
        while ( (ff == bb) || (ff == aa) || (ff == cc) || (ff == dd) || (ff == ee) )
            ff = rand() % 100;
        gg = bb;
        while ( (gg == bb) || (gg == aa) || (gg == cc) || (gg == dd) || (gg == ee) || (gg == ff) )
            gg = rand() % 100;
        hh = bb;
        while ( (hh == bb) || (hh == aa) || (hh == cc) || (hh == dd) || (hh == ee) || (hh == ff) || (hh == gg) )
            hh = rand() % 100;
    }
    else if (position == 2) // the correct price will be CCBB
    {
        cc = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        bb = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = cc;
        while ( (aa == cc) || (aa == bb) )
            aa = rand() % 100;
        dd = cc;
        while ( (dd == cc) || (dd == bb) || (dd == aa) )
            dd = rand() % 100;
        ee = cc;
        while ( (ee == cc) || (ee == bb) || (ee == aa) || (ee == dd) )
            ee = rand() % 100;
        ff = cc;
        while ( (ff == cc) || (ff == bb) || (ff == aa) || (ff == dd) || (ff == ee) )
            ff = rand() % 100;
        gg = cc;
        while ( (gg == cc) || (gg == bb) || (gg == aa) || (gg == dd) || (gg == ee) || (gg == ff) )
            gg = rand() % 100;
        hh = cc;
        while ( (hh == cc) || (hh == bb) || (hh == aa) || (hh == dd) || (hh == ee) || (hh == ff) || (hh == gg) )
            hh = rand() % 100;
    }
    else if (position == 3) // the correct price will be DDCC
    {
        dd = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        cc = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = dd;
        while ( (aa == dd) || (aa == cc) )
            aa = rand() % 100;
        bb = dd;
        while ( (bb == dd) || (bb == cc) || (bb == aa) )
            bb = rand() % 100;
        ee = dd;
        while ( (ee == dd) || (ee == cc) || (ee == aa) || (ee == bb) )
            ee = rand() % 100;
        ff = dd;
        while ( (ff == dd) || (ff == cc) || (ff == aa) || (ff == bb) || (ff == ee) )
            ff = rand() % 100;
        gg = dd;
        while ( (gg == dd) || (gg == cc) || (gg == aa) || (gg == bb) || (gg == ee) || (gg == ff) )
            gg = rand() % 100;
        hh = dd;
        while ( (hh == dd) || (hh == cc) || (hh == aa) || (hh == bb) || (hh == ee) || (hh == ff) || (hh == gg) )
            hh = rand() % 100;
    }
    else if (position == 4) // the correct price will be EEDD
    {
        ee = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        dd = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = ee;
        while ( (aa == ee) || (aa == dd) )
            aa = rand() % 100;
        bb = ee;
        while ( (bb == ee) || (bb == dd) || (bb == aa) )
            bb = rand() % 100;
        cc = ee;
        while ( (cc == ee) || (cc == dd) || (cc == aa) || (cc == bb) )
            cc = rand() % 100;
        ff = ee;
        while ( (ff == ee) || (ff == dd) || (ff == aa) || (ff == bb) || (ff == cc) )
            ff = rand() % 100;
        gg = ee;
        while ( (gg == ee) || (gg == dd) || (gg == aa) || (gg == bb) || (gg == cc) || (gg == ff) )
            gg = rand() % 100;
        hh = ee;
        while ( (hh == ee) || (hh == dd) || (hh == aa) || (hh == bb) || (hh == cc) || (hh == ff) || (hh == gg) )
            hh = rand() % 100;
    }
    else if (position == 5) // the correct price will be FFEE
    {
        ff = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        ee = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = ff;
        while ( (aa == ff) || (aa == ee) )
            aa = rand() % 100;
        bb = ff;
        while ( (bb == ff) || (bb == ee) || (bb == aa) )
            bb = rand() % 100;
        cc = ff;
        while ( (cc == ff) || (cc == ee) || (cc == aa) || (cc == bb) )
            cc = rand() % 100;
        dd = ff;
        while ( (dd == ff) || (dd == ee) || (dd == aa) || (dd == bb) || (dd == cc) )
            dd = rand() % 100;
        gg = ff;
        while ( (gg == ff) || (gg == ee) || (gg == aa) || (gg == bb) || (gg == cc) || (gg == dd) )
            gg = rand() % 100;
        hh = ff;
        while ( (hh == ff) || (hh == ee) || (hh == aa) || (hh == bb) || (hh == cc) || (hh == dd) || (hh == gg) )
            hh = rand() % 100;
    }
    else if (position == 6) // the correct price will be GGFF
    {
        gg = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        ff = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = gg;
        while ( (aa == gg) || (aa == ff) )
            aa = rand() % 100;
        bb = gg;
        while ( (bb == gg) || (bb == ff) || (bb == aa) )
            bb = rand() % 100;
        cc = gg;
        while ( (cc == gg) || (cc == ff) || (cc == aa) || (cc == bb) )
            cc = rand() % 100;
        dd = gg;
        while ( (dd == gg) || (dd == ff) || (dd == aa) || (dd == bb) || (dd == cc) )
            dd = rand() % 100;
        ee = gg;
        while ( (ee == gg) || (ee == ff) || (ee == aa) || (ee == bb) || (ee == cc) || (ee == dd) )
            ee = rand() % 100;
        hh = gg;
        while ( (hh == gg) || (hh == ff) || (hh == aa) || (hh == bb) || (hh == cc) || (hh == dd) || (hh == ee) )
            hh = rand() % 100;
    }
    else    // the correct price will be HHGG
    {
        hh = ( (itemPrice / 1000 % 10)*10 ) + (itemPrice / 100 % 10);
        gg = ( (itemPrice / 10 % 10)*10 ) + (itemPrice % 10);
        aa = hh;
        while ( (aa == hh) || (aa == gg) )
            aa = rand() % 100;
        bb = hh;
        while ( (bb == hh) || (bb == gg) || (bb == aa) )
            bb = rand() % 100;
        cc = hh;
        while ( (cc == hh) || (cc == gg) || (cc == aa) || (cc == bb) )
            cc = rand() % 100;
        dd = hh;
        while ( (dd == hh) || (dd == gg) || (dd == aa) || (dd == bb) || (dd == cc) )
            dd = rand() % 100;
        ee = hh;
        while ( (ee == hh) || (ee == gg) || (ee == aa) || (ee == bb) || (ee == cc) || (ee == dd) )
            ee = rand() % 100;
        ff = hh;
        while ( (ff == hh) || (ff == gg) || (ff == aa) || (ff == bb) || (ff == cc) || (ff == dd) || (ff == ee) )
            ff = rand() % 100;
    }

    bool stopped = false;
    int on = 0; // position of the board

    while (!stopped)
    {
        cout << endl << "  ####  ";
        if (on == 0){ // AAHH is in the frame
            cout << endl << "**" << ffSpace(aa) << ffSpace(hh) << "**";
            cout << endl << ffSpace(bb) << "####" << ffSpace(gg);
            cout << endl << ffSpace(cc) << "    " << ffSpace(ff);
            cout << endl << "**" << ffSpace(dd) << ffSpace(ee) << "**";
        }
        else if (on == 1){ // BBAA is in the frame
            cout << endl << "**" << ffSpace(bb) << ffSpace(aa) << "**";
            cout << endl << ffSpace(cc) << "####" << ffSpace(hh);
            cout << endl << ffSpace(dd) << "    " << ffSpace(gg);
            cout << endl << "**" << ffSpace(ee) << ffSpace(ff) << "**";
        }
        else if (on == 2){ // CCBB is in the frame
            cout << endl << "**" << ffSpace(cc) << ffSpace(bb) << "**";
            cout << endl << ffSpace(dd) << "####" << ffSpace(aa);
            cout << endl << ffSpace(ee) << "    " << ffSpace(hh);
            cout << endl << "**" << ffSpace(ff) << ffSpace(gg) << "**";
        }
        else if (on == 3){ // DDCC is in the frame
            cout << endl << "**" << ffSpace(dd) << ffSpace(cc) << "**";
            cout << endl << ffSpace(ee) << "####" << ffSpace(bb);
            cout << endl << ffSpace(ff) << "    " << ffSpace(aa);
            cout << endl << "**" << ffSpace(gg) << ffSpace(hh) << "**";
        }
        else if (on == 4){ // EEDD is in the frame
            cout << endl << "**" << ffSpace(ee) << ffSpace(dd) << "**";
            cout << endl << ffSpace(ff) << "####" << ffSpace(cc);
            cout << endl << ffSpace(gg) << "    " << ffSpace(bb);
            cout << endl << "**" << ffSpace(hh) << ffSpace(aa) << "**";
        }
        else if (on == 5){ // FFEE is in the frame
            cout << endl << "**" << ffSpace(ff) << ffSpace(ee) << "**";
            cout << endl << ffSpace(gg) << "####" << ffSpace(dd);
            cout << endl << ffSpace(hh) << "    " << ffSpace(cc);
            cout << endl << "**" << ffSpace(aa) << ffSpace(bb) << "**";
        }
        else if (on == 6){ // GGFF is in the frame
            cout << endl << "**" << ffSpace(gg) << ffSpace(ff) << "**";
            cout << endl << ffSpace(hh) << "####" << ffSpace(ee);
            cout << endl << ffSpace(aa) << "   " << ffSpace(dd);
            cout << endl << "**" << ffSpace(bb) << ffSpace(cc) << "**";
        }
        else // HHGG is in the frame
        {
            cout << endl << "**" << ffSpace(hh) << ffSpace(gg) << "**";
            cout << endl << ffSpace(aa) << "####" << ffSpace(ff);
            cout << endl << ffSpace(bb) << "    " << ffSpace(ee);
            cout << endl << "**" << ffSpace(cc) << ffSpace(dd) << "**";
        }

        char answer = 'A';
        while ( (answer != 'Y') && (answer != 'N') &&  (answer != 'y') && (answer != 'n') ){
        cout << endl << "Do you want to stop here (Y) or keep going (N)?: ";
        cin >> answer;
        }
        if ( (answer == 'Y') || (answer == 'y') )
            stopped = true;
        else
        {
            if (on == 7)
                on = 0;
            else
                on++;
        }

    } // end while loop

    cout << endl << "The actual retail price is $" << itemPrice;
    if (on == position)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Gallery Game
void playGalleryGame()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "GALLERY GAME" << endl;

    large gamePrize;
    int priceDigits[4];
    int id;
    int digitStyle;
    int missingDigit;

    bool setup = false;
    while (!setup){
    bool can = false;
    id = rand() % i;
    digitStyle = rand() % 4;
    missingDigit = rand() % 3;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < id; z++)
        gameItemIt++;
    priceDigits[0] = gameItemIt->getPrice() / 1000 % 10;
    priceDigits[1] = gameItemIt->getPrice() / 100 % 10;
    priceDigits[2] = gameItemIt->getPrice() / 10 % 10;
    priceDigits[3] = gameItemIt->getPrice() % 10;

    if (digitStyle == 0) // missing digit can either be a 3 or an 8
    {
    if (missingDigit == 0){
        if ( (priceDigits[0] == 3) || (priceDigits[0] == 8) )
            can = true;
    }
    else if (missingDigit == 1){
        if ( (priceDigits[1] == 3) || (priceDigits[1] == 8) )
            can = true;
    }
    else{
        if ( (priceDigits[2] == 3) || (priceDigits[2] == 8) )
            can = true;
    }
    } // end if digitStyle == 0

    else if (digitStyle == 1) // missing digit can either be 0, 2, 3, 6, 8, or 9
    {
    if (missingDigit == 0){
        if ( (priceDigits[0] == 0) || (priceDigits[0] == 2) || (priceDigits[0] == 3) || (priceDigits[0] == 6) || (priceDigits[0] == 8) || (priceDigits[0] == 9) )
            can = true;
    }
    else if (missingDigit == 1){
        if ( (priceDigits[1] == 0) || (priceDigits[1] == 2) || (priceDigits[1] == 3) || (priceDigits[1] == 6) || (priceDigits[1] == 8) || (priceDigits[1] == 9) )
            can = true;
    }
    else{
        if ( (priceDigits[2] == 0) || (priceDigits[2] == 2) || (priceDigits[2] == 3) || (priceDigits[2] == 6) || (priceDigits[2] == 8) || (priceDigits[2] == 9) )
            can = true;
    }
    } // end if digitStyle == 1

    else if (digitStyle == 2) // missing digit can be 3, 5, 6, or 8
    {
    if (missingDigit == 0){
        if ( (priceDigits[0] == 3) || (priceDigits[0] == 5) || (priceDigits[0] == 6) || (priceDigits[0] == 8) )
            can = true;
    }
    else if (missingDigit == 1){
        if ( (priceDigits[1] == 3) || (priceDigits[1] == 5) || (priceDigits[1] == 6) || (priceDigits[1] == 8) )
            can = true;
    }
    else{
        if ( (priceDigits[2] == 3) || (priceDigits[2] == 5) || (priceDigits[2] == 6) || (priceDigits[2] == 8) )
            can = true;
    }
    } // end if digitStyle == 2

    else // missing digit can be 0, 3, 5, 6, or 8
    {
    if (missingDigit == 0){
        if ( (priceDigits[0] == 0) || (priceDigits[0] == 3) || (priceDigits[0] == 5) || (priceDigits[0] == 6) || (priceDigits[0] == 8) )
            can = true;
    }
    else if (missingDigit == 1){
        if ( (priceDigits[1] == 0) || (priceDigits[1] == 3) || (priceDigits[1] == 5) || (priceDigits[1] == 6) || (priceDigits[1] == 8) )
            can = true;
    }
    else{
        if ( (priceDigits[2] == 0) || (priceDigits[2] == 3) || (priceDigits[2] == 5) || (priceDigits[2] == 6) || (priceDigits[2] == 8) )
            can = true;
    }
    } // end if digitStyle == 3

    if (can){
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());
    setup = true;
    }
    } // end while loop

    int correctDigit;

    gamePrize.showPrize();
    if (missingDigit == 0){
        cout << endl << "$*" << priceDigits[1] << priceDigits[2] << priceDigits[3];
        correctDigit = priceDigits[0];
        }
    else if (missingDigit == 1){
        cout << endl << "$" << priceDigits[0] << "*" << priceDigits[2] << priceDigits[3];
        correctDigit = priceDigits[1];
        }
    else{
        cout << endl << "$" << priceDigits[0] << priceDigits[1] << "*" << priceDigits[3];
        correctDigit = priceDigits[2];
        }

    int choice = 10;
    //cout << endl << "digitStyle = " << digitStyle;

    if (digitStyle == 0){
        cout << endl << "The missing digit could either be a 3 or an 8...";
        while ( (choice != 3) && (choice != 8) ){
            cout << endl << "What is the missing digit?: ";
                cin >> choice;
        }
    } // end if digitStyle == 0

    else if (digitStyle == 1){
        cout << endl << "The missing digit could be a 0, 2, 3, 6, 8, or 9...";
        while ( (choice != 0) && (choice != 2) && (choice != 3) && (choice != 6) && (choice != 8) && (choice != 9) ){
            cout << endl << "What is the missing digit?: ";
                cin >> choice;
        }
    } // end if digitStyle == 1

    else if (digitStyle == 2){
        cout << endl << "The missing digit could be a 3, 5, 6, or 8...";
        while ( (choice != 3) && (choice != 5) && (choice != 6) && (choice != 8) ){
            cout << endl << "What is the missing digit?: ";
                cin >> choice;
        }
    } // end if digitStyle == 2

    else{
        cout << endl << "The missing digit could be a 0, 3, 5, 6, or 8...";
        while ( (choice != 0) && (choice != 3) && (choice != 5) && (choice != 6) && (choice != 8) ){
            cout << endl << "What is the missing digit?: ";
                cin >> choice;
        }
    } // end if digitStyle == 3

    cout << endl << "The actual retail price is $" << gamePrize.getPrice();
    if (choice == correctDigit)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Jam
void playJam()
{
    /// Credit to tpirfan28 for making this game!
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (compatibleForFlipFlop(t_Price)) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "JAM" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    int itemPrice = gamePrize.getPrice();

    /// Select the digit to be "jammed" into the price. If 0, the first digit is removed, if 1, the second,
    /// and so on.
    int removedDigit = rand() % 4;

    /// Digits in the price.
    int digits[4];
    digits[0] = itemPrice / 1000 % 10;
    digits[1] = itemPrice / 100 % 10;
    digits[2] = itemPrice / 10 % 10;
    digits[3] = itemPrice % 10;

    //cout << endl << "possible items: " << i;

    gamePrize.showPrize();

    int sampleDigit;

    cout << endl;


    /// Show the game setup.
    if (removedDigit == 0){
        sampleDigit = digits[0];
        cout << endl << "A B C D";
        cout << endl << "*" << digits[1] << "*" << digits[2] << "*" << digits[3] << "*";
        cout << endl << "___" << digits[0] << "___";
    }
    else if (removedDigit == 1){
        sampleDigit = digits[1];
        cout << endl << "A B C D";
        cout << endl << "*" << digits[0] << "*" << digits[2] << "*" << digits[3] << "*";
        cout << endl << "___" << digits[1] << "___";
    }
    else if (removedDigit == 2){
        sampleDigit = digits[2];
        cout << endl << "A B C D";
        cout << endl << "*" << digits[0] << "*" << digits[1] << "*" << digits[3] << "*";
        cout << endl << "___" << digits[2] << "___";
    }
    else{
        sampleDigit = digits[3];
        cout << endl << "A B C D";
        cout << endl << "*" << digits[0] << "*" << digits[1] << "*" << digits[2] << "*";
        cout << endl << "___" << digits[3] << "___";
    }

    char choice = '!';
    while ( (choice != 'A') && (choice != 'a') && (choice != 'B') && (choice != 'b') &&
            (choice != 'C') && (choice != 'c') && (choice != 'D') && (choice != 'd') ){
        cout << endl << "Which space (A-D) does the " << sampleDigit << " go in?: ";
        cin >> choice;
    }

    int playerPrice;

    /// Player puts the digit on the far-left
    if ( (choice == 'A') || (choice == 'a') ){
    if (removedDigit == 0)
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    else if (removedDigit == 1)
        playerPrice = digits[1]*1000 + digits[0]*100 + digits[2]*10 + digits[3];
    else if (removedDigit == 2)
        playerPrice = digits[2]*1000 + digits[0]*100 + digits[1]*10 + digits[3];
    else
        playerPrice = digits[3]*1000 + digits[0]*100 + digits[1]*10 + digits[2];
    } // end if choice A

    /// Player puts the digit on the center-left
    else if ( (choice == 'B') || (choice == 'b') ){
    if (removedDigit == 0)
        playerPrice = digits[1]*1000 + digits[0]*100 + digits[2]*10 + digits[3];
    else if (removedDigit == 1)
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    else if (removedDigit == 2)
        playerPrice = digits[0]*1000 + digits[2]*100 + digits[1]*10 + digits[3];
    else
        playerPrice = digits[0]*1000 + digits[3]*100 + digits[1]*10 + digits[2];
    } // end if choice B

    /// Player puts the digit on the center-right
    else if ( (choice == 'C') || (choice == 'c') ){
    if (removedDigit == 0)
        playerPrice = digits[1]*1000 + digits[2]*100 + digits[0]*10 + digits[3];
    else if (removedDigit == 1)
        playerPrice = digits[0]*1000 + digits[2]*100 + digits[1]*10 + digits[3];
    else if (removedDigit == 2)
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    else
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[3]*10 + digits[2];
    } // end if choice C

    /// Player puts the digit on the far-right
    else{
    if (removedDigit == 0)
        playerPrice = digits[1]*1000 + digits[2]*100 + digits[3]*10 + digits[0];
    else if (removedDigit == 1)
        playerPrice = digits[0]*1000 + digits[2]*100 + digits[3]*10 + digits[1];
    else if (removedDigit == 2)
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[3]*10 + digits[2];
    else
        playerPrice = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    }

    cout << endl << "You've made the price $" << playerPrice;
    cout << endl << "The actual retail price is $" << itemPrice;

    if (playerPrice == itemPrice)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// One Way or Another
void playOneWayOrAnother()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (compatibleForOneWayOrAnother(t_Price)) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "ONE WAY OR ANOTHER" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int position = rand() % 2; /// if 0, the digit goes on the left. If 1, the digit goes on the right.

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();

    int digits[4];
    digits[0] = itemPrice / 1000 % 10;
    digits[1] = itemPrice / 100 % 10;
    digits[2] = itemPrice / 10 % 10;
    digits[3] = itemPrice % 10;

    cout << endl << endl;

    if (position == 0) /// the digit goes on the LEFT
    {
    cout << "**" << digits[0] << "**";
    cout << endl << "*" << digits[1] << digits[2] << digits[3] << "*";
    cout << endl << "1. LEFT - $" << itemPrice;
    cout << endl << "2. RIGHT - $" << digits[1] << digits[2] << digits[3] << digits[0];
    }
    else
    {
    cout << "**" << digits[3] << "**";
    cout << endl << "*" << digits[0] << digits[1] << digits[2] << "*";
    cout << endl << "1. LEFT - $" << digits[3] << digits[0] << digits[1] << digits[2];
    cout << endl << "2. RIGHT - $" << itemPrice;
    }

    int choice = 0;
    while ((choice < 1) || (choice > 2))
    {
        cout << endl << "Does the digit go on the left (1) or the right (2)?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price is $" << itemPrice;
    if (choice == position+1)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Pick-A-Number
void playPickANumber()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "PICK-A-NUMBER" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();
    int choices[3];
    int missing;

    if (itemPrice < 10000) /// 4-digit price
    {
        int val = rand() % 2; /// if 0, the thousandths place will be missing. if 1, the hundredths place will be missing.
        if (val == 0)
        {
            missing = itemPrice / 1000 % 10;
            choices[0] = itemPrice / 1000 % 10;
            choices[1] = (rand() % 7) + 2;
            while (choices[1] == choices[0])
                choices[1] = rand() % 10;
            choices[2] = (rand() % 7) + 2;
            while ( (choices[2] == choices[0]) || (choices[2] == choices[1]) )
                choices[2] = rand() % 10;

            cout << endl << "$_";
            cout << itemPrice / 100 % 10;
            cout << itemPrice / 10 % 10;
            cout << itemPrice % 10;
        }
        else
        {
            missing = itemPrice / 100 % 10;
            choices[0] = itemPrice / 100 % 10;
            choices[1] = rand() % 10;
            while (choices[1] == choices[0])
                choices[1] = rand() % 10;
            choices[2] = rand() % 10;
            while ( (choices[2] == choices[0]) || (choices[2] == choices[1]) )
                choices[2] = rand() % 10;
            cout << endl << "$";
            cout << itemPrice / 1000 % 10;
            cout << "_";
            cout << itemPrice / 10 % 10;
            cout << itemPrice % 10;
        }

    sortPickNumbers(choices);
    char entry = '!';
    int playerNumber;

    cout << endl << "A. " << choices[0];
    cout << endl << "B. " << choices[1];
    cout << endl << "C. " << choices[2];

    while ( (entry != 'A') && (entry != 'a') && (entry != 'B') && (entry != 'b') && (entry != 'C') && (entry != 'c') ){
        cout << endl << "What is the missing number?: ";
        cin >> entry;
    }
    if ( (entry == 'A') || (entry == 'a') )
        playerNumber = choices[0];
    else if ( (entry == 'B') || (entry == 'b') )
        playerNumber = choices[1];
    else
        playerNumber = choices[2];

    cout << endl << "The actual retail price is $" << itemPrice;
    if (playerNumber == missing)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    } /// end 4-digit price
    else
    {
    // not "necessary," will be implemented later
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Push-Over
void playPushOver()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( ( inFile >> t_Description >> t_ShortName >> t_Price ) && (t_Price < 10000) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "PUSH-OVER" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    cout << endl;
    int itemPrice = gamePrize.getPrice();

    /// Creates the player's price based on the blocks in the "window."
    int playerPrice = 0;

    int blocks[9];

    if (itemPrice < 10000) /// 4-digit price
    {
        int positionA = rand() % 5;
        if (positionA == 0)
        {
            blocks[0] = itemPrice / 1000 % 10;
            blocks[1] = itemPrice / 100 % 10;
            blocks[2] = itemPrice / 10 % 10;
            blocks[3] = itemPrice % 10;
            blocks[4] = rand() % 10;
            blocks[5] = rand() % 10;
            blocks[6] = rand() % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else if (positionA == 1)
        {
            blocks[0] = (rand() % 6) + 3;
            blocks[1] = itemPrice / 1000 % 10;
            blocks[2] = itemPrice / 100 % 10;
            blocks[3] = itemPrice / 10 % 10;
            blocks[4] = itemPrice % 10;
            blocks[5] = rand() % 10;
            blocks[6] = rand() % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else if (positionA == 2)
        {
            blocks[0] = (rand() % 6) + 3;
            blocks[1] = rand() % 10;
            blocks[2] = itemPrice / 1000 % 10;
            blocks[3] = itemPrice / 100 % 10;
            blocks[4] = itemPrice / 10 % 10;
            blocks[5] = itemPrice % 10;
            blocks[6] = rand() % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else if (positionA == 3)
        {
            blocks[0] = (rand() % 6) + 3;
            blocks[1] = rand() % 10;
            blocks[2] = rand() % 10;
            blocks[3] = itemPrice / 1000 % 10;
            blocks[4] = itemPrice / 100 % 10;
            blocks[5] = itemPrice / 10 % 10;
            blocks[6] = itemPrice % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else
        {
            blocks[0] = (rand() % 6) + 3;
            blocks[1] = rand() % 10;
            blocks[2] = rand() % 10;
            blocks[3] = rand() % 10;
            blocks[4] = itemPrice / 1000 % 10;
            blocks[5] = itemPrice / 100 % 10;
            blocks[6] = itemPrice / 10 % 10;
            blocks[7] = itemPrice % 10;
            blocks[8] = rand() % 10;
        }

    int blocksPushed = 0;
    bool stopped = false;

    while ( (!stopped) && (blocksPushed < 5) ){
    char choice = 'A';
    //cout << endl << "blocks pushed = " << blocksPushed;
    cout << endl;
    for (int y = 0; y < blocksPushed; y++)
        cout << " ";
    for (int x = 0; x < (9-blocksPushed); x++)
        cout << blocks[x];
    cout << endl << "     ####|_|";
    while ( (choice != 'Y') && (choice != 'N') &&  (choice != 'y') && (choice != 'n') )
    {
        cout << endl << "Do you want to push the blocks (Y) or stop now (N)?: ";
        cin >> choice;
    }
    if ((choice == 'Y') || (choice == 'y'))
    {
        /// push blocks
        blocksPushed += 1;
    }
    else
        stopped = true;
    } /// end while loop

    if (blocksPushed == 0)
        playerPrice = blocks[5]*1000 + blocks[6]*100 + blocks[7]*10 + blocks[8];
    else if (blocksPushed == 1)
        playerPrice = blocks[4]*1000 + blocks[5]*100 + blocks[6]*10 + blocks[7];
    else if (blocksPushed == 2)
        playerPrice = blocks[3]*1000 + blocks[4]*100 + blocks[5]*10 + blocks[6];
    else if (blocksPushed == 3)
        playerPrice = blocks[2]*1000 + blocks[3]*100 + blocks[4]*10 + blocks[5];
    else if (blocksPushed == 4)
        playerPrice = blocks[1]*1000 + blocks[2]*100 + blocks[3]*10 + blocks[4];
    else
        playerPrice = blocks[0]*1000 + blocks[1]*100 + blocks[2]*10 + blocks[3];
    } // end 4-digit prize

    else /// 5-digit price
    {
        int positionB = rand() % 4;
        if (positionB == 0)
        {
            blocks[0] = itemPrice / 10000 % 10;
            blocks[1] = itemPrice / 1000 % 10;
            blocks[2] = itemPrice / 100 % 10;
            blocks[3] = itemPrice / 10 % 10;
            blocks[4] = itemPrice % 10;
            blocks[5] = rand() % 10;
            blocks[6] = rand() % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else if (positionB == 1)
        {
            blocks[0] = rand() % 10;
            blocks[1] = itemPrice / 10000 % 10;
            blocks[2] = itemPrice / 1000 % 10;
            blocks[3] = itemPrice / 100 % 10;
            blocks[4] = itemPrice / 10 % 10;
            blocks[5] = itemPrice % 10;
            blocks[6] = rand() % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else if (positionB == 2)
        {
            blocks[0] = rand() % 10;
            blocks[1] = rand() % 10;
            blocks[2] = itemPrice / 10000 % 10;
            blocks[3] = itemPrice / 1000 % 10;
            blocks[4] = itemPrice / 100 % 10;
            blocks[5] = itemPrice / 10 % 10;
            blocks[6] = itemPrice % 10;
            blocks[7] = rand() % 10;
            blocks[8] = rand() % 10;
        }
        else
        {
            blocks[0] = rand() % 10;
            blocks[1] = rand() % 10;
            blocks[2] = rand() % 10;
            blocks[3] = itemPrice / 10000 % 10;
            blocks[4] = itemPrice / 1000 % 10;
            blocks[5] = itemPrice / 100 % 10;
            blocks[6] = itemPrice / 10 % 10;
            blocks[7] = itemPrice % 10;
            blocks[8] = rand() % 10;
        }
        int blocksPushedB = 0;
        bool stoppedB = false;

        while ( (!stoppedB) && (blocksPushedB < 4) ){
        char choiceB = 'A';

        cout << endl;
        for (int y = 0; y < blocksPushedB; y++)
            cout << " ";
        for (int x = 0; x < (9-blocksPushedB); x++)
            cout << blocks[x];
        cout << endl << "     ####|_|";
        while ( (choiceB != 'Y') && (choiceB != 'N') &&  (choiceB != 'y') && (choiceB != 'n') )
        {
            cout << endl << "Do you want to push the blocks (Y) or stop now (N)?: ";
            cin >> choiceB;
        }
        if ((choiceB == 'Y') || (choiceB == 'y'))
        {
            /// push blocks
            blocksPushedB += 1;
        }
        else
            stoppedB = true;
        } /// end while loop

    if (blocksPushedB == 0)
        playerPrice = blocks[4]*10000 + blocks[5]*1000 + blocks[6]*100 + blocks[7]*10 + blocks[8];
    else if (blocksPushedB == 1)
        playerPrice = blocks[3]*10000 + blocks[4]*1000 + blocks[5]*100 + blocks[6]*10 + blocks[7];
    else if (blocksPushedB == 2)
        playerPrice = blocks[2]*10000 + blocks[3]*1000 + blocks[4]*100 + blocks[5]*10 + blocks[6];
    else if (blocksPushedB == 3)
        playerPrice = blocks[1]*10000 + blocks[2]*1000 + blocks[3]*100 + blocks[4]*10 + blocks[5];
    else
        playerPrice = blocks[0]*10000 + blocks[1]*1000 + blocks[2]*100 + blocks[3]*10 + blocks[4];

    } // end 5-digit prize

    cout << endl << "You've set the price to $" << playerPrice;
    cout << endl << "The actual retail price is $" << itemPrice;

    if (playerPrice == itemPrice)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Range Game
void playRangeGame()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( inFile >> t_Description >> t_ShortName >> t_Price )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "RANGE GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int rangeStart = rand() % 6;
    int bound = 0;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();

    /*
    cout << endl;
    cout << "price = $" << itemPrice << endl;
    cout << "bound = $" << itemPrice - (itemPrice % 100) << endl;
    */

    if (rangeStart == 5)
        bound = itemPrice - (itemPrice % 100);
    else if (rangeStart == 4)
        bound = (itemPrice - (itemPrice % 100)) - 100;
    else if (rangeStart == 3)
        bound = (itemPrice - (itemPrice % 100)) - 200;
    else if (rangeStart == 2)
        bound = (itemPrice - (itemPrice % 100)) - 300;
    else if (rangeStart == 1)
        bound = (itemPrice - (itemPrice % 100)) - 400;
    else
        bound = (itemPrice - (itemPrice % 100)) - 500;

    cout << endl << "Range: $" << bound << "-" << bound+600;

    int start = 0;
    int finish = 0;

    while ( (start < bound) || ( start > (bound+600) ) ){
    cout << endl << "Enter the starting point for the $150 range that contains the price: $";
    cin >> start;
    }

    finish = start+150;

    if (start > bound+450){
        finish = bound+600;
        start = finish - 150;
        }
    cout << endl << "Is the price between $" << start << " and $" << finish << "?" << endl;
    system("pause");
    cout << endl << "The actual retail price of the prize is $" << itemPrice;
    if ( (itemPrice >= start) && (itemPrice <= finish) )
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Side By Side
void playSideBySide()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (compatibleForSBS(t_Price)) )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "SIDE BY SIDE" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;
    int position = rand() % 2; /// if 0, the digits go on the left. If 1, the digits go on the right.

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    int itemPrice = gamePrize.getPrice();

    int digits[4];
    digits[0] = itemPrice / 1000 % 10;
    digits[1] = itemPrice / 100 % 10;
    digits[2] = itemPrice / 10 % 10;
    digits[3] = itemPrice % 10;

    cout << endl;
    if (position == 0) /// the digits go on the LEFT
    {
    cout << "*" << digits[0] << digits[1] << "*" << endl;
    cout << "*" << digits[2] << digits[3] << "*" << endl;
    cout << "1. LEFT - $" << itemPrice << endl;
    cout << "2. RIGHT - $" << digits[2] << digits[3] << digits[0] << digits[1] << endl;
    }
    else /// the digits go on the RIGHT
    {
    cout << "*" << digits[2] << digits[3] << "*" << endl;
    cout << "*" << digits[0] << digits[1] << "*" << endl;
    cout << "1. LEFT - $" << digits[2] << digits[3] << digits[0] << digits[1] << endl;
    cout << "2. RIGHT - $" << itemPrice << endl;
    }

    int choice = 0;
    while ((choice < 1) || (choice > 2))
    {
        cout << endl << "On which side (enter the number) do the digits go?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price is $" << itemPrice;
    if (choice == position+1)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Squeeze Play
void playSqueezePlay()
{
    list<large> gameItems;
    list<large>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    large * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/large.txt");
    while (inFile)
    {
        pptr = new large;
        if ( inFile >> t_Description >> t_ShortName >> t_Price )
        {
            pptr->setDescription(t_Description);
            pptr->setShortName(t_ShortName);
            pptr->setPrice(t_Price);
            gameItems.push_back(*pptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "SQUEEZE PLAY" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    large gamePrize;

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomPrize; z++)
        gameItemIt++;
    gamePrize.setDescription(gameItemIt->getDescription());
    gamePrize.setShortName(gameItemIt->getShortName());
    gamePrize.setPrice(gameItemIt->getPrice());

    gamePrize.showPrize();
    cout << endl;
    int itemPrice = gamePrize.getPrice();

    /// This makes sure the player still wins if there are duplicates and they eliminate the "wrong" number.
    int playerPrice = 0;

    if (itemPrice < 10000) /// 4-digit price
    {
        int displayA[5];
        displayA[0] = itemPrice / 1000 % 10;
        displayA[4] = itemPrice % 10;
        int extraDigitA = rand() % 10;
        int extraDigitSpaceA = rand() % 3;
        if (extraDigitSpaceA == 0)
        {
            displayA[1] = extraDigitA;
            displayA[2] = itemPrice / 100 % 10;
            displayA[3] = itemPrice / 10 % 10;
        }
        else if (extraDigitSpaceA == 1)
        {
            displayA[1] = itemPrice / 100 % 10;
            displayA[2] = extraDigitA;
            displayA[3] = itemPrice / 10 % 10;
        }
        else
        {
            displayA[1] = itemPrice / 100 % 10;
            displayA[2] = itemPrice / 10 % 10;
            displayA[3] = extraDigitA;
        }

        cout << endl << "$";
        for (int x = 0; x < 5; x++)
            cout << displayA[x];
        cout << endl << "$-ABC-";

        char choiceA = '!';

        cout << endl << "Which middle digit do you want to eliminate?: ";
        cin >> choiceA;
        switch (choiceA)
        {
        case 'A': /// eliminating display[1]
            playerPrice = (displayA[0]*1000 + displayA[2]*100 + displayA[3]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[1];
            cout << " and made the price $" << playerPrice;
            break;

        case 'a': /// eliminating display[1]
            playerPrice = (displayA[0]*1000 + displayA[2]*100 + displayA[3]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[1];
            cout << " and made the price $" << playerPrice;
            break;

        case 'B': /// eliminating display[2]
            playerPrice = (displayA[0]*1000 + displayA[1]*100 + displayA[3]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[2];
            cout << " and made the price $" << playerPrice;
            break;

        case 'b': /// eliminating display[2]
            playerPrice = (displayA[0]*1000 + displayA[1]*100 + displayA[3]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[2];
            cout << " and made the price $" << playerPrice;
            break;

        case 'C': /// eliminating display[3]
            playerPrice = (displayA[0]*1000 + displayA[1]*100 + displayA[2]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[3];
            cout << " and made the price $" << playerPrice;
            break;

        case 'c': /// eliminating display[3]
            playerPrice = (displayA[0]*1000 + displayA[1]*100 + displayA[2]*10 + displayA[4]);
            cout << endl << "You've eliminated the " << displayA[3];
            cout << " and made the price $" << playerPrice;
            break;

        default:
            cout << endl << "That won't work. Try again." << endl;

        } /// end switch statement


    } // end 4-digit price
    else /// 5-digit price
    {
        int displayB[6];
        displayB[0] = itemPrice / 10000 % 10;
        displayB[5] = itemPrice % 10;
        int extraDigitB = rand() % 10;
        int extraDigitSpaceB = rand() % 4;
        if (extraDigitSpaceB == 0)
        {
            displayB[1] = extraDigitB;
            displayB[2] = itemPrice / 1000 % 10;
            displayB[3] = itemPrice / 100 % 10;
            displayB[4] = itemPrice / 10 % 10;
        }
        else if (extraDigitSpaceB == 1)
        {
            displayB[1] = itemPrice / 1000 % 10;
            displayB[2] = extraDigitB;
            displayB[3] = itemPrice / 100 % 10;
            displayB[4] = itemPrice / 10 % 10;
        }
        else if (extraDigitSpaceB == 2)
        {
            displayB[1] = itemPrice / 1000 % 10;
            displayB[2] = itemPrice / 100 % 10;
            displayB[3] = extraDigitB;
            displayB[4] = itemPrice / 10 % 10;
        }
        else
        {
            displayB[1] = itemPrice / 1000 % 10;
            displayB[2] = itemPrice / 100 % 10;
            displayB[3] = itemPrice / 10 % 10;
            displayB[4] = extraDigitB;
        }

        cout << endl << "$";
        for (int y = 0; y < 6; y++)
            cout << displayB[y];
        cout << endl << "$-ABCD-";

        char choiceB = '!';

        cout << endl << "Which middle digit do you want to eliminate?: ";
        cin >> choiceB;
        switch (choiceB)
        {
        case 'A': /// eliminating display[1]
            playerPrice = (displayB[0]*10000 + displayB[2]*1000 + displayB[3]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[1];
            cout << " and made the price $" << playerPrice;
            break;

        case 'a': /// eliminating display[1]
            playerPrice = (displayB[0]*10000 + displayB[2]*1000 + displayB[3]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[1];
            cout << " and made the price $" << playerPrice;
            break;

        case 'B': /// eliminating display[2]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[3]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[2];
            cout << " and made the price $" << playerPrice;
            break;

        case 'b': /// eliminating display[2]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[3]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[2];
            cout << " and made the price $" << playerPrice;
            break;

        case 'C': /// eliminating display[3]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[2]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[3];
            cout << " and made the price $" << playerPrice;
            break;

        case 'c': /// eliminating display[3]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[2]*100 + displayB[4]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[3];
            cout << " and made the price $" << playerPrice;
            break;

        case 'D': /// eliminating display[4]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[2]*100 + displayB[3]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[4];
            cout << " and made the price $" << playerPrice;
            break;

        case 'd': /// eliminating display[4]
            playerPrice = (displayB[0]*10000 + displayB[1]*1000 + displayB[2]*100 + displayB[3]*10 + displayB[5]);
            cout << endl << "You've eliminated the " << displayB[4];
            cout << " and made the price $" << playerPrice;
            break;

        default:
            cout << endl << "That won't work. Try again." << endl;
        } /// end switch statement

    } // end 5-digit price

    cout << endl << "The actual retail price is $" << itemPrice;

    if (playerPrice == itemPrice)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

#endif // SINGLEPRIZE_H_INCLUDED
