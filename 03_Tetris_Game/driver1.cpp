#include "tetromino.hpp"
#include "tetris.hpp"
#include <iostream>

using namespace std;


int main(){

    char type;
    cout<<"Enter the tetromino type(L,S,Z,O,I,J,T): ";
    cin>> type;

    Tetromino tetromino(static_cast<Shp> (type));  //Creating tetro object.
    tetromino.printTetro();  //Printing tetro
    tetromino.rotate('R');
    cout<<"Rotated tetromino is: \n";
    tetromino.printTetro();

    int row, column;

    cout<<"Enter row of the board: ";
    cin>> row;

    cout<<"Enter column of the board: ";
    cin>> column;

    cout<<"Creating game board... \n";
    Tetris tetris(row,column);
    //tetris.printMap();
    Tetromino tetro(Shp::J); //I O T J L S Z
    tetris+=tetro;

    tetris.printMap();
    tetris.clearMap();
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
    tetris.moveTetro(mDirection, mCount);

    cout<< "Tetromino has been rotated and moved. Map is being printed.... \n";

    tetris.animate();

    //tetris.printMap();

    return 0;
}
