/****************************************************************************************
*                                                                                       *
*	Title:   CS11 listing 6.10 using for loops to eneter elements in a Static array and *
*            displaying it                                                              *
*	Author:  Felipe                                                                     *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is to teach about using for loops to enter elements in a static*
*            array to display it                                                        *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    const int ARRAY_LENGTH = 5;
    int myNums[ARRAY_LENGTH] = { 0 };

    cout << "Populate array of " << ARRAY_LENGTH << " integers" << endl;

    for (int counter = 0; counter < ARRAY_LENGTH; ++counter) {

        cout << "Enter an integer for element " << counter << ": ";
        cin >> myNums[counter];

    }

    cout << "Displaying contents of the array: " << endl;

    for (int counter = 0; counter < ARRAY_LENGTH; ++counter)
        cout << "Element " << counter << " = " << myNums[counter] << endl;

    return 0;
}