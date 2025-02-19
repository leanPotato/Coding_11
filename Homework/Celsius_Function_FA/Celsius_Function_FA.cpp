/*Celsius_Function_FA_18/02/2025*/
#include <iostream>
using namespace std;

const short ADD_TO_FORMULA = 32;

//declaring function//
double celsiusToFahrenheit(double celsius);
short adding_Add();

int main() {
    
    double celsius, fahrenheit;
    //Declares celsius and fahrenheit variable//

    cout << "What is your temperature in Celsius: ";
    cin >> celsius;

    fahrenheit = celsiusToFahrenheit(celsius);
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;

    return 0;

}

double celsiusToFahrenheit(double celsius) {
   
    return (celsius * 1.8) + adding_Add() ;

}

short adding_Add() {

    return ADD_TO_FORMULA;

}