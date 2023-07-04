#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

#include "prize.h"

/// header files that contain the games themselves
#include "smallprize.h"
#include "games.h"
#include "multiprize.h"
#include "singleprize.h"
#include "cargames.h"

using namespace std;

/// function prototypes for the menu functions
void displayMainMenu();
void displayGrocMenu();
void displaySmalMenu();
void displaySingMenu();
void displayMultMenu();
void displayCarsMenu();
void displayCars2Menu();
void displayCashMenu();
void displayRetiredMenu();
void displayRetired2Menu();
void displayCustomMenu();
void randomGame(int r);

int main()
{
    //playFillErUp();

    int cat; /// Category selection
    int gro; /// Grocery game selection
    int sma; /// Small prize game selection
    int sng; /// Single-prize game selection
    int mul; /// Multi-prize game selection
    int cgs; /// Car game selection
    int cms; /// Car games with other items selection
    int csh; /// Cash game selection
    int ret; /// Retired games (A-J) selection
    int re2; /// Retired games (M-W) selection
    int cus; /// Custom games selection

    bool mdsMode;

    cout << "THE PRICE IS RIGHT" << endl;
    srand(time(0));

    do{
    int rgame = rand() % 120;
    //cout << endl << "random game: " << rgame;
    cat = 0;
    displayMainMenu();
    cin >> cat;
    switch (cat)
    {

    case 0: /// Play a random game. This is an easter egg hidden from the player.
        system("CLS");
        randomGame(rgame);
        break;


    case 1: /// Grocery games
        gro = 0;
        do{
        displayGrocMenu();
        cin >> gro;
        switch (gro)
        {

        case 1:
            system("CLS");
            playBullseye();
            break;

        case 2:
            system("CLS");
            playCheckOut();
            break;

        case 3:
            system("CLS");
            playGroceryGame();
            break;

        case 4:
            system("CLS");
            playHiLo();
            break;

        case 5:
            system("CLS");
            playNowOrThen();
            break;

        case 6:
            system("CLS");
            playPickAPair();
            break;

        case 7:
            system("CLS");
            playVendOPrice();
            break;

        case 8:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 8.";

        } // end switch statement for grocery games

        } // end grocery do-while loop
        while (gro != 8);
        break;

    case 2: /// Small prize games
        sma = 0;
        do{
        displaySmalMenu();
        cin >> sma;
        switch (sma)
        {
        case 1:
            system("CLS");
            playBackTo72();
            break;

        case 2:
            system("CLS");
            playBonusGame();
            break;

        case 3:
            system("CLS");
            playCliffHangers();
            break;

        case 4:
            system("CLS");
            playSecretX();
            break;

        case 5:
            system("CLS");
            playShellGame();
            break;

        case 6:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 6.";

        } // end switch statement for small prize games

        } // end small do-while loop
        while (sma != 6);
        break;

    case 3: /// Single-prize games
        sng = 0;
        do{
        displaySingMenu();
        cin >> sng;
        switch (sng)
        {
        case 1:
            system("CLS");
            playBalanceGame();
            break;

        case 2:
            system("CLS");
            playBonkers();
            break;

        case 3:
            system("CLS");
            playCheckGame();
            break;

        case 4:
            system("CLS");
            playComingOrGoing();
            break;

        case 5:
            system("CLS");
            playDoublePrices();
            break;

        case 6:
            system("CLS");
            playFlipFlop();
            break;

        case 7:
            system("CLS");
            playFreezeFrame();
            break;

        case 8:
            system("CLS");
            playPickANumber();
            break;

        case 9:
            system("CLS");
            playPushOver();
            break;

        case 10:
            system("CLS");
            playRangeGame();
            break;

        case 11:
            system("CLS");
            playSideBySide();
            break;

        case 12:
            system("CLS");
            playSqueezePlay();
            break;

        case 13:
            system("CLS");
            break;

        default:
           cout << endl << "Please enter a number between 1 and 13.";

        } // end switch statement for single-prize games

        } // end small do-while loop
        while (sng != 13);
        break;

    case 4: /// Multi-prize games
        mul = 0;
        do{
        displayMultMenu();
        cin >> mul;
        switch (mul)
        {
        case 1:
            system("CLS");
            playBargainGame();
            break;

        case 2:
            system("CLS");
            playClockGame();
            break;

        case 3:
            system("CLS");
            playDangerPrice();
            break;

        case 4:
            system("CLS");
            playDoTheMath();
            break;

        case 5:
            system("CLS");
            playDoubleCross();
            break;

        case 6:
            system("CLS");
            playEasyAs123();
            break;

        case 7:
            system("CLS");
            playMagicNumber();
            break;

        case 8:
            system("CLS");
            playMakeYourMove();
            break;

        case 9:
            system("CLS");
            playMostExpensive();
            break;

        case 10:
            system("CLS");
            playOneRightPrice();
            break;

        case 11:
            system("CLS");
            playOneWrongPrice();
            break;

        case 12:
            system("CLS");
            playRaceGame();
            break;

        case 13:
            system("CLS");
            playSafeCrackers();
            break;

        case 14:
            system("CLS");
            playShoppingSpree();
            break;

        case 15:
            system("CLS");
            playSwapMeet();
            break;

        case 16:
            system("CLS");
            playSwitch();
            break;

        case 17:
            system("CLS");
            playTakeTwo();
            break;

        case 18:
            system("CLS");
            playTwoForOne();
            break;

        case 19:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 19.";

        } // end switch statement for multi-prize games
        }
        while (mul != 19);
        break;

    case 5: /// Car games
        cgs = 0;
        do{
        displayCarsMenu();
        cin >> cgs;
        switch (cgs)
        {
        case 1:
            system("CLS");
            playCardGame();
            break;

        case 2:
            system("CLS");
            playCoverUp();
            break;

        case 3:
            system("CLS");
            playDiceGame();
            break;

        case 4:
            system("CLS");
            playGasMoney();
            break;

        case 5:
            system("CLS");
            playGridlock();
            break;

        case 6:
            system("CLS");
            playLuckySeven();
            break;

        case 7:
            system("CLS");
            playMoneyGame();
            break;

        case 8:
        {
            char oneAwayMDG = '!';
            while ( (oneAwayMDG != 'Y') && (oneAwayMDG != 'N') &&  (oneAwayMDG != 'y') && (oneAwayMDG != 'n') ){
            cout << endl << "Play One Away as the Million Dollar Game (Y/N)?: ";
            cin >> oneAwayMDG;
            } // end while
            if ((oneAwayMDG == 'Y') || (oneAwayMDG == 'y')){
            system("CLS");
            playOneAway(true);
            }
            else{
            system("CLS");
            playOneAway(false);
            }
            break;
        }

        case 9:
            system("CLS");
            playPocketChange();
            break;

        case 10:
            system("CLS");
            playThatsTooMuch();
            break;

        case 11:
            system("CLS");
            playThreeStrikes();
            break;

        case 12:
            system("CLS");
            playTriplePlay();
            break;

        case 13:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 13.";

        } // end switch statement for car games
        }
        while (cgs != 13);
        break;

    case 6: /// Car/other prizes games
        cms = 0;
        do{
        displayCars2Menu();
        cin >> cms;
        switch (cms)
        {

        case 1:
            system("CLS");
            playAnyNumber();
            break;

        case 2:
            system("CLS");
            playFivePriceTags();
            break;

        case 3:
            system("CLS");
            playGoldenRoad();
            break;

        case 4:
            system("CLS");
            playHoleInOne();
            break;

        case 5:
            system("CLS");
            playLetEmRoll();
            break;

        case 6:
            system("CLS");
            playLineEmUp();
            break;

        case 7:
            system("CLS");
            playMasterKey();
            break;

        case 8:
            system("CLS");
            playMoreOrLess();
            break;

        case 9:
            system("CLS");
            playPassTheBuck();
            break;

        case 10:
            system("CLS");
            playPathfinder();
            break;

        case 11:
            system("CLS");
            playRatRace();
            break;

        case 12:
            system("CLS");
            playSpellingBee();
            break;

        case 13:
            system("CLS");
            playStackTheDeck();
            break;

        case 14:
        {
            char switcherooMDG = '!';
            while ( (switcherooMDG != 'Y') && (switcherooMDG != 'N') && (switcherooMDG != 'y') && (switcherooMDG != 'n') ){
            cout << endl << "Play Switcheroo as the Million Dollar Game (Y/N)?: ";
            cin >> switcherooMDG;
            } // end while

            if ((switcherooMDG == 'Y') || (switcherooMDG == 'y')){
            system("CLS");
            playSwitcheroo(true);
            }
            else{
            system("CLS");
            playSwitcheroo(false);
            }

            break;
        }

        case 15:
            system("CLS");
            playTemptation();
            break;

        case 16:
            system("CLS");
            playTenChances();
            break;

        case 17:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 17.";
        } // end switch statement for car/prize games
        }
        while (cms != 17);
        break;

    case 7: /// Cash games
        csh = 0;
        do{
        displayCashMenu();
        cin >> csh;
        switch (csh)
        {
        case 1:
            system("CLS");
            playGrandGame();
            break;

        case 2:
        {
            char halfOffMDS = '!';
            char halfOffMDG = '!';
            while ( (halfOffMDS != 'Y') && (halfOffMDS != 'y') && (halfOffMDS != 'N') && (halfOffMDS != 'n') ){
                cout << endl << "Play 1/2 Off for $25,000 (Y/N)?: ";
                cin >> halfOffMDS;
            }
            if ( (halfOffMDS == 'Y') || (halfOffMDS == 'y') ){
            /// Playing 1/2 Off for $25,000
            while ( (halfOffMDG != 'Y') && (halfOffMDG != 'y') && (halfOffMDG != 'N') && (halfOffMDG != 'n') ){
                cout << endl << "Play 1/2 Off as the Million Dollar Game (Y/N)?: ";
                cin >> halfOffMDG;
            }
            if ( (halfOffMDG == 'Y') || (halfOffMDG == 'y') ){
                system("CLS");
                playHalfOff(true, true);
            }
            else{
                system("CLS");
                playHalfOff(true, false);
            }

            } // play for $25,000
            else{
            system("CLS");
            playHalfOff(false, false);
            }
            break;
        }

        case 3:
            system("CLS");
            playHotSeat();
            break;

        case 4:
            system("CLS");
            playItsInTheBag();
            break;

        case 5:
            system("CLS");
            playPayTheRent();
            break;

        case 6:
            system("CLS");
            playPlinko();
            break;

        case 7:
            system("CLS");
            playPunchABunch();
            break;

        case 8:
            system("CLS");
            playTimeIsMoney();
            break;

        case 9:
            system("CLS");
            playToThePenny();
            break;

        case 10:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 10.";

        } // end switch statement for cash games
        }
        while (csh != 10);
        break;

    case 8: /// Retired games (A-J)
        ret = 0;
        do{
        displayRetiredMenu();
        cin >> ret;
        switch (ret)
        {
        case 1:
            system("CLS");
            playAddEmUp();
            break;

        case 2:
            system("CLS");
            playBalanceGame84();
            break;

        case 3:
            system("CLS");
            playBullseye72();
            break;

        case 4:
            system("CLS");
            playBump();
            break;

        case 5:
            system("CLS");
            playBuyOrSell();
            break;

        case 6:
            system("CLS");
            playClearanceSale();
            break;

        case 7:
            system("CLS");
            playCreditCard();
            break;

        case 8:
            system("CLS");
            playDoubleBullseye();
            break;

        case 9:
            system("CLS");
            playDoubleDigits();
            break;

        case 10:
            system("CLS");
            playFinishLine();
            break;

        case 11:
            system("CLS");
            playFortuneHunter();
            break;

        case 12:
            system("CLS");
            playGalleryGame();
            break;

        case 13:
            system("CLS");
            playGiveOrKeep();
            break;

        case 14:
            system("CLS");
            playHitMe();
            break;

        case 15:
            system("CLS");
            playHurdles();
            break;

        case 16:
            system("CLS");
            playItsOptional();
            break;

        case 17:
            system("CLS");
            playJoker();
            break;

        case 18:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 18.";

        } // end switch statement for retired games A-J
        }
        while (ret != 18);
        break;

    case 9:
        re2 = 0;
        do{
        displayRetired2Menu();
        cin >> re2;
        switch (re2){
        case 1:
            system("CLS");
            playMakeYourMark();
            break;

        case 2:
            system("CLS");
            playMysteryPrice();
            break;

        case 3:
            system("CLS");
            playOnTheNose();
            break;

        case 4:
            system("CLS");
            playOnTheSpot();
            break;

        case 5:
            system("CLS");
            playPennyAnte();
            break;

        case 6:
            system("CLS");
            playPokerGame();
            break;

        case 7:
            system("CLS");
            playProfessorPrice();
            break;

        case 8:
            system("CLS");
            playShowerGame();
            break;

        case 9:
            system("CLS");
            playSplitDecision();
            break;

        case 10:
            system("CLS");
            playStepUp();
            break;

        case 11:
            system("CLS");
            playSuperBall();
            break;

        case 12:
            system("CLS");
            playSuperSaver();
            break;

        case 13:
            system("CLS");
            playTelephoneGame();
            break;

        case 14:
            system("CLS");
            playThePhoneHomeGame();
            break;

        case 15:
            system("CLS");
            playTraderBob();
            break;

        case 16:
            system("CLS");
            playWalkOfFame();
            break;

        case 17:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 17.";

        } // end switch statement for retired games M-W
        }
        while (re2 != 17);
        break;

    case 10:
        cus = 0;
        do{
        displayCustomMenu();
        cin >> cus;
        switch (cus){
        case 1:
            system("CLS");
            playBigItemBash();
            break;

        case 2:
            system("CLS");
            playDominoGame();
            break;

        case 3:
            system("CLS");
            playFillErUp();
            break;

        case 4:
            system("CLS");
            playJam();
            break;

        case 5:
            system("CLS");
            playMasterPrice();
            break;

        case 6:
            system("CLS");
            playOneForAll();
            break;

        case 7:
            system("CLS");
            playOneWayOrAnother();
            break;

        case 8:
            system("CLS");
            playSevenUp();
            break;

        case 9:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 9.";

        } // end switch for custom games
        }
        while (cus != 9);
        break;

    case 11: /// Play a user-generated line-up
    {
        vector<int> lineup;
        ifstream in;
        string setup;
        cout << endl << "Enter the .txt file containing your line-up: ";
        cin >> setup;
        in.open(setup);
        if (!in){
            cout << endl << "This file doesn't exist." << endl;
            in.close();
            system("pause");
            system("CLS");
        }
        else{
        int n;
        while (in >> n){
            lineup.push_back(n);
        }
        in.close();
        if (lineup.size() != 6){
            cout << endl << "A line-up needs to have six games in it." << endl;
            system("pause");
            system("CLS");
            }
        else{
            system("CLS");
            for (int a = 0; a < 6; a++)
                randomGame(lineup[a]);
        }
        }
        break;
    } // end case 11


    case 12: /// Quit
        ;
        break;

    default:
        cout << endl << "Please enter a number between 1 and 12.";

    } // end switch statement

    } // end do-while loop
    while (cat != 12);

    /*
    playHitMe();

    playTenChances();

    playFreezeFrame();

    playGridlock();

    playHurdles();

    playGrandGame();

    playShowerGame();

    playRangeGame();

    playSuperSaver();

    playTakeTwo();

    playBuyOrSell();

    playBackTo72();

    playShellGame();

    playFinishLine();

    playPickANumber();

    playMagicNumber();

    playMoreOrLess();

    playPushOver();

    playSqueezePlay();

    playFivePriceTags();

    playMakeYourMove();

    playBalanceGame();

    playMoneyGame();

    playSafeCrackers();

    playPlinko();

    playLetEmRoll();

    playStepUp();

    playBullseye72();

    playPassTheBuck();

    playBump();

    playGiveOrKeep();

    playItsInTheBag();

    playThatsTooMuch();

    playCardGame();

    playPunchABunch();

    playGasMoney();

    playDiceGame();

    playCheckGame();

    playLuckySeven();

    playDangerPrice();

    playDoTheMath();

    playBargainGame();

    playOneRightPrice();

    playEasyAs123();

    playSwitch();

    playClockGame();

    playOneWrongPrice();

    playDoublePrices();

    playSideBySide();

    playFlipFlop();

    playComingOrGoing();

    playMostExpensive();

    playShoppingSpree();

    playSecretX();

    playHiLo();

    playCliffHangers();

    playCheckOut();

    playVendOPrice();

    playGroceryGame();

    playBullseye();

    playBonusGame();
    */

    return 0;
}

