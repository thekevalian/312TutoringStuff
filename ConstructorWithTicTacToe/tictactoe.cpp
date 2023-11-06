#include "tictactoe.h"
#include <iostream>
tictactoe::tictactoe(){
    #ifdef CPP_CONSTRUCTOR_EXAMPLE
    std::cout << "Constructor Called\n";
    #endif
    board = new char*[3];
    for(int i = 0; i< 3; i++){board[i]=new char[3];}
    for(int i =0 ; i<3; i++){
        for(int j = 0; j< 3; j++){
            board[i][j] = ' ';
        }
    }
    x_turn = true;
}

tictactoe::~tictactoe(){
    #ifdef CPP_CONSTRUCTOR_EXAMPLE
    std::cout << "Destructor Called\n";
    #endif
    for(int i =0 ; i< 3; i++){
        delete [] board[i];
    }
    delete [] board;
}

tictactoe::tictactoe(const tictactoe& other){ // copy constructor
    #ifdef CPP_CONSTRUCTOR_EXAMPLE
    std::cout << "Copy Constructor Called\n";
    #endif
    x_turn = other.x_turn;
    board = new char*[3];
    for(int i = 0; i< 3; i++){board[i]=new char[3];}
    for(int i =0 ; i<3; i++){
        for(int j = 0; j< 3; j++){
            board[i][j] = other.board[i][j];
        }
    }
}


tictactoe& tictactoe::operator=(const tictactoe& other){
    #ifdef CPP_CONSTRUCTOR_EXAMPLE
    std::cout << "Copy Assignment Operator\n";
    #endif
    for(int i =0 ; i< 3; i++){
        delete [] board[i];
    }
    delete [] board;
    x_turn = other.x_turn;
    board = new char*[3];
    for(int i = 0; i< 3; i++){board[i]=new char[3];}
    for(int i =0 ; i<3; i++){
        for(int j = 0; j< 3; j++){
            board[i][j] = other.board[i][j];
        }
    }


    return *this;
}

bool tictactoe::play(int a, int b){
    if(a <=0 || a >= 4) return false;
    if(b <=0 || b >= 4) return false;
    if(board[a-1][b-1]!= ' ') return false;
    board[a-1][b-1] = (x_turn)?'X':'O';
    x_turn = !x_turn;
    return true;
}

void tictactoe::printBoard(void){
    std::cout <<std::endl;
    for( int i = 0; i< 3; i++){
        std::cout<<" ";
        for (int j = 0; j< 3 ; j++){
            std::cout<< board[i][j];
            if(j!=2)std::cout << " | ";
        }
        std::cout << std::endl;
        if(i!=2)std::cout<< "-----------"<<std::endl;
    }
}

tictactoe::tictactoe_status tictactoe::status(){
    int open_slots = 0;
    for(int i = 0; i< 3; i++){
        for(int j = 0; j< 3; j++){
            if(board[i][j]==' ') open_slots++;
            if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O') return O_WIN;
            if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X') return X_WIN;
        }
        if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O') return O_WIN;
        if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X') return X_WIN;
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')return X_WIN;
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')return O_WIN;
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')return X_WIN;
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')return O_WIN;
    return (open_slots>0)?IN_PLAY:DRAW;
}
