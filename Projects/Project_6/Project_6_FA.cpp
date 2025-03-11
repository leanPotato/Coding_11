/****************************************************************************************
*                                                                                       *
*	Title:   Programming Project 6                                                      *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    03/03/2025                                                                 *
*	Purpose: The program is trying to find your gross pay, each withholding amount,     *
*            and the net take-home pay depending on your input hours per week and       *
*            number of dependents                                                       *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

// Defining functions
void display_Intro();  // Function to display intro banner
double calc_Gross_and_Tax(double hoursWorked, double dependents, double PAYMENT_PER_HOUR);  // Calculate gross and tax

int main() {

	// State local variables
	double hoursWorked, dependents , take_Home_Pay;
	
	// isRepeat is set as yes so you can run it the first time
	char isRepeat = 'y'; 

	// While loop dependent on yes or no
	while (isRepeat == 'y' || isRepeat == 'Y') {

		// Call title banner
		display_Intro();

		// Ask user for their hours worked and amount of dependents
		cout << "Input the number of hours you work in a week: ";
		cin >> hoursWorked;
		cout << "Input the amount of dependents you have:      ";
		cin >> dependents;
		cout << "\n------------------------------------------------\n";

		// Call function to do calculation
		take_Home_Pay = calc_Gross_and_Tax(hoursWorked, dependents, 16.78);
        cout << "\n------------------------------------------------\n";
        cout << "\nWe have saved your take\nhome net pay in a file as:   $" << take_Home_Pay << endl;
        cout << "\n------------------------------------------------\n";
		cout << "\n\nWould you like to repeat the program again? (y/n): ";  // Ask if program wants to be runned again
		cin >> isRepeat;

		// Check if isRepeat is y
		if (isRepeat != 'y' && isRepeat != 'Y') {
			cout << "\nThanks for watching!";  // Output thank you message
            system("pause");  // Pause until user presses button
		} else {
			cout << "\n####################################################\n";  // Display a barrier for new line
		}

	}

	return 0;
}

// Displays intro panel
void display_Intro() {

	cout << endl;
	cout << "############################" << endl;
	cout << "#                          #" << endl;
	cout << "#  GROSS & TAX CALCULATOR  #" << endl;
	cout << "#                          #" << endl;
	cout << "############################" << endl << endl;

	return;
}

// Calculate gross and tax
double calc_Gross_and_Tax(double hoursWorked, double dependents, double PAYMENT_PER_HOUR) {
	
	// Makes sure that hours worked >= 0
	if (hoursWorked <= 0) {
		cout << "Hours worked needs to be more than 0.\n";
		return 0;
	} if (dependents < 0) {
		cout << "Dependents cannot be negative.\n";
		return 0;
	}

	const float SOCIAL_SECURITY_TAX = 0.06;
	const float FEDERAL_INCOME_TAX = 0.14;
	const float UNION_DUES = 10;
	const float WITHHELD_DEPENDENTS = 35;
	const float OVERTIME_RATE = 1.5;
	const float STATE_INCOME_TAX = 0.05;
	
	// State local variables
	double grossPay, newSocialSecurityTax, newFederalTax,
		   newStateTax, takeHomePay;

    cout.setf(ios::fixed);      // Setting the output to fixed-point
	cout.setf(ios::showpoint);  // Setting a decimal point must
	cout.precision(2); 		    // Setting 2 decimal places

	// If hours worked > 40, then gross pay has overtime included
	if (hoursWorked > 40) {

		// Updates gross pay with overtime payment
		grossPay = (PAYMENT_PER_HOUR * 40) + (((hoursWorked - 40) * PAYMENT_PER_HOUR) * OVERTIME_RATE);
		cout << "\nIf you worked more than 40 hours,\nyour Gross payment is:       $" << grossPay << endl;

	} else {  // If hours worked < 40, then gross has NO overtime included

		// Calculate gross pay (No overtime included)
		grossPay = PAYMENT_PER_HOUR * hoursWorked;
		// Original gross pay is left untouched
		cout << "\nIf you worked less than 40 hours,\nyour Gross payment is:       $" << grossPay << endl;

	}

	// Calculate the rest of the taxes based on the correct gross pay that was calculated earlier
	newSocialSecurityTax = SOCIAL_SECURITY_TAX * grossPay;
	newFederalTax = FEDERAL_INCOME_TAX * grossPay;
	newStateTax = STATE_INCOME_TAX * grossPay;

	// If dependents >= 3, then take home pay will include withheld dependents
	if (dependents >= 3) {

		cout << "Your Withheld dependents is: $" << WITHHELD_DEPENDENTS << endl;
		takeHomePay = grossPay - newSocialSecurityTax - newFederalTax - newStateTax - UNION_DUES - WITHHELD_DEPENDENTS;

	} else {  // Dependents < 3

		// Otherwise, dependents will not include withheld dependents
		takeHomePay = grossPay - newSocialSecurityTax - newFederalTax - newStateTax - UNION_DUES;

	}

	// Show all taxes at the end
	cout << "Your Security tax is:        $" << newSocialSecurityTax << endl;
	cout << "Your Federal tax is:         $" << newFederalTax << endl;
	cout << "Your State income tax is:    $" << newStateTax << endl;
	cout << "Your Union dues is:          $" << UNION_DUES << endl;
	cout << "Your Net take home pay is:   $" << takeHomePay << endl;

	return takeHomePay;
}