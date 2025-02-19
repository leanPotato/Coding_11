//*CSAssignment1FA.cpp Felipe and Ayaan, Feb 12th, 2025*//
#include <iostream>
using namespace std;

//Main code//
int main() {  
	
	//Variable Declarations for Celsius and Fahrenheit//
	float Celsius;
	double Fahrenheit;

	//Ask the user to enter temperature//
	cout << "Enter temperature in Cahrenheit (Up to two decimal places): ";
	cin >> Celsius;

	//Convert Celsius to Fahrenheit//
	Fahrenheit = (1.8 * Celsius) + 32;

	//Print the explanation and the result of the convertion//
	cout << "\nFormula used: Fahrenheit = (1.8 * Celsius) + 32\n";
	cout << "You entered: " << Celsius << " degrees Celsius" << endl;
	cout << "Your temperature of: " << Celsius << " degrees Celsius is: " << Fahrenheit << " in degrees Fahrenheit. ";

	return 0;
	
}
