/****************************************************************************************
*                                                                                       *
*	Title:   CS11 Tic Tac Toe Game                                                      *
*	Author:  Ayaan Padinharkkara                                                        *
*	Date:    06/11/2025                                                                 *
*	Purpose: This program allows two players to play a game of Tic Tac Toe.             *
*            It uses a 2D array to represent the game board, checks for valid moves,    *
*            handles user input errors, and supports replaying the game after it ends.  *
*                                                                                       *
*****************************************************************************************/

#include <iostream>     // for input and output (cin, cout)
#include <limits>       // for clearing invalid input using numeric_limits

using namespace std;

// Function declarations (so the compiler knows about all functions before main)
void showIntroScreen();                         // Shows welcome message
void displayBoard(char board[3][3]);            // Displays the current Tic Tac Toe board
void getPlayerMove(char board[3][3], char player); // Gets and validates a move from a player
bool isValidMove(char board[3][3], int move);   // Checks if a move is allowed
bool checkWin(char board[3][3], char player);   // Checks if the current player has won
bool checkTie(char board[3][3]);                // Checks if the game is a tie
void resetBoard(char board[3][3]);              // Resets the board for a new game

int main() {
    // The game board using a 2D char array
    char board[3][3];

    char currentPlayer;     // Tracks the current player ('X' or 'O')
    bool gameOver;          // True when a win or tie is detected
    char playAgain;         // Tracks if players want to play again

    showIntroScreen();      // Display the welcome screen

    do {
        resetBoard(board);     // Initialize the board with positions 1 to 9
        currentPlayer = 'X';   // X always goes first
        gameOver = false;      // Start a new round

        // Main game loop
        while (!gameOver) {
            displayBoard(board);               // Show the board
            getPlayerMove(board, currentPlayer); // Prompt player for their move

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;
            }
            // Check if the game is a tie
            else if (checkTie(board)) {
                displayBoard(board);
                cout << "It's a tie! Well played both players.\n";
                gameOver = true;
            }
            // Switch to the next player
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Ask if the users want to replay
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover input

    } while (playAgain == 'y' || playAgain == 'Y'); // Repeat if user types 'y' or 'Y'

    cout << "Thanks for playing Tic Tac Toe!\n"; // Exit message
    return 0;
}

/**
 * Function: showIntroScreen
 * Purpose : Displays a stylized welcome message for the user.
 */
void showIntroScreen() {
    cout << "\n##########################################################\n";
    cout << "#                                                        #\n";
    cout << "#            WELCOME TO TIC TAC TOE IN C++               #\n";
    cout << "#                                                        #\n";
    cout << "##########################################################\n\n";
}

/**
 * Function: resetBoard
 * Purpose : Fills the board with numbers 1 to 9 for a new game.
 * Input   : board - the game board
 */
void resetBoard(char board[3][3]) {
    char num = '1'; // Start with '1'
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = num++; // Fill each cell with increasing digits
}

/**
 * Function: displayBoard
 * Purpose : Outputs the current board to the screen in a grid format.
 * Input   : board - the game board
 */
void displayBoard(char board[3][3]) {
    cout << "\nCurrent Board:\n\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];          // Print the cell
            if (j < 2) cout << " | ";     // Add vertical dividers
        }
        if (i < 2)
            cout << "\n-----------\n";     // Add horizontal dividers
    }
    cout << "\n\n";
}

/**
 * Function: getPlayerMove
 * Purpose : Prompts the player for a move and updates the board if valid.
 * Input   : board - the game board
 *           player - current player ('X' or 'O')
 */
void getPlayerMove(char board[3][3], char player) {
    int move;
    bool valid = false;

    while (!valid) {
        cout << "Player " << player << ", enter your move (1-9): ";

        // Check if the input is a valid number
        if (!(cin >> move)) {
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            continue;
        }

        // Check if the move is allowed (valid number and not already taken)
        if (isValidMove(board, move)) {
            int row = (move - 1) / 3; // Row index (0–2)
            int col = (move - 1) % 3; // Column index (0–2)
            board[row][col] = player; // Place the player's mark
            valid = true;
        }
        else {
            cout << "Invalid move! That square is taken or out of range.\n";
        }
    }
}

/**
 * Function: isValidMove
 * Purpose : Returns true if the move is within bounds and on an empty space.
 * Input   : board - the game board
 *           move - the move number entered by the user (1-9)
 */
bool isValidMove(char board[3][3], int move) {
    if (move < 1 || move > 9)
        return false;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    // If cell is already marked by 'X' or 'O', it's not valid
    return board[row][col] != 'X' && board[row][col] != 'O';
}

/**
 * Function: checkWin
 * Purpose : Checks all win conditions for the current player.
 * Input   : board - the game board
 *           player - current player ('X' or 'O')
 */
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

/**
 * Function: checkTie
 * Purpose : Returns true if all cells are filled and no one has won.
 * Input   : board - the game board
 */
bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // Found an empty spot

    return true; // No empty spots and no winner = tie
}