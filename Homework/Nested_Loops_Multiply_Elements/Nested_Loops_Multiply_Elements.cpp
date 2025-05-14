/****************************************************************************************
*                                                                                       *
*	Title:   CS11 listing 6.14 Using nested loops to multiply each element in an array  *
*             by each                                                                    *
*	Author:  Felipe                                                                     *
*	Date:    05/14/2025                                                                 *
*	Purpose: The program is to teach about using for loops to enter elements in a static*
*            array to display it                                                        *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    const int ARRAY1_LEN = 3;
    const int ARRAY2_LEN = 2;

    int myNums1[ARRAY1_LEN] = { 35, -3, 0 };
    int myNums2[ARRAY2_LEN] = { 20, -1 };

    cout << "Multiplying each int in myNums1 by each in nyyNums2:" << endl;

    for (int index1 = 0; index1 < ARRAY1_LEN; ++index1)
        for (int index2 = 0; index2 < ARRAY2_LEN; ++index2)
            cout << myNums1[index1] << " x " << myNums2[index2] << " = " << myNums1[index1] * myNums2[index2] << endl;

    return 0;



}