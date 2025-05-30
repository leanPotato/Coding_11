/****************************************************************************************
*                                                                                       *
*	Title:   CS11 Modifying Data Stored In An Array                                     *
*	Author:  Felipe                                                                     *
*	Date:    05/07/2025                                                                 *
*	Purpose: The program is to teach how to modify an array                             *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

constexpr int Square(int number) { return number * number; }

int main() {

    const int ARRAY_LENGTH = 5;

    int myNumbers[ARRAY_LENGTH] = { 5, 10, 0 , -101, 20 };

    int moreNumbers [Square(ARRAY_LENGTH)];
    
    cout << "Enter index of the element to be changed: ";
    int elementIndex = 0;
    cin >> elementIndex;

    cout << "Enter new value: ";
    int newValue = 0;
    cin >> newValue;


    myNumbers[elementIndex] = newValue;
    moreNumbers[elementIndex] = newValue;

    cout << "Element " << elementIndex << " in array myNumbers is:   ";
    cout << myNumbers[elementIndex] << endl;

    cout << "Element " << elementIndex << " in array moreNumbers is: ";
    cout << moreNumbers[elementIndex] << endl;

    return 0;
}