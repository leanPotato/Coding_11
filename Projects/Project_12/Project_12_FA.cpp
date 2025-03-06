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

// Defining constants for the value of pi and the conversion for cubic feet to gallons
const float NUMBER_OF_PI = 3.14159;  // Value of pi
const float CUBIC_FOOT = 7.48;       // Conversion for gallons
const float CONV_TO_FEET = 12;	     // Conversion from inches to feet

// Function for volume of a cylinder
double volume_Of_Cylinder(double radius, double height);

int main() {

	double radius, height, volume;

	// Asking for the radius
	cout << "What is your radius casing in inches: ";
	cin >> radius;
	radius /= CONV_TO_FEET;  // Converting inches to feet

	// Checking if the radius is 0
	if (radius == 0) {

		cout << "Sorry, radius cannot be 0.";
		return 0;

	}

	// Asking for the depth
	cout << "What is the depth of the well in feet: ";
	cin >> height;

	// Checking if the height is 0
	if (height == 0) {

		cout << "Sorry, depth cannot be 0.";
		return 0;

	}

	volume = volume_Of_Cylinder(radius, height);  // Calling the function volume_Of_Cylinder to volume
	volume = (volume * CUBIC_FOOT);  			  // Converting cubic feet to gallons
	cout.setf(ios::fixed);          			  // Setting the output to fixed-point
	cout.setf(ios::showpoint);       			  // Setting a decimal point must
	cout.precision(2);               			  // Setting precision to two decimal places

	// Outputing the volume of the well in gallons
	cout << "Your casing holds: " << volume << " gallons of water." << endl;

	return 0;

}

// Function to calculate the volume of the cylinder
double volume_Of_Cylinder(double radius, double height) {

	// Formula for the volume of a cylinder: V = pi * r^2 * height
	return ((NUMBER_OF_PI * (radius * radius)) * (height));  //Return the finished calculation

}