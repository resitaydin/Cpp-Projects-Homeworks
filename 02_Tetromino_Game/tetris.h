#ifndef TETRIS_H
#define TETRIS_H

#include "Tetromino.h"

class Tetris{

    public:
        Tetris(int rowInput,int columnInput); //Constructor to create map with row and column size.
        void setRowColumn(int r, int c);
        void draw() const ;
        void initMap();
        Shapes getTetroType()const {return tetroShape;};
        void setTetroType(Shapes input){tetroShape=input;}
        void addTetro(Tetromino &tetro);
        void BestFit(Tetromino &tetro);

        vector<vector<char>>& getMap() {return map;}; //We're going to change map through this function.
        Tetromino getTetro()const {return tetro;};

    private:
        int rowSize;
        int columnSize;
        vector<vector<char>> map; 
        Shapes tetroShape;    //Shape object
        Tetromino tetro; //Creating Tetromino object using the composition.
};
#endif