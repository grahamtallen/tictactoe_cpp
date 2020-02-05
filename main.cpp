#include "board.hpp"
#include "ui.hpp"
#include <iostream>
using namespace std;


int main() {
    GameBoard game_board;

    game_board.setValue(0, 0, "X");
    game_board.setValue(0, 1, "X");
    game_board.displayGameState();

    playerTurn(game_board, "X", "O");


}