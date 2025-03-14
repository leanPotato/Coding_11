/****************************************************************************************
*                                                                                       *
*	Title:   Randomizing 1                                                              *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    03/03/2025                                                                 *
*	Purpose: The program is trying to use rand_MAX                                      *
*                                                                                       *
*****************************************************************************************/

#include <iostream>

using namespace std;

int main() {

    short Value;
    short Dividend = 4;

    for (Value = 0; Value < 25; Value++)

    {
   
        cout << Value <<  "%" << Dividend << "=" << Value % Dividend << endl;

    
    }

    return 0;

}