/// This header file used to contain all the games, but will now be used to
/// store grocery games.

#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

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

/// Converts a given random number to a grocery item's price, using the formula 0.5p + 0.5.
/// Used in Penny Ante and To The Penny.
double toRandomPrice(int p)
{
    double result;
    result = 0.5*(p) + 0.5;
    if ( floor(result) == result)
        result -= 0.01;

    return result;
}

/// Checks if a grocery item's price can be multiplied by an integer so that the total falls between $10 and $12.
bool compatibleForBullseye(double price)
{
    if (price > 12)
        return false;
    else if ( (price > 4) && (price < 5) )
        return false;
    else if ( (price > 6) && (price < 10) )
        return false;
    else if ( (price > 3) && (price < 3.34) )
        return false;
    else if ( (price > 2.40) && (price < 2.50) )
        return false;
    else
        return true;

}

/// Bullseye (1976)
void playBullseye()
{
    list<grocery> bullsItems;
    list<grocery>::iterator bullsItemIt;

    string t_bullsDescription;
    string t_bullsShortName;
    double t_bullsPrice;

    grocery * bullsptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    bullsptr = new grocery;
    if ((inFile >> t_bullsDescription >> t_bullsShortName >> t_bullsPrice) && (compatibleForBullseye(t_bullsPrice)) )
    {
        bullsptr->setDescription(t_bullsDescription);
        bullsptr->setShortName(t_bullsShortName);
        bullsptr->setPrice(t_bullsPrice);
        bullsItems.push_back(*bullsptr);
        i++;
    }
    } // end while loop

    cout << "BULLSEYE" << endl;

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
    grocery items[5];
    bool picked[5];
    bool hasMarking[5];
    int picks = 0;
    bool won = false;
    int hiddenBullseye = (rand() % 5 + 1);

    /// Set each item
    for (int grocCount = 0; grocCount < 5; grocCount++)
    {
        bullsItemIt = bullsItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            bullsItemIt++;
        }

        items[grocCount].setDescription(bullsItemIt->getDescription());
        items[grocCount].setShortName(bullsItemIt->getShortName());
        items[grocCount].setPrice(bullsItemIt->getPrice());
        picked[grocCount] = false;
        hasMarking[grocCount] = false;
    }

    /// The line below was used for debugging purposes only and is now commented out.
    //cout << "Hidden bullseye is behind #" << hiddenBullseye;

    do
    {
        cout << endl;
        cout << "Picks remaining: " << 3-picks << endl;
        for (int show = 0; show < 5; show++){
        cout << show+1 << ". ";
        items[show].showPrize();
        if (picked[show] == true && hasMarking[show] == true)
            cout << " O ";
        if (picked[show] == true && hasMarking[show] == false)
            cout << " X ";
        cout << endl;
        }
        int playerChoice = 0;
        int toBuy = 0;
        double itemTotal = 0;
        cout << endl << "Which item (enter its number) would you like to pick?: ";
        cin >> playerChoice;
        switch (playerChoice)
        {
        case 1:
            /// check if the player has already picked this item
            if (picked[0] == false)
            {
                cout << endl << "You picked the ";
                items[0].showShortName();
                cout << endl << "How many do you want?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[0].showARP();
                itemTotal = items[0].getPrice() * toBuy;
                cout << endl << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                if (itemTotal >= 10 && itemTotal <= 12) // on the bullseye
                {
                    won = true;
                }
                else if (itemTotal >= 2 && itemTotal < 10) // on the target, but not the bullseye
                {
                    cout << endl << "You didn't hit the bullseye, but you do get a mark for this item.";
                    picked[0] = true;
                    hasMarking[0] = true;
                    picks += 1;
                }
                else // not on the target at all
                {
                    cout << endl << "You completely missed the target. You don't get a mark for this item.";
                    picked[0] = true;
                    picks += 1;
                }
            }
            else
                cout << endl << "You've already picked this item. Please pick another.";
            break;

        case 2:
            /// check if the player has already picked this item
            if (picked[1] == false)
            {
                cout << endl << "You picked the ";
                items[1].showShortName();
                cout << endl << "How many do you want?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[1].showARP();
                itemTotal = items[1].getPrice() * toBuy;
                cout << endl << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                if (itemTotal >= 10 && itemTotal <= 12) // on the bullseye
                {
                    won = true;
                }
                else if (itemTotal >= 2 && itemTotal < 10) // on the target, but not the bullseye
                {
                    cout << endl << "You didn't hit the bullseye, but you do get a mark for this item.";
                    picked[1] = true;
                    hasMarking[1] = true;
                    picks += 1;
                }
                else // not on the target at all
                {
                    cout << endl << "You completely missed the target. You don't get a mark for this item.";
                    picked[1] = true;
                    picks += 1;
                }
            }
            else
                cout << endl << "You've already picked this item. Please pick another.";
            break;


        case 3:
            /// check if the player has already picked this item
            if (picked[2] == false)
            {
                cout << endl << "You picked the ";
                items[2].showShortName();
                cout << endl << "How many do you want?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[2].showARP();
                itemTotal = items[2].getPrice() * toBuy;
                cout << endl << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                if (itemTotal >= 10 && itemTotal <= 12) // on the bullseye
                {
                    won = true;
                }
                else if (itemTotal >= 2 && itemTotal < 10) // on the target, but not the bullseye
                {
                    cout << endl << "You didn't hit the bullseye, but you do get a mark for this item.";
                    picked[2] = true;
                    hasMarking[2] = true;
                    picks += 1;
                }
                else // not on the target at all
                {
                    cout << endl << "You completely missed the target. You don't get a mark for this item.";
                    picked[2] = true;
                    picks += 1;
                }
            }
            else
                cout << endl << "You've already picked this item. Please pick another.";
            break;

        case 4:
            /// check if the player has already picked this item
            if (picked[3] == false)
            {
                cout << endl << "You picked the ";
                items[3].showShortName();
                cout << endl << "How many do you want?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[3].showARP();
                itemTotal = items[3].getPrice() * toBuy;
                cout << endl << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                if (itemTotal >= 10 && itemTotal <= 12) // on the bullseye
                {
                    won = true;
                }
                else if (itemTotal >= 2 && itemTotal < 10) // on the target, but not the bullseye
                {
                    cout << endl << "You didn't hit the bullseye, but you do get a mark for this item.";
                    picked[3] = true;
                    hasMarking[3] = true;
                    picks += 1;
                }
                else // not on the target at all
                {
                    cout << endl << "You completely missed the target. You don't get a mark for this item.";
                    picked[3] = true;
                    picks += 1;
                }
            }
            else
                cout << endl << "You've already picked this item. Please pick another.";
            break;


        case 5:
            /// check if the player has already picked this item
            if (picked[4] == false)
            {
                cout << endl << "You picked the ";
                items[4].showShortName();
                cout << endl << "How many do you want?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[4].showARP();
                itemTotal = items[4].getPrice() * toBuy;
                cout << endl << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                if (itemTotal >= 10 && itemTotal <= 12) // on the bullseye
                {
                    won = true;
                }
                else if (itemTotal >= 2 && itemTotal < 10) // on the target, but not the bullseye
                {
                    cout << endl << "You didn't hit the bullseye, but you do get a mark for this item.";
                    picked[4] = true;
                    hasMarking[4] = true;
                    picks += 1;
                }
                else // not on the target at all
                {
                    cout << endl << "You completely missed the target. You don't get a mark for this item.";
                    picked[4] = true;
                    picks += 1;
                }
            }
            else
                cout << endl << "You've already picked this item. Please pick another.";
            break;


        default:
            cout << endl << "That won't work. Try again.";

        } // end switch statement
    }
    while (picks < 3 && !won);

    cout << endl;

    /// Win conditions
    if (won)
    {
        cout << "You hit the bullseye! You win!" << endl;
    }
    else
    {
        cout << "You didn't hit the bullseye, but let's see if you \nfound the hidden bullseye." << endl;
        for (int findBullseye = 0; findBullseye < 5; findBullseye++)
        {
            if ((hasMarking[findBullseye]) && (!won))
            {
                cout << "Let's look behind the ";
                items[findBullseye].showShortName();
                cout << endl;
                system("pause");
                cout << endl;
                if ((hiddenBullseye - 1) == findBullseye)
                    won = true;
                else
                    cout << "Sorry, it's not behind this item." << endl;
            }
        }
        if (won)
            cout << endl << "You found the hidden bullseye! You win!" << endl;
        else
            cout << endl << "Sorry, you lose." << endl;
    } // end else statement

    cout << endl;

    inFile.close();
    system("pause");
    system("CLS");

}

/// Check-Out
void playCheckOut()
{
    list<grocery> coItems;
    list<grocery>::iterator coItemIt;

    string t_coDescription;
    string t_coShortName;
    double t_coPrice;

    grocery * coptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    coptr = new grocery;
    if (inFile >> t_coDescription >> t_coShortName >> t_coPrice)
    {
        coptr->setDescription(t_coDescription);
        coptr->setShortName(t_coShortName);
        coptr->setPrice(t_coPrice);
        coItems.push_back(*coptr);
        i++;
    }

    } // end while loop

    cout << "CHECK-OUT" << endl;

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


    grocery prize1;
    grocery prize2;
    grocery prize3;
    grocery prize4;
    grocery prize5;

    double cost1 = 0;
    double cost2 = 0;
    double cost3 = 0;
    double cost4 = 0;
    double cost5 = 0;

    double total;
    double realTotal;
    double difference;

    int z = 0;

    /// Set prize 1

    coItemIt = coItems.begin();
    for (z = 0; z < randomizationField[0]; z++)
    {
        coItemIt++;
    }

    prize1.setDescription(coItemIt->getDescription());
    prize1.setShortName(coItemIt->getShortName());
    prize1.setPrice(coItemIt->getPrice());
    /*
    cout << endl;
    prize1.showPrize();
    */

    /// Set prize 2

    coItemIt = coItems.begin();
    for (z = 0; z < randomizationField[1]; z++)
    {
        coItemIt++;
    }

    prize2.setDescription(coItemIt->getDescription());
    prize2.setShortName(coItemIt->getShortName());
    prize2.setPrice(coItemIt->getPrice());
    /*
    cout << endl;
    prize2.showPrize();
    */

    /// Set prize 3

    coItemIt = coItems.begin();
    for (z = 0; z < randomizationField[2]; z++)
    {
        coItemIt++;
    }

    prize3.setDescription(coItemIt->getDescription());
    prize3.setShortName(coItemIt->getShortName());
    prize3.setPrice(coItemIt->getPrice());
    /*
    cout << endl;
    prize3.showPrize();
    */

    /// Set prize 4

    coItemIt = coItems.begin();
    for (z = 0; z < randomizationField[3]; z++)
    {
        coItemIt++;
    }

    prize4.setDescription(coItemIt->getDescription());
    prize4.setShortName(coItemIt->getShortName());
    prize4.setPrice(coItemIt->getPrice());
    /*
    cout << endl;
    prize4.showPrize();
    */

    /// Set prize 5

    coItemIt = coItems.begin();
    for (z = 0; z < randomizationField[4]; z++)
    {
        coItemIt++;
    }

    prize5.setDescription(coItemIt->getDescription());
    prize5.setShortName(coItemIt->getShortName());
    prize5.setPrice(coItemIt->getPrice());
    /*
    cout << endl;
    prize5.showPrize();
    */


/// --- ///



    /// Start the game itself

    cout << endl;

    cout << "1. ";
    prize1.showPrize();
    while (cost1 <= 0){
    cout << endl << "$";
    cin >> cost1;}

    cout << "2. ";
    prize2.showPrize();
    while (cost2 <= 0){
    cout << endl << "$";
    cin >> cost2;}

    cout << "3. ";
    prize3.showPrize();
    while (cost3 <= 0){
    cout << endl << "$";
    cin >> cost3;}

    cout << "4. ";
    prize4.showPrize();
    while (cost4 <= 0){
    cout << endl << "$";
    cin >> cost4;}

    cout << "5. ";
    prize5.showPrize();
    while (cost5 <= 0){
    cout << endl << "$";
    cin >> cost5;}

    total = cost1 + cost2 + cost3 + cost4 + cost5;

    cout << fixed << endl << "Your total: $" << setprecision(2) << total;
    cout << endl << "Now, let's reveal the actual prices of the items..." << endl;

    cout << endl << "The actual retail price of the ";
    prize1.showShortName();
    cout << endl << "is ";
    prize1.showARP();

    cout << endl;
    system("pause");

    /// --- ///

    cout << endl << "The actual retail price of the ";
    prize2.showShortName();
    cout << endl << "is ";
    prize2.showARP();

    cout << endl;
    system("pause");

    /// --- ///

    cout << endl << "The actual retail price of the ";
    prize3.showShortName();
    cout << endl << "is ";
    prize3.showARP();

    cout << endl;
    system("pause");

    /// --- ///

    cout << endl << "The actual retail price of the ";
    prize4.showShortName();
    cout << endl << "is ";
    prize4.showARP();

    cout << endl;
    system("pause");

    /// --- ///

    cout << endl << "The actual retail price of the ";
    prize5.showShortName();
    cout << endl << "is ";
    prize5.showARP();

    cout << endl;
    system("pause");

    realTotal = prize1.getPrice() + prize2.getPrice() + prize3.getPrice() + prize4.getPrice() + prize5.getPrice();
    cout << fixed << "The total of the ARPs is $" << setprecision(2) << realTotal;
    cout << endl;

    difference = abs(realTotal - total);
    cout << fixed << "For a difference of $" << setprecision(2) << difference;

    cout << endl;

    if (difference <= 2)
        cout << "Congratulations, you win!" << endl;
    else
        cout << "Sorry, you lose." << endl;

    cout << endl;

    inFile.close();
    system("pause");
    system("CLS");
}

