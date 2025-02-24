//*Functions and lists - 02/23/2025*//
#include <iostream>

using namespace std;

void ShowHelp(void);

int main() 
{
	short Action;

	cout << "What do you want to do: ";
	cin >> Action;

	if (Action == 1)
	{
		cout << "You have chosen to run away.";
		cout << endl;
	}
	if (Action == 2)
	{
		cout << "You have chosen to fight.";
		cout << endl;
	}
	if (Action == 3)
	{
		cout << "You did wrong... You die!";
		cout << endl;
	}
	if (Action == 4)
		ShowHelp ();

	return 0;
}

void ShowHelp(void)
{
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