void displayMainMenu()
{
    cout << endl << "1. Grocery games";
    cout << endl << "2. Small prize games";
    cout << endl << "3. Single-prize games";
    cout << endl << "4. Multi-prize games";
    cout << endl << "5. Car games";
    cout << endl << "6. Car + other item games";
    cout << endl << "7. Cash games";
    cout << endl << "8. Retired games (A-J)";
    cout << endl << "9. Retired games (M-W)";
    cout << endl << "10. Custom games";
    cout << endl << "11. Play a line-up you've created";
    cout << endl << "12. Quit";
    cout << endl << "Select a game classification: ";
}

void displayGrocMenu()
{
    cout << endl << "GROCERY GAMES" << endl;
    cout << endl << "1. Bullseye";
    cout << endl << "2. Check-Out";
    cout << endl << "3. Grocery Game";
    cout << endl << "4. Hi-Lo";
    cout << endl << "5. Now... or Then";
    cout << endl << "6. Pick-a-Pair";
    cout << endl << "7. Vend-o-Price";
    cout << endl << "8. Go back";
    cout << endl << "Select a pricing game: ";
}

void displaySmalMenu()
{
    cout << endl << "SMALL PRIZE GAMES" << endl;
    cout << endl << "1. Back to '72";
    cout << endl << "2. Bonus Game";
    cout << endl << "3. Cliff Hangers";
    cout << endl << "4. Secret \"X\"";
    cout << endl << "5. Shell Game";
    cout << endl << "6. Go back";
    cout << endl << "Select a pricing game: ";
}

