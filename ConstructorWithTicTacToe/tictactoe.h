#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe{
    private:
        char** board;
        bool x_turn;
    public:
        typedef enum{
            X_WIN,
            O_WIN,
            DRAW,
            IN_PLAY
        }tictactoe_status;
        tictactoe();
        ~tictactoe();
        tictactoe( const tictactoe& );            // Declare copy constructor.
        tictactoe& operator=(const tictactoe& other); // Declare copy assignment.
        tictactoe& operator=(int a);
        bool play(int a, int b);
        bool is_x_turn(){ return x_turn;}
        tictactoe_status status();
        void printBoard(void);
};

#endif