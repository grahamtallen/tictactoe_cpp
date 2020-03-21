#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int const boardSize = 10;

class Space {
public:
    string value;
    int x;
    int y;

    Space(int arg_x, int arg_y);

    void setValue(string val);

    bool spaceAvailable();

};

class GameBoard {
    vector < vector<Space> > board_matrix;

    void initializeSpacesInBoard();

public:
    GameBoard();

    string setValue(const int x, const int y, string newValue);

    bool spaceAvailable(const int x, const int y);

    bool displayGameState();
};

