/// Car games are stored here.

#ifndef CARGAMES_H_INCLUDED
#define CARGAMES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <list>
#include <algorithm>
#include <string>

#include "prize.h"

using namespace std;

    /// Checks if the car price has a zero. Cars with zero in the price cannot be used in Lucky $even.
    bool hasZeros(int price)
    {
        bool flag = false;
        if (price < 100000)
        {
            int digits[5];
            digits[0] = price / 10000 % 10;
            digits[1] = price / 1000 % 10;
            digits[2] = price / 100 % 10;
            digits[3] = price / 10 % 10;
            digits[4] = price % 10;

            for (int x = 0; x < 5; x++)
            {
                if (digits[x] == 0)
                    flag = true;
            }
            if (flag)
                return true;
            else
                return false;
        }
        else
            return true; /// we'll implement this (maybe for MDS/Dream Car Week) later
    }

    /// Checks if a car's price contains either 0 or a number higher than 6. These cars do not work for Dice Game (sorry, ilovesuperball).
    bool incompatibleDiceGame(int price)
    {
        bool flag = false;
        if (price < 100000)
        {
            int digits[5];
            digits[0] = price / 10000 % 10;
            digits[1] = price / 1000 % 10;
            digits[2] = price / 100 % 10;
            digits[3] = price / 10 % 10;
            digits[4] = price % 10;

            for (int x = 0; x < 5; x++)
            {
                if ((digits[x] == 0) || (digits[x] > 6))
                    flag = true;
            }
            if (flag)
                return true;
            else
                return false;
        }
        else
            return true;
    }

    /// Checks if the first two digits and last two digits of the car's price are the same. These cars do not work for Money Game.
    bool incompatibleMoneyGame(int price)
    {
        bool flag = false;
        if (price < 100000)
        {
            int digits[5];
            digits[0] = price / 10000 % 10;
            digits[1] = price / 1000 % 10;
            digits[2] = price / 100 % 10;
            digits[3] = price / 10 % 10;
            digits[4] = price % 10;


        if ( (digits[0] == digits[3]) && (digits[1] == digits[4]) )
            return true;
        else
            return false;
        }
        else
            return true;
    }

    /// Checks if the car's price has no repeating digits. This is a requirement for games like 3 Strikes, Ten Chances, and Pocket Change.
    bool noRepeatingDigits(int price)
    {
        if (price < 100000){
        int digits[5];
        digits[0] = price / 10000 % 10;
        digits[1] = price / 1000 % 10;
        digits[2] = price / 100 % 10;
        digits[3] = price / 10 % 10;
        digits[4] = price % 10;
        if ( (digits[0] == digits[1]) || (digits[0] == digits[2]) || (digits[0] == digits[3]) || (digits[0] == digits[4]) )
            return false;
        else if ( (digits[1] == digits[2]) || (digits[1] == digits[3]) || (digits[1] == digits[4]) )
            return false;
        else if ( (digits[2] == digits[3]) || (digits[2] == digits[4]) )
            return false;
        else if ( digits[3] == digits[4] )
            return false;
        else
            return true;
        } // end if price has 5 digits
        else
            return false;

    }

    /// For Any Number, the first digit can appear elsewhere in the price, but not the last four.
    bool compatibleForAnyNumber(int price)
    {
        if (price < 100000){
        int digits[5];
        digits[0] = price / 10000 % 10;
        digits[1] = price / 1000 % 10;
        digits[2] = price / 100 % 10;
        digits[3] = price / 10 % 10;
        digits[4] = price % 10;
        if ( (digits[1] == digits[2]) || (digits[1] == digits[3]) || (digits[1] == digits[4]) )
            return false;
        else if ( (digits[2] == digits[3]) || (digits[2] == digits[4]) )
            return false;
        else if ( digits[3] == digits[4] )
            return false;
        else
            return true;
        }
        else
            return false;
    }

    /// For Any Number, checks if the medium prize has no repeating digits.
    bool medPrizeNoRepDigits(int price)
    {
        if (price < 1000){
        int digits[3];
        digits[0] = price / 100 % 10;
        digits[1] = price / 10 % 10;
        digits[2] = price % 10;
        if ( (digits[0] == digits[1]) || (digits[0] == digits[2]) || (digits[1] == digits[2]) )
            return false;
        else
            return true;
        }
        else
            return false;
    }

    /// For Any Number, checks if the medium prize can be paired with the car.
    bool medPrizeCompatible(int carPrice, int medPrice)
    {
        if (medPrice > 999)
            return false;
        else
        {
            int carDigits[5];
            int medDigits[3];
            carDigits[0] = carPrice / 10000 % 10;
            carDigits[1] = carPrice / 1000 % 10;
            carDigits[2] = carPrice / 100 % 10;
            carDigits[3] = carPrice / 10 % 10;
            carDigits[4] = carPrice % 10;

            medDigits[0] = medPrice / 100 % 10;
            medDigits[1] = medPrice / 10 % 10;
            medDigits[2] = medPrice % 10;

            if ( (carDigits[1] == medDigits[0]) || (carDigits[1] == medDigits[1]) || (carDigits[1] == medDigits[2]) )
                return false;
            else if ( (carDigits[2] == medDigits[0]) || (carDigits[2] == medDigits[1]) || (carDigits[2] == medDigits[2]) )
                return false;
            else if ( (carDigits[3] == medDigits[0]) || (carDigits[3] == medDigits[1]) || (carDigits[3] == medDigits[2]) )
                return false;
            else if ( (carDigits[4] == medDigits[0]) || (carDigits[4] == medDigits[1]) || (carDigits[4] == medDigits[2]) )
                return false;
            else
                return true;
        } // check if the medium prize is 3 digits
    }

    /// Checks if a digit is in the price of a car, but not the first digit. This is used in Any Number.
    bool inCarPrice(int carPrice, int digit)
    {
        if (digit > 9)
            return false ; // automatically returns false if you try a number greater than 9
        else
        {
            int carDigits[5];
            carDigits[0] = carPrice / 10000 % 10;
            carDigits[1] = carPrice / 1000 % 10;
            carDigits[2] = carPrice / 100 % 10;
            carDigits[3] = carPrice / 10 % 10;
            carDigits[4] = carPrice % 10;
            if (digit == carDigits[1])
                return true;
            else if (digit == carDigits[2])
                return true;
            else if (digit == carDigits[3])
                return true;
            else if (digit == carDigits[4])
                return true;
            else
                return false;
        }
    }

    /// Checks if a digit is in the price of a car, including the first digit
    bool inCarPriceIncDig1(int carPrice, int digit)
    {
        if (digit > 9)
            return false ; // automatically returns false if you try a number greater than 9
        else
        {
            int carDigits[5];
            carDigits[0] = carPrice / 10000 % 10;
            carDigits[1] = carPrice / 1000 % 10;
            carDigits[2] = carPrice / 100 % 10;
            carDigits[3] = carPrice / 10 % 10;
            carDigits[4] = carPrice % 10;
            if (digit == carDigits[0])
                return true;
            else if (digit == carDigits[1])
                return true;
            else if (digit == carDigits[2])
                return true;
            else if (digit == carDigits[3])
                return true;
            else if (digit == carDigits[4])
                return true;
            else
                return false;
        }
    }

    /// Checks if a digit is in the price of a medium prize. This is used in Any Number and Line 'em Up.
    bool inMedPrice(int medPrice, int digit)
    {
        if (digit > 9)
            return false;
        else
        {
        int medDigits[3];
        medDigits[0] = medPrice / 100 % 10;
        medDigits[1] = medPrice / 10 % 10;
        medDigits[2] = medPrice % 10;
        if (digit == medDigits[0])
            return true;
        else if (digit == medDigits[1])
            return true;
        else if (digit == medDigits[2])
            return true;
        else
            return false;
        }
    }

    /// Checks if a digit is in the price of a small prize.
    bool inSmallPrice(int smap, int digit)
    {
        if (digit > 9)
            return false;
        else
        {
            int smallDigits[2];
            smallDigits[0] = smap / 10 % 10;
            smallDigits[1] = smap % 10;
            if (digit == smallDigits[0])
                return true;
            else if (digit == smallDigits[1])
                return true;
            else
                return false;
        }
    }

    /// Takes an int and makes it show up as a proper Money Game space. This ensures that "El Cheapo" spaces show up correctly.
    string mgSpace(int value)
    {
        string r;
        if (value < 10)
            r = "0" + to_string(value);
        else
            r = to_string(value);
        return r;
    }

    /// Checks if a prize works for Line 'em Up (i.e., it has no repeating digits). This works for 2-digit and 3-digit prices.
    bool compatibleForLineEmUp(int price)
    {
        if (price < 100){
            if ( (price % 11) == 0)
                return false;
            else
                return true;
        } // 2-digit price
        else if (price < 1000){
            int prizeDigits[3];
            prizeDigits[0] = price / 100 % 10;
            prizeDigits[1] = price / 10 % 10;
            prizeDigits[2] = price % 10;

            if (prizeDigits[1] == prizeDigits[0])
                return false;
            else if (prizeDigits[2] == prizeDigits[0])
                return false;
            else if (prizeDigits[2] == prizeDigits[1])
                return false;
            else
                return true;

        } // 3-digit price
        else
            return false;
    }

    /// Uses a bubble sort algorithm to sort the number choices in Stack the Deck.
    void sortStackNumbers(int nos[])
    {
        int temp;
        int iter;
        int index;
        for (iter = 1; iter < 7; iter++)
        {
            for (index = 0; index < 7-iter; index++)
                if (nos[index] > nos[index + 1])
                {
                    temp = nos[index];
                    nos[index] = nos[index + 1];
                    nos[index + 1] = temp;
                }
        }
    }

    /// Uses a bubble sort algorithm to sort the numbers in 3 Strikes.
    void sortStrikesNos(int nos[])
    {
        int temp;
        int iter;
        int index;
        for (iter = 1; iter < 5; iter++)
        {
            for (index = 0; index < 5-iter; index++)
                if (nos[index] > nos[index + 1])
                {
                    temp = nos[index];
                    nos[index] = nos[index + 1];
                    nos[index + 1] = temp;
                }
        }
    }

    /// Uses a bubble sort algorithm to sort the numbers in Pocket Change.
    void sortPocketNos(int nos[])
    {
        int temp;
        int iter;
        int index;
        for (iter = 1; iter < 6; iter++)
        {
            for (index = 0; index < 6-iter; index++)
                if (nos[index] > nos[index + 1])
                {
                    temp = nos[index];
                    nos[index] = nos[index + 1];
                    nos[index + 1] = temp;
                }
        }
    }

    /// These are used to calculate how many chances the player gets in On the Nose.
    void sortDifferences(int nos[])
    {
        int temp;
        int iter;
        int index;
        for (iter = 1; iter < 4; iter++)
        {
            for (index = 0; index < 4-iter; index++)
                if (nos[index] > nos[index + 1])
                {
                    temp = nos[index];
                    nos[index] = nos[index + 1];
                    nos[index + 1] = temp;
                }
        }
    }

    /// These are used to calculate which digits belong in the 3-digit price for Split Decision
    void sortSplitPlaces(int nos[])
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

    /// Checks if a medium prize has exactly 2 different digits, and can therefore be used in Temptation.
    bool hasTwoDiffDigits(int price)
    {
    if (price < 1000) /// 3-digit price
    {
        int threes[3];
        threes[0] = price / 100 % 10;
        threes[1] = price / 10 % 10;
        threes[2] = price % 10;

        if ( (threes[0] == threes[1]) && (threes[0] == threes[2]) && (threes[1] == threes[2]) )
            return false;
        else if ( (threes[0] != threes[1]) && (threes[0] != threes[2]) && (threes[1] != threes[2]) )
            return false;
        else
            return true;
    } // end for three-digit price
    else    /// 4-digit price
    {
        int fours[4];
        fours[0] = price / 1000 % 10;
        fours[1] = price / 100 % 10;
        fours[2] = price / 10 % 10;
        fours[3] = price % 10;

        int check = 1;

        if (fours[1] != fours[0])
            check += 1;
        if ( (fours[2] != fours[0]) && (fours[2] != fours[1]) )
            check += 1;
        if ( (fours[3] != fours[0]) && (fours[3] != fours[1]) && (fours[3] != fours[2]) )
            check += 1;

        if (check == 2)
            return true;
        else
            return false;

    } // end for four-digit price

    }

    /// Checks if a number is in a medium prize's price.
    bool isInPrice(int number, int price)
    {
    if (price < 1000){
        int threes[3];
        threes[0] = price / 100 % 10;
        threes[1] = price / 10 % 10;
        threes[2] = price % 10;

        if (number == threes[0])
            return true;
        else if (number == threes[1])
            return true;
        else if (number == threes[2])
            return true;
        else
            return false;
    }
    else{
        int fours[4];
        fours[0] = price / 1000 % 10;
        fours[1] = price / 100 % 10;
        fours[2] = price / 10 % 10;
        fours[3] = price % 10;

        if (number == fours[0])
            return true;
        else if (number == fours[1])
            return true;
        else if (number == fours[2])
            return true;
        else if (number == fours[3])
            return true;
        else
            return false;
    }

    }

    /// Obtain the digits from a Temptation prize, returning a 2-digit number (e.g., a price of $755 would return 75).
    int obtainDigits(int price)
    {
    int result;
    if (price < 1000){
        int threes[3];
        threes[0] = price / 100 % 10;
        threes[1] = price / 10 % 10;
        threes[2] = price % 10;

        if (threes[1] == threes[0]) // digits 1 and 2 are the same, so digits 1 and 3 will be used
        {
            result = threes[0]*10 + threes[2];
            return result;
        }
        else // digits 1 and 3 are the same, so digits 1 and 2 will be used
        {
            result = threes[0]*10 + threes[1];
            return result;
        }
    } // end if price is 3 digits
    else{
        int fours[4];
        fours[0] = price / 1000 % 10;
        fours[1] = price / 100 % 10;
        fours[2] = price / 10 % 10;
        fours[3] = price % 10;

        if (fours[1] == fours[0]) // digits 1 and 2 are the same (AABB or AABA)
        {
            // price is either AABB or AABA
            if (fours[2] != fours[0]){
            result = fours[0]*10 + fours[2];
            return result;
            }
            // price is AAAB
            else{
            result = fours[0]*10 + fours[3];
            return result;
            }

        }
        else
        {
            result = fours[0]*10 + fours[1];
            return result;
        }

    } // end if price is 4 digits

    }

    /// Coordinates on a multidimensional array for a tile in Pathfinder.
    struct tile{
    int a;
    int b;
    };

    bool isValid(tile myTile){
    if (myTile.a < 0)
        return false;
    else if (myTile.b < 0)
        return false;
    else if (myTile.a > 4)
        return false;
    else if (myTile.b > 4)
        return false;
    else
        return true;
    }

    /// Returns true if on one of the corners of the grid.
    bool isCorner(tile myTile){
    if ( (myTile.a == 0) && (myTile.b == 0) )
        return true;
    else if ( (myTile.a == 0) && (myTile.b == 4) )
        return true;
    else if ( (myTile.a == 4) && (myTile.b == 0) )
        return true;
    else if ( (myTile.a == 4) && (myTile.b == 4) )
        return true;
    else
        return false;
    }

    /// Returns true if on the top edge but not a corner.
    bool onTopEdge(tile myTile){
    if ( (myTile.a == 0) && (!isCorner(myTile)) )
        return true;
    else
        return false;
    }

    /// Returns true if on the bottom edge but not a corner.
    bool onBottomEdge(tile myTile){
    if ( (myTile.a == 4) && (!isCorner(myTile)) )
        return true;
    else
        return false;
    }

    /// Returns true if on the left edge but not a corner.
    bool onLeftEdge(tile myTile){
    if ( (myTile.b == 0) && (!isCorner(myTile)) )
        return true;
    else
        return false;
    }

    /// Returns true if on the right edge but not a corner.
    bool onRightEdge(tile myTile){
    if ( (myTile.b == 4) && (!isCorner(myTile)) )
        return true;
    else
        return false;
    }

    bool onEdge(tile myTile){
    if (onTopEdge(myTile))
        return true;
    else if (onBottomEdge(myTile))
        return true;
    else if (onLeftEdge(myTile))
        return true;
    else if (onRightEdge(myTile))
        return true;
    else
        return false;
    }

    /// Returns true if a set of prizes can be used in Golden Road.
    bool forGoldenRoad(double grocPrice, int medPrice, int largePrice, int carPrice){
    int groDigits[2];
    int medDigits[3];
    int larDigits[4];
    int carDigits[5];

    medDigits[0] = medPrice / 100 % 10;
    medDigits[1] = medPrice / 10 % 10;
    medDigits[2] = medPrice % 10;

    larDigits[0] = largePrice / 1000 % 10;
    larDigits[1] = largePrice / 100 % 10;
    larDigits[2] = largePrice / 10 % 10;
    larDigits[3] = largePrice % 10;

    if (grocPrice > 0.98)
        return false;
    else
    {
    double temp = grocPrice * 100;
    int grocHold = static_cast<int>(temp);
    if (grocHold % 11 == 0)
        return false;
    else if (grocHold % 10 == 0)
        return false;
    else{
        /// Check if the medium prize has repeating digits.
        if ( (medDigits[1] == medDigits[0]) || (medDigits[2] == medDigits[0]) || (medDigits[2] == medDigits[1]) )
            return false;
        /// Check if the large prize has repeating digits.
        else if ( (larDigits[1] == larDigits[0]) || (larDigits[2] == larDigits[0]) || (larDigits[2] == larDigits[1]) ||
                  (larDigits[3] == larDigits[0]) || (larDigits[3] == larDigits[1]) || (larDigits[3] == larDigits[2]) ||
                  (larDigits[4] == larDigits[0]) || (larDigits[4] == larDigits[1]) || (larDigits[4] == larDigits[2]) || (larDigits[4] == larDigits[3]) )
            return false;
        else{
            groDigits[0] = grocHold / 10 % 10;
            groDigits[1] = grocHold % 10;

            carDigits[0] = carPrice / 10000 % 10;
            carDigits[1] = carPrice / 1000 % 10;
            carDigits[2] = carPrice / 100 % 10;
            carDigits[3] = carPrice / 10 % 10;
            carDigits[4] = carPrice % 10;

            if ( ((groDigits[0] == medDigits[0]) || (groDigits[1] == medDigits[0])) &&
                 ((medDigits[0] == larDigits[1]) || (medDigits[1] == larDigits[1]) || (medDigits[2] == larDigits[1])) &&
                 ((larDigits[0] == carDigits[2]) || (larDigits[1] == carDigits[2]) || (larDigits[2] == carDigits[2]) || (larDigits[3] == carDigits[2])))
                return true;
            else
                return false;
        } // neither the medium prize nor large prize has repeating digits
    } // grocery price isn't divisible by 10 or 11

    } // grocery price is less than $1


    }

    bool compatibleForSwitcheroo(int price){
        int digits[5];
        digits[0] = price / 10000 % 10;
        digits[1] = price / 1000 % 10;
        digits[2] = price / 100 % 10;
        digits[3] = price / 10 % 10;
        digits[4] = price % 10;
        if (digits[3] == 0)
            return false;
        else
            return true;
    }

    /// Shows a trivia question for a digit in Professor Price. "which" will be a random number 0-2, for some variety.
    void showTrivia(int digit, int which){
    if ( (digit == 1) && (which == 0) )
        cout << endl << "What is the atomic number of hydrogen?: ";
    else if ( (digit == 1) && (which == 1) )
        cout << endl << "What number do you get if you divide any number by itself?: ";
    else if ( (digit == 1) && (which == 2) )
        cout << endl << "How many stars are on the flag of Texas?: ";
    else if ( (digit == 2) && (which == 0) )
        cout << endl << "Which dollar bill has Thomas Jefferson on the front?: ";
    else if ( (digit == 2) && (which == 1) )
        cout << endl << "What is the only even prime number?: ";
    else if ( (digit == 2) && (which == 2) )
        cout << endl << "How many wheels does a bicycle have?: ";
    else if ( (digit == 3) && (which == 0) )
        cout << endl << "In American football, how many points is a field goal worth?: ";
    else if ( (digit == 3) && (which == 1) )
        cout << endl << "How many primary colors of light are there?: ";
    else if ( (digit == 3) && (which == 2) )
        cout << endl << "How many face cards are in one suit in a deck of playing cards?: ";
    else if ( (digit == 4) && (which == 0) )
        cout << endl << "How many points are on a compass?: ";
    else if ( (digit == 4) && (which == 1) )
        cout << endl << "How many sides does a trapezoid have?: ";
    else if ( (digit == 4) && (which == 2) )
        cout << endl << "How many terrestrial planets are there in the solar system?: ";
    else if ( (digit == 5) && (which == 0) )
        cout << endl << "What is the highest category number on the Saffir-Simpson hurricane wind scale?: ";
    else if ( (digit == 5) && (which == 1) )
        cout << endl << "How many appendages does a starfish have?: ";
    else if ( (digit == 5) && (which == 2) )
        cout << endl << "How many cents is a nickel?: ";
    else if ( (digit == 6) && (which == 0) )
        cout << endl << "How many faces does a cube have?: ";
    else if ( (digit == 6) && (which == 1) )
        cout << endl << "How many strings does a standard guitar have?: ";
    else if ( (digit == 6) && (which == 2) )
        cout << endl << "How many wives did Henry VIII have?: ";
    else if ( (digit == 7) && (which == 0) )
        cout << endl << "How many different tones are there on a major scale?: ";
    else if ( (digit == 7) && (which == 1) )
        cout << endl << "What number do opposite sides of a die add up to?: ";
    else if ( (digit == 7) && (which == 2) )
        cout << endl << "What number indicates a neutral pH?: ";
    else if ( (digit == 8) && (which == 0) )
        cout << endl << "How many legs does a spider have?: ";
    else if ( (digit == 8) && (which == 1) )
        cout << endl << "How many bits equal one byte?: ";
    else if ( (digit == 8) && (which == 2) )
        cout << endl << "What number does the black ball in pool have on it?: ";
    else if ( (digit == 9) && (which == 0) )
        cout << endl << "In Greek mythology, how many Muses were there?: ";
    else if ( (digit == 9) && (which == 1) )
        cout << endl << "How many justices sit on the U.S. Supreme Court?: ";
    else if ( (digit == 9) && (which == 2) )
        cout << endl << "How many months does a typical human pregnancy last?: ";
    else if ( (digit == 0) && (which == 0) )
        cout << endl << "In tennis, \"love\" represents a score of what?: ";
    else if ( (digit == 0) && (which == 1) )
        cout << endl << "In degrees Celsius, what is the freezing point of water?: ";
    else if ( (digit == 0) && (which == 2) )
        cout << endl << "What number do most programming languages begin arrays with?: ";
    }

    /// In this game's modernized take on Telephone Game, the car's price will be listed as in the original, alongside
    /// two 4-digit prizes' prices with a number before them. Therefore, the second digit in the car's price can't be 0.
    bool compatibleForTelephoneGame(int price){
        int digits[5];
        digits[0] = price / 10000 % 10;
        digits[1] = price / 1000 % 10;
        digits[2] = price / 100 % 10;
        digits[3] = price / 10 % 10;
        digits[4] = price % 10;
        if (digits[1] == 0)
            return false;
        else
            return true;
    }

    /// Rounds a car price down to the nearest multiple of 5000. This is used in games with multiple car prices, like
    /// Five Price Tags and Gas Money.
    int roundDown(int price){
        return price - (price % 5000);
    }

/// Add 'em Up
void playAddEmUp()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "ADD 'EM UP" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int total = digits[0] + digits[1] + digits[2] + digits[3] + digits[4];

    bool revealed[5];
    for (int r = 0; r < 5; r++)
        revealed[r] = false;

    /// This will be 0 if the digit hasn't been guessed, 1 if it's guessed and in the price,
    /// and 2 if it's guessed and isn't in the price.
    int digitOn[10];
    for (int d = 0; d < 10; d++)
        digitOn[d] = 0;

    cout << endl << endl << "$*****";
    cout << endl << "Total: " << total;

    cout << endl;

    int freePos = 0;

    while ( (freePos < 1) || (freePos > 5) ){
        cout << endl << "Which digit (1-5) do you want for free?: ";
        cin >> freePos;
        }
    revealed[freePos-1] = true;

    int r1 = digits[freePos-1];
    digitOn[r1] = 1;
    int r2;
    int r3;
    int r4;
    int r5;

    int chances = 3;
    bool lost = false;
    bool won = false;

    int on = 1;

    while ( (!won) && (!lost) ){
        cout << endl << "$";
        for (int p = 0; p < 5; p++){
        if (revealed[p])
            cout << digits[p];
        else
            cout << "*";
        }
        if (on == 1){
            cout << endl << r1 << " + ? + ? + ? + ? = " << total;
            cout << endl << "So far: " << r1;
            }
        else if (on == 2){
            cout << endl << r1 << " + " << r2 << " + ? + ? + ? = " << total;
            cout << endl << "So far: " << r1+r2;
            }
        else if (on == 3){
            cout << endl << r1 << " + " << r2 << " + " << r3 << " + ? + ? = " << total;
            cout << endl << "So far: " << r1+r2+r3;
            }
        else if (on == 4){
            cout << endl << r1 << " + " << r2 << " + " << r3 << " + " << r4 << " + ? = " << total;
            cout << endl << "So far: " << r1+r2+r3+r4;
            }
        cout << endl << endl << "0123456789";
        cout << endl;
        for (int n = 0; n < 10; n++){
            if (digitOn[n] == 0)
                cout << "*";
            else if (digitOn[n] == 1)
                cout << "O";
            else
                cout << "X";
        }
        cout << endl << endl << "Chances left: " << chances;

        int choice = 10;
        while ((choice < 0) || (choice > 9)){
            cout << endl << "Enter a number you think is in the price of the car: ";
                cin >> choice;
            if (digitOn[choice] != 0){
                cout << endl << "You've already chosen this number. Please pick another.";
                choice = 10;
            }
        } // end while loop involving digit entry

        if (choice == digits[0]){
            cout << endl << "Yes, that's correct.";
            revealed[0] = true;
            digitOn[choice] = 1;
            if (on == 1)
                r2 = choice;
            else if (on == 2)
                r3 = choice;
            else if (on == 3)
                r4 = choice;
            else if (on == 4)
                r5 = choice;
            on++;
        }
        else if (choice == digits[1]){
            cout << endl << "Yes, that's correct.";
            revealed[1] = true;
            digitOn[choice] = 1;
            if (on == 1)
                r2 = choice;
            else if (on == 2)
                r3 = choice;
            else if (on == 3)
                r4 = choice;
            else if (on == 4)
                r5 = choice;
            on++;
        }
        else if (choice == digits[2]){
            cout << endl << "Yes, that's correct.";
            revealed[2] = true;
            digitOn[choice] = 1;
            if (on == 1)
                r2 = choice;
            else if (on == 2)
                r3 = choice;
            else if (on == 3)
                r4 = choice;
            else if (on == 4)
                r5 = choice;
            on++;
        }
        else if (choice == digits[3]){
            cout << endl << "Yes, that's correct.";
            revealed[3] = true;
            digitOn[choice] = 1;
            if (on == 1)
                r2 = choice;
            else if (on == 2)
                r3 = choice;
            else if (on == 3)
                r4 = choice;
            else if (on == 4)
                r5 = choice;
            on++;
        }
        else if (choice == digits[4]){
            cout << endl << "Yes, that's correct.";
            revealed[4] = true;
            digitOn[choice] = 1;
            if (on == 1)
                r2 = choice;
            else if (on == 2)
                r3 = choice;
            else if (on == 3)
                r4 = choice;
            else if (on == 4)
                r5 = choice;
            on++;
        }
        else{
            cout << endl << "Sorry, that number isn't in the price.";
            digitOn[choice] = 2;
            chances -= 1;
        }

        if (on == 5)
            won = true;
        else if (chances == 0)
            lost = true;

    } // end while loop

    cout << endl << "$" << carPrice;

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Any Number
void playAnyNumber()
{
    /// car
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    /// medium prize
    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    int i = 0;
    int j = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && compatibleForAnyNumber(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

   /// Load the medium prizes
    inFile.open("./prizes/" + medInput);
    while (inFile){
    mptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price < 1000) && medPrizeNoRepDigits(m_Price) )
    {
        mptr->setDescription(m_Description);
        mptr->setShortName(m_ShortName);
        mptr->setPrice(m_Price);
        gameMeds.push_back(*mptr);
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();



    cout << "ANY NUMBER" << endl;

    srand(time(0));
    bool found = false;
    int ofCars;
    int ofMeds;
    int z1;
    int z2;

    car prizeCar;
    medium prizeMed;

    /// Keep generating a random combination of car/smaller prizes until you get one that works.
    /// This will work a bit differently from past games, although the underlying code isn't hugely different.
    while (!found)
    {
        ofCars = rand() % i;
        ofMeds = rand() % j;
        gameCarIt = gameCars.begin();
        for (z1 = 0; z1 < ofCars; z1++)
            gameCarIt++;
        prizeCar.setModel(gameCarIt->getModel());
        prizeCar.setOptions(gameCarIt->getOptions());
        prizeCar.setPrice(gameCarIt->getPrice());

        gameMedIt = gameMeds.begin();
        for (z2 = 0; z2 < ofMeds; z2++)
            gameMedIt++;
        prizeMed.setDescription(gameMedIt->getDescription());
        prizeMed.setShortName(gameMedIt->getShortName());
        prizeMed.setPrice(gameMedIt->getPrice());

        if ( medPrizeCompatible(prizeCar.getPrice(), prizeMed.getPrice()) )
            found = true;
    }

    int piggyBank[3];

    /// Load the digits in the piggy bank's price.

    /// First digit
    if ( !inCarPrice(prizeCar.getPrice(), 0) && !inMedPrice(prizeMed.getPrice(), 0) )
        piggyBank[0] = 0;
    else if ( !inCarPrice(prizeCar.getPrice(), 1) && !inMedPrice(prizeMed.getPrice(), 1) )
        piggyBank[0] = 1;
    else if ( !inCarPrice(prizeCar.getPrice(), 2) && !inMedPrice(prizeMed.getPrice(), 2) )
        piggyBank[0] = 2;
    else if ( !inCarPrice(prizeCar.getPrice(), 3) && !inMedPrice(prizeMed.getPrice(), 3) )
        piggyBank[0] = 3;
    else if ( !inCarPrice(prizeCar.getPrice(), 4) && !inMedPrice(prizeMed.getPrice(), 4) )
        piggyBank[0] = 4;
    else if ( !inCarPrice(prizeCar.getPrice(), 5) && !inMedPrice(prizeMed.getPrice(), 5) )
        piggyBank[0] = 5;
    else if ( !inCarPrice(prizeCar.getPrice(), 6) && !inMedPrice(prizeMed.getPrice(), 6) )
        piggyBank[0] = 6;
    else if ( !inCarPrice(prizeCar.getPrice(), 7) && !inMedPrice(prizeMed.getPrice(), 7) )
        piggyBank[0] = 7;
    else if ( !inCarPrice(prizeCar.getPrice(), 8) && !inMedPrice(prizeMed.getPrice(), 8) )
        piggyBank[0] = 8;
    else
        piggyBank[0] = 9;

    /// Second digit
    if ( !inCarPrice(prizeCar.getPrice(), 0) && !inMedPrice(prizeMed.getPrice(), 0) && (piggyBank[0] != 0) )
        piggyBank[1] = 0;
    else if ( !inCarPrice(prizeCar.getPrice(), 1) && !inMedPrice(prizeMed.getPrice(), 1) && (piggyBank[0] != 1) )
        piggyBank[1] = 1;
    else if ( !inCarPrice(prizeCar.getPrice(), 2) && !inMedPrice(prizeMed.getPrice(), 2) && (piggyBank[0] != 2) )
        piggyBank[1] = 2;
    else if ( !inCarPrice(prizeCar.getPrice(), 3) && !inMedPrice(prizeMed.getPrice(), 3) && (piggyBank[0] != 3) )
        piggyBank[1] = 3;
    else if ( !inCarPrice(prizeCar.getPrice(), 4) && !inMedPrice(prizeMed.getPrice(), 4) && (piggyBank[0] != 4) )
        piggyBank[1] = 4;
    else if ( !inCarPrice(prizeCar.getPrice(), 5) && !inMedPrice(prizeMed.getPrice(), 5) && (piggyBank[0] != 5) )
        piggyBank[1] = 5;
    else if ( !inCarPrice(prizeCar.getPrice(), 6) && !inMedPrice(prizeMed.getPrice(), 6) && (piggyBank[0] != 6) )
        piggyBank[1] = 6;
    else if ( !inCarPrice(prizeCar.getPrice(), 7) && !inMedPrice(prizeMed.getPrice(), 7) && (piggyBank[0] != 7) )
        piggyBank[1] = 7;
    else if ( !inCarPrice(prizeCar.getPrice(), 8) && !inMedPrice(prizeMed.getPrice(), 8) && (piggyBank[0] != 8) )
        piggyBank[1] = 8;
    else
        piggyBank[1] = 9;

    /// Third digit
    if ( !inCarPrice(prizeCar.getPrice(), 0) && !inMedPrice(prizeMed.getPrice(), 0) && (piggyBank[0] != 0) && (piggyBank[1] != 0) )
        piggyBank[2] = 0;
    else if ( !inCarPrice(prizeCar.getPrice(), 1) && !inMedPrice(prizeMed.getPrice(), 1) && (piggyBank[0] != 1) && (piggyBank[1] != 1) )
        piggyBank[2] = 1;
    else if ( !inCarPrice(prizeCar.getPrice(), 2) && !inMedPrice(prizeMed.getPrice(), 2) && (piggyBank[0] != 2) && (piggyBank[1] != 2) )
        piggyBank[2] = 2;
    else if ( !inCarPrice(prizeCar.getPrice(), 3) && !inMedPrice(prizeMed.getPrice(), 3) && (piggyBank[0] != 3) && (piggyBank[1] != 3) )
        piggyBank[2] = 3;
    else if ( !inCarPrice(prizeCar.getPrice(), 4) && !inMedPrice(prizeMed.getPrice(), 4) && (piggyBank[0] != 4) && (piggyBank[1] != 4) )
        piggyBank[2] = 4;
    else if ( !inCarPrice(prizeCar.getPrice(), 5) && !inMedPrice(prizeMed.getPrice(), 5) && (piggyBank[0] != 5) && (piggyBank[1] != 5) )
        piggyBank[2] = 5;
    else if ( !inCarPrice(prizeCar.getPrice(), 6) && !inMedPrice(prizeMed.getPrice(), 6) && (piggyBank[0] != 6) && (piggyBank[1] != 6) )
        piggyBank[2] = 6;
    else if ( !inCarPrice(prizeCar.getPrice(), 7) && !inMedPrice(prizeMed.getPrice(), 7) && (piggyBank[0] != 7) && (piggyBank[1] != 7) )
        piggyBank[2] = 7;
    else if ( !inCarPrice(prizeCar.getPrice(), 8) && !inMedPrice(prizeMed.getPrice(), 8) && (piggyBank[0] != 8) && (piggyBank[1] != 8) )
        piggyBank[2] = 8;
    else
        piggyBank[2] = 9;

    random_shuffle(&piggyBank[0], &piggyBank[2]);

    prizeMed.showPrize();
    cout << endl;

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    cout << endl;

    //cout << prizeCar.getPrice() << endl << prizeMed.getPrice();
    //cout << endl << "Piggy bank: $" << piggyBank[0] << "." << piggyBank[1] << piggyBank[2] << endl;

    /// Checks if the digits have been revealed.
    bool carDigitRevealed[5];
    for (int f = 0; f < 5; f++)
        carDigitRevealed[f] = false;

    bool prizeDigitRevealed[3];
    for (int e = 0; e < 3; e++)
        prizeDigitRevealed[e] = false;

    bool piggyDigitRevealed[3];
    for (int d = 0; d < 3; d++)
        piggyDigitRevealed[d] = false;

    /// Separate bools that check if each digit has been revealed.
    bool digitRevealed[10];
    for (int c = 0; c < 10; c++)
        digitRevealed[c] = false;

    /// Get the digits of the prizes.
    int car1 = prizeCar.getPrice() / 10000 % 10;
    int car2 = prizeCar.getPrice() / 1000 % 10;
    int car3 = prizeCar.getPrice() / 100 % 10;
    int car4 = prizeCar.getPrice() / 10 % 10;
    int car5 = prizeCar.getPrice() % 10;

    int med1 = prizeMed.getPrice() / 100 % 10;
    int med2 = prizeMed.getPrice() / 10 % 10;
    int med3 = prizeMed.getPrice() % 10;

    bool wonCar = false;
    bool wonPrize = false;
    bool wonPiggy = false;

    while (!wonCar && !wonPrize && !wonPiggy)
    {
        cout << endl << "CAR - $";
        cout << car1;
        if (carDigitRevealed[1])
            cout << car2;
        else
            cout << "*";
        if (carDigitRevealed[2])
            cout << car3;
        else
            cout << "*";
        if (carDigitRevealed[3])
            cout << car4;
        else
            cout << "*";
        if (carDigitRevealed[4])
            cout << car5;
        else
            cout << "*";
        cout << endl;
        prizeMed.showShortName();
        cout << " - $";
        if (prizeDigitRevealed[0])
            cout << med1;
        else
            cout << "*";
        if (prizeDigitRevealed[1])
            cout << med2;
        else
            cout << "*";
        if (prizeDigitRevealed[2])
            cout << med3;
        else
            cout << "*";
        cout << endl << "PIGGY BANK - $";
        if (piggyDigitRevealed[0])
            cout << piggyBank[0];
        else
            cout << "*";
        cout << ".";
        if (piggyDigitRevealed[1])
            cout << piggyBank[1];
        else
            cout << "*";
        if (piggyDigitRevealed[2])
            cout << piggyBank[2];
        else
            cout << "*";
        int choice = 10;
        while ( (choice < 0) || (choice > 9) ){
            cout << endl << "Which digit do you want?: ";
            cin >> choice;
            }
        if ( (digitRevealed[choice]) )
            cout << endl << "You've already revealed this digit. Please pick another.";
        else
        {
            digitRevealed[choice] = true;
            if (choice == car2)
                carDigitRevealed[1] = true;
            else if (choice == car3)
                carDigitRevealed[2] = true;
            else if (choice == car4)
                carDigitRevealed[3] = true;
            else if (choice == car5)
                carDigitRevealed[4] = true;
            else if (choice == med1)
                prizeDigitRevealed[0] = true;
            else if (choice == med2)
                prizeDigitRevealed[1] = true;
            else if (choice == med3)
                prizeDigitRevealed[2] = true;
            else if (choice == piggyBank[0])
                piggyDigitRevealed[0] = true;
            else if (choice == piggyBank[1])
                piggyDigitRevealed[1] = true;
            else
                piggyDigitRevealed[2] = true;

            /// check if all of an item's digits are revealed
            if (carDigitRevealed[1] && carDigitRevealed[2] && carDigitRevealed[3] && carDigitRevealed[4])
                wonCar = true;
            else if (prizeDigitRevealed[0] && prizeDigitRevealed[1] && prizeDigitRevealed[2])
                wonPrize = true;
            else if (piggyDigitRevealed[0] && piggyDigitRevealed[1] && piggyDigitRevealed[2])
                wonPiggy = true;
        }
    } // end while loop

        cout << endl << "CAR - $";
        cout << car1;
        if (carDigitRevealed[1])
            cout << car2;
        else
            cout << "*";
        if (carDigitRevealed[2])
            cout << car3;
        else
            cout << "*";
        if (carDigitRevealed[3])
            cout << car4;
        else
            cout << "*";
        if (carDigitRevealed[4])
            cout << car5;
        else
            cout << "*";
        cout << endl;
        prizeMed.showShortName();
        cout << " - $";
        if (prizeDigitRevealed[0])
            cout << med1;
        else
            cout << "*";
        if (prizeDigitRevealed[1])
            cout << med2;
        else
            cout << "*";
        if (prizeDigitRevealed[2])
            cout << med3;
        else
            cout << "*";
        cout << endl << "PIGGY BANK - $";
        if (piggyDigitRevealed[0])
            cout << piggyBank[0];
        else
            cout << "*";
        cout << ".";
        if (piggyDigitRevealed[1])
            cout << piggyBank[1];
        else
            cout << "*";
        if (piggyDigitRevealed[2])
            cout << piggyBank[2];
        else
            cout << "*";

        if (wonCar)
            cout << endl << "Congratulations, you win!";
        else if (wonPrize){
            cout << endl << "Well, at least you won the ";
            prizeMed.showShortName();
            cout << ".";
        }
        else
            cout << endl << "You won the piggy bank...";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Bullseye (1972)
void playBullseye72()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > 15000) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "BULLSEYE (1972)" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    /// Calculate bounds
    int lowerBound = carPrice - (carPrice % 1000);
    int upperBound = lowerBound + 1000;

    int chances = 7;

    cout << endl << "Range: $" << lowerBound << "-$" << upperBound;
    bool won = false;

    while ( (chances > 0) && (!won) )
    {
        cout << endl << "Chances left: " << chances << endl;
        int bid = 0;
        while (bid == 0){
        cout << endl << "How much do you think the car is?: $";
        cin >> bid;
        }
        if (bid == carPrice)
            won = true;
        else if (carPrice > bid){
            cout << endl << "The car's price is HIGHER than your bid";
            chances -= 1;
        }
        else if (carPrice < bid){
            cout << endl << "The car's price is LOWER than your bid";
            chances -= 1;
        }
    }

    if (won)
        cout << endl << "Congratulations, you won! \nYou've accomplished a feat no contestant ever did!";
    else
        cout << endl << "Sorry, you lose. The ARP was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Card Game
void playCardGame()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > 16000) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "CARD GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int cards[52] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
                     8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13};

    int ranges[7] = {1000, 1000, 2000, 2000, 3000, 3000, 5000};

    random_shuffle(&cards[0], &cards[52]);
    int playerRange = ranges[rand() % 7];

    int startingBid;
    if (carPrice < 25000)
        startingBid = 15000;
    else if ( (carPrice > 25000) && (carPrice < 30000) )
        startingBid = 20000;
    else
        startingBid = 25000;

    bool stoppedDrawing = false;

    cout << endl << "Let's see your range..." << endl;
    //system("pause");
    cout << endl << "You need to be within $" << playerRange << endl;
    int onCard = 0;
    while ( (onCard < 52) && (stoppedDrawing == false) )
    {
        int aceValue = 0;
        char decision = 'A';
        cout << endl << "Range: $" << playerRange;
        cout << endl << "Bid: $" << startingBid;
        cout << endl << "Press any key to draw a card." << endl;
        system("pause");
        if ( (cards[onCard] > 1) && (cards[onCard] < 11) ){ /// number between 2 and 10
            if (cards[onCard] == 8)
                cout << endl << "You drew an " << cards[onCard];
            else
                cout << endl << "You drew a " << cards[onCard];
            startingBid += cards[onCard]*100;
            } /// end if
        else if (cards[onCard] == 11) /// jack
        {
            cout << endl << "You drew a jack";
            startingBid += 1000;
        }
        else if (cards[onCard] == 12) /// queen
        {
            cout << endl << "You drew a queen";
            startingBid += 1000;
        }
        else if (cards[onCard] == 13) /// king
        {
            cout << endl << "You drew a king";
            startingBid += 1000;
        }
        else if (cards[onCard] == 1) /// ace
        {
            cout << endl << "You drew an ace";
            cout << endl << "You can set the car's price to anything you want.";
            while (aceValue <= startingBid)
            {
                cout << endl << "What do you think is the price?: ";
                cin >> aceValue;
            }
            startingBid = aceValue;
        }
        cout << endl << "Bid: $" << startingBid;
        while ( (decision != 'Y') && (decision != 'N') &&  (decision != 'y') && (decision != 'n') ){
        cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
        cin >> decision;
        }
        if ((decision == 'Y') || (decision == 'y'))
            onCard += 1;
        else
            stoppedDrawing = true;

    } /// end while loop

    int difference = 0;
    cout << endl << "Your bid is $" << startingBid;
    cout << endl << "The actual retail price of the car is $" << carPrice;
    if (startingBid > carPrice)
        cout << endl << "Sorry, you went over.";
    else
    {
        int difference = carPrice - startingBid;
        cout << endl << "For a difference of $" << difference;
        if (difference <= playerRange)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";

    }


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Cover Up
void playCoverUp()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "COVER UP" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int dig1Choices[2];
    int dig2Choices[3];
    int dig3Choices[4];
    int dig4Choices[5];
    int dig5Choices[6];

    /// Initialize choices for digit #1
    dig1Choices[0] = digits[0];
    dig1Choices[1] = digits[0];
    while (dig1Choices[1] == digits[0])
        dig1Choices[1] = (rand() % 3) + 1;
    random_shuffle(&dig1Choices[0], &dig1Choices[2]);
    bool chosenDig1[2];
    for (int h = 0; h < 2; h++)
        chosenDig1[h] = false;

    /// Initialize choices for digit #2
    dig2Choices[0] = digits[1];
    dig2Choices[1] = digits[1];
    while (dig2Choices[1] == digits[1])
        dig2Choices[1] = rand() % 10;
    dig2Choices[2] = digits[1];
    while ( (dig2Choices[2] == digits[1]) || (dig2Choices[2] == dig2Choices[1]) )
        dig2Choices[2] = rand() % 10;
    random_shuffle(&dig2Choices[0], &dig2Choices[3]);
    bool chosenDig2[3];
    for (int h = 0; h < 3; h++)
        chosenDig2[h] = false;

    /// Initialize choices for digit #3
    dig3Choices[0] = digits[2];
    dig3Choices[1] = digits[2];
    while (dig3Choices[1] == digits[2])
        dig3Choices[1] = rand() % 10;
    dig3Choices[2] = digits[2];
    while ( (dig3Choices[2] == digits[2]) || (dig3Choices[2] == dig3Choices[1]) )
        dig3Choices[2] = rand() % 10;
    dig3Choices[3] = digits[3];
    while ( (dig3Choices[3] == digits[2]) || (dig3Choices[3] == dig3Choices[1]) || (dig3Choices[3] == dig3Choices[2]) )
        dig3Choices[3] = rand() % 10;
    random_shuffle(&dig3Choices[0], &dig3Choices[4]);
    bool chosenDig3[4];
    for (int h = 0; h < 4; h++)
        chosenDig3[h] = false;

    /// Initialize choices for digit #4
    dig4Choices[0] = digits[3];
    dig4Choices[1] = digits[3];
    while (dig4Choices[1] == digits[3])
        dig4Choices[1] = rand() % 10;
    dig4Choices[2] = digits[3];
    while ( (dig4Choices[2] == digits[3]) || (dig4Choices[2] == dig4Choices[1]) )
        dig4Choices[2] = rand() % 10;
    dig4Choices[3] = digits[3];
    while ( (dig4Choices[3] == digits[3]) || (dig4Choices[3] == dig4Choices[1]) || (dig4Choices[3] == dig4Choices[2]) )
        dig4Choices[3] = rand() % 10;
    dig4Choices[4] = digits[4];
    while ( (dig4Choices[4] == digits[3]) || (dig4Choices[4] == dig4Choices[1]) || (dig4Choices[4] == dig4Choices[2]) || (dig4Choices[4] == dig4Choices[3]) )
        dig4Choices[4] = rand() % 10;
    random_shuffle(&dig4Choices[0], &dig4Choices[5]);
    bool chosenDig4[5];
    for (int h = 0; h < 5; h++)
        chosenDig4[h] = false;

    /// Initialize choices for digit #5
    dig5Choices[0] = digits[4];
    dig5Choices[1] = digits[4];
    while (dig5Choices[1] == digits[4])
        dig5Choices[1] = rand() % 10;
    dig5Choices[2] = digits[4];
    while ( (dig5Choices[2] == digits[4]) || (dig5Choices[2] == dig5Choices[1]) )
        dig5Choices[2] = rand() % 10;
    dig5Choices[3] = digits[4];
    while ( (dig5Choices[3] == digits[4]) || (dig5Choices[3] == dig5Choices[1]) || (dig5Choices[3] == dig5Choices[2]) )
        dig5Choices[3] = rand() % 10;
    dig5Choices[4] = digits[4];
    while ( (dig5Choices[4] == digits[4]) || (dig5Choices[4] == dig5Choices[1]) || (dig5Choices[4] == dig5Choices[2]) || (dig5Choices[4] == dig5Choices[3]) )
        dig5Choices[4] = rand() % 10;
    dig5Choices[5] = digits[4];
    while ( (dig5Choices[5] == digits[4]) || (dig5Choices[5] == dig5Choices[1]) || (dig5Choices[5] == dig5Choices[2]) || (dig5Choices[5] == dig5Choices[3]) || (dig5Choices[5] == dig5Choices[4]) )
        dig5Choices[5] = rand() % 10;
    random_shuffle(&dig5Choices[0], &dig5Choices[6]);
    bool chosenDig5[6];
    for (int h = 0; h < 6; h++)
        chosenDig5[h] = false;

    //cout << endl << dig1Choices[0] << ", " << dig1Choices[1];
    //cout << endl << dig2Choices[0] << ", " << dig2Choices[1] << ", " << dig2Choices[2];
    //cout << endl << dig3Choices[0] << ", " << dig3Choices[1] << ", " << dig3Choices[2] << ", " << dig3Choices[3];
    //cout << endl << dig4Choices[0] << ", " << dig4Choices[1] << ", " << dig4Choices[2] << ", " << dig4Choices[3] << ", " << dig4Choices[4];
    //cout << endl << dig5Choices[0] << ", " << dig5Choices[1] << ", " << dig5Choices[2] << ", " << dig5Choices[3] << ", " << dig5Choices[4] << ", " << dig5Choices[5];
    //cout << endl;

    bool guessedCorrectly[5];
    bool beenFilled[5];

    for (int g = 0; g < 5; g++){
        guessedCorrectly[g] = false;
        beenFilled[g] = false;
    }

    int guesses[5];

    bool won = false;
    bool lost = false;

    int hasRight = 0;

    while ( (!won) && (!lost) ){

        int choices[5];
        for (int r = 0; r < 5; r++){
            if (!guessedCorrectly[r])
                choices[r] = 10;
            }

        cout << endl;
        for (int n = 0; n < 5; n++){

        if (!guessedCorrectly[n]){
        /// First row
        cout << endl << "*****";
        if (chosenDig5[0])
            cout << "_";
        else
            cout << dig5Choices[0];

        /// Second row
        cout << endl << "****";
        if (chosenDig4[0])
            cout << "_";
        else
            cout << dig4Choices[0];
        if (chosenDig5[1])
            cout << "_";
        else
            cout << dig5Choices[1];

        /// Third row
        cout << endl << "***";
        if (chosenDig3[0])
            cout << "_";
        else
            cout << dig3Choices[0];
        if (chosenDig4[1])
            cout << "_";
        else
            cout << dig4Choices[1];
        if (chosenDig5[2])
            cout << "_";
        else
            cout << dig5Choices[2];

        /// Fourth row
        cout << endl << "**";
        if (chosenDig2[0])
            cout << "_";
        else
            cout << dig2Choices[0];
        if (chosenDig3[1])
            cout << "_";
        else
            cout << dig3Choices[1];
        if (chosenDig4[2])
            cout << "_";
        else
            cout << dig4Choices[2];
        if (chosenDig5[3])
            cout << "_";
        else
            cout << dig5Choices[3];

        /// Fifth row
        cout << endl << "*";
        if (chosenDig1[0])
            cout << "_";
        else
            cout << dig1Choices[0];
        if (chosenDig2[1])
            cout << "_";
        else
            cout << dig2Choices[1];
        if (chosenDig3[2])
            cout << "_";
        else
            cout << dig3Choices[2];
        if (chosenDig4[3])
            cout << "_";
        else
            cout << dig4Choices[3];
        if (chosenDig5[4])
            cout << "_";
        else
            cout << dig5Choices[4];

        /// Sixth row
        cout << endl << "*";
        if (chosenDig1[1])
            cout << "_";
        else
            cout << dig1Choices[1];
        if (chosenDig2[2])
            cout << "_";
        else
            cout << dig2Choices[2];
        if (chosenDig3[3])
            cout << "_";
        else
            cout << dig3Choices[3];
        if (chosenDig4[4])
            cout << "_";
        else
            cout << dig4Choices[4];
        if (chosenDig5[5])
            cout << "_";
        else
            cout << dig5Choices[5];

        /// Price row
        cout << endl << "$";
        for (int b = 0; b < 5; b++){
        if (beenFilled[b])
            cout << guesses[b];
        else
            cout << "#";
        }

        /// Any correct numbers?
        cout << endl << "*";
        for (int y = 0; y < 5; y++){
            if (guessedCorrectly[y])
                cout << "!";
            else
                cout << "*";
        }
        } // end showing board

        /// Enter first digit
        if ((n == 0) && (!guessedCorrectly[0]) ){
            while ( (choices[0] != dig1Choices[0] ) && (choices[0] != dig1Choices[1] ) ){
            cout << endl << "What is digit #1?: ";
            cin >> choices[0];
            if ( (choices[0] == dig1Choices[0]) && (chosenDig1[0]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[0] = 10;
            }
            else if ( (choices[0] == dig1Choices[1]) && (chosenDig1[1]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[0] = 10;
            }
            } // end while loop involving entering digit #1
            guesses[0] = choices[0];

            if (choices[0] == dig1Choices[0])
                chosenDig1[0] = true;
            else
                chosenDig1[1] = true;

            beenFilled[0] = true;
        } // end if n = 0

        /// Enter second digit
        else if ( (n == 1) && (!guessedCorrectly[1]) ){
        while ( (choices[1] != dig2Choices[0] ) && (choices[1] != dig2Choices[1] ) && (choices[1] != dig2Choices[2] ) ){
        cout << endl << "What is digit #2?: ";
        cin >> choices[1];

            if ( (choices[1] == dig2Choices[0]) && (chosenDig2[0]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[1] = 10;
            }
            else if ( (choices[1] == dig2Choices[1]) && (chosenDig2[1]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[1] = 10;
            }
            else if ( (choices[1] == dig2Choices[2]) && (chosenDig2[2]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[1] = 10;
            }
        } // end while loop involving entering digit #2
        guesses[1] = choices[1];

        if (choices[1] == dig2Choices[0])
            chosenDig2[0] = true;
        else if (choices[1] == dig2Choices[1])
            chosenDig2[1] = true;
        else
            chosenDig2[2] = true;

        beenFilled[1] = true;
        } // end if n = 1

    /// Enter third digit
    else if ( (n == 2) && (!guessedCorrectly[2]) ){
        while ( (choices[2] != dig3Choices[0] ) && (choices[2] != dig3Choices[1] ) && (choices[2] != dig3Choices[2] ) && (choices[2] != dig3Choices[3] ) ){
        cout << endl << "What is digit #3?: ";
        cin >> choices[2];

            if ( (choices[2] == dig3Choices[0]) && (chosenDig3[0]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[2] = 10;
            }
            else if ( (choices[2] == dig3Choices[1]) && (chosenDig3[1]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[2] = 10;
            }
            else if ( (choices[2] == dig3Choices[2]) && (chosenDig3[2]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[2] = 10;
            }
            else if ( (choices[2] == dig3Choices[3]) && (chosenDig3[3]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[2] = 10;
            }
        } // end while loop involving entering digit #3
        guesses[2] = choices[2];

        if (choices[2] == dig3Choices[0])
            chosenDig3[0] = true;
        else if (choices[2] == dig3Choices[1])
            chosenDig3[1] = true;
        else if (choices[2] == dig3Choices[2])
            chosenDig3[2] = true;
        else
            chosenDig3[3] = true;

        beenFilled[2] = true;
    } // end if n = 2

    /// Enter fourth digit
    else if ( (n == 3) && (!guessedCorrectly[3]) ){
        while ( (choices[3] != dig4Choices[0] ) && (choices[3] != dig4Choices[1] ) && (choices[3] != dig4Choices[2] ) &&
               (choices[3] != dig4Choices[3] ) && (choices[3] != dig4Choices[4] ) ){
        cout << endl << "What is digit #4?: ";
        cin >> choices[3];

            if ( (choices[3] == dig4Choices[0]) && (chosenDig4[0]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[3] = 10;
            }
            else if ( (choices[3] == dig4Choices[1]) && (chosenDig4[1]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[3] = 10;
            }
            else if ( (choices[3] == dig4Choices[2]) && (chosenDig4[2]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[3] = 10;
            }
            else if ( (choices[3] == dig4Choices[3]) && (chosenDig4[3]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[3] = 10;
            }
            else if ( (choices[3] == dig4Choices[4]) && (chosenDig4[4]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[3] = 10;
            }
    } // end while loop involving entering digit #4
    guesses[3] = choices[3];

        if (choices[3] == dig4Choices[0])
            chosenDig4[0] = true;
        else if (choices[3] == dig4Choices[1])
            chosenDig4[1] = true;
        else if (choices[3] == dig4Choices[2])
            chosenDig4[2] = true;
        else if (choices[3] == dig4Choices[3])
            chosenDig4[3] = true;
        else
            chosenDig4[4] = true;

        beenFilled[3] = true;

    } // end if n = 3

    /// Enter fifth digit
    else if ( (n == 4) && (!guessedCorrectly[4]) ){
        while ( (choices[4] != dig5Choices[0] ) && (choices[4] != dig5Choices[1] ) && (choices[4] != dig5Choices[2] ) &&
               (choices[4] != dig5Choices[3] ) && (choices[4] != dig5Choices[4] ) && (choices[4] != dig5Choices[5] ) )
        {
        cout << endl << "What is digit #5?: ";
        cin >> choices[4];

            if ( (choices[4] == dig5Choices[0]) && (chosenDig5[0]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
            else if ( (choices[4] == dig5Choices[1]) && (chosenDig5[1]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
            else if ( (choices[4] == dig5Choices[2]) && (chosenDig5[2]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
            else if ( (choices[4] == dig5Choices[3]) && (chosenDig5[3]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
            else if ( (choices[4] == dig5Choices[4]) && (chosenDig5[4]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
            else if ( (choices[4] == dig5Choices[5]) && (chosenDig5[5]) ){
                cout << endl << "This digit has already been chosen. Please pick another one.";
                choices[4] = 10;
            }
        } // end while loop involving entering digit #5

    guesses[4] = choices[4];

        if (choices[4] == dig5Choices[0])
            chosenDig5[0] = true;
        else if (choices[4] == dig5Choices[1])
            chosenDig5[1] = true;
        else if (choices[4] == dig5Choices[2])
            chosenDig5[2] = true;
        else if (choices[4] == dig5Choices[3])
            chosenDig5[3] = true;
        else if (choices[4] == dig5Choices[4])
            chosenDig5[4] = true;
        else
            chosenDig5[5] = true;

        beenFilled[4] = true;

    } // end if n = 4

        } // end placing numbers loop

    cout << endl << "You've entered a price of $";
    for (int v = 0; v < 5; v++)
        cout << choices[v];
    cout << ".";
    cout << endl << "Is this the correct price?: ";
    cout << endl;
    system("pause");

    int calc = 0;

    for (int c = 0; c < 5; c++){
        if (choices[c] == digits[c]){
            guessedCorrectly[c] = true;
            calc++;
        }
    }

    if (calc == 5)
        won = true;

    else{
        cout << endl << "That's not correct, but let's see if any new digits are right.";
        cout << endl;
        system("pause");
        if (calc > hasRight){
            hasRight = calc;
        }
        else
            lost = true;
    }

    } // end while loop

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose. \nThe actual retail price was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Dice Game
void playDiceGame()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (!incompatibleDiceGame(t_Price)) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "DICE GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    int carPrice = prizeCar.getPrice();

        int normalDigits[5];
        normalDigits[0] = carPrice / 10000 % 10;
        normalDigits[1] = carPrice / 1000 % 10;
        normalDigits[2] = carPrice / 100 % 10;
        normalDigits[3] = carPrice / 10 % 10;
        normalDigits[4] = carPrice % 10;

        bool normalRevealed[5];
        for (int x = 0; x < 5; x++)
            normalRevealed[x] = false;


    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int rolls[4];

    for (int r = 1; r <= 4; r++){
        rolls[r-1] = (rand() % 6) + 1;
        //cout << rolls[r-1] << ", ";
    }

    /*
    rolls[0] = 6;
    rolls[1] = 6;
    rolls[2] = 6;
    rolls[3] = 6; /// These were used for testing.
    */

    /// if 0, the roll is uninitialized. if 1, the player rolled the correct number.
    /// if 2, the player rolled a 1 (HIGHER). if 3, the player rolled a 6 (LOWER).
    /// if 4, the player guessed HIGHER. If 5, the player guessed LOWER.
    int rollResults[4];
    /*
    for (int q = 0; q <= 4; q++)
        rollResults[q-1] = 0;
    */
    rollResults[0] = 0;
    rollResults[1] = 0;
    rollResults[2] = 0;
    rollResults[3] = 0;

    cout << endl;

        bool won = false;
        bool lost = false;

    int b;
    //cout << "price: $" << carPrice << endl;

    for (int digit = 1; digit <= 4; digit++)
    {
        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;

        cout << normalDigits[0];
        if (normalRevealed[1] == true)
            cout << normalDigits[1];
        else
            cout << "#";
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else
            cout << "#";
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else
            cout << "#";
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else
            cout << "#";

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        }


        cout << endl << "Press any key to roll the dice." << endl;
        system("pause");
        cout << endl << "You rolled a " << rolls[digit-1] << "." << endl;
        //cout << "correct digit = " << normalDigits[digit] << endl;
        if (rolls[digit-1] == normalDigits[digit]){
            cout << endl << "Yes, that's correct!" << endl;
            normalRevealed[digit] = true;
        }
        else if (rolls[digit-1] == 1)
        {
            cout << endl << "It's not 1, but we know it must be HIGHER." << endl;
            rollResults[digit-1] = 2; /// set to HIGHER
        }
        else if (rolls[digit-1] == 6)
        {
            cout << endl << "It's not 6, but we know it must be LOWER." << endl;
            rollResults[digit-1] = 3; /// set to LOWER
        }
        else
        {
            char guess = 'A';
            cout << endl << "It's not " << rolls[digit-1] << ".";
            while ( (guess != 'H') && (guess != 'L') &&  (guess != 'h') && (guess != 'l') ){
            cout << endl << "Is the right digit higher (H) or lower (L)?: ";
            cin >> guess;
            } /// end while loop
            if ((guess == 'H') || (guess == 'h'))
            {
                rollResults[digit-1] = 4;
                cout << endl << "You guessed HIGHER." << endl;
            } /// end guess of higher
            else if ((guess == 'L') || (guess == 'l'))
            {
                rollResults[digit-1] = 5;
                cout << endl << "You guessed LOWER." << endl;
            } /// end guess of higher

        }
    } /// finished the dice-rolling portion

    cout << endl << "Now, let's reveal the price of the car." << endl;

     cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;

        cout << normalDigits[0];
        if (normalRevealed[1] == true)
            cout << normalDigits[1];
        else
            cout << "#";
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else
            cout << "#";
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else
            cout << "#";
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else
            cout << "#";

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        }

        /// First, check for correct rolls.
        cout << endl;
        for (int cor = 1; cor <= 4; cor++){
            if (normalRevealed[cor])
                cout << "We know the " << normalDigits[cor] << " is correct." << endl;
        }

        /// If these bools are true, display them on the board.
        bool knowHigher[4];
        for (int y = 0; y < 4; y++)
            knowHigher[y] = false;

        /// If these bools are true, display them on the board.
        bool knowLower[4];
        for (int y2 = 0; y2 < 4; y2++)
            knowLower[y2] = false;

        bool foundOneRoll = false;
        bool foundSixRoll = false;

        /// Check for incorrect rolls of 1.
        cout << endl;
        for (int wan = 1; wan <= 4; wan++){
            if (rollResults[wan-1] == 2){
                knowHigher[wan-1] = true;
                foundOneRoll = true;
                }
        }

        /// Here just for an added affirmation measure.
        if (rollResults[3] == 2){
            knowHigher[3] = true;
            foundOneRoll = true;
        }

        if (foundOneRoll){
        /// Display the board, this time with rolls of 1 shown.
        cout << "Let's reveal the digits we know are higher." << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];
        if (normalRevealed[1] == true)
            cout << normalDigits[1];
        else if (knowHigher[0] == true)
            cout << normalDigits[1];
        else
            cout << "#";
        ///
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else if (knowHigher[1] == true)
            cout << normalDigits[2];
        else
            cout << "#";
        ///
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else if (knowHigher[2] == true)
            cout << normalDigits[3];
        else
            cout << "#";
        ///
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else if (knowHigher[3] == true)
            cout << normalDigits[4];
        else
            cout << "#";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        }
        cout << endl;
        system("pause");
        } // end
        /// Finish displaying the board with rolls of 1.

        //cout << endl;
        //system("pause");

        /// Check for incorrect rolls of 6.
        cout << endl;
        for (int sik = 1; sik <= 4; sik++){
            //cout << "~[" << rollResults[sik-1] << "]~, ";
            if (rollResults[sik-1] == 3){
                //cout << "\nfound\n";
                knowLower[sik-1] = true;
                foundSixRoll = true;
                }
        }

        /// Here just for an added affirmation measure.
        if (rollResults[3] == 3){
            knowLower[3] = true;
            foundSixRoll = true;
        }

        if (foundSixRoll){
        /// Display the board, this time with rolls of 1 and 6 shown.
        cout << "Let's reveal the digits we know are lower." << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];
        if (normalRevealed[1] == true)
            cout << normalDigits[1];
        else if (knowHigher[0] == true)
            cout << normalDigits[1];
        else if (knowLower[0] == true){
            cout << normalDigits[1];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
            }
        else
            cout << "#";
        ///
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else if (knowHigher[1] == true)
            cout << normalDigits[2];
        else if (knowLower[1] == true){
            cout << normalDigits[2];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else if (knowHigher[2] == true)
            cout << normalDigits[3];
        else if (knowLower[2] == true){
            cout << normalDigits[3];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else if (knowHigher[3] == true)
            cout << normalDigits[4];
        else if (knowLower[3] == true){
            cout << normalDigits[4];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        }
        cout << endl;
        system("pause");
        } /// end if
        /// Finish displaying the board with rolls of 6.

        //cout << endl;
        //system("pause");

        /// You could be really lucky, so let's check for that.
        int countRevealed = 0;
        for (int b = 0; b < 4; b++)
        {
            if ( (rollResults[b] == 2) || (rollResults[b] == 3) || (normalRevealed[b+1] == true) )
                countRevealed += 1;
        }

        if (countRevealed == 4)
            cout << endl << "Congratulations, you win!" << endl;
        else{
        cout << endl << "Now, let's reveal the remaining digits." << endl;
        //cout << " HHHH" << endl;

        while ( (!won) && (!lost) ){

        cout << endl;
        /// BEGIN DISPLAYING DIGIT 2
        if ( (rollResults[0] == 4) || (rollResults[0] == 5) ){
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];

        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[1];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else if (knowHigher[1] == true)
            cout << normalDigits[2];
        else if (knowLower[1] == true){
            cout << normalDigits[2];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else if (knowHigher[2] == true)
            cout << normalDigits[3];
        else if (knowLower[2] == true){
            cout << normalDigits[3];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else if (knowHigher[3] == true)
            cout << normalDigits[4];
        else if (knowLower[3] == true){
            cout << normalDigits[4];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        } /// end

        /// Check for a loss if the player said HIGHER (the correct answer is LOWER)
        if ( (rollResults[0] == 4) && ( normalDigits[1] < rolls[0] ) ){
            lost = true;
        }
        /// Check for a loss if the player said LOWER (the correct answer is HIGHER)
        else if ( (rollResults[0] == 5) && ( normalDigits[1] > rolls[0]) )
            lost = true;

        if (!lost){
            cout << endl;
            system("pause");
        }

        } /// FINISHED WITH DIGIT 2

        ///--------------------------------------///

        cout << endl;
        /// BEGIN DISPLAYING DIGIT 3
        if ( (rollResults[1] == 4) || (rollResults[1] == 5) ){
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];

        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[1];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[2];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else if (knowHigher[2] == true)
            cout << normalDigits[3];
        else if (knowLower[2] == true){
            cout << normalDigits[3];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else if (knowHigher[3] == true)
            cout << normalDigits[4];
        else if (knowLower[3] == true){
            cout << normalDigits[4];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        } /// end

        /// Check for a loss if the player said HIGHER (the correct answer is LOWER)
        if ( (rollResults[1] == 4) && ( normalDigits[2] < rolls[1] ) ){
            lost = true;
        }
        /// Check for a loss if the player said LOWER (the correct answer is HIGHER)
        else if ( (rollResults[1] == 5) && ( normalDigits[2] > rolls[1]) )
            lost = true;

        if (!lost){
            cout << endl;
            system("pause");
        }

        } /// FINISHED WITH DIGIT 3

        ///--------------------------------------///

        cout << endl;
        /// BEGIN DISPLAYING DIGIT 4
        if ( (rollResults[2] == 4) || (rollResults[2] == 5) ){
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];

        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[1];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[2];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[3];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else if (knowHigher[3] == true)
            cout << normalDigits[4];
        else if (knowLower[3] == true){
            cout << normalDigits[4];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        }
        else
            cout << "#";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        } /// end

        /// Check for a loss if the player said HIGHER (the correct answer is LOWER)
        if ( (rollResults[2] == 4) && ( normalDigits[3] < rolls[2] ) ){
            lost = true;
        }
        /// Check for a loss if the player said LOWER (the correct answer is HIGHER)
        else if ( (rollResults[2] == 5) && ( normalDigits[3] > rolls[2]) )
            lost = true;

        if (!lost){
            cout << endl;
            system("pause");
        }

        } /// FINISHED WITH DIGIT 4

        ///--------------------------------------///

    cout << endl;
    /// BEGIN DISPLAYING DIGIT 5
        if ( (rollResults[3] == 4) || (rollResults[3] == 5) ){
        cout << " ";
        for (int k = 1; k <= 4; k++){
        if (normalRevealed[k] == true)
            cout << normalDigits[k];
        else if ((rollResults[k-1] == 2) || (rollResults[k-1] == 4))
            cout << "H";
        else
            cout << "*";
        }

        cout << endl;


        cout << normalDigits[0];

        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[1];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[2];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[3];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///
        /// THIS DIGIT IS NOW DISPLAYED
        cout << normalDigits[4];
            //cout << "THIS SHOULD DISPLAY THE CORRECT DIGIT";
        ///

        cout << endl;
        //cout << " HHHH" << endl;
        cout << " ";
        for (int l = 1; l <= 4; l++){
        if (normalRevealed[l] == true)
            cout << normalDigits[l];
        else if ((rollResults[l-1] == 3) || (rollResults[l-1] == 5))
            cout << "L";
        else
            cout << "*";
        } /// end

        /// Check for a loss if the player said HIGHER (the correct answer is LOWER)
        if ( (rollResults[3] == 4) && ( normalDigits[4] < rolls[3] ) ){
            lost = true;
        }
        /// Check for a loss if the player said LOWER (the correct answer is HIGHER)
        else if ( (rollResults[3] == 5) && ( normalDigits[4] > rolls[3]) )
            lost = true;

        } /// FINISHED WITH DIGIT 5

    if (!lost)
        won = true;

        } /// end while loop

        } /// END ELSE STATEMENT

    if (won)
        cout << endl << "Congratulations, you win!";
    if (lost)
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Double Bullseye
void playDoubleBullseye()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > 15000) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "DOUBLE BULLSEYE" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    /// Calculate bounds
    int lowerBound = carPrice - (carPrice % 1000);
    int upperBound = lowerBound + 1000;

    int player = 1;

    cout << endl << "Range: $" << lowerBound << "-$" << upperBound;
    bool won = false;

    while ( (!won) )
    {
        int bid = 0;
        cout << endl << endl << "Player " << player << ", it's your turn.";
        while (bid == 0){
        cout << endl << "How much do you think the car is?: $";
        cin >> bid;
        }
        if (bid == carPrice)
            won = true;
        else if (carPrice > bid){
            cout << endl << "The car's price is HIGHER than your bid";
            if (player == 1)
                player = 2;
            else
                player = 1;
        }
        else if (carPrice < bid){
            cout << endl << "The car's price is LOWER than your bid";
            if (player == 1)
                player = 2;
            else
                player = 1;
        }
    } // end while loop

    cout << endl << "Congratulations, Player " << player << ", you win!";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Double Digits
void playDoubleDigits()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) && !hasZeros(t_Price) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    int j = 0;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ( (inFile >> s_Description >> s_ShortName >> s_Price) && (s_Price < 100) )
        {
            pptr->setDescription(s_Description);
            pptr->setShortName(s_ShortName);
            pptr->setPrice(s_Price);
            gameItems.push_back(*pptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "DOUBLE DIGITS" << endl;

    /// Pick a car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    int carPrice = prizeCar.getPrice();
    int carDigits[5];
    carDigits[0] = carPrice / 10000 % 10;
    carDigits[1] = carPrice / 1000 % 10;
    carDigits[2] = carPrice / 100 % 10;
    carDigits[3] = carPrice / 10 % 10;
    carDigits[4] = carPrice % 10;

    small prizes[4];

    /// If 0, the correct answer will be the smaller of two consecutive digits.
    /// If 1, the correct answer will be the larger of two consecutive digits.
    int directions[4];

    /// First prize (second digit)
    if (carDigits[1] == 1)
        directions[0] = 0;
    else if (carDigits[1] == 9)
        directions[0] = 1;
    else
        directions[0] = rand() % 2;

    /// Second prize (third digit)
    if (carDigits[2] == 1)
        directions[1] = 0;
    else if (carDigits[2] == 9)
        directions[1] = 1;
    else
        directions[1] = rand() % 2;

    /// Third prize (fourth digit)
    if (carDigits[3] == 1)
        directions[2] = 0;
    else if (carDigits[3] == 9)
        directions[2] = 1;
    else
        directions[2] = rand() % 2;

    /// Fourth prize (fifth digit)
    if (carDigits[4] == 1)
        directions[3] = 0;
    else if (carDigits[3] == 9)
        directions[3] = 1;
    else
        directions[3] = rand() % 2;

    cout << endl;
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int digitChoices[4];

    int first;
    int second;
    int third;
    int fourth;

    bool setFirst = false;
    while (!setFirst){
    first = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    if ( ( (gameItemIt->getPrice()) / 10 % 10 ) == carDigits[1]){
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());
    setFirst = true;
    }
    } // end while loop

    bool setSecond = false;
    while (!setSecond){
    second = first;
    while (second == first)
        second = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    if ( ( (gameItemIt->getPrice()) / 10 % 10 ) == carDigits[2]){
    prizes[1].setDescription(gameItemIt->getDescription());
    prizes[1].setShortName(gameItemIt->getShortName());
    prizes[1].setPrice(gameItemIt->getPrice());
    setSecond = true;
    }
    } // end while loop

    bool setThird = false;
    while (!setThird){
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    if ( ( (gameItemIt->getPrice()) / 10 % 10 ) == carDigits[3]){
    prizes[2].setDescription(gameItemIt->getDescription());
    prizes[2].setShortName(gameItemIt->getShortName());
    prizes[2].setPrice(gameItemIt->getPrice());
    setThird = true;
    }
    } // end while loop

    bool setFourth = false;
    while (!setFourth){
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    if ( ( (gameItemIt->getPrice()) / 10 % 10 ) == carDigits[4]){
    prizes[3].setDescription(gameItemIt->getDescription());
    prizes[3].setShortName(gameItemIt->getShortName());
    prizes[3].setPrice(gameItemIt->getPrice());
    setFourth = true;
    }
    } // end while loop

    cout << endl;
    cout << endl << "$" << carDigits[0] << "****";
//    cout << endl << "car price: $" << carPrice;
//    cout << endl << "price #1: $" << prizes[0].getPrice();
//    cout << endl << "price #2: $" << prizes[1].getPrice();
//    cout << endl << "price #3: $" << prizes[2].getPrice();
//    cout << endl << "price #4: $" << prizes[3].getPrice();

    /// Digit #2
    int choice1 = 0;
    cout << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "$*" << (prizes[0].getPrice() % 10);
    cout << endl << "The missing digit in the price is also the car's second digit.";
    if (directions[0] == 0 && (carDigits[1] != 9) ){
    while ( (choice1 != carDigits[1]) && (choice1 != (carDigits[1]+1)) ){
        cout << endl << "Is the missing digit " << carDigits[1] << " or " << (carDigits[1]+1) << "?: ";
        cin >> choice1;
    }
    } // the correct digit is the smaller of the two digits
    else{
    while ( (choice1 != (carDigits[1]-1) ) && (choice1 != carDigits[1]) ){
        cout << endl << "Is the missing digit " << (carDigits[1]-1) << " or " << carDigits[1] << "?: ";
        cin >> choice1;
    }
    } // the correct digit is the larger of the two digits
    digitChoices[0] = choice1;

    /// Digit #3
    cout << endl << "$" << carDigits[0] << digitChoices[0] << "***";
    int choice2 = 0;
    cout << endl << "2. ";
    prizes[1].showPrize();
    cout << endl << "$*" << (prizes[1].getPrice() % 10);
    cout << endl << "The missing digit in the price is also the car's third digit.";
    if (directions[1] == 0 && (carDigits[2] != 9) ){
    while ( (choice2 != carDigits[2]) && (choice2 != (carDigits[2]+1)) ){
        cout << endl << "Is the missing digit " << carDigits[2] << " or " << (carDigits[2]+1) << "?: ";
        cin >> choice2;
    }
    } // the correct digit is the smaller of the two digits
    else{
    while ( (choice2 != (carDigits[2]-1) ) && (choice2 != carDigits[2]) ){
        cout << endl << "Is the missing digit " << (carDigits[2]-1) << " or " << carDigits[2] << "?: ";
        cin >> choice2;
    }
    } // the correct digit is the larger of the two digits
    digitChoices[1] = choice2;

    /// Digit #4
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << "**";
    int choice3 = 0;
    cout << endl << "3. ";
    prizes[2].showPrize();
    cout << endl << "$*" << (prizes[2].getPrice() % 10);
    cout << endl << "The missing digit in the price is also the car's fourth digit.";
    if ( (directions[2] == 0) && (carDigits[3] != 9) ){
    while ( (choice3 != carDigits[3]) && (choice3 != (carDigits[3]+1)) ){
        cout << endl << "Is the missing digit " << carDigits[3] << " or " << (carDigits[3]+1) << "?: ";
        cin >> choice3;
    }
    } // the correct digit is the smaller of the two digits
    else{
    while ( (choice3 != (carDigits[3]-1) ) && (choice3 != carDigits[3]) ){
        cout << endl << "Is the missing digit " << (carDigits[3]-1) << " or " << carDigits[3] << "?: ";
        cin >> choice3;
    }
    } // the correct digit is the larger of the two digits
    digitChoices[2] = choice3;

    /// Digit #5
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << "*";
    int choice4 = 0;
    cout << endl << "4. ";
    prizes[3].showPrize();
    cout << endl << "$*" << (prizes[3].getPrice() % 10);
    cout << endl << "The missing digit in the price is also the car's fifth digit.";
    if ( (directions[3] == 0) && (carDigits[4] != 9) ){
    while ( (choice4 != carDigits[4]) && (choice4 != (carDigits[4]+1)) ){
        cout << endl << "Is the missing digit " << carDigits[4] << " or " << (carDigits[4]+1) << "?: ";
        cin >> choice4;
    }
    } //  the correct digit is the smaller of the two digits
    else{
    while ( (choice4 != (carDigits[4]-1) ) && (choice4 != carDigits[4]) ){
        cout << endl << "Is the missing digit " << (carDigits[4]-1) << " or " << carDigits[4] << "?: ";
        cin >> choice4;
    }
    } // the correct digit is the larger of the two digits
    digitChoices[3] = choice4;

    bool lostCar = false;
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3];
    cout << endl << "$" << carDigits[0] << "****";
    cout << endl << "Let's see if you've won.";
    cout << endl;
    system("pause");

    /// reveal digit #2
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3];
    cout << endl << "$" << carDigits[0] << carDigits[1] << "***";
    if (carDigits[1] == digitChoices[0]){
        cout << endl << "You've won the ";
        prizes[0].showShortName();
    }
    else{
        cout << endl << "You didn't win the car. \nLet's go on though to see which items you got right.";
        lostCar = true;
    }
    cout << endl;
    system("pause");

    /// reveal digit #3
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3];
    cout << endl << "$" << carDigits[0] << carDigits[1] << carDigits[2] << "**";
    if (carDigits[2] == digitChoices[1]){
        cout << endl << "You've won the ";
        prizes[1].showShortName();
    }
    else{
        if (!lostCar){
        cout << endl << "You didn't win the car. \nLet's go on though to see which items you got right.";
        lostCar = true;
        }
    }
    cout << endl;
    system("pause");

    /// reveal digit #4
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3];
    cout << endl << "$" << carDigits[0] << carDigits[1] << carDigits[2] << carDigits[3] << "*";
    if (carDigits[3] == digitChoices[2]){
        cout << endl << "You've won the ";
        prizes[2].showShortName();
    }
    else{
        if (!lostCar){
        cout << endl << "You didn't win the car. \nLet's go on though to see which items you got right.";
        lostCar = true;
        }
    }
    cout << endl;
    system("pause");

    /// reveal digit #5
    cout << endl << "$" << carDigits[0] << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3];
    cout << endl << "$" << carDigits[0] << carDigits[1] << carDigits[2] << carDigits[3] << carDigits[4];
    if (carDigits[4] == digitChoices[3]){
        cout << endl << "You've won the ";
        prizes[3].showShortName();
    }
    else{
        if (!lostCar)
            lostCar = true;
    }

    cout << endl;
    if (!lostCar)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Fill 'er Up
void playFillErUp()
{
    /// Credit to wdm1219 for making this game!

    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "FILL 'ER UP" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    bool revealed[5];
    for (int r = 0; r < 5; r++)
        revealed[r] = false;

    /// This will be 0 if the digit hasn't been guessed, 1 if it's guessed and in the price,
    /// and 2 if it's guessed and isn't in the price.
    int digitOn[10];
    for (int d = 0; d < 10; d++)
        digitOn[d] = 0;

    bool revealedL = false;
    bool revealedO = false;
    bool revealedS = false;
    bool revealedE = false;
    bool outOfGas = false;

    int on = 0;
    int wrongs[5] = {0, 1, 2, 3, 4};
    random_shuffle(&wrongs[0], &wrongs[5]);

    bool lost = false;
    bool won = false;

    while ( (!lost) && (!won) ){

        /// Show the digits that have been revealed
        cout << endl << "  $";
        for (int p = 0; p < 5; p++){
        if (revealed[p])
            cout << digits[p];
        else
            cout << "*";
        }
        cout << endl << "  ";
        if (outOfGas)
            cout << "X";
        else
            cout << "_";
        cout << " ";
        if (revealedL)
            cout << "L";
        else
            cout << "_";
        if (revealedO)
            cout << "O";
        else
            cout << "_";
        if (revealedS)
            cout << "S";
        else
            cout << "_";
        if (revealedE)
            cout << "E";
        else
            cout << "_";

        cout << endl << "0123456789";
        cout << endl;
        for (int n = 0; n < 10; n++){
            if (digitOn[n] == 0)
                cout << "*";
            else if (digitOn[n] == 1)
                cout << "O";
            else
                cout << "X";
        }

        int choice = 10;
        while ((choice < 0) || (choice > 9)){
            cout << endl << "Enter a number you think is in the price of the car: ";
                cin >> choice;
            if (digitOn[choice] != 0){
                cout << endl << "You've already chosen this number. Please pick another.";
                choice = 10;
            }
        } // end while loop involving digit entry

        if (choice == digits[0]){
            cout << endl << "Yes, that's correct.";
            revealed[0] = true;
            digitOn[choice] = 1;
        }
        else if (choice == digits[1]){
            cout << endl << "Yes, that's correct.";
            revealed[1] = true;
            digitOn[choice] = 1;
        }
        else if (choice == digits[2]){
            cout << endl << "Yes, that's correct.";
            revealed[2] = true;
            digitOn[choice] = 1;
        }
        else if (choice == digits[3]){
            cout << endl << "Yes, that's correct.";
            revealed[3] = true;
            digitOn[choice] = 1;
        }
        else if (choice == digits[4]){
            cout << endl << "Yes, that's correct.";
            revealed[4] = true;
            digitOn[choice] = 1;
        }
        else{
            cout << endl << "Sorry, that number isn't in the price.";
            digitOn[choice] = 2;
            if (wrongs[on] == 0){
                outOfGas = true;
                cout << endl << "You ran out of gas, so you won't win the $1000 gas card.";
            }
            else if (wrongs[on] == 1)
                revealedL = true;
            else if (wrongs[on] == 2)
                revealedO = true;
            else if (wrongs[on] == 3)
                revealedS = true;
            else
                revealedE = true;
            on++;
        }

        cout << endl;

        if ( (revealed[0]) && (revealed[1]) && (revealed[2]) && (revealed[3]) && (revealed[4]) )
            won = true;
        else if ( (revealedL) && (revealedO) && (revealedS) && (revealedE) )
            lost = true;
    } /// end main gameplay while loop

        /// Verdict
        // Show the digits that have been revealed
        cout << endl << "  $";
        for (int p = 0; p < 5; p++){
        if (revealed[p])
            cout << digits[p];
        else
            cout << "*";
        }
        cout << endl << "  ";
        if (outOfGas)
            cout << "X";
        else
            cout << "_";
        cout << " ";
        if (revealedL)
            cout << "L";
        else
            cout << "_";
        if (revealedO)
            cout << "O";
        else
            cout << "_";
        if (revealedS)
            cout << "S";
        else
            cout << "_";
        if (revealedE)
            cout << "E";
        else
            cout << "_";

        cout << endl << "0123456789";
        cout << endl;
        for (int n = 0; n < 10; n++){
            if (digitOn[n] == 0)
                cout << "*";
            else if (digitOn[n] == 1)
                cout << "O";
            else
                cout << "X";
        }

    cout << endl;
    if (won && !outOfGas)
        cout << endl << "Congratulations, you win the car and $1000 of gas money!";
    else if (won && outOfGas)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Five Price Tags
void playFivePriceTags()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * pptr;

    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ((inFile >> s_Description >> s_ShortName >> s_Price))
        {
            pptr->setDescription(s_Description);
            pptr->setShortName(s_ShortName);
            pptr->setPrice(s_Price);
            gameItems.push_back(*pptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "FIVE PRICE TAGS" << endl;

    /// Pick which car will be used in the game.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int price2 = carPrice;
    int price3 = carPrice;
    int price4 = carPrice;
    int price5 = carPrice;

    int loBound = roundDown(carPrice);
    int hiBound = loBound + 5000;

    while (price2 == carPrice)
        price2 = rand() % (hiBound - loBound) + loBound;

    while ((price3 == carPrice) || (price3 == price2))
        price3 = rand() % (hiBound - loBound) + loBound;

    while ((price4 == carPrice) || (price4 == price2) || (price4 == price3) )
        price4 = rand() % (hiBound - loBound) + loBound;

     while ((price5 == carPrice) || (price5 == price2) || (price5 == price3) || (price5 == price4))
        price5 = rand() % (hiBound - loBound) + loBound;

    /// Put the prices in an array and randomize them.
    int prices[5] = {carPrice, price2, price3, price4, price5};
    random_shuffle(&prices[0], &prices[5]);

    bool picked[5];
    for (int x = 0; x < 5; x++)
        picked[x] = false;

    /// Randomize the small prizes.
    int randomizationField[j];
    for (int k = 0; k < j; k++)
    {
        randomizationField[k] = k;
    }
    random_shuffle(&randomizationField[0], &randomizationField[j]);

    int z2 = 0;
    small items[4];

    int displayPrices[4];
    bool isFalse[4];
    for (int w = 0; w < 4; w++)
    {
        int flag = rand() % 2;
        if (flag == 0)
            isFalse[w] = false;
        else
            isFalse[w] = true;
    }

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
        displayPrices[itemCount] = items[itemCount].getPrice();
    }

    /// If any prizes are set to be FALSE, change them.
    for (int v = 0; v < 4; v++)
    {
        if (isFalse[v])
        {
            while (displayPrices[v] == items[v].getPrice())
                displayPrices[v] = rand() % (100 - 10) + 10;
        }
    }

    int picks = 0;

    cout << endl << endl;

    for (int u = 0; u < 4; u++)
    {
        char choice = 'A';
        cout << u+1 << ". ";
        items[u].showPrize();
        cout << " - $" << displayPrices[u];
        while ( (choice != 'T') && (choice != 'F') &&  (choice != 't') && (choice != 'f') ){
        cout << endl << "Is this price true (T) or false (F)?: ";
        cin >> choice;
        }
        if ( (choice == 'T') || (choice == 't') )
        {
        cout << "The actual retail price is ";
        items[u].showARP();
        if (items[u].getPrice() == displayPrices[u])
        {
            cout << endl << "That's correct! You earn a pick.";
            picks += 1;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } /// end if the player chooses TRUE
        else
        {
        cout << "The actual retail price is ";
        items[u].showARP();
        if (items[u].getPrice() != displayPrices[u])
        {
            cout << endl << "That's correct! You earn a pick.";
            picks += 1;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } /// end if the player chooses FALSE
        cout << endl << endl;
    }

    bool won = false;
    bool lost = false;

    if (picks == 0)
        lost = true;
    else
    {
    if (picks == 1)
        cout << endl << "You've earned 1 pick on the board.";
    else
        cout << endl << "You've earned " << picks << " picks on the board.";

    while (!won && picks > 0){
    int tagChoice = 0;
    cout << endl;
    for (int t = 0; t < 5; t++){
        cout << t+1 << ". $" << prices[t];
        if (picked[t])
            cout << " - X";
        cout << endl;
        }
    cout << endl << "Which tag do you want to pick?: ";
    cin >> tagChoice;
    switch (tagChoice){

    case 1:
    if (picked[0])
        cout << endl << "You've already picked this price. Please pick another." << endl;
    else
    {
        picked[0] = true;
        if (prices[0] == carPrice)
            won = true;
        else
            picks -= 1;
    }
        break;

    case 2:
    if (picked[1])
        cout << endl << "You've already picked this price. Please pick another." << endl;
    else
    {
        picked[1] = true;
        if (prices[1] == carPrice)
            won = true;
        else
            picks -= 1;
    }
        break;

    case 3:
    if (picked[2])
        cout << endl << "You've already picked this price. Please pick another." << endl;
    else
    {
        picked[2] = true;
        if (prices[2] == carPrice)
            won = true;
        else
            picks -= 1;
    }
        break;

    case 4:
    if (picked[3])
        cout << endl << "You've already picked this price. Please pick another." << endl;
    else
    {
        picked[3] = true;
        if (prices[3] == carPrice)
            won = true;
        else
            picks -= 1;
    }
        break;

    case 5:
    if (picked[4])
        cout << endl << "You've already picked this price. Please pick another." << endl;
    else
    {
        picked[4] = true;
        if (prices[4] == carPrice)
            won = true;
        else
            picks -= 1;
    }
        break;

    default:
        cout << endl << "That won't work. Try again." << endl;

    } /// end switch statement

    } /// end while loop

    } /// if player has at least one pick

    if ( (picks == 0) && (!won) )
        lost = true;

    if (won)
        cout << endl << "Congratulations, you win!";
    else if (lost)
        cout << endl << "Sorry, you lose. The price of the car was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Gas Money
void playGasMoney()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "GAS MONEY" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int price2 = carPrice;
    int price3 = carPrice;
    int price4 = carPrice;
    int price5 = carPrice;

    int loBound = roundDown(carPrice);
    int hiBound = loBound + 5000;

    while (price2 == carPrice)
        price2 = rand() % (hiBound - loBound) + loBound;

    while ((price3 == carPrice) || (price3 == price2))
        price3 = rand() % (hiBound - loBound) + loBound;

    while ((price4 == carPrice) || (price4 == price2) || (price4 == price3) )
        price4 = rand() % (hiBound - loBound) + loBound;

     while ((price5 == carPrice) || (price5 == price2) || (price5 == price3) || (price5 == price4))
        price5 = rand() % (hiBound - loBound) + loBound;

    bool picked[5];
    for (int x = 0; x < 5; x++)
        picked[x] = false;

    /// Instead of randomly associating each value with a price, the money values will be randomized
    /// and the player will go through them in that order. Every time the player picks a price,
    /// valueOn will be incremented.
    int moneys[4] = { 1000, 2000, 3000, 4000 };
    random_shuffle(&moneys[0], &moneys[4]);
    int valueOn = 0;

    /// Put the prices in an array and randomize them.
    int prices[5] = {carPrice, price2, price3, price4, price5};
    random_shuffle(&prices[0], &prices[5]);

    bool won = false;
    bool lost = false;
    bool bail = false;

    int winnings = 0;

    //cout << endl << "Price: $" << carPrice;

    cout << endl;
    while ( (!won) && (!lost) && (!bail) )
    {
        int choice = 0;
        char keepGoing = 'A';
        cout << "1. $" << prices[0];
        if (picked[0])
            cout << "- O";
        cout << endl;
        cout << "2. $" << prices[1];
        if (picked[1])
            cout << "- O";
        cout << endl;
        cout << "3. $" << prices[2];
        if (picked[2])
            cout << "- O";
        cout << endl;
        cout << "4. $" << prices[3];
        if (picked[3])
            cout << "- O";
        cout << endl;
        cout << "5. $" << prices[4];
        if (picked[4])
            cout << "- O";
        cout << endl;
        cout << "Which price do you want to pick?: ";
        cin >> choice;
        switch (choice){

    case 1:
        if (picked[0] == false)
        {
            if (prices[0] == carPrice)
                lost = true;
            else
            {
                picked[0] = true;
                cout << endl << "Behind this price is $" << moneys[valueOn] << "." << endl;
                winnings += moneys[valueOn];
                if (winnings < 10000){
                cout << "Right now you have $" << winnings << ".";
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') )
                {
                cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
                cin >> keepGoing;
                } /// end while loop
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                    valueOn += 1;
                else
                    bail = true;
                }
                else
                    won = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 2:
        if (picked[1] == false)
        {
            if (prices[1] == carPrice)
                lost = true;
            else
            {
                picked[1] = true;
                cout << endl << "Behind this price is $" << moneys[valueOn] << "." << endl;
                winnings += moneys[valueOn];
                if (winnings < 10000){
                cout << "Right now you have $" << winnings << ".";
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') )
                {
                cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
                cin >> keepGoing;
                } /// end while loop
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                    valueOn += 1;
                else
                    bail = true;
                }
                else
                    won = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 3:
        if (picked[2] == false)
        {
            if (prices[2] == carPrice)
                lost = true;
            else
            {
                picked[2] = true;
                cout << endl << "Behind this price is $" << moneys[valueOn] << "." << endl;
                winnings += moneys[valueOn];
                if (winnings < 10000){
                cout << "Right now you have $" << winnings << ".";
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') )
                {
                cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
                cin >> keepGoing;
                } /// end while loop
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                    valueOn += 1;
                else
                    bail = true;
                }
                else
                    won = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 4:
        if (picked[3] == false)
        {
            if (prices[3] == carPrice)
                lost = true;
            else
            {
                picked[3] = true;
                cout << endl << "Behind this price is $" << moneys[valueOn] << "." << endl;
                winnings += moneys[valueOn];
                if (winnings < 10000){
                cout << "Right now you have $" << winnings << ".";
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') )
                {
                cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
                cin >> keepGoing;
                } /// end while loop
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                    valueOn += 1;
                else
                    bail = true;
                }
                else
                    won = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    case 5:
        if (picked[4] == false)
        {
            if (prices[4] == carPrice)
                lost = true;
            else
            {
                picked[4] = true;
                cout << endl << "Behind this price is $" << moneys[valueOn] << "." << endl;
                winnings += moneys[valueOn];
                if (winnings < 10000){
                cout << "Right now you have $" << winnings << ".";
                while ( (keepGoing != 'Y') && (keepGoing != 'N') &&  (keepGoing != 'y') && (keepGoing != 'n') )
                {
                cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
                cin >> keepGoing;
                } /// end while loop
                if ((keepGoing == 'Y') || (keepGoing == 'y'))
                    valueOn += 1;
                else
                    bail = true;
                }
                else
                    won = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

    default:
        cout << endl << "That won't work. Try again." << endl;

        } /// end switch statement

    if (valueOn == 4)
        won = true;
    }

    if (won)
        cout << endl << "Congratulations, you win!";
    if (lost)
    {
        winnings = 0;
        cout << endl << "Sorry, you lose.";
    }
    if (bail)
        cout << endl << "You're walking away with $" << winnings << ". Thanks for playing!";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Golden Road
void playGoldenRoad()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;
    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;
    grocery * ggptr;

    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    list<large> gameLarges;
    list<large>::iterator gameLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    srand(time(0));

    int i = 0; // Cars
    int j = 0; // Grocery items
    int k = 0; // Medium items
    int l = 0; // Large items

    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > 40000) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + grocInput);
    while (inFile)
    {
    ggptr = new grocery;
    if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice < 0.99) && (t_ggPrice > 0.30) )
    {
        ggptr->setDescription(t_ggDescription);
        ggptr->setShortName(t_ggShortName);
        ggptr->setPrice(t_ggPrice);
        ggItems.push_back(*ggptr);
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
    mptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price < 1000) )
    {
        mptr->setDescription(m_Description);
        mptr->setShortName(m_ShortName);
        mptr->setPrice(m_Price);
        gameMeds.push_back(*mptr);
        k++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + largInput);
    while (inFile)
    {
    lptr = new large;
    if (inFile >> l_Description >> l_ShortName >> l_Price)
    {
        lptr->setDescription(l_Description);
        lptr->setShortName(l_ShortName);
        lptr->setPrice(l_Price);
        gameLarges.push_back(*lptr);
        l++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "GOLDEN ROAD" << endl;
//    cout << endl << "cars = " << i;
//    cout << endl << "grocs = " << j;
//    cout << endl << "meds = " << k;
//    cout << endl << "larges = " << l;

    grocery prizeGroc;
    medium  prizeMed;
    large   prizeLarge;
    car     prizeCar;

    bool setup = false;

    while (!setup){
    int ofCars = rand() % i;
    int ofGroc = rand() % j;
    int ofMeds = rand() % k;
    int ofLarg = rand() % l;

    gameCarIt = gameCars.begin();
    for (int z = 0; z < ofCars; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z = 0; z < ofGroc; z++)
        ggItemIt++;
    prizeGroc.setDescription(ggItemIt->getDescription());
    prizeGroc.setShortName(ggItemIt->getShortName());
    prizeGroc.setPrice(ggItemIt->getPrice());

    gameMedIt = gameMeds.begin();
    for (int z = 0; z < ofMeds; z++)
        gameMedIt++;
    prizeMed.setDescription(gameMedIt->getDescription());
    prizeMed.setShortName(gameMedIt->getShortName());
    prizeMed.setPrice(gameMedIt->getPrice());

    gameLargeIt = gameLarges.begin();
    for (int z = 0; z < ofLarg; z++)
        gameLargeIt++;
    prizeLarge.setDescription(gameLargeIt->getDescription());
    prizeLarge.setShortName(gameLargeIt->getShortName());
    prizeLarge.setPrice(gameLargeIt->getPrice());

    if ( forGoldenRoad(prizeGroc.getPrice(), prizeMed.getPrice(), prizeLarge.getPrice(), prizeCar.getPrice()) )
        setup = true;
    } // end while loop setting up the gameplay

//    cout << endl;
//    prizeGroc.showARP();
//    cout << endl;
//    prizeMed.showARP();
//    cout << endl;
//    prizeLarge.showARP();
//    cout << endl;
//    prizeCar.showARP();

    cout << endl << "At the end of the golden road today is..." << endl;
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    cout << endl;
    cout << endl << "Your journey down the golden road begins with:";
    cout << endl;
    prizeGroc.showPrize();
    cout << endl << "worth ";
    prizeGroc.showARP();

    double temp = prizeGroc.getPrice() * 100;
    int fin = static_cast<int>(temp);

    //cout << endl << "temp = " << temp;
    //cout << endl << "fin = " << fin;
    int firstChoices[2];
    firstChoices[0] = fin / 10 % 10;
    firstChoices[1] = fin % 10;

    int secondChoices[3];
    secondChoices[0] = prizeMed.getPrice() / 100 % 10;
    secondChoices[1] = prizeMed.getPrice() / 10 % 10;
    secondChoices[2] = prizeMed.getPrice() % 10;

    //cout << endl << "price: $" << prizeMed.getPrice();
    //cout << endl << secondChoices[0] << ", " << secondChoices[1] << ", " << secondChoices[2];

    int thirdChoices[4];
    thirdChoices[0] = prizeLarge.getPrice() / 1000 % 10;
    thirdChoices[1] = prizeLarge.getPrice() / 100 % 10;
    thirdChoices[2] = prizeLarge.getPrice() / 10 % 10;
    thirdChoices[3] = prizeLarge.getPrice() % 10;

    int carChoices[5];
    carChoices[0] = prizeCar.getPrice() / 10000 % 10;
    carChoices[1] = prizeCar.getPrice() / 1000 % 10;
    carChoices[2] = prizeCar.getPrice() / 100 % 10;
    carChoices[3] = prizeCar.getPrice() / 10 % 10;
    carChoices[4] = prizeCar.getPrice() % 10;

    cout << endl;
    int choice1 = 10;
    cout << endl << "1. ";
    prizeMed.showPrize();
    cout << endl << "$*" << secondChoices[1] << secondChoices[2];
    while ( (choice1 != firstChoices[0]) && (choice1 != firstChoices[1]) ){
        cout << endl << "What digit from the ";
        prizeGroc.showShortName();
        cout << " is the missing number?: ";
        cin >> choice1;
    }

    cout << endl << "The actual retail price of the ";
    prizeMed.showShortName();
    cout << " is $" << prizeMed.getPrice();
    if (choice1 == secondChoices[0]){
        int choice2 = 10;
        cout << endl << "Yes, that's correct! On to the next item...";
        cout << endl;
        cout << endl << "2. ";
        prizeLarge.showPrize();
        cout << endl << "$" << thirdChoices[0] << "*" << thirdChoices[2] << thirdChoices[3];
        while ( (choice2 != secondChoices[0]) && (choice2 != secondChoices[1]) && (choice2 != secondChoices[2]) ){
            cout << endl << "What digit from the ";
            prizeMed.showShortName();
            cout << " is the missing number?: ";
            cin >> choice2;
        }

        cout << endl << "The actual retail price of the ";
        prizeLarge.showShortName();
        cout << " is $" << prizeLarge.getPrice();
        if (choice2 == thirdChoices[1]){
        int choice3 = 10;
        cout << endl << "Yes, that's correct! On to the final item...";
        cout << endl;
        cout << endl << "3. ";
        prizeCar.showModel();
        cout << endl << "Comes with: ";
        prizeCar.showOptions();
        cout << endl << "$" << carChoices[0] << carChoices[1] << "*" << carChoices[3] << carChoices[4];
        while ( (choice3 != thirdChoices[0]) && (choice3 != thirdChoices[1]) && (choice3 != thirdChoices[2]) && (choice3 != thirdChoices[3]) ){
            cout << endl << "What digit from the ";
            prizeLarge.showShortName();
            cout << " is the missing number?: ";
            cin >> choice3;
        }
        cout << endl << "The actual retail price of the car is $" << prizeCar.getPrice();
        if (choice3 == carChoices[2])
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";

        } // end if player guessed second item correctly
        else
            cout << endl << "Sorry, you lose.";

    } // end if player guessed first item correctly
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Gridlock!
void playGridlock()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "GRIDLOCK!" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    //cout << endl << "price = $" << carPrice << endl;

    int first = carPrice / 10000 % 10;

    /// Get the next two digits of the car's price
    int correct1 = (carPrice / 1000 % 10)*10 + (carPrice / 100 % 10);
    //cout << endl << "a = " << correct1;

    /// Get the last two digits of the car's price
    int correct2 = (carPrice / 10 % 10)*10 + (carPrice % 10);
    //cout << endl << "b = " << correct2;

    /// Create "wrong" answers for each price. They're initially set to the correct value and are eventually changed.
    int wrongFirstA = correct1;
    int wrongFirstB = correct1;
    if (correct1 < 30)
    {
        while (wrongFirstA == correct1)
            wrongFirstA = rand() % 30;
        while ( (wrongFirstB == correct1) || (wrongFirstB == wrongFirstA) )
            wrongFirstB = rand() % 30;
    }
    else if (correct1 > 70)
    {
        while (wrongFirstA == correct1)
            wrongFirstA = rand()%(99-71 + 1) + 71;
        while ( (wrongFirstB == correct1) || (wrongFirstB == wrongFirstA) )
            wrongFirstB = rand()%(99-71 + 1) + 71;
    }
    else
    {
        while (wrongFirstA == correct1)
            wrongFirstA = rand()%(69-31 + 1) + 31;
        while ( (wrongFirstB == correct1) || (wrongFirstB == wrongFirstA) )
            wrongFirstB = rand()%(69-31 + 1) + 31;
    }

    //cout << endl << correct1 << ", " << wrongFirstA << ", " << wrongFirstB << endl;

    int wrongSecondA = correct2;
    int wrongSecondB = correct2;
    while (wrongSecondA == correct2)
        wrongSecondA = rand() % 100;
    while ( (wrongSecondB == correct2) || (wrongSecondB == wrongSecondA) )
        wrongSecondB = rand() % 100;

    /// These variables determine which of the three choices will be correct.
    int position1 = rand() % 3;
    int position2 = rand() % 3;

    int chances = 2;
    bool won = false;
    bool gotCarOne = false;

    bool chosenWFA = false;
    bool chosenWFB = false;
    bool chosenWSA = false;
    bool chosenWSB = false;

    while ( (chances > 0) && !won )
    {
        int choice = 0;
        cout << endl << "Chances left: " << chances;
        if (gotCarOne){
        cout << endl << "$" << first << mgSpace(correct1) << "**";
        if (position2 == 0)
        {
            cout << endl << "1. " << mgSpace(correct2);
            cout << endl << "2. " << mgSpace(wrongSecondA);
            if (chosenWSA)
                cout << " - X";
            cout << endl << "3. " << mgSpace(wrongSecondB);
            if (chosenWSB)
                cout << " - X";
        }
        else if (position2 == 1)
        {
            cout << endl << "1. " << mgSpace(wrongSecondA);
            if (chosenWSA)
                cout << " - X";
            cout << endl << "2. " << mgSpace(correct2);
            cout << endl << "3. " << mgSpace(wrongSecondB);
            if (chosenWSB)
                cout << " - X";
        }
        else
        {
            cout << endl << "1. " << mgSpace(wrongSecondA);
            if (chosenWSA)
                cout << " - X";
            cout << endl << "2. " << mgSpace(wrongSecondB);
            if (chosenWSB)
                cout << " - X";
            cout << endl << "3. " << mgSpace(correct2);
        }
        while ( (choice < 1) || (choice > 3) ){
            cout << endl << "What are the next two digits in the price of the car?: ";
            cin >> choice;
        }
        if (choice == 1)
        {
            if ( (chosenWSA) && (position2 != 0) )
                cout << endl << "You've already chosen this one. Please pick another.";
            else
            {
                if (position2 == 0)
                    won = true;
                else
                {
                    chosenWSA = true;
                    chances -= 1;
                }
            }
        } // end if choice==1
        else if (choice == 2)
        {
            if ( (position2 == 0) && chosenWSA)
                cout << endl << "You've already chosen this one. Please pick another.";
            else if ( (position2 == 2) && chosenWSB)
                cout << endl << "You've already chosen this one. Please pick another.";
            else
            {
            if (position2 == 1)
                won = true;
            else if (position2 == 0)
            {
                chosenWSA = true;
                chances -= 1;
            }
            else
            {
               chosenWSB = true;
               chances -= 1;
            }
            }
        } // end if choice==2
        else
        {
            if ( (chosenWSB) && (position2 != 2) )
                cout << endl << "You've already chosen this one. Please pick another.";
                else
                {
                    if (position2 == 2)
                        won = true;
                    else
                    {
                        chosenWSB = true;
                        chances -= 1;
                    }
                }
        } // end if choice==3


        } // end if statement if player has guessed the first pair of digits correctly
        else{
            cout << endl << "$" << first << "****";
                if (position1 == 0)
                {
                    cout << endl << "1. " << mgSpace(correct1);
                    cout << endl << "2. " << mgSpace(wrongFirstA);
                    if (chosenWFA)
                        cout << " - X";
                    cout << endl << "3. " << mgSpace(wrongFirstB);
                    if (chosenWFB)
                        cout << " - X";
                }
                else if (position1 == 1)
                {
                    cout << endl << "1. " << mgSpace(wrongFirstA);
                    if (chosenWFA)
                        cout << " - X";
                    cout << endl << "2. " << mgSpace(correct1);
                    cout << endl << "3. " << mgSpace(wrongFirstB);
                    if (chosenWFB)
                        cout << " - X";
                }
                else
                {
                    cout << endl << "1. " << mgSpace(wrongFirstA);
                    if (chosenWFA)
                        cout << " - X";
                    cout << endl << "2. " << mgSpace(wrongFirstB);
                    if (chosenWFB)
                        cout << " - X";
                    cout << endl << "3. " << mgSpace(correct1);
                }
            while ( (choice < 1) || (choice > 3) ){
                cout << endl << "What are the next two digits in the price of the car?: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                if ((chosenWFA) && (position1 != 0) )
                    cout << endl << "You've already chosen this one. Please pick another.";
                else
                {
                if (position1 == 0){
                    cout << endl << "That's correct! Onto the final two digits...";
                    gotCarOne = true;
                    }
                else
                {
                    chosenWFA = true;
                    chances -= 1;
                }
                }
            } // end if choice==1
            else if (choice == 2)
            {
                if ( (position1 == 0) && chosenWFA)
                    cout << endl << "You've already chosen this one. Please pick another.";
                else if ( (position1 == 2) && chosenWFB)
                    cout << endl << "You've already chosen this one. Please pick another.";
                else{
                if (position1 == 1){
                    cout << endl << "That's correct! Onto the final two digits...";
                    gotCarOne = true;
                    }
                else if (position1 == 0)
                {
                    chosenWFA = true;
                    chances -= 1;
                }
                else
                {
                    chosenWFB = true;
                    chances -= 1;
                }
                }
            } // end if choice==2
            else
            {
                if ((chosenWFB) && (position1 != 2) )
                    cout << endl << "You've already chosen this one. Please pick another.";
                else
                {
                    if (position1 == 2){
                    cout << endl << "That's correct! Onto the final two digits...";
                    gotCarOne = true;
                    }
                    else
                    {
                        chosenWFB = true;
                        chances -= 1;
                    }
                }
            } // end if choice==3

        } // end else statement for first car


    } // end while loop

    cout << endl << "$" << carPrice;
    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// It's Optional
void playItsOptional()
{
    /// cars
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    /// medium prizes
    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    /// small prize
    list<small> gameSmalls;
    list<small>::iterator gameSmallIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    int k = 0;

    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
        mptr = new medium;
        if ( (inFile >> m_Description >> m_ShortName >> m_Price) )
        {
            mptr->setDescription(m_Description);
            mptr->setShortName(m_ShortName);
            mptr->setPrice(m_Price);
            gameMeds.push_back(*mptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        sptr = new small;
        if ( (inFile >> s_Description >> s_ShortName >> s_Price) )
        {
            sptr->setDescription(s_Description);
            sptr->setShortName(s_ShortName);
            sptr->setPrice(s_Price);
            gameSmalls.push_back(*sptr);
            k++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "IT'S OPTIONAL" << endl;

    car firstCar;
    car secondCar;

    int carID1;
    int carID2;
    int difference;

    bool setCars = false;

    while (!setCars){
    carID1 = rand() % i;
    carID2 = carID1;
    while (carID2 == carID1)
        carID2 = rand() % i;

    gameCarIt = gameCars.begin();
    for (int z = 0; z < carID1; z++)
        gameCarIt++;
    firstCar.setModel(gameCarIt->getModel());
    firstCar.setOptions(gameCarIt->getOptions());
    firstCar.setPrice(gameCarIt->getPrice());

    gameCarIt = gameCars.begin();
    for (int z = 0; z < carID2; z++)
        gameCarIt++;
    secondCar.setModel(gameCarIt->getModel());
    secondCar.setOptions(gameCarIt->getOptions());
    secondCar.setPrice(gameCarIt->getPrice());

    difference = secondCar.getPrice() - firstCar.getPrice();

    if ( (difference >= 5000) && (difference <= 10000) )
        setCars = true;
    } // end while loop

    int counting[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    random_shuffle(&counting[0], &counting[9]);

    medium temps[9];
    medium options[9];

    /// The "option board" will have three medium prizes over $1000, three medium
    /// prizes under $1000, and three small prizes.
    bool setOp1 = false;
    bool setOp2 = false;
    bool setOp3 = false;
    bool setOp4 = false;
    bool setOp5 = false;
    bool setOp6 = false;
    bool setOp7 = false;
    bool setOp8 = false;
    bool setOp9 = false;

    int medID1;
    int medID2;
    int medID3;
    int medID4;
    int medID5;
    int medID6;
    int smaID1;
    int smaID2;
    int smaID3;

    /// We'll start by choosing the three "larger" medium prizes.
    while (!setOp1){
    medID1 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID1; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() >= 2000){
    temps[0].setDescription(gameMedIt->getDescription());
    temps[0].setShortName(gameMedIt->getShortName());
    temps[0].setPrice(gameMedIt->getPrice());
    setOp1 = true;
    }
    } // end while loop

    while (!setOp2){
    medID2 = medID1;
    while (medID2 == medID1)
        medID2 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID2; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() >= 1500){
    temps[1].setDescription(gameMedIt->getDescription());
    temps[1].setShortName(gameMedIt->getShortName());
    temps[1].setPrice(gameMedIt->getPrice());
    setOp2 = true;
    }
    } // end while loop

    while (!setOp3){
    medID3 = medID1;
    while ( (medID3 == medID1) || (medID3 == medID2) )
        medID3 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID3; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() >= 1000){
    temps[2].setDescription(gameMedIt->getDescription());
    temps[2].setShortName(gameMedIt->getShortName());
    temps[2].setPrice(gameMedIt->getPrice());
    setOp3 = true;
    }
    } // end while loop

    /// Set the three smaller medium prizes.
    while (!setOp4){
    medID4 = medID1;
    while ( (medID4 == medID1) || (medID4 == medID2) || (medID4 == medID3) )
        medID4 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID4; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() < 1000){
    temps[3].setDescription(gameMedIt->getDescription());
    temps[3].setShortName(gameMedIt->getShortName());
    temps[3].setPrice(gameMedIt->getPrice());
    setOp4 = true;
    }
    } // end while loop

    while (!setOp5){
    medID5 = medID1;
    while ( (medID5 == medID1) || (medID5 == medID2) || (medID5 == medID3) || (medID5 == medID4) )
        medID5 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID5; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() < 1000){
    temps[4].setDescription(gameMedIt->getDescription());
    temps[4].setShortName(gameMedIt->getShortName());
    temps[4].setPrice(gameMedIt->getPrice());
    setOp5 = true;
    }
    } // end while loop

    while (!setOp6){
    medID6 = medID1;
    while ( (medID6 == medID1) || (medID6 == medID2) || (medID6 == medID3) || (medID6 == medID4) || (medID6 == medID5) )
        medID6 = rand() % j;
    gameMedIt = gameMeds.begin();
    for (int z = 0; z < medID6; z++)
        gameMedIt++;
    if (gameMedIt->getPrice() < 1000){
    temps[5].setDescription(gameMedIt->getDescription());
    temps[5].setShortName(gameMedIt->getShortName());
    temps[5].setPrice(gameMedIt->getPrice());
    setOp6 = true;
    }
    } // end while loop

    /// Set the three small prizes.
    while (!setOp7){
    smaID1 = rand() % k;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < smaID1; z++)
        gameSmallIt++;
    temps[6].setDescription(gameSmallIt->getDescription());
    temps[6].setShortName(gameSmallIt->getShortName());
    temps[6].setPrice(gameSmallIt->getPrice());
    setOp7 = true;
    } // end while loop

    while (!setOp8){
    smaID2 = smaID1;
    while (smaID2 == smaID1)
        smaID2 = rand() % k;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < smaID2; z++)
        gameSmallIt++;
    temps[7].setDescription(gameSmallIt->getDescription());
    temps[7].setShortName(gameSmallIt->getShortName());
    temps[7].setPrice(gameSmallIt->getPrice());
    setOp8 = true;
    } // end while loop

    while (!setOp9){
    smaID3 = smaID1;
    while ( (smaID3 == smaID1) || (smaID3 == smaID2) )
        smaID3 = rand() % k;
    gameSmallIt = gameSmalls.begin();
    for (int z = 0; z < smaID3; z++)
        gameSmallIt++;
    temps[8].setDescription(gameSmallIt->getDescription());
    temps[8].setShortName(gameSmallIt->getShortName());
    temps[8].setPrice(gameSmallIt->getPrice());
    setOp9 = true;
    } // end while loop

//    cout << endl << endl;
//    temps[0].showPrize();
//    cout << endl;
//    temps[1].showPrize();
//    cout << endl;
//    temps[2].showPrize();
//    cout << endl;
//    temps[3].showPrize();
//    cout << endl;
//    temps[4].showPrize();
//    cout << endl;
//    temps[5].showPrize();
//    cout << endl;
//    temps[6].showPrize();
//    cout << endl;
//    temps[7].showPrize();
//    cout << endl;
//    temps[8].showPrize();

    cout << endl << "Car #1: ";
    firstCar.showModel();
    cout << endl << "Car #2: ";
    secondCar.showModel();

    //cout << endl << "first price: $" << firstCar.getPrice();
    //cout << endl << "second price: $" << secondCar.getPrice();

    for (int s = 0; s < 9; s++){
    options[counting[s]].setDescription(temps[s].getDescription());
    options[counting[s]].setShortName(temps[s].getShortName());
    options[counting[s]].setPrice(temps[s].getPrice());
    }

    bool won = false;
    bool lost = false;
    int choicesLeft = 4;
    int distance = firstCar.getPrice();

    bool chosen[9];
    for (int c = 0; c < 9; c++)
        chosen[c] = false;
    cout << endl;

    while ( (!won) && (!lost) && (choicesLeft > 0) ){
    cout << endl << "Car #1 is at $" << distance << " and car #2 is at $" << secondCar.getPrice();
    if (choicesLeft == 1)
        cout << endl << "You have 1 item left to choose.";
    else
        cout << endl << "You have " << choicesLeft << " items left to choose.";
    cout << endl;
    for (int t = 0; t < 9; t++){
    if (!(chosen[t]))
        cout << endl << t+1 << ". ";
    else
        cout << endl << "X. ";
    options[t].showPrize();
    }

    int choice = 0;
    while ( (choice < 1) || (choice > 9) ){
        cout << endl << "Which item would you like to pick?: ";
            cin >> choice;
        if (chosen[choice-1])
            cout << endl << "You've already chosen this item. Please pick another one.";
    } // end while loop

    distance += options[choice-1].getPrice();
    cout << endl << "The actual retail price of the item is $" << options[choice-1].getPrice();
    cout << endl << "The car on the left has traveled to $" << distance << ".";
    chosen[choice-1] = true;
    cout << endl;
    if (distance > secondCar.getPrice())
        lost = true;
    else if ( ((secondCar.getPrice() - distance) <= 1000) && ((secondCar.getPrice() - distance) >= 0) )
        won = true;

    choicesLeft -= 1;
    } // end main gameplay while loop

    if ( ((secondCar.getPrice() - distance) <= 1000) && ((secondCar.getPrice() - distance) >= 0) ){
        cout << endl << "Car #1 is at $" << distance << " and car #2 is at $" << secondCar.getPrice();
        cout << endl << "Congratulations, you win!";
    }
    else if (distance > secondCar.getPrice()){
        cout << endl << "Car #1's distance exceeded car #2's price... \nSorry, you lose.";
    }
    else{
        cout << endl << "Car #1 is at $" << distance << " and car #2 is at $" << secondCar.getPrice();
        cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Line 'em Up
void playLineEmUp()
{
    /// Fun fact: This was the 75th game completed!

    /// car
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    /// small prize
    list<small> gameSmalls;
    list<small>::iterator gameSmallIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    /// medium prize
    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    int k = 0;

    ifstream inFile;

    /// Load cars
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Load small prizes
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
    sptr = new small;
    if ( (inFile >> s_Description >> s_ShortName >> s_Price) && (s_Price < 100) && (compatibleForLineEmUp(s_Price)) )
    {
        sptr->setDescription(s_Description);
        sptr->setShortName(s_ShortName);
        sptr->setPrice(s_Price);
        gameSmalls.push_back(*sptr);
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Load medium prizes
    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
    mptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price < 1000) && (compatibleForLineEmUp(m_Price)) )
    {
        mptr->setDescription(m_Description);
        mptr->setShortName(m_ShortName);
        mptr->setPrice(m_Price);
        gameMeds.push_back(*mptr);
        k++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << endl << "LINE 'EM UP" << endl;

    /// Pick a random car
    int carID = rand() % i;

    car prizeCar;
    medium prize1;
    small prize2;
    medium prize3;

    /// Set the car's price
    gameCarIt = gameCars.begin();
    for (int zCar = 0; zCar < carID; zCar++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    //cout << endl << "j = " << j;
    //cout << endl << "k = " << k;
    //cout << endl << "car price: $" << prizeCar.getPrice() << endl;

    int coreDigits[3];
    int playerDigits[3];

    coreDigits[0] = prizeCar.getPrice() / 1000 % 10;
    coreDigits[1] = prizeCar.getPrice() / 100 % 10;
    coreDigits[2] = prizeCar.getPrice() / 10 % 10;

    playerDigits[0] = 10;
    playerDigits[1] = 10;
    playerDigits[2] = 10;

    int hold;

    /// Set first prize
    bool foundFirst = false;
    while (!foundFirst){
    int id1 = rand() % k;
    hold = id1;
    gameMedIt = gameMeds.begin();
    for (int z1 = 0; z1 < id1; z1++)
        gameMedIt++;
    if ( inMedPrice( (gameMedIt->getPrice()), coreDigits[0] ) )
    {
        prize1.setDescription(gameMedIt->getDescription());
        prize1.setShortName(gameMedIt->getShortName());
        prize1.setPrice(gameMedIt->getPrice());
        foundFirst = true;
    }
    } // end while loop

   /// Set second prize
    bool foundSecond = false;
    while (!foundSecond){
    int id2 = rand() % j;
    gameSmallIt = gameSmalls.begin();
    for (int z2 = 0; z2 < id2; z2++)
        gameSmallIt++;
    if ( inSmallPrice( (gameSmallIt->getPrice()), coreDigits[1]) )
    {
        prize2.setDescription(gameSmallIt->getDescription());
        prize2.setShortName(gameSmallIt->getShortName());
        prize2.setPrice(gameSmallIt->getPrice());
        foundSecond = true;
    }
    } // end while loop

    /// Set third prize
    bool foundThird = false;
    while (!foundThird){
    int id3 = hold;
    while (id3 == hold)
        id3 = rand() % k;
    gameMedIt = gameMeds.begin();
    for (int z3 = 0; z3 < id3; z3++)
        gameMedIt++;
    if ( inMedPrice( (gameMedIt->getPrice()), coreDigits[2] ) && (gameMedIt->getPrice() != prize1.getPrice()) )
    {
        prize3.setDescription(gameMedIt->getDescription());
        prize3.setShortName(gameMedIt->getShortName());
        prize3.setPrice(gameMedIt->getPrice());
        foundThird = true;
    }
    } // end while loop

//    cout << endl << "first price: $" << prize1.getPrice();
//    cout << endl << "second prize: $" << prize2.getPrice();
//    cout << endl << "third prize: $" << prize3.getPrice();

    int first = prizeCar.getPrice() / 10000 % 10;
    int last = prizeCar.getPrice() / 1 % 10;

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();
    cout << endl;
    cout << endl << "1. ";
    prize1.showPrize();
    cout << endl << "2. ";
    prize2.showPrize();
    cout << endl << "3. ";
    prize3.showPrize();

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "$" << prize1.getPrice() << " ";
    prize1.showShortName();
    cout << "<";
    cout << endl << "$" << prize2.getPrice() << " ";
    prize2.showShortName();
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << "***" << last;

    int firstDigits[3];
    firstDigits[0] = prize1.getPrice() / 100 % 10;
    firstDigits[1] = prize1.getPrice() / 10 % 10;
    firstDigits[2] = prize1.getPrice() % 10;

    while ( (playerDigits[0] != firstDigits[0]) && (playerDigits[0] != firstDigits[1]) && (playerDigits[0] != firstDigits[2]) ){
        cout << endl << "What is the second digit in the price of the car?: ";
        cin >> playerDigits[0];
    }

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "     " << playerDigits[0];
    cout << endl << "$" << prize2.getPrice() << " ";
    prize2.showShortName();
    cout << "<";
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << playerDigits[0] << "**" << last;

    int secondDigits[2];
    secondDigits[0] = prize2.getPrice() / 10 % 10;
    secondDigits[1] = prize2.getPrice() % 10;

    while ( ( playerDigits[1] != secondDigits[0] ) && (playerDigits[1] != secondDigits[1]) ){
        cout << endl << "What is the third digit in the price of the car?: ";
        cin >> playerDigits[1];
    }

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "     " << playerDigits[0];
    cout << endl << "     " << playerDigits[1];
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << "<";
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << playerDigits[0] << playerDigits[1] << "*" << last;

    int thirdDigits[3];
    thirdDigits[0] = prize3.getPrice() / 100 % 10;
    thirdDigits[1] = prize3.getPrice() / 10 % 10;
    thirdDigits[2] = prize3.getPrice() % 10;

    while ( (playerDigits[2] != thirdDigits[0]) && (playerDigits[2] != thirdDigits[1]) && (playerDigits[2] != thirdDigits[2]) ){
        cout << endl << "What is the fourth digit in the price of the car?: ";
        cin >> playerDigits[2];
    }

    cout << endl << "You have a price of $" << first << playerDigits[0] << playerDigits[1] << playerDigits[2] << last;
    cout << endl << "Is this correct?";
    cout << endl;
    system("pause");

    int hasRight = 0;

    for (int p = 0; p < 3; p++){
        if (coreDigits[p] == playerDigits[p])
            hasRight++;
    }

    if (hasRight == 3)
        cout << endl << "Congratulations, you win!";
    else
    {
        cout << endl << "No, that's not correct.";
        if (hasRight == 1)
            cout << endl << "You have 1 number right.";
        else
            cout << endl << "You have " << hasRight << " numbers right.";

    playerDigits[0] = 10;
    playerDigits[1] = 10;
    playerDigits[2] = 10;

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "$" << prize1.getPrice() << " ";
    prize1.showShortName();
    cout << "<";
    cout << endl << "$" << prize2.getPrice() << " ";
    prize2.showShortName();
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << "***" << last;

    while ( (playerDigits[0] != firstDigits[0]) && (playerDigits[0] != firstDigits[1]) && (playerDigits[0] != firstDigits[2]) ){
        cout << endl << "What is the second digit in the price of the car?: ";
        cin >> playerDigits[0];
    }

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "     " << playerDigits[0];
    cout << endl << "$" << prize2.getPrice() << " ";
    prize2.showShortName();
    cout << "<";
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << playerDigits[0] << "**" << last;

    while ( ( playerDigits[1] != secondDigits[0] ) && (playerDigits[1] != secondDigits[1]) ){
        cout << endl << "What is the third digit in the price of the car?: ";
        cin >> playerDigits[1];
    }

    cout << endl << "     $";
    cout << endl << "     " << first;
    cout << endl << "     " << playerDigits[0];
    cout << endl << "     " << playerDigits[1];
    cout << endl << "$" << prize3.getPrice() << " ";
    prize3.showShortName();
    cout << "<";
    cout << endl << "     " << last;
    cout << endl << endl << "$" << first << playerDigits[0] << playerDigits[1] << "*" << last;

    while ( (playerDigits[2] != thirdDigits[0]) && (playerDigits[2] != thirdDigits[1]) && (playerDigits[2] != thirdDigits[2]) ){
        cout << endl << "What is the fourth digit in the price of the car?: ";
        cin >> playerDigits[2];
    }

    cout << endl << "You have a price of $" << first << playerDigits[0] << playerDigits[1] << playerDigits[2] << last;
    cout << endl << "Is this correct?";
    cout << endl;
    system("pause");

    hasRight = 0;

    for (int p = 0; p < 3; p++){
        if (coreDigits[p] == playerDigits[p])
            hasRight++;
    }

    if (hasRight == 3)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose." << endl << "The price of the car was $" << prizeCar.getPrice() << ".";

    } // end else

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Lucky $even
void playLuckySeven()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (!hasZeros(t_Price)) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "LUCKY $EVEN" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    int dollars = 7;
    bool won = false;
    int carPrice = prizeCar.getPrice();

        int normalDigits[5];
        normalDigits[0] = carPrice / 10000 % 10;
        normalDigits[1] = carPrice / 1000 % 10;
        normalDigits[2] = carPrice / 100 % 10;
        normalDigits[3] = carPrice / 10 % 10;
        normalDigits[4] = carPrice % 10;

        bool normalRevealed[5];
        for (int x = 0; x < 5; x++)
            normalRevealed[x] = false;


    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();
    int on = 0;

    while ((dollars > 0) && !won)
    {
        //cout << endl << "on = " << on << endl;
        int entry = 0;
        cout << endl << "Dollars left: $" << dollars;
        cout << endl << "Price: $";
        cout << normalDigits[0];
        if (normalRevealed[1] == true)
            cout << normalDigits[1];
        else
            cout << "*";
        if (normalRevealed[2] == true)
            cout << normalDigits[2];
        else
            cout << "*";
        if (normalRevealed[3] == true)
            cout << normalDigits[3];
        else
            cout << "*";
        if (normalRevealed[4] == true)
            cout << normalDigits[4];
        else
            cout << "*";
        while ((entry < 1) || (entry > 9)){
        cout << endl << "What is the next digit (1-9)?: ";
        cin >> entry;
        }
        if (on < 5)
        {
            normalRevealed[on+1] = true;
            //cout << normalDigits[on+1] << " - " << entry << endl;
            dollars -= abs(normalDigits[on+1]-entry);
            on += 1;
        }
       // cout << endl << "on = " << on << endl;
        if ((on >= 4) && (dollars >= 1) )
            won = true;
    } // end while loop

    if (dollars <= 0){
        cout << endl << "Sorry, you lose.";
        cout << endl << "The price of the car was $" << carPrice << "." << endl;
    }
    else{
        cout << endl << "Price: $" << carPrice;
        cout << endl << "Congratulations, you win!";
    }


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Master Price
void playMasterPrice()
{
    /// Credit to BigJon (probably) for making this game!

    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "MASTER PRICE" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int bidDigits[5];

    int chances = 5;
    bool won = false;

    while ( (chances > 0) && (!won) ){
        cout << endl << "Chances left: " << chances << endl;
        int bid = 0;
        while ( (bid < 10000) || (bid > 99999) ){
        cout << endl << "The car's price has no repeating digits.";
        cout << endl << "How much do you think the car is?: $";
        cin >> bid;
        if (!noRepeatingDigits(bid))
            bid = 0;
        }
        if (bid == carPrice)
            won = true;
        else{
        int hasRight = 0;
        int wrongPos = 0;
        bidDigits[0] = bid / 10000 % 10;
        bidDigits[1] = bid / 1000 % 10;
        bidDigits[2] = bid / 100 % 10;
        bidDigits[3] = bid / 10 % 10;
        bidDigits[4] = bid % 10;
        cout << endl << "Sorry, that's not correct.";
        cout << endl << "$" << bid;
        cout << endl << "$";
        for (int b = 0; b < 5; b++){
        if (bidDigits[b] == digits[b]){
            cout << "O";
            hasRight += 1;
        }
        else if (inCarPriceIncDig1(carPrice, bidDigits[b])){
            cout << " ";
            wrongPos += 1;
            }
        else
            cout << " ";
        } // end for loop
        if (hasRight == 1)
            cout << endl << "You have 1 correct digit and ";
        else
            cout << endl << "You have " << hasRight << " correct digits and ";
        cout << wrongPos << " in an incorrect position.";
        cout << endl;
        chances -= 1;
        } // else if player didn't get the car's price right
    }

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Money Game
void playMoneyGame()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (!incompatibleMoneyGame(t_Price)) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "MONEY GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    //cout << endl << "price = $" << carPrice << endl;

    int whichFront = rand() % 3;

    /// Get the first two digits of the car's price
    int frontDigits = (carPrice / 10000 % 10)*10 + (carPrice / 1000 % 10);

    //cout << "front digits = " << frontDigits << endl;

    /// Get the middle digit
    int middle = carPrice / 100 % 10;
    //cout << endl << "middle digit = " << middle << endl;

    /// Get the last two digits of the car's price
    int backDigits = (carPrice / 10 % 10)*10 + (carPrice % 10);

    //cout << "back digits = " << backDigits << endl;

    /// Place the front digits, back digits, and two decoy values for the front digits on the board.
    int spaces[9];
    spaces[0] = frontDigits;
    if (whichFront == 0)
    {
        spaces[1] = frontDigits+1;
        spaces[2] = frontDigits+2;
    }
    else if (whichFront == 1)
    {
        spaces[1] = frontDigits-1;
        spaces[2] = frontDigits+1;
    }
    else
    {
        spaces[1] = frontDigits-1;
        spaces[2] = frontDigits-2;
    }
    spaces[3] = backDigits;

    /// Ensure that one of the decoy values doesn't equal the last two digits. Just to be safe... like if we get a price like $22623.
    if (spaces[1] == backDigits)
    {
    while ( (spaces[1] == frontDigits) || (spaces[1] == backDigits) )
        spaces[1] = rand() % 100;
    }
    if (spaces[2] == backDigits)
    {
    while ( (spaces[2] == frontDigits) || (spaces[2] == backDigits) || (spaces[2] == spaces[1]) )
        spaces[2] = rand() % 100;
    }

    /// For the remaining spaces, generate random numbers that aren't used by another space. We start by initializing them to
    /// the value of spaces[0] just to get things going.
    spaces[4] = spaces[0];
    while ( (spaces[4] == spaces[0]) || (spaces[4] == spaces[1]) || (spaces[4] == spaces[2]) || (spaces[4] == spaces[3]) )
        spaces[4] = rand() % 100;

    spaces[5] = spaces[0];
    while ( (spaces[5] == spaces[0]) || (spaces[5] == spaces[1]) || (spaces[5] == spaces[2]) || (spaces[5] == spaces[3]) || (spaces[5] == spaces[4]) )
        spaces[5] = rand() % 100;

    spaces[6] = spaces[0];
    while ( (spaces[6] == spaces[0]) || (spaces[6] == spaces[1]) || (spaces[6] == spaces[2]) || (spaces[6] == spaces[3]) || (spaces[6] == spaces[4]) || (spaces[6] == spaces[5]) )
        spaces[6] = rand() % 100;

    spaces[7] = spaces[0];
    while ( (spaces[7] == spaces[0]) || (spaces[7] == spaces[1]) || (spaces[7] == spaces[2]) || (spaces[7] == spaces[3]) || (spaces[7] == spaces[4]) || (spaces[7] == spaces[5]) || (spaces[7] == spaces[6]) )
        spaces[7] = rand() % 100;

    spaces[8] = spaces[0];
    while ( (spaces[8] == spaces[0]) || (spaces[8] == spaces[1]) || (spaces[8] == spaces[2]) || (spaces[8] == spaces[3]) || (spaces[8] == spaces[4]) || (spaces[8] == spaces[5]) || (spaces[8] == spaces[6]) || (spaces[8] == spaces[7]) )
        spaces[8] = rand() % 100;

    /// Shuffle the values
    random_shuffle(&spaces[0], &spaces[9]);

    bool picked[9];
    for (int p = 0; p < 9; p++)
        picked[p] = false;

    bool won = false;
    bool lost = false;
    bool foundFront = false;
    bool foundBack = false;
    int moneyEarned = 0;
    int moneyAmtsPicked = 0;

    /*
    for (int x = 0; x < 9; x++)
        cout << spaces[x] << endl;
    */



    while (!won && !lost){
    //cout << endl << "picked = " << moneyAmtsPicked << endl;
    char choice = '!';
    cout << endl;
    cout << "---------------------" << endl << endl;
    cout << "A. ";
    if (!picked[0]) /// not been picked
        cout << mgSpace(spaces[0]);
    else if (picked[0] && (spaces[0] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[0] && (spaces[0] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | B. ";
    if (!picked[1]) /// not been picked
        cout << mgSpace(spaces[1]);
    else if (picked[1] && (spaces[1] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[1] && (spaces[1] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | C. ";
    if (!picked[2]) /// not been picked
        cout << mgSpace(spaces[2]);
    else if (picked[2] && (spaces[2] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[2] && (spaces[2] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << endl << "D. ";
    if (!picked[3]) /// not been picked
        cout << mgSpace(spaces[3]);
    else if (picked[3] && (spaces[3] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[3] && (spaces[3] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | E. ";
     if (!picked[4]) /// not been picked
        cout << mgSpace(spaces[4]);
    else if (picked[4] && (spaces[4] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[4] && (spaces[4] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | F. ";
    if (!picked[5]) /// not been picked
        cout << mgSpace(spaces[5]);
    else if (picked[5] && (spaces[5] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[5] && (spaces[5] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << endl << "G. ";
    if (!picked[6]) /// not been picked
        cout << mgSpace(spaces[6]);
    else if (picked[6] && (spaces[6] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[6] && (spaces[6] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | H. ";
    if (!picked[7]) /// not been picked
        cout << mgSpace(spaces[7]);
    else if (picked[7] && (spaces[7] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[7] && (spaces[7] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << " | I. ";
    if (!picked[8]) /// not been picked
        cout << mgSpace(spaces[8]);
    else if (picked[8] && (spaces[8] == frontDigits) ) /// picked front digits
        cout << "FF";
    else if (picked[8] && (spaces[8] == backDigits) ) /// picked back digits
        cout << "BB";
    else /// has money
        cout << "$$";
    //---//
    cout << endl;

    if (!foundFront && !foundBack){
    cout << endl << "-------$**" << middle;
    cout << "**--------" << endl;}
    if (foundFront && !foundBack){
    cout << endl << "-------$" << frontDigits << middle;
    cout << "**--------" << endl;}
    if (!foundFront && foundBack){
    cout << endl << "-------$**" << middle;
    cout << backDigits << "--------" << endl;}
    cout << "Which space (enter the letter) do you want to pick?: ";
    cin >> choice;
    switch (choice){

    case 'A':
        if (picked[0])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[0] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[0] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[0] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[0];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'a':
        if (picked[0])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[0] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[0] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[0] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[0];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'B':
        if (picked[1])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[1] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[1] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[1] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[1];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'b':
        if (picked[1])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[1] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[1] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[1] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[1];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'C':
        if (picked[2])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[2] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[2] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[2] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[2];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'c':
        if (picked[2])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[2] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[2] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[2] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[2];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'D':
        if (picked[3])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[3] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[3] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[3] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[3];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'd':
        if (picked[3])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[3] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[3] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[3] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[3];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'E':
        if (picked[4])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[4] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[4] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[4] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[4];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'e':
        if (picked[4])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[4] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[4] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[4] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[4];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'F':
        if (picked[5])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[5] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[5] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[5] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[5];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'f':
        if (picked[5])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[5] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[5] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[5] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[5];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'G':
        if (picked[6])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[6] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[6] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[6] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[6];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'g':
        if (picked[6])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[6] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[6] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[6] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[6];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'H':
        if (picked[7])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[7] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[7] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[7] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[7];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'h':
        if (picked[7])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[7] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[7] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[7] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[7];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'I':
        if (picked[8])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[8] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[8] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[8] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[8];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    case 'i':
        if (picked[8])
            cout << endl << "You've already picked this space. Please pick another.";
        else{
        picked[8] = true;
        cout << endl << "Let's see what's behind this space...";
        if (spaces[8] == frontDigits){
            cout << endl << "You found the front of the car!" << endl;
            foundFront = true;
            }
        else if (spaces[8] == backDigits){
            cout << endl << "You found the back of the car!" << endl;
            foundBack = true;
        }
        else{
            cout << endl << "There's cash behind this space." << endl;
            moneyEarned += spaces[8];
            moneyAmtsPicked += 1;
        }

        if (foundFront && foundBack)
            won = true;
        else if ( (moneyAmtsPicked >= 4) && !won )
            lost = true;
        } // end else
        break;

    default:
        cout << endl << "That won't work. Try again." << endl;


    } /// end switch statement
    } /// end while loop

    cout << endl << "$" << carPrice;
    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose. At least you won $" << moneyEarned << ". ";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// More or Less
void playMoreOrLess()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * pptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    ifstream inFile;
    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> m_Description >> m_ShortName >> m_Price) && m_Price > 1000)
    {
        pptr->setDescription(m_Description);
        pptr->setShortName(m_ShortName);
        pptr->setPrice(m_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "MORE OR LESS" << endl;

    ///----Work on randomization----///

    /// Randomization works by making an array of random numbers as big
    /// as the list of items, then reordering the array randomly. This way,
    /// it feels like the items in the list are being arranged randomly.
    int randomizationField[i];
    for (int k = 0; k < i; k++)
    {
        randomizationField[k] = k;
    }

    // rearrange the numbers
    random_shuffle(&randomizationField[0], &randomizationField[i]);

    /// Pick which car will be used in the game.
    int randomPrize = rand() % j;

    int z = 0;
    car prizeCar;
    medium prizes[3];

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (int z2 = 0; z2 < randomizationField[itemCount]; z2++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// If 0, the wrong price will be too low and the correct answer is MORE.
    /// If 1, the wrong price will be too high and the correct answer is LESS.
    int wrongValues[3];
    for (int t = 0; t < 3; t++)
    {
        wrongValues[t] = rand() % 2;
    }

    /// Because "it's always less," the correct answer for the car is more likely to be LESS.
    int wrongCarValue;
    int setCarWrong = rand() % 3;
    if (setCarWrong == 0)
        wrongCarValue = 0;
    else
        wrongCarValue = 1;

    /// Set the display prices.
    int displayPrices[4];

    if (wrongValues[0] == 0){
        displayPrices[0] = prizes[0].getPrice() - (((rand() % 5)+2)*100);
        displayPrices[0] = displayPrices[0] - (displayPrices[0] % 100);
        }
    else{
        displayPrices[0] = prizes[0].getPrice() + (((rand() % 5)+2)*100);
        displayPrices[0] = (displayPrices[0] - (displayPrices[0] % 100))+100;
        }

    if (wrongValues[1] == 0){
        displayPrices[1] = prizes[1].getPrice() - (((rand() % 5)+2)*100);
        displayPrices[1] = displayPrices[1] - (displayPrices[1] % 100);
        }
    else{
        displayPrices[1] = prizes[1].getPrice() + (((rand() % 5)+2)*100);
        displayPrices[1] = (displayPrices[1] - (displayPrices[1] % 100))+100;
        }

    if (wrongValues[2] == 0){
        displayPrices[2] = prizes[2].getPrice() - (((rand() % 5)+2)*100);
        displayPrices[2] = displayPrices[2] - (displayPrices[2] % 100);
        }
    else{
        displayPrices[2] = prizes[2].getPrice() + (((rand() % 5)+2)*100);
        displayPrices[2] = (displayPrices[2] - (displayPrices[2] % 100))+100;
        }

    if (wrongCarValue == 0){
        displayPrices[3] = prizeCar.getPrice() - (((rand() % 3)+1)*1000);
        displayPrices[3] = displayPrices[3] - (displayPrices[3] % 1000);
        }
    else{
        displayPrices[3] = prizeCar.getPrice() + (((rand() % 3)+1)*1000);
        displayPrices[3] = (displayPrices[3] - (displayPrices[3] % 1000))+1000;
        }

    bool won = false;
    bool lost = false;
    int prizesWon = 0;

    char choice1 = 'A';
    char choice2 = 'A';
    char choice3 = 'A';
    char choice4 = 'A';

    cout << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "$" << displayPrices[0];
    while ( (choice1 != 'M') && (choice1 != 'L') &&  (choice1 != 'm') && (choice1 != 'l') ){
    cout << endl << "This price is wrong. Is the correct price more (M) or less (L)?: ";
    cin >> choice1;
    }
    if ((choice1 == 'M') || (choice1 == 'm'))
    {
    cout << "The actual retail price is ";
    prizes[0].showARP();
    if (prizes[0].getPrice() >= displayPrices[0]){
        cout << endl << "That's correct! On to the next item...";
        cout << endl;
        prizesWon += 1;
        }
    else
        lost = true;
        } // end if player guesses MORE
    else
    {
    cout << "The actual retail price is ";
    prizes[0].showARP();
    if (prizes[0].getPrice() <= displayPrices[0]){
    cout << endl << "That's correct! On to the next item...";
    cout << endl;
    prizesWon += 1;
    }
    else
        lost = true;
    } /// end else

    if (!lost){
    cout << endl << "2. ";
    prizes[1].showPrize();
    cout << endl << "$" << displayPrices[1];
    while ( (choice2 != 'M') && (choice2 != 'L') &&  (choice2 != 'm') && (choice2 != 'l') ){
    cout << endl << "This price is wrong. Is the correct price more (M) or less (L)?: ";
    cin >> choice2;
    }

    if ((choice2 == 'M') || (choice2 == 'm'))
    {
    cout << "The actual retail price is ";
    prizes[1].showARP();
    if (prizes[1].getPrice() >= displayPrices[1]){
        cout << endl << "That's correct! On to the next item...";
        cout << endl;
        prizesWon += 1;
        }
    else
        lost = true;
        } // end if player guesses MORE
    else
    {
    cout << "The actual retail price is ";
    prizes[1].showARP();
    if (prizes[1].getPrice() <= displayPrices[1]){
    cout << endl << "That's correct! On to the next item...";
    cout << endl;
    prizesWon += 1;
    }
    else
        lost = true;
    } /// end else

    if (!lost)
    {
        cout << endl << "3. ";
        prizes[2].showPrize();
        cout << endl << "$" << displayPrices[2];
        while ( (choice3 != 'M') && (choice3 != 'L') && (choice3 != 'm') && (choice3 != 'l') ){
        cout << endl << "This price is wrong. Is the correct price more (M) or less (L)?: ";
        cin >> choice3;
        }
        if ((choice3 == 'M') || (choice3 == 'm'))
        {
        cout << "The actual retail price is ";
        prizes[2].showARP();
        if (prizes[2].getPrice() >= displayPrices[2]){
        cout << endl << "That's correct! On to the car...";
        cout << endl;
        prizesWon += 1;
        }
        else
            lost = true;
        } // end if player guesses MORE
        else
        {
        cout << "The actual retail price is ";
        prizes[2].showARP();
        if (prizes[2].getPrice() <= displayPrices[2]){
        cout << endl << "That's correct! On to the car...";
        cout << endl;
        prizesWon += 1;
        }
    else
        lost = true;
        } /// end else

    if (!lost)
    {
        cout << endl << "4. ";
        prizeCar.showModel();
        cout << endl << "Comes with: ";
        prizeCar.showOptions();
        cout << endl << "$" << displayPrices[3];
        while ( (choice4 != 'M') && (choice4 != 'L') && (choice4 != 'm') && (choice4 != 'l') ){
        cout << endl << "This price is wrong. Is the correct price more (M) or less (L)?: ";
        cin >> choice4;
        }
        if ((choice4 == 'M') || (choice4 == 'm'))
        {
        cout << "The actual retail price is ";
        prizeCar.showARP();
        if (prizeCar.getPrice() >= displayPrices[3])
            won = true;
        else
            lost = true;
        }
        else
        {
        cout << "The actual retail price is ";
        prizeCar.showARP();
        if (prizeCar.getPrice() <= displayPrices[3])
            won = true;
        else
            lost = true;
        }

    } /// end if

    } /// end if

    } /// end if

    cout << endl;

    if (lost){
        if (prizesWon == 0)
            cout << endl << "Sorry, you lose.";
        else if (prizesWon == 1)
            cout << endl << "Sorry, you lose. At least you won 1 prize.";
        else
            cout << endl << "Sorry, you lose. At least you won " << prizesWon << " prizes.";
    }
    else if (won)
        cout << endl << "Congratulations, you win!";

    /*
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();
    */

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// On the Nose
void playOnTheNose()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "ON THE NOSE" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int price2 = carPrice;
    int price3 = carPrice;
    int price4 = carPrice;

    int loBound = roundDown(carPrice);
    int hiBound = loBound + 5000;

    while (price2 == carPrice)
        price2 = rand() % (hiBound - loBound) + loBound;

    while ((price3 == carPrice) || (price3 == price2))
        price3 = rand() % (hiBound - loBound) + loBound;

    while ((price4 == carPrice) || (price4 == price2) || (price4 == price3) )
        price4 = rand() % (hiBound - loBound) + loBound;

    int allPrices[4] = {carPrice, price2, price3, price4};
    random_shuffle(&allPrices[0], &allPrices[4]);

    int differences[4];
    for (int d = 0; d < 4; d++){
        differences[d] = abs(carPrice-allPrices[d]);
    }

//    for (int e = 0; e < 4; e++){
//        cout << endl << "price #" << e+1 << "= $" << allPrices[e] << ", difference = " << differences[e];
//    }

    sortDifferences(differences);

    /// Sport 0: Baseball  Sport 1. Basketball
    /// Sport 2. Football  Sport 3. Darts
    /// Sport 4. Tennis
    int sport = rand() % 5;

    cout << endl;

    for (int f = 0; f < 4; f++)
        cout << endl << f+1 << ". $" << allPrices[f];

    int chances;

    int choice = 0;

    while ( (choice < 1) || (choice > 4) ){
    cout << endl << "What is the price of the car?: ";
    cin >> choice;
    }

    if (allPrices[choice-1] == carPrice){
        cout << endl << "You got the price of the car on the nose!";
        chances = 4;
    }
    else if ( abs(carPrice - allPrices[choice-1]) == differences[1] ){
        cout << endl << "The actual retail price of the car was $" << carPrice << ".";
        chances = 3;
    }
    else if ( abs(carPrice - allPrices[choice-1]) == differences[2] ){
        cout << endl << "The actual retail price of the car was $" << carPrice << ".";
        chances = 2;
    }
    else{
        cout << endl << "The actual retail price of the car was $" << carPrice << ".";
        chances = 1;
    }

    if (chances == 1)
        cout << endl << "You get 1 chance to ";
    else
        cout << endl << "You get " << chances << " chances to ";
    if (sport == 0)
        cout << "pitch the baseball into the target.";
    else if (sport == 1)
        cout << "throw the basketball into the hoop.";
    else if (sport == 2)
        cout << "throw the football into the target.";
    else if (sport == 3)
        cout << "pop the balloon with the dart.";
    else
        cout << "throw the tennis ball into the target.";

    bool won = false;

    while ( (chances > 0) && (!won) ){
        int result = rand() % 2;
        cout << endl << endl << "Chances left: " << chances;
        cout << endl << "Press any key to make a shot.";
        cout << endl;
        system("pause");
        if (result == 1){
            cout << endl << "Yes, you made the shot!";
            won = true;
        }
        else{
            cout << endl << "Sorry, you didn't make this shot.";
            chances -= 1;
        }
    }

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// One Away
void playOneAway(bool mds)
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);

    if (!mds){
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    } /// not the Million Dollar Game

    else{
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    }

    cout << "ONE AWAY" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    if (mds){
    cout << endl;
    cout << endl << "This is the Million Dollar Game!";
    cout << endl << "Get the car's price right on the first try,";
    cout << endl << "and you win $1,000,000!";
    cout << endl << endl;
    }

    int carPrice = prizeCar.getPrice();
    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    /// If setting[x] = 0, the display number is one LESS than the real number.
    /// If setting[x] = 1, the display number is one MORE than the real number.
    int settings[5];

    /// The if-statements below prevent the first number in the wrong price from displaying as a zero, as well as
    /// preventing wrong digits from showing up as negative one or ten.
    if (digits[0] == 1)
        settings[0] = 1;
    else if (digits[0] == 2)
        settings[0] = 1;
    else if (digits[0] == 9)
        settings[0] = 0;
    else if (digits[0] == 8)
        settings[0] = 0;
    else
        settings[0] = rand() % 2;

    if (digits[1] == 0)
        settings[1] = 1;
    else if (digits[1] == 9)
        settings[1] = 0;
    else if (digits[1] == 8)
        settings[1] = 0;
    else if (digits[1] == 1)
        settings[1] = 1;
    else
        settings[1] = rand() % 2;

    if (digits[2] == 0)
        settings[2] = 1;
    else if (digits[2] == 9)
        settings[2] = 0;
    else if (digits[2] == 8)
        settings[2] = 0;
    else if (digits[2] == 1)
        settings[2] = 1;
    else
        settings[2] = rand() % 2;

    if (digits[3] == 0)
        settings[3] = 1;
    else if (digits[3] == 9)
        settings[3] = 0;
    else if (digits[3] == 8)
        settings[3] = 0;
    else if (digits[3] == 1)
        settings[3] = 1;
    else
        settings[3] = rand() % 2;

    if (digits[4] == 0)
        settings[4] = 1;
    else if (digits[4] == 9)
        settings[4] = 0;
    else if (digits[4] == 8)
        settings[4] = 0;
    else if (digits[4] == 1)
        settings[4] = 1;
    else
        settings[4] = rand() % 2;

    int display[5];

    for (int b = 0; b < 5; b++){
    if (settings[b] == 0)
        display[b] = digits[b] - 1;
    else
        display[b] = digits[b] + 1;
    }

    int firstGuess[5];

    cout << endl << "$" << display[0] << display[1] << display[2] << display[3] << display[4];
    cout << endl << " #    ";

    char choice1 = 'A';
    char choice2 = 'A';
    char choice3 = 'A';
    char choice4 = 'A';
    char choice5 = 'A';

    bool lost = false;

    /// Digit #1
    while ( (choice1 != 'H') && (choice1 != 'L') &&  (choice1 != 'h') && (choice1 != 'l') ){
    cout << endl << "Should the " << display[0] << " be one digit higher (H) or lower (L)?: ";
    cin >> choice1;
    }
    if ((choice1 == 'H') || (choice1 == 'h'))
        firstGuess[0] = display[0] + 1;
    else
        firstGuess[0] = display[0] - 1;

    cout << endl << "$" << firstGuess[0] << display[1] << display[2] << display[3] << display[4];
    cout << endl << " " << static_cast<char>(toupper(choice1)) << "#";

    /// Digit #2
    while ( (choice2 != 'H') && (choice2 != 'L') &&  (choice2 != 'h') && (choice2 != 'l') ){
    cout << endl << "Should the " << display[1] << " be one digit higher (H) or lower (L)?: ";
    cin >> choice2;
    }
    if ((choice2 == 'H') || (choice2 == 'h'))
        firstGuess[1] = display[1] + 1;
    else
        firstGuess[1] = display[1] - 1;

    cout << endl << "$" << firstGuess[0] << firstGuess[1] << display[2] << display[3] << display[4];
    cout << endl << " " << static_cast<char>(toupper(choice1)) << static_cast<char>(toupper(choice2)) << "#";

    /// Digit #3
    while ( (choice3 != 'H') && (choice3 != 'L') &&  (choice3 != 'h') && (choice3 != 'l') ){
    cout << endl << "Should the " << display[2] << " be one digit higher (H) or lower (L)?: ";
    cin >> choice3;
    }
    if ((choice3 == 'H') || (choice3 == 'h'))
        firstGuess[2] = display[2] + 1;
    else
        firstGuess[2] = display[2] - 1;

    cout << endl << "$" << firstGuess[0] << firstGuess[1] << firstGuess[2] << display[3] << display[4];
    cout << endl << " " << static_cast<char>(toupper(choice1)) << static_cast<char>(toupper(choice2)) << static_cast<char>(toupper(choice3)) << "#";

    /// Digit #4
    while ( (choice4 != 'H') && (choice4 != 'L') &&  (choice4 != 'h') && (choice4 != 'l') ){
    cout << endl << "Should the " << display[3] << " be one digit higher (H) or lower (L)?: ";
    cin >> choice4;
    }
    if ((choice4 == 'H') || (choice4 == 'h'))
        firstGuess[3] = display[3] + 1;
    else
        firstGuess[3] = display[3] - 1;

    cout << endl << "$" << firstGuess[0] << firstGuess[1] << firstGuess[2] << firstGuess[3] << display[4];
    cout << endl << " " << static_cast<char>(toupper(choice1)) << static_cast<char>(toupper(choice2)) << static_cast<char>(toupper(choice3)) << static_cast<char>(toupper(choice4)) << "#";


    /// Digit #5
    while ( (choice5 != 'H') && (choice5 != 'L') &&  (choice5 != 'h') && (choice5 != 'l') ){
    cout << endl << "Should the " << display[4] << " be one digit higher (H) or lower (L)?: ";
    cin >> choice5;
    }
    if ((choice5 == 'H') || (choice5 == 'h'))
        firstGuess[4] = display[4] + 1;
    else
        firstGuess[4] = display[4] - 1;

    cout << endl << "$" << firstGuess[0] << firstGuess[1] << firstGuess[2] << firstGuess[3] << firstGuess[4];
    cout << endl << " " << static_cast<char>(toupper(choice1)) << static_cast<char>(toupper(choice2)) << static_cast<char>(toupper(choice3)) << static_cast<char>(toupper(choice4)) << static_cast<char>(toupper(choice5));

    cout << endl << "Let's see how many you have right.";
    int hasRight = 0;

    for (int c = 0; c < 5; c++)
    {
        if (digits[c] == firstGuess[c])
            hasRight++;
    }

    if (hasRight == 0)
    {
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*BUZZ*";
        cout << endl << "Sorry, you lose. The price of the car was ";
        prizeCar.showARP();
        cout << ".";
    }
    else if (hasRight == 5)
    {
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 2 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 3 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 4 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have all 5 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        if (mds)
            cout << endl << "CONGRATULATIONS, YOU WIN THE CAR AND $1,000,000!";
        else
            cout << endl << "Congratulations, you win!";
    }
    else
    {
        if (hasRight == 1){
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 2 numbers right?" << endl;
        system("pause");
        cout << endl << "...";
        }
        else if (hasRight == 2){
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 2 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 3 numbers right?" << endl;
        system("pause");
        cout << endl << "...";
        }
        else if (hasRight == 3){
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 2 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 3 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 4 numbers right?" << endl;
        system("pause");
        cout << endl << "...";
        }
        else
        {
        cout << endl << "Oh, mighty sound effects lady, do I have 1 number right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 2 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 3 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have 4 numbers right?" << endl;
        system("pause");
        cout << endl << "*HONK*";
        cout << endl << "Oh, mighty sound effects lady, do I have all 5 numbers right?" << endl;
        system("pause");
        cout << endl << "...";
        }

        cout << endl << "$" << firstGuess[0] << firstGuess[1] << firstGuess[2] << firstGuess[3] << firstGuess[4];
        cout << endl << " " << static_cast<char>(toupper(choice1)) << static_cast<char>(toupper(choice2)) << static_cast<char>(toupper(choice3)) << static_cast<char>(toupper(choice4)) << static_cast<char>(toupper(choice5));

        cout << endl;
        int secondGuess = 0;
        if (hasRight == 4)
            cout << endl << "You need to change " << 5-hasRight << " number.";
        else
            cout << endl << "You need to change " << 5-hasRight <<  " numbers.";

        while ( (secondGuess < 10000) || (secondGuess > 99999) ){
            cout << endl << "Enter your guess for the price of the car: $";
            cin >> secondGuess;
        }

        int secondDigits[5];
        secondDigits[0] = secondGuess / 10000 % 10;
        secondDigits[1] = secondGuess / 1000 % 10;
        secondDigits[2] = secondGuess / 100 % 10;
        secondDigits[3] = secondGuess / 10 % 10;
        secondDigits[4] = secondGuess % 10;

        cout << endl << "Now, let's see if you won." << endl;
        system("pause");

        cout << endl << "$" << secondDigits[0] << secondDigits[1] << secondDigits[2] << secondDigits[3] << secondDigits[4];
        cout << endl << "$" << digits[0] << "****";
        if (secondDigits[0] != digits[0]){
            cout << endl << "Sorry, you lose.";
            lost = true;
            }
        else
        {
            cout << endl;
            system("pause");
            cout << endl << "$" << secondDigits[0] << secondDigits[1] << secondDigits[2] << secondDigits[3] << secondDigits[4];
            cout << endl << "$" << digits[0] << digits[1] << "***";
            if (secondDigits[1] != digits[1]){
                cout << endl << "Sorry, you lose.";
                lost = true;
                }
            else
            {
            cout << endl;
            system("pause");
            cout << endl << "$" << secondDigits[0] << secondDigits[1] << secondDigits[2] << secondDigits[3] << secondDigits[4];
            cout << endl << "$" << digits[0] << digits[1] << digits[2] << "**";
            if (secondDigits[2] != digits[2]){
                cout << endl << "Sorry, you lose.";
                lost = true;
                }
            else
            {
            cout << endl;
            system("pause");
            cout << endl << "$" << secondDigits[0] << secondDigits[1] << secondDigits[2] << secondDigits[3] << secondDigits[4];
            cout << endl << "$" << digits[0] << digits[1] << digits[2] << digits[3] << "*";
            if (secondDigits[3] != digits[3]){
                cout << endl << "Sorry, you lose.";
                lost = true;
                }
            else{
            cout << endl;
            system("pause");
            cout << endl << "$" << secondDigits[0] << secondDigits[1] << secondDigits[2] << secondDigits[3] << secondDigits[4];
            cout << endl << "$" << digits[0] << digits[1] << digits[2] << digits[3] << digits[4];
            if (secondDigits[4] != digits[4]){
                cout << endl << "Sorry, you lose.";
                lost = true;
                }
            else
                cout << endl << "Congratulations, you win!";

            } // end else for if player guessed fourth digit correctly


            } // end else for if player guessed third digit correctly


            } // end else for if player guessed second digit correctly

        } // end else for if player guessed first digit correctly

    } /// end else statement for if player get a second chance.

    if (lost)
        cout << endl << "The actual retail price of the car was $" << prizeCar.getPrice() << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Pathfinder
void playPathfinder()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    int j = 0;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ( (inFile >> s_Description >> s_ShortName >> s_Price) )
        {
            pptr->setDescription(s_Description);
            pptr->setShortName(s_ShortName);
            pptr->setPrice(s_Price);
            gameItems.push_back(*pptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "PATHFINDER" << endl;

    /// Pick a car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    /// Generate the three items
    int randomizationField[j];
    for (int f = 0; f < j; f++)
    {
        randomizationField[f] = f;
    }
    random_shuffle(&randomizationField[0], &randomizationField[j]);

    //cout << endl << "rands: " << randomizationField[0] << ", " << randomizationField[1] << ", " << randomizationField[2];

    small items[3];
    bool usedSmall[3];
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        usedSmall[itemCount] = false;
        gameItemIt = gameItems.begin();
        for (int g = 0; g < randomizationField[itemCount]; g++)
            gameItemIt++;
        items[itemCount].setDescription(gameItemIt->getDescription());
        items[itemCount].setShortName(gameItemIt->getShortName());
        items[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Set the pricing questions for the two smaller prices.
    int placement1 = rand() % 2;
    int placement2 = rand() % 2;
    int placement3 = rand() % 2;

    int temphold;
    int item1Prices[2];
    int item2Prices[2];
    int item3Prices[2];

    /// Set item 1's price options
    temphold = items[0].getPrice();
    while (temphold == items[0].getPrice())
        temphold = rand()%(100-15 + 1) + 15;

    if (placement1 == 0){
        item1Prices[0] = items[0].getPrice();
        item1Prices[1] = temphold;
    }
    else{
        item1Prices[0] = temphold;
        item1Prices[1] = items[0].getPrice();
    }

    /// Set item 2's price options
    temphold = items[1].getPrice();
    while (temphold == items[1].getPrice())
        temphold = rand()%(100-15 + 1) + 15;

    if (placement2 == 0){
        item2Prices[0] = items[1].getPrice();
        item2Prices[1] = temphold;
    }
    else{
        item2Prices[0] = temphold;
        item2Prices[1] = items[1].getPrice();
    }

    /// Set item 3's price options
    temphold = items[2].getPrice();
    while (temphold == items[2].getPrice())
        temphold = rand()%(100-15 + 1) + 15;

    if (placement3 == 0){
        item3Prices[0] = items[2].getPrice();
        item3Prices[1] = temphold;
    }
    else{
        item3Prices[0] = temphold;
        item3Prices[1] = items[2].getPrice();
    }

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    /// Initialize the grid.
    int grid[5][5];

    bool hasPrice[5][5];

    /// Fill the grid with dummy values.
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            grid[x][y] = 10;
            hasPrice[x][y] = false;
        }
    }

    grid[2][2] = digits[0];
    hasPrice[2][2] = true;

    tile dig2;
    tile dig3;
    tile dig4;
    tile dig5;

    int digit2Pos = rand() % 4;
    if (digit2Pos == 0) /// digit 2 is ABOVE
    {
        grid[1][2] = digits[1];
        hasPrice[1][2] = true;
        dig2.a = 1;
        dig2.b = 2;
    }
    else if (digit2Pos == 1) /// digit 2 is LEFT
    {
        grid[2][1] = digits[1];
        hasPrice[2][1] = true;
        dig2.a = 2;
        dig2.b = 1;
    }
    else if (digit2Pos == 2) /// digit 2 is RIGHT
    {
        grid[2][3] = digits[1];
        hasPrice[2][3] = true;
        dig2.a = 2;
        dig2.b = 3;
    }

    else /// digit 2 is BELOW
    {
        grid[3][2] = digits[1];
        hasPrice[3][2] = true;
        dig2.a = 3;
        dig2.b = 2;
    }


    /// When going from digit 2 to digit 3, you need to make sure you avoid
    /// going back to digit 1.
    int digit3Pos = rand() % 3;

    if (digit2Pos == 0) /// digit 2 is at [1][2]
    {
        if (digit3Pos == 0) /// digit 3 is ABOVE
        {
        grid[0][2] = digits[2];
        hasPrice[0][2] = true;
        dig3.a = 0;
        dig3.b = 2;
        }
        else if (digit3Pos == 1) /// digit 3 is LEFT
        {
        grid[1][1] = digits[2];
        hasPrice[1][1] = true;
        dig3.a = 1;
        dig3.b = 1;
        }

        else /// digit 3 is RIGHT
        {
        grid[1][3] = digits[2];
        hasPrice[1][3] = true;
        dig3.a = 1;
        dig3.b = 3;
        }

    }

    else if (digit2Pos == 1) /// digit 2 is at [2][1]
    {
        if (digit3Pos == 0) /// digit 3 is ABOVE
        {
        grid[1][1] = digits[2];
        hasPrice[1][1] = true;
        dig3.a = 1;
        dig3.b = 1;
        }
        else if (digit3Pos == 1) /// digit 3 is LEFT
        {
        grid[2][0] = digits[2];
        hasPrice[2][0] = true;
        dig3.a = 2;
        dig3.b = 0;
        }
        else /// digit 3 is BELOW
        {
        grid[3][1] = digits[2];
        hasPrice[3][1] = true;
        dig3.a = 3;
        dig3.b = 1;
        }
    }

    else if (digit2Pos == 2) /// digit 2 is at [2][3]
    {
        if (digit3Pos == 0) /// digit 3 is ABOVE
        {
        grid[1][3] = digits[2];
        hasPrice[1][3] = true;
        dig3.a = 1;
        dig3.b = 3;
        }

        else if (digit3Pos == 1) /// digit 3 is RIGHT
        {
        grid[2][4] = digits[2];
        hasPrice[2][4] = true;
        dig3.a = 2;
        dig3.b = 4;
        }

        else /// digit 3 is BELOW
        {
        grid[3][3] = digits[2];
        hasPrice[3][3] = true;
        dig3.a = 3;
        dig3.b = 3;
        }
    }

    else /// digit 2 is at [3][2]
    {
        if (digit3Pos == 0) /// digit 3 is LEFT
        {
        grid[3][1] = digits[2];
        hasPrice[3][1] = true;
        dig3.a = 3;
        dig3.b = 1;
        }

        else if (digit3Pos == 1) /// digit 3 is RIGHT
        {
        grid[3][3] = digits[2];
        hasPrice[3][3] = true;
        dig3.a = 3;
        dig3.b = 3;
        }

        else /// digit 3 is BELOW
        {
        grid[4][2] = digits[2];
        hasPrice[4][2] = true;
        dig3.a = 4;
        dig3.b = 2;
        }
    }

    /// Digits #4 and 5. Hold your breath... this one might take a while.
    int digit4Pos;
    int digit5Pos;

    /// 2. ABOVE, 3. ABOVE
    if ( ((dig2.a == 1) && (dig2.b == 2)) && ((dig3.a == 0) && (dig3.b == 2)) ){
        digit4Pos = rand() % 2;
        if (digit4Pos == 0) /// digit 4 is to the LEFT
        {
        grid[0][1] = digits[3];
        hasPrice[0][1] = true;
        dig4.a = 0;
        dig4.b = 1;

        digit5Pos = rand() % 2;
        if (digit5Pos == 0) /// digit 5 is to the LEFT
        {
        grid[0][0] = digits[4];
        hasPrice[0][0] = true;
        dig5.a = 0;
        dig5.b = 0;
        }
        else /// digit 5 is BELOW
        {
        grid[1][1] = digits[4];
        hasPrice[1][1] = true;
        dig5.a = 1;
        dig5.b = 1;
        }

        } // end if digit 4 is [0][1]

    else /// digit 4 is to the RIGHT
        {
        grid[0][3] = digits[3];
        hasPrice[0][3] = true;
        dig4.a = 0;
        dig4.b = 3;

        digit5Pos = rand() % 2;
        if (digit5Pos == 0) /// digit 5 is to the RIGHT
        {
        grid[0][4] = digits[4];
        hasPrice[0][4] = true;
        dig5.a = 0;
        dig5.b = 4;
        }
        else /// digit 5 is BELOW
        {
        grid[1][3] = digits[4];
        hasPrice[1][3] = true;
        dig5.a = 1;
        dig5.b = 3;
        }

        } // end if digit 4 is [0][3]
    } // end for 2. ABOVE, 3. ABOVE

    /// 2. ABOVE, 3. LEFT
    else if ( ((dig2.a == 1) && (dig2.b == 2)) && ((dig3.a == 1) && (dig3.b == 1)) ){
        digit4Pos = rand() % 3;

        /// Digit 4 is at (0, 1)
        if (digit4Pos == 0){
        grid[0][1] = digits[3];
        hasPrice[0][1] = true;
        dig4.a = 0;
        dig4.b = 1;

        digit5Pos = rand() % 2;

        if (digit5Pos == 0) /// LEFT - [0][0]
        {
            grid[0][0] = digits[4];
            hasPrice[0][0] = true;
            dig5.a = 0;
            dig5.b = 0;
        }
        else /// RIGHT 0 [0][2]
        {
            grid[0][2] = digits[4];
            hasPrice[0][2] = true;
            dig5.a = 0;
            dig5.b = 2;
        }
        } // end if digit 4 is [0][1]

        /// Digit 4 is at (1, 0)
        else if (digit4Pos == 1){
        grid[1][0] = digits[3];
        hasPrice[1][0] = true;
        dig4.a = 1;
        dig4.b = 0;

        digit5Pos = rand() % 2;

        if (digit5Pos == 0) /// ABOVE - [0][0]
        {
            grid[0][0] = digits[4];
            hasPrice[0][0] = true;
            dig5.a = 0;
            dig5.b = 0;
        }
        else /// BELOW - [2][0]
        {
            grid[2][0] = digits[4];
            hasPrice[2][0] = true;
            dig5.a = 2;
            dig5.b = 0;
        }
        } // end if digit 4 is [1][0]

        /// Digit 4 is at (2, 1)
        else{
        grid[2][1] = digits[3];
        hasPrice[2][1] = true;
        dig4.a = 2;
        dig4.b = 1;

        digit5Pos = rand() % 2;

        if (digit5Pos == 0) /// LEFT - [2][0]
        {
        grid[2][0] = digits[4];
        hasPrice[2][0] = true;
        dig5.a = 2;
        dig5.b = 0;
        }
        else /// BELOW - [3][1]
        {
        grid[3][1] = digits[4];
        hasPrice[3][1] = true;
        dig5.a = 3;
        dig5.b = 1;
        }
        } // end if digit 4 is [2][1]

    } // end for 2. ABOVE, 3. LEFT

    /// 2. ABOVE, 3. RIGHT
    else if ( ((dig2.a == 1) && (dig2.b == 2)) && ((dig3.a == 1) && (dig3.b == 3)) ){
        digit4Pos = rand() % 3;

        /// Digit 4 is at (0, 3) - ABOVE
        if (digit4Pos == 0){
        grid[0][3] = digits[3];
        hasPrice[0][3] = true;
        dig4.a = 0;
        dig4.b = 3;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (0, 2) - LEFT
        if (digit5Pos == 0){
        grid[0][2] = digits[4];
        hasPrice[0][2] = true;
        dig5.a = 0;
        dig5.b = 2;
        }
        /// Digit 5 is at (0, 4) - RIGHT
        else{
        grid[0][4] = digits[4];
        hasPrice[0][4] = true;
        dig5.a = 0;
        dig5.b = 4;
        }
        } // end if digit 4 is at [0][3]


        /// Digit 4 is at (1, 4) - RIGHT
        else if (digit4Pos == 1){
        grid[1][4] = digits[3];
        hasPrice[1][4] = true;
        dig4.a = 1;
        dig4.b = 4;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (0, 4) - ABOVE
        if (digit5Pos == 0){
        grid[0][4] = digits[4];
        hasPrice[0][4] = true;
        dig5.a = 0;
        dig5.b = 4;
        }
        /// Digit 5 is at (2, 4) - BELOW
        else{
        grid[2][4] = digits[4];
        hasPrice[2][4] = true;
        dig5.a = 2;
        dig5.b = 4;
        }
        } // end if digit 4 is at [1][4]


        /// Digit 4 is at (2, 3) - RIGHT
        else
        {
        grid[2][3] = digits[3];
        hasPrice[2][3] = true;
        dig4.a = 2;
        dig4.b = 3;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (2, 4) - RIGHT
        if (digit5Pos == 0)
        {
        grid[2][4] = digits[4];
        hasPrice[2][4] = true;
        dig5.a = 2;
        dig5.b = 4;
        }
        else
        {
        grid[3][3] = digits[4];
        hasPrice[3][3] = true;
        dig5.a = 3;
        dig5.b = 3;
        }

        } // end if digit 4 is at [2][3]
    } // end for 2. ABOVE, 3. RIGHT

    /// 2. LEFT, 3. ABOVE
    else if ( ((dig2.a == 2) && (dig2.b == 1)) && ((dig3.a == 1) && (dig3.b == 1)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is at (0, 1) - ABOVE
    if (digit4Pos == 0)
    {
        grid[0][1] = digits[3];
        hasPrice[0][1] = true;
        dig4.a = 0;
        dig4.b = 1;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (0, 0) - LEFT
        if (digit5Pos == 0){
        grid[0][0] = digits[4];
        hasPrice[0][0] = true;
        dig5.a = 0;
        dig5.b = 0;
        }
        /// Digit 5 is at (0, 2) - RIGHT
        else{
        grid[0][2] = digits[4];
        hasPrice[0][2] = true;
        dig5.a = 0;
        dig5.b = 2;
        }
    } // end if digit 4 is at [0][1]

    /// Digit 4 is at (1, 0) - LEFT
    else if (digit4Pos == 1)
    {
        grid[1][0] = digits[3];
        hasPrice[1][0] = true;
        dig4.a = 1;
        dig4.b = 0;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (0, 0) - ABOVE
        if (digit5Pos == 0){
        grid[0][0] = digits[4];
        hasPrice[0][0] = true;
        dig5.a = 0;
        dig5.b = 0;
        }

        /// Digit 5 is at (2, 0) - BELOW
        else{
        grid[2][0] = digits[4];
        hasPrice[2][0] = true;
        dig5.a = 2;
        dig5.b = 0;
        }

    } // end if digit 4 is at [1][0]

    /// Digit 4 is at (1, 2) - RIGHT
    else
    {
        grid[1][2] = digits[3];
        hasPrice[1][2] = true;
        dig4.a = 1;
        dig4.b = 2;

        digit5Pos = rand() % 2;

        /// Digit 5 is at (0, 2) - ABOVE
        if (digit5Pos == 0){
        grid[0][2] = digits[4];
        hasPrice[0][2] = true;
        dig5.a = 0;
        dig5.b = 2;
        }

        /// Digit 5 is at (1, 3) - RIGHT
        else{
        grid[1][3] = digits[4];
        hasPrice[1][3] = true;
        dig5.a = 1;
        dig5.b = 3;
        }
    } // end if digit 4 is at [1][2]

    } // end for 2. LEFT, 3. ABOVE

    /// 2. LEFT, 3. LEFT
    else if ( ((dig2.a == 2) && (dig2.b == 1)) && ((dig3.a == 2) && (dig3.b == 0)) ){
    digit4Pos = rand() % 2;

    /// Digit 4 is (1, 0) - ABOVE
    if (digit4Pos == 0){
    grid[1][0] = digits[3];
    hasPrice[1][0] = true;
    dig4.a = 1;
    dig4.b = 0;

    digit5Pos = rand() % 2;

    /// Digit 5 is (0, 0) - ABOVE
    if (digit5Pos == 0){
    grid[0][0] = digits[4];
    hasPrice[0][0] = true;
    dig5.a = 0;
    dig5.b = 0;
    }
    /// Digit 5 is (1, 1) - RIGHT
    else{
    grid[1][1] = digits[4];
    hasPrice[1][1] = true;
    dig5.a = 1;
    dig5.b = 1;
    }
    } // end if digit 4 is at [1][0]


    /// Digit 4 is (3, 0) - BELOW
    else{
    grid[3][0] = digits[3];
    hasPrice[3][0] = true;
    dig4.a = 3;
    dig4.b = 0;

    digit5Pos = rand() % 2;

    /// Digit 5 is (3, 1) - RIGHT
    if (digit5Pos == 0){
    grid[3][1] = digits[4];
    hasPrice[3][1] = true;
    dig5.a = 3;
    dig5.b = 1;
    }
    /// Digit 5 is (4, 0) - BELOW
    else{
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }

    } // end if digit 4 is at [3][0]
    } // end for 2. LEFT, 3. LEFT

    /// 2. LEFT, 3. BELOW
    else if ( ((dig2.a == 2) && (dig2.b == 1)) && ((dig3.a == 3) && (dig3.b == 1)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is (3, 0) - LEFT
    if (digit4Pos == 0){
    grid[3][0] = digits[3];
    hasPrice[3][0] = true;
    dig4.a = 3;
    dig4.b = 0;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (2, 0) - ABOVE
    if (digit5Pos == 0){
    grid[2][0] = digits[4];
    hasPrice[2][0] = true;
    dig5.a = 2;
    dig5.b = 0;
    }

    /// Digit 5 is at (4, 0) - BELOW
    else{
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }
    } // end if digit 4 is at [3][0]

    /// Digit 4 is (4, 1) - BELOW
    else if (digit4Pos == 1){
    grid[4][1] = digits[3];
    hasPrice[4][1] = true;
    dig4.a = 4;
    dig4.b = 1;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (4, 0) - LEFT
    if (digit5Pos == 0){
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }

    /// Digit 5 is at (4, 2) - RIGHT
    else{
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    } // end if digit 4 is at [4][1]

    /// Digit 4 is (3, 2) - RIGHT
    else{
    grid[3][2] = digits[3];
    hasPrice[3][2] = true;
    dig4.a = 3;
    dig4.b = 2;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (3, 3) - RIGHT
    if (digit5Pos == 0){
    grid[3][3] = digits[4];
    hasPrice[3][3] = true;
    dig5.a = 3;
    dig5.b = 3;
    }

    /// Digit 5 is at (4, 2) - BELOW
    else{
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    } // end if digit 4 is at [3][2]

    } // end for 2. LEFT, 3. BELOW

    /// 2. RIGHT, 3. ABOVE
    else if ( ((dig2.a == 2) && (dig2.b == 3)) && ((dig3.a == 1) && (dig3.b == 3)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is at (1, 2) - LEFT
    if (digit4Pos == 0){
    grid[1][2] = digits[3];
    hasPrice[1][2] = true;
    dig4.a = 1;
    dig4.b = 2;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (0, 2) - ABOVE
    if (digit5Pos == 0){
    grid[0][2] = digits[4];
    hasPrice[0][2] = true;
    dig5.a = 0;
    dig5.b = 2;
    }

    /// Digit 5 is at (1, 1) - LEFT
    else{
    grid[1][1] = digits[4];
    hasPrice[1][1] = true;
    dig5.a = 1;
    dig5.b = 1;
    }

    } // end if digit 4 is at [1][2]

    /// Digit 4 is at (0, 3) - ABOVE
    else if (digit4Pos == 1){
    grid[0][3] = digits[3];
    hasPrice[0][3] = true;
    dig4.a = 0;
    dig4.b = 3;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (0, 2) - LEFT
    if (digit5Pos == 0){
    grid[0][2] = digits[4];
    hasPrice[0][2] = true;
    dig4.a = 0;
    dig4.b = 2;
    }

    /// Digit 5 is at (0, 4) - RIGHT
    else{
    grid[0][4] = digits[4];
    hasPrice[0][4] = true;
    dig4.a = 0;
    dig4.b = 4;
    }
    } // end if digit 4 is at [0][3]

    /// Digit 4 is at (1, 4) - RIGHT
    else{
    grid[1][4] = digits[3];
    hasPrice[1][4] = true;
    dig4.a = 1;
    dig4.b = 4;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (0, 4) - ABOVE
    if (digit5Pos == 0){
    grid[0][4] = digits[4];
    hasPrice[0][4] = true;
    dig5.a = 0;
    dig5.b = 4;
    }

    /// Digit 5 is at (2, 4) - BELOW
    else{
    grid[2][4] = digits[4];
    hasPrice[2][4] = true;
    dig5.a = 2;
    dig5.b = 4;
    }
    } // end if digit 4 is at [1][4]

    } // end for 2. RIGHT, 3. ABOVE

    /// 2. RIGHT, 3. RIGHT
    else if ( ((dig2.a == 2) && (dig2.b == 3)) && ((dig3.a == 2) && (dig3.b == 4)) ){
    digit4Pos = rand() % 2;

    /// Digit 4 is at (1, 4) - ABOVE
    if (digit4Pos == 0){
    grid[1][4] = digits[3];
    hasPrice[1][4] = true;
    dig4.a = 1;
    dig4.b = 4;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (0, 4) - ABOVE
    if (digit5Pos == 0){
    grid[0][4] = digits[4];
    hasPrice[0][4] = true;
    dig5.a = 0;
    dig5.b = 4;
    }

    /// Digit 5 is at (1, 3) - LEFT
    else{
    grid[1][3] = digits[4];
    hasPrice[1][3] = true;
    dig5.a = 1;
    dig5.b = 3;
    }

    } // end if digit 4 is at [1][4]

    /// Digit 4 is at (3, 4) - BELOW
    else{
    grid[3][4] = digits[3];
    hasPrice[3][4] = true;
    dig4.a = 3;
    dig4.b = 4;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (3, 3) - LEFT
    if (digit5Pos == 0){
    grid[3][3] = digits[4];
    hasPrice[3][3] = true;
    dig5.a = 3;
    dig5.b = 3;
    }

    /// Digit 5 is at (4, 4) - BELOW
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }

    } // end if digit 4 is at [3][4]

    } // end for 2. RIGHT, 3. RIGHT

    /// 2. RIGHT, 3. BELOW
    else if ( ((dig2.a == 2) && (dig2.b == 3)) && ((dig3.a == 3) && (dig3.b == 3)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is at (3, 2) - LEFT
    if (digit4Pos == 0){
    grid[3][2] = digits[3];
    hasPrice[3][2] = true;
    dig4.a = 3;
    dig4.b = 2;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (3, 1) - LEFT
    if (digit5Pos == 0){
    grid[3][1] = digits[4];
    hasPrice[3][1] = true;
    dig5.a = 3;
    dig5.b = 1;
    }

    /// Digit 5 is at (4, 2) - BELOW
    else{
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    } // end if digit 4 is at [3][2]

    /// Digit 4 is at (3, 4) - RIGHT
    else if (digit4Pos == 1){
    grid[3][4] = digits[3];
    hasPrice[3][4] = true;
    dig4.a = 3;
    dig4.b = 4;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (2, 4) - UP
    if (digit5Pos == 0){
    grid[2][4] = digits[4];
    hasPrice[2][4] = true;
    dig5.a = 2;
    dig5.b = 4;
    }

    /// Digit 5 is at (4, 4) - DOWN
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }

    } // end if digit 4 is at [3][4]

    /// Digit 4 is at (4, 3) - DOWN
    else{
    grid[4][3] = digits[3];
    hasPrice[4][3] = true;
    dig4.a = 4;
    dig4.b = 3;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (4, 2) - LEFT
    if (digit5Pos == 0){
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    /// Digit 5 is at (4, 4) - RIGHT
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }
    } // end if digit 4 is at [4][3]

    } // end for 2. RIGHT, 3. BELOW

    /// 2. BELOW, 3. LEFT
    else if ( ((dig2.a == 3) && (dig2.b == 2)) && ((dig3.a == 3) && (dig3.b == 1)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is at (2, 1) - ABOVE
    if (digit4Pos == 0){
    grid[2][1] = digits[3];
    hasPrice[2][1] = true;
    dig4.a = 2;
    dig4.b = 1;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (1, 1) - ABOVE
    if (digit5Pos == 0){
    grid[1][1] = digits[4];
    hasPrice[1][1] = true;
    dig5.a = 1;
    dig5.b = 1;
    }

    /// Digit 5 is at (2, 0) - LEFT
    else{
    grid[2][0] = digits[4];
    hasPrice[2][0] = true;
    dig5.a = 2;
    dig5.b = 0;
    }

    } // end if digit 4 is at [2][1]

    /// Digit 4 is at (3, 0) - LEFT
    else if (digit4Pos == 1){
    grid[3][0] = digits[3];
    hasPrice[3][0] = true;
    dig4.a = 3;
    dig4.b = 0;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (2, 0) - ABOVE
    if (digit5Pos == 0){
    grid[2][0] = digits[4];
    hasPrice[2][0] = true;
    dig5.a = 2;
    dig5.b = 0;
    }

    /// Digit 5 is at (4, 0) - BELOW
    else{
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }

    } // end if digit 4 is at [3][0]

    /// Digit 4 is at (4, 1) - BELOW
    else{
    grid[4][1] = digits[3];
    hasPrice[4][1] = true;
    dig4.a = 4;
    dig4.b = 1;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (4, 0) - LEFT
    if (digit5Pos == 0){
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }

    /// Digit 5 is at (4, 2) - RIGHT
    else{
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    } // end if digit 4 is at [4][1]

    } // end for 2. BELOW, 3. LEFT

    /// 2. BELOW, 3. RIGHT
    else if ( ((dig2.a == 3) && (dig2.b == 2)) && ((dig3.a == 3) && (dig3.b == 3)) ){
    digit4Pos = rand() % 3;

    /// Digit 4 is at (2, 3) - ABOVE
    if (digit4Pos == 0){
    grid[2][3] = digits[3];
    hasPrice[2][3] = true;
    dig4.a = 2;
    dig4.b = 3;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (1, 3) - ABOVE
    if (digit5Pos == 0){
    grid[1][3] = digits[4];
    hasPrice[1][3] = true;
    dig5.a = 1;
    dig5.b = 3;
    } // end if digit 5 is at [1][3]

    /// Digit 5 is at (2, 4) - RIGHT
    else{
    grid[2][4] = digits[4];
    hasPrice[2][4] = true;
    dig5.a = 2;
    dig5.b = 4;
    } // end if digit 5 is at [2][4]

    } // end if digit 4 is at [2][3]

    /// Digit 4 is at (3, 4) - RIGHT
    else if (digit4Pos == 1){
    grid[3][4] = digits[3];
    hasPrice[3][4] = true;
    dig4.a = 3;
    dig4.b = 4;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (2, 4) - ABOVE
    if (digit5Pos == 0){
    grid[2][4] = digits[4];
    hasPrice[2][4] = true;
    dig5.a = 2;
    dig5.b = 4;
    }

    /// Digit 5 is at (4, 4) - BELOW
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }

    } // end if digit 4 is at [3][4]

    /// Digit 4 is at (4, 3) - BELOW
    else{
    grid[4][3] = digits[3];
    hasPrice[4][3] = true;
    dig4.a = 4;
    dig4.b = 3;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (4, 2) - LEFT
    if (digit5Pos == 0){
    grid[4][2] = digits[4];
    hasPrice[4][2] = true;
    dig5.a = 4;
    dig5.b = 2;
    }

    /// Digit 5 is at (4, 4) - RIGHT
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }

    } // end if digit 4 is at [4][3]

    } // end for 2. BELOW, 3. RIGHT

    /// 2. BELOW, 3. BELOW (Digit 2 is at [3][2] and Digit 3 is at [4][2])
    else{
    digit4Pos = rand() % 2;

    /// Digit 4 is at (4, 1) - LEFT
    if (digit4Pos == 0){
    grid[4][1] = digits[3];
    hasPrice[4][1] = true;
    dig4.a = 4;
    dig4.b = 1;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (3, 1) - ABOVE
    if (digit5Pos == 0){
    grid[3][1] = digits[4];
    hasPrice[3][1] = true;
    dig5.a = 3;
    dig5.b = 1;
    }

    /// Digit 5 is at (4, 0) - LEFT
    else{
    grid[4][0] = digits[4];
    hasPrice[4][0] = true;
    dig5.a = 4;
    dig5.b = 0;
    }

    } // end if digit 4 is at [4][1]

    /// Digit 4 is at (4, 3) - RIGHT
    else{
    grid[4][3] = digits[3];
    hasPrice[4][3] = true;
    dig4.a = 4;
    dig4.b = 3;

    digit5Pos = rand() % 2;

    /// Digit 5 is at (3, 3) - ABOVE
    if (digit5Pos == 0){
    grid[3][3] = digits[4];
    hasPrice[3][3] = true;
    dig5.a = 3;
    dig5.b = 3;
    }

    /// Digit 5 is at (4, 4) - RIGHT
    else{
    grid[4][4] = digits[4];
    hasPrice[4][4] = true;
    dig5.a = 4;
    dig5.b = 4;
    }

    } // end if digit 4 is at [4][3]

    } // end final else statement
///--------------------------------------------------///
    /// Set possibilities for digit #2
    int neighbors1[3];

    /// This will be set to 0 if ABOVE, 1 if LEFT, 2 if BELOW, and 3 if RIGHT. It will be important for future digits.
    int setting;

    neighbors1[0] = digits[1];
    while (neighbors1[0] == digits[1])
        neighbors1[0] = rand() % 10;
    neighbors1[1] = digits[1];
    while ( (neighbors1[1] == digits[1]) || (neighbors1[1] == neighbors1[0]) )
        neighbors1[1] = rand() % 10;
    neighbors1[2] = digits[1];
    while ( (neighbors1[2] == digits[1]) || (neighbors1[2] == neighbors1[0]) || (neighbors1[2] == neighbors1[1]) )
        neighbors1[2] = rand() % 10;

    /// Second digit is ABOVE
    if ( (dig2.a == 1) && (dig2.b == 2) ){
        setting = 0;
        if (grid[2][1] == 10)
            grid[2][1] = neighbors1[0];
        if (grid[2][3] == 10)
            grid[2][3] = neighbors1[1];
        if (grid[3][2] == 10)
            grid[3][2] = neighbors1[2];
    }

    /// Second digit is to the LEFT
    else if ( (dig2.a == 2) && (dig2.b == 1) ){
        setting = 1;
        if (grid[1][2] == 10)
            grid[1][2] = neighbors1[0];
        if (grid[2][3] == 10)
            grid[2][3] = neighbors1[1];
        if (grid[3][2] == 10)
            grid[3][2] = neighbors1[2];
    }

    /// Second digit is BELOW
    else if ( (dig2.a == 3) && (dig2.b == 2) ){
        setting = 2;
        if (grid[1][2] == 10)
            grid[1][2] = neighbors1[0];
        if (grid[2][3] == 10)
            grid[2][3] = neighbors1[1];
        if (grid[2][1] == 10)
            grid[2][1] = neighbors1[2];
    }

    /// Second digit is to the RIGHT
    else if ( (dig2.a == 2) && (dig2.b == 3) ){
        setting = 3;
        if (grid[1][2] == 10)
            grid[1][2] = neighbors1[0];
        if (grid[3][2] == 10)
            grid[3][2] = neighbors1[1];
        if (grid[2][1] == 10)
            grid[2][1] = neighbors1[2];
    }
///--------------------------------------------------///
    /// Set possibilities for digit #3

    int neighbors2[2];
    neighbors2[0] = digits[2];
    while (neighbors2[0] == digits[2])
        neighbors2[0] = rand() % 10;
    neighbors2[1] = digits[2];
    while ( (neighbors2[1] == digits[2]) || (neighbors2[1] == neighbors2[0]) )
        neighbors2[1] = rand() % 10;

    /// Possibilities for the third digit are [0][2], [1][1], and [1][3]
    if (setting == 0){

    /// Digit 3 is at [0][2]
    if ( (dig3.a == 0) && (dig3.b == 2) ){
        if (!hasPrice[1][1])
            grid[1][1] = neighbors2[0];
        if (!hasPrice[1][3])
            grid[1][3] = neighbors2[1];
    }

    /// Digit 3 is at [1][1]
    else if ( (dig3.a == 1) && (dig3.b == 1) ){
        if (!hasPrice[0][2])
            grid[0][2] = neighbors2[0];
        if (!hasPrice[1][3])
            grid[1][3] = neighbors2[1];
    }

    /// Digit 3 is at [1][3]
    else if ( (dig3.a == 1) && (dig3.b == 3) ){
        if (!hasPrice[0][2])
            grid[0][2] = neighbors2[0];
        if (!hasPrice[1][1])
            grid[1][1] = neighbors2[1];
    }
    } // end if second digit was ABOVE

    /// Possibilities for the third digit are [1][1], [2][0], and [3][1]
    else if (setting == 1){

    /// Digit 3 is at [1][1]
    if ( (dig3.a == 1) && (dig3.b == 1) ){
        if (!hasPrice[2][0])
            grid[2][0] = neighbors2[0];
        if (!hasPrice[3][1])
            grid[3][1] = neighbors2[1];
    }

    /// Digit 3 is at [2][0]
    else if ( (dig3.a == 2) && (dig3.b == 0) ){
        if (!hasPrice[1][1])
            grid[1][1] = neighbors2[0];
        if (!hasPrice[3][1])
            grid[3][1] = neighbors2[1];
    }

    /// Digit 3 is at [3][1]
    else if ( (dig3.a == 3) && (dig3.b == 1) ){
        if (!hasPrice[1][1])
            grid[1][1] = neighbors2[0];
        if (!hasPrice[2][0])
            grid[2][0] = neighbors2[1];
    }
    } // end if second digit was to the LEFT

    /// Possibilities for the third digit are [3][1], [4][2], and [3][3]
    else if (setting == 2){

    /// Digit 3 is at [3][1]
    if ( (dig3.a == 3) && (dig3.b == 1) ){
    if (!hasPrice[4][2])
        grid[4][2] = neighbors2[0];
    if (!hasPrice[3][3])
        grid[3][3] = neighbors2[1];
    }

    /// Digit 3 is at [4][2]
    else if ( (dig3.a == 4) && (dig3.b == 2) ){
    if (!hasPrice[3][1])
        grid[3][1] = neighbors2[0];
    if (!hasPrice[3][3])
        grid[3][3] = neighbors2[1];
    }

    /// Digit 3 is at [3][3]
    else if ( (dig3.a == 3) && (dig3.b == 3) ){
    if (!hasPrice[3][1])
        grid[3][1] = neighbors2[0];
    if (!hasPrice[4][2])
        grid[4][2] = neighbors2[1];
    }

    } // end if second digit was BELOW

    /// Possibilities for the third digit are [1][3], [2][4], and [3][3]
    else{

    /// Digit 3 is at [1][3]
    if ( (dig3.a == 1) && (dig3.b == 3) ){
    if (!hasPrice[2][4])
        grid[2][4] = neighbors2[0];
    if (!hasPrice[3][3])
        grid[3][3] = neighbors2[1];
    }

    /// Digit 3 is at [2][4]
    else if ( (dig3.a == 2) && (dig3.b == 4) ){
    if (!hasPrice[1][3])
        grid[1][3] = neighbors2[0];
    if (!hasPrice[3][3])
        grid[3][3] = neighbors2[1];
    }

    /// Digit 3 is at [3][3]
    else if ( (dig3.a == 3) && (dig3.b == 3) ){
    if (!hasPrice[1][3])
        grid[1][3] = neighbors2[0];
    if (!hasPrice[2][4])
        grid[2][4] = neighbors2[1];
    }
    }

///--------------------------------------------------///

    cout << endl;
    //cout << endl << "car price: $" << carPrice;

    /// Fill the remainder of the board.
    int temp;
    for (int q = 0; q < 5; q++){
        for (int p = 0; p < 5; p++){
            temp = rand() % 10;
            if (grid[q][p] == 10){
                //while ( (temp == digits[0]) || (temp == digits[1]) || (temp == digits[2]) || (temp == digits[3]) || (temp == digits[4]) )
                //    temp = rand() % 10;
                grid[q][p] = temp;
                }
        }
    }


//    cout << endl << grid[0][0] << " " << grid[0][1] << " " << grid[0][2] << " " << grid[0][3] << " " << grid[0][4];
//    cout << endl << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << " " << grid[1][3] << " " << grid[1][4];
//    cout << endl << grid[2][0] << " " << grid[2][1] << " " << grid[2][2] << " " << grid[2][3] << " " << grid[2][4];
//    cout << endl << grid[3][0] << " " << grid[3][1] << " " << grid[3][2] << " " << grid[3][3] << " " << grid[3][4];
//    cout << endl << grid[4][0] << " " << grid[4][1] << " " << grid[4][2] << " " << grid[4][3] << " " << grid[4][4];

    int playerX = 2;
    int playerY = 2;

    bool lost = false;
    bool wrong = false;

    bool guessedDigit2 = false;

    while ( (!guessedDigit2) && (!lost) ){
    cout << endl << " $" << digits[0] << "****";
    cout << endl;
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            if ( (x == playerX) && (y == playerY) )
                cout << "@ ";
            else
                cout << grid[x][y] << " ";
        }
        cout << endl;
    }

    char choice = '!';
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') &&
            (choice != 'B') && (choice != 'b') && (choice != 'R') && (choice != 'r') ){
    cout << endl << "Is the next number";
    cout << endl << "the " << grid[1][2] << " above you (A)? ";
    cout << endl << "the " << grid[2][1] << " to your left (L)? ";
    cout << endl << "the " << grid[3][2] << " below you (B)? ";
    cout << endl << "the " << grid[2][3] << " to your right (R)?: ";
    cout << endl << "Enter which way the next digit is: ";
    cin >> choice;
    }
    if ( (choice == 'A') || (choice == 'a') ){
    if (digits[1] == grid[1][2]){
        cout << endl << "Yes, that's correct!";
        playerX -= 1;
        guessedDigit2 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }
    else if ( (choice == 'L') || (choice == 'l') ){
    if (digits[1] == grid[2][1]){
        cout << endl << "Yes, that's correct!";
        playerY -= 1;
        guessedDigit2 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }
    else if ( (choice == 'B') || (choice == 'b') ){
    if (digits[1] == grid[3][2]){
        cout << endl << "Yes, that's correct!";
        playerX += 1;
        guessedDigit2 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }
    else if ( (choice == 'R') || (choice == 'r') ){
    if (digits[1] == grid[2][3]){
        cout << endl << "Yes, that's correct!";
        playerY += 1;
        guessedDigit2 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    if (wrong){
    while ( (wrong) && (!lost) ){
    if ( (usedSmall[0]) && (usedSmall[1]) && (usedSmall[2]) )
        lost = true;
    else{
        int chance = 0;
        for (int ch = 0; ch < 3; ch++){
            cout << endl << ch+1 << ". ";
            items[ch].showPrize();
            if (usedSmall[ch])
                cout << " - X";
        }
        while ( (chance < 1) || (chance > 3) ){
            cout << endl << "Which item do you want to try for a second chance?: ";
                cin >> chance;
            if (usedSmall[chance-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                chance = 0;
            }
        }
        int thePrice = 0;
        if (chance == 1){
            usedSmall[0] = true;
            cout << endl;
            items[0].showPrize();
            cout << endl << "1. $" << item1Prices[0];
            cout << endl << "2. $" << item1Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[0].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item1Prices[thePrice-1] == items[0].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 1

        else if (chance == 2){
            usedSmall[1] = true;
            cout << endl;
            items[1].showPrize();
            cout << endl << "1. $" << item2Prices[0];
            cout << endl << "2. $" << item2Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[1].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item2Prices[thePrice-1] == items[1].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 2

        else{
            usedSmall[2] = true;
            cout << endl;
            items[2].showPrize();
            cout << endl << "1. $" << item3Prices[0];
            cout << endl << "2. $" << item3Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[2].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item3Prices[thePrice-1] == items[2].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 3

    } // end else if player can pick items
    } // end while wrong statement

    } // end if wrong

    } // end while loop for guessing digit #2

    bool guessedDigit3 = false;
    char orientation = '!';

    while ( (!guessedDigit3) && (!lost) ){
    cout << endl << " $" << digits[0] << digits[1] << "***";
    cout << endl;
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            if ( (x == playerX) && (y == playerY) )
                cout << "@ ";
            else
                cout << grid[x][y] << " ";
        }
        cout << endl;
    }
    char choice = '!';

    if ( (playerX == 1) && (playerY == 2) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if player is at [1][2]

    else if ( (playerX == 2) && (playerY == 1) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if player is at [2][1]

    else if ( (playerX == 3) && (playerY == 2) ){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if player is at [3][2]

    else{
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if player is at [2][3]

    if ( (choice == 'A') || (choice == 'a') ){
    if (digits[2] == grid[playerX-1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX -= 1;
        orientation = 'A';
        guessedDigit3 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'L') || (choice == 'l') ){
    if (digits[2] == grid[playerX][playerY-1]){
        cout << endl << "Yes, that's correct!";
        playerY -= 1;
        orientation = 'L';
        guessedDigit3 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'B') || (choice == 'b') ){
    if (digits[2] == grid[playerX+1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX += 1;
        orientation = 'B';
        guessedDigit3 = true;
    }
    else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'R') || (choice == 'r') ){
    if (digits[2] == grid[playerX][playerY+1]){
        cout << endl << "Yes, that's correct!";
        playerY += 1;
        orientation = 'R';
        guessedDigit3 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

   if (wrong){
    while ( (wrong) && (!lost) ){
    if ( (usedSmall[0]) && (usedSmall[1]) && (usedSmall[2]) )
        lost = true;
    else{
        int chance = 0;
        for (int ch = 0; ch < 3; ch++){
            cout << endl << ch+1 << ". ";
            items[ch].showPrize();
            if (usedSmall[ch])
                cout << " - X";
        }
        while ( (chance < 1) || (chance > 3) ){
            cout << endl << "Which item do you want to try for a second chance?: ";
                cin >> chance;
            if (usedSmall[chance-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                chance = 0;
            }
        }
        int thePrice = 0;
        if (chance == 1){
            usedSmall[0] = true;
            cout << endl;
            items[0].showPrize();
            cout << endl << "1. $" << item1Prices[0];
            cout << endl << "2. $" << item1Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[0].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item1Prices[thePrice-1] == items[0].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 1

        else if (chance == 2){
            usedSmall[1] = true;
            cout << endl;
            items[1].showPrize();
            cout << endl << "1. $" << item2Prices[0];
            cout << endl << "2. $" << item2Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[1].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item2Prices[thePrice-1] == items[1].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 2

        else{
            usedSmall[2] = true;
            cout << endl;
            items[2].showPrize();
            cout << endl << "1. $" << item3Prices[0];
            cout << endl << "2. $" << item3Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[2].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item3Prices[thePrice-1] == items[2].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 3

    } // end else if player can pick items
    } // end while wrong statement

    } // end if wrong

    } // end while loop for guessing digit #3

///--------------------------------------------------///
    tile current;
    current.a = playerX;
    current.b = playerY;

    bool guessedDigit4 = false;

    while ( (!guessedDigit4) && (!lost) ){
    cout << endl << " $" << digits[0] << digits[1] << digits[2] << "**";
    cout << endl;
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            if ( (x == playerX) && (y == playerY) )
                cout << "@ ";
            else
                cout << grid[x][y] << " ";
        }
        cout << endl;
    }

    char choice = '!';

    if (onTopEdge(current)){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    }
    }

    else if (onBottomEdge(current)){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    }
    }

    else if (onLeftEdge(current)){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'B') && (choice != 'b') ){
    cout << endl << "Is the next number";
    cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
    cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
    cout << endl << "Enter which way the next digit is: ";
    cin >> choice;
    }
    }

    else if (onRightEdge(current)){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'B') && (choice != 'b') ){
    cout << endl << "Is the next number";
    cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
    cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
    cout << endl << "Enter which way the next digit is: ";
    cin >> choice;
    }
    }

    else{

    if (orientation == 'A'){
        while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
        } // end while loop
    } // end if orientation is ABOVE

    else if (orientation == 'B'){
        while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
        } // end while loop
    } // end if orientation is BELOW

    else if (orientation == 'R'){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if orentation is RIGHT

    else{
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end input while loop
    } // end if orientation is LEFT

    } // end else if player is not on an edge

    if ( (choice == 'A') || (choice == 'a') ){
    if (digits[3] == grid[playerX-1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX -= 1;
        guessedDigit4 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'L') || (choice == 'l') ){
    if (digits[3] == grid[playerX][playerY-1]){
        cout << endl << "Yes, that's correct!";
        playerY -= 1;
        guessedDigit4 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'B') || (choice == 'b') ){
    if (digits[3] == grid[playerX+1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX += 1;
        guessedDigit4 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'R') || (choice == 'r') ){
    if (digits[3] == grid[playerX][playerY+1]){
        cout << endl << "Yes, that's correct!";
        playerY += 1;
        guessedDigit4 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

   if (wrong){
    while ( (wrong) && (!lost) ){
    if ( (usedSmall[0]) && (usedSmall[1]) && (usedSmall[2]) )
        lost = true;
    else{
        int chance = 0;
        for (int ch = 0; ch < 3; ch++){
            cout << endl << ch+1 << ". ";
            items[ch].showPrize();
            if (usedSmall[ch])
                cout << " - X";
        }
        while ( (chance < 1) || (chance > 3) ){
            cout << endl << "Which item do you want to try for a second chance?: ";
                cin >> chance;
            if (usedSmall[chance-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                chance = 0;
            }
        }
        int thePrice = 0;
        if (chance == 1){
            usedSmall[0] = true;
            cout << endl;
            items[0].showPrize();
            cout << endl << "1. $" << item1Prices[0];
            cout << endl << "2. $" << item1Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[0].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item1Prices[thePrice-1] == items[0].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 1

        else if (chance == 2){
            usedSmall[1] = true;
            cout << endl;
            items[1].showPrize();
            cout << endl << "1. $" << item2Prices[0];
            cout << endl << "2. $" << item2Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[1].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item2Prices[thePrice-1] == items[1].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 2

        else{
            usedSmall[2] = true;
            cout << endl;
            items[2].showPrize();
            cout << endl << "1. $" << item3Prices[0];
            cout << endl << "2. $" << item3Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[2].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item3Prices[thePrice-1] == items[2].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 3

    } // end else if player can pick items
    } // end while wrong statement

    } // end if wrong

    } // end while loop for guessing digit #4

    current.a = playerX;
    current.b = playerY;

    bool guessedDigit5 = false;
    while ( (!guessedDigit5) && (!lost) ){
    cout << endl << " $" << digits[0] << digits[1] << digits[2] << digits[3] << "*";
    cout << endl;
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            if ( (x == playerX) && (y == playerY) )
                cout << "@ ";
            else
                cout << grid[x][y] << " ";
        }
        cout << endl;
    }

    char choice = '!';

    if (onTopEdge(current) &&  !(onTopEdge(dig3)) ){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    } // end if on top edge

    else if (onBottomEdge(current) && !(onBottomEdge(dig3)) ){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onLeftEdge(current) && !(onLeftEdge(dig3)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onRightEdge(current) && !(onRightEdge(dig3)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onTopEdge(current) && (playerY == 1) ){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onTopEdge(current) && (playerY == 3) ){
    while ( (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onBottomEdge(current) && (playerY == 1) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onBottomEdge(current) && (playerY == 3) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onLeftEdge(current) && (playerX == 1)){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onLeftEdge(current) && (playerX == 3)){
    while ( (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onRightEdge(current) && (playerX == 1)){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if (onRightEdge(current) && (playerX == 3)){
    while ( (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 2) && (dig2.b == 3)) && ((dig3.a == 3) && (dig3.b == 3)) && ((dig4.a == 3) && (dig4.b == 2)) ){
    while ( (choice != 'L') && (choice != 'l') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 2) && (dig2.b == 3)) && ((dig3.a == 1) && (dig3.b == 3)) && ((dig4.a == 1) && (dig4.b == 2)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 3) && (dig2.b == 2)) && ((dig3.a == 3) && (dig3.b == 3)) && ((dig4.a == 2) && (dig4.b == 3)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 3) && (dig2.b == 2)) && ((dig3.a == 3) && (dig3.b == 1)) && ((dig4.a == 2) && (dig4.b == 1)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'L') && (choice != 'l') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 2) && (dig2.b == 1)) && ((dig3.a == 1) && (dig3.b == 1)) && ((dig4.a == 1) && (dig4.b == 2)) ){
    while ( (choice != 'A') && (choice != 'a') && (choice != 'R') && (choice != 'r') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX-1][playerY] << " above you (A)? ";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 2) && (dig2.b == 1)) && ((dig3.a == 3) && (dig3.b == 1)) && ((dig4.a == 3) && (dig4.b == 2)) ){
    while ( (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else if ( ((dig2.a == 1) && (dig2.b == 2)) && ((dig3.a == 1) && (dig3.b == 3)) && ((dig4.a == 2) && (dig4.b == 3)) ){
    while ( (choice != 'R') && (choice != 'r') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY+1] << " to your right (R)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    else{
    while ( (choice != 'L') && (choice != 'l') && (choice != 'B') && (choice != 'b') ){
        cout << endl << "Is the next number";
        cout << endl << "the " << grid[playerX][playerY-1] << " to your left (L)? ";
        cout << endl << "the " << grid[playerX+1][playerY] << " below you (B)? ";
        cout << endl << "Enter which way the next digit is: ";
        cin >> choice;
    } // end while loop
    }

    if ( (choice == 'A') || (choice == 'a') ){
    if (digits[4] == grid[playerX-1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX -= 1;
        guessedDigit5 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'L') || (choice == 'l') ){
    if (digits[4] == grid[playerX][playerY-1]){
        cout << endl << "Yes, that's correct!";
        playerY -= 1;
        guessedDigit5 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'B') || (choice == 'b') ){
    if (digits[4] == grid[playerX+1][playerY]){
        cout << endl << "Yes, that's correct!";
        playerX += 1;
        guessedDigit5 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

    else if ( (choice == 'R') || (choice == 'r') ){
    if (digits[4] == grid[playerX][playerY+1]){
        cout << endl << "Yes, that's correct!";
        playerY += 1;
        guessedDigit5 = true;
    }
   else{
        cout << endl << "Sorry, that's not correct.";
        wrong = true;
        }
    }

  if (wrong){
    while ( (wrong) && (!lost) ){
    if ( (usedSmall[0]) && (usedSmall[1]) && (usedSmall[2]) )
        lost = true;
    else{
        int chance = 0;
        for (int ch = 0; ch < 3; ch++){
            cout << endl << ch+1 << ". ";
            items[ch].showPrize();
            if (usedSmall[ch])
                cout << " - X";
        }
        while ( (chance < 1) || (chance > 3) ){
            cout << endl << "Which item do you want to try for a second chance?: ";
                cin >> chance;
            if (usedSmall[chance-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                chance = 0;
            }
        }
        int thePrice = 0;
        if (chance == 1){
            usedSmall[0] = true;
            cout << endl;
            items[0].showPrize();
            cout << endl << "1. $" << item1Prices[0];
            cout << endl << "2. $" << item1Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[0].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item1Prices[thePrice-1] == items[0].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 1

        else if (chance == 2){
            usedSmall[1] = true;
            cout << endl;
            items[1].showPrize();
            cout << endl << "1. $" << item2Prices[0];
            cout << endl << "2. $" << item2Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[1].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item2Prices[thePrice-1] == items[1].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 2

        else{
            usedSmall[2] = true;
            cout << endl;
            items[2].showPrize();
            cout << endl << "1. $" << item3Prices[0];
            cout << endl << "2. $" << item3Prices[1];
            while ( (thePrice < 1) || (thePrice > 2) ){
                cout << endl << "What is the price of the ";
                items[2].showShortName();
                cout << "?: ";
                cin >> thePrice;
            } // end while
        if (item3Prices[thePrice-1] == items[2].getPrice()){
            cout << endl << "Yes, that's correct. You've won another chance.";
            wrong = false;
        }
        else
            cout << endl << "Sorry, that's not correct.";
        } // end if chance == 3

    } // end else if player can pick items
    } // end while wrong statement

    } // end if wrong

    } // end while loop for guessing digit #5

    cout << endl;

    if (guessedDigit5){
        cout << endl << " $" << carPrice;
        cout << endl << "Congratulations, you win!";}
    else{
        cout << endl << "Sorry, you lose.";
        cout << endl << "The price of the car was $" << carPrice << ".";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Pocket Change
void playPocketChange()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "POCKET CHANGE" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    double amounts[20] = {0, 0, 0.05, 0.05, 0.05, 0.05,
                          0.1, 0.1, 0.1, 0.1, 0.1,
                          0.25, 0.25, 0.25, 0.25,
                          0.5, 0.5, 0.5, 0.75, 2};

    random_shuffle(&amounts[0], &amounts[20]);

    int choices[6];

    /// Set the first five digits, then set a fake "dummy" digit.
    for (int c = 0; c < 5; c++)
        choices[c] = digits[c];

    choices[5] = rand() % 10;
    while ( (choices[5] == choices[0]) || (choices[5] == choices[1]) || (choices[5] == choices[2]) || (choices[5] == choices[3]) || (choices[5] == choices[4]) )
            choices[5] = rand() % 10;

    sortPocketNos(choices);
    cout << endl;

    bool shown[10];
    for (int s = 0; s < 10; s++)
        shown[s] = false;

    double salePrice = 0.25;

    /// Give the player the first digit for free.
    shown[digits[0]] = true;

    /// Second digit
    bool guessedSecondDigit = false;
    while (!guessedSecondDigit){
    cout << endl << "$" << digits[0] << "****";
    cout << endl << fixed << setprecision(2) << "Price: $" << salePrice;
    cout << endl;
    for (int e = 0; e < 6; e++){
        if (shown[choices[e]])
            cout << "* ";
        else
            cout << choices[e] << " ";
    }
    int answer2 = 10;
    while ( (answer2 < 0) || (answer2 > 9) ){
        cout << endl << "What is the next digit in the price of the car?: ";
        cin >> answer2;
    }
    if ( (answer2 != choices[0] ) && (answer2 != choices[1] ) && (answer2 != choices[2] ) && (answer2 != choices[3] ) && (answer2 != choices[4] ) && (answer2 != choices[5] ) ){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer2 = 10;
    } // player guesses a number that isn't in the price at all

    else if (shown[answer2]){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer2 = 10;
    } // player guesses a number that's already been called

    else{
    if (answer2 == digits[1]){
        cout << endl << "That's correct! You get to pick an envelope.";

        /// Reset the board.
        for (int g = 0; g < 10; g++)
            shown[g] = false;
        shown[digits[0]] = true;
        shown[digits[1]] = true;
        guessedSecondDigit = true;
        }
    else{
        cout << endl << fixed << setprecision(2) << "Sorry, that's not correct. The car's price is now $" << salePrice+0.25 << ".";
        salePrice += 0.25;
        shown[answer2] = true;
        answer2 = 10;
    }
    } // player guesses a number on the board

    } // end while loop for second digit
    cout << endl;

    /// Third digit
    bool guessedThirdDigit = false;
    while (!guessedThirdDigit){
    cout << endl << "$" << digits[0] << digits[1] << "***";
    cout << endl << fixed << setprecision(2) << "Price: $" << salePrice;
    cout << endl;
    for (int e = 0; e < 6; e++){
        if (shown[choices[e]])
            cout << "* ";
        else
            cout << choices[e] << " ";
    }
    int answer3 = 10;
    while ( (answer3 < 0) || (answer3 > 9) ){
        cout << endl << "What is the next digit in the price of the car?: ";
        cin >> answer3;
    }
    if ( (answer3 != choices[0] ) && (answer3 != choices[1] ) && (answer3 != choices[2] ) && (answer3 != choices[3] ) && (answer3 != choices[4] ) && (answer3 != choices[5] ) ){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer3 = 10;
    } // player guesses a number that isn't in the price at all

    else if (shown[answer3]){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer3 = 10;
    } // player guesses a number that's already been called

    else{
    if (answer3 == digits[2]){
        cout << endl << "That's correct! You get to pick an envelope.";

        /// Reset the board.
        for (int g = 0; g < 10; g++)
            shown[g] = false;
        shown[digits[0]] = true;
        shown[digits[1]] = true;
        shown[digits[2]] = true;
        guessedThirdDigit = true;
        }
    else{
        cout << endl << fixed << setprecision(2) << "Sorry, that's not correct. The car's price is now $" << salePrice+0.25 << ".";
        salePrice += 0.25;
        shown[answer3] = true;
        answer3 = 10;
    }
    } // player guesses a number on the board

    } // end while loop for third digit

    /// Fourth digit
    bool guessedFourthDigit = false;
    while (!guessedFourthDigit){
    cout << endl << "$" << digits[0] << digits[1] << digits[2] << "**";
    cout << endl << fixed << setprecision(2) << "Price: $" << salePrice;
    cout << endl;
    for (int e = 0; e < 6; e++){
        if (shown[choices[e]])
            cout << "* ";
        else
            cout << choices[e] << " ";
    }
    int answer4 = 10;
    while ( (answer4 < 0) || (answer4 > 9) ){
        cout << endl << "What is the next digit in the price of the car?: ";
        cin >> answer4;
    }
    if ( (answer4 != choices[0] ) && (answer4 != choices[1] ) && (answer4 != choices[2] ) && (answer4 != choices[3] ) && (answer4 != choices[4] ) && (answer4 != choices[5] ) ){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer4 = 10;
    } // player guesses a number that isn't in the price at all

    else if (shown[answer4]){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer4 = 10;
    } // player guesses a number that's already been called

    else{
    if (answer4 == digits[3]){
        cout << endl << "That's correct! You get to pick an envelope.";

        /// Reset the board.
        for (int g = 0; g < 10; g++)
            shown[g] = false;
        shown[digits[0]] = true;
        shown[digits[1]] = true;
        shown[digits[2]] = true;
        shown[digits[3]] = true;
        guessedFourthDigit = true;
        }
    else{
        cout << endl << fixed << setprecision(2) << "Sorry, that's not correct. The car's price is now $" << salePrice+0.25 << ".";
        salePrice += 0.25;
        shown[answer4] = true;
        answer4 = 10;
    }
    } // player guesses a number on the board

    } // end while loop for fourth digit

    /// Fifth digit
    bool guessedFifthDigit = false;
    while (!guessedFifthDigit){
    cout << endl << "$" << digits[0] << digits[1] << digits[2] << digits[3] << "*";
    cout << endl << fixed << setprecision(2) << "Price: $" << salePrice;
    cout << endl;
    for (int e = 0; e < 6; e++){
        if (shown[choices[e]])
            cout << "* ";
        else
            cout << choices[e] << " ";
    }
    int answer5 = 10;
    while ( (answer5 < 0) || (answer5 > 9) ){
        cout << endl << "What is the next digit in the price of the car?: ";
        cin >> answer5;
    }
    if ( (answer5 != choices[0] ) && (answer5 != choices[1] ) && (answer5 != choices[2] ) && (answer5 != choices[3] ) && (answer5 != choices[4] ) && (answer5 != choices[5] ) ){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer5 = 10;
    } // player guesses a number that isn't in the price at all

    else if (shown[answer5]){
        cout << endl << "That number isn't on the board. Please pick another one.";
        answer5 = 10;
    } // player guesses a number that's already been called

    else{
    if (answer5 == digits[4]){
        cout << endl << "That's correct! You get to pick an envelope.";
        guessedFifthDigit = true;
        }
    else{
        cout << endl << fixed << setprecision(2) << "Sorry, that's not correct. The car's price is now $" << salePrice+0.25 << ".";
        salePrice += 0.25;
        shown[answer5] = true;
        answer5 = 10;
    }

    } // player guesses a number on the board

    } // end while loop for fifth digit

    double total = 0.25;

    cout << endl << "$" << carPrice;
    cout << endl << fixed << setprecision(2) << "Price: $" << salePrice;

    bool won = false;

    if (salePrice == 0.25)
        cout << endl << "Congratulations, you win!";
    else{
        cout << endl << "Let's see if you've collected enough pocket change to buy the car.";
        cout << endl;
        system("pause");
        int on = 0;
        cout << endl << "Right now you have $0.25." << endl;
        while ( (on < 4) && (!won) ){
            cout << endl << fixed << setprecision(2) << "In this envelope is $" << amounts[on];
            total += amounts[on];
            cout << endl << fixed << setprecision(2) << "For a total of $" << total;
            if (total >= salePrice)
                won = true;
            else{
                if (on < 3){
                cout << endl;
                system("pause");}
                on++;}
        }
        if (won)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";

    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Professor Price
void playProfessorPrice()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "PROFESSOR PRICE" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int corrects = 0;
    int wrongs = 0;

    //cout << endl << "$" << digits[0] << "**" << digits[3] << digits[4];
    cout << endl << "Correct answers: " << corrects;
    cout << endl << "Incorrect answers: " << wrongs;

    int revealWhich = rand() % 2; // if 0, digit 2 will be "revealed" first. if 1, digit 3 will be "revealed" first.

    // Determines which question will be asked
    int digit2Ques = rand() % 3;
    int digit3Ques;

    // Ensures that if digits 2 and 3 are the same, the same question won't be asked for both numbers
    if (digits[2] == digits[1]){
    digit3Ques = digit2Ques;
    while (digit3Ques == digit2Ques)
            digit3Ques = rand() % 3;
    }
    else
        digit3Ques = rand() % 3;

    // If these equal 0, then the random number will be in the price. If 1, they won't.
    int rightForDig2 = rand() % 2;
    int rightForDig3 = rand() % 2;

    int wrong2 = digits[1];
    while ( (wrong2 == digits[1]) || (wrong2 == digits[2]) )
        wrong2 = rand() % 10;

    int wrong3 = digits[2];
    while ( (wrong3 == digits[1] || (wrong3 == digits[2]) || (wrong3 == wrong2)) )
        wrong3 = rand() % 10;

    int question1ID;
    if ( (revealWhich == 0) && (rightForDig2 == 0) ) // this is the correct answer for digit #2
        question1ID = digits[1];
    else if ( (revealWhich == 1) && (rightForDig3 == 0) ) // this is the correct answer for digit #3
        question1ID = digits[2];
    else if ( (revealWhich == 0) && (rightForDig2 == 1) )
        question1ID = wrong2;
    else
        question1ID = wrong3;

    int question2ID;
    if ( (revealWhich == 0) && (rightForDig3 == 0) ) // this is the correct answer for digit #3
        question2ID = digits[2];
    else if ( (revealWhich == 1) && (rightForDig2 == 0) ) // this is the correct answer for digit #2
        question2ID = digits[1];
    else if ( (revealWhich == 0) && (rightForDig3 == 1) )
        question2ID = wrong3;
    else
        question2ID = wrong2;

    cout << endl;
    int choice1 = 10;

    while ( (choice1 < 0) || (choice1 > 9) ){
    if (revealWhich == 0)
        showTrivia(question1ID, digit2Ques);
    else
        showTrivia(question1ID, digit3Ques);
    cin >> choice1;
    }
    if (choice1 == question1ID){
        cout << endl << "Yes, that's correct.";
        corrects += 1;
    }
    else{
        cout << endl << "Sorry, that's not correct. \nThe correct answer was " << question1ID << ".";
        wrongs += 1;
    }

    cout << endl;
    cout << endl << "Correct answers: " << corrects;
    cout << endl << "Incorrect answers: " << wrongs;
    cout << endl << "$" << digits[0] << "**" << digits[3] << digits[4];

    bool revealedDigit2 = false;
    bool revealedDigit3 = false;

    char answer1 = '!';
    while ( (answer1 != 'Y') && (answer1 != 'y') && (answer1 != 'N') && (answer1 != 'n') ){
    cout << endl << "Is " << question1ID << " one of the missing digits in the price of the car (Y/N)?: ";
    cin >> answer1;
    }

    if ( (answer1 == 'Y') || (answer1 == 'y') ){
    if (question1ID == digits[1]){
        cout << endl << "Yes, it's the second digit in the price.";
        revealedDigit2 = true;
        corrects += 1;
    }
    else if (question1ID == digits[2]){
        cout << endl << "Yes, it's the third digit in the price.";
        revealedDigit3 = true;
        corrects += 1;
    }
    else{
        cout << endl << "Sorry, " << question1ID << " is not one of the missing digits in the price.";
        wrongs += 1;
    }
    } // player said YES

    else{
    if (question1ID == digits[1]){
        cout << endl << "Sorry, " << question1ID << " is the second digit in the price.";
        revealedDigit2 = true;
        wrongs += 1;
    }
    else if (question1ID == digits[2]){
        cout << endl << "Sorry, " << question1ID << " is the third digit in the price.";
        revealedDigit3 = true;
        wrongs += 1;
    }
    else{
        cout << endl << "Yes, " << question1ID << " is not one of the missing digits in the price.";
        corrects += 1;
    }
    } // player said NO

    cout << endl;
    cout << endl << "Correct answers: " << corrects;
    cout << endl << "Incorrect answers: " << wrongs;
    if (revealedDigit2)
        cout << endl << "$" << digits[0] << digits[1] << "*" << digits[3] << digits[4];
    else if (revealedDigit3)
        cout << endl << "$" << digits[0] << "*" << digits[2] << digits[3] << digits[4];
    else
        cout << endl << "$" << digits[0] << "**" << digits[3] << digits[4];

    cout << endl;
    int choice2 = 10;

    while ( (choice2 < 0) || (choice2 > 9) ){
    if (revealWhich == 0)
        showTrivia(question2ID, digit3Ques);
    else
        showTrivia(question2ID, digit2Ques);
    cin >> choice2;
    }
    if (choice2 == question2ID){
        cout << endl << "Yes, that's correct.";
        corrects += 1;
    }
    else{
        cout << endl << "Sorry, that's not correct. \nThe correct answer was " << question2ID << ".";
        wrongs += 1;
    }
    cout << endl;
    cout << endl << "Correct answers: " << corrects;
    cout << endl << "Incorrect answers: " << wrongs;
    if (corrects == 3)
        cout << endl << "Congratulations, you win!";
    else if (wrongs == 3)
        cout << endl << "Sorry, you lose.";
    else{
    char answer2 = '!';
    while ( (answer2 != 'Y') && (answer2 != 'y') && (answer2 != 'N') && (answer2 != 'n') ){
    cout << endl << "Is " << question2ID << " one of the missing digits in the price of the car (Y/N)?: ";
    cin >> answer2;
    }

    if ( (answer2 == 'Y') || (answer2 == 'y') ){
    if (question2ID == digits[1]){
        cout << endl << "Yes, it's the second digit in the price.";
        revealedDigit2 = true;
        corrects += 1;
    }
    else if (question2ID == digits[2]){
        cout << endl << "Yes, it's the third digit in the price.";
        revealedDigit3 = true;
        corrects += 1;
    }
    else{
        cout << endl << "Sorry, " << question2ID << " is not one of the missing digits in the price.";
        wrongs += 1;
    }
    } // player said YES

    else{
    if (question2ID == digits[1]){
        cout << endl << "Sorry, " << question2ID << " is the second digit in the price.";
        revealedDigit2 = true;
        wrongs += 1;
    }
    else if (question2ID == digits[2]){
        cout << endl << "Sorry, " << question2ID << " is the third digit in the price.";
        revealedDigit3 = true;
        wrongs += 1;
    }
    else{
        cout << endl << "Yes, " << question2ID << " is not one of the missing digits in the price.";
        corrects += 1;
    }
    } // player said NO

    cout << endl;
    cout << endl << "Correct answers: " << corrects;
    cout << endl << "Incorrect answers: " << wrongs;
    if ( (revealedDigit2) && (revealedDigit3) )
        cout << endl << "$" << carPrice;
    else if (revealedDigit2)
        cout << endl << "$" << digits[0] << digits[1] << "*" << digits[3] << digits[4];
    else if (revealedDigit3)
        cout << endl << "$" << digits[0] << "*" << digits[2] << digits[3] << digits[4];
    else
        cout << endl << "$" << digits[0] << "**" << digits[3] << digits[4];

    if (corrects == 3)
        cout << endl << "Congratulations, you win!";
    else if (wrongs == 3)
        cout << endl << "Sorry, you lose.";
    else{
        int verdict = digits[1];
        while ( (verdict == digits[1]) || (verdict == digits[2]) || (verdict == wrong2) || (verdict == wrong3) )
            verdict = rand() % 10;

        int param = rand() % 3;
        int choice3 = 10;
        while ( (choice3 < 0) || (choice3 > 9) ){
            showTrivia(verdict, param);
            cin >> choice3;
        }
        if (choice3 == verdict){
            cout << endl << "Yes, that's correct. \nCongratulations, you win!";
        }
        else{
            cout << endl << "Sorry, that's not correct. \nThe correct answer was " << verdict << ".";
            cout << endl << "Sorry, you lose.";
        }

    } // end else if player has two right and two wrong

    } // end else if player didn't win or lose at the third question

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Seven Up
void playSevenUp()
{
    /// Credit to barkernewton for making this game!

    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "7UP" << endl;
    cout << endl;

    /// Pick a car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int choices[7];
    for (int c = 0; c < 5; c++)
        choices[c] = digits[c];

    choices[5] = digits[0];
    while ( (choices[5] == choices[0]) || (choices[5] == choices[1]) || (choices[5] == choices[2])
           || (choices[5] == choices[3]) || (choices[5] == choices[4]) )
        choices[5] = rand() % 10;

    choices[6] = digits[0];
    while ( (choices[6] == choices[0]) || (choices[6] == choices[1]) || (choices[6] == choices[2])
           || (choices[6] == choices[3]) || (choices[6] == choices[4]) || (choices[6] == choices[5]) )
        choices[6] = rand() % 10;

    sortStackNumbers(choices);

    int chances = 3;
    bool won = false;

    cout << endl;

    while ( (chances > 0) && (!won) ){
    int bid = 0;
    cout << endl << "Chances left: " << chances;
    cout << endl << "*" << choices[0] << choices[1] << choices[2] << choices[3] << choices[4] << choices[5] << choices[6] << "*";
    while ( (bid < 10000) || (bid > 99999) ){
        cout << endl << "Using 5 of the above digits, what is the price of the car?: $";
        cin >> bid;
    }
    if (bid == carPrice)
        won = true;
    else{
        cout << endl << "Sorry, that's not correct.";
        chances -= 1;
    }
    } // end while loop

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Shower Game
void playShowerGame()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "SHOWER GAME" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int price2 = carPrice;
    int price3 = carPrice;
    int price4 = carPrice;
    int price5 = carPrice;
    int price6 = carPrice;
    //cout << endl << "initialized car price variables" << endl;

    //cout << endl << "price = $" << carPrice;

    int loBound = roundDown(carPrice);
    int hiBound = loBound + 5000;

    while (price2 == carPrice)
        price2 = rand() % (hiBound - loBound) + loBound;

    while ((price3 == carPrice) || (price3 == price2))
        price3 = rand() % (hiBound - loBound) + loBound;

    while ((price4 == carPrice) || (price4 == price2) || (price4 == price3) )
        price4 = rand() % (hiBound - loBound) + loBound;

    while ((price5 == carPrice) || (price5 == price2) || (price5 == price3) || (price5 == price4))
        price5 = rand() % (hiBound - loBound) + loBound;

    while ((price6 == carPrice) || (price6 == price2) || (price6 == price3) || (price6 == price4) || (price6 == price5))
        price6 = rand() % (hiBound - loBound) + loBound;

    bool picked[6];
    for (int x = 0; x < 6; x++)
        picked[x] = false;
    //cout << endl << "set picked variables" << endl;

    /// Instead of randomly associating each value with a price, the results for each
    /// incorrect shower will be randomized and the player will go through them in that
    /// order. Every time the player picks a price, valueOn will be incremented.
    /// 1 refers to confetti (at which point the game continues), and 2 refers to $500
    /// (at which point the game ends).
    int showerRes[5] = { 1, 1, 1, 2, 2 };
    random_shuffle(&showerRes[0], &showerRes[5]);
    int valueOn = 0;

    /// Put the prices in an array and randomize them.
    int prices[6] = {carPrice, price2, price3, price4, price5, price6};
    random_shuffle(&prices[0], &prices[6]);

    bool won = false;
    bool lost = false;

       //cout << endl << "Price: $" << carPrice;

    cout << endl;
    while ( (!won) && (!lost) )
    {
       int choice = 0;
        cout << "1. $" << prices[0];
        if (picked[0])
            cout << "- O";
        cout << endl;
        cout << "2. $" << prices[1];
        if (picked[1])
            cout << "- O";
        cout << endl;
        cout << "3. $" << prices[2];
        if (picked[2])
            cout << "- O";
        cout << endl;
        cout << "4. $" << prices[3];
        if (picked[3])
            cout << "- O";
        cout << endl;
        cout << "5. $" << prices[4];
        if (picked[4])
            cout << "- O";
        cout << endl;
        cout << "6. $" << prices[5];
        if (picked[5])
            cout << "- O";
        cout << endl;
        cout << "Which price do you want to pick?: ";
        cin >> choice;
        switch (choice){
        case 1:
        if (picked[0] == false)
        {
            if (prices[0] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[0] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        case 2:
        if (picked[1] == false)
        {
            if (prices[1] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[1] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        case 3:
        if (picked[2] == false)
        {
            if (prices[2] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[2] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        case 4:
        if (picked[3] == false)
        {
            if (prices[3] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[3] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        case 5:
        if (picked[4] == false)
        {
            if (prices[4] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[4] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        case 6:
        if (picked[5] == false)
        {
            if (prices[5] == carPrice)
                won = true;
            else
            {
            if (showerRes[valueOn] == 1)
            {
                cout << endl << "You were showered with confetti! Pick another price." << endl;
                picked[5] = true;
                valueOn += 1;
            }
            else if (showerRes[valueOn] == 2)
                lost = true;
            } // end else statement
        } // end if statement
        else
            cout << endl << "You've already picked this price. Please pick another." << endl;
        break;

        default:
            cout << endl << "That won't work. Try again." << endl;

        } // end switch statement
    }

    if (won)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "You didn't win the car, but you won $500. \nThe price of the car was $" << carPrice << ".";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Split Decision
void playSplitDecision()
{
    /// car
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    /// medium prize
    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    int j = 0;

    inFile.open("./prizes/" + medInput);
    while (inFile){
    mptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price < 1000) )
    {
        mptr->setDescription(m_Description);
        mptr->setShortName(m_ShortName);
        mptr->setPrice(m_Price);
        gameMeds.push_back(*mptr);
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// The game itself
    cout << "SPLIT DECISION" << endl;

    /// Set the car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    /// Set the small prize
    int randomSmall = rand() % j;
    medium prizeMed;

    gameMedIt = gameMeds.begin();
    for (int y = 0; y < randomSmall; y++)
        gameMedIt++;
    prizeMed.setDescription(gameMedIt->getDescription());
    prizeMed.setShortName(gameMedIt->getShortName());
    prizeMed.setPrice(gameMedIt->getPrice());

    cout << endl;
    prizeMed.showPrize();

    int medPrice = prizeMed.getPrice();

    /// The combined digits of the car and the medium prize.
    int digits[8];

    int carDigits[5];
    carDigits[0] = carPrice / 10000 % 10;
    carDigits[1] = carPrice / 1000 % 10;
    carDigits[2] = carPrice / 100 % 10;
    carDigits[3] = carPrice / 10 % 10;
    carDigits[4] = carPrice % 10;

    int medDigits[3];
    medDigits[0] = medPrice / 100 % 10;
    medDigits[1] = medPrice / 10 % 10;
    medDigits[2] = medPrice % 10;

    int carOn = 0;
    int medOn = 0;

    int slots[3];
    slots[0] = rand() % 8;
    slots[1] = slots[0];
    while (slots[1] == slots[0])
        slots[1] = rand() % 8;
    slots[2] = slots[0];
    while ( (slots[2] == slots[0]) || (slots[2] == slots[1]) )
        slots[2] = rand() % 8;
    sortSplitPlaces(slots);

    for (int b = 0; b < 8; b++){
    if ( (b == slots[0]) || (b == slots[1]) || (b == slots[2]) ){
        digits[b] = medDigits[medOn];
        medOn++;
        }
    else{
        digits[b] = carDigits[carOn];
        carOn++;
    }
    }

//    cout << endl << endl;
//    for (int c = 0; c < 8; c++){
//        cout << digits[c];
//    }

    int finalCar;
    int finalSmall;

    int carGuess[5];
    int smallGuess[3];

//    cout << endl;
//    cout << endl << "Car price: $" << carPrice;
//    cout << endl << "Medium price: $" << medPrice;
//    cout << endl;

    int chances = 3;
    bool won = false;
    cout << endl << endl;

    while ( (chances > 0) && (!won) ){
    int forCar = 0;
    int forSmall = 0;

    /// Initialize the "values" to dummy values.
    for (int x = 0; x < 5; x++)
        carGuess[x] = 10;
    for (int w = 0; w < 3; w++)
        smallGuess[w] = 10;

    /// Checks if a number has been "used" in the row.
    bool used[8];
    for (int u = 0; u < 8; u++)
        used[u] = false;

    for (int on = 0; on < 8; on++){
        if (forCar >= 5){
            //cout << endl << "The next digit must belong in the small prize";
            smallGuess[forSmall] = digits[on];
            forSmall += 1;
            }
        else if (forSmall >= 3){
            //cout << endl << "The next digit must belong in the car";
            carGuess[forCar] = digits[on];
            forCar += 1;
            }
        else{
            char choice = '!';
            for (int c = 0; c < 8; c++){
            if (!used[c])
                cout << digits[c];
            else
                cout << "*";
            }
            cout << endl << "CAR: ";
            if (forCar == 4)
                cout << "$" << carGuess[0] << carGuess[1] << carGuess[2] << carGuess[3] << "*";
            else if (forCar == 3)
                cout << "$" << carGuess[0] << carGuess[1] << carGuess[2] << "*" << "*";
            else if (forCar == 2)
                cout << "$" << carGuess[0] << carGuess[1] << "*" << "*" << "*";
            else if (forCar == 1)
                cout << "$" << carGuess[0] << "*" << "*" << "*" << "*";
            else
                cout << "$*****";
            cout << endl;
            prizeMed.showShortName();
            cout << ": ";
            if (forSmall == 2)
                cout << "$" << smallGuess[0] << smallGuess[1] << "*";
            else if (forSmall == 1)
                cout << "$" << smallGuess[0] << "**";
            else
                cout << "$***";
            while ( (choice != 'U') && (choice != 'u') && (choice != 'D') && (choice != 'd') ){
            cout << endl << "Does " << digits[on] << " belong in the CAR (U) or the ";
            prizeMed.showShortName();
            cout << "? (D): ";
            cin >> choice;
            }
            if ( (choice == 'U') || (choice == 'u') ){
                carGuess[forCar] = digits[on];
                forCar++;
                cout << endl;
            }
            else{
                smallGuess[forSmall] = digits[on];
                forSmall++;
                cout << endl;
            }
        } // end else
        used[on] = true;
    } // end for loop

    finalCar = carGuess[0]*10000 + carGuess[1]*1000 + carGuess[2]*100 + carGuess[3]*10 + carGuess[4];
    finalSmall = smallGuess[0]*100 + smallGuess[1]*10 + smallGuess[2];

    cout << "The CAR is set to $" << finalCar;
    cout << endl << "The ";
    prizeMed.showShortName();
    cout << " is set to $" << finalSmall;
    cout << endl << "Are these values correct?";
    cout << endl;
    system("pause");

    if ( (finalCar == carPrice) && (finalSmall == medPrice) )
        won = true;
    else{
        cout << endl << "Sorry, that's not correct.";
        if (chances == 3)
            cout << endl << "You have 2 chances left." << endl;
        else if (chances == 2)
            cout << endl << "You have 1 chance left." << endl;
        chances -= 1;
    }

    } // end while loop

    if (won)
        cout << endl << "Congratulations, you win!";
    else{
        cout << endl << "Sorry, you lose.";
        cout << endl << "The price of the CAR was $" << carPrice << " and";
        cout << endl << "the price of the ";
        prizeMed.showShortName();
        cout << " was $" << medPrice << ".";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Stack the Deck
void playStackTheDeck()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;
    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;
    grocery * ggptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    int j = 0;
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
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "STACK THE DECK" << endl;
    cout << endl;

    /// Pick a car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int choices[7];
    for (int c = 0; c < 5; c++)
        choices[c] = digits[c];

    choices[5] = digits[0];
    while ( (choices[5] == choices[0]) || (choices[5] == choices[1]) || (choices[5] == choices[2])
           || (choices[5] == choices[3]) || (choices[5] == choices[4]) )
        choices[5] = rand() % 10;

    choices[6] = digits[0];
    while ( (choices[6] == choices[0]) || (choices[6] == choices[1]) || (choices[6] == choices[2])
           || (choices[6] == choices[3]) || (choices[6] == choices[4]) || (choices[6] == choices[5]) )
        choices[6] = rand() % 10;

    sortStackNumbers(choices);

    bool chosenNo[10];
    for (int h = 0; h < 10; h++)
        chosenNo[h] = false;

    /// Grocery items.
    grocery items[6];

    /// Determines which price will be the correct price.
    int side1 = rand() % 2;
    int side2 = rand() % 2;
    int side3 = rand() % 2;

    /// The prices that will be changed based on their corresponding side.
    double price1;
    double price2;
    double price3;

    /// Random values
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;

    first = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s1 = 0; s1 < first; s1++)
        ggItemIt++;
    items[0].setDescription(ggItemIt->getDescription());
    items[0].setShortName(ggItemIt->getShortName());
    items[0].setPrice(ggItemIt->getPrice());

    bool setSec = false;
    while (!setSec){
    second = first;
    while (second == first)
        second = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s2 = 0; s2 < second; s2++)
        ggItemIt++;
    if (ggItemIt->getPrice() != items[0].getPrice()){
    items[1].setDescription(ggItemIt->getDescription());
    items[1].setShortName(ggItemIt->getShortName());
    items[1].setPrice(ggItemIt->getPrice());
    setSec = true;
    }
    } // end while loop that finds the second item
    if (side1 == 0)
        price1 = items[0].getPrice();
    else
        price1 = items[1].getPrice();

    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s3 = 0; s3 < third; s3++)
        ggItemIt++;
    items[2].setDescription(ggItemIt->getDescription());
    items[2].setShortName(ggItemIt->getShortName());
    items[2].setPrice(ggItemIt->getPrice());

    bool setFor = false;
    while (!setFor){
        fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s4 = 0; s4 < fourth; s4++)
        ggItemIt++;
    if (ggItemIt->getPrice() != items[2].getPrice()){
    items[3].setDescription(ggItemIt->getDescription());
    items[3].setShortName(ggItemIt->getShortName());
    items[3].setPrice(ggItemIt->getPrice());
    setFor = true;
    }
    } // end while loop that finds the fourth item
    if (side2 == 0)
        price2 = items[2].getPrice();
    else
        price2 = items[3].getPrice();

    fifth = first;
    while ( (fifth == first) || (fifth == second) || (fifth == third) || (fifth == fourth) )
        fifth = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s5 = 0; s5 < fifth; s5++)
        ggItemIt++;
    items[4].setDescription(ggItemIt->getDescription());
    items[4].setShortName(ggItemIt->getShortName());
    items[4].setPrice(ggItemIt->getPrice());

    bool setSix = false;
    while (!setSix){
    sixth = first;
    while ( (sixth == first) || (sixth == second) || (sixth == third) || (sixth == fourth) || (sixth == fifth) )
        sixth = rand() % j;
    ggItemIt = ggItems.begin();
    for (int s6 = 0; s6 < sixth; s6++)
        ggItemIt++;
    if (ggItemIt->getPrice() != items[4].getPrice()){
    items[5].setDescription(ggItemIt->getDescription());
    items[5].setShortName(ggItemIt->getShortName());
    items[5].setPrice(ggItemIt->getPrice());
    setSix = true;
    }
    } // end while loop that finds the sixth item
    if (side3 == 0)
        price3 = items[4].getPrice();
    else
        price3 = items[5].getPrice();

    bool revealed[5];
    for (int r = 0; r < 5; r++)
        revealed[r] = false;

    cout << endl << "$*****";
    cout << endl << "| ";
    for (int d = 0; d < 7; d++)
        cout << choices[d] << " ";
    cout << "|" << endl;

    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl << "2. ";
    items[1].showPrize();
    int choice1 = 0;
    while ( (choice1 < 1) || (choice1 > 2) ){
        cout << endl << fixed << setprecision(2) << "Which item is $" << price1 << "?: ";
        cin >> choice1;
        }
    cout << endl << "The actual retail price of the ";
    items[choice1-1].showShortName();
    cout << " is ";
    items[choice1-1].showARP();

    if ( (choice1-1) == side1){
        cout << endl << "Yes, that's correct! You can pick another digit.";
        int pick1 = 0;
        while ( (pick1 < 1) || (pick1 > 5) ){
            cout << endl << "Which digit (1-5) do you want to be revealed?: ";
            cin >> pick1;
        }
        revealed[pick1-1] = true;
        chosenNo[digits[pick1-1]] = true;
    }
    else
        cout << endl << "Sorry, that's not correct." << endl;

    /// Show the player's "price" so far.
    cout << endl << "$";
    for (int k = 0; k < 5; k++){
        if (revealed[k])
            cout << digits[k];
        else
            cout << "*";
    }

    /// Show the usable digits.
    cout << endl << "| ";
    for (int d = 0; d < 7; d++){
        if (chosenNo[choices[d]])
            cout << "*";
        else
            cout << choices[d];
        cout << " ";
        }
    cout << "|" << endl;

    cout << endl << "1. ";
    items[2].showPrize();
    cout << endl << "2. ";
    items[3].showPrize();
    int choice2 = 0;
    while ( (choice2 < 1) || (choice2 > 2) ){
        cout << endl << fixed << setprecision(2) << "Which item is $" << price2 << "?: ";
        cin >> choice2;
        }
    cout << endl << "The actual retail price of the ";
    items[choice2+1].showShortName();
    cout << " is ";
    items[choice2+1].showARP();
    if ( (choice2-1) == side2){
        cout << endl << "Yes, that's correct! You can pick another digit.";
        int pick2 = 0;
        while ( (pick2 < 1) || (pick2 > 5) ){
            cout << endl << "Which digit (1-5) do you want to be revealed?: ";
            cin >> pick2;
            if (revealed[pick2-1]){
                cout << endl << "That digit has already been revealed. Please pick another.";
                pick2 = 0;
            }
        }
        revealed[pick2-1] = true;
        chosenNo[digits[pick2-1]] = true;
    }
    else
        cout << endl << "Sorry, that's not correct." << endl;

    /// Show the player's "price" so far.
    cout << endl << "$";
    for (int k = 0; k < 5; k++){
        if (revealed[k])
            cout << digits[k];
        else
            cout << "*";
    }

    /// Show the usable digits.
    cout << endl << "| ";
    for (int d = 0; d < 7; d++){
        if (chosenNo[choices[d]])
            cout << "*";
        else
            cout << choices[d];
        cout << " ";
        }
    cout << "|" << endl;

    cout << endl << "1. ";
    items[4].showPrize();
    cout << endl << "2. ";
    items[5].showPrize();
    int choice3 = 0;
    while ( (choice3 < 1) || (choice3 > 2) ){
        cout << endl << fixed << setprecision(2) << "Which item is $" << price3 << "?: ";
        cin >> choice3;
        }
    cout << endl << "The actual retail price of the ";
    items[choice3+3].showShortName();
    cout << " is ";
    items[choice3+3].showARP();

    if ( (choice3-1) == side3){
        cout << endl << "Yes, that's correct! You can pick another digit.";
        int pick3 = 0;
        while ( (pick3 < 1) || (pick3 > 5) ){
            cout << endl << "Which digit (1-5) do you want to be revealed?: ";
            cin >> pick3;
            if (revealed[pick3-1]){
                cout << endl << "That digit has already been revealed. Please pick another.";
                pick3 = 0;
            }
        }
        revealed[pick3-1] = true;
        chosenNo[digits[pick3-1]] = true;
    }
    else
        cout << endl << "Sorry, that's not correct." << endl;

    /// Show the player's "price" so far.
    cout << endl << "$";
    for (int k = 0; k < 5; k++){
        if (revealed[k])
            cout << digits[k];
        else
            cout << "*";
    }

    /// Show the usable digits.
    cout << endl << "| ";
    for (int d = 0; d < 7; d++){
        if (chosenNo[choices[d]])
            cout << "*";
        else
            cout << choices[d];
        cout << " ";
        }
    cout << "|" << endl;

    int finalPrice = 0;

    while ( (finalPrice < 10000) || (finalPrice > 99999) ){
    cout << endl << "Now, what do you think is the price of the car?: $";
    cin >> finalPrice;
    }

    cout << endl << "The actual retail price of the car is $" << carPrice;
    if (finalPrice == carPrice)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Switcheroo
void playSwitcheroo(bool mds)
{
    /// Fun fact: This was the 100th game completed!

    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<small> gameItems;
    list<small>::iterator gameItemIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);

    if (!mds){
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) && (compatibleForSwitcheroo(t_Price)) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();
    } // end if not MDG
    else{
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price > maxCar) && (compatibleForSwitcheroo(t_Price)) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();
    } // end if MDG

    int j = 0;
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
        pptr = new small;
        if ( (inFile >> s_Description >> s_ShortName >> s_Price) && (s_Price < 100) )
        {
            pptr->setDescription(s_Description);
            pptr->setShortName(s_ShortName);
            pptr->setPrice(s_Price);
            gameItems.push_back(*pptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "SWITCHEROO" << endl;

    /// Pick a car
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    int carPrice = prizeCar.getPrice();
    int carDigits[5];
    carDigits[0] = carPrice / 10000 % 10;
    carDigits[1] = carPrice / 1000 % 10;
    carDigits[2] = carPrice / 100 % 10;
    carDigits[3] = carPrice / 10 % 10;
    carDigits[4] = carPrice % 10;
//    cout << endl << "car price: $" << carPrice;

    int missingDigits[5];
    missingDigits[0] = carPrice / 10 % 10;
//    cout << endl << "missing digit: " << missingDigits[0];

    /// Set the small prizes.
    small items[4];

    int first;
    int second;
    int third;
    int fourth;

    /// First small prize
    bool setSP1 = false;
    while (!setSP1){
    first = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice() / 10 % 10) != missingDigits[0] ){
        items[0].setDescription(gameItemIt->getDescription());
        items[0].setShortName(gameItemIt->getShortName());
        items[0].setPrice(gameItemIt->getPrice());
        missingDigits[1] = (gameItemIt->getPrice() / 10 % 10);
        setSP1 = true;
    } // end if
    } // end while
//    cout << endl << "set first";
//    cout << endl << endl;
//    items[0].showPrize();
//    cout << endl << "price = " << items[0].getPrice();
//    cout << endl << "missing digit = " << missingDigits[1];

    /// Second small prize
    bool setSP2 = false;
    while (!setSP2){
    second = first;
    while (second == first)
        second = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    if ( ((gameItemIt->getPrice() / 10 % 10) != missingDigits[0]) && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[1]) ){
        items[1].setDescription(gameItemIt->getDescription());
        items[1].setShortName(gameItemIt->getShortName());
        items[1].setPrice(gameItemIt->getPrice());
        missingDigits[2] = (gameItemIt->getPrice() / 10 % 10);
        setSP2 = true;
    } // end if
    } // end while
   // cout << endl << "set second";
//    cout << endl << endl;
//    items[1].showPrize();
//    cout << endl << "price = " << items[1].getPrice();
//    cout << endl << "missing digit = " << missingDigits[2];

    /// Third small prize
    bool setSP3 = false;
    while (!setSP3){
    third = first;
    while ( (third == first) || (third == second) )
        third = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    if ( ((gameItemIt->getPrice() / 10 % 10) != missingDigits[0]) && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[1])
          && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[2]) ){
        items[2].setDescription(gameItemIt->getDescription());
        items[2].setShortName(gameItemIt->getShortName());
        items[2].setPrice(gameItemIt->getPrice());
        missingDigits[3] = (gameItemIt->getPrice() / 10 % 10);
        setSP3 = true;
    } // end if
    } // end while
    //cout << endl << "set third";
//    cout << endl << endl;
//    items[2].showPrize();
//    cout << endl << "price = " << items[2].getPrice();
//    cout << endl << "missing digit = " << missingDigits[3];

    /// Fourth small prize
    bool setSP4 = false;
    while (!setSP4){
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    if ( ((gameItemIt->getPrice() / 10 % 10) != missingDigits[0]) && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[1])
          && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[2]) && ((gameItemIt->getPrice() / 10 % 10) != missingDigits[3]) ){
        items[3].setDescription(gameItemIt->getDescription());
        items[3].setShortName(gameItemIt->getShortName());
        items[3].setPrice(gameItemIt->getPrice());
        missingDigits[4] = (gameItemIt->getPrice() / 10 % 10);
        setSP4 = true;
    } // end if
    } // end while
    //cout << endl << "set fourth";
//    cout << endl << endl;
//    items[3].showPrize();
//    cout << endl << "price = " << items[3].getPrice();
//    cout << endl << "missing digit = " << missingDigits[4];

    int rightOrder[5];
    for (int r = 0; r < 5; r++)
        rightOrder[r] = missingDigits[r];

    int playerOrder[5];
    for (int r = 0; r < 5; r++)
        playerOrder[r] = 10;

    sortStrikesNos(missingDigits);
    bool used[5];
    bool priceFilled[5];

    for (int u = 0; u < 5; u++){
        used[u] = false;
        priceFilled[u] = false;
        }

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();
    cout << endl;
    cout << endl << "1. ";
    items[0].showPrize();
    cout << endl << "2. ";
    items[1].showPrize();
    cout << endl << "3. ";
    items[2].showPrize();
    cout << endl << "4. ";
    items[3].showPrize();
    cout << endl;

    if (mds){
    cout << endl;
    cout << endl << "This is the Million Dollar Game!";
    cout << endl << "Get all 5 prices right on the first try,";
    cout << endl << "and you win $1,000,000!";
    cout << endl << endl;
    }

    bool filledAll = false;

    while (!filledAll){
    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl;
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl;
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl;
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl;
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl;
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl;
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl;
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl;
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    cout << endl << endl << "Digits: ";
    for (int d = 0; d < 5; d++){
        if (used[d])
            cout << "* ";
        else
            cout << missingDigits[d] << " ";
    }

    int choice = 0;
    while ( (choice != missingDigits[0]) && (choice != missingDigits[1]) && (choice != missingDigits[2]) &&
           (choice != missingDigits[3]) && (choice != missingDigits[4]) ){
        cout << endl << "Which digit do you want to pick?: ";
            cin >> choice;
        if ( (choice == missingDigits[0]) && used[0]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[1]) && used[1]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[2]) && used[2]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[3]) && used[3]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[4]) && used[4]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
    } // end while loop for digit choice

    if (choice == missingDigits[0])
        used[0] = true;
    else if (choice == missingDigits[1])
        used[1] = true;
    else if (choice == missingDigits[2])
        used[2] = true;
    else if (choice == missingDigits[3])
        used[3] = true;
    else
        used[4] = true;

    /// Item choice begins below

    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    int itemChoice = 0;
    while ( (itemChoice < 1) || (itemChoice > 5) ){
        cout << endl << "Which item's price does the " << choice << " belong in?: ";
            cin >> itemChoice;
        if (priceFilled[itemChoice-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            itemChoice = 0;
        }
    } // end while loop

    playerOrder[itemChoice-1] = choice;
    priceFilled[itemChoice-1] = true;

    if (priceFilled[0] && priceFilled[1] && priceFilled[2] && priceFilled[3] && priceFilled[4])
        filledAll = true;
    } // end while loop

    cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];
    cout << endl << "2. ";
    items[0].showShortName();
    cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    cout << endl << "3. ";
    items[1].showShortName();
    cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    cout << endl << "4. ";
    items[2].showShortName();
    cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    cout << endl << "5. ";
    items[3].showShortName();
    cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);

    int hasRightFirst = 0;
    cout << endl << "Let's see how many you have right.";
    cout << endl;
    system("pause");
    for (int h = 0; h < 5; h++){
        if (playerOrder[h] == rightOrder[h])
            hasRightFirst += 1;
    }
    if (hasRightFirst == 5){
        if (!mds)
            cout << endl << "You have all 5 right! \nCongratulations, you win!";
        else
            cout << endl << "You have all 5 right! \nYOU WON THE CAR AND $1,000,000!";
    }
    else if (hasRightFirst == 0){
        for (int w = 0; w < 5; w++){
            playerOrder[w] = 10;
            used[w] = false;
            priceFilled[w] = false;
        }
        filledAll = false;
        cout << endl << "You have 0 right. You need to change them around again!";

    while (!filledAll){
    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl;
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl;
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl;
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl;
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl;
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl;
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl;
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl;
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    cout << endl << endl << "Digits: ";
    for (int d = 0; d < 5; d++){
        if (used[d])
            cout << "* ";
        else
            cout << missingDigits[d] << " ";
    }

    int choice = 0;
    while ( (choice != missingDigits[0]) && (choice != missingDigits[1]) && (choice != missingDigits[2]) &&
           (choice != missingDigits[3]) && (choice != missingDigits[4]) ){
        cout << endl << "Which digit do you want to pick?: ";
            cin >> choice;
        if ( (choice == missingDigits[0]) && used[0]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[1]) && used[1]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[2]) && used[2]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[3]) && used[3]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[4]) && used[4]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
    } // end while loop for digit choice

    if (choice == missingDigits[0])
        used[0] = true;
    else if (choice == missingDigits[1])
        used[1] = true;
    else if (choice == missingDigits[2])
        used[2] = true;
    else if (choice == missingDigits[3])
        used[3] = true;
    else
        used[4] = true;

    /// Item choice begins below

    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    int itemChoice = 0;
    while ( (itemChoice < 1) || (itemChoice > 5) ){
        cout << endl << "Which item's price does the " << choice << " belong in?: ";
            cin >> itemChoice;
        if (priceFilled[itemChoice-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            itemChoice = 0;
        }
    } // end while loop

    playerOrder[itemChoice-1] = choice;
    priceFilled[itemChoice-1] = true;

    if (priceFilled[0] && priceFilled[1] && priceFilled[2] && priceFilled[3] && priceFilled[4])
        filledAll = true;
    } // end while loop

    cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];
    cout << endl << "2. ";
    items[0].showShortName();
    cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    cout << endl << "3. ";
    items[1].showShortName();
    cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    cout << endl << "4. ";
    items[2].showShortName();
    cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    cout << endl << "5. ";
    items[3].showShortName();
    cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    int hasRightSecond = 0;

    cout << endl << "Let's see how many you have right now...";
    cout << endl;
    system("pause");
    for (int h = 0; h < 5; h++){
        if (playerOrder[h] == rightOrder[h])
            hasRightSecond += 1;
    }
    if (hasRightSecond == 5)
        cout << endl << "You have all 5 right! \nCongratulations, you win!";
    else if (hasRightSecond == 0)
        cout << endl << "You still have 0 right... \nSorry, you lose.";
    else{
        cout << endl << "You have " << hasRightSecond << " right this time. \nLet's see which ones are right.";
        cout << endl;
        system("pause");
        for (int v = 4; v > 0; v--){
        if (playerOrder[v] == rightOrder[v]){
            cout << endl << "You won the ";
            items[v-1].showShortName();
            }
        } // end for loop revealing small prizes
        if (playerOrder[0] == rightOrder[0])
            cout << endl << "You won the car! \nCongratulations, you win!";
    } // else if player has 1 to 3 items right on the second try

    } // end if player has none right
    else{
        char toDo = '!';
        cout << endl << "You have " << hasRightFirst << " right.";
        while ( (toDo != 'Y') && (toDo != 'y') && (toDo != 'N') && (toDo != 'n') ){
        cout << endl << "Do you want to \n- keep the prices as they are (Y) or \n- switch them around (N)?: ";
        cin >> toDo;
        }
        if ( (toDo == 'Y') || (toDo == 'y') ){
        cout << endl << "Let's see which prices you have right.";
        cout << endl;
        system("pause");
        for (int v = 4; v > 0; v--){
        if (playerOrder[v] == rightOrder[v]){
            cout << endl << "You won the ";
            items[v-1].showShortName();
            }
        } // end for loop revealing small prizes
        if (playerOrder[0] == rightOrder[0])
            cout << endl << "You won the car! \nCongratulations, you win!";
        } // end if player keeps the prices as they are
        else{
        for (int w = 0; w < 5; w++){
            playerOrder[w] = 10;
            used[w] = false;
            priceFilled[w] = false;
        }
        filledAll = false;
        cout << endl << "All right, then. Let's switcheroo!";

        while (!filledAll){
    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl;
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl;
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl;
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl;
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl;
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl;
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl;
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl;
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    cout << endl << endl << "Digits: ";
    for (int d = 0; d < 5; d++){
        if (used[d])
            cout << "* ";
        else
            cout << missingDigits[d] << " ";
    }

    int choice = 0;
    while ( (choice != missingDigits[0]) && (choice != missingDigits[1]) && (choice != missingDigits[2]) &&
           (choice != missingDigits[3]) && (choice != missingDigits[4]) ){
        cout << endl << "Which digit do you want to pick?: ";
            cin >> choice;
        if ( (choice == missingDigits[0]) && used[0]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[1]) && used[1]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[2]) && used[2]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[3]) && used[3]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
        else if ( (choice == missingDigits[4]) && used[4]){
            cout << endl << "You've already chosen this digit. Please pick another one.";
            choice = 10;
            }
    } // end while loop for digit choice

    if (choice == missingDigits[0])
        used[0] = true;
    else if (choice == missingDigits[1])
        used[1] = true;
    else if (choice == missingDigits[2])
        used[2] = true;
    else if (choice == missingDigits[3])
        used[3] = true;
    else
        used[4] = true;

    /// Item choice begins below

    /// Car
    if (playerOrder[0] == 10)
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << "*" << carDigits[4];
    else
        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];

    /// Prize #1
    if (playerOrder[1] == 10){
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << "*" << (items[0].getPrice() % 10);
    }
    else{
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
    }

    /// Prize #2
    if (playerOrder[2] == 10){
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << "*" << (items[1].getPrice() % 10);
    }
    else{
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
    }

    /// Prize #3
    if (playerOrder[3] == 10){
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << "*" << (items[2].getPrice() % 10);
    }
    else{
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
    }

    /// Prize #4
    if (playerOrder[4] == 10){
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << "*" << (items[3].getPrice() % 10);
    }
    else{
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);
    }

    int itemChoice = 0;
    while ( (itemChoice < 1) || (itemChoice > 5) ){
        cout << endl << "Which item's price does the " << choice << " belong in?: ";
            cin >> itemChoice;
        if (priceFilled[itemChoice-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            itemChoice = 0;
        }
    } // end while loop

    playerOrder[itemChoice-1] = choice;
    priceFilled[itemChoice-1] = true;

    if (priceFilled[0] && priceFilled[1] && priceFilled[2] && priceFilled[3] && priceFilled[4])
        filledAll = true;
    } // end while loop

        cout << endl << "1. CAR - $" << carDigits[0] << carDigits[1] << carDigits[2] << playerOrder[0] << carDigits[4];
        cout << endl << "2. ";
        items[0].showShortName();
        cout << " - $" << playerOrder[1] << (items[0].getPrice() % 10);
        cout << endl << "3. ";
        items[1].showShortName();
        cout << " - $" << playerOrder[2] << (items[1].getPrice() % 10);
        cout << endl << "4. ";
        items[2].showShortName();
        cout << " - $" << playerOrder[3] << (items[2].getPrice() % 10);
        cout << endl << "5. ";
        items[3].showShortName();
        cout << " - $" << playerOrder[4] << (items[3].getPrice() % 10);

        int hasRightSecond = 0;
        cout << endl << "Let's see how many you have right now...";
        cout << endl;
        system("pause");
        for (int h = 0; h < 5; h++){
            if (playerOrder[h] == rightOrder[h])
                hasRightSecond += 1;
        }
        if (hasRightSecond == 5)
            cout << endl << "You have all 5 right! \nCongratulations, you win!";
        else if (hasRightSecond == 0)
            cout << endl << "You have 0 right... \nSorry, you lose.";
        else{
            cout << endl << "You have " << hasRightSecond << " this time. Let's see which ones are right.";
            cout << endl;
            system("pause");
            for (int v = 4; v > 0; v--){
            if (playerOrder[v] == rightOrder[v]){
                cout << endl << "You won the ";
                items[v-1].showShortName();
                }
            } // end for loop revealing small prizes
            if (playerOrder[0] == rightOrder[0])
                cout << endl << "You won the car! \nCongratulations, you win!";
        } // end if player has 1 to 3 prices right on the second try

        } // end if player changes the prices and has at least one right
    } // end if player has 1 to 3 prices right on the first try

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Telephone Game
void playTelephoneGame()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<grocery> ggItems;
    list<grocery>::iterator ggItemIt;
    string t_ggDescription;
    string t_ggShortName;
    double t_ggPrice;
    grocery * ggptr;

    list<large> gameLarges;
    list<large>::iterator gameLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    srand(time(0));

    int i = 0; // Cars
    int j = 0; // Grocery items
    int k = 0; // Other prizes

    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && compatibleForTelephoneGame(t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    bool useLargePrizes = false;

    /// Pick a car
    int randomPrize = rand() % i;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (int z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    int carPrice = prizeCar.getPrice();
    int firstDigit = carPrice / 10000 % 10;
    int secondDigit = carPrice / 1000 % 10;

    if (secondDigit >= 5)
        useLargePrizes = true;

    /// Pick grocery items
    inFile.open("./prizes/" + grocInput);
    while (inFile){
        ggptr = new grocery;
        if ( (inFile >> t_ggDescription >> t_ggShortName >> t_ggPrice) && (t_ggPrice < 9.5) )
        {
            ggptr->setDescription(t_ggDescription);
            ggptr->setShortName(t_ggShortName);
            ggptr->setPrice(t_ggPrice);
            ggItems.push_back(*ggptr);
            j++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Pick other items. Medium prizes and large prizes have the same parameters, so it doesn't matter if
    /// medium prizes are technically considered "large" by the game.

    // large prizes
    if (secondDigit >= 5){
    inFile.open("./prizes/" + largInput);
    while (inFile){
        lptr = new large;
        if (inFile >> l_Description >> l_ShortName >> l_Price){
            lptr->setDescription(l_Description);
            lptr->setShortName(l_ShortName);
            lptr->setPrice(l_Price);
            gameLarges.push_back(*lptr);
            k++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();
    }
    // medium prizes
    else{
    inFile.open("./prizes/" + medInput);
    while (inFile){
        lptr = new large;
        if ( (inFile >> l_Description >> l_ShortName >> l_Price) && (l_Price > 999) ){
            lptr->setDescription(l_Description);
            lptr->setShortName(l_ShortName);
            lptr->setPrice(l_Price);
            gameLarges.push_back(*lptr);
            k++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();
    }

    large prize1;
    large prize2;

    int first_p;
    int second_p;

    /// Pick which prizes to use
    bool gotFirst = false;
    while (!gotFirst){
    first_p = rand() % k;
    gameLargeIt = gameLarges.begin();
    for (int z = 0; z < first_p; z++)
        gameLargeIt++;
    // ensure that the randomly generated price doesn't somehow equal the car's price
    if (gameLargeIt->getPrice() != ( carPrice - (firstDigit*10000) ) ){
        prize1.setDescription(gameLargeIt->getDescription());
        prize1.setShortName(gameLargeIt->getShortName());
        prize1.setPrice(gameLargeIt->getPrice());
        gotFirst = true;
    }
    } // end while loop

    bool gotSecond = false;
    while (!gotSecond){
    second_p = first_p;
    while (second_p == first_p)
        second_p = rand() % k;
    gameLargeIt = gameLarges.begin();
    for (int z = 0; z < second_p; z++)
        gameLargeIt++;
    // ensure that the randomly generated price doesn't somehow equal the car's price
    if (gameLargeIt->getPrice() != ( carPrice - (firstDigit*10000) ) ){
        prize2.setDescription(gameLargeIt->getDescription());
        prize2.setShortName(gameLargeIt->getShortName());
        prize2.setPrice(gameLargeIt->getPrice());
        gotSecond = true;
    }
    } // end while loop

    cout << "TELEPHONE GAME" << endl;

    cout << endl << "1. ";
    prize1.showPrize();
    cout << endl << "2. ";
    prize2.showPrize();
    cout << endl << "3. ";
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    grocery temps[4];
    int ids[4] = {0, 1, 2, 3};

    int first_g;
    int second_g;
    int third_g;
    int fourth_g;

    bool setFirstTwo = false;
    while (!setFirstTwo){
    first_g = rand() % j;
    second_g = first_g;
    while (second_g == first_g)
        second_g = rand() % j;
    ggItemIt = ggItems.begin();
    for (int z = 0; z < first_g; z++)
        ggItemIt++;
    temps[0].setDescription(ggItemIt->getDescription());
    temps[0].setShortName(ggItemIt->getShortName());
    temps[0].setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z = 0; z < second_g; z++)
        ggItemIt++;
    temps[1].setDescription(ggItemIt->getDescription());
    temps[1].setShortName(ggItemIt->getShortName());
    temps[1].setPrice(ggItemIt->getPrice());

    if ( (temps[0].getPrice() + temps[1].getPrice()) < 9 )
        setFirstTwo = true;
    } // end while loop

    bool setLastTwo = false;
    while (!setLastTwo){
    third_g = first_g;
    while ( (third_g == first_g) || (third_g == second_g) )
        third_g = rand() % j;
    fourth_g = first_g;
    while ( (fourth_g == first_g) || (fourth_g == second_g) || (fourth_g == third_g) )
        fourth_g = rand() % j;

    ggItemIt = ggItems.begin();
    for (int z = 0; z < third_g; z++)
        ggItemIt++;
    temps[2].setDescription(ggItemIt->getDescription());
    temps[2].setShortName(ggItemIt->getShortName());
    temps[2].setPrice(ggItemIt->getPrice());

    ggItemIt = ggItems.begin();
    for (int z = 0; z < fourth_g; z++)
        ggItemIt++;
    temps[3].setDescription(ggItemIt->getDescription());
    temps[3].setShortName(ggItemIt->getShortName());
    temps[3].setPrice(ggItemIt->getPrice());

    if ( (temps[2].getPrice() + temps[3].getPrice()) > 9 )
        setLastTwo = true;

    } // end while loop

    //cout << endl << "price = $" << carPrice;
    //cout << endl << "second digit = " << secondDigit;

    cout << endl;
    double money = 10;
    random_shuffle(&ids[0], &ids[4]);

    grocery items[4];
    for (int s = 0; s < 4; s++){
    items[ids[s]].setDescription(temps[s].getDescription());
    items[ids[s]].setShortName(temps[s].getShortName());
    items[ids[s]].setPrice(temps[s].getPrice());
    }

    bool chosen[4];
    for (int c = 0; c < 4; c++)
        chosen[c] = false;

    int itemsPicked = 0;

    while (itemsPicked < 2){
        for (int t = 0; t < 4; t++){
            cout << endl << t+1 << ". ";
            items[t].showPrize();
            if (chosen[t]){
                cout << " - ";
                items[t].showARP();
            }
        }
        cout << endl << fixed << setprecision(2) << "Money: $" << money;
        int choice = 0;
        while ( (choice < 1) || (choice > 4) ){
            cout << endl << "Which item do you want to pick?: ";
                cin >> choice;
            if (chosen[choice-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                choice = 0;
            }
        }

        cout << endl << "The actual retail price of the ";
        items[choice-1].showShortName();
        cout << " is ";
        items[choice-1].showARP();
        chosen[choice-1] = true;
        money -= items[choice-1].getPrice();
        itemsPicked += 1;

    } // end while loop

    int location = (rand() % 3) + 1;
    int otherLoc = rand() % 2;
    cout << endl;
    if (money < 1)
        cout << endl << "You don't have $1 left over. Sorry, you lose.";
    else{
        cout << endl << fixed << setprecision(2) << "Money: $" << money;
        cout << endl << "You have at least $1, so you can use the pay phone.";

    if ( (location == 1) && (otherLoc == 0) ){
        cout << endl << "1. " << carPrice;
        cout << endl << "2. " << firstDigit << prize1.getPrice();
        cout << endl << "3. " << firstDigit << prize2.getPrice();
    }
    else if ( (location == 1) && (otherLoc == 1) ){
        cout << endl << "1. " << carPrice;
        cout << endl << "2. " << firstDigit << prize2.getPrice();
        cout << endl << "3. " << firstDigit << prize1.getPrice();
    }
    else if ( (location == 2) && (otherLoc == 0) ){
        cout << endl << "1. " << firstDigit << prize1.getPrice();
        cout << endl << "2. " << carPrice;
        cout << endl << "3. " << firstDigit << prize2.getPrice();
    }
    else if ( (location == 2) && (otherLoc == 1) ){
        cout << endl << "1. " << firstDigit << prize2.getPrice();
        cout << endl << "2. " << carPrice;
        cout << endl << "3. " << firstDigit << prize1.getPrice();
    }
    else if ( (location == 3) && (otherLoc == 0) ){
        cout << endl << "1. " << firstDigit << prize1.getPrice();
        cout << endl << "2. " << firstDigit << prize2.getPrice();
        cout << endl << "3. " << carPrice;
    }
    else{
        cout << endl << "1. " << firstDigit << prize2.getPrice();
        cout << endl << "2. " << firstDigit << prize1.getPrice();
        cout << endl << "3. " << carPrice;
    }

    int dial = 0;
    while ( (dial < 1) || (dial > 3) ){
        cout << endl << "Which number (1-3) do you want to dial for the car?: ";
        cin >> dial;
    }

    cout << endl << "*ring* *ring* *ring*";
    cout << endl;
    system("pause");

    if (dial == location)
        cout << endl << "Congratulations, you win!";
    else if ( (location == 1) && (otherLoc == 0) && (dial == 2) ){
        cout << endl << "You won the ";
        prize1.showShortName();
    }
    else if ( (location == 1) && (otherLoc == 0) && (dial == 3) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else if ( (location == 1) && (otherLoc == 1) && (dial == 2) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else if ( (location == 1) && (otherLoc == 1) && (dial == 3) ){
        cout << endl << "You won the ";
        prize1.showShortName();
    }
    else if ( (location == 2) && (otherLoc == 0) && (dial == 1) ){
        cout << endl << "You won the ";
        prize1.showShortName();
    }
    else if ( (location == 2) && (otherLoc == 0) && (dial == 3) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else if ( (location == 2) && (otherLoc == 1) && (dial == 1) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else if ( (location == 2) && (otherLoc == 1) && (dial == 3) ){
        cout << endl << "You won the ";
        prize1.showShortName();
    }
    else if ( (location == 3) && (otherLoc == 0) && (dial == 1) ){
        cout << endl << "You won the ";
        prize1.showShortName();
    }
    else if ( (location == 3) && (otherLoc == 0) && (dial == 2) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else if ( (location == 3) && (otherLoc == 1) && (dial == 1) ){
        cout << endl << "You won the ";
        prize2.showShortName();
    }
    else{
        cout << endl << "You won the ";
        prize1.showShortName();
    }

    if (dial != location)
        cout << endl << "The price of the car was $" << carPrice << ".";

    } // else if player can use the pay phone

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Temptation
void playTemptation()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string t_Model;
    string t_Options;
    int t_Price;
    car * cptr;

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * pptr;

    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("./prizes/" + medInput);
    while (inFile)
    {
    pptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (hasTwoDiffDigits(m_Price)) )
    {
        pptr->setDescription(m_Description);
        pptr->setShortName(m_ShortName);
        pptr->setPrice(m_Price);
        gameItems.push_back(*pptr);
        j++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "TEMPTATION" << endl;
    //cout << endl << "j = " << j;

    int carID = rand() % i;

    car prizeCar;

    gameCarIt = gameCars.begin();
    for (int z = 0; z < carID; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    cout << endl;
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

//    gameItemIt = gameItems.begin();
//    while (gameItemIt != gameItems.end()){
//        cout << endl << "$" << gameItemIt->getPrice();
//        gameItemIt++;
//    }

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    //cout << endl << "car price: $" << carPrice;
    //cout << endl << "digits = " << digits[0] << ", " << digits[1] << ", " << digits[2] << ", " << digits[3] << ", " << digits[4];

    /// One of the four digits will always be a fishbowl of cash.
    int fishbowlNo = rand() % 4;
    int fishbowlValue;
    //cout << endl << "fishbowl value = " << fishbowlNo;

    cout << endl;

    int itemID1;
    int itemID2;
    int itemID3;
    int itemID4;

    medium prizes[4];

    int digitChoices[5];
    digitChoices[0] = digits[0];

    cout << endl << "$" << digitChoices[0] << "****";

    /// Second digit
    bool setFirst = false;
    if (fishbowlNo == 0){
    int set1 = rand() % 2; // Determines whether the cash amount will be 3 digits or 4 digits
    int set2 = rand() % 2; // Determines where in the amount the correct digit will be
    int wrong1 = digits[1];
    while (wrong1 == digits[1])
        wrong1 = (rand() % 10);
    if (set1 == 0){
        if (digits[1] > wrong1)
            fishbowlValue = digits[1]*100 + wrong1*10 + wrong1;
        else
            fishbowlValue = wrong1*100 + digits[1]*10 + digits[1];
    } // fishbowl of cash has one digit
    else{
        if (digits[1] > 5)
            wrong1 = (rand() % 2) + 1;
        if ( (digits[1] < wrong1) && (set2 == 0) && (digits[1] != 0) )
            fishbowlValue = digits[1]*1000 + wrong1*100 + digits[1]*10 + wrong1;
        else if ( (digits[1] < wrong1) && (set2 == 1) && (digits[1] != 0) )
            fishbowlValue = digits[1]*1000 + wrong1*100 + wrong1*10 + digits[1];
        else if (set2 == 0)
            fishbowlValue = wrong1*1000 + digits[1]*100 + wrong1*10 + digits[1];
        else
            fishbowlValue = wrong1*1000 + digits[1]*100 + digits[1]*10 + wrong1;
    } // fishbowl of cash has 2 digits

    prizes[0].setDescription("Fishbowl of cash");
    prizes[0].setShortName("CASH");
    prizes[0].setPrice(fishbowlValue);
    }
    else{
    while (!setFirst){
    int itemID1 = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < itemID1; z++)
        gameItemIt++;
    if (isInPrice(digits[1], gameItemIt->getPrice())){
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());
    setFirst = true;
    }
    } // end while loop setting the item
    } // end else if this item is not the fishbowl of cash

    cout << endl << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "$" << prizes[0].getPrice();
    int result1 = obtainDigits(prizes[0].getPrice());
    int first1 = result1 / 10 % 10;
    int second1 = result1 % 10;
    //cout << endl << "result = " << result1;
    int entry1 = 10;
    while ( (entry1 != first1) && (entry1 != second1) ){
        cout << endl << "What digit from this prize is the second digit in the car?: ";
        cin >> entry1;
    }
    digitChoices[1] = entry1;

    cout << endl << "$" << digitChoices[0] << digitChoices[1] << "***";

    /// Third digit
    bool setSecond = false;
    if (fishbowlNo == 1){
    int setb1 = rand() % 2; // Determines whether the cash amount will be 3 digits or 4 digits
    int setb2 = rand() % 2; // Determines where in the amount the correct digit will be
    int wrong2 = digits[2];
    while (wrong2 == digits[2])
        wrong2 = (rand() % 10);
    if (setb1 == 0){
        if (digits[2] > wrong2)
            fishbowlValue = digits[2]*100 + wrong2*10 + wrong2;
        else
            fishbowlValue = wrong2*100 + digits[2]*10 + digits[2];
    } // fishbowl of cash has one digit
    else{
        if (digits[2] > 5)
            wrong2 = (rand() % 2) + 1;
        if ( (digits[2] < wrong2) && (setb2 == 0) && (digits[2] != 0) )
            fishbowlValue = digits[2]*1000 + wrong2*100 + digits[2]*10 + wrong2;
        else if ( (digits[2] < wrong2) && (setb2 == 1) && (digits[2] != 0) )
            fishbowlValue = digits[2]*1000 + wrong2*100 + wrong2*10 + digits[2];
        else if (setb2 == 0)
            fishbowlValue = wrong2*1000 + digits[2]*100 + wrong2*10 + digits[2];
        else
            fishbowlValue = wrong2*1000 + digits[2]*100 + digits[2]*10 + wrong2;
    } // fishbowl of cash has 2 digits

    prizes[1].setDescription("Fishbowl of cash");
    prizes[1].setShortName("CASH");
    prizes[1].setPrice(fishbowlValue);
    }
    else{
    while (!setSecond){
    int itemID2 = itemID1;
    while (itemID2 == itemID1)
        itemID2 = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < itemID2; z++)
        gameItemIt++;
    if ( (isInPrice(digits[2], gameItemIt->getPrice())) && ( gameItemIt->getDescription() != prizes[0].getDescription() ) ){
    prizes[1].setDescription(gameItemIt->getDescription());
    prizes[1].setShortName(gameItemIt->getShortName());
    prizes[1].setPrice(gameItemIt->getPrice());
    setSecond = true;
    }
    } // end while loop setting the item
    } // end else if this item is not the fishbowl of cash

    cout << endl << endl << "2. ";
    prizes[1].showPrize();
    cout << endl << "$" << prizes[1].getPrice();
    int result2 = obtainDigits(prizes[1].getPrice());
    int first2 = result2 / 10 % 10;
    int second2 = result2 % 10;
    //cout << endl << "result = " << result2;
    int entry2 = 10;
    while ( (entry2 != first2) && (entry2 != second2) ){
        cout << endl << "What digit from this prize is the third digit in the car?: ";
        cin >> entry2;
    }
    digitChoices[2] = entry2;

    cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << "**";

    /// Fourth digit
    bool setThird = false;
    if (fishbowlNo == 2){
    int setc1 = rand() % 2; // Determines whether the cash amount will be 3 digits or 4 digits
    int setc2 = rand() % 2; // Determines where in the amount the correct digit will be
    int wrong3 = digits[3];
    while (wrong3 == digits[3])
        wrong3 = (rand() % 10);
    if (setc1 == 0){
        if (digits[3] > wrong3)
            fishbowlValue = digits[3]*100 + wrong3*10 + wrong3;
        else
            fishbowlValue = wrong3*100 + digits[3]*10 + digits[3];
    } // fishbowl of cash has one digit
    else{
        if (digits[3] > 5)
            wrong3 = (rand() % 2) + 1;
        if ( (digits[3] < wrong3) && (setc2 == 0) && (digits[3] != 0) )
            fishbowlValue = digits[3]*1000 + wrong3*100 + digits[3]*10 + wrong3;
        else if ( (digits[3] < wrong3) && (setc2 == 1) && (digits[3] != 0) )
            fishbowlValue = digits[3]*1000 + wrong3*100 + wrong3*10 + digits[3];
        else if (setc2 == 0)
            fishbowlValue = wrong3*1000 + digits[3]*100 + wrong3*10 + digits[3];
        else
            fishbowlValue = wrong3*1000 + digits[3]*100 + digits[3]*10 + wrong3;
    } // fishbowl of cash has 2 digits

    prizes[2].setDescription("Fishbowl of cash");
    prizes[2].setShortName("CASH");
    prizes[2].setPrice(fishbowlValue);
    }
    else{
    while (!setThird){
    int itemID3 = itemID1;
    while ( (itemID3 == itemID1) || (itemID3 == itemID2) )
        itemID3 = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < itemID3; z++)
        gameItemIt++;
    if ( (isInPrice(digits[3], gameItemIt->getPrice())) && ( gameItemIt->getDescription() != prizes[0].getDescription() ) && ( gameItemIt->getDescription() != prizes[1].getDescription() ) ){
    prizes[2].setDescription(gameItemIt->getDescription());
    prizes[2].setShortName(gameItemIt->getShortName());
    prizes[2].setPrice(gameItemIt->getPrice());
    setThird = true;
    } // end if
    } // end while
    } // end else

    cout << endl << endl << "3. ";
    prizes[2].showPrize();
    cout << endl << "$" << prizes[2].getPrice();
    int result3 = obtainDigits(prizes[2].getPrice());
    int first3 = result3 / 10 % 10;
    int second3 = result3 % 10;
    //cout << endl << "result = " << result3;
    int entry3 = 10;
    while ( (entry3 != first3) && (entry3 != second3) ){
        cout << endl << "What digit from this prize is the fourth digit in the car?: ";
        cin >> entry3;
    }
    digitChoices[3] = entry3;

    cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << "*";

    /// Fifth digit
    bool setFourth = false;
    if (fishbowlNo == 3){
    int setd1 = rand() % 2; // Determines whether the cash amount will be 3 digits or 4 digits
    int setd2 = rand() % 2; // Determines where in the amount the correct digit will be
    int wrong4 = digits[4];
    while (wrong4 == digits[4])
        wrong4 = (rand() % 10);
    if (setd1 == 0){
        if (digits[4] > wrong4)
            fishbowlValue = digits[4]*100 + wrong4*10 + wrong4;
        else
            fishbowlValue = wrong4*100 + digits[4]*10 + digits[4];
    } // fishbowl of cash has one digit
    else{
        if (digits[4] > 5)
            wrong4 = (rand() % 2) + 1;
        if ( (digits[4] < wrong4) && (setd2 == 0) && (digits[4] != 0) )
            fishbowlValue = digits[4]*1000 + wrong4*100 + digits[4]*10 + wrong4;
        else if ( (digits[4] < wrong4) && (setd2 == 1) && (digits[4] != 0) )
            fishbowlValue = digits[4]*1000 + wrong4*100 + wrong4*10 + digits[4];
        else if (setd2 == 0)
            fishbowlValue = wrong4*1000 + digits[4]*100 + wrong4*10 + digits[4];
        else
            fishbowlValue = wrong4*1000 + digits[4]*100 + digits[4]*10 + wrong4;
    } // fishbowl of cash has 2 digits

    prizes[3].setDescription("Fishbowl of cash");
    prizes[3].setShortName("CASH");
    prizes[3].setPrice(fishbowlValue);
    }
    else{
    while (!setFourth){
    int itemID4 = itemID1;
    while ( (itemID4 == itemID1) || (itemID4 == itemID2) || (itemID4 == itemID3) )
        itemID4 = rand() % j;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < itemID4; z++)
        gameItemIt++;
    if ( (isInPrice(digits[4], gameItemIt->getPrice())) && ( gameItemIt->getDescription() != prizes[0].getDescription() ) && ( gameItemIt->getDescription() != prizes[1].getDescription() ) &&
        ( gameItemIt->getDescription() != prizes[2].getDescription() ) ){
    prizes[3].setDescription(gameItemIt->getDescription());
    prizes[3].setShortName(gameItemIt->getShortName());
    prizes[3].setPrice(gameItemIt->getPrice());
    setFourth = true;
    } // end if
    } // end while
    } // end else

    cout << endl << endl << "4. ";
    prizes[3].showPrize();
    cout << endl << "$" << prizes[3].getPrice();
    int result4 = obtainDigits(prizes[3].getPrice());
    int first4 = result4 / 10 % 10;
    int second4 = result4 % 10;
    //cout << endl << "result = " << result4;
    int entry4 = 10;
    while ( (entry4 != first4) && (entry4 != second4) ){
        cout << endl << "What digit from this prize is the fifth digit in the car?: ";
        cin >> entry4;
    }
    digitChoices[4] = entry4;

    cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];

    char changeDigits = '!';
    while ( (changeDigits != 'Y') && (changeDigits != 'y') && (changeDigits != 'N') && (changeDigits != 'n') ){
        cout << endl << "Do you want to change any digits in the price (Y/N)?: ";
        cin >> changeDigits;
    }
    if ( (changeDigits == 'Y') || (changeDigits == 'y' ) ){

        char change1 = '!';
        char change2 = '!';
        char change3 = '!';
        char change4 = '!';

        /// Second digit
        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        while ( (change1 != 'Y') && (change1 != 'y') && (change1 != 'N') && (change1 != 'n') ){
        if (digitChoices[1] == first1)
            cout << endl << "Do you want to change the " << digitChoices[1] << " in digit #2 to " << second1 << " (Y/N)?: ";
        else
            cout << endl << "Do you want to change the " << digitChoices[1] << " in digit #2 to " << first1 << " (Y/N)?: ";
        cin >> change1;
        }
        if ( ((change1 == 'Y') || (change1 == 'y')) && (digitChoices[1] == first1) )
            digitChoices[1] = second1;
        else if ( ((change1 == 'Y') || (change1 == 'y')) && (digitChoices[1] == second1) )
            digitChoices[1] = first1;

        /// Third digit
        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        while ( (change2 != 'Y') && (change2 != 'y') && (change2 != 'N') && (change2 != 'n') ){
        if (digitChoices[2] == first2)
            cout << endl << "Do you want to change the " << digitChoices[2] << " in digit #3 to " << second2 << " (Y/N)?: ";
        else
            cout << endl << "Do you want to change the " << digitChoices[2] << " in digit #3 to " << first2 << " (Y/N)?: ";
        cin >> change2;
        }
        if ( ((change2 == 'Y') || (change2 == 'y')) && (digitChoices[2] == first2) )
            digitChoices[2] = second2;
        else if ( ((change2 == 'Y') || (change2 == 'y')) && (digitChoices[2] == second2) )
            digitChoices[2] = first2;

        /// Fourth digit
        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        while ( (change3 != 'Y') && (change3 != 'y') && (change3 != 'N') && (change3 != 'n') ){
        if (digitChoices[3] == first3)
            cout << endl << "Do you want to change the " << digitChoices[3] << " in digit #4 to " << second3 << " (Y/N)?: ";
        else
            cout << endl << "Do you want to change the " << digitChoices[3] << " in digit #4 to " << first3 << " (Y/N)?: ";
        cin >> change3;
        }
        if ( ((change3 == 'Y') || (change3 == 'y')) && (digitChoices[3] == first3) )
            digitChoices[3] = second3;
        else if ( ((change3 == 'Y') || (change3 == 'y')) && (digitChoices[3] == second3) )
            digitChoices[3] = first3;

        /// Fifth digit
        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        while ( (change4 != 'Y') && (change4 != 'y') && (change4 != 'N') && (change4 != 'n') ){
        if (digitChoices[4] == first4)
            cout << endl << "Do you want to change the " << digitChoices[4] << " in digit #5 to " << second4 << " (Y/N)?: ";
        else
            cout << endl << "Do you want to change the " << digitChoices[4] << " in digit #5 to " << first4 << " (Y/N)?: ";
        cin >> change4;
        }
        if ( ((change4 == 'Y') || (change4 == 'y')) && (digitChoices[4] == first4) )
            digitChoices[4] = second4;
        else if ( ((change4 == 'Y') || (change4 == 'y')) && (digitChoices[4] == second4) )
            digitChoices[4] = first4;

    }

    cout << endl << "You have a price of $" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4] << ".";
    char bailChoice = '!';
    while ( (bailChoice != 'Y') && (bailChoice != 'y') && (bailChoice != 'N') && (bailChoice != 'n') ){
        cout << endl << "Do you want to keep the prizes (Y) or risk them for the car (N)?: ";
        cin >> bailChoice;
    }
    if ( (bailChoice == 'Y') || (bailChoice == 'y' ) )
        cout << endl << "You've chosen to keep the prizes. Thanks for playing!";
    else{
        cout << endl << "Let's reveal the price of the car.";
        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        cout << endl << "$" << digits[0] << "****";
        cout << endl;
        system("pause");

        cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
        cout << endl << "$" << digits[0] << digits[1] << "***";
        if (digits[1] != digitChoices[1])
            cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << "." << endl;
        else{
            cout << endl;
            system("pause");

            cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
            cout << endl << "$" << digits[0] << digits[1] << digits[2] << "**";

            if (digits[2] != digitChoices[2])
                cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << "." << endl;
            else{
                cout << endl;
                system("pause");

                cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
                cout << endl << "$" << digits[0] << digits[1] << digits[2] << digits[3] << "*";

                if (digits[3] != digitChoices[3])
                    cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << "." << endl;
                else{
                    cout << endl;
                    system("pause");

                    cout << endl << "$" << digitChoices[0] << digitChoices[1] << digitChoices[2] << digitChoices[3] << digitChoices[4];
                    cout << endl << "$" << digits[0] << digits[1] << digits[2] << digits[3] << digits[4];

                    if (digits[4] != digitChoices[4])
                        cout << endl << "Sorry, you lose. \nThe price of the car was $" << carPrice << "." << endl;
                    else
                        cout << endl << "Congratulations, you win!" << endl;

                } // end if player got fourth digit right

            } // end if player got third digit right

        } // end if player got second digit right
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Ten Chances
void playTenChances()
{
    /// car
    list<car> gameCars;
    list<car>::iterator gameCarIt;
    string c_Model;
    string c_Options;
    int c_Price;
    car * cptr;

    /// medium prize
    list<medium> gameMeds;
    list<medium>::iterator gameMedIt;
    string m_Description;
    string m_ShortName;
    int m_Price;
    medium * mptr;

    /// small prize
    list<small> gameSmalls;
    list<small>::iterator gameSmallsIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    srand(time(0));

    int cars = 0;
    int meds = 0;
    int smas = 0;

    ifstream inFile;

    /// Load the small prizes
    inFile.open("./prizes/" + smalInput);
    while (inFile)
    {
    sptr = new small;
    if ( (inFile >> s_Description >> s_ShortName >> s_Price) && (s_Price < 100) && (s_Price % 10 == 0) )
    {
        sptr->setDescription(s_Description);
        sptr->setShortName(s_ShortName);
        sptr->setPrice(s_Price);
        gameSmalls.push_back(*sptr);
        smas++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Load the medium prizes
    inFile.open("./prizes/" + medInput);
    while (inFile){
    mptr = new medium;
    if ( (inFile >> m_Description >> m_ShortName >> m_Price) && (m_Price < 1000) && (m_Price % 10 == 0) && (m_Price % 100 != 0) && (m_Price % 110 != 0) )
    {
        mptr->setDescription(m_Description);
        mptr->setShortName(m_ShortName);
        mptr->setPrice(m_Price);
        gameMeds.push_back(*mptr);
        meds++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Load the cars
    inFile.open("./prizes/" + carInput);
    while (inFile){
    cptr = new car;
    if ( (inFile >> c_Model >> c_Options >> c_Price) && (c_Price % 10 == 0) && noRepeatingDigits(c_Price) && (c_Price < maxCar) )
    {
        cptr->setModel(c_Model);
        cptr->setOptions(c_Options);
        cptr->setPrice(c_Price);
        gameCars.push_back(*cptr);
        cars++;
    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Pick a random small prize, medium prize, and car
    int smaID = rand() % smas;
    int medID = rand() % meds;
    int carID = rand() % cars;

    int z1 = 0; // small prize
    int z2 = 0; // medium prize
    int z3 = 0; // car

    small prizeSma;
    medium prizeMed;
    car prizeCar;

    /// Set the small prize.
    gameSmallsIt = gameSmalls.begin();
    for (z1 = 0; z1 < smaID; z1++)
        gameSmallsIt++;
    prizeSma.setDescription(gameSmallsIt->getDescription());
    prizeSma.setShortName(gameSmallsIt->getShortName());
    prizeSma.setPrice(gameSmallsIt->getPrice());

    /// Set the medium prize.
    gameMedIt = gameMeds.begin();
    for (z2 = 0; z2 < medID; z2++)
        gameMedIt++;
    prizeMed.setDescription(gameMedIt->getDescription());
    prizeMed.setShortName(gameMedIt->getShortName());
    prizeMed.setPrice(gameMedIt->getPrice());

    /// Finally, the car.
    gameCarIt = gameCars.begin();
    for (z3 = 0; z3 < carID; z3++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    cout << endl << "TEN CHANCES" << endl;

    cout << endl << "1. ";
    prizeSma.showPrize();
    cout << endl << "2. ";
    prizeMed.showPrize();
    cout << endl << "3. ";
    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int onChance = 1;
    bool wonSmall = false;
    bool wonMed = false;
    bool wonCar = false;

    int firstOrder = rand() % 6;
    int dummy = prizeSma.getPrice() / 10;
    int wrong = dummy;
    while (wrong == dummy)
        wrong = (rand() % 9) + 1;

    int medDigits[4];
    medDigits[0] = prizeMed.getPrice() / 100 % 10;
    medDigits[1] = prizeMed.getPrice() / 10 % 10;
    medDigits[2] = 0;
    medDigits[3] = 0;
    while ( (medDigits[3] == medDigits[0]) || (medDigits[3] == medDigits[1]) || (medDigits[3] == medDigits[2]) )
        medDigits[3] = (rand() % 9) + 1;
    random_shuffle(&medDigits[0], &medDigits[4]);

    int carDigits[5];
    carDigits[0] = prizeCar.getPrice() / 10000 % 10;
    carDigits[1] = prizeCar.getPrice() / 1000 % 10;
    carDigits[2] = prizeCar.getPrice() / 100 % 10;
    carDigits[3] = prizeCar.getPrice() / 10 % 10;
    carDigits[4] = 0;
    random_shuffle(&carDigits[0], &carDigits[5]);

    cout << endl;

    while ( (onChance <= 10) && (!wonCar) )
    {
        int inSmall = 0;
        int inMed = 0;
        int inCar = 0;
        cout << endl << "Chance #" << onChance;
        if (!wonSmall)
        {
            if (firstOrder == 0)
                cout << endl << dummy << ", 0, " << wrong;
            else if (firstOrder == 1)
                cout << endl << dummy << ", " << wrong << ", 0";
            else if (firstOrder == 2)
                cout << endl << "0, " << dummy << ", " << wrong;
            else if (firstOrder == 3)
                cout << endl << "0, " << wrong << ", " << dummy;
            else if (firstOrder == 4)
                cout << endl << wrong << ", " << dummy << ", 0";
            else
                cout << endl << wrong << ", 0, " << dummy;
            while (inSmall < 1){
            cout << endl;
            prizeSma.showShortName();
            cout << ": $";
            cin >> inSmall;
            }
            if (inSmall == prizeSma.getPrice())
                wonSmall = true;
        } // end if the player hasn't won the small prize
        else if (wonSmall && !wonMed)
        {
            cout << endl << medDigits[0] << ", " << medDigits[1] << ", " << medDigits[2] << ", " << medDigits[3];
            while (inMed < 1){
            cout << endl;
            prizeMed.showShortName();
            cout << ": $";
            cin >> inMed;
            }
            if (inMed == prizeMed.getPrice())
                wonMed = true;
        } // end if player hasn't won the medium prize
        else if (wonMed && !wonCar)
        {
            cout << endl << carDigits[0] << ", " << carDigits[1] << ", " << carDigits[2] << ", " << carDigits[3] << ", " << carDigits[4];
            while (inCar < 1){
            cout << endl << "CAR: $";
            cin >> inCar;
            }
            if (inCar == prizeCar.getPrice())
                wonCar = true;
        } // end if player hasn't won the car


        if (!wonCar)
            onChance++;

    } // end while loop

    if (!wonCar)
    {
        cout << endl;
        prizeSma.showShortName();
        cout << " - $" << prizeSma.getPrice();
        cout << endl;
        prizeMed.showShortName();
        cout << " - $" << prizeMed.getPrice();
        cout << endl << "CAR - $" << prizeCar.getPrice();
        cout << endl;
    }

    if (wonCar)
        cout << endl << "Congratulations, you win!";
    else if (wonMed)
        cout << endl << "Sorry, you lose. At least you won 2 prizes.";
    else if (wonSmall)
        cout << endl << "Sorry, you lose. At least you won 1 prize.";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// That's Too Much!
void playThatsTooMuch()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) && (t_Price < maxCar) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "THAT'S TOO MUCH!" << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();
    int prices[10];

    int tooMuchPrice = carPrice + (rand() % (1500 - 500) + 500) - 500;

    //cout << "price = $" << carPrice << endl;
    //cout << "too much = $" << tooMuchPrice << endl;

    /// Ensure that the "too much" price is never the first or last price (which it never has
    /// been, as far as we know), or the second or ninth price (to avoid "That's Two Ninth!").
    int tooMuchPosition = rand() % 6;

    /// Initialize the price list.
    if (tooMuchPosition == 0) /// the third price is the first "TOO MUCH" price
    {
        prices[2] = tooMuchPrice;
        prices[1] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[1] >= carPrice)
            prices[1] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[3] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[4] = prices[3] + (rand() % (1500 - 500) + 500);
        prices[5] = prices[4] + (rand() % (1500 - 500) + 500);
        prices[6] = prices[5] + (rand() % (1500 - 500) + 500);
        prices[7] = prices[6] + (rand() % (1500 - 500) + 500);
        prices[8] = prices[7] + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }
    else if (tooMuchPosition == 1) /// the fourth price is the first "TOO MUCH" price
    {
        prices[3] = tooMuchPrice;
        prices[2] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[2] >= carPrice)
            prices[2] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[1] = prices[2] - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[4] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[5] = prices[4] + (rand() % (1500 - 500) + 500);
        prices[6] = prices[5] + (rand() % (1500 - 500) + 500);
        prices[7] = prices[6] + (rand() % (1500 - 500) + 500);
        prices[8] = prices[7] + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }
    else if (tooMuchPosition == 2) /// the fifth price is the first "TOO MUCH" price
    {
        prices[4] = tooMuchPrice;
        prices[3] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[3] >= carPrice)
            prices[3] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[2] = prices[3] - (rand() % (1500 - 500) + 500);
        prices[1] = prices[2] - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[5] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[6] = prices[5] + (rand() % (1500 - 500) + 500);
        prices[7] = prices[6] + (rand() % (1500 - 500) + 500);
        prices[8] = prices[7] + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }
    else if (tooMuchPosition == 3) /// the sixth price is the first "TOO MUCH" price
    {
        prices[5] = tooMuchPrice;
        prices[4] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[4] >= carPrice)
            prices[4] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[3] = prices[4] - (rand() % (1500 - 500) + 500);
        prices[2] = prices[3] - (rand() % (1500 - 500) + 500);
        prices[1] = prices[2] - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[6] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[7] = prices[6] + (rand() % (1500 - 500) + 500);
        prices[8] = prices[7] + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }
    else if (tooMuchPosition == 4) /// the seventh price is the first "TOO MUCH" price
    {
        prices[6] = tooMuchPrice;
        prices[5] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[5] >= carPrice)
            prices[5] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[4] = prices[5] - (rand() % (1500 - 500) + 500);
        prices[3] = prices[4] - (rand() % (1500 - 500) + 500);
        prices[2] = prices[3] - (rand() % (1500 - 500) + 500);
        prices[1] = prices[2] - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[7] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[8] = prices[7] + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }
    else /// the eighth price is the first "TOO MUCH" price
    {
        prices[7] = tooMuchPrice;
        prices[6] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        while (prices[6] >= carPrice)
            prices[6] = tooMuchPrice - (rand() % (1500 - 500) + 500);
        prices[5] = prices[6] - (rand() % (1500 - 500) + 500);
        prices[4] = prices[5] - (rand() % (1500 - 500) + 500);
        prices[3] = prices[4] - (rand() % (1500 - 500) + 500);
        prices[2] = prices[3] - (rand() % (1500 - 500) + 500);
        prices[1] = prices[2] - (rand() % (1500 - 500) + 500);
        prices[0] = prices[1] - (rand() % (1500 - 500) + 500);
        prices[8] = tooMuchPrice + (rand() % (1500 - 500) + 500);
        prices[9] = prices[8] + (rand() % (1500 - 500) + 500);
    }

    //cout << endl << "Too much price: #" << tooMuchPosition+3 << endl;

    int on = 0;
    bool stop = false;

    while ( (on < 9) && !stop)
    {
        char choice = 'A';
        //cout << on-2 << " - On" << endl << tooMuchPosition << " - Stop" << endl;
        cout << endl << on+1 << ". $" << prices[on];
        while ( (choice != 'Y') && (choice != 'N') &&  (choice != 'y') && (choice != 'n') ){
        cout << endl << "Keep going (Y) or THAT'S TOO MUCH (N)?: ";
        cin >> choice;
        }
        if ( (choice == 'Y') || (choice == 'y') )
            on++;
        else
            stop = true;
    }
    if (on == 9)
    {
        cout << endl << "10. $" << prices[9];
        cout << endl << "THAT'S TOO MUCH!";
    }
    else
        cout << endl << "THAT'S TOO MUCH!";

    cout << endl << "The actual retail price of the car is $" << carPrice << endl;
    if ( (on-2) == tooMuchPosition)
        cout << "Congratulations, you win!";
    else
        cout << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Three Strikes
void playThreeStrikes()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ((inFile >> t_Model >> t_Options >> t_Price) && noRepeatingDigits(t_Price) && (t_Price > 40000) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "3 STRIKES" << endl;
    cout << endl;

    /// Since there's only one prize, randomization is a lot simpler than the randomizationField
    /// method used in other games.
    int randomPrize = rand() % i;

    int z = 0;
    car prizeCar;

    gameCarIt = gameCars.begin();
    for (z = 0; z < randomPrize; z++)
        gameCarIt++;
    prizeCar.setModel(gameCarIt->getModel());
    prizeCar.setOptions(gameCarIt->getOptions());
    prizeCar.setPrice(gameCarIt->getPrice());

    prizeCar.showModel();
    cout << endl << "Comes with: ";
    prizeCar.showOptions();

    int carPrice = prizeCar.getPrice();

    int digits[5];
    digits[0] = carPrice / 10000 % 10;
    digits[1] = carPrice / 1000 % 10;
    digits[2] = carPrice / 100 % 10;
    digits[3] = carPrice / 10 % 10;
    digits[4] = carPrice % 10;

    int sample[5];
    for (int m = 0; m < 5; m++)
        sample[m] = digits[m];

    sortStrikesNos(sample);

    bool revealed[5];
    for (int r = 0; r < 5; r++)
        revealed[r] = false;

    int strikesDrawn = 0;
    int on = 0;
    bool won = false;

    /// These hold the contestant's previous draws and ensure "balls" can be discarded while not having to mess with the array.
    int draw1 = 10;
    int draw2 = 10;
    int draw3 = 10;
    int draw4 = 10;

    cout << endl;
    cout << endl << "The digits in the price of the car are: ";
    cout << endl;
    for (int show = 0; show < 5; show++)
        cout << sample[show] << " ";
    cout << endl;

    while ( (!won) && (strikesDrawn < 3) ){
        int draw = -1;
        int position = 0;

        cout << endl << "$";
        for (int p = 0; p < 5; p++){
            if (revealed[p])
                cout << digits[p];
            else
                cout << "*";
        }
        if (strikesDrawn == 0)
            cout << endl;
        else if (strikesDrawn == 1)
            cout << endl << "  X   ";
        else if (strikesDrawn == 2)
            cout << endl << "  XX  ";

        bool init = false;

        cout << endl << "Press any key to draw a ball from the bag.";
        cout << endl;
        system("pause");
        if (strikesDrawn == 0) // Three strikes in the bag, player has no strikes.
        {
        while (!init){
        draw = rand() % 8;
        if (draw >= 5){
            init = true;
        }
        else if ( (draw < 5) ){

        // Ensure the player doesn't draw a discarded number.
        while ( (digits[draw] == draw1) || (digits[draw] == draw2) || (digits[draw] == draw3) || (digits[draw] == draw4) )
            draw = rand() % 5;
        init = true;
        }

        } // end initialization

        if (draw >= 5){
            cout << endl << "You drew a strike! Be careful.";
            strikesDrawn += 1;
        }
        else{
            if (digits[draw] == 8)
                cout << endl << "You've drawn an 8.";
            else
                cout << endl << "You've drawn a " << digits[draw] << ".";
            while ( (position < 1) || (position > 5) ){
                cout << endl << "Where does it go (1-5) in the price of the car?: ";{
                cin >> position;
                if (revealed[position-1]){
                    cout << endl << "This position already has a number revealed. Try another one.";
                    position = 0;
                    }
                }
            }
            if (digits[position-1] == digits[draw]){
                cout << endl << "Yes, that's correct! Let's discard this ball.";
                revealed[position-1] = true;

                if (on == 0)
                    draw1 = digits[draw];
                else if (on == 1)
                    draw2 = digits[draw];
                else if (on == 2)
                    draw3 = digits[draw];
                else if (on == 3)
                    draw4 = digits[draw];
                on++;
            } // end if player guessed correctly
            else
                cout << endl << "Sorry, that's not correct. Let's put the ball back in the bag.";

        } // end else if player didn't draw a strke

        } // end if player has no strikes

        else if (strikesDrawn == 1) // Two strikes in the bag, player has one strike.
        {
        while (!init){
        draw = rand() % 7;
        if (draw >= 5){
            init = true;
        }
        else if ( (draw < 5) ){

        // Ensure the player doesn't draw a discarded number.
        while ( (digits[draw] == draw1) || (digits[draw] == draw2) || (digits[draw] == draw3) || (digits[draw] == draw4) )
            draw = rand() % 5;
        init = true;
        }

        } // end initialization

        if (draw >= 5){
            cout << endl << "You've now drawn two strikes! One more, and you're out!";
            strikesDrawn += 1;
        }
        else{
            if (digits[draw] == 8)
                cout << endl << "You've drawn an 8.";
            else
                cout << endl << "You've drawn a " << digits[draw] << ".";
            while ( (position < 1) || (position > 5) ){
                cout << endl << "Where does it go (1-5) in the price of the car?: ";{
                cin >> position;
                if (revealed[position-1]){
                    cout << endl << "This position already has a number revealed. Try another one.";
                    position = 0;
                    }
                }
            }
            if (digits[position-1] == digits[draw]){
                cout << endl << "Yes, that's correct! Let's discard this ball.";
                revealed[position-1] = true;

                if (on == 0)
                    draw1 = digits[draw];
                else if (on == 1)
                    draw2 = digits[draw];
                else if (on == 2)
                    draw3 = digits[draw];
                else if (on == 3)
                    draw4 = digits[draw];
                on++;
            } // end if player guessed correctly
            else
                cout << endl << "Sorry, that's not correct. Let's put the ball back in the bag.";

        } // end else if player didn't draw a strke

        } // end if player has one strike

        else // One strike in the bag, player has two strikes.
        {

        while (!init){
        draw = rand() % 6;
        if (draw == 5){
            init = true;
        }
        else if ( (draw < 5) ){

        // Ensure the player doesn't draw a discarded number.
        while ( (digits[draw] == draw1) || (digits[draw] == draw2) || (digits[draw] == draw3) || (digits[draw] == draw4) )
            draw = rand() % 5;
        init = true;
        }

        } // end init

        if (draw >= 5){
            cout << endl << "You've drawn three strikes! You're out!";
            strikesDrawn += 1;
        }
   else{
            if (digits[draw] == 8)
                cout << endl << "You've drawn an 8.";
            else
                cout << endl << "You've drawn a " << digits[draw] << ".";
            while ( (position < 1) || (position > 5) ){
                cout << endl << "Where does it go (1-5) in the price of the car?: ";{
                cin >> position;
                if (revealed[position-1]){
                    cout << endl << "This position already has a number revealed. Try another one.";
                    position = 0;
                    }
                }
            }
            if (digits[position-1] == digits[draw]){
                cout << endl << "Yes, that's correct! Let's discard this ball.";
                revealed[position-1] = true;

                if (on == 0)
                    draw1 = digits[draw];
                else if (on == 1)
                    draw2 = digits[draw];
                else if (on == 2)
                    draw3 = digits[draw];
                else if (on == 3)
                    draw4 = digits[draw];
                on++;
            } // end if player guessed correctly
            else
                cout << endl << "Sorry, that's not correct. Let's put the ball back in the bag.";

        } // end else if player didn't draw a strke

        } // end if player has two strikes

    if (revealed[0] && revealed[1] && revealed[2] && revealed[3] && revealed[4])
        won = true;

    } /// end while loop

    if (won){
        cout << endl << "$" << carPrice;
        if (strikesDrawn == 0)
            cout << endl;
        else if (strikesDrawn == 1)
            cout << endl << "  X   ";
        else if (strikesDrawn == 2)
            cout << endl << "  XX  ";

        cout << endl << "Congratulations, you win!";
    }
    else{
        cout << endl << "The price was $" << carPrice << ".";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Triple Play
void playTriplePlay()
{
    list<car> gameCars;
    list<car>::iterator gameCarIt;

    string t_Model;
    string t_Options;
    int t_Price;

    car * cptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("./prizes/" + carInput);
    while (inFile)
    {
        cptr = new car;
        if ( (inFile >> t_Model >> t_Options >> t_Price) )
        {
            cptr->setModel(t_Model);
            cptr->setOptions(t_Options);
            cptr->setPrice(t_Price);
            gameCars.push_back(*cptr);
            i++;
        }
    } // end while loop
    inFile.close();

    cout << "TRIPLE PLAY" << endl;

    car tpCars[3];

    /// Set car #1
    bool setFirst = false;
    while (!setFirst){
    int val1 = rand() % i;
    gameCarIt = gameCars.begin();
    for (int z = 0; z < val1; z++)
        gameCarIt++;
    if ( (gameCarIt->getPrice()) < 20000 ){
        tpCars[0].setModel(gameCarIt->getModel());
        tpCars[0].setOptions(gameCarIt->getOptions());
        tpCars[0].setPrice(gameCarIt->getPrice());
        setFirst = true;
    }
    } // end while loop setting car #1

    /// Set car #2
    bool setSecond = false;
    while (!setSecond){
    int val2 = rand() % i;
    gameCarIt = gameCars.begin();
    for (int z = 0; z < val2; z++)
        gameCarIt++;
    if ( ((gameCarIt->getPrice()) > 20000) && ((gameCarIt->getPrice()) < 25000) ){
        tpCars[1].setModel(gameCarIt->getModel());
        tpCars[1].setOptions(gameCarIt->getOptions());
        tpCars[1].setPrice(gameCarIt->getPrice());
        setSecond = true;
    }
    } // end while loop setting car #2

    /// Set car #3
    bool setThird = false;
    while (!setThird){
    int val3 = rand() % i;
    gameCarIt = gameCars.begin();
    for (int z = 0; z < val3; z++)
        gameCarIt++;
    if ( ((gameCarIt->getPrice()) > 25000) && ((gameCarIt->getPrice()) < 35000) ){
        tpCars[2].setModel(gameCarIt->getModel());
        tpCars[2].setOptions(gameCarIt->getOptions());
        tpCars[2].setPrice(gameCarIt->getPrice());
        setThird = true;
    }
    } // end while loop setting car #3

//    cout << endl;
//    tpCars[0].showModel();
//    cout << endl;
//    tpCars[0].showARP();
//    cout << endl;
//    tpCars[1].showModel();
//    cout << endl;
//    tpCars[1].showARP();
//    cout << endl;
//    tpCars[2].showModel();
//    cout << endl;
//    tpCars[2].showARP();

    int car1Choices[2];
    int setIt = rand() % 2;
    int further = rand() % 2;
    int amount;

    if (further == 0)
        amount = 2000;
    else
        amount = 3000;

    int rightA = tpCars[0].getPrice() - ( (tpCars[0].getPrice()) % 1000);

    if (setIt == 0){
        car1Choices[0] = rightA;
        car1Choices[1] = rightA + amount;
    }
    else{
        car1Choices[0] = rightA - amount;
        car1Choices[1] = rightA;
    }

    cout << endl << "1. ";
    tpCars[0].showModel();
    cout << endl << "Comes with: ";
    tpCars[0].showOptions();

    cout << endl << "1. $" << car1Choices[0];
    cout << endl << "2. $" << car1Choices[1];

    int choice1 = 0;
    while ( (choice1 < 1) || (choice1 > 2) ){
        cout << endl << "Which is closest to the actual retail price without going over?: ";
        cin >> choice1;
    }

    cout << endl << "The actual retail price is $" << tpCars[0].getPrice();
    if (car1Choices[choice1-1] == rightA){
        cout << endl << "Yes, that's correct! On to the next car...";

        int car2Choices[3];
        int setIt2 = rand() % 3;
        int further2 = rand() % 2;
        int amount2a;
        int amount2b;
        if (further2 == 0){
            amount2a = 2000;
            amount2b = 3000;
            }
        else{
            amount2a = 3000;
            amount2b = 2000;
            }

        int rightB = tpCars[1].getPrice() - ( (tpCars[1].getPrice()) % 1000);

        if (setIt2 == 0){
            car2Choices[0] = rightB;
            car2Choices[1] = rightB + amount2a;
            car2Choices[2] = car2Choices[1] + amount2b;
        }
        else if (setIt2 == 1){
            car2Choices[1] = rightB;
            car2Choices[0] = rightB - amount2a;
            car2Choices[2] = rightB + amount2b;
        }
        else{
            car2Choices[2] = rightB;
            car2Choices[1] = rightB - amount2a;
            car2Choices[0] = car2Choices[1] - amount2b;
        }

        cout << endl;
        cout << endl << "2. ";
        tpCars[1].showModel();
        cout << endl << "Comes with: ";
        tpCars[1].showOptions();

        cout << endl << "1. $" << car2Choices[0];
        cout << endl << "2. $" << car2Choices[1];
        cout << endl << "3. $" << car2Choices[2];

        int choice2 = 0;
        while ( (choice2 < 1) || (choice2 > 3) ){
            cout << endl << "Which is closest to the actual retail price without going over?: ";
            cin >> choice2;
        }
    cout << endl << "The actual retail price is $" << tpCars[1].getPrice();
    if (car2Choices[choice2-1] == rightB){
        cout << endl << "Yes, that's correct! On to the final car...";

        int car3Choices[4];
        int setIt3 = rand() % 4;
        int further3 = rand() % 2;
        int amount3a;
        int amount3b;
        int amount3c;

        if (further3 == 0){
            amount3a = 2000;
            amount3b = 3000;
            amount3c = 4000;
            }
        else{
            amount3a = 4000;
            amount3b = 3000;
            amount3c = 2000;
            }

        int rightC = tpCars[2].getPrice() - ( (tpCars[2].getPrice()) % 1000);

        if (setIt3 == 0){
        car3Choices[0] = rightC;
        car3Choices[1] = rightC + amount3a;
        car3Choices[2] = car3Choices[1] + amount3b;
        car3Choices[3] = car3Choices[2] + amount3c;
        }
        else if (setIt3 == 1){
        car3Choices[1] = rightC;
        car3Choices[0] = rightC - amount3a;
        car3Choices[2] = rightC + amount3b;
        car3Choices[3] = car3Choices[2] + amount3c;
        }
        else if (setIt3 == 2){
        car3Choices[2] = rightC;
        car3Choices[1] = rightC - amount3a;
        car3Choices[0] = car3Choices[1] - amount3b;
        car3Choices[3] = car3Choices[2] + amount3c;
        }
        else{
        car3Choices[3] = rightC;
        car3Choices[2] = rightC - amount3a;
        car3Choices[1] = car3Choices[2] - amount3b;
        car3Choices[0] = car3Choices[1] - amount3c;
        }

        cout << endl;
        cout << endl << "3. ";
        tpCars[2].showModel();
        cout << endl << "Comes with: ";
        tpCars[2].showOptions();

        cout << endl << "1. $" << car3Choices[0];
        cout << endl << "2. $" << car3Choices[1];
        cout << endl << "3. $" << car3Choices[2];
        cout << endl << "4. $" << car3Choices[3];

        int choice3 = 0;
        while ( (choice3 < 1) || (choice3 > 4) ){
            cout << endl << "Which is closest to the actual retail price without going over?: ";
            cin >> choice3;
        }

    cout << endl << "The actual retail price is $" << tpCars[2].getPrice();
    if (car3Choices[choice3-1] == rightC)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    } // end if player got car #2 correctly
    else
        cout << endl << "Sorry, you lose.";

    } // end if player got car #1 correctly
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

#endif // CARGAMES_H_INCLUDED
