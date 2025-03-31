/****************************************************************************************
*                                                                                       *
*	Title:   Programming Project Guess the number game                                  *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    03/31/2025                                                                 *
*	Purpose: The program is trying to guess a random number                             *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    short Number;
    short Guess = 0;

    Number = rand() % 100;
    Number++;

    while (Guess != Number || Guess != 0) {

        cout << "Enter a number between 1 and 100: ";
        cin >> Guess;

        if (Guess < Number) {

            cout << "You are guessing low." << endl;
        }

        if (Guess > Number) {

            cout << "You are guessing high." << endl;
        }

        if (Guess > 4) {
            
            cout << "You have too many guesses!" << endl;
            return 0;

        }
    }

    if (Guess == 0) {

        cout << "Too many guesses bud!";

    }
    
    else {

        cout << "You got it bud, the winning number is: " << Number << endl;

    }

    return 0;
}