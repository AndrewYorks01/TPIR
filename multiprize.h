/// Multi-prize games are stored here.

#ifndef MULTIPRIZE_H_INCLUDED
#define MULTIPRIZE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <list>
#include <string>

#include "prize.h"

using namespace std;

    /// Uses a bubble sort algorithm to sort the prices in Credit Card, which helps calculate the credit limit.
    void sortCredPrices(int nos[])
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

    /// Uses a bubble sort algorithm to sort the prices in Race Game.
    void sortRacePrices(int nos[])
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

    /// Uses a bubble sort algorithm to sort the clearance prices in Clearance Sale.
    void sortClearancePrices(int nos[])
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

    /// Uses a bubble sort algorithm to sort cards when creating hands in Poker Game.
    void sortCards(int nos[])
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

    /// Checks if these two prizes have five of a kind. If true, returns whatever number there is four of.
    /// If false, returns -1.
    int hasFiveOfAKind(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        /// Return a value
        if (nines == 5)
            return 9;
        else if (eights == 5)
            return 8;
        else if (sevens == 5)
            return 7;
        else if (sixes == 5)
            return 6;
        else if (fives == 5)
            return 5;
        else if (fours == 5)
            return 4;
        else if (threes == 5)
            return 3;
        else if (twos == 5)
            return 2;
        else if (ones == 5)
            return 1;
        else if (zeros == 5)
            return 0;
        else
            return -1;
    }

    /// Checks if these two prizes have four of a kind. If true, returns whatever number there is four of.
    /// If false, returns -1.
    int hasFourOfAKind(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        /// Return a value
        if (nines == 4)
            return 9;
        else if (eights == 4)
            return 8;
        else if (sevens == 4)
            return 7;
        else if (sixes == 4)
            return 6;
        else if (fives == 4)
            return 5;
        else if (fours == 4)
            return 4;
        else if (threes == 4)
            return 3;
        else if (twos == 4)
            return 2;
        else if (ones == 4)
            return 1;
        else if (zeros == 4)
            return 0;
        else
            return -1;
    }

    /// Returns the larger of the remaining digits in the player's four of a kind poker hand.
    int createFourKindHand(int price1, int price2)
    {
        int fourcard = hasFourOfAKind(price1, price2);

        int first = 10;
        int second = 10;

        if (fourcard >= 0){

        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        for (int b = 0; b < 6; b++){
            if (cards[b] == fourcard)
                cards[b] = 10;
        }

        sortCards(cards);

        return cards[1];

        } // end if player has four of a kind
        else
            return -1;
    }

    /// Checks if these two prizes have a full house. If true, returns whatever number there is three of.
    /// If false, returns -1.
    int hasFullHouse(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        if ( (nines == 3) || (eights == 3) || (sevens == 3) || (sixes == 3) || (fives == 3) ||
            (fours == 3) || (threes == 3) || (twos == 3) || (ones == 3) || (zeros == 3)){

        int majority;
        if (nines == 3)
            majority = 9;
        else if (eights == 3)
            majority = 8;
        else if (sevens == 3)
            majority = 7;
        else if (sixes == 3)
            majority = 6;
        else if (fives == 3)
            majority = 5;
        else if (fours == 3)
            majority = 4;
        else if (threes == 3)
            majority = 3;
        else if (twos == 3)
            majority = 2;
        else if (ones == 3)
            majority = 1;
        else
            majority = 0;

        int nines_2 = 0;
        int eights_2 = 0;
        int sevens_2 = 0;
        int sixes_2 = 0;
        int fives_2 = 0;
        int fours_2 = 0;
        int threes_2 = 0;
        int twos_2 = 0;
        int ones_2 = 0;
        int zeros_2 = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines_2 += 1;
        if (cards[x] == 8)
            eights_2 += 1;
        if (cards[x] == 7)
            sevens_2 += 1;
        if (cards[x] == 6)
            sixes_2 += 1;
        if (cards[x] == 5)
            fives_2 += 1;
        if (cards[x] == 4)
            fours_2 += 1;
        if (cards[x] == 3)
            threes_2 += 1;
        if (cards[x] == 2)
            twos_2 += 1;
        if (cards[x] == 1)
            ones_2 += 1;
        if (cards[x] == 0)
            zeros_2 += 1;
        } // end for loop

        if ( ( (nines_2 >= 2) && (majority != 9) ) ||   ( (eights_2 >= 2) && (majority != 8) ) ||
             ( (sevens_2 >= 2) && (majority != 7)) ||   ( (sixes_2 >= 2) && (majority != 6) )  ||
             ( (fives_2 >= 2) && (majority != 5) ) ||    ( (fours_2 >= 2) && (majority != 4) )  ||
             ( (threes_2 >= 2) && (majority != 3)) ||   ( (twos_2 >= 2) && (majority != 2) ) ||
             ( (ones_2 >= 2) && (majority != 1) ) || ( (zeros_2 >= 2) && (majority != 0)) )
            return majority;
        else
            return -1;

        } // end if player has three of one number
        else
            return -1;


    }

    /// Returns the digit the player has two of in a full house.
    int createFullHouseHand(int price1, int price2)
    {
        int threecard = hasFullHouse(price1, price2);

        if (threecard >= 0){
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        for (int b = 0; b < 6; b++){
            if (cards[b] == threecard)
                cards[b] = 10;
        }

        sortCards(cards);
        return cards[1];

        }
        else
            return -1;

    }

    /// Checks if these two prizes have a full house. If true, returns whatever number there is three of.
    /// If false, returns -1.
    int hasThreeOfAKind(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        if (nines == 3)
            return 9;
        else if (eights == 3)
            return 8;
        else if (sevens == 3)
            return 7;
        else if (sixes == 3)
            return 6;
        else if (fives == 3)
            return 5;
        else if (fours == 3)
            return 3;
        else if (threes == 3)
            return 3;
        else if (twos == 3)
            return 2;
        else if (ones == 3)
            return 1;
        else if (zeros == 3)
            return 0;
        else if ( (nines == 3) && (eights == 3) )
            return 9;
        else if ( (nines == 3) && (sevens == 3) )
            return 9;
        else if ( (nines == 3) && (sixes == 3) )
            return 9;
        else if ( (nines == 3) && (fives == 3) )
            return 9;
        else if ( (nines == 3) && (fours == 3) )
            return 9;
        else if ( (nines == 3) && (threes == 3) )
            return 9;
        else if ( (nines == 3) && (twos == 3) )
            return 9;
        else if ( (nines == 3) && (ones == 3) )
            return 9;
        else if ( (nines == 3) && (zeros == 3) )
            return 9;
        else
            return -1;
    }

    /// Returns the larger remaining number if the player has three of a kind.
    int largerRemainingTOAK(int price1, int price2)
    {
        int threecard = hasThreeOfAKind(price1, price2);
        if (threecard >= 0){
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        for (int b = 0; b < 6; b++){
            if (cards[b] == threecard)
                cards[b] = 10;
        }

        sortCards(cards);
        return cards[2];

        }
        else
            return -1;

    }

    /// Returns the smaller remaining number if the player has three of a kind.
    int smallerRemainingTOAK(int price1, int price2)
    {
        int threecard = hasThreeOfAKind(price1, price2);
        if (threecard >= 0){
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        for (int b = 0; b < 6; b++){
            if (cards[b] == threecard)
                cards[b] = 10;
        }

        sortCards(cards);
        return cards[1];

        }
        else
            return -1;

    }

    /// Checks if these two prizes have two pairs of digits between them. If true, returns the larger number in the pair.
    /// If false, returns -1.
    int hasTwoPair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        /// Pairs where 9 is the leading number
        if ( (nines == 2) && (eights == 2) )
            return 9;
        else if ( (nines == 2) && (sevens == 2) )
            return 9;
        else if ( (nines == 2) && (sixes == 2) )
            return 9;
        else if ( (nines == 2) && (fives == 2) )
            return 9;
        else if ( (nines == 2) && (fours == 2) )
            return 9;
        else if ( (nines == 2) && (threes == 2) )
            return 9;
        else if ( (nines == 2) && (twos == 2) )
            return 9;
        else if ( (nines == 2) && (ones == 1) )
            return 9;
        else if ( (nines == 2) && (zeros == 2) )
            return 9;

        /// Pairs where 8 is the leading number
        else if ( (eights == 2) && (sevens == 2) )
            return 8;
        else if ( (eights == 2) && (sixes == 2) )
            return 8;
        else if ( (eights == 2) && (fives == 2) )
            return 8;
        else if ( (eights == 2) && (fours == 2) )
            return 8;
        else if ( (eights == 2) && (threes == 2) )
            return 8;
        else if ( (eights == 2) && (twos == 2) )
            return 8;
        else if ( (eights == 2) && (ones == 2) )
            return 8;
        else if ( (eights == 2) && (zeros == 2) )
            return 8;

        /// Pairs where 7 is the leading number
        else if ( (sevens == 2) && (sixes == 2) )
            return 7;
        else if ( (sevens == 2) && (fives == 2) )
            return 7;
        else if ( (sevens == 2) && (fours == 2) )
            return 7;
        else if ( (sevens == 2) && (threes == 2) )
            return 7;
        else if ( (sevens == 2) && (twos == 2) )
            return 7;
        else if ( (sevens == 2) && (ones == 2) )
            return 7;
        else if ( (sevens == 2) && (zeros == 2) )
            return 7;

        /// Pairs where 6 is the leading number
        else if ( (sixes == 2) && (fives == 2) )
            return 6;
        else if ( (sixes == 2) && (fours == 2) )
            return 6;
        else if ( (sixes == 2) && (threes == 2) )
            return 6;
        else if ( (sixes == 2) && (twos == 2) )
            return 6;
        else if ( (sixes == 2) && (ones == 2) )
            return 6;
        else if ( (sixes == 2) && (zeros == 2) )
            return 6;

        /// Pairs where 5 is the leading number
        else if ( (fives == 2) && (fours == 2) )
            return 5;
        else if ( (fives == 2) && (threes == 2) )
            return 5;
        else if ( (fives == 2) && (twos == 2) )
            return 5;
        else if ( (fives == 2) && (ones == 2) )
            return 5;
        else if ( (fives == 2) && (zeros == 2) )
            return 5;

        /// Pairs where 4 is the leading number
        else if ( (fours == 2) && (threes == 2) )
            return 4;
        else if ( (fours == 2) && (twos == 2) )
            return 4;
        else if ( (fours == 2) && (ones == 2) )
            return 4;
        else if ( (fours == 2) && (zeros == 2) )
            return 4;

        /// Pairs where 3 is the leading number
        else if ( (threes == 2) && (twos == 2) )
            return 3;
        else if ( (threes == 2) && (ones == 2) )
            return 3;
        else if ( (threes == 2) && (zeros == 2) )
            return 3;

        /// Pairs where 2 is the leading number
        else if ( (twos == 2) && (ones == 2) )
            return 2;
        else if ( (twos == 2) && (zeros == 2) )
            return 2;

        else if ( (ones == 2) && (zeros == 2) )
            return 1;
        else
            return -1;

    }

    /// Returns the smaller number of a hand with two pairs.
    int otherTwoPair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        /// Pairs where 9 is the leading number
        if ( (nines == 2) && (eights == 2) )
            return 8;
        else if ( (nines == 2) && (sevens == 2) )
            return 7;
        else if ( (nines == 2) && (sixes == 2) )
            return 6;
        else if ( (nines == 2) && (fives == 2) )
            return 5;
        else if ( (nines == 2) && (fours == 2) )
            return 4;
        else if ( (nines == 2) && (threes == 2) )
            return 3;
        else if ( (nines == 2) && (twos == 2) )
            return 2;
        else if ( (nines == 2) && (ones == 1) )
            return 1;
        else if ( (nines == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 8 is the leading number
        else if ( (eights == 2) && (sevens == 2) )
            return 7;
        else if ( (eights == 2) && (sixes == 2) )
            return 6;
        else if ( (eights == 2) && (fives == 2) )
            return 5;
        else if ( (eights == 2) && (fours == 2) )
            return 4;
        else if ( (eights == 2) && (threes == 2) )
            return 3;
        else if ( (eights == 2) && (twos == 2) )
            return 2;
        else if ( (eights == 2) && (ones == 2) )
            return 1;
        else if ( (eights == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 7 is the leading number
        else if ( (sevens == 2) && (sixes == 2) )
            return 6;
        else if ( (sevens == 2) && (fives == 2) )
            return 5;
        else if ( (sevens == 2) && (fours == 2) )
            return 4;
        else if ( (sevens == 2) && (threes == 2) )
            return 3;
        else if ( (sevens == 2) && (twos == 2) )
            return 2;
        else if ( (sevens == 2) && (ones == 2) )
            return 1;
        else if ( (sevens == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 6 is the leading number
        else if ( (sixes == 2) && (fives == 2) )
            return 5;
        else if ( (sixes == 2) && (fours == 2) )
            return 4;
        else if ( (sixes == 2) && (threes == 2) )
            return 3;
        else if ( (sixes == 2) && (twos == 2) )
            return 2;
        else if ( (sixes == 2) && (ones == 2) )
            return 1;
        else if ( (sixes == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 5 is the leading number
        else if ( (fives == 2) && (fours == 2) )
            return 4;
        else if ( (fives == 2) && (threes == 2) )
            return 3;
        else if ( (fives == 2) && (twos == 2) )
            return 2;
        else if ( (fives == 2) && (ones == 2) )
            return 1;
        else if ( (fives == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 4 is the leading number
        else if ( (fours == 2) && (threes == 2) )
            return 3;
        else if ( (fours == 2) && (twos == 2) )
            return 2;
        else if ( (fours == 2) && (ones == 2) )
            return 1;
        else if ( (fours == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 3 is the leading number
        else if ( (threes == 2) && (twos == 2) )
            return 2;
        else if ( (threes == 2) && (ones == 2) )
            return 1;
        else if ( (threes == 2) && (zeros == 2) )
            return 0;

        /// Pairs where 2 is the leading number
        else if ( (twos == 2) && (ones == 2) )
            return 1;
        else if ( (twos == 2) && (zeros == 2) )
            return 0;

        else if ( (ones == 2) && (zeros == 2) )
            return 0;
        else
            return -1;
    }

    /// Returns the remaining digit if a player has two pairs.
    int remainingTwoPair(int price1, int price2)
    {
    int larger = hasTwoPair(price1, price2);
    int smaller = otherTwoPair(price1, price2);

    int cards[6];
    cards[0] = price1 / 100 % 10;
    cards[1] = price1 / 10 % 10;
    cards[2] = price1 % 10;
    cards[3] = price2 / 100 % 10;
    cards[4] = price2 / 10 % 10;
    cards[5] = price2 % 10;

    for (int x = 0; x < 6; x++){
        if (cards[x] == larger)
            cards[x] = 11;
        else if (cards[x] == smaller)
            cards[x] = 10;
    }

    sortCards(cards);
    return cards[1];

    }

    /// Checks if the player has one pair. If true, returns the number in that pair. If false, returns -1.
    int hasOnePair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int nines = 0;
        int eights = 0;
        int sevens = 0;
        int sixes = 0;
        int fives = 0;
        int fours = 0;
        int threes = 0;
        int twos = 0;
        int ones = 0;
        int zeros = 0;

        for (int x = 0; x < 6; x++){
        if (cards[x] == 9)
            nines += 1;
        if (cards[x] == 8)
            eights += 1;
        if (cards[x] == 7)
            sevens += 1;
        if (cards[x] == 6)
            sixes += 1;
        if (cards[x] == 5)
            fives += 1;
        if (cards[x] == 4)
            fours += 1;
        if (cards[x] == 3)
            threes += 1;
        if (cards[x] == 2)
            twos += 1;
        if (cards[x] == 1)
            ones += 1;
        if (cards[x] == 0)
            zeros += 1;
        } // end for loop

        if ( (nines == 2) && (eights != 2) && (sevens != 2) && (sixes != 2) && (fives != 2) &&
            (fours != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 9;
        else if ( (eights == 2) && (nines != 2) && (sevens != 2) && (sixes != 2) && (fives != 2) &&
            (fours != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 8;
        else if ( (sevens == 2) && (nines != 2) && (eights != 2) && (sixes != 2) && (fives != 2) &&
            (fours != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 7;
        else if ( (sixes == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (fives != 2) &&
            (fours != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 6;
        else if ( (fives == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fours != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 5;
        else if ( (fours == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fives != 2) && (threes != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 4;
        else if ( (threes == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fives != 2) && (fours != 2) && (twos != 2) && (ones != 2) && (zeros != 2) )
            return 3;
        else if ( (twos == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fives != 2) && (fours != 2) && (threes != 2) && (ones != 2) && (zeros != 2) )
            return 2;
        else if ( (ones == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fives != 2) && (fours != 2) && (threes != 2) && (twos != 2) && (zeros != 2) )
            return 1;
        else if ( (zeros == 2) && (nines != 2) && (eights != 2) && (sevens != 2) && (sixes != 2) &&
            (fives != 2) && (fours != 2) && (threes != 2) && (twos != 2) && (nines != 2) )
            return 0;
        else
            return -1;

    }

    /// Returns the largest remaining number if the player has one pair.
    int largestOnePair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int pairno = hasOnePair(price1, price2);

        for (int x = 0; x < 6; x++){
            if (cards[x] == pairno)
                cards[x] = 10;
        }

        sortCards(cards);
        return cards[3];

    }

    /// Returns the middle remaining number if the player has one pair.
    int middleOnePair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int pairno = hasOnePair(price1, price2);

        for (int x = 0; x < 6; x++){
            if (cards[x] == pairno)
                cards[x] = 10;
        }

        sortCards(cards);
        return cards[2];

    }

    /// Returns the smallest remaining number if the player has one pair.
    int smallestOnePair(int price1, int price2)
    {
        int cards[6];
        cards[0] = price1 / 100 % 10;
        cards[1] = price1 / 10 % 10;
        cards[2] = price1 % 10;
        cards[3] = price2 / 100 % 10;
        cards[4] = price2 / 10 % 10;
        cards[5] = price2 % 10;

        int pairno = hasOnePair(price1, price2);

        for (int x = 0; x < 6; x++){
            if (cards[x] == pairno)
                cards[x] = 10;
        }

        sortCards(cards);
        return cards[1];

    }

    /// Checks if a 3-digit prize DOESN'T have repeating digits. This is the "given" price in One For All.
    /// (The name of this function actually implies the opposite of what it actually does, but it's too late
    /// to change it now.)
    bool incompatibleForOneForAll(int price)
    {
    if (price > 999)
        return false;
    else{
    int digits[3];
    digits[0] = price / 100 % 10;
    digits[1] = price / 10 % 10;
    digits[2] = price % 10;
    if ( (digits[1] == digits[0]) || (digits[2] == digits[0]) || (digits[2] == digits[1]) )
        return false;
    //else if ( (digits[0] == 0) || (digits[1] == 0) || (digits[2] == 0) )
    //    return false;
    else
        return true;
    }
    }

    /// Checks if a 3-digit price hsa a zero. If this is the case, the four-digit prices will all need to have the hundreds place digit missing.
    bool hasZero(int price)
    {
    if (price > 999)
        return false;
    else{
    int digits[3];
    digits[0] = price / 100 % 10;
    digits[1] = price / 10 % 10;
    digits[2] = price % 10;
    if ( (digits[0] == 0) || (digits[1] == 0) || (digits[2] == 0) )
        return true;
    else
        return false;
    } // end else
    }

    /// Checks if the digits in a 3-digit prize can fit into the thousands or hundreds spaces of three four-digit prizes.
    bool compatibleForOneForAll(int threeDigit, int fourDigit1, int fourDigit2, int fourDigit3, int pos1, int pos2, int pos3)
    {
    bool check = false;
    int digits[3];
    if (!incompatibleForOneForAll(threeDigit)){
        //cout << endl << "The base prize has more than three digits or has repeating digits";
        return false;
        }
    else{
    digits[0] = threeDigit / 100 % 10;
    digits[1] = threeDigit / 10 % 10;
    digits[2] = threeDigit % 10;
    if ( ((fourDigit1 > 999) && (fourDigit1 < 10000)) && ((fourDigit2 > 999) && (fourDigit2 < 10000)) && ((fourDigit3 > 999) && (fourDigit3 < 10000)) ){

    if ( ( ( (pos1 == 0) && ((fourDigit1 / 1000 % 10) == digits[0]))) || ( ( (pos1 == 1) && ( (fourDigit1 / 100 % 10) == digits[0]) ) ) ){
        if ( (((pos2 == 0) && ((fourDigit2 / 1000 % 10) == digits[1]))) || (((pos2 == 1) && ((fourDigit2 / 100 % 10) == digits[1]))) ){
            if ( (((pos3 == 0) && ((fourDigit3 / 1000 % 10) == digits[2]))) || (((pos3 == 1) && ((fourDigit3 / 100 % 10) == digits[2]))) ){
                return true;
            } // third digit
            else
                return false;
        } // second digit
          else
            return false;
    } // first digit
     else
        return false;

    } // end if that checks if the four-digit prizes have four digits
    else{
        //cout << endl << "At least one of the missing digit prizes doesn't have four digits";
        return false;
        }
    } // end else if three digit prize is compatible
    }

/// Bargain Game
void playBargainGame()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1600)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "BARGAIN GAME" << endl;

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
    medium prizes[2];

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int difference1 = 0;
    int difference2 = 0;

    int biggerBargain = rand() % 2; /// if 0, the prize on the left is the bigger bargain. if 1, the
                                    /// prize on the right is the bigger bargain.


    int bargain1 = (rand() % (7 - 3) + 3) * 100;
    int bargain2 = (rand() % (12 - 8) + 8) * 100;

    //cout << "bargain1 = $" << bargain1 << endl;
    //cout << "bargain2 = $" << bargain2 << endl;

    if (biggerBargain == 0)
    {
        difference1 = prizes[0].getPrice() - bargain2;
        difference2 = prizes[1].getPrice() - bargain1;
    }
    else
    {
        difference1 = prizes[0].getPrice() - bargain1;
        difference2 = prizes[1].getPrice() - bargain2;
    }

    cout << "1. ";
    prizes[0].showPrize();
    cout << " - $" << difference1;
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << " - $" << difference2;
    cout << endl;
    int choice = 0;
    while ( (choice < 1) || (choice > 2) )
    {
        cout << endl << "Which price (enter the number) is the bigger bargain?: ";
        cin >> choice;
    }

    /// The other prize's price is always revealed first.
    if (choice == 1)
    {
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is ";
    prizes[1].showARP();
    cout << endl << "for a difference of $" << prizes[1].getPrice() - difference2 << endl;
    system("pause");
    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is ";
    prizes[0].showARP();
    cout << endl << "for a difference of $" << prizes[0].getPrice() - difference1 << endl;
    if (biggerBargain == 0)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";
    }
    else if (choice == 2)
    {
    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is ";
    prizes[0].showARP();
    cout << endl << "for a difference of $" << prizes[0].getPrice() - difference1 << endl;
    system("pause");
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is ";
    prizes[1].showARP();
    cout << endl << "for a difference of $" << prizes[1].getPrice() - difference2 << endl;
    if (biggerBargain == 1)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";
    }

    cout << endl;
    system("pause");
    system("CLS");
}

/// Big Item Bash
void playBigItemBash()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1600)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "BIG ITEM BASH" << endl;

    medium item1;
    medium item2;

    int val1 = rand() % i;
    int val2;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < val1; z++)
        gameItemIt++;
    item1.setDescription(gameItemIt->getDescription());
    item1.setShortName(gameItemIt->getShortName());
    item1.setPrice(gameItemIt->getPrice());

    bool setSecond = false;
    while (!setSecond){
    val2 = val1;
    while (val2 == val1)
        val2 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < val2; z++)
        gameItemIt++;
    if (gameItemIt->getPrice() != item1.getPrice()){
        item2.setDescription(gameItemIt->getDescription());
        item2.setShortName(gameItemIt->getShortName());
        item2.setPrice(gameItemIt->getPrice());
        setSecond = true;
    }
    } // end while loop

    cout << endl << "1. ";
    item1.showPrize();
    cout << endl << "2. ";
    item2.showPrize();

    cout << endl;
    int choice = 0;
    while ( (choice < 1) || (choice > 2) ){
        cout << endl << "Which item is more expensive?: ";
        cin >> choice;
    }

    if ( (choice == 1) && (item1.getPrice() >= item2.getPrice()) )
        cout << endl << "Congratulations, you win!";
    else if ( (choice == 2) && (item2.getPrice() >= item1.getPrice()) )
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Bump
void playBump()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1600)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "BUMP" << endl;

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
    medium prizes[2];

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int item1Price = prizes[0].getPrice();
    int item2Price = prizes[1].getPrice();

    int wrongPriceA = item1Price;
    while ((wrongPriceA == item1Price) || (wrongPriceA == item2Price))
        wrongPriceA = rand() % (3500 - 1000) + 1000;
    int wrongPriceB = item1Price;
    while ((wrongPriceB == item1Price) || (wrongPriceB == item2Price))
        wrongPriceB = rand() % (3500 - 1000) + 1000;

    int random = rand() % 2; /// if 0, bump to the RIGHT. if 1, bump to the LEFT.

    cout << "1. ";
    prizes[0].showPrize();
    cout << endl << "2. ";
    prizes[1].showPrize();
    cout << endl;

    if (random == 0)
    {
        /*
        cout << endl << "$" << item1Price;
        cout << endl << "$" << item2Price << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << wrongPriceA << " - ";
        prizes[1].showShortName();
        cout << endl << "$" << wrongPriceB;
        */

        cout << endl << "$" << item1Price << " $" << item2Price << " $" << wrongPriceA << " $" << wrongPriceB;
        cout << endl << "________#1____#2_______";

        cout << endl;

        cout << endl << "1. Bump RIGHT:";
        cout << endl << "$" << item1Price << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << item2Price << " - ";
        prizes[1].showShortName();
        cout << endl;
        cout << endl << "2. Bump LEFT:";
        cout << endl << "$" << wrongPriceA << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << wrongPriceB << " - ";
        prizes[1].showShortName();
        cout << endl;
    }
    else
    {
        /*
        cout << endl << "$" << wrongPriceA;
        cout << endl << "$" << wrongPriceB << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << item1Price << " - ";
        prizes[1].showShortName();
        cout << endl << "$" << item2Price;
        */

        cout << endl << "$" << wrongPriceA << " $" << wrongPriceB << " $" << item1Price << " $" << item2Price;
        cout << endl << "________#1____#2_______";

        cout << endl;
        cout << endl << "1. Bump RIGHT:";
        cout << endl << "$" << wrongPriceA << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << wrongPriceB << " - ";
        prizes[1].showShortName();
        cout << endl;
        cout << endl << "2. Bump LEFT:";
        cout << endl << "$" << item1Price << " - ";
        prizes[0].showShortName();
        cout << endl << "$" << item2Price << " - ";
        prizes[1].showShortName();
        cout << endl;

    }

    int choice = 0;
    while ((choice < 1) || (choice > 2) )
    {
        cout << endl << "Which way should the prices be bumped?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is ";
    prizes[0].showARP();
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is ";
    prizes[1].showARP();

    if ((choice-1) == random)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Buy or Sell
void playBuyOrSell()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1100)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "BUY OR SELL" << endl;

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
    medium prizes[3];

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int dispPrice1;
    int dispPrice2;
    int dispPrice3;

    /// If the bools are 0, the price will be decreased (BUY). If the bools are 1, the price will be increased (SELL).
    bool set1 = rand() % 2;
    bool set2 = rand() % 2;
    bool set3 = rand() % 2;

    int vals[8] = {300, 400, 500, 600, 700, 800, 900, 1000};
    random_shuffle(&vals[0], &vals[8]);

    /// Create random prices.
    if (set1 == 0)
        dispPrice1 = prizes[0].getPrice() - vals[0];
    else
        dispPrice1 = prizes[0].getPrice() + vals[0];
    if (set2 == 0)
        dispPrice2 = prizes[1].getPrice() - vals[1];
    else
        dispPrice2 = prizes[1].getPrice() + vals[1];
    if (set3 == 0)
        dispPrice3 = prizes[2].getPrice() - vals[2];
    else
        dispPrice3 = prizes[2].getPrice() + vals[2];

    int bank = 0;

    char choice1 = 'A';
    char choice2 = 'A';
    char choice3 = 'A';

    cout << "Bank: $" << bank;
    cout << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "$" << dispPrice1;
    while ( (choice1 != 'B') && (choice1 != 'S') &&  (choice1 != 'b') && (choice1 != 's') ){
        cout << endl << "Do you want to buy this item (B) or sell it (S)?: ";
        cin >> choice1;
    }
    cout << endl << "2. ";
    prizes[1].showPrize();
    cout << endl << "$" << dispPrice2;
    while ( (choice2 != 'B') && (choice2 != 'S') &&  (choice2 != 'b') && (choice2 != 's') ){
        cout << endl << "Do you want to buy this item (B) or sell it (S)?: ";
        cin >> choice2;
    }
    cout << endl << "3. ";
    prizes[2].showPrize();
    cout << endl << "$" << dispPrice3;
    while ( (choice3 != 'B') && (choice3 != 'S') &&  (choice3 != 'b') && (choice3 != 's') ){
        cout << endl << "Do you want to buy this item (B) or sell it (S)?: ";
        cin >> choice3;
    }

    cout << endl << "Bank: $" << bank;
    if ( (choice1 == 'B') || (choice1 == 'b') )
    {
        cout << endl << "For the first item, you chose to BUY.";
        cout << endl << "The actual retail price is ";
        prizes[0].showARP();
        if (dispPrice1 <= prizes[0].getPrice())
        {
            bank += vals[0];
            cout << endl << "You've earned $" << vals[0] << ".";
        }
        else
        {
            bank -= vals[0];
            cout << endl << "You've lost $" << vals[0] << ".";
        }
    } // end if buy
    else
    {
        cout << endl << "For the first item, you chose to SELL.";
        cout << endl << "The actual retail price is ";
        prizes[0].showARP();
        if (dispPrice1 >= prizes[0].getPrice())
        {
            bank += vals[0];
            cout << endl << "You've earned $" << vals[0] << ".";
        }
        else
        {
            bank -= vals[0];
            cout << endl << "You've lost $" << vals[0] << ".";
        }
    } // end if sell

    cout << endl;
    system("pause");

    cout << endl << "Bank: $" << bank;
    if ( (choice2 == 'B') || (choice2 == 'b') )
    {
        cout << endl << "For the second item, you chose to BUY.";
        cout << endl << "The actual retail price is ";
        prizes[1].showARP();
        if (dispPrice2 <= prizes[1].getPrice())
        {
            bank += vals[1];
            cout << endl << "You've earned $" << vals[1] << ".";
        }
        else
        {
            bank -= vals[1];
            cout << endl << "You've lost $" << vals[1] << ".";
        }
    } // end if buy
    else
    {
        cout << endl << "For the second item, you chose to SELL.";
        cout << endl << "The actual retail price is ";
        prizes[1].showARP();
        if (dispPrice2 >= prizes[1].getPrice())
        {
            bank += vals[1];
            cout << endl << "You've earned $" << vals[1] << ".";
        }
        else
        {
            bank -= vals[1];
            cout << endl << "You've lost $" << vals[1] << ".";
        }
    } // end if sell

    cout << endl;
    system("pause");

    cout << endl << "Bank: $" << bank;
    if ( (choice3 == 'B') || (choice3 == 'b') )
    {
        cout << endl << "For the third item, you chose to BUY.";
        cout << endl << "The actual retail price is ";
        prizes[2].showARP();
        if (dispPrice3 <= prizes[2].getPrice())
        {
            bank += vals[2];
            cout << endl << "You've earned $" << vals[2] << ".";
        }
        else
        {
            bank -= vals[2];
            cout << endl << "You've lost $" << vals[2] << ".";
        }
    } // end if buy
    else
    {
        cout << endl << "For the third item, you chose to SELL.";
        cout << endl << "The actual retail price is ";
        prizes[2].showARP();
        if (dispPrice3 >= prizes[2].getPrice())
        {
            bank += vals[2];
            cout << endl << "You've earned $" << vals[2] << ".";
        }
        else
        {
            bank -= vals[2];
            cout << endl << "You've lost $" << vals[2] << ".";
        }
    } // end if sell
    cout << endl << endl;

    cout << "Bank: $" << bank;
    if (bank > 0)
        cout << endl << "Congratulations, you win the three prizes and $" << bank << "!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Clearance Sale
void playClearanceSale()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "CLEARANCE SALE" << endl;

    medium prizes[3];
    int clearancePrices[3];

    int val1 = rand() % i;
    int val2;
    int val3;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < val1; z++)
        gameItemIt++;
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());

    /// Sets a random number to generate the clearance price.
    int set1 = ( (rand() % 4)+1) * 100;
    clearancePrices[0] = prizes[0].getPrice() - set1;
    clearancePrices[0] = clearancePrices[0] - (clearancePrices[0] % 100);

//    prizes[0].showPrize();
//    cout << endl << "price: $" << prizes[0].getPrice();
//    cout << endl << "clearance price: $" << clearancePrices[0];

    /// Generate the second prize.
    bool setSecond = false;
    while (!setSecond){
    val2 = val1;
    while (val2 == val1)
        val2 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < val2; z++)
        gameItemIt++;
    if ( abs(prizes[0].getPrice() - gameItemIt->getPrice()) > 525 ){
        prizes[1].setDescription(gameItemIt->getDescription());
        prizes[1].setShortName(gameItemIt->getShortName());
        prizes[1].setPrice(gameItemIt->getPrice());
        setSecond = true;
    } // end if
    } // end while loop

    int set2 = ( (rand() % 4)+1) * 100;
    clearancePrices[1] = prizes[1].getPrice() - set2;
    clearancePrices[1] = clearancePrices[1] - (clearancePrices[1] % 100);

//    cout << endl << endl;
//    prizes[1].showPrize();
//    cout << endl << "price: $" << prizes[1].getPrice();
//    cout << endl << "clearance price: $" << clearancePrices[1];

    /// Generate the third prize.
    bool setThird = false;
    while (!setThird){
    val3 = val1;
    while ( (val3 == val1) || (val3 == val2) )
        val3 = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < val3; z++)
        gameItemIt++;
    if ( ( abs(prizes[0].getPrice() - gameItemIt->getPrice()) > 525 ) && ( abs(prizes[1].getPrice() - gameItemIt->getPrice()) > 525 ) ){
        prizes[2].setDescription(gameItemIt->getDescription());
        prizes[2].setShortName(gameItemIt->getShortName());
        prizes[2].setPrice(gameItemIt->getPrice());
        setThird = true;
    } // end if
    } // end while loop

    int set3 = ( (rand() % 4)+1) * 100;
    clearancePrices[2] = prizes[2].getPrice() - set3;
    clearancePrices[2] = clearancePrices[2] - (clearancePrices[2] % 100);

//    cout << endl << endl;
//    prizes[2].showPrize();
//    cout << endl << "price: $" << prizes[2].getPrice();
//    cout << endl << "clearance price: $" << clearancePrices[2];

    sortClearancePrices(clearancePrices);

    int choices[3];
    int order[3];

    bool picked[3];
    for (int p = 0; p < 3; p++)
        picked[p] = false;

    for (int c = 0; c < 3; c++)
        cout << endl << "$" << clearancePrices[c];
    cout << endl;

    for (int start = 0; start < 3; start++){
        for (int b = 0; b < 3; b++){
            cout << endl << b+1 << ". ";
            prizes[b].showPrize();
            if (picked[b]){
                cout << " - $" << choices[b];
                }
            } // end for loop showing prices
        cout << endl;
        int choice = 0;
        while ( (choice < 1) || (choice > 3) ){
            cout << endl << "Which item does the clearance price of $" << clearancePrices[start] << " go with?: ";
                cin >> choice;
            if (picked[choice-1]){
                cout << endl << "You've already chosen this item. Please pick another one.";
                choice = 0;
            }
        } // end while loop
    picked[choice-1] = true;
    choices[choice-1] = clearancePrices[start];
    //order[start] = clearancePrices[start];
    } // end for loop

    for (int b = 0; b < 3; b++){
        cout << endl << b+1 << ". ";
        prizes[b].showPrize();
        if (picked[b]){
            cout << " - $" << choices[b];
        }
    } // end for loop showing prices

    cout << endl;
    cout << endl << "Let's see if you've won.";
    cout << endl;
    system("pause");

    // show prize #1
    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is $" << prizes[0].getPrice();
    if (choices[0] < prizes[0].getPrice()){
    cout << endl;
    system("pause");

    // show prize #2
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is $" << prizes[1].getPrice();
    if (choices[1] < prizes[1].getPrice()){
    cout << endl;
    system("pause");

    // show prize #3
    cout << endl << "The actual retail price of the ";
    prizes[2].showShortName();
    cout << " is $" << prizes[2].getPrice();
    if (choices[2] < prizes[2].getPrice()){
        cout << endl << "Congratulations, you win!";
    }
    else
        cout << endl << "Sorry, you lose.";

    } // end if second prize has a valid clearance price
    else
        cout << endl << "Sorry, you lose.";

    } // end if first prize has a valid clearance price
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Clock Game
void playClockGame()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price < 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "CLOCK GAME" << endl;

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
    medium prizes[2];
    int chances = 45;
    bool won1 = false;
    bool won2 = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int bid = 0;
    int bid2 = 0;

    cout << "1. ";
    prizes[0].showPrize();
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << endl;
    while ((chances > 0) && !won1) /// Prize 1
    {
        cout << "Chances left: " << chances << endl;
        cout << "Your bid on the ";
        prizes[0].showShortName();
        cout << ": $";
        cin >> bid;
        if (bid == prizes[0].getPrice())
            won1 = true;
        else if (prizes[0].getPrice() > bid) /// HIGHER
        {
            cout << "HIGHER" << endl;
            chances -= 1;
        }
        else /// LOWER
        {
            cout << "LOWER" << endl;
            chances -= 1;
        }

    } /// end while loop
    if (won1)
        cout << endl << "You got it! On to the next item..." << endl;
    while ((chances > 0) && (won1 == true) && (won2 == false) ) /// Prize 2
    {
        cout << "Chances left: " << chances << endl;
        cout << "Your bid on the ";
        prizes[1].showShortName();
        cout << ": $";
        cin >> bid2;
        if (bid2 == prizes[1].getPrice())
            won2 = true;
        else if (prizes[1].getPrice() > bid2) /// HIGHER
        {
            cout << "HIGHER" << endl;
            chances -= 1;
        }
        else /// LOWER
        {
            cout << "LOWER" << endl;
            chances -= 1;
        }
    }

    if (won2) /// won both prizes
        cout << endl << "Congratulations, you won both prizes!";
    else if ((!won2) && (won1)) /// won the first prize
    {
        cout << endl << "Well, you at least won the ";
        prizes[0].showShortName();
        cout << ".";
    }
    else
    {
        cout << endl << "Sorry, you didn't win anything...";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Credit Card
void playCreditCard()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "CREDIT CARD" << endl;

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
    medium prizes[5];
    bool bought[5]; /// Denotes if the player has purchased the prize.
    int creditLimit = 0; /// The minimum amount the player must spend.

    int tempPrices[5]; /// This is used to calculate the credit limit.

    /// Initialize all the bought bools to false.
    for (int x = 0; x < 5; x++)
        bought[x] = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 5; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
        tempPrices[itemCount] = prizes[itemCount].getPrice();
    }

    int itemsChosen = 0;

    sortCredPrices(tempPrices);

    /// Create the credit limit by taking the prices of the three cheapest items
    /// and rounding their sum to the nearest hundred.
    creditLimit = tempPrices[0] + tempPrices[1] + tempPrices[2];
    creditLimit = ( (creditLimit + 99) / 100) * 100;

    while ( (itemsChosen < 3) && (creditLimit >= 0) )
    {
        for (int p = 0; p < 5; p++){
            cout << endl << p+1 << ". ";
            prizes[p].showPrize();
            if (bought[p])
                cout << " - $" << prizes[p].getPrice();
        }
        cout << endl << "Credit limit: $" << creditLimit;

        int choice = 0;
        while ( (choice < 1) || (choice > 5) ){
            cout << endl << "Which item do you want to purchase?: ";
                cin >> choice;
            if (bought[choice-1]){
                cout << endl << "You've already picked this item. Please pick another.";
                choice = 0;
            }
        }

        bought[choice-1] = true;
        cout << endl << "The actual retail price of the ";
        prizes[choice-1].showShortName();
        cout << " is $" << prizes[choice-1].getPrice();
        creditLimit -= prizes[choice-1].getPrice();
        cout << endl;
        itemsChosen += 1;

    } // end while loop

    if (creditLimit >= 0){
        cout << endl << "Credit limit: $" << creditLimit;
        cout << endl << "Congratulations, you win!";
    }
    else{
        cout << endl << "Credit limit: OVER";
        cout << endl << "Sorry, you lose.";
    }

    cout << endl;
    system("pause");
    system("CLS");
}

/// Danger Price
void playDangerPrice()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "DANGER PRICE" << endl;

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
    medium prizes[4];
    bool picked[4];
    int prizeWithDangerPrice = rand() % 4;

    /// Initialize all the picked bools to false.
    for (int x = 0; x < 4; x++)
        picked[x] = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Set the danger price.
    int dangerPrice = prizes[prizeWithDangerPrice].getPrice();

    int picks = 0;
    bool pickedDangerPrice = false;

    while ((picks < 3) && !pickedDangerPrice){
    cout << "Danger price: $" << dangerPrice << endl;
    for (int p = 0; p < 4; p++)
    {
        cout << p+1 << ". ";
        prizes[p].showPrize();
        if (picked[p])
        {
            cout << " - ";
            prizes[p].showARP();
        }
        cout << endl;
    } // end for loop

    int playerChoice = 0;
    cout << endl << "Which item (enter the number) would you like to pick?: ";
    cin >> playerChoice;
    switch (playerChoice){
    case 1:
        if (picked[0] == false)
        {
            cout << "The actual retail price of the ";
            prizes[0].showShortName();
            cout << " is ";
            prizes[0].showARP();
            cout << endl << endl;
            if (prizes[0].getPrice() == dangerPrice)
                pickedDangerPrice = true;
            else
            {
                picked[0] = true;
                picks += 1;
            }
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 2:
        if (picked[1] == false)
        {
            cout << "The actual retail price of the ";
            prizes[1].showShortName();
            cout << " is ";
            prizes[1].showARP();
            cout << endl << endl;
            if (prizes[1].getPrice() == dangerPrice)
                pickedDangerPrice = true;
            else
            {
                picked[1] = true;
                picks += 1;
            }
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 3:
        if (picked[2] == false)
        {
            cout << "The actual retail price of the ";
            prizes[2].showShortName();
            cout << " is ";
            prizes[2].showARP();
            cout << endl << endl;
            if (prizes[2].getPrice() == dangerPrice)
                pickedDangerPrice = true;
            else
            {
                picked[2] = true;
                picks += 1;
            }
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 4:
        if (picked[3] == false)
        {
            cout << "The actual retail price of the ";
            prizes[3].showShortName();
            cout << " is ";
            prizes[3].showARP();
            cout << endl << endl;
            if (prizes[3].getPrice() == dangerPrice)
                pickedDangerPrice = true;
            else
            {
                picked[3] = true;
                picks += 1;
            }
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    default:
        cout << endl << "That won't work. Try again.";

    } /// end switch statement

    } /// end while loop

    /// Determine results
    if (pickedDangerPrice)
        cout << "Sorry, you lose.";
    else
        cout << "Congratulations, you win!";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Do the Math
void playDoTheMath()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "DO THE MATH" << endl;

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
    medium prizes[2];

    int order = rand() % 2; /// if 0, the more expensive prize will be on the left. if 1,
                            /// the more expensive prize will be on the right.

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Cash bonus.
    int middle = abs(prizes[0].getPrice() - prizes[1].getPrice());

    bool prize0More = false;
    bool prize1More = false;

    bool zeroThenOne = false;
    bool oneThenZero = false;

    /// Display the board
    if (order == 0) /// The more expensive prize is on the left. The correct answer is MINUS.
    {
        if (prizes[0].getPrice() >= prizes[1].getPrice())
        {
            cout << "1. ";
            prizes[0].showPrize();
            cout << endl;
            cout << "2. ";
            prizes[1].showPrize();
            cout << endl;
            prize0More = true;
            zeroThenOne = true;
        }
        else
        {
            cout << "1. ";
            prizes[1].showPrize();
            cout << endl;
            cout << "2. ";
            prizes[0].showPrize();
            cout << endl;
            prize1More = true;
            oneThenZero = true;

        }

    }
    else /// The more expensive prize is on the right. The correct answer is PLUS.
    {
    if ( prizes[1].getPrice() >=  prizes[0].getPrice() )
    {
        cout << "1. ";
        prizes[0].showPrize();
        cout << endl;
        cout << "2. ";
        prizes[1].showPrize();
        cout << endl;
        prize1More = true;
        zeroThenOne = true;
    }
    else
    {
        cout << "1. ";
        prizes[1].showPrize();
        cout << endl;
        cout << "2. ";
        prizes[0].showPrize();
        cout << endl;
        prize0More = true;
        oneThenZero = true;
    }

    } // end if

    cout << endl;

    if (zeroThenOne == true)
    {
        cout << "1. ";
        prizes[0].showShortName();
        cout << " + " << middle << " = ";
        prizes[1].showShortName();
        cout << endl;
        cout << "2. ";
        prizes[0].showShortName();
        cout << " - " << middle << " = ";
        prizes[1].showShortName();
        cout << endl;
    }
    else if (oneThenZero == true)
    {
        cout << "1. ";
        prizes[1].showShortName();
        cout << " + " << middle << " = ";
        prizes[0].showShortName();
        cout << endl;
        cout << "2. ";
        prizes[1].showShortName();
        cout << " - " << middle << " = ";
        prizes[0].showShortName();
        cout << endl;
    }

    /*
    if (order == 0)
        cout << endl << "The more expensive prize is on the left" << endl;
    else
        cout << endl << "The more expensive prize is on the right" << endl;
    */

    int choice = 0;
    while ((choice < 1) || (choice > 2))
    {
        cout << endl << "Which equation (enter the number) is correct?: ";
        cin >> choice;
    }

    if (zeroThenOne)
    {
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        if ( (prize0More) && choice == 2 )
            cout << endl << "Congratulations, you win!";
        else if ( (prize1More) && choice == 1 )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        if ( (prize1More) && choice == 2 )
            cout << endl << "Congratulations, you win!";
        else if ( (prize0More) && choice == 1 )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }



    cout << endl;
    system("pause");
    system("CLS");
}

/// Double Cross
void playDoubleCross()
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
    inFile.open("large.txt");
    while (inFile)
    {
    pptr = new large;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price < 10000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    int first;
    int second;

    int outcome = rand() % 4;

    large prizes[2];

    cout << "DOUBLE CROSS" << endl;

    bool setup = false;
    large temp1;
    large temp2;

    while (!setup){
        first = rand() % i;
        second = first;
        while (second == first)
            second = rand() % i;

        int digit1 = 0;
        int digit2 = 0;

        /// Set item #1
        gameItemIt = gameItems.begin();
        for (int z = 0; z < first; z++)
            gameItemIt++;
        temp1.setDescription(gameItemIt->getDescription());
        temp1.setShortName(gameItemIt->getShortName());
        temp1.setPrice(gameItemIt->getPrice());

        /// Set item #2
        gameItemIt = gameItems.begin();
        for (int z = 0; z < second; z++)
            gameItemIt++;
        temp2.setDescription(gameItemIt->getDescription());
        temp2.setShortName(gameItemIt->getShortName());
        temp2.setPrice(gameItemIt->getPrice());

        if (outcome == 0) /// Last digit of prize 1 and first digit of prize 2 are the same
        {
        digit1 = temp1.getPrice() % 10;
        digit2 = temp2.getPrice() / 1000 % 10;
        if (digit1 == digit2)
        {
            prizes[0].setDescription(temp1.getDescription());
            prizes[0].setShortName(temp1.getShortName());
            prizes[0].setPrice(temp1.getPrice());

            prizes[1].setDescription(temp2.getDescription());
            prizes[1].setShortName(temp2.getShortName());
            prizes[1].setPrice(temp2.getPrice());

            setup = true;
        }
        } // end if outcome = 0

        else if (outcome == 1) /// Third digit of prize 1 and second digit of prize 2 are the same
        {
        digit1 = temp1.getPrice() / 10 % 10;
        digit2 = temp2.getPrice() / 100 % 10;
        if (digit1 == digit2)
        {
            prizes[0].setDescription(temp1.getDescription());
            prizes[0].setShortName(temp1.getShortName());
            prizes[0].setPrice(temp1.getPrice());

            prizes[1].setDescription(temp2.getDescription());
            prizes[1].setShortName(temp2.getShortName());
            prizes[1].setPrice(temp2.getPrice());

            setup = true;
        }
        } // end if outcome = 1

        else if (outcome == 2) /// Second digit of prize 1 and third digit of prize 2 are the same
        {
        digit1 = temp1.getPrice() / 100 % 10;
        digit2 = temp2.getPrice() / 10 % 10;
        if (digit1 == digit2)
        {
            prizes[0].setDescription(temp1.getDescription());
            prizes[0].setShortName(temp1.getShortName());
            prizes[0].setPrice(temp1.getPrice());

            prizes[1].setDescription(temp2.getDescription());
            prizes[1].setShortName(temp2.getShortName());
            prizes[1].setPrice(temp2.getPrice());

            setup = true;
        }
        } // end if outcome = 2

        else /// First digit of prize 1 and last digit of prize 2 are the same
        {
        digit1 = temp1.getPrice() / 1000 % 10;
        digit2 = temp2.getPrice() % 10;
        if (digit1 == digit2)
        {
            prizes[0].setDescription(temp1.getDescription());
            prizes[0].setShortName(temp1.getShortName());
            prizes[0].setPrice(temp1.getPrice());

            prizes[1].setDescription(temp2.getDescription());
            prizes[1].setShortName(temp2.getShortName());
            prizes[1].setPrice(temp2.getPrice());

            setup = true;
        }
        }

    } // end while loop

    /// Initialize and set the gameplay up.
    int green[7];
    int yellow[7];

    if (outcome == 0){
        green[0] = prizes[0].getPrice() / 1000 % 10;
        green[1] = prizes[0].getPrice() / 100 % 10;
        green[2] = prizes[0].getPrice() / 10 % 10;
        green[3] = prizes[0].getPrice() % 10;
        green[4] = rand() % 10;
        green[5] = rand() % 10;
        green[6] = rand() % 10;

        yellow[0] = (rand() % 9) + 1;
        yellow[1] = (rand() % 9) + 1;
        yellow[2] = (rand() % 9) + 1;
        yellow[3] = prizes[1].getPrice() / 1000 % 10;
        yellow[4] = prizes[1].getPrice() / 100 % 10;
        yellow[5] = prizes[1].getPrice() / 10 % 10;
        yellow[6] = prizes[1].getPrice() % 10;
    }
    else if (outcome == 1){
        green[0] = (rand() % 9) + 1;
        green[1] = prizes[0].getPrice() / 1000 % 10;
        green[2] = prizes[0].getPrice() / 100 % 10;
        green[3] = prizes[0].getPrice() / 10 % 10;
        green[4] = prizes[0].getPrice() % 10;
        green[5] = rand() % 10;
        green[6] = rand() % 10;

        yellow[0] = (rand() % 9) + 1;
        yellow[1] = (rand() % 9) + 1;
        yellow[2] = prizes[1].getPrice() / 1000 % 10;
        yellow[3] = prizes[1].getPrice() / 100 % 10;
        yellow[4] = prizes[1].getPrice() / 10 % 10;
        yellow[5] = prizes[1].getPrice() % 10;
        yellow[6] = rand() % 10;
    }
    else if (outcome == 2){
        green[0] = (rand() % 9) + 1;
        green[1] = (rand() % 9) + 1;
        green[2] = prizes[0].getPrice() / 1000 % 10;
        green[3] = prizes[0].getPrice() / 100 % 10;
        green[4] = prizes[0].getPrice() / 10 % 10;
        green[5] = prizes[0].getPrice() % 10;
        green[6] = rand() % 10;

        yellow[0] = (rand() % 9) + 1;
        yellow[1] = prizes[1].getPrice() / 1000 % 10;
        yellow[2] = prizes[1].getPrice() / 100 % 10;
        yellow[3] = prizes[1].getPrice() / 10 % 10;
        yellow[4] = prizes[1].getPrice() % 10;
        yellow[5] = rand() % 10;
        yellow[6] = rand() % 10;
    }
    else{
        green[0] = (rand() % 9) + 1;
        green[1] = (rand() % 9) + 1;
        green[2] = (rand() % 9) + 1;
        green[3] = prizes[0].getPrice() / 1000 % 10;
        green[4] = prizes[0].getPrice() / 100 % 10;
        green[5] = prizes[0].getPrice() / 10 % 10;
        green[6] = prizes[0].getPrice() % 10;

        yellow[0] = prizes[1].getPrice() / 1000 % 10;
        yellow[1] = prizes[1].getPrice() / 100 % 10;
        yellow[2] = prizes[1].getPrice() / 10 % 10;
        yellow[3] = prizes[1].getPrice() % 10;
        yellow[4] = rand() % 10;
        yellow[5] = rand() % 10;
        yellow[6] = rand() % 10;
    }

    cout << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "2. ";
    prizes[1].showPrize();

    cout << endl;

    cout << endl << green[0] << "*****" << yellow[6];
    cout << endl << "*" << green[1] << "***" << yellow[5] << "*";
    cout << endl << "**" << green[2] << "*" << yellow[4] << "**";
    cout << endl << "***" << green[3] << "***";
    cout << endl << "**" << yellow[2] << "*" << green[4] << "**";
    cout << endl << "*" << yellow[1] << "***" << green[5] << "*";
    cout << endl << yellow[0] << "*****" << green[6];

    /*
    cout << endl << "outcome = " << outcome;
    cout << endl << "price1 = $" << prizes[0].getPrice();
    cout << endl << "price2 = $" << prizes[1].getPrice();
    */

    cout << endl << "1. 1 = $" << green[0] << green[1] << green[2] << green[3] << ", ";
    cout << "2 = $" << yellow[3] << yellow[4] << yellow[5] << yellow[6];

    cout << endl << "2. 1 = $" << green[1] << green[2] << green[3] << green[4] << ", ";
    cout << "2 = $" << yellow[2] << yellow[3] << yellow[4] << yellow[5];

    cout << endl << "3. 1 = $" << green[2] << green[3] << green[4] << green[5] << ", ";
    cout << "2 = $" << yellow[1] << yellow[2] << yellow[3] << yellow[4];

    cout << endl << "4. 1 = $" << green[3] << green[4] << green[5] << green[6] << ", ";
    cout << "2 = $" << yellow[0] << yellow[1] << yellow[2] << yellow[3];

    int choice = 0;
    while ( (choice < 1) || (choice > 4) ){
        cout << endl << "What is the correct arrangement?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is $" << prizes[0].getPrice();
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is $" << prizes[1].getPrice();

    cout << endl;

    if (choice-1 == outcome)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// End of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Easy as 1-2-3
void playEasyAs123()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "EASY AS 1-2-3" << endl;

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
    medium prizes[3];

    /// Denotes which items correspond to which block.
    int leastExpensive = -1;
    int midExpensive = -1;
    int mostExpensive = -1;

    /// Checks if the player has placed a block by an item.
    bool hasBlockPlaced[3];
    for (int j = 0; j < 3; j++)
        hasBlockPlaced[j] = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    cout << "1. ";
    prizes[0].showPrize();
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << endl;
    cout << "3. ";
    prizes[2].showPrize();
    cout << endl;

    while ((leastExpensive < 1) || (leastExpensive > 3))
    {
    cout << "What is the least expensive prize?: ";
    cin >> leastExpensive;
    }
    hasBlockPlaced[leastExpensive-1] = true;

    //midExpensive = leastExpensive;
    //mostExpensive = leastExpensive;
    cout << endl;

    cout << "1. ";
    prizes[0].showPrize();
    if (leastExpensive == 1)
        cout << " - 1";
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    if (leastExpensive == 2)
        cout << " - 1";
    cout << endl;
    cout << "3. ";
    prizes[2].showPrize();
    if (leastExpensive == 3)
        cout << " - 1";
    cout << endl;

    int finalInput;
    hasBlockPlaced[midExpensive] = false; /// asserts this value as FALSE
    while ( ((midExpensive < 1) || (midExpensive > 3)) && (!hasBlockPlaced[midExpensive]) )
    {
        cout << "What is the next least expensive prize?: ";
        cin >> midExpensive;
        finalInput = midExpensive;

        /// This checks if the player attempts to place a block on a prize that already has a block.
        if (midExpensive != leastExpensive)
            hasBlockPlaced[midExpensive] = true;
        else
            midExpensive = 4;
    }

    //cout << "midExpensive = " << midExpensive << endl;
    //cout << "finalInput = " << finalInput << endl;
    cout << endl;
    cout << "1. ";
    prizes[0].showPrize();
    if (leastExpensive == 1)
        cout << " - 1";
    else if (finalInput == 1)
        cout << " - 2";
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    if (leastExpensive == 2)
        cout << " - 1";
    else if (finalInput == 2)
        cout << " - 2";
    cout << endl;
    cout << "3. ";
    prizes[2].showPrize();
    if (leastExpensive == 3)
        cout << " - 1";
    else if (finalInput == 3)
        cout << " - 2";
    cout << endl;

    /// The item the player didn't pick is therefore the most expensive.
    if ((leastExpensive == 1) && (finalInput == 2))
    {
        cout << "Therefore, the ";
        prizes[2].showShortName();
        cout << " must be the most expensive." << endl;
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        if ( prizes[1].getPrice() >= prizes[0].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        if ( prizes[2].getPrice() >= prizes[1].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }
    } /// end if
    else if ((leastExpensive == 1) && (finalInput == 3))
    {
        cout << "Therefore, the ";
        prizes[1].showShortName();
        cout << " must be the most expensive." << endl;
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        if ( prizes[2].getPrice() >= prizes[0].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        if ( prizes[1].getPrice() >= prizes[2].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }


    } /// end if


    else if ((leastExpensive == 2) && (finalInput == 1))
    {
        cout << "Therefore, the ";
        prizes[2].showShortName();
        cout << " must be the most expensive." << endl;

        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        if ( prizes[0].getPrice() >= prizes[1].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        if ( prizes[2].getPrice() >= prizes[0].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }

    } /// end if


    else if ((leastExpensive == 2) && (finalInput == 3))
    {
        cout << "Therefore, the ";
        prizes[0].showShortName();
        cout << " must be the most expensive." << endl;
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        if ( prizes[2].getPrice() >= prizes[1].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        if ( prizes[0].getPrice() >= prizes[2].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }
    } /// end if


    else if ((leastExpensive == 3) && (finalInput == 1))
    {
        cout << "Therefore, the ";
        prizes[1].showShortName();
        cout << " must be the most expensive." << endl;

        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        if ( prizes[0].getPrice() >= prizes[2].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        if ( prizes[1].getPrice() >= prizes[0].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }


    } /// end if


    else if ((leastExpensive == 3) && (finalInput == 2))
    {
        cout << "Therefore, the ";
        prizes[0].showShortName();
        cout << " must be the most expensive." << endl;

        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        if ( prizes[1].getPrice() >= prizes[2].getPrice() )
        {
        system("pause");
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        if ( prizes[0].getPrice() >= prizes[1].getPrice() )
            {
                cout << endl << "Congratulations, you win!";
            }
        else
            {
                cout << endl << "Sorry, you lose.";
            }


        } /// end if statement comparing prize #2 to prize #1
        else
        {
            cout << endl << "Sorry, you lose.";
        }


    } /// end if


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");

}

/// Fortune Hunter
void playFortuneHunter()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "FORTUNE HUNTER" << endl;

    medium prizes[4];
    bool eliminated[4];
    for (int e = 0; e < 4; e++)
            eliminated[e] = false;

    /// The order in which the prizes will be revealed.
    int order[3];

    /// The id of the prize that contains the $5000.
    int fortunePrize = rand() % 4;

    if (fortunePrize == 0){
        order[0] = 1;
        order[1] = 2;
        order[2] = 3;
    }
    else if (fortunePrize == 1){
        order[0] = 0;
        order[1] = 2;
        order[2] = 3;
    }
    else if (fortunePrize == 2){
        order[0] = 0;
        order[1] = 1;
        order[2] = 3;
    }
    else{
        order[0] = 0;
        order[1] = 1;
        order[2] = 2;
    }

    int first = rand() % i;
    int second;
    int third;
    int fourth;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());


    bool setSecond = false;
    while (!setSecond){
    second = first;
    while (second == first)
        second = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) ){
        prizes[1].setDescription(gameItemIt->getDescription());
        prizes[1].setShortName(gameItemIt->getShortName());
        prizes[1].setPrice(gameItemIt->getPrice());
        setSecond = true;
    }
    } // end setting second item

    bool setThird = false;
    while (!setThird){
    third = first;
    while ((third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) && (gameItemIt->getPrice()) != (prizes[1].getPrice()) ){
        prizes[2].setDescription(gameItemIt->getDescription());
        prizes[2].setShortName(gameItemIt->getShortName());
        prizes[2].setPrice(gameItemIt->getPrice());
        setThird = true;
    }
    } // end setting third item

    bool setFourth = false;
    while (!setFourth){
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) && (gameItemIt->getPrice()) != (prizes[1].getPrice()) && (gameItemIt->getPrice()) != (prizes[2].getPrice()) ){
        prizes[3].setDescription(gameItemIt->getDescription());
        prizes[3].setShortName(gameItemIt->getShortName());
        prizes[3].setPrice(gameItemIt->getPrice());
        setFourth = true;
    }
    } // end setting fourth item

    /// Set the least expensive prize
    int leastExpensive = prizes[0].getPrice();
    if (prizes[1].getPrice() < leastExpensive)
        leastExpensive = prizes[1].getPrice();
    if (prizes[2].getPrice() < leastExpensive)
        leastExpensive = prizes[2].getPrice();
    if (prizes[3].getPrice() < leastExpensive)
        leastExpensive = prizes[3].getPrice();

    /// Set the most expensive prize
    int mostExpensive = prizes[0].getPrice();
    if (prizes[1].getPrice() > mostExpensive)
        mostExpensive = prizes[1].getPrice();
    if (prizes[2].getPrice() > mostExpensive)
        mostExpensive = prizes[2].getPrice();
    if (prizes[3].getPrice() > mostExpensive)
        mostExpensive = prizes[3].getPrice();

    /*
    for (int p = 0; p < 4; p++)
        cout << endl << "$" << prizes[p].getPrice();
    cout << endl;
    cout << endl << "Least expensive: $" << leastExpensive;
    cout << endl << "Most expensive: $" << mostExpensive;
    */

    random_shuffle(&order[0], &order[3]);

    int gone = 0;
    while (gone < 3){
        for (int s = 0; s < 4; s++){
            cout << endl << s+1 << ". ";
            prizes[s].showPrize();
            if (eliminated[s])
                cout << " - X";
        }
        int choice = 0;
        while ( (choice < 1) || (choice > 4) ){
            //prizes[order[gone]].getPrice();
            if ( (prizes[order[gone]].getPrice()) == leastExpensive )
                cout << endl << "Eliminate the prize that is the least expensive: ";
            else if ( (prizes[order[gone]].getPrice()) == mostExpensive )
                cout << endl << "Eliminate the prize that is the most expensive: ";
            else
                cout << endl << "Eliminate the prize that is worth $" << prizes[order[gone]].getPrice() << ": ";
            cin >> choice;
            if (eliminated[choice-1]){
                cout << endl << "You've already eliminated this prize. Please pick another one.";
                choice = 0;
            }
        } // end entry while loop
        eliminated[choice-1] = true;
        gone++;
    }

    /// Find the prize that the player didn't eliminate.
    int remaining;
    if (!eliminated[0])
        remaining = 0;
    else if (!eliminated[1])
        remaining = 1;
    else if (!eliminated[2])
        remaining = 2;
    else
        remaining = 3;

    cout << endl << "The ";
    prizes[remaining].showShortName();
    cout << " is the remaining item now.";
    cout << endl << "Let's see if it has the $5000.";
    cout << endl;
    system("pause");
    if (remaining == fortunePrize)
        cout << endl << "Congratulations, you won $5000 and the four prizes!";
    else{
        cout << endl << "Sorry, you lose. \nThe box containing the $5000 was by the ";
        prizes[fortunePrize].showShortName();
        cout << ".";
        }

    cout << endl;
    system("pause");
    system("CLS");
}

/// Magic #
void playMagicNumber()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "MAGIC #" << endl;

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
    medium prizes[2];

    /// Set each item
    /*
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }
    */

    gameItemIt = gameItems.begin();
    for (z = 0; z < randomizationField[0]; z++)
        gameItemIt++;
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());

    int tempPrice = prizes[0].getPrice();
    bool ideal = false;
    int to = 1;

    while (!ideal){
    gameItemIt = gameItems.begin();
    for (int z2 = 0; z2 < randomizationField[to]; z2++)
        gameItemIt++;
    if (abs( (gameItemIt->getPrice()) - prizes[0].getPrice() ) >= 750){
    ideal = true;
    prizes[1].setDescription(gameItemIt->getDescription());
    prizes[1].setShortName(gameItemIt->getShortName());
    prizes[1].setPrice(gameItemIt->getPrice());
    }
    else
        to += 1;
    }

    int side = 0;
    int magicNo = 0;

    if (prizes[0].getPrice() < prizes[1].getPrice()){
    side = 1;
    cout << endl << "1. ";
    prizes[0].showPrize();
    cout << endl << "2. ";
    prizes[1].showPrize();
    }
    else
    {
    side = 2;
    cout << endl << "1. ";
    prizes[1].showPrize();
    cout << endl << "2. ";
    prizes[0].showPrize();
    }

    cout << endl << "Enter a number that falls between the two items' prices: ";
    cin >> magicNo;

    if (side == 1) /// prizes[1] is more expensive
    {
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();

        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();

        if ( (magicNo >= prizes[0].getPrice()) && (magicNo <= prizes[1].getPrice()) )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else
    {
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();

        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();

        if ( (magicNo >= prizes[1].getPrice()) && (magicNo <= prizes[0].getPrice()) )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }

    /// End of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Make Your Mark
void playMakeYourMark()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "MAKE YOUR MARK" << endl;

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
    medium prizes[3];

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int markings[4];
    markings[0] = prizes[0].getPrice();
    markings[1] = prizes[1].getPrice();
    markings[2] = prizes[2].getPrice();
    markings[3] = prizes[0].getPrice();
    while ( (markings[3] == markings[0]) || (markings[3] == markings[1]) || (markings[3] == markings[2]) ){
        markings[3] = rand()%(3500-1000 + 1) + 1000;
    }
    random_shuffle(&markings[0], &markings[4]);

    bool picked[4];
    for (int p = 0; p < 4; p++)
        picked[p] = false;

    for (int q = 0; q < 3; q++){
        cout << q+1 << ". ";
        prizes[q].showPrize();
        cout << endl;
    }

    int marksMade = 0;
    int markedPrices[3];

    while (marksMade < 3){

        /// Show board
        cout << endl;
        if (picked[0])
            cout << "*. $" << markings[0];
        else
            cout << "A. $" << markings[0];
        if (picked[1])
            cout << "   *. $" << markings[1];
        else
            cout << "   B. $" << markings[1];
        if (picked[2])
            cout << endl << "*. $" << markings[2];
        else
            cout << endl << "C. $" << markings[2];
        if (picked[3])
            cout << "   *. $" << markings[3];
        else
            cout << "   D. $" << markings[3];

        cout << endl;
        char choice = '!';
        while ( (choice != 'A') && (choice != 'B') && (choice != 'C') && (choice != 'D') && (choice != 'a') && (choice != 'b') && (choice != 'c') && (choice != 'd') ){
            cout << endl << "Where do you want to place a mark?: ";
            cin >> choice;
        }
        if ( ((choice == 'A') || (choice == 'a')) && picked[0] )
            cout << endl << "You've already chosen this price. Please pick another.";
        else if ( ((choice == 'B') || (choice == 'b')) && picked[1] )
            cout << endl << "You've already chosen this price. Please pick another.";
        else if ( ((choice == 'C') || (choice == 'c')) && picked[2] )
            cout << endl << "You've already chosen this price. Please pick another.";
        else if ( ((choice == 'D') || (choice == 'd')) && picked[3] )
            cout << endl << "You've already chosen this price. Please pick another.";
        else if ( ((choice == 'A') || (choice == 'a')) && !picked[0] ){
            picked[0] = true;
            markedPrices[marksMade] = markings[0];
            marksMade += 1;
        }
        else if ( ((choice == 'B') || (choice == 'b')) && !picked[1] ){
            picked[1] = true;
            markedPrices[marksMade] = markings[1];
            marksMade += 1;
        }
        else if ( ((choice == 'C') || (choice == 'c')) && !picked[2] ){
            picked[2] = true;
            markedPrices[marksMade] = markings[2];
            marksMade += 1;
        }
        else if ( ((choice == 'D') || (choice == 'd')) && !picked[3] ){
            picked[3] = true;
            markedPrices[marksMade] = markings[3];
            marksMade += 1;
        }

    } /// end while loop of player setting marks

    /// Show board again
    cout << endl;
    if (picked[0])
        cout << "*. $" << markings[0];
    else
        cout << "A. $" << markings[0];
    if (picked[1])
        cout << "   *. $" << markings[1];
    else
        cout << "   B. $" << markings[1];
    if (picked[2])
        cout << endl << "*. $" << markings[2];
    else
        cout << endl << "C. $" << markings[2];
    if (picked[3])
        cout << "   *. $" << markings[3];
    else
        cout << "   D. $" << markings[3];

    cout << endl;

    int unchosen;
    if ( (picked[0]) && (picked[1]) && (picked[2]) )
        unchosen = markings[3];
    else if ( (picked[0]) && (picked[1]) && (picked[3]) )
        unchosen = markings[2];
    else if ( (picked[0]) && (picked[2]) && (picked[3]) )
        unchosen = markings[1];
    else
        unchosen = markings[0];

    //cout << endl << "Unchosen price: $" << unchosen;


    cout << endl << "Now, let's reveal two prices you have right.";
    cout << endl;
    system("pause");

    int revealed = 0;

    bool hasRight[3];
    for (int s = 0; s < 3; s++)
        hasRight[s] = false;

    /// First price
    if (prizes[0].getPrice() == markedPrices[0]){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
        hasRight[0] = true;
        revealed += 1;
    }
    else if (prizes[1].getPrice() == markedPrices[0]){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
        hasRight[1] = true;
        revealed += 1;
    }
    else if (prizes[2].getPrice() == markedPrices[0]){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
        hasRight[2] = true;
        revealed += 1;
    }

    /// Second price
    if (prizes[0].getPrice() == markedPrices[1]){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
        hasRight[0] = true;
        revealed += 1;
    }
    else if (prizes[1].getPrice() == markedPrices[1]){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
        hasRight[1] = true;
        revealed += 1;
    }
    else if (prizes[2].getPrice() == markedPrices[1]){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
        hasRight[2] = true;
        revealed += 1;
    }

    /// Third price
    if ( (prizes[0].getPrice() == markedPrices[2]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
        hasRight[0] = true;
        revealed += 1;
    }
    else if ( (prizes[1].getPrice() == markedPrices[2]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
        hasRight[1] = true;
        revealed += 1;
    }
    else if ( (prizes[2].getPrice() == markedPrices[2]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
        hasRight[2] = true;
        revealed += 1;
    }

    /// Fourth price
    if ( (prizes[0].getPrice() == markedPrices[3]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
        hasRight[0] = true;
        revealed += 1;
    }
    else if ( (prizes[1].getPrice() == markedPrices[3]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
        hasRight[1] = true;
        revealed += 1;
    }
    else if ( (prizes[2].getPrice() == markedPrices[3]) && (revealed < 2) ){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
        hasRight[2] = true;
        revealed += 1;
    }

    int swapID;
    if ( (hasRight[0]) && (hasRight[1]) )
        swapID = 2;
    else if ( (hasRight[0]) && (hasRight[2]) )
        swapID = 1;
    else
        swapID = 0;

    char toSwap = '!';

    while ( (toSwap != 'Y') && (toSwap != 'N') &&  (toSwap != 'y') && (toSwap != 'n') ){
        cout << endl << "For the ";
        prizes[swapID].showShortName();
        cout << ", do you want to" << endl << "- leave the marker where it is (Y) or " << endl << "- change it to $" << unchosen << " and give up $500 (N)?: ";
        cin >> toSwap;
    }
    if ((toSwap == 'Y') || (toSwap == 'y')){
        cout << endl << "The actual retail price of the ";
        prizes[swapID].showShortName();
        cout << " is $" << prizes[swapID].getPrice();
        if (prizes[swapID].getPrice() != unchosen)
            cout << endl << "Congratulations, you win the prizes and $500!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else{
        cout << endl << "The actual retail price of the ";
        prizes[swapID].showShortName();
        cout << " is $" << prizes[swapID].getPrice();
        if (prizes[swapID].getPrice() == unchosen)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Make Your Move
void playMakeYourMove()
{
    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;
    string t_Description;
    string t_ShortName;
    int t_Price;
    medium * pptr;

    list<small> gameItemsSmall;
    list<small>::iterator gameItemsSmallIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    small * sptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    int k = 0;

    ifstream inFile;

    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price < 1000)
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

    inFile.open("large.txt");
    while (inFile)
    {
    lptr = new large;
    if ( (inFile >> l_Description >> l_ShortName >> l_Price) && l_Price < 10000)
    {
        lptr->setDescription(l_Description);
        lptr->setShortName(l_ShortName);
        lptr->setPrice(l_Price);
        gameItemsLarge.push_back(*lptr);
        j++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    inFile.open("small.txt");
    while (inFile)
    {
    sptr = new small;
    if ( (inFile >> s_Description >> s_ShortName >> s_Price) && s_Price < 100)
    {
        sptr->setDescription(s_Description);
        sptr->setShortName(s_ShortName);
        sptr->setPrice(s_Price);
        gameItemsSmall.push_back(*sptr);
        k++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "MAKE YOUR MOVE" << endl;

    cout << endl;
    int randomMediumNo = rand() % i;
    int randomLargeNo = rand() % j;
    int randomSmallNo = rand() % k;

    int z = 0;
    int z2 = 0;
    int z3 = 0;

    small twodigit;
    medium threedigit;
    large fourdigit;

    /// Set the large prize.
    gameItemsLargeIt = gameItemsLarge.begin();
    for (z = 0; z < randomLargeNo; z++)
        gameItemsLargeIt++;
    fourdigit.setDescription(gameItemsLargeIt->getDescription());
    fourdigit.setShortName(gameItemsLargeIt->getShortName());
    fourdigit.setPrice(gameItemsLargeIt->getPrice());

    /// Set the medium prize
    gameItemIt = gameItems.begin();
    for (z2 = 0; z2 < randomMediumNo; z2++)
        gameItemIt++;
    threedigit.setDescription(gameItemIt->getDescription());
    threedigit.setShortName(gameItemIt->getShortName());
    threedigit.setPrice(gameItemIt->getPrice());

    /// Set the small prize
    gameItemsSmallIt = gameItemsSmall.begin();
    for (z3 = 0; z3 < randomSmallNo; z3++)
        gameItemsSmallIt++;
    twodigit.setDescription(gameItemsSmallIt->getDescription());
    twodigit.setShortName(gameItemsSmallIt->getShortName());
    twodigit.setPrice(gameItemsSmallIt->getPrice());

    twodigit.showPrize();
    cout << endl;
    threedigit.showPrize();
    cout << endl;
    fourdigit.showPrize();
    cout << endl;

    /// Determines the order the prices show up on the board.
    int order = rand() % 6;

    string board;
    string playerInput;

    /// Display the prices.
    if (order == 0) /// SMALL, MEDIUM, LARGE
        board = to_string(twodigit.getPrice()) + to_string(threedigit.getPrice()) + to_string(fourdigit.getPrice());
    else if (order == 1) /// SMALL, LARGE, MEDIUM
        board = to_string(twodigit.getPrice()) + to_string(fourdigit.getPrice()) + to_string(threedigit.getPrice());
    else if (order == 2) /// MEDIUM, SMALL, LARGE
        board = to_string(threedigit.getPrice()) + to_string(twodigit.getPrice()) + to_string(fourdigit.getPrice());
    else if (order == 3) /// MEDIUM, LARGE, SMALL
        board = to_string(threedigit.getPrice()) + to_string(fourdigit.getPrice()) + to_string(twodigit.getPrice());
    else if (order == 4) /// LARGE, SMALL, MEDIUM
        board = to_string(fourdigit.getPrice()) + to_string(twodigit.getPrice()) + to_string(threedigit.getPrice());
    else                /// LARGE, MEDIUM, SMALL
        board = to_string(fourdigit.getPrice()) + to_string(threedigit.getPrice()) + to_string(twodigit.getPrice());

    cout << endl << board;

    int first = 0;
    int second = 0;
    int third = 0;

    cout << endl;
    cout << endl << "1. ";
    twodigit.showShortName();
    cout << endl << "2. ";
    threedigit.showShortName();
    cout << endl << "3. ";
    fourdigit.showShortName();
    while ( (first < 1) || (first > 3) ){
    cout << endl << "Which would you like to place on the left?: ";
    cin >> first;
    }
    cout << endl << board;
    if (first == 1){
        playerInput += "AA";
    }
    else if (first == 2){
        playerInput += "AAA";
    }
    else{
        playerInput += "AAAA";
    }
    cout << endl << playerInput;
    cout << endl;
    cout << endl << "1. ";
    twodigit.showShortName();
    cout << endl << "2. ";
    threedigit.showShortName();
    cout << endl << "3. ";
    fourdigit.showShortName();

    while ( ( (second < 1) || (second > 3) ) || (second == first)){
    cout << endl << "Which would you like to place next?: ";
    cin >> second;
    }
    if (second == 1){
        playerInput += "BB";
    }
    else if (second == 2){
        playerInput += "BBB";
    }
    else{
        playerInput += "BBBB";
    }

    /// The four-digit price went unused.
    if ( ((first == 1) && (second == 2)) || ((first == 2) && (second == 1)) )
    {
        playerInput += "CCCC";
    }
    /// The three-digit price went unused.
    else if ( ((first == 1) && (second == 3)) || ((first == 3) && (second == 1)) )
    {
        playerInput += "CCC";
    }
    /// The two-digit price went unused.
    else
    {
        playerInput += "CC";
    }

    cout << endl << "Here's what you've set the prices to: ";
    cout << endl << board;
    cout << endl << playerInput;

    cout << endl;
    system("pause");

    bool won = false;

    if ( (order == 0) && ( (first == 1) && (second == 2) ) )
        won = true;
    else if ( (order == 1) && ( (first == 1) && (second == 3) ) )
        won = true;
    else if ( (order == 2) && ( (first == 2) && (second == 1) ) )
        won = true;
    else if ( (order == 3) && ( (first == 2) && (second == 3) ) )
        won = true;
    else if ( (order == 4) && ( (first == 3) && (second == 1) ) )
        won = true;
    else if ( (order == 5) && ( (first == 3) && (second == 2) ) )
        won = true;

    cout << endl << "The prices of the items are: ";
    cout << endl;
    twodigit.showShortName();
    cout << " - $" << twodigit.getPrice();
    cout << endl;
    threedigit.showShortName();
    cout << " - $" << threedigit.getPrice();
    cout << endl;
    fourdigit.showShortName();
    cout << " - $" << fourdigit.getPrice();
    cout << endl;

    if (won)
        cout << endl << "Congratulations, you won!";
    else
        cout << endl << "Sorry, you lose.";


    /// End of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Most Expensive
void playMostExpensive()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "MOST EXPENSIVE" << endl;

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
    medium prizes[3];
    int playerChoice = 0;

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Display the prizes.
    for (int j = 0; j < 3; j++){
    cout << j+1 << ". ";
    prizes[j].showPrize();
    cout << endl;
    }

    while ((playerChoice < 1) || (playerChoice > 3)){
    cout << endl << "Which prize (enter the number) is the most expensive?: ";
    cin >> playerChoice;
    }

    if (playerChoice == 1)
    {
        //cout << endl << "You chose the ";
        //prizes[0].showShortName();
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        if ( ((prizes[0].getPrice()) >= (prizes[1].getPrice())) && ((prizes[0].getPrice()) >= (prizes[2].getPrice())) )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";

    }
    else if (playerChoice == 2)
    {
        //cout << endl << "You chose the ";
        //prizes[1].showShortName();
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        if ( ((prizes[1].getPrice()) >= (prizes[0].getPrice())) && ((prizes[1].getPrice()) >= (prizes[2].getPrice())) )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else
    {
        //cout << endl << "You chose the ";
        //prizes[2].showShortName();
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is ";
        prizes[0].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is ";
        prizes[1].showARP();
        cout << endl;
        system("pause");

        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is ";
        prizes[2].showARP();
        cout << endl;
        if ( ((prizes[2].getPrice()) >= (prizes[0].getPrice())) && ((prizes[2].getPrice()) >= (prizes[1].getPrice())) )
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// One For All
void playOneForAll()
{
    /// Credit to PriceFanArmadillo for making this game!

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ( (inFile >> t_Description >> t_ShortName >> t_Price) )
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    medium base;
    medium other1;
    medium other2;
    medium other3;

    int pv1;
    int pv2;
    int pv3;

    int baseID;
    int otherID1;
    int otherID2;
    int otherID3;

    bool setup = false;

    while (!setup){
    baseID = rand() % i;

    otherID1 = baseID;
    while (otherID1 == baseID)
        otherID1 = rand() % i;

    otherID2 = baseID;
    while ( (otherID2 == baseID) || (otherID2 == otherID1) )
        otherID2 = rand() % i;

    otherID3 = baseID;
    while ( (otherID3 == baseID) || (otherID3 == otherID1) || (otherID3 == otherID2) )
        otherID3 = rand() % i;
    //cout << endl << "initialized random ids";

    pv1 = rand() % 2;
    pv2 = rand() % 2;
    pv3 = rand() % 2;
    //cout << endl << "initialized place values";

    gameItemIt = gameItems.begin();
    for (int z = 0; z < baseID; z++)
        gameItemIt++;
    base.setDescription(gameItemIt->getDescription());
    base.setShortName(gameItemIt->getShortName());
    base.setPrice(gameItemIt->getPrice());

    /// Check if the three-digit price has a zero.
    if (hasZero(base.getPrice())){
        pv1 = 1;
        pv2 = 1;
        pv3 = 1;
    }

    gameItemIt = gameItems.begin();
    for (int z = 0; z < otherID1; z++)
        gameItemIt++;
    other1.setDescription(gameItemIt->getDescription());
    other1.setShortName(gameItemIt->getShortName());
    other1.setPrice(gameItemIt->getPrice());

    gameItemIt = gameItems.begin();
    for (int z = 0; z < otherID2; z++)
        gameItemIt++;
    other2.setDescription(gameItemIt->getDescription());
    other2.setShortName(gameItemIt->getShortName());
    other2.setPrice(gameItemIt->getPrice());

    gameItemIt = gameItems.begin();
    for (int z = 0; z < otherID3; z++)
        gameItemIt++;
    other3.setDescription(gameItemIt->getDescription());
    other3.setShortName(gameItemIt->getShortName());
    other3.setPrice(gameItemIt->getPrice());

    if (compatibleForOneForAll(base.getPrice(), other1.getPrice(), other2.getPrice(), other3.getPrice(), pv1, pv2, pv3))
        setup = true;
    } // end while loop

    cout << "ONE FOR ALL" << endl;

    int order[3] = {0, 1, 2};
    random_shuffle(&order[0], &order[3]);

    int finalPlaceValueNotes[3];
    int finalMissingDigits[3];

    int digitOrder[3];
    digitOrder[0] = base.getPrice() / 100 % 10;
    digitOrder[1] = base.getPrice() / 10 % 10;
    digitOrder[2] = base.getPrice() % 10;

    medium finals[3];
    finals[order[0]].setDescription(other1.getDescription());
    finals[order[0]].setShortName(other1.getShortName());
    finals[order[0]].setPrice(other1.getPrice());
    finalMissingDigits[order[0]] = base.getPrice() / 100 % 10;
    finalPlaceValueNotes[order[0]] = pv1;

    finals[order[1]].setDescription(other2.getDescription());
    finals[order[1]].setShortName(other2.getShortName());
    finals[order[1]].setPrice(other2.getPrice());
    finalMissingDigits[order[1]] = base.getPrice() / 10 % 10;
    finalPlaceValueNotes[order[1]] = pv2;

    finals[order[2]].setDescription(other3.getDescription());
    finals[order[2]].setShortName(other3.getShortName());
    finals[order[2]].setPrice(other3.getPrice());
    finalMissingDigits[order[2]] = base.getPrice() % 10;
    finalPlaceValueNotes[order[2]] = pv3;

    bool chosen[3];
    for (int c = 0; c < 3; c++)
        chosen[c] = false;

//    cout << endl;
//    base.showARP();
//    cout << endl;
//    other1.showARP();
//    cout << endl;
//    other2.showARP();
//    cout << endl;
//    other3.showARP();


//    cout << endl;
//    finals[0].showARP();
//    cout << endl;
//    finals[1].showARP();
//    cout << endl;
//    finals[2].showARP();
//
//    cout << endl << "missing digits: " << finalMissingDigits[0] << ", " << finalMissingDigits[1] << ", " << finalMissingDigits[2];


    int firstFill = 10;
    int secondFill = 10;
    int thirdFill = 10;

    cout << endl << "Base prize:";
    cout << endl;
    base.showPrize();
    cout << endl;
    base.showARP();

    /// First prize
    cout << endl;
    cout << endl << "1. ";
    finals[0].showPrize();
    if ( (finalPlaceValueNotes[0] == 0) && (firstFill > 9) )
        cout << " - $_" << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 1) && (firstFill > 9) )
        cout << " - $" << (finals[0].getPrice() / 1000 % 10) << "_" << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 0) && (firstFill <= 9) )
        cout << " - $" << firstFill << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else
         cout << " - $" << (finals[0].getPrice() / 1000 % 10) << firstFill << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);

    cout << endl << "2. ";
    finals[1].showPrize();
    if ( (finalPlaceValueNotes[1] == 0) && (secondFill > 9) )
        cout << " - $_" << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 1) && (secondFill > 9) )
        cout << " - $" << (finals[1].getPrice() / 1000 % 10) << "_" << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 0) && (secondFill <= 9) )
        cout << " - $" << secondFill << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else
         cout << " - $" << (finals[1].getPrice() / 1000 % 10) << secondFill << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);

    cout << endl << "3. ";
    finals[2].showPrize();
    if ( (finalPlaceValueNotes[2] == 0) && (thirdFill > 9) )
        cout << " - $_" << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 1) && (thirdFill > 9) )
        cout << " - $" << (finals[2].getPrice() / 1000 % 10) << "_" << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 0) && (thirdFill <= 9) )
        cout << " - $" << thirdFill << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else
         cout << " - $" << (finals[2].getPrice() / 1000 % 10) << thirdFill << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);

    int choice1 = 0;
    while ( (choice1 < 1) || (choice1 > 3) ){
        cout << endl << "Which item's price does the " << digitOrder[0] << " go in?: ";
        cin >> choice1;
    }
    if (choice1 == 1){
        firstFill = digitOrder[0];
        chosen[0] = true;
    }
    else if (choice1 == 2){
        secondFill = digitOrder[0];
        chosen[1] = true;
    }
    else{
        thirdFill = digitOrder[0];
        chosen[2] = true;
    }

    /// Second digit
    cout << endl << "1. ";
    finals[0].showPrize();
    if ( (finalPlaceValueNotes[0] == 0) && (firstFill > 9) )
        cout << " - $_" << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 1) && (firstFill > 9) )
        cout << " - $" << (finals[0].getPrice() / 1000 % 10) << "_" << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 0) && (firstFill <= 9) )
        cout << " - $" << firstFill << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else
         cout << " - $" << (finals[0].getPrice() / 1000 % 10) << firstFill << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);

    cout << endl << "2. ";
    finals[1].showPrize();
    if ( (finalPlaceValueNotes[1] == 0) && (secondFill > 9) )
        cout << " - $_" << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 1) && (secondFill > 9) )
        cout << " - $" << (finals[1].getPrice() / 1000 % 10) << "_" << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 0) && (secondFill <= 9) )
        cout << " - $" << secondFill << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else
         cout << " - $" << (finals[1].getPrice() / 1000 % 10) << secondFill << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);

    cout << endl << "3. ";
    finals[2].showPrize();
    if ( (finalPlaceValueNotes[2] == 0) && (thirdFill > 9) )
        cout << " - $_" << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 1) && (thirdFill > 9) )
        cout << " - $" << (finals[2].getPrice() / 1000 % 10) << "_" << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 0) && (thirdFill <= 9) )
        cout << " - $" << thirdFill << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else
         cout << " - $" << (finals[2].getPrice() / 1000 % 10) << thirdFill << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);

    int choice2 = 0;
    while ( (choice2 < 1) || (choice2 > 3) ){
        cout << endl << "Which item's price does the " << digitOrder[1] << " go in?: ";
        cin >> choice2;
        if (chosen[choice2-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            choice2 = 0;
        }
    }
    if (choice2 == 1){
        firstFill = digitOrder[1];
        chosen[0] = true;
    }
    else if (choice2 == 2){
        secondFill = digitOrder[1];
        chosen[1] = true;
    }
    else{
        thirdFill = digitOrder[1];
        chosen[2] = true;
    }

    /// Third digit
    cout << endl << "1. ";
    finals[0].showPrize();
    if ( (finalPlaceValueNotes[0] == 0) && (firstFill > 9) )
        cout << " - $_" << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 1) && (firstFill > 9) )
        cout << " - $" << (finals[0].getPrice() / 1000 % 10) << "_" << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 0) && (firstFill <= 9) )
        cout << " - $" << firstFill << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else
         cout << " - $" << (finals[0].getPrice() / 1000 % 10) << firstFill << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);

    cout << endl << "2. ";
    finals[1].showPrize();
    if ( (finalPlaceValueNotes[1] == 0) && (secondFill > 9) )
        cout << " - $_" << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 1) && (secondFill > 9) )
        cout << " - $" << (finals[1].getPrice() / 1000 % 10) << "_" << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 0) && (secondFill <= 9) )
        cout << " - $" << secondFill << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else
         cout << " - $" << (finals[1].getPrice() / 1000 % 10) << secondFill << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);

    cout << endl << "3. ";
    finals[2].showPrize();
    if ( (finalPlaceValueNotes[2] == 0) && (thirdFill > 9) )
        cout << " - $_" << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 1) && (thirdFill > 9) )
        cout << " - $" << (finals[2].getPrice() / 1000 % 10) << "_" << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 0) && (thirdFill <= 9) )
        cout << " - $" << thirdFill << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else
         cout << " - $" << (finals[2].getPrice() / 1000 % 10) << thirdFill << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);

    int choice3 = 0;
    while ( (choice3 < 1) || (choice3 > 3) ){
        cout << endl << "Which item's price does the " << digitOrder[2] << " go in?: ";
        cin >> choice3;
        if (chosen[choice3-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            choice3 = 0;
        }
    }
    if (choice3 == 1){
        firstFill = digitOrder[2];
        chosen[0] = true;
    }
    else if (choice3 == 2){
        secondFill = digitOrder[2];
        chosen[1] = true;
    }
    else{
        thirdFill = digitOrder[2];
        chosen[2] = true;
    }

    /// Results
    cout << endl << "1. ";
    finals[0].showPrize();
    if ( (finalPlaceValueNotes[0] == 0) && (firstFill > 9) )
        cout << " - $_" << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 1) && (firstFill > 9) )
        cout << " - $" << (finals[0].getPrice() / 1000 % 10) << "_" << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else if ( (finalPlaceValueNotes[0] == 0) && (firstFill <= 9) )
        cout << " - $" << firstFill << (finals[0].getPrice() / 100 % 10) << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);
    else
         cout << " - $" << (finals[0].getPrice() / 1000 % 10) << firstFill << (finals[0].getPrice() / 10 % 10) << (finals[0].getPrice() % 10);

    cout << endl << "2. ";
    finals[1].showPrize();
    if ( (finalPlaceValueNotes[1] == 0) && (secondFill > 9) )
        cout << " - $_" << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 1) && (secondFill > 9) )
        cout << " - $" << (finals[1].getPrice() / 1000 % 10) << "_" << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else if ( (finalPlaceValueNotes[1] == 0) && (secondFill <= 9) )
        cout << " - $" << secondFill << (finals[1].getPrice() / 100 % 10) << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);
    else
         cout << " - $" << (finals[1].getPrice() / 1000 % 10) << secondFill << (finals[1].getPrice() / 10 % 10) << (finals[1].getPrice() % 10);

    cout << endl << "3. ";
    finals[2].showPrize();
    if ( (finalPlaceValueNotes[2] == 0) && (thirdFill > 9) )
        cout << " - $_" << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 1) && (thirdFill > 9) )
        cout << " - $" << (finals[2].getPrice() / 1000 % 10) << "_" << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else if ( (finalPlaceValueNotes[2] == 0) && (thirdFill <= 9) )
        cout << " - $" << thirdFill << (finals[2].getPrice() / 100 % 10) << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);
    else
         cout << " - $" << (finals[2].getPrice() / 1000 % 10) << thirdFill << (finals[2].getPrice() / 10 % 10) << (finals[2].getPrice() % 10);

    cout << endl << "Let's see if you've won.";
    cout << endl;
    system("pause");

    cout << endl << "The actual retail price of the ";
    finals[0].showShortName();
    cout << " is $" << finals[0].getPrice();
    if (firstFill != finalMissingDigits[0])
        cout << endl << "Sorry, you lose.";
    else{
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        finals[1].showShortName();
        cout << " is $" << finals[1].getPrice();
        if (secondFill != finalMissingDigits[1])
            cout << endl << "Sorry, you lose.";
        else{
        cout << endl;
        system("pause");
        cout << endl << "The actual retail price of the ";
        finals[2].showShortName();
        cout << " is $" << finals[2].getPrice();
        if (thirdFill != finalMissingDigits[2])
            cout << endl << "Sorry, you lose.";
        else
            cout << endl << "Congratulations, you win!";
        } // end if player has second item's price right
    } // end if player has first item's price right.

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// One Right Price
void playOneRightPrice()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "ONE RIGHT PRICE" << endl;

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
    medium prizes[2];

    int side = rand() % 2; /// if 0, the ORP is the left item's price. If 1, the ORP is the right item's price.
    int orp = 0;
    //cout << "todo = " << todo << endl;

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// Set the one right price.
    if (side == 0)
        orp = prizes[0].getPrice();
    else
        orp = prizes[1].getPrice();

    cout << endl << "One right price: $" << orp << endl;
    cout << "1. ";
    prizes[0].showPrize();
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << endl;

    int choice = 0;
    while ((choice < 1) || (choice > 2))
    {
        cout << endl << "Which prize (enter the number) has the one right price?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[choice-1].showShortName();
    cout << " is ";
    prizes[choice-1].showARP();
    if (prizes[choice-1].getPrice() == orp)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    cout << endl;
    system("pause");
    system("CLS");
}

