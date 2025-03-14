/****************************************************************************************
*                                                                                       *
*	Title:   Pseudo Numbers                                                             *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    03/14/2025                                                                 *
*	Purpose: The program is trying to use cstdlib as the library for rand()             *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    for (int i = 0; i < 8; i++)
        cout << rand() << endl;
    cout << "RAND_MAX = " << RAND_MAX << endl;

}
