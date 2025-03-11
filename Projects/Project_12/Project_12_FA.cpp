/****************************************************************************************
*																						*
*	Title:   Programming project 12														*
*	Author:  Felipe and Ayaan															*
*	Date:    26/02/2025																	*
*	Purpose: The program is trying to find your gross pay, each withholding ammount,	*
*			 and the net take-home pay depending on your input							*
*																						*
*****************************************************************************************/

#include <iostream>
using namespace std;

// Function for volume of a cylinder
void calc_Volume(double radius, double height);

int main() {

	double radius, height;

    const float CONV_TO_FEET = 12;	     // Conversion from inches to feet

	// Asking for the radius
	cout << "What is your radius casing in inches: ";
	cin >> radius;
	radius /= CONV_TO_FEET;  // Converting inches to feet

	// Asking for the depth
	cout << "What is the depth of the well in feet: ";
	cin >> height;
    
    calc_Volume(radius, height);

	return 0;

}

// Function to calculate the volume of the cylinder
void calc_Volume(double radius, double height) {

    double volume;

    // Checking if the radius is 0
    if (radius == 0) {

        cout << "Sorry, radius cannot be 0.";
        return;

    }

    // Checking if the height is 0
    if (height == 0) {

        cout << "Sorry, depth cannot be 0.";
        return;

    }

    // Defining constants for the value of pi and the conversion for cubic feet to gallons
    const float NUMBER_OF_PI = 3.14159;  // Value of pi
    const float CUBIC_FOOT = 7.48;       // Conversion for gallons

	// Formula for the volume of a cylinder: V = pi * r^2 * height
	volume = ((NUMBER_OF_PI * (radius * radius)) * height);  //Return the finished calculation

    volume = (volume * CUBIC_FOOT);  			  // Converting cubic feet to gallons
    cout.setf(ios::fixed);          			  // Setting the output to fixed-point
    cout.setf(ios::showpoint);       			  // Setting a decimal point must
    cout.precision(2);               			  // Setting precision to two decimal places

    // Outputing the volume of the well in gallons
    cout << "Your casing holds: " << volume << " gallons of water." << endl;

    return;

}