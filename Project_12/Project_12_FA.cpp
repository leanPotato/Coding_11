//*Programming project 12 Felipe and Ayaan - 26/02/2025*//

#include <iostream>
using namespace std;

const float NUMBER_OF_PI = 3.14159;

const float CUBIC_FOOT = 7.48;

double volume_Of_Cylinder(double radius, double height);

int main() {

	double radius, height, volume;

	cout << "What is your radius casing in inches: ";
	cin >> radius;
	cout << "What is the depth of the well in feet: ";
	cin >> height;

	if (radius == 0) {

		cout << "Sorry, no can do.";
		return 0;

	}

	else if (height == 0)
	
	{

	cout << "Sorry, no can do.";
	return 0;

	}

	else
	
	{

	volume = volume_Of_Cylinder(radius, height);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Your casing holds: " << volume << " gallons of water." << endl;

	}

	return 0;

}

double volume_Of_Cylinder(double radius, double height) {

	return (NUMBER_OF_PI * (radius * radius)) * (height * 12) * (CUBIC_FOOT));

}