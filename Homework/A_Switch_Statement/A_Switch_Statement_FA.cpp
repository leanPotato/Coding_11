/* A swtich statement Felipe/Ayaan 28/02/2025 */

#include <iostream>

using namespace std;

int main() {

	char grade;

	cout << "Enter your midterm grade and press Return: ";
	cin >> grade;

	switch (grade) {

	case 'A':
		cout << "Excellent."
			 << " You need not take the final.\n";
		break;

	case 'B':
		cout << "Very good. ";
		grade = 'A';
		cout << "Your midterm grade is now "
			<< grade << "." << endl;
		break;

	case 'C':
		cout << "Passing.\n";
		break;

	case 'D':
	case 'F':
		cout << "Not good. "
			<< "Go study.\n";
		break;

	default:
		cout << "That is not a possible grade.\n";

	}

	cout << "End of program.\n";
	return 0;

}