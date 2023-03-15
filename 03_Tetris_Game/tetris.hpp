#ifndef TETRIS
#define TETRIS

#include "tetromino.hpp"

    class Tetris{

        public:
            Tetris();
            Tetris(int, int );

            int getR() const{return r;};
            int getC() const{return c;};
            Shp getShp() const{ return shp;};

            void createTetro(Shp shape);
            void printMap() const;
            void clearMap();
            void moveTetro(char, int);
            void animate();
            
            Tetris& operator+=(const Tetromino&); //overloaded.

            ~Tetris();  //dest.

        private:
            Shp shp;
            int r, c;
            char** map;
            Tetromino tetromino;
    };


#endif
