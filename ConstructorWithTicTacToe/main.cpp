#include <iostream>
#include "tictactoe.h"
#include <string>
int main(void){
    #ifdef CPP_CONSTRUCTOR_EXAMPLE
    tictactoe game1;
    game1.play(2,2);
    tictactoe game2 = game1;
    tictactoe game3;
    game3 = game2;


    #else
    tictactoe game1;
    while(game1.status()==tictactoe::IN_PLAY){
        int input;
        game1.printBoard();
        std::string turn = (game1.is_x_turn())?"X":"O";
        std::cout << "Enter Your Move From 1-9. It is " << turn << "s turn" << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        if(!game1.play((input-1)/3+1, (input-1)%3+1)){
            std::cout<< "Invalid Move\n";
        }
    }
    
    game1.printBoard();
    switch (game1.status())
    {
    case tictactoe::IN_PLAY:
        std::cout << "Something Goofed up" << std::endl;
        break;
    case tictactoe::X_WIN:
        std::cout << "X Wins" << std::endl;
        break;
    case tictactoe::O_WIN:
        std::cout << "O Wins" << std::endl;
        break;
    case tictactoe::DRAW:
        std::cout << "It's a draw" << std::endl;
        break;
    
    default:
        break;
    }
    return 0;
    #endif
    #ifdef CPP_CONSTRUCTOR_EXAMPLE

    #endif

}