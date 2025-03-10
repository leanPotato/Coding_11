/************************************
*                                   *
*   While_Loops_2.12                *
*   Author: Felipe and Ayaan        *
*   Date: 07-03-2025                *
*   Purpose: To make a while loop   *
*                                   *
************************************/

#include <iostream>

using namespace std;

int main() {

    int countdown;

    cout << "How many greetings do you want? ";
    cin >> countdown;

    while (countdown > 0) {

        cout << "Hello ";
        countdown = countdown - 1;

    }

    cout << endl;
    cout << "That's all!\n";
    return 0;

}