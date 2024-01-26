#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "player.hpp"

using namespace std;

class GameBoard{
    public:
        GameBoard(int size);
        bool setTurn(Player player);
        void printBoard();
        bool findWinnerDiagonal();
        bool findWinnerHorizontal();
        bool findWinnerVertical();
        bool findWinner();
        void resetBoard();
    private:
        vector<vector<string>> board;
        int board_size;
};

#endif