/* Project 6 Felipe and Ayaan 03/03/2025 */

#include <iostream>

using namespace std;

// Defining functions
void calc_Gross_and_Tax(double amount, double dependents); // Calculate gross and tax

int main() {

	// State local variables
	double hours_Worked, dependents;
	
	// Ask user for their hours worked and amount of dependents
	cout << "Input the number of hours you work in a week: ";
	cin >> hours_Worked;
	cout << "Input the amount of dependents you have:      ";
	cin >> dependents;
	cout << "\n------------------------------------------------\n";

	// Call function to do calculation
	calc_Gross_and_Tax(hours_Worked, dependents);

	return 0;
	
}

// Calculate gross and tax
void calc_Gross_and_Tax(double amount, double dependents) {
	
	const float PAYMENT_PER_HOUR = 16.78;
	const float SOCIAL_SECURITY_TAX = 0.06;
	const float FEDERAL_INCOME_TAX = 0.14;
	const float UNION_DUES = 10;
	const float WITHHELD_DEPENDENTS = 35;
	const float OVERTIME_RATE = 1.5;
	const float STATE_INCOME_TAX = 0.05;
	
	// State local variables
	double gross_Pay, new_Social_Security_Tax, new_Federal_Tax,
		   new_State_Tax, take_Home_Pay, overtime_Payment;

    cout.setf(ios::fixed);      // Setting the output to fixed-point
	cout.setf(ios::showpoint);  // Setting a decimal point must
	cout.precision(2); 		    // Setting 2 decimal places

	// Calculate gross pay (No overtime included yet)
	gross_Pay = PAYMENT_PER_HOUR * hours_Worked;

	// Calculate overtime gross pay
	overtime_Payment = gross_Pay + ((hours_Worked * PAYMENT_PER_HOUR) * OVERTIME_RATE);

	// If hours worked > 40, then gross pay has overtime included
	if (hours_Worked > 40) {

		// Updates gross pay with overtime payment
		gross_Pay = overtime_Payment;
		cout << "\nIf you worked more than 40 hours,\nyour Gross payment is:       $" << gross_Pay << endl;

	}
	else {  // If hours worked < 40, then gross has NO overtime included

		// Original gross pay is left untouched
		cout << "\nIf you worked less than 40 hours,\nyour Gross payment is:       $" << gross_Pay << endl;

	}

	// If dependents >= 3, then take home pay will include withheld dependents
	if (dependents >= 3) {

		cout << "Your Withheld dependents is: $" << WITHHELD_DEPENDENTS << endl;
		take_Home_Pay = gross_Pay - new_Social_Security_Tax - new_Federal_Tax - new_State_Tax - UNION_DUES - WITHHELD_DEPENDENTS;

	}
	else {  // Dependents < 3

		// Otherwise, dependents will not include withheld dependents
		take_Home_Pay = gross_Pay - new_Social_Security_Tax - new_Federal_Tax - new_State_Tax - UNION_DUES;

	}

	// Calculate the rest of the taxes based on the correct gross pay that was calculated earlier
	new_Social_Security_Tax = SOCIAL_SECURITY_TAX * gross_Pay;
	new_Federal_Tax = FEDERAL_INCOME_TAX * gross_Pay;
	new_State_Tax = STATE_INCOME_TAX * gross_Pay;

	// Show all taxes at the end
	cout << "Your Security tax is:        $" << new_Social_Security_Tax << endl;
	cout << "Your Federal tax is:         $" << new_Federal_Tax << endl;
	cout << "Your State income tax is:    $" << new_State_Tax << endl;
	cout << "Your Union dues is:          $" << UNION_DUES << endl;
	cout << "Your Net take home pay is:   $" << take_Home_Pay << endl;

	return;

}