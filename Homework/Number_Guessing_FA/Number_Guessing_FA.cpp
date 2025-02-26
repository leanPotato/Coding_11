//*Number Guessing for fun - 25/02/2025*//

#include <iostream>
#include <cstdlib>

using namespace std;

//Declare functions//


//Main//

int main() {

	int secret_Number = rand() % 100 + 1;
	int guess, attempts = 0;

	cout << "Guess a number between 1 and 100!" << endl;

	cout << "Enter your guess: ";
	cin >> guess;
	attempts++;

	if (guess > secret_Number)	{
		cout << "Too high! Try again!";
		attempts++;
		cout << endl;
		}
	else if (guess < secret_Number) {

		cout << "Too low! Try again!";
		attempts++;
		cout << endl;
	}

	if (guess == secret_Number) {

		cout << "Congratulations! You have won!";
	}
}