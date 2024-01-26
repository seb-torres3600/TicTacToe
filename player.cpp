#include "player.hpp"

Player :: Player(int s){
    wins = 0;
    sign = s;
    if(sign == 0){
        character = 'X';
    }
    else{
        character = 'O';
    }
}

