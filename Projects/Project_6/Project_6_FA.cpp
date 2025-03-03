/* Project 6 Felipe and Ayaan 03/03/2025 */

#include <iostream>

using namespace std;

// Defining constants //
const float PAYMENT_PER_HOUR = 16.78;
const float SOCIAL_SECURITY_TAX = 0.06;
const float FEDERAL_INCOME_TAX = 0.14;
const float STATE_INCOME_TAX = 0.05;
const float UNION_DUES = 10;
const float WITHHELD = 35;

// Defining functions //
double give_Gross_Pay(double hours_Worked);
//double net_Take_Home_Pay(double)//

int main() {

	double hours_Worked, dependents, gross_Pay, new_Social_Security_Tax, new_Federal_Tax
	, new_State_Tax;

	cout << "Input the number of hours you work in a week: ";
	cin >> hours_Worked;
	cout << "Input the amount of dependents you have: ";
	cin >> dependents;

	gross_Pay = give_Gross_Pay(hours_Worked);

	if (hours_Worked < 40) {

		cout.setf(ios::fixed);          			  // Setting the output to fixed-point
		cout.setf(ios::showpoint);       			  // Setting a decimal point must
		cout.precision(2);
		cout << "If you worked less than 40 hours, your payment is: $" << gross_Pay << endl;
		new_Social_Security_Tax = SOCIAL_SECURITY_TAX * gross_Pay;
		cout << "Your Security tax is: $" << new_Social_Security_Tax << endl;
		new_Federal_Tax = FEDERAL_INCOME_TAX * gross_Pay;
		cout << "Your Federal tax is $" << new_Federal_Tax << endl;
		new_State_Tax = STATE_INCOME_TAX * gross_Pay;
		cout << "Your State income tax is $" << new_State_Tax << endl;
		return 0;

	}
	

	else if (hours_Worked > 40) {

		cout.setf(ios::fixed);          			  // Setting the output to fixed-point
		cout.setf(ios::showpoint);       			  // Setting a decimal point must
		cout.precision(2);
		cout << "If you worked more than 40 hours, your payment is: $" << gross_Pay  << endl;
		new_Social_Security_Tax = SOCIAL_SECURITY_TAX * gross_Pay;
		cout << "Your Security tax is: $" << new_Social_Security_Tax << endl;
		new_Federal_Tax = FEDERAL_INCOME_TAX * gross_Pay;
		cout << "Your Federal tax is $" << new_Federal_Tax << endl;
		new_State_Tax = STATE_INCOME_TAX * gross_Pay;
		cout << "Your State income tax is $" << new_State_Tax << endl;
		return 0;

	}





}

double give_Gross_Pay(double hours_Worked) {

	return PAYMENT_PER_HOUR * hours_Worked;

}