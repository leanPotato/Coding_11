//*Calculate_Circle_FA, 2/19/2025*//
#include <iostream>
#include <cmath>

using namespace std;

const float NUMBER_OF_PI = 3.14159;

float find_The_Circumference(double radius);

double find_The_Area(double radius);

int main() {

	double radius, area, circumference;

	cout << "What is your Radius?: ";
	cin >> radius;

	circumference = find_The_Circumference(radius);
	cout << "The formula used for this was: (2 * " << NUMBER_OF_PI << " * " << radius << ")" << endl;
	cout << "Your circumference is: " << circumference << endl;

	area = find_The_Area(radius);
	cout << "The formula used for this was: (" << NUMBER_OF_PI << " * " << radius << "^2)"<< endl;
	cout << "Your Area is: " << area << endl;

	return 0;

}

float find_The_Circumference(double radius) {

	return 2 * NUMBER_OF_PI * radius;

}

double find_The_Area(double radius) {

	return pow(radius, 2) * NUMBER_OF_PI;

}