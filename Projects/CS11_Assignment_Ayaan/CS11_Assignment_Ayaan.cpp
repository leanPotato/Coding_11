/****************************************************************************************
 *                                                                                      *
 *	Title:   Craps Project 6                                                            *
 *	Author:  Ayaan                                                                      *
 *	Date:    03/03/2025                                                                 *
 *	Purpose: The program is trying to operate a fully functioning craps game            *
 *                                                                                      *
 ****************************************************************************************/

#include <iostream>                              //Libraries
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::microseconds;

using namespace std;

void ShowIntroScreen(void);                                             //Functions
void ShowInformation(unsigned long Money);
char GetBet(void);
short DoDiceThrow(void);
unsigned short DoMoneyCalc(short Dice, short Bet, short BetMoney);
unsigned long GetAmount(void);

int main(void) {                                           // Main function

    unsigned long MoneyEarned;
    unsigned long Money;

    short DiceValue;
    short Bet;
    short BetMoney;

    /* Show intro and setup game */
    ShowIntroScreen();
    Money = 1000;

    /* Play while player has money
       Keep 100 dollars for the cab home */

    do {

        ShowInformation(Money);

        // Get bet info */
        Bet = GetBet();
        BetMoney = GetAmount();
        DiceValue = DoDiceThrow();
        MoneyEarned = DoMoneyCalc(DiceValue, Bet, BetMoney);

        Money -= BetMoney;

        /* Show the number */
        if (MoneyEarned == 0) {

            cout << "You lost. Number was: " << DiceValue << endl;
        }

        else {

            cout << "You won " << MoneyEarned - BetMoney << " dollars. Number was: " << DiceValue << endl;

            Money += MoneyEarned;
        }
    }

    while (Money > 100);
    cout << "\n########################################################################";
    cout << "\n*  Looks like you haven't had much luck. Keep $" << Money << " for the ride home.     *";
    cout << "\n*  Don't tell the cops and we won't tell your partner...               *\n";
    cout << "########################################################################";
    return 0;
}

void ShowIntroScreen(void) {

    cout << "\n##########################################################";
    cout << "\n*             Welcome to Underground Craps               *" << endl;
    cout << "*                 Here are the rules:                    *\n";
    cout << "*                                                        *";
    cout << "\n*        You have 1000 dollars to start gambling.        *" << endl;
    cout << "*           You can do three different bets.             *" << endl;
    cout << "*    You can bet on numbers 2 and 12 which will give     *" << endl;
    cout << "*               you a win ratio of 5 to 1.               *" << endl;
    cout << "*      You can also bet on the numbers 4 and 10          *" << endl;
    cout << "*    which will give you a win ratio of 2.5 to 1.        *" << endl;
    cout << "*   The last kind of bet you can do is on the numbers    *" << endl;
    cout << "*  6 and 8 which will give you a win ratio of 1.5 to 1.  *" << endl;
    cout << "*     The minimum amount to bet is 10 dollars and the    *" << endl;
    cout << "*                maximum is 100 dollars.                 *" << endl;
    cout << "##########################################################" << endl << endl;

    cout << "                    Have fun playing!" << endl << endl;
}

void ShowInformation(unsigned long Money) {

    cout << "\nYou have: " << Money << " dollars." << endl;
}

char GetBet(void) {
    unsigned char BetType;
    cout << "Enter type of bet (1 = '2/12' 2 = '4/10' 3 = '6/8' 4 = '3/9'): ";
    cin >> BetType;

    if ((BetType == 1) || (BetType == 2) || (BetType == 3) || (BetType == 4)) {
        return BetType;
    }
    else {
        cout << "That is an invalid input. Please insert a valid input:";
        cout << "Enter type of bet (1 = '2/12' 2 = '4/10' 3 = '6/8' 4 = '3/9'): ";
        cin >> BetType;

        return BetType;
    }
}

short DoDiceThrow(void) {

    short DiceValue;
    short DV1;
    short DV2;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int numberRand1 = rand();
    DV1 = (numberRand1 % 6) + 1;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int numberRand2 = rand();
    DV2 = (numberRand2 % 6) + 1;

    DiceValue = (DV1 + DV2);

    return DiceValue;
}


unsigned short DoMoneyCalc(short Dice, short Bet, short BetMoney) {

    unsigned long MoneyEarned = 0;

    switch (Bet) {

    case 1:
        if ((Dice == 2) || (Dice == 12)) {
            MoneyEarned = BetMoney * 5;
        }
        break;

    case 2:
        if ((Dice == 4) || (Dice == 10)) {
            MoneyEarned = BetMoney * 2.5;
        }
        break;

    case 3:
        if ((Dice == 6) || (Dice == 8)) {
            MoneyEarned = BetMoney * 1.5;
        }
        break;

    case 4:
        if ((Dice == 3) || (Dice == 9)) {
            MoneyEarned = BetMoney * 1.7;
        }
        break;

    default:
        MoneyEarned = 0;
        break;
    }

    return MoneyEarned;
}

unsigned long GetAmount(void) {

    unsigned int BetAmount;

    cout << "Enter amount to bet (min 10 - max 100): ";
    cin >> BetAmount;

    if (BetAmount < 10) {
        BetAmount = 10;
    }
    if (BetAmount > 100) {
        BetAmount = 100;
    }

    return BetAmount;
}