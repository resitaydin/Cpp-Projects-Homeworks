#ifndef TETRIS_ARRAY_H
#define TETRIS_ARRAY_H


#include "AbstractTetris.h"

namespace tetrisArray1D{

class TetrisArray1D: public AbstractTetris{

    public:

        TetrisArray1D(); //no param constr.
        TetrisArray1D(int r, int c);
        void draw() const override;
        void readFromFile(string filename) override;
        void writeToFile(string filename) override ;
        AbstractTetris& operator+=(const Tetromino& tetro) override;
        void animate() override;
        void move();
        void rotate();
        int getLoc() const{ return loc;}

        ~TetrisArray1D(); //Intentionally left blank.

    private:
        char* board;
        int loc; // location of tetro object.
};

}

#endif