#include <iostream>
#include "Tetromino.h"

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

    cout<< "How many Tetrominos?" <<endl;
    cin >>howManyTetro;

    cout<<"What are the types?"<<endl;

    for(int i=0; i<howManyTetro; i++){
        cin>> tetroType;
        Shapes shape = static_cast<Shapes> (tetroType);
        Tetrominos.push_back(Tetromino(shape)); 
        Tetrominos[i].setTetro(); 
    }

        cout<<"Your tetrominos"<<endl;
        for(int i=0; i<howManyTetro; i++) Tetrominos[i].printTetro(); //Printing tetrominos in the beginning.

        for(int i=0;i<howManyTetro -1 ; i++){
            for(int j=1; j<=howManyTetro - 1 ; j++){
                    Tetrominos[i].canFit(Tetrominos[j],'R');  //Calling canFit function.
            }
        }

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
    
        cout<< "Horizontally best-fit tetrominos"<<endl;

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
          
    return 0;
}






