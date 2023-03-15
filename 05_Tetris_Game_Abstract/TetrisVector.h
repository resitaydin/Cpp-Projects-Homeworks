#ifndef TETRISVECTOR_H
#define TETRISVECTOR_H

#include <vector>
#include "AbstractTetris.h"

namespace tetrisVector{


class TetrisVector: public AbstractTetris

{
    public:

        TetrisVector(); //no param constr.
        TetrisVector(int r, int c); 
        void draw() const override;
        void readFromFile(string filename) override;
        void writeToFile(string filename) override ;
        AbstractTetris& operator+=(const Tetromino& tetro) override;
        void animate() override;
        void move();
        void rotate();
        int getLoc() const{ return loc;}

        ~TetrisVector(){  }; //Intentionally left blank.

    private:
        vector<vector<char>> board;
        int loc; // location of tetro object.
};

}

#endif