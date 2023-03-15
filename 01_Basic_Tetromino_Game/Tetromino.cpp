#include "Tetromino.h"
#include <iostream>
using namespace std;

void Tetromino::setTetro(){

    switch(getTetroType()){
        case Shapes::I :
                tetro = {{' ', 'I', ' '},{' ', 'I', ' '}, {' ', 'I', ' '}};
            break;
        case Shapes::O :
                //tetro = {{'O', 'O', ' '},{'O', 'O', ' '}};
                 tetro = {{' ', ' ', ' '},{'O', 'O', ' '}, {'O', 'O', ' '}};
            break;
        case Shapes::T :
                tetro = {{' ', ' ', ' '},{' ', 'T', ' '},{'T', 'T', 'T'}};
            break;
        case Shapes::J :
                tetro = {{' ', ' ', 'J'},{' ', ' ', 'J'}, {' ', 'J', 'J'}};
            break;
        case Shapes::L :
                tetro = {{'L', ' ', ' '},{'L', ' ', ' '}, {'L', 'L', ' '}};
            break;
        case Shapes::S :
                tetro = {{' ', ' ', ' '},{' ', 'S', 'S'},{'S', 'S', ' '}};
            break;
        case Shapes::Z :
                tetro = {{'Z', 'Z', ' '},{' ', 'Z', 'Z'},{' ', ' ', ' '}};
            break;

    }
}

void Tetromino::printTetro() const{
//Printing tetros
    for(int a=0; a<3 ;a++ ){
        for(int b=0; b<3;b++) cout<< tetro[a][b];
           cout <<endl;
    }
}

void Tetromino::rotate(char direction){

    int loopTimes = (direction=='R') ? 1 : 3;
    //Here if we want to rotate it left, we just have to rotate it right 3 times.

    for(int k=0; k<loopTimes; k++){
        for (int i = 0; i < 3/2; i++) {  //Code for rotating the right once
            for (int j = i; j < 2-i; j++) {
                int tmp = tetro[i][j];
                tetro[i][j] = tetro[2 - j][i];
                tetro[2 - j][i] = tetro[2 - i][2 - j];
                tetro[2 - i][2 - j] = tetro[j][2 - i];
                tetro[j][2 - i] = tmp;
            }
        }
    }
}

bool Tetromino::canFit( Tetromino &other, int position){
    bool returnValue = false;
      //Checking every condition and calling the functions by looking at the types.
    if( tetroType == Shapes::O){
        returnValue = canFitO(other);
    }
    else if(tetroType == Shapes::I){
        returnValue = canFitI(other);
    }
    else if(tetroType == Shapes::T){
        returnValue = canFitT(other);
    }
    else if(tetroType == Shapes::J){
        returnValue = canFitJ(other);
    }
    else if(tetroType == Shapes::L){
        returnValue = canFitL(other);
    }
    else if(tetroType == Shapes::S){
        returnValue = canFitS(other);
    }
    else if(tetroType == Shapes::Z){
        returnValue = canFitZ(other);
    }
    return returnValue;
}

bool Tetromino::canFitO(Tetromino &other){
    bool returnValue = true;
   // Checking every condition of every type of tetrominos which is next to O.
    switch(other.getTetroType()){
            case Shapes::Z :
                returnValue = false;
                    break;
            
            case Shapes::J :
                other.rotate('R');
                    break;

            case Shapes::T :
                other.rotate('R');
                other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::S : break;
            case Shapes::L : break;

            default: break;
        }
        return returnValue;
}

bool Tetromino::canFitI(Tetromino &other){
        bool returnValue = true;
// Checking every condition of every type of tetrominos which is next to I.
        switch(other.getTetroType()){
            case Shapes::L :
                other.rotate('L');
                    break;

            case Shapes::J :
                other.rotate('R');
                    break;

            case Shapes::T :
                other.rotate('R');
                 other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::Z : break;
            case Shapes::S : break;

            default: break;
        }
        return returnValue;
}
bool Tetromino::canFitT(Tetromino &other){
    bool returnValue = true;
// Checking every condition of every type of tetrominos which is next to T.

        switch(other.getTetroType()){
            case Shapes::Z :
                returnValue = false;
                    break;
            
            case Shapes::L :
                other.rotate('L');
                    break;
           
            case Shapes::T :
                other.rotate('R');
                 other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::S : break;
            case Shapes::J : break;

            default: break;
        }
        return returnValue;
}

bool Tetromino::canFitJ(Tetromino &other) {
    bool returnValue = true;
// Checking every condition of every type of tetrominos which is next to J.

        switch(other.getTetroType()){
            
            case Shapes::L :
                other.rotate('L');
                    break;
            
            case Shapes::T :
                other.rotate('R');
                 other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::Z : break;
            case Shapes::S : break;
            case Shapes::J : break;

            default: break;
        }
        return returnValue;
}
bool Tetromino::canFitL(Tetromino &other){
        bool returnValue = true;
// Checking every condition of every type of tetrominos which is next to L.

        switch(other.getTetroType()){
            case Shapes::Z :
                returnValue = false;
                    break;
            
            case Shapes::L :
                other.rotate('L');
                    break;
            
            case Shapes::T :
                other.rotate('R');
                 other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::J : break;
            case Shapes::S : break;

            default: break;
        }
        return returnValue;
}
bool Tetromino::canFitS(Tetromino &other){
    bool returnValue = true;
// Checking every condition of every type of tetrominos which is next to S.

        switch(other.getTetroType()){
            case Shapes::Z :
                returnValue = false;
                    break;

            case Shapes::L :
                other.rotate('L');
                    break; 

            case Shapes::T :
                other.rotate('R');
                 other.rotate('R');
                    break;

            case Shapes::O :
                returnValue = false;
                    break;

            case Shapes::I : break;
            case Shapes::J : break;
            case Shapes::S : break;

            default: break;
        }
        return returnValue;
}
bool Tetromino::canFitZ(Tetromino &other){
    bool returnValue = true;
        //In this function Z could fit to every shape if it's rotated correctly so I return true.
        switch(other.getTetroType()){
            case Shapes::L :
                other.rotate('L');
                    break;
            
            case Shapes::T :
                other.rotate('R');
                other.rotate('R');
                    break;

            case Shapes::O : break;
            case Shapes::I : break;
            case Shapes::Z : break;
            case Shapes::S : break;
            case Shapes::J : break;

            default: break;
        }
        return returnValue;
}