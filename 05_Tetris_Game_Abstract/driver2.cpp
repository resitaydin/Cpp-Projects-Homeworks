
#include "TetrisAdapter.cpp"
#include "TetrisArray1D.h"
#include "TetrisVector.h"
#include "tetromino.h"

#include <vector>
#include <deque>
#include <string>

using namespace tetrisVector;
using namespace tetrisArray1D;
using namespace tetrisAdapter;

int main(){
    AbstractTetris* boardObj;
    Shp shape_arr[]= {Shp::I,Shp::O,Shp::T,Shp::J,Shp::L,Shp::S,Shp::Z}; //random array

    int row=0,column=0;
    bool flag;
    char input;
    char tetrotype;
    srand(time(NULL));

    while(row<=0 || column<=0 ){
        cout<< "Enter the row size of tetris board: ";
        cin>> row;

        cout<< "Enter the column size of tetris board: ";
        cin>> column;
    }   

    while(input!='V' && input!= '1' && input!='A'){
        cout<<"Enter the type of the Tetris class(V for vector, 1 for array1D, A for adaptor): ";
        cin>> input;
    }
    

    if(input == 'V')
        boardObj= new TetrisVector(row,column);

    else if(input == '1'){
        boardObj= new TetrisArray1D(row,column);
    }
    else if(input == 'A'){
        boardObj= new TetrisAdapter< deque<char> >(row,column); // This works for basic_string(char), deque, vector etc.
        // boardObj= new TetrisAdapter< vector<char> >(row,column);
        // boardObj= new TetrisAdapter< basic_string<char> >(row,column);
    }

    while(boardObj->gameIsOver()!=1 || flag){
        flag= 0;
    
        cout<<"Enter the tetromino type(I, O, T, J, L, S, Z or R for random, Q for quit): ";
        cin>> tetrotype;
        Shp shape;

        if(tetrotype== 'Q') {cout<< "Quitting the game.... \n"; exit(1);}

        else if(tetrotype=='R' || tetrotype=='I' || tetrotype=='O' || tetrotype=='T' || tetrotype=='J' || tetrotype=='L' || tetrotype=='S' || tetrotype=='Z'){
            if(tetrotype=='R') shape = shape_arr[rand()%7];
            else shape = static_cast<Shp> (tetrotype);  //Casting input into shape object.  
            Tetromino tetro(shape);

            boardObj->operator+=(tetro);
            boardObj->animate();
            boardObj->lastMove();
            boardObj->writeToFile("result.txt");
            boardObj->readFromFile("result.txt");
        }

        else{
            // throw invalid_argument("Invalid value! Try again...\n");
            flag = 1;
            cout<<"Invalid value.\n";
        }
    
    }
    cout<<endl<<"Game is Over!!!\n";

    return 0;
}
