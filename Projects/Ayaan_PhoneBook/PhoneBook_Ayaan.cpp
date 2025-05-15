/****************************************************************************************
*                                                                                       *
*	Title:   Phone Book Assignment                                                      *
*	Author:  Ayaan                                                                      *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is to make a phone book using arrays                           *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string lookupName(string targetName, string names[], string phoneNumbers[], int size);

int main() {

    string names[]        = { "Micheal Myers", "Ash Williams", "Jack Torrance", "Freddy Krueger", "Albert Einstein" , "Issac Newton" , "Steve Jobs" };

    string phoneNumbers[] = { "333-8000" , "333-2323", "333-6150", "339-7970", "888 8888", "999 9999", "777 7777" };

    string targetName, targetPhone;
    char c;
    
    do {

        cout << "\nEnter a name to find the corresponding phone number: ";

        getline(cin, targetName);
        targetPhone = lookupName(targetName, names, phoneNumbers, 7);

        if (targetPhone.length() > 0) {

            cout << "\nThe number is: " << targetPhone << endl << endl;

        } else {

            cout << "Name not found. " << endl;
            cout << "look up another name? (y/n)" << endl;

            cin >> c;
            cin.ignore();
        }
    } while (c == 'y');

    return 0;
}

string lookupName(string targetName, string names[], string phoneNumbers[], int size) {

    for (int counter = 0; counter < size; ++counter) {

        if (names[counter] == targetName) {

            return phoneNumbers[counter];
        }
    }
    return "";
}