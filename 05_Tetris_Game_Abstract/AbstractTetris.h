#ifndef ABSTRACT_TETRIS_H
#define ABSTRACT_TETRIS_H

#include <iostream>
#include <fstream>

using namespace std;

#include "tetromino.h"


class AbstractTetris{

    public:

        AbstractTetris(){}; //no param constr.
        AbstractTetris(int r, int c){ row= r; column= c;} // just in case(might not be used.)
        virtual void draw() const = 0;
        virtual void readFromFile(string filename) = 0;
        virtual void writeToFile(string filename) = 0 ;
        virtual AbstractTetris& operator+=(const Tetromino& tetro) = 0;
        virtual void animate() = 0;

        static int numberOfMoves() { return numberOfMoves_;};
        pair<char,int> lastMove() const { if(lastMove_.first==0 && lastMove_.second==0) throw invalid_argument("No last move!\n"); else return lastMove_;};
        Tetromino getTetro() const{ return tetrom; };
        virtual ~AbstractTetris(){ }; //Intentionally left blank.
        bool gameIsOver() const { return GameOver;}

        int getR() const{ return row;}
        int getC() const{ return column;}

    protected: 
        static int numberOfMoves_;
        int row;
        int column;
        Tetromino tetrom; 
        pair<char,int> lastMove_; // pair char,int for last move
        bool GameOver;
};

#endif