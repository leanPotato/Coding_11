/****************************************************************************************
 *                                                                                       *
 *	Title:   Craps Project 6                                                            *
 *	Author:  Ayaan                                                                      *
 *	Date:    03/03/2025                                                                 *
 *	Purpose: The program is trying to operate a fully functioning craps game            *
 *                                                                                       *
 *****************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void ShowIntroScreen(void);
void ShowInformation(unsigned long Money);
short GetBet(void);
short DoDiceThrow(void);
unsigned short DoMoneyCalc(short Dice, short Bet, short BetMoney);
unsigned long GetAmount(void);

int main(void) {

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
    cout << "Game Over. Keep $" << Money << " for the ride home." << endl;

    return 0;
}

void ShowIntroScreen(void) {

    cout << "     Welcome to Craps 1.0" << endl;
    cout << "Here are the rules:" << endl;


    cout << "You have 1000 dollars to start gambling. " << endl;


    cout << "You can do three different bets. You can bet on ";
    cout << "numbers 2 and 12 which will give";
    cout << " you a win ratio of ";
    cout << "5 to 1. You can also bet on the numbers 4 ";
    cout << "and 10";
    cout << "which will give you a win ratio of 2.5 to 1." << endl;
    cout << "The last kind of bet you can do is on the numbers 6 ";
    cout << "and 8 which will give you a wion ration of 1.5 to 1" << endl;

    cout << "The minimum amount to bet is 10 dollars and the ";
    cout << "maximum is 100 dollars." << endl;

    cout << "Have fun playing!" << endl;
}

void ShowInformation(unsigned long Money) {

    cout << "You have: " << Money << " dollars." << endl;
}

short GetBet(void) {
    unsigned short BetType;
    cout << "Enter type of bet (1 = '2/12' 2 = '4/10' 3 = '6/8' 4 = '3/9'): ";
    cin >> BetType;

    if ((BetType == 1) || (BetType == 2) || (BetType == 3) || (BetType == 4)) {
        return BetType;
    }
     else if ((BetType != 1) && (BetType != 2) && (BetType != 3) && (BetType != 4)) {
        cout << "That is an invalid input. Please insert a valid input." << endl;
        cin >> BetType;
    }

    else {
        return 0;
    }
}

short DoDiceThrow(void) {

    short DiceValue;

    srand(time(NULL));
    DiceValue = (rand() % 12) + 1;

    if ((DiceValue == 4) || (DiceValue == 10)) {
        srand(time(NULL));
        DiceValue = (rand() % 12) + 1;
    }

    if ((DiceValue == 2) || (DiceValue == 12)) {
        srand(time(NULL));
        DiceValue = (rand() % 12) + 1;
    }

    if ((DiceValue == 6) || (DiceValue == 8)) {
        srand(time(NULL));
        DiceValue = (rand() % 12) + 1;
    }

    if ((DiceValue == 3) || (DiceValue == 9)) {
        srand(time(NULL));
        DiceValue = (rand() % 12) + 1;
    }


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

    unsigned short BetAmount;

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
