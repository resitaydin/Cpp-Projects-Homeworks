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


void testFunctions(AbstractTetris* tet){

    Tetromino tetro1(Shp::O);
    Tetromino tetro2(Shp::I);
    Tetromino tetro3(Shp::J);
    Tetromino tetro4(Shp::L);

    tet->operator+=(tetro1);   // Calling functions polymorphically.
    tet->animate();
    cout<<"Last move is going "<<tet->lastMove().first<<" "<<tet->lastMove().second<<" unit with tetrotype: "<<" O "<<endl;
    cout<<"number of moves: "<<tet->numberOfMoves()<<endl;

    tet->operator+=(tetro2);
    tet->animate();
    tet->lastMove();
    cout<<"Last move is going "<<tet->lastMove().first<<" "<<tet->lastMove().second<<" unit with tetrotype: "<<" I "<<endl;
    cout<<"number of moves: "<<tet->numberOfMoves()<<endl;

    tet->operator+=(tetro3);
    tet->animate();
    tet->lastMove();
    cout<<"Last move is going "<<tet->lastMove().first<<" "<<tet->lastMove().second<<" unit with tetrotype: "<<" J "<<endl;
    cout<<"number of moves: "<<tet->numberOfMoves()<<endl;

    tet->operator+=(tetro4);
    tet->animate();
    tet->lastMove();
    cout<<"Last move is going "<<tet->lastMove().first<<" "<<tet->lastMove().second<<" unit with tetrotype: "<<" L "<<endl;
    cout<<"number of moves: "<<tet->numberOfMoves()<<endl;

    tet->writeToFile("result.txt");
    tet->readFromFile("result.txt");
}

int main(){

    int row= 15, column = 20;

    vector< AbstractTetris* > TetrisGames(5);  // AbstractTetris* TetrisGames[5];
    vector< AbstractTetris* > TetrisGames1 (2);  // AbstractTetris* TetrisGames[5];

    TetrisGames[0] = new TetrisVector(row,column);
    TetrisGames[1] = new TetrisArray1D(row,column);
    TetrisGames[2] = new TetrisAdapter< deque<char> >(row,column);
    TetrisGames[3] = new TetrisAdapter< vector<char> >(row,column);
    TetrisGames[4] = new TetrisAdapter< basic_string<char> >(row,column);

    // TetrisGames[i] = new TetrisAdapter< list<char> >(row,column);
    // TetrisGames[i] = new TetrisAdapter< forward_list<char> >(row,column);

    TetrisGames1[0] = new TetrisVector(row,column);
    TetrisGames1[1] = new TetrisAdapter< deque<char> >(row,column);

    cout<<"\nTrying functions and game with an array of 5 pointers...\n";

    for(int i=0 ; i< 5; ++i){
        switch(i){
            case 0:
                cout<<"\n--------------------------------\n";
                cout<<"Playing game with TetrisVector...\n";
                cout<<"\n--------------------------------\n";
                    break;
            case 1:
                cout<<"\n--------------------------------\n";
                cout<<"Playing game with TetrisArray1D...\n";
                cout<<"--------------------------------\n";
                    break;
            case 2:
                cout<<"\n--------------------------------\n";
                cout<<"Playing game with TetrisAdapter(deque) ...\n";
                cout<<"\n--------------------------------\n\n";
                    break;
            case 3:
                cout<<"\n--------------------------------\n";
                cout<<"Playing game with TetrisAdapter(vector) ...\n";
                cout<<"\n--------------------------------\n";
                    break;
            case 4:
                cout<<"\n--------------------------------\n";
                cout<<"Playing game with TetrisAdapter(basic_string) ...\n";
                cout<<"\n--------------------------------\n";
                    break;
            default:
                break;
        }
        testFunctions(TetrisGames[i]);
    }

    cout<<"\nTrying functions and game with an array of 2 pointers...\n";
    for(int i=0; i<2; ++i) {
        if(i==0){
            cout<<"\n--------------------------------\n";
            cout<<"Playing game with TetrisVector...\n";
            cout<<"\n--------------------------------\n";
        }
        else if(i==1){
            cout<<"\n--------------------------------\n";
            cout<<"Playing game with TetrisAdapter(deque) ...\n";
            cout<<"\n--------------------------------\n\n";
        }
        testFunctions(TetrisGames1[i]);
    }

    return 0;
}