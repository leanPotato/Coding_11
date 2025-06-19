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

void showSeating (char seats[][6], int rows, int colmn);
void addPassenger(char seats[][6], int rows, int colmn);
bool isFull(char seats[][6], int rows, int colmn);
void showIntroScreen();

int main() {

    char cmd;
    string input;
    const int  NUM_ROWS = 9;
    const int  NUM_SEATS = 6;
    
    char seats[NUM_ROWS][NUM_SEATS];
    char Quit = 'q';
    char Add = 'a';
    char Show = 's';

    showIntroScreen();

    for (int row = 0; row < NUM_ROWS; ++row) {

        for (int col = 0; col < NUM_SEATS; ++col) {
            seats[row][col] = 'A' + col;  //  Fills seat letters
        }
    }

    do {

        cout << "\nType what you want to do (a = add passenger, s = show seating available, q = quit program): ";
        cin >> input;  // Recieves the input the user puts in


        if (input != "a" && input != "s" && input != "q") {

            input.clear();  // clears the string
            cout << "This input is invalid. Please only input a, s, or q.\n";
            continue;
        
        }

        cmd = tolower(input[0]);  // This changes the input to uppercase incase it was inputed as lowercase

        switch (cmd) {
        case 's':
            showSeating(seats, NUM_ROWS, NUM_SEATS);
            break;
        case 'a':
            if (isFull(seats, NUM_ROWS, NUM_SEATS)) {
                cout << "All seats are already taken.\n";
            } else {
                addPassenger(seats, NUM_ROWS, NUM_SEATS);
            }
            break;
        case 'q':
            cout << "Thanks for checking this seating arrangment program!\n";
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

void showSeating(char seats[][6], int rows, int colmn) {

    cout << "\nShowing seating chart (0 = Open seat, X = Taken seat):\n\n";
    cout << "";


    cout << "           _      "   << endl;
    cout << "          / \\    "   << endl;
    cout << "         /   \\   "   << endl;
    cout << "        /     \\  "   << endl;
    cout << "       /       \\ "   << endl;
    cout << "      /         \\ "  << endl;
    cout << "     /           \\ " << endl;
    cout << "    |             | " << endl;

    for (int r = 0; r < rows; ++r) {

        if (r == 3 || r == 8) {

            cout << "    |             |" << endl;

        }

        cout << r + 1 << "  ";

        if (r < 9) {

            cout << " ";

        }

        for (int c = 0; c < colmn; ++c) {



            if (c == 0) {

                cout << "|";

            } else if (c == 3) {

                cout << "  ";
 
            }

            cout << seats[r][c] << ' ';
            
            if (c == 5) {

                cout << "\b|";
                
            }
        }
        cout << endl;
    }
}


void addPassenger(char seats[][6], int rows, int colmn) {

    string input;
    cout << "Type the seat you would like and we will check if its available! (e.g. : 1A, 2B): ";
    cin >> input;

    int row = 0;
    char seatLet;

    if (input.length() == 2 && (input[0] >= '0') && (input[0] <= '9')) {

        row = input[0] - '1';  // Taking row from input
        seatLet = input[1];

    } else {

        cout << "Input is invalid please try again.\n";
        return;

    }

    if (row < 1 || row > rows || seatLet < 'A' || seatLet >= 'A' + colmn) {

        cout << "Input is invalid please try again.\n";
        return;

    }

    int seatNum = seatLet - 'A';  // Find col 

    if (seats[row][seatNum] == 'X') {

        cout << "Seat is already taken";

    } else {

        seats[row][seatNum] = 'X';
        cout << "Seat " << input << " has been assigned to you.\n";

    }
}

bool isFull(char seats[][6], int rows, int colmn) {

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < colmn; ++c)
            if (seats[r][c] != 'X')
                return false;

    return true;
}