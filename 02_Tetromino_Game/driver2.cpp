#include <iostream>
#include "tetris.h"

using namespace std;

int main(){

    int rowSize,columnSize;
    vector<Shapes> shape_arr= {Shapes::I,Shapes::O,Shapes::T,Shapes::J,Shapes::L,Shapes::S,Shapes::Z}; //random array.
    srand(time(NULL));

    cout<<"Enter the row size of the tetris board: ";
    cin>> rowSize;
    cout<<"Enter the column size of the tetris board: ";
    cin>> columnSize;
    Tetris tetris(rowSize,columnSize);  //Creating tetris object using the inputs.

    char input;
    while(1){
        cout<<"Enter the tetromino type(I, O, T, J, L, S, Z) (enter R for random and Q for quit):  ";
        cin>> input;

    Shapes shape = static_cast<Shapes> (input);  //Casting input into shape object.

    if(input== 'Q') {cout<< "Quitting the game.... \n"; exit(1);};
    if(input=='R'){
        shape = static_cast<Shapes> (shape_arr[rand()%7]);
    }
    
    tetris.setTetroType(shape);
    Tetromino tetro(shape);  //Creating tetromino object using shape input.
      
    tetris.initMap();
    tetris.addTetro(tetro);  
    }  

    return 0;
}