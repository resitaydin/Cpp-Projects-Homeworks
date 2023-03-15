#include "tetris.hpp"

#include <iostream>
#include <unistd.h>


Tetris::Tetris(int row, int column){

    r = row;
    c = column;

    map = new char* [row];   //Creating map dynamically.

    for(int i=0; i<row; ++i){
        *(map+i) = new char[column];
    }

    for(int i=0; i<getR(); i++){
        for(int j=0; j<getC(); j++){
            map[i][j] = ' ';
        }
    }
}

Tetris::Tetris() : Tetris(20,20){ //I set row and column default as 20.
    //Intentionally left blank.
}

void Tetris::printMap() const{
    for(int i=0; i<getC(); ++i) std::cout<<"#";
    std::cout<<'\n';

    for(int i=0; i<getR(); ++i){
        for(int j=0; j<getC(); ++j){
            std::cout<< map[i][j];   //Printing map.
        }
        std::cout<<"\n";
    }
    std::cout<<'\n';

    for(int i=0; i<getC(); ++i) std::cout<<"#";
    std::cout<<'\n';

}

Tetris& Tetris::operator+=(const Tetromino& tetro){

    tetromino = tetro; // Assigning our private object to tetro object using overloaded = operator.

    int midPoint=(getC()/2)-1;

    for(int i=0;i<tetro.getRow();i++){
        for(int j=0;j<tetro.getColumn(); j++){
            map[i][j+midPoint]=tetro.getTetro()[i][j];  //Adding tetro to the map.
        }
    }

    return *this;
}

void Tetris::clearMap(){
    int midPoint=(getC()/2)-1;
    for(int i=0; i<getR(); ++i){
        for(int j=0; j<getC(); ++j){
            map[i][j+midPoint]=' ';
        }
    }
}

void Tetris::moveTetro(char mD, int mC){
    if(mD=='L') mC = -mC; //if we move it to left, we just decrease its x property.

    int mid=(getC()/2)-1;

    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            map[i][j+mid]=' ';  //Clearing the map where object used to be.
        }
    }

    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            map[i][j+mid+mC]=tetromino.getTetro()[i][j];
        }
    }
    tetromino.setLoc(mid+mC);
}

void Tetris::animate(){
    int lower=1;

while(lower< getR() - tetromino.getRow()+1){
    std::cout<<"\x1B[2J\x1B[H";  //To move cursor top left.
    usleep(500000);   //Sleeping a little bit to see the screen.

    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            map[i+lower-1][j+tetromino.getLoc()]=' ';
        }
    }
    
    for(int i=0;i<tetromino.getRow();i++){
        for(int j=0;j<tetromino.getColumn(); j++){
            map[i+lower][j+tetromino.getLoc()]= tetromino.getTetro()[i][j];
        }
    }
    
    printMap();
 
    lower++;
}
}

Tetris:: ~Tetris(){    //Destructor
    for(int i=0; i<getR(); i++){
        delete [] map[i];
    }
    delete [] map;
}