void displaySingMenu()
{
    cout << endl << "SINGLE PRIZE GAMES" << endl;
    cout << endl << "1. Balance Game (2006)  8. Pick-a-Number";
    cout << endl << "2. Bonkers              9. Push-Over";
    cout << endl << "3. Check Game           10. Range Game";
    cout << endl << "4. Coming or Going      11. Side by Side";
    cout << endl << "5. Double Prices        12. Squeeze Play";
    cout << endl << "6. Flip Flop            13. Go back";
    cout << endl << "7. Freeze Frame";
    cout << endl << "Select a pricing game: ";
}

void displayMultMenu()
{
    cout << endl << "MULTI PRIZE GAMES" << endl;
    cout << endl << "1. Bargain Game     11. One Wrong Price";
    cout << endl << "2. Clock Game       12. Race Game";
    cout << endl << "3. Danger Price     13. Safe Crackers";
    cout << endl << "4. Do the Math      14. Shopping Spree";
    cout << endl << "5. Double Cross     15. Swap Meet";
    cout << endl << "6. Easy as 1-2-3    16. Switch?";
    cout << endl << "7. Magic #          17. Take Two";
    cout << endl << "8. Make Your Move   18. Two for the Price of One";
    cout << endl << "9. Most Expensive   19. Go back";
    cout << endl << "10. One Right Price";
    cout << endl << "Select a pricing game: ";
}

