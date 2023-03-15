#include "tetromino.hpp"
#include "tetris.hpp"
#include <iostream>

using namespace std;


int main(){

    int row, column;
    char input;
    Shp shape_arr[]= {Shp::I,Shp::O,Shp::T,Shp::J,Shp::L,Shp::S,Shp::Z}; //random array

    
    cout<<"Enter row of the board: ";
    cin>> row;

    cout<<"Enter column of the board: ";
    cin>> column;

    cout<<"Creating game board... \n";
    Tetris tetris(row,column);

    while(1){
        srand(time(NULL));

        cout<<"Enter the tetromino type(I,O,T,J,L,S,Z or R for random, Q for Quit.): ";

        cin>> input;

        Shp shape = static_cast<Shp> (input);  //Casting input into shape object.

        if(input== 'Q') {cout<< "Quitting the game.... \n"; exit(1);};
        if(input=='R'){
            shape = static_cast<Shp> (shape_arr[rand()%7]);
        }

        Tetromino tetro(shape);  //Creating tetromino object using shape input.

        tetris+=tetro;

        tetris.printMap();
        char direction;
        int count;

        cout<<"Enter rotation direction(R for Right, L for Left) and rotation count: ";
        cin>> direction;
        cin>> count;

        for(int i=0; i<count; ++i ) tetro.rotate(direction);
    
        tetris+=tetro;

        tetris.printMap();

        cout<<"Enter the move direction(R for Right, L for Left) and count: ";
        char mDirection;
        int mCount;
        cin>> mDirection;
        cin>> mCount;
        tetris.moveTetro(mDirection, mCount);  //moving tetro to right and left.

        cout<< "Tetromino has been rotated and moved. Map is being printed.... \n";

        tetris.animate();

    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    return 0;
}