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
#include <chrono>
#include <string>

using namespace std;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::microseconds;

void ShowIntroScreen(void);
void ShowInformation(unsigned long Money);
int GetBet(void);
short DoDiceThrow(void);
unsigned short DoMoneyCalc(short DiceValue, int Bet, int BetMoney);
int GetAmount(void);

int main(void) {

    unsigned long MoneyEarned;
    unsigned long Money;

    short DiceValue;
    int Bet;
    int BetMoney;
    char isRepeat = 'y';

    ShowIntroScreen();
    Money = 1000;

    do {

        do {

            ShowInformation(Money);

            Bet         = GetBet();
            BetMoney    = GetAmount();
            DiceValue   = DoDiceThrow();
            MoneyEarned = DoMoneyCalc(DiceValue, Bet, BetMoney);

            Money -= BetMoney;

            if (MoneyEarned == 0) {

                cout << "You lost. Number was: " << DiceValue;
                cout << endl << endl;

            } else {

                cout << "You won " << MoneyEarned - BetMoney;
                cout << " dollars. Number was: " << DiceValue;
                cout << endl << endl;

                Money += MoneyEarned;

            }

        } while (Money >= 101);

        cout << "Game Over. Keep $" << Money << " for the ride home";
        cout << endl;
        cout << "\nWould you like to play again? (y/n): ";  // Ask if program wants to be runned again
        cin >> isRepeat;

        if (isRepeat != 'y' && isRepeat != 'Y') {

            cout << "\nThanks for watching!";  // Output thank you message
            cout << "\n\n####################################################\n\n";
            system("pause");  // Pause until user presses any key

        } else {

            cout << "\n####################################################\n";  // Display a barrier for new line

        }

    } while (isRepeat == 'y' || isRepeat == 'Y');

    return 0;
}

void ShowIntroScreen(void) {

    cout << endl;
    cout << "           ############################           " << endl;
    cout << "           #                          #           " << endl;
    cout << "           #   WELCOME TO CRAPS 1.0!  #           " << endl;
    cout << "           #                          #           " << endl;
    cout << "           ############################           " << endl;
    cout << endl;

    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "* ---------------- HOW TO PLAY ----------------- *" << endl;
    cout << "*                                                *" << endl;
    cout << "*    YOU HAVE 1000 DOLLARS TO START GAMBLING!    *" << endl;
    cout << "*                                                *" << endl;
    cout << "*       You can do three different bets.         *" << endl;
    cout << "* You can bet on numbers 2 or 12 which will give *" << endl;
    cout << "*     you a win ratio of 5 to 1 if you win.      *" << endl;
    cout << "* You can also bet on the numbers 4 or 10 which  *" << endl;
    cout << "*     will give you a win ratio of 2.5 to 1.     *" << endl;
    cout << "*  You can also bet on the numbers 3 or 9 which  *" << endl;
    cout << "*     will give you a win ratio of 1.7 to 1.     *" << endl;
    cout << "*   The last kind of bet you can do is on the    *" << endl;
    cout << "*        numbers 6 or 8 which will give          *" << endl;
    cout << "*         you a win ratio of 1.5 to 1.           *" << endl;
    cout << "*                                                *" << endl;
    cout << "* ---------------- END OF RULES ---------------- *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;

    cout << "The minimum amount to bet is 10 dollars and the maximum 100 dollars.";
    cout << endl << endl;

    cout << "Have fun playing.";
    cout << endl << endl;
}

void ShowInformation(unsigned long Money) {
    cout << "You have : " << Money << " dollars.";
    cout << endl;
}

int GetBet(void) {

    int BetType;
    string input;

    bool isWrong = false;  // Flag to check if input is correct

    do {    

        cout << "Enter type of bet (1 = '2/12' 2 = '4/10' 3 = '6/8' 4 = '3/9'): ";
        cin >> input;  // Store input into a string as text input

        // Check if input is correct or not
        if (input != "1" && input != "2" && input != "3" && input != "4") {
            
            cout << "\nPlease enter again, because only numbers 1,2,3,4 are allowed.\n\n";
            isWrong = true;

        } else {
            
            isWrong = false;  // Reset isWrong to false
        
        }

    } while (isWrong == true);  // Flags it
    
    // Convert text to integer after checking it is 1,2,3,4
    BetType = stoi(input);
    return BetType;

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

unsigned short DoMoneyCalc(short DiceValue, int Bet, int BetMoney) {

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

int GetAmount(void) {     

    int BetAmount;
    string input;
    bool isWrong = false;  // Flag to check if input is correct

    do {

        cout << "Enter amount to bet (min 10 - max 100): ";
        cin >> input;  // Store input into a string as text input

        // Check if input is correct or not
        if (input >= "1") {

            isWrong = false;  // Reset isWrong to false

        } if (input <= "100") {

            isWrong = false;  // Reset isWrong to false

        } else {

            cout << "\nPlease enter again, because bet amount needs to be between 1 and 100.\n\n";
            isWrong = true;

        }

    } while (isWrong == true);  // Flags it

        // Convert text to integer after checking it is between 1 and 100
        BetAmount = stoi(input);

    if (BetAmount < 10) {

        BetAmount = 10;

    } if (BetAmount > 100) {

        BetAmount = 100;

    }

    return BetAmount;
}