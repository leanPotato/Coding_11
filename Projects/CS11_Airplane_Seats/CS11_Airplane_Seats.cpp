/****************************************************************************************
*                                                                                       *
*	Title:   CS11 Airplane Seats                                                        *
*	Author:  Felipe                                                                     *
*	Date:    05/20/2025                                                                 *
*	Purpose: The program is to write a program to assign passengers seats in an         *
*            airplane.                                                                  *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string lookupRow(string targetRow, string row[], string aisle[], int size);
string lookupAisle(string targetRow, string row[], string aisle[], int size);

int main() {

    string row[] = { "A", "B", "C", "D" };

    string aisle[] = { "1" , "2", "3", "4", "5", "6", "7" };

    string targetRow, targetAisle;
    char c;

    do {

        cout << "These are the available seats:" << endl;
        cout << row[0] << aisle[0] << aisle[1] << aisle[2] << aisle[3] << "" << endl;
        cout << row[1] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << aisle[0]<< "" << endl;
        cout << row[2] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << "" << endl;
        cout << row[3] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << "" << endl;
        cout << row[4] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << "" << endl;
        cout << row[5] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << "" << endl;
        cout << row[6] << aisle[0] << aisle[0] << aisle[0] << aisle[0] << "" << endl;

        lookupName(targetRow, row[], aisle[], 4);

        getline(cin, targetRow);
        targetRow = lookupName(targetName, names, phoneNumbers, 7);


        if (targetPhone.length() > 0) {

            cout << "\nThe number is: " << targetPhone << endl << endl;

        }
        else {

            cout << "Name not found. " << endl;
            cout << "look up another name? (y/n)" << endl;

            cin >> c;
            cin.ignore();
        }
    } while (c == 'y');

    return 0;
}

string  lookupName(targetRow, row[], aisle[], 4); {

    cout << "Enter the row in which you would like to pick your seat in: ";
    cin 
    return "";
}