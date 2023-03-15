#ifndef TETRIS_ADAPTER_H
#define TETRIS_ADAPTER_H

#include "AbstractTetris.h"

namespace tetrisAdapter{

template <class T>

class TetrisAdapter : public AbstractTetris {
    
    public:
        TetrisAdapter(); //no param constr.
        TetrisAdapter(int r, int c);
        void draw() const override;

        void readFromFile(string filename) override;
        void writeToFile(string filename) override;
        AbstractTetris& operator+=(const Tetromino& tetro) override;
        void animate() override;
        void move();
        void rotate();
        int getLoc() const{ return loc;}

        ~TetrisAdapter(){ } //Intentionally left blank.

    private:
        T board;
        int loc; // location of tetro object.

};

}

#endif