void displayCarsMenu()
{
    cout << endl << "CAR GAMES" << endl;
    cout << endl << "1. Card Game    8. One Away";
    cout << endl << "2. Cover Up     9. Pocket Change";
    cout << endl << "3. Dice Game    10. That's Too Much!";
    cout << endl << "4. Gas Money    11. Three Strikes";
    cout << endl << "5. Gridlock!    12. Triple Play";
    cout << endl << "6. Lucky $even  13. Go back";
    cout << endl << "7. Money Game";
    cout << endl << "Select a pricing game: ";
}

void displayCars2Menu()
{
    cout << endl << "CAR/OTHER PRIZES GAMES" << endl;
    cout << endl << "1. Any Number       10. Pathfinder";
    cout << endl << "2. Five Price Tags  11. Rat Race";
    cout << endl << "3. Golden Road      12. Spelling Bee";
    cout << endl << "4. Hole in One      13. Stack the Deck";
    cout << endl << "5. Let 'em Roll     14. Switcheroo";
    cout << endl << "6. Line 'em Up      15. Temptation";
    cout << endl << "7. Master Key       16. Ten Chances";
    cout << endl << "8. More or Less     17. Go back";
    cout << endl << "9. Pass the Buck";
    cout << endl << "Select a pricing game: ";
}

