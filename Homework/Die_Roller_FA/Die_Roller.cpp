/****************************************************************************************
*                                                                                       *
*	Title:   Die Roller Program                                                         *
*	Author:  Felipe and Ayaan                                                           *
*	Date:    04/01/2025                                                                 *
*	Purpose: The program is trying to run a die roller program, generating a            *
*   random number                                                                       *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using std:: chrono::duration_cast;
using std:: chrono::system_clock;
using std:: chrono::microseconds;

int main() {

    srand(duration_cast<microseconds>(system_clock::now().time_since_epoch()).count());
    int randomNumber = rand();
    int die = (randomNumber % 6) + 1;
    cout << "You rolled a " << die << endl;

    return 0;
}