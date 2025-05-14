/****************************************************************************************
*                                                                                       *
*	Title:   CS11 listing 6.15 Using nested loops to iterate elements in a 2D Array of  *
*            integers                                                                   *
*	Author:  Felipe                                                                     *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is trying to teach how to use nested loops to walk a           *
*            multidimensional array. Since arrays may be larger, using lops can change  *
*            array's way to access its elements                                         *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    const int NUM_ROWS    = 3;
    const int NUM_COLUMNS = 4;

    int MyInts[NUM_ROWS][NUM_COLUMNS] = { {34, -1, 879, 22}, {24, 365, -101, -1} , {-20, 40, 90, 97} };

    // Iterate rows, each array of int

    for (int row = 0; row < NUM_ROWS; ++row) {

        // Iterate integers in each row (columns)
        for (int column = 0; column < NUM_COLUMNS; ++column) {
            cout << "Integer[" << row << "][" << column << "] = " << MyInts[row][column] << endl;
        }
    }

    return 0;
}