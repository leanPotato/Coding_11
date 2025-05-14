/****************************************************************************************
*                                                                                       *
*	Title:   CS11 listing 4.3 Accessing Elements in a Multidimensional Array            *
*	Author:  Felipe                                                                     *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is trying to teach how to access elements in a                 *
*            multidimensional array. Listing 4.3 explains how integer elements in this  *
*            array can be accessed                                                      *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    int threeRowsThreeColums[3][3] = {{-501, 205, 2016}, { 989, 101, 206 }, { 303, 456, 596 }};

    cout << "Row 0: " << threeRowsThreeColums[0][0] << " " << threeRowsThreeColums[0][1] << " " << threeRowsThreeColums[0][2] << endl;

    cout << "Row 1: " << threeRowsThreeColums[1][0] << " " << threeRowsThreeColums[1][1] << " " << threeRowsThreeColums[1][2] << endl;

    cout << "Row 2: " << threeRowsThreeColums[2][0] << " " << threeRowsThreeColums[2][1] << " " << threeRowsThreeColums[2][2] << endl;

    return 0;
}