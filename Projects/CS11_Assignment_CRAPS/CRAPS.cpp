/****************************************************************************************
*                                                                                       *
*	Title:   CS11 CRAPS assignment                                                      *
*	Author:  Felipe                                                                     *
*	Date:    04/07/2025                                                                 *
*	Purpose: The program is function as a craps game                                    *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::microseconds;

void ShowIntroScreen(void);
void ShowInformation(unsigned long Money);
short GetBet(void);
short DoDiceThrow(void);
unsigned short DoMoneyCalc(short DiceValue, short Bet, short BetMoney);
unsigned long GetAmount(void);

int main(void) {

    unsigned long MoneyEarned;
    unsigned long Money;

    short DiceValue;
    short Bet;
    short BetMoney;
    
    ShowIntroScreen();
    Money = 1000;

    do {
       
        char isRepeat = 'y';

        while (isRepeat == 'y' || isRepeat == 'Y') {

            while (Money >= 100) {
                ShowInformation(Money);

                Bet = GetBet();

                if (Bet == 0) {
                    Bet = GetBet();
                }
                else {
                    BetMoney = GetAmount();
                    DiceValue = DoDiceThrow();
                    MoneyEarned = DoMoneyCalc(DiceValue, Bet, BetMoney);

                    Money -= BetMoney;

                    if (MoneyEarned == 0) {

                        cout << "You lost. Number was: " << DiceValue;
                        cout << endl << endl;
                    }
                    else {
                        cout << "You won " << MoneyEarned - BetMoney;
                        cout << " dollars. Number was: " << DiceValue;
                        cout << endl << endl;

                        Money += MoneyEarned;
                    }
                }
            }
        }
        cout << "Game Over. Keep $" << Money << " for the ride home";
        cout << endl;
        cout << "\nWould you like to play again? (y/n): ";  // Ask if program wants to be runned again
        cin >> isRepeat;
        if (isRepeat != 'y' && isRepeat != 'Y') {
            cout << "\nThanks for watching!";  // Output thank you message
            cout << "\n\n####################################################\n\n";
            system("pause");  // Pause until user presses any key
        }
        else {
            cout << "\n####################################################\n";  // Display a barrier for new line
        }
    } 

    return 0;
}

void ShowIntroScreen(void) {

    cout << endl;
    cout << "############################" << endl;
    cout << "#                          #" << endl;
    cout << "#   WELCOME TO CRAPS 1.0!  #" << endl;
    cout << "#                          #" << endl;
    cout << "############################" << endl << endl;
    cout << "Here are the rules:";
    cout << endl << endl;

    cout << "You have 1000 dollars to start gambling.";
    cout << endl;
    cout << "You can do three different bets. You can bet on ";
    cout << "numbers 2 and 12 which will give you a win ratio of 5 to 1 if you win. " << endl;
    cout << "You can also bet on the numbers 4 and 10 which will give you a win ratio of 2.5 to 1. " << endl;
    cout << "The last kind of bet you can do is on the numbers 6 and 8 which will give you a win ratio of 1.5 to 1. ";
    cout << endl << endl;

    cout << "The minimum amount to bet is 10 dollars and the maximum 100 dollars.";
    cout << endl << endl;

    cout << "Have fun playing.";
    cout << endl << endl;
}

void ShowInformation(unsigned long Money) {
    cout << "You have : " << Money << " dollars.";
    cout << endl;
}

short GetBet(void) {
    unsigned short BetType;
    cout << "Enter type of bet (1 = '2/12' 2 = '4/10' 3 = '6/8' 4 = '3/9'): ";
    cin >> BetType;

    if ((BetType == 1) || (BetType == 2) || (BetType == 3) || (BetType == 4)) {
        return BetType;
    }
    else {
        cout << "Please enter a valid number.\n";
        return 0;
    }
}

short DoDiceThrow(void) {

    short DiceValue;
    short DiceValue1;
    short DiceValue2;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int randomNumber1 = rand();
    DiceValue1 = (randomNumber1 % 6) + 1;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int randomNumber2 = rand();
    DiceValue2 = (randomNumber2 % 6) + 1;

    DiceValue = (DiceValue1 + DiceValue2);

    return DiceValue;
}

unsigned short DoMoneyCalc(short DiceValue, short Bet, short BetMoney) {

    unsigned long MoneyEarned = 0;

    switch (Bet) {

    case 1:
        if ((DiceValue == 2) || (DiceValue == 12)) {
            MoneyEarned = BetMoney * 5;
        }
        break;

    case 2:
        if ((DiceValue == 4) || (DiceValue == 10)) {
            MoneyEarned = BetMoney * 2.5;
        }
        break;

    case 3:
        if ((DiceValue == 6) || (DiceValue == 8)) {
            MoneyEarned = BetMoney * 1.5;
        }
        break;

    case 4:
        if ((DiceValue == 3) || (DiceValue == 9)) {
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