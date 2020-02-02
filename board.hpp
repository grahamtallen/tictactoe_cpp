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
        value = "foo";
    }

    void setValue(string val) {
        value = val;
    };

};

class GameBoard {
    vector<vector<Space> > board;


    void setSpacesInBoard() {
        for (int x = 0; x < boardSize; x++) {
            vector<Space> column;
            for (int y = 0; y < boardSize; y++) {
                Space newSpace(x, y);
            }
        }
    }

public:
    GameBoard() {
        setSpacesInBoard();
    }

    void displayGameState() {
        for (int x = 0; x < boardSize; x++) {
            vector<Space> column = board[x];
            cout << "Board:" << board.size();
            // for (int y = 0; y < boardSize; y++) {
            //     cout << "|" << column[y].value << "|" << endl;
            // }
        }
    }
};

