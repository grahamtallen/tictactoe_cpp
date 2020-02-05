#pragma once
#include "board.hpp"
#include <iostream>
using namespace std;

void playerTurn(GameBoard game_board, const string player1Letter, const string player2Letter) {
    int x_coordinate;
    int y_coordinate;
    bool confirm;
    string response;
    cout << "Player \"" << player1Letter << "\", where would you like to move?" << endl;
    cout << "X coordinate:";
    cin >> x_coordinate;
    cout << endl;

    cout << "Y coordinate:";
    cin >> y_coordinate;
    cout << endl;
    bool spaceIsAvailable = game_board.spaceAvailable(x_coordinate, y_coordinate);
    if (!spaceIsAvailable) {
        cout << "That space is already taken, try again." << endl << endl;
        playerTurn(game_board, player1Letter, player2Letter);
        return;
    }
    cout << "Confirm x: " << x_coordinate << " y: " << y_coordinate << " [y/n]" << endl;

    cin >> response;
    confirm = response == "y";
    cout << endl;

    if (confirm) {
        game_board.setValue(x_coordinate, y_coordinate, player1Letter);
        bool win = game_board.displayGameState();
        if (!win) {
            // next player's turn
            playerTurn(game_board, player2Letter, player1Letter);
        } else {
            cout << " Game Over! Thanks for playing!" << endl;
        }
    } else {
        // try again
        playerTurn(game_board, player1Letter, player2Letter);

    }
    

}