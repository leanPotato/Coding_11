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
#include <ctime>

using namespace std;


int main() {

    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand()%100 + 1;
    int tries = 0;
    int guess;

    cout << "\n\tWelcome to Guess My Number\n\n";

    do {

        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber) {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Too low!\n\n";
        }
        else {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        } 
    } while (guess!= secretNumber);
    return 0;
}