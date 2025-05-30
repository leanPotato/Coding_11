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

void showSeating(char seats[NUM_ROWS][NUM_AISLES]);
void showIntroScreen();
/*string addPassenger();



string lookupRow(string targetRow, string row[], string aisle[], int size);
string lookupAisle(string targetRow, string row[], string aisle[], int size);*/

int main() {

    char seats[NUM_ROWS][NUM_SEATS];
    int  NUM_ROWS = 4;
    int  NUM_AISLES = 7;
    char Quit = 'q';
    char Add = 'a';
    char Show = 's';

    for (int i = 0; i < NUM_ROWS; ++i) {

        for (int j = 0; j < NUM_AISLES; ++j) {
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
            showSeating(char seats[NUM_ROWS][NUM_AISLES]);
            showIntroScreen();
            break;
        case 'a':
            addPassenger();
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

void showSeating(char seats[NUM_ROWS][NUM_AISLES]) {

    cout << "\n Showing seating chart (0 = Open seat, X = Taken seat):\n\n";
    cout << "         ";

    for (int i = = ; i < NUM_SEATS; ++i) {


    }
    

    return;
}

