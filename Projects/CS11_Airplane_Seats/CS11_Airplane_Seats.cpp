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

void showSeating (char seats[][4], int rows, int colmn);
void addPassenger(char seats[][4], int rows, int colmn);
bool isFull(char seats[][4], int rows, int colmn);
void showIntroScreen();

int main() {

    const int  NUM_ROWS = 4;
    const int  NUM_SEATS = 7;
    
    char seats[NUM_ROWS][NUM_SEATS];
    char Quit = 'q';
    char Add = 'a';
    char Show = 's';

    for (int r = 0; r < NUM_ROWS; ++r) {

        for (int c = 0; c < NUM_SEATS; ++c) {
            seats[r][c] = 'A' + c;
        }
    }

    char cmd;

    do {

        showIntroScreen();

        cout << "\nType what you want to do (a = add passenger, s = show seating available, q = quit program): ";
        cin >> cmd;

        switch (cmd) {
        case 's':
            showSeating(seats, NUM_ROWS, NUM_SEATS);
            showIntroScreen();
            break;
        case 'a':
            if (isFull(seats, NUM_ROWS, NUM_SEATS)) {
                cout << "All seats are already taken.\n";
            } else {
                addPassenger(seats, NUM_ROWS, NUM_SEATS);
            }
            break;
        case 'q':
            cout << "Thanks for checking it out!\n";
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

void showSeating(char seats[][4], int rows, int colmn); {

    cout << "\n Showing seating chart (0 = Open seat, X = Taken seat):\n\n";
    cout << "         ";

    for (int r = 0; r < rows; ++r) {
        cout << r + 1;
        for (int c = 0; c < colmn; ++c) {
            cout << seats[r][c];
        }
        cout << endl;
    }
}


void addPassenger(char seats[][4], int rows, int colmn) {

    string input;
    cout << "Type the seat you would like and we will check if its available! (exp: 1A, 2B): ";
    cin >> input;

    int row = 0;
    char seatLet;

    if (input.length == 2 && (input[0] >= '0') && (input[0] <= '9') {

        row = input[0] - '0';
        seatLet = input[1];
    }
    else {

        cout << "Input is invalid please try again.\n";
        return;
    }

    if (row < 1 || row > rows || seatLet < 'A' || seatLet >= 'A' + colmn) {

        cout << "Input is invalid please try again.\n";
        return;
    }

    int rowNum = row - '1';
    int seatNum = seatLet - 'A';

    if (seats[rowNum][seatNum] == 'X') {

        cout << "Seat is already taken";
    }
    else {

        seats[rowNum][seatNum] == 'X';
        cout << "Seat " << input << " has been assigned to you.\n";
    }
}

bool isFull(char seats[][4], int rows, int colmn) {

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < colmn; ++c)
            if (seats[r][c] != 'X')
                return false;

    return true;
}