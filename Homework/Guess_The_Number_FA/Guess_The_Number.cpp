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
    short Guesses = 0;

    Number = rand() % 100;
    Number++;

    while (Guess != Number) {

        cout << "Enter a number between 1 and 100: ";
        cin >> Guess;
        Guesses++;

        if (Guess < Number) {

            cout << "You are guessing low." << endl;

        }

        else if (Guess > Number) {

            cout << "You are guessing high." << endl;

        }

        else {

            cout << "You got it bud, the winning number is: " << Number << endl;
            break;

        }

        if (Guesses >= 5) {

            cout << "You have too many guesses!" << endl;
            break;

        }

    }

    return 0;
}