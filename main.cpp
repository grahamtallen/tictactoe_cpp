#include "board.hpp"

int main() {
    GameBoard game_board;

    game_board.setValue(0, 1, "X");
    game_board.setValue(2, 2, "0");

    game_board.displayGameState();

}