/// Grand Game
void playGrandGame()
{
    /// Items below the target price.
    list<grocery> ggItems;
    list<grocery>::iterator ggItemsIt;

    /// Items above the target price.
    list<grocery> highItems;
    list<grocery>::iterator highItemsIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;

    /// Generate the target price. The way this works is that it generates an integer between 450 and 900, and then
    /// converts it into a double, and then divides the double by 100, thereby creating a target price between
    /// $4.50 and $9.00.
    int test = (rand() % (901 - 450) + 450);
    double targetPrice = static_cast<double>(test);
    targetPrice /= 100;

    int below = 0; /// Items below the target price.
    int above = 0; /// Items above the target price.

    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice)
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        if ((t_ggPrice <= targetPrice)){
            ggItems.push_back(*ggptr);
            below++;
        }
        else if (t_ggPrice-targetPrice <= 2.5){
            highItems.push_back(*ggptr);
            above++;
        }
        i++;
    }
    } // end while loop
    inFile.close();

    /// These numbers represent the prizes. 4 and 5 represent the two items above the target price.
    int numbers[6] = {0, 1, 2, 3, 4, 5};
    random_shuffle(&numbers[0], &numbers[6]);

    cout << "GRAND GAME" << endl;

    /// Generate two randomization fields, one for each grouping of groceries.
    int loRandomizationField[below];
    /// Initialize the randomization field.
    for (int j = 0; j < below; j++)
    {
        loRandomizationField[j] = j;
    }
    random_shuffle(&loRandomizationField[0], &loRandomizationField[below]);

    /// Generate two randomization fields, one for each grouping of groceries.
    int hiRandomizationField[above];
    /// Initialize the randomization field.
    for (int k = 0; k < above; k++)
    {
        hiRandomizationField[k] = k;
    }
    random_shuffle(&hiRandomizationField[0], &hiRandomizationField[above]);

    int z = 0;
    grocery items[6];

    bool itemChosen[6];
    for (int b = 0; b < 6; b++)
        itemChosen[b] = false;


    /// Initialize all the grocery items.
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        ggItemsIt = ggItems.begin();
        for (z = 0; z < loRandomizationField[itemCount]; z++)
        {
            ggItemsIt++;
        }

        items[itemCount].setDescription(ggItemsIt->getDescription());
        items[itemCount].setShortName(ggItemsIt->getShortName());
        items[itemCount].setPrice(ggItemsIt->getPrice());
    }


    for (int secCount = 4; secCount < 6; secCount++)
    {
     highItemsIt = highItems.begin();
     for (z = 0; z < hiRandomizationField[secCount]; z++)
     {
         highItemsIt++;
     }
        items[secCount].setDescription(highItemsIt->getDescription());
        items[secCount].setShortName(highItemsIt->getShortName());
        items[secCount].setPrice(highItemsIt->getPrice());
    }


    int picks = 0;
    int money = 1;

    bool won = false;
    bool lost = false;
    bool bail = false;
    bool madeChoice = false;

    while ( (!won) && (!lost) && (!bail) ){
    char bailChoice = 'b';
    int playerChoice = 0;
    cout << endl << "Money: $" << money << endl;
    cout << fixed << "Target price: $" << setprecision(2) << targetPrice << endl;
        for (int d = 0; d < 6; d++){
        cout << d+1 << ". ";
        items[numbers[d]].showPrize();
        if (itemChosen[numbers[d]])
        {
            cout << " - ";
            items[numbers[d]].showARP();
        }
        cout << endl;
    }
    cout << endl << "Which item would you like to pick?: ";
    cin >> playerChoice;
    switch (playerChoice){

    case 1:
        if (itemChosen[numbers[0]] == false)
        {
            itemChosen[numbers[0]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[0]].showARP();
            if (items[numbers[0]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 2:
        if (itemChosen[numbers[1]] == false)
        {
            itemChosen[numbers[1]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[1]].showARP();
            if (items[numbers[1]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 3:
        if (itemChosen[numbers[2]] == false)
        {
            itemChosen[numbers[2]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[2]].showARP();
            if (items[numbers[2]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;


    case 4:
        if (itemChosen[numbers[3]] == false)
        {
            itemChosen[numbers[3]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[3]].showARP();
            if (items[numbers[3]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 5:
        if (itemChosen[numbers[4]] == false)
        {
            itemChosen[numbers[4]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[4]].showARP();
            if (items[numbers[4]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 6:
        if (itemChosen[numbers[5]] == false)
        {
            itemChosen[numbers[5]] = true;
            cout << endl << "The actual retail price is ";
            items[numbers[5]].showARP();
            if (items[numbers[5]].getPrice() >= targetPrice)
                lost = true;
            else
            {
            money *= 10;
            if (money >= 10000)
                won = true;
            } // end else statement

        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    default:
        cout << endl << "That won't work. Try again.";
    } // end switch statement

    if ((money == 1000) && (!lost) && (!won) && (!madeChoice) )
    {
        while ( (bailChoice != 'Y') && (bailChoice != 'N') &&  (bailChoice != 'y') && (bailChoice != 'n') )
        {
        cout << endl << "You have $1000 now. \nDo you want to keep going (Y) or quit with $1000 (N)?: ";
        cin >> bailChoice;
        }
        madeChoice = true;
        if ((bailChoice == 'N') || (bailChoice == 'n'))
            bail = true;
    }

} // end while loop

    if (won)
    {
        cout << endl << "Money: $" << money;
        cout << endl << "Congratulations, you win!";
    }
    else if (bail)
        cout << endl << "You're walking away with $1000. Thanks for playing!";
    else if (lost)
    {
        if (money == 1000)
            cout << endl << "Sorry, you lose.";
        else
            cout << endl << "Sorry, you lose. At least you won $" << money << ".";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Grocery Game
void playGroceryGame()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice <= 22) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop

    cout << "GROCERY GAME" << endl;

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
    grocery items[5];
    bool picked[5];
    bool boughtFive = false;
    bool won = false;

    /// Set each item, this time using a for loop:
    for (int grocCount = 0; grocCount < 5; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
        picked[grocCount] = false;
    }

    double runningTotal = 0;

    /*
    cout << "Here are the grocery items today:" << endl;
    for (int disp = 0; disp < 5; disp++){
        items[disp].showPrize();
        cout << endl;
    }

    cout << endl;
    */

    do{
        cout << endl;
        cout << "Running total: $" << setprecision(2) << runningTotal << endl;
        for (int show = 0; show < 5; show++){
        cout << show+1 << ". ";
        items[show].showPrize();
        if (picked[show] == true)
            cout << " X ";
        cout << endl;
        }
        int playerChoice = 0;
        int toBuy = 0;
        double itemTotal = 0;
        cout << endl << "Which item (enter the number) would you like to buy?: ";
        cin >> playerChoice;
        switch (playerChoice)
        {
        case 1:

            /// check if the player already purchased this item
            if (picked[0] == false)
            {
                cout << endl << "You picked the ";
                items[0].showShortName();
                cout << endl << "How many do you want to buy?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[0].showARP();
                cout << endl;
                itemTotal = items[0].getPrice() * toBuy;
                cout << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                runningTotal += items[0].getPrice() * toBuy;
                picked[0] = true;
            }
            else
                cout << endl << "You've already purchased this item. Please pick another.";

            /// check if all five items have been purchased
            if (picked[0] && picked[1] && picked[2] && picked[3] && picked[4])
            {
                boughtFive = true;
            }

            /// check if the game has been won
            if (runningTotal >= 20 && runningTotal <= 22)
                won = true;
            break;

        case 2:

            /// check if the player already purchased this item
            if (picked[1] == false)
            {
                cout << endl << "You picked the ";
                items[1].showShortName();
                cout << endl << "How many do you want to buy?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[1].showARP();
                cout << endl;
                itemTotal = items[1].getPrice() * toBuy;
                cout << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                runningTotal += items[1].getPrice() * toBuy;
                picked[1] = true;
            }
            else
                cout << endl << "You've already purchased this item. Please pick another.";

            /// check if all five items have been purchased
            if (picked[0] && picked[1] && picked[2] && picked[3] && picked[4])
            {
                boughtFive = true;
            }

            /// check if the game has been won
            if (runningTotal >= 20 && runningTotal <= 22)
                won = true;
            break;

        case 3:

            /// check if the player already purchased this item
            if (picked[2] == false)
            {
                cout << endl << "You picked the ";
                items[2].showShortName();
                cout << endl << "How many do you want to buy?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[2].showARP();
                cout << endl;
                itemTotal = items[2].getPrice() * toBuy;
                cout << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                runningTotal += items[2].getPrice() * toBuy;
                picked[2] = true;
            }
            else
                cout << endl << "You've already purchased this item. Please pick another.";

            /// check if all five items have been purchased
            if (picked[0] && picked[1] && picked[2] && picked[3] && picked[4])
            {
                boughtFive = true;
            }

            /// check if the game has been won
            if (runningTotal >= 20 && runningTotal <= 22)
                won = true;
            break;

        case 4:

            /// check if the player already purchased this item
            if (picked[3] == false)
            {
                cout << endl << "You picked the ";
                items[3].showShortName();
                cout << endl << "How many do you want to buy?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[3].showARP();
                cout << endl;
                itemTotal = items[3].getPrice() * toBuy;
                cout << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                runningTotal += items[3].getPrice() * toBuy;
                picked[3] = true;
            }
            else
                cout << endl << "You've already purchased this item. Please pick another.";

            /// check if all five items have been purchased
            if (picked[0] && picked[1] && picked[2] && picked[3] && picked[4])
            {
                boughtFive = true;
            }

            /// check if the game has been won
            if (runningTotal >= 20 && runningTotal <= 22)
                won = true;
            break;

        case 5:

            /// check if the player already purchased this item
            if (picked[4] == false)
            {
                cout << endl << "You picked the ";
                items[4].showShortName();
                cout << endl << "How many do you want to buy?: ";
                cin >> toBuy;
                cout << "Each one is ";
                items[4].showARP();
                cout << endl;
                itemTotal = items[4].getPrice() * toBuy;
                cout << toBuy << " of them is $" << setprecision(2) << itemTotal << endl;
                runningTotal += items[4].getPrice() * toBuy;
                picked[4] = true;
            }
            else
                cout << endl << "You've already purchased this item. Please pick another.";

            /// check if all five items have been purchased
            if (picked[0] && picked[1] && picked[2] && picked[3] && picked[4])
            {
                boughtFive = true;
            }

            /// check if the game has been won
            if (runningTotal >= 20 && runningTotal <= 22)
                won = true;
            break;

        default:
            cout << endl << "That won't work. Try again.";
        }
}
    while ((runningTotal <= 22) && (boughtFive == false) && (won == false));

        cout << endl;
        cout << "Running Total: $" << setprecision(2) << runningTotal << endl;
        if (won)
            cout << endl << "Congratulations, you won!";
        else
        {
            if (runningTotal < 20)
                cout << endl << "You didn't purchase enough items. Sorry.";
            else if (runningTotal > 22)
                cout << endl << "You went over $22. Sorry.";
            else
                cout << endl << "Congratulations, you win!";
        }

        cout << endl;

    inFile.close();
    system("pause");
    system("CLS");
}

/// Hi-Lo
void playHiLo()
{
    list<grocery> hiloItems;
    list<grocery>::iterator hiloItemIt;

    string t_hlDescription;
    string t_hlShortName;
    double t_hlPrice;

    grocery * hlptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    hlptr = new grocery;
    if (inFile >> t_hlDescription >> t_hlShortName >> t_hlPrice)
    {
        hlptr->setDescription(t_hlDescription);
        hlptr->setShortName(t_hlShortName);
        hlptr->setPrice(t_hlPrice);
        hiloItems.push_back(*hlptr);
        i++;
    }
    } // end while loop

    cout << "HI-LO" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int j = 0; j < i; j++)
    {
        randomizationField[j] = j;
    }


    random_shuffle(&randomizationField[0], &randomizationField[i]);

    int z = 0;
    grocery items[6];
    bool picked[6];
    for (int p = 0; p < 6; p++)
        picked[p] = false;
    double smallestHiItem;

    /// Set each item
    for (int itemCount = 0; itemCount < 6; itemCount++)
    {
        hiloItemIt = hiloItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            hiloItemIt++;
        }

        items[itemCount].setDescription(hiloItemIt->getDescription());
        items[itemCount].setShortName(hiloItemIt->getShortName());
        items[itemCount].setPrice(hiloItemIt->getPrice());
    }

    cout << "Here are the grocery items today:" << endl;

    int picks = 0;

    while (picks < 3){
    int playerChoice = 0;

    for (int d = 0; d < 6; d++){
        cout << d+1 << ". ";
        items[d].showPrize();
        if (picked[d])
        {
            cout << " - ";
            items[d].showARP();
        }
        cout << endl;
    }
    cout << "Which item (enter the number) do you want to pick?: ";
    cin >> playerChoice;
    switch (playerChoice){
    case 1:
        if (picked[0] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[0].showShortName();
            cout << " is ";
            items[0].showARP();
            cout << endl << endl;
            picked[0] = true;
            if (picks == 0)
                smallestHiItem = items[0].getPrice();
            else
            {
                if (items[0].getPrice() <= smallestHiItem)
                    smallestHiItem = items[0].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 2:
        if (picked[1] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[1].showShortName();
            cout << " is ";
            items[1].showARP();
            cout << endl << endl;
            picked[1] = true;
            if (picks == 0)
                smallestHiItem = items[1].getPrice();
            else
            {
                if (items[1].getPrice() <= smallestHiItem)
                    smallestHiItem = items[1].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 3:
        if (picked[2] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[2].showShortName();
            cout << " is ";
            items[2].showARP();
            cout << endl << endl;
            picked[2] = true;
            if (picks == 0)
                smallestHiItem = items[2].getPrice();
            else
            {
                if (items[2].getPrice() <= smallestHiItem)
                    smallestHiItem = items[2].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 4:
        if (picked[3] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[3].showShortName();
            cout << " is ";
            items[3].showARP();
            cout << endl << endl;
            picked[3] = true;
            if (picks == 0)
                smallestHiItem = items[3].getPrice();
            else
            {
                if (items[3].getPrice() <= smallestHiItem)
                    smallestHiItem = items[3].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 5:
        if (picked[4] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[4].showShortName();
            cout << " is ";
            items[4].showARP();
            cout << endl << endl;
            picked[4] = true;
            if (picks == 0)
                smallestHiItem = items[4].getPrice();
            else
            {
                if (items[4].getPrice() <= smallestHiItem)
                    smallestHiItem = items[4].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 6:
        if (picked[5] == false)
        {
            cout << endl << "The actual retail price of the ";
            items[5].showShortName();
            cout << " is ";
            items[5].showARP();
            cout << endl << endl;
            picked[5] = true;
            if (picks == 0)
                smallestHiItem = items[5].getPrice();
            else
            {
                if (items[5].getPrice() <= smallestHiItem)
                    smallestHiItem = items[5].getPrice();
            }
            picks += 1;
        }
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    default:
        cout << endl << "That won't work. Try again.";
    } // end switch statement:


    } // end while loop

    for (int h = 0; h < 6; h++){
        cout << h+1 << ". ";
        items[h].showPrize();
        if (picked[h])
        {
            cout << " - ";
            items[h].showARP();
        }
        cout << endl;
    }
    cout << endl;

    cout << fixed << "The cheapest price on the HI shelf is $" << setprecision(2) << smallestHiItem << endl;
    cout << "Now, let's reveal the prices of the remaining items." << endl;
    system("pause");
    bool lost = false;

    for (int j = 0; j < 6; j++){
    if (!picked[j] && !lost){
        cout << endl << "The actual retail price of the ";
        items[j].showShortName();
        cout << " is ";
        items[j].showARP();
        cout << endl;
        if (items[j].getPrice() > smallestHiItem)
            lost = true;
        else
            system("pause");
    }
    }

    if (lost)
        cout << endl << "Sorry, you lose.";
    else
        cout << endl << "Congratulations, you win!";
    cout << endl;

    inFile.close();
    system("pause");
    system("CLS");

}

/// Hit Me
void playHitMe()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "HIT ME" << endl;

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
    grocery items[6];
    bool picked[6];

    /// Cards associated with each grocery item.
    int cards[6];
    cards[0] = 1;
    cards[1] = 10;
    cards[2] = 1;
    while ( (cards[2] == cards[0]) || (cards[2] == cards[1]) )
        cards[2] =  rand()%(9-2+1)+2;
    cards[3] = 1;
    while ( (cards[3] == cards[0]) || (cards[3] == cards[1]) || (cards[3] == cards[2]) )
        cards[3] =  rand()%(9-2+1)+2;
    cards[4] = 1;
    while ( (cards[4] == cards[0]) || (cards[4] == cards[1]) || (cards[4] == cards[2]) || (cards[4] == cards[3]) )
        cards[4] =  rand()%(9-2+1)+2;
    cards[5] = 1;
    while ( (cards[5] == cards[0]) || (cards[5] == cards[1]) || (cards[5] == cards[2]) || (cards[5] == cards[3]) || (cards[5] == cards[4]) )
        cards[5] =  rand()%(9-2+1)+2;

    random_shuffle(&cards[0], &cards[6]);

    /// Initial values shown (the price of the item multiplied by its card's value).
    double showns[6];

    /// Set each item, this time using a for loop:
    for (int grocCount = 0; grocCount < 6; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
        showns[grocCount] = items[grocCount].getPrice() * cards[grocCount];
        picked[grocCount] = false;
    }

    int handIfAceOne = 0;
    int handIfAceEleven = 0;

    int deck[52] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
                     8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13};
    random_shuffle(&deck[0], &deck[52]);

    bool pickedAll = false;
    bool won = false;
    bool lost = false;

    int upCard;

    if (deck[0] == 10){
        cout << endl << "The house's up card is a 10";
        upCard = 10;
        }
    else if (deck[0] == 11){
        cout << endl << "The house's up card is a jack";
        upCard = 10;
    }
    else if (deck[0] == 12){
        cout << endl << "The house's up card is a queen";
        upCard = 10;
    }
    else if (deck[0] == 13){
        cout << endl << "The house's up card is a king";
        upCard = 10;
    }
    else if (deck[0] == 1){
        cout << endl << "The house's up card is an ace";
        upCard = 11;
    }
    else if (deck[0] == 8){
        cout << endl << "The house's up card is an 8";
        upCard = 8;
    }
    else{
        cout << endl << "The house's up card is a " << deck[0];
        upCard = deck[0];
    }
    cout << endl;

    int houseHandIfAceOne = upCard;
    int houseHandIfAceEleven = upCard;
    if (upCard == 11)
        int houseHandIfAceOne = 1;


    while ((!pickedAll) && (!won) && (!lost) )
    {
        for (int x = 0; x < 6; x++)
        {
            cout << endl << x+1 << ". ";
            items[x].showPrize();
            if (picked[x]){
                if (cards[x] != 1)
                    cout << fixed << setprecision(2) << " - $" << items[x].getPrice() << " (" << cards[x] << ")";
                else
                    cout << fixed << setprecision(2) << " - $" << items[x].getPrice() << " (A)";
                }
            else
                cout << fixed << setprecision(2) << " - $" << showns[x];
        } // end for loop
        cout << endl << "7. Stop drawing";
        if (handIfAceOne == handIfAceEleven)
            cout << endl << "Hand: " << handIfAceOne;
        else if (handIfAceEleven <= 21)
            cout << endl << "Hand: " << handIfAceEleven << "/" << handIfAceOne;
        else
            cout << endl << "Hand: " << handIfAceOne;

        int choice = 0;
        while ( (choice < 1) || (choice > 7) )
        {
            cout << endl << "Which item do you want to pick?: ";
            cin >> choice;
        }
        if (choice == 7){
            if ( (handIfAceOne == 0) || (handIfAceEleven == 0) )
                cout << endl << "You need to pick some items first!";
            else
                pickedAll = true;
            }
        else
        {
        if (picked[choice-1])
            cout << endl << "You've already picked this item. Please pick another.";
        else
        {
            cout << endl << "The actual retail price of the ";
            items[choice-1].showShortName();
            cout << " is ";
            items[choice-1].showARP();
            if (cards[choice-1] == 8)
                cout << endl << "Behind this item is an " << cards[choice-1];
            else if (cards[choice-1] == 1)
                cout << endl << "Behind this item is an ace";
            else
                cout << endl << "Behind this item is a " << cards[choice-1];
            if (cards[choice-1] == 1)
            {
                handIfAceOne += 1;
                handIfAceEleven += 11;
            }
            else
            {
                handIfAceOne += cards[choice-1];
                handIfAceEleven += cards[choice-1];
            }
            picked[choice-1] = true;
            if ( (handIfAceEleven == 21) || (handIfAceOne == 21) )
                won = true;
            else if (handIfAceOne > 21)
                lost = true;
            else if ( (picked[0]) && (picked[1]) && (picked[2]) && (picked[3]) && (picked[4]) && (picked[5]) )
                pickedAll = true;

        } // end else statement for if player picks an unchosen item

        } // end else statement for if player picks an item


    } // end while loop

    int onCard = 1;
    bool stay = false;
    bool bust = false;

    if (won)
        cout << endl << "Congratulations, you win!";
    else if (lost)
        cout << endl << "Sorry, you lose.";
    else
    {
        cout << endl << "The house's hole card is " << cards[1];
        if (cards[1] >= 10){
            houseHandIfAceEleven += 10;
            //houseHandIfAceOne += 10;
        }
        else if (cards[1] == 1){
            houseHandIfAceEleven += 11;
            //houseHandIfAceOne += 1;
        }
        else{
            houseHandIfAceEleven += cards[1];
            //houseHandIfAceOne += cards[1];
        }
        //if (houseHandIfAceOne > 21)
        //    cout << endl << "The house busted." << endl << "Congratulations, you win!";
        if ( ((houseHandIfAceEleven >= 17) && (houseHandIfAceEleven <= 21)) )
        {
            //if (houseHandIfAceEleven != houseHandIfAceOne)
            //    cout << endl << "The house stays at " << houseHandIfAceEleven << "/" << houseHandIfAceOne;
            //else
            cout << endl << "The house stays at " << houseHandIfAceEleven;
            if ( (handIfAceEleven >= houseHandIfAceEleven) || (handIfAceOne >= houseHandIfAceEleven) )
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
         // end else if the house stays at the hole card
        }
         else
         {
            onCard += 1;
            while ( (onCard < 26) && !stay && !bust)
            {
            if (cards[onCard] == 13)
            {
                cout << endl << "The house drew a king";
                houseHandIfAceEleven += 10;
                //houseHandIfAceOne += 10;
            }
            else if (cards[onCard] == 12)
            {
                cout << endl << "The house drew a queen";
                houseHandIfAceEleven += 10;
                //houseHandIfAceOne += 10;
            }
            else if (cards[onCard] == 11)
            {
                cout << endl << "The house drew a jack";
                houseHandIfAceEleven += 10;
                //houseHandIfAceOne += 10;
            }
            else if (cards[onCard] == 1)
            {
                cout << endl << "The house drew an ace";
                houseHandIfAceEleven += 11;
                //houseHandIfAceOne += 1;
            }
            else if (cards[onCard] == 8)
            {
                cout << endl << "The house drew an 8";
                houseHandIfAceEleven += 8;
                //houseHandIfAceOne += 8;
            }
            else
            {
                cout << endl << "The house drew a " << cards[onCard];
                houseHandIfAceEleven += cards[onCard];
                //houseHandIfAceOne += cards[onCard];
            }
            if (houseHandIfAceEleven > 21)
                bust = true;
            else if ( ((houseHandIfAceEleven >= 17) && (houseHandIfAceEleven <= 21)) )
                stay = true;
            else
            {
                cout << endl;
                system("pause");
                onCard++;
            }
            } // end while loop when the house draws cards

         } // end else if the house hits at the hole card

    } // end else if player's hand is less than 21

    if (bust)
        cout << endl << "The house busted." << endl << "Congratulations, you win!";
    else if (stay)
    {
    //if (houseHandIfAceEleven != houseHandIfAceOne)
    //    cout << endl << "The house stays at " << houseHandIfAceEleven << "/" << houseHandIfAceOne;
    //else
    cout << endl << "The house stays at " << houseHandIfAceEleven;
    if ( (handIfAceEleven >= houseHandIfAceEleven) || (handIfAceOne >= houseHandIfAceEleven) )
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Hole in One
void playHoleInOne()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "HOLE IN ONE" << endl;

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
    grocery items[6];
    bool picked[6];
    for (int p = 0; p < 6; p++)
            picked[p] = false;

    /// The ints here will be the ids for each grocery item.
    int arrangement[6];

    /// The ints here will be the order for each item.
    int order[6];

    /// Set each item, this time using a for loop:
    for (int grocCount = 0; grocCount < 6; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
    }

    int on = 0;

    while (on < 6)
    {
        cout << endl;
        for (int y = 0; y < 6; y++)
        {
            cout << y+1 << ". ";
            items[y].showPrize();
            if (picked[y])
                cout << " - " << order[y];
            cout << endl;
        }
        int choice = 0;
        while ( (choice < 1) ||  (choice > 6) )
        {
            if (on == 0)
                cout << endl << "Which item is the least expensive?: ";
            else if (on == 5)
                cout << endl << "Which item is the most expensive?: ";
            else
                cout << endl << "Which item is the next least expensive?: ";
            cin >> choice;
        }
        if (picked[choice-1])
            cout << endl << "You've already chosen this item. Please choose another.";
        else
        {
            picked[choice-1] = true;
            arrangement[on] = choice-1;
            order[choice-1] = on+1;
            on++;
        }

    } // end while loop

    cout << endl << "Now, let's see how you ranked the items.";
    cout << endl;

    bool stopped;
    bool perfect;
    int puttingLine = 1;

    /*
    for (int x = 0; x < 6; x++){
        items[arrangement[x]].showShortName();
        cout << endl;
    }
    */

    double lastPrice;

    cout << endl << "The actual retail price of the ";
    items[arrangement[0]].showShortName();
    cout << " is ";
    items[arrangement[0]].showARP();
    lastPrice = items[arrangement[0]].getPrice();
    cout << endl;
    system("pause");

    puttingLine++;
    cout << endl << "The actual retail price of the ";
    items[arrangement[1]].showShortName();
    cout << " is ";
    items[arrangement[1]].showARP();
    if (items[arrangement[1]].getPrice() >= lastPrice)
    {
        lastPrice = items[arrangement[1]].getPrice();
        cout << endl;
        system("pause");

        puttingLine++;
        cout << endl << "The actual retail price of the ";
        items[arrangement[2]].showShortName();
        cout << " is ";
        items[arrangement[2]].showARP();
        if (items[arrangement[2]].getPrice() >= lastPrice)
        {
            lastPrice = items[arrangement[2]].getPrice();
            cout << endl;
            system("pause");

            puttingLine++;
            cout << endl << "The actual retail price of the ";
            items[arrangement[3]].showShortName();
            cout << " is ";
            items[arrangement[3]].showARP();
            if (items[arrangement[3]].getPrice() >= lastPrice)
            {
             lastPrice = items[arrangement[3]].getPrice();
             cout << endl;
             system("pause");

             puttingLine++;
             cout << endl << "The actual retail price of the ";
             items[arrangement[4]].showShortName();
             cout << " is ";
             items[arrangement[4]].showARP();
             if (items[arrangement[4]].getPrice() >= lastPrice)
             {
             lastPrice = items[arrangement[4]].getPrice();
             cout << endl;
             system("pause");

             puttingLine++;
             cout << endl << "The actual retail price of the ";
             items[arrangement[5]].showShortName();
             cout << " is ";
             items[arrangement[5]].showARP();

             if (items[arrangement[5]].getPrice() >= lastPrice)
             {
                cout << endl << "You arranged the items perfectly! You win a $500 bonus!";         /// 7/8 odds
                puttingLine++;

             } /// end if sixth item > fifth item
             else
                cout << endl << "Sorry, that's not correct. \nYou're very close to the hole though!"; /// 6/8 odds

             } /// end if fifth item > fourth item
             else
                cout << endl << "Sorry, that's not correct. \nYou're pretty close to the hole though!"; /// 5/8 odds

            } /// end if fourth item > third item
            else
              cout << endl << "Sorry, that's not correct. \nYou're not too far from the hole though."; /// 4/8 odds


        } /// end if third item > second item
    else
        cout << endl << "Sorry, that's not correct. \nYou're pretty far, but you can do it."; /// 3/8 odds

    } /// end if second item > first item
    else
        cout << endl << "Sorry, that's not correct. \nYou'll have to putt from the furthest line."; /// 2/8 odds

    cout << endl;

    int firstPutt = rand() % 8 + 1;
    int secondPutt = rand() % 8 + 1;

    //cout << endl << "first putt = " << firstPutt;
    //cout << endl << "second putt = " << secondPutt;
    //cout << endl << "putting odds =" << puttingLine;

    cout << endl << "Press any key to putt the ball.";
    cout << endl;
    system("pause");
    if (puttingLine >= firstPutt)
        cout << endl << "Congratulations, you win!";
    else
    {
        cout << endl << "You didn't sink the ball on the first try, but the game is called...";
        cout << endl << "HOLE IN ONE... OR TWO!";
        cout << endl << "Press any key to put the ball.";
        cout << endl;
        system("pause");
        if (puttingLine >= secondPutt)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }



    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Hurdles
void playHurdles()
{
    /// Items that belong to the hurdler.
    list<grocery> hurdItems;
    list<grocery>::iterator hurdItemsIt;

    /// Items that cost less than the hurdler's item.
    list<grocery> loItems;
    list<grocery>::iterator loItemsIt;

    /// Items that cost more than the hurdler's item.
    list<grocery> hiItems;
    list<grocery>::iterator hiItemsIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    string u_ggDescription;
    string u_ggShortName;
    double u_ggPrice;

    grocery * ggptr;
    grocery * hgptr;

    srand(time(0));

    int i = 0;
    int ii = 0;

    int midCount = 0; /// counts hurdler items
    int loCount = 0; /// counts items that cost less than the hurdler's item
    int hiCount = 0; /// counts items that cost more than the hurdler's item

    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice)
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        if ((t_ggPrice > 3) && (t_ggPrice < 6)){
            hurdItems.push_back(*ggptr);
            midCount++;
        }
        i++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    //cout << endl << "midcount = " << midCount << endl;

    /// Pick a random grocery item for the hurdler. Since there's only one item,
    /// a randomization field isn't necessary.
    grocery hurdlerItem;
    int hurdlerGrocID = rand() % midCount;
    hurdItemsIt = hurdItems.begin();
    for (int x = 0; x < hurdlerGrocID; x++)
            hurdItemsIt++;
    hurdlerItem.setDescription(hurdItemsIt->getDescription());
    hurdlerItem.setShortName(hurdItemsIt->getShortName());
    hurdlerItem.setPrice(hurdItemsIt->getPrice());



    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    hgptr = new grocery;
    if (inFile >> u_ggDescription >> u_ggShortName >> u_ggPrice)
    {
        hgptr->setDescription(u_ggDescription);
        hgptr->setShortName(u_ggShortName);
        hgptr->setPrice(u_ggPrice);
        if (u_ggPrice < hurdlerItem.getPrice())
        {
            loItems.push_back(*hgptr);
            loCount++;
        }
        else if ( (u_ggPrice > hurdlerItem.getPrice()) && (u_ggPrice < 10) )
        {
            hiItems.push_back(*hgptr);
            hiCount++;
        }
        ii++;
    } // end if statement
    } // end while loop
    inFile.close();
    inFile.clear();

     /// Generate two randomization fields, one for each grouping of groceries.
    int loRandomizationField[loCount];
    /// Initialize the randomization field.
    for (int j = 0; j < loCount; j++)
    {
        loRandomizationField[j] = j;
    }
    random_shuffle(&loRandomizationField[0], &loRandomizationField[loCount]);

   //for (int w = 0; w < loCount; w++)
        //cout << loRandomizationField[w] << ", ";

    /// Generate two randomization fields, one for each grouping of groceries.
    int hiRandomizationField[hiCount];
    /// Initialize the randomization field.
    for (int k = 0; k < hiCount; k++)
    {
        hiRandomizationField[k] = k;
    }
    random_shuffle(&hiRandomizationField[0], &hiRandomizationField[hiCount]);

    //cout << endl << endl;
    //for (int v = 0; v < hiCount; v++)
        //cout << hiRandomizationField[v] << ", ";

    grocery loGrocs[3];
    grocery hiGrocs[3];

    int z = 0;
    int zz = 0;

    /// Initialize all the grocery items.
    for (int lc = 0; lc < 3; lc++)
    {
        loItemsIt = loItems.begin();
        for (z = 0; z < loRandomizationField[lc]; z++)
        {
            loItemsIt++;
        }

        loGrocs[lc].setDescription(loItemsIt->getDescription());
        loGrocs[lc].setShortName(loItemsIt->getShortName());
        loGrocs[lc].setPrice(loItemsIt->getPrice());
    }

    for (int hc = 0; hc < 3; hc++)
    {
        hiItemsIt = hiItems.begin();
        for (z = 0; z < loRandomizationField[hc]; z++)
        {
            hiItemsIt++;
        }

        hiGrocs[hc].setDescription(hiItemsIt->getDescription());
        hiGrocs[hc].setShortName(hiItemsIt->getShortName());
        hiGrocs[hc].setPrice(hiItemsIt->getPrice());
    }

    /// If these variables equal 0, then the less expensive item will be on the left. If they equal
    /// 1, the less expensive item will be on the right.
    int side1 = rand() % 2;
    int side2 = rand() % 2;
    int side3 = rand() % 2;

    /// Player's choice for each pair of items.
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    /// Values of each hurdle, stored for convenience.
    double hurdleVal1;
    double hurdleVal2;
    double hurdleVal3;

    cout << "HURDLES" << endl;

    cout << endl << "Hurdler's item: ";
    cout << endl;
    hurdlerItem.showPrize();
    cout << endl;
    hurdlerItem.showARP();
    cout << endl;

    /// Hurdle #1
    cout << endl << "HURDLE #1";
    if (side1 == 0)
    {
        cout << endl << "1. ";
        loGrocs[0].showPrize();
        cout << endl << "2. ";
        hiGrocs[0].showPrize();
    }
    else
    {
        cout << endl << "1. ";
        hiGrocs[0].showPrize();
        cout << endl << "2. ";
        loGrocs[0].showPrize();
    }

    while ((choice1 < 1) || (choice1 > 2)){
    cout << endl << "Which item (enter its number) costs less than the hurdler's item?: ";
    cin >> choice1;
    }
    if ( (choice1 == 1) && (side1 == 0) || (choice1 == 2) && (side1 == 1) )
        hurdleVal1 = loGrocs[0].getPrice();
    else
        hurdleVal1 = hiGrocs[0].getPrice();

    /// Hurdle #2
    cout << endl << "HURDLE #2";
    if (side2 == 0)
    {
        cout << endl << "1. ";
        loGrocs[1].showPrize();
        cout << endl << "2. ";
        hiGrocs[1].showPrize();
    }
    else
    {
        cout << endl << "1. ";
        hiGrocs[1].showPrize();
        cout << endl << "2. ";
        loGrocs[1].showPrize();
    }

    while ((choice2 < 1) || (choice2 > 2)){
    cout << endl << "Which item (enter its number) costs less than the hurdler's item?: ";
    cin >> choice2;
    }
    if ( (choice2 == 1) && (side2 == 0) || (choice2 == 2) && (side2 == 1) )
        hurdleVal2 = loGrocs[1].getPrice();
    else
        hurdleVal2 = hiGrocs[1].getPrice();

    /// Hurdle #3
    cout << endl << "HURDLE #3";
    if (side3 == 0)
    {
        cout << endl << "1. ";
        loGrocs[2].showPrize();
        cout << endl << "2. ";
        hiGrocs[2].showPrize();
    }
    else
    {
        cout << endl << "1. ";
        hiGrocs[2].showPrize();
        cout << endl << "2. ";
        loGrocs[2].showPrize();
    }

    while ((choice3 < 1) || (choice3 > 2)){
    cout << endl << "Which item (enter its number) costs less than the hurdler's item?: ";
    cin >> choice3;
    }
    if ( (choice3 == 1) && (side3 == 0) || (choice3 == 2) && (side3 == 1) )
        hurdleVal3 = loGrocs[2].getPrice();
    else
        hurdleVal3 = hiGrocs[2].getPrice();

    bool lost = false;

    cout << endl << "Now, let's see if the hurdler can make it over all three hurdles." << endl;
    system("pause");
    cout << endl << "Hurdler's price: ";
    hurdlerItem.showARP();
    cout << fixed << endl << "The item at hurdle #1 is $" << setprecision(2) << hurdleVal1 << endl;
    if (hurdleVal1 > hurdlerItem.getPrice())
        lost = true;
    else
    {
        cout << endl << "The hurdler made it over this hurdle!" << endl;
        system("pause");
        cout << fixed << endl << "The item at hurdle #2 is $" << setprecision(2) << hurdleVal2 << endl;
        if (hurdleVal2 > hurdlerItem.getPrice())
            lost = true;
        else
        {
        cout << endl << "The hurdler made it over this hurdle!" << endl;
        system("pause");
        cout << fixed << endl << "The item at hurdle #3 is $" << setprecision(2) << hurdleVal3 << endl;
        if (hurdleVal3 > hurdlerItem.getPrice())
            lost = true;
        else
        {
            cout << endl << "Congratulations, you win!" << endl;
        } // end else for hurdle #3

        } // end else for hurdle #2
    } // end else for hurdle #1

    if (lost)
        cout << endl << "CRASH!" << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// It's In The Bag
void playItsInTheBag()
{
    /// Items between $1 and $10
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    /// Items under $1. The first item is always under $1.
    list<grocery> firstItems;
    list<grocery>::iterator firstItemsIt;

    /// Items over $10. The second item is always over $10.
    list<grocery> secondItems;
    list<grocery>::iterator secondItemsIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;

    int ofType1 = 0; /// Counts normal items.
    int ofType2 = 0; /// Counts items under $1.
    int ofType3 = 0; /// Counts items over $10.

    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice)
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        if (t_ggPrice < 1){
            firstItems.push_back(*ggptr);
            ofType1++;
        }
        else if (t_ggPrice >= 10){
            secondItems.push_back(*ggptr);
            ofType2++;
        }
        else{
            ggItems.push_back(*ggptr);
            ofType3++;
        }
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "IT'S IN THE BAG" << endl;

        ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.

    /// Since there is only one grocery in these categories, we don't need to generate a randomization field.
    int randomSmallGrocery = rand() % ofType1;
    int randomLargeGrocery = rand() % ofType2;

    /// We do, however, generate one for the remaining groceries.
    int randomizationField[ofType3];

    /// Initialize the randomization field.
    for (int j = 0; j < ofType3; j++)
    {
        randomizationField[j] = j;
    }


    /// Rearrange the numbers
    /*
    for (int k = ofType3-1; k > 0; k--)
    {
        int l = rand()%k;
        int t = randomizationField[k];
        randomizationField[k] = randomizationField[l];
        randomizationField[l] = l;
    }
    */
    random_shuffle(&randomizationField[0], &randomizationField[ofType3]);

    ///int z = 0;
    grocery items[6];
    double prices[5];
    bool itemChosen[6];
    for (int b = 0; b < 6; b++)
        itemChosen[b] = false;




    for (int itemCount = 0; itemCount < 6; itemCount++)
    {
        if (itemCount == 0)
        {
            firstItemsIt = firstItems.begin();
            for (int x = 0; x < randomSmallGrocery; x++)
                firstItemsIt++;
            items[0].setDescription(firstItemsIt->getDescription());
            items[0].setShortName(firstItemsIt->getShortName());
            items[0].setPrice(firstItemsIt->getPrice());
        }
        else if (itemCount == 1)
        {
            secondItemsIt = secondItems.begin();
            for (int y = 0; y < randomLargeGrocery; y++)
                secondItemsIt++;
            items[1].setDescription(secondItemsIt->getDescription());
            items[1].setShortName(secondItemsIt->getShortName());
            items[1].setPrice(secondItemsIt->getPrice());
        }
        else
        {
            ggItemIt = ggItems.begin();
            for (int z = 0; z < randomizationField[itemCount]; z++)
                ggItemIt++;
            items[itemCount].setDescription(ggItemIt->getDescription());
            items[itemCount].setShortName(ggItemIt->getShortName());
            items[itemCount].setPrice(ggItemIt->getPrice());
        //cout << "randomization field number = " << randomizationField[itemCount] << endl;
        //items[itemCount].showPrize();
        }
        //ggItemIt = ggItems.begin();
    } /// end for loop. All the items should be initialized.

    /*
    for (int d = 0; d < 6; d++)
    {
        cout << d+1 << ". ";
        items[d].showPrize();
        cout << endl;
    }
    */

    /// Set prices. The price of items[5] will go unused, so the fact that there are
    /// only five prices is not a mistake.

    for (int t = 0; t < 5; t++)
    {
        prices[t] = items[t].getPrice();
    }

    /// This randomizes the order the items appear in.
    int randomizePrizes[6];
    for (int u = 0; u < 6; u++)
    {
        randomizePrizes[u] = u;
    }
    random_shuffle(&randomizePrizes[0], &randomizePrizes[6]);

    /*
    for (int e = 0; e < 6; e++)
    {
        cout << e+1 << ". ";
        items[randomizePrizes[e]].showPrize();
        cout << endl;
    }
    */


    string bagChoices[5];

    cout << endl;

    int s = 0;

    /// Ensure that no two prices are the same. It may be cheesy to generate fake prices,
    /// but it's a temporary fix.
    if (prices[3] == prices[2])
        prices[3] += 0.2;
    if (prices[4] == prices[2])
        prices[4] += 0.2;
    if (prices[4] == prices[3])
        prices[4] += 0.2;



    cout << "Prices: " << endl;
    for (int show = 0; show < 5; show++){
        cout << fixed << "$" << setprecision(2) << prices[show];
        cout << " - $" << setprecision(0) << (pow(2, show)*1000) << endl;
    }

    cout << endl;

    while (s < 5)
    {
        cout << fixed << "$" << setprecision(2) << prices[s] << endl;
        bool setIt = false;
        int choice = 0;
        for (int e = 0; e < 6; e++)
        {
            cout << e+1 << ". ";
            items[randomizePrizes[e]].showPrize();
            if (itemChosen[randomizePrizes[e]] == true)
                cout << " - O";
            cout << endl;
        }
        cout << endl << fixed << "Which item is $" << setprecision(2) << prices[s] << "?: ";
        cin >> choice;
        switch (choice){

    case 1:
        if (itemChosen[randomizePrizes[0]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[0]] = true;
            bagChoices[s] = items[randomizePrizes[0]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    case 2:
        if (itemChosen[randomizePrizes[1]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[1]] = true;
            bagChoices[s] = items[randomizePrizes[1]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    case 3:
        if (itemChosen[randomizePrizes[2]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[2]] = true;
            bagChoices[s] = items[randomizePrizes[2]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    case 4:
        if (itemChosen[randomizePrizes[3]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[3]] = true;
            bagChoices[s] = items[randomizePrizes[3]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    case 5:
        if (itemChosen[randomizePrizes[4]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[4]] = true;
            bagChoices[s] = items[randomizePrizes[4]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    case 6:
        if (itemChosen[randomizePrizes[5]] == true)
            cout << endl << "You've already chosen this item. Please pick another." << endl;
        else
        {
            itemChosen[randomizePrizes[5]] = true;
            bagChoices[s] = items[randomizePrizes[5]].getShortName();
            //cout << endl << bagChoices[s] << " = $" << prices[s] << endl;
            s++;
        }
    break;

    default:
        cout << endl << "That won't work. Try again." << endl;

        } /// end switch statement
    cout << endl;
    } /// end while loop

    /*
    for (int f = 0; f < 5; f++)
        cout << bagChoices[f] << endl;
    */

    bool wonBig = false;
    bool lost = false;
    bool bail = false;
    int winnings = 1000;
    int onAgain = 0;
    char goOn = 'A';

    while ( (!wonBig) && (!lost) && (!bail) )
    {
        cout << fixed << endl << "For $1000, let's see what is $" << setprecision(2) << prices[onAgain] << endl;
        system("pause");
        //cout << fixed << endl << "The " << items[0].getShortName() << " is $" << setprecision(2) << prices[onAgain] << endl;
        cout << endl << "The ";
        items[0].showShortName();
        cout << fixed << " is $" << setprecision(2) << prices[onAgain];
        if (items[0].getShortName() != bagChoices[0]){
            //cout << endl << "AAAA" << endl;
            lost = true;
        }
        else
        {
        /// Player guesses correctly.
        cout << endl << "You have $" << winnings << ".";
        while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
         cout << endl << "Do you want to go on (Y) or stop now (N)?: ";
         cin >> goOn;
        } /// end while loop
        if ( (goOn == 'N') || (goOn == 'n') )
            bail = true;
        else
        { /// Moving on to the second bag.
            onAgain++;
            cout << endl << "For $" << setprecision(0) << (pow(2, onAgain)*1000);
            cout << fixed << ", let's see what is $" << setprecision(2) << prices[onAgain] << endl;
            system("pause");
            cout << endl << "The ";
            items[onAgain].showShortName();
            cout << fixed << " is $" << setprecision(2) << prices[onAgain];
            if (items[onAgain].getShortName() != bagChoices[onAgain])
                lost = true;
            else
            {
            /// Player guesses correctly;
            goOn = 'A';
            winnings *= 2;
            cout << endl << "You have $" << winnings << ".";
        while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
         cout << endl << "Do you want to go on (Y) or stop now (N)?: ";
         cin >> goOn;
        } /// end while loop
        if ( (goOn == 'N') || (goOn == 'n') )
            bail = true;
        else
        { /// Moving on to the third bag.
            onAgain++;
            cout << endl << "For $" << setprecision(0) << (pow(2, onAgain)*1000);
            cout << fixed << ", let's see what is $" << setprecision(2) << prices[onAgain] << endl;
            system("pause");
            cout << endl << "The ";
            items[onAgain].showShortName();
            cout << fixed << " is $" << setprecision(2) << prices[onAgain];
            if (items[onAgain].getShortName() != bagChoices[onAgain])
                lost = true;
            else
            {
            /// Player guesses correctly.
            goOn = 'A';
            winnings *= 2;
            cout << endl << "You have $" << winnings << ".";
            while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
            cout << endl << "Do you want to go on (Y) or stop now (N)?: ";
            cin >> goOn;
            } /// end while loop
            if ( (goOn == 'N') || (goOn == 'n') )
                bail = true;
            else
            { /// Moving on to the fourth bag.
            onAgain++;
            cout << endl << "For $" << setprecision(0) << (pow(2, onAgain)*1000);
            cout << fixed << ", let's see what is $" << setprecision(2) << prices[onAgain] << endl;
            system("pause");
            cout << endl << "The ";
            items[onAgain].showShortName();
            cout << fixed << " is $" << setprecision(2) << prices[onAgain];
            if (items[onAgain].getShortName() != bagChoices[onAgain])
                lost = true;
            else
            { /// Player guesses correctly.
            goOn = 'A';
            winnings *= 2;
            cout << endl << "You have $" << winnings << ".";
            while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
            cout << endl << "Do you want to go on (Y) or stop now (N)?: ";
            cin >> goOn;
            } /// end while loop
            if ( (goOn == 'N') || (goOn == 'n') )
                bail = true;
            else
            { /// Moving on the fifth bag.
            onAgain++;
            cout << endl << "For $" << setprecision(0) << (pow(2, onAgain)*1000);
            cout << fixed << ", let's see what is $" << setprecision(2) << prices[onAgain] << endl;
            system("pause");
            cout << endl << "The ";
            items[onAgain].showShortName();
            cout << fixed << " is $" << setprecision(2) << prices[onAgain];
            if (items[onAgain].getShortName() != bagChoices[onAgain])
                lost = true;
            else
                wonBig = true;
            }

        } /// end else statement comparing the fourth price

        } /// Moving on to the fourth prize -- END.

        } /// end else statement comparing the third prize

        } /// Moving on to the third prize -- END.

        } /// end else statement comparing the second prize

        } /// Moving on to the second prize -- END.

        } /// end else statement comparing the first prize


    }

    if (lost)
        cout << endl << "Sorry, you lose.";
    if (bail)
        cout << endl << "You're walking away with $" << winnings << ". Thanks for playing!";
    if (wonBig)
    {
        winnings = 16000;
        cout << endl << "Congratulations, you won $16,000!";
    }


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Let 'Em Roll
void playLetEmRoll()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ((inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice > 1.00))
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
   inFile.close();

    cout << "LET 'EM ROLL" << endl;


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
    grocery items[3];
    int rolls = 1;

    int dice[5];

    /// Set each item
    for (int grocCount = 0; grocCount < 3; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
    }

    for (int y = 0; y < 3; y++)
    {
        cout << y+1 << ". ";
        items[y].showPrize();
        cout << endl;
    }

    char choice = 'A';
    cout << endl << "The actual retail price of the ";
    items[0].showShortName();
    cout << " is ";
    items[0].showARP();
    while ( (choice != 'H') && (choice != 'L') && (choice != 'h') && (choice != 'l') ){
    cout << endl << "Is the price of the ";
    items[1].showShortName();
    cout << " higher (H) or lower (L)?: ";
    cin >> choice;
    }
    cout << endl << "The actual retail price of the ";
    items[1].showShortName();
    cout << " is ";
    items[1].showARP();
    if ((choice == 'H') || (choice == 'h'))
    {
    if (items[1].getPrice() >= items[0].getPrice())
    {
        cout << endl << "That's correct! You win another roll.";
        rolls += 1;
    }
    else
        cout << endl << "Sorry, that's not correct.";
    } /// end HIGHER
    else
    {
    if (items[1].getPrice() <= items[0].getPrice())
    {
        cout << endl << "That's correct! You win another roll.";
        rolls += 1;
    }
    else
        cout << endl << "Sorry, that's not correct.";
    } /// end LOWER

    ///
    cout << endl;

    choice = 'A';
    cout << endl << "The actual retail price of the ";
    items[1].showShortName();
    cout << " is ";
    items[1].showARP();
   while ( (choice != 'H') && (choice != 'L') && (choice != 'h') && (choice != 'l') ){
    cout << endl << "Is the price of the ";
    items[2].showShortName();
    cout << " higher (H) or lower (L)?: ";
    cin >> choice;
    }
    cout << endl << "The actual retail price of the ";
    items[2].showShortName();
    cout << " is ";
    items[2].showARP();
    if ((choice == 'H') || (choice == 'h'))
    {
    if (items[2].getPrice() >= items[1].getPrice())
    {
        cout << endl << "That's correct! You win another roll.";
        rolls += 1;
    }
    else
        cout << endl << "Sorry, that's not correct.";
    } /// end HIGHER
    else
    {
    if (items[2].getPrice() <= items[1].getPrice())
    {
        cout << endl << "That's correct! You win another roll.";
        rolls += 1;
    }
    else
        cout << endl << "Sorry, that's not correct.";
    } /// end LOWER

    cout << endl;

    int cars = 0;
    int tempCars = 0;
    int money = 0;

    bool won = false;
    bool bail = false;

    if (rolls == 1)
        cout << endl << "You have 1 roll.";
    else
        cout << endl << "You have " << rolls << " rolls.";

    while ( (rolls > 0) && (!won) && (!bail) ){
    cout << endl << "Rolls left: " << rolls;
    cout << endl << "Let's roll the dice..." << endl;
    system("pause");

    for (int w = 0; w < 5-cars; w++){
        dice[w] = rand() % 6;
        if (dice[w] <= 2){
        money += (dice[w]+1)*500;
        cout << "$" << (dice[w]+1)*500 << endl;
        }
        else{
        tempCars += 1;
        cout << "CAR" << endl;
        }
        }

    if (tempCars == 5)
        won = true;
    else if (tempCars+cars == 5)
        won = true;
    else{
        if (rolls > 1){
        cout << endl << "You have " << tempCars+cars << " car(s) and $" << money << ".";
        char toDo = 'A';
        while ( (toDo != 'Y') && (toDo != 'N') && (toDo != 'y') && (toDo != 'n') ){
        cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
        cin >> toDo;
        }
        if ((toDo == 'N') || (toDo == 'n'))
            bail = true;
        else
        {
            cars += tempCars;
            tempCars = 0;
            money = 0;
            rolls -= 1;
        }
    }
    else
        rolls -= 1;
    }

    } /// end while loop

    if (won)
        cout << endl << "Congratulations, you won!";
    else
        cout << endl << "You won $" << money << ". Thanks for playing!";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Now... or Then
void playNowOrThen()
{
    /// "NOW" grocery items.
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    /// "THEN" grocery items.
    list<grocery> thenItems;
    list<grocery>::iterator thenItemsIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    string thenDescr;
    string thenShort;
    double thenPrice;
    grocery * tptr;


    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ((inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice))
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    int month = rand() % 5;

    if (month == 0)      /// APR 2008
        inFile.open("./prizes/groceryapr2008.txt");
    else if (month == 1) /// FEB 2007
        inFile.open("./prizes/groceryfeb2007.txt");
    else if (month == 2) /// JUNE 2009
        inFile.open("./prizes/groceryjun2009.txt");
    else if (month == 3) /// MARCH 2010
        inFile.open("./prizes/grocerymar2010.txt");
    else                 /// MAY 2006
        inFile.open("./prizes/grocerymay2006.txt");
    while (inFile){
    tptr = new grocery;
    if (inFile >> thenDescr >> thenShort >> thenPrice)
    {
        tptr->setDescription(thenDescr);
        tptr->setShortName(thenShort);
        tptr->setPrice(thenPrice);
        thenItems.push_back(*tptr);
        j++;
    }
    } /// end while loop

    cout << "NOW... OR THEN";

    int firstThen = (rand() % 6) + 1;
    int secondThen = firstThen;
    while (secondThen == firstThen)
        secondThen = (rand() % 6) + 1;

    grocery items[6];

    bool initialized[6];
    for (int b = 0; b < 6; b++)
        initialized[b] = false;

    int isNowOrThen[6]; /// will be 0 if NOW, 1 if THEN

    grocery tItem1;
    grocery tItem2;

    int id1 = rand() % j;
    int id2 = id1;
    while (id2 == id1)
        id2 = rand() % j;

    thenItemsIt = thenItems.begin();
    for (int z = 0; z < id1; z++)
        thenItemsIt++;
    tItem1.setDescription(thenItemsIt->getDescription());
    tItem1.setShortName(thenItemsIt->getShortName());
    tItem1.setPrice(thenItemsIt->getPrice());

    initialized[firstThen-1] = true;
    isNowOrThen[firstThen-1] = 1;
    items[firstThen-1].setDescription(tItem1.getDescription());
    items[firstThen-1].setShortName(tItem1.getShortName());
    items[firstThen-1].setPrice(tItem1.getPrice());

    thenItemsIt = thenItems.begin();
    for (int z2 = 0; z2 < id2; z2++)
        thenItemsIt++;
    tItem2.setDescription(thenItemsIt->getDescription());
    tItem2.setShortName(thenItemsIt->getShortName());
    tItem2.setPrice(thenItemsIt->getPrice());

    initialized[secondThen-1] = true;
    isNowOrThen[secondThen-1] = 1;
    items[secondThen-1].setDescription(tItem2.getDescription());
    items[secondThen-1].setShortName(tItem2.getShortName());
    items[secondThen-1].setPrice(tItem2.getPrice());

    string firstDec = items[firstThen-1].getShortName();
    string secondDec = items[secondThen-1].getShortName();

    int now1;
    int now2;
    int now3;
    int now4;
    int now5;
    int now6;

    /// Item #1
    bool setFirst = false;
    while (!setFirst)
    {
        if (initialized[0])
            setFirst = true;
        else
        {
        now1 = rand() % i;
        ggItemIt = ggItems.begin();
        for (int z3 = 0; z3 < now1; z3++)
            ggItemIt++;
        if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[0].setDescription(ggItemIt->getDescription());
            items[0].setShortName(ggItemIt->getShortName());
            items[0].setPrice(ggItemIt->getPrice());
            isNowOrThen[0] = 0;
            initialized[0] = true;
            setFirst = true;
        } // end if
        } // end else
    } // end while loop setting first item

    /// Item #2
    bool setSecond = false;
    while (!setSecond)
    {
        if (initialized[1])
            setSecond = true;
        else
        {
            now2 = rand() % i;
            while (now2 == now1)
                now2 = rand() % i;
            ggItemIt = ggItems.begin();
            for (int z4 = 0; z4 < now2; z4++)
                ggItemIt++;
        if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[1].setDescription(ggItemIt->getDescription());
            items[1].setShortName(ggItemIt->getShortName());
            items[1].setPrice(ggItemIt->getPrice());
            isNowOrThen[1] = 0;
            initialized[1] = true;
            setSecond = true;
        } // end if
        } // end else
    } // end while loop setting second item

    /// Item #3
    bool setThird = false;
    while (!setThird)
    {
        if (initialized[2])
            setThird = true;
        else
        {
            now3 = rand() % i;
            while ( (now3 == now1) || (now3 == now2) )
                now3 = rand() % i;
            ggItemIt = ggItems.begin();
            for (int z5 = 0; z5 < now3; z5++)
                ggItemIt++;
            if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[2].setDescription(ggItemIt->getDescription());
            items[2].setShortName(ggItemIt->getShortName());
            items[2].setPrice(ggItemIt->getPrice());
            isNowOrThen[2] = 0;
            initialized[2] = true;
            setThird = true;
            } // end if
        } // end else
    } // end while loop setting third item

    /// Item #4
    bool setFourth = false;
    while (!setFourth)
    {
        if (initialized[3])
            setFourth = true;
        else
        {
            now4 = rand() % i;
            while ( (now4 == now1) || (now4 == now2) || (now4 == now3) )
                now4 = rand() % i;
            ggItemIt = ggItems.begin();
            for (int z6 = 0; z6 < now4; z6++)
                ggItemIt++;
            if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[3].setDescription(ggItemIt->getDescription());
            items[3].setShortName(ggItemIt->getShortName());
            items[3].setPrice(ggItemIt->getPrice());
            isNowOrThen[3] = 0;
            initialized[3] = true;
            setFourth = true;
            } // end if
        } // end else
    } // end while loop setting fourth item

    /// Item #5
    bool setFifth = false;
    while (!setFifth)
    {
        if (initialized[4])
            setFifth = true;
        else
        {
            now5 = rand() % i;
            while ( (now5 == now1) || (now5 == now2) || (now5 == now3) || (now5 == now4) )
                now5 = rand() % i;
            ggItemIt = ggItems.begin();
            for (int z7 = 0; z7 < now5; z7++)
                ggItemIt++;
            if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[4].setDescription(ggItemIt->getDescription());
            items[4].setShortName(ggItemIt->getShortName());
            items[4].setPrice(ggItemIt->getPrice());
            isNowOrThen[4] = 0;
            initialized[4] = true;
            setFifth = true;
            } // end if
        } // end else
    } // end while loop setting fifth item

    /// Item #6
    bool setSixth = false;
    while (!setSixth)
    {
        if (initialized[5])
            setSixth = true;
        else
        {
            now6 = rand() % i;
            while ( (now6 == now1) || (now6 == now2) || (now6 == now3) || (now6 == now4) || (now6 == now5) )
                now6 = rand() % i;
            ggItemIt = ggItems.begin();
            for (int z8 = 0; z8 < now6; z8++)
                ggItemIt++;
            if ( (ggItemIt->getShortName() != firstDec) && (ggItemIt->getShortName() != secondDec) ){
            items[5].setDescription(ggItemIt->getDescription());
            items[5].setShortName(ggItemIt->getShortName());
            items[5].setPrice(ggItemIt->getPrice());
            isNowOrThen[5] = 0;
            initialized[5] = true;
            setSixth = true;
            } // end if
        } // end else
    } // end while loop setting sixth item

    bool picked[6];
    int status[6]; /// 0 = not picked, 1 = guessed correctly, 2 = guessed incorrectly
    for (int k = 0; k < 6; k++){
        picked[k] = false;
        status[k] = 0;
    }

    bool won = false;
    bool lost = false;
    int wrongs = 0;
    int rights = 0;

    cout << endl << "THEN: ";
    if (month == 0)
        cout << "APRIL 2008";
    else if (month == 1)
        cout << "FEBRUARY 2007";
    else if (month == 2)
        cout << "JUNE 2009";
    else if (month == 3)
        cout << "MARCH 2010";
    else
        cout << "MAY 2006";

    cout << endl;

    while (!won && !lost){
    for (int m = 0; m < 6; m++)
    {
        cout << m+1 << ". ";
        items[m].showPrize();
        cout << " - ";
        items[m].showARP();
//        if (status[m] == 1)
//            cout << " O ";
//        else if (status[m] == 2)
//            cout << " X ";
        cout << endl;
    }
    if (status[1] == 1)
        cout << "  O";
    else if (status[1] == 2)
        cout << "  X";
    else
        cout << "  2";
    if (status[0] == 1)
        cout << endl << "O";
    else if (status[0] == 2)
        cout << endl << "X";
    else
        cout << endl << "1";
    if (status[2] == 1)
        cout << "   O";
    else if (status[2] == 2)
        cout << "   X";
    else
        cout << "   3";
///
    if (status[3] == 1)
        cout << endl << "O";
    else if (status[3] == 2)
        cout << endl << "X";
    else
        cout << endl << "4";
    if (status[5] == 1)
        cout << "   O";
    else if (status[5] == 2)
        cout << "   X";
    else
        cout << "   6";
///
    if (status[4] == 1)
        cout << endl << "  O";
    else if (status[4] == 2)
        cout << endl << "  X";
    else
        cout << endl << "  5";

    int itemChoice = 0;
    while ( (itemChoice < 1) || (itemChoice > 6) ){
        cout << endl << "Which item (enter its number) do you want to pick?: ";
        cin >> itemChoice;
    }
    if (picked[itemChoice-1])
        cout << endl << "You've already chosen this item. Please choose another one.";
    else
    {
        char dateChoice = 'A';
        while ( (dateChoice != 'N') && (dateChoice != 'T') &&  (dateChoice != 'n') && (dateChoice != 't') ){
        cout << endl << "Is ";
        items[itemChoice-1].showARP();
        cout << " the NOW price (N) or the THEN price (T)?: ";
        cin >> dateChoice;
        }
        if ( (dateChoice == 'N') || (dateChoice == 'n') ){
            picked[itemChoice-1] = true;
            if (isNowOrThen[itemChoice-1] == 0){
                cout << endl << "NOW";
                cout << endl << "Yes, that's correct!";
                status[itemChoice-1] = 1;
                rights += 1;
            }
            else{
                cout << endl << "THEN";
                cout << endl << "Sorry, that's not correct.";
                status[itemChoice-1] = 2;
                wrongs += 1;
            }
        }
        else{
            picked[itemChoice-1] = true;
            if (isNowOrThen[itemChoice-1] == 1){
                cout << endl << "THEN";
                cout << endl << "Yes, that's correct!";
                status[itemChoice-1] = 1;
                rights += 1;
            }
            else{
                cout << endl << "NOW";
                cout << endl << "Sorry, that's not correct.";
                status[itemChoice-1] = 2;
                wrongs += 0;
            }
        }

    cout << endl << endl;

    /// Check if the player has won or lost.

    /// 3 in a row
    if ( ( (status[0] == 1) && (status[1] == 1) && (status[2] == 1) ) ||
         ( (status[0] == 1) && (status[1] == 1) && (status[3] == 1) ) ||
         ( (status[0] == 1) && (status[3] == 1) && (status[4] == 1) ) ||
         ( (status[3] == 1) && (status[4] == 1) && (status[5] == 1) ) ||
         ( (status[2] == 1) && (status[4] == 1) && (status[5] == 1) ) ||
         ( (status[1] == 1) && (status[2] == 1) && (status[5] == 1) ) )
        won = true;
    /// If at least 4 are wrong, there's no way to get 3 in a row.
    else if (wrongs >= 4)
        lost = true;
    /// If a right answer is surrounded by two wrong answers, and another answer is wrong, there's no way to get 3 in a row.
    else if ( ( (status[0] == 2) && (status[1] == 1) && (status[3] == 2) && (wrongs >= 3) ) ||
              ( (status[0] == 1) && (status[1] == 2) && (status[3] == 2) && (wrongs >= 3) ) ||
              ( (status[0] == 2) && (status[3] == 1) && (status[4] == 2) && (wrongs >= 3) ) ||
              ( (status[3] == 2) && (status[4] == 1) && (status[5] == 2) && (wrongs >= 3) ) ||
              ( (status[2] == 2) && (status[4] == 2) && (status[5] == 1) && (wrongs >= 3) ) ||
              ( (status[1] == 2) && (status[2] == 1) && (status[5] == 2) && (wrongs >= 3) ) )
        lost = true;

    } // end else

    } // end while

    if (won)
        cout << endl << "Congratulations, you win!";
    else if (lost)
        cout << endl << "Sorry, you lose.";

    /*
    cout << endl;
    items[0].showPrize();
    cout << endl;
    items[1].showPrize();
    cout << endl;
    items[2].showPrize();
    cout << endl;
    items[3].showPrize();
    cout << endl;
    items[4].showPrize();
    cout << endl;
    items[5].showPrize();
    */


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Pass the Buck
void playPassTheBuck()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ((inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice > 1.00))
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
   inFile.close();

    cout << "PASS THE BUCK" << endl;


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
    grocery items[4];

    int passDir[2];
    for (int y = 0; y < 2; y++)
        passDir[y] = rand() % 2;

    /// the 10000 space equals the car, and the 0 spaces equal "LOSE EVERYTHING"
    int board[6] = {1000, 3000, 5000, 10000, 0, 0};
    random_shuffle(&board[0], &board[6]);
    bool chosen[6];
    for (int x = 0; x < 6; x++)
        chosen[x] = false;

    int picks = 1;

    /// Set each item, this time using a for loop:
    for (int grocCount = 0; grocCount < 4; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
    }


    //cout << "direction = " << passDir[0]+1 << endl;
    int choice = 0;

    cout << "Picks = " << picks << endl;
    if (passDir[0] == 0){
    cout << "1. ";
    items[0].showPrize();
    cout << fixed << " - $" << setprecision(2) << (items[0].getPrice()-1) << endl;
    cout << "2. ";
    items[1].showPrize();
    cout << " - ";
    items[1].showARP();
    cout << endl;
    }
    else
    {
    cout << "1. ";
    items[0].showPrize();
    cout << " - ";
    items[0].showARP();
    cout << endl << "2. ";
    items[1].showPrize();
    cout << fixed << " - $" << setprecision(2) << (items[1].getPrice()-1) << endl;
    }
    while ( (choice < 1) || (choice > 2) ){
        cout << endl << "Which price should be $1 more?: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        cout << "The actual retail price of the ";
        items[0].showShortName();
        cout << " is ";
        items[0].showARP();
    }
    else
    {
        cout << "The actual retail price of the ";
        items[1].showShortName();
        cout << " is ";
        items[1].showARP();
    }

    if ( (choice-1) == passDir[0] ){
        cout << endl << "That's correct! You earn another pick.";
        picks += 1;
        }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl << endl;
    choice = 0;

    cout << "Picks = " << picks << endl;

    if (passDir[1] == 0)
    {
    cout << "1. ";
    items[2].showPrize();
    cout << fixed << " - $" << setprecision(2) << (items[2].getPrice()-1) << endl;
    cout << "2. ";
    items[3].showPrize();
    cout << " - ";
    items[3].showARP();
    cout << endl;
    }
    else
    {
    cout << "1. ";
    items[2].showPrize();
    cout << " - ";
    items[2].showARP();
    cout << endl << "2. ";
    items[3].showPrize();
    cout << fixed << " - $" << setprecision(2) << (items[3].getPrice()-1) << endl;
    }
    while ( (choice < 1) || (choice > 2) ){
        cout << endl << "Which price should be $1 more?: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        cout << "The actual retail price of the ";
        items[2].showShortName();
        cout << " is ";
        items[2].showARP();
    }
    else
    {
        cout << "The actual retail price of the ";
        items[3].showShortName();
        cout << " is ";
        items[3].showARP();
    }

    if ( (choice-1) == passDir[1] ){
        cout << endl << "That's correct! You earn another pick.";
        picks += 1;
        }
    else
        cout << endl << "Sorry, that's not correct.";

    cout << endl << endl;

    bool quit = false;
    bool won = false;
    random_shuffle(&board[0], &board[6]);

    int winnings = 0;

    while ( (picks > 0) && (!quit) && (!won) ){
    for (int w = 0; w < 6; w++)
    {
    cout << w+1 << ". ";
    if (chosen[w] == false)
        cout << "Not chosen";
    else
    {
        if (board[w] == 0)
            cout << "LOSE EVERYTHING";
        else if (board[w] == 10000)
            cout << "CAR";
        else
            cout << "$" << board[w];
    }
    cout << endl;
    } /// end for loop
    int panelPick = 0;
    while ((panelPick < 1) || (panelPick > 6)){
        cout << endl << "Which number do you want to pick?: ";
        cin >> panelPick;
        }
    if (chosen[panelPick-1] == true)
        cout << endl << "You've already chosen this panel. Please pick another." << endl;
    else{
    chosen[panelPick-1] = true;
    cout << endl << "Behind panel #" << panelPick << " is...";
    if (board[panelPick-1] == 0) /// LOSE EVERYTHING
    {
        winnings = 0;
        cout << "LOSE EVERYTHING";
        cout << endl;
    }
    else if (board[panelPick-1] == 10000) /// Won the car
    {
        cout << "The car!";
        won = true;
    }
    else /// Dollar amount
    {
        winnings += board[panelPick-1];
        cout << "$" << board[panelPick-1];
        cout << endl;
        if (picks > 1){
        char goOn = 'A';
        cout << "You have $" << winnings << " now." << endl;
        while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
        cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
        cin >> goOn;
        }
        if ( (goOn == 'N') || (goOn == 'n') )
            quit = true;
        }
    }

    picks -= 1;
    }
    } /// end while loop

    if ((won) && (winnings > 0))
        cout << endl << "Congratulations, you won the car and $" << winnings << "!";
    else if ( (won) && (winnings == 0) )
        cout << endl << "Congratulations, you won!";
    else if ( (!won) && (winnings > 0) )
        cout << endl << "You won $" << winnings << ". Thanks for playing!";
    else if ( (!won) && (winnings == 0) )
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Pay the Rent
void playPayTheRent()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice < 16) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop

    cout << "PAY THE RENT" << endl;

    grocery temps[6];
    grocery items[6];

    int ids[6] = {0, 1, 2, 3, 4, 5};
    random_shuffle(&ids[0], &ids[6]);

    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;

    bool setup = false;

    while (!setup){

    double safeSet = 0;
    double floor2Set = 0;
    double floor1Set = 0;
    double mailboxSet = 0;

    /// Initialize the random variables.
    first = rand() % i;
    second = first;
    while (second == first)
        second = rand() % i;
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    sixth = first;
    while ( (sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % i;

    /// Set the item in the mailbox.
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first; z++)
        ggItemIt++;
    temps[0].setDescription(ggItemIt->getDescription());
    temps[0].setShortName(ggItemIt->getShortName());
    temps[0].setPrice(ggItemIt->getPrice());

    /// Set the items that go on floor 1.
    ggItemIt = ggItems.begin();
    for (int z = 0; z < second; z++)
        ggItemIt++;
    temps[1].setDescription(ggItemIt->getDescription());
    temps[1].setShortName(ggItemIt->getShortName());
    temps[1].setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z = 0; z < third; z++)
        ggItemIt++;
    temps[2].setDescription(ggItemIt->getDescription());
    temps[2].setShortName(ggItemIt->getShortName());
    temps[2].setPrice(ggItemIt->getPrice());

    /// Set the items that go on floor 2.
    ggItemIt = ggItems.begin();
    for (int z = 0; z < fourth; z++)
        ggItemIt++;
    temps[3].setDescription(ggItemIt->getDescription());
    temps[3].setShortName(ggItemIt->getShortName());
    temps[3].setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z = 0; z < fifth; z++)
        ggItemIt++;
    temps[4].setDescription(ggItemIt->getDescription());
    temps[4].setShortName(ggItemIt->getShortName());
    temps[4].setPrice(ggItemIt->getPrice());

    /// Set the item that goes in the safe.
    ggItemIt = ggItems.begin();
    for (int z = 0; z < sixth; z++)
        ggItemIt++;
    temps[5].setDescription(ggItemIt->getDescription());
    temps[5].setShortName(ggItemIt->getShortName());
    temps[5].setPrice(ggItemIt->getPrice());

    mailboxSet = temps[0].getPrice();
    floor1Set = temps[1].getPrice() + temps[2].getPrice();
    floor2Set = temps[3].getPrice() + temps[4].getPrice();
    safeSet = temps[5].getPrice();

    if ( ( (safeSet > floor2Set) && (floor2Set > floor1Set) && (floor1Set > mailboxSet) && ((safeSet-floor2Set) < 5) )
        && (temps[0].getPrice() != temps[1].getPrice()) && (temps[0].getPrice() != temps[2].getPrice()) && (temps[0].getPrice() != temps[3].getPrice())
        && (temps[0].getPrice() != temps[4].getPrice()) && (temps[0].getPrice() != temps[5].getPrice()) && (temps[1].getPrice() != temps[2].getPrice())
        && (temps[1].getPrice() != temps[3].getPrice()) && (temps[1].getPrice() != temps[4].getPrice()) && (temps[1].getPrice() != temps[5].getPrice())
        && (temps[2].getPrice() != temps[3].getPrice()) && (temps[2].getPrice() != temps[4].getPrice()) && (temps[2].getPrice() != temps[5].getPrice())
        && (temps[3].getPrice() != temps[4].getPrice()) && (temps[3].getPrice() != temps[5].getPrice()) && (temps[4].getPrice() != temps[5].getPrice()) )
        setup = true;

    } // end while loop setting the gameplay up

    /// Set up the actual items.
    for (int q = 0; q < 6; q++){
        items[q].setDescription(temps[ids[q]].getDescription());
        items[q].setShortName(temps[ids[q]].getShortName());
        items[q].setPrice(temps[ids[q]].getPrice());
    }

    bool chosen[6];
    bool setPos[6];

    for (int s = 0; s < 6; s++){
        chosen[s] = false;
        setPos[s] = false;
    }

    double mailbox;
    double floor1;
    double floor2;
    double attic;

    grocery placement[6];

    for (int on = 0; on < 6; on++){

    /// Show the house
    cout << endl << "Attic: *";

    cout << endl << "Floor 2: ";
    if (setPos[3])
        placement[3].showShortName();
    else
        cout << "*";
    cout << ", ";
    if (setPos[4])
        placement[4].showShortName();
    else
        cout << "*";

    cout << endl << "Floor 1: ";
    if (setPos[1])
        placement[1].showShortName();
    else
        cout << "*";
    cout << ", ";
    if (setPos[2])
        placement[2].showShortName();
    else
        cout << "*";

    cout << endl << "Mailbox: ";
    if (setPos[0])
        placement[0].showShortName();
    else
        cout << "*";


    /// Show items
    for (int r = 0; r < 6; r++){
        cout << endl << r+1 << ". ";
        items[r].showPrize();
        if (chosen[r])
            cout << " - O";
    }

    int choice = 0;
    while ( (choice < 1) || (choice > 6) ){

    if (on == 0)
        cout << endl << "What item goes in the mailbox?: ";
    else if (on == 1)
        cout << endl << "What item goes on the couch on floor 1?: ";
    else if (on == 2)
        cout << endl << "What item goes on the stove on floor 1?: ";
    else if (on == 3)
        cout << endl << "What item goes on the TV on floor 2?: ";
    else if (on == 4)
        cout << endl << "What item goes on the tub on floor 2?: ";
    else
        cout << endl << "What item goes in the safe in the attic?: ";

    cin >> choice;
    if (chosen[choice-1]){
        cout << endl << "You've already chosen this item. Please pick another one.";
        choice = 0;
        }
    } // end entry while loop

    if (!chosen[choice-1]){
    chosen[choice-1] = true;
    setPos[on] = true;
    placement[on].setShortName(items[choice-1].getShortName());
    placement[on].setPrice(items[choice-1].getPrice());
    }

    } // end for loop

    mailbox = placement[0].getPrice();
    floor1 = placement[1].getPrice() + placement[2].getPrice();
    floor2 = placement[3].getPrice() + placement[4].getPrice();
    attic = placement[5].getPrice();

    cout << endl << "Attic: ";
    placement[5].showShortName();
    cout << endl << "Floor 2: ";
    placement[3].showShortName();
    cout << ", ";
    placement[4].showShortName();
    cout << endl << "Floor 1: ";
    placement[1].showShortName();
    cout << ", ";
    placement[2].showShortName();
    cout << endl << "Mailbox: ";
    placement[0].showShortName();

    bool bail = false;
    cout << endl << "Let's see how you did.";
    cout << endl;
    system("pause");
    cout << endl << "The actual retail price of the ";
    placement[0].showShortName();
    cout << " is ";
    placement[0].showARP();
    cout << endl << "You've won $1000.";
    char bc1 = '!';
    while ( (bc1 != 'Y') && (bc1 != 'N') && (bc1 != 'y') && (bc1 != 'n') ){
        cout << endl << "Do you want to keep $1000 (Y) or risk it for $5000 (N)?: ";
        cin >> bc1;
    }
    if ( (bc1 == 'Y') || (bc1 == 'y') )
        cout << endl << "You're walking away with $1000. Thanks for playing!";
    else
    {
        cout << endl << "On to the first floor...";
        cout << endl << "The actual retail price of the ";
        placement[1].showShortName();
        cout << " is ";
        placement[1].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        placement[2].showShortName();
        cout << " is ";
        placement[2].showARP();
        cout << endl;
        system("pause");
        cout << endl << fixed << setprecision(2) << "For a total of $" << floor1;
        if (floor1 < mailbox)
            cout << endl << "Sorry, you lose.";
        else{
            cout << endl << "You now have $5000.";
            char bc2 = '!';
            while ( (bc2 != 'Y') && (bc2 != 'N') && (bc2 != 'y') && (bc2 != 'n') ){
            cout << endl << "Do you want to keep $5000 (Y) or risk it for $10000 (N)?: ";
            cin >> bc2;
            }
            if ( (bc2 == 'Y') || (bc2 == 'y') )
                cout << endl << "You're walking away with $5000. Thanks for playing!";
            else{
            cout << endl << "On to the second floor...";
            cout << endl << "The actual retail price of the ";
            placement[3].showShortName();
            cout << " is ";
            placement[3].showARP();
            cout << endl;
            system("pause");
            cout << endl << "The actual retail price of the ";
            placement[4].showShortName();
            cout << " is ";
            placement[4].showARP();
            cout << endl;
            system("pause");
            cout << endl << fixed << setprecision(2) << "For a total of $" << floor2;
            if (floor2 < floor1)
                cout << endl << "Sorry, you lose.";
            else{
                cout << endl << "You now have $10000.";
                char bc3 = '!';
                while ( (bc3 != 'Y') && (bc3 != 'N') && (bc3 != 'y') && (bc3 != 'n') ){
                cout << endl << "Do you want to keep $10000 (Y) or risk it for $100000 (N)?: ";
                cin >> bc3;
                }
                if ( (bc3 == 'Y') || (bc3 == 'y') )
                    cout << endl << "You're walking away with $10000. Thanks for playing!";
                else{
                cout << endl << "On to the attic...";
                cout << endl << "The actual retail price of the ";
                placement[5].showShortName();
                cout << " is ";
                placement[5].showARP();
                cout << endl;
                if (attic > floor2)
                    cout << endl << "Congratulations, you won $100000!";
                else
                    cout << endl << "Sorry, you lose.";
                } // end if player continued on to attic

            } // end else statement if second floor's total is more than first floor's

            } // end if player continued on to second floor

        } // end else statement if first floor's total is more than the mailbox
    } // end if player continued on to first floor


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Penny Ante
void playPennyAnte()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ((inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice < 10.00))
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "PENNY ANTE" << endl;

    grocery item1;
    grocery item2;

    /// Pick two grocery items
    int firstID = rand() % i;
    int secondID = firstID;
    while (secondID == firstID)
        secondID = rand() % i;

    ggItemIt = ggItems.begin();
    for (int z = 0; z < firstID; z++)
        ggItemIt++;
    item1.setDescription(ggItemIt->getDescription());
    item1.setShortName(ggItemIt->getShortName());
    item1.setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z2 = 0; z2 < secondID; z2++)
        ggItemIt++;
    item2.setDescription(ggItemIt->getDescription());
    item2.setShortName(ggItemIt->getShortName());
    item2.setPrice(ggItemIt->getPrice());

    /// Determines which number each correct price will be.
    int price1Loc = rand() % 4;
    int price2Loc = rand() % 4;

    double choicesP1[4];
    double choicesP2[4];

    int temp; // temporarily holds a random number
    int flag1; // determines if the price should be slightly modified
    int flag2; // determines if flag1's value should be added or subtracted

    double tempAP1 = item1.getPrice();
    while (tempAP1 == item1.getPrice()){
        if (item1.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP1 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP1 -= 0.20;
        }
        else if ( (item1.getPrice() > 3.5) && (item1.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP1 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP1 -= 0.40;
        }
    } /// end while loop seting tempAP1

    double tempBP1 = item1.getPrice();
    while ( (tempBP1 == item1.getPrice()) || (tempBP1 == tempAP1) ){
        if (item1.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP1 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP1 -= 0.20;
        }
        else if ( (item1.getPrice() > 3.5) && (item1.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP1 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP1 -= 0.40;
        }
    } /// end while loop seting tempBP1

    double tempCP1 = item1.getPrice();
    while ( (tempCP1 == item1.getPrice()) || (tempCP1 == tempAP1) || (tempCP1 == tempBP1) ){
        if (item1.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP1 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP1 -= 0.20;
        }
        else if ( (item1.getPrice() > 3.5) && (item1.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP1 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP1 -= 0.40;
        }
    } /// end while loop seting tempCP1

    double tempAP2 = item2.getPrice();
    while (tempAP2 == item2.getPrice()){
        if (item2.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP2 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP2 -= 0.20;
        }
        else if ( (item2.getPrice() > 3.5) && (item2.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP2 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempAP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempAP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempAP2 -= 0.40;
        }
    } /// end while loop seting tempAP2


    double tempBP2 = item2.getPrice();
    while ( (tempBP2 == item2.getPrice()) || (tempBP2 == tempAP2) ){
        if (item2.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP2 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP2 -= 0.20;
        }
        else if ( (item2.getPrice() > 3.5) && (item2.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP2 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempBP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempBP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempBP2 -= 0.40;
        }
    } /// end while loop seting tempBP1


    double tempCP2 = item2.getPrice();
    while ( (tempCP2 == item2.getPrice()) || (tempCP2 == tempAP2) || (tempCP2 == tempBP2) ){
        if (item2.getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP2 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP2 -= 0.20;
        }
        else if ( (item2.getPrice() > 3.5) && (item2.getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP2 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        tempCP2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            tempCP2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            tempCP2 -= 0.40;
        }
    } /// end while loop seting tempCP2

    /// Programmer's note: I probably should have used random_shuffle here, but oh well. What's done is done.
    /// It might be a good idea to use that when you get around to To The Penny, though.

    /// Set prices for item 1
    if (price1Loc == 0){
        choicesP1[0] = item1.getPrice();
        choicesP1[1] = tempAP1;
        choicesP1[2] = tempBP1;
        choicesP1[3] = tempCP1;
    }
    else if (price1Loc == 1){
        choicesP1[1] = item1.getPrice();
        choicesP1[0] = tempAP1;
        choicesP1[2] = tempBP1;
        choicesP1[3] = tempCP1;
    }
    else if (price1Loc == 2){
        choicesP1[2] = item1.getPrice();
        choicesP1[0] = tempAP1;
        choicesP1[1] = tempBP1;
        choicesP1[3] = tempCP1;
    }
    else{
        choicesP1[3] = item1.getPrice();
        choicesP1[0] = tempAP1;
        choicesP1[1] = tempBP1;
        choicesP1[2] = tempCP1;
    }

    /// Set prices for item 2
    if (price2Loc == 0){
        choicesP2[0] = item2.getPrice();
        choicesP2[1] = tempAP2;
        choicesP2[2] = tempBP2;
        choicesP2[3] = tempCP2;
    }
    else if (price2Loc == 1){
        choicesP2[1] = item2.getPrice();
        choicesP2[0] = tempAP2;
        choicesP2[2] = tempBP2;
        choicesP2[3] = tempCP2;
    }
    else if (price2Loc == 2){
        choicesP2[2] = item2.getPrice();
        choicesP2[0] = tempAP2;
        choicesP2[1] = tempBP2;
        choicesP2[3] = tempCP2;
    }
    else{
        choicesP2[3] = item2.getPrice();
        choicesP2[0] = tempAP2;
        choicesP2[1] = tempBP2;
        choicesP2[2] = tempCP2;
    }

    bool chosenP1[4];
    bool chosenP2[4];
    for (int c = 0; c < 4; c++){
        chosenP1[c] = false;
        chosenP2[c] = false;
        }

    int pennies = 3;
    bool wonFirst = false;
    bool wonSecond = false;

    while ( (!wonFirst) && (pennies > 0) ){
        cout << endl << "Pennies left: " << pennies;
        cout << endl;
        item1.showPrize();
        for (int a = 0; a < 4; a++){
        cout << endl << a+1 << ". $" << fixed << setprecision(2) << choicesP1[a];
        if (chosenP1[a])
            cout << " - X";
        }
        int choiceA = 0;
        while ( (choiceA < 1) || (choiceA > 4) ){
            cout << endl << "What is the price of the item?: ";
            cin >> choiceA;
        }

        if (chosenP1[choiceA-1])
            cout << endl << "You've already chosen this price. Please pick another." << endl;
        else{
        if (choicesP1[choiceA-1] == item1.getPrice()){
            cout << endl << "Yes, that's correct!" << endl;
            wonFirst = true;
        }
        else{
            cout << endl << "Sorry, that's not correct." << endl;
            chosenP1[choiceA-1] = true;
            pennies -= 1;
        }
        }
    } /// end while loop for first item

    while ( (wonFirst) && (!wonSecond) && (pennies > 0) ){
        cout << endl << "Pennies left: " << pennies;
        cout << endl;
        item2.showPrize();

        for (int b = 0; b < 4; b++){
        cout << endl << b+1 << ". $" << fixed << setprecision(2) << choicesP2[b];
        if (chosenP2[b])
            cout << " - X";
        }
        int choiceB = 0;

        while ( (choiceB < 1) || (choiceB > 4) ){
            cout << endl << "What is the price of the item?: ";
            cin >> choiceB;
        }

        if (chosenP2[choiceB-1])
            cout << endl << "You've already chosen this price. Please pick another." << endl;
        else{
        if (choicesP2[choiceB-1] == item2.getPrice()){
            cout << endl << "Yes, that's correct!" << endl;
            wonSecond = true;
        }
        else{
            cout << endl << "Sorry, that's not correct." << endl;
            chosenP2[choiceB-1] = true;
            pennies -= 1;
        }
        }

    } /// end while loop for second item

    if (wonSecond)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Pick-a-Pair
void playPickAPair()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice)
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop

    cout << "PICK-A-PAIR" << endl;
    grocery items[6];

    double firstPairPrice;
    double secondPairPrice;
    double thirdPairPrice;

    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;

    bool foundFirstPair = false;
    bool foundSecondPair = false;
    bool foundThirdPair = false;

    grocery tempItem1;
    grocery tempItem2;

    /// Generate the first pair of grocery items.
    while (!foundFirstPair){

    /// Pick two random grocery items by generating two integers. Ensure that the two integers are different.

    first = rand() % i;
    second = first;
    while (second == first)
        second = rand() % i;

    //cout << endl << first << ", " << second << endl;

    /// Use an iterator to find the two grocery items associated with each integer.
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first; z++)
        ggItemIt++;

    tempItem1.setDescription(ggItemIt->getDescription());
    tempItem1.setShortName(ggItemIt->getShortName());
    tempItem1.setPrice(ggItemIt->getPrice());

    //tempItem1.showPrize();
    //cout << endl;
    //tempItem1.showARP();

    ggItemIt = ggItems.begin();
    for (int z2 = 0; z2 < second; z2++)
        ggItemIt++;

    tempItem2.setDescription(ggItemIt->getDescription());
    tempItem2.setShortName(ggItemIt->getShortName());
    tempItem2.setPrice(ggItemIt->getPrice());

    //tempItem2.showPrize();
    //cout << endl;
    //tempItem2.showARP();

    /// Compare the two items' prices.
    if (tempItem1.getPrice() == tempItem2.getPrice())
    {
        firstPairPrice = tempItem1.getPrice();
        foundFirstPair = true;
        items[0].setDescription(tempItem1.getDescription());
        items[0].setShortName(tempItem1.getShortName());
        items[0].setPrice(tempItem1.getPrice());
        items[1].setDescription(tempItem2.getDescription());
        items[1].setShortName(tempItem2.getShortName());
        items[1].setPrice(tempItem2.getPrice());
    }

    } /// end while loop that sets the first pair of items

    /// Generate the second pair of grocery items.
    while (!foundSecondPair){
    third = first;

    while ((third == first) || (third == second))
        third = rand() % i;
    fourth = third;
    while ((fourth == first) || (fourth == second) || (fourth == third))
        third = rand() % i;

    ggItemIt = ggItems.begin();
    for (int z3 = 0; z3 < third; z3++)
        ggItemIt++;

    tempItem1.setDescription(ggItemIt->getDescription());
    tempItem1.setShortName(ggItemIt->getShortName());
    tempItem1.setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z4 = 0; z4 < fourth; z4++)
        ggItemIt++;

    tempItem2.setDescription(ggItemIt->getDescription());
    tempItem2.setShortName(ggItemIt->getShortName());
    tempItem2.setPrice(ggItemIt->getPrice());

    if ( (tempItem1.getPrice() == tempItem2.getPrice()) && (tempItem1.getPrice() != firstPairPrice) )
    {
        secondPairPrice = tempItem1.getPrice();
        foundSecondPair = true;
        items[2].setDescription(tempItem1.getDescription());
        items[2].setShortName(tempItem1.getShortName());
        items[2].setPrice(tempItem1.getPrice());
        items[3].setDescription(tempItem2.getDescription());
        items[3].setShortName(tempItem2.getShortName());
        items[3].setPrice(tempItem2.getPrice());
    }

    } /// end while loop that sets the second pair of items

    /// Generate the third pair of grocery items.
    while (!foundThirdPair){

    fifth = first;
    while ((fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;

    sixth = first;
    while ((sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % i;

    ggItemIt = ggItems.begin();
    for (int z5 = 0; z5 < fifth; z5++)
        ggItemIt++;

    tempItem1.setDescription(ggItemIt->getDescription());
    tempItem1.setShortName(ggItemIt->getShortName());
    tempItem1.setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z6 = 0; z6 < sixth; z6++)
        ggItemIt++;

    tempItem2.setDescription(ggItemIt->getDescription());
    tempItem2.setShortName(ggItemIt->getShortName());
    tempItem2.setPrice(ggItemIt->getPrice());

    if ( (tempItem1.getPrice() == tempItem2.getPrice()) && (tempItem1.getPrice() != firstPairPrice) &&  (tempItem1.getPrice() != secondPairPrice) )
    {
        thirdPairPrice = tempItem1.getPrice();
        foundThirdPair = true;
        items[4].setDescription(tempItem1.getDescription());
        items[4].setShortName(tempItem1.getShortName());
        items[4].setPrice(tempItem1.getPrice());
        items[5].setDescription(tempItem2.getDescription());
        items[5].setShortName(tempItem2.getShortName());
        items[5].setPrice(tempItem2.getPrice());
    }

    }

    /*
    cout << endl;
    items[0].showPrize();
    cout << " - ";
    items[0].showARP();
    cout << endl;
    items[1].showPrize();
    cout << " - ";
    items[1].showARP();
    cout << endl;
    items[2].showPrize();
    cout << " - ";
    items[2].showARP();
    cout << endl;
    items[3].showPrize();
    cout << " - ";
    items[3].showARP();
    cout << endl;
    items[4].showPrize();
    cout << " - ";
    items[4].showARP();
    cout << endl;
    items[5].showPrize();
    cout << " - ";
    items[5].showARP();
    */

    int ids[6] = {0, 1, 2, 3, 4, 5};
    random_shuffle(&ids[0], &ids[6]);

    bool picked[6];

    int choice1 = 0;
    int choice2 = 0;

    for (int w = 0; w < 6; w++){
        picked[w] = false;
        cout << w+1 << ". ";
        items[ids[w]].showPrize();
        cout << endl;
    }
    while ( (choice1 < 1) || (choice1 > 6) ){
        cout << endl << "Which item (enter its number) do you want to pick first?: ";
        cin >> choice1;
    }

    cout << endl << "The actual retail price of the ";
    items[ids[choice1-1]].showShortName();
    cout << " is ";
    items[ids[choice1-1]].showARP();
    while ( (choice2 < 1) || (choice2 > 6) || (choice2 == choice1) ){
        cout << endl << "Now, which item do you think has the same price?: ";
        cin >> choice2;
    }

    cout << endl << "The actual retail price of the ";
    items[ids[choice2-1]].showShortName();
    cout << " is ";
    items[ids[choice2-1]].showARP();

    if (items[ids[choice1-1]].getPrice() ==  items[ids[choice2-1]].getPrice())
        cout << endl << "Congratulations, you win!";
    else
    {
        cout << endl << "That's not correct, but you get a second chance.";
        int choice3 = 0;
        int choice4 = 0;
        cout << endl << "1. ";
        items[ids[choice1-1]].showPrize();
        cout << endl << "2. ";
        items[ids[choice2-1]].showPrize();
        while ( (choice3 < 1) || (choice3 > 2) ){
            cout << endl << "Which item do you want to keep?: ";
            cin >> choice3;
            }
        int tempchoice;
        double tempPrice;
        if (choice3 == 1){
            tempchoice = choice1;
            tempPrice = items[ids[choice1-1]].getPrice();
            }
        else{
            tempchoice = choice2;
            tempPrice = items[ids[choice2-1]].getPrice();
            }
        while ( (choice4 < 1) || (choice4 > 6) || (choice4 == tempchoice) )
        {
            cout << fixed << endl << "Now, which item do you think is $" << setprecision(2) << tempPrice << "?: ";
            cin >> choice4;
        }

        cout << endl << "The actual retail price of the ";
        items[ids[choice4-1]].showShortName();
        cout << " is ";
        items[ids[choice4-1]].showARP();
        if (tempPrice == items[ids[choice4-1]].getPrice())
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";

    }


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// $uper $aver
void playSuperSaver()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice > 0.5) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "$UPER $AVER" << endl;

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
    grocery items[6];
    bool picked[6];

    double discounts[6] = {0.1, 0.2, 0.3, 0.4, 0.5, -0.2};
    random_shuffle(&discounts[0], &discounts[6]);

    /// Set each item, this time using a for loop:
    for (int grocCount = 0; grocCount < 6; grocCount++)
    {
        ggItemIt = ggItems.begin();
        for (z = 0; z < randomizationField[grocCount]; z++)
        {
            ggItemIt++;
        }

        items[grocCount].setDescription(ggItemIt->getDescription());
        items[grocCount].setShortName(ggItemIt->getShortName());
        items[grocCount].setPrice(ggItemIt->getPrice());
        picked[grocCount] = false;
    }

    double bank = 0;
    int itemsChosen = 0;

    while (itemsChosen < 4)
    {
        cout << endl << fixed << "Bank: $" << setprecision(2) << bank;
        for (int x = 0; x < 6; x++)
        {
            cout << endl << x+1 << ". ";
            items[x].showPrize();
            cout << " - $";
            cout << fixed << setprecision(2) << items[x].getPrice() - discounts[x];
            if (picked[x]){
                if (discounts[x] > 0)
                    cout << fixed << " / +$" << setprecision(2) << abs(discounts[x]);
                else
                    cout << fixed << " / -$" << setprecision(2) << abs(discounts[x]);
                }
        }
    int choice = 0;
    while ( (choice < 1) || (choice > 6) )
    {
        cout << endl << "Which item do you want to pick?: ";
        cin >> choice;
    }
    if (picked[choice-1])
        cout << endl << "You've already picked this item. Please pick another.";
    else
    {
        cout << endl << "The actual retail price of the ";
        items[choice-1].showShortName();
        cout << " is ";
        items[choice-1].showARP();
        if (discounts[choice-1] > 0){
            cout << endl << "You've saved $" << discounts[choice-1] << ".";
        }
        else
            cout << endl << "You've lost $" << abs(discounts[choice-1]) << ".";
        bank += discounts[choice-1];
        picked[choice-1] = true;
        itemsChosen += 1;
    }

    cout << endl;

    } /// end while loop

    cout << endl << fixed << "Bank: $" << setprecision(2) << bank;
    if (bank >= 1)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// The Phone Home Game
void playThePhoneHomeGame()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice > 0.5) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "THE PHONE HOME GAME" << endl;

    grocery items[7];

    int first;

    int second;
    bool foundSecond = false;

    int third;
    bool foundThird = false;

    int fourth;
    bool foundFourth = false;

    int fifth;
    bool foundFifth = false;

    int sixth;
    bool foundSixth = false;

    int seventh;
    bool foundSeventh = false;

    /// Generate first item.
    first = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first; z++)
        ggItemIt++;
    items[0].setDescription(ggItemIt->getDescription());
    items[0].setShortName(ggItemIt->getShortName());
    items[0].setPrice(ggItemIt->getPrice());

    /// Generate second item.
    while (!foundSecond){
    second = first;
    while (second == first)
        second = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z2 = 0; z2 < second; z2++)
        ggItemIt++;
    if (ggItemIt->getPrice() != items[0].getPrice()){
        items[1].setDescription(ggItemIt->getDescription());
        items[1].setShortName(ggItemIt->getShortName());
        items[1].setPrice(ggItemIt->getPrice());
        foundSecond = true;
    } // end if
    } // end while loop that generates the second item

    /// Generate third item.
    while (!foundThird){
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z3 = 0; z3 < third; z3++)
        ggItemIt++;
    if ( (ggItemIt->getPrice() != items[0].getPrice()) && (ggItemIt->getPrice() != items[1].getPrice()) ){
        items[2].setDescription(ggItemIt->getDescription());
        items[2].setShortName(ggItemIt->getShortName());
        items[2].setPrice(ggItemIt->getPrice());
        foundThird = true;
    } // end if
    } // end while loop that generates the third item

    /// Generate fourth item.
    while (!foundFourth){
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z4 = 0; z4 < fourth; z4++)
        ggItemIt++;
     if ( (ggItemIt->getPrice() != items[0].getPrice()) && (ggItemIt->getPrice() != items[1].getPrice())
         && (ggItemIt->getPrice() != items[2].getPrice()) ){
        items[3].setDescription(ggItemIt->getDescription());
        items[3].setShortName(ggItemIt->getShortName());
        items[3].setPrice(ggItemIt->getPrice());
        foundFourth = true;
    } // end if
    } // end while loop that generates the fourth item

    /// Generate fifth item.
    while (!foundFifth){
    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z5 = 0; z5 < fifth; z5++)
        ggItemIt++;
     if ( (ggItemIt->getPrice() != items[0].getPrice()) && (ggItemIt->getPrice() != items[1].getPrice())
         && (ggItemIt->getPrice() != items[2].getPrice()) && (ggItemIt->getPrice() != items[3].getPrice()) ){
        items[4].setDescription(ggItemIt->getDescription());
        items[4].setShortName(ggItemIt->getShortName());
        items[4].setPrice(ggItemIt->getPrice());
        foundFifth = true;
    } // end if
    } // end while loop that generates the fifth item

    /// Generate sixth item.
    while (!foundSixth){
    sixth = first;
    while ( (sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z6 = 0; z6 < sixth; z6++)
        ggItemIt++;
     if ( (ggItemIt->getPrice() != items[0].getPrice()) && (ggItemIt->getPrice() != items[1].getPrice())
         && (ggItemIt->getPrice() != items[2].getPrice()) && (ggItemIt->getPrice() != items[3].getPrice())
         && (ggItemIt->getPrice() != items[4].getPrice()) ){
        items[5].setDescription(ggItemIt->getDescription());
        items[5].setShortName(ggItemIt->getShortName());
        items[5].setPrice(ggItemIt->getPrice());
        foundSixth = true;
    } // end if
    } // end while loop that generates the sixth item

    /// Generate seventh item.
    while (!foundSeventh){
    seventh = first;
    while ( (seventh == first) || (seventh == second) || (seventh == third) || (seventh == fourth) || (seventh == fifth) || (seventh == sixth) )
        seventh = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z7 = 0; z7 < seventh; z7++)
        ggItemIt++;
     if ( (ggItemIt->getPrice() != items[0].getPrice()) && (ggItemIt->getPrice() != items[1].getPrice())
         && (ggItemIt->getPrice() != items[2].getPrice()) && (ggItemIt->getPrice() != items[3].getPrice())
         && (ggItemIt->getPrice() != items[4].getPrice()) && (ggItemIt->getPrice() != items[5].getPrice()) ){
        items[6].setDescription(ggItemIt->getDescription());
        items[6].setShortName(ggItemIt->getShortName());
        items[6].setPrice(ggItemIt->getPrice());
        foundSeventh = true;
    } // end if
    } // end while loop that generates the seventh item


    bool pickedPrice[7];
    bool pickedItem[7];

    for (int p = 0; p < 7; p++){
        pickedPrice[p] = false;
        pickedItem[p] = false;
        }

    int cashVals[7] = {200, 200, 1000, 1000, 2000, 3000, 10000};
    random_shuffle(&cashVals[0], &cashVals[7]);

    double prices[7] = {items[0].getPrice(), items[1].getPrice(), items[2].getPrice(), items[3].getPrice(),
                        items[4].getPrice(), items[5].getPrice(), items[6].getPrice()};
    random_shuffle(&prices[0], &prices[7]);

    for (int y = 0; y < 7; y++){
    cout << endl << y+1 << ". ";
    items[y].showPrize();
    }

    int guessedRight = 0;

    int answer1 = 0;
    cout << endl;
    cout << endl << fixed << setprecision(2) << "Your phone friend gave you the price $" << prices[0] << ".";
    while ( (answer1 < 1) || (answer1 > 7) ){
        cout << endl << "Which item has that price?: ";
        cin >> answer1;
    }
    pickedItem[answer1-1] = true;
    pickedPrice[0] = true;
    cout << endl << "The actual retail price of the ";
    items[answer1-1].showShortName();
    cout << " is ";
    items[answer1-1].showARP();
    if (items[answer1-1].getPrice() == prices[0]){
        cout << endl << "Yes, that's correct!";
        guessedRight += 1;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        if (items[0].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[0].showShortName();
            cout << ".";
            pickedItem[0] = true;
        }
        else if (items[1].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[1].showShortName();
            cout << ".";
            pickedItem[1] = true;
        }
        else if (items[2].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[2].showShortName();
            cout << ".";
            pickedItem[2] = true;
        }
        else if (items[3].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[3].showShortName();
            cout << ".";
            pickedItem[3] = true;
        }
        else if (items[4].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[4].showShortName();
            cout << ".";
            pickedItem[4] = true;
        }
        else if (items[5].getPrice() == prices[0]){
            cout << endl << "It was the ";
            items[5].showShortName();
            cout << ".";
            pickedItem[5] = true;
        }
        else{
            cout << endl << "It was the ";
            items[6].showShortName();
            cout << ".";
            pickedItem[6] = true;
        }

    // Ensure that the price is picked and won't be chosen again by the "home player."
    double wrongA = items[answer1-1].getPrice();
    if (prices[0] == wrongA)
        pickedPrice[0] = true;
    else if (prices[1] == wrongA)
        pickedPrice[1] = true;
    else if (prices[2] == wrongA)
        pickedPrice[2] = true;
    else if (prices[3] == wrongA)
        pickedPrice[3] = true;
    else if (prices[4] == wrongA)
        pickedPrice[4] = true;
    else if (prices[5] == wrongA)
        pickedPrice[5] = true;
    else
        pickedPrice[6] = true;
    } // end else if the player guessed wrong

    cout << endl;
    for (int yy = 0; yy < 7; yy++){
    cout << endl << yy+1 << ". ";
    items[yy].showPrize();
    if (pickedItem[yy]){
        cout << " - ";
        items[yy].showARP();
        }
    }

    int id1 = 0;
    while (pickedPrice[id1])
        id1 = rand() % 7;

    int answer2 = 0;
    cout << endl;
    cout << endl << fixed << setprecision(2) << "Your phone friend gave you the price $" << prices[id1] << ".";
    while ( (answer2 < 1) || (answer2 > 7) ){
        cout << endl << "Which item has that price?: ";
        cin >> answer2;
        if (pickedItem[answer2-1]){
            cout << endl << "This item's price has already been revealed. Please pick another.";
            answer2 = 0;
        }
    }
    pickedItem[answer2-1] = true;
    pickedPrice[id1] = true;
    cout << endl << "The actual retail price of the ";
    items[answer2-1].showShortName();
    cout << " is ";
    items[answer2-1].showARP();
    if (items[answer2-1].getPrice() == prices[id1]){
        cout << endl << "Yes, that's correct!";
        guessedRight += 1;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        if (items[0].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[0].showShortName();
            cout << ".";
            pickedItem[0] = true;
        }
        else if (items[1].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[1].showShortName();
            cout << ".";
            pickedItem[1] = true;
        }
        else if (items[2].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[2].showShortName();
            cout << ".";
            pickedItem[2] = true;
        }
        else if (items[3].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[3].showShortName();
            cout << ".";
            pickedItem[3] = true;
        }
        else if (items[4].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[4].showShortName();
            cout << ".";
            pickedItem[4] = true;
        }
        else if (items[5].getPrice() == prices[id1]){
            cout << endl << "It was the ";
            items[5].showShortName();
            cout << ".";
            pickedItem[5] = true;
        }
        else{
            cout << endl << "It was the ";
            items[6].showShortName();
            cout << ".";
            pickedItem[6] = true;
        }

    // Ensure that the price is picked and won't be chosen again by the "home player."
    double wrongB = items[answer2-1].getPrice();
    if (prices[0] == wrongB)
        pickedPrice[0] = true;
    else if (prices[1] == wrongB)
        pickedPrice[1] = true;
    else if (prices[2] == wrongB)
        pickedPrice[2] = true;
    else if (prices[3] == wrongB)
        pickedPrice[3] = true;
    else if (prices[4] == wrongB)
        pickedPrice[4] = true;
    else if (prices[5] == wrongB)
        pickedPrice[5] = true;
    else
        pickedPrice[6] = true;

    } // end else if the player guessed wrong

    cout << endl;
    for (int w = 0; w < 7; w++){
    cout << endl << w+1 << ". ";
    items[w].showPrize();
    if (pickedItem[w]){
        cout << " - ";
        items[w].showARP();
        }
    }

    int id2 = 0;
    while (pickedPrice[id2])
        id2 = rand() % 7;

    int answer3 = 0;
    cout << endl;
    cout << endl << fixed << setprecision(2) << "Your phone friend gave you the price $" << prices[id2] << ".";
    while ( (answer3 < 1) || (answer3 > 7) ){
        cout << endl << "Which item has that price?: ";
        cin >> answer3;
        if (pickedItem[answer3-1]){
            cout << endl << "This item's price has already been revealed. Please pick another.";
            answer3 = 0;
        }
    }
    pickedItem[answer3-1] = true;
    pickedPrice[id2] = true;
    cout << endl << "The actual retail price of the ";
    items[answer3-1].showShortName();
    cout << " is ";
    items[answer3-1].showARP();
    if (items[answer3-1].getPrice() == prices[id2]){
        cout << endl << "Yes, that's correct!";
        guessedRight += 1;
    }
    else
    {
        cout << endl << "Sorry, that's not correct.";
        if (items[0].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[0].showShortName();
            cout << ".";
            pickedItem[0] = true;
        }
        else if (items[1].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[1].showShortName();
            cout << ".";
            pickedItem[1] = true;
        }
        else if (items[2].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[2].showShortName();
            cout << ".";
            pickedItem[2] = true;
        }
        else if (items[3].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[3].showShortName();
            cout << ".";
            pickedItem[3] = true;
        }
        else if (items[4].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[4].showShortName();
            cout << ".";
            pickedItem[4] = true;
        }
        else if (items[5].getPrice() == prices[id2]){
            cout << endl << "It was the ";
            items[5].showShortName();
            cout << ".";
            pickedItem[5] = true;
        }
        else{
            cout << endl << "It was the ";
            items[6].showShortName();
            cout << ".";
            pickedItem[6] = true;
        }
    } // end else if the player guessed wrong

    if (guessedRight == 0)
        cout << endl << "Sorry, you don't win any money.";
    else if (guessedRight == 1){
        cout << endl << "Let's see what's behind the item you guessed correctly...";
        cout << endl;
        system("pause");
        cout << endl << "You've won $" << cashVals[0] << ". Thanks for playing!";
    }
    else if (guessedRight == 2){
        cout << endl << "Let's see what's behind the items you guessed correctly...";
        cout << endl;
        system("pause");
        cout << endl << "Behind the first item is $" << cashVals[0];
        cout << endl;
        system("pause");
        cout << endl << "Behind the second item is $" << cashVals[1];
        cout << endl << "You've won $" << cashVals[0]+cashVals[1] << ". Thanks for playing!";
    }
    else{
        cout << endl << "Let's see what's behind the items you guessed correctly...";
        cout << endl;
        system("pause");
        cout << endl << "Behind the first item is $" << cashVals[0];
        cout << endl;
        system("pause");
        cout << endl << "Behind the second item is $" << cashVals[1];
        cout << endl;
        system("pause");
        cout << endl << "Behind the third item is $" << cashVals[2];
        if ( (cashVals[0]+cashVals[1]+cashVals[2] ) == 15000 )
            cout << endl << "Congratulations, you won $15,000!";
        else
           cout << endl << "You've won $" << cashVals[0]+cashVals[1]+cashVals[2] << ". Thanks for playing!";
    }


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Time is Money
void playTimeIsMoney()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "TIME IS MONEY" << endl;

    int ids[5] = {0, 1, 2, 3, 4};
    grocery tempItems[5];
    grocery items[5];

    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    int chances = 6;

    /// First item (must be under $3)
    bool setFirst = false;
    while (!setFirst){
    first = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first; z++)
        ggItemIt++;
    if (ggItemIt->getPrice() < 3){
    tempItems[0].setDescription(ggItemIt->getDescription());
    tempItems[0].setShortName(ggItemIt->getShortName());
    tempItems[0].setPrice(ggItemIt->getPrice());
    setFirst = true;
    }
    } // end while loop

    /// Second item (must be between $3 and $5.99, inclusive of both)
    bool setSecond = false;
    while (!setSecond){
    second = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < second; z++)
        ggItemIt++;
    if ( (ggItemIt->getPrice() >= 3) && (ggItemIt->getPrice() < 6) ){
    tempItems[1].setDescription(ggItemIt->getDescription());
    tempItems[1].setShortName(ggItemIt->getShortName());
    tempItems[1].setPrice(ggItemIt->getPrice());
    setSecond = true;
    }
    } // end while loop

    /// Third item (must be $6 or more)
    bool setThird = false;
    while (!setThird){
    third = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < third; z++)
        ggItemIt++;
    if ( (ggItemIt->getPrice() >= 6) ){
    tempItems[2].setDescription(ggItemIt->getDescription());
    tempItems[2].setShortName(ggItemIt->getShortName());
    tempItems[2].setPrice(ggItemIt->getPrice());
    setThird = true;
    }
    } // end while loop

    /// Fourth item (can be any price)
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < fourth; z++)
        ggItemIt++;
    tempItems[3].setDescription(ggItemIt->getDescription());
    tempItems[3].setShortName(ggItemIt->getShortName());
    tempItems[3].setPrice(ggItemIt->getPrice());

    /// Fifth item (can be any price)
    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < fifth; z++)
        ggItemIt++;
    tempItems[4].setDescription(ggItemIt->getDescription());
    tempItems[4].setShortName(ggItemIt->getShortName());
    tempItems[4].setPrice(ggItemIt->getPrice());

    random_shuffle(&ids[0], &ids[5]);

    for (int s = 0; s < 5; s++){
    items[s].setDescription(tempItems[ids[s]].getDescription());
    items[s].setShortName(tempItems[ids[s]].getShortName());
    items[s].setPrice(tempItems[ids[s]].getPrice());
    }

    /// 1 refers to $0-$2.99, 2 refers to $3-$5.99, and 3 refers to $6+.
    int rightShelf[5];
    for (int t = 0; t < 5; t++){
//    cout << endl;
//    items[t].showPrize();
//    cout << " - ";
//    items[t].showARP();
    if (items[t].getPrice() < 3)
        rightShelf[t] = 1;
    else if (items[t].getPrice() >= 6)
        rightShelf[t] = 3;
    else
        rightShelf[t] = 2;
    }

    int playerSetup[5] = {0, 0, 0, 0, 0};
    //cout << endl << rightShelf[0] << ", " << rightShelf[1] << ", " << rightShelf[2] << ", " << rightShelf[3] << ", " << rightShelf[4];

    bool finishedFirstTry = false;

    while (!finishedFirstTry){
    for (int y = 0; y < 5; y++){
        cout << endl << y+1 << ". ";
        items[y].showPrize();
        if (playerSetup[y] == 1)
            cout << " - $0-$2.99";
        else if (playerSetup[y] == 2)
            cout << " - $3-$5.99";
        else if (playerSetup[y] == 3)
            cout << " - $6+";
    }
    int choice = 0;
    int shelf = 0;
    while ( (choice < 1) || (choice > 5) ){
        cout << endl << "Which item do you want to pick?: ";
        cin >> choice;
        if (playerSetup[choice-1] > 0){
            if ( (choice < 1) || (choice > 5) )
                cout << endl << "Please enter a number between 1 and 5.";
            else
                cout << endl << "You've already chosen this item. Please pick another one.";
            choice = 0;
        }
    } // end while loop
    cout << endl << "1. $0-$2.99";
    cout << endl << "2. $3-$5.99";
    cout << endl << "3. $6+";
    while ( (shelf < 1) || (shelf > 3) ){
    cout << endl << "On which shelf does this item go?: ";
    cin >> shelf;
    }
    playerSetup[choice-1] = shelf;

    if ( (playerSetup[0] > 0) && (playerSetup[1] > 0) && (playerSetup[2] > 0) && (playerSetup[3] > 0) && (playerSetup[4] > 0) )
        finishedFirstTry = true;
    } // end while loop

    for (int y = 0; y < 5; y++){
        cout << endl << y+1 << ". ";
        items[y].showPrize();
        if (playerSetup[y] == 1)
            cout << " - $0-$2.99";
        else if (playerSetup[y] == 2)
            cout << " - $3-$5.99";
        else if (playerSetup[y] == 3)
            cout << " - $6+";
    }

    int hasRight = 0;
    cout << endl;
    cout << endl << "Here's what you've chosen. Is this correct?";
    cout << endl;
    system("pause");
    for (int r = 0; r < 5; r++){
        if (playerSetup[r] == rightShelf[r])
            hasRight++;
    }
    if (hasRight == 5)
        cout << endl << "Congratulations, you win $20,000!";
    else{
    bool won = false;
    chances -= 1;
    cout << endl << "Sorry, that's not correct. \nThe money will start counting down now.";
    while ( (chances > 0) && (!won) )
    {
    bool finished = false;
    playerSetup[0] = 0;
    playerSetup[1] = 0;
    playerSetup[2] = 0;
    playerSetup[3] = 0;
    playerSetup[4] = 0;

    while (!finished){
    for (int y = 0; y < 5; y++){
        cout << endl << y+1 << ". ";
        items[y].showPrize();
        if (playerSetup[y] == 1)
            cout << " - $0-$2.99";
        else if (playerSetup[y] == 2)
            cout << " - $3-$5.99";
        else if (playerSetup[y] == 3)
            cout << " - $6+";
    }
    int choice1 = 0;
    int shelf1 = 0;

    while ( (choice1 < 1) || (choice1 > 5) ){
        cout << endl << "Which item do you want to pick?: ";
        cin >> choice1;
        if (playerSetup[choice1-1] > 0){
            if ( (choice1 < 1) || (choice1 > 5) )
                cout << endl << "Please enter a number between 1 and 5.";
            else
                cout << endl << "You've already chosen this item. Please pick another one.";
            choice1 = 0;
        }
    } // end while loop
    cout << endl << "1. $0-$2.99";
    cout << endl << "2. $3-$5.99";
    cout << endl << "3. $6+";
    while ( (shelf1 < 1) || (shelf1 > 3) ){
    cout << endl << "On which shelf does this item go?: ";
    cin >> shelf1;
    }
    playerSetup[choice1-1] = shelf1;

    if ( (playerSetup[0] > 0) && (playerSetup[1] > 0) && (playerSetup[2] > 0) && (playerSetup[3] > 0) && (playerSetup[4] > 0) )
        finished = true;

    } // end while loop for setting up

    for (int y = 0; y < 5; y++){
        cout << endl << y+1 << ". ";
        items[y].showPrize();
        if (playerSetup[y] == 1)
            cout << " - $0-$2.99";
        else if (playerSetup[y] == 2)
            cout << " - $3-$5.99";
        else if (playerSetup[y] == 3)
            cout << " - $6+";
    }

    int hasRight1 = 0;
    cout << endl;
    cout << endl << "Here's what you've chosen. Is this correct?";
    cout << endl;
    system("pause");
    for (int r = 0; r < 5; r++){
        if (playerSetup[r] == rightShelf[r])
            hasRight1++;
    }
    if (hasRight1 == 5)
        won = true;
    else{
        cout << endl << "Sorry, that's not correct.";
        chances -= 1;
    }

    } // end while loop

    if ( (won) && (chances == 5) )
        cout << endl << "Congratulations, you win $17,143!";
    else if ( (won) && (chances == 4) )
        cout << endl << "Congratulations, you win $14,286!";
    else if ( (won) && (chances == 3) )
        cout << endl << "Congratulations, you win $11,429!";
    else if ( (won) && (chances == 2) )
        cout << endl << "Congratulations, you win $8572!";
    else if ( (won) && (chances == 1) )
        cout << endl << "Congratulations, you win $5715!";
    else
        cout << endl << "Sorry, you lose.";

    } // end else statement if player didn't get prices right on first try

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// To the Penny
void playToThePenny()
{
    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;

    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;

    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice < 10) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "TO THE PENNY" << endl;

    grocery items[5];
    int pennies = 5;
    int money = 0;

    /// Set up the items
    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    first = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first; z++)
        ggItemIt++;
    items[0].setDescription(ggItemIt->getDescription());
    items[0].setShortName(ggItemIt->getShortName());
    items[0].setPrice(ggItemIt->getPrice());

    second = first;
    while (second == first)
        second = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < second; z++)
        ggItemIt++;
    items[1].setDescription(ggItemIt->getDescription());
    items[1].setShortName(ggItemIt->getShortName());
    items[1].setPrice(ggItemIt->getPrice());

    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < third; z++)
        ggItemIt++;
    items[2].setDescription(ggItemIt->getDescription());
    items[2].setShortName(ggItemIt->getShortName());
    items[2].setPrice(ggItemIt->getPrice());

    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < fourth; z++)
        ggItemIt++;
    items[3].setDescription(ggItemIt->getDescription());
    items[3].setShortName(ggItemIt->getShortName());
    items[3].setPrice(ggItemIt->getPrice());

    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % i;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < fifth; z++)
        ggItemIt++;
    items[4].setDescription(ggItemIt->getDescription());
    items[4].setShortName(ggItemIt->getShortName());
    items[4].setPrice(ggItemIt->getPrice());

    int temp; // temporarily holds a random number
    int flag1; // determines if the price should be slightly modified
    int flag2; // determines if flag1's value should be added or subtracted

    /// Price #1
    int position1 = rand() % 2;
    bool eliminatedWrong = false;

    double wrong1 = items[0].getPrice();
    while (wrong1 == items[0].getPrice()){
        if (items[0].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrong1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrong1 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrong1 -= 0.20;
        }
        else if ( (items[0].getPrice() > 3.5) && (items[0].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrong1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrong1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrong1 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrong1 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrong1 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrong1 -= 0.40;
        }
    } /// end while loop seting wrong1
    cout << endl;
    bool guessedFirst = false;
    while (!guessedFirst){
    cout << "Pennies: " << pennies << endl;
    cout << "Money: $" << money << endl;
    cout << endl;
    int choice1 = 0;
    items[0].showPrize();
    if (position1 == 0){
        if (!eliminatedWrong){
        cout << endl << "1. ";
        items[0].showARP();
        cout << endl << fixed << setprecision(2) << "2. $" << wrong1;
        }
        else{
        cout << endl << "1. ";
        items[0].showARP();
        cout << endl << fixed << setprecision(2) << "2. $" << wrong1 << " - X";
        }
    } // end if position == 0
    else{
        if (!eliminatedWrong){
        cout << endl << fixed << setprecision(2) << "1. $" << wrong1;
        cout << endl << "2. ";
        items[0].showARP();
        }
        else{
        cout << endl << fixed << setprecision(2) << "1. $" << wrong1 << " - X";
        cout << endl << "2. ";
        items[0].showARP();
        }
    } // end if position == 1
    while ( (choice1 < 1) || (choice1 > 2) ){
        cout << endl << "For $1500, what is the correct price?: ";
        cin >> choice1;
    }

    if ( (choice1 == 1) && (position1 == 0) ){
        cout << endl << "Yes, that's correct! You've won $1500.";
        cout << endl;
        money = 1500;
        guessedFirst = true;
    }
    else if ( (choice1 == 2) && (position1 == 1) ){
        cout << endl << "Yes, that's correct! You've won $1500.";
        cout << endl;
        money = 1500;
        guessedFirst = true;
    }
    else if ( (choice1 == 1) && (position1 != 0) && (!eliminatedWrong) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        pennies -= 2;
        eliminatedWrong = true;
    }
    else if ( (choice1 == 2) && (position1 != 1) && (!eliminatedWrong) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        pennies -= 2;
        eliminatedWrong = true;
    }
    else if ( (choice1 == 1) && (position1 != 0) && (eliminatedWrong) ){
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    else if ( (choice1 == 2) && (position1 != 1) && (eliminatedWrong) ){
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }

    } // while player hasn't won this item

    /// Price #2
    cout << endl;
    bool guessedSecond = false;
    bool bailedOnSec = false;
    int position2 = rand() % 3;
    bool price2ChoicesElim[3];
    for (int p = 0; p < 3; p++)
        price2ChoicesElim[p] = false;

    /// Set the "wrong" prices
    double wronga_2 = items[1].getPrice();
    while (wronga_2 == items[1].getPrice()){
        if (items[1].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_2 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_2 -= 0.20;
        }
        else if ( (items[1].getPrice() > 3.5) && (items[1].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_2 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_2 -= 0.40;
        }
    } /// end while loop setting wronga_2

    double wrongb_2 = items[1].getPrice();
    while ( (wrongb_2 == items[1].getPrice()) || (wrongb_2 == wronga_2) ){
        if (items[1].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_2 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_2 -= 0.20;
        }
        else if ( (items[1].getPrice() > 3.5) && (items[1].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_2 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_2 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_2 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_2 -= 0.40;
        }
    } /// end while loop setting wrongb_2

    int secondsElim = 0;

    while ( (!guessedSecond) && (!bailedOnSec) && (pennies > 0) ){
    cout << "Pennies: " << pennies << endl;
    cout << "Money: $" << money << endl;
    cout << endl;
    int choice2 = 0;
    items[1].showPrize();

    /// Show prices
    if (position2 == 0){
        cout << endl << "1. ";
        items[1].showARP();
        cout << endl << fixed << setprecision(2) << "2. $" << wronga_2;
        if (price2ChoicesElim[1])
            cout << " - X";
        cout << endl << fixed << setprecision(2) << "3. $" << wrongb_2;
        if (price2ChoicesElim[2])
            cout << " - X";
        cout << endl << "4. Eliminate one of the wrong prices";
        cout << endl << "5. Quit with $1500";
    } // end if the price is #1
    else if (position2 == 1){
        cout << endl << fixed << setprecision(2) << "1. $" << wronga_2;
        if (price2ChoicesElim[0])
            cout << " - X";
        cout << endl << "2. ";
        items[1].showARP();
        cout << endl << fixed << setprecision(2) << "3. $" << wrongb_2;
        if (price2ChoicesElim[2])
            cout << " - X";
        cout << endl << "4. Eliminate one of the wrong prices";
        cout << endl << "5. Quit with $1500";
    } // end if the price is #2
    else{
        cout << endl << fixed << setprecision(2) << "1. $" << wronga_2;
        if (price2ChoicesElim[0])
            cout << " - X";
        cout << endl << fixed << setprecision(2) << "2. $" << wrongb_2;
        if (price2ChoicesElim[1])
            cout << " - X";
        cout << endl << "3. ";
        items[1].showARP();
        cout << endl << "4. Eliminate one of the wrong prices";
        cout << endl << "5. Quit with $1500";
    } // end if the price is #3

    while ( (choice2 < 1) || (choice2 > 5) ){
        cout << endl << "For $3000, what is the correct price?: ";
        cin >> choice2;
    }
    if (choice2 == 5)
        bailedOnSec = true;

    else if (choice2 == 4){
    if (pennies <= 1)
        cout << endl << "You don't have enough pennies to do that." << endl;
    else if (secondsElim >= 2)
        cout << endl << "There are no more prices to eliminate." << endl;
    else{
        int randomel = position2;
        while ( (randomel == position2) || (price2ChoicesElim[randomel]) )
            randomel = rand() % 3;
        pennies -= 1;
        price2ChoicesElim[randomel] = true;
        secondsElim += 1;
        cout << endl << "You've spent one penny to eliminate a price." << endl;
    }
    } // end if player eliminated one of the prices

    else if (choice2 == 1){
    if (position2 == 0){
        cout << endl << "Yes, that's correct! You've earned $3000.";
        cout << endl;
        money = 3000;
        guessedSecond = true;
    }
    else if ( (position2 != 0) && (!price2ChoicesElim[0]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price2ChoicesElim[0] = true;
        secondsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #1

    else if (choice2 == 2){
    if (position2 == 1){
        cout << endl << "Yes, that's correct! You've earned $3000.";
        cout << endl;
        money = 3000;
        guessedSecond = true;
    }
    else if ( (position2 != 1) && (!price2ChoicesElim[1]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price2ChoicesElim[1] = true;
        secondsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #2

    else if (choice2 == 3){
    if (position2 == 2){
        cout << endl << "Yes, that's correct! You've earned $3000.";
        cout << endl;
        money = 3000;
        guessedSecond = true;
    }
    else if ( (position2 != 2) && (!price2ChoicesElim[2])){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price2ChoicesElim[2] = true;
        secondsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #3

    } /// end while loop for second item

    bool bailedOnThird = false;
    bool bailedOnFourth = false;
    bool bailedOnFifth = false;

    bool guessedThird = false;
    bool guessedFourth = false;
    bool guessedFifth = false;

    if (guessedSecond){
    /// Price #3
    cout << endl;
    int position3 = rand() % 4;
    bool price3ChoicesElim[4];
    for (int p = 0; p < 4; p++)
        price3ChoicesElim[p] = false;

    /// Set the "wrong" prices
    double wronga_3 = items[2].getPrice();
    while (wronga_3 == items[2].getPrice()){
        if (items[2].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_3 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_3 -= 0.20;
        }
        else if ( (items[2].getPrice() > 3.5) && (items[2].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_3 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_3 -= 0.40;
        }
    } /// end while loop setting wronga_3

    double wrongb_3 = items[2].getPrice();
    while ( (wrongb_3 == items[2].getPrice()) || (wrongb_3 == wronga_3) ){
        if (items[2].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_3 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_3 -= 0.20;
        }
        else if ( (items[2].getPrice() > 3.5) && (items[2].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_3 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_3 -= 0.40;
        }
    } /// end while loop setting wrongb_3

    double wrongc_3 = items[2].getPrice();
    while ( (wrongc_3 == items[2].getPrice()) || (wrongc_3 == wronga_3) || (wrongc_3 == wrongb_3) ){
        if (items[2].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_3 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_3 -= 0.20;
        }
        else if ( (items[2].getPrice() > 3.5) && (items[2].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_3 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_3 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_3 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_3 -= 0.40;
        }
    } /// end while loop setting wrongc_3

    int thirdsElim = 0;

    while ( (!guessedThird) && (!bailedOnThird) && (pennies > 0) ){
    cout << "Pennies: " << pennies << endl;
    cout << "Money: $" << money << endl;
    cout << endl;
    int choice3 = 0;
    items[2].showPrize();

    /// Show options
    if (position3 == 0){
    cout << endl << "1. ";
    items[2].showARP();
    cout << endl << fixed << setprecision(2) << "2. $" << wronga_3;
    if (price3ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_3;
    if (price3ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_3;
    if (price3ChoicesElim[3])
        cout << " - X";
    cout << endl << "5. Eliminate one of the wrong prices";
    cout << endl << "6. Quit with $3000";
    } // end if price is #1

    else if (position3 == 1){
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_3;
    if (price3ChoicesElim[0])
        cout << " - X";
    cout << endl << "2. ";
    items[2].showARP();
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_3;
    if (price3ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_3;
    if (price3ChoicesElim[3])
        cout << " - X";
    cout << endl << "5. Eliminate one of the wrong prices";
    cout << endl << "6. Quit with $3000";
    } // end if price is #2

    else if (position3 == 2){
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_3;
    if (price3ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_3;
    if (price3ChoicesElim[1])
        cout << " - X";
    cout << endl << "3. ";
    items[2].showARP();
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_3;
    if (price3ChoicesElim[3])
        cout << " - X";
    cout << endl << "5. Eliminate one of the wrong prices";
    cout << endl << "6. Quit with $3000";
    } // end if price is #3

    else{
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_3;
    if (price3ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_3;
    if (price3ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_3;
    if (price3ChoicesElim[2])
        cout << " - X";
    cout << endl << "4. ";
    items[2].showARP();
    cout << endl << "5. Eliminate one of the wrong prices";
    cout << endl << "6. Quit with $3000";
    } // end if price is #4

    while ( (choice3 < 1) || (choice3 > 6) ){
        cout << endl << "For $6000, what is the correct price?: ";
        cin >> choice3;
    }
    if (choice3 == 6)
        bailedOnThird = true;

    else if (choice3 == 5){
    if (pennies <= 1)
        cout << endl << "You don't have enough pennies to do that." << endl;
    else if (thirdsElim >= 3)
        cout << endl << "There are no more prices to eliminate." << endl;
    else{
        int randome2 = position3;
        while ( (randome2 == position3) || (price3ChoicesElim[randome2]) )
            randome2 = rand() % 4;
        pennies -= 1;
        price3ChoicesElim[randome2] = true;
        thirdsElim += 1;
        cout << endl << "You've spent one penny to eliminate a price." << endl;
    }
    } // end if player eliminated one of the prices

    else if (choice3 == 1){
    if (position3 == 0){
        cout << endl << "Yes, that's correct! You've earned $6000.";
        cout << endl;
        money = 6000;
        guessedThird = true;
    }
    else if ( (position3 != 0) && (!price3ChoicesElim[0]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price3ChoicesElim[0] = true;
        thirdsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #1

    else if (choice3 == 2){
    if (position3 == 1){
        cout << endl << "Yes, that's correct! You've earned $6000.";
        cout << endl;
        money = 6000;
        guessedThird = true;
    }
    else if ( (position3 != 1) && (!price3ChoicesElim[1]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price3ChoicesElim[1] = true;
        thirdsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #2

    else if (choice3 == 3){
    if (position3 == 2){
        cout << endl << "Yes, that's correct! You've earned $6000.";
        cout << endl;
        money = 6000;
        guessedThird = true;
    }
    else if ( (position3 != 2) && (!price3ChoicesElim[2]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price3ChoicesElim[2] = true;
        thirdsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #3

    else if (choice3 == 4){
    if (position3 == 3){
        cout << endl << "Yes, that's correct! You've earned $6000.";
        cout << endl;
        money = 6000;
        guessedThird = true;
    }
    else if ( (position3 != 3) && (!price3ChoicesElim[3]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price3ChoicesElim[3] = true;
        thirdsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #4

    } /// end while loop for third item

    if (guessedThird){
    /// Price #4
    cout << endl;
    int position4 = rand() % 5;
    bool price4ChoicesElim[5];
    for (int p = 0; p < 5; p++)
        price4ChoicesElim[p] = false;

    /// Set the "wrong" prices
    double wronga_4 = items[3].getPrice();
    while (wronga_4 == items[3].getPrice()){
        if (items[3].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_4 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_4 -= 0.20;
        }
        else if ( (items[3].getPrice() > 3.5) && (items[3].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_4 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_4 -= 0.40;
        }
    } /// end while loop setting wronga_4

    double wrongb_4 = items[3].getPrice();
    while ( (wrongb_4 == items[3].getPrice()) || (wrongb_4 == wronga_4) ){
        if (items[3].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_4 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_4 -= 0.20;
        }
        else if ( (items[3].getPrice() > 3.5) && (items[3].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_4 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_4 -= 0.40;
        }
    } /// end while loop setting wrongb_4

    double wrongc_4 = items[3].getPrice();
    while ( (wrongc_4 == items[3].getPrice()) || (wrongc_4 == wronga_4) || (wrongc_4 == wrongb_4) ){
        if (items[3].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_4 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_4 -= 0.20;
        }
        else if ( (items[3].getPrice() > 3.5) && (items[3].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_4 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_4 -= 0.40;
        }
    } /// end while loop setting wrongc_4

    double wrongd_4 = items[3].getPrice();
    while ( (wrongd_4 == items[3].getPrice()) || (wrongd_4 == wronga_4) || (wrongd_4 == wrongb_4) || (wrongd_4 == wrongc_4) ){
        if (items[3].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_4 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_4 -= 0.20;
        }
        else if ( (items[3].getPrice() > 3.5) && (items[3].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_4 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_4 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_4 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_4 -= 0.40;
        }
    } /// end while loop setting wrongd_4

    int fourthsElim = 0;

    while ( (!guessedFourth) && (!bailedOnFourth) && (pennies > 0) ){
    cout << "Pennies: " << pennies << endl;
    cout << "Money: $" << money << endl;
    cout << endl;
    int choice4 = 0;
    items[3].showPrize();

    /// Show options
    if (position4 == 0){
    cout << endl << "1. ";
    items[3].showARP();
    cout << endl << fixed << setprecision(2) << "2. $" << wronga_4;
    if (price4ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_4;
    if (price4ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_4;
    if (price4ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_4;
    if (price4ChoicesElim[4])
        cout << " - X";
    cout << endl << "6. Eliminate one of the wrong prices";
    cout << endl << "7. Quit with $6000";
    } // end if price is #1

    else if (position4 == 1){
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_4;
    if (price4ChoicesElim[0])
        cout << " - X";
    cout << endl << "2. ";
    items[3].showARP();
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_4;
    if (price4ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_4;
    if (price4ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_4;
    if (price4ChoicesElim[4])
        cout << " - X";
    cout << endl << "6. Eliminate one of the wrong prices";
    cout << endl << "7. Quit with $6000";
    } // end if price is #2

    else if (position4 == 2){
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_4;
    if (price4ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_4;
    if (price4ChoicesElim[1])
        cout << " - X";
    cout << endl << "3. ";
    items[3].showARP();
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_4;
    if (price4ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_4;
    if (price4ChoicesElim[4])
        cout << " - X";
    cout << endl << "6. Eliminate one of the wrong prices";
    cout << endl << "7. Quit with $6000";
    } // end if price is #3

    else if (position4 == 3){
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_4;
    if (price4ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_4;
    if (price4ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_4;
    if (price4ChoicesElim[2])
        cout << " - X";
    cout << endl << "4. ";
    items[3].showARP();
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_4;
    if (price4ChoicesElim[4])
        cout << " - X";
    cout << endl << "6. Eliminate one of the wrong prices";
    cout << endl << "7. Quit with $6000";
    } // end if price is #4

    else{
    cout << endl << fixed << setprecision(2) << "1. $" << wronga_4;
    if (price4ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_4;
    if (price4ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_4;
    if (price4ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongd_4;
    if (price4ChoicesElim[3])
        cout << " - X";
    cout << endl << "5. ";
    items[3].showARP();
    cout << endl << "6. Eliminate one of the wrong prices";
    cout << endl << "7. Quit with $6000";
    } // end if price is #5

    while ( (choice4 < 1) || (choice4 > 7) ){
        cout << endl << "For $12,000, what is the correct price?: ";
        cin >> choice4;
    }
    if (choice4 == 7)
        bailedOnFourth = true;

    else if (choice4 == 6){
    if (pennies <= 1)
        cout << endl << "You don't have enough pennies to do that." << endl;
    else if (fourthsElim >= 4)
        cout << endl << "There are no more prices to eliminate." << endl;
    else{
        int randome3 = position4;
        while ( (randome3 == position4) || (price4ChoicesElim[randome3]) )
            randome3 = rand() % 5;
        pennies -= 1;
        price4ChoicesElim[randome3] = true;
        fourthsElim += 1;
        cout << endl << "You've spent one penny to eliminate a price." << endl;
    }
    } // end if player eliminated one of the prices

    else if (choice4 == 1){
    if (position4 == 0){
        cout << endl << "Yes, that's correct! You've earned $12,000.";
        cout << endl;
        money = 12000;
        guessedFourth = true;
    }
    else if ( (position4 != 0) && (!price4ChoicesElim[0]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price4ChoicesElim[0] = true;
        fourthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #1

    else if (choice4 == 2){
    if (position4 == 1){
        cout << endl << "Yes, that's correct! You've earned $12,000.";
        cout << endl;
        money = 12000;
        guessedFourth = true;
    }
    else if ( (position4 != 1) && (!price4ChoicesElim[1]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price4ChoicesElim[1] = true;
        fourthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #2

    else if (choice4 == 3){
    if (position4 == 2){
        cout << endl << "Yes, that's correct! You've earned $12,000.";
        cout << endl;
        money = 12000;
        guessedFourth = true;
    }
    else if ( (position4 != 2) && (!price4ChoicesElim[2]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price4ChoicesElim[2] = true;
        fourthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #3

    else if (choice4 == 4){
    if (position4 == 3){
        cout << endl << "Yes, that's correct! You've earned $12,000.";
        cout << endl;
        money = 12000;
        guessedFourth = true;
    }
    else if ( (position4 != 3) && (!price4ChoicesElim[3]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price4ChoicesElim[3] = true;
        fourthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #4

    else if (choice4 == 5){
    if (position4 == 4){
        cout << endl << "Yes, that's correct! You've earned $12,000.";
        cout << endl;
        money = 12000;
        guessedFourth = true;
    }
    else if ( (position4 != 4) && (!price4ChoicesElim[4]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price4ChoicesElim[4] = true;
        fourthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #5

    } /// end while loop for fourth item

    if (guessedFourth){
    /// Price #5

    if (pennies == 5){
        cout << endl << "Since you still have all five pennies, you win $25,000 by default!";
        guessedFifth = true;
    }
    else{
    cout << endl;
    int position5 = rand() % 6;
    bool price5ChoicesElim[6];
    for (int p = 0; p < 6; p++)
        price5ChoicesElim[p] = false;

    /// Set the "wrong" prices
    double wronga_5 = items[4].getPrice();
    while (wronga_5 == items[4].getPrice()){
        if (items[4].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_5 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_5 -= 0.20;
        }
        else if ( (items[4].getPrice() > 3.5) && (items[4].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_5 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronga_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronga_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronga_5 -= 0.40;
        }
    } /// end while loop setting wronga_5

    double wrongb_5 = items[4].getPrice();
    while ( (wrongb_5 == items[4].getPrice()) || (wrongb_5 == wronga_5) ){
        if (items[4].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_5 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_5 -= 0.20;
        }
        else if ( (items[4].getPrice() > 3.5) && (items[4].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_5 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongb_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongb_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongb_5 -= 0.40;
        }
    } /// end while loop setting wrongb_5

    double wrongc_5 = items[4].getPrice();
    while ( (wrongc_5 == items[4].getPrice()) || (wrongc_5 == wronga_5) || (wrongc_5 == wrongb_5) ){
        if (items[4].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_5 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_5 -= 0.20;
        }
        else if ( (items[4].getPrice() > 3.5) && (items[4].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_5 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongc_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongc_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongc_5 -= 0.40;
        }
     } /// end while loop setting wrongc_5

    double wrongd_5 = items[4].getPrice();
    while ( (wrongd_5 == items[4].getPrice()) || (wrongd_5 == wronga_5) || (wrongd_5 == wrongb_5) || (wrongd_5 == wrongc_5) ){
        if (items[4].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_5 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_5 -= 0.20;
        }
        else if ( (items[4].getPrice() > 3.5) && (items[4].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_5 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wrongd_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wrongd_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wrongd_5 -= 0.40;
        }
     } /// end while loop setting wrongd_5

    double wronge_5 = items[4].getPrice();
    while ( (wronge_5 == items[4].getPrice()) || (wronge_5 == wronga_5) || (wronge_5 == wrongb_5) || (wronge_5 == wrongc_5) || (wronge_5 == wrongd_5) ){
        if (items[4].getPrice() <= 3.5){
        temp = (rand() % 5) + 1;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronge_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronge_5 += 0.20;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronge_5 -= 0.20;
        }
        else if ( (items[4].getPrice() > 3.5) && (items[4].getPrice() <= 6.5)){
        temp = rand()%(12-7 + 1) + 7;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronge_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronge_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronge_5 -= 0.40;
        }
        else{
        temp = rand()%(18-13 + 1) + 13;
        flag1 = rand() % 2;
        flag2 = rand() % 2;
        wronge_5 = toRandomPrice(temp);
        if ( (flag1 == 1) && (flag2 == 0) )
            wronge_5 += 0.40;
        if ( (flag1 == 1) && (flag2 == 1) )
            wronge_5 -= 0.40;
        }
    } /// end while loop setting wronge_5

    int fifthsElim = 0;

    while ( (!guessedFifth) && (!bailedOnFifth) && (pennies > 0) ){
    cout << "Pennies: " << pennies << endl;
    cout << "Money: $" << money << endl;
    cout << endl;
    int choice5 = 0;
    items[4].showPrize();

    /// Show options
    if (position5 == 0){
    cout << endl << "1. ";
    items[4].showARP();
    cout << endl << fixed << setprecision(2) << "2. $" << wronga_5;
    if (price5ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_5;
    if (price5ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_5;
    if (price5ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_5;
    if (price5ChoicesElim[4])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "6. $" << wronge_5;
    if (price5ChoicesElim[5])
        cout << " - X";
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #1

    else if (position5 == 1){
    cout << endl << fixed << setprecision(2) <<  "1. $" << wronga_5;
    if (price5ChoicesElim[0])
        cout << " - X";
    cout << endl << "2. ";
    items[4].showARP();
    cout << endl << fixed << setprecision(2) << "3. $" << wrongb_5;
    if (price5ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_5;
    if (price5ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_5;
    if (price5ChoicesElim[4])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "6. $" << wronge_5;
    if (price5ChoicesElim[5])
        cout << " - X";
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #2

    else if (position5 == 2){
    cout << endl << fixed << setprecision(2) <<  "1. $" << wronga_5;
    if (price5ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_5;
    if (price5ChoicesElim[1])
        cout << " - X";
    cout << endl << "3. ";
    items[4].showARP();
    cout << endl << fixed << setprecision(2) << "4. $" << wrongc_5;
    if (price5ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_5;
    if (price5ChoicesElim[4])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "6. $" << wronge_5;
    if (price5ChoicesElim[5])
        cout << " - X";
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #3

    else if (position5 == 3){
    cout << endl << fixed << setprecision(2) <<  "1. $" << wronga_5;
    if (price5ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_5;
    if (price5ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_5;
    if (price5ChoicesElim[2])
        cout << " - X";
    cout << endl << "4. ";
    items[4].showARP();
    cout << endl << fixed << setprecision(2) << "5. $" << wrongd_5;
    if (price5ChoicesElim[4])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "6. $" << wronge_5;
    if (price5ChoicesElim[5])
        cout << " - X";
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #4

    else if (position5 == 4){
    cout << endl << fixed << setprecision(2) <<  "1. $" << wronga_5;
    if (price5ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_5;
    if (price5ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_5;
    if (price5ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongd_5;
    if (price5ChoicesElim[3])
        cout << " - X";
    cout << endl << "5. ";
    items[4].showARP();
    cout << endl << fixed << setprecision(2) << "6. $" << wronge_5;
    if (price5ChoicesElim[5])
        cout << " - X";
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #5

    else{
    cout << endl << fixed << setprecision(2) <<  "1. $" << wronga_5;
    if (price5ChoicesElim[0])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "2. $" << wrongb_5;
    if (price5ChoicesElim[1])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "3. $" << wrongc_5;
    if (price5ChoicesElim[2])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "4. $" << wrongd_5;
    if (price5ChoicesElim[3])
        cout << " - X";
    cout << endl << fixed << setprecision(2) << "5. $" << wronge_5;
    if (price5ChoicesElim[4])
        cout << " - X";
    cout << endl << "6. ";
    items[4].showARP();
    cout << endl << "7. Eliminate one of the wrong prices";
    cout << endl << "8. Quit with $12,000";
    } // end if price is #6

    while ( (choice5 < 1) || (choice5 > 8) ){
        cout << endl << "For $25,000, what is the correct price?: ";
        cin >> choice5;
    }
    if (choice5 == 8)
        bailedOnFifth = true;

    else if (choice5 == 7){
    if (pennies <= 1)
        cout << endl << "You don't have enough pennies to do that." << endl;
    else if (fifthsElim >= 5)
        cout << endl << "There are no more prices to eliminate." << endl;
    else{
        int randome4 = position5;
        while ( (randome4 == position5) || (price5ChoicesElim[randome4]) )
            randome4 = rand() % 6;
        pennies -= 1;
        price5ChoicesElim[randome4] = true;
        fifthsElim += 1;
        cout << endl << "You've spent one penny to eliminate a price." << endl;
    }
    } // end if player eliminated one of the prices

    else if (choice5 == 1){
    if (position5 == 0){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 0) && (!price5ChoicesElim[0]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[0] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #1

    else if (choice5 == 2){
    if (position5 == 1){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 1) && (!price5ChoicesElim[1]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[1] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #2

    else if (choice5 == 3){
    if (position5 == 2){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 2) && (!price5ChoicesElim[2]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[2] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #3

    else if (choice5 == 4){
    if (position5 == 3){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 3) && (!price5ChoicesElim[3]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[3] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #4

    else if (choice5 == 5){
    if (position5 == 4){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 4) && (!price5ChoicesElim[4]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[4] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #5

    else if (choice5 == 6){
    if (position5 == 5){
        cout << endl << "Yes, that's correct!";
        cout << endl;
        money = 25000;
        guessedFifth = true;
    }
    else if ( (position5 != 5) && (!price5ChoicesElim[5]) ){
        cout << endl << "Sorry, that's not correct. You've lost two pennies.";
        cout << endl;
        price5ChoicesElim[5] = true;
        fifthsElim += 1;
        pennies -= 2;
    }
    else{
        cout << endl << "You've already eliminated this answer. Please pick another one.";
        cout << endl;
    }
    } // end if player chose price #6

    } /// end while loop for fifth item

    } // else if player has less than five pennies on the last item

    } // end if guessed fourth

    } // end if guessed third
    } // end if guessed second

    if (bailedOnSec)
        cout << endl << "You're walking away with $1500. Thanks for playing!";
    if (bailedOnThird)
        cout << endl << "You're walking away with $3000. Thanks for playing!";
    if (bailedOnFourth)
        cout << endl << "You're walking away with $6000. Thanks for playing!";
    if (bailedOnFifth)
        cout << endl << "You're walking away with $12,000. Thanks for playing!";
    if (guessedFifth)
        cout << endl << "Congratulations, you win $25,000!";
    if (pennies <= 0)
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Vend-o-Price
void playVendOPrice()
{
    list<grocery> vopItems;
    list<grocery>::iterator vopItemIt;

    string t_vopDescription;
    string t_vopShortName;
    double t_vopPrice;

    grocery * vopptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/vopgrocery.txt");
    while (inFile)
    {
    vopptr = new grocery;
    if (inFile >> t_vopDescription >> t_vopShortName >> t_vopPrice)
    {
        vopptr->setDescription(t_vopDescription);
        vopptr->setShortName(t_vopShortName);
        vopptr->setPrice(t_vopPrice);
        vopItems.push_back(*vopptr);
        i++;
    }

    } // end while loop


    cout << "VEND-O-PRICE" << endl;

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

    grocery prize1;
    grocery prize2;
    grocery prize3;

    int z = 0;

    /// Set prize 1

    vopItemIt = vopItems.begin();
    for (z = 0; z < randomizationField[0]; z++)
    {
        vopItemIt++;
    }

    prize1.setDescription(vopItemIt->getDescription());
    prize1.setShortName(vopItemIt->getShortName());
    prize1.setPrice(vopItemIt->getPrice());


    /// Set prize 2

    vopItemIt = vopItems.begin();
    for (z = 0; z < randomizationField[1]; z++)
    {
        vopItemIt++;
    }

    prize2.setDescription(vopItemIt->getDescription());
    prize2.setShortName(vopItemIt->getShortName());
    prize2.setPrice(vopItemIt->getPrice());



    /// Set prize 3

    vopItemIt = vopItems.begin();
    for (z = 0; z < randomizationField[2]; z++)
    {
        vopItemIt++;
    }

    prize3.setDescription(vopItemIt->getDescription());
    prize3.setShortName(vopItemIt->getShortName());
    prize3.setPrice(vopItemIt->getPrice());

    /// These will be used so the products can be arranged from least to most expensive.
    grocery finalPrize1;
    grocery finalPrize2;
    grocery finalPrize3;


    if ( (prize1.getPrice() <= prize2.getPrice()) && (prize2.getPrice() <= prize3.getPrice()) ) /// 1, 2, 3
    {
    finalPrize1.setDescription(prize1.getDescription());
    finalPrize1.setShortName(prize1.getShortName());
    finalPrize1.setPrice(prize1.getPrice());

    finalPrize2.setDescription(prize2.getDescription());
    finalPrize2.setShortName(prize2.getShortName());
    finalPrize2.setPrice(prize2.getPrice());

    finalPrize3.setDescription(prize3.getDescription());
    finalPrize3.setShortName(prize3.getShortName());
    finalPrize3.setPrice(prize3.getPrice());
    }
    else if ( (prize1.getPrice() <= prize3.getPrice()) && (prize3.getPrice() <= prize2.getPrice()) ) /// 1, 3, 2
    {
    finalPrize1.setDescription(prize1.getDescription());
    finalPrize1.setShortName(prize1.getShortName());
    finalPrize1.setPrice(prize1.getPrice());

    finalPrize2.setDescription(prize3.getDescription());
    finalPrize2.setShortName(prize3.getShortName());
    finalPrize2.setPrice(prize3.getPrice());

    finalPrize3.setDescription(prize2.getDescription());
    finalPrize3.setShortName(prize2.getShortName());
    finalPrize3.setPrice(prize2.getPrice());
    }
    else if ( (prize2.getPrice() <= prize1.getPrice()) && (prize1.getPrice() <= prize3.getPrice()) ) /// 2, 1, 3
    {
    finalPrize1.setDescription(prize2.getDescription());
    finalPrize1.setShortName(prize2.getShortName());
    finalPrize1.setPrice(prize2.getPrice());

    finalPrize2.setDescription(prize1.getDescription());
    finalPrize2.setShortName(prize1.getShortName());
    finalPrize2.setPrice(prize1.getPrice());

    finalPrize3.setDescription(prize3.getDescription());
    finalPrize3.setShortName(prize3.getShortName());
    finalPrize3.setPrice(prize3.getPrice());
    }
    else if ( (prize2.getPrice() <= prize3.getPrice()) && (prize3.getPrice() <= prize1.getPrice()) ) /// 2, 3, 1
    {
    finalPrize1.setDescription(prize2.getDescription());
    finalPrize1.setShortName(prize2.getShortName());
    finalPrize1.setPrice(prize2.getPrice());

    finalPrize2.setDescription(prize3.getDescription());
    finalPrize2.setShortName(prize3.getShortName());
    finalPrize2.setPrice(prize3.getPrice());

    finalPrize3.setDescription(prize1.getDescription());
    finalPrize3.setShortName(prize1.getShortName());
    finalPrize3.setPrice(prize1.getPrice());
    }
    else if ( (prize3.getPrice() <= prize1.getPrice()) && (prize1.getPrice() <= prize2.getPrice()) ) /// 3, 1, 2
    {
    finalPrize1.setDescription(prize3.getDescription());
    finalPrize1.setShortName(prize3.getShortName());
    finalPrize1.setPrice(prize3.getPrice());

    finalPrize2.setDescription(prize1.getDescription());
    finalPrize2.setShortName(prize1.getShortName());
    finalPrize2.setPrice(prize1.getPrice());

    finalPrize3.setDescription(prize2.getDescription());
    finalPrize3.setShortName(prize2.getShortName());
    finalPrize3.setPrice(prize2.getPrice());
    }
    else /// 3, 2, 1
    {
    finalPrize1.setDescription(prize3.getDescription());
    finalPrize1.setShortName(prize3.getShortName());
    finalPrize1.setPrice(prize3.getPrice());

    finalPrize2.setDescription(prize2.getDescription());
    finalPrize2.setShortName(prize2.getShortName());
    finalPrize2.setPrice(prize2.getPrice());

    finalPrize3.setDescription(prize1.getDescription());
    finalPrize3.setShortName(prize1.getShortName());
    finalPrize3.setPrice(prize1.getPrice());
    }

    /// Generate multipliers for the grocery items.
    int multiplier1 = rand()%((9-7)+1)+7;

    int multiplier2 = multiplier1;
    while (multiplier2 == multiplier1)
        multiplier2 = rand()%((7-5)+1)+5;

    int multiplier3 = multiplier2;
    while (multiplier3 == multiplier2)
        multiplier3 = rand()%((5-3)+1)+3;

    /// Generate the total prices of each row
    double shelf1Total = finalPrize1.getPrice() * (double)multiplier1;
    double shelf2Total = finalPrize2.getPrice() * (double)multiplier2;
    double shelf3Total = finalPrize3.getPrice() * (double)multiplier3;

    int playerChoice = 12;

    /// Start the game itself
    cout << endl;

    cout << "1. ";
    finalPrize1.showPrize();
    cout << " x" << multiplier1 << endl;
    cout << "2. ";
    finalPrize2.showPrize();
    cout << " x" << multiplier2 << endl;
    cout << "3. ";
    finalPrize3.showPrize();
    cout << " x" << multiplier3 << endl;

    while (playerChoice > 3 || playerChoice < 1){
    cout << endl << "Which shelf is the most expensive?: ";
        cin >> playerChoice;
    }
    if (playerChoice == 1)
    {
        cout << endl << "The total of Shelf 2 is:" << endl;
        finalPrize2.showARP();
        cout << " x " << multiplier2 << " = $" << setprecision(2) << shelf2Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 3 is:" << endl;
        finalPrize3.showARP();
        cout << " x " << multiplier3 << " = $" << setprecision(2) << shelf3Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 1 is:" << endl;
        finalPrize1.showARP();
        cout << " x " << multiplier1 << " = $" << setprecision(2) << shelf1Total;
        cout << endl;

        if (shelf1Total >= shelf2Total && shelf1Total >= shelf3Total)
        {
            cout << endl << "Congratulations, you win!" << endl;
        }
        else
            cout << endl << "Sorry, you lose." << endl;
    } // end of where the player chooses Shelf 1

    else if (playerChoice == 2)
    {
        cout << endl << "The total of Shelf 1 is:" << endl;
        finalPrize1.showARP();
        cout << " x " << multiplier1 << " = $" << setprecision(2) << shelf1Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 3 is:" << endl;
        finalPrize3.showARP();
        cout << " x " << multiplier3 << " = $" << setprecision(2) << shelf3Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 2 is:" << endl;
        finalPrize2.showARP();
        cout << " x " << multiplier2 << " = $" << setprecision(2) << shelf2Total;
        cout << endl;

        if (shelf2Total >= shelf1Total && shelf2Total >= shelf3Total)
        {
            cout << endl << "Congratulations, you win!" << endl;
        }
        else
            cout << endl << "Sorry, you lose." << endl;
    } // end of where the player chooses Shelf 2

    else // here the player is assumed to have chosen Shelf 3
    {
        cout << endl << "The total of Shelf 1 is:" << endl;
        finalPrize1.showARP();
        cout << " x " << multiplier1 << " = $" << setprecision(2) << shelf1Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 2 is:" << endl;
        finalPrize2.showARP();
        cout << " x " << multiplier2 << " = $" << setprecision(2) << shelf2Total;
        cout << endl;
        system("pause");

        cout << endl << "The total of Shelf 3 is:" << endl;
        finalPrize3.showARP();
        cout << " x " << multiplier3 << " = $" << setprecision(2) << shelf3Total;
        cout << endl;

        if (shelf3Total >= shelf1Total && shelf3Total >= shelf2Total)
        {
            cout << endl << "Congratulations, you win!" << endl;
        }
        else
            cout << endl << "Sorry, you lose." << endl;
    } // end of where the player chooses Shelf 3

    cout << endl;
    inFile.close();
    system("pause");
    system("CLS");
}

#endif // GAMES_H_INCLUDED