/// One Wrong Price
void playOneWrongPrice()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price >= 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "ONE WRONG PRICE" << endl;

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
    medium prizes[3];
    int playerChoice = 0;
    int withWrong = rand()% 3; /// determines which prize will have the wrong price

    /// Set each item
    for (int itemCount = 0; itemCount < 3; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    /// This is a failsafe to ensure that the "wrong price" isn't actually wrong.
    int wrongPrice = prizes[0].getPrice();
    while ( (wrongPrice == prizes[0].getPrice()) || (wrongPrice == prizes[1].getPrice()) || (wrongPrice == prizes[2].getPrice()) )
        wrongPrice = rand() % (4500 - 1000) + 1000;

    if (withWrong == 0) /// the one wrong price is on the left
    {
        cout << "1. ";
        prizes[0].showPrize();
        cout << " - $";
        cout << wrongPrice;
        cout << endl;
        cout << "2. ";
        prizes[1].showPrize();
        cout << " - ";
        prizes[1].showARP();
        cout << endl;
        cout << "3. ";
        prizes[2].showPrize();
        cout << " - ";
        prizes[2].showARP();
        cout << endl;
    }
    else if (withWrong == 1) /// the one wrong price is in the middle
    {
        cout << "1. ";
        prizes[0].showPrize();
        cout << " - ";
        prizes[0].showARP();
        cout << endl;
        cout << "2. ";
        prizes[1].showPrize();
        cout << " - $";
        cout << wrongPrice;
        cout << endl;
        cout << "3. ";
        prizes[2].showPrize();
        cout << " - ";
        prizes[2].showARP();
        cout << endl;
    }
    else /// the one wrong price is on the right
    {
        cout << "1. ";
        prizes[0].showPrize();
        cout << " - ";
        prizes[0].showARP();
        cout << endl;
        cout << "2. ";
        prizes[1].showPrize();
        cout << " - ";
        prizes[1].showARP();
        cout << endl;
        cout << "3. ";
        prizes[2].showPrize();
        cout << " - $";
        cout << wrongPrice;
        cout << endl;
    }

    int choice = 0;
    while ((choice < 1) || (choice > 3)){
    cout << endl << "Which item has the one wrong price?: ";
    cin >> choice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[choice-1].showShortName();
    cout << " is ";
    prizes[choice-1].showARP();

    if (choice-1 == withWrong)
        cout << endl << "Congratulations, you win!";
    else{
        cout << endl << "Sorry, you lose. The correct answer was the ";
        prizes[withWrong].showShortName();
        cout << ".";
    }

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Poker Game
void playPokerGame()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 1000) )
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "POKER GAME" << endl;

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

    medium prizes[4];

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (int z = 0; z < randomizationField[itemCount]; z++)
            gameItemIt++;

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    bool chosen[4];
    for (int c = 0; c < 4; c++)
        chosen[c] = false;

    int hasInHand = 0;

    int firstPrice;
    int secondPrice;

    while (hasInHand < 2){
    for (int y = 0; y < 4; y++){
        cout << endl << y+1 << ". ";
        prizes[y].showPrize();
        if (chosen[y])
            cout << " - $" << prizes[y].getPrice();
    }
    cout << endl;
    int choice = 0;
    while ( (choice < 1) || (choice > 4) ){
        cout << endl << "Which item would you like to pick?: ";
        cin >> choice;
    if (chosen[choice-1]){
        cout << endl << "You've already chosen this item. Please pick another one.";
        choice = 0;
    }
    }
    cout << endl << "The actual retail price of the ";
    prizes[choice-1].showShortName();
    cout << " is $" << prizes[choice-1].getPrice();
    cout << endl;
    chosen[choice-1] = true;
    if (hasInHand == 0)
        firstPrice = prizes[choice-1].getPrice();
    else
        secondPrice = prizes[choice-1].getPrice();
    hasInHand += 1;
    }

    int other;

    //cout << endl << "x = " << hasThreeOfAKind(firstPrice, secondPrice);

    int highest;
    int ranking;

    if (hasFiveOfAKind(firstPrice, secondPrice) >= 0){
        int fiver = hasFiveOfAKind(firstPrice, secondPrice);

        highest = fiver;
        ranking = 7;

        cout << endl << fiver << fiver << fiver << fiver << fiver;
        cout << endl << "You have five " << fiver << "s - that's five of a kind.";
    }
    else if (hasFourOfAKind(firstPrice, secondPrice) >= 0){
        int fourer = hasFourOfAKind(firstPrice, secondPrice);
        other = createFourKindHand(firstPrice, secondPrice);

        highest = fourer;
        ranking = 6;

        cout << endl << fourer << fourer << fourer << fourer << other;
        cout << endl << "You have four " << fourer << "s - that's four of a kind.";
    }
    else if (hasFullHouse(firstPrice, secondPrice) >= 0){
        int larger = hasFullHouse(firstPrice, secondPrice);
        int smaller = createFullHouseHand(firstPrice, secondPrice);

        highest = larger;
        ranking = 5;

        cout << endl << larger << larger << larger << smaller << smaller;
        cout << endl << "You have three " << larger << "s and two " << smaller << "s - that's a full house.";
    }
    else if (hasThreeOfAKind(firstPrice, secondPrice) >= 0){
        int larger = hasThreeOfAKind(firstPrice, secondPrice);
        int smaller = largerRemainingTOAK(firstPrice, secondPrice);
        int smallest = smallerRemainingTOAK(firstPrice, secondPrice);

        highest = larger;
        ranking = 4;

        cout << endl << larger << larger << larger << smaller << smallest;
        cout << endl << "You have three " << larger << "s - that's three of a kind.";
    }
    else if (hasTwoPair(firstPrice, secondPrice) >= 0){
        int larger = hasTwoPair(firstPrice, secondPrice);
        int smaller = otherTwoPair(firstPrice, secondPrice);
        int smallest = remainingTwoPair(firstPrice, secondPrice);

        highest = larger;
        ranking = 3;

        cout << endl << larger << larger << smaller << smaller << smallest;
        cout << endl << "You have two " << larger << "s and two " << smaller << "s - that's two pair.";
    }
    else if (hasOnePair(firstPrice, secondPrice) >= 0){
        int pairno = hasOnePair(firstPrice, secondPrice);
        int largest = largestOnePair(firstPrice, secondPrice);
        int middle = middleOnePair(firstPrice, secondPrice);
        int smallest = smallestOnePair(firstPrice, secondPrice);

        highest = pairno;
        ranking = 2;

        cout << endl << pairno << pairno << largest << middle << smallest;
        cout << endl << "You have two " << pairno << "s - that's one pair.";
    }
    else{
        int hand[6];
        hand[0] = firstPrice / 100 % 10;
        hand[1] = firstPrice / 10 % 10;
        hand[2] = firstPrice % 10;
        hand[3] = secondPrice / 100 % 10;
        hand[4] = secondPrice / 10 % 10;
        hand[5] = secondPrice % 10;
        sortCards(hand);

        highest = hand[5];
        ranking = 1;

        cout << endl << hand[5] << hand[4] << hand[3] << hand[2] << hand[1];
        cout << endl << "You have " << hand[5] << " as a high card.";
    }
    char keep = '!';
    while ( (keep != 'Y') && (keep != 'y') && (keep != 'N') && (keep != 'n') ){
        cout << endl << "Do you want to keep this hand (Y) or pass it to the house (N)?: ";
        cin >> keep;
    }

    int otherPrice1;
    int otherPrice2;

    if ( (keep == 'Y') || (keep == 'y') ){

    if (chosen[0] && chosen[1]){
        otherPrice1 = prizes[2].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[2].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[0] && chosen[2]){
        otherPrice1 = prizes[1].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[1].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[0] && chosen[3]){
        otherPrice1 = prizes[1].getPrice();
        otherPrice2 = prizes[2].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[1].showShortName();
        cout << endl;
        prizes[2].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[1] && chosen[2]){
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[1] && chosen[3]){
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[2].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[2].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else{
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[1].getPrice();
        cout << endl << "The house picked these prizes:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[1].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }

    cout << endl;
    system("pause");
    if (!chosen[0]){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
    }
    if (!chosen[1]){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
    }
    if (!chosen[2]){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
    }
    if (!chosen[3]){
        cout << endl << "The actual retail price of the ";
        prizes[3].showShortName();
        cout << " is $" << prizes[3].getPrice();
    }

    if (hasFiveOfAKind(otherPrice1, otherPrice2) >= 0){
        int housefive = hasFiveOfAKind(otherPrice1, otherPrice2);
        cout << endl << housefive << housefive << housefive << housefive << housefive;
        cout << endl << "The house has five " << housefive << "s - that's five of a kind.";
        if (ranking < 7)
            cout << endl << "Sorry, you lose.";
        else{
            if (highest >= housefive)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
    } // end if the house has five of a kind

    else if (hasFourOfAKind(otherPrice1, otherPrice2) >= 0){
        int housefour = hasFourOfAKind(otherPrice1, otherPrice2);
        int houseother = createFourKindHand(otherPrice1, otherPrice2);
        cout << endl << housefour << housefour << housefour << housefour << houseother;
        cout << endl << "The house has four " << housefour << "s - that's four of a kind.";
        if (ranking > 6)
            cout << endl << "Congratulations, you win!";
        else if (ranking == 6){
            if (highest >= housefour)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the house has four of a kind

    else if (hasFullHouse(otherPrice1, otherPrice2) >= 0){
        int houselarge = hasFullHouse(otherPrice1, otherPrice2);
        int housesmall = createFullHouseHand(otherPrice1, otherPrice2);
        cout << endl << houselarge << houselarge << houselarge << housesmall << housesmall;
        cout << endl << "The house has three " << houselarge << "s and two " << housesmall << "s - that's a full house.";
        if (ranking > 5)
            cout << endl << "Congratulations, you win!";
        else if (ranking == 5){
            if (highest >= houselarge)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the house has a full house

    else if (hasThreeOfAKind(otherPrice1, otherPrice2) >= 0){
        int houselarger = hasThreeOfAKind(otherPrice1, otherPrice2);
        int housesmaller = largerRemainingTOAK(otherPrice1, otherPrice2);
        int housesmallest = smallerRemainingTOAK(otherPrice1, otherPrice2);
        cout << endl << houselarger << houselarger << houselarger << housesmaller << housesmallest;
        cout << endl << "The house has three " << houselarger << "s - that's three of a kind.";
        if (ranking > 4)
            cout << endl << "Congratulations, you win!";
        else if (ranking == 4){
            if (highest >= houselarger)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the house has three of a kind

    else if (hasTwoPair(otherPrice1, otherPrice2) >= 0){
        int houselarger = hasTwoPair(otherPrice1, otherPrice2);
        int housesmaller = otherTwoPair(otherPrice1, otherPrice2);
        int housesmallest = remainingTwoPair(otherPrice1, otherPrice2);
        cout << endl << houselarger << houselarger << housesmaller << housesmaller << housesmallest;
        cout << endl << "The house has two " << houselarger << "s and two " << housesmaller << "s - that's two pair.";
        if (ranking > 3)
            cout << endl << "Congratulations, you win!";
        else if (ranking == 3){
            if (highest >= houselarger)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the house has two pair

    else if (hasOnePair(otherPrice1, otherPrice2) >= 0){
        int houseno = hasOnePair(otherPrice1, otherPrice2);
        int houselargest = largestOnePair(otherPrice1, otherPrice2);
        int housemiddle = middleOnePair(otherPrice1, otherPrice2);
        int housesmallest = smallestOnePair(otherPrice1, otherPrice2);
        cout << endl << houseno << houseno << houselargest << housemiddle << housesmallest;
        cout << endl << "The house has two " << houseno << "s - that's one pair.";
        if (ranking > 2)
            cout << endl << "Congratulations, you win!";
        else if (ranking == 2){
            if (highest >= houseno)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the house has one pair

    else{
        int houseHand[6];
        houseHand[0] = otherPrice1 / 100 % 10;
        houseHand[1] = otherPrice1 / 10 % 10;
        houseHand[2] = otherPrice1 % 10;
        houseHand[3] = otherPrice2 / 100 % 10;
        houseHand[4] = otherPrice2 / 10 % 10;
        houseHand[5] = otherPrice2 % 10;
        sortCards(houseHand);

        int houseHigh = houseHand[5];
        cout << endl << houseHand[5] << houseHand[4] << houseHand[3] << houseHand[2] << houseHand[1];
        cout << endl << "The house has " << houseHand[5] << " as a high card.";
        if (ranking > 1)
            cout << endl << "Congratulations, you win!";
        else{
            if (highest >= houseHigh)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }

    } // end if the house has high card


    } // end if player said YES
    else{
    int playerID;

    if (chosen[0] && chosen[1]){
        otherPrice1 = prizes[2].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[2].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[0] && chosen[2]){
        otherPrice1 = prizes[1].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[1].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[0] && chosen[3]){
        otherPrice1 = prizes[1].getPrice();
        otherPrice2 = prizes[2].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[1].showShortName();
        cout << endl;
        prizes[2].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[1] && chosen[2]){
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[3].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[3].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else if (chosen[1] && chosen[3]){
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[2].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[2].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }
    else{
        otherPrice1 = prizes[0].getPrice();
        otherPrice2 = prizes[1].getPrice();
        cout << endl << "You've chosen these prices:";
        cout << endl;
        prizes[0].showShortName();
        cout << endl;
        prizes[1].showShortName();
        cout << endl << endl << "Let's see what hand their prices have.";
    }

    cout << endl;
    system("pause");
    if (!chosen[0]){
        cout << endl << "The actual retail price of the ";
        prizes[0].showShortName();
        cout << " is $" << prizes[0].getPrice();
    }
    if (!chosen[1]){
        cout << endl << "The actual retail price of the ";
        prizes[1].showShortName();
        cout << " is $" << prizes[1].getPrice();
    }
    if (!chosen[2]){
        cout << endl << "The actual retail price of the ";
        prizes[2].showShortName();
        cout << " is $" << prizes[2].getPrice();
    }
    if (!chosen[3]){
        cout << endl << "The actual retail price of the ";
        prizes[3].showShortName();
        cout << " is $" << prizes[3].getPrice();
    }

    if (hasFiveOfAKind(otherPrice1, otherPrice2) >= 0){
        playerID = 7;
        int housefive = hasFiveOfAKind(otherPrice1, otherPrice2);
        cout << endl << housefive << housefive << housefive << housefive << housefive;
        cout << endl << "Your hand has five " << housefive << "s - that's five of a kind.";
        if (ranking < playerID)
            cout << endl << "Sorry, you lose.";
        else{
            if (highest <= housefive)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
    } // end if the player's new hand has five of a kind

    else if (hasFourOfAKind(otherPrice1, otherPrice2) >= 0){
        playerID = 6;
        int housefour = hasFourOfAKind(otherPrice1, otherPrice2);
        int houseother = createFourKindHand(otherPrice1, otherPrice2);
        cout << endl << housefour << housefour << housefour << housefour << houseother;
        cout << endl << "Your hand has four " << housefour << "s - that's four of a kind.";
        if (playerID > ranking)
            cout << endl << "Congratulations, you win!";
        else if (playerID == ranking){
            if (highest <= housefour)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the player's new hand has four of a kind

    else if (hasFullHouse(otherPrice1, otherPrice2) >= 0){
        playerID = 5;
        int houselarge = hasFullHouse(otherPrice1, otherPrice2);
        int housesmall = createFullHouseHand(otherPrice1, otherPrice2);
        cout << endl << houselarge << houselarge << houselarge << housesmall << housesmall;
        cout << endl << "Your hand has three " << houselarge << "s and two " << housesmall << "s - that's a full house.";
        if (playerID > ranking)
            cout << endl << "Congratulations, you win!";
        else if (playerID == ranking){
            if (highest <= houselarge)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the player's new hand has a full house

    else if (hasThreeOfAKind(otherPrice1, otherPrice2) >= 0){
    playerID = 4;
    int houselarger = hasThreeOfAKind(otherPrice1, otherPrice2);
    int housesmaller = largerRemainingTOAK(otherPrice1, otherPrice2);
    int housesmallest = smallerRemainingTOAK(otherPrice1, otherPrice2);
    cout << endl << houselarger << houselarger << houselarger << housesmaller << housesmallest;
    cout << endl << "Your hand has three " << houselarger << "s - that's three of a kind.";
    if (playerID > ranking)
        cout << endl << "Congratulations, you win!";
    else if (playerID == ranking){
        if (highest <= houselarger)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else
        cout << endl << "Sorry, you lose.";
    } // end if the player's new hand has three of a kind

    else if (hasTwoPair(otherPrice1, otherPrice2) >= 0){
    playerID = 3;
    int houselarger = hasTwoPair(otherPrice1, otherPrice2);
    int housesmaller = otherTwoPair(otherPrice1, otherPrice2);
    int housesmallest = remainingTwoPair(otherPrice1, otherPrice2);
    cout << endl << houselarger << houselarger << housesmaller << housesmaller << housesmallest;
    cout << endl << "Your hand has two " << houselarger << "s and two " << housesmaller << "s - that's two pair.";
    if (playerID > ranking)
        cout << endl << "Congratulations, you win!";
    else if (playerID == ranking){
        if (highest <= houselarger)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";
    }
    else
        cout << endl << "Sorry, you lose.";
    } // end if the player's new hand has two pair

    else if (hasOnePair(otherPrice1, otherPrice2) >= 0){
        playerID = 2;
        int houseno = hasOnePair(otherPrice1, otherPrice2);
        int houselargest = largestOnePair(otherPrice1, otherPrice2);
        int housemiddle = middleOnePair(otherPrice1, otherPrice2);
        int housesmallest = smallestOnePair(otherPrice1, otherPrice2);
        cout << endl << houseno << houseno << houselargest << housemiddle << housesmallest;
        cout << endl << "Your hand has two " << houseno << "s - that's one pair.";
        if (playerID > ranking)
            cout << endl << "Congratulations, you win!";
        else if (playerID == ranking){
            if (highest <= houseno)
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";
    } // end if the player's new hand has one pair

    else{
    playerID = 1;
        int newHand[6];
        newHand[0] = otherPrice1 / 100 % 10;
        newHand[1] = otherPrice1 / 10 % 10;
        newHand[2] = otherPrice1 % 10;
        newHand[3] = otherPrice2 / 100 % 10;
        newHand[4] = otherPrice2 / 10 % 10;
        newHand[5] = otherPrice2 % 10;
        sortCards(newHand);

        int newHigh = newHand[5];
        cout << endl << newHand[5] << newHand[4] << newHand[3] << newHand[2] << newHand[1];
        cout << endl << "Your hand has " << newHand[5] << " as a high card.";

        if (playerID == ranking){
            if (highest <= newHand[5])
                cout << endl << "Congratulations, you win!";
            else
                cout << endl << "Sorry, you lose.";
        }
        else
            cout << endl << "Sorry, you lose.";

    } // end if the player's new hand has a high card


    } // end if player said NO

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Race Game
void playRaceGame()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "RACE GAME" << endl;

    medium prizes[4];

    int first = rand() % i;
    int second;
    int third;
    int fourth;

    gameItemIt = gameItems.begin();
    for (int z = 0; z < first; z++)
        gameItemIt++;
    prizes[0].setDescription(gameItemIt->getDescription());
    prizes[0].setShortName(gameItemIt->getShortName());
    prizes[0].setPrice(gameItemIt->getPrice());


    bool setSecond = false;
    while (!setSecond){
    second = first;
    while (second == first)
        second = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < second; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) ){
        prizes[1].setDescription(gameItemIt->getDescription());
        prizes[1].setShortName(gameItemIt->getShortName());
        prizes[1].setPrice(gameItemIt->getPrice());
        setSecond = true;
    }
    } // end setting second item

    bool setThird = false;
    while (!setThird){
    third = first;
    while ((third == first) || (third == second) )
        third = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < third; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) && (gameItemIt->getPrice()) != (prizes[1].getPrice()) ){
        prizes[2].setDescription(gameItemIt->getDescription());
        prizes[2].setShortName(gameItemIt->getShortName());
        prizes[2].setPrice(gameItemIt->getPrice());
        setThird = true;
    }
    } // end setting third item

    bool setFourth = false;
    while (!setFourth){
    fourth = first;
    while ( (fourth == first) || (fourth == second) || (fourth == third) )
        fourth = rand() % i;
    gameItemIt = gameItems.begin();
    for (int z = 0; z < fourth; z++)
        gameItemIt++;
    if ( (gameItemIt->getPrice()) != (prizes[0].getPrice()) && (gameItemIt->getPrice()) != (prizes[1].getPrice()) && (gameItemIt->getPrice()) != (prizes[2].getPrice()) ){
        prizes[3].setDescription(gameItemIt->getDescription());
        prizes[3].setShortName(gameItemIt->getShortName());
        prizes[3].setPrice(gameItemIt->getPrice());
        setFourth = true;
    }
    } // end setting fourth item

    int tags[4];

    for (int t = 0; t < 4; t++){
        tags[t] = prizes[t].getPrice();
    }

    sortRacePrices(tags);

    for (int s = 0; s < 4; s++){
        cout << endl;
        prizes[s].showPrize();
    }

    cout << endl;

    int chances = 4;
    bool won = false;

    bool pickedTag[4];
    bool pickedItem[4];

    int tempPrices[4];

    int hasRight = 0;

    /// Main gameplay begins.
    while ( (chances > 0) && (!won) ){
    cout << endl << "Chances left: " << chances;

    for (int r = 0; r < 4; r++){
        pickedTag[r] = false;
        pickedItem[r] = false;
        tempPrices[r] = 0;
    }

    for (int u = 0; u < 4; u++){
        cout << endl << u+1 << ". $" << tags[u];
    }

    for (int place = 0; place < 4; place++){
    int tagChoice = 0;
    while ( (tagChoice < 1) || (tagChoice > 4) ){
        cout << endl << "Which price tag (1-4) do you want to pick?: ";
        cin >> tagChoice;
        if (pickedTag[tagChoice-1]){
            cout << endl << "You've already chosen this tag. Please pick another one.";
            tagChoice = 0;
            }
    } // end tag choice
    pickedTag[tagChoice-1] = true;

    for (int v = 0; v < 4; v++){
        cout << endl << v+1 << ". ";
        prizes[v].showPrize();
        if (pickedItem[v])
            cout << " - $" << tempPrices[v];
    }

    int itemChoice = 0;
    while ( (itemChoice < 1) || (itemChoice > 4) ){
        cout << endl << "Which item is worth $" << tags[tagChoice-1] << "?: ";
        cin >> itemChoice;
        if (pickedItem[itemChoice-1]){
            cout << endl << "You've already chosen this item. Please pick another one.";
            itemChoice = 0;
        }
    } // end item choice
    pickedItem[itemChoice-1] = true;
    tempPrices[itemChoice-1] = tags[tagChoice-1];

    for (int vv = 0; vv < 4; vv++){
        cout << endl;
        prizes[vv].showPrize();
        if (pickedItem[vv])
            cout << " - $" << tempPrices[vv];
    }

    cout << endl;

    for (int uu = 0; uu < 4; uu++){
        if (!pickedTag[uu])
            cout << endl << uu+1 << ". $" << tags[uu];
        else
            cout << endl << uu+1 << ". $***";
    }

    } // end for loop placing all the tags

    cout << endl << "Let's pull the lever and see how many you have right.";
    cout << endl;
    system("pause");

    hasRight = 0;
    for (int verdict = 0; verdict < 4; verdict++){
        if (tempPrices[verdict] == prizes[verdict].getPrice())
            hasRight += 1;
    }

    if (hasRight == 4)
        won = true;
    else
    {
        if (hasRight == 1)
            cout << endl << "You have 1 price right.";
        else
            cout << endl << "You have " << hasRight << " prices right.";

        chances -= 1;
    }

    } // end of gameplay while loop

    if (won)
        cout << endl << "Congratulations, you win!";
    else if (hasRight == 2)
        cout << endl << "Well, at least you won two prizes.";
    else if (hasRight == 1)
        cout << endl << "Well, at least you won one prize.";
    else
        cout << endl << "Sorry, you lose.";

    cout << endl;
    system("pause");
    system("CLS");
}

/// Safe Crackers
void playSafeCrackers()
{
    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;

    string l_Description;
    string l_ShortName;
    int l_Price;

    large * lptr;

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;

    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 1000) && ( (t_Price % 10) == 0 ) && ( (t_Price % 100 != 0) ) && ( (t_Price % 110 != 0) ) )
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

    inFile.open("large.txt");
    while (inFile)
    {
    lptr = new large;
    if (inFile >> l_Description >> l_ShortName >> l_Price)
    {
        lptr->setDescription(l_Description);
        lptr->setShortName(l_ShortName);
        lptr->setPrice(l_Price);
        gameItemsLarge.push_back(*lptr);
        j++;

    }
    } // end while loop
    inFile.close();

    cout << "SAFE CRACKERS" << endl;

    //cout << "i = " << i << endl;
    //cout << "j = " << j << endl;

    int randomMediumNo = rand() % i;
    int randomLargeNo = rand() % j;

    int z = 0;
    int z2 = 0;

    large bonusPrize;
    medium comboPrize;

    /// Set the large prize.
    gameItemsLargeIt = gameItemsLarge.begin();
    for (z = 0; z < randomLargeNo; z++)
        gameItemsLargeIt++;
    bonusPrize.setDescription(gameItemsLargeIt->getDescription());
    bonusPrize.setShortName(gameItemsLargeIt->getShortName());
    bonusPrize.setPrice(gameItemsLargeIt->getPrice());

    /// Set the medium prize
    gameItemIt = gameItems.begin();
    for (z2 = 0; z2 < randomMediumNo; z2++)
        gameItemIt++;
    comboPrize.setDescription(gameItemIt->getDescription());
    comboPrize.setShortName(gameItemIt->getShortName());
    comboPrize.setPrice(gameItemIt->getPrice());

    cout << endl;

    cout << "Large prize:" << endl;
    bonusPrize.showPrize();
    cout << endl;
    cout << "Smaller prize:" << endl;
    comboPrize.showPrize();
    cout << endl << endl;

    cout << "The price of the ";
    comboPrize.showShortName();
    cout << " is the combination of the safe." << endl;

    int combination = comboPrize.getPrice();
    int digits[3];

    digits[0] = 0;

    if ( (combination / 100 % 10) < (combination / 10 % 10) ) /// first digit is less than second digit
    {
        digits[1] = combination / 100 % 10;
        digits[2] = combination / 10 % 10;
    }
    else
    {
        digits[1] = combination / 10 % 10;
        digits[2] = combination / 100 % 10;
    }

    cout << " " << digits[0] << "     " << digits[0] << "     " << digits[0] << endl;
    cout << digits[1] << " " << digits[2] << "   " << digits[1] << " " << digits[2] << "   " << digits[1] << " " << digits[2] << endl;

    int input1 = 10;
    int input2 = 10;
    int input3 = 10;

    int playerCombo = 0;

    while ( (input1 != digits[0]) && (input1 != digits[1]) && (input1 != digits[2]) )
    {
        cout << endl << "What is the first digit in the combination?: ";
        cin >> input1;
    }
    playerCombo += input1*100;

    while ( (input2 != digits[0]) && (input2 != digits[1]) && (input2 != digits[2]) )
    {
        cout << endl << "What is the second digit in the combination?: ";
        cin >> input2;
    }
    playerCombo += input2*10;

    while ( (input3 != digits[0]) && (input3 != digits[1]) && (input3 != digits[2]) )
    {
        cout << endl << "What is the third digit in the combination?: ";
        cin >> input3;
    }
    playerCombo += input3;

    cout << endl << "You input $" << playerCombo << " as the combination.";
    cout << endl << endl << "The correct combination is $" << combination;

    if (playerCombo == combination)
        cout << endl << "Congratulations, you win both prizes!";
    else
        cout << endl << "Sorry, you lose.";

    /// End of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Shopping Spree
void playShoppingSpree()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "SHOPPING SPREE" << endl;

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
    medium prizes[4];
    bool bought[4]; /// Denotes if the player has purchased the prize.
    int spendingAmt = 0; /// The minimum amount the player must spend.
    int spentSoFar = 0;

    int tempPrices[4]; /// This is used to calculate the minimum spending amount.
    int cheapestPrice; /// As is this.

    /// Initialize all the bought bools to false.
    for (int x = 0; x < 4; x++)
        bought[x] = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
        tempPrices[itemCount] = prizes[itemCount].getPrice();
    }

    /// Find the cheapest of the four prizes. This will be important in calculating
    /// the minimum spending amount. At the same time, prepare the spending amount.
    cheapestPrice = tempPrices[0];
    for (int j = 0; j < 4; j++)
    {
        spendingAmt += tempPrices[j];
        if (tempPrices[j] < cheapestPrice)
            cheapestPrice = tempPrices[j];
    }

    /// Subtract the cheapest prize's value from the spending amount, and then round the
    /// spending value down to the nearest hundred.
    spendingAmt -= cheapestPrice;
    int roundOff = spendingAmt % 100;
    spendingAmt -= roundOff;

    int picks = 0;

    while (picks < 3){
    for (int p = 0; p < 4; p++)
    {
        cout << p+1 << ". ";
        prizes[p].showPrize();
        if (bought[p])
        {
            cout << " - ";
            prizes[p].showARP();
        }
        cout << endl;
    }

    int playerChoice = 0;
    cout << endl << "Spending amount: $" << spendingAmt;
    cout << endl << "Left to spend: $" << spendingAmt-spentSoFar;
    cout << endl << "Which item (enter the number) would you like to buy?: ";
    cin >> playerChoice;
    switch (playerChoice){
    case 1:
        if (bought[0] == false)
        {
            cout << "The actual retail price of the ";
            prizes[0].showShortName();
            cout << " is ";
            prizes[0].showARP();
            cout << endl;
            bought[0] = true;
            spentSoFar += prizes[0].getPrice();
            picks += 1;
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 2:
        if (bought[1] == false)
        {
            cout << "The actual retail price of the ";
            prizes[1].showShortName();
            cout << " is ";
            prizes[1].showARP();
            cout << endl;
            bought[1] = true;
            spentSoFar += prizes[1].getPrice();
            picks += 1;
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 3:
        if (bought[2] == false)
        {
            cout << "The actual retail price of the ";
            prizes[2].showShortName();
            cout << " is ";
            prizes[2].showARP();
            cout << endl;
            bought[2] = true;
            spentSoFar += prizes[2].getPrice();
            picks += 1;
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    case 4:
        if (bought[3] == false)
        {
            cout << "The actual retail price of the ";
            prizes[3].showShortName();
            cout << " is ";
            prizes[3].showARP();
            cout << endl;
            bought[3] = true;
            spentSoFar += prizes[3].getPrice();
            picks += 1;
        } // end if statement
        else
            cout << endl << "You've already picked this item. Please pick another." << endl;
        break;

    default:
        cout << endl << "That won't work. Try again.";

    } // end switch statement
    cout << endl;

    } // end while loop

    cout << "Spending amount: $" << spendingAmt;
    cout << endl << "Amount spent: $" << spentSoFar;
    if (spentSoFar >= spendingAmt)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    cout << endl;
    system("pause");
    system("CLS");

}

/// Step Up
void playStepUp()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "STEP UP" << endl;

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
    medium prizes[4];
    bool chosen[4];
    for (int y = 0; y < 4; y++)
        chosen[y] = false;

    int winnings = 0;
    bool won500 = false;
    bool won1000 = false;
    bool won1500 = false;

    bool won = false;
    bool lost = false;
    bool bail = false;

    int on = 0;
    int lastPrice = 0;

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    cout << endl;

    while ( (!won) && (!lost) && (!bail) )
    {
        //cout << "lastprice = " << lastPrice << endl;
        if (won1500)
            cout << "O - $1,500" << endl;
        else
            cout << "X - $1,500" << endl;
        if (won1000)
            cout << "O - $1,000" << endl;
        else
            cout << "X - $1,000" << endl;
        if (won500)
            cout << "O - $500" << endl;
        else
            cout << "X - $500" << endl;

        for (int x = 0; x < 4; x++)
        {
            cout << x+1 << ". ";
            prizes[x].showPrize();
            if (chosen[x]){
                cout << " - ";
                prizes[x].showARP();
            }
            cout << endl;
        } // end for loop
    int choice = 0;
    while ( (choice < 1) || (choice > 4) ){
    if (on == 0){
        cout << endl << "Which item do you want to start with?: ";
    }
    else
        cout << endl << "Which item do you think is more expensive?: ";
    cin >> choice;
    }
    if ( chosen[choice-1] )
        cout << endl << "You've already chosen this item. Please pick another.";
    else
    {
        if (on == 0)
        {
            cout << endl << "The actual retail price of the ";
            prizes[choice-1].showShortName();
            cout << " is ";
            prizes[choice-1].showARP();
            chosen[choice-1] = true;
            lastPrice = prizes[choice-1].getPrice();
            on += 1;
        }
        else
        {
            //cout << "price: " << prizes[choice-1].getPrice() << ", other: " << lastPrice << endl;
            cout << endl << "The actual retail price of the ";
            prizes[choice-1].showShortName();
            cout << " is ";
            prizes[choice-1].showARP();
            if (prizes[choice-1].getPrice() < lastPrice)
                lost = true;
            else
            {
            chosen[choice-1] = true;
            if ( (on == 3) && (prizes[choice-1].getPrice() > lastPrice) )
                won = true;
            else
            {
            if (on == 1){
                won500 = true;
                winnings += 500;
            }
            else if (on == 2){
                won1000 = true;
                winnings += 1000;
                }
            char goOn = 'A';
            lastPrice = prizes[choice-1].getPrice();
            cout << endl << "You have $" << winnings << " and " << on+1 << " prizes.";
            while ( (goOn != 'Y') && (goOn != 'y') && (goOn != 'N') && (goOn != 'n') ){
            cout << endl << "Do you want to keep going (Y) or stop now (N)?: ";
            cin >> goOn;
            }
            if ( (goOn == 'N') || (goOn == 'n') )
                bail = true;
            else
                on += 1;

            } /// end else statement if the player is on the second or third prize

            } /// end else statement for if the player didn't lose
        }

    }
    cout << endl;
    } /// end while loop

    if (lost)
        cout << endl << "Sorry, you lose.";
    else if (won)
        cout << endl << "Congratulations, you win all four prizes and $3,000!";
    else if ( (bail) && (on == 2) )
        cout << endl << "You won " << on+1 << " prizes and $" << winnings << ". Thanks for playing!";
    else if ( (bail) && (on == 1) )
        cout << endl << "You won " << on+1 << " prizes and $" << winnings << ". Thanks for playing!";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Swap Meet
void playSwapMeet()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "SWAP MEET" << endl;

    medium prizes[4];
    int swapPrice;

    bool foundPair = false;
    medium temp1;
    medium temp2;


    int first;
    int second;

    int partner = rand() % 3;

    while (!foundPair){
        first = rand() % i;
        second = first;
        while (second == first)
            second = rand() % i;

        gameItemIt = gameItems.begin();
        for (int z = 0; z < first; z++)
            gameItemIt++;
        temp1.setDescription(gameItemIt->getDescription());
        temp1.setShortName(gameItemIt->getShortName());
        temp1.setPrice(gameItemIt->getPrice());

        gameItemIt = gameItems.begin();
        for (int z2 = 0; z2 < second; z2++)
            gameItemIt++;
        temp2.setDescription(gameItemIt->getDescription());
        temp2.setShortName(gameItemIt->getShortName());
        temp2.setPrice(gameItemIt->getPrice());

        if (temp1.getPrice() == temp2.getPrice()){
            prizes[0].setDescription(temp1.getDescription());
            prizes[0].setShortName(temp1.getShortName());
            prizes[0].setPrice(temp1.getPrice());
            if (partner == 0) /// The prize on the left is the one that should be swapped.
            {
            prizes[1].setDescription(temp2.getDescription());
            prizes[1].setShortName(temp2.getShortName());
            prizes[1].setPrice(temp2.getPrice());
            }
            else if (partner == 1) /// The prize in the middle needs to be swapped.
            {
            prizes[2].setDescription(temp2.getDescription());
            prizes[2].setShortName(temp2.getShortName());
            prizes[2].setPrice(temp2.getPrice());
            }
            else    /// The prize on the right needs to be swapped.
            {
            prizes[3].setDescription(temp2.getDescription());
            prizes[3].setShortName(temp2.getShortName());
            prizes[3].setPrice(temp2.getPrice());
            }
            foundPair = true;
        } // end if statement

    } /// end while loop that finds a pair of items


    int third;
    int fourth;
    medium temp3;
    medium temp4;
    bool setThird = false;
    bool setFourth = false;

    while (!setThird){
        third = first;
        while ( (third == first) || (third == second ) )
            third = rand() % i;

        gameItemIt = gameItems.begin();
        for (int z3 = 0; z3 < third; z3++)
            gameItemIt++;
        temp3.setDescription(gameItemIt->getDescription());
        temp3.setShortName(gameItemIt->getShortName());
        temp3.setPrice(gameItemIt->getPrice());

        if (temp3.getPrice() != prizes[0].getPrice())
        {
            if (partner == 0)
            {
            prizes[2].setDescription(temp3.getDescription());
            prizes[2].setShortName(temp3.getShortName());
            prizes[2].setPrice(temp3.getPrice());
            }
            else if (partner == 1)
            {
            prizes[1].setDescription(temp3.getDescription());
            prizes[1].setShortName(temp3.getShortName());
            prizes[1].setPrice(temp3.getPrice());
            }
            else
            {
            prizes[1].setDescription(temp3.getDescription());
            prizes[1].setShortName(temp3.getShortName());
            prizes[1].setPrice(temp3.getPrice());
            }
            setThird = true;
        }


    } /// end while loop that sets the third item

    while (!setFourth){
        fourth = first;
        while ( (fourth == first) || (fourth == second ) || (fourth == third ) )
            fourth = rand() % i;

        gameItemIt = gameItems.begin();
        for (int z4 = 0; z4 < fourth; z4++)
            gameItemIt++;
        temp4.setDescription(gameItemIt->getDescription());
        temp4.setShortName(gameItemIt->getShortName());
        temp4.setPrice(gameItemIt->getPrice());

        if (temp4.getPrice() != prizes[0].getPrice())
        {
            if (partner == 0)
            {
            prizes[3].setDescription(temp4.getDescription());
            prizes[3].setShortName(temp4.getShortName());
            prizes[3].setPrice(temp4.getPrice());
            }
            else if (partner == 1)
            {
            prizes[3].setDescription(temp4.getDescription());
            prizes[3].setShortName(temp4.getShortName());
            prizes[3].setPrice(temp4.getPrice());
            }
            else
            {
            prizes[2].setDescription(temp4.getDescription());
            prizes[2].setShortName(temp4.getShortName());
            prizes[2].setPrice(temp4.getPrice());
            }

            setFourth = true;
        }

    } /// end while loop that sets the fourth item

    int choice = 0;

    cout << endl << "Base prize:";
    cout << endl;
    prizes[0].showPrize();
    cout << endl << endl;
    for (int w = 0; w < 3; w++)
    {
        cout << w+1 << ". ";
        prizes[w+1].showPrize();
        cout << endl;
    }

    while ((choice < 1) || (choice > 3)){
        cout << endl << "Which item has the same price as the base item?: ";
        cin >> choice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[choice].showShortName();
    cout << " is ";
    prizes[choice].showARP();
    cout << endl;
    system("pause");
    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is ";
    prizes[0].showARP();
    cout << endl;
    if (prizes[choice].getPrice() == prizes[0].getPrice())
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    cout << endl;
    system("pause");
    system("CLS");
}

/// Switch?
void playSwitch()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ((inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1000)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "SWITCH?" << endl;

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
    medium prizes[2];
    int todo = rand() % 2; /// if 0, then the prices are correct. if 1, they should be switched.
    //cout << "todo = " << todo << endl;

    /// Set each item
    for (int itemCount = 0; itemCount < 2; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    if (todo == 0){
    cout << "1. ";
    prizes[0].showPrize();
    cout << " - ";
    prizes[0].showARP();
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << " - ";
    prizes[1].showARP();
    cout << endl;
    }
    else
    {
    cout << "1. ";
    prizes[0].showPrize();
    cout << " - ";
    prizes[1].showARP();
    cout << endl;
    cout << "2. ";
    prizes[1].showPrize();
    cout << " - ";
    prizes[0].showARP();
    cout << endl;
    }

    int achoice = 0;
    while ((achoice < 1) || (achoice > 2)){
    cout << endl << "Are these prices correct (1) or should they be switched (2)?: ";
    cin >> achoice;
    }

    cout << endl << "The actual retail price of the ";
    prizes[0].showShortName();
    cout << " is ";
    prizes[0].showARP();
    cout << endl << "The actual retail price of the ";
    prizes[1].showShortName();
    cout << " is ";
    prizes[1].showARP();

    if (achoice == todo+1)
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    cout << endl;
    system("pause");
    system("CLS");
}

/// Take Two
void playTakeTwo()
{
    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    ifstream inFile;
    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if (inFile >> t_Description >> t_ShortName >> t_Price)
    {
        pptr->setDescription(t_Description);
        pptr->setShortName(t_ShortName);
        pptr->setPrice(t_Price);
        gameItems.push_back(*pptr);
        i++;
    }
    } // end while loop
    inFile.close();

    cout << "TAKE TWO" << endl;

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
    medium prizes[4];
    bool picked[4];

    /// Initialize all the picked bools to false.
    for (int x = 0; x < 4; x++)
        picked[x] = false;

    /// Set each item
    for (int itemCount = 0; itemCount < 4; itemCount++)
    {
        gameItemIt = gameItems.begin();
        for (z = 0; z < randomizationField[itemCount]; z++)
        {
            gameItemIt++;
        }

        prizes[itemCount].setDescription(gameItemIt->getDescription());
        prizes[itemCount].setShortName(gameItemIt->getShortName());
        prizes[itemCount].setPrice(gameItemIt->getPrice());
    }

    int topick[4] = {0, 1, 2, 3};
    random_shuffle(&topick[0], &topick[4]);
    int total = prizes[topick[0]].getPrice() + prizes[topick[1]].getPrice();

    int choice1 = 0;
    int choice2 = 0;

    for (int y = 0; y < 4; y++){
        cout << y+1 << ". ";
        prizes[y].showPrize();
        cout << endl;
        }

    cout << "Target: $" << total;
    cout << endl;
    cout << endl << "Which two items total $" << total << "?: ";
    while ( (choice1 < 1) || (choice1 > 4) ){
        cout << endl << "Item #1: ";
        cin >> choice1;
    }
    while ( (choice2 < 1) || (choice2 > 4) || (choice2 == choice1) ){
        cout << endl << "Item #2: ";
        cin >> choice2;
    }

    cout << endl << "The actual retail price of the ";
    prizes[choice1-1].showShortName();
    cout << " is ";
    prizes[choice1-1].showARP();
    cout << endl << "The actual retail price of the ";
    prizes[choice2-1].showShortName();
    cout << " is ";
    prizes[choice2-1].showARP();
    int preTotal = prizes[choice1-1].getPrice() + prizes[choice2-1].getPrice();
    cout << endl << "For a total of $" << preTotal;
    cout << endl;
    if (preTotal == total)
        cout << endl << "Congratulations, you win!";
    else
    {
        cout << endl << "That's not correct, but you get a second chance.";
        int choice3 = 0;
        int choice4 = 0;
        cout << endl << endl;

        for (int x = 0; x < 4; x++){
        cout << x+1 << ". ";
        prizes[x].showPrize();
        cout << endl;
        }

        cout << "Target: $" << total;
        cout << endl;
        cout << endl << "Which two items total $" << total << "?: ";
        while ( (choice3 < 1) || (choice3 > 4) ){
        cout << endl << "Item #1: ";
        cin >> choice3;
        }
        while ( (choice4 < 1) || (choice4 > 4) || (choice4 == choice3) ){
        cout << endl << "Item #2: ";
        cin >> choice4;
        }

        cout << endl << "The actual retail price of the ";
        prizes[choice3-1].showShortName();
        cout << " is ";
        prizes[choice3-1].showARP();
        cout << endl << "The actual retail price of the ";
        prizes[choice4-1].showShortName();
        cout << " is ";
        prizes[choice4-1].showARP();
        int finTotal = prizes[choice3-1].getPrice() + prizes[choice4-1].getPrice();
        cout << endl << "For a total of $" << finTotal;
        cout << endl;

        if (finTotal == total)
            cout << endl << "Congratulations, you win!";
        else
            cout << endl << "Sorry, you lose.";



    } /// end else

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Two for the Price of One
void playTwoForOne()
{
    list<large> gameItemsLarge;
    list<large>::iterator gameItemsLargeIt;

    string l_Description;
    string l_ShortName;
    int l_Price;

    large * lptr;

    list<medium> gameItems;
    list<medium>::iterator gameItemIt;

    string t_Description;
    string t_ShortName;
    int t_Price;

    medium * pptr;

    srand(time(0));

    int i = 0;
    int j = 0;

    ifstream inFile;

    inFile.open("medium.txt");
    while (inFile)
    {
    pptr = new medium;
    if ( (inFile >> t_Description >> t_ShortName >> t_Price) && (t_Price < 1000) )
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

    inFile.open("large.txt");
    while (inFile)
    {
    lptr = new large;
    if (inFile >> l_Description >> l_ShortName >> l_Price)
    {
        lptr->setDescription(l_Description);
        lptr->setShortName(l_ShortName);
        lptr->setPrice(l_Price);
        gameItemsLarge.push_back(*lptr);
        j++;

    }
    } // end while loop
    inFile.close();

    cout << "TWO FOR THE PRICE OF ONE" << endl;

    //cout << "i = " << i << endl;
    //cout << "j = " << j << endl;

    int randomMediumNo = rand() % i;
    int randomLargeNo = rand() % j;

    int z = 0;
    int z2 = 0;

    large bonusPrize;
    medium comboPrize;

    /// Set the large prize.
    gameItemsLargeIt = gameItemsLarge.begin();
    for (z = 0; z < randomLargeNo; z++)
        gameItemsLargeIt++;
    bonusPrize.setDescription(gameItemsLargeIt->getDescription());
    bonusPrize.setShortName(gameItemsLargeIt->getShortName());
    bonusPrize.setPrice(gameItemsLargeIt->getPrice());

    /// Set the medium prize
    gameItemIt = gameItems.begin();
    for (z2 = 0; z2 < randomMediumNo; z2++)
        gameItemIt++;
    comboPrize.setDescription(gameItemIt->getDescription());
    comboPrize.setShortName(gameItemIt->getShortName());
    comboPrize.setPrice(gameItemIt->getPrice());

    cout << endl;

    cout << "Large prize:" << endl;
    bonusPrize.showPrize();
    cout << endl;
    cout << "Smaller prize:" << endl;
    comboPrize.showPrize();
    cout << endl;

    /// If these are 0, then the correct choice will be on top. If 1, the correct choice will be on the bottom.
    int position1 = rand() % 2;
    int position2 = rand() % 2;
    int position3 = rand() % 2;

    int firstDigitChoiceA;
    int firstDigitChoiceB;
    int secondDigitChoiceA;
    int secondDigitChoiceB;
    int thirdDigitChoiceA;
    int thirdDigitChoiceB;

    /// Set choices for first number
    if (position1 == 0){
        firstDigitChoiceA = comboPrize.getPrice() / 100 % 10;
        firstDigitChoiceB = firstDigitChoiceA;
        while (firstDigitChoiceB == firstDigitChoiceA)
            firstDigitChoiceB = rand()%(9-4 + 1) + 4;
    }
    else{
        firstDigitChoiceB = comboPrize.getPrice() / 100 % 10;
        firstDigitChoiceA = firstDigitChoiceB;
        while (firstDigitChoiceA == firstDigitChoiceB)
            firstDigitChoiceA = rand()%(9-4 + 1) + 4;
    }

    /// Set choices for second number
    if (position2 == 0){
        secondDigitChoiceA = comboPrize.getPrice() / 10 % 10;
        secondDigitChoiceB = secondDigitChoiceA;
        while (secondDigitChoiceB == secondDigitChoiceA)
            secondDigitChoiceB = rand() % 10;
    }
    else{
        secondDigitChoiceB = comboPrize.getPrice() / 10 % 10;
        secondDigitChoiceA = secondDigitChoiceB;
        while (secondDigitChoiceA == secondDigitChoiceB)
            secondDigitChoiceA = rand() % 10;
    }

    /// Set choices for third number
    if (position3 == 0){
        thirdDigitChoiceA = comboPrize.getPrice() % 10;
        thirdDigitChoiceB = thirdDigitChoiceA;
        while (thirdDigitChoiceB == thirdDigitChoiceA)
            thirdDigitChoiceB = rand() % 10;
    }
    else{
        thirdDigitChoiceB = comboPrize.getPrice() % 10;
        thirdDigitChoiceA = thirdDigitChoiceB;
        while (thirdDigitChoiceA == thirdDigitChoiceB)
            thirdDigitChoiceA = rand() % 10;
    }

    cout << endl << " " << firstDigitChoiceA << secondDigitChoiceA << thirdDigitChoiceA;
    cout << endl << "$***";
    cout << endl << " " << firstDigitChoiceB << secondDigitChoiceB << thirdDigitChoiceB;

    int freeDigit = 0;
    while ( (freeDigit < 1) || (freeDigit > 3) ){
        cout << endl << "Which digit (enter a number (1-3) do you want for free?: ";
        cin >> freeDigit;
    }

    char first = 'X';
    char second = 'X';
    char third = 'X';

    int playerPrice = 0;

    if (freeDigit == 1){
        if (position1 == 0){
            cout << endl << " #" << secondDigitChoiceA << thirdDigitChoiceA;
            cout << endl << "$" << firstDigitChoiceA << "**";
            cout << endl << firstDigitChoiceB << secondDigitChoiceB << thirdDigitChoiceB;
            playerPrice += firstDigitChoiceA*100;
        }
        else{
            cout << endl << " " << firstDigitChoiceA << secondDigitChoiceA << thirdDigitChoiceA;
            cout << endl << "$" << firstDigitChoiceB << "**";
            cout << endl << " #" << secondDigitChoiceB << thirdDigitChoiceB;
            playerPrice += firstDigitChoiceB*100;
        }

    /// Enter the remaining digits
    while ( (second != 'A') && (second != 'B') && (second != 'a') && (second != 'b') ){
        cout << endl << "Is the middle number " << secondDigitChoiceA << " (A) or " << secondDigitChoiceB << " (B)?: ";
        cin >> second;
    }
    if ( (second == 'A') || (second == 'a') )
        playerPrice += secondDigitChoiceA*10;
    else
        playerPrice += secondDigitChoiceB*10;

    while ( (third != 'A') && (third != 'B') && (third != 'a') && (third != 'b') ){
        cout << endl << "Is the last number " << thirdDigitChoiceA << " (A) or " << thirdDigitChoiceB << " (B)?: ";
        cin >> third;
    }
    if ( (third == 'A') || (third == 'a') )
        playerPrice += thirdDigitChoiceA;
    else
        playerPrice += thirdDigitChoiceB;

    } // player guessed first digit for free

    else if (freeDigit == 2){
        if (position2 == 0){
            cout << endl << " " << firstDigitChoiceA << "#" << thirdDigitChoiceA;
            cout << endl << "$*" << secondDigitChoiceA << "*";
            cout << endl << " " << firstDigitChoiceB << secondDigitChoiceB << thirdDigitChoiceB;
            playerPrice += secondDigitChoiceA*10;
        }
        else{
            cout << endl << " " << firstDigitChoiceA << secondDigitChoiceA << thirdDigitChoiceA;
            cout << endl << "$*" << secondDigitChoiceB << "*";
            cout << endl << " " << firstDigitChoiceB << "#" << thirdDigitChoiceB;
            playerPrice += secondDigitChoiceB*10;
        }

    /// Enter the remaining digits
    while ( (first != 'A') && (first != 'B') && (first != 'a') && (first != 'b') ){
        cout << endl << "Is the first number " << firstDigitChoiceA << " (A) or " << firstDigitChoiceB << " (B)?: ";
        cin >> first;
    }
    if ( (first == 'A') || (first == 'a') )
        playerPrice += firstDigitChoiceA*100;
    else
        playerPrice += firstDigitChoiceB*100;

    while ( (third != 'A') && (third != 'B') && (third != 'a') && (third != 'b') ){
        cout << endl << "Is the last number " << thirdDigitChoiceA << " (A) or " << thirdDigitChoiceB << " (B)?: ";
        cin >> third;
    }
    if ( (third == 'A') || (third == 'a') )
        playerPrice += thirdDigitChoiceA;
    else
        playerPrice += thirdDigitChoiceB;

    } // player guessed middle digit for free

    else{
        if (position3 == 0){
        cout << endl << " " << firstDigitChoiceA << secondDigitChoiceA << "#";
        cout << endl << "$**" << thirdDigitChoiceA;
        cout << endl << " " << firstDigitChoiceB << secondDigitChoiceB << thirdDigitChoiceB;
        playerPrice += thirdDigitChoiceA;
        }
        else{
        cout << endl << " " << firstDigitChoiceA << secondDigitChoiceA << thirdDigitChoiceA;
        cout << endl << "$**" << thirdDigitChoiceB;
        cout << endl << " " << firstDigitChoiceB << secondDigitChoiceB << "#";
        playerPrice += thirdDigitChoiceB;
        }

    /// Enter the remaining digits
    while ( (first != 'A') && (first != 'B') && (first != 'a') && (first != 'b') ){
        cout << endl << "Is the first number " << firstDigitChoiceA << " (A) or " << firstDigitChoiceB << " (B)?: ";
        cin >> first;
    }
    if ( (first == 'A') || (first == 'a') )
        playerPrice += firstDigitChoiceA*100;
    else
        playerPrice += firstDigitChoiceB*100;

    while ( (second != 'A') && (second != 'B') && (second != 'a') && (second != 'b') ){
        cout << endl << "Is the middle number " << secondDigitChoiceA << " (A) or " << secondDigitChoiceB << " (B)?: ";
        cin >> second;
    }
    if ( (second == 'A') || (second == 'a') )
        playerPrice += secondDigitChoiceA*10;
    else
        playerPrice += secondDigitChoiceB*10;

    } // player guessed last digit for free

    cout << endl << "You set the price to $" << playerPrice;
    cout << endl << endl << "The actual retail price is ";
    comboPrize.showARP();
    if (playerPrice == comboPrize.getPrice())
        cout << endl << "Congratulations, you win!";
    else
        cout << endl << "Sorry, you lose.";

    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

/// Walk of Fame
void playWalkOfFame()
{
    list<small> firstPrizes;
    list<small>::iterator firstPrizesIt;
    string f_Description;
    string f_ShortName;
    int f_Price;
    small * fptr;

    list<medium> secondPrizes;
    list<medium>::iterator secondPrizesIt;
    string s_Description;
    string s_ShortName;
    int s_Price;
    medium * sptr;

    list<medium> thirdPrizes;
    list<medium>::iterator thirdPrizesIt;
    string t_Description;
    string t_ShortName;
    int t_Price;
    medium * tptr;

    list<large> lastPrizes;
    list<large>::iterator lastPrizesIt;
    string l_Description;
    string l_ShortName;
    int l_Price;
    large * lptr;

    srand(time(0));

    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    ifstream inFile;

    /// Small prizes
    inFile.open("small.txt");
    while (inFile)
    {
    fptr = new small;
    if ( (inFile >> f_Description >> f_ShortName >> f_Price) && f_Price < 200)
    {
        fptr->setDescription(f_Description);
        fptr->setShortName(f_ShortName);
        fptr->setPrice(f_Price);
        firstPrizes.push_back(*fptr);
        i++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Medium prizes under $1000
    inFile.open("medium.txt");
    while (inFile)
    {
    sptr = new medium;
    if ( (inFile >> s_Description >> s_ShortName >> s_Price) && s_Price < 1000)
    {
        sptr->setDescription(s_Description);
        sptr->setShortName(s_ShortName);
        sptr->setPrice(s_Price);
        secondPrizes.push_back(*sptr);
        j++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Medium prizes over $1000
    inFile.open("medium.txt");
    while (inFile)
    {
    tptr = new medium;
    if ( (inFile >> t_Description >> t_ShortName >> t_Price) && t_Price > 1000)
    {
        tptr->setDescription(t_Description);
        tptr->setShortName(t_ShortName);
        tptr->setPrice(t_Price);
        thirdPrizes.push_back(*tptr);
        k++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    /// Large prizes
    inFile.open("large.txt");
    while (inFile)
    {
    lptr = new large;
    if ( (inFile >> l_Description >> l_ShortName >> l_Price) && l_Price < 8000)
    {
        lptr->setDescription(l_Description);
        lptr->setShortName(l_ShortName);
        lptr->setPrice(l_Price);
        lastPrizes.push_back(*lptr);
        l++;

    }
    } // end while loop
    inFile.close();
    inFile.clear();

    cout << "WALK OF FAME" << endl;

    cout << endl;
    int randFirst = rand() % i;
    int randSecond = rand() % j;
    int randThird = rand() % k;
    int randLast = rand() % l;

    small prize1;
    medium prize2;
    medium prize3;
    large prize4;

    int z1;
    int z2;
    int z3;
    int z4;

    /// Set the small prize.
    firstPrizesIt = firstPrizes.begin();
    for (z1 = 0; z1 < randFirst; z1++)
        firstPrizesIt++;
    prize1.setDescription(firstPrizesIt->getDescription());
    prize1.setShortName(firstPrizesIt->getShortName());
    prize1.setPrice(firstPrizesIt->getPrice());

    /// Set the smaller medium prize.
    secondPrizesIt = secondPrizes.begin();
    for (z2 = 0; z2 < randSecond; z2++)
        secondPrizesIt++;
    prize2.setDescription(secondPrizesIt->getDescription());
    prize2.setShortName(secondPrizesIt->getShortName());
    prize2.setPrice(secondPrizesIt->getPrice());

    /// Set the larger medium prize.
    thirdPrizesIt = thirdPrizes.begin();
    for (z3 = 0; z3 < randThird; z3++)
        thirdPrizesIt++;
    prize3.setDescription(thirdPrizesIt->getDescription());
    prize3.setShortName(thirdPrizesIt->getShortName());
    prize3.setPrice(thirdPrizesIt->getPrice());

    /// Set the large prize.
    lastPrizesIt = lastPrizes.begin();
    for (z4 = 0; z4 < randLast; z4++)
        lastPrizesIt++;
    prize4.setDescription(lastPrizesIt->getDescription());
    prize4.setShortName(lastPrizesIt->getShortName());
    prize4.setPrice(lastPrizesIt->getPrice());

    int secondChanceBook = rand() % 2;
    bool usedSecondChance = false;
    bool lost = false;
    bool won = false;

    int price1 = 0;
    int difference1 = 0;
    int book = 0;

    cout << "1. ";
    prize1.showPrize();
    cout << endl << "RANGE: $50";
    while (price1 <= 0){
    cout << endl << "Price: $";
    cin >> price1;
    }
    cout << endl << "The actual retail price is ";
    prize1.showARP();
    difference1 = abs(price1 - prize1.getPrice());
    cout << endl << "For a difference of $" << difference1;
    cout << endl;
    if (difference1 > 50)
    {
        cout << endl << "You don't win this prize, but you may get a second chance.";
        while (book < 1 || book > 2){
        cout << endl << "There are two autograph books numbered 1 and 2.\nWhich do you want to pick?: ";
        cin >> book;
        }
        if (book-1 == secondChanceBook){
            cout << endl << "Yes, you get a second chance!";
            usedSecondChance = true;
            }
        else
            lost = true;
    }
    if (!lost)
    {
        int price2 = 0;
        int difference2 = 0;
        cout << endl << "2. ";
        prize2.showPrize();
        cout << endl << "RANGE: $200";
        while (price2 <= 0){
        cout << endl << "Price: $";
        cin >> price2;
    }

    cout << endl << "The actual retail price is ";
    prize2.showARP();
    difference2 = abs(price2 - prize2.getPrice());
    cout << endl << "For a difference of $" << difference2;
    cout << endl;

    if (difference2 > 200)
    {
    if (usedSecondChance)
        lost = true;
    else
    {
        cout << endl << "You don't win this prize, but you may get a second chance.";
        while (book < 1 || book > 2){
        cout << endl << "There are two autograph books numbered 1 and 2. \nWhich do you want to pick?: ";
        cin >> book;
        }
        if (book-1 == secondChanceBook){
            cout << endl << "Yes, you get a second chance!";
            usedSecondChance = true;
            }
        else
            lost = true;
    } // end else statement for if player can use second chance on the second item

    } // end if statement for if the player goes outside the range on item #2
    if (!lost)
    {
        int price3 = 0;
        int difference3 = 0;
        cout << endl << "3. ";
        prize3.showPrize();
        cout << endl << "RANGE: $500";
        while (price3 <= 0){
        cout << endl << "Price: $";
        cin >> price3;
        }

        cout << endl << "The actual retail price is ";
        prize3.showARP();
        difference3 = abs(price3 - prize3.getPrice());
        cout << endl << "For a difference of $" << difference3;
        cout << endl;

        if (difference3 > 500)
        {
        if (usedSecondChance)
        lost = true;
        else
        {
        cout << endl << "You don't win this prize, but you may get a second chance.";
        while (book < 1 || book > 2){
        cout << endl << "There are two autograph books numbered 1 and 2. \nWhich do you want to pick?: ";
        cin >> book;
        }
        if (book-1 == secondChanceBook){
            cout << endl << "Yes, you get a second chance!";
            usedSecondChance = true;
            }
        else
            lost = true;

        }
        } // end if statement for if the player goes outside the range on item #3
        if (!lost)
        {
        int price4 = 0;
        int difference4 = 0;
        cout << endl << "4. ";
        prize4.showPrize();
        cout << endl << "RANGE: $1000";
        while (price4 <= 0){
        cout << endl << "Price: $";
        cin >> price4;
        }
        cout << endl << "The actual retail price is ";
        prize4.showARP();
        difference4 = abs(price4 - prize4.getPrice());
        cout << endl << "For a difference of $" << difference4;
        cout << endl;

        if (difference4 > 1000)
            lost = true;
        else
            won = true;

        } // end if statement for if player guessed third item correctly

    } // end if statement for if player guessed second item correctly

    } // end if statement for if player guessed first item correctly
    if (lost)
        cout << endl << "Ouch. You are a loser...";
    if (won)
        cout << endl << "Congratulations, you win!";


    /// end of the game
    cout << endl;
    system("pause");
    system("CLS");
}

#endif // MULTIPRIZE_H_INCLUDED
