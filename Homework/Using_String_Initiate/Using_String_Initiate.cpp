/****************************************************************************************
*                                                                                       *
*	Title:   CS11 listing 4.7 Using string to initialize, store user input, copy        *
*            concatenate, and determine the lenght of a string                          *
*	Author:  Felipe                                                                     *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is to teach about using std::string to initiate and manipulate *
*            string data, needed when string is needed to scale up when more data       *
*            is needed to be stored in                                                  *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string greetString("Hello std::string!");
    cout << greetString << endl;

    cout << "Enter a line of text : " << endl;
    string firstLine;
    getline(cin, firstLine);

    cout << "Enter another : " << endl;
    string secondLine;
    getline(cin, secondLine);

    cout << "Result of concatenation: " << endl;
    string concatString = firstLine + " " + secondLine;
    cout << concatString << endl;

    cout << "Copy of concatenated string: " << endl;
    string aCopy;
    aCopy = concatString;
    cout << aCopy << endl;

    cout << "Length of concat string: " << concatString.length() << endl;

    return 0;
}