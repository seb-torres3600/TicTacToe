#include "board.hpp"

GameBoard:: GameBoard(int size){
    int spot = 1;
    board_size = size;
    for(int i = 0; i < size; i++){
        vector<string> tmp;
        for(int j = 0; j < size; j++){
            tmp.push_back(to_string(spot));
            spot++;
        }
        board.push_back(tmp);
    }
}

void GameBoard:: resetBoard(){
    int spot = 1;
    vector<vector<string>> temp_board;
    for(int i = 0; i < board_size; i++){
        vector<string> tmp;
        for(int j = 0; j < board_size; j++){
            tmp.push_back(to_string(spot));
            spot++;
        }
        temp_board.push_back(tmp);
    }
    board = temp_board;
}

bool GameBoard:: setTurn(Player player){
    string open_spot;
    printf("Player %d Select Your Next Locations\n", player.sign);
    printf("Select an open location: ");
    cin >> open_spot;
    for(int i = 0; i < board_size; i ++){
        for(int j = 0; j < board_size; j++){
            if(board[i][j] == open_spot){
                board[i][j] = player.character;
                return true;
                printf("\n");
            }
        }
    }
    return false;
}

bool GameBoard :: findWinnerHorizontal(){
    for(int i = 0; i  < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(board[i][j] != board[i][j+1]){
                break;
            }
            if(j == board_size - 2){
                return true;
            }
        }
    }
    return false;
}

bool GameBoard :: findWinnerVertical(){
   for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(board[j][i] != board[j+1][i]){
                break;
            }
            if(j == board_size - 2){
                return true;
            }
        }
   }
   return false;
}

bool GameBoard :: findWinnerDiagonal(){

    int diag_check = 0;
    for(int i = 0; i < board_size; i++){
        if(board[i][diag_check] != board[i+1][diag_check+1]){
            break;
        }
        if(diag_check == board_size - 2){
            return true;
        }
        diag_check++;
    }

    diag_check = board_size - 1;
    for(int i = 0; i < board_size; i++){
        if(board[i][diag_check] != board[i+1][diag_check-1]){
            break;
        }
        if(diag_check + 2 == board_size){
            return true;
        }
        diag_check--;
    }
    return false;
}

bool GameBoard :: findWinner(){
    return findWinnerDiagonal() || findWinnerHorizontal() || findWinnerVertical();
}

void GameBoard:: printBoard(){
    printf("-------------\n");
    for(int i = 0; i < board_size; i++){
        printf("   ");
        for(int j = 0; j < board_size; j++){
            if (j != 0 && j != board_size){
                cout << "|";
            }
            cout << board[i][j];
        }
        if(i != board_size - 1){
            printf("\n");
            for(int z = 0; z < board_size*3; z++){
                if(z < board_size){
                    printf(" ");
                } else if(z <= board_size * 2 + 1){
                    printf("-");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("-------------\n");
}