#include <iostream>

#include "tetromino.h"

using namespace std;


Tetromino::Tetromino(Shp shape){

    setTetroType(shape);

    switch(getTetroType()){
        case Shp::I :
            r= 1, c=4;
            createArr(); //Creating objects.
            tetro[0][0] = 'I', tetro[0][1] = 'I', tetro[0][2] = 'I', tetro[0][3] = 'I';
            break;
        case Shp::O :
            r=2, c=2;
            createArr();
            tetro[0][0] = 'O', tetro[0][1] = 'O', tetro[1][0] = 'O', tetro[1][1] = 'O';
            break;
        case Shp::T :
            r=2, c=3;
            createArr();
            tetro[0][1] = 'T', tetro[1][0] = 'T', tetro[1][1] = 'T', tetro[1][2] = 'T';
            break;
        case Shp::J :
            r=3, c=2;
            createArr();
            tetro[0][1] = 'J', tetro[1][1] = 'J', tetro[2][0] = 'J', tetro[2][1] = 'J';
            break;
        case Shp::L :
            r=3, c=2;
            createArr(); //Creating objects.
            tetro[0][0] = 'L', tetro[1][0] = 'L', tetro[2][0] = 'L', tetro[2][1] = 'L';
            break;
        case Shp::S :
            r=2, c=3;
            createArr();
            tetro[0][1] = 'S', tetro[0][2] = 'S', tetro[1][0] = 'S', tetro[1][1] = 'S';
            break;
        case Shp::Z :
            r=2, c=3;
            createArr();
            tetro[0][0] = 'Z', tetro[0][1] = 'Z', tetro[1][1] = 'Z', tetro[1][2] = 'Z';
            break;
        default:
            break;
    }
}


void Tetromino::createArr(){  //Creating tetro array dynamically.
    tetro = new char* [getRow()];
    for(int i=0; i<getRow(); ++i){
        *(tetro+i) = new char[getColumn()];
    }

    for(int i=0; i<getRow(); ++i){
        for(int j=0; j<getColumn(); ++j){
            tetro[i][j] = ' ';
        }
    }
}

Tetromino::Tetromino() : Tetromino(Shp::O){
  //Intentionally left blank.
}

void Tetromino::rotate(char direction){


    int newColumn, newRow = 0;

    char **temp=new char*[getColumn()]; 
    for(int i=0;i<getColumn() ;i++){
        temp[i]=new char[getRow()];
    }

    if(direction=='L'){ 
        for (int oldColumn = getColumn() - 1; oldColumn >= 0; oldColumn--)
        {  
            newColumn = 0;
            for (int oldRow = 0; oldRow < getRow(); oldRow++) //Rotating the object left.
            {
                temp[newRow][newColumn] = tetro[oldRow] [oldColumn];
                newColumn++;
            }
            newRow++;
        }
    }
   

    else{ 
        for (int oldColumn = 0; oldColumn<getColumn(); oldColumn++)//Rotating the object right.
        {
            newColumn = 0;
            for (int oldRow = getRow()-1; oldRow >= 0; oldRow--)
            {
                temp[newRow][newColumn] = tetro[oldRow] [oldColumn];
                newColumn++;
            }
            newRow++;
        }
    }

    for(int i=0;i<getRow();i++){
        delete[] tetro[i]; //deleting tetro.
    }
    delete [] tetro;

    tetro=new char*[getColumn()];
    for(int i=0;i<getColumn();i++){
        tetro[i]=new char[getRow()];
    }

    for(int i=0;i<getColumn();i++){ //tetro=temp;
        for(int j=0;j<getRow();j++){
            tetro[i][j]=temp[i][j];
        }
    }

    for(int i=0;i<getColumn();i++){
        delete[] temp[i];   //Deleting temp for avoiding memory leak.
    }
    delete [] temp;

    r = newRow;
    c = newColumn;

}

void Tetromino::printTetro(){
    for(int i=0; i<getRow(); ++i){
        for(int j=0; j<getColumn(); ++j){  //Printing.
            cout<< tetro[i][j]<< ' ';
        }
        cout<<endl;
    }
}

Tetromino:: ~Tetromino(){    //Destructor
    for(int i=0; i<getRow(); i++){
        delete [] tetro[i];
    }
    delete [] tetro;
}

Tetromino& Tetromino::operator=(const Tetromino& tetrObj){  //Overloaded = operator for assigning any tetromino object to any other tetromino object properly.

    for(int i=0; i<getRow(); i++){
        delete [] tetro[i];
    }
    delete [] tetro;

    tetro=new char*[tetrObj.getRow()];
    for(int i=0;i<tetrObj.getRow();i++){
        tetro[i]=new char[tetrObj.getColumn()];
    }

    r = tetrObj.getRow();
    c = tetrObj.getColumn();

    for(int i=0; i<getRow(); ++i){
        for(int j=0; j<getColumn(); ++j){
            tetro[i][j] = tetrObj.tetro[i][j];   
        }
    }

    setTetroType(tetrObj.getTetroType());

    return *this;
}  // This CAUSES SEG. FAULT!!!