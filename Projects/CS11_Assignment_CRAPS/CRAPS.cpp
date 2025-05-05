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
short DoDiceThrow1(void);
short DoDiceThrow2(void);
unsigned short DoMoneyCalc(short DiceValue1, short DiceValue2, int Bet, int BetMoney);
int GetAmount(void);

int main(void) {

    unsigned long MoneyEarned;
    unsigned long Money;

    short DiceValue;
    short DiceValue1;
    short DiceValue2;
    int Bet;
    int BetMoney;
    char isRepeat = 'y';

    ShowIntroScreen();

    do {

        cout << "How much money would you like start the game with? (Recommended 10 - 1000): ";
        cin >> Money;

        while (cin.fail() || Money < 10) {

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number with a minimum of 10 dollars: ";
            cin >> Money;

        }

        do {

            ShowInformation(Money);

            Bet         = GetBet();
            BetMoney    = GetAmount();
            DiceValue1  = DoDiceThrow1();
            DiceValue2  = DoDiceThrow2();
            MoneyEarned = DoMoneyCalc(DiceValue1, DiceValue2, Bet, BetMoney);

            Money -= BetMoney;

            DiceValue = (DiceValue1 + DiceValue2);

            if (MoneyEarned == 0) {

                cout << "You lost. The Number was: " << DiceValue << " and the two dice were: " << DiceValue1 << " and " << DiceValue2 << ".";
                cout << endl << endl;

            } else {

                cout << "You won " << MoneyEarned - BetMoney;
                cout << " dollars. The Number was: " << DiceValue << " and the two dice were: " << DiceValue1 << " and " << DiceValue2 << ".";
                cout << endl << endl;

                Money += MoneyEarned;

            }

        } while (Money >= 101);

        cout << "Game Over. Keep $" << Money << " for the ride home";
        cout << endl;
        cout << "\nWould you like to play again? (y/n): ";  // Ask if program wants to be runned again
        cin >> isRepeat;

        if (isRepeat != 'y' && isRepeat != 'Y') {

            cout << "\nThanks for playing!";  // Output thank you message
            cout << "\n\n####################################################\n\n";
            system("pause");  // Pause until user presses any key

        } else {

            cout << "\n####################################################\n" << endl;  // Display a barrier for new line

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
    cout << "\nYou have : " << Money << " dollars.\n" << endl;
    cout << "*************************************" << endl;
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

short DoDiceThrow1(void) {

    short DiceValue1;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int randomNumber1 = rand();
    DiceValue1 = (randomNumber1 % 6) + 1;

    return DiceValue1;
}

short DoDiceThrow2(void) {

    short DiceValue2;

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int randomNumber2 = rand();
    DiceValue2 = (randomNumber2 % 6) + 1;

    return DiceValue2;

}

unsigned short DoMoneyCalc(short DiceValue1, short DiceValue2, int Bet, int BetMoney) {

    short DiceValue;
    unsigned long MoneyEarned = 0;
    
    DiceValue = (DiceValue1 + DiceValue2);

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
    bool isWrong;  // Flag to check if input is correct

    do {

        cout << "\nEnter amount to bet (min 10 - max 100): ";
        cin >> BetAmount;  // Store input into a string as text input

        // Check if input is correct or not
        if (cin.fail()) {

            cout << "\nBruh thats not a number.\n";
            isWrong = true;  // Reset isWrong to false
            cin.clear();
            cin.ignore(1000, '\n');

        }
        else if (BetAmount < 10 || BetAmount > 100) {

            cout << "\nNumber has to be between 10 and 100.\n";
            isWrong = true;  // Reset isWrong to false

        }
        else {

            isWrong = false;

        }

    } while (isWrong == true);  // Flags it

    return BetAmount;
}