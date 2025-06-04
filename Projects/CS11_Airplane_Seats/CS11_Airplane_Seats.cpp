/****************************************************************************************
*                                                                                       *
*	Title:   CS11 Airplane Seats                                                        *
*	Author:  Felipe                                                                     *
*	Date:    05/20/2025                                                                 *
*	Purpose: The program is to write a program to assign passengers seats in an         *
*            airplane.                                                                  *
*                                                                                       *
*****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void showSeating (char seats[][4], int rows, int cols);
bool addPassenger(char seats[][4], int rows, int cols);
bool isFull(char seats[][4], int rows, int cols);
void showIntroScreen();

int main() {

    const int  NUM_ROWS = 4;
    const int  NUM_SEATS = 7;
    
    char seats[NUM_ROWS][NUM_SEATS];
    char Quit = 'q';
    char Add = 'a';
    char Show = 's';

    for (int i = 0; i < NUM_ROWS; ++i) {

        for (int j = 0; j < NUM_SEATS; ++j) {
            seats[i][j] = '0';
        }
    }

    char cmd;

    do {

        showIntroScreen();

        cout << "\nType what you want to do (a = add passenger, s = show seating available, q = quit program): ";
        cin >> cmd;

        switch (cmd) {
        case 's':
            showSeating(seats);
            showIntroScreen();
            break;
        case 'a':
            addPassenger(seats);
            showIntroScreen();
            break;
        case 'q':
            cout << "Exiting program\n";
            break;
        default:
            cout << "Please type a, s, or q.";
            break;
        }

    } while (cmd != 'q');

    return 0;
}



void showIntroScreen() {

    cout << endl;
    cout << "           #############################################           " << endl;
    cout << "           #                                           #           " << endl;
    cout << "           #   WELCOME TO AIPLANE SEAT ARRANGER 1.0!   #           " << endl;
    cout << "           #                                           #           " << endl;
    cout << "           #############################################           " << endl;
    cout << endl;


}

void showSeating (char seats[][4], int rows, int cols); {

    cout << "\n Showing seating chart (0 = Open seat, X = Taken seat):\n\n";
    cout << "         ";

    for (int i = 0; i < NUM_SEATS; ++i)
    cout << " " << i + 1 << " ";
    cout << "\n";

    for (int i = 0; i < NUM_ROWS; ++i) {
    
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < NUM_SEATS; ++j) {

            cout << "[" << seats[i][j] << "]";

        }
        cout << "\n";

    }
    cout << "\n";
}


bool addPassenger(char seats[][4], int rows, int cols) {

    int row, seat;
    cout << "Enter row number (1-" << NUM_ROWS << "): ";
    cin >> row;
    cout << "Enter seat number (1-" << NUM_SEATS << "): ";
    cin >> seat;

    row -= 1;
    seat -= 1;

    if (row < 0 || row >= NUM_ROWS || seat < 0 || seat >= NUM_SEATS) {
        cout << "Invalid seat selection.\n";
        return;
    }

    if (seats[row][seat] == 'X') {
        cout << "Seat already taken.\n";
    } else {
        seats[row][seat] = 'X';
        cout << "Passenger added to Row " << row + 1 << ", Seat " << seat + 1 << ".\n";
    }
}