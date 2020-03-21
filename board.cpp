#include <vector>
#include <string>
#include <iostream>
#include "board.hpp"
using namespace std;

Space::Space(int arg_x, int arg_y) : x(arg_x), y(arg_y) {
    value = "*";
}

void Space::setValue(string val) {
        value = val;
};

bool Space::spaceAvailable() {
    return value == "*";
}


void GameBoard::initializeSpacesInBoard() {
    for (int x = 0; x < boardSize; x++) {
        vector<Space> column;
        for (int y = 0; y < boardSize; y++) {
            Space newSpace(x, y);
            column.push_back(newSpace);
        }
        board_matrix.push_back(column);
    }
}

GameBoard::GameBoard() {
    initializeSpacesInBoard();
}

string GameBoard::setValue(const int x, const int y, string newValue) {
    board_matrix[x][y].setValue(newValue);
    return board_matrix[x][y].value;
}

bool GameBoard::spaceAvailable(const int x, const int y) {
        return board_matrix[x][y].spaceAvailable();
}

bool GameBoard::displayGameState() {
    bool top;
    bool bottom;
    bool left;
    bool right;
    cout << "---- Tic Tac Toe ----" << endl << endl;

    const int x_size = board_matrix.size();

    for (int x = 0; x < x_size; x++) {

        vector<Space> column = board_matrix[x];
        top = x == 0;
        bottom = x == (x_size - 1);

        const int y_size = column.size();
        for (int y = 0; y < y_size; y++) {
            // cout << "x:" << x << endl;
            // cout << "y:" << y << endl;
            
            string value;
            if (column[y].value != "*") {
                value = column[y].value;
            } else {
                value = to_string(x) + to_string(y);
            }
            
            left = y == 0;
            right= y == (y_size - 1);

            if (left) { 
                cout << "|" << value;
            }
            if (right) {
                cout << value << "|";
            } 
            if (!right && !left) {
                cout << "|" << value << "|";
            }
        }
        cout << endl;   

    }
    return false;
    

}

