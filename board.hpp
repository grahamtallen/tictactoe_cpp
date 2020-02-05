#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int const boardSize = 3;

class Space {
public:
    string value;
    int x;
    int y;

    Space(int arg_x, int arg_y) : x(arg_x), y(arg_y) {
        value = "*";
    }

    void setValue(string val) {
        value = val;
    };

    bool spaceAvailable() {
        return value == "*";
    }

};

class GameBoard {
    vector < vector<Space> > board_matrix;

    void initializeSpacesInBoard() {
        for (int x = 0; x < boardSize; x++) {
            vector<Space> column;
            for (int y = 0; y < boardSize; y++) {
                Space newSpace(x, y);
                column.push_back(newSpace);
            }
            board_matrix.push_back(column);
        }
    }

public:
    GameBoard() {
        initializeSpacesInBoard();
    }

    string setValue(const int x, const int y, string newValue) {
        board_matrix[x][y].setValue(newValue);
        return board_matrix[x][y].value;
    }

    bool spaceAvailable(const int x, const int y) {
         return board_matrix[x][y].spaceAvailable();
    }

    bool displayGameState() {
        bool top;
        bool bottom;
        bool left;
        bool right;
        cout << "---- Current Game State ----" << endl << endl;

        const int x_size = board_matrix.size();
        bool possible_win_ycol = false;

        for (int x = 0; x < x_size; x++) {

            vector<Space> column = board_matrix[x];
            top = x == 0;
            bottom = x == (x_size - 1);

            const int y_size = column.size();
            string lastValue_ycol;
            for (int y = 0; y < y_size; y++) {
                // cout << "x:" << x << endl;
                // cout << "y:" << y << endl;
                
                string value;
                value = column[y].value;
                if (y == 0 && value != "*") {
                    lastValue_ycol = value;
                } else {
                    if (lastValue_ycol == value) {
                        possible_win_ycol = true;
                    } else {
                        possible_win_ycol = false;
                    }
                }
                // cout << "value: " << column[y].value << endl;
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
        if (possible_win_ycol) {
                cout << "Win on y column!";
                return true;
        } else {
            return false;
        }
        
        cout << " _________" << endl << endl;

    }
};

