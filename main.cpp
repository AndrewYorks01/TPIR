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
void displayFeeMenu();
void displaySingMenu();
void displayMultMenu();
void displayCarsMenu();
void displayCars2Menu();
void displayCashMenu();
void displayCustomMenu();
void displayGamesACMenu();
void displayGamesDGMenu();
void displayGamesHMMenu();
void displayGamesNPMenu();
void displayGamesRSMenu();
void displayGamesTWMenu();

/// play a random game
void randomGame(int r);

int main()
{
    //playTowerOfCash();

    int cat; /// Category selection
    int gro; /// Grocery game selection
    int sma; /// Small prize game selection
    int fee; /// Fee game selection
    int sng; /// Single-prize game selection
    int mul; /// Multi-prize game selection
    int cgs; /// Car game selection
    int cms; /// Car games with other items selection
    int csh; /// Cash game selection
    int cus; /// Custom games selection

    int all; /// Choose when selecting from all games
    int g_ac; /// Games A-C selection
    int g_dg; /// Games D-G selection
    int g_hm; /// Games H-M selection
    int g_np; /// Games N-P selection
    int g_rs; /// Games R-S selection
    int g_tw; /// Games T-W selection

    bool mdsMode;

    cout << "THE PRICE IS RIGHT" << endl;
    srand(time(0));

    do{
    int rgame = rand() % 126;
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

    case 1: /// Fee games
        fee = 0;
        do{
            displayFeeMenu();
            cin >> fee;
        switch (fee)
        {
        case 1:
            system("CLS");
            playBackTo72();
            break;

        case 2:
            system("CLS");
            playBalanceGame84();
            break;

        case 3:
            system("CLS");
            playBonusGame();
            break;

        case 4:
            system("CLS");
            playBullseye();
            break;

        case 5:
            system("CLS");
            playCheckOut();
            break;

        case 6:
            system("CLS");
            playCliffHangers();
            break;

        case 7:
            system("CLS");
            playFinishLine();
            break;

        case 8:
            system("CLS");
            playGiveOrKeep();
            break;

        case 9:
            system("CLS");
            playGroceryGame();
            break;

        case 10:
            system("CLS");
            playHiLo();
            break;

        case 11:
            system("CLS");
            playHitMe();
            break;

        case 12:
            system("CLS");
            playHurdles();
            break;

        case 13:
            system("CLS");
            playJoker();
            break;

        case 14:
            system("CLS");
            playMysteryPrice();
            break;

        case 15:
            system("CLS");
            playNowOrThen();
            break;

        case 16:
            system("CLS");
            playPennyAnte();
            break;

        case 17:
            system("CLS");
            playPickAPair();
            break;

        case 18:
            system("CLS");
            playSecretX();
            break;

        case 19:
            system("CLS");
            playShellGame();
            break;

        case 20:
            system("CLS");
            playSuperSaver();
            break;

        case 21:
            system("CLS");
            playTraderBob();
            break;

        case 22:
            system("CLS");
            playVendOPrice();
            break;

        case 23:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 23.";

        } // end switch statement for fee games
        } // end fee do-while
        while (fee != 23);

        break;

    case 2: /// Single-prize games
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
            playGalleryGame();
            break;

        case 9:
            system("CLS");
            playPickANumber();
            break;

        case 10:
            system("CLS");
            playPushOver();
            break;

        case 11:
            system("CLS");
            playRangeGame();
            break;

        case 12:
            system("CLS");
            playSideBySide();
            break;

        case 13:
            system("CLS");
            playSqueezePlay();
            break;

        case 14:
            system("CLS");
            break;

        default:
           cout << endl << "Please enter a number between 1 and 14.";

        } // end switch statement for single-prize games

        } // end do-while loop
        while (sng != 14);
        break;

    case 3: /// Multi-prize games
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
            playBump();
            break;

        case 3:
            system("CLS");
            playBuyOrSell();
            break;

        case 4:
            system("CLS");
            playClearanceSale();
            break;

        case 5:
            system("CLS");
            playClockGame();
            break;

        case 6:
            system("CLS");
            playCreditCard();
            break;

        case 7:
            system("CLS");
            playDangerPrice();
            break;

        case 8:
            system("CLS");
            playDoTheMath();
            break;

        case 9:
            system("CLS");
            playDoubleCross();
            break;

        case 10:
            system("CLS");
            playEasyAs123();
            break;

        case 11:
            system("CLS");
            playMagicNumber();
            break;

        case 12:
            system("CLS");
            playMakeYourMark();
            break;

        case 13:
            system("CLS");
            playMakeYourMove();
            break;

        case 14:
            system("CLS");
            playMostExpensive();
            break;

        case 15:
            system("CLS");
            playOneRightPrice();
            break;

        case 16:
            system("CLS");
            playOneWrongPrice();
            break;

        case 17:
            system("CLS");
            playPokerGame();
            break;

        case 18:
            system("CLS");
            playRaceGame();
            break;

        case 19:
            system("CLS");
            playSafeCrackers();
            break;

        case 20:
            system("CLS");
            playShoppingSpree();
            break;

        case 21:
            system("CLS");
            playStepUp();
            break;

        case 22:
            system("CLS");
            playSuperBall();
            break;

        case 23:
            system("CLS");
            playSwapMeet();
            break;

        case 24:
            system("CLS");
            playSwitch();
            break;

        case 25:
            system("CLS");
            playTakeTwo();
            break;

        case 26:
            system("CLS");
            playTwoForOne();
            break;

        case 27:
            system("CLS");
            playWalkOfFame();
            break;

        case 28:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 28.";

        } // end switch statement for multi-prize games
        } // end do-while loop
        while (mul != 28);
        break;

    case 4: /// Car games
        cgs = 0;
        do{
        displayCarsMenu();
        cin >> cgs;
        switch (cgs)
        {

        case 1:
            system("CLS");
            playAddEmUp();
            break;

        case 2:
            system("CLS");
            playBullseye72();
            break;

        case 3:
            system("CLS");
            playCardGame();
            break;

        case 4:
            system("CLS");
            playCoverUp();
            break;

        case 5:
            system("CLS");
            playDiceGame();
            break;

        case 6:
            system("CLS");
            playDoubleBullseye();
            break;

        case 7:
            system("CLS");
            playGasMoney();
            break;

        case 8:
            system("CLS");
            playGridlock();
            break;

        case 9:
            system("CLS");
            playItsOptional();
            break;

        case 10:
            system("CLS");
            playLuckySeven();
            break;

        case 11:
            system("CLS");
            playMoneyGame();
            break;

        case 12:
            system("CLS");
            playOnTheNose();
            break;

        case 13:
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

        case 14:
            system("CLS");
            playPocketChange();
            break;

        case 15:
            system("CLS");
            playProfessorPrice();
            break;

        case 16:
            system("CLS");
            playShowerGame();
            break;

        case 17:
            system("CLS");
            playThatsTooMuch();
            break;

        case 18:
            system("CLS");
            playThreeStrikes();
            break;

        case 19:
            system("CLS");
            playTriplePlay();
            break;

        case 20:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 20.";

        } // end switch statement for car games
        }
        while (cgs != 20);
        break;

    case 5: /// Car/other prizes games
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
            playDoubleDigits();
            break;

        case 3:
            system("CLS");
            playFivePriceTags();
            break;

        case 4:
            system("CLS");
            playGoldenRoad();
            break;

        case 5:
            system("CLS");
            playHoleInOne();
            break;

        case 6:
            system("CLS");
            playLetEmRoll();
            break;

        case 7:
            system("CLS");
            playLineEmUp();
            break;

        case 8:
            system("CLS");
            playMasterKey();
            break;

        case 9:
            system("CLS");
            playMoreOrLess();
            break;

        case 10:
            system("CLS");
            playOnTheSpot();
            break;

        case 11:
            system("CLS");
            playPassTheBuck();
            break;

        case 12:
            system("CLS");
            playPathfinder();
            break;

        case 13:
            system("CLS");
            playRatRace();
            break;

        case 14:
            system("CLS");
            playSpellingBee();
            break;

        case 15:
            system("CLS");
            playSplitDecision();
            break;

        case 16:
            system("CLS");
            playStackTheDeck();
            break;

        case 17:
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

        case 18:
            system("CLS");
            playTelephoneGame();
            break;

        case 19:
            system("CLS");
            playTemptation();
            break;

        case 20:
            system("CLS");
            playTenChances();
            break;

        case 21:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 21.";
        } // end switch statement for car/prize games
        }
        while (cms != 21);
        break;

    case 6: /// Cash games
        csh = 0;
        do{
        displayCashMenu();
        cin >> csh;
        switch (csh)
        {

        case 1:
            system("CLS");
            playFortuneHunter();
            break;

        case 2:
            system("CLS");
            playGrandGame();
            break;

        case 3:
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

        case 4:
            system("CLS");
            playHotSeat();
            break;

        case 5:
            system("CLS");
            playItsInTheBag();
            break;

        case 6:
            system("CLS");
            playPayTheRent();
            break;

        case 7:
            system("CLS");
            playPlinko();
            break;

        case 8:
            system("CLS");
            playPunchABunch();
            break;

        case 9:
            system("CLS");
            playTheLionsShare();
            break;

        case 10:
            system("CLS");
            playThePhoneHomeGame();
            break;

        case 11:
            system("CLS");
            playTimeIsMoney();
            break;

        case 12:
            system("CLS");
            playToThePenny();
            break;

        case 13:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 13.";

        } // end switch statement for cash games
        }
        while (csh != 13);
        break;

    case 7:
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
            playEthsPastas();
            break;

        case 4:
            system("CLS");
            playFillErUp();
            break;

        case 5:
            system("CLS");
            playJam();
            break;

        case 6:
            system("CLS");
            playMasterPrice();
            break;

        case 7:
            system("CLS");
            playOneForAll();
            break;

        case 8:
            system("CLS");
            playOneWayOrAnother();
            break;

        case 9:
            system("CLS");
            playPriceSearch();
            break;

        case 10:
            system("CLS");
            playSevenUp();
            break;

        case 11:
            system("CLS");
            playShotInTheDark();
            break;

        case 12:
            system("CLS");
            playStartingPoints();
            break;

        case 13:
            system("CLS");
            playTowerOfCash();
            break;

        case 14:
            system("CLS");
            break;

        default:
            cout << endl << "Please enter a number between 1 and 14.";

        } // end switch for custom games
        }
        while (cus != 14);
        break;

    case 8:
        all = 0;
        do{
        cout << endl << "ALL GAMES";
        cout << endl << "1. Games A-C";
        cout << endl << "2. Games D-G";
        cout << endl << "3. Games H-M";
        cout << endl << "4. Games N-P";
        cout << endl << "5. Games R-S";
        cout << endl << "6. Games T-W";
        cout << endl << "7. Go back";
        cout << endl << "Select a range: ";
        cin >> all;
        switch (all){

        /// Games A-C
        case 1:
            g_ac = 0;
            do{
            displayGamesACMenu();
            cin >> g_ac;
            switch (g_ac){
            case 1:
                system("CLS");
                playAddEmUp();
                break;

            case 2:
                system("CLS");
                playAnyNumber();
                break;

            case 3:
                system("CLS");
                playBackTo72();
                break;

            case 4:
                system("CLS");
                playBalanceGame84();
                break;

            case 5:
                system("CLS");
                playBalanceGame();
                break;

            case 6:
                system("CLS");
                playBargainGame();
                break;

            case 7:
                system("CLS");
                playBigItemBash();
                break;

            case 8:
                system("CLS");
                playBonkers();
                break;

            case 9:
                system("CLS");
                playBonusGame();
                break;

            case 10:
                system("CLS");
                playBullseye72();
                break;

            case 11:
                system("CLS");
                playBullseye();
                break;

            case 12:
                system("CLS");
                playBump();
                break;

            case 13:
                system("CLS");
                playBuyOrSell();
                break;

            case 14:
                system("CLS");
                playCardGame();
                break;

            case 15:
                system("CLS");
                playCheckGame();
                break;

            case 16:
                system("CLS");
                playCheckOut();
                break;

            case 17:
                system("CLS");
                playClearanceSale();
                break;

            case 18:
                system("CLS");
                playCliffHangers();
                break;

            case 19:
                system("CLS");
                playClockGame();
                break;

            case 20:
                system("CLS");
                playComingOrGoing();
                break;

            case 21:
                system("CLS");
                playCoverUp();
                break;

            case 22:
                system("CLS");
                playCreditCard();
                break;

            case 23:
                system("CLS");
                break;

            case 24:
                all = 7;
                system("CLS");
                break;

            default:
                cout << endl << "Please enter a number between 1 and 24.";
            } // end switch
            } // end do
            while ((g_ac != 23) && (g_ac != 24));
            break;

        case 7:
            system("CLS");
            break;

        /// Games D-G
        case 2:
            g_dg = 0;
            do{
            displayGamesDGMenu();
            cin >> g_dg;
            switch (g_dg){

            case 1:
                system("CLS");
                playDangerPrice();
                break;

            case 2:
                system("CLS");
                playDiceGame();
                break;

            case 3:
                system("CLS");
                playDoTheMath();
                break;

            case 4:
                system("CLS");
                playDominoGame();
                break;

            case 5:
                system("CLS");
                playDoubleBullseye();
                break;

            case 6:
                system("CLS");
                playDoubleCross();
                break;

            case 7:
                system("CLS");
                playDoubleDigits();
                break;

            case 8:
                system("CLS");
                playDoublePrices();
                break;

            case 9:
                system("CLS");
                playEasyAs123();
                break;

            case 10:
                system("CLS");
                playEthsPastas();
                break;

            case 11:
                system("CLS");
                playFillErUp();
                break;

            case 12:
                system("CLS");
                playFinishLine();
                break;

            case 13:
                system("CLS");
                playFivePriceTags();
                break;

            case 14:
                system("CLS");
                playFlipFlop();
                break;

            case 15:
                system("CLS");
                playFortuneHunter();
                break;

            case 16:
                system("CLS");
                playFreezeFrame();
                break;

            case 17:
                system("CLS");
                playGalleryGame();
                break;

            case 18:
                system("CLS");
                playGasMoney();
                break;

            case 19:
                system("CLS");
                playGiveOrKeep();
                break;

            case 20:
                system("CLS");
                playGoldenRoad();
                break;

            case 21:
                system("CLS");
                playGrandGame();
                break;

            case 22:
                system("CLS");
                playGridlock();
                break;

            case 23:
                system("CLS");
                playGroceryGame();
                break;

            case 24:
                system("CLS");
                break;

            case 25:
                all = 7;
                system("CLS");
                break;

            default:
                cout << endl << "Please enter a number between 1 and 25.";
            } // end switch
            } // end do
            while ((g_dg != 24) && (g_dg != 25));

            break;

        case 3:
            g_hm = 0;
            do{
            displayGamesHMMenu();
            cin >> g_hm;
            switch (g_hm){

            case 1:
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

            case 2:
                system("CLS");
                playHiLo();
                break;

            case 3:
                system("CLS");
                playHitMe();
                break;

            case 4:
                system("CLS");
                playHoleInOne();
                break;

            case 5:
                system("CLS");
                playHotSeat();
                break;

            case 6:
                system("CLS");
                playHurdles();
                break;

            case 7:
                system("CLS");
                playItsInTheBag();
                break;

            case 8:
                system("CLS");
                playItsOptional();
                break;

            case 9:
                system("CLS");
                playJam();
                break;

            case 10:
                system("CLS");
                playJoker();
                break;

            case 11:
                system("CLS");
                playLetEmRoll();
                break;

            case 12:
                system("CLS");
                playLineEmUp();
                break;

            case 13:
                system("CLS");
                playLuckySeven();
                break;

            case 14:
                system("CLS");
                playMagicNumber();
                break;

            case 15:
                system("CLS");
                playMakeYourMark();
                break;

            case 16:
                system("CLS");
                playMakeYourMove();
                break;

            case 17:
                system("CLS");
                playMasterKey();
                break;

            case 18:
                system("CLS");
                playMasterPrice();
                break;

            case 19:
                system("CLS");
                playMoneyGame();
                break;

            case 20:
                system("CLS");
                playMoreOrLess();
                break;

            case 21:
                system("CLS");
                playMostExpensive();
                break;

            case 22:
                system("CLS");
                playMysteryPrice();
                break;

            case 23:
                system("CLS");
                break;

            case 24:
                all = 7;
                system("CLS");
                break;

            default:
                cout << endl << "Please enter a number between 1 and 24.";
            } // end switch
            } // end do
            while ((g_hm != 23) && (g_hm != 24));
             break;

        case 4:
            g_np = 0;
            do{
            displayGamesNPMenu();
            cin >> g_np;
            switch (g_np){

            case 1:
                system("CLS");
                playNowOrThen();
                break;

            case 2:
                system("CLS");
                playOnTheNose();
                break;

            case 3:
                system("CLS");
                playOnTheSpot();
                break;

            case 4:
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

            case 5:
                system("CLS");
                playOneForAll();
                break;

            case 6:
                system("CLS");
                playOneRightPrice();
                break;

            case 7:
                system("CLS");
                playOneWayOrAnother();
                break;

            case 8:
                system("CLS");
                playOneWrongPrice();
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
                playPayTheRent();
                break;

            case 12:
                system("CLS");
                playPennyAnte();
                break;

            case 13:
                system("CLS");
                playPickANumber();
                break;

            case 14:
                system("CLS");
                playPickAPair();
                break;

            case 15:
                system("CLS");
                playPlinko();
                break;

            case 16:
                system("CLS");
                playPocketChange();
                break;

            case 17:
                system("CLS");
                playPokerGame();
                break;

            case 18:
                system("CLS");
                playPriceSearch();
                break;

            case 19:
                system("CLS");
                playProfessorPrice();
                break;

            case 20:
                system("CLS");
                playPunchABunch();
                break;

            case 21:
                system("CLS");
                playPushOver();
                break;

            case 22:
                system("CLS");
                break;

            case 23:
                all = 7;
                system("CLS");
                break;

            default:
                cout << endl << "Please enter a number between 1 and 23.";
            } // end switch
            } // end do
            while ((g_np != 22) && (g_np != 23));

            break;

        case 5:
            g_rs = 0;
            do{
            displayGamesRSMenu();
            cin >> g_rs;
            switch (g_rs){

            case 1:
                system("CLS");
                playRaceGame();
                break;

            case 2:
                system("CLS");
                playRangeGame();
                break;

            case 3:
                system("CLS");
                playRatRace();
                break;

            case 4:
                system("CLS");
                playSafeCrackers();
                break;

            case 5:
                system("CLS");
                playSecretX();
                break;

            case 6:
                system("CLS");
                playSevenUp();
                break;

            case 7:
                system("CLS");
                playShellGame();
                break;

            case 8:
                system("CLS");
                playShoppingSpree();
                break;

            case 9:
                system("CLS");
                playShotInTheDark();
                break;

            case 10:
                system("CLS");
                playShowerGame();
                break;

            case 11:
                system("CLS");
                playSideBySide();
                break;

            case 12:
                system("CLS");
                playSpellingBee();
                break;

            case 13:
                system("CLS");
                playSplitDecision();
                break;

            case 14:
                system("CLS");
                playSqueezePlay();
                break;

            case 15:
                system("CLS");
                playStackTheDeck();
                break;

            case 16:
                system("CLS");
                playStartingPoints();
                break;

            case 17:
                system("CLS");
                playStepUp();
                break;

            case 18:
                system("CLS");
                playSuperBall();
                break;

            case 19:
                system("CLS");
                playSuperSaver();
                break;

            case 20:
                system("CLS");
                playSwapMeet();
                break;

            case 21:
                system("CLS");
                playSwitch();
                break;

            case 22:
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

            case 23:
                system("CLS");
                break;

            case 24:
                all = 7;
                system("CLS");
                break;

            default:
                cout << endl << "Please enter a number between 1 and 24.";
            } // end switch
            } // end do
            while ((g_rs != 23) && (g_rs != 24));
            break;

        case 6:
            g_tw = 0;
            do{
            displayGamesTWMenu();
            cin >> g_tw;
            switch (g_tw){
            case 1:
                system("CLS");
                playTakeTwo();
                break;

            case 2:
                system("CLS");
                playTelephoneGame();
                break;

            case 3:
                system("CLS");
                playTemptation();
                break;

            case 4:
                system("CLS");
                playTenChances();
                break;

            case 5:
                system("CLS");
                playThatsTooMuch();
                break;

            case 6:
                system("CLS");
                playTheLionsShare();
                break;

            case 7:
                system("CLS");
                playThePhoneHomeGame();
                break;

            case 8:
                system("CLS");
                playThreeStrikes();
                break;

            case 9:
                system("CLS");
                playTimeIsMoney();
                break;

            case 10:
                system("CLS");
                playToThePenny();
                break;

            case 11:
                system("CLS");
                playTowerOfCash();
                break;

            case 12:
                system("CLS");
                playTraderBob();
                break;

            case 13:
                system("CLS");
                playTriplePlay();
                break;

            case 14:
                system("CLS");
                playTwoForOne();
                break;

            case 15:
                system("CLS");
                playVendOPrice();
                break;

            case 16:
                system("CLS");
                playWalkOfFame();
                break;

            case 17:
                system("CLS");
                break;

            case 18:
                all = 7;
                system("CLS");
                break;
            } // end switch
            } // end do
            while ((g_tw != 17) && (g_tw != 18));
            break;

        default:
            cout << endl << "Please enter a number between 1 and 7.";
        } // end big switch
        } // end do
        while (all != 7);
        break;




    case 9: /// Play a user-generated line-up
    {
        vector<int> lineup;
        ifstream in;
        string setup;
        cout << endl << "Enter the .txt file containing your line-up: ";
        cin >> setup;
        setup = "./lineups/" + setup;
        cout << endl << setup;
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


    case 10: /// Quit
        ;
        break;

    default:
        cout << endl << "Please enter a number between 1 and 10.";

    } // end switch statement

    } // end do-while loop
    while (cat != 10);

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
    cout << endl << "1. Fee games";
    cout << endl << "2. Single-prize games";
    cout << endl << "3. Multi-prize games";
    cout << endl << "4. Car games";
    cout << endl << "5. Car + other item games";
    cout << endl << "6. Cash games";
    cout << endl << "7. Custom games";
    cout << endl << "8. All games";
    cout << endl << "9. Play a line-up you've created";
    cout << endl << "10. Quit";
    cout << endl << "Select a game classification: ";
}