void displayCashMenu()
{
    cout << endl << "CASH GAMES" << endl;
    cout << endl << "1. Grand Game       6. Plinko";
    cout << endl << "2. 1/2 Off          7. Punch-a-Bunch";
    cout << endl << "3. Hot Seat         8. Time Is Money";
    cout << endl << "4. It's in the Bag  9. To the Penny";
    cout << endl << "5. Pay the Rent     10. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayRetiredMenu()
{
    cout << endl << "RETIRED GAMES (A-J)" << endl;
    cout << endl << "1. Add 'em Up           10. Finish Line";
    cout << endl << "2. Balance Game (1984)  11. Fortune Hunter";
    cout << endl << "3. Bullseye (1972)      12. Gallery Game";
    cout << endl << "4. Bump                 13. Give or Keep";
    cout << endl << "5. Buy or Sell          14. Hit Me";
    cout << endl << "6. Clearance Sale       15. Hurdles";
    cout << endl << "7. Credit Card          16. It's Optional";
    cout << endl << "8. Double Bullseye      17. Joker";
    cout << endl << "9. Double Digits        18. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayRetired2Menu()
{
    cout << endl << "RETIRED GAMES (M-W)" << endl;
    cout << endl << "1. Make Your Mark   10. Step Up";
    cout << endl << "2. Mystery Price    11. Super Ball!!";
    cout << endl << "3. On the Nose      12. $uper $aver";
    cout << endl << "4. On the Spot      13. Telephone Game";
    cout << endl << "5. Penny Ante       14. The Phone Home Game";
    cout << endl << "6. Poker Game       15. Trader Bob";
    cout << endl << "7. Professor Price  16. Walk of Fame";
    cout << endl << "8. Shower Game      17. Go back";
    cout << endl << "9. Split Decision";
    cout << endl << "Select a pricing game: ";
}

void displayCustomMenu()
{
    cout << endl << "CUSTOM GAMES" << endl;
    cout << endl << "1. Big Item Bash";
    cout << endl << "2. Domino Game";
    cout << endl << "3. Fill 'er Up";
    cout << endl << "4. Jam";
    cout << endl << "5. Master Price";
    cout << endl << "6. One For All";
    cout << endl << "7. One Way Or Another";
    cout << endl << "8. 7Up";
    cout << endl << "9. Go back";
    cout << endl << "Select a pricing game: ";
}

void randomGame(int r)
{
    if (r == 0)
        playBackTo72();
    else if (r == 1)
        playBalanceGame();
    else if (r == 2)
        playBargainGame();
    else if (r == 3)
        playBonusGame();
    else if (r == 4)
        playBullseye72();
    else if (r == 5)
        playBullseye();
    else if (r == 6)
        playBump();
    else if (r == 7)
        playBuyOrSell();
    else if (r == 8)
        playCardGame();
    else if (r == 9)
        playCheckGame();
    else if (r == 10)
        playCheckOut();
    else if (r == 11)
        playCliffHangers();
    else if (r == 12)
        playClockGame();
    else if (r == 13)
        playComingOrGoing();
    else if (r == 14)
        playDangerPrice();
    else if (r == 15)
        playDiceGame();
    else if (r == 16)
        playDoTheMath();
    else if (r == 17)
        playDoublePrices();
    else if (r == 18)
        playEasyAs123();
    else if (r == 19)
        playFinishLine();
    else if (r == 20)
        playFivePriceTags();
    else if (r == 21)
        playFlipFlop();
    else if (r == 22)
        playFreezeFrame();
    else if (r == 23)
        playGasMoney();
    else if (r == 24)
        playGiveOrKeep();
    else if (r == 25)
        playGrandGame();
    else if (r == 26)
        playGridlock();
    else if (r == 27)
        playGroceryGame();
    else if (r == 28)
        playHiLo();
    else if (r == 29)
        playHitMe();
    else if (r == 30)
        playHurdles();
    else if (r == 31)
        playItsInTheBag();
    else if (r == 32)
        playLetEmRoll();
    else if (r == 33)
        playLuckySeven();
    else if (r == 34)
        playMagicNumber();
    else if (r == 35)
        playMakeYourMove();
    else if (r == 36)
        playMoneyGame();
    else if (r == 37)
        playMoreOrLess();
    else if (r == 38)
        playMostExpensive();
    else if (r == 39)
        playOneRightPrice();
    else if (r == 40)
        playOneWrongPrice();
    else if (r == 41)
        playPassTheBuck();
    else if (r == 42)
        playPickANumber();
    else if (r == 43)
        playPlinko();
    else if (r == 44)
        playPunchABunch();
    else if (r == 45)
        playPushOver();
    else if (r == 46)
        playRangeGame();
    else if (r == 47)
        playSafeCrackers();
    else if (r == 48)
        playSecretX();
    else if (r == 49)
        playShellGame();
    else if (r == 50)
        playShoppingSpree();
    else if (r == 51)
        playShowerGame();
    else if (r == 52)
        playSideBySide();
    else if (r == 53)
        playSqueezePlay();
    else if (r == 54)
        playStepUp();
    else if (r == 55)
        playSuperSaver();
    else if (r == 56)
        playSwitch();
    else if (r == 57)
        playTakeTwo();
    else if (r == 58)
        playTenChances();
    else if (r == 59)
        playThatsTooMuch();
    else if (r == 60)
        playWalkOfFame();
    else if (r == 61)
        playAnyNumber();
    else if (r == 62)
        playPickAPair();
    else if (r == 63)
        playSwapMeet();
    else if (r == 64)
        playHalfOff(false, false);
    else if (r == 65)
        playMasterKey();
    else if (r == 66)
        playOneAway(false);
    else if (r == 67)
        playSpellingBee();
    else if (r == 68)
        playHoleInOne();
    else if (r == 69)
        playNowOrThen();
    else if (r == 70)
        playTwoForOne();
    else if (r == 71)
        playPennyAnte();
    else if (r == 72)
        playMakeYourMark();
    else if (r == 73)
        playLineEmUp();
    else if (r == 74)
        playOnTheSpot();
    else if (r == 75)
        playThePhoneHomeGame();
    else if (r == 76)
        playHotSeat();
    else if (r == 77)
        playAddEmUp();
    else if (r == 78)
        playStackTheDeck();
    else if (r == 79)
        playThreeStrikes();
    else if (r == 80)
        playCreditCard();
    else if (r == 81)
        playPocketChange();
    else if (r == 82)
        playRaceGame();
    else if (r == 83)
        playDoubleCross();
    else if (r == 84)
        playCoverUp();
    else if (r == 85)
        playPayTheRent();
    else if (r == 86)
        playTraderBob();
    else if (r == 87)
        playFortuneHunter();
    else if (r == 88)
        playOnTheNose();
    else if (r == 89)
        playSplitDecision();
    else if (r == 90)
        playDoubleBullseye();
    else if (r == 91)
        playBalanceGame84();
    else if (r == 92)
        playJoker();
    else if (r == 93)
        playPathfinder();
    else if (r == 94)
        playClearanceSale();
    else if (r == 95)
        playGoldenRoad();
    else if (r == 96)
        playTriplePlay();
    else if (r == 97)
        playBonkers();
    else if (r == 98)
        playSwitcheroo(false);
    else if (r == 99)
        playRatRace();
    else if (r == 100)
        playSuperBall();
    else if (r == 101)
        playTemptation();
    else if (r == 102)
        playTimeIsMoney();
    else if (r == 103)
        playProfessorPrice();
    else if (r == 104)
        playTelephoneGame();
    else if (r == 105)
        playPokerGame();
    else if (r == 106)
        playToThePenny();
    else if (r == 107)
        playDoubleDigits();
    else if (r == 108)
        playGalleryGame();
    else if (r == 109)
        playMysteryPrice();
    else if (r == 110)
        playItsOptional();
    else if (r == 111)
        playOneWayOrAnother();
    else if (r == 112)
        playBigItemBash();
    else if (r == 113)
        playMasterPrice();
    else if (r == 114)
        playSevenUp();
    else if (r == 115)
        playDominoGame();
    else if (r == 116)
        playOneForAll();
    else if (r == 117)
        playJam();
    else if (r == 118)
        playFillErUp();
    else
        playVendOPrice();
}
