#include <iostream>
#include <algorithm>
#include <string>
#include "player.hpp"
#include "board.hpp"

using namespace std;

int main(){
    int board_size = 3;
    GameBoard b(board_size);
    // Make players
    Player p1(0);
    Player p2(1);
    // Make player vector
    vector<Player> players;
    players.push_back(p1);
    players.push_back(p2);
    // max turns
    int max = board_size * board_size;
    int iter = 0;
    string cont = "";
    while(1){
        printf(" TIC TAC TOE \n");
        printf("-------------\n");
        printf("  Game Stats \n");
        printf("-------------\n");
        printf("P1: %d  P2: %d \n", players.at(0).wins, players.at(1).wins);
        printf("-------------\n");
        bool game = true;
        while(game){
            // No winner, board is filled
            if(iter == max-1){
                printf("No winner");
                b.resetBoard();
                game = false;
                break;
            }
            for(int i = 0; i < 2; i++){
                b.printBoard();
                // Make sure they pick a valid location
                while(!b.setTurn(players.at(i))){
                    printf("Location Occupied, pick another\n");
                    b.printBoard();
                }
                if(b.findWinner()){
                    b.printBoard();
                    printf("Player %d won\n", players.at(i).sign);
                    printf("-------------\n");
                    printf("Would you like to play again? [Yes, No] \n");
                    cin >> cont;
                    transform(cont.begin(), cont.end(), cont.begin(), ::toupper);
                    if(cont == "NO"){
                        return 0;
                    }
                    players.at(i).wins++;
                    b.resetBoard();
                    game = false;
                    break;
                }
            }
        }
    }
}

