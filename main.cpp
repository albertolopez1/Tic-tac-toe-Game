//Programmed by: Lopez, Alberto
//Program name: Laboratory Practice Final
//Last edited: 05 – 14 – 2023
//Class: EGR – 123 – 002

#include <iostream>
#include <fstream>

using namespace std;

string player1;
string player2;
int i = 0;
char board[3][3] = {{'1', '2', '3'}, { '4', '5', '6'}, {'7', '8', '9'}};
int choice;
int r;
int c;
int turn = 'X';
bool draw = false;

void registerPlayers() {
    cout << "Enter player 1: ";
    cin >> player1;
    
    cout << "Enter player 2: ";
    cin >> player2;
    i++;
    cout << "\n";
}

void boardLayout() {
    cout << "Tic Tac Toe Game" << endl << "\n";
    cout << "    |   |    " << endl;
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "____|___|____" << endl;
    cout << "    |   |    " << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "____|___|____" << endl;
    cout << "    |   |    " << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "    |   |    " << endl << "\n";
}

void players() {
    if(turn == 'X') {
        cout << player1 << "'s turn: ";
    }
    else if(turn == 'O') {
        cout << player2 << "'s turn: ";
    }
    
    cin >> choice;
    switch(choice) {
        case 1: {
            r = 0;
            c = 0;
        } break;
        case 2: {
            r = 0;
            c = 1;
        } break;
        case 3: {
            r = 0;
            c = 2;
        } break;
        case 4: {
            r = 1;
            c = 0;
        } break;
        case 5: {
            r = 1;
            c = 1;
        } break;
        case 6: {
            r = 1;
            c = 2;
        } break;
        case 7: {
            r = 2;
            c = 0;
        } break;
        case 8: {
            r = 2;
            c = 1;
        } break;
        case 9: {
            r = 2;
            c = 2;
        } break;
        default: {
            cout << "Error. Invalid input." << endl << "\n";
        }
    }
    
    if(turn == 'X' && board[r][c] != 'X' && board[r][c] != 'O') {
        board[r][c] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[r][c] != 'X' && board[r][c] != 'O') {
        board[r][c] = 'O';
        turn = 'X';
    }
    else {
        cout << "Error. Number has already been chosen. Try again." << endl << "\n";
        players();
    }
    boardLayout();
}

bool status() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return false;
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

void p1() {
    registerPlayers();
    boardLayout();
    players();
    char choice;
    
    while(status()) {
        boardLayout();
        players();
        status();
    }
    if(turn == 'X' && draw == false) {
        cout << player2 << " has won!" << endl;
        cout << "Wins: " << i << endl;
        
        ofstream exFile;
        exFile.open(player2);
        exFile << "Name: " << player2 << endl;
        exFile << "Wins: " << i << endl;
        exFile.close();
    }
    else if(turn == 'O' && draw == false) {
        cout << player1 << " has won!" << endl;
        cout << "Wins: " << i << endl;
        
        ofstream exFile;
        exFile.open(player1);
        exFile << "Name: " << player1 << endl;
        exFile << "Wins: " << i << endl;
        exFile.close();
    }
    else if(draw == true) {
        cout << "Draw, no one won." << endl;;
    }
    do {
        cout << "Would you like to play again? (y/n): ";
        cin >> choice;
    } while(choice != 'n');
}

int main() {
    p1();
    
    return 0;
}