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

};

class GameBoard {
    vector<vector<Space> > board_matrix;


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

    vector<Space> getXColumn(const int x) {
        // if (x > (board_matrix.size() - 1)) {
        //     throw std::out_of_range
        // } 
        return board_matrix[x];
    }

public:
    GameBoard() {
        initializeSpacesInBoard();
    }

    string setValue(const int x, const int y, string newValue) {
        vector<Space> column = getXColumn(x);
        Space row = column[y];
        row.value = newValue;
        cout << "New Value: " << " x: " << "y: " << y << " val: " << row.value;
        return row.value;
    }

    void displayGameState() {
        const int x_size = board_matrix.size();
        bool top;
        bool bottom;
        bool left;
        bool right;
        cout << "TTTT Current Game State TTTT" << endl << endl;

        for (int x = 0; x < x_size; x++) {

            vector<Space> column = board_matrix[x];
            top = x == 0;
            bottom = x == (x_size - 1);

            if (top) {
                // for (int i = 0; i < x_size; i++) {
                // }
            }
            const int y_size = column.size();
            for (int y = 0; y < y_size; y++) {
                // cout << "x:" << x;
                // cout << "y:" << y;
                left = y == 0;
                right= y == (y_size - 1);
                string value;
                // if (!column[y]) {
                    value = column[y].value;
                // } else {
                    // value = "*";
                // }

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
            // if (bottom) {
            //     for (int i = 0; i < x_size; i++) {
            //         cout << "_______________";
            //     }
            // }
        }
        cout << " _________" << endl << endl;

    }
};

