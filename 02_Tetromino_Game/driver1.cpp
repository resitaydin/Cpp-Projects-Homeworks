#include <iostream>
#include "Tetromino.h"
#include "tetris.h"

using namespace std;


int main() {
    int howManyTetro;
    char tetroType;
    vector <Tetromino> Tetrominos; //Vector to create tetromino objects.
    vector <char> map1 ; //First row
    vector <char> map2 ; //Second row
    vector <char> map3 ; //Third row
    map1.reserve(100);
    map2.reserve(100);
    map3.reserve(100);
    
    Tetrominos.reserve(50);
    howManyTetro = 4; 

    cout<<"Creating 4 Tetromino objects...\n";

    Tetrominos.push_back(Tetromino(Shapes::I)); 
    Tetrominos.push_back(Tetromino(Shapes::O)); 
    Tetrominos.push_back(Tetromino(Shapes::O));
    Tetrominos.push_back(Tetromino(Shapes::O)); 
    cout<<"Done!\n";
  
    cout<<"Setting the tetrominos...\n";

    for(int i=0; i<howManyTetro; i++){

        Tetrominos[i].setTetro(); 
    }
        cout<<"Done!\n";

        cout<<"Your tetrominos"<<endl;
        for(int i=0; i<howManyTetro; i++) Tetrominos[i].printTetro(); //Printing tetrominos in the beginning.

        cout<<"Calling CanFit function.\n";

        for(int i=0;i<howManyTetro -1 ; i++){
            for(int j=1; j<=howManyTetro - 1 ; j++){
                    Tetrominos[i].canFit(Tetrominos[j],'R');  //Calling canFit function.
            }
        }
        cout<<"Done!\n";

        cout<<"Creating map...\n";
        int k=0;
        for(int i=0;i<howManyTetro;i++){
            auto tetro = Tetrominos[i].getTetro();  //Creating first row of map.
            for(int j=0;j<3;j++){
                map1.push_back(tetro[0][j]);
                k++;
            }
        }
        k=0;
        for(int i=0;i<howManyTetro;i++){
            auto tetro = Tetrominos[i].getTetro(); //Creating second row of map.
            for(int j=0;j<3;j++){
                map2.push_back(tetro[1][j]);
                k++;
            }
        }
        k=0;
        for(int i=0;i<howManyTetro;i++){
            auto tetro = Tetrominos[i].getTetro(); //Creating third row of map.
            for(int j=0;j<3;j++){
                map3.push_back(tetro[2][j]);
                k++;
            }
        }
        cout<<"Done!\n";
    
        cout<<"Printing map...\n";

        for(int i=0;i<map1.size();i++){
            cout<< map1[i];  //Printing first row of map
        }
        cout<<endl;

        for(int i=0;i<map2.size();i++){
            cout<< map2[i];  //Printing second row of map
        }
        cout<<endl;
        for(int i=0;i<map3.size();i++){
            cout<< map3[i]; //Printing third row of map
        } 
        cout<<endl;
        cout<<"Done!\n";

    cout<<"Creating the Tetris object for the game\n";

    Tetris myTetris(20,20);

    cout<<"Done!\n";


    cout<<"Setting tetroType...\n";
    myTetris.setTetroType(Shapes::I);

    cout<<"Done!\n";

    cout<<"Calling bestFit function to fit object in the map...\n";
    myTetris.BestFit(Tetrominos[0]);
    cout<<"Done!\n";

    cout<<"Initializing map...\n";
    myTetris.initMap();
    cout<<"Done!\n";

    cout<<"Adding tetro to the map...\n";
    myTetris.addTetro(Tetrominos[0]);
    cout<<"Done!\n";

    cout<<"Printing map to the screen...\n";
    myTetris.draw();
    cout<<"Done!\n";

          
    return 0;
}






