/* Switching to Switch Felipe and Ayaan 28/02/2025 */

#include <iostream>

using namespace std;

void ShowHelp(void);

int main() {

	short Action;
	cout << "What do you want to do: ";
	cin >> Action;

	switch (Action) {

	case 1: 
		cout << "You have chosen to run away.";
		cout << endl;
		break;

	case 2:
		cout << "You have chosen to fight.";
		cout << endl;
		break;

	case 3:
		cout << "You did wrong, you die!";
		cout << endl;
		break;

	default:
		ShowHelp();
		break;

	}

	return 0;

}

void ShowHelp(void) {

	cout << endl;
	cout << "1 - Run";
	cout << endl;
	cout << "2 - Fight";
	cout << endl;
	cout << "3 - Surprise Action";
	cout << endl;
	cout << "4 - Shows this help screen";
	cout << endl;

}