void displayFeeMenu()
{
    cout << endl << "FEE GAMES" << endl;
    cout << endl << "1. Back to '72          13. Joker";
    cout << endl << "2. Balance Game (1984)  14. Mystery Price";
    cout << endl << "3. Bonus Game           15. Now... or Then";
    cout << endl << "4. Bullseye (1976)      16. Penny Ante";
    cout << endl << "5. Check-Out            17. Pick-a-Pair";
    cout << endl << "6. Cliff Hangers        18. Secret \"X\"";
    cout << endl << "7. Finish Line          19. Shell Game";
    cout << endl << "8. Give or Keep         20. $uper $aver";
    cout << endl << "9. Grocery Game         21. Trader Bob";
    cout << endl << "10. Hi-Lo               22. Vend-O-Price";
    cout << endl << "11. Hit Me              23. Go back";
    cout << endl << "12. Hurdles";
    cout << endl << "Select a pricing game: ";
}

void displaySingMenu()
{
    cout << endl << "SINGLE PRIZE GAMES" << endl;
    cout << endl << "1. Balance Game (2006)  8. Gallery Game";
    cout << endl << "2. Bonkers              9. Pick-a-Number";
    cout << endl << "3. Check Game           10. Push-Over";
    cout << endl << "4. Coming or Going      11. Range Game";
    cout << endl << "5. Double Prices        12. Side by Side";
    cout << endl << "6. Flip Flop            13. Squeeze Play";
    cout << endl << "7. Freeze Frame         14. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayMultMenu()
{
    cout << endl << "MULTI PRIZE GAMES" << endl;
    cout << endl << "1. Bargain Game     15. One Right Price";
    cout << endl << "2. Bump             16. One Wrong Price";
    cout << endl << "3. Buy or Sell      17. Poker Game";
    cout << endl << "4. Clearance Sale   18. Race Game";
    cout << endl << "5. Clock Game       19. Safe Crackers";
    cout << endl << "6. Credit Card      20. Shopping Spree";
    cout << endl << "7. Danger Price     21. Step Up";
    cout << endl << "8. Do the Math      22. Super Ball!!";
    cout << endl << "9. Double Cross     23. Swap Meet";
    cout << endl << "10. Easy as 1-2-3   24. Switch?";
    cout << endl << "11. Magic #         25. Take Two";
    cout << endl << "12. Make Your Mark  26. Two for the Price of One";
    cout << endl << "13. Make Your Move  27. Walk of Fame";
    cout << endl << "14. Most Expensive  28. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayCarsMenu()
{
    cout << endl << "CAR GAMES" << endl;
    cout << endl << "1. Add 'em Up       11. Money Game";
    cout << endl << "2. Bullseye (1972)  12. On the Nose";
    cout << endl << "3. Card Game        13. One Away";
    cout << endl << "4. Cover Up         14. Pocket Change";
    cout << endl << "5. Dice Game        15. Professor Price";
    cout << endl << "6. Double Bullseye  16. Shower Game";
    cout << endl << "7. Gas Money        17. That's Too Much!";
    cout << endl << "8. Gridlock!        18. Three Strikes";
    cout << endl << "9. It's Optional    19. Triple Play";
    cout << endl << "10. Lucky $even     20. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayCars2Menu()
{
    cout << endl << "CAR/OTHER PRIZES GAMES" << endl;
    cout << endl << "1. Any Number       12. Pathfinder";
    cout << endl << "2. Double Digits    13. Rat Race";
    cout << endl << "3. Five Price Tags  14. Spelling Bee";
    cout << endl << "4. Golden Road      15. Split Decision";
    cout << endl << "5. Hole in One      16. Stack the Deck";
    cout << endl << "6. Let 'em Roll     17. Switcheroo";
    cout << endl << "7. Line 'em Up      18. Telephone Game";
    cout << endl << "8. Master Key       19. Temptation";
    cout << endl << "9. More or Less     20. Ten Chances";
    cout << endl << "10. On the Spot     21. Go back";
    cout << endl << "11. Pass the Buck";
    cout << endl << "Select a pricing game: ";
}

void displayCashMenu()
{
    cout << endl << "CASH GAMES" << endl;
    cout << endl << "1. Fortune Hunter   8. Punch-a-Bunch";
    cout << endl << "2. Grand Game       9. The Lion's Share";
    cout << endl << "3. 1/2 Off          10. The Phone Home Game";
    cout << endl << "4. Hot Seat         11. Time Is Money";
    cout << endl << "5. It's in the Bag  12. To the Penny";
    cout << endl << "6. Pay the Rent     13. Go back";
    cout << endl << "7. Plinko";
    cout << endl << "Select a pricing game: ";
}

void displayCustomMenu()
{
    cout << endl << "CUSTOM GAMES" << endl;
    cout << endl << "1. Big Item Bash   8. One Way Or Another";
    cout << endl << "2. Domino Game     9. Price Search";
    cout << endl << "3. Eth's Pastas    10. 7UP";
    cout << endl << "4. Fill 'er Up     11. Shot in the Dark";
    cout << endl << "5. Jam             12. Starting Points";
    cout << endl << "6. Master Price    13. Tower of Cash";
    cout << endl << "7. One For All     14. Go back";
    cout << endl << "Select a pricing game: ";
}

void displayGamesACMenu()
{
    cout << endl << "GAMES A-C";
    cout << endl << "1. Add 'em Up           13. Buy or Sell";
    cout << endl << "2. Any Number           14. Card Game";
    cout << endl << "3. Back to '72          15. Check Game";
    cout << endl << "4. Balance Game (1984)  16. Check-Out";
    cout << endl << "5. Balance Game (2006)  17. Clearance Sale";
    cout << endl << "6. Bargain Game         18. Cliff Hangers";
    cout << endl << "7. Big Item Bash        19. Clock Game";
    cout << endl << "8. Bonkers              20. Coming or Going";
    cout << endl << "9. Bonus Game           21. Cover Up";
    cout << endl << "10. Bullseye (1972)     22. Credit Card";
    cout << endl << "11. Bullseye (1976)     23. Return to all games menu";
    cout << endl << "12. Bump                24. Return to main menu";
    cout << endl << "Select a pricing game: ";
}

void displayGamesDGMenu()
{
    cout << endl << "GAMES D-G";
    cout << endl << "1. Danger Price     14. Flip Flop";
    cout << endl << "2. Dice Game        15. Fortune Hunter";
    cout << endl << "3. Do the Math      16. Freeze Frame";
    cout << endl << "4. Domino Game      17. Gallery Game";
    cout << endl << "5. Double Bullseye  18. Gas Money";
    cout << endl << "6. Double Cross     19. Give or Keep";
    cout << endl << "7. Double Digits    20. Golden Road";
    cout << endl << "8. Double Prices    21. Grand Game";
    cout << endl << "9. Easy as 1-2-3    22. Gridlock!";
    cout << endl << "10. Eth's Pastas    23. Grocery Game";
    cout << endl << "11. Fill 'er Up     24. Return to all games menu";
    cout << endl << "12. Finish Line     25. Return to main menu";
    cout << endl << "13. Five Price Tags";
    cout << endl << "Select a pricing game: ";
}

void displayGamesHMMenu()
{
    cout << endl << "GAMES H-M";
    cout << endl << "1. 1/2 Off           13. Lucky $even";
    cout << endl << "2. Hi-Lo             14. Magic #";
    cout << endl << "3. Hit Me            15. Make Your Mark";
    cout << endl << "4. Hole in One       16. Make Your Move";
    cout << endl << "5. Hot Seat          17. Master Key";
    cout << endl << "6. Hurdles           18. Master Price";
    cout << endl << "7. It's in the Bag   19. Money Game";
    cout << endl << "8. It's Optional     20. More or Less";
    cout << endl << "9. Jam               21. Most Expensive";
    cout << endl << "10. Joker            22. Mystery Price";
    cout << endl << "11. Let 'em Roll     23. Return to all games menu";
    cout << endl << "12. Line 'em Up      24. Return to main menu";
    cout << endl << "Select a pricing game: ";
}

void displayGamesNPMenu()
{
    cout << endl << "GAMES N-P";
    cout << endl << "1. Now... or Then      13. Pick-a-Number";
    cout << endl << "2. On the Nose         14. Pick-a-Pair";
    cout << endl << "3. On the Spot         15. Plinko";
    cout << endl << "4. One Away            16. Pocket Change";
    cout << endl << "5. One For All         17. Poker Game";
    cout << endl << "6. One Right Price     18. Price Search";
    cout << endl << "7. One Way or Another  19. Professor Price";
    cout << endl << "8. One Wrong Price     20. Punch-a-Bunch";
    cout << endl << "9. Pass the Buck       21. Push-Over";
    cout << endl << "10. Pathfinder         22. Return to all games";
    cout << endl << "11. Pay the Rent       23. Return to main menu";
    cout << endl << "12. Penny Ante";
    cout << endl << "Select a pricing game: ";
}

void displayGamesRSMenu()
{
    cout << endl << "GAMES R-S";
    cout << endl << "1. Race Game         13. Split Decision";
    cout << endl << "2. Range Game        14. Squeeze Play";
    cout << endl << "3. Rat Race          15. Stack the Deck";
    cout << endl << "4. Safe Crackers     16. Starting Points";
    cout << endl << "5. Secret \"X\"        17. Step Up";
    cout << endl << "6. 7UP               18. Super Ball!!";
    cout << endl << "7. Shell Game        19. $uper $aver";
    cout << endl << "8. Shopping Spree    20. Swap Meet";
    cout << endl << "9. Shot in the Dark  21. Switch?";
    cout << endl << "10. Shower Game      22. Switcheroo";
    cout << endl << "11. Side by Side     23. Return to all games";
    cout << endl << "12. Spelling Bee     24. Return to main menu";
    cout << endl << "Select a pricing game: ";
}

void displayGamesTWMenu()
{
    cout << endl << "GAMES T-W";
    cout << endl << "1. Take Two              10. To the Penny";
    cout << endl << "2. Telephone Game        11. Tower of Cash";
    cout << endl << "3. Temptation            12. Trader Bob";
    cout << endl << "4. Ten Chances           13. Triple Play";
    cout << endl << "5. That's Too Much!      14. Two for the Price of One";
    cout << endl << "6. The Lion's Share      15. Vend-O-Price";
    cout << endl << "7. The Phone Home Game   16. Walk of Fame";
    cout << endl << "8. Three Strikes         17. Return to all games menu";
    cout << endl << "9. Time is Money         18. Return to main menu";
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
    else if (r == 119)
        playTheLionsShare();
    else if (r == 120)
        playPriceSearch();
    else if (r == 121)
        playEthsPastas();
    else if (r == 122)
        playShotInTheDark();
    else if (r == 123)
        playStartingPoints();
    else if (r == 124)
        playTowerOfCash();
    else
        playVendOPrice();
}
