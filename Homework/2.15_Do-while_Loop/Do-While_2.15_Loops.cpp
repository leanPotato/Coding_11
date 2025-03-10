/****************************************************************************************
*                                                                                       *
*	Title:   Display 2.15                                                               *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    03/10/2025                                                                 *
*	Purpose: The program is trying tell a do-while loop                                 *
*                                                                                       *
*****************************************************************************************/

#include<iostream>

using namespace std;

int main() {

    char ans;

    do {

        cout << "Hello\n";
        cout << "Do you want another greeting?\n"
            << "Press y for yes, n for no,\n"
            << "and then press return: ";

        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << "Good-Bye\n";
    return 0;

}