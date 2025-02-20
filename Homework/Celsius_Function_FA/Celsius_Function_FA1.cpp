/*Celsius_Function_FA_18/02/2025*/
#include <iostream>
using namespace std;

//declaring function//
double celsiusToFahrenheit(double celsius);

//Main Program//
int main() {
    
    //Declaring celsius and fahrenheit variable//
    double celsius, fahrenheit;

    cout << "What is your temperature in Celsius (Up to two decimals): ";
    cin >> celsius;

    //Function_Call//
    fahrenheit = celsiusToFahrenheit(celsius);
    cout << "The formula used for this was: (" << celsius << " * 1.8) +32 " << endl;
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;

    return 0;

}

//Function_heading//
double celsiusToFahrenheit(double celsius) {
   
    return (celsius * 1.8) + 